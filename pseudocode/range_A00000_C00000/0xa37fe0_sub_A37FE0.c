// Function: sub_A37FE0
// Address: 0xa37fe0
// Size: 0xb8
// Prototype: 

int sub_A37FE0()
{
  _DWORD *v0; // edi
  int v1; // eax
  _DWORD *v2; // ecx
  int v3; // esi
  int v4; // edx
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // eax
  int result; // eax

  (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_1A858B4[1] + 440))(dword_1A858B4[1]);
  v0 = dword_1A858B4;
  v1 = dword_1A858B4[622];
  v2 = (_DWORD *)dword_1A858B4[684];
  v3 = dword_1A858B4[689];
  v4 = dword_1A858B4[688];
  dword_1A858B4[686] = 1;
  v0[623] = v1;
  v0[622] = 0;
  v0[617] = 0;
  v0[621] = 0;
  v5 = v2[104];
  v2[3] &= 0xFFFFFFF9;
  v2[102] = v5;
  v6 = v2[105];
  v2[105] = v3;
  v2[103] = v6;
  v2[104] = v4;
  v7 = (_DWORD *)v0[685];
  v8 = v7[104];
  v7[3] &= 0xFFFFFFF9;
  v7[102] = v8;
  result = v7[105];
  v7[105] = v3;
  v7[103] = result;
  v7[104] = v4;
  return result;
}

