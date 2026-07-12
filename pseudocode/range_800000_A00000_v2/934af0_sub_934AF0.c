// Function: sub_934AF0
// Address: 0x934af0
int sub_934AF0()
{
  int v0; // edx
  int result; // eax
  int v2; // ecx
  int v3; // esi

  if ( unk_193BF80 && *(_DWORD *)unk_193BF80 )
    v0 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
  else
    v0 = 0;
  if ( *(_DWORD *)(unk_193C0F0 + 652) == 1 )
  {
    result = *(_DWORD *)(v0 + 8);
    *(_DWORD *)(192 * *(_DWORD *)(unk_193C0F0 + 648) + result + 176) &= ~1u;
  }
  else
  {
    result = *(_DWORD *)(unk_193C0F0 + 652) - 2;
    if ( *(_DWORD *)(unk_193C0F0 + 652) == 2 )
    {
      v2 = 0;
      if ( *(int *)(v0 + 4) > 0 )
      {
        v3 = 0;
        do
        {
          result = *(_DWORD *)(v0 + 8);
          ++v2;
          *(_DWORD *)(result + v3) &= ~2u;
          v3 += 192;
        }
        while ( v2 < *(_DWORD *)(v0 + 4) );
      }
    }
  }
  return result;
}
