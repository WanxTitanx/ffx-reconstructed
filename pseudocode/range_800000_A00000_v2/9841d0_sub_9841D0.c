// Function: sub_9841D0
// Address: 0x9841d0
char __thiscall sub_9841D0(int this, float *a2)
{
  float *v3; // ecx
  float v5; // edi
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v3 = *(float **)(this + 196);
  if ( v3[1] == 0.0 )
    return 0;
  v5 = *a2;
  if ( (*(unsigned __int8 (__thiscall **)(float *, _DWORD))(*(_DWORD *)v3 + 4))(v3, *(_DWORD *)(*(_DWORD *)a2 + 200)) )
    sub_982C40(
      (int)&savedregs,
      *(int **)(this + 204),
      (float *)(this + 48),
      (float *)(this + 112),
      v5,
      *(int **)(LODWORD(v5) + 204),
      (float *)(LODWORD(v5) + 16),
      *(float **)(this + 196),
      COERCE_INT(*(float *)(this + 200)));
  return 1;
}
