// Function: sub_A2A650
// Address: 0xa2a650
// Size: 0x56
// Prototype: _DWORD __stdcall(float *p_Src)

int __thiscall sub_A2A650(int *this, float *p_Src)
{
  int v2; // esi
  int v3; // eax
  float Src[4]; // [esp+4h] [ebp-10h] BYREF

  v2 = *this;
  Src[0] = *p_Src;
  Src[1] = p_Src[1];
  Src[2] = p_Src[2];
  Src[3] = 1.0;
  if ( v2 && (v3 = sub_56CD50("textColor")) != 0 )
    return sub_638930(v3, Src);
  else
    return 9;
}

