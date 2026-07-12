// Function: sub_9B14C0
// Address: 0x9b14c0
int __thiscall sub_9B14C0(_DWORD *this)
{
  int v1; // edx
  int v2; // ecx
  float v4; // [esp+0h] [ebp-10h]
  float i; // [esp+8h] [ebp-8h]
  float i_1; // [esp+Ch] [ebp-4h]

  v1 = *(this + 2581);
  v2 = *(_DWORD *)(v1 + 52);
  v4 = *(float *)(v1 + 20);
  for ( i = *(float *)(v1 + 16) * *(float *)(v1 + 16); v2; v2 = *(_DWORD *)(v2 + 52) )
  {
    if ( *(float *)(v2 + 20) >= (double)v4 )
    {
      i_1 = *(float *)(v2 + 16) * *(float *)(v2 + 16);
      if ( i > (double)i_1 )
      {
        i = *(float *)(v2 + 16) * *(float *)(v2 + 16);
        v1 = v2;
        v4 = *(float *)(v2 + 20);
      }
    }
  }
  return v1;
}
