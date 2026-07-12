// Function: sub_80A630
// Address: 0x80a630
int __usercall sub_80A630@<eax>(int a1@<ebp>, float *a2)
{
  double v2; // st7
  int v3; // eax
  double v4; // st7
  int v5; // eax
  double v6; // st7
  int v8[11]; // [esp-20h] [ebp-2Ch] BYREF
  int retaddr; // [esp+Ch] [ebp+0h]

  v8[8] = a1;
  v8[9] = retaddr;
  if ( !unk_11A004F )
  {
    unk_11A004F = 1;
    sub_9086D0(dword_11A0050);
  }
  v2 = a2[1];
  v8[0] = (int)*a2;
  v3 = (int)v2;
  v4 = a2[2];
  v8[1] = v3;
  v5 = (int)v4;
  v6 = a2[3];
  v8[2] = v5;
  v8[3] = (int)v6;
  return sub_90A040(v8);
}
