// Function: sub_80AD60
// Address: 0x80ad60
int __usercall sub_80AD60@<eax>(float a1@<ebp>)
{
  int result; // eax
  float v2[11]; // [esp-20h] [ebp-2Ch] BYREF
  float retaddr; // [esp+Ch] [ebp+0h]

  v2[8] = a1;
  v2[9] = retaddr;
  v2[3] = 1.0;
  v2[2] = 1.0;
  v2[1] = 1.0;
  v2[0] = 1.0;
  sub_909E10(4);
  result = sub_90A270(v2);
  if ( unk_11A004F )
  {
    result = sub_90A040(dword_11A0050);
    unk_11A004F = 0;
  }
  flt_C48E64 = 1.0;
  flt_C48E68 = 1.0;
  flt_C48E6C = 1.0;
  flt_C48E70 = 1.0;
  return result;
}
