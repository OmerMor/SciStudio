//---------------------------------------------------------------------------
#include "scihdr.h"
#include <alloc.h>
//---------------------------------------------------------------------------
// Allocate memory--always use instead of malloc
void *ssAlloc(U32 size)
{
	void *p;
    if((p=malloc(size))==0) {
    	ssMessage(ssERROR,"Unable to allocate memory for SCI Studio!");
        Application->Terminate();
    }
    return p;
}
//---------------------------------------------------------------------------
// Allocate & clear memory--always use instead of calloc
void *ssCalloc(U32 size)
{
	void *p;
    if((p=calloc(1,size))==0) {
    	ssMessage(ssERROR,"Unable to allocate memory for SCI Studio!");
        Application->Terminate();
    }
    return p;
}
//---------------------------------------------------------------------------
// Free allocated memory--always use instead of free()
void ssFreeX(void **p)
{
	if(*p)
    	free(*p);
    *p=NULL;
}
//---------------------------------------------------------------------------

