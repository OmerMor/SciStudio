//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//[U16]+[U32]=Map entry
// first U16
#define rmGET_TYPE(n) 		((BYTE)(((n)>>11)&0x1F))
#define rmGET_NUMBER(n)		((WORD)((n)&0x07FF))
// next U32
#define rmGET_PACKAGE(n)	((BYTE)(((n)>>26)&0x3F))
#define rmGET_OFFSET(n)		((long)((n)&0x03FFFFFF))
// first U16
#define rmSET_TYPE(n) 		((WORD)(((n)&0x1F)<<11))
#define rmSET_NUMBER(n)		((WORD)((n)&0x07FF))
// next U32
#define rmSET_PACKAGE(n)	((long)(((n)&0x3F)<<26))
#define rmSET_OFFSET(n)		((long)((n)&0x03FFFFFF))


#define fgetw(fHandle) \
	(WORD)(fgetc(fHandle)|(fgetc(fHandle)<<8))
#define fgett(fHandle) \
	(long)(fgetc(fHandle)|(fgetc(fHandle)<<8)|(fgetc(fHandle)<<16))
#define fgetl(fHandle) \
	(long)(fgetc(fHandle)|(fgetc(fHandle)<<8)|(fgetc(fHandle)<<16)|(fgetc(fHandle)<<24))
#define fputw(w,fHandle) \
	fputc((w)&0xFF,fHandle);fputc((w)>>8,fHandle)
#define fputt(l,fHandle) \
	fputc((l)&0xFF,fHandle);fputc((l)>>8,fHandle);fputc((l)>>16,fHandle)
#define fputl(l,fHandle) \
	fputc((l)&0xFF,fHandle);fputc((l)>>8,fHandle);fputc((l)>>16,fHandle);fputc((l)>>24,fHandle)

char *typeNames[] =
	{"view","pic","script","text","sound",
     "memory","vocab","font","cursor","patch"};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}          
//---------------------------------------------------------------------------
BOOL CheckStringNum(char *str)
{
	 int CharPos = 0;
	 if(str[0] == '\0') return FALSE;
	 if(str[0] == '0'&&(str[1]=='x'||str[1]=='X')) {
		  if(str[2] == '\0') return FALSE;
		  CharPos+=2;
		  while(str[CharPos] != '\0')
				if(!((str[CharPos] >= '0' && str[CharPos] <= '9') ||
				((char)(str[CharPos] & 0xDF) >= 'A' && (char)(str[CharPos] & 0xDF) <= 'F')))
					 return FALSE;
				else CharPos++;
	 } else {
		  if(str[0] == '+' || str[0] == '-') {
				CharPos++;
				if(str[1] == '\0') return FALSE;
		  }
		  while(str[CharPos] != '\0')
				if(str[CharPos] < '0' || str[CharPos] > '9')
						  return FALSE;
				else CharPos++;
	 }
	 return TRUE;
}
//---------------------------------------------------------------------------
int GetFileExtNumber(char *s)
{
	int sLen = strlen(s);
    if(sLen<5) return -1;
    char *se=s+sLen-3;
	if(!CheckStringNum(se)) return -1;
	return StrToInt(AnsiString(se));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	OpenDialog2->FileName = Edit1->Text;
	if(!OpenDialog2->Execute()) return;
	Edit1->Text = OpenDialog2->FileName;
    Label3->Caption = ExtractFilePath(Edit1->Text)+"resource.map";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	OpenDialog1->FileName = Edit2->Text;
	if(!OpenDialog2->Execute()) return;
	Edit2->Text = OpenDialog1->FileName;
    Label4->Caption = ExtractFilePath(Edit1->Text)+"resource.001";
}         
//---------------------------------------------------------------------------
void __fastcall CopyFile(AnsiString from, AnsiString to)
{
	FILE *f,*t;
    if((f=fopen(from.c_str(),"rb"))==NULL) return;
    if((t=fopen(to.c_str(),"wb"))==NULL) {
    	fclose(f);
		return;
    }
                     
    fseek(f,0,SEEK_END);
	long len = ftell(f);
    fseek(f,0,SEEK_SET);

    while(len) {
    	fputc(fgetc(f),t);
        len--;
    }

    fclose(f);
    fclose(t);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	FILE *fP,*fM;
    long len,offs;
    int id,pack,enclen;

    pack = (WORD)GetFileExtNumber((char*)Edit1->Text.c_str());
    if(pack==-1) {
     	ShowMessage("File: "+Edit1->Text+" is not named as a correct SCI0 resource package!");
        return;
    }
    if(CheckBox1->Checked)
    	CopyFile(Label3->Caption, Label3->Caption+".old");

    if((fP=fopen(Edit1->Text.c_str(),"rb"))==NULL) {
     	ShowMessage("Error opening file: "+Edit1->Text+" for reading!");
        return;
    }
    if((fM=fopen(Label3->Caption.c_str(),"wb"))==NULL) {
        fclose(fP);
     	ShowMessage("Error opening file: "+Label3->Caption+" for writing!");
        return;
    }

    ListBox1->Items->Clear();

    fseek(fP,0,SEEK_END);
	len = ftell(fP);
    fseek(fP,0,SEEK_SET);

    while((offs = ftell(fP))<len) {
    	id = fgetw(fP);
    	enclen = fgetw(fP);
        fseek(fP,enclen,SEEK_CUR);
        fputw(id,fM);
        fputl(rmSET_OFFSET(offs)|rmSET_PACKAGE(pack),fM);
    	ListBox1->Items->Add(AnsiString(typeNames[rmGET_TYPE(id)])+" #"+IntToStr(rmGET_NUMBER(id)));
    }
    fwrite("\xFF\xFF\xFF\xFF\xFF\xFF",6,1,fM);
    fclose(fM);
    fclose(fP);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{           /*
	FILE *fP,*fM;
    long len,offs;
    int id,pack,enclen;

    pack = (WORD)GetFileExtNumber((char*)Label4->Caption.c_str());
    if(pack==-1) {
     	ShowMessage("File: "+Label4->Caption+" is not named as a correct SCI0 resource package!");
        return;
    }

    if((fM=fopen(Edit1->Text.c_str(),"rb"))==NULL) {
     	ShowMessage("Error opening file: "+Edit1->Text+" for reading!");
        return;
    }
    if((fP=fopen(Label4->Caption.c_str(),"rb+"))==NULL) {
        fclose(fM);
     	ShowMessage("Error opening file: "+Label4->Caption+" for writing!");
        return;
    }

    ListBox1->Items->Clear();

    fseek(fM,0,SEEK_END);
	len = ftell(fP);
    fseek(fM,0,SEEK_SET);

    while(ftell(fM)<len) {  
    	id = fgetw(fM);
    	if(id==0xFFFF) break; 
        fseek(fP,rmGETfgetL(fM)),SEEK_CUR);

    	enclen = fgetw(fP);
        fseek(fP,enclen,SEEK_CUR);
        fputw(id,fM);
        fputl(rmSET_OFFSET(offs)|rmSET_PACKAGE(pack),fM);
    	ListBox1->Items->Add(AnsiString(typeNames[rmGET_TYPE(id)])+" #"+IntToStr(rmGET_NUMBER(id)));
    }
    fclose(fM);
    fclose(fP); */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------

