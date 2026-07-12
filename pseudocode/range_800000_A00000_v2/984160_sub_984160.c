// Function: sub_984160
// Address: 0x984160
char __thiscall sub_984160(float **this, int a2)
{
  float *v3; // ecx

  v3 = *(this + 57);
  if ( v3[1] == 0.0 )
    return 0;
  if ( (*(unsigned __int8 (__thiscall **)(float *, _DWORD))(*(_DWORD *)v3 + 4))(v3, *(_DWORD *)(*(_DWORD *)a2 + 200)) )
    sub_9849E0(this + 20, this + 36);
  return 1;
}
