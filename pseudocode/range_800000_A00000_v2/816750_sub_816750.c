// Function: sub_816750
// Address: 0x816750
int __cdecl sub_816750(int a1, int a2)
{
  int v2; // edi
  __int16 v3; // cx
  __int16 v4; // dx
  int v5; // eax
  int v6; // eax

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(_WORD *)(a2 + 2);
  v4 = *(_WORD *)(a2 + 4);
  v5 = *(unsigned __int16 *)(a1 + 538) >> 12;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
      {
        *(_DWORD *)(v3 + v2 + 168) = *(_DWORD *)(a2 + 4);
        return a2 + 8;
      }
      else
      {
        return a2;
      }
    }
    else
    {
      *(_WORD *)(v3 + v2 + 168) = v4;
      return a2 + 6;
    }
  }
  else
  {
    *(_BYTE *)(v3 + v2 + 168) = v4;
    return a2 + 6;
  }
}
