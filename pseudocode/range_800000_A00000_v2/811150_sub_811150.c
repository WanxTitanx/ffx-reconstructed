// Function: sub_811150
// Address: 0x811150
int __cdecl sub_811150(int a1, int a2, int a3, int a4)
{
  int v5; // ebx
  double v6; // st7
  float v8; // [esp+1Ch] [ebp+10h]

  v5 = *(unsigned __int8 *)(a3 + 2);
  sub_795730(*(unsigned __int8 *)(*(_DWORD *)(a1 + 544) + 24), (float *)(a1 + 192));
  v6 = *(float *)(a1 + 196);
  if ( v6 < 0.0 )
  {
    v8 = -v6;
    v6 = v8;
  }
  *(float *)(v5 + a4) = v6 * *(float *)(v5 + a4);
  return a3 + 4;
}
