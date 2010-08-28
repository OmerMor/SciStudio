//---------------------------------------------------------------------------

#include <vcl.h>     
#include <shlobj.h>
#pragma hdrstop

#include "dirdialog.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TDirDialog *ddPtr;
//---------------------------------------------------------------------------
int __stdcall BrowseProc(HWND hwnd,UINT uMsg, LPARAM lParam, LPARAM lpData )
{
    char szDir[MAX_PATH];

    switch(uMsg)
    {
        case BFFM_INITIALIZED:
            // Set the initial directory. If WPARAM is TRUE, then LPARAM is a
            // string that contains the path. If WPARAM is FALSE, then LPARAM
            // should be a lovely PIDL
            if(ddPtr->InitialDir!="") SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM)ddPtr->InitialDir.c_str());
            SetWindowText(hwnd,ddPtr->Title.c_str());
            ddPtr->Handle = hwnd;
            
            ddPtr->CheckMap(ddPtr->InitialDir.c_str());
            break;
        case BFFM_SELCHANGED:
            if(SHGetPathFromIDList((LPITEMIDLIST)lParam, szDir))
                ddPtr->CheckMap(szDir);
            break;
    }
    return 0;
}
//---------------------------------------------------------------------------
TDirDialog::TDirDialog()
{
    AnsiString Title = "Select a folder.";
    InitialDir = "";
    MAP_CHECK = FALSE;
}       
//---------------------------------------------------------------------------
void TDirDialog::CheckMap(char *szDir)
{
    BOOL FILE_FOUND;
    WIN32_FIND_DATA FindFileData;
    char DirectoryString[255];

	if(!MAP_CHECK) return;

    if(szDir[3])
        wsprintf(DirectoryString, "%s\\resource.map", szDir);
    else
        wsprintf(DirectoryString, "%sresource.map", szDir);

    FILE_FOUND = FindFirstFile((LPCTSTR)DirectoryString,(LPWIN32_FIND_DATA)&FindFileData)!=INVALID_HANDLE_VALUE;
 	if(!FILE_FOUND) {
    	if(szDir[3])
        	wsprintf(DirectoryString, "%s\\resmap.000", szDir);
    	else
        	wsprintf(DirectoryString, "%sresmap.000", szDir);
    	if(FILE_FOUND=(FindFirstFile((LPCTSTR)DirectoryString,(LPWIN32_FIND_DATA)&FindFileData)!=INVALID_HANDLE_VALUE)) {
       		SendMessage(Handle, BFFM_SETSTATUSTEXT, FALSE, (LPARAM)"RESMAP.000 exists: YES");
        } else {
    		SendMessage(Handle, BFFM_SETSTATUSTEXT, FALSE, (LPARAM)"RESOURCE.MAP/RESMAP.000 exists: NO");
        }
   	} else {
    	SendMessage(Handle, BFFM_SETSTATUSTEXT, FALSE, (LPARAM)"RESOURCE.MAP exists: YES");
    }
    SendMessage(Handle, BFFM_ENABLEOK, 0, LPARAM(FILE_FOUND));
}
//---------------------------------------------------------------------------
BOOL TDirDialog::Execute()
{
    BROWSEINFO    info;
    char          szDir[MAX_PATH];
    char          szDisplayName[MAX_PATH];
    LPITEMIDLIST  pidl;
    LPMALLOC      pShellMalloc;

    ddPtr = this;
    FullPath = InitialDir;

    if(SHGetMalloc(&pShellMalloc) == NO_ERROR)
    {
        memset(&info, 0x00, sizeof(info));
        info.hwndOwner = 0;
        info.pidlRoot  = NULL;
        info.pszDisplayName = szDisplayName;
        info.lpszTitle = Caption.c_str();
        info.ulFlags   = BIF_RETURNONLYFSDIRS;
        if(MAP_CHECK) info.ulFlags|=BIF_STATUSTEXT;
        info.lpfn      = BrowseProc;             // callback function

        pidl = SHBrowseForFolder(&info);

        if(pidl)
        {
            if(SHGetPathFromIDList(pidl, szDir))
            {
            	int sl=strlen(szDir);
    			if(szDir[sl-1]=='\\')
             		szDir[sl-1]='\0';
                FullPath = AnsiString(szDir);
            }

            pShellMalloc->Free(pidl);
        }
		pShellMalloc->Release();
    }
    return pidl!=NULL;
}                               
//---------------------------------------------------------------------------