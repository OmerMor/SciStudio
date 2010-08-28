//---------------------------------------------------------------------------
#include <vcl.h>
#include "scihdr.h"
#pragma hdrstop

#include <shellapi.h>
#include <shlobj.h>
#include "main.h"
#include "config.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)  

#pragma link "SynEditPrint"
#pragma link "SynEditExport"
#pragma link "SynEditHighlighter"
#pragma link "SynExportHTML"
#pragma link "SynHighlighterSCI"
//---------------------------------------------------------------------------
sCONFIG config;

AnsiString identStrings[]={
	"a","b","c","d","e","f","g","h","i","j","k","l","m",
    "n","o","p","q","r","s","t","u","v","w","x","y","z"};
AnsiString regProgTypes[3] = {
	"SCIStudio.Game",
    "SCIStudio.Script",
    "SCIStudio.Header"
};
int SCIRegVersion;
#define SCI_REG_VERSION 0x0300
//---------------------------------------------------------------------------
void __fastcall TWndMain::LoadConfig()
{
	NO_KEY = FALSE;

    TRegistry *Registry = new TRegistry;
    try {
        Registry->RootKey = HKEY_LOCAL_MACHINE;
        if(!Registry->OpenKey(REG_KEY_NAME, TRUE));// return;

        SCIRegVersion = (Registry->ValueExists("SCIRegVersion"))?Registry->ReadInteger("SCIRegVersion"):0;

        Top    = (Registry->ValueExists("Top"))?Registry->ReadInteger("Top"):(Screen->Height-Height)>>1;
        Left   = (Registry->ValueExists("Left"))?Registry->ReadInteger("Left"):(Screen->Width-Width)>>1;
        if(Registry->ValueExists("Width")) Width  = Registry->ReadInteger("Width");
        if(Registry->ValueExists("Height")) Height = Registry->ReadInteger("Height");

        config.maxUndos   = (Registry->ValueExists("MaxUndos"))?Registry->ReadInteger("MaxUndos"):20;

        int xWindowState = (Registry->ValueExists("WindowState"))?Registry->ReadInteger("WindowState"):0;
        WindowState = (xWindowState == 1)?wsMaximized:wsNormal;

        config.SHOW_SPLASH = (Registry->ValueExists("SplashScreen"))?Registry->ReadBool("SplashScreen"):TRUE;
        config.SHOW_WELCOME = (Registry->ValueExists("ShowWelcome"))?Registry->ReadBool("ShowWelcome"):TRUE;
        config.QUERY_SAVING = (Registry->ValueExists("QuerySave"))?Registry->ReadBool("QuerySave"):TRUE;

        config.SHOW_CLASS_REF = (Registry->ValueExists("ShowClassRef"))?Registry->ReadBool("ShowClassRef"):TRUE;
        config.SHOW_KERNEL_REF = (Registry->ValueExists("ShowKernelRef"))?Registry->ReadBool("ShowKernelRef"):TRUE;

        if(Registry->ValueExists("StatusBar") && Registry->ReadBool("StatusBar")==0)
            StatusBar2Click(this);
        if(!Registry->ValueExists("ToolBar") || Registry->ReadBool("ToolBar"))
            ToolBar3Click(this);
        if(Registry->ValueExists("TextLabels") && Registry->ReadBool("TextLabels")==0)
            TextLabels1Click(this);
        if(Registry->ValueExists("AlwaysColour") && !Registry->ReadBool("AlwaysColour"))
            AlwaysColour1Click(this);
        if(Registry->ValueExists("ToolBarImages") && Registry->ReadBool("ToolBarImages")==0)
            Images1Click(this);
        if(Registry->ValueExists("ToolBarBitmap")) {
        	config.tbBitmapName=Registry->ReadString("ToolBarBitmap");
		} else config.tbBitmapName="";
        if(config.tbBitmapName!="")
            MainPanel2->Bitmap->LoadFromFile(config.tbBitmapName);

        config.ewsDefResType = (Registry->ValueExists("DefaultResourceType"))?Registry->ReadInteger("DefaultResourceType"):rsVIEW;
        config.ewsViewStyle = (Registry->ValueExists("ViewStyle"))?Registry->ReadInteger("ViewStyle"):2;
        config.ewsSHOW_PREVIEW = (Registry->ValueExists("ShowPreview"))?Registry->ReadBool("ShowPreview"):TRUE;
        config.ewsSHOW_RESCAP = (Registry->ValueExists("ShowResourceCaption"))?Registry->ReadBool("ShowResourceCaption"):TRUE;
        config.ewsFLAT_SCROLL = (Registry->ValueExists("FlatScroll"))?Registry->ReadBool("FlatScroll"):FALSE;
        config.ewsGRID_LINES = (Registry->ValueExists("GridLines"))?Registry->ReadBool("GridLines"):FALSE;
        config.ewsHOT_TRACK = (Registry->ValueExists("HotTrack"))?Registry->ReadBool("HotTrack"):FALSE;
        config.ewsHAND_POINT = (Registry->ValueExists("HandPoint"))?Registry->ReadBool("HandPoint"):TRUE;
        config.ewsUNDERLINEC = (Registry->ValueExists("UnderlineC"))?Registry->ReadBool("UnderlineC"):FALSE;
        config.ewsUNDERLINEH = (Registry->ValueExists("UnderlineH"))?Registry->ReadBool("UnderlineH"):TRUE;

        config.ewsManagerBarV = (Registry->ValueExists("ManagerBarV"))?Registry->ReadBool("ManagerBarV"):TRUE;

        config.ewsPreviewBarWidth = (Registry->ValueExists("PreviewBarWidth"))?Registry->ReadInteger("PreviewBarWidth"):338;
        config.ewsManagerBarWidth = (Registry->ValueExists("ManagerBarWidth"))?Registry->ReadInteger("ManagerBarWidth"):113;

        Color = (Registry->ValueExists("BGColour"))?(TColor) Registry->ReadInteger("BGColour"):(TColor) 0x00906030;

        config.ewsSEP_SCR_WNDS = (Registry->ValueExists("SeperateScriptWnds"))?Registry->ReadBool("SeperateScriptWnds"):FALSE;

        PrevOpenCount = 0;
        if(Registry->ValueExists("PrevOpened0")) {  
			DirDialog->InitialDir = Registry->ReadString("PrevOpened0");
        	for(int i=0;i<10;i++) {
            	if(Registry->ValueExists("PrevOpened"+IntToStr(i))) {
            		PrevOpened[i] = new TMenuItem(mnuRecent);
            		PrevOpened[i]->Caption = "&"+IntToStr(i)+" "+Registry->ReadString("PrevOpened"+IntToStr(i));
            		PrevOpenCount++;
                }
            }
        } else {
            DirDialog->InitialDir = AnsiString(Program.path);
        }

        if(Registry->ValueExists("shHighlights")) {
            config.shHighlightsSET = TRUE;
            Registry->ReadBinaryData("shHighlights",config.shHighlights,sizeof(config.shHighlights));
        } else {
            config.shHighlightsSET = FALSE;
            memset(config.shHighlights,0,sizeof(config.shHighlights));
        }
        if(Registry->ValueExists("shOptions")) {
        	Registry->ReadBinaryData("shOptions",&config.shOptions,sizeof(config.shOptions));
        } else
        	memcpy(&config.shOptions, "\x06\x6C\x00\x00", 4);
        if(Registry->ValueExists("shFont.Name")) {
            config.shFont = new TFont;
            config.shFont->Name = Registry->ReadString("shFont.Name");
            config.shFont->Size = Registry->ReadInteger("shFont.Size");
        } else
            config.shFont = NULL;
        if(Registry->ValueExists("shGutter.Width")) {
            config.shGutter = new TSynGutter;
            config.shGutter->Width = Registry->ReadInteger("shGutter.Width");
            config.shGutter->ShowLineNumbers = Registry->ReadInteger("shGutter.ShowLineNumbers");
            config.shGutter->Visible = Registry->ReadBool("shGutter.Visible");
        } else
            config.shGutter = NULL;
        config.shTabWidth = (Registry->ValueExists("shTabWidth"))?Registry->ReadInteger("shTabWidth"):4;
        config.shExtraLineSpacing = (Registry->ValueExists("shExtraLineSpacing"))?Registry->ReadInteger("shExtraLineSpacing"):0;

		SynAttr[0] = SynSCISyn1->NormalAttri;
		SynAttr[1] = SynSCISyn1->NumberAttri;
		SynAttr[2] = SynSCISyn1->StringAttri;
		SynAttr[3] = SynSCISyn1->KeyAttri;
		SynAttr[4] = SynSCISyn1->OperatorAttri;
		SynAttr[5] = SynSCISyn1->CommentAttri;
		SynAttr[6] = SynSCISyn1->SpaceAttri;

		if(config.shHighlightsSET) {
        	for(int i=0;i<hlTOTAL;i++) {
            	SynAttr[i]->Foreground = config.shHighlights[i].Foreground;
            	SynAttr[i]->Background = config.shHighlights[i].Background;
            	SynAttr[i]->Style = config.shHighlights[i].Style;
        	}
    	}

        if(Registry->ValueExists("FullScreen") && Registry->ReadBool("FullScreen"))
            FullScreen1Click(this);
    } __finally {
        delete Registry;
    }      
    #define REG_KEY_FILEEXT "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts\\"
    AnsiString s,s2;

    config.RegExtInfo[0].Ext = ".map";
    config.RegExtInfo[1].Ext = ".sc";
    config.RegExtInfo[2].Ext = ".sh";

    for(int i=0;i<3;i++) {
    	Registry = new TRegistry;
    	Registry->RootKey = HKEY_CLASSES_ROOT;
    	if(Registry->OpenKey(regProgTypes[i]+"\\shell\\open\\command", TRUE)) {
			Registry->WriteString("",AnsiString(Program.path)+"\\scistudio.exe %1");
			if(Registry->OpenKey("DefaultIcon", TRUE)) {
				Registry->WriteString("",AnsiString(Program.path)+"\\scistudio.exe,"+IntToStr(i+1));
        	}
    	}
    	delete Registry;

    	Registry = new TRegistry;
    	Registry->RootKey = HKEY_LOCAL_MACHINE;
    	if(Registry->OpenKey("SOFTWARE\\Classes\\"+regProgTypes[i], TRUE)) {
			if(Registry->OpenKey("DefaultIcon", TRUE)) {
				Registry->WriteString("",AnsiString(Program.path)+"\\scistudio.exe,"+IntToStr(i+1));
        	}
    	}
    	delete Registry;

    	Registry = new TRegistry;
        Registry->RootKey = HKEY_CLASSES_ROOT;
        config.RegExtInfo[i].Set = FALSE;
    	if(Registry->OpenKey(AnsiString(config.RegExtInfo[i].Ext), FALSE)) {
            s = Registry->ReadString("");
            if(s==regProgTypes[i])
            	config.RegExtInfo[i].Set = TRUE;
        }
        delete Registry;
    }

    config.RegExtInfo[3].Set = FALSE;
    Registry = new TRegistry;
    Registry->RootKey = HKEY_CLASSES_ROOT;
    if(Registry->OpenKey("Folder\\shell\\Open Game with SCI Studio", FALSE))
    	config.RegExtInfo[3].Set = TRUE;
    delete Registry;

    memcpy(config.PrevRegExtInfo,config.RegExtInfo,sizeof(config.PrevRegExtInfo));
}
//---------------------------------------------------------------------------
void __fastcall TWndMain::SaveConfig()
{
    if(NO_KEY) return;

    TRegistry *Registry = new TRegistry;
    TRegistry *Registry2;
    try {
        Registry->RootKey = HKEY_LOCAL_MACHINE;
        Registry->OpenKey(REG_KEY_NAME, TRUE);

        Registry->WriteInteger("SCIRegVersion",SCIRegVersion);
                                 
        Registry->WriteBool("FullScreen",FullScreen1->Checked);
        if(FullScreen1->Checked)
        	FullScreen1Click(this);

        Registry->WriteInteger("WindowState", (WindowState==wsMaximized));
        WindowState=wsNormal;

        Registry->WriteInteger("Top", Top);
        Registry->WriteInteger("Left", Left);
        Registry->WriteInteger("Width", Width);
        Registry->WriteInteger("Height", Height);

        Registry->WriteInteger("MaxUndos", config.maxUndos);

        Registry->WriteBool("SplashScreen", config.SHOW_SPLASH);
        Registry->WriteBool("QuerySave", config.QUERY_SAVING);
        Registry->WriteBool("ShowWelcome", config.SHOW_WELCOME);
                                                          
        Registry->WriteBool("ShowClassRef", config.SHOW_CLASS_REF);
        Registry->WriteBool("ShowKernelRef", config.SHOW_KERNEL_REF);

        Registry->WriteBool("StatusBar", StatusBar2->Checked);
        Registry->WriteBool("ToolBar", ToolBar3->Checked);
        Registry->WriteBool("TextLabels", TextLabels1->Checked);
        Registry->WriteBool("AlwaysColour", AlwaysColour1->Checked);
        Registry->WriteBool("ToolBarImages", Images1->Checked);

		Registry->WriteString("ToolBarBitmap",config.tbBitmapName);

        Registry->WriteInteger("DefaultResourceType", config.ewsDefResType);
        Registry->WriteInteger("ViewStyle", config.ewsViewStyle);
        Registry->WriteBool("ShowPreview", config.ewsSHOW_PREVIEW); 
        Registry->WriteBool("ShowResourceCaption", config.ewsSHOW_RESCAP);
        Registry->WriteBool("FlatScroll", config.ewsFLAT_SCROLL);
        Registry->WriteBool("GridLines", config.ewsGRID_LINES);
        Registry->WriteBool("HotTrack", config.ewsHOT_TRACK);
        Registry->WriteBool("HandPoint", config.ewsHAND_POINT);
        Registry->WriteBool("UnderlineC", config.ewsUNDERLINEC);
        Registry->WriteBool("UnderlineH", config.ewsUNDERLINEH);

        Registry->WriteBool("ManagerBarV", config.ewsManagerBarV);
        Registry->WriteInteger("PreviewBarWidth", config.ewsPreviewBarWidth);
        Registry->WriteInteger("ManagerBarWidth", config.ewsManagerBarWidth);

        Registry->WriteInteger("BGColour", Color);

        Registry->WriteString("LastDirectory", DirDialog->InitialDir);

        Registry->WriteBool("SeperateScriptWnds", config.ewsSEP_SCR_WNDS);

        if(config.shHighlightsSET) Registry->WriteBinaryData("shHighlights",config.shHighlights,sizeof(config.shHighlights));
        Registry->WriteBinaryData("shOptions",&config.shOptions,sizeof(config.shOptions));

        if(config.shFont) {
            Registry->WriteString("shFont.Name",config.shFont->Name);
            Registry->WriteInteger("shFont.Size",config.shFont->Size);
        }
        if(config.shGutter) {
            Registry->WriteInteger("shGutter.Width",config.shGutter->Width);
            Registry->WriteInteger("shGutter.ShowLineNumbers",config.shGutter->ShowLineNumbers);
            Registry->WriteBool("shGutter.Visible",config.shGutter->Visible);
        }
        Registry->WriteInteger("shTabWidth", config.shTabWidth);
        Registry->WriteInteger("shExtraLineSpacing", config.shExtraLineSpacing);


        for(int i=0;i<PrevOpenCount;i++)
        	Registry->WriteString("PrevOpened"+IntToStr(i), PrevOpened[i]->Caption.SubString(4,PrevOpened[i]->Caption.Length()-3));
    } __finally {
        delete Registry;
    }
    AnsiString s;
    BOOL ANY_CHANGED=FALSE;
    for(int i=0;i<3;i++) {
        if(config.RegExtInfo[i].Set!=config.PrevRegExtInfo[i].Set) {
        	ANY_CHANGED=TRUE;
    		Registry = new TRegistry;
        	Registry->RootKey = HKEY_CLASSES_ROOT;
    		if(Registry->OpenKey(AnsiString(config.RegExtInfo[i].Ext), TRUE)) {
        	    if(config.RegExtInfo[i].Set) {
                 	Registry->WriteString("", regProgTypes[i]);
                } else {
                 	Registry->DeleteValue("");
                }
            }
        	delete Registry;
        }
    }
    if(config.RegExtInfo[3].Set!=config.PrevRegExtInfo[3].Set) { 
        ANY_CHANGED=TRUE;
        Registry = new TRegistry;
        Registry->RootKey = HKEY_CLASSES_ROOT;
        if(Registry->OpenKey("Folder\\shell\\Open Game with SCI Studio\\command", TRUE)) {
        	if(config.RegExtInfo[3].Set) {
            	Registry->WriteString("", AnsiString(Program.path)+"\\scistudio.exe %1");
            } else {
            	Registry2 = new TRegistry;  
        		Registry2->RootKey = HKEY_CLASSES_ROOT;
        		if(Registry2->OpenKey("Folder\\shell", FALSE)) {
            		Registry2->DeleteKey("Open Game with SCI Studio\\command");
            		Registry2->DeleteKey("Open Game with SCI Studio");
                }
       			delete Registry2;
            }
        }
        delete Registry;
    }
    if(ANY_CHANGED) {
    	SHChangeNotify(SHCNE_ASSOCCHANGED,NULL,NULL,NULL);
    }
}
//---------------------------------------------------------------------------