// phyre_stubs.cpp - Full reconstruction stubs
#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <windows.h>

unsigned int unk_C91C18[38]={0};
unsigned int MEMORY_C90B00[16]={0};
unsigned int MEMORY_C93DD4=0;
unsigned int unk_C90758=0;
unsigned int dword_C94EE4=0;
unsigned int dword_C904D4=0;
unsigned int unk_C93E10[4]={0};
unsigned int unk_C93E20[4]={0};
unsigned int unk_C93E30[4]={0};
unsigned int *unk_C94F00=0;
unsigned int *unk_C9628C=0;

int nullsub_virtual() { return 0; }
void *vtable_PhyrePClassDescriptor[16];
void *vtable_PhyrePClassDescriptorDynamic[16];

extern "C" {
void *Engine_AlignedAllocSimple(int s){return malloc(s);}
void Engine_AlignedFree(void*p){if(p)free(((void**)p)[-1]);}
}

int HeapArena_GlobalBootInit(int h){return 1;}
float*Phyre_PApplication_Constructor(float*a){return a;}
int*GetGlobalSystemContext(){static int c[256];return c;}
int Phyre_Property_SetValue231(float*a,int v){return 1;}
int Phyre_Application_SetWindowTitle(int*a,const char*t){return 0;}
int g_renderState=0;
void FFX_Heap_Free(void*p){free(p);}
void FFX_SmallArray_DtorLoop_B(void*a,int b){}
int FFX_Encounter_TestFrustumCull(int a,int b){return 0;}
void FFX_BtlUI_GetOverlaySub_structural(int a,char b){}
