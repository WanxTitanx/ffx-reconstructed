// Function: sub_A1AE00
// Address: 0xa1ae00
// Size: 0x26a

int __userpurge sub_A1AE00@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, int a3, int a4)
{
  int result; // eax
  int v6; // eax
  int v7; // ecx
  _DWORD *v8; // edx
  _DWORD *p_Size; // ecx
  int *v10; // edi
  unsigned int v11; // eax
  int v12; // ecx
  _DWORD *v13; // ebx
  unsigned int v14; // eax
  _DWORD *v15; // eax
  int v16; // edi
  int v17; // ecx
  _DWORD *v18; // edx
  unsigned int n4; // ecx
  size_t Size; // ebx
  unsigned int n4_1; // ecx
  _DWORD *v22; // edx
  size_t Size_1; // esi
  int v25; // [esp-8h] [ebp-2Ch]
  _DWORD v26[4]; // [esp+4h] [ebp-20h] BYREF
  _DWORD Src[4]; // [esp+14h] [ebp-10h] BYREF
  int v28; // [esp+30h] [ebp+Ch]

  if ( !a1[7] ) /*0xa1ae09*/
    return 21; /*0xa1ae18*/
  v6 = sub_4E6BA0(a3, 0, 0); /*0xa1ae2a*/
  v7 = a1[2]; /*0xa1ae2f*/
  a1[29] = v6; /*0xa1ae32*/
  if ( v7 ) /*0xa1ae37*/
  {
    v8 = *(_DWORD **)(v6 + 4); /*0xa1ae39*/
    p_Size = *(_DWORD **)(v7 + 4); /*0xa1ae3c*/
    if ( ((p_Size[2] ^ v8[2]) & 0x7FFFFFFF) == 0 ) /*0xa1ae4a*/
    ... [3597 chars total]