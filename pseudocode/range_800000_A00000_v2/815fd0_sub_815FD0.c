// Function: sub_815FD0
// Address: 0x815fd0
int __cdecl sub_815FD0(int a1, int a2)
{
  int v2; // edx
  int *v3; // ecx

  v2 = a2;
  v3 = *(int **)(a1 + 544);
  switch ( *(_WORD *)(a2 + 2) )
  {
    case 1:
      if ( !*(_WORD *)(a1 + 530) )
        return a2 + 6;
      return *(__int16 *)(a2 + 4) + a2;
    case 2:
      dword_C48CC0 = v3[36];
      dword_C48CC4 = v3[37];
      dword_C48CC8 = v3[38];
      return a2 + 4;
    case 3:
      return a2 + 6;
    case 4:
      *(_WORD *)(a1 + 952) = *(_WORD *)(a2 + 4);
      return a2 + 6;
    default:
      return v2;
  }
}
