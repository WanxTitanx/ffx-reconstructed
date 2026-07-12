// Function: sub_A3CE00
// Address: 0xa3ce00
// Size: 0xb7
// Prototype: 

_DWORD *__cdecl sub_A3CE00(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  _DWORD *v5; // edi
  int v6; // eax
  _DWORD *result; // eax
  float v8[6]; // [esp+0h] [ebp-2Ch] BYREF
  _DWORD v9[4]; // [esp+18h] [ebp-14h] BYREF

  v4 = dword_1A858B4[1];
  v8[0] = (float)a1;
  v8[1] = (float)a2;
  v8[2] = (float)a3;
  v8[3] = (float)a4;
  v8[4] = 0.0;
  v8[5] = 1.0;
  (*(void (__stdcall **)(int, int, float *))(*(_DWORD *)v4 + 176))(v4, 1, v8);
  v5 = dword_1A858B4;
  dword_1A858B4[449] = a3;
  v9[2] = a1 + a3;
  v5[448] = a2;
  v9[1] = a2;
  v9[3] = a2 + a4;
  v6 = v5[1];
  v5[447] = a1;
  v5[450] = a4;
  v9[0] = a1;
  (*(void (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v6 + 180))(v6, 1, v9);
  result = dword_1A858B4;
  dword_1A858B4[625] = 0;
  return result;
}

