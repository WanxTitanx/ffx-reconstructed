// Function: sub_A428A0
// Address: 0xa428a0
// Size: 0x102
// Prototype: 

unsigned int __cdecl sub_A428A0(int a1)
{
  _DWORD *CoreWorkPtr; // ebx
  unsigned int result; // eax
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // ebx
  int v6; // eax
  int v7; // edi
  int v8; // eax

  CoreWorkPtr = FFX_Btl_GetCoreWorkPtr();
  result = sub_76D770(n14, a1);
  if ( !result )
  {
    if ( unk_133C8D3 )
      return sub_76C430(a1);
    v3 = a1 + CoreWorkPtr[8];
    v4 = 0;
    if ( *((_DWORD *)FFX_Btl_GetCoreWorkPtr() + 12) )
    {
      v5 = sub_A42C00(v3);
      if ( v5 )
      {
        if ( n14 != 14
          && n14 != 16
          && n14 != 26
          && n14 != 28
          && n14 != 29
          && n14 != 30
          && n14 != 31
          && n14 != 32
          && n14 != 33
          && n14 != 34
          && n14 != 40
          && n14 != 41
          || (v4 = sub_76C520(a1), v4 == -1) )
        {
          v6 = sub_62FBE0(v5, 1);
          v7 = v6;
          if ( !v6 )
          {
            nullsub_34();
            return 0;
          }
          v8 = sub_62F910(v6);
          v4 = ((((v8 + 15) >> 31) & 0xF) + v8 + 15) & 0xFFFFFFF0;
          FFX_FileIO_IopDevice_Close(v7);
        }
      }
    }
    return v4;
  }
  return result;
}

