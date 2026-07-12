// Function: sub_8176D0
// Address: 0x8176d0
unsigned int __usercall sub_8176D0@<eax>(int a1@<ebp>, int a2)
{
  unsigned int result; // eax
  int v3; // esi
  float v4; // [esp+28h] [ebp-78h]
  float v5; // [esp+2Ch] [ebp-74h]
  float v6; // [esp+2Ch] [ebp-74h]
  float v7; // [esp+30h] [ebp-70h]
  float v8; // [esp+30h] [ebp-70h]
  int v9; // [esp+34h] [ebp-6Ch] BYREF
  _DWORD v10[4]; // [esp+44h] [ebp-5Ch] BYREF
  _DWORD v11[4]; // [esp+54h] [ebp-4Ch] BYREF
  float v12[4]; // [esp+64h] [ebp-3Ch] BYREF
  _DWORD v13[8]; // [esp+74h] [ebp-2Ch] BYREF
  _DWORD v14[3]; // [esp+94h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+A0h] [ebp+0h]

  v14[0] = a1;
  v14[1] = retaddr;
  result = (unsigned int)v14 ^ __security_cookie;
  if ( word_11A004C )
  {
    sub_782BA0(v10);
    sub_7BD3F0(1, v13);
    sub_7BD3F0(0, v11);
    v5 = sub_7BD490();
    result = sub_7E8EE0(v10[0], v10[2], 120.0, v13[0], v13[2], v11[0], v11[1], v12, &v9);
    if ( result )
    {
      v3 = *(_DWORD *)(a2 + 92);
      v12[1] = *(float *)&v13[1];
      v7 = sub_7E7ED0(v13, v12);
      v4 = (float)(word_11A004C - 4096);
      v8 = v4 * v7 * 0.00390625;
      FFX_BtlPool_WriteEntryTransform(v3, 1, (int)v12);
      v6 = v5 - v8;
      result = FFX_BtlPool_SetSpeedParameter(v3, v6);
      if ( unk_2322790 )
      {
        if ( unk_232154B )
          return sub_7EACC0(-2139095040, 72, 0);
      }
    }
  }
  return result;
}
