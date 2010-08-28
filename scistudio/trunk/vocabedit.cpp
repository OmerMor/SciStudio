//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "scihdr.h"
#include "vocabedit.h"
#include "explorer.h"
#include "main.h"     
#include "vocabfind.h"
#include "addword.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MenuBar"
#pragma resource "*.dfm"
TWndVocabEdit *WndVocabEdit;
//---------------------------------------------------------------------------
int CurrentSortMethod;
int __stdcall SubItemSort2(long Item1, long Item2, long ParamSort);
int __stdcall ItemSort2(long Item1, long Item2, long ParamSort);
//---------------------------------------------------------------------------
__fastcall TWndVocabEdit::TWndVocabEdit(TComponent* Owner)
	: TForm(Owner)
{
	WINBLOWS = FALSE;
    LOADING_VOCAB = TRUE;

    TypeListBox->Items->Clear();
    for(int i = 0; i < TOTAL_VT; i++)
		TypeListBox->Items->Add(vocabTypes[i].Name);

    for(long i = 0; i < MAX_VOC_GROUPS; i++) {
        vocGroups[i] = new sciVocGroup;
        vocGroups[i]->Strings = new TStringList;
    }
    
	NewVocab();
}
//---------------------------------------------------------------------------
void vcEditorClose(EDITORTAG *edtTag)
{
	TWndVocabEdit *form = ((TWndVocabEdit*)edtTag->Form);
	form->LOADING_VOCAB = TRUE;
    for(long i = 0; i < MAX_VOC_GROUPS; i++) {
        if(form->vocGroups[i]) {
        	if(form->vocGroups[i]->Strings) delete form->vocGroups[i]->Strings;
        	delete form->vocGroups[i];
        }
    }
}
//---------------------------------------------------------------------------
void vcSaveRes(EDITORTAG *edtTag)
{
	((TWndVocabEdit*)edtTag->Form)->Save1Click(edtTag->Form);
}
//---------------------------------------------------------------------------
BOOL TWndVocabEdit::InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 resVer)
{
    edTag.EditorClose = vcEditorClose;
    edTag.SaveRes = vcSaveRes;
    edTag.edtWnd = _edtWnd;
    strcpy(edTag.defCaption,Caption.c_str());   
    edTag.Form = this;
	Tag = (int)&edTag;

    if(!WndExplorer)
    	SaveToGame1->Visible = FALSE;
	else {    
		SET_EXPLORERED();
    	if(resBuf) {
			LoadVocab(resBuf,edTag.edtWnd->resIDfo.size);
            UPDATE_CAPTION();
        }
    }
	return TRUE;
}          
//---------------------------------------------------------------------------
AnsiString __fastcall TWndVocabEdit::GetTypesAsString(WORD Type)
{
    AnsiString Str = "";

    switch(Type) {
        case vtiNO_WORD: // no word
            Str = GetVocTypeName(vtNO_WORD);
            break;
        case vtiANY_WORD:
            Str = GetVocTypeName(vtANY_WORD);
            break;
        default:
            for(int i = 0; i < TOTAL_VT; i++)
                if((Type >> i) & 1) {
                    if(Str != "") Str += " | ";
                    Str += GetVocTypeName(1 << i);
                }
    }

    return Str;
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::GotoCurrentItem()
{
    AnsiString StrGroup = IntToStr(currentGroup);
    selectedListItem =
        ListView->FindCaption(0, StrGroup, FALSE, TRUE, FALSE);

    ListView->SetFocus();
    ListView->Selected = selectedListItem;
    ListView->ItemFocused = selectedListItem;
    selectedListItem->MakeVisible(TRUE);
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::UpdateVocabEditVisuals()
{
    if(LOADING_VOCAB) return;
    ListView->OnChange = NULL;

    // Show the group number
    Panel4->Caption = "Group "+IntToStr(currentGroup);

    // Show the words in the group
    ListBox->Items->BeginUpdate();
    ListBox->Items->Clear();
    for(int i = 0; i < vocGroups[currentGroup]->Strings->Count; i++) {
        ListBox->Items->Add(vocGroups[currentGroup]->Strings->Strings[i]);
    }              

    	// Show the types set for the group
    	for(int i=0;i<TOTAL_VT;i++)
    		TypeListBox->Checked[i] = FALSE;
		if(vocGroups[currentGroup]->Type==vtNO_WORD) {
   			TypeListBox->Checked[vtiNO_WORD] = TRUE;
    	} else if(vocGroups[currentGroup]->Type==vtANY_WORD) {
   			TypeListBox->Checked[vtiANY_WORD] = TRUE;
    	} else {
    		for(int i=1;i<TOTAL_VT-1;i++) {
        		if(HasType(vocGroups[currentGroup]->Type,i)==1)
    				TypeListBox->Checked[i] = TRUE;
    		}
    	}

    ListBox->Items->EndUpdate();   
    ListView->OnChange = ListViewChange;
}
//---------------------------------------------------------------------------
int TWndVocabEdit::GetVocTypeIndex(AnsiString Str)
{
    for(int i = 0; i < TOTAL_VT; i++)
        if(AnsiString(vocabTypes[i].Name) == Str)
            return i;

    return -1;
}
//---------------------------------------------------------------------------
WORD TWndVocabEdit::GetVocTypeMask(AnsiString Str)
{
    for(int i = 0; i < TOTAL_VT; i++)
        if(AnsiString(vocabTypes[i].Name) == Str)
            return vocabTypes[i].Mask;

    return -1;
}
//---------------------------------------------------------------------------
AnsiString TWndVocabEdit::GetVocTypeName(int Mask)
{         int i;

    for(i = 0; i < TOTAL_VT; i++)
        if(vocabTypes[i].Mask == Mask)
            return vocabTypes[i].Name;

    return "NULL";
}
//---------------------------------------------------------------------------
WORD __fastcall TWndVocabEdit::HasType(WORD Type, WORD n)
{
    switch(Type) {
        case vtiNO_WORD:
        case vtiANY_WORD:
            return -1;
        default:
                if((Type & vocabTypes[n].Mask)==vocabTypes[n].Mask)
                    return 1;
    }

    return -1;
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::AddType(WORD Group, WORD Type)
{
    switch(Type) {
        case vtiNO_WORD: // no word
            vocGroups[Group]->Type = vtNO_WORD;
            break;
        case vtiANY_WORD:
            vocGroups[Group]->Type = vtANY_WORD;
            break;
        default:
            vocGroups[Group]->Type |= (WORD) Type;
    }
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::DeleteType(WORD Group, WORD Type)
{
    switch(Type) {
        case 0: // no word
            ssMessage(ssNOTICE,"No word types to delete!");
            break;
        case 0x4FF: // anyword = no word
            vocGroups[Group]->Type = vtNO_WORD;
            break;
        default:
            vocGroups[Group]->Type &= (WORD) (~Type);
    }
}

//--------------------------------------------------------------------------
void __fastcall TWndVocabEdit::NewVocab()
{
    ClearFields();

    for(long i = 0; i < MAX_VOC_GROUPS; i++) {
        vocGroups[i]->Strings->Clear();
        vocGroups[i]->Type = vtNO_WORD;
    }

    selectedListItem = NULL;
    Panel1->Enabled = TRUE;
    ListView->Enabled = TRUE;
    LoadListViewVocab(FALSE);
    ListView->Selected = ListView->Items->Item[0];

    WRITE_STATUS("New vocab created successfully.");
}
//---------------------------------------------------------------------------

bool __fastcall TWndVocabEdit::LoadVocab(U8 *data,U16 len)
{
    LOADING_VOCAB = true;
    ListView->Enabled = false;

    wordsType = sv_WT_00;
    if(!VerifyVocab000(data,len)) {
    	if(!VerifyVocab900(data,len)) {
        	ssMessage(ssERROR,"The vocab you are trying to load has been confirmed as neither an SCI0 Words file (vocab.000) nor an SCI1 Words file (vocab.900). You are either trying to load different vocab type of resource, or the vocab is corrupt!");
            return FALSE;
        }
    	wordsType = sv_WT_10;
    }

    for(long i = 0; i < MAX_VOC_GROUPS; i++) {
        vocGroups[i]->Strings->Clear();
        vocGroups[i]->Type = vtNO_WORD;
    }
    if(wordsType == sv_WT_00) {
		int Offset=52;
	    while(Offset < len) {
	        BYTE i = data[Offset++];
	        while((BYTE) (vocString[i++] = data[Offset++]) < 0x80);
	        vocString[i-1] &= 0x7F;
	        vocString[i] = '\0';
	        WORD Type  = data[Offset]&0xFF;
	        Type += (WORD)(((WORD)data[Offset+1]>>4) &0xF)<<8;
	        WORD Group = (((data[Offset+1] << 8) & 0x0F00) + ((data[Offset+2]) & 0xFF)) & 0xFFF;
	        Offset += 3;

	        vocGroups[Group]->Type = Type;
	        vocGroups[Group]->Strings->Add(vocString);
	    }
    } else {
		int Offset=0x1FE;
	    while(Offset < len) {
	        BYTE i = data[Offset++];
	        while(((BYTE)vocString[i++] = data[Offset++])!='\0');
	        WORD Type  = data[Offset]&0xFF;
	        Type += (WORD)(((WORD)data[Offset+1]>>4) &0xF)<<8;
	        WORD Group = (((data[Offset+1] << 8) & 0x0F00) + ((data[Offset+2]) & 0xFF)) & 0xFFF;
	        Offset += 3;

	        vocGroups[Group]->Type = Type;
	        vocGroups[Group]->Strings->Add(vocString);
	    }
    }

    currentGroup = 0;
    LoadListViewVocab(FALSE);
    ListView->Selected = ListView->Items->Item[0];

    CLEAR_RESCHANGED();
    return TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::SaveVocab(int wt)
{
	BOOL WORD_FOUND;
    char *ch = "\0";
    int newType=wordsType;
                       
    if((!CHECK_EXPLORERED())&&(edTag.edtWnd->fileName[0]=='\0')) {
        SaveAs1Click(this);
        return;
    }
    newType = wt;
    if((CHECK_EXPLORERED())&&(wt!=Game.version->wordsType)) {
        if(Game.version->wordsType!=-1) {
        	ssMessage(ssNOTICE,"The game you are saving the words vocab to is a different version from the vocab you loaded. SCI Studio will convert it to the compatible version.");
        	newType=Game.version->wordsType;
        } else {
        	int i = ssMessage(ssNOTICE|ssYESNO,"The game you are saving the words vocab to does not support words vocabs. Would you like to save it to a file instead?");
         	if(i==IDNO)
            	return;
        	CLEAR_EXPLORERED();   
        	SaveAs1Click(this);
        	return;
        }
    }

    // Create the buffer to write to
    U8 *data = (U8*)ssCalloc(rsMAX_SIZE);

    int Offset;

    if(newType==sv_WT_00) {
    	// Remember that there's a 26 Word-sized alphabet index
	    Offset = 52;

	    TStringList *TempList = new TStringList;
	    TempList->Sorted = TRUE;
	    for(long Group = 0; Group < MAX_VOC_GROUPS; Group++)
	        if(vocGroups[Group]->Strings->Count)
	            for(int s = 0; s < vocGroups[Group]->Strings->Count; s++)
	                if(!isalpha(vocGroups[Group]->Strings->Strings[s].c_str()[0]))
	                    TempList->Add(vocGroups[Group]->Strings->Strings[s]);

	    for(int Index = 0; Index < TempList->Count; Index++) {
	        for(long Group = 0; Group < MAX_VOC_GROUPS; Group++) {
	            WORD_FOUND = FALSE;
	            if(vocGroups[Group]->Strings->Count > 0) {
	                for(int s = 0; s < vocGroups[Group]->Strings->Count; s++) {
	                    if(vocGroups[Group]->Strings->Strings[s] == TempList->Strings[Index]) {
	                        int i = 0;
	                        while(ch[i] == vocGroups[Group]->Strings->Strings[s].c_str()[i]) i++;
	                        data[Offset++] = i;
	                        ch = vocGroups[Group]->Strings->Strings[s].c_str();
	                        while((data[Offset] = ch[i++]) != 0) {
                            	if(data[Offset]>=0x80) {
        							int i = ssMessage(ssNOTICE|ssYESNO,"The words file you are trying to save uses over 127 chars. SCI0 only supports 127 or less. Would you like to save it to a file instead?");
         							if(i==IDNO) {
                                    	delete TempList;
            							return;
                                    }
        							CLEAR_EXPLORERED();
                                    delete TempList;
									SaveVocab(wordsType);
                                    return;
                                }
                            	Offset++;
                            }
	                        data[Offset-1] |= 0x80;
	                        // Write the ID
	                        // AB CD EF -> Type=(CAB) Group=(DEF)
	                        data[Offset] = vocGroups[Group]->Type & 0xFF;
	                        data[Offset+1] =
	                            (((vocGroups[Group]->Type>>8)<<4)&0xF0)+
	                            ((Group>>8)&0x0F);
	                        data[Offset+2] = Group & 0xFF;
	                        Offset+=3;
	                        s = vocGroups[Group]->Strings->Count;
	                        WORD_FOUND = TRUE;
	                    }
	                }
	                if(WORD_FOUND) Group = MAX_VOC_GROUPS;
	            }
	        }
	    }
	    delete TempList;
	
	    for(int Letter = 'a'; Letter <= 'z'; Letter++) {
	        TempList = new TStringList;
	        TempList->Sorted = TRUE;
	        WORD StartOffset = Offset;
	        BOOL THERE_ARE_WORDS = FALSE;
	        for(long Group = 0; Group < MAX_VOC_GROUPS; Group++) {
	            if(vocGroups[Group]->Strings->Count) {
	                for(int s = 0; s < vocGroups[Group]->Strings->Count; s++)
	                    if(vocGroups[Group]->Strings->Strings[s].c_str()[0] == Letter) {
	                        TempList->Add(vocGroups[Group]->Strings->Strings[s]);
	                    }
	            }
	        }
	        for(int Index = 0; Index < TempList->Count; Index++) {
	            for(long Group = 0; Group < MAX_VOC_GROUPS; Group++) {
	                WORD_FOUND = FALSE;
	                if(vocGroups[Group]->Strings->Count > 0) {
	                    for(int s = 0; s < vocGroups[Group]->Strings->Count; s++) {
	                        if(vocGroups[Group]->Strings->Strings[s] == TempList->Strings[Index]) {
	                            int i = 0;
	                            while(ch[i] == vocGroups[Group]->Strings->Strings[s].c_str()[i]) i++;
	                            data[Offset++] = i;
	                            ch = vocGroups[Group]->Strings->Strings[s].c_str();
	                            while((data[Offset] = ch[i++]) != 0) {
                            		if(data[Offset]>=0x80) {
        								int i = ssMessage(ssNOTICE|ssYESNO,"The words file you are trying to save uses over 127 chars. SCI0 only supports 127 or less. Would you like to save it to a file instead?");
         								if(i==IDNO) {
                                    		delete TempList;
            								return;
                                    	}
        								CLEAR_EXPLORERED();
                                    	delete TempList;
                                    	SaveVocab(wordsType);
                                    	return;
                                	}
                            		Offset++;
                            	}
	                            data[Offset-1] |= 0x80;
	                            // Write the ID
	                            // AB CD EF -> Type=(CAB) Group=(DEF)
	                            data[Offset] = vocGroups[Group]->Type & 0xFF;
	                            data[Offset+1] =
	                                (((vocGroups[Group]->Type>>8)<<4)&0xF0)+
	                                ((Group>>8)&0x0F);
	                            data[Offset+2] = Group & 0xFF;
	                            Offset+=3;
	                            s = vocGroups[Group]->Strings->Count;
	                            WORD_FOUND = TRUE;
	                            THERE_ARE_WORDS = TRUE;
	                        }
	                    }
	                    if(WORD_FOUND) Group = MAX_VOC_GROUPS;
	                }
	            }
	        }
	        delete TempList;
	        if(THERE_ARE_WORDS) {
	            data[(Letter - 'a') << 1] = StartOffset & 0xFF;
	            data[((Letter - 'a') << 1) + 1] = (StartOffset >> 8) & 0xFF;
	        }
	    }
    } else  { // sv_WT_10
	    Offset = 0x1FE; // remember 255 word sized indexes fo'shizzall!
        TStringList *TempList;
	    for(int Letter = 1; Letter <= 255; Letter++) {
	        TempList = new TStringList;
	        TempList->Sorted = TRUE;
	        WORD StartOffset = Offset;
	        BOOL THERE_ARE_WORDS = FALSE;
	        for(long Group = 0; Group < MAX_VOC_GROUPS; Group++) {
	            if(vocGroups[Group]->Strings->Count) {
	                for(int s = 0; s < vocGroups[Group]->Strings->Count; s++)
	                    if(vocGroups[Group]->Strings->Strings[s].c_str()[0] == Letter) {
	                        TempList->Add(vocGroups[Group]->Strings->Strings[s]);
	                    }
	            }
	        }
	        for(int Index = 0; Index < TempList->Count; Index++) {
	            for(long Group = 0; Group < MAX_VOC_GROUPS; Group++) {
	                WORD_FOUND = FALSE;
	                if(vocGroups[Group]->Strings->Count > 0) {
	                    for(int s = 0; s < vocGroups[Group]->Strings->Count; s++) {
	                        if(vocGroups[Group]->Strings->Strings[s] == TempList->Strings[Index]) {
	                            int i = 0;
	                            while(ch[i] == vocGroups[Group]->Strings->Strings[s].c_str()[i]) i++;
	                            data[Offset++] = i;
	                            ch = vocGroups[Group]->Strings->Strings[s].c_str();
	                            while((data[Offset++] = ch[i++]) != 0);
	                            // Write the ID
	                            // AB CD EF -> Type=(CAB) Group=(DEF)
	                            data[Offset] = vocGroups[Group]->Type & 0xFF;
	                            data[Offset+1] =
	                                (((vocGroups[Group]->Type>>8)<<4)&0xF0)+
	                                ((Group>>8)&0x0F);
	                            data[Offset+2] = Group & 0xFF;
	                            Offset+=3;
	                            s = vocGroups[Group]->Strings->Count;
	                            WORD_FOUND = TRUE;
	                            THERE_ARE_WORDS = TRUE;
	                        }
	                    }
	                    if(WORD_FOUND) Group = MAX_VOC_GROUPS;
	                }
	            }
	        }
	        delete TempList;
	        if(THERE_ARE_WORDS) {
	            data[((Letter) << 1)] = StartOffset & 0xFF;
	            data[((Letter) << 1)+1] = (StartOffset >> 8) & 0xFF;
	        }
	    }
    }

    wordsType = newType;

    if(CHECK_EXPLORERED()) {
        RESINFO *newRI = WndExplorer->SaveResToGame(data, Offset, rsVOCAB, wordsType==sv_WT_00?0:900);
     	if(!newRI) {
    		ssFree(data);
    		return;
        } else SetResIDfo(&EDTTAG->edtWnd->resIDfo,newRI);
    } else {
        FILE *fFile;
        if((fFile=ssOpenFile(ssFIO_ROOT|ssFIO_MESSAGE,edTag.edtWnd->fileName,"wb"))==NULL)
            return;
        ssFPutW((0x80|rsVOCAB),fFile);
        ssFWrite(data,Offset,fFile);
        ssCloseFile(fFile);
    }
    ssFree(data);

    CLEAR_RESCHANGED();
}

//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::LoadListViewVocab(BOOL SELECT)
{
    long Group;

    LOADING_VOCAB = TRUE;
    ListView->Items->BeginUpdate();
    ListView->Items->Clear();
    for(Group = 0; Group < MAX_VOC_GROUPS; Group++) {
        if(vocGroups[Group]->Strings->Count) {
            currentItem = ListView->Items->Count;
            ListView->Items->Add();
            ListView->Items->Item[currentItem]->Caption = IntToStr(Group);
            ListView->Items->Item[currentItem]->SubItems->Add(IntToHex(vocGroups[Group]->Type,3) + "h : " + GetTypesAsString(vocGroups[Group]->Type));

            AnsiString aString;
            for(int i = 0; i < vocGroups[Group]->Strings->Count; i++) {
                aString.cat_printf("%s", vocGroups[Group]->Strings->Strings[i].c_str());
                if(i < vocGroups[Group]->Strings->Count-1)
                    aString.cat_printf(" | ");
            }
            ListView->Items->Item[currentItem]->SubItems->Add(aString);
        }
    }
    ListView->Items->EndUpdate();
    LOADING_VOCAB = FALSE;
    //AddToGroup1->Enabled = (ListView->Items->Count);

    ListView->Enabled = true;

    AnsiString TempString = IntToStr(currentGroup);

    if(SELECT) {
        ListView->SetFocus();
        TListItem *ListItem =
            ListView->FindCaption(
                0, TempString, FALSE, TRUE, FALSE);

        ListView->Selected = ListItem;
        ListView->ItemFocused = ListItem;
        ListItem->MakeVisible(TRUE);
    }
}

//---------------------------------------------------------------------------
bool __fastcall TWndVocabEdit::AddWord(AnsiString s, int group)
{
    // Convert it to lowercase
    //  - Added code to only modify 'A'-'Z', 'cause lowercasing something like '1'
    //    Would mess things up
    char *tempChar;
    int strLen = s.Length();
    tempChar = (char *) ssCalloc(strLen+1);
    strcpy(tempChar, s.c_str());
    for(int i = 0; i < strLen; i++)
        if(tempChar[i] >= 'A' && tempChar[i] <= 'Z')
            tempChar[i] = tolower(tempChar[i]);

    // Check to see if the word already exists in the group
    for(int Group = 0; Group < MAX_VOC_GROUPS; Group++)
        if(vocGroups[Group]->Strings->Count)
            for(int i = 0; i < vocGroups[Group]->Strings->Count; i++)
                if(vocGroups[Group]->Strings->Strings[i] == AnsiString(tempChar)) {
                    ssMessage(ssERROR,"Error! \"%s\" already exists in group %d!",tempChar,Group);
    				free(tempChar);
                    return FALSE;
                }

    vocGroups[group]->Strings->Add(AnsiString(tempChar));

    ssFree(tempChar);
    return TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::ClearFields()
{                  /*
	for(int i=0;i<TOTAL_VT;i++)
    	TypeListBox->Checked[i] = FALSE;
    AddWordEdit->Text = "";
    ListBox->Items->Clear();      */
}

//---------------------------------------------------------------------------
int __stdcall SubItemSort2(long Item1, long Item2, long ParamSort)
{
    return CompareText(((TListItem *)Item1)->SubItems->Strings[CurrentSortMethod], ((TListItem *)Item2)->SubItems->Strings[CurrentSortMethod]);
}
//---------------------------------------------------------------------------
int __stdcall ItemSort2(long Item1, long Item2, long ParamSort)
{
    __int64 Value1 = StrToInt(((TListItem *)Item1)->Caption);
    __int64 Value2 = StrToInt(((TListItem *)Item2)->Caption);

    if(Value1 > Value2) return 1;
    if(Value1 < Value2) return -1;

    return 0;
}
//---------------------------------------------------------------------------

void __fastcall TWndVocabEdit::Open1Click(TObject *Sender)
{
    if(!OpenDialog->Execute()) return;

	U8 *buf;
    U32 len;
    WRITE_STATUS("Loading vocab...");

   	if((buf=ssLoadFile(ssFIO_ROOT|ssFIO_MESSAGE, OpenDialog->FileName.c_str(), &len))==NULL)
    	return;
    if(CheckSCIFileHeader(buf)!=rsVOCAB) {
		ssMessage(ssERROR,"The file your are trying to open, %s, is not a valid SCI vocab resource, or does not contain a valid header",OpenDialog->FileName.c_str());
        ssFree(buf);
        return;
    }

    strcpy(edTag.edtWnd->fileName,OpenDialog->FileName.c_str());
    LoadVocab(buf+2,len-2);
                     
    ssFree(buf);
       
    CLEAR_EXPLORERED();

    WRITE_STATUS("Vocab loaded.");
    UPDATE_CAPTION();
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::Save1Click(TObject *Sender)
{
	SaveVocab(wordsType);
    UPDATE_CAPTION();
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::SaveAs1Click(TObject *Sender)
{
	char c[4];
 	if(wordsType == sv_WT_10) {
     	SaveDialog->DefaultExt = "900";
    } else {
     	SaveDialog->DefaultExt = "000";
    }
	if(edTag.edtWnd->fileName[0])
    	SaveDialog->FileName=AnsiString(edTag.edtWnd->fileName);
    else if(CHECK_EXPLORERED())
    	SaveDialog->FileName = AnsiStringFmtRes(edTag.edtWnd->resIDfo.type,edTag.edtWnd->resIDfo.number);
	if(SaveDialog->Execute()) {
        memcpy(c,ExtractFileExt(SaveDialog->FileName).c_str()+1,3);
        c[3]='\0';
        if(!CheckStringNum(c)) {
        	ShowMessage("You must select the specific vocab type to save it as (vocab.000 or vocab.900).");
            SaveAs1Click(Sender);
            return;
        }
    	CLEAR_EXPLORERED();
        strcpy(edTag.edtWnd->fileName,SaveDialog->FileName.c_str());
    	
		SaveVocab(c[0]=='0'?sv_WT_00:sv_WT_10);
    	UPDATE_CAPTION();
    }
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::SaveToGame1Click(TObject *Sender)
{
	SET_EXPLORERED();
    Save1Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::Copy2Click(TObject *Sender)
{
    AnsiString CopyString, Str1 = "", Str2 = "";

    CopyString.cat_printf("Group:%d, Type:", currentGroup);
                    /*
    for(int i = 0; i < vocGroups[currentGroup]->Strings->Count; i++) {
        for(int ii = 0; ii < vocGroups[currentGroup]->Strings->Strings[i].Length(); ii++)
            Str1 += ""+IntToHex(vocGroups[currentGroup]->Strings->Strings[i].c_str()[ii],2)+",";
        Str1 += "00 ("+vocGroups[currentGroup]->Strings->Strings[i]+"), ";
    }             */
    CopyString += ListView->Selected->SubItems->Strings[0];
    CopyString += ", ";
    CopyString += ListView->Selected->SubItems->Strings[1];

    Clipboard()->SetTextBuf(CopyString.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::Edit1Click(TObject *Sender)
{
    BOOL ENABLE_COPY = ListView->Items->Count;
    Copy1->Enabled = ENABLE_COPY;
    Copy2->Enabled = ENABLE_COPY;
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::DeleteGroup1Click(TObject *Sender)
{
    if(Application->MessageBox(("Are you sure you want to delete group "+IntToStr(currentGroup)+"?").c_str(), Caption.c_str(), MB_YESNO)
        == IDYES) {
        vocGroups[currentGroup]->Strings->Clear();
        currentGroup = 0;
        LoadListViewVocab(FALSE);
    	ListView->Selected = ListView->Items->Item[0];

        if(!ListView->Items->Count) ClearFields();
    }      
	SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::DeleteWord1Click(TObject *Sender)
{
    if(Application->MessageBox(("Are you sure you want to delete \""+ListBox->Items->Strings[ListBox->ItemIndex]+"\" from group "+IntToStr(currentGroup)+"?").c_str(), Caption.c_str(), MB_YESNO)
        == IDYES) {
        if(vocGroups[currentGroup]->Strings->Count > 1) {
            vocGroups[currentGroup]->Strings->Delete(ListBox->ItemIndex);
            UpdateVocabEditVisuals();
            LoadListViewVocab(TRUE);
        } else ShowMessage("Can not delete last word in group!");
    }      
	SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::FindWord1Click(TObject *Sender)
{
    // Display the splash screen
    TDlgVocabFind *DlgVocabFind = new TDlgVocabFind( this );
    DlgVocabFind->aWndVocabEdit = this;
    DlgVocabFind->ShowModal();
    delete DlgVocabFind;
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::ListViewChange(TObject *Sender,
      TListItem *Item, TItemChange Change)
{
    if(!LOADING_VOCAB) {
        selectedListItem = Item;
        currentGroup = StrToInt(selectedListItem->Caption);
        UpdateVocabEditVisuals();
    }
	DeleteGroup1->Enabled = (ListView->Selected);
    tbDeleteGroup->Enabled = (ListView->Selected);
	Copy1->Enabled = (ListView->Selected);
	Copy2->Enabled = (ListView->Selected);
    Panel1->Enabled = (ListView->Selected);
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::ListViewColumnClick(TObject *Sender,
      TListColumn *Column)
{
    // Sort the list items accordingly

    CurrentSortMethod = Column->Index - 1;

    if(Column->Index)
//        ListView->AlphaSort();
        ListView->CustomSort(SubItemSort2, 0);
    else
        ListView->CustomSort(ItemSort2, 0);
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::TypeListBoxClick(TObject *Sender)
{
	int x=vtNO_WORD;
	if(WINBLOWS) return;
    WINBLOWS = TRUE;
    if(TypeListBox->Checked[vtiANY_WORD]&&vocGroups[currentGroup]->Type != vtANY_WORD) {
    	for(int i=0;i<TOTAL_VT-1;i++)
        	TypeListBox->Checked[i] = FALSE;
        vocGroups[currentGroup]->Type = vtANY_WORD;
    } else {
    	for(int i=1;i<TOTAL_VT-1;i++)
        	if(TypeListBox->Checked[i])
            	x |= vocabTypes[i].Mask;
    	vocGroups[currentGroup]->Type = x;
        if(x==vtNO_WORD) {
    			for(int i=1;i<TOTAL_VT;i++)
    				TypeListBox->Checked[i] = FALSE;
         		TypeListBox->Checked[vtiNO_WORD] = TRUE;
        } else {
			TypeListBox->Checked[vtiNO_WORD] = FALSE;
			TypeListBox->Checked[vtiANY_WORD] = FALSE;
        }
    }
    UpdateVocabEditVisuals();
    ListView->Selected->SubItems->Strings[0] = (IntToHex(vocGroups[currentGroup]->Type,3) + "h : " + GetTypesAsString(vocGroups[currentGroup]->Type));
	SET_RESCHANGED();
    WINBLOWS = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::AddWordEditKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{       /*
    if(Key==VK_RETURN) {
        if(AddToGroup1->Enabled) AddToGroup1Click(Sender);
        else AddToNewGroup1Click(Sender);
    }  */
}
//---------------------------------------------------------------------------
void __fastcall TWndVocabEdit::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if(Shift.Contains(ssCtrl)) {
    	switch(Key) {
            case 'N':
                New1Click(Sender);
                break;
            case 'O':
                Open1Click(Sender);
                break;
            case 'S':
                Save1Click(Sender);
                break;
         	case 'C':
            	Copy2Click(Sender);
                break;
         	case 'F':
            	FindWord1Click(Sender);
                break;
        }
    }
}
//---------------------------------------------------------------------------



void __fastcall TWndVocabEdit::tbAddWordClick(TObject *Sender)
{
	TDlgAddWord *d = new TDlgAddWord(this);

    int g,fgc=0;
    for(g=1;g<MAX_VOC_GROUPS;g++) {
    	if(!vocGroups[g]->Strings->Count) {
        	d->ComboBox1->Items->Add(IntToStr(g));
    		fgc++;
        }
    }
    if(!fgc) {
        ssMessage(ssERROR,"No more free groups!");
        delete d;
        return;
    }
    d->ComboBox1->ItemIndex = 0;
    d->Caption = "Add Group to Vocab";
    d->ShowModal();
	SET_RESCHANGED();

    delete d;
}
//---------------------------------------------------------------------------

void __fastcall TWndVocabEdit::ToolButton8Click(TObject *Sender)
{
	TDlgAddWord *d = new TDlgAddWord(this);
    int g,fgc=0;
    int ii=-1;
    for(g=1;g<MAX_VOC_GROUPS;g++) {
    	if(vocGroups[g]->Strings->Count) {
        	int x = d->ComboBox1->Items->Add(IntToStr(g));
            if(g==currentGroup)
            	ii=x;
    		fgc++;

        }
    }
    if(!fgc||ii==-1) {
        delete d;
        return;
    }
    d->ComboBox1->ItemIndex = ii;    
    d->Caption = "Add Word to Group";
    d->ShowModal();
	SET_RESCHANGED();

    delete d;
}
//---------------------------------------------------------------------------


void __fastcall TWndVocabEdit::New1Click(TObject *Sender)
{
	NewVocab();
	CLEAR_FILENAME();
    CLEAR_RESCHANGED();
    UPDATE_CAPTION();
}
//---------------------------------------------------------------------------



