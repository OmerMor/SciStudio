//---------------------------------------------------------------------------
#include "scihdr.h"     
#include "explorer.h"
#include "addresource.h"  
#include "scc\scc.h"   
#include "main.h"


#include "stdafx.h"
#include "resvol.h"
#include <stdlib.h>
#include <memory.h>
#include "lzs.h"
#include "pkdcl.h"
//---------------------------------------------------------------------------
RESIDX	ResIdx;

RESTYPE resTypes[TOTAL_RES_TYPES3] = {
	{0x00, 0x80, "View",		"Views",	"v16", "v", "animated elements",
    	3, &edtWnds[rsVIEW], NULL,
        "SCI View Resource (view.*)|view.*|All Files (*.*)|*.*"},//WndExplorer->ViewPage},
	{0x01, 0x81, "Pic",		"Pics", 	"p16", "p", "background pictures",
    	4, &edtWnds[rsPIC], NULL,
        "SCI Pic Resource (pic.*)|pic.*|All Files (*.*)|*.*"},//WndExplorer->PicPage},
	{0x02, 0x82, "Script",	"Scripts",	"scr", "s", "scripts contain the code telling the game what to do, and how to interact with the player",
    	5, &edtWnds[rsSCRIPT], NULL,
        "SCI Script Resource (script.*)|script.*|All Files (*.*)|*.*"},//WndExplorer->MemoPage},
	{0x03, 0x83, "Text",		"Texts",	"tex", "t", "text resources link with the scripts, allowing the game to store external, easy to modify text",
    	6, &edtWnds[rsTEXT], NULL,
        "SCI Text Resource (text.*)|text.*|All Files (*.*)|*.*"},//WndExplorer->MemoPage},
	{0x04, 0x84, "Sound",		"Sounds",	"snd", "m", "sound effects and music",
    	7, &edtWnds[rsSOUND], NULL,
        "SCI Sound Resource (sound.*)|sound.*|All Files (*.*)|*.*"},//WndExplorer->SoundPage},
	{0x05, 0x85, "Memory",	"Memory",	"mem", "X", "internal memory allocated a runtime. (not stored in resources)",
    	8, NULL, NULL,""},//WndExplorer->PageNoPrev},
	{0x06, 0x86, "Vocab",		"Vocabs",	"voc", "w", "vocabulary resources all have different purposes, but primarily deal with parsing the player's input",
    	9, &edtWnds[rsVOCAB], NULL,
        "SCI Vocab Resource (vocab.*)|vocab.*|All Files (*.*)|*.*"},//WndExplorer->MemoPage},
	{0x07, 0x87, "Font",		"Fonts",	"fon", "f", "fonts, the text styles drawn by the game",
    	10, &edtWnds[rsFONT], NULL,
        "SCI Font Resource (font.*)|font.*|All Files (*.*)|*.*"},//WndExplorer->FontPage},
	{0x08, 0x88, "Cursor",	"Cursors",	"cur", "c", "mouse graphics to show the position of the cursor",
    	11, &edtWnds[rsCURSOR], NULL,
        "SCI Cursor Resource (cursor.*)|cursor.*|All Files (*.*)|*.*"},//WndExplorer->CursorPage},
	{0x09, 0x89, "Patch",		"Patches",	"pat", "a", "sound patch files for dealing with the source drivers",
    	12, NULL, NULL,
        "SCI Patch Resource (patch.*)|patch.*|All Files (*.*)|*.*"},//WndExplorer->PageNoPrev},

	{0x0A, 0x8A, "Bitmap",		"Bitmaps",	"bit", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x0B, 0x8B, "Palette",		"Palettes",	"pal", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},

	{0x0C, 0x8C, "CD Audio",	"CD Audio",	"cda", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x0D, 0x8D, "Audio",		"Audio",	"aud", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x0E, 0x8E, "Sync",		"Syncs",	"syn", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x0F, 0x8F, "Message",		"Messages",	"msg", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x10, 0x90, "Map",			"Maps",		"map", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x11, 0x91, "Heap",  		"Heaps",   	"hep", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x12, 0x92, "Chunk",  		"Chunks",  	"chk", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x13, 0x93, "Audio36",  	"Audio36",  "a36", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x14, 0x94, "Aync36",  	"Sync36",   "s36", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"}, 
	{0x15, 0x95, "Translation", "Translations", "trn", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x16, 0x96, "Robot",  		"Robots",   	"rbt", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x17, 0x97, "VMD",  		"VMD",   	"vmd", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x18, 0x98, "Duck",  		"Ducks",   	"duk", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x19, 0x99, "Clut",  		"Cluts",   	"clu", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x1A, 0x9A, "Targa",  		"Targas",   "tga", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x1B, 0x9B, "ZZZ",  		"ZZZ",   "zzz", "x", "x",
    	0, NULL, NULL,
        "x (x.*)|x.*|All Files (*.*)|*.*"},
	{0x1C, 0x00, "Script Header",	"Headers",	"sch", "h", "source code header files",
    	13, NULL, NULL,""},//WndExplorer->MemoPage},

	{0x1D, 0x00, "Game Explorer",	"",	"", "", "resources are managed by the Game Explorer",
    	15, &edtWnds[wnEXPLORER], NULL,""},//WndExplorer->MemoPage},
};

char szTemp[1024];
U8 *bufTemp;
int extractStatus;
//---------------------------------------------------------------------------
#define SET_PACK(n) \
	PACK_USED[(n>>3)] |= (0x80>>(n&7))
#define GET_PACK(n) \
	((PACK_USED[n>>3] >> (7-(n&7))) &1)
//---------------------------------------------------------------------------
BOOL LoadMap()
{
	FILE	*fPack;
	U32		ulMapLen;
	U8		*mapBuf,*mapPtr,*mapPtrEnd,*buf;
    S32		curEnt,totalEnt;
    RESINFO *ri,*ori;
    U16 ident,num;
    U32 addr;
    U8 resType,pack;
    U16 offs;
    S16 maxEncodeType;
    BOOL SCI1_MAP,SCI32_MAP,MAP_OK;
    S16 i,v,st;
    U8 PACK_USED[8];
    U8 mapType = sv_MT_1;
    U32 couldBeType,subType;

    WRITE_STATUS("Loading Map...");

    // load the map
    SCI32_MAP = FALSE;
    if((mapBuf=ssLoadFile(ssFIO_GAME,"resource.map",&ulMapLen))==0) {
    	if((mapBuf=ssLoadFile(ssFIO_GAME,"resmap.000",&ulMapLen))==0) {
        	ssMessage(ssERROR,"No Map File Found! RESOURCE.MAP or RESMAP.000 could not be located in the specified directory or opened for reading!");
    		return FALSE;
        }
        SCI32_MAP = TRUE;     
    	WRITE_STATUS("Found SCI32 Map...");
    } else {
    	WRITE_STATUS("Detecting Map Version...");
    }

    // no bugs in the champagne room=make sure the map is valid
    if(ulMapLen < rmMIN_SIZE) {
		ssMessage(ssERROR,"Invalid resource.map file! File too small!");
        ssFree(mapBuf);
        return FALSE;
    }
    mapPtrEnd = mapBuf+ulMapLen;

        TCGauge *pb1=new TCGauge(WndMain->StatusBar);
        pb1->Parent = WndMain->StatusBar;
        pb1->MinValue = 0;
        pb1->MaxValue = TOTAL_RES_TYPES*ResIdx.maxPack;
        pb1->Progress = 0;
        pb1->Left = 1;
        pb1->Top = 1;
        pb1->Width = 98;
        pb1->Height = 18;

    if(!SCI32_MAP) {
		// Check if it's an SCI1 map
	
	    // there can't be more than TOTAL_RES_TYPES+1 entries (though there wouldn't even be that many).
	    // If it can't find the terminator by then, it can't be valid SCI1
	    SCI1_MAP = TRUE;
		mapPtr = mapBuf;
		while(mapPtr<mapPtrEnd) {
	    	resType = *mapPtr;
	        offs = ssBGetW(mapPtr+1);
	        mapPtr += 3;
			if((U8)resType==(U8)0xFF) {  // terminator
	        	if(offs!=ulMapLen)
	             	SCI1_MAP = FALSE;
	            break;
	        }
	        if((resType<0x80||resType>=(0x80|TOTAL_RES_TYPES)) || offs > ulMapLen) {
	        	SCI1_MAP = FALSE;
	            break;
	        }
	    }
	    if(mapPtr>=mapPtrEnd)
	    	SCI1_MAP = FALSE;
	    // check if it could possibly be an SCI0 type map
	    if(!SCI1_MAP) {
	    	mapPtr = mapBuf+ulMapLen-6;
	     	for(i=0;i<6;i++) {
	        	if((U8)*mapPtr!=(U8)0xFF) {
	            	ssMessage(ssERROR, "The game you are trying to load is either not a supported SCI version or corrupt/invalid!");
	        		ssFree(mapBuf);
	        		return FALSE;
	            }
	            mapPtr++;
	        }
	    }
	}
    WRITE_STATUS("Loading Map...");
    memset(PACK_USED,0,sizeof(PACK_USED));
 	if(SCI32_MAP) {
        pb1->MaxValue = TOTAL_RES_TYPES*2+1;
        	// find the map pointers for the current resource
            mapPtr = mapBuf;
            MAP_OK = TRUE;

            while(mapPtr<mapPtrEnd) {
                offs = ssBGetW(mapPtr+1);
				if((U8)*mapPtr==(U8)0xFF) {  // terminator
	        		if(offs!=ulMapLen)
	             		SCI1_MAP = FALSE;
                    mapPtr = NULL;
	            	break;
	        	}
	        	if(/*resType>=TOTAL_RES_TYPES) || */offs > ulMapLen) {
	        		MAP_OK = FALSE;
	           		break;
	        	}
                mapPtr += 3;
            }
	    	if(mapPtr>=mapPtrEnd)
	    		MAP_OK = FALSE;
           	if(!MAP_OK) {
             	ssMessage(ssERROR,
                	"An SCI32 game was found, but an error occured while attemping to load it. It is either an unsupported format or corrupt!");
                ssFree(mapBuf);
             	return FALSE;
            }

	    // Read the map data and load the resource headers into memory
	    // first load them up with the map data
		InitResInfo(TRUE);
		for(int t=0;t<TOTAL_RES_TYPES;t++) {
        	// find the map pointers for the current resource
			mapPtr = mapBuf;
			while(mapPtr<mapPtrEnd) {
				if(*mapPtr==0xFF) {
                	mapPtr = NULL;
            		break;
                }
            	if(*mapPtr==t) { // no 0x80 in SCI32
                    mapPtrEnd	= mapBuf+ssBGetW(mapPtr+4);
                 	mapPtr		= mapBuf+ssBGetW(mapPtr+1);
                    break;
                }
        		mapPtr += 3;
        	}
            if(mapPtr) {
	        	BOOL first=TRUE;
	        	ri = NULL;
            	while(mapPtr<mapPtrEnd) {
            		ri = AddResInfo(ri, t, 0, ssBGetW(mapPtr), ssBGetL(((U8*)mapPtr+2)));
               		mapPtr+=6;
                	if(first) {
                		first=FALSE;
                    	ResIdx.resInfo[t] = ri;
           		     }
            	}
            	if(ri!=NULL) ri->next = NULL;
            }
            pb1->Progress++;
            Application->ProcessMessages();
	    }
	    // now get rid of the map, it's wasting memory!
	    ssFree(mapBuf);

    	WRITE_STATUS("Loading Resource Information...");
	    maxEncodeType = -1;
        Application->ProcessMessages();
	    // fill in the rest of the res headers by reading the packages
	    for(int p=0;p<1;p++) {
			sprintf(szTemp,"ressci.%03d",p);
            if((fPack = ssOpenFile(ssFIO_GAME,szTemp,"rb"))==NULL) {
                ssMessage(ssERROR,"Could not open file: %s!",szTemp);
                DisposeResInfo();
               	return FALSE;
            }
	    	for(int t=0;t<TOTAL_RES_TYPES;) {
                pb1->Progress++;
                Application->ProcessMessages();
	    		if(ResIdx.totalRes[t]&&ResIdx.resInfo[t]!=NULL) {
	       	     	ri = ResIdx.resInfo[t];
	        		do {
	                	if(ri->pack==p) {
                        	if(!fPack) {
                            	ori = ri;
	                    		ri = ri->next;
                        		DelResInfo(ori);
                            } else {
	                    	fseek(fPack,ri->offset,SEEK_SET);
                            resType = ssFGetB(fPack)&0x7F;
	                 		num = ssFGetW(fPack);
	                    	if(resType!=ri->type||num!=ri->number) {
	                       		ssMessage(ssERROR,"Resource package/map file identifier mismatch! "MSG_DEFRESERROR);
	                        	DisposeResInfo();
	                       		return FALSE;
	                    	}
							ri->encSize	= (U32)ssFGetL(fPack);
							ri->size 	= (U32)ssFGetL(fPack);
							ri->encType = (ri->encSize==ri->size)?0:1;//(U16)ssFGetW(fPack);
	                        if(maxEncodeType<ri->encType)
	                          	maxEncodeType = ri->encType;
                            }
	                    }
	                    ri = ri->next;
	        		} while(ri!=NULL);
	        	}
                t++;
	    	}
	        ssCloseFile(fPack);
	    }
        pb1->Progress++;
        Application->ProcessMessages();
        Game.version = &versions[svSCI_32];
        delete pb1;
		return TRUE;
    } else if(SCI1_MAP) {
    	// find the sub version (SCI1=6 byte entries, SCI11=5, SCI20=6)
        couldBeType = 3;
    	for(int skip=5;skip<=6;skip++) {
			for(int t=0;t<TOTAL_RES_TYPES;t++) {
        		// find the map pointers for the current resource
				mapPtr = mapBuf;
				while(mapPtr<mapPtrEnd) {
					if(*mapPtr==0xFF) {
                		mapPtr = NULL;
            			break;
                	}
            		if((*mapPtr&0x7F)==t) {
                    	mapPtrEnd	= mapBuf+ssBGetW(mapPtr+4);
                 		mapPtr		= mapBuf+ssBGetW(mapPtr+1);
                    	break;
                	}
        			mapPtr += 3;
        		}
            	if(!mapPtr) continue; // none of that type
	    		while(mapPtr<mapPtrEnd)
	            	mapPtr+=skip;
           		if(mapPtr!=mapPtrEnd) {
                	CLEAR_BIT32(couldBeType,skip-5);
                    break;
                }
            }
        }
        switch(couldBeType) {
         	case 1:
             	subType=1;
                break;
         	case 2:
             	subType=0;
                break; /*
         	case 4:
             	subType=2;
                break;   */
         	default: // OUCH!!!!!!!!!
             	ssMessage(ssERROR,"Unable to detetect specific SCI1+ version. Detection will be implemented further.");
                break;
        }
	    // Read the map data and load the resource headers into memory
	    // first load them up with the map data
		InitResInfo(TRUE);
		for(int t=0;t<TOTAL_RES_TYPES;t++) {
        	// find the map pointers for the current resource
			mapPtr = mapBuf;
			while(mapPtr<mapPtrEnd) {
				if(*mapPtr==0xFF) {
                	mapPtr = NULL;
            		break;
                }
            	if((*mapPtr&0x7F)==t) {
                    mapPtrEnd	= mapBuf+ssBGetW(mapPtr+4);
                 	mapPtr		= mapBuf+ssBGetW(mapPtr+1);
                    break;
                }
        		mapPtr += 3;
        	}
            if(!mapPtr) continue; // none of that type

	        BOOL first=TRUE;
	        ri = NULL;
            if(subType==0) {// SCI10
	    		while(mapPtr<mapPtrEnd) {
            		pack = rmGET_PACKAGE_SCI1(ssBGetL(((U8*)mapPtr+2)));
            		SET_PACK(pack);
            		ri = AddResInfo(ri, t, pack, ssBGetW(mapPtr), rmGET_OFFSET_SCI1(ssBGetL(((U8*)mapPtr+2))));
	            	mapPtr+=6;

                	if(first) {
                		first=FALSE;
                    	ResIdx.resInfo[t] = ri;
                	}
	        	}
	        	if(ri!=NULL) ri->next = NULL;
            } else if(subType==1) {// SCI11
	    		while(mapPtr<mapPtrEnd) {
            		pack = rmGET_PACKAGE_SCI11(ssBGetT(((U8*)mapPtr+2)));
            		SET_PACK(pack);
            		ri = AddResInfo(ri, t, pack, ssBGetW(mapPtr), rmGET_OFFSET_SCI11(ssBGetT(((U8*)mapPtr+2))));
	            	mapPtr+=5;

                	if(first) {
                		first=FALSE;
                    	ResIdx.resInfo[t] = ri;
                	}
	        	}
	        	if(ri!=NULL) ri->next = NULL;
            }
	    }
	    // now get rid of the map, it's wasting memory!
	    ssFree(mapBuf);

    	WRITE_STATUS("Loading Resource Information...");
	    maxEncodeType = -1;
	    // fill in the rest of the res headers by reading the packages
	    for(int p=0;p<=ResIdx.maxPack;p++) {
        	if(!GET_PACK(p)) continue;
			sprintf(szTemp,"resource.%03d",p);
            if((fPack = ssOpenFile(ssFIO_GAME,szTemp,"rb"))==NULL) {
            	//ssMessage(ssERROR,"Could not open file: %s! "MSG_DEFRESERROR,szTemp);
                //DisposeResInfo();
                //return FALSE;
                WRITE_STATUS("WARNING! Could not open file: "+AnsiString(szTemp)+"!");
//                continue;
            }
	    	for(int t=0;t<TOTAL_RES_TYPES;) {
	    		if(ResIdx.totalRes[t]&&ResIdx.resInfo[t]!=NULL) {
	       	     	ri = ResIdx.resInfo[t];
	        		do {
	                	if(ri->pack==p) {
                        	if(!fPack) {
                            	ori = ri;
	                    		ri = ri->next;
                        		DelResInfo(ori);
                            	continue;
                            }
	                    	fseek(fPack,ri->offset,SEEK_SET);
                            resType = ssFGetB(fPack)&0x7F;
	                 		num = ssFGetW(fPack);
	                    	if(resType!=ri->type||num!=ri->number) {
	                       		ssMessage(ssERROR,"Resource package/map file identifier mismatch! "MSG_DEFRESERROR);
	                        	DisposeResInfo();
	                       		return FALSE;
	                    	}
							ri->encSize	= (U16)((U16)ssFGetW(fPack)-(U16)4);
							ri->size 	= (U16)ssFGetW(fPack);
							ri->encType = (U16)ssFGetW(fPack);
	                        if(maxEncodeType<ri->encType)
	                          	maxEncodeType = ri->encType;
	                    }
	                    ri = ri->next;
	        		} while(ri!=NULL);
	        	}
                t++;
	    	}
	        ssCloseFile(fPack);
	    }
      	switch(subType) {
        	case 0:
            	Game.version = &versions[svSCI_10_VGA_LATE];
                break;
        	case 1:
            	Game.version = &versions[svSCI_11_ORIGINAL];
                break;
        }
		return TRUE;
    } else {// SCI0 map
	    curEnt = ulMapLen/6;
	    // parse the map
	    // two loop breakers to make sure of no crashing!
	    totalEnt = 0;
        mapPtr = mapBuf;
	    while(curEnt&&mapPtr<mapPtrEnd) {
			ident = ssBGetW(mapPtr);
			addr = ssBGetL((mapPtr+2));
	    	if((U16)ident==(U16)0xFFFF&&(U16)addr==(U16)0xFFFFFFFF) break;
			mapPtr+=6;
	        totalEnt++;
	        curEnt--;
	    }
	
	
	    // Read the map data and load the resource headers into memory
	

	    // first load them up with the map data
	    InitResInfo(TRUE);
        int quex=0;
	    for(int t=0;t<TOTAL_RES_TYPES;t++) {
	    	mapPtr = mapBuf;
	        BOOL first=TRUE;
	        ri = NULL;
	    	for(int i=0;i<totalEnt;i++) {
	        	if(rmGET_TYPE(ssBGetW(mapPtr))==t) {
	    			ri = AddResInfo(ri,t,-1,rmGET_NUMBER(ssBGetW(mapPtr)),ssBGetL(((U8*)mapPtr+2)));
	                if(first) {
	                	first=FALSE;
	                	ResIdx.resInfo[t] = ri;
	             	}
                    if(ri->offset & 0x04000000) mapType = sv_MT_0;
                    quex++;
	            }
	            mapPtr+=6;
	        }
	        if(ri!=NULL) ri->next = NULL;
	    }
	    // now get rid of the map, it's wasting memory!
	    ssFree(mapBuf);

    	WRITE_STATUS("Loading Resource Information...");
	    maxEncodeType = -1;
        int quex2 = 0;
	    // fill in the rest of the res headers by reading the packages
	    for(int p=0;p<=ResIdx.maxPack;p++) {
			sprintf(szTemp,"resource.%03d",p);
            if((fPack = ssOpenFile(ssFIO_GAME,szTemp,"rb"))==NULL) {
            	//ssMessage(ssERROR,"Could not open file: %s! "MSG_DEFRESERROR,szTemp);
                //DisposeResInfo();
                //return FALSE;
                //WRITE_STATUS("WARNING! Could not open file: "+AnsiString(szTemp)+"!");
                //continue;
            }
	    	for(int t=0;t<TOTAL_RES_TYPES;) {
	    		if(ResIdx.totalRes[t]&&ResIdx.resInfo[t]!=NULL) {
	       	     	ri = ResIdx.resInfo[t];
	        		do {
	                	if(((mapType==sv_MT_0)?(ri->offset>>26):(ri->offset>>28))==p) {
                        	if(!fPack) {
                            	ori = ri;
	                    		ri = ri->next;
                        		DelResInfo(ori);
                            	continue;
                            }
	                    	ri->pack = p;
                            ri->offset = mapType==sv_MT_0?ri->offset&0x03FFFFFFul:ri->offset&0x00FFFFFFul;
                            quex2++;
                        	fseek(fPack,ri->offset,SEEK_SET);
	                 		ident = ssFGetW(fPack);
                            int tX=rmGET_TYPE(ident);
                            int nX=rmGET_NUMBER(ident);
	                    	if(tX!=ri->type||nX!=ri->number) {
	                       		//ssMessage(ssERROR,"Resource package/map file identifier mismatch! "MSG_DEFRESERROR);
	                        	//DisposeResInfo();
	                       		//return FALSE;
	                    	}
							ri->encSize	= (U16)((U16)ssFGetW(fPack)-(U16)4);
							ri->size 	= (U16)ssFGetW(fPack);
							ri->encType = (U16)ssFGetW(fPack);
	                        if(maxEncodeType<ri->encType)
	                          	maxEncodeType = ri->encType;
	                    }
	                    ri = ri->next;
	        		} while(ri!=NULL);
	        	}
                t++;
            	pb1->Progress++;
	    	}
	        ssCloseFile(fPack);
            pb1->Progress++;
            Application->ProcessMessages();
	    }

    	WRITE_STATUS("Detecting SCI Version...");
	    if(maxEncodeType!=-1) {
	    	// check if the extraction is successful
	        for(v=0; v<svTOTAL; v++) {
            	if(versions[v].mapType>sv_MT_1) continue;
	            if(maxEncodeType<=versions[v].maxEnc) {
	            	extractStatus=1;
					Game.version = &versions[v];
	    			for(i=1; i<=maxEncodeType; i++) {
	           			if((ri = FindEncRes(i))!=NULL) {
							if((buf = ExtractResource(ri, erBUFFER, NULL, NULL))==NULL) {
	             				if(extractStatus==-1)
	             		   			break;
	                        	DisposeResInfo();
	                            return FALSE;
	                        }
	               			ssFree(buf);
	    				}
	            	}
	                if(extractStatus==1) {
	                 	switch(v) {
	                   		case svSCI_00_EARLY:
							case svSCI_00_LATE:
	                         	if((st=CheckSCI0())!=0) {
                                    if(st==sv_ST_SCI0a)
										Game.version = &versions[svSCI_00_EARLY];
                                    else // sv_ST_SCI0b
                                    	Game.version = &versions[svSCI_00_LATE];
	                            	return TRUE;
                                }
	                            break;
							case svSCI_10_EGA_EARLY:
							case svSCI_10_EGA_LATE:
	                         	if(CheckSCI1EGA()) {
                                	Game.version = &versions[v];
	                            	return TRUE;
	                            }
	                            break;
							case svSCI_10_VGA_EARLY:
                            	st = CheckSCI1VGAEGA();
	                         	switch(st) {
                                	case sv_VT_EGA:
                                     	Game.version = &versions[svSCI_10_EGA_LATEST];
	                            		return TRUE;
                                	case sv_VT_VGA10:
                                     	Game.version = &versions[svSCI_10_VGA_EARLY];
	                            		return TRUE;
	                            }
	                        	break;
							case svSCI_10_AMIGA:  
	                         	if(CheckSCI1Amiga()) {
                                	Game.version = &versions[v];
	                            	return TRUE;
	                            }
	                        	break;
                            case svSCI_L:
                            	if(maxEncodeType==8) {
    								Game.version = &versions[svSCI_L];
    								return TRUE;
                                }
                                break;
	                    }
	                }
	            }
	        }
	    }
    }
        delete pb1;
    // Ask to select a version or else...
	DisposeResInfo();
	return FALSE; //!!!
}
//---------------------------------------------------------------------------
BOOL VerifyVocab000(U8 *buf, U16 resLen)
{
	U16 i,offs;
    if(resLen<52) {
    	return FALSE;
    }
	for(offs=0;offs<52;offs+=2) {
    	if(ssBGetW(buf+offs)>=resLen)
    		return FALSE;
    }
    while(offs<resLen) {
		i = buf[offs++];
        do {
        	if(offs>resLen)  {
    			return FALSE;
    		}
        } while((U8)buf[offs++] < 0x80);
		offs += 3;
    }
    if(offs>resLen)  {
    	return FALSE;
    }
    return TRUE;
}
//---------------------------------------------------------------------------
BOOL VerifyVocab999_0(U8 *buf, U16 resLen)
{
	U16 count,offs,i;
    count = ssBGetW(buf);
    if(resLen<(count<<1)) {
    	return FALSE;
    }
    for(i=0;i<count;i++) {
    	offs = ssBGetW(buf+2+(count<<1));

        do {
        	if(offs>=resLen)  {
    			return FALSE;
    		}
        } while(buf[offs++]);
    }         
    if(offs>resLen)  {
    	return FALSE;
    }
    return TRUE;
}
//---------------------------------------------------------------------------
// -1 = corrupt
//  0 = unknown
//  sv_VT_EGA/sv_VT_VGA10
S16 VerifyView(U8 *buf, U16 resLen)
{
	U16 totalLoops,totalCels,offs,width,height,x,y,run,i;
    U8 *p,*pEnd;

    totalLoops = *buf;
    // buf[1] should be NZ if SCI VGA
    offs = ssBGetW(buf+8);
    if(offs+2>=resLen) return -1;
   	p = buf+offs;
    offs = ssBGetW(p+4);
    if(offs+8>=resLen) return 0;
   	p = buf+offs;
	width		= ssBGetW(p);
	height		= ssBGetW(p+2);
    if(width>sPIC_WIDTH||height>sPIC_HEIGHT)
    	return -1;
    if(width==0||height==0)
    	return 0;
    p+=8;
    if(buf[1]==0x80) {
    	// well, yeah, but lets do even more validity checking!

        offs = ssBGetW(buf+6);
        if(offs>=resLen) return -1;  // could be zero but doesn't matter

    	for(y=0;y<height;y++) {
     		x = 0;
        	while(x<width) { /*
        	if(p>=pEnd) {
            	y = 9999;
                break;
            }     */
				if (*p >= 0xc0)
            		x+=*(p++)&0x3f;
				else if (*p >= 0x80) {
	  				x += *(p++)&0x7F;
	  				p++;
				} else {
            		i=*(p++);
              		x += i;
                	p += i;
            	}
      		}
        	if(x>width) {
        		y = 9999;
        		break;
        	}
    	}
    	if(y==height)
    		return sv_VT_VGA10;
    } else {
		//pEnd = p+(width*height);
    	for(y=0;y<height;y++) {
     		x = 0;
        	while(x<width) {  /*
        	if(p>=pEnd) {
            	y = 9999;
                break;
            }          */
				x+=(U8)(*p>>4);
				p++;
        	}
        	if(x>width) {
        		y = 9999;
        		break;
        	}
    	}
    	if(y==height)
    		return sv_VT_EGA;

        // Lets check 'em AMIGA!
        if(ssBGetW(buf+6)) return -1;  // should be zero, Amiga only has 32 colours!
   		p = buf+offs+8;
    	for(y=0;y<height;y++) {
     		x = 0;
        	while(x<width) {  
        		if((*p&7)!=0)
            		x += *p&7;
            	else
        			x += (*p>>3)&0x1F;
            	p++;
      		}
        	if(x>width) {
        		y = 9999;
        		break;
        	}
        }
    	if(y==height)
    		return sv_VT_AMIGA10;
    }



    return -1;
}
//---------------------------------------------------------------------------
S16 CheckScript(U8 *buf, U16 resLen)
{
	U16 offs,segType;
    BOOL SCRIPT_OK;
   	offs = 0;
    SCRIPT_OK = TRUE;
    while(offs<resLen) {
    	segType = ssBGetW(buf+offs);
        if(segType == sgRETURN) {
        	offs += 2;
        	break;
		}
		if(segType>=TOTAL_SEGMENTS) {
        	SCRIPT_OK = FALSE;
            break;
        }
        offs += ssBGetW(buf+offs+2);
    }
    if(offs==resLen&&SCRIPT_OK) {
    	Game.version = &versions[svSCI_00_LATE];
		return sv_ST_SCI0b;
    }
   	offs = 2;
    SCRIPT_OK = TRUE;
    while(offs<resLen) {
    	segType = ssBGetW(buf+offs);
        if(segType == sgRETURN) {
        	offs += 2;
        	break;
		}
		if(segType>=TOTAL_SEGMENTS) {
        	SCRIPT_OK = FALSE;
            break;
        }
        offs += ssBGetW(buf+offs+2);
    }
    if(offs==resLen&&SCRIPT_OK) {
    	Game.version = &versions[svSCI_00_EARLY];
		return sv_ST_SCI0a;
    }
    return 0;
}
//---------------------------------------------------------------------------
BOOL VerifyVocab900(U8 *buf, U16 resLen)
{
	U16 offs,i;
    if(resLen<0x1FE) {
    	return FALSE;
    }
    offs = 0x1FE;
    while(offs<resLen) {
		i = buf[offs++];
        do {
        	if(offs>resLen)  {
    			return FALSE;
    		}
        } while((U8)buf[offs++]);
		offs += 3;
    }
    return TRUE;
}
//---------------------------------------------------------------------------
BOOL VerifyVocab999_1(U8 *buf, U16 resLen)
{
	U16 offs=0;
    while(offs<resLen) {
        do {
        	if(offs>=resLen)  {
    			return FALSE;
    		}
        } while(buf[offs++]);
    }
    return TRUE;
}
//---------------------------------------------------------------------------
S16 CheckSCI0()
{
	U8 *buf;
    U16 resLen,s;
    RESINFO *resInfo;
	/* Check if there is a vocab.000 and it is valid
     * Check if the vocab.999 is valid SCI0
     * Check if the script has the extra two bytes
     */
	// check view for validity

	resInfo = FindRes(rsVIEW, -1, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(VerifyView(buf, resLen)!=sv_VT_EGA) {
    	ssFree(buf);
        return FALSE;
    }
	ssFree(buf);

	// check vocab.000 for validity

	resInfo = FindRes(rsVOCAB, 0, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(!VerifyVocab000(buf, resLen)) {
    	ssFree(buf);
        return FALSE;
    }
	ssFree(buf);

	// check vocab.999 for validity
	resInfo = FindRes(rsVOCAB, 999, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(!VerifyVocab999_0(buf, resLen)) {
    	ssFree(buf);
        return FALSE;
    }
	ssFree(buf);

	// Check if the script doesn't have the extra two bytes
	resInfo = FindRes(rsSCRIPT, -1, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if((s=CheckScript(buf, resLen))) {
    	ssFree(buf);
        return s;
    }
	ssFree(buf);
    // it would be really safe to say that's it's an invalid game completely,
    // but still continue checking...
	return FALSE;
}
//---------------------------------------------------------------------------

BOOL CheckSCI1EGA()
{
	U8 *buf;
    U16 offs,resLen,segLen,segType;
    RESINFO *resInfo;
    int i,count,vt=0;
    BOOL SCRIPT_OK;
	/* Check if there is a vocab.900 and it is valid
     * Check if the vocab.999 is valid SCI1
     * Check if a script is valid
     */
	// check view for validity

	resInfo = FindRes(rsVIEW, -1, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(VerifyView(buf, resLen)!=sv_VT_EGA) {
    	ssFree(buf);
        return FALSE;
    }
	ssFree(buf);

	// check vocab.900 for validity
	resInfo = FindRes(rsVOCAB, 900, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(!VerifyVocab900(buf, resLen)) {
    	ssFree(buf);
        return FALSE;
    }
	ssFree(buf);

	// check vocab.999 for validity
	resInfo = FindRes(rsVOCAB, 999, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(!VerifyVocab999_0(buf, resLen)) {
    	if(!VerifyVocab999_1(buf, resLen)) {
    		ssFree(buf);
        	return FALSE;
    	}
        vt=1;
    }
	ssFree(buf);

	// Check if the script doesn't have the extra two bytes
	resInfo = FindRes(rsSCRIPT, -1, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(CheckScript(buf, resLen)==sv_ST_SCI0b) {
    	ssFree(buf);
        return TRUE;
    }
	ssFree(buf);
    // yeah, it can't be a valid complete game. Just ask them to select.
	return FALSE;
}

//---------------------------------------------------------------------------

S16 CheckSCI1VGAEGA()
{
	U8 *buf;
    U16 offs,resLen,segLen,segType;
    RESINFO *resInfo;
    int i,count;
    BOOL SCRIPT_OK;
    S16 vt;
	/* Check if there is a vocab.900 and it is valid
     * Check if the vocab.999 is valid SCI1
     * Check if a script is valid
     */
	// check view for validity

	resInfo = FindRes(rsVIEW, -1, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    vt=VerifyView(buf, resLen);
	ssFree(buf);

	// check vocab.999 for validity
	resInfo = FindRes(rsVOCAB, 999, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(!VerifyVocab999_1(buf, resLen)) {
    	ssFree(buf);
        return FALSE;
    }
	ssFree(buf);

	// Check if the script doesn't have the extra two bytes
	resInfo = FindRes(rsSCRIPT, -1, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(CheckScript(buf, resLen)==sv_ST_SCI0b) {
    	ssFree(buf);
        return vt;
    }
	ssFree(buf);
    // yeah, it can't be a valid complete game. Just ask them to select.
	return FALSE;
}

//---------------------------------------------------------------------------

S16 CheckSCI1Amiga()
{
	U8 *buf;
    U16 offs,resLen,segLen,segType;
    RESINFO *resInfo;
    int i,count;
    BOOL SCRIPT_OK;
    S16 vt;
	/* Check if there is a vocab.900 and it is valid
     * Check if the vocab.999 is valid SCI1
     * Check if a script is valid
     */
	// check view for validity

	resInfo = FindRes(rsVIEW, -1, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(VerifyView(buf, resLen)!=sv_VT_AMIGA10) {
    	ssFree(buf);
        return FALSE;
    }
	ssFree(buf);

	// check vocab.999 for validity
	resInfo = FindRes(rsVOCAB, 999, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(!VerifyVocab999_1(buf, resLen)) {
    	ssFree(buf);
        return FALSE;
    }
	ssFree(buf);

	// Check if the script doesn't have the extra two bytes
	resInfo = FindRes(rsSCRIPT, -1, -1, -1);
	if(!resInfo) return FALSE;
	if((buf = ExtractResource(resInfo, erBUFFER, &resLen, NULL))==NULL) return FALSE;
    if(CheckScript(buf, resLen)==sv_ST_SCI0b) {
    	ssFree(buf);
        return TRUE;
    }
	ssFree(buf);
    // yeah, it can't be a valid complete game. Just ask them to select.
	return FALSE;
}

//---------------------------------------------------------------------------
void InitResInfo(BOOL ALLOCATE)
{
	int i;

    ResIdx.totalAllocs = 0;
    ResIdx.lastAlloc = NULL;
    ResIdx.maxPack = 0;

	for(i=0;i<TOTAL_RES_TYPES;i++) {
    	ResIdx.totalRes[i] = 0; 
    	ResIdx.resInfo[i] = NULL;
    }
    if(ALLOCATE) AllocResMem();
}
//---------------------------------------------------------------------------
void DisposeResInfo()
{
	int i;
               
	for(i=0;i<TOTAL_RES_TYPES;i++) {
    	ResIdx.totalRes[i] = 0;
    	ResIdx.resInfo[i] = NULL;
    }

	for(i=ResIdx.totalAllocs-1;i>=0;i--)
    	ssFree(ResIdx.allocBufs[i]);
    ResIdx.maxPack = 0;

    ResIdx.totalAllocs = 0;
    ResIdx.lastAlloc = NULL;
}
//---------------------------------------------------------------------------
void AllocResMem()
{
	if(ResIdx.totalAllocs+1>=rsMAX_ALLOCS) {
    	ssMessage(ssERROR,"Unable to allocate enough memory for the resource map entries! The map must be corrupt as no map would be this large!");
        Application->Terminate();
        return;
    }
    ResIdx.lastAlloc = (RESINFO*)ssAlloc(sizeof(RESINFO)*rsALLOCBUFSZ);
	ResIdx.allocBufs[ResIdx.totalAllocs] = ResIdx.lastAlloc;
    ResIdx.allocPtr = 0;
    ResIdx.totalAllocs++;
}
//---------------------------------------------------------------------------
RESINFO *AddResInfo(RESINFO *prev, U8 type, U8 pack, U16 number, U32 offset)
{                     
	ResIdx.allocPtr++;
	if(!ResIdx.lastAlloc||ResIdx.allocPtr+1>=rsALLOCBUFSZ) {
		AllocResMem();
    }
    ResIdx.lastAlloc++;
    if(ResIdx.maxPack<pack) ResIdx.maxPack=pack;

    ResIdx.lastAlloc->type = type;
    ResIdx.lastAlloc->number = number;
    ResIdx.lastAlloc->pack = pack;
    ResIdx.lastAlloc->offset = offset;

    if(prev!=NULL) prev->next = ResIdx.lastAlloc;
	ResIdx.lastAlloc->next = NULL;
	ResIdx.lastAlloc->prev = prev;
                          
    if(!ResIdx.resInfo[type])
    	ResIdx.resInfo[type] = ResIdx.lastAlloc;

    ResIdx.totalRes[type]++;

    return ResIdx.lastAlloc;
}
//---------------------------------------------------------------------------
void DelResInfo(RESINFO *resInfo)
{
	ResIdx.totalRes[resInfo->type]--;
    if(ResIdx.resInfo[resInfo->type]==resInfo)
    	ResIdx.resInfo[resInfo->type] = resInfo->next;
    if(ResIdx.totalRes[resInfo->type]==0) {
		ResIdx.resInfo[resInfo->type] = NULL;
    } else {
		if(resInfo->prev) resInfo->prev->next = resInfo->next;
    	if(resInfo->next) resInfo->next->prev = resInfo->prev;
    }
    resInfo->type = 0xFF;
}
//---------------------------------------------------------------------------
void AddResInfoStruct(RESINFO *resInfo)
{
	RESINFO *ri = ResIdx.resInfo[resInfo->type];
    if(!ResIdx.totalRes[resInfo->type]) {
		ResIdx.resInfo[resInfo->type] = resInfo;
        resInfo->next = NULL;
        resInfo->prev = NULL;
    } else {
		do {
        	ri = ri->next;
        } while(ri->next!=NULL);
        ri->next = resInfo;
		resInfo->prev = ri;
    	resInfo->next = NULL;
    }
	ResIdx.totalRes[resInfo->type]++;
}                                       
//---------------------------------------------------------------------------
RESINFO *FindLastResInfo(int type)
{
	RESINFO *ri = ResIdx.resInfo[type];
    while(ri) {
    	if(ri->next==NULL) return ri;
		ri = ri->next;
    }
    return ri;
}
//---------------------------------------------------------------------------
// opens the map, seeks to the location of the resource entry and returns the file handle
FILE *FindMapEntry(RESINFO *resInfo, U32 *ml)
{
	FILE *fMap;  
    U32 ulMapLen;
    U16 ident;
    U32 addr;

    // load the map
    if((fMap=ssOpenFile(ssFIO_GAME|ssFIO_MESSAGE,"resource.map","rb+"))==0) return NULL;
    ulMapLen = ssFileLen(fMap);

    // make sure the map is valid
    if(ulMapLen < rmMIN_SIZE) {
		ssMessage(ssERROR,"Invalid resource.map file! File too small!");
        ssCloseFile(fMap);
        return NULL;
    }

    for(U32 i=0;i<ulMapLen;i+=6) {
    	ident = ssFGetW(fMap);
        if(rmGET_NUMBER(ident)==resInfo->number&&rmGET_TYPE(ident)==resInfo->type) {
        	addr = ssFGetL(fMap);
           	if((U8)rmGET_PACKAGE(addr)==resInfo->pack&&rmGET_OFFSET(addr)==resInfo->offset) {
            	ssFSeek(fMap,-6,SEEK_CUR);
                if(ml) *ml = ulMapLen;
                return fMap;
            }
        } else ssFSeek(fMap,4,SEEK_CUR);
    }
    ssCloseFile(fMap);
    ssMessage(ssERROR,"Could not locate resource %s.%03d in the resource.map!",resTypes[resInfo->type].name,resInfo->number);
    return NULL;
}
//---------------------------------------------------------------------------
BOOL DelMapEntry(RESINFO *resInfo)
{
    U16 copyLen;
    U8 *buf;
	FILE *fMap;
    U32 ulMapLen;
    U16 offset;

    // load the map
    if((fMap=FindMapEntry(resInfo,&ulMapLen))==NULL) return FALSE;

    offset = (U16)ftell(fMap);
    fseek(fMap,6,SEEK_CUR);
    copyLen = (U16)((U16)ulMapLen-offset-6);
    buf = (U8*)ssAlloc(copyLen);
    ssFRead(buf,copyLen,fMap);
    ssFSeek(fMap,offset,SEEK_SET);
    ssFWrite(buf,copyLen,fMap);
    ssFree(buf);
    ssCloseFile(fMap);
    DelResInfo(resInfo);

    return TRUE;
}
//---------------------------------------------------------------------------
RESINFO *AddResource(U8 *buf, U16 len, U8 type, S16 number, U8 pack)
{        
	FILE *fMap,*fPack;
    U32 ulMapLen;
    U16 ident;
    U32 addr;
    U32 packOffset;
    U8 *mBuf;
                

    if(Game.version->decType!=svDECOMP_0) {
    	ssMessage(ssNOTICE,"Sorry! Unimplemented!");
        return NULL;
    }

    // load the map
    if((fMap=ssOpenFile(ssFIO_GAME|ssFIO_MESSAGE,"resource.map","rb+"))==0) return NULL;
    ulMapLen = ssFileLen(fMap);
    // make sure the map is valid
    if(ulMapLen < rmMIN_SIZE) {
		ssMessage(ssERROR,"Invalid resource.map file! File too small!");
        ssCloseFile(fMap);
        return FALSE;
    }

    // Ask the user for which package to store the resource and
    // what number to use.
    DlgAddResource = new TDlgAddResource(WndExplorer);
    DlgAddResource->ResourceType = AnsiString(resTypes[type].name);
    DlgAddResource->NumberEdit->Text  = IntToStr(number);
    DlgAddResource->PackageEdit->Text = IntToStr(pack);
    DlgAddResource->NumberEditChange(DlgAddResource->NumberEdit);
    DlgAddResource->ShowModal();
	delete DlgAddResource;

    // they pressed cancel, no res will be added
    if(WndExplorer->dlgCANCLOSE) {
        ssCloseFile(fMap);
        return FALSE;
    }

	number = (S16)WndExplorer->adrsNumber;
	pack = (U8)WndExplorer->adrsPackage;

    // Load the pack
    sprintf(szTemp,"resource.%03d",pack);
    if((fPack=ssOpenFile(ssFIO_GAME|ssFIO_MESSAGE,szTemp,"rb+"))==0) return NULL;
//    ulPackLen = ssFileLen(fPack);

    // move all the current entries forward 6 bytes so that the new entry is at the beginning!
	mBuf = (U8*)ssAlloc(ulMapLen);
    ssFRead(mBuf,ulMapLen,fMap);
    ssFSeek(fMap,6,SEEK_SET);
    ssFWrite(mBuf,ulMapLen,fMap);
    ssFree(mBuf);
    // Now write the new entry!

    // First to the package!
	ident = (U16)rmSET_TYPE(type)|(U16)rmSET_NUMBER(number);
    ssFSeek(fPack,0,SEEK_END);
    packOffset = ftell(fPack);
    ssFPutW(ident,fPack);	 // identifier (same as map)
    ssFPutW(len+4,fPack);  	 // actual length
    ssFPutW(len,fPack);  // encoded length
    ssFPutW(0,fPack);		 // encoding method (0-none)
    ssFWrite(buf,len,fPack);
    ssCloseFile(fPack);
    ssFSeek(fMap,0,SEEK_SET);

	addr = rmSET_PACKAGE(pack)|rmSET_OFFSET(packOffset);
    ssFPutW(ident,fMap);
    ssFPutL(addr,fMap);

    ssCloseFile(fMap);  

	RESINFO *ri = AddResInfo(FindLastResInfo(type), type, pack, number, packOffset);
    ri->size = len;
    ri->encSize = len;
    ri->encType = 0;

    return ri;
}
//---------------------------------------------------------------------------
/* The following are used in both decryption algorithms: */
#define MAXBIT 0x2000
unsigned int whichbit = 0;
unsigned char bits[(MAXBIT>>3)+3];

/*****************  Decryption Method 1  *******************************/

U16 getbits1(int numbits, FILE *handle) /* handles bitstrings length 9-12 */
{
  int place;
  unsigned long bitstring;
  if (whichbit >= MAXBIT) {
    whichbit -= MAXBIT;
    ssFRead(bits, (MAXBIT >> 3)+3, handle);
    ssFSeek(handle, -3L, SEEK_CUR);
  }
  place = whichbit >> 3;
  bitstring = bits[place] | (long)((bits[place+1])<<8)
	      | (long)((bits[place+2])<<16);
  bitstring >>= (whichbit & 7);
  bitstring &= 0xffffffffUL >> (32-numbits);
  whichbit += numbits;
  return bitstring;
}

#define STACKSIZE 16384
char stack[STACKSIZE];
int stackptr;
void push(char c) {
  stack[stackptr++] = c;
  if (stackptr >= STACKSIZE) {
    ssMessage(ssERROR,"Stack overflow!");
    Application->Terminate();
  }
}
char *popall(char *dest) {
  while (stackptr-- > 0) *(dest++) = stack[stackptr];
  stackptr++;
  return dest;
}

int Decrypt_LZW(FILE *handle, char *data, U16 destLen)
{                
	U16 field, linkindex = 0x102, nextindex = 0, newindex = 0,
	maxindex = 0x200, width = 9;
	U8 *links, lastbyte=0, linkbyte=0; 
	char *destEnd = (char*)(data+destLen);
	
	links = (U8*)ssAlloc(12300);
	whichbit = MAXBIT;
	stackptr = 0;
	while ((field = getbits1(width, handle)) != 0x101) { /* exit on 0x101 */
		if (field == 0x100) { /* start over from beginning of table */
			linkindex = 0x102;
			width = 9;
			maxindex = 0x200;
			nextindex = field = getbits1(width, handle);
			lastbyte = linkbyte = (U8)(field & 0xff);
			if(data>=destEnd) {
				ssFree(links);
				return -1;
            }
			*(data++) = (char)lastbyte;
		}
		else {
			newindex = field;
			if (field >= linkindex) { /* if it's a forward reference, */
				push(lastbyte);         /* repeat the last thing */
				field = nextindex;
			}
			while (field > 0xff) { /* trace links back */
				push(links[field*3+2]);
				field = (int)(links[field*3]) | (int)((links[field*3+1]) << 8);
			}
			lastbyte = linkbyte = (U8)field;
			push(lastbyte);
			data = popall(data);
			links[linkindex*3+2] = linkbyte;
			links[linkindex*3+1] = (U8)(nextindex >> 8);
			links[linkindex*3+0] = (U8)(nextindex & 0xff);
			linkindex++;
			nextindex = newindex;
			if (linkindex >= maxindex && width != 12) {
				width++;
				maxindex <<= 1;
			}
		}
	}
	ssFree(links);
	//if(data!=destEnd)
	//	return -1;
	return 1;
}

/*****************  Decryption Method 2  *******************************/
/*This is basically byte-token huffman coding, except that a prefix of
  1 signals a literal byte. In fact, most bytes are literal; only extremely
  common ones are put in the huffman tree. */

char getbits2(int numbits, FILE *handle) /* handles bitstrings length 1-8 */
{
  int bitstring, place;
  if (whichbit >= MAXBIT) {
    whichbit -= MAXBIT;
    ssFRead(bits, (MAXBIT >> 3)+3, handle);
    ssFSeek(handle, -3L, SEEK_CUR);
  }
  place = whichbit >> 3;
  bitstring = bits[place] << 8;
  bitstring |= bits[place+1] & 0x00ff;
  bitstring >>= 16-numbits-(whichbit & 7);
  bitstring &= 0xffffu >> (16-numbits);
  whichbit += numbits;
  return (char)bitstring;
}

int getc2(U8 *node, FILE *handle)
{
  int next;
  while (node[1] != 0) {
    if (getbits2(1, handle)) {
      next = node[1] & 0xf; /* low 4 bits */
      if (next == 0) return (getbits2(8, handle) | 0x100);
    }
    else next = node[1] >> 4; /* high 4 bits */
    node += next*2;
  }
  return (int)*node;
}

int Decrypt_HUFFMAN(FILE *handle, char *data, U16 destLen)
{
  U8 numnodes, terminator;
  char *nodes;
  char *destEnd = (char*)(data+destLen);
  int c;
  numnodes = (U8)ssFGetB(handle);
  terminator = (U8)ssFGetB(handle);
  nodes = (char*)ssAlloc(2*numnodes); 
  ssFRead(nodes, 2*numnodes, handle);
  whichbit = MAXBIT;
  while ((int)(c = getc2((U8*)nodes, handle)) != (int)(0x0100 | (int)terminator)) {
    if(data>=destEnd) {
    	ssFree(nodes);
    	return -1;
    }
    *data = (char)c;
    data++;
  }
  ssFree(nodes);
  if(data!=destEnd)
  	return -1;
  return 1;
}



/* Our first decompression method is a subtitutional coding. I don't know
   name, but it's the one where tokens with high bit 0 are literal,
   and ones with high bit 1 are indexes to a pair of tokens already
   seen. There are some later decryption types that use it, making
   it necessary to leave it and resume where you left off later.
   This made things a little trickier, but I use the global 
   'decryptstart' to indicate where to begin again. */


struct tokenlist {
  unsigned char data;
  int next;
} tokens[0x1004];

char stak[0x1014], lastchar;
int stakptr;
unsigned long numbits, bitstring, lastbits, decryptstart;
int curtoken, endtoken;

unsigned long getbits(int numbits, FILE *handle)
/* gets the next numbits bits from file, low bit first */
{
  int place; /* indicates location within byte */
  unsigned long bitstring;
  if (whichbit >= MAXBIT) {
    whichbit -= MAXBIT;
    ssFRead(bits, (MAXBIT >> 3)+3, handle);
    ssFSeek(handle, -3L, SEEK_CUR);
  }
  place = whichbit >> 3;
  bitstring = bits[place+2] | (long)((bits[place+1])<<8)
	      | (long)((bits[place])<<16);
  bitstring >>= 24-(whichbit & 7)-numbits;
  bitstring &= 0xffffffffUL >> (32-numbits);
  /* Okay, so this could be made faster with a table lookup.
     It doesn't matter. It's fast enough as it is. */
  whichbit += numbits;
  return bitstring;
}

int Decrypt_COMP3(FILE *f, char  *buffer, U16 length);
int decrypt(U16 length, char  *buffer, FILE *f);
int Decrypt_SCI1ENC3(FILE *f, unsigned char *data, U16 encLen);
int Decrypt_SCI1ENC4(FILE *f, unsigned char *data, U16 encLen);

void decryptinit()
{
  lastchar = lastbits = bitstring = whichbit = stakptr = 0;
  numbits = 9;
  whichbit = MAXBIT;
  curtoken = 0x102;
  endtoken = 0x1ff;
  decryptstart = 0;
}

int Decrypt_COMP3(FILE *f, char  *buffer, U16 length)
{
  decryptinit();

  return decrypt(length, buffer, f);
}

int token;
int decrypt(U16 length, char  *buffer, FILE *f)
{
	while(length != 0){
		switch (decryptstart) {
			case 0:
			case 1:
				bitstring = getbits(numbits, f);
				if (bitstring == 0x101) { /* found end-of-data signal */
					decryptstart = 4;
					return 1;
				}
				if (decryptstart == 0) { /* first char */
					decryptstart = 1;
					lastbits = bitstring;
					*(buffer++) = lastchar = (bitstring & 0xff);
					if (--length != 0) continue;
					return 1;
				}
				if (bitstring == 0x100) { /* start-over signal */
					numbits = 9;
					endtoken = 0x1ff;
					curtoken = 0x102;
					decryptstart = 0;
					continue;
				}
				token = bitstring;
				if (token >= curtoken) { /* index past current point */
					token = lastbits;
					stak[stakptr++] = lastchar;
				}
				while ((token > 0xff)&&(token < 0x1004)) { /* follow links back in data */
					stak[stakptr++] = tokens[token].data;
					token = tokens[token].next;
				}
				lastchar = stak[stakptr++] = token & 0xff;
			case 2:
				while (stakptr > 0) { /* put stack in buffer */
					*(buffer++) = stak[--stakptr];
					length--;
					if (length == 0) {
						decryptstart = 2;
						return 1;
					}
				}
				decryptstart = 1;
				if (curtoken <= endtoken) { /* put token into record */
					
					tokens[curtoken].data = lastchar;
					tokens[curtoken].next = lastbits;
					curtoken++;
					if (curtoken == endtoken && numbits != 12) {
						numbits++;
						endtoken *= 2;
						endtoken++;
					}
				}
				lastbits = bitstring;
				continue; /* When are "break" and "continue" synonymous? */
			case 4:
				return 1;
		}
	}
    return 1;
}

unsigned char buf[0x600];

int Decrypt_SCI1ENC3(FILE *f, unsigned char *data, U16 encLen)
/* This calls decrypt, but rearranges the resulting data somehow
   that is specific to the data type it's reading. */
{
  unsigned char buf14[0x14];
  unsigned short buf200[0x200];
  unsigned char b=0, *place, *place14 = buf14, *charto, *chartoend;
  unsigned short *placeto;
  unsigned short k=0, L16=0, L18=0, L1a=0, L1c=0, L1e=0;
  unsigned short *L2, *L8 = buf200;
  unsigned char *L14;
  decryptinit();
  decrypt(2, (char *)&k, f);
  place = data+encLen-k;
  decrypt(k, place, f);
  decrypt(*(short *)(place+8)*2, (char *)buf200, f);
  placeto = (unsigned short *)data;
  L18 = *(place++);
  *(placeto++) = 0x8000 | L18;
  L16 = *(place++);
  *(placeto++) = ssBGetW(place);
  place+=2;
  *(placeto++) = ssBGetW(place);
  place+=2;
  *(placeto++) = ssBGetW(place);
  place += 4;
  L2 = placeto;
  placeto += L18;
  L14 = place+L16;
  L1e = ssBGetW((data+2));
  L1a = L18;
  while (L16-- != 0) *(place14++) = *(place++);
  place14 = buf14;
  while (L1a-- != 0) {    /* decode the group indices */
    if (L1e & 1) {
      *L2 = *(L2-1);
      L2++;
    }
    else {
      *(L2++) = (char *)placeto - (char *)data;
      *(placeto++) = L1c = *(place14++);
      *(placeto++) = 0;
      charto = (unsigned char *)(placeto+L1c);
      while (L1c-- != 0) {
	*(placeto++) = charto-data;
    memcpy(charto,L14,14);
    charto+=7;
    L14 += 7;

	*(charto++) = 0;
	charto += *(L8++);
      }
      placeto = (unsigned short *)charto;
    }
    L1e >>= 1;
  }
  decrypt(0x600, buf, f);
  k = 0x600;
  place = buf;
  placeto = (unsigned short *)data;
  L1e = *(placeto+1);
  L2 = placeto+4;
  L8 = buf200;
  L1a = L18;
  while (L1a-- != 0) {
    if (L1e & 1) L2++;
    else {
      placeto = (unsigned short *)(data+*(L2++));
      L1c = *placeto;
      placeto += 2;
      while (L1c-- != 0) {
	charto = data+*(placeto++)+8;
	chartoend = charto+*(L8++);
	while (charto < chartoend) {
	  b = *(charto++) = *(place++);
	  if (--k == 0) {
	    decrypt(0x600, buf, f);
	    k = 0x600;
	    place = buf;
	  }
	  if (b >= 0xc0) continue;
	  else if (b >= 0x80) charto++;
	  else charto += b;
	}
      }
    }
    L1e >>= 1;
  }
  placeto = (unsigned short *)data;
  L1e = *(placeto+1);
  L2 = placeto+4;
  L8 = buf200;
  L1a = L18;
  while (L1a-- != 0) {
    if (L1e & 1) L2++;
    else {
      placeto = (unsigned short *)(data+*(L2++));
      L1c = *placeto;
      placeto += 2;
      while (L1c-- != 0) {
	charto = data+*(placeto++)+8;
	chartoend = charto+*(L8++);
	while (charto < chartoend) {
	  b = *(charto++);
	  if (b >= 0xc0) continue;
	  else if (b >= 0x80) {
	    *(charto++) = *(place++);
	    if (--k == 0) {
	      decrypt(0x600, buf, f);
	      k = 0x600;
	      place = buf;
	    }
	  }
	  else while (b-- > 0) {
	    *(charto++) = *(place++);
	    if (--k == 0) {
	      decrypt(0x600, buf, f);
	      k = 0x600;
	      place = buf;
	    }
	  }
	}
      }
    }
  L1e >>= 1;
  }
  if (*(short *)(data+6)) {
    *(charto++) = 'P';
    *(charto++) = 'A';
    *(charto++) = 'L';
    for (k=0; k<0x100; k++) *(charto++) = k;
  }
  return 1;
}

int Decrypt_SCI1ENC4(FILE *f, unsigned char *data, U16 encLen)
{
  unsigned short place=0, bufplace=0, after=0, pal1start=0, pal1end=0, pal2end=0, L10=0, L12=0;
  decryptinit();
  decrypt(6, data, f);
  after = ssBGetW(data);
  L10 = ssBGetW(data+4);
  place = pal1start = ssBGetW(data+2);
  data[place++] = 0xfe;
  data[place++] = 0x01;
  data[place++] = 0x00;
  data[place++] = 0x00;
  data[place++] = 0x00;
  data[place++] = (after+8)&0xff;
  data[place++] = (after+8)>>8;
  decrypt(7, data+place, f);
  place += 7;
  data[place++] = 0;
  pal1end = place;
  data[0] = 0xfe;
  data[1] = 0x02;
  for (place=2; place < 0x102; place++) data[place] = place-2;
  data[place++]=0;
  data[place++]=0;
  data[place++]=0;
  data[place++]=0;
  decrypt(0x400, data+place, f);
  place += 0x400;
  pal2end = place;
  if (pal2end != pal1start) decrypt(pal1start - pal2end, data+place, f);
  place = pal1end+after;
  if (place != encLen) decrypt(encLen-place, data+place, f);
  place = L12 = pal1end+after-L10;
  decrypt(L10, data+place, f);
  decrypt(0x600, buf, f);
  bufplace = 0;
  place = pal1end;
  while (place < pal1end+after) {
    unsigned short k;
    k = data[place++] = buf[bufplace++];
    if (bufplace == 0x600) {
      decrypt(0x600, buf, f);
      bufplace = 0;
    }
    if (k>0xc0) continue;
    else if (k>0x80) data[place++]=data[L12++];
    else while (k-- > 0) data[place++]=data[L12++];
  }
  return 1;
}




// mode -
//        erFILE/erBUFFER/erFILENAME
//        erSHOW_MESSAGES
// 	if file mode, it extracts it to a file (if erFILENAME set, to a specified
//	file, otherwise, it asks the user). If buffer mode, it allocates a
//	buffer and extracts it there, returning a pointer
//
char dirPath[1024];
U8 *ExtractResource(RESINFO *resInfo, U8 mode, U16 *len, char *fileName)
{
	FILE *fPack,*fOut;
    U8 type;
    U16 num,ident;
    U8 *decBuf,*encBuf;
    AnsiString s;

    // Load the pack
    if(Game.version->decType==svDECOMP_4)
    	sprintf(dirPath,"ressci.%03d",resInfo->pack);
	else
    	sprintf(dirPath,"resource.%03d",resInfo->pack);
    if((fPack=ssOpenFile(ssFIO_GAME|ssFIO_MESSAGE,dirPath,"rb"))==0) return FALSE;

    if(mode&erFILENAME) {
        strcpy(dirPath,fileName);
    } else if(mode & erFILE) {
     	WndExplorer->SaveDialog->Filter = FilterAllRes;
        WndExplorer->SaveDialog->FileName = s.sprintf("%s.%03d", resTypes[resInfo->type].name, resInfo->number);
        if(!WndExplorer->SaveDialog->Execute()) {
        	ssCloseFile(fPack);
            return NULL;
        }
        //ExtractedFileName.sprintf("%s\\%s.%03d", DirDialog->FullPath, TypeNames[Type], ResourceNumber);
        strcpy(dirPath,WndExplorer->SaveDialog->FileName.c_str());
    }

//    ulPackLen = ssFileLen(fPack);

    ssFSeek(fPack,resInfo->offset,SEEK_SET);
    if(Game.version->mapType==sv_MT_0||Game.version->mapType==sv_MT_1) {
    	ident = ssFGetW(fPack);
    	type = rmGET_TYPE(ident);
        num = rmGET_NUMBER(ident);
    } else if(Game.version->mapType==sv_MT_2) {
    	type = ssFGetB(fPack)&0x7F;
        num = ssFGetW(fPack);
    } else { // sv_MT_3
    	type = ssFGetB(fPack)&0x7F;
        num = ssFGetW(fPack);
    }
    if(type!=resInfo->type||num!=resInfo->number) {
    	if(mode&erSHOW_MESSAGES)
    		ssMessage(ssERROR,"Resource package/map file identifier mismatch! "MSG_DEFRESERROR);
        else
        	if(WndExplorer)
            	WndExplorer->PreviewPC->ActivePage = WndExplorer->ErrPage;
   	 	DisposeResInfo();
        return FALSE;
    }

    if(Game.version->decType==svDECOMP_5) {
    	resInfo->encSize = ssFGetW(fPack);
    	resInfo->size = ssFGetW(fPack);
    	if(!resInfo->size) {
   			ssCloseFile(fPack);
    		return NULL;
    	}
    	resInfo->encType = ssFGetW(fPack);
    	decBuf = (U8*)ssAlloc(resInfo->size);
    	extractStatus = -1;
    	if(resInfo->encSize==resInfo->size) {
        	ssFRead(decBuf,resInfo->size,fPack);
        } else {
    		encBuf = (U8*)ssAlloc(resInfo->encSize);
        	ssFRead(encBuf,resInfo->encSize,fPack);
			dcl_unpack(encBuf,decBuf);
            ssFree(encBuf);
        }
		ssCloseFile(fPack);
    	extractStatus = 1;
    } else if(Game.version->decType==svDECOMP_3) {
    	resInfo->encSize = ssFGetW(fPack);
    	resInfo->size = ssFGetW(fPack);
    	if(!resInfo->size) {
   			ssCloseFile(fPack);
    		return NULL;
    	}
    	resInfo->encType = ssFGetW(fPack);
    	decBuf = (U8*)ssAlloc(resInfo->size);
    	extractStatus = -1;
    	if(resInfo->encSize==resInfo->size) {
        	ssFRead(decBuf,resInfo->size,fPack);
        } else {
    		encBuf = (U8*)ssAlloc(resInfo->encSize);
        	ssFRead(encBuf,resInfo->encSize,fPack);
			dcl_unpack(encBuf,decBuf);
            ssFree(encBuf);
        }
		ssCloseFile(fPack);
    	extractStatus = 1;
    } else if(Game.version->decType==svDECOMP_4) {
    	resInfo->encSize = ssFGetL(fPack);
    	resInfo->size = ssFGetL(fPack);
    	if(!resInfo->size) {
   			ssCloseFile(fPack);
    		return NULL;
    	}
    	resInfo->encType = ssFGetW(fPack);
    	decBuf = (U8*)ssAlloc(resInfo->size);
    	extractStatus = -1;
    	if(resInfo->encSize==resInfo->size) {
        	ssFRead(decBuf,resInfo->size,fPack);
        } else {
    		encBuf = (U8*)ssAlloc(resInfo->encSize);
        	ssFRead(encBuf,resInfo->encSize,fPack);
			lzs_unpack(encBuf,decBuf);
            ssFree(encBuf);
        }
		ssCloseFile(fPack);
    	extractStatus = 1;
    } else {
    	resInfo->encSize = ssFGetW(fPack);
    	resInfo->size = ssFGetW(fPack);
    	if(!resInfo->size) {
   			ssCloseFile(fPack);
    		return NULL;
    	}
    	resInfo->encType = ssFGetW(fPack);
    	decBuf = (U8*)ssAlloc(resInfo->size);
    	extractStatus = -1;
    	resInfo->encSize-=4;
	    switch(resInfo->encType) {
			case 0:
	    		ssFRead(decBuf,resInfo->size,fPack);
	            extractStatus = 1;
	            break;
	        case 1:
	        	if((Game.version->decType==svDECOMP_0))
	        		extractStatus = Decrypt_LZW(fPack, (char*)decBuf, resInfo->size);
	            else if((Game.version->decType==svDECOMP_1) || (Game.version->decType==svDECOMP_2))
	        		extractStatus = Decrypt_HUFFMAN(fPack, (char*)decBuf, resInfo->size);
	            break;
	        case 2:
	        	if(Game.version->decType==svDECOMP_0)
	            	extractStatus = Decrypt_HUFFMAN(fPack, (char*)decBuf, resInfo->size);
	            else if((Game.version->decType==svDECOMP_1)||(Game.version->decType==svDECOMP_2))
	            	extractStatus = Decrypt_COMP3(fPack, (char*)decBuf, resInfo->size);
	            break;
	        case 3:
	            if(Game.version->decType==svDECOMP_1)
	        		extractStatus = Decrypt_HUFFMAN(fPack, (char*)decBuf, resInfo->size);
	            else if((Game.version->decType==svDECOMP_2))
	            	extractStatus = Decrypt_SCI1ENC3(fPack, (char*)decBuf, resInfo->size);
	            break;
	        case 4:
	            if((Game.version->decType==svDECOMP_1) || (Game.version->decType==svDECOMP_2))
	            	extractStatus = Decrypt_SCI1ENC4(fPack, (char*)decBuf, resInfo->size);
	            break;
	        case 8:
	            if(Game.version->decType==svDECOMP_5)
	            	extractStatus = Decrypt_COMP3(fPack, (char*)decBuf, resInfo->size);
	            break;
	        default:
	    		if(mode&erSHOW_MESSAGES)
	            	ssMessage(ssERROR,"Unknown encoding method! "MSG_DEFRESERROR);
	            else
	            	WndExplorer->PreviewPC->ActivePage = WndExplorer->UnkComPage;
				ssFree(decBuf);
	    		ssCloseFile(fPack);
	            return NULL;
	    }
   		ssCloseFile(fPack);
    	if(extractStatus==-1) {
     		ssFree(decBuf);
        	return NULL;
    	};
    }


    if(mode&erFILE||mode&erFILENAME) {
    	if((fOut=ssOpenFile(ssFIO_ROOT|ssFIO_MESSAGE,dirPath,"wb"))==0) return NULL;
        ssFPutW(MAKE_RESFILE_HEADER(resInfo->type),fOut);
        ssFWrite(decBuf,resInfo->size,fOut);
        ssCloseFile(fOut);
    	ssFree(decBuf);
        decBuf = (U8*) 1;
    } else {
     	if(len) *len = resInfo->size;
    }

    return decBuf;
}
//---------------------------------------------------------------------------
BOOL ExtractAllRes(char *path, int type)
{
	BOOL fERROR = FALSE;
    RESINFO *resInfo;
	resInfo = ResIdx.resInfo[type];
    while(resInfo) {
    	sprintf(szTemp,"%s\\%s.%03d",path,resTypes[type].name,resInfo->number);
		if(!ExtractResource(resInfo, erFILENAME, NULL, szTemp))
			fERROR = TRUE;
    	resInfo = resInfo->next;
    }
    return fERROR;
}
//---------------------------------------------------------------------------
RESINFO *FindRes(int type, int number, int pack, long offset)
{
	RESINFO *ri;
    ri = ResIdx.resInfo[type];
    while(ri) {
       	if(ri->number == number||number==-1) {
        	if(pack==ri->pack||pack==-1)
        		if(offset==(long)ri->offset||offset==-1)
         			return ri;
        }
    	ri = ri->next;
    }

    return ri;
}
//---------------------------------------------------------------------------
RESINFO *FindEncRes(int encType)
{
	RESINFO *ri;
    int type;
    for(type=0;type<TOTAL_RES_TYPES;type++) {
    	ri = ResIdx.resInfo[type];
    	while(ri) {
       		if(ri->encType == encType)
        		return ri;
    		ri = ri->next;
    	}
    }

    return ri;
}
//---------------------------------------------------------------------------
RESINFO *FindFirstRes()
{
	RESINFO *ri;
    int type;
    for(type=0;type<TOTAL_RES_TYPES;type++)
    	if(ResIdx.resInfo[type])
        	return(ResIdx.resInfo[type]);

    return ri;
}
//---------------------------------------------------------------------------
int CheckSCIFileHeader(U8 *rBuf)
{
	if(((rBuf[0]&0xF0)!=0x80)||(rBuf[1]!=0x00)) return -1;
    return rBuf[0]&0x0F;
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
AnsiString AnsiStringFmtRes(int type, int number)
{
 	AnsiString s;
    s.sprintf("%s.%03d",resTypes[type].name,number);
    return s;
}
//---------------------------------------------------------------------------

void SetResIDfo(RESIDFO *resIDfo, RESINFO *resInfo)
{
    resIDfo->type = resInfo->type;	// the currently open resource
    resIDfo->number = resInfo->number;
    resIDfo->pack = resInfo->pack;
    resIDfo->size = resInfo->size;
}

//---------------------------------------------------------------------------
int GetResTypeIndex(char* s)
{
	for(int i=0;i<TOTAL_RES_TYPES2;i++) {
    	if(strcmp(s,resTypes[i].name)==0)
        	return i;
    }
    return -1;
}
//---------------------------------------------------------------------------


