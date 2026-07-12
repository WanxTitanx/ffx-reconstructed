// Function: sub_808C70
// Address: 0x808c70
int __cdecl sub_808C70(int *a1, _DWORD *a2)
{
  int *v2; // esi
  int n4; // edi
  int result; // eax
  _DWORD v5[4]; // [esp+Ch] [ebp-14h] BYREF

  v5[0] = *a2;
  v5[1] = a2[1];
  v2 = a1;
  v5[2] = a2[2];
  v5[3] = a2[3];
  n4 = 4;
  do
  {
    result = (int)*(float *)((char *)v2 + (char *)v5 - (char *)a1);
    *v2++ = result;
    --n4;
  }
  while ( n4 );
  return result;
}
