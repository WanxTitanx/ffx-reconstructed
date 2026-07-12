// Function: sub_A04460
// Address: 0xa04460
// Size: 0x163
// Prototype: int __cdecl(int, int, float, char)

int __cdecl sub_A04460(int *a1, int a2, float a3, char a4)
{
  int v4; // ebx
  int v6; // [esp+18h] [ebp-DCh]
  _BYTE v7[4]; // [esp+1Ch] [ebp-D8h] BYREF
  int v8; // [esp+20h] [ebp-D4h]
  _BYTE v9[4]; // [esp+80h] [ebp-74h] BYREF
  int v10; // [esp+84h] [ebp-70h]
  int v11; // [esp+F0h] [ebp-4h]

  if ( *(_DWORD *)(*(_DWORD *)a2 + 8) != 12 || *(_DWORD *)(a2 + 28) != a1[7] || *(_DWORD *)(a2 + 32) != a1[8] ) /*0xa044b2*/
    return 5; /*0xa045a2*/
  sub_5835F0(v9); /*0xa044bb*/
  v11 = 0; /*0xa044c6*/
  v4 = sub_A1B2A0(v9); /*0xa044d2*/
  if ( !v4 ) /*0xa044d6*/
  {
    v6 = v10; /*0xa044df*/
    if ( v10 ) /*0xa044e7*/
    {
      sub_5835F0(v7); /*0xa044f3*/
      LOBYTE(v11) = 1; /*0xa04501*/
      v4 = sub_5A7970(v7); /*0xa0450a*/
      if ( v4 || !v8 ) /*0xa04518*/
      {
        if ( !sub_59D880(*(_DWORD *)(a2 + 8), v9) ) /*0xa04574*/
          *(_BYTE *)(a2 + 4) = 0; /*0xa0457d*/
      }
      else
      {
        v4 = sub_A042C0(v8, v6, *(_DWORD *)(a2 + 28), *(_DWORD *)(a2 + 3... [1378 chars total]