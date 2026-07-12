// Function: sub_A1E8E0
// Address: 0xa1e8e0
// Size: 0x21f

int __thiscall sub_A1E8E0(int *this, int a2, int a3, int a4, int a5, int a6)
{
  int *v7; // edx
  int result; // eax
  int v9; // esi
  int v10; // esi
  void **v11; // eax
  int n2; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // esi
  _BYTE dst[64]; // [esp+10h] [ebp-ACh] BYREF
  _BYTE src[64]; // [esp+50h] [ebp-6Ch] BYREF
  _BYTE v18[16]; // [esp+90h] [ebp-2Ch] BYREF
  int Src; // [esp+A0h] [ebp-1Ch] BYREF
  int v20; // [esp+A4h] [ebp-18h]
  _DWORD *v21; // [esp+A8h] [ebp-14h]
  int v22; // [esp+ACh] [ebp-10h]
  int v23; // [esp+B8h] [ebp-4h]

  v7 = (int *)*(this + 26); /*0xa1e90d*/
  if ( !v7 ) /*0xa1e912*/
    return 21; /*0xa1e914*/
  if ( *((_BYTE *)v7 + 4) ) /*0xa1e92b*/
    v9 = 0; /*0xa1e935*/
  else
    v9 = *v7; /*0xa1e931*/
  if ( *(_DWORD *)(v9 + 28) != *(_DWORD *)(a5 + 28) >> 2 ) /*0xa1e943*/
    return 5; /*0xa1e943*/
  v10 = *((_BYTE *)v7 + 4) ? 0 : *v7;
  if ( *(_DWORD *)(v10 + 32) != *(_DWORD *)(a5 + 32) >> 2 ) /*0xa1e95e*/
    return 5; /*0xa1e95e*/
  v11... [2588 chars total]