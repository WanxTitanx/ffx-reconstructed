// Function: sub_920050
// Address: 0x920050
void __cdecl sub_920050(int a1, int a2, _DWORD *a3, _DWORD *a4, int *a5)
{
  int v5; // eax

  if ( a3 )
    *a3 = sub_929910(a1);
  if ( a4 )
    *a4 = sub_929910(a2);
  if ( a5 )
  {
    v5 = (a1 + 63) / 64;
    *a5 = v5;
    if ( (v5 & 1) != 0 )
      *a5 = v5 + 1;
  }
}
