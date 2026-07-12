// Function: sub_991930
// Address: 0x991930
int __thiscall sub_991930(_DWORD *this, int a2, float *a3, float *a4)
{
  int v5; // esi
  int v6; // ecx
  int v7; // edi
  unsigned __int8 v8; // cl
  int v9; // ebx
  bool v10; // al
  int v11; // ecx
  int result; // eax
  _DWORD *this_1; // [esp+8h] [ebp-Ch]
  int v14; // [esp+Ch] [ebp-8h]
  bool v15; // [esp+13h] [ebp-1h]

  v5 = *(this + 27);
  v6 = 0;
  v7 = 0;
  this_1 = this;
  while ( v7 < this_1[17] )
  {
    v14 = v6 + 1;
    v8 = 1;
    if ( *a3 > (double)*(float *)(v5 + 16) || *(float *)v5 > (double)*a4 )
      v8 = 0;
    if ( a3[2] > (double)*(float *)(v5 + 24) || *(float *)(v5 + 8) > (double)a4[2] )
      v8 = 0;
    if ( a3[1] > (double)*(float *)(v5 + 20) || *(float *)(v5 + 4) > (double)a4[1] )
      v8 = 0;
    v9 = v8;
    v10 = *(_DWORD *)(v5 + 32) == -1;
    v15 = v10;
    if ( *(_DWORD *)(v5 + 32) == -1 )
    {
      if ( !v8 )
        goto LABEL_15;
      (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)a2 + 4))(a2, *(_DWORD *)(v5 + 36), *(_DWORD *)(v5 + 40));
      v10 = v15;
    }
    if ( v9 )
      goto LABEL_17;
LABEL_15:
    if ( v10 )
    {
LABEL_17:
      v5 += 64;
      ++v7;
      goto LABEL_18;
    }
    v11 = *(_DWORD *)(v5 + 32);
    v5 += v11 << 6;
    v7 += v11;
LABEL_18:
    v6 = v14;
  }
  result = dword_193F244;
  if ( dword_193F244 < v6 )
    result = v6;
  dword_193F244 = result;
  return result;
}
