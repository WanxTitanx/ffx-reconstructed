// Function: sub_807C90
// Address: 0x807c90
unsigned int __cdecl sub_807C90(int a1)
{
  int v1; // edi
  int v2; // eax
  int v3; // ebx
  int v4; // esi
  int v5; // eax

  v1 = 0;
  v2 = sub_83C9A0(a1);
  v3 = v2;
  if ( !v2 )
    return 0;
  v4 = 0;
  if ( v2 > 0 )
  {
    do
    {
      v5 = sub_83C9F0(a1, v4++);
      v1 += 8 * v5;
    }
    while ( v4 < v3 );
  }
  if ( ((v1 + 15) & 0xFFFFFFF0) != 0 )
    return ((v1 + 15) & 0xFFFFFFF0) + 32;
  else
    return 0;
}
