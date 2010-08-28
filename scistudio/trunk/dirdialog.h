//---------------------------------------------------------------------------

#ifndef dirdialogH
#define dirdialogH
//---------------------------------------------------------------------------
class TDirDialog
{
public:
	TDirDialog();
	BOOL Execute();
    HWND Handle;
    AnsiString Title,Caption,InitialDir,FullPath;
    BOOL MAP_CHECK;
    void CheckMap(char *szDir);
};
#endif
 