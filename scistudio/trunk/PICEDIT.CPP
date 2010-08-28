//---------------------------------------------------------------------------
// SCI Studio 3+
// By Brian Provinciano
// www.bripro.com
// (c) 1999-2003 Brian Provinciano
//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <ClipBrd.hpp>
#pragma hdrstop
                 
#include "picedit.h"
#include "explorer.h"
#include "main.h"
#include "colourselect.h"
#include "piccommand.h"
#include "wait.h"
#include "gfxedits.h"
#include "impbitmap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MenuBar"
#pragma resource "*.dfm"
TWndPicEdit *WndPicEdit;
//---------------------------------------------------------------------------
tsCSRRES picCsrRes[] = {
	{-1,				NULL},
	{PTOOL_LINE,		"LINECURSOR"},
	{PTOOL_SHORTLINE,	"LINECURSOR"},
	{PTOOL_TINYLINE,	"LINECURSOR"},
	{PTOOL_ABSPEN,		"PENCURSOR"},
	{PTOOL_NEARPEN,	 	"PENCURSOR"},
	{PTOOL_CLSPEN,	 	"PENCURSOR"},
	{PTOOL_FILL,		"FILLCURSOR"},
	{PTOOL_ZOOM,		"ZOOMCURSOR"},
	{PTOOL_RECTANGLE, 	"SQUARECURSOR"},
	{PTOOL_ELLIPSE,		"ELLIPSECURSOR"},
	{PTOOL_CHANGEBMP,	"DRAG"},
	{PTOOL_SETPRI,		"DRAG"},
};
PAINTSTRUCT ps = {
	NULL,
	FALSE,
	{NULL}
};
AnsiString picCmdNames[] = {
	"Visual Set",
	"Visual Off",
	"Priority Set",
	"Priority Off",
	"Short Pen",
	"Short Line",
	"Line",
	"Tiny Line",
    "Fill",
    "Change Pattern",
    "Abs Pen",
	"Control Set",
	"Control Off",
    "Short Pen",
    "Ext",
    "End of Pic"
};

U8 onCodes[3]  = {0xF0,0xF2,0xFB};
U8 offCodes[3] = {0xF1,0xF3,0xFC};

#define GETPIX(x,y,s)\
	pic->bitmaps[s][(sPIC_MAXY-y)*sPIC_WIDTH+x]
//---------------------------------------------------------------------------
__fastcall TWndPicEdit::TWndPicEdit(TComponent* Owner)
	: TForm(Owner)
{
	pic = NULL;   
	settingPri = -1;
}
//---------------------------------------------------------------------------
void piEditorClose(EDITORTAG *edtTag)
{          
	TWndPicEdit *form = ((TWndPicEdit*)edtTag->Form);
    form->CAN_DRAW = FALSE;
    form->MOUSE_DOWN = FALSE;
    form->pbSurface->OnPaint = NULL;
    form->ScrollBox1->OnResize = NULL;
    form->pnPicBar->OnResize = NULL;

    PicDispose(form->pic); 
	//::DeleteObject(form->PicBitmap);
    //ssFree(form->binfo);
}
//---------------------------------------------------------------------------
void piSaveRes(EDITORTAG *edtTag)
{
	((TWndPicEdit*)edtTag->Form)->Save1Click(edtTag->Form);
}
//---------------------------------------------------------------------------
BOOL TWndPicEdit::InitEditor(EDTWND *_edtWnd, U8 *resBuf, S16 resVer)
{
    edTag.EditorClose = piEditorClose;
    edTag.SaveRes = piSaveRes;
    edTag.edtWnd = _edtWnd;
    strcpy(edTag.defCaption,Caption.c_str());
    edTag.Form = this;
	Tag = (int)&edTag;

    picType = resVer;

    CAN_DRAW = FALSE;
    MOUSE_DOWN = FALSE;
    PICBMP=FALSE;

	binfo.bmiHeader.biSize          = sizeof(BITMAPINFOHEADER);
	binfo.bmiHeader.biWidth         = sPIC_WIDTH;
	binfo.bmiHeader.biHeight        = sPIC_HEIGHT;
	binfo.bmiHeader.biPlanes        = 1;
	binfo.bmiHeader.biBitCount      = 32;
	binfo.bmiHeader.biCompression   = BI_RGB;
	binfo.bmiHeader.biSizeImage     = sizeof(PicBitmapBits);
	binfo.bmiHeader.biXPelsPerMeter = 0;
	binfo.bmiHeader.biYPelsPerMeter = 0;
	binfo.bmiHeader.biClrUsed       = 0;
	binfo.bmiHeader.biClrImportant  = 0;

	HDC ahDC = GetDC( ScrollBox1->Handle );
	PicBitmap = CreateDIBitmap(
		ahDC,
		&binfo.bmiHeader,
		0L,
		NULL,
		NULL,
        0
	);
	SetDIBits(
		ahDC,	// handle of device context
    	PicBitmap,	// handle of bitmap
    	0,	// starting scan line
    	sPIC_HEIGHT,	// number of scan lines
		PicBitmapBits,	// array of bitmap bits
		&binfo,	// address of structure with bitmap data
		DIB_RGB_COLORS	 	// type of color indices to use
   );
	ReleaseDC( ScrollBox1->Handle, ahDC );

    BACK_LOADED = FALSE;

    activeScreen = asVISUAL;
    activePalette = 0;

    drawingCursor = winNum+10; // unique tag

    ZoomClick(NormalViewing1);

    tbCurTool = NULL;
    ToolClick(sbOff);  

    drawingTool = -1;

    ScrollBox1->Color = WndMain->Color;

    newCount = 0;
    if(!WndExplorer)
    	SaveToGame1->Visible = FALSE;
    else {
		SET_EXPLORERED();
    }

    if(resBuf) {
		LoadPic(resBuf, edTag.edtWnd->resIDfo.size);
		UPDATE_CAPTION();
    } else {  
    	NewPic();
    }   

    PICBMP=TRUE;
    UpdatePic();


	switch(activePalette) {
     	case 0:
    		PaletteClick(tbPal0);
        	break;
     	case 1:
    		PaletteClick(tbPal1);
        	break;
     	case 2:
    		PaletteClick(tbPal2);
        	break;
     	case 3:
    		PaletteClick(tbPal3);
        	break;
    }

	return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndPicEdit::SavePic()
{
	U8 *buf;
    U16 len;
	CAN_DRAW = FALSE;

    if((!CHECK_EXPLORERED())&&(CHECK_RESNEW()||(edTag.edtWnd->fileName[0]=='\0'))) {
        SaveAs1Click(this);
		CAN_DRAW = TRUE;
        return TRUE;
    }

    buf = pic->data;
    len = pic->length;

    if(CHECK_EXPLORERED()) {
        RESINFO *newRI = WndExplorer->SaveResToGame(buf, len, rsPIC, EDTTAG->edtWnd->resIDfo.number);
     	if(!newRI) {
			CAN_DRAW = TRUE;
    		return FALSE;
        } else SetResIDfo(&EDTTAG->edtWnd->resIDfo,newRI);
    } else {
        FILE *fFile;
        if((fFile=ssOpenFile(ssFIO_ROOT|ssFIO_MESSAGE,edTag.edtWnd->fileName,"wb"))==NULL){
			CAN_DRAW = TRUE;
            return FALSE;
        }
        ssFPutW((0x80|rsPIC),fFile);
        ssFWrite(buf,len,fFile);
        ssCloseFile(fFile);
    }
                          
    CLEAR_RESNEW();
    CLEAR_RESCHANGED();
    UPDATE_CAPTION();

    CAN_DRAW = TRUE;

    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndPicEdit::LoadPic(U8 *buf, U32 len)
{
	U8 *newB,*uBuf;
    sciPIC   *p;   
    CAN_DRAW = FALSE;
	if(buf==NULL||len==0) {
		OpenDialog->Filter = resTypes[rsPIC].filter;
    	if(!OpenDialog->Execute()) {
    		CAN_DRAW = TRUE;
        	return FALSE;
        }
   		if((newB=ssLoadFile(ssFIO_ROOT|ssFIO_MESSAGE, OpenDialog->FileName.c_str(), &len))==NULL) {
    		CAN_DRAW = TRUE;
    		return FALSE;
    	}
        if(CheckSCIFileHeader(newB)!=rsPIC) {
			ssMessage(ssERROR,"The file your are trying to open, %s, is not a valid SCI %s resource, or does not contain a valid header",OpenDialog->FileName.c_str(),resTypes[rsPIC].name);
        	ssFree(newB); 
    		CAN_DRAW = TRUE;
        	return FALSE;
    	}       
    	CLEAR_EXPLORERED();       
    	strcpy(edTag.edtWnd->fileName,OpenDialog->FileName.c_str());
    	uBuf = newB+2;
        len-=2;
    } else
    	uBuf=buf;

	ClosePic();

	if((p = PicLoad(uBuf,len,plEDITOR,activePalette,picType))==NULL) {
    	NewPic();
		CAN_DRAW = TRUE;
    	return FALSE;
    }
    pic = p;

    if(!buf)
    	ssFree(uBuf);

	UpdatePic();    
    CLEAR_RESCHANGED();
    CLEAR_RESNEW();
    CAN_DRAW = TRUE;

    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndPicEdit::UpdatePic()
{
	if(!pic) return FALSE;

    oldPicLen = -1;   

    UpdateDataEdit();

	switch(activeScreen) {
     	case asVISUAL:
    		ScreenClick(tbVisual);
        	break;
     	case asPRIORITY:
    		ScreenClick(tbPriority);
        	break;
     	case asCONTROL:
    		ScreenClick(tbControl);
        	break;
    }

    DrawActiveScreen(TRUE);
                         
    sbSquare->Down  =  (pic->patCode&PATTERN_FLAG_RECTANGLE  );
    sbCircle->Down  = !(pic->patCode&PATTERN_FLAG_RECTANGLE  );
    sbPattern->Down =  (pic->patCode&PATTERN_FLAG_USE_PATTERN);
    sbSolid->Down   = !(pic->patCode&PATTERN_FLAG_USE_PATTERN);

    PenSizeE->Caption = IntToStr((pic->patCode&7)+1);
    UpDown1->Position = (pic->patCode&7);
    
    for(int i=0;i<3;i++)
		DrawColour(i);

    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndPicEdit::ClosePic()
{
	CAN_DRAW = FALSE;
    PicDispose(pic);

    return TRUE;
}
//---------------------------------------------------------------------------
BOOL TWndPicEdit::NewPic()
{
	CAN_DRAW = FALSE;
    sprintf(edTag.edtWnd->fileName,"%s.n%02d",resTypes[rsPIC].name,newCount);
    SET_RESNEW();
	if((pic = PicLoad(defPic,sizeof(defPic),plEDITOR,activePalette,picType))==NULL) {
		CAN_DRAW = TRUE;
    	return FALSE;
	}
    CLEAR_RESCHANGED();
	UpdatePic();
	
	CAN_DRAW = TRUE;
    return TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TWndPicEdit::New1Click(TObject *Sender)
{
	NewPic();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::Open1Click(TObject *Sender)
{
	LoadPic(NULL,0);
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::Save1Click(TObject *Sender)
{
	SavePic();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::SaveAs1Click(TObject *Sender)
{
	CAN_DRAW = FALSE;
	if(CHECK_EXPLORERED())
    	SaveDialog->FileName = AnsiStringFmtRes(edTag.edtWnd->resIDfo.type,edTag.edtWnd->resIDfo.number);
	else if(edTag.edtWnd->fileName[0])
    	SaveDialog->FileName=AnsiString(edTag.edtWnd->fileName);

    SaveDialog->Filter=resTypes[rsPIC].filter;
	if(SaveDialog->Execute()) {
    	CLEAR_EXPLORERED();
        CLEAR_RESNEW();
        strcpy(edTag.edtWnd->fileName,SaveDialog->FileName.c_str());
    	Save1Click(Sender);
    }
	CAN_DRAW = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::SaveToGame1Click(TObject *Sender)
{
	SET_EXPLORERED();  
	CLEAR_RESNEW();
    Save1Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::Close1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::CommandHistory1Click(TObject *Sender)
{
	long oldPixLen=pic->length;

	TDlgPicCommand *CmdWin = new TDlgPicCommand(this);

    FillListView(CmdWin->ListBox,pic->offset);
	CmdWin->offset = pic->offset;
    CmdWin->ShowModal();
    pic->offset = CmdWin->offset;
	if(pic->offset>=pic->length&&oldPixLen!=pic->length) pic->offset = pic->length;
	delete CmdWin;
    UpdatePic();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::Copy1Click(TObject *Sender)
{
    // generate a clipboard compatible bitmap
    Graphics::TBitmap *b =
    	DrawBufferToBitmap(pic->bitmaps[activeScreen], sPIC_WIDTH, sPIC_HEIGHT, (pic->palVGA&&activeScreen==asVISUAL)?&(pic->palVGA->pal):&palEGA, FALSE, TRUE);
    // Copy it to the clipboard
    Clipboard()->Assign(b);
    // Free it
    delete b;
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::PasteTracingImage1Click(TObject *Sender)
{
    TClipboard *pCB = Clipboard();

    if(pCB->HasFormat(CF_BITMAP)) {
        Graphics::TBitmap *pBitmap = new Graphics::TBitmap();

        try {
            pBitmap->LoadFromClipboardFormat(CF_BITMAP, pCB->GetAsHandle(CF_BITMAP), 0);
   			AssignBack(pBitmap);
        }
        catch (...) {
            MessageBeep(0);
        }
        delete pBitmap;
    } else {
        MessageBeep(0);
        ShowMessage("Clipboard does not contain a valid Bitmap!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::AssignBack(Graphics::TBitmap *TempBit)
{
	long c;
    int w =  TempBit->Width, h = TempBit->Height;
    Graphics::TBitmap *newBit=new Graphics::TBitmap;
	newBit->Width  = sPIC_WIDTH;
	newBit->Height = sPIC_HEIGHT;
    if((w!=sPIC_WIDTH||h!=sPIC_HEIGHT)
    	&& Application->MessageBox(
        	"The bitmap's dimensions do not match the picture's (320x190). Would it to be scaled?",
            "Scale The Picture?",
            MB_YESNO)==IDYES) {
                newBit->Canvas->StretchDraw(
                	Rect(0,0,sPIC_WIDTH,sPIC_HEIGHT),
                    TempBit
                );
            	w = sPIC_WIDTH;
            	h = sPIC_HEIGHT;
    } else newBit->Canvas->Draw(
                	0,0,
                    TempBit
                );

    DlgWait = new TDlgWait(this);
    DlgWait->ProgressBar->Max = sPIC_HEIGHT;
    DlgWait->ProgressBar->Position = 0;
    DlgWait->Show();
    if(w>sPIC_WIDTH) w = sPIC_WIDTH;
    if(h>sPIC_HEIGHT) h = sPIC_HEIGHT;
    long *foo=(long*)BackBitmapBits;
    for(int y=0;y<h;y++) {
        for(int x=0;x<w;x++) {
        	c = (long)newBit->Canvas->Pixels[x][y];
            foo[((189-y)*sPIC_WIDTH)+x] =
                ((c>>16)&0xFF)|((c<<16)&0xFF0000)|(c&0xFF00);
        }  
        DlgWait->ProgressBar->Position++;
    }
	delete newBit;
    delete DlgWait;

    BACK_LOADED = TRUE;
    ShowTracingImage1->Checked 		 = TRUE;
    ShowTracingImage1->ImageIndex 	&= 0xFFFE;
    tbTracingBitmap->ImageIndex  	&= 0xFFFE;
    DrawActiveScreen(TRUE);
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::LoadTracingImage1Click(TObject *Sender)
{
    if(!BGOpenDialog->Execute()) return;
    Graphics::TBitmap *BGBitmap = new Graphics::TBitmap;
    BGBitmap->LoadFromFile(BGOpenDialog->FileName);
    AssignBack(BGBitmap);
    delete BGBitmap;
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::ShowTracingImage1Click(TObject *Sender)
{
    if(!BACK_LOADED) {
    	LoadTracingImage1Click(this);
        return;
    }
    if(!BACK_LOADED) return;
    ShowTracingImage1->Checked 		 = !ShowTracingImage1->Checked;
    ShowTracingImage1->ImageIndex 	^= 1;
    tbTracingBitmap->ImageIndex  	^= 1;
    DrawActiveScreen(FALSE);
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::ShowPriorityBars1Click(TObject *Sender)
{
    ShowPriorityBars1->Checked 	     = !ShowPriorityBars1->Checked;
    ShowPriorityBars1->ImageIndex 	^= 1;
    tbPriLines->ImageIndex 			^= 1;
    DrawActiveScreen(FALSE);
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::ZoomClick(TObject *Sender)
{
	zoomLevel = ((TMenuItem*)Sender)->Tag;
    FixUpSurface();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::ZoomIn1Click(TObject *Sender)
{
	if(zoomLevel<16) zoomLevel++;   
    FixUpSurface();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::ZoomOut1Click(TObject *Sender)
{
	if(zoomLevel>1) zoomLevel--;    
    FixUpSurface();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::ShapeSelectClick(TObject *Sender)
{
	switch( ((TToolButton*)Sender)->Tag ) {
		case 0: // circle
        	pic->patCode &= 0xEF; break;
		case 1: // square
        	pic->patCode |= 0x10; break;
		case 2: // random
        	pic->patCode |= 0x20; break;
		case 3: // solid
        	pic->patCode &= 0xDF; break;
    }     
    WritePattern();
    UpdatePic();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::UpDown1Click(TObject *Sender,
      TUDBtnType Button)
{
    PenSizeE->Caption = IntToStr(UpDown1->Position+1);
    pic->patCode = (pic->patCode & 0xF8) | (StrToInt(UpDown1->Position) & 7);

    WritePattern();
    UpdatePic();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::SpeedButton2Click(TObject *Sender)
{
	DeleteCode(pic->offset);
    UpdatePic();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::SpeedButton1Click(TObject *Sender)
{
	CropCode(pic->offset);
    UpdatePic();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::SpeedButton11Click(TObject *Sender)
{
    pic->offset = 0;    
    drawingTool = -1;
    UpdatePic();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::SpeedButton10Click(TObject *Sender)
{
    if(!pic->offset) return;
    pic->offset = PicSkipTo(pic,psBACKWARD);  
    drawingTool = -1;
    UpdatePic();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::SpeedButton9Click(TObject *Sender)
{
    if(pic->offset>=pic->length-1) return;
    pic->offset = PicSkipTo(pic,psFORWARD);
    drawingTool = -1;
    UpdatePic();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::SpeedButton8Click(TObject *Sender)
{
	pic->offset = pic->length-1;    
    drawingTool = -1;
    UpdatePic();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::ToolClick(TObject *Sender)
{
	int i,newTool;
	lastTool = curTool;
	if(tbCurTool)
    	tbCurTool->Down = FALSE;
    tbCurTool = ((TToolButton*)Sender);
	newTool = tbCurTool->Tag;
    tbCurTool->Down = TRUE;
    for(i=0;i<TOTAL_PIC_TOOLS;i++)
    	if(picCsrRes[i].index==newTool) {
    		Screen->Cursors[drawingCursor] = LoadCursor(HInstance, picCsrRes[i].name);
    		pbSurface->Cursor = (TCursor) drawingCursor;
            break;
        }
    if(i==TOTAL_PIC_TOOLS) {
		Screen->Cursors[drawingCursor] = (HICON)crArrow;
		pbSurface->Cursor = (TCursor)drawingCursor;
    }
    curTool = newTool;
    drawingTool = -1;
    if(curTool == PTOOL_SETPRI) {
    	ShowPriorityBars1->Checked 	     = TRUE;
    	ShowPriorityBars1->ImageIndex 	&= 0xFFFE;
    	tbPriLines->ImageIndex 			&= 0xFFFE;
    	DrawActiveScreen(FALSE);
    }
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::ScreenClick(TObject *Sender)
{
	((TToolButton*)Sender)->Down = TRUE;
	activeScreen = ((TToolButton*)Sender)->Tag;

    if(activeScreen==asVISUAL&&picType==sv_PT_VGA10) {
    	pal = &pic->palVGA->pal;
    } else
    	pal = &palEGA;

    DrawActiveScreen(FALSE);
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::PaletteClick(TObject *Sender)
{
	((TToolButton*)Sender)->Down = TRUE;
	activePalette = ((TToolButton*)Sender)->Tag;
    pic->visPal = activePalette;
    DrawActiveScreen(TRUE);
    UpdatePic();
}       
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::pbSurfaceMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int i;
	if(!CAN_DRAW) return;
    MOUSE_DOWN = TRUE;
	settingPri = -1;

	float hPcnt,vPcnt;
	dnX = CalcAct(X,zoomLevel);
	dnY = CalcAct(Y,zoomLevel);
    DoAngleThing(&dnX,&dnY,Shift.Contains(ssShift));
                       
    if(curTool==PTOOL_ZOOM) {
    	if(Shift.Contains(ssLeft))
        	ZoomIn1Click(this);
        else
        	ZoomOut1Click(this);
        hPcnt = (float)dnX/(float)sPIC_WIDTH;
        vPcnt = (float)dnY/(float)sPIC_HEIGHT;
        ScrollBox1->HorzScrollBar->Position = (((float)((float)ScrollBox1->HorzScrollBar->Range-ScrollBox1->Width)*hPcnt));
        ScrollBox1->VertScrollBar->Position = (((float)((float)ScrollBox1->VertScrollBar->Range-ScrollBox1->Height)*vPcnt));
     	return;
	}
    if(Shift.Contains(ssRight)) {
     	drawingTool = -1;
		UpdatePic();
        return;
    }
    if(!Shift.Contains(ssLeft)) return;

    if(drawingTool!=curTool) paramCount=0;

    switch(curTool) {
        case PTOOL_LINE:
        	if(paramCount) {
        		if(paramCount==1) {
            		AddCode(0xF6);
        			AddCoords(lastPoint.x,lastPoint.y);
            	}
                if(paramCount>=1)
        			AddCoords(dnX,dnY);
            }
            UpdatePic();
            break;
        case PTOOL_SHORTLINE:
        	if(paramCount) {
        		if(paramCount==1) {
            		AddCode(0xF5);
        			AddCoords(lastPoint.x,lastPoint.y);
            	}
                if(paramCount>=1) {
            		FixCoords8Bit(&dnX,&dnY);
        			AddRel8Coords(lastPoint.x,lastPoint.y,dnX,dnY);
            	}
            }
            UpdatePic();
            break;
        case PTOOL_TINYLINE:
        	if(paramCount) {
        		if(paramCount==1) {
            		AddCode(0xF7);
        			AddCoords(lastPoint.x,lastPoint.y);
            	} 
                if(paramCount>=1) {
            		FixCoords4Bit(&dnX,&dnY);
        			AddRel4Coords(lastPoint.x,lastPoint.y,dnX,dnY);
            	}
            }
            UpdatePic();
            break;
        case PTOOL_FILL:
        	if(drawingTool!=PTOOL_FILL)
            	AddCode(0xF8);
        	AddCoords(dnX,dnY);
            UpdatePic();
            break;
        case PTOOL_ABSPEN:
        	if(drawingTool!=PTOOL_ABSPEN)
            	AddCode(0xFA);
            if(pic->patCode & 0x20) AddCode(pic->patNum<<1);
        	AddCoords(dnX,dnY);
            UpdatePic();
            break;
        case PTOOL_NEARPEN:
        	if(drawingTool!=PTOOL_NEARPEN) {
            	AddCode(0xFD);
            	if(pic->patCode & 0x20) AddCode(pic->patNum<<1);
        		AddCoords(dnX,dnY);
            } else {
            	FixCoords8Bit(&dnX,&dnY);  
            	if(pic->patCode & 0x20) AddCode(pic->patNum<<1);
        		AddRel8Coords(lastPoint.x,lastPoint.y,dnX,dnY);
            }
            UpdatePic();
            break;
        case PTOOL_CLSPEN:
        	if(drawingTool!=PTOOL_CLSPEN) {
            	AddCode(0xF4);       
            	if(pic->patCode & 0x20) AddCode(pic->patNum<<1);
        		AddCoords(dnX,dnY);
            } else {
            	FixCoords4Bit(&dnX,&dnY); 
            	if(pic->patCode & 0x20) AddCode(pic->patNum<<1);
        		AddRel4Coords(lastPoint.x,lastPoint.y,dnX,dnY);
            }
            UpdatePic();
            break;
        case PTOOL_SETPRI:
        	for(i=0;i<14;i++)
            	if(pic->priBars[i]==dnY) {
                	settingPri = i;
                    break;
                }
            break;

    }
    lastPoint.x = dnX;
    lastPoint.y = dnY;
	mvX = dnX;
	mvY = dnY;
    drawingTool = curTool;
    paramCount++;
                     
	pbSurfacePaint(this);
}
//---------------------------------------------------------------------------
#include <time.h>
void __fastcall TWndPicEdit::pbSurfaceMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
	int i;
	if(!CAN_DRAW) return;
//	clock_t s = clock();
//    int a,b,c,d;
	mvX = CalcAct(X,zoomLevel);
	mvY = CalcAct(Y,zoomLevel);
//a = clock()-s;
    DoAngleThing(&mvX,&mvY,Shift.Contains(ssShift));
//b = clock()-s;

    switch(curTool) {
        case PTOOL_NEARPEN:
        case PTOOL_SHORTLINE:
        	FixCoords8Bit(&mvX,&mvY);
            break;
        case PTOOL_CLSPEN:   
        case PTOOL_TINYLINE:
        	FixCoords4Bit(&mvX,&mvY);
            break;    
        case PTOOL_SETPRI:
        	settingPri == -1;
        	for(i=0;i<14;i++)
            	if(pic->priBars[i]==mvY) {
                	settingPri = i;
                    if(Shift.Contains(ssLeft))
                    	pic->priBars[settingPri] = mvY;
                    break;
                }  
			pbSurfacePaint(this);
            break;
    }
//c = clock()-s;
	if(drawingTool!=-1)
		pbSurfacePaint(this);
//d = clock()-s;
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::pbSurfaceMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{           
	if(!CAN_DRAW||!MOUSE_DOWN) return;
    MOUSE_DOWN = FALSE;
                
	upX = CalcAct(X,zoomLevel);
	upY = CalcAct(Y,zoomLevel);
                               
	settingPri = -1;
	//pbSurfacePaint(Sender);
}
//---------------------------------------------------------------------------
void TWndPicEdit::FixUpSurface()
{
    pbSurface->Width = sPIC_WIDTH*zoomLevel;
    pbSurface->Height = sPIC_HEIGHT*zoomLevel;

	pbSurfacePaint(this);
}
//---------------------------------------------------------------------------
#define LINEMACROX(startx, starty, deltalinear, deltanonlinear, linearvar, nonlinearvar, \
                  linearend, nonlinearstart, linearmod, nonlinearmod) \
   x = (startx); y = (starty); \
   incrNE = ((deltalinear) > 0)? (deltalinear) : -(deltalinear); \
   incrNE <<= 1; \
   deltanonlinear <<= 1; \
   incrE = ((deltanonlinear) > 0) ? -(deltanonlinear) : (deltanonlinear);  \
   d = nonlinearstart-1;  \
   while (linearvar != (linearend)) { \
     ((U32*)b)[y*sPIC_WIDTH+x] = pal->wCols[(((x^y)&1)?c&0xF:c>>4)];; \
     linearvar += linearmod; \
     if ((d+=incrE) < 0) { \
       d += incrNE; \
       nonlinearvar += nonlinearmod; \
     }; \
   }; \
   ((U32*)b)[y*sPIC_WIDTH+x] = pal->wCols[(((x^y)&1)?c&0xF:c>>4)];;

void TWndPicEdit::BitsLine(int x1, int y1, int x2, int y2, U8 *b, U8 c)
{
	int dx, dy, incrE, incrNE, d, finalx, finaly;
	int x = x1;
	int y = y1;
	dx = x2-x1;
	dy = y2-y1;
	finalx = x2;
	finaly = y2;

	dx = abs(dx);
	dy = abs(dy);

	if (dx > dy) {
		if (finalx < x) {
			if (finaly < y) { /* llu == left-left-up */
				LINEMACROX(x, y, dx, dy, x, y, finalx, dx, -1, -1);
			} else {         /* lld */
				LINEMACROX(x, y, dx, dy, x, y, finalx, dx, -1, 1);
			}
		} else { /* x1 >= x */
			if (finaly < y) { /* rru */
				LINEMACROX(x, y, dx, dy, x, y, finalx, dx, 1, -1);
			} else {         /* rrd */
				LINEMACROX(x, y, dx, dy, x, y, finalx, dx, 1, 1);
			}
		}
	} else { /* dx <= dy */
		if (finaly < y) {
			if (finalx < x) { /* luu */
				LINEMACROX(x, y, dy, dx, y, x, finaly, dy, -1, -1);
			} else {         /* ruu */
				LINEMACROX(x, y, dy, dx, y, x, finaly, dy, -1, 1);
			}
		} else { /* y1 >= y */
			if (finalx < x) { /* ldd */
				LINEMACROX(x, y, dy, dx, y, x, finaly, dy, 1, -1);
			} else {         /* rdd */
				LINEMACROX(x, y, dy, dx, y, x, finaly, dy, 1, 1);
			}
		}
	}
}
//---------------------------------------------------------------------------
LOGBRUSH YOBRUSH = {BS_NULL,DIB_RGB_COLORS,0};
void __fastcall TWndPicEdit::DrawSurface()
{
	if(!pic) return;
	HPEN p;

    FromTop = ScrollBox1->VertScrollBar->Position==0?0:
    	CalcAct(ScrollBox1->VertScrollBar->Position, zoomLevel);
    FromLeft = ScrollBox1->HorzScrollBar->Position==0?0:
    	CalcAct(ScrollBox1->HorzScrollBar->Position, zoomLevel);

	nDestWidth  = pbSurface->Width-ScrollBox1->HorzScrollBar->Position;
	nDestHeight = pbSurface->Height-ScrollBox1->VertScrollBar->Position;
    nSrcWidth   = sPIC_WIDTH-FromLeft;
    nSrcHeight  = sPIC_HEIGHT-FromTop;

    ps.rcPaint.left   = FromLeft;
    ps.rcPaint.top    = FromTop;
    ps.rcPaint.right  = nSrcWidth;
    ps.rcPaint.bottom = nSrcHeight;

	BeginPaint(ScrollBox1->Handle,&ps);
    long copylen = sPIC_SIZE<<2;
    memcpy(TempBitmapBits,PicBitmapBits,copylen);

    if(ShowPriorityBars1->Checked)
        for(int i=0;i<14;i++)
        	BitsLine(0,sPIC_MAXY-pic->priBars[i],sPIC_WIDTH,sPIC_MAXY-pic->priBars[i],PicBitmapBits,(i&0xF)|(i<<4));

 	if((pic->drawenable&(1<<activeScreen))&&(drawingTool == PTOOL_LINE || drawingTool == PTOOL_SHORTLINE || drawingTool == PTOOL_TINYLINE)) {
    	BitsLine(lastPoint.x,sPIC_MAXY-lastPoint.y,mvX,sPIC_MAXY-mvY,PicBitmapBits,pic->palette[GET_PALDEX(pic->col[activeScreen])][GET_PALCOL(pic->col[activeScreen])]);
    }
    HDC xhdc = GetDC(ScrollBox1->Handle);
    StretchDIBits(
        xhdc,
        0,
		0,
		nDestWidth,
		nDestHeight,
		FromLeft,
        0,
		nSrcWidth,
		nSrcHeight,
		PicBitmapBits,
		&binfo,
		DIB_RGB_COLORS,
		SRCCOPY
    );
    if( (!(pic->drawenable&(1<<activeScreen))&&(drawingTool == PTOOL_LINE || drawingTool == PTOOL_SHORTLINE || drawingTool == PTOOL_TINYLINE) )
    	|| (drawingTool == PTOOL_CLSPEN || drawingTool == PTOOL_NEARPEN)) {
    	RECT r = {(lastPoint.x-FromLeft)*zoomLevel,(lastPoint.y-FromTop)*zoomLevel,(mvX-FromLeft)*zoomLevel,(mvY-FromTop)*zoomLevel};
        p = CreatePen(PS_DOT,1,0);
        SelectObject(xhdc, p);
        MoveToEx(xhdc, r.left, r.top,NULL);
        LineTo(xhdc, r.right, r.bottom);
        DeleteObject(p);
    }
    if(settingPri != -1) {
    	RECT r = {(-FromLeft)*zoomLevel,(pic->priBars[settingPri]-FromTop)*zoomLevel-1,(sPIC_WIDTH-FromLeft)*zoomLevel,(pic->priBars[settingPri]-FromTop)*zoomLevel+zoomLevel+1};
        HBRUSH b = CreateBrushIndirect(&YOBRUSH);
        SelectObject(xhdc, b);
        p = CreatePen(PS_DOT,1,0);
        SelectObject(xhdc, p);
        Rectangle(xhdc, r.left, r.top, r.right, r.bottom);
        DeleteObject(p);
        DeleteObject(b);
    }
    memcpy(PicBitmapBits,TempBitmapBits,copylen);

	EndPaint(ScrollBox1->Handle,&ps);
    ReleaseDC(ScrollBox1->Handle,xhdc);
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::pbSurfacePaint(TObject *Sender)
{
	pbSurface->OnPaint = NULL;
	DrawSurface();
	pbSurface->OnPaint = pbSurfacePaint;
}
//---------------------------------------------------------------------------

void __fastcall TWndPicEdit::DrawActiveScreen(BOOL FULL)
{
    if(!PICBMP) return;
    if(FULL) DrawPic(FALSE, activePalette, pic,picType);

    if(ShowTracingImage1->Checked) {
        memcpy(PicBitmapBits, BackBitmapBits, sizeof(BackBitmapBits));
        U8 *c = pic->bitmaps[activeScreen];
        U8 d = activeScreen==asVISUAL?0xF:0;

    long *p,g,a;
    g = sPIC_SIZE;
    p = (long*)PicBitmapBits;

    while(g) {
    	if(*c!=d)
        	*p = pal->wCols[*c];
        p++;
        c++;
        g--;
    }
    } else {           
        U8 *c = pic->bitmaps[activeScreen];
    long *p,g,a;
    g = sPIC_SIZE;
    p = (long*)PicBitmapBits;

    while(g) {
    	*p = pal->wCols[*c];
        p++;
        c++;
        g--;
    }
    }

    pbSurfacePaint(this);
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::FormShow(TObject *Sender)
{
    DrawActiveScreen(FALSE);
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::AddCode(U8 code)
{/*
	if(pic->offset >= rsMAX_SIZE) {
     	ssMessage(ssERROR,"Somehow you've managed to create a picture larger than SCI is capable of using! The picture is too large!");
        return;
    }*/
    for(int i=pic->length;i>pic->offset;i--)
    	pic->data[i] = pic->data[i-1];
	pic->data[pic->offset] = code;
    pic->offset++;
    pic->length++;  
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::AddCoords(S16 x, S16 y)
{
	AddCode((x&0x100)>>4);
	AddCode(x&0xFF);
	AddCode(y&0xFF);
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::AddRel8Coords(S16 x1, S16 y1, S16 x2, S16 y2)
{
	AddCode((char) (y2 < y1)? (char)(((y1-y2) & 0x7F) | 0x80):(char)((y2-y1) & 0x7F));
	AddCode((char) (x2 - x1));
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::AddRel4Coords(S16 x1, S16 y1, S16 x2, S16 y2)
{
	U8 w = ((abs(x2-x1) << 4) & 0x70) | (abs(y2-y1) & 7);
	if(x2<x1) w |= 0x80;
	if(y2<y1) w |= 0x08;
	AddCode(w);
}                
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::FixCoords8Bit(int *x, int *y)
{
	if(*x > lastPoint.x + 0x6F) *x = lastPoint.x + 0x6F;
	if(*x < lastPoint.x - 0x6F) *x = lastPoint.x - 0x6F;
	if(*y > lastPoint.y + 0x6F) *y = lastPoint.y + 0x6F;
	if(*y < lastPoint.y - 0x6F) *y = lastPoint.y - 0x6F;
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::FixCoords4Bit(int *x, int *y)
{
	if(*x > lastPoint.x + 6) *x = lastPoint.x + 6;
	if(*x < lastPoint.x - 6) *x = lastPoint.x - 6;
	if(*y > lastPoint.y + 7) *y = lastPoint.y + 7;
	if(*y < lastPoint.y - 7) *y = lastPoint.y - 7;
}

//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::WritePattern()
{
    drawingTool = -1;
	if(PicGetLastCode(pic)==0xF9)
    	pic->data[pic->offset-1] = (pic->patCode);
    else {
    	AddCode(0xF9);
    	AddCode(pic->patCode);
    }        
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::DeleteCode(U16 position)
{
	pic->offset = position;
	U16 oldOffset = pic->offset;
    U16 endOffset = PicGetNextCmdOffset(pic);
    U16 copyLen = pic->length-endOffset;

    for(int i=0;i<copyLen;i++)
    	pic->data[oldOffset+i] = pic->data[endOffset+i];
    pic->length -= endOffset-oldOffset;
    drawingTool = -1;        
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::CropCode(U16 position)
{
	pic->length				= position+1;
    pic->offset				= position;
    pic->data[pic->offset]	= 0xFF;
    drawingTool = -1;      
    SET_RESCHANGED();
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::DoAngleThing(int *_x, int *_y, BOOL LOCK)
{
	int x=*_x,y=*_y;
	if((curTool==PTOOL_LINE||curTool==PTOOL_SHORTLINE||curTool==PTOOL_TINYLINE||curTool==PTOOL_NEARPEN||curTool==PTOOL_CLSPEN)&&curTool==drawingTool) {
    	Angle = PointsToAngle(lastPoint.x,lastPoint.y,x,y);
		if(LOCK) {
        	int sq = ((x-lastPoint.x)*(x-lastPoint.x))+((y-lastPoint.y)*(y-lastPoint.y));
        	int d=sq?(sqrt( sq )*M_SQRT_2):0;
        	if(Angle<23) 		{Angle=0;   x = lastPoint.x;}
        	else if(Angle<68)  	{Angle=45;  x = lastPoint.x+d; y = lastPoint.y-d; }
        	else if(Angle<113) 	{Angle=90;  y = lastPoint.y;}
        	else if(Angle<158) 	{Angle=135; x = lastPoint.x+d; y = lastPoint.y+d; }
        	else if(Angle<203) 	{Angle=180; x = lastPoint.x;}
        	else if(Angle<248) 	{Angle=225; x = lastPoint.x-d; y = lastPoint.y+d; }
        	else if(Angle<293) 	{Angle=270; y = lastPoint.y;}
        	else if(Angle<338) 	{Angle=315; x = lastPoint.x-d; y = lastPoint.y-d; }
        	else               	{Angle=0;   x = lastPoint.x;}
        }
    } else Angle = 0;
	FIX_X(x);
 	FIX_Y(y);
    AngleLabel->Caption = "Angle: "+IntToStr((__int64)Angle)+"°";
    XLabel->Caption = "X: "+IntToStr(x);
    YLabel->Caption = "Y: "+IntToStr(y);
    PriLabel->Caption = IntToStr(VIEW_PRIORITY(y));
    ColLabel->Caption = picType==sv_PT_VGA10?IntToHex(GETPIX(x,y,activeScreen),2):IntToStr(GETPIX(x,y,activeScreen));
    shPri->Brush->Color = pal->cols[VIEW_PRIORITY(y)];
    shCol->Brush->Color = pal->cols[GETPIX(x,y,activeScreen)];
    *_x = x;
    *_y = y;
}
//---------------------------------------------------------------------------
void __fastcall TWndPicEdit::FillListView(TListBox *lb, WORD o)
{
	int i=0,ii=-1,j,oi;
	lb->Items->Clear();
    U16 oldOffset = pic->offset;
    pic->offset=0;
    BOOL FIRST=TRUE;
	while(i<pic->length-1) {
    	oi = PicPrintCode(pic,FIRST);
        FIRST = FALSE;
        j=lb->Items->Add(IntToHex(i,4)+": "+picCmdNames[pic->data[i]&0xF]+" "+codeStr);
        if(i==o) ii=j;
        i = oi;
    }
    lb->ItemIndex=ii==-1?lb->Items->Count-1:ii;
    pic->offset = oldOffset;
}
//---------------------------------------------------------------------------

void __fastcall TWndPicEdit::UpdateDataEdit()
{
    if(!PICBMP) return;
                               /*
    if(oldPicLen!=pic->length) SET_RESCHANGED();
    oldPicLen = pic->length;    */
    if(!CAN_DRAW) return;

    Graphics::TBitmap *b=new Graphics::TBitmap;
    b->Width  = ImgData->Width;
    b->Height = ImgData->Height;
    b->Canvas->Brush->Color = clBtnFace;
    b->Canvas->Brush->Style = bsSolid;
    b->Canvas->FillRect(Rect(0,0,b->Width,b->Height));
	AnsiString NewText;
    NewText= IntToHex((__int64)pic->offset,4)+":";
	int X = 0;

    	b->Canvas->Font->Name = "Tahoma";
    	b->Canvas->Font->Color = clMagicText;
    	b->Canvas->Font->Style = TFontStyles() << fsBold;
    	b->Canvas->Brush->Color = clMagicShadow;
    	b->Canvas->Pen->Color = clMagicFrame;
    	b->Canvas->Pen->Width = 2;
        int tw=b->Canvas->TextWidth(NewText)+8;
        int th=b->Canvas->TextHeight(NewText)+8;
    	b->Canvas->Rectangle(Rect(X+1,(b->Height-th)/2+1,X+tw,((b->Height-th)/2)+th));
		b->Canvas->TextOut(X+4, (b->Height-th)/2+4, NewText);
        X += tw+4;
        b->Canvas->Font->Style=TFontStyles();
    int xo=pic->offset;
    BOOL FIRST=TRUE;
    while(xo<pic->length&&X<b->Width) {
        int g=pic->data[xo]&0xF;   
        int tw= b->Canvas->TextWidth(picCmdNames[g])+6;
        int th= b->Canvas->TextHeight(picCmdNames[g])+6;
 		b->Canvas->Pen->Width = 2;
    	b->Canvas->Brush->Color = clMagicShadow;
    	b->Canvas->Rectangle(Rect(X,(b->Height-th)/2,X+tw+1,((b->Height-th)/2)+th+1));
    	b->Canvas->Font->Color = clMagicText;
		b->Canvas->TextOut(X+3, (b->Height-th)/2+3, picCmdNames[g]);
        X += tw;
    	xo = PicPrintCode(pic,FIRST);
        FIRST = FALSE;
    	if(codeStr!="") {     
 			b->Canvas->Pen->Width = 1;
    		b->Canvas->Font->Color = clMagicText;
    		b->Canvas->Brush->Color = clMagicFace;
        	int cw=b->Canvas->TextWidth(codeStr)+6;
        	int ch=b->Canvas->TextHeight(codeStr)+6;

        	b->Canvas->Rectangle(Rect(X,(b->Height-ch)/2,X+cw,((b->Height-ch)/2)+ch));
			b->Canvas->TextOut(X+3, (b->Height-th)/2+3, codeStr);
        	X += cw+4;
		} else X+=4;
    }
    ImgData->Picture->Bitmap->Assign(b);
}
//---------------------------------------------------------------------------

void __fastcall TWndPicEdit::GetColour(int scr, sciPIC *pic)
{          
	RECT r;
	TDlgColourSelect *ColWin = new TDlgColourSelect(this);
    ColWin->Setup(scr,this);

	if(GetWindowRect(pnPicBar->Handle,&r)) {
    	ColWin->Left = r.left;
    	ColWin->Top = r.top-ColWin->Height;
    }

	ColWin->ShowModal();
    if(ColWin->ResPal==-2) return; // cancel
                   
    drawingTool = -1;
    if(ColWin->COLOUR_CHANGED) {
		if(ColWin->rbNewColours->Checked) {
    		AddCode(0xFE);
    		AddCode(0x00);
            for(int p=0;p<4;p++)
            	for(int c=0;c<40;c++) {
    				if(pic->palette[p][c]!=ColWin->Palette[p][c]) {
                    	AddCode(SET_PALENT(p,c));
    					AddCode(ColWin->Palette[p][c]);
                    }
                }
        } else {
        	for(int i=0;i<4;i++) {
            	if((ColWin->COLOUR_CHANGED>>i)&1) {
    				AddCode(0xFE);
    				AddCode(0x01);
					AddCode(i);
            		for(int c=0;c<40;c++)
                		AddCode(ColWin->Palette[i][c]);
                }
            }
        }
    }              

    memcpy(pic->palette, ColWin->Palette, sizeof(ColWin->Palette));

    if(ColWin->ResPal==-1) {// turn off
    	AddCode(offCodes[scr]);
    } else {
    	AddCode(onCodes[scr]);  
    	pic->col[scr] = (scr==asVISUAL)?
            SET_PALENT(ColWin->ResPal,ColWin->ResCol):
            ColWin->ResCol;
    	AddCode(pic->col[scr]);
    }           
    SET_RESCHANGED();

	DrawColour(scr);

	delete ColWin;

    UpdatePic();
}
//---------------------------------------------------------------------------

void __fastcall TWndPicEdit::DrawColour(int scr)
{
	TColor c1,c2;
    Graphics::TBitmap *b = new Graphics::TBitmap;
    b->Width = 14;
    b->Height = 14;

    U8 p,c;
	p = GET_PALDEX(pic->col[scr]);
	c = GET_PALCOL(pic->col[scr]);
    if(pic->drawenable&(1<<scr)) {// turn on
        if(scr==asVISUAL) {
        	if(pic->palVGA) {
         		c2 = c1 = pic->palVGA->pal.cols[pic->col[scr]];
            } else {
         		c1 = palEGA.cols[(pic->palette[p][c]>>4)&0xF];
         		c2 = palEGA.cols[pic->palette[p][c]&0xF];
            }
        } else {
         	c1 = c2 = palEGA.cols[c&0xF];
        }
        b->Canvas->Pen->Color		= clWindowFrame;
        b->Canvas->Brush->Style	= bsClear;
        b->Canvas->Rectangle(0,0,b->Width,b->Height);
        for(int y=b->Height-2;y>=1;y--)
        	for(int x=b->Width-2;x>=1;x--)
        		b->Canvas->Pixels[x][y] = ((x^y)&1)?c1:c2;
    } else { // turn off
    	ClearBitmap(b,clBtnFace);
        b->Canvas->Draw(0,0,imNoCol->Picture->Bitmap);
    }    
	imCol->Canvas->Draw(scr*14,0,b);
    delete b;
}
//---------------------------------------------------------------------------

void __fastcall TWndPicEdit::sbVisClick(TObject *Sender)
{
	GetColour(asVISUAL,pic);
}
//---------------------------------------------------------------------------

void __fastcall TWndPicEdit::sbPriClick(TObject *Sender)
{
	GetColour(asPRIORITY,pic);
}
//---------------------------------------------------------------------------

void __fastcall TWndPicEdit::sbCtlClick(TObject *Sender)
{
	GetColour(asCONTROL,pic);
}
//---------------------------------------------------------------------------

void __fastcall TWndPicEdit::ScrollBox1Resize(TObject *Sender)
{
    FixUpSurface();
}
//---------------------------------------------------------------------------
                                
void __fastcall TWndPicEdit::pnPicBarResize(TObject *Sender)
{
	UpdatePic();
}
//---------------------------------------------------------------------------

void __fastcall TWndPicEdit::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

	if(Key==0xC0) {  // The '`' '~' key
    	Key = '1'+activeScreen+1;
        if(Key=='4') Key='1';
    }      
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
            case 'I':
                ZoomIn1Click(Sender);
                break;
            case 'U':
                ZoomOut1Click(Sender);
                break;
            case 'C':
                Copy1Click(Sender);
                break;
            case 'V':
                PasteTracingImage1Click(Sender);
                break;
            case 'H':
            	CommandHistory1Click(Sender);
                break;
        }
    } else switch(Key) {
    	case 'V':
        case '1':
            ScreenClick(tbVisual);
            break;
    	case 'P':
        case '2':     
            ScreenClick(tbPriority);
            break;
    	case 'C':
        case '3':
            ScreenClick(tbControl);
            break;
    	case VK_DELETE:
        	SpeedButton2Click(this);
            break;
    	case VK_LEFT:
        	SpeedButton10Click(this);
            break;
    	case VK_RIGHT:
        	SpeedButton9Click(this);
            break;
    	case VK_UP:
        	SpeedButton8Click(this);
            break;
    	case VK_DOWN:
        	SpeedButton11Click(this);
            break;   
        case '4':
        case 'T':
        	ShowTracingImage1Click(Sender);
            break;
        case '5':
        case 'B':
        	ShowPriorityBars1Click(Sender);
            break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndPicEdit::ToolButton2Click(TObject *Sender)
{
	TDlgImpBitmap *d=new TDlgImpBitmap(this);
    d->ShowModal();
    delete d;
}
//---------------------------------------------------------------------------

