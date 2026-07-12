// Function: sub_A6CF10
// Address: 0xa6cf10
// Size: 0x4d
// Prototype: 

int __cdecl sub_A6CF10(int a1, int a2, int a3)
{
  int v3; // edi

  v3 = *(_DWORD *)(a3 + 912);
  sub_A690C0(v3 + 128, v3 + 192);
  sub_A6CD80(v3 + 64, *(_DWORD *)(a2 + 40), *(_DWORD *)(a2 + 44));
  return sub_A6CD80(v3 + 192, v3 + 192, *(_DWORD *)(a2 + 44));
}

