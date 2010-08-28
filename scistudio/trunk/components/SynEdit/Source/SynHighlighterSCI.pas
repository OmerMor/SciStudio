unit SynHighlighterSCI;

{$I SynEdit.inc}

interface

uses
  SysUtils, Windows, Messages, Classes, Controls, Graphics, Registry,
  SynEditTypes, SynEditHighlighter;

type
  TtkTokenKind = (tkComment, tkKey, tkNull,
    tkNumber, tkSpace, tkString, tkOperator, tkUnknown);

  TRangeState = (rsUnknown, rsAnsiC, rsAnsiCAsm, rsAnsiCAsmBlock, rsAsm,
    rsAsmBlock, rsDirective, rsDirectiveComment, rsString34, rsString39);

  TProcTableProc = procedure of object;

  PIdentFuncTableFunc = ^TIdentFuncTableFunc;
  TIdentFuncTableFunc = function: TtkTokenKind of object;

  TSynSCISyn = class(TSynCustomHighlighter)
  private
    fRange: TRangeState;
    fLine: PChar;
    fProcTable: array[#0..#255] of TProcTableProc;
    Run: LongInt;
    fStringLen: Integer;
    fToIdent: PChar;
    fTokenPos: Integer;
    FTokenID: TtkTokenKind;
    fLineNumber: Integer;
    fCommentAttri: TSynHighlighterAttributes;       
    fOperatorAttri: TSynHighlighterAttributes;
    fKeyAttri: TSynHighlighterAttributes;
    fNumberAttri: TSynHighlighterAttributes;
    fSpaceAttri: TSynHighlighterAttributes;
    fStringAttri: TSynHighlighterAttributes;    
    fNormalAttri: TSynHighlighterAttributes;

    function KeyHash(ToHash: PChar): Integer;
    function KeyComp(const aKey: String): Boolean;  
    procedure AnsiCProc;
    procedure OperatorProc;
    procedure CommentProc;
    procedure LFProc;
    procedure NullProc;
    procedure NumberProc;
    procedure SpaceProc;
    procedure StringProc;
    procedure IdentProc;
    procedure UnknownProc;
    //function AltFunc: TtkTokenKind;
    //function IdentKind(MayBe: PChar): TtkTokenKind;
    procedure MakeMethodTables;
  protected
    function GetIdentChars: TSynIdentChars; override;
  public
    constructor Create(AOwner: TComponent); override;
    function GetDefaultAttribute(Index: integer): TSynHighlighterAttributes;
      override;
    function GetRange: Pointer; override;
    function GetEol: Boolean; override;
    function GetTokenID: TtkTokenKind;
    procedure SetLine(NewValue: String; LineNumber:Integer); override;
    function GetToken: String; override;
    function GetTokenAttribute: TSynHighlighterAttributes; override;
    function GetTokenKind: integer; override;
    function GetTokenPos: Integer; override;
    procedure Next; override;      
    procedure SetRange(Value: Pointer); override;
    procedure ResetRange; override;
  published
    property CommentAttri: TSynHighlighterAttributes read fCommentAttri
      write fCommentAttri;
    property KeyAttri: TSynHighlighterAttributes read fKeyAttri write fKeyAttri;
    property NumberAttri: TSynHighlighterAttributes read fNumberAttri
      write fNumberAttri;
    property SpaceAttri: TSynHighlighterAttributes read fSpaceAttri
      write fSpaceAttri;
    property StringAttri: TSynHighlighterAttributes read fStringAttri
      write fStringAttri;
    property OperatorAttri: TSynHighlighterAttributes read fOperatorAttri
      write fOperatorAttri;
    property NormalAttri: TSynHighlighterAttributes read fNormalAttri
      write fNormalAttri;
  end;

implementation

uses
  SynEditStrConst;

var
  Identifiers: array[#0..#255] of ByteBool;
  mHashTable: array[#0..#255] of Integer;

  KeyNames: Array[0..49] of PCHAR = (
    'and',
    'asm',
    'bnot',
    'break',
    'case',
    'class',
    'default',
    'define',
    'do',
    'else',
    'for',
    'global',
    'if',
    'include',
    'instance',
    'local',
    'method',
    'neg',
    'not',
    'objectFunctionArea',
    'objectInfo',
    'objectLocal',
    'objectName',
    'objectSize',
    'objectSpecies',
    'objectSuperclass',
    'objectTotalProperties',
    'objectType',
    'of',
    'or',
    'param',
    'paramTotal',
    'preload',
    'procedure',
    'properties',
    'public',
    'rest',
    'return',
    'script',
    'scriptNumber',
    'self',
    'send',
    'string',
    'super',
    'switch',
    'synonyms',
    'temp',
    'use',
    'var',
    'while'
    );
    KeyTotal:Integer = 50;

procedure MakeIdentTable;
var
  I: Char;
begin
  for I := #0 to #255 do
  begin
    Case I of
      '_', '0'..'9', 'a'..'z', 'A'..'Z': Identifiers[I] := True;
    else Identifiers[I] := False;
    end;
    Case I in['_', 'a'..'z', 'A'..'Z'] of
      True:
        begin
          if (I > #64) and (I < #91) then mHashTable[I] := Ord(I) - 64 else
            if (I > #96) then mHashTable[I] := Ord(I) - 95;
        end;
    else mHashTable[I] := 0;
    end;
  end;
end;

function TSynSCISyn.KeyHash(ToHash: PChar): Integer;
begin
  Result := 0;
  while ToHash^ in ['_', '0'..'9', 'a'..'z', 'A'..'Z'] do
  begin
    inc(Result, mHashTable[ToHash^]);
    inc(ToHash);
  end;
  fStringLen := ToHash - fToIdent;
end; { KeyHash }

function TSynSCISyn.KeyComp(const aKey: String): Boolean;
var
  I: Integer;
  Temp: PChar;
begin
  Temp := fToIdent;
  if Length(aKey) = fStringLen then
  begin
    Result := True;
    for i := 1 to fStringLen do
    begin
      if Temp^ <> aKey[i] then
      begin
        Result := False;
        break;
      end;
      inc(Temp);
    end;
  end else Result := False;
end; { KeyComp }

procedure TSynSCISyn.MakeMethodTables;
var
  I: Char;
begin
  for I := #0 to #255 do
    case I of
    '/': fProcTable[I] := CommentProc;
    '+','-','=','*','%','&','^','!','|','(',')','[',']','>','<','#','@':
    fProcTable[I] := OperatorProc;
      'A'..'Z', 'a'..'z', '_': fProcTable[I] := IdentProc;
      #10: fProcTable[I] := LFProc;
      #0: fProcTable[I] := NullProc;
      '$','0'..'9': fProcTable[I] := NumberProc;
      '''','"': fProcTable[I] := StringProc;
      #1..#9, #11, #12, #14..#32: fProcTable[I] := SpaceProc;
      else fProcTable[I] := UnknownProc;
    end;
end;

constructor TSynSCISyn.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  fCommentAttri := TSynHighlighterAttributes.Create(SYNS_AttrComment);
  fCommentAttri.Style:= [fsItalic];
  AddAttribute(fCommentAttri);
  fNormalAttri := TSynHighlighterAttributes.Create(SYNS_AttrIllegalChar);
  AddAttribute(fNormalAttri);
  fKeyAttri := TSynHighlighterAttributes.Create(SYNS_AttrReservedWord);
  fKeyAttri.Style:= [fsBold];
  AddAttribute(fKeyAttri);
  fNumberAttri := TSynHighlighterAttributes.Create(SYNS_AttrNumber);
  AddAttribute(fNumberAttri);
  fSpaceAttri := TSynHighlighterAttributes.Create(SYNS_AttrSpace);
  fSpaceAttri.Foreground := clWindow;
  AddAttribute(fSpaceAttri);
  fStringAttri := TSynHighlighterAttributes.Create(SYNS_AttrString);
  AddAttribute(fStringAttri);
  fOperatorAttri := TSynHighlighterAttributes.Create(SYNS_AttrSymbol);
  AddAttribute(fOperatorAttri);
  SetAttributesOnChange(DefHighlightChange);
  MakeMethodTables;       
  fRange := rsUnknown;
  fDefaultFilter := 'SCI Script files (*.sc,*.sch)|*.sc;*.sch';
end; { Create }

procedure TSynSCISyn.SetLine(NewValue: String; LineNumber:Integer);
begin
  fLine := PChar(NewValue);
  Run := 0;
  fLineNumber := LineNumber;
  Next;
end; { SetLine }

procedure TSynSCISyn.LFProc;
begin
  fTokenID := tkSpace;
  inc(Run);
end;

procedure TSynSCISyn.NullProc;
begin
  fTokenID := tkNull;
end;

procedure TSynSCISyn.NumberProc;
begin
  inc(Run);
  fTokenID := tkNumber;
  while FLine[Run] in
    ['0'..'9', 'A'..'F', 'a'..'f', '$'] do inc(Run);
end;

procedure TSynSCISyn.CommentProc;
begin
  case FLine[Run + 1] of
    '/':                               {c++ style comments}
      begin
        fTokenID := tkComment;
        inc(Run, 2);
        while not (fLine[Run] in [#0, #10, #13]) do Inc(Run);
      end;
    '*':                               {c style comments}
      begin
        fTokenID := tkComment;
        if fRange = rsAsm then
          fRange := rsAnsiCAsm
        else if fRange = rsAsmBlock then
          fRange := rsAnsiCAsmBlock
        else if fRange <> rsDirectiveComment then                          
          fRange := rsAnsiC;
        inc(Run, 2);
        while fLine[Run] <> #0 do
          case fLine[Run] of
            '*':
              if fLine[Run + 1] = '/' then
              begin
                inc(Run, 2);
                if fRange = rsDirectiveComment then
                  fRange := rsDirective
                else if fRange = rsAnsiCAsm then
                  fRange := rsAsm
                else
                  begin
                  if fRange = rsAnsiCAsmBlock then
                    fRange := rsAsmBlock
                  else
                    fRange := rsUnKnown;
                  end;
                break;
              end else inc(Run);
            #10, #13:
              begin
                if fRange = rsDirectiveComment then
                  fRange := rsAnsiC;
                break;
              end;
          else inc(Run);
          end;
      end;
    '=':                               {divide assign}
      begin
        inc(Run, 2);
        fTokenID := tkOperator;
      end;
  else                                 {divide}
    begin
      inc(Run);
      fTokenID := tkOperator;
    end;
  end;
end;

procedure TSynSCISyn.SpaceProc;
begin
  inc(Run);
  fTokenID := tkSpace;
  while FLine[Run] in [#1..#9, #11, #12, #14..#32] do inc(Run);
end;

procedure TSynSCISyn.OperatorProc;
begin
  inc(Run);
  fTokenID := tkOperator;
  while FLine[Run] in ['+','-','=','*','%','&','^','!',
  '|','(',')','[',']','>','<','#','@'] do inc(Run);
end;

procedure TSynSCISyn.IdentProc;
var
  tCount:integer;
  tString:array[0..128] of char;
begin
  tCount := 0;
  fTokenID := tkUnknown;

  while FLine[Run] in
    ['_', '0'..'9', 'a'..'z', 'A'..'Z'] do
      begin
        tString[tCount] := FLine[Run];
        tCount := tCount + 1;
        inc(Run);
      end;

  tString[tCount] := #0;
  for tCount := 0 to KeyTotal-1 do
    if StrComp(KeyNames[tCount],tString) = 0 then fTokenID := tkKey;
end;

procedure TSynSCISyn.StringProc;
var
  StrChar:Char;
begin
  fTokenID := tkString;
  StrChar  := fLine[Run];
  repeat
    if fLine[Run] = '\' then begin
      if fLine[Run + 1] in [StrChar, '\'] then                                      //ek 2000-04-26
        Inc(Run);
    end;
    inc(Run);
  until (fLine[Run] = #0) or (fLine[Run] = #10) or (fLine[Run] = #13) or (fLine[Run] = StrChar);
  if FLine[Run] = StrChar then
    inc(Run);
end;

procedure TSynSCISyn.UnknownProc;
begin
  inc(Run);
  fTokenID := tkUnknown;
end;

procedure TSynSCISyn.AnsiCProc;
begin
  fTokenID := tkComment;
  case FLine[Run] of
    #0:
      begin
        NullProc;
        exit;
      end;
    #10:
      begin
        LFProc;
        exit;
      end;
    #13:
      begin
        UnknownProc;
        exit;
      end;
  end;

  while FLine[Run] <> #0 do
    case FLine[Run] of
      '*':
        if fLine[Run + 1] = '/' then
        begin
          inc(Run, 2);
          if fRange = rsAnsiCAsm then
            fRange := rsAsm
          else if fRange = rsAnsiCAsmBlock then
            fRange := rsAsmBlock
          else if fRange = rsDirectiveComment then
            fRange := rsDirective
          else
            fRange := rsUnKnown;
          break;
        end else
          inc(Run);
      #10: break;
      #13: break;
    else inc(Run);
    end;
end;


procedure TSynSCISyn.Next;
begin
  fTokenPos := Run;
  case fRange of
    rsAnsiC, rsAnsiCAsm,
    rsAnsiCAsmBlock, rsDirectiveComment: AnsiCProc;
    //rsDirective: DirectiveProc;
  else
    begin
      fRange := rsUnknown;
      fProcTable[fLine[Run]];
    end;
  end;
end;

function TSynSCISyn.GetDefaultAttribute(Index: integer): TSynHighlighterAttributes;
begin                       {
  case Index of
    SYN_ATTR_COMMENT: Result := fCommentAttri;
    SYN_ATTR_KEYWORD: Result := fKeyAttri;
    SYN_ATTR_NUMBER: Result := fNumberAttri;
    SYN_ATTR_WHITESPACE: Result := fSpaceAttri;
    SYN_ATTR_STRING: Result := fStringAttri;
    SYN_ATTR_OPERATOR: Result := fOperatorAttri;
    SYN_ATTR_INVALID: Result := fNormalAttri;
    else }Result := nil;
  //end;
end;

function TSynSCISyn.GetEol: Boolean;
begin
  Result := fTokenID = tkNull;
end;


function TSynSCISyn.GetRange: Pointer;
begin
  Result := Pointer(fRange);
end;


function TSynSCISyn.GetToken: String;
var
  Len: LongInt;
begin
  Len := Run - fTokenPos;
  SetString(Result, (FLine + fTokenPos), Len);
end;

function TSynSCISyn.GetTokenID: TtkTokenKind;
begin
  Result := fTokenId;
end;

function TSynSCISyn.GetTokenAttribute: TSynHighlighterAttributes;
begin
  case fTokenID of
    tkComment: Result := fCommentAttri;
    tkKey: Result := fKeyAttri;
    tkNumber: Result := fNumberAttri;
    tkSpace: Result := fSpaceAttri;
    tkString: Result := fStringAttri;
    tkOperator: Result := fOperatorAttri;
    tkUnknown: Result := fNormalAttri;
    else Result := nil;
  end;
end;

function TSynSCISyn.GetTokenKind: integer;
begin
  Result := Ord(GetTokenID);
end;

function TSynSCISyn.GetTokenPos: Integer;
begin
  Result := fTokenPos;
end;

procedure TSynSCISyn.ReSetRange;
begin
  fRange:= rsUnknown;
end;

procedure TSynSCISyn.SetRange(Value: Pointer);
begin
  fRange := TRangeState(Value);
end;

function TSynSCISyn.GetIdentChars: TSynIdentChars;
begin
  Result := ['_', '0'..'9', 'a'..'z', 'A'..'Z'];
end;

end.

