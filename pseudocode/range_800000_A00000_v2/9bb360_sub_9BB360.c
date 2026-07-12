// Function: sub_9BB360
// Address: 0x9bb360
int (__cdecl *__thiscall sub_9BB360(float *this, float a2))(float *, _DWORD)
{
  double v2; // st7
  void (__cdecl *v4)(float *, _DWORD); // eax
  int v5; // edx
  int i; // edi
  int v7; // ecx
  int (__cdecl *result)(float *, _DWORD); // eax
  float v9; // [esp+14h] [ebp-Ch]

  v2 = a2;
  v4 = (void (__cdecl *)(float *, _DWORD))*((_DWORD *)this + 24);
  if ( v4 )
  {
    v4(this, LODWORD(a2));
    v2 = a2;
  }
  v9 = v2;
  (*(void (__thiscall **)(float *, _DWORD))(*(_DWORD *)this + 128))(this, LODWORD(v9));
  *(_QWORD *)(this + 7) = LODWORD(a2);
  *((_DWORD *)this + 12) = (*(int (__thiscall **)(float *))(*(_DWORD *)this + 12))(this);
  (*(void (__thiscall **)(float *))(*(_DWORD *)this + 36))(this);
  (*(void (__thiscall **)(float *))(*(_DWORD *)this + 136))(this);
  v5 = *(_DWORD *)this;
  *(this + 29) = a2;
  (*(void (__thiscall **)(float *, _DWORD *))(v5 + 140))(this, (_DWORD *)this + 26);
  (*(void (__thiscall **)(float *, _DWORD))(*(_DWORD *)this + 132))(this, LODWORD(a2));
  for ( i = 0; i < *((_DWORD *)this + 63); ++i )
  {
    v7 = *(_DWORD *)(*((_DWORD *)this + 65) + 4 * i);
    (*(void (__thiscall **)(int, float *, _DWORD))(*(_DWORD *)v7 + 4))(v7, this, LODWORD(a2));
  }
  sub_9BC740(this, a2);
  result = (int (__cdecl *)(float *, _DWORD))*((_DWORD *)this + 23);
  if ( result )
    return (int (__cdecl *)(float *, _DWORD))result(this, LODWORD(a2));
  return result;
}
