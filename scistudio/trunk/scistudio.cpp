//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("scistudio.res");
USEFORM("main.cpp", WndMain);
USEUNIT("ssalloc.cpp");
USEUNIT("ssfileio.cpp");
USEUNIT("ssgame.cpp");
USEUNIT("ssmessage.cpp");
USEUNIT("ssres.cpp");
USEFORM("explorer.cpp", WndExplorer);
USEUNIT("sseditors.cpp");
USEFORM("addresource.cpp", DlgAddResource);
USEFORM("properties.cpp", DlgProperties);
USEFORM("about.cpp", DlgAbout);
USEFORM("resrebuild.cpp", DlgResRebuild);
USEUNIT("dirdialog.cpp");
USEUNIT("ssresdecode.cpp");
USEFORM("textedit.cpp", WndTextEdit);
USEFORM("vocabedit.cpp", WndVocabEdit);
USEFORM("vocabfind.cpp", DlgVocabFind);
USEFORM("viewedit.cpp", WndGfxEdit);
USEUNIT("gfxedits.cpp");
USERES("cursors.res");
USEFORM("scriptedit.cpp", WndScriptEdit);
USEUNIT("config.cpp");
USEFORM("settings.cpp", DlgSettings);
USEFORM("newroom.cpp", DlgNewRoom);
USEFORM("splash.cpp", DlgSplash);
USEUNIT("picrender.cpp");
USEFORM("picedit.cpp", WndPicEdit);
USEFORM("colourselect.cpp", DlgColourSelect);
USEFORM("piccommand.cpp", DlgPicCommand);
USEFORM("wait.cpp", DlgWait);
USEFORM("viewani.cpp", DlgViewAni);
USEFORM("fonttest.cpp", DlgFontTest);
USEFORM("viewfont.cpp", DlgViewFont);
USEFORM("checkversion.cpp", DlgCheckVersion);
USEFORM("expcels.cpp", DlgExpCels);
USEFORM("printprev.cpp", DlgPrintPrev);
USEFORM("editorprops.cpp", DlgEditorProps);
USEFORM("makefile.cpp", DlgMakeFile);
USEFORM("newgame.cpp", DlgNewGame);
USEFORM("welcome.cpp", DlgWelcome);
USEFORM("paledit.cpp", WndPalEdit);
USEFORM("addword.cpp", DlgAddWord);
USEUNIT("lzs.cpp");
USEUNIT("pkdcl.cpp");
USEUNIT("StdAfx.cpp");
USEFORM("impbitmap.cpp", DlgImpBitmap);
USEUNIT("Components\MENUBAR.PAS");
//---------------------------------------------------------------------------
char sCmdLine[1024];
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR CmdLn, int)
{
	try
	{       
        if(CmdLn) strcpy(sCmdLine,CmdLn);

		Application->Initialize();
		Application->Title = "SCI Studio 3+";
		Application->CreateForm(__classid(TWndMain), &WndMain);
                 Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------

