// Function: sub_A139C0
// Address: 0xa139c0
// Size: 0x1ca

int __thiscall sub_A139C0(_DWORD *this, int a2, int a3)
{
  int v4; // esi
  _DWORD *v5; // edi
  int n66; // eax
  int n3; // eax
  unsigned int n4; // ecx
  size_t Size; // edx
  int v10; // esi
  int v11; // [esp-4h] [ebp-40h]
  _BYTE v12[16]; // [esp+10h] [ebp-2Ch] BYREF
  _DWORD Src[4]; // [esp+20h] [ebp-1Ch] BYREF
  int v14; // [esp+38h] [ebp-4h]

  v4 = *(this + 29); /*0xa139ea*/
  if ( !v4 ) /*0xa139ef*/
    goto LABEL_18; /*0xa139ef*/
  v5 = *(_DWORD **)(*(this + 24) + 4); /*0xa139fb*/
  n66 = *(unsigned __int8 *)(v4 + 2); /*0xa139fe*/
  Src[0] = 66; /*0xa13a05*/
  Src[1] = 0; /*0xa13a0c*/
  Src[3] = a3; /*0xa13a13*/
  Src[2] = this + 14; /*0xa13a16*/
  if ( n66 != 66 && n66 != 217 && n66 != 218 && n66 != 219 && n66 != 220 && n66 != 18 ) /*0xa13a3d*/
    return 5; /*0xa13a55*/
  if ( this == (_DWORD *)-56 || !a3 || (n3 = sub_59E6B0(a3)) == 0 ) /*0xa13a6a*/
  {
    n4 = *(unsigned __int16 *)(v4 + 8); /*0xa13a74*/
    Size = *(_WORD *)(v4 + 10) & 0x1FFF; /*0xa13a80*/
    if ( n4... [2087 chars total]