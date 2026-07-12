// Function: sub_A23080
// Address: 0xa23080
// Size: 0x8b
// Prototype: 

int __thiscall sub_A23080(int *this, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // eax
  int v4; // edi
  unsigned int v5; // edx
  int *i; // ebx
  int v7; // esi
  int *v8; // esi
  int result; // eax
  unsigned int v10; // [esp+14h] [ebp+8h]
  unsigned int v11; // [esp+18h] [ebp+Ch]

  v3 = a3 >> 1;
  v4 = 0;
  v5 = a2 >> 1;
  v11 = a3 >> 1;
  v10 = a2 >> 1;
  for ( i = this + 971; ; ++i )
  {
    v7 = *i;
    if ( !*i )
      break;
    if ( *(_BYTE *)(v7 + 4) )
      break;
    v8 = *(int **)v7;
    if ( !v8 )
      break;
    if ( v8[7] != v5 || v8[8] != v3 )
    {
      if ( sub_596120(v8) )
      {
        result = sub_59CDD0(v8);
        if ( result )
          return result;
      }
      result = sub_4C41C0(v8, v10, v11, *v8, 0);
      if ( result )
        return result;
      v3 = v11;
      v5 = v10;
    }
    if ( (unsigned int)++v4 >= 3 )
      return 0;
  }
  return 1;
}

