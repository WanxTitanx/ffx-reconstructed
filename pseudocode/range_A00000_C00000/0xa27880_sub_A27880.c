// Function: sub_A27880
// Address: 0xa27880
// Size: 0x64
// Prototype: 

int __cdecl sub_A27880(int a1)
{
  bool v1; // zf
  int n2; // eax

  v1 = *(_DWORD *)(a1 + 208) == 1;
  *(_DWORD *)(a1 + 212) = 1;
  if ( !v1 )
  {
    do
    {
      PhyreEvent_WaitForever((HANDLE *)(a1 + 684));
      n2 = *(_DWORD *)(a1 + 228);
      if ( (n2 == 1 || n2 == 2) && *(_DWORD *)(a1 + 232) != 2 )
        sub_A27650((_DWORD *)a1);
    }
    while ( *(_DWORD *)(a1 + 208) != 1 );
  }
  *(_DWORD *)(a1 + 212) = 2;
  return 0;
}

