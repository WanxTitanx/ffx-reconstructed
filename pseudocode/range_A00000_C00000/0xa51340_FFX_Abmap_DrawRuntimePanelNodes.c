// Function: FFX_Abmap_DrawRuntimePanelNodes
// Address: 0xa51340
// Size: 0x217
// Prototype: int __usercall@<eax>(int@<ebp>)

// [Jarvis naming goal 2026-06-17 pass2] Draws runtime Sphere Grid panel/node icons using node content, active character mask, and panel/icon table.
int __usercall FFX_Abmap_DrawRuntimePanelNodes@<eax>(int a1@<ebp>)
{
  char v1; // cl
  int v2; // edi
  int result; // eax
  double v4; // st7
  int v5; // esi
  _DWORD *v6; // edx
  float v7; // [esp+0h] [ebp-130h]
  int v8; // [esp+18h] [ebp-118h]
  int v9; // [esp+1Ch] [ebp-114h]
  int v10; // [esp+1Ch] [ebp-114h]
  unsigned __int8 v11; // [esp+23h] [ebp-10Dh]
  _WORD v12[2]; // [esp+24h] [ebp-10Ch] BYREF
  int v13; // [esp+28h] [ebp-108h]
  int v14; // [esp+2Ch] [ebp-104h]
  int v15; // [esp+30h] [ebp-100h]
  _BYTE *v16; // [esp+34h] [ebp-FCh]
  char v17; // [esp+3Ch] [ebp-F4h]
  _DWORD *v18; // [esp+40h] [ebp-F0h]
  _BYTE v19[64]; // [esp+5Ch] [ebp-D4h] BYREF
  _BYTE v20[64]; // [esp+9Ch] [ebp-94h] BYREF
  _DWORD v21[21]; // [esp+DCh] [ebp-54h] BYREF
  _UNKNOWN *retaddr; // [esp+130h] [ebp+0h]

  v21[18] = a1; /*0xa5134c*/
  v21[19] ... [3401 chars total]