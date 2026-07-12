// Function: sub_998C20
// Address: 0x998c20
unsigned int __thiscall sub_998C20(int this, int a2, int a3, int a4, int a5)
{
  int v5; // ebx
  int v7; // ecx
  _DWORD *v8; // edx
  unsigned int n8; // eax
  int v10; // eax
  int v11; // ecx
  _DWORD *v12; // [esp+18h] [ebp-8h]
  float v13; // [esp+28h] [ebp+8h]
  int v14; // [esp+2Ch] [ebp+Ch]

  v5 = a3;
  v7 = a2;
  if ( *(_BYTE *)(this + 8) )
  {
    v7 = a3;
    v5 = a2;
  }
  v8 = *(_DWORD **)(v5 + 204);
  v14 = v7;
  n8 = v8[1] - 21;
  v12 = v8;
  if ( n8 <= 8 )
  {
    n8 = *(_DWORD *)(v7 + 204);
    if ( *(int *)(n8 + 4) < 20 )
    {
      v13 = ((double (__thiscall *)(_DWORD *))*(_DWORD *)(*v8 + 40))(v8);
      *(_DWORD *)(a5 + 4) = *(_DWORD *)(this + 84);
      sub_999840(LODWORD(v13), a4, a5);
      v10 = *(_DWORD *)(this + 84);
      *(_DWORD *)(v10 + 1172) = v5;
      *(_DWORD *)(v10 + 1168) = v14;
      n8 = (*(int (__thiscall **)(_DWORD *, int, int, int))(*v12 + 56))(v12, this + 16, this + 32, this + 48);
      v11 = *(_DWORD *)(a5 + 4);
      if ( *(_DWORD *)(v11 + 1176) )
      {
        if ( *(_DWORD *)(v11 + 1168) == *(_DWORD *)(a5 + 144) )
          return sub_9A4470(a5 + 16, a5 + 80);
        else
          return sub_9A4470(a5 + 80, a5 + 16);
      }
    }
  }
  return n8;
}
