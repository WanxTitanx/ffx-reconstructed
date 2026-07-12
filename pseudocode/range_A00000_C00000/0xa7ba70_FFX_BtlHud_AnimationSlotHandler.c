// Function: FFX_BtlHud_AnimationSlotHandler
// Address: 0xa7ba70
// Size: 0x81
// Prototype: int __cdecl(int n2, int, int)

int __cdecl FFX_BtlHud_AnimationSlotHandler(int n2, int a2, int a3)
{
  int result; // eax
  int v4; // ecx
  int v5; // edx
  int *v6; // ecx
  _DWORD *v7; // eax
  int i; // ecx

  result = a2;
  if ( a2 )
  {
    v4 = unk_22FB4DC[n2];
    if ( v4 )
    {
      v5 = v4 + a2;
      if ( v4 + a2 )
      {
        *(_DWORD *)(v5 + 4) &= 0x3FFFFFFFu;
        v6 = (int *)(unk_22FB4DC[n2] + (*(_DWORD *)(v5 + 4) & 0x3FFFFFFF));
        v7 = v6 + 1;
        for ( i = *v6; i > 0; v7 += 5 )
        {
          if ( a3 )
            *v7 |= 0x80000000;
          else
            *v7 &= 0x3FFFFFFFu;
          v7[2] = 0;
          *((_WORD *)v7 + 6) = -1;
          *((_WORD *)v7 + 2) = 0;
          *(_DWORD *)((char *)v7 + 14) = 0;
          --i;
        }
      }
      return v5;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

