// Function: sub_A15C70
// Address: 0xa15c70
// Size: 0x1e1

int __thiscall sub_A15C70(int this, int a2, float *a3, int a4)
{
  int result; // eax
  int v6; // ecx
  void **v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // esi
  _BYTE v13[16]; // [esp+10h] [ebp-2Ch] BYREF
  _DWORD Src[4]; // [esp+20h] [ebp-1Ch] BYREF
  int v15; // [esp+38h] [ebp-4h]

  if ( !*(_DWORD *)(this + 3292) ) /*0xa15c9a*/
    return 21; /*0xa15c9a*/
  v6 = *(_DWORD *)(this + 3404); /*0xa15cbc*/
  if ( !v6 ) /*0xa15cc4*/
    return 21; /*0xa15ca3*/
  if ( *(_UNKNOWN **)a4 != &unk_CA3454 ) /*0xa15ccf*/
    return 5; /*0xa15ccf*/
  v7 = *(_BYTE *)(v6 + 4) ? 0 : *(void ***)v6;
  if ( *v7 != &unk_CA3364 ) /*0xa15ce7*/
    return 5; /*0xa15ce7*/
  v8 = *(_BYTE *)(v6 + 4) ? 0 : *(_DWORD *)v6;
  if ( *(_DWORD *)(a4 + 28) != 2 * *(_DWORD *)(v8 + 28) ) /*0xa15d01*/
    return 5; /*0xa15d01*/
  v9 = *(_BYTE *)(v6 + 4) ? 0 : *(_DWORD *)v6;
  if ( *(_DWORD *)(a4 + 32) != 2 * *(_DWORD *)(v9 + 32) ) /*0xa15d1b*/
    return 5; /*0xa15e38*/
 ... [2211 chars total]