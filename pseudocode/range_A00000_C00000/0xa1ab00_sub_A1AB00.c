// Function: sub_A1AB00
// Address: 0xa1ab00
// Size: 0x1a1

int __userpurge sub_A1AB00@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, int a3, int a4)
{
  int v5; // eax
  int result; // eax
  int v7; // esi
  int *v8; // edi
  unsigned int v9; // eax
  int v10; // ecx
  _DWORD *v11; // esi
  int v12; // ecx
  int v14; // [esp-4h] [ebp-28h]
  float Src[4]; // [esp+8h] [ebp-1Ch] BYREF
  int v16; // [esp+18h] [ebp-Ch]
  int v17; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]
  int v19; // [esp+30h] [ebp+Ch]

  v5 = sub_A06120(); /*0xa1ab0e*/
  a1[18] = v5; /*0xa1ab16*/
  if ( !v5 ) /*0xa1ab1b*/
    return 21; /*0xa1ab1e*/
  a1[19] = sub_4E6BA0(a3, 0, 0); /*0xa1ab41*/
  v7 = sub_56CD50("GlowBuffer"); /*0xa1ab49*/
  a1[24] = v7; /*0xa1ab52*/
  v19 = sub_56CD50("GlowBufferState"); /*0xa1ab61*/
  a1[25] = v19; /*0xa1ab64*/
  v16 = sub_56CD50("GlowGain"); /*0xa1ab73*/
  a1[26] = v16; /*0xa1ab76*/
  v18 = sub_56CD50("GaussianOutputScale"); /*0xa1ab85*/
  a1[27] = v18; /*0xa1ab88*/
  v17 = sub_56CD50("GaussianBlurBufferSize"); /*0xa1ab97*/
  a1[28] = v17;... [2021 chars total]