//---------------------------------------------------------------------------
#ifndef _ssres_h_
#define _ssres_h_
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define MSG_DEFRESERROR "The game you are trying to open is incomplete, corrupt, or not the correct version!"
//---------------------------------------------------------------------------
#define rsMAX_ALLOCS		64
#define rsALLOCBUFSZ		480 // just under 16K    
#define MAX_VOC_GROUPS		(4096)

typedef struct _RESINFO {
	U8			type;
    U8			pack;
    U16			encType;
    U16			number;
	U32			offset;
    U32			size;
    U32			encSize;
    _RESINFO 	*prev;
    _RESINFO 	*next;
} RESINFO;

typedef struct {
	U8			type;
    U8			pack; 
    U16			number; 
    U16			size;
} RESIDFO;

typedef struct {
	RESINFO	*resInfo[TOTAL_RES_TYPES2];
	int		totalRes[TOTAL_RES_TYPES2];
	RESINFO	*selResItems[TOTAL_RES_TYPES2];
	int		selRes;
    int		totalAllocs;
    int		allocPtr;
    int 	maxPack;
    RESINFO	*allocBufs[rsMAX_ALLOCS];
    RESINFO	*lastAlloc;
} RESIDX;
extern RESIDX ResIdx;


typedef struct {  
	U8	index;
	U8	id;
	char *name;
    char *namePl;
    char *ext;
    char *abbr;
    char *description;
	int iconIndex;
    struct _EDTWND *edtWnd;
    TTabSheet* previewPage;
    char *filter;
} RESTYPE;
extern RESTYPE resTypes[TOTAL_RES_TYPES3];

extern int extractStatus;
//---------------------------------------------------------------------------
// resource map defines

#define rmMIN_SIZE			6

//[U16]+[U32]=Map entry
// first U16
#define rmGET_TYPE(n) 		((U8) (((n)>>11)&0x1F))
#define rmGET_NUMBER(n)		((U16)((n)&0x07FF))
// next U32
#define rmGET_PACKAGE(n)	((U8) (((n)>>26)&0x3F))
#define rmGET_OFFSET(n)		((U32)((n)&0x03FFFFFF))
// first U16
#define rmSET_TYPE(n) 		((U16)(((n)&0x1F)<<11))
#define rmSET_NUMBER(n)		((U16)((n)&0x07FF))
// next U32
#define rmSET_PACKAGE(n)	((U32)(((n)&0x3F)<<26))
#define rmSET_OFFSET(n)		((U32)((n)&0x03FFFFFF))


// first U16
#define rmGET_NUMBER_SCI1(n)		((U16)(n))
// next U32
#define rmGET_PACKAGE_SCI1(n)		((U8) (((n)>>28)&0xF))
#define rmGET_OFFSET_SCI1(n)		((U32)((n)&0x0FFFFFFF))
// first U16
#define rmSET_NUMBER_SCI1(n)		((U16)(n))
// next U32
#define rmSET_PACKAGE_SCI1(n)		((U32)(((n)&0xF)<<28))
#define rmSET_OFFSET_SCI1(n)		((U32)((n)&0x0FFFFFFF))

// first U16
#define rmGET_NUMBER_SCI11(n)		((U16)(n))
// next U32
#define rmGET_PACKAGE_SCI11(n)		0
#define rmGET_OFFSET_SCI11(n)		((U32)((n)&0x00FFFFFF)<<1)
// first U16
#define rmSET_NUMBER_SCI11(n)		((U16)(n))
// next U32
#define rmSET_PACKAGE_SCI11(n)		0
#define rmSET_OFFSET_SCI11(n)		((U32)((n)&0x00FFFFFF)>>1)


#define MAKE_RESFILE_HEADER(a) ((a)|0x80)

//---------------------------------------------------------------------------
// extract resource
#define erBUFFER		  	0x00
#define erFILE			  	0x01
#define erFILENAME		  	0x02
#define erSHOW_MESSAGES  	0x08
//---------------------------------------------------------------------------
BOOL LoadMap(void);


BOOL VerifyVocab000(U8 *buf, U16 resLen); 
BOOL VerifyVocab900(U8 *buf, U16 resLen);
BOOL VerifyVocab999_0(U8 *buf, U16 resLen); 
BOOL VerifyVocab999_1(U8 *buf, U16 resLen);
S16  CheckScript(U8 *buf, U16 resLen);
S16  VerifyView(U8 *buf, U16 resLen);


S16  CheckSCI0(void);
BOOL CheckSCI1EGA(void);
S16 CheckSCI1VGAEGA(void);
S16 CheckSCI1Amiga(void);

void InitResInfo(BOOL ALLOCATE);
void DisposeResInfo(void);
void AllocResMem(void);
RESINFO *AddResInfo(RESINFO *prev, U8 type, U8 pack, U16 number, U32 offset);
FILE *FindMapEntry(RESINFO *resInfo, U32 *ml);
void DelResInfo(RESINFO *resInfo);
void AddResInfoStruct(RESINFO *resInfo);
RESINFO *FindLastResInfo(int type);
RESINFO *FindRes(int type, int number, int pack, long offset);
RESINFO *FindEncRes(int encType);
RESINFO *FindFirstRes(void);

U8 *ExtractResource(RESINFO *resInfo, U8 mode, U16 *len, char *fileName);
BOOL ExtractAllRes(char *path, int type);
RESINFO *AddResource(U8 *buf, U16 len, U8 type, S16 number, U8 pack);
BOOL DelMapEntry(RESINFO *resInfo);

int CheckSCIFileHeader(U8 *rBuf);
int GetFileExtNumber(char *s);        
BOOL CheckStringNum(char *str);

AnsiString AnsiStringFmtRes(int type, int number);

void SetResIDfo(RESIDFO *resIDfo, RESINFO *resInfo);
int GetResTypeIndex(char* s);
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------