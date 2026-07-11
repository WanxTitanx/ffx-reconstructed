#include "../include/ffx_debug.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/ffx_structs.h"
#include "../include/ffx_vtables.h"

bool Phyre_PClassDescriptor_Destructor(PhyrePClassDescriptor *pThis, bool flags) { (void)pThis; (void)flags; return true; }

int *Phyre_PClassDescriptor_ctor(PhyrePClassDescriptor *pThis, int name, int field18, int field1C, int totalSize, int parentCD, int field84) {
    (void)pThis; (void)name; (void)field18; (void)field1C; (void)totalSize; (void)parentCD; (void)field84; return (int *)pThis;
}

void Phyre_PClassDescriptor_Constructor(PhyrePClassDescriptor *pThis, int name, int field18, int field1C, int totalSize) {
    (void)pThis; (void)name; (void)field18; (void)field1C; (void)totalSize;
}

int Phyre_PClassDescriptor_GetTotalSize(PhyrePClassDescriptor *pThis) { (void)pThis; return 0; }
int Phyre_PClassDescriptor_GetMemberCount(PhyrePClassDescriptor *pThis) { (void)pThis; return 0; }
bool Phyre_PClassDescriptor_IsRegistered(PhyrePClassDescriptor *pThis) { (void)pThis; return false; }
void Phyre_PClassDescriptor_Unregister(PhyrePClassDescriptor *pThis) { (void)pThis; }
void Phyre_PClassDescriptor_RegisterAll(PhyrePClassDescriptor *pThis) { (void)pThis; }
int Phyre_PClassDescriptor_CalcLayoutSize(PhyrePClassDescriptor *pThis) { (void)pThis; return 0; }

int HeapArena_GlobalBootInit(int heapSize) { (void)heapSize; return 1; }
float *Phyre_PApplication_Constructor(float *app) { return app; }
int Phyre_Application_SetWindowTitle(int *app, const char *title) { (void)app; (void)title; return 1; }
int FFX_Dbg_LogPrintf(int level, const char *fmt, ...) { (void)level; (void)fmt; return 0; }
int FFX_Debug_RedirectStdoutToFile(void) { return 0; }
int *GetGlobalSystemContext(void) { static int ctx[256] = {0}; return ctx; }
int Phyre_Property_SetValue231(float *app, int value) { (void)app; (void)value; return 1; }
