// Function: sub_9B5580
// Address: 0x9b5580
int __userpurge sub_9B5580@<eax>(_DWORD *a1@<ecx>, char a2@<efl>, float a3)
{
  bool v3; // cf
  bool v4; // zf
  char v5; // sf
  char v6; // of
  char v7; // pf
  _DWORD *v8; // edx
  int result; // eax
  int v10; // ecx
  _DWORD *v11; // edi
  _DWORD *v12; // esi

  v3 = a3 < 0.0;
  v7 = 0;
  v4 = a3 == 0.0;
  v5 = 0;
  v6 = 0;
  v8 = a1;
  BYTE1(result) = a2;
  if ( a3 != 0.0 )
  {
    v10 = a1[125];
    if ( v10 )
    {
      (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v10 + 4))(v10, v8 + 4);
      v8 = a1;
    }
    v11 = v8 + 84;
    v12 = v8 + 80;
    sub_97D980(v8 + 20, v8 + 4, LODWORD(a3), v8 + 80, v8 + 84);
    a1[36] = *v12;
    a1[37] = v12[1];
    a1[38] = v12[2];
    a1[39] = v12[3];
    a1[40] = *v11;
    a1[41] = v11[1];
    a1[42] = v11[2];
    a1[43] = v11[3];
    a1[20] = a1[4];
    a1[21] = a1[5];
    a1[22] = a1[6];
    a1[23] = a1[7];
    a1[24] = a1[8];
    a1[25] = a1[9];
    a1[26] = a1[10];
    a1[27] = a1[11];
    a1[28] = a1[12];
    a1[29] = a1[13];
    a1[30] = a1[14];
    a1[31] = a1[15];
    a1[32] = a1[16];
    a1[33] = a1[17];
    a1[34] = a1[18];
    result = a1[19];
    a1[35] = result;
  }
  return result;
}
