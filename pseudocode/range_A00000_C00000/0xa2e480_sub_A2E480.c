// Function: sub_A2E480
// Address: 0xa2e480
// Size: 0xa7
// Prototype: 

int __stdcall sub_A2E480(int *a1)
{
  int v1; // eax
  int v2; // ecx
  int i; // esi
  void *buf; // edx
  _DWORD *j; // ecx
  void *buf_1; // [esp+10h] [ebp+8h]

  v1 = unk_1A85354;
  v2 = unk_1A85354;
  for ( i = 0; v2; ++i )
    v2 = *(_DWORD *)(v2 + 8);
  if ( i != *a1 )
  {
    buf = 0;
    buf_1 = 0;
    if ( i )
    {
      buf = (void *)sub_42FC60(4 * i, 4);
      buf_1 = buf;
      if ( !buf )
        return 13;
      memset(buf, 0, 4 * i);
    }
    if ( (void *)a1[1] != buf && *a1 >= 0 )
    {
      Phyre_Memory_AlignedFree(a1[1]);
      buf = buf_1;
    }
    a1[1] = (int)buf;
    *a1 = i;
    v1 = unk_1A85354;
  }
  for ( j = (_DWORD *)a1[1]; v1; ++j )
  {
    *j = v1;
    v1 = *(_DWORD *)(v1 + 8);
  }
  return 0;
}

