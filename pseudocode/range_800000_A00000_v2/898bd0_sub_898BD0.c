// Function: sub_898BD0
// Address: 0x898bd0
int __cdecl sub_898BD0(unsigned __int16 a1)
{
  int v1; // ecx
  float *v2; // eax
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = v1;
  v2 = FFX_Btl_LookupCommandDataById(a1, &v4);
  if ( ((_BYTE)v2[7] & 4) == 0 )
    return 0;
  sub_89DB10(1, v4 + *(unsigned __int16 *)v2);
  return 1;
}
