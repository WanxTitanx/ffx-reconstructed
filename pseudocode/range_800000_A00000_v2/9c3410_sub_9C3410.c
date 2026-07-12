// Function: sub_9C3410
// Address: 0x9c3410
int __cdecl sub_9C3410(int a1, float *a2)
{
  int result; // eax
  float v4; // [esp+0h] [ebp-10h]
  float v5; // [esp+0h] [ebp-10h]
  float v6; // [esp+4h] [ebp-Ch]
  float v7; // [esp+8h] [ebp-8h]
  float v8; // [esp+Ch] [ebp-4h]
  float v9; // [esp+1Ch] [ebp+Ch]

  v8 = a2[1];
  v9 = *a2;
  v7 = a2[2];
  v6 = v9 * v9 + v8 * v8 + v7 * v7;
  v4 = sqrt(v6);
  result = a1;
  *(_DWORD *)(a1 + 12) = 0;
  v5 = 1.0 / v4;
  *(float *)a1 = v9 * v5;
  *(float *)(a1 + 4) = v8 * v5;
  *(float *)(a1 + 8) = v5 * v7;
  if ( v6 < 1.4210855e-14 )
  {
    *(_DWORD *)a1 = 0;
    *(_DWORD *)(a1 + 4) = 0;
    *(_DWORD *)(a1 + 8) = 0;
    *(_DWORD *)(a1 + 12) = 0;
  }
  return result;
}
