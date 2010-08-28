//---------------------------------------------------------------------------
#include "scihdr.h"
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
char fName[ssMAX_PATH_LEN];
//---------------------------------------------------------------------------
FILE  *ssOpenFile(const U8 path, const char *filename, const char *mode)
{
	FILE *f;

    // path+stuff better not be >1023!
    switch(path&0x0F) {
    	case ssFIO_ROOT:
        	strcpy(fName,filename);
            break;
    	case ssFIO_GAME:
        	sprintf(fName,"%s\\%s",Game.path,filename);
            break;
    	case ssFIO_GAME_SRC:
        	sprintf(fName,"%s\\src\\%s",Game.path,filename);
            break;
    }
	if((f=fopen(fName,mode))==0) {
    	if(path&ssFIO_MESSAGE) ssMessage(ssERROR,"Unable to open file %s!", fName);
        return NULL;
    }
    return f;
}          
//---------------------------------------------------------------------------
U8 *ssLoadFile(const U8 path, const char *filename, U32 *len)
{
	FILE *f;
    U8 *buf;
    U32 fLen;
    if((f=ssOpenFile(path, filename, "rb"))==0) return NULL;
    fLen = ssFileLen(f);  /*
    if(fLen>rsMAX_SIZE) {
     	ssMessage(ssERROR,"The file you are trying to open, %s, is too large for the SCI interpreter to handle!",filename);
        return NULL ;
    }            */
    *len = (U32)fLen;
    buf = (U8*)ssAlloc(fLen);
    fread(buf,fLen,1,f);
    ssCloseFile(f);


    return buf;
}
//---------------------------------------------------------------------------
U8 *ssLoadFileEx(const U8 path, const char *filename, U32 *len)
{
	FILE *f;
    U8 *buf;
    U32 fLen;

    if((f=ssOpenFile(path, filename, "rb"))==0) return NULL;     
    fLen = ssFileLen(f);
    *len = fLen;
    buf = (U8*)ssAlloc(fLen);
    fread(buf,fLen,1,f);
    ssCloseFile(f);

    return buf;
}
//---------------------------------------------------------------------------
/*void ssCloseFile(FILE  *fHandle)
{
	fclose(fHandle);
}*/
//---------------------------------------------------------------------------
/*U8 ssFGetB(FILE  *fHandle)
{
	return fgetc(fHandle);
} */
//---------------------------------------------------------------------------
/*U32 ssFRead(FILE  *fHandle, U8 *buf, U32 len)
{
	return (U32)fread(buf, len, 1, fHandle);
}  */
//---------------------------------------------------------------------------
U32  ssFileLen(FILE *fHandle)
{
	U32 len,oldPos;

    oldPos = ftell(fHandle);
    fseek(fHandle,0,SEEK_END);
    len = ftell(fHandle);
    fseek(fHandle,oldPos,SEEK_SET);

	return (U32)len;
}

//---------------------------------------------------------------------------
char StartDir[ssMAX_PATH_LEN];
SECURITY_ATTRIBUTES DirSecAttr;
//---------------------------------------------------------------------------
BOOL CopyFiles(char *FromDirectory, char *ToDirectory)
{
    char DirectoryString[ssMAX_PATH_LEN], FromFileString[ssMAX_PATH_LEN], ToFileString[ssMAX_PATH_LEN],
    	 NewFromDirectoryString[ssMAX_PATH_LEN], NewToDirectoryString[ssMAX_PATH_LEN];
    WIN32_FIND_DATA FindFileData;
    HANDLE hFindFile;

    wsprintf(DirectoryString, "%s\\*.*", FromDirectory);

    hFindFile = FindFirstFile(
        DirectoryString,
        &FindFileData
    );
    do {
        if(lstrcmp(FindFileData.cFileName,"..")!=0&&lstrcmp(FindFileData.cFileName,".")!=0
            &&lstrcmp(FindFileData.cFileName,"TEMPLATE")!=0) {
            if(FindFileData.dwFileAttributes==FILE_ATTRIBUTE_DIRECTORY) {
                wsprintf(NewFromDirectoryString, "%s\\%s", FromDirectory, FindFileData.cFileName);
                wsprintf(NewToDirectoryString, "%s\\%s", ToDirectory, FindFileData.cFileName);

                if(!CreateDirectory(NewToDirectoryString,NULL)&&!DirectoryExists(AnsiString(NewToDirectoryString)))
                	return FALSE;
                if(!CopyFiles(NewFromDirectoryString, NewToDirectoryString))
                	return FALSE;
            } else {
                wsprintf(FromFileString,"%s\\%s",FromDirectory, FindFileData.cFileName);
                wsprintf(ToFileString,"%s\\%s",ToDirectory, FindFileData.cFileName);

                if(!CopyFile(FromFileString,ToFileString,FALSE))
                	return FALSE;
            }
        }
    } while(FindNextFile(hFindFile,	&FindFileData));
    return TRUE;
}
//---------------------------------------------------------------------------
void FixPath(char *s)
{
	int l=strlen(s)-1;
    if(s[l]=='\\')
     	s[l]='\0';
}
//---------------------------------------------------------------------------

