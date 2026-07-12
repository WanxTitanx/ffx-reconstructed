// Function: sub_A3B160
// Address: 0xa3b160
// Size: 0x73
// Prototype: 

int __stdcall sub_A3B160(int *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // eax
  int v11; // [esp-18h] [ebp-3Ch]
  _DWORD v12[6]; // [esp+8h] [ebp-1Ch] BYREF

  v12[3] = a3 + a6;
  v12[1] = a4;
  v12[4] = a4 + a7;
  v9 = dword_1A858B4[1];
  v11 = *a1;
  v12[0] = a3;
  v12[2] = 0;
  v12[5] = 1;
  return (*(int (__stdcall **)(int, int, _DWORD, _DWORD *, int, int, _DWORD))(*(_DWORD *)v9 + 192))(
           v9,
           v11,
           0,
           v12,
           a8,
           a5,
           0);
}

