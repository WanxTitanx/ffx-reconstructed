#include "../include/ffx_structs.h"
#include "../include/ffx_vtables.h"

typedef struct PhyrePNamespace {
    int *vfptr; int f4; int f8; int fC; int f10; int f14;
    int f18; int f1C; int f20; int f24; int f28; int f2C;
    int f30; int f34; int f38; int f3C; int f40; int f44;
    int f48; int f4C; int f50; int f54; int f58; int f5C;
    int f60; int f64; int f68; int f6C; int f70; int f74;
    int f78; int f7C;
} PhyrePNamespace;

void Phyre_PClassDescriptor_Constructor(PhyrePClassDescriptor*s,int a,int b,int c,int d){}
int* Phyre_PClassDescriptor_ctor(PhyrePClassDescriptor*s,int a,int b,int c,int d,int e,int f){return 0;}
void Phyre_PClassDescriptor_Destructor(PhyrePClassDescriptor*s){}
int Phyre_PClassDescriptor_TraverseWithFlag(PhyrePClassDescriptor*s,int f){return 0;}
int Phyre_PClassDescriptor_FindByName(PhyrePClassDescriptor*s,const char*n){return 0;}
int Phyre_PClassDescriptor_FindByNamePropertyList(PhyrePClassDescriptor*s,const char*n){return 0;}
int Phyre_PClassDescriptor_GetTotalSize(PhyrePClassDescriptor*s){
    if (!s) return 0;
    return s->m_totalSize ? s->m_totalSize : s->m_cachedTotalSize;
}
int Phyre_PClassDescriptor_GetMemberCount(PhyrePClassDescriptor*s){
    if (!s) return 0;
    return s->m_propCount;
}
int Phyre_PClassDescriptor_FinalizeRegistration(PhyrePClassDescriptor*s){return 0;}
int Phyre_PClassDescriptor_IsRegistered(PhyrePClassDescriptor*s){
    if (!s) return 0;
    return s->m_regState != 0;
}
int Phyre_PClassDescriptor_Unregister(PhyrePClassDescriptor*s){
    if (!s) return 0;
    s->m_regState = 0;
    return 1;
}
int Phyre_PClassDescriptor_RegisterAll(PhyrePClassDescriptor*s){
    if (!s) return 0;
    s->m_regState = 1;
    return 1;
}
int Phyre_PClassDescriptor_CalcLayoutSize(PhyrePClassDescriptor*s){
    if (!s) return 0;
    return s->m_cachedTotalSize;
}
int Phyre_PClassDescriptor_TraversePropertyList(PhyrePClassDescriptor*s,int c){return 0;}
int Phyre_PClassDescriptor_TraversePropertyList_V2(PhyrePClassDescriptor*s,int c){return 0;}
PhyrePNamespace* Phyre_PNamespace_GetSingleton(void){return 0;}
int Phyre_PNamespace_FindClassDescriptor(PhyrePNamespace*n,PhyrePClassDescriptor*c){return 0;}
int Phyre_PNamespace_AddClassDescriptor(PhyrePNamespace*n,PhyrePClassDescriptor*c){return 0;}
int Phyre_PClassMember_InsertIntoPropertyList(PhyrePClassDescriptor*s,int p){return 0;}
int Phyre_PClassMember_InitSingleton(void*s){return 0;}
int Phyre_PArrayU8_ClassDescriptorInit(void*s){return 0;}
int Phyre_PClass_ConstructDefault(PhyrePClassDescriptor*s,PhyrePClassDescriptor*s2){return 0;}
void Phyre_PClass_CopyMemberData(PhyrePClassDescriptor*s){}
void Phyre_PClassDataMember_ValidateLayout(PhyrePClassDescriptor*s){}
int Phyre_PClassMember_SerializeMember(int c,int*m){return 0;}

extern "C" void Phyre_PClassDescriptor_Init(void* desc) {
    if (desc) {
        for (int i = 0; i < 0x94; i++) {
            ((unsigned char*)desc)[i] = 0;
        }
    }
}
