// Function: sub_988BD0
// Address: 0x988bd0
int __cdecl sub_988BD0(int a1, int a2, int *a3)
{
  int v3; // eax
  int *v4; // ebx
  int v5; // esi
  int v6; // edi
  bool v7; // zf
  int *v8; // eax
  int result; // eax

  v3 = a1;
  v4 = a3;
  v5 = a2;
  v6 = a1 + 40;
  if ( *(_DWORD *)(a1 + 40) )
  {
    do
    {
      sub_988BD0(*(_DWORD *)(v3 + 36), ++v5, v4);
      v3 = *(_DWORD *)v6;
      v7 = *(_DWORD *)(*(_DWORD *)v6 + 40) == 0;
      v6 = *(_DWORD *)v6 + 40;
      a2 = v5;
    }
    while ( !v7 );
  }
  v8 = &a2;
  if ( *v4 > v5 )
    v8 = v4;
  result = *v8;
  *v4 = result;
  return result;
}
