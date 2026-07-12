// Function: sub_934B50
// Address: 0x934b50
int sub_934B50()
{
  int v0; // esi
  int result; // eax
  int v2; // ecx
  int v3; // edx

  if ( unk_193BF80 && *(_DWORD *)unk_193BF80 )
    v0 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
  else
    v0 = 0;
  result = unk_193C0F0;
  if ( *(_DWORD *)(unk_193C0F0 + 652) == 1 )
  {
    result = *(_DWORD *)(v0 + 8);
    *(_DWORD *)(192 * *(_DWORD *)(unk_193C0F0 + 648) + result + 176) |= 1u;
  }
  else
  {
    v2 = *(_DWORD *)(unk_193C0F0 + 652) - 2;
    if ( *(_DWORD *)(unk_193C0F0 + 652) == 2 && *(int *)(v0 + 4) > 0 )
    {
      v3 = 0;
      do
      {
        if ( v2 != *(_DWORD *)(result + 648) )
        {
          *(_DWORD *)(*(_DWORD *)(v0 + 8) + v3) |= 2u;
          result = unk_193C0F0;
        }
        ++v2;
        v3 += 192;
      }
      while ( v2 < *(_DWORD *)(v0 + 4) );
    }
  }
  return result;
}
