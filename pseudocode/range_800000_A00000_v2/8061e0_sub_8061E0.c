// Function: sub_8061E0
// Address: 0x8061e0
int __usercall sub_8061E0@<eax>(float a1@<ebp>, void *a2, int n32, float a4, int a5, int a6, int a7)
{
  int result; // eax
  float v8; // [esp+10h] [ebp-30h]
  float v9; // [esp+10h] [ebp-30h]
  float v10[11]; // [esp+14h] [ebp-2Ch] BYREF
  float retaddr; // [esp+40h] [ebp+0h]

  v10[8] = a1;
  v10[9] = retaddr;
  v8 = flt_12A80C0[n32];
  if ( a7 && n32 < 32 )
  {
    sub_795730(n32, v10);
  }
  else
  {
    v10[0] = sub_82ADB0(LODWORD(flt_12A80C0[n32]));
    v10[1] = sub_82ADC0(LODWORD(v8));
    v10[2] = sub_82ADD0(LODWORD(v8));
  }
  v9 = sub_82ABE0(LODWORD(v8)) * a4 * 0.001000000047497451 * 0.00390625;
  sub_7EA760(v10, v10, LODWORD(v9));
  sub_7EA640(a2, (int)v10);
  result = a5;
  if ( a5 )
  {
    if ( a6 )
      return sub_7E9760(a2, a2, a5, a6);
    else
      return sub_7E9440(a2, a2, a5);
  }
  else if ( a6 )
  {
    return sub_7EA460(a2, a2, a6);
  }
  return result;
}
