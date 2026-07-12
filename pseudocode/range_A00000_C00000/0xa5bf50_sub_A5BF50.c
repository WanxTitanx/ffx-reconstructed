// Function: sub_A5BF50
// Address: 0xa5bf50
// Size: 0x131

int __usercall sub_A5BF50@<eax>(
        int a1@<ebp>,
        __int64 n2622,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        float a11,
        float a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17)
{
  _DWORD v18[31]; // [esp+2Ch] [ebp-7Ch] BYREF
  _UNKNOWN *retaddr; // [esp+A8h] [ebp+0h]

  v18[28] = a1; /*0xa5bf5c*/
  v18[29] = retaddr; /*0xa5bf60*/
  sub_83B6D0(); /*0xa5bf6b*/
  unknown_libname_742(a3); /*0xa5bf73*/
  if ( sub_645580(n2622) ) /*0xa5bf80*/
  {
    if ( !unk_12FB790 ) /*0xa5bf93*/
      sub_A5C370(n2622, SHIDWORD(n2622), a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17); /*0xa5bfcf*/
    return FFX_MagicHost_CommitDrawableResources(n2622); /*0xa5bfd9*/
  }
  else if ( sub_A5C130(n2622, HIDWORD(n2622), a3, v18, a7, a8, a9, a10, a17) && sub_645930(n2622) ) /*0xa5c011*/
  {
    sub_A5C370(n2622, SHIDWORD(n2622), a3, a4, a5,... [1220 chars total]