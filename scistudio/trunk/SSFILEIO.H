//---------------------------------------------------------------------------
#ifndef _ssfileio_h_
#define _ssfileio_h_
//---------------------------------------------------------------------------
// path modes
#define  ssFIO_ROOT			0		// load a file with an absolute path
#define  ssFIO_GAME			1		// load a file in the game folder
#define  ssFIO_GAME_SRC		2		// load a file in the game's src folder
#define  ssFIO_MESSAGE 		0x80
//---------------------------------------------------------------------------
FILE *ssOpenFile(const U8 path, const char *filename, const char *mode);
U8 *ssLoadFile(const U8 path, const char *filename, U32 *len);
U8 *ssLoadFileEx(const U8 path, const char *filename, U32 *len);
/*void ssCloseFile(FILE  *fHandle);
U8   ssFGetB(FILE  *fHandle);
U32  ssFRead(FILE  *fHandle, U8 *buf, U32 len);  */
#define ssCloseFile(fHandle) \
	fclose(fHandle)
#define ssFGetB(fHandle) \
	fgetc(fHandle)
#define ssFGetW(fHandle) \
	(U16)(fgetc(fHandle)|(fgetc(fHandle)<<8))
#define ssFGetT(fHandle) \
	(U32)(fgetc(fHandle)|(fgetc(fHandle)<<8)|(fgetc(fHandle)<<16))
#define ssFGetL(fHandle) \
	(U32)(fgetc(fHandle)|(fgetc(fHandle)<<8)|(fgetc(fHandle)<<16)|(fgetc(fHandle)<<24))
#define ssFPutB(b,fHandle) \
	fputc(b,fHandle)
#define ssFPutW(w,fHandle) \
	fputc((w)&0xFF,fHandle);fputc((w)>>8,fHandle)
#define ssFPutT(l,fHandle) \
	fputc((l)&0xFF,fHandle);fputc((l)>>8,fHandle);fputc((l)>>16,fHandle)
#define ssFPutL(l,fHandle) \
	fputc((l)&0xFF,fHandle);fputc((l)>>8,fHandle);fputc((l)>>16,fHandle);fputc((l)>>24,fHandle)

#define ssBGetW(buf) \
	(U16)( (buf)[0] | ((buf)[1]<<8) )
#define ssBGetT(buf) \
	(U32)( (buf)[0] | ((buf)[1]<<8) | ((buf)[2]<<16))
#define ssBGetL(buf) \
	(U32)( (buf)[0] | ((buf)[1]<<8) | ((buf)[2]<<16) | ((buf)[3]<<24) )

#define ssBPutW(w,buf) \
	(buf)[0] = w&0xFF;(buf)[1]=w>>8
#define ssBPutT(l,buf) \
	(buf)[0] = w&0xFF;(buf)[1]=w>>8;(buf)[2]=w>>16
#define ssBPutL(l,buf) \
	(buf)[0] = w&0xFF;(buf)[1]=w>>8;(buf)[2]=w>>16;(buf)[3]=w>>24

#define ssFRead(buf, len,fHandle) \
	((U32)fread(buf, len, 1, fHandle))
#define ssFWrite(buf, len,fHandle) \
	((U32)fwrite(buf, len, 1, fHandle))
#define ssFSeek(fHandle,offset,whence) \
	fseek(fHandle, offset, whence)
#define ssFTell(fHandle) \
	ftell(fHandle)
#define ssFPrint fprintf
U32  ssFileLen(FILE *fHandle);

BOOL CopyFiles(char *FromDirectory, char *ToDirectory);
void FixPath(char *s);

#define ssMAX_PATH_LEN	1024
//---------------------------------------------------------------------------
#endif                                                                  
//---------------------------------------------------------------------------

