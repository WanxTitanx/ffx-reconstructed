// Function: sub_A60E10
// Address: 0xa60e10
// Size: 0xb5

_BYTE *__cdecl sub_A60E10(int a1)
{
  _BYTE *v1; // edi
  _BYTE v3[64]; // [esp+8h] [ebp-44h] BYREF

  v1 = (char *)&unk_12A1470 + 384 * a1; /*0xa60e2b*/
  if ( (*v1 & 8) != 0 ) /*0xa60e34*/
  {
    sub_7EA5E0(v3); /*0xa60e3a*/
    sub_7E9440(v3, v3, v1 + 368); /*0xa60e4b*/
    sub_7E82C0(v1 + 240, v3, v1 + 176); /*0xa60e62*/
    sub_7E78B0(v1 + 288, v1 + 304, v1 + 224); /*0xa60e7c*/
  }
  else
  {
    sub_7E82C0(v1 + 240, v1 + 304, v1 + 176); /*0xa60eab*/
  }
  return v1 + 240; /*0xa60e86*/
}