unit SynHighlighterNHA;

{$I SynEdit.inc}

interface

uses
  SysUtils, Windows, Messages, Classes, Controls, Graphics, Registry,
  SynEditTypes, SynEditHighlighter;

type
  TtkTokenKind = (tkComment, tkKey, tkNull,
    tkNumber, tkSpace, tkString, tkOperator, tkOptions, tkPrep, tkError, tkUnknown);

  TRangeState = (rsUnknown, rsAnsiC, rsAnsiCAsm, rsAnsiCAsmBlock, rsAsm,
    rsAsmBlock, rsDirective, rsDirectiveComment, rsString34, rsString39);

  TProcTableProc = procedure of object;

  PIdentFuncTableFunc = ^TIdentFuncTableFunc;
  TIdentFuncTableFunc = function: TtkTokenKind of object;

  TSynNHASyn = class(TSynCustomHighlighter)
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
    fPrepAttri: TSynHighlighterAttributes;
    fOptionsAttri: TSynHighlighterAttributes;
    fErrorAttri: TSynHighlighterAttributes;   
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
    procedure PrepProc;
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
    property PrepAttri: TSynHighlighterAttributes read fPrepAttri
      write fPrepAttri;
    property OptionsAttri: TSynHighlighterAttributes read fOptionsAttri
      write fOptionsAttri;
    property ErrorAttri: TSynHighlighterAttributes read fErrorAttri
      write fErrorAttri;
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

  KeyOperatorsNames: Array[0..23] of PCHAR = (
'carry', 'clear',
'equal',
'false', 'far',
'greater',
'is',
'less',
'minus',
'near', 'negative', 'no', 'nonzero', 'not',
'overflow',
'plus', 'positive',
'reg.a', 'reg.x', 'reg.y',
'set',
'true',
'unset',
'zero'
  );
  KeyOperatorsTotal:Integer = 24;

  KeyNames: Array[0..29] of PCHAR = (
'bool', 'byte',
'case', 'char',
'default', 'do',// 'doop',
'else', 'enum',
'forever', 'function',
//'goto',
'hi',
'if', 'inline', 'interrupt', 'interrupt.irq', 'interrupt.nmi', 'interrupt.start',
'lo',
'noreturn', 'nyhi', 'nylo',
'pointer',
'return',
'shared', 'sizeof', 'struct', 'switch',
'typedef',
'while', 'word'
    );
    KeyTotal:Integer = 30;
      
  KeyPrepNames: Array[0..42] of PCHAR = (
    'setpad',
    'align',

	'define',
	'undef',

    'ifdef',
    'ifndef',
    'else',
    'endif',

    'todo',
    'warning',
    'error',
    'fatal',
    'tell',
    	'tell.bank', 'tell.bankoffset', 'tell.banksize', 'tell.bankfree', 'tell.banktype',

    'include',
    'incbin',
    'usepath',

    'ram',
    	'ram.org', 'ram.end', 

    'rom',
    	'rom.org', 'rom.end', 'rom.banksize', 'rom.bank',

    'chr',
    	'chr.banksize', 'chr.bank', 'chr.end', 

    'ines',
    	'ines.mapper', 'ines.mirroring', 'ines.battery', 'ines.trainer', 'ines.fourscreen', 

    'interrupt',
    	'interrupt.nmi','interrupt.start','interrupt.irq'
  );   
    KeyPrepTotal:Integer = 43;

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

function TSynNHASyn.KeyHash(ToHash: PChar): Integer;
begin
  Result := 0;
  while ToHash^ in ['_', '0'..'9', 'a'..'z', 'A'..'Z'] do
  begin
    inc(Result, mHashTable[ToHash^]);
    inc(ToHash);
  end;
  fStringLen := ToHash - fToIdent;
end; { KeyHash }

function TSynNHASyn.KeyComp(const aKey: String): Boolean;
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

procedure TSynNHASyn.MakeMethodTables;
var
  I: Char;
begin
  for I := #0 to #255 do
    case I of
    '/': fProcTable[I] := CommentProc;  
    '#': fProcTable[I] := PrepProc;
    '{','}','(',')','\',':',',','.','[',']','=','!','~','+','-','*','%','>','<','^','&','|':
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

constructor TSynNHASyn.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  fCommentAttri := TSynHighlighterAttributes.Create(SYNS_AttrComment);
  fCommentAttri.Style:= [fsItalic];
  AddAttribute(fCommentAttri);
  fNormalAttri := TSynHighlighterAttributes.Create(SYNS_AttrIllegalChar);
  AddAttribute(fNormalAttri);
  fKeyAttri := TSynHighlighterAttributes.Create(SYNS_AttrReservedWord);
  fKeyAttri.Style:= [fsBold];
  fPrepAttri := TSynHighlighterAttributes.Create(SYNS_AttrReservedWord);
  fPrepAttri.Style:= [fsBold];
  fOptionsAttri := TSynHighlighterAttributes.Create(SYNS_AttrReservedWord);
  fOptionsAttri.Style:= [fsBold];
  fErrorAttri := TSynHighlighterAttributes.Create(SYNS_AttrReservedWord);
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
  fDefaultFilter := 'Source files (*.as,*.h)|*.as;*.h';
end; { Create }

procedure TSynNHASyn.SetLine(NewValue: String; LineNumber:Integer);
begin
  fLine := PChar(NewValue);
  Run := 0;
  fLineNumber := LineNumber;
  Next;
end; { SetLine }

procedure TSynNHASyn.LFProc;
begin
  fTokenID := tkSpace;
  inc(Run);
end;

procedure TSynNHASyn.NullProc;
begin
  fTokenID := tkNull;
end;

procedure TSynNHASyn.NumberProc;
begin
  fTokenID := tkNumber;
  if (FLine[Run]='$') or ((FLine[Run]='0') and ((FLine[Run+1]='x') or (FLine[Run+1]='X') )) then
  begin
  	if(FLine[Run]='$') then
    	inc(Run)
    else
    	Run := Run+2;
  	while FLine[Run] in
    	['0'..'9', 'A'..'F', 'a'..'f'] do inc(Run);
    if FLine[Run] in
    	['_', '.', 'G'..'Z', 'g'..'z'] then
        	fTokenID := tkError;
  	while FLine[Run] in
    	['_', '.', 'G'..'Z', 'g'..'z'] do inc(Run);
  end
  else begin
  	inc(Run);
  	while FLine[Run] in
   		['0'..'9'] do inc(Run);
    if FLine[Run] in
    	['k','K'] then
        	inc(Run);
    if FLine[Run] in
    	['_', '.', 'G'..'Z', 'g'..'z'] then
        	fTokenID := tkError;
  	while FLine[Run] in
    	['_', '.', 'G'..'Z', 'g'..'z'] do inc(Run);
  end;

end;

procedure TSynNHASyn.CommentProc;
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

procedure TSynNHASyn.SpaceProc;
begin
  inc(Run);
  fTokenID := tkSpace;
  while FLine[Run] in [#1..#9, #11, #12, #14..#32] do inc(Run);
end;

procedure TSynNHASyn.OperatorProc;
begin
  inc(Run);
  fTokenID := tkOperator;
  while FLine[Run] in ['+','-','=','*','%','&','^','!',
  '|','(',')','[',']','>','<','#','@'] do inc(Run);
end;

procedure TSynNHASyn.IdentProc;
var
  tCount,mRun:integer;
  tString:array[0..128] of char;
	label IdentProcEnd;
begin
  tCount := 0;
  fTokenID := tkUnknown;
	mRun := -1;
  while FLine[Run] in
    ['_', '.', '0'..'9', 'a'..'z', 'A'..'Z'] do
      begin
        tString[tCount] := FLine[Run];
        if( (FLine[Run] = '.') and (mRun = -1) ) then
        	mRun := Run;
        inc(tCount);
        inc(Run);
      end;

  tString[tCount] := #0;
  for tCount := 0 to KeyOperatorsTotal-1 do
    if StrIComp(KeyOperatorsNames[tCount],tString) = 0 then begin
    	fTokenID := tkOptions; 
        goto IdentProcEnd;
    end;
  for tCount := 0 to KeyTotal-1 do
    if StrIComp(KeyNames[tCount],tString) = 0 then begin
    	fTokenID := tkKey;
        goto IdentProcEnd;
    end;

	if(mRun <> -1) then
    	Run := mRun;

  IdentProcEnd:
end;

procedure TSynNHASyn.PrepProc;
var
  tCount:integer;
  startRun:integer;
  tString:array[0..128] of char;
	label bah1;
begin
  tCount := 0;
  fTokenID := tkNumber;
	inc(Run);
  startRun := Run;
    fTokenID := tkOperator;
  while FLine[Run] in
    ['_', '.', 'a'..'z', 'A'..'Z'] do
      begin
        tString[tCount] := FLine[Run];
        inc(tCount);
        inc(Run);
      end;
  tString[tCount] := #0;
  for tCount := 0 to KeyPrepTotal-1 do
    if StrIComp(KeyPrepNames[tCount],tString) = 0 then begin
    	fTokenID := tkPrep;
       	goto bah1;
    end;
    Run := startRun;
	bah1:
end;

procedure TSynNHASyn.StringProc;
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

procedure TSynNHASyn.UnknownProc;
begin
  inc(Run);
  fTokenID := tkUnknown;
end;

procedure TSynNHASyn.AnsiCProc;
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


procedure TSynNHASyn.Next;
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

function TSynNHASyn.GetDefaultAttribute(Index: integer): TSynHighlighterAttributes;
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

function TSynNHASyn.GetEol: Boolean;
begin
  Result := fTokenID = tkNull;
end;


function TSynNHASyn.GetRange: Pointer;
begin
  Result := Pointer(fRange);
end;


function TSynNHASyn.GetToken: String;
var
  Len: LongInt;
begin
  Len := Run - fTokenPos;
  SetString(Result, (FLine + fTokenPos), Len);
end;

function TSynNHASyn.GetTokenID: TtkTokenKind;
begin
  Result := fTokenId;
end;

function TSynNHASyn.GetTokenAttribute: TSynHighlighterAttributes;
begin
  case fTokenID of
    tkComment: Result := fCommentAttri;
    tkKey: Result := fKeyAttri;
    tkNumber: Result := fNumberAttri;
    tkSpace: Result := fSpaceAttri;
    tkString: Result := fStringAttri;
    tkOperator: Result := fOperatorAttri;
    tkPrep: Result := fPrepAttri;
    tkOptions: Result := fOptionsAttri;
    tkError: Result := fErrorAttri;
    tkUnknown: Result := fNormalAttri;
    else Result := nil;
  end;
end;

function TSynNHASyn.GetTokenKind: integer;
begin
  Result := Ord(GetTokenID);
end;

function TSynNHASyn.GetTokenPos: Integer;
begin
  Result := fTokenPos;
end;

procedure TSynNHASyn.ReSetRange;
begin
  fRange:= rsUnknown;
end;

procedure TSynNHASyn.SetRange(Value: Pointer);
begin
  fRange := TRangeState(Value);
end;

function TSynNHASyn.GetIdentChars: TSynIdentChars;
begin
  Result := ['_', '0'..'9', 'a'..'z', 'A'..'Z'];
end;

end.

