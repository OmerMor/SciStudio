//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <windows.h>
#pragma hdrstop

#include "main.h"
#include "viewedit.h"
#include "explorer.h"
#include "gfxedits.h"
#include "viewani.h"
#include "fonttest.h"
#include "viewfont.h"
#include "expcels.h"  
#include "config.h"
#include "paledit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MenuBar"
#pragma resource "*.dfm"
TWndGfxEdit *WndGfxEdit;
//---------------------------------------------------------------------------
#define MAX_SELCEL_WIDTHX	32
#define MAX_SELCEL_HEIGHTX	54
#define MAX_SELCEL_WIDTH	28
#define MAX_SELCEL_HEIGHT	50
#define RESET_SRL_MAX() \
        int newMax;  \
    	newMax = (loopReal->totalCels-(imCels->Width/climW)); \
        sbrCels->Max = (newMax<0)?0:newMax;

#define RESET_SRL_POS() \
    	sbrCels->Position = 0;

#define RESET_SRL_CHARS() \
    	RESET_SRL_POS(); \
    	RESET_SRL_MAX()
//---------------------------------------------------------------------------
#define MAX_SELCHAR_WIDTHX	54
#define MAX_SELCHAR_HEIGHTX	54
#define MAX_SELCHAR_WIDTH	52
#define MAX_SELCHAR_HEIGHT	52

#define RESET_FSRL_MAX() \
        int newMax;  \
    	newMax = (font->totalChars-(imChars->Height/chimH)); \
        sbrChars->Max = (newMax<0)?0:newMax;

#define RESET_FSRL_POS() \
    	sbrChars->Position = 0;

#define RESET_FSRL_CHARS() \
    	RESET_FSRL_POS(); \
    	RESET_FSRL_MAX()
//---------------------------------------------------------------------------
void gxEditorClose(EDITORTAG *edtTag)
{
	TWndGfxEdit *form = ((TWndGfxEdit*)edtTag->Form);

    form->CAN_DRAW = FALSE;

    form->CancelSelection();
    form->tmrSelCel->Enabled = FALSE;
    form->tmrSelection->Enabled = FALSE; // just to make sure
    form->tmrSelChar->Enabled = FALSE;
    form->tmrSelCel->OnTimer = NULL;
    form->tmrSelection->OnTimer = NULL; // just to make sure
    form->tmrSelChar->OnTimer = NULL;
	form->Panel6->OnResize = NULL;

    form->Panel6->OnResize = NULL;
	form->cbLoopMirror->OnChange = NULL;
	form->sbrCels->OnChange = NULL;
	form->sbrChars->OnChange= NULL;
	form->OnKeyDown= NULL;

	FULL_DELETE(form->bmSurface);
	FULL_DELETE(form->bmSavedSurface);
	FULL_DELETE(form->bmSelection);
    form->bmRz = NULL;

    ViewDispose(form->view);
    FontDispose(form->font);
    CursorDispose(form->cursor);
}
//---------------------------------------------------------------------------
void gxSaveRes(EDITORTAG *edtTag)
{
	((TWndGfxEdit*)edtTag->Form)->Save1Click(edtTag->Form);
}
//---------------------------------------------------------------------------
BOOL TWndGfxEdit::InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 _resVer)
{
    resType = _edtWnd->resType->index;
    resVer = _resVer;
	Caption = AnsiString(resTypes[resType].name)+" Editor";
    edTag.EditorClose = gxEditorClose;
    edTag.SaveRes = gxSaveRes;
    edTag.edtWnd = _edtWnd;
    strcpy(edTag.defCaption,Caption.c_str());
    edTag.Form = this;
	Tag = (int)&edTag;

    maxUndos = config.maxUndos;
    ScrollBox1->Color = WndMain->Color;

	if(resBuf) {
		LoadRes(resBuf, edTag.edtWnd->resIDfo.size);
    } else {
    	NewRes(resType,resVer);
    }
	UPDATE_CAPTION();


    if(!WndExplorer)
    	SaveToGame1->Visible = FALSE;
    else {
		SET_EXPLORERED();
    }
    
	return TRUE;
}
//---------------------------------------------------------------------------
void TWndGfxEdit::SetUpNew()
{
    if(resType==rsCURSOR)
    	bmRz			= NULL;
    else
    	bmRz			= WndMain->imResize->Picture->Bitmap;

    pnView->Visible = FALSE;
    pnView->Enabled = FALSE;
    tmrSelCel->Enabled = FALSE;
    tmrSelChar->Enabled = FALSE;
    tbAnimate->Visible = FALSE; 
    ViewMenu->Visible = FALSE;
    ExportCelsToBitmapBMP1->Visible = FALSE;  
    pnPal->Visible = FALSE;
    pnFont->Visible = FALSE;
    pnFont->Enabled = FALSE;
    FontMenu->Visible = FALSE;
    tbViewFont->Visible = FALSE;
    tbFontTest->Visible = FALSE;
    CursorMenu->Visible = FALSE;

	switch(resType) {
    	case rsVIEW:
        	pal = &palEGA;
            pnView->Visible = TRUE;
            pnView->Enabled = TRUE;
    		shCol1->Brush->Color = pal->cols[0];
    		shCol2->Brush->Color = pal->cols[pal->bitdepth-1];
            ViewMenu->Visible = TRUE;
            ExportCelsToBitmapBMP1->Visible = TRUE;
            tbAnimate->Visible = TRUE;
    		pnPal->Visible = TRUE;
            pnVGAPal->Visible = resVer!=sv_VT_EGA;
        	break;
    	case rsFONT:
        	pal = &palFont;    
            imPal->Height = 0;
            pnPal->Visible = FALSE;
            pnFont->Visible = TRUE;
            pnFont->Enabled = TRUE;
    		shCol1->Brush->Color = pal->cols[1];
    		shCol2->Brush->Color = pal->cols[0];
            FontMenu->Visible = TRUE;
            tbViewFont->Visible = TRUE;
            tbFontTest->Visible = TRUE;
        	break;
    	case rsCURSOR:
        	pal = resVer==sv_CT_2COL?&palCursor:&palCursorVGA;
    		shCol1->Brush->Color = pal->cols[0];
    		shCol2->Brush->Color = pal->cols[1];
            CursorMenu->Visible = TRUE;
    		pnPal->Visible = TRUE;
            UpdatePalette(2,2);
        	break;
    }

    if(resType==rsVIEW&&resVer==sv_VT_VGA10) {
     	pnPalette->Height = 160;
     	pnPal->Height = 98;
     	pnPal->Width = 98;
     	pnCol->Top = 104;
    } else {
     	pnPalette->Height = 60;
     	pnPal->Height = 52;
     	pnPal->Width = 52;
     	pnCol->Top = 4;
    }
                          
    MenuBar1->Visible = FALSE;
    MenuBar1->Menu = NULL;
    MenuBar1->Menu = MainMenu1;
    MenuBar1->Visible = TRUE;

    InitUndos();

    newCount = 0;
    AskSave = 0;

    tbCurTool = NULL;
    sbToolsClick(sbPen);
    pbSurfacePaint(this);
}
//---------------------------------------------------------------------------
__fastcall TWndGfxEdit::TWndGfxEdit(TComponent* Owner)
	: TForm(Owner)
{
    MOUSE_DOWN = FALSE;
    CAN_DRAW = FALSE;

    bmSurface			= NULL;
    bmSavedSurface		= new Graphics::TBitmap;
    bmSelection      	= NULL;

    MIRRORING			= FALSE;

    zoomLv 				= 3;

    view				= NULL;
    loop				= NULL;
    loopReal			= NULL;
    cel					= NULL;
    font				= NULL;
    fChar				= NULL;
    cursor				= NULL;

    tbCurTool			= NULL;

    acBits				= NULL;

    canvasRz			= CRZ_NONE;
    CANVAS_RESIZING		= FALSE;

    SELECTION_ACTIVE	= FALSE;
    DRAW_SELECTY 		= FALSE;

    celsRect.left		= -1;

    aniSpeed			= 2;

    Shift1Click(WithLoop1);
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::pnToolsDockDrop(TObject *Sender,
      TDragDockObject *Source, int X, int Y)
{
	AnsiString C = ((TPanel*)Source->Control)->Caption;
	if(C=="Drawing Tools") {
            Source->Control->Align = alTop;
            Source->Control->Top = 0;
    } else if(C=="Palette") {
            Source->Control->Align = alTop;
            Source->Control->Top = 200;
    } else if(C=="Coords") {
            Source->Control->Align = alBottom;
            Source->Control->Top = pnTools->Height;
    }
}
//---------------------------------------------------------------------------
BOOL TWndGfxEdit::SaveRes()
{
	U8 *buf;
    U16 len;  

    CAN_DRAW = FALSE;

    if((!CHECK_EXPLORERED())&&(CHECK_RESNEW()||(edTag.edtWnd->fileName[0]=='\0'))) {
        SaveAs1Click(this);
    	CAN_DRAW = TRUE;
        return TRUE;
    }

    SetSelection();
	switch(resType) {
    	case rsVIEW:
            buf = ViewSave(view, &len,resVer);
        	break;
    	case rsFONT:
            buf = FontSave(font, &len);
        	break;
    	case rsCURSOR:
            buf = CursorSave(cursor, &len);
        	break;
    }               
	if(!buf) {
     	ssMessage(ssERROR,"An error occured while saving the resource");  
    	CAN_DRAW = TRUE;
        return FALSE;
    }
    if(CHECK_EXPLORERED()) {
        RESINFO *newRI = WndExplorer->SaveResToGame(buf, len, resType, EDTTAG->edtWnd->resIDfo.number);
     	if(!newRI) {
    		ssFree(buf);
    		CAN_DRAW = TRUE;
    		return FALSE;
        } else SetResIDfo(&EDTTAG->edtWnd->resIDfo,newRI);
    } else {
        FILE *fFile;
        if((fFile=ssOpenFile(ssFIO_ROOT|ssFIO_MESSAGE,edTag.edtWnd->fileName,"wb"))==NULL) {
    		CAN_DRAW = TRUE;
            return FALSE;
        }
        ssFPutW((0x80|resType),fFile);
        ssFWrite(buf,len,fFile);
        ssCloseFile(fFile);
    }
    ssFree(buf);

    CLEAR_RESCHANGED();
    UPDATE_CAPTION();   
    CLEAR_RESNEW();
	

    CAN_DRAW = TRUE;
    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndGfxEdit::LoadRes(U8 *buf, U32 len)
{
	U8 *newB=NULL,*uBuf;
    sciVIEW   *v;
    sciFONT   *f;
    sciCURSOR *c;

    CAN_DRAW = FALSE;
	if(buf==NULL||len==0) {
		OpenDialog->Filter = resTypes[resType].filter;
    	if(!OpenDialog->Execute()) {
    		CAN_DRAW = TRUE;
        	return FALSE;
        }
   		if((newB=ssLoadFile(ssFIO_ROOT|ssFIO_MESSAGE, OpenDialog->FileName.c_str(), &len))==NULL) {
    		CAN_DRAW = TRUE;
    		return FALSE;
        }
    	if(CheckSCIFileHeader(newB)!=resType) {
			ssMessage(ssERROR,"The file your are trying to open, %s, is not a valid SCI %s resource, or does not contain a valid header",OpenDialog->FileName.c_str(),resTypes[resType].name);
        	ssFree(newB);
    		CAN_DRAW = TRUE;
        	return FALSE;
    	}
        if(OpenDialog->FileName.Length()>ssMAX_PATH_LEN) {
         	ssMessage(ssERROR,"The file path is too long!");
        	ssFree(newB);
    		CAN_DRAW = TRUE;
        	return FALSE;
        }                 
    	CLEAR_EXPLORERED();
    	strcpy(edTag.edtWnd->fileName,OpenDialog->FileName.c_str());
    	uBuf = newB+2;
        len-=(U16)2;
    } else
    	uBuf = buf;

	CloseRes();
    CLEAR_RESCHANGED();   
    CLEAR_RESNEW();    
	SetUpNew();
	switch(resType) {
    	case rsVIEW:
			if((v = ViewLoad(uBuf,len,resVer))==NULL) return FALSE;
            view = v;
			ViewSetUpUpDowns(view,udLoop,udCel);
    		ChangeLoopCel(0,0,TRUE);         
            UpdatePalette(0,0);
        	break;
    	case rsFONT:    
			if((f = FontLoad(uBuf,len))==NULL) return FALSE;
            font = f;
    		ChangeChar(0,TRUE);
        	break;
    	case rsCURSOR:
			if((c = CursorLoad(uBuf,len))==NULL) return FALSE;
            cursor = c;
    		ChangeCursor();
        	break;
    }

    ssFree(newB);

	CAN_DRAW = TRUE;
    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndGfxEdit::UpdateRes()
{
	switch(resType) {
    	case rsVIEW:
			ChangeLoopCel(loop->loop,cel->cel,FALSE);
            break;
        case rsFONT:
			ChangeChar(fChar->index,FALSE);
            break;
        case rsCURSOR:
			ChangeCursor();
            break;
	}
    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndGfxEdit::NewRes(int type, int depth)
{
	CAN_DRAW = FALSE;
   	CloseRes();
    resType = type;
    sprintf(edTag.edtWnd->fileName,"%s.n%02d",resTypes[resType].name,newCount);
    SET_RESNEW();
    CLEAR_RESCHANGED();
    newCount++;  
    resVer = depth;
    SetUpNew();
	switch(resType) {
    	case rsVIEW:
			NewView();
            break;
        case rsFONT:
        	NewFont();
            break;
        case rsCURSOR:
        	NewCursor();
            break;
	}
	CAN_DRAW = TRUE;
    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndGfxEdit::CloseRes()
{
	switch(resType) {
    	case rsVIEW:
            break;
        case rsFONT:
            break;
        case rsCURSOR:
            break;
	}    
	CancelSelection();
    ClearUndos();
    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndGfxEdit::NewView()
{
	if((view = ViewLoad(defView,sizeof(defView),resVer))==NULL) return FALSE;
	ViewSetUpUpDowns(view,udLoop,udCel);
    ChangeLoopCel(0,0,TRUE);
    UpdatePalette(0,0);

    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndGfxEdit::NewFont()
{
	if((font = FontLoad(defFont,sizeof(defFont)))==NULL) return FALSE;
    ChangeChar(0,TRUE);

    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndGfxEdit::NewCursor()
{
	if((cursor = CursorLoad(defCursor,sizeof(defCursor)))==NULL) return FALSE;
    ChangeCursor();
    return TRUE;
}
//---------------------------------------------------------------------------
edUNDO* TWndGfxEdit::GetUndo(int i)
{
	edUNDO *u=firstUndo;
    while(u) {
    	if(i==0) return u;
        i--;
    	u=u->next;
    }
    return NULL;
}
//---------------------------------------------------------------------------
void TWndGfxEdit::DeleteUndo(edUNDO* undo)
{
	ssFree(undo->bits);
    if(undo==firstUndo)
    	firstUndo = undo->next;
	if(undo->next)
    	undo->next->prev = undo->prev;
	if(undo->prev)
    	undo->prev->next = undo->next;
	ssFree(undo);

    undoTotal--;
}
//---------------------------------------------------------------------------
void TWndGfxEdit::UpdateUndos()
{
	if(undoPtr==0) {
		sbUndo->Enabled = FALSE;
		Undo1->Enabled  = FALSE;
    } else {
		sbUndo->Enabled = TRUE;
		Undo1->Enabled  = TRUE;
    }  
	if(!undoTotal||undoPtr>=undoTotal-1) {
		sbRedo->Enabled = FALSE;
		Redo1->Enabled  = FALSE;
	} else {
		sbRedo->Enabled = TRUE;
		Redo1->Enabled  = TRUE;
	}
}
//---------------------------------------------------------------------------
edUNDO* TWndGfxEdit::AddUndo(AnsiString desc)
{
    CAN_DRAW = FALSE;
	if(desc!="")
    	ClearRedos();
	undoXOX = FALSE;

    if(undoPtr==maxUndos) {
     	DeleteUndo(firstUndo);
        undoPtr--;
    }

    edUNDO *nextUndo = GetUndo(undoPtr);
    edUNDO *curUndo = GetUndo(undoPtr-1);
	edUNDO *newUndo = (edUNDO*)ssAlloc(sizeof(edUNDO)); 
    if(!nextUndo)
    	nextUndo=nextUndo;
    if(!firstUndo)
    	firstUndo = newUndo;

	newUndo->prev = curUndo;
    if(curUndo)
    	curUndo->next = newUndo;
    newUndo->next  = nextUndo;
    if(nextUndo)
    	nextUndo->prev = newUndo;

	newUndo->width = acWidth;
    newUndo->height = acHeight;
    newUndo->bits = (U8*)ssAlloc(acWidth*acHeight);
    memcpy(newUndo->bits,acBits,acWidth*acHeight);

    newUndo->n = undoPtr;

    undoTotal++;
    undoPtr++;

    UpdateUndos();

    CAN_DRAW = TRUE;
    return newUndo;
}
//---------------------------------------------------------------------------
void TWndGfxEdit::SetUndo(edUNDO *u)
{
	CAN_DRAW  = FALSE;
	ssFree(acBits);
	acWidth  = u->width;
    acHeight = u->height;
    acBits = (U8*)ssAlloc(acWidth*acHeight);
    memcpy(acBits,u->bits,acWidth*acHeight);

    StoreBits();
	switch(resType) {
    	case rsVIEW:
    		ChangeLoopCel(loop->loop, cel->cel, TRUE);
            break;
        case rsFONT:
    		ChangeChar(fChar->index, TRUE);
            break;
        case rsCURSOR:
    		DeletePaledBitmap(bmSurface);
			bmSurface = CursorDrawBitmap(cursor,pal);
			PaintSurface();
            break;
	}
	CAN_DRAW  = TRUE;
}
//---------------------------------------------------------------------------
void TWndGfxEdit::DoRedo()
{
	edUNDO *u;
	u = GetUndo(undoPtr+1);
    undoPtr++;
	SetUndo(u);
    UpdateUndos();
	undoXOX = TRUE;
}
//---------------------------------------------------------------------------
void TWndGfxEdit::DoUndo()
{
	edUNDO *u;      
	u = GetUndo(undoPtr-1);
	if(!undoXOX) {
    	AddUndo("");
		undoPtr-=2;
    	undoXOX = TRUE;
    } else {
		undoPtr--;
    }
	SetUndo(u);
    UpdateUndos();
}
//---------------------------------------------------------------------------
void TWndGfxEdit::InitUndos()
{
	Undo1->Enabled = FALSE;
    sbUndo->Enabled = FALSE;
    Redo1->Enabled = FALSE;
    sbRedo->Enabled = FALSE;

	undoTotal  = 0;
    firstUndo  = NULL;
    undoPtr    = 0;

	undoXOX = FALSE;
    undoYOY = FALSE;
}
//---------------------------------------------------------------------------
void TWndGfxEdit::ClearUndos()
{                 
	while(firstUndo)
    	DeleteUndo(firstUndo);
    InitUndos();
}
//---------------------------------------------------------------------------
void TWndGfxEdit::ClearRedos()
{
	if(undoPtr) {
    	edUNDO *u = GetUndo(undoPtr-1);
    	edUNDO *q = GetUndo(undoPtr);
    	edUNDO *n;
    	if(!u)
        	u=u;
        while(q) {
            n = q->next;
			DeleteUndo(q);
            q = n;
        }
        undoTotal = undoPtr;
        u->next = NULL;
    } else {
    	firstUndo = NULL;
    }
}
//---------------------------------------------------------------------------
void TWndGfxEdit::SetBits(U8 *bits,int width,int height)
{
	ssFree(acBits);
	acBits = (U8*)ssAlloc(width*height);
    if(MIRRORING)
    	for(int y=0;y<height;y++)
        	for(int x=width-1;x>=0;x--)
            	acBits[y*width+x] = *bits++;
    else
    	memcpy(acBits,bits,width*height);
    acWidth = width;
    acHeight = height;
}
//---------------------------------------------------------------------------
void TWndGfxEdit::SaveBits()
{
	BitmapToBits(bmSurface,acBits,pal);
	StoreBits();
}
//---------------------------------------------------------------------------
void TWndGfxEdit::DisableInterface()
{
	pbSurface->Enabled = FALSE;
	pbSurface->OnPaint = NULL;

}
//---------------------------------------------------------------------------
void TWndGfxEdit::EnableInterface()
{
	pbSurface->Enabled = TRUE;
	pbSurface->OnPaint = pbSurfacePaint;
}
//---------------------------------------------------------------------------
void TWndGfxEdit::StoreBits()
{
	U8 *bits;
	DisableInterface();
	switch(resType) {
    	case rsVIEW:
        	cel->width = acWidth;
            cel->height = acHeight;
            ssFree(cel->data);
            cel->data = (U8*)ssAlloc(acWidth*acHeight);
    		if(MIRRORING) {
            	bits = acBits;
    			for(int y=0;y<acHeight;y++)
        			for(int x=acWidth-1;x>=0;x--) {
            			cel->data[y*acWidth+x] = *bits++;
                    }
            } else
    			memcpy(cel->data,acBits,acWidth*acHeight);

            DrawSelsCel();
            break;
        case rsFONT:
        	fChar->width = acWidth;
            fChar->height = acHeight;
            ssFree(fChar->data);
            fChar->data = (U8*)ssAlloc(acWidth*acHeight);
            memcpy(fChar->data,acBits,acWidth*acHeight);

            DrawSelsChar();
            break;
        case rsCURSOR:
            memcpy(cursor->data,acBits,sCSR_SIZE);
            break;
	}
    SET_RESCHANGED();
	EnableInterface();
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::udLoopCelClick(TObject *Sender,
      TUDBtnType Button)
{
	if( ((TUpDown*)Sender)->Tag ) {// loop up down
		ViewSetCelUpDown(ViewGetLoop(view,udLoop->Position),udCel);
    	ChangeLoopCel(udLoop->Position,udCel->Position,TRUE);
    } else
    	ChangeLoopCel(udLoop->Position,udCel->Position,FALSE);
}
//---------------------------------------------------------------------------
void TWndGfxEdit::ChangeLoopCel(int lNum, int cNum, BOOL SELO)
{
	if(cel) {
    	if(SELECTION_ACTIVE&&cel->cel==cNum) return;
    	if(cel->cel!=cNum) {
    		ClearUndos();
    		SetSelection();
        }
    }

    loop 				= ViewGetLoop(view,lNum);
    loopReal 			= GetRealLoop(loop);
    cel 				= ViewLoopGetCel(loopReal,cNum);
    edWidth->Text 		= IntToStr(cel->width);
    edHeight->Text 		= IntToStr(cel->height);
    edX->Text 			= IntToStr(cel->x);
    edY->Text 			= IntToStr(cel->y);
                                    
	udLoop->Max 		= view->totalLoops-1;
    udLoop->Enabled		= (udLoop->Max);
	udCel->Max 			= loopReal->totalCels-1;  
    udCel->Enabled		= (udCel->Max);
	udLoop->Position 	= lNum;
	udCel->Position 	= cNum;
    lbLoop->Caption 	= IntToStr(lNum)+"/"+IntToStr(udLoop->Max);
    lbCel->Caption  	= IntToStr(cNum)+"/"+IntToStr(udCel->Max);

    cbLoopMirror->Items->Clear();
    for(int i=0;i<view->totalLoops;i++) {
    	if(i==lNum)
    		cbLoopMirror->Items->Add("None");
        else
    		cbLoopMirror->Items->Add("Loop "+IntToStr(i));
    }
    cbLoopMirror->ItemIndex = loopReal->loop;
    MIRRORING = (loopReal!=loop);

    shpTCol->Brush->Color = pal->cols[cel->transCol];

    SetBits(cel->data,cel->width,cel->height);
    DeletePaledBitmap(bmSurface);
	bmSurface = ViewDrawCelBitmap(view,lNum,cNum,(view->palVGA)?&(view->palVGA->pal):&palEGA);
	PaintSurface();
                          
    udLoop->Position = lNum;
    udCel->Position = cNum;

	if(SELO)
     	SetUpCelsSelector();
    DrawCelSelImg(TRUE);
}
//---------------------------------------------------------------------------
void TWndGfxEdit::SetUpCelsSelector()
{
    sPOINT p = GetLoopMaxSize(loopReal);
	int maxWidth=p.x,maxHeight=p.y;
	drawPercent = (float)MAX_SELCEL_HEIGHT/(float)maxHeight;
	if((float)maxWidth*(float)drawPercent>(float)MAX_SELCEL_WIDTH)
		drawPercent = (float)MAX_SELCEL_WIDTH/(float)maxWidth;    
    climW = (maxWidth * drawPercent)+4;
	RESET_SRL_MAX();
}

//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::DrawCelSelImg(BOOL FIX_UP)
{
    int drawWidth,drawHeight;
	tmrSelCel->Enabled = FALSE;

	int startCel = sbrCels->Position;
	int endCel;
    endCel = startCel + (imCels->Width/MAX_SELCEL_WIDTH);
    if(endCel>=loopReal->totalCels)
    	endCel = loopReal->totalCels-1;
    if(FIX_UP) {
    	if(cel->cel<startCel)
    		startCel += cel->cel-startCel;
   	 	else if(cel->cel>endCel)
    		startCel -= endCel-cel->cel;
        endCel = startCel + (imCels->Width/MAX_SELCEL_WIDTH);
        if(endCel>=loopReal->totalCels)
        	endCel = loopReal->totalCels-1;
        sbrCels->Position = startCel;
    }


	Graphics::TBitmap *bmpCels = new Graphics::TBitmap;
	bmpCels->Height = imCels->Height;
	bmpCels->Width = imCels->Width;
    int x=2;
    bmpCels->Canvas->Pen->Color = clBlack;
    bmpCels->Canvas->Brush->Color = clBtnFace;
    bmpCels->Canvas->FillRect(Rect(0,0,imCels->Width,imCels->Height));
    bmpCels->Canvas->Brush->Style = bsClear;
    celsRect.left = -1;
	for(int t=startCel;t<=endCel;t++) {

		Graphics::TBitmap *b = ViewDrawCelBitmap(view,loop->loop,t,(view->palVGA)?&(view->palVGA->pal):&palEGA);
        drawHeight = b->Height*drawPercent;
        drawWidth = b->Width*drawPercent;
        int y1=(bmpCels->Height-drawHeight)>>1;
        int x1=x+((climW-drawWidth)>>1);
        if(t==cel->cel) {
         	celsRect.left	= x1;
         	celsRect.top	= y1;
         	celsRect.right	= x1+drawWidth;
         	celsRect.bottom	= y1+drawHeight;
        }
        bmpCels->Canvas->Rectangle(
        	Rect(x1-1,y1-1,x1+drawWidth+1,y1+drawHeight+1)
        );
		bmpCels->Canvas->CopyRect(
			Rect(x1,y1,x1+drawWidth,y1+drawHeight),
			b->Canvas,
			Rect(0,0,b->Width,b->Height)
		);
		DeletePaledBitmap(b);
    	x+=climW;
    }
    imCels->Picture->Bitmap->Assign(bmpCels);
    delete bmpCels;

	tmrSelCel->Enabled = TRUE;
}
//---------------------------------------------------------------------------
void TWndGfxEdit::DrawSelsCel()
{
	if(celsRect.left==-1) return;
	Graphics::TBitmap *b = ViewDrawCelBitmap(view,loop->loop,cel->cel,(view->palVGA)?&(view->palVGA->pal):&palEGA);
    if(!b) return;
	imCels->Canvas->CopyRect(
		Rect(celsRect.left,celsRect.top,celsRect.right,celsRect.bottom),
		b->Canvas,
		Rect(0,0,b->Width,b->Height)
	);
	DeletePaledBitmap(b);
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::tmrSelCelTimer(TObject *Sender)
{
	if(!CAN_DRAW||!cel) return;

    int x = (cel->cel-sbrCels->Position)*climW+2;

    int drawHeight = cel->height*drawPercent;
    int drawWidth = cel->width*drawPercent;
    int y1=(imCels->Height-drawHeight)>>1;
    int x1=x+((climW-drawWidth)>>1);

    imCels->Canvas->Pen->Width = 2;
	imCels->Canvas->Brush->Style = bsClear;
    imCels->Canvas->Pen->Color = clFados[1][tmrSelCel->Tag];
    imCels->Canvas->Rectangle(x1,y1,x1+drawWidth+1,y1+drawHeight+1);

    tmrSelCel->Tag = (tmrSelCel->Tag+1)&0xF;
}         
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::sbrCelsChange(TObject *Sender)
{
	DrawCelSelImg(FALSE);
}    
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::imCelsMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int t=(sbrCels->Position)+((X/climW));
    if(t>=0&&t<loopReal->totalCels) {
    	ChangeLoopCel(loop->loop,t,FALSE);
    }
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::PaintSurface()
{
	if(!bmSurface) return;
	
	Graphics::TBitmap *b = new Graphics::TBitmap;

    int uW,uH;
    if(CANVAS_RESIZING) {uW=rzWidth*zoomLv;uH=rzHeight*zoomLv;}
    else {uW=acWidth*zoomLv;uH=acHeight*zoomLv;}
    if(bmRz) {
    	b->Width  = uW+4;
    	b->Height = uH+4;
    } else {
    	b->Width  = uW;
    	b->Height = uH;
    }
    if(SELECTION_ACTIVE) {
    	bmSurface->Canvas->CopyRect(
    		SelRect,
        	bmSelection->Canvas,
    		SelBounds
    	);
    }

    b->Canvas->CopyRect(
    	Rect(0,0,acWidth*zoomLv,acHeight*zoomLv),
        bmSurface->Canvas,
    	Rect(0,0,acWidth,acHeight)
    );

    b->Canvas->Pen->Mode = pmNot;
    b->Canvas->Pen->Width = 1;
    b->Canvas->Brush->Style = bsClear;
    b->Canvas->Pen->Style = psDot;
    if(SELECTION_ACTIVE) {
    	if(tmrSelection->Tag) {
        	// aargh! Can't Microsoft do anything right? Rects draw (x1,y1,x2-1,y2-1), lines draw(x1,y1,x2,y2)!
        	RECT r = {SelRect.Left*zoomLv,SelRect.Top*zoomLv,SelRect.Right*zoomLv-1,SelRect.Bottom*zoomLv-1};
        	b->Canvas->Rectangle(r.left,r.top,r.right+1,r.bottom+1);
    		/*b->Canvas->Pen->Style   = psSolid;
        	b->Canvas->Rectangle(r);
            */ // doesn't work in win98--stupid Microsoft makes the pen mode rule the brush in win98!
       		b->Canvas->Pen->Style   = psSolid;
            b->Canvas->MoveTo(r.left,r.top);
            b->Canvas->LineTo(r.right,r.top);
            b->Canvas->LineTo(r.right,r.bottom);
            b->Canvas->LineTo(r.left,r.bottom);
            b->Canvas->LineTo(r.left,r.top);
    	} else
        	b->Canvas->Rectangle(SelRect.Left*zoomLv,SelRect.Top*zoomLv,SelRect.Right*zoomLv,SelRect.Bottom*zoomLv);
    } else if(DRAW_SELECTY)
    	b->Canvas->Rectangle(dnX*zoomLv,dnY*zoomLv,mvX*zoomLv,mvY*zoomLv);

    if(bmRz) {
    	b->Width  = uW+4;
    	b->Height = uH+4;

    	b->Canvas->Brush->Color = clWhite;
    	b->Canvas->Pen->Color = clBlack;
    	b->Canvas->Pen->Mode = pmCopy;
    	b->Canvas->Pen->Style = psSolid;
    	b->Canvas->Rectangle(Rect(uW,-1,uW+4,uH+4));
    	b->Canvas->Rectangle(Rect(-1,uH,uW+4,uH+4));
    	b->Canvas->CopyRect(
    		Rect(uW,0,uW+4,uH+4),
        	bmRz->Canvas,
    		Rect(bmRz->Width-4,bmRz->Height-b->Height,bmRz->Width,bmRz->Height)
    	);
    	b->Canvas->CopyRect(
    		Rect(0,uH,uW+4,uH+4),
        	bmRz->Canvas,
    		Rect(bmRz->Width-b->Width,bmRz->Height-4,bmRz->Width,bmRz->Height)
    	);
    }
    pbSurface->Width = b->Width;
    pbSurface->Height = b->Height;
    pbSurface->Canvas->Draw(0,0,b);
    delete b;
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::pbSurfacePaint(TObject *Sender)
{
	pbSurface->OnPaint = NULL;
    PaintSurface();
	pbSurface->OnPaint = pbSurfacePaint;
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::pbSurfaceMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if(!CAN_DRAW) return;
    MOUSE_DOWN = TRUE;

	float hPcnt,vPcnt;
	dnX = CalcAct(X,zoomLv);
	dnY = CalcAct(Y,zoomLv);

	if(canvasRz) {
    	if(Shift.Contains(ssLeft)) {
        	CANVAS_RESIZING = TRUE;
            rzWidth  = acWidth;
            rzHeight = acHeight;
        }
        return;
    }
    CANVAS_RESIZING = FALSE;
    RESIZE_SELECTION = FALSE;

	pbSurface->Cursor = (TCursor)DRAWING_CURSOR;

    if(Shift.Contains(ssLeft)) {
    	bmSurface->Canvas->Brush->Color = shCol1->Brush->Color;
    	bmSurface->Canvas->Pen->Color   = shCol1->Brush->Color;
        c1 = shCol1->Brush->Color;
        c2 = shCol2->Brush->Color;
    } else if(Shift.Contains(ssRight)) {
    	bmSurface->Canvas->Brush->Color = shCol2->Brush->Color;
    	bmSurface->Canvas->Pen->Color   = shCol2->Brush->Color;  
        c2 = shCol1->Brush->Color;
        c1 = shCol2->Brush->Color;
    } else return;

	bmSurface->Canvas->Brush->Style = (TBrushStyle)sbBrushStyle->Tag;
	bmSurface->Canvas->Pen->Width = sbPenWidth->Tag;
	bmSurface->Canvas->Pen->Style = (TPenStyle)sbPenStyle->Tag;

    if(!SELECTION_ACTIVE) {
    	if(!DRAG_IN_SELECTION)
        	bmSavedSurface->Assign(bmSurface);
	} else {
    	if(GET_TOOL_GROUP(curTool)==TOOLS_SELECTION) {
        	if(curTool==TOOL_SELECTION||Shift.Contains(ssRight)) {
            	CancelSelection();
                PaintSurface();
                return;
 			}
            else
             	if(!InRect(SelRect,dnX,dnY)) {
            		SetSelection();
        			PaintSurface();
					return;
                }
        } else
			SetSelection();
        PaintSurface();
	}

    switch(curTool) {
    	case TOOL_PEN:
    		AddUndo("Draw With Pen");
            PenDraw(bmSurface,dnX,dnY);
            break;
    	case TOOL_REPLACE:
    		AddUndo("Draw With Replace Pen");
            PenReplaceDraw(bmSurface,dnX,dnY,c1,c2);
            break;
    	case TOOL_FILL:
    		AddUndo("Flood Fill");
            bmSurface->Canvas->FloodFill(dnX,dnY,bmSurface->Canvas->Pixels[dnX][dnY], fsSurface);
            break;
    	case TOOL_ARROW:
        	CancelSelection();
            break;
    	case TOOL_GRABBER:
            if(Shift.Contains(ssLeft))
            	shCol1->Brush->Color = bmSurface->Canvas->Pixels[dnX][dnY];
            else if(Shift.Contains(ssRight))
            	shCol2->Brush->Color = bmSurface->Canvas->Pixels[dnX][dnY];
            break;
    	case TOOL_ZOOM:
            if(Shift.Contains(ssLeft))
            	ZoomIn1Click(this);
            else
            	ZoomOut1Click(this);
            hPcnt = (float)dnX/(float)acWidth;
            vPcnt = (float)dnY/(float)acHeight;
            ScrollBox1->HorzScrollBar->Position = (((float)((float)ScrollBox1->HorzScrollBar->Range-ScrollBox1->Width)*hPcnt));
            ScrollBox1->VertScrollBar->Position = (((float)((float)ScrollBox1->VertScrollBar->Range-ScrollBox1->Height)*vPcnt));
            break;
        case TOOL_SELRESIZE:
        	RESIZE_SELECTION =
            	((dnX==SelRect.Left||dnX==SelRect.Right)&&(dnY>=SelRect.Top&&dnY<=SelRect.Bottom)) ||
                ((dnX>=SelRect.Left&&dnX<=SelRect.Right)&&(dnY==SelRect.Top||dnY==SelRect.Bottom));
        	break;
        case TOOL_SELMOVE:
        	if(DRAG_IN_SELECTION&&!InRect(SelRect,dnX,dnY)) {
            	SetSelection();
            }
        	DRAG_IN_SELECTION = (InRect(SelRect,dnX,dnY));
        	break;
        case TOOL_SELCOPY:
        	if(DRAG_IN_SELECTION&&!InRect(SelRect,dnX,dnY)) {
            	SetSelection();
            }
        	DRAG_IN_SELECTION = (InRect(SelRect,dnX,dnY));
        	break;
    }

	PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::pbSurfaceMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
	if(!view&&!cursor&&!font) return;
	int newH,newV;

	mvX = CalcAct(X,zoomLv);
	mvY = CalcAct(Y,zoomLv);
    if(mvX < 0)  mvX = 0;
    if(mvY < 0) mvY = 0;

	if(CANVAS_RESIZING) {
    	if(mvX!=dnX&&(canvasRz&CRZ_WIDTH)) {
            rzWidth  -= (dnX-mvX);
            dnX = mvX;         
            if(resType==rsVIEW)
            	edWidth->Text = IntToStr(rzWidth);
            else
            	edChWidth->Text = IntToStr(rzWidth);
        }
    	if(mvY!=dnY&&(canvasRz&CRZ_HEIGHT)) {
            rzHeight  -= (dnY-mvY);
            dnY = mvY;        
            if(resType==rsVIEW)
            	edHeight->Text = IntToStr(rzHeight);
            else
            	edChHeight->Text = IntToStr(rzHeight);
        }
        PaintSurface();
        return;
    }       
    if(mvX > acWidth)  mvX = acWidth;
    if(mvY > acHeight) mvY = acHeight;
	if((!DRAW_SELECTY)&&bmRz&&(X>=pbSurface->Width-4||Y>=pbSurface->Height-4)) {
    	if(!CANVAS_RESIZING) {
    		if(X>=pbSurface->Width-4) {
        		if(Y>=pbSurface->Height-4) {
        			canvasRz = CRZ_BOTH;
            		pbSurface->Cursor = crSizeNWSE;
            	} else {
        			canvasRz = CRZ_WIDTH;
            		pbSurface->Cursor = crSizeWE;
           	 	}
        	} else {
        		canvasRz = CRZ_HEIGHT;
        		pbSurface->Cursor = crSizeNS;
        	}
        }
    	return;
    }          
    if(((TWinControl*)Sender)->Tag==111) lbCoords->Caption = "X: "+IntToStr(mvX)+"  Y: "+IntToStr(mvY);

	pbSurface->Cursor = (TCursor)DRAWING_CURSOR;
    canvasRz = CRZ_NONE;

	if(!Shift.Contains(ssLeft)&&!Shift.Contains(ssRight)) return;

    DRAW_SELECTY = FALSE; 
	if(!CAN_DRAW||!MOUSE_DOWN) return;

    switch(curTool) {
    	case TOOL_PEN:
            PenDraw(bmSurface,mvX,mvY);
            break;
    	case TOOL_REPLACE:
            PenReplaceDraw(bmSurface,mvX,mvY,c1,c2);
            break;
    	case TOOL_LINE:
        	bmSurface->Canvas->Draw(0,0,bmSavedSurface);
            LineDraw(bmSurface,dnX,dnY,mvX,mvY);
            break;
    	case TOOL_RECT:
    	case TOOL_RECTF:
    	case TOOL_RRECT:
    	case TOOL_RRECTF:
    	case TOOL_ELLIPSE:
    	case TOOL_ELLIPSEF:
        	bmSurface->Canvas->Draw(0,0,bmSavedSurface);
            ShapeDraw(bmSurface,dnX,dnY,mvX,mvY,curTool);
            break; 
    	case TOOL_GRABBER:
            if(Shift.Contains(ssLeft))
            	shCol1->Brush->Color = bmSurface->Canvas->Pixels[mvX][mvY];
            else if(Shift.Contains(ssRight))
            	shCol2->Brush->Color = bmSurface->Canvas->Pixels[mvX][mvY];
            break;
    	case TOOL_SCROLL:
            if(Shift.Contains(ssLeft)) {
           		newH = ScrollBox1->HorzScrollBar->Position- (dnX-mvX)*ScrollBox1->HorzScrollBar->Increment;
            	dnX = mvX;
           		newV = ScrollBox1->VertScrollBar->Position-(dnY-mvY)*ScrollBox1->VertScrollBar->Increment;
            	dnY = mvY;
                if(newH>=0&&newH<=ScrollBox1->HorzScrollBar->Range)
                	ScrollBox1->HorzScrollBar->Position = newH;
                if(newV>=0&&newV<=ScrollBox1->VertScrollBar->Range)
                	ScrollBox1->VertScrollBar->Position = newV;
            }
            break;
        case TOOL_SELECTION:
        	DRAW_SELECTY = TRUE;   /*
        	bmSurface->Canvas->Draw(0,0,bmSavedSurface);
        	bmSurface->Canvas->Pen->Color	= (TColor) clBlack;
        	bmSurface->Canvas->Pen->Width	= 1;
        	bmSurface->Canvas->Pen->Style	= psDot;
        	bmSurface->Canvas->Pen->Mode	= pmCopy;
        	bmSurface->Canvas->Brush->Style	= bsClear;
			bmSurface->Canvas->Rectangle(Rect(dnX,dnY,mvX,mvY));  */
        	break;
        case TOOL_SELRESIZE:
        	if(!RESIZE_SELECTION||!SELECTION_ACTIVE) return;
    		if(dnX==SelRect.Left&&mvX!=dnX) {
            	SelRect.Left  -= (dnX-mvX);
            	dnX = mvX;
        	} else if(dnX==SelRect.Right&&mvX!=dnX) {
            	SelRect.Right -= (dnX-mvX);
            	dnX = mvX;
        	}
    		if(dnY==SelRect.Top&&mvY!=dnY) {
            	SelRect.Top     -= (dnY-mvY);
            	dnY = mvY;
        	} else if(dnY==SelRect.Bottom&&mvY!=dnY) {
            	SelRect.Bottom  -= (dnY-mvY);
            	dnY = mvY;
        	}
        	break;
        case TOOL_SELMOVE:
        	if(!DRAG_IN_SELECTION||!SELECTION_ACTIVE) break;
        	bmSurface->Canvas->Draw(0,0,bmSavedSurface);
            bmSurface->Canvas->Brush->Color = shCol2->Brush->Color;
            bmSurface->Canvas->FillRect(SelCutRect);
    		if(mvX!=dnX) {
            	SelRect.Left  -= (dnX-mvX);
            	SelRect.Right -= (dnX-mvX);
            	dnX = mvX;
        	}
    		if(mvY!=dnY) {
            	SelRect.Top     -= (dnY-mvY);
            	SelRect.Bottom  -= (dnY-mvY);
            	dnY = mvY;
        	}
        	break;
        case TOOL_SELCOPY:
        	if(!DRAG_IN_SELECTION||!SELECTION_ACTIVE) break;
        	bmSurface->Canvas->Draw(0,0,bmSavedSurface);
    		if(mvX!=dnX) {
            	SelRect.Left  -= (dnX-mvX);
            	SelRect.Right -= (dnX-mvX);
            	dnX = mvX;
        	}
    		if(mvY!=dnY) {
            	SelRect.Top     -= (dnY-mvY);
            	SelRect.Bottom  -= (dnY-mvY);
            	dnY = mvY;
        	}
        	break;
    }
	PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::pbSurfaceMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if(CANVAS_RESIZING) {
    	CANVAS_RESIZING		= FALSE;
        if(resType==rsVIEW)
        	ResizeCel(cel,rzWidth,rzHeight);
        else if(resType==rsFONT)
        	ResizeChar(fChar,rzWidth,rzHeight);  
    	SET_RESCHANGED();
    	return;
    }

	upX = CalcAct(X,zoomLv);
	upY = CalcAct(Y,zoomLv);
    if(upX > acWidth)  upX = acWidth;
    if(upY > acHeight) upY = acHeight;
    if(upX < 0)  upX = 0;
    if(upY < 0) upY = 0;
               
	if(!CAN_DRAW||!MOUSE_DOWN) return;
    MOUSE_DOWN = FALSE;

    switch(curTool) {
    	case TOOL_PEN:
    	case TOOL_REPLACE:
    	case TOOL_FILL:
    		SaveBits();
            break;
    	case TOOL_LINE:
			AddUndo("Draw Line");
    		LineDraw(bmSurface,dnX,dnY,upX,upY);
    		SaveBits();
            break;
    	case TOOL_RECT:
    	case TOOL_RECTF:
    	case TOOL_RRECT:
    	case TOOL_RRECTF:
    	case TOOL_ELLIPSE:
    	case TOOL_ELLIPSEF:
			AddUndo("Draw Shape");
        	bmSurface->Canvas->Draw(0,0,bmSavedSurface);
            ShapeDraw(bmSurface,dnX,dnY,upX,upY,curTool);   
    		SaveBits();
            break;
        case TOOL_SELECTION:    
        	if(dnX==upX||dnY==upY) break;
        	SetUpSelection(dnX, dnY, upX, upY);
            SelCutRect = SelRect;
            SELECTION_ACTIVE = TRUE;
        	break;    
        case TOOL_SELRESIZE:
        	if(dnX==upX||dnY==upY) break;
        	if(!RESIZE_SELECTION) return;
            SetUpSelection(SelRect.Left, SelRect.Top, SelRect.Right, SelRect.Bottom);
            break;
    }
	PaintSurface();
}

//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::SetUpSelection(int dnX, int dnY, int upX, int upY)
{
    		SelRect.Top 	= (dnY>upY)? upY:dnY;
    		SelRect.Left 	= (dnX>upX)? upX:dnX;
    		SelRect.Bottom 	= (dnY>upY)? dnY:upY;
    		SelRect.Right	= (dnX>upX)? dnX:upX;
    		SelBounds.Top 		= 0;
    		SelBounds.Left 		= 0;
    		SelBounds.Bottom 	= SelRect.Bottom-SelRect.Top;
    		SelBounds.Right		= SelRect.Right-SelRect.Left;
        	bmSurface->Canvas->Draw(0,0,bmSavedSurface);
            FULL_DELETE(bmSelection);
            bmSelection = new Graphics::TBitmap;
            bmSelection->Width	= SelBounds.Right;
            bmSelection->Height	= SelBounds.Bottom;
            bmSelection->Canvas->CopyRect(
            	SelBounds,
                bmSurface->Canvas,
              	SelRect
            );  
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::WindowsBitmap1Click(TObject *Sender)
{
	if(!OpenPictureDialog1->Execute()) return;
    if(!SELECTION_ACTIVE)
   	 	AddUndo("Import");

    Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
    pBitmap->LoadFromFile(OpenPictureDialog1->FileName);
    DropImage(pBitmap);
    delete pBitmap;
    
    if(!SELECTION_ACTIVE)
		SaveBits();      
    PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::ExportCelsToBitmapBMP1Click(TObject *Sender)
{
	TDlgExpCels *d = new TDlgExpCels(this,view,loop->loop);
    d->ShowModal();
    delete d;
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Open1Click(TObject *Sender)
{
	LoadRes(NULL,0);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Save1Click(TObject *Sender)
{
	SaveRes();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::SaveAs1Click(TObject *Sender)
{
	if(CHECK_EXPLORERED()) {
    	SaveDialog->FileName = AnsiStringFmtRes(edTag.edtWnd->resIDfo.type,edTag.edtWnd->resIDfo.number);
	} else if(edTag.edtWnd->fileName[0])
    	SaveDialog->FileName=AnsiString(edTag.edtWnd->fileName);

    SaveDialog->Filter=resTypes[resType].filter;
	if(SaveDialog->Execute()) {
    	CLEAR_EXPLORERED();
        CLEAR_RESNEW();
        strcpy(edTag.edtWnd->fileName,SaveDialog->FileName.c_str());
    	Save1Click(Sender);
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::SaveToGame1Click(TObject *Sender)
{
	SET_EXPLORERED(); 
	CLEAR_RESNEW();
    Save1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Undo1Click(TObject *Sender)
{
	DoUndo();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Redo1Click(TObject *Sender)
{
	DoRedo();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Cut1Click(TObject *Sender)
{
    Copy1Click(this);
    Clear1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Copy1Click(TObject *Sender)
{                    
    // generate a clipboard compatible bitmap
    Graphics::TBitmap *xBitmap = new Graphics::TBitmap;
    if(SELECTION_ACTIVE) {
		xBitmap->Width = bmSelection->Width;
		xBitmap->Height = bmSelection->Height;
    	xBitmap->Canvas->Draw(0,0,bmSelection);
    } else {
    	xBitmap->Width = bmSurface->Width;
    	xBitmap->Height = bmSurface->Height;
    	xBitmap->Canvas->Draw(0,0,bmSurface);
    }

    // Copy it to the clipboard
    Clipboard()->Assign(xBitmap);

    // Free it
    delete xBitmap;
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::DropImage(Graphics::TBitmap *pBitmap)
{
	int destW,destH,srcW,srcH;
    TRect destRect,srcRect;

	srcW 		= pBitmap->Width;
	srcH 		= pBitmap->Height;

    if(SELECTION_ACTIVE) {
		destW	= bmSelection->Width;
		destH	= bmSelection->Height;
    } else {
       	destW	= bmSurface->Width;
        destH	= bmSurface->Height;
    }
    destRect.left 	= 0;
    destRect.top 	= 0;
    srcRect.left 	= 0;
    srcRect.top 	= 0;
    if((destW!=srcW||destH!=srcH)&&(ssMessage(ssYESNO,"The image you are dropping is not the same size as the canvas. Would you like it to be scaled?")==ID_YES)) {
         	destRect.right 			= destW;
         	destRect.bottom			= destH;
         	srcRect.right 			= srcW;
         	srcRect.bottom			= srcH;
    } else {
			if(destW<srcW) {
				destRect.right 		= destW;
                srcRect.right 		= destW;
            } else {
				destRect.right 		= srcW;
                srcRect.right 		= srcW;
            }
			if(destH<srcH) {
				destRect.bottom 	= destH;
                srcRect.bottom 		= destH;
            } else {
				destRect.bottom 	= srcH;
                srcRect.bottom 		= srcH;
            }
    }

    if(SELECTION_ACTIVE) {
		bmSelection->Canvas->CopyRect(
        	destRect,
            pBitmap->Canvas,
            srcRect
        );
    } else {
		bmSurface->Canvas->CopyRect(
        	destRect,
            pBitmap->Canvas,
            srcRect
        );
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Paste1Click(TObject *Sender)
{
    TClipboard *pCB = Clipboard();
    if(!SELECTION_ACTIVE)
   	 	AddUndo("Paste");

    if(pCB->HasFormat(CF_BITMAP)) {
        Graphics::TBitmap *pBitmap = new Graphics::TBitmap();

        try {
            pBitmap->LoadFromClipboardFormat(CF_BITMAP, pCB->GetAsHandle(CF_BITMAP), 0);

			DropImage(pBitmap);
        }
        catch (...) {
            MessageBeep(0);
        }
        delete pBitmap;
    } else {
        MessageBeep(0);
        ShowMessage("Clipboard does not contain a valid Bitmap!");
    }      

    if(!SELECTION_ACTIVE)
		SaveBits();      
    PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Clear1Click(TObject *Sender)
{
    AddUndo("Clear");
    if(SELECTION_ACTIVE)
		ClearBitmap(bmSelection,shCol2->Brush->Color);
    else {
		ClearBitmap(bmSurface,shCol2->Brush->Color);
		SaveBits();
    }        
    PaintSurface();
}
//---------------------------------------------------------------------------


void __fastcall TWndGfxEdit::Horizontally1Click(TObject *Sender)
{
    if(SELECTION_ACTIVE)
		FlipBitmapH(bmSelection);
    else {         
    	AddUndo("Flip Horizontally");
		FlipBitmapH(bmSurface);
		SaveBits();
    }      
    PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Vertically1Click(TObject *Sender)
{
    if(SELECTION_ACTIVE)
		FlipBitmapV(bmSelection);
    else {
    	AddUndo("Flip Vertically");
		FlipBitmapV(bmSurface);
		SaveBits();
    }      
    PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Invert1Click(TObject *Sender)
{
    if(SELECTION_ACTIVE)
		InvertBitmap(bmSelection);
    else {
    	AddUndo("Invert");
        InvertBitmap(bmSurface);
        SaveBits();
    }      
    PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::GreyScale1Click(TObject *Sender)
{
    if(SELECTION_ACTIVE)
		GreyScaleBitmap(bmSelection);
    else {
    	AddUndo("Grey Scale");
		GreyScaleBitmap(bmSurface);
		SaveBits();
    }     
    PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Up1Click(TObject *Sender)
{
    if(SELECTION_ACTIVE)
		BitmapShiftUp(bmSelection,shCol2->Brush->Color,shiftMode);
    else {
    	AddUndo("Shift Up");
		BitmapShiftUp(bmSurface,shCol2->Brush->Color,shiftMode);
		SaveBits();
    }     
    PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Down1Click(TObject *Sender)
{
    if(SELECTION_ACTIVE)
		BitmapShiftDown(bmSelection,shCol2->Brush->Color,shiftMode);
    else {
    	AddUndo("Shift Down");
		BitmapShiftDown(bmSurface,shCol2->Brush->Color,shiftMode);
		SaveBits();
    }   
    PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Left1Click(TObject *Sender)
{
    if(SELECTION_ACTIVE)
		BitmapShiftLeft(bmSelection,shCol2->Brush->Color,shiftMode);
    else {
    	AddUndo("Shift Left");
		BitmapShiftLeft(bmSurface,shCol2->Brush->Color,shiftMode);
		SaveBits();
    }    
    PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Right1Click(TObject *Sender)
{
    if(SELECTION_ACTIVE)
		BitmapShiftRight(bmSelection,shCol2->Brush->Color,shiftMode);
    else {
    	AddUndo("Shift Right");
		BitmapShiftRight(bmSurface,shCol2->Brush->Color,shiftMode);
		SaveBits();
    }     
    PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Zoom1Click(TObject *Sender)
{
	zoomLv = ((TMenuItem*)Sender)->Tag;
	PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::ZoomIn1Click(TObject *Sender)
{
	if(zoomLv<16) zoomLv++;
	PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::ZoomOut1Click(TObject *Sender)
{
	if(zoomLv>1) zoomLv--;
	PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::sbSwapColsClick(TObject *Sender)
{
	TColor c=shCol1->Brush->Color;
	shCol1->Brush->Color=shCol2->Brush->Color;
	shCol2->Brush->Color=c;
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::sbToolsClick(TObject *Sender)
{
	int i,newTool;
	lastTool = curTool;
	if(tbCurTool)
    	tbCurTool->Down = FALSE;
    tbCurTool = ((TToolButton*)Sender);
	newTool = tbCurTool->Tag;
    tbCurTool->Down = TRUE;
    for(i=0;i<TOTAL_EDIT_TOOLS;i++)
    	if(csrRes[i].index==newTool) {
    		Screen->Cursors[DRAWING_CURSOR] = LoadCursor(HInstance, csrRes[i].name);
    		pbSurface->Cursor = (TCursor) DRAWING_CURSOR;
            break;
        }
    if(i==TOTAL_EDIT_TOOLS) {
		Screen->Cursors[DRAWING_CURSOR] = (HICON)crArrow;
		pbSurface->Cursor = (TCursor)DRAWING_CURSOR;
    }

	if((GET_TOOL_GROUP(newTool)!=TOOLS_SELECTION)&&SELECTION_ACTIVE){
    	SetSelection();
    	curTool = newTool;
 		PaintSurface();
    } else curTool = newTool;
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::BrushStyle1Click(TObject *Sender)
{
	sbBrushStyle->Tag = (((TToolButton*)Sender)->Tag);
	sbBrushStyle->ImageIndex = sbBrushStyle->Tag;
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::PenSize1Click(TObject *Sender)
{
	sbPenWidth->Tag = (((TToolButton*)Sender)->Tag);
	sbPenWidth->ImageIndex = 7+sbPenWidth->Tag;
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::PenStyle1Click(TObject *Sender)
{
	sbPenStyle->Tag = (((TToolButton*)Sender)->Tag);
	sbPenStyle->ImageIndex = 16+(((TToolButton*)Sender)->Tag);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::sbPenWidthClick(TObject *Sender)
{
	sbPenWidth->Tag = (sbPenWidth->Tag&7)+1;
    PenSize1Click(sbPenWidth);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::sbPenStyleClick(TObject *Sender)
{
	sbPenStyle->Tag++;
    if(sbPenStyle->Tag>5)
    	sbPenStyle->Tag=0;
    PenStyle1Click(sbPenStyle);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::sbBrushStyleClick(TObject *Sender)
{
	sbBrushStyle->Tag = (sbBrushStyle->Tag+1)&7;
    BrushStyle1Click(sbBrushStyle);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::imPalMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int w=imPal->Width/imPal->Picture->Bitmap->Width;
    int h=imPal->Height/imPal->Picture->Bitmap->Height;
	TColor c=pal->cols[((Y/h)*imPal->Picture->Bitmap->Width)+(X/w)];
    if(Shift.Contains(ssLeft)) {
    	shCol1->Brush->Color = c;
    } else if(Shift.Contains(ssRight)) {  
    	shCol2->Brush->Color = c;
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::btnTColClick(TObject *Sender)
{
	shpTCol->Brush->Color = shCol1->Brush->Color;
    cel->transCol = GetPaldex(shpTCol->Brush->Color,pal);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::cbLoopMirrorChange(TObject *Sender)
{
	sciVIEWLOOP *newLoop;
	int newLoopNum = cbLoopMirror->ItemIndex;
	if((!loop->mirror&&loop->loop==newLoopNum)) {
    	cbLoopMirror->ItemIndex = loop->loop;
    	return;
    }
	if(loop->mirror&&loop->mirror->loop==newLoopNum) {
    	cbLoopMirror->ItemIndex = loop->mirror->loop;
    	return;
    }
    if(loop->mirror&&newLoopNum==loop->loop) {
    	//ssMessage(ssNOTICE,"Note! By unlinking loop %d from loop %d, any changes made to either will no longer affect the other. To relink them, simply select the loop's mirror again.", loop->loop, loop->mirror->loop);
     	ViewUnmirrorLoop(loop);
        WRITE_STATUS("View loop "+IntToStr(loop->loop)+" unmirrored.");
    } else {
    	do {
    		newLoop = ViewGetLoop(view, newLoopNum);
    	    if(newLoop->mirror) newLoopNum = newLoop->mirror->loop;
    	    else break;
   	 	} while(newLoop->mirror);
  		if((!loop->mirror&&newLoopNum==loop->loop)||(newLoop->mirror&&newLoop->mirror->loop==loop->loop)) {
    		cbLoopMirror->ItemIndex = loop->loop;
    		return;
    	}
    	if(ssMessage(ssWARNING|ssYESNO,
    		"Warning! All cels in the current loop will be lost and replaced with "
        	"the mirrored cels of loop %d. Continue?", newLoopNum)==IDNO) {  
    		cbLoopMirror->ItemIndex = loop->loop;
            return; // alright.
        }

    	ViewClearLoop(loop);
    	loop->mirror = newLoop;   
        WRITE_STATUS("View loop "+IntToStr(loop->loop)+" mirrored to "+IntToStr(loop->mirror->loop)+".");
    }
    SET_RESCHANGED();
    ChangeLoopCel(loop->loop,0,TRUE);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::edWidthKeyPress(TObject *Sender, char &Key)
{
	if(Key==VK_RETURN) {
     	((TEdit*)Sender)->OnExit(Sender);
    }
}      
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::edWidthExit(TObject *Sender)
{
	if(!CheckStringNum(edWidth->Text.c_str())) {
    	ssMessage(ssNOTICE, "%s is not a valid number!",edWidth->Text.c_str());
        edWidth->Text = IntToStr(cel->width);
        return;
    }
	int w=StrToInt(edWidth->Text);
    if((unsigned)w>MAX_WIDTH) {
    	ssMessage(ssNOTICE, "The cel width must be between from 1 to %d!",MAX_WIDTH);
        edWidth->Text = IntToStr(cel->width);
        return;
    }
    ResizeCel(cel,w,cel->height);  
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::edHeightExit(TObject *Sender)
{
	if(!CheckStringNum(edHeight->Text.c_str())) {
    	ssMessage(ssNOTICE, "%s is not a valid number!",edHeight->Text.c_str());
        edHeight->Text = IntToStr(cel->height);
        return;
    }
	int h=StrToInt(edHeight->Text);
    if((unsigned)h>MAX_HEIGHT) {
    	ssMessage(ssNOTICE, "The cel height must be between from 1 to %d!",MAX_HEIGHT);
        edHeight->Text = IntToStr(cel->height);
        return;
    }

    ResizeCel(cel,cel->width,h);  
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::edXExit(TObject *Sender)
{
	if(!CheckStringNum(edX->Text.c_str())) {
    	ssMessage(ssNOTICE, "%s is not a valid number!",edX->Text.c_str());
        edX->Text = IntToStr(cel->x);
        return;
    }
	int x=StrToInt(edX->Text);
    if((unsigned)x>255) {
    	ssMessage(ssNOTICE, "The cel X must be between from -128 to +127!");
        edX->Text = IntToStr(cel->x);
        return;
    }
    cel->x = x;     
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::edYExit(TObject *Sender)
{
	if(!CheckStringNum(edY->Text.c_str())) {
    	ssMessage(ssNOTICE, "%s is not a valid number!",edY->Text.c_str());
        edY->Text = IntToStr(cel->y);
        return;
    }
	int y=StrToInt(edY->Text);
    if((unsigned)y>255) {
    	ssMessage(ssNOTICE, "The cel Y must be between from -128 to +127!");
        edY->Text = IntToStr(cel->y);
        return;
    }
    cel->y = y;    
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void TWndGfxEdit::ResizeCel(sciVIEWCEL *cel, int nWidth, int nHeight)
{
	if(nWidth>MAX_WIDTH)   nWidth  = MAX_WIDTH;
    else if(nWidth<1) nWidth = 1;
	if(nHeight>MAX_HEIGHT) nHeight = MAX_HEIGHT;
    else if(nHeight<1) nHeight = 1;

	cel->data = ResizeBits(cel->data, cel->width, cel->height, nWidth, nHeight, GetPaldex(shCol2->Brush->Color, pal));
	cel->width  = nWidth;
	cel->height = nHeight;
	ChangeLoopCel(loop->loop,cel->cel,TRUE);
}
//---------------------------------------------------------------------------
void TWndGfxEdit::ResizeChar(sciFONTCHAR *fontChar, int nWidth, int nHeight)
{
	if(nWidth>MAX_CHAR_WIDTH)   nWidth  = MAX_CHAR_WIDTH;
    else if(nWidth<1) nWidth = 1;
	if(nHeight>MAX_CHAR_HEIGHT) nHeight = MAX_CHAR_HEIGHT;
    else if(nHeight<1) nHeight = 1;

	fontChar->data = ResizeBits(fontChar->data, fontChar->width, fontChar->height, nWidth, nHeight, GetPaldex(shCol2->Brush->Color, pal));
	fontChar->width  = nWidth;
	fontChar->height = nHeight;
	ChangeChar(fontChar->index,TRUE);
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::tmrSelectionTimer(TObject *Sender)
{
	if(!CAN_DRAW) return;
    tmrSelection->Tag = !(tmrSelection->Tag);//!tmrSelection->Tag;
    PaintSurface();//InvalidateRect(ScrollBox1->Handle,NULL,FALSE);
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::CancelSelection()
{
	if(!SELECTION_ACTIVE) return;
	SELECTION_ACTIVE = FALSE;
    DRAG_IN_SELECTION = FALSE;
    RESIZE_SELECTION = FALSE;    
    DRAW_SELECTY		= FALSE;
    bmSurface->Canvas->Draw(0,0,bmSavedSurface);
    FULL_DELETE(bmSelection);
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::SetSelection()
{
	if(!SELECTION_ACTIVE) return;
	SELECTION_ACTIVE = FALSE;
    DRAG_IN_SELECTION = FALSE;
    RESIZE_SELECTION = FALSE;
    DRAW_SELECTY		= FALSE;

    bmSurface->Canvas->Draw(0,0,bmSavedSurface);
    if(curTool==TOOL_SELMOVE) {
            bmSurface->Canvas->Brush->Color = shCol2->Brush->Color;
            bmSurface->Canvas->FillRect(SelCutRect);
    }
    bmSurface->Canvas->CopyRect(
    	SelRect,
        bmSelection->Canvas,
        SelBounds
    );            
    bmSavedSurface->Assign(bmSurface);
    FULL_DELETE(bmSelection);
    SelRect.left = -1;
    SelRect.right = -1;
    SelRect.top = -1;
    SelRect.bottom = -1;
	SaveBits();
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::pnToolsDockOver(TObject *Sender,
      TDragDockObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
	Accept = ( ((TPanel*)Source->Control)->Tag == Tag );
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::pnCoordsEndDock(TObject *Sender,
      TObject *Target, int X, int Y)
{
	((TPanel*)Sender)->Tag = Tag;
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::ddLoopClick(TObject *Sender)
{
	RECT r;
	if(GetWindowRect(tbLoopCel->Handle,&r))
		pmLoop->Popup(r.left,r.top+21);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::ddCelClick(TObject *Sender)
{
	RECT r;
	if(GetWindowRect(tbLoopCel->Handle,&r))
		pmCel->Popup(r.left,r.top+42);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::AddToEndCel1Click(TObject *Sender)
{
    ChangeLoopCel(loop->loop,
    	ViewAddCel(loop,-1,GetPaldex(shCol2->Brush->Color,pal),acWidth,acHeight)->cel,TRUE
    );       
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::AppendCel1Click(TObject *Sender)
{
    ChangeLoopCel(loop->loop,
    	ViewAddCel(loop,cel->cel+1,GetPaldex(shCol2->Brush->Color,pal),acWidth,acHeight)->cel,TRUE
    );  
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::InsertCel1Click(TObject *Sender)
{
    ChangeLoopCel(loop->loop,
    	ViewAddCel(loop,cel->cel,GetPaldex(shCol2->Brush->Color,pal),acWidth,acHeight)->cel ,TRUE
    );    
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::AddToEndLoop1Click(TObject *Sender)
{
	loop = ViewAddLoop(view,-1);
	ViewAddCel(loop,0,GetPaldex(shCol2->Brush->Color,pal),acWidth,acHeight);
    ChangeLoopCel(loop->loop,0,TRUE);    
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::AppendLoop1Click(TObject *Sender)
{
	loop = ViewAddLoop(view,loop->loop+1);
	ViewAddCel(loop,0,GetPaldex(shCol2->Brush->Color,pal),acWidth,acHeight);
    ChangeLoopCel(loop->loop,0,TRUE);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::InsertLoop1Click(TObject *Sender)
{
	loop = ViewAddLoop(view,loop->loop);
	ViewAddCel(loop,0,GetPaldex(shCol2->Brush->Color,pal),acWidth,acHeight);
    ChangeLoopCel(loop->loop,0,TRUE);
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::DeleteLoop1Click(TObject *Sender)
{
	int nextl = loop->loop-1;
	if(view->totalLoops>1) {
    	if(!ViewDeleteLoop(view,loop))  {
     		ssMessage(ssNOTICE,"You cannot delete the loop until you delete the loops which mirror it!");
        	return;
      	}
    } else {
     	ssMessage(ssNOTICE,"You cannot delete the last loop of a view!");
		return;
    }
    ChangeLoopCel(nextl>=0?nextl:0,0,TRUE);
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::DeleteCel1Click(TObject *Sender)
{
	int oldE = tmrSelCel->Enabled;
    tmrSelCel->Enabled = FALSE;
	if(loop->totalCels>1)
    	ViewDeleteCel(loop,cel);
    else {
     	ssMessage(ssNOTICE,"You cannot delete the last cel of a loop!");
    }         
    ChangeLoopCel(loop->loop,0,TRUE);
    tmrSelCel->Enabled = oldE;    
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void TWndGfxEdit::ChangeChar(int cNum, BOOL SELO)
{
	if(fChar) {
    	if(SELECTION_ACTIVE&&fChar->index==cNum) return;
    	if(fChar->index!=cNum) {
    		ClearUndos();
    		SetSelection();
        }
    }

	fChar				= GetFontChar(font,cNum);
    edChWidth->Text     = IntToStr(fChar->width);
    edChHeight->Text 	= IntToStr(fChar->height);
    edFnHeight->Text 	= IntToStr(font->height);
                                    
	udChar->Max 		= font->totalChars-1;
    udChar->Enabled		= (udChar->Max);
	udChar->Position 	= cNum;
    lbChar->Caption 	= IntToStr(cNum)+"/"+IntToStr(udChar->Max);

    SetBits(fChar->data,fChar->width,fChar->height);
    DeletePaledBitmap(bmSurface);
	bmSurface = FontDrawCharBitmap(font, cNum);
	PaintSurface();

	if(SELO)
     	SetUpCharsSelector();
    DrawCharSelImg(TRUE);
}
//---------------------------------------------------------------------------
void TWndGfxEdit::SetUpCharsSelector()
{
	int i=0;
	int maxWidth=0,maxHeight=0;
	sciFONTCHAR *fc = font->firstChar;
	while(fc) {
		if(fc->height>maxHeight) maxHeight=fc->height;
		if(fc->width>maxWidth)   maxWidth=fc->width;
		i++;
        	fc = fc->next;
	};
	drawPercent = (float)MAX_SELCHAR_HEIGHT/(float)maxHeight;
	if((float)maxWidth*(float)drawPercent>(float)MAX_SELCHAR_WIDTH) {
		drawPercent = (float)MAX_SELCHAR_WIDTH/(float)maxWidth;
    }
    chimH = (maxHeight * drawPercent)+2;
	RESET_FSRL_MAX();
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::DrawCharSelImg(BOOL FIX_UP)
{
	int drawWidth,drawHeight;
	
	if(!font) return;

	tmrSelChar->Enabled = FALSE;

	int startChar = sbrChars->Position;
	int endChar;
	endChar = startChar + (imChars->Height/chimH);
	if(endChar>=font->totalChars)
		endChar = font->totalChars-1;
	if(FIX_UP) {
		if(fChar->index<startChar)
			startChar += fChar->index-startChar;
	 	else if(fChar->index>endChar)
			startChar -= endChar-fChar->index;
		endChar = startChar + (imChars->Height/chimH);
		if(endChar>=font->totalChars)
			endChar = font->totalChars-1;
		sbrChars->Position = startChar;
	}


	Graphics::TBitmap *bmpChars = new Graphics::TBitmap;
	bmpChars->Height = imChars->Height;
	bmpChars->Width = imChars->Width;
    int y=2;
    bmpChars->Canvas->Pen->Color = clBlack;
    bmpChars->Canvas->Brush->Color = clBtnFace;
    bmpChars->Canvas->FillRect(Rect(0,0,imChars->Width,imChars->Height));
    bmpChars->Canvas->Brush->Style = bsClear;
    fCharsRect.left = -1;
	for(int t=startChar;t<=endChar;t++) {

		Graphics::TBitmap *b = FontDrawCharBitmap(font,t);
        drawHeight = b->Height*drawPercent;
        drawWidth = b->Width*drawPercent;
        int x1=(bmpChars->Width-drawWidth)>>1;
        int y1=y+((chimH-drawHeight)>>1);
        if(t==fChar->index) {
         	fCharsRect.left	= x1;
         	fCharsRect.top	= y1;
         	fCharsRect.right	= x1+drawWidth;
         	fCharsRect.bottom	= y1+drawHeight;
        }
        bmpChars->Canvas->Rectangle(
        	Rect(x1-1,y1-1,x1+drawWidth+1,y1+drawHeight+1)
        );                                 
		bmpChars->Canvas->CopyRect(
			Rect(x1,y1,x1+drawWidth,y1+drawHeight),
			b->Canvas,
			Rect(0,0,b->Width,b->Height)
		);
		DeletePaledBitmap(b);
    	y+=chimH;
    }
    imChars->Picture->Bitmap->Assign(bmpChars);
    delete bmpChars;

	tmrSelChar->Enabled = TRUE;
}
//---------------------------------------------------------------------------
void TWndGfxEdit::DrawSelsChar()
{
	if(fCharsRect.left==-1) return;
	Graphics::TBitmap *b =  FontDrawCharBitmap(font,fChar->index);
	imChars->Canvas->CopyRect(
		Rect(fCharsRect.left,fCharsRect.top,fCharsRect.right,fCharsRect.bottom),
		b->Canvas,
		Rect(0,0,b->Width,b->Height)
	);
	DeletePaledBitmap(b);
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::udCharClick(TObject *Sender,
      TUDBtnType Button)
{
	ChangeChar(udChar->Position,FALSE);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::edChWidthExit(TObject *Sender)
{
	if(!CheckStringNum(edChWidth->Text.c_str())) {
    	ssMessage(ssNOTICE, "%s is not a valid number!",edChWidth->Text.c_str());
        edChWidth->Text = IntToStr(fChar->width);
        return;
    }
	int w=StrToInt(edChWidth->Text);
    if((unsigned)w>MAX_CHAR_WIDTH) {
    	ssMessage(ssNOTICE, "The char width must be between from 1 to %d!",MAX_CHAR_WIDTH);
        edChWidth->Text = IntToStr(fChar->width);
        return;
    }
    ResizeChar(fChar,w,fChar->height);       
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::edChHeightExit(TObject *Sender)
{
	if(!CheckStringNum(edChHeight->Text.c_str())) {
    	ssMessage(ssNOTICE, "%s is not a valid number!",edChHeight->Text.c_str());
        edChHeight->Text = IntToStr(fChar->height);
        return;
    }
	int h=StrToInt(edChHeight->Text);
    if((unsigned)h>MAX_CHAR_HEIGHT) {
    	ssMessage(ssNOTICE, "The char height must be between from 1 to %d!",MAX_CHAR_HEIGHT);
        edChHeight->Text = IntToStr(fChar->height);
        return;
    }
    ResizeChar(fChar,fChar->width,h);  
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::edFnHeightExit(TObject *Sender)
{
	if(!CheckStringNum(edFnHeight->Text.c_str())) {
    	ssMessage(ssNOTICE, "%s is not a valid number!",edFnHeight->Text.c_str());
        edFnHeight->Text = IntToStr(font->height);
        return;
    }
	int h=StrToInt(edChHeight->Text);
    if((unsigned)h>MAX_FONT_HEIGHT) {
    	ssMessage(ssNOTICE, "The font height must be between from 1 to %d!",MAX_FONT_HEIGHT);
        edFnHeight->Text = IntToStr(font->height);
        return;
    }
    font->height = h;  
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::imCharsMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int t=(sbrChars->Position)+((Y/chimH));
    if(t>=0&&t<font->totalChars) {
    	ChangeChar(t,FALSE);
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::sbrCharsChange(TObject *Sender)
{
	DrawCharSelImg(FALSE);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::tmrSelCharTimer(TObject *Sender)
{
	if(!CAN_DRAW||!fChar) return;
    int y = (fChar->index-sbrChars->Position)*chimH+2;
                    
    int drawHeight = fChar->height*drawPercent;
    int drawWidth = fChar->width*drawPercent;
    int x1=(imChars->Width-drawWidth)>>1;
    int y1=y+((chimH-drawHeight)>>1);

    imChars->Canvas->Pen->Width = 2;
	imChars->Canvas->Brush->Style = bsClear;
    imChars->Canvas->Pen->Color = clFados[1][tmrSelChar->Tag];
    imChars->Canvas->Rectangle(x1,y1,x1+drawWidth+1,y1+drawHeight+1);

    tmrSelChar->Tag = (tmrSelChar->Tag+1)&0xF;
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::Panel6Resize(TObject *Sender)
{
	DrawCharSelImg(TRUE);
}      
//---------------------------------------------------------------------------
void TWndGfxEdit::ChangeCursor()
{
    ClearUndos();

    if(cursor->hotSpot) HotSpot881->Checked = TRUE;
    else  HotSpot001->Checked = TRUE;

    SetBits(cursor->data,sCSR_WIDTH,sCSR_HEIGHT);
    DeletePaledBitmap(bmSurface);
	bmSurface = CursorDrawBitmap(cursor,pal);
	PaintSurface();
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Animator1Click(TObject *Sender)
{
    TDlgViewAni *v = new TDlgViewAni(this);
    v->view = view;
    v->loop = loop;
    v->pal = view->palVGA?&view->palVGA->pal:&palEGA;
    v->realLoop = loopReal;
    v->ViewEditWin = this;
    v->TrackBar1->Max = loop->totalCels-1;
    v->TrackBar2->OnChange = NULL;
    v->TrackBar2->Position = aniSpeed;
    v->Timer1->Interval = aniSpeed*100;
    v->TrackBar2->OnChange = v->TrackBar2Change;
    v->ToolButton1Click(this);
    v->ShowModal();
    delete v;
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::ViewFontTable1Click(TObject *Sender)
{
	TDlgViewFont *v=new TDlgViewFont(this);
	v->ShowModal();
    delete v;
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::FontTester1Click(TObject *Sender)
{
	TDlgFontTest *FTW=new TDlgFontTest(this);
    FTW->Setup(font);
	FTW->ShowModal();
    delete FTW;
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::Shift1Click(TObject *Sender)
{
	TMenuItem *m = (TMenuItem*)Sender;
	shiftMode = m->Tag;
    m->Checked = TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::DrawingTools1Click(TObject *Sender)
{
	pnDrawingTools->Visible = !pnDrawingTools->Visible;
	DrawingTools1->Checked = pnDrawingTools->Visible;
    pnDrawingTools->ManualDock(pnTools,NULL,alNone);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::ColourSelection1Click(TObject *Sender)
{  
	pnPalette->Visible = !pnPalette->Visible;
	ColourSelection1->Checked = pnPalette->Visible;
    pnPalette->ManualDock(pnTools,NULL,alNone);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::Coords1Click(TObject *Sender)
{  
	pnCoords->Visible = !pnCoords->Visible;
	Coords1->Checked = pnCoords->Visible;
    pnCoords->ManualDock(pnTools,NULL,alNone);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if(Shift.Contains(ssCtrl)) {
    	switch(Key) { /*
            case 'N':
                New1Click(Sender);
                break;  */
            case 'O':
                Open1Click(Sender);
                break;
            case 'S':
                Save1Click(Sender);
                break;
         	case 'Z':
            	Undo1Click(Sender);
                break;
         	case 'C':
            	Copy1Click(Sender);
                break;
         	case 'X':
            	Cut1Click(Sender);
                break;
         	case 'V':
            	Paste1Click(Sender);
                break;
         	case 'I':
            	ZoomIn1Click(Sender);
                break;
         	case 'U':
            	ZoomOut1Click(Sender);
                break;
        }
    } else {
    	if(resType==rsVIEW) {
    	switch(Key) {
         	case 'C':
            	AddToEndCel1Click(Sender);
                break;
         	case 'L':
            	AddToEndLoop1Click(Sender);
                break;
         	case VK_UP:
            	if(udLoop->Position>0) {
    				ChangeLoopCel(udLoop->Position-1,0,TRUE);
                }
                break;
         	case VK_DOWN:
            	if(udLoop->Position<view->totalLoops-1) {
    				ChangeLoopCel(udLoop->Position+1,0,TRUE);
                }
                break;
         	case VK_LEFT:
            	if(udCel->Position>0) {
    				ChangeLoopCel(udLoop->Position,udCel->Position-1,FALSE);
                }
                break;
         	case VK_RIGHT:
            	if(udCel->Position<loopReal->totalCels-1) {
    				ChangeLoopCel(udLoop->Position,udCel->Position+1,FALSE);
                }
                break;
        }
        }
        if(resType==rsFONT) {
    	switch(Key) {    
        	case VK_UP:
        	case VK_RIGHT:
            	if(udChar->Position<font->totalChars-1)
					ChangeChar(udChar->Position+1,FALSE);
                break;
        	case VK_DOWN:
        	case VK_LEFT:
            	if(udChar->Position>0)
					ChangeChar(udChar->Position-1,FALSE);
                break;
            default:
            	if(Key<font->totalChars)
                	 ChangeChar(Key,TRUE);
        }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::ScrollBox1Click(TObject *Sender)
{
	ActiveControl = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::HotSpot001Click(TObject *Sender)
{
	cursor->hotSpot = ((TMenuItem*)Sender)->Tag;
    HotSpot001->Checked = FALSE;
    HotSpot881->Checked = FALSE;
    ((TMenuItem*)Sender)->Checked = TRUE;
}
//---------------------------------------------------------------------------



void __fastcall TWndGfxEdit::SpeedButton1Click(TObject *Sender)
{
	tmrSelCel->OnTimer = NULL;
	TWndPalEdit *p = new TWndPalEdit(this);
    p->SetUp(view->palVGA);
    p->ShowModal();
    if(p->OK_CLOSE) {
    	SCI1PalDispose(view->palVGA);
        view->palVGA = (sciPALETTE*)ssAlloc(sizeof(sciPALETTE));
    	memcpy(view->palVGA,&p->pal,sizeof(sciPALETTE));
        SetupSCIPal(view->palVGA);
    }
    delete p;
    UpdatePalette(0,0);
    ChangeLoopCel(loop->loop,cel->cel,FALSE);
	tmrSelCel->OnTimer = tmrSelCelTimer;
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::EGAView1Click(TObject *Sender)
{
	NewRes(rsVIEW,sv_VT_EGA);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::VGAView1Click(TObject *Sender)
{
	NewRes(rsVIEW,sv_VT_VGA10);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::N128CharFont1Click(TObject *Sender)
{
	NewRes(rsFONT,sv_FT_STD);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::N256CharFont1Click(TObject *Sender)
{
	NewRes(rsFONT,sv_FT_EXT);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::N3ColourCursor1Click(TObject *Sender)
{
	NewRes(rsCURSOR,sv_CT_2COL);
}
//---------------------------------------------------------------------------

void __fastcall TWndGfxEdit::N4ColourCursor1Click(TObject *Sender)
{
	NewRes(rsCURSOR,sv_CT_3COL);
}
//---------------------------------------------------------------------------
void TWndGfxEdit::UpdatePalette(int w, int h)
{
	if(resType==rsVIEW) {
    	if(resVer==sv_VT_EGA) {
        	w = 4;
            h = 4;
        } else {
        	pal = &view->palVGA->pal;     
			cbEmbedPalette->Checked = view->palVGA->SET;
            w = 16;
            h = 16;
        }
    }
		Graphics::TBitmap *b = new Graphics::TBitmap;
    	int p=0;
    	b->Width  = w;
    	b->Height = h;
    	for(int y=0;y<h;y++)
    		for(int x=0;x<w;x++)
        		b->Canvas->Pixels[x][y] = pal->cols[p++];
    	imPal->Stretch = TRUE;
    	imPal->Align = alClient;
    	imPal->Picture->Bitmap->Assign(b);
    	delete b;
}
//---------------------------------------------------------------------------
void __fastcall TWndGfxEdit::cbEmbedPaletteClick(TObject *Sender)
{
	view->palVGA->SET = cbEmbedPalette->Checked;
}
//---------------------------------------------------------------------------

