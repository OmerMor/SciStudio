//---------------------------------------------------------------------------
#include "scihdr.h"
//---------------------------------------------------------------------------
char	szTitle[128];
char	szMessage[4096];
//---------------------------------------------------------------------------
int ssMessage(int type, char *str, ...)
{
	UINT uType=0;
	va_list argptr;
	int cnt;

	switch(type&0xF) {
		case ssERROR:
			uType |= MB_ICONERROR;
            sprintf(szTitle,"%s Error!",Program.title);
			break;
		case ssWARNING:
			uType |= MB_ICONWARNING;
            sprintf(szTitle,"%s Warning!",Program.title);
			break;
		default:
			uType |= MB_ICONINFORMATION;
            sprintf(szTitle,"%s Message",Program.title);
	};
	switch(type&0xF0) {
		case ssYESNO:
			uType |= MB_YESNO;
			break;
		case ssYESNOCANCEL:
			uType |= MB_YESNOCANCEL;
			break;
		default:
			uType |= MB_OK;
	};

	va_start(argptr, str);
	cnt = vsprintf(szMessage, str, argptr);
	va_end(argptr);


    cnt = Application->MessageBox(
    	szMessage,
    	szTitle,
    	uType
	);

	return(cnt);
}
//---------------------------------------------------------------------------