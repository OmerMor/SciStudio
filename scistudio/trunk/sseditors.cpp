//---------------------------------------------------------------------------
#include "scihdr.h"
#include "main.h"
#include "viewedit.h"
#include "picedit.h"
#include "scriptedit.h"
#include "textedit.h"
#include "vocabedit.h"
#include "explorer.h"
//---------------------------------------------------------------------------
int totalEdtWnds;
int winNum;

EDTWND *edtWndFirst,*edtWndLast;
EDTWND *scrEdtWnd;
EDTWND edtWnds[TOTAL_RES_TYPES3] = {
	{//VIEW
		NULL,NULL,
	    WndGfxEdit,
	    &resTypes[rsVIEW]
	},
	{//PIC
		NULL,NULL,
	    WndPicEdit,
	    &resTypes[rsPIC]
    },
	{//SCRIPT
		NULL,NULL,
	    WndScriptEdit,
	    &resTypes[rsSCRIPT]
    },
	{//TEXT
		NULL,NULL,
	    WndTextEdit,
	    &resTypes[rsTEXT]
	},
	{//SOUND
    },
	{//MEM
    },
	{//VOCAB
		NULL,NULL,
	    WndVocabEdit,
	    &resTypes[rsVOCAB]
	},
	{//FONT
		NULL,NULL,
	    WndGfxEdit,
	    &resTypes[rsFONT]
    },
	{//CURSOR
		NULL,NULL,
	    WndGfxEdit,
	    &resTypes[rsCURSOR]
    },
	{//PATCH
    },
	{//BITMAP
    },
	{//PALETTE
    },
	{//CDA
    },
	{//AUD
    },
	{//SYN
    },      
	{//MSG
    },
	{//MAP
    },
	{//HEP
    },
	{//HEADER
    },     
	{
    },   
	{
    },   
	{
    },   
	{
    },   
	{
    },   
	{
    },   
	{
    },   
	{
    },   
	{
    },   
	{
    },
	{//EXPLORER
		NULL,NULL,
	    WndExplorer,
	    &resTypes[wnEXPLORER]
	}
};
//---------------------------------------------------------------------------
BOOL InitEditWnds()
{
	totalEdtWnds	= 0;
    edtWndFirst		= NULL;
    edtWndLast		= NULL;
    WndExplorer 	= NULL;

    winNum = 0;

    return TRUE;
}
//---------------------------------------------------------------------------
BOOL DisposeEditWnds()
{
	if(totalEdtWnds) return FALSE; // WndMain closes everything with CloseGame1Click
	totalEdtWnds	= 0;
    edtWndFirst		= NULL;
    edtWndLast		= NULL;
    WndExplorer 	= NULL;

	return TRUE;
}
//---------------------------------------------------------------------------
// Opens up a new editor window
// - used for stand alone windows as well as explorer game resource editors
// - for the explorer, resInfo and resBuf can be passed which will cause
//   the editor to open the resource up for editing. After NewEditWnd is
//   called, explorer will take care of freeing the buffer

#define CREATE_INIT_WND(type)\
   			edtWnd->Wnd = new type(WndMain); \
            ((type*)edtWnd->Wnd)->InitEditor(edtWnd, resBuf, resVer)
EDTWND *NewEditWnd(int resType, RESINFO *resInfo, U16 flags, U8 *resBuf, S16 resVer)
{
	EDTWND *edtWnd;

    edtWnd = (EDTWND*)ssAlloc(sizeof(EDTWND));
    memcpy(edtWnd,resTypes[resType].edtWnd,sizeof(EDTWND));
	if(!edtWndFirst)
    	edtWndFirst			= edtWnd;
    edtWnd->prev			= edtWndLast;
	edtWnd->next			= NULL;
	if(edtWndLast)
    	edtWndLast->next	= edtWnd;
    edtWndLast				= edtWnd;

    if(resInfo)
    	SetResIDfo(&edtWnd->resIDfo,resInfo);
    else {
     	edtWnd->resIDfo.type = resType;
        edtWnd->resIDfo.number = 0;
        edtWnd->resIDfo.size = 0;
        edtWnd->resIDfo.pack = Game.defaultPack;
    }
    edtWnd->flags = flags;

    edtWnd->fileName[0] = '\0'; // clear it.

    switch(resType) {
     	case rsVIEW:
            CREATE_INIT_WND(TWndGfxEdit);
    		((TWndGfxEdit*)edtWnd->Wnd)->pnTools->Tag = winNum;
        	break;
     	case rsPIC:
            CREATE_INIT_WND(TWndPicEdit);
        	break;
     	case rsSCRIPT:
     	case lvHEADER:
            CREATE_INIT_WND(TWndScriptEdit);
        	break;
     	case rsTEXT:
            CREATE_INIT_WND(TWndTextEdit);
        	break;
     	case rsVOCAB:
            CREATE_INIT_WND(TWndVocabEdit);
        	break;
     	case rsFONT:
            CREATE_INIT_WND(TWndGfxEdit);
    		((TWndGfxEdit*)edtWnd->Wnd)->pnTools->Tag = winNum;
        	break;
     	case rsCURSOR:
            CREATE_INIT_WND(TWndGfxEdit);
    		((TWndGfxEdit*)edtWnd->Wnd)->pnTools->Tag = winNum;
        	break;

     	case wnEXPLORER:
            CREATE_INIT_WND(TWndExplorer);
        	break;
        default:;
    }

    WndMain->ilTreeView->GetIcon(edtWnd->resType->iconIndex, edtWnd->Wnd->Icon);
    DrawMenuBar(WndMain->Handle);

 	winNum++;

    edtWnd->Wnd->OnClose = WndMain->EditFormClose;
    WndMain->AddToTaskbar(edtWnd);

    totalEdtWnds++;

    return edtWnd;
}
//---------------------------------------------------------------------------
int ParseSaveChanges(EDTWND *edtWnd)
{
	int result;
	if(edtWnd->flags & ewRES_CHANGED) {
        if(edtWnd->flags & ewEXPLORER_EDITOR)
        	result = ssMessage(ssNOTICE|ssYESNOCANCEL,
        		"Would you like to save your changes made to %s.%03d?",
            	resTypes[edtWnd->resIDfo.type].name,edtWnd->resIDfo.number);
        else
        	result = ssMessage(ssNOTICE|ssYESNOCANCEL,
        		"Would you like to save your changes made to %s?",
            	edtWnd->fileName);
        if(result==IDYES)
        	return SVCHG_YES;
        if(result==IDCANCEL)
        	return SVCHG_CANCEL;
    }
    return SVCHG_NO;
}
//---------------------------------------------------------------------------
BOOL FreeEditWnd(EDTWND *edtWnd)
{
    WndMain->DeleteFromTaskbar(edtWnd);

	if(edtWnd->prev) edtWnd->prev->next = edtWnd->next;
    else edtWndFirst = edtWnd->next;
    if(edtWnd->next) edtWnd->next->prev = edtWnd->prev;
    if(edtWnd==edtWndLast)
    	edtWndLast = edtWnd->prev;

    WRITE_STATUS(edtWnd->Wnd->Caption+" closed.");

    totalEdtWnds--;
    ssFree(edtWnd);

    return TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TWndMain::EditFormClose(System::TObject *Sender,TCloseAction &Action)
{
	Action = caNone;
	EDITORTAG *edTag = (EDITORTAG*)(((TForm*)Sender)->Tag);
	EDTWND *edtWnd = edTag->edtWnd;
	if(edtWnd->resType->index<TOTAL_RES_TYPES) {
    	if(config.QUERY_SAVING) {
			int result;
        	if(edtWnd->resType->index==rsSCRIPT)
        		result = ((TWndScriptEdit*)edtWnd->Wnd)->ParseSaveChanges();
        	else
        		result = ParseSaveChanges(edtWnd);
			if(result!=SVCHG_NO) {
				if(result==SVCHG_CANCEL) return;
    			edTag->SaveRes(edTag);
				if(edtWnd->flags & ewRES_CHANGED) return;
    		}
        }
    } else if(edtWnd->resType->index == wnEXPLORER) {
    	if(!(edtWnd->flags&ewCLOSING_EXPLORER)) {
    		WndMain->CloseGame1Click(WndMain);
            edtWnd->flags&=~ewCLOSING_EXPLORER;
			return;
    	}
    } else if(!edTag->QueryClose(edTag)) return;

    Action = caFree;       
	((TForm*)Sender)->Enabled=FALSE;
                         
	((TForm*)Sender)->Tag=NULL;
    edTag->EditorClose(edTag);

    FreeEditWnd(edtWnd);
}
//---------------------------------------------------------------------------
void UpdateCaption(EDTWND *edtWnd, TForm *Form, AnsiString DefCaption)
{
	if(edtWnd->resType->index != rsSCRIPT) {
    	if(!(edtWnd->flags & ewEXPLORER_EDITOR))
    		Form->Caption = DefCaption+" - "+ExtractFileName(AnsiString(edtWnd->fileName));
    	else
    		Form->Caption = DefCaption+" - "+AnsiStringFmtRes(edtWnd->resIDfo.type,edtWnd->resIDfo.number);
    }
    WndMain->UpdateTaskBarCaption(edtWnd->taskTab);
}
//---------------------------------------------------------------------------


 