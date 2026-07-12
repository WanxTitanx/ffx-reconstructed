// Function: sub_A37410
// Address: 0xa37410
// Size: 0xc1
// Prototype: 

int __stdcall sub_A37410(char a1)
{
  int v1; // edi
  _BYTE v3[48]; // [esp+8h] [ebp-30h] BYREF

  v1 = sub_A3D020(0, 0, 0, a1);
  (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 132))(
    dword_1A858B4[1],
    0,
    0,
    dword_1A858B4[481]);
  (*(void (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 172))(dword_1A858B4[1], dword_1A858B4[491]);
  sub_A3BED0(v3, v1, 1);
  if ( dword_1A858B4[482] )
  {
    (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 132))(
      dword_1A858B4[1],
      0,
      0,
      dword_1A858B4[482]);
    (*(void (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 172))(dword_1A858B4[1], dword_1A858B4[491]);
    sub_A3BED0(v3, v1, 0);
  }
  sub_A3C570(v3);
  sub_A3CD30();
  return sub_A3C350();
}

