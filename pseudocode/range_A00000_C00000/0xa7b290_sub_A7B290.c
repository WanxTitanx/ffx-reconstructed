// Function: sub_A7B290
// Address: 0xa7b290
// Size: 0xcb
// Prototype: 

int __cdecl sub_A7B290(int a1, int a2, int a3, int a4, int a5)
{
  unsigned __int16 *v5; // edi
  unsigned __int16 *v6; // esi
  int v7; // ebx
  double v9; // st7
  int v10; // ecx
  float v11; // [esp+0h] [ebp-14h]
  int v12; // [esp+4h] [ebp-10h]
  float v13; // [esp+20h] [ebp+Ch]

  v5 = (unsigned __int16 *)(a1 + 2 * *(unsigned __int16 *)(a2 + 8));
  v6 = (unsigned __int16 *)(a1 + 2 * *(unsigned __int16 *)(a2 + 10));
  v7 = *v6;
  if ( *(__int16 *)(a2 + 6) < 0 )
    goto LABEL_2;
  if ( !a3 )
    return sub_A7BBC0(*v5, (int)v5, (int)v5, 0.0, a5);
  if ( a3 == a4 )
  {
LABEL_2:
    v12 = a5;
    v11 = 0.0;
    return sub_A7BBC0(v7, (int)v6, (int)v6, v11, v12);
  }
  v9 = sub_A7C6F0(*v6, a3, a4);
  v10 = *v5;
  v13 = v9;
  v12 = a5;
  if ( ((v10 ^ v7) & 0x7FF) == 0 )
    return sub_A7BBC0(v10, (int)v6, (int)v5, v13, a5);
  v11 = 0.0;
  if ( v13 >= 0.5 )
    return sub_A7BBC0(v7, (int)v6, (int)v6, v11, v12);
  return sub_A7BBC0(v10, (int)v5, (int)v5, v11, a5);
}

