// Function: sub_9BBF40
// Address: 0x9bbf40
int __userpurge sub_9BBF40@<eax>(int a1@<ecx>, char a2@<efl>, float a3)
{
  int v4; // esi
  double v5; // st7
  int result; // eax
  int v7; // ecx
  char v8; // cf
  bool v9; // zf
  char v10; // sf
  char v11; // of
  bool v12; // pf
  float v13; // [esp+0h] [ebp-Ch]

  v4 = 0;
  if ( *(int *)(a1 + 8) > 0 )
  {
    v5 = a3;
    do
    {
      result = *(_DWORD *)(a1 + 16);
      v7 = *(_DWORD *)(result + 4 * v4);
      if ( (*(_BYTE *)(v7 + 244) & 2) != 0 && *(_DWORD *)(v7 + 228) != 2 )
      {
        result = *(_DWORD *)(v7 + 216) >> 1;
        v8 = 0;
        v11 = 0;
        v9 = (*(_DWORD *)(v7 + 216) & 2) == 0;
        v12 = __SETP__((*(_DWORD *)(v7 + 216) & 2) != 0, 0);
        v10 = 0;
        if ( (*(_DWORD *)(v7 + 216) & 2) != 0 )
        {
          v13 = v5;
          result = sub_9B5580((_DWORD *)v7, a2, v13);
          v5 = a3;
        }
      }
      ++v4;
    }
    while ( v4 < *(_DWORD *)(a1 + 8) );
  }
  return result;
}
