// Function: sub_98B7E0
// Address: 0x98b7e0
int __thiscall sub_98B7E0(int this, int a2, int a3, int a4)
{
  int result; // eax
  float v6; // [esp+8h] [ebp+8h]
  float v7; // [esp+8h] [ebp+8h]
  float v8; // [esp+8h] [ebp+8h]

  v6 = *(float *)(a2 + 4) * *(float *)(this + 116)
     + *(float *)(this + 112) * *(float *)a2
     + *(float *)(a2 + 8) * *(float *)(this + 120);
  if ( v6 > (double)*(float *)(this + 96) )
  {
    *(float *)(this + 96) = v6;
    *(_DWORD *)(this + 16) = *(_DWORD *)a2;
    *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 8);
    result = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(this + 28) = result;
  }
  v7 = *(float *)(a2 + 20) * *(float *)(this + 116)
     + *(float *)(this + 112) * *(float *)(a2 + 16)
     + *(float *)(a2 + 24) * *(float *)(this + 120);
  if ( v7 > (double)*(float *)(this + 96) )
  {
    *(float *)(this + 96) = v7;
    *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
    result = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(this + 28) = result;
  }
  v8 = *(float *)(a2 + 36) * *(float *)(this + 116)
     + *(float *)(this + 112) * *(float *)(a2 + 32)
     + *(float *)(a2 + 40) * *(float *)(this + 120);
  if ( v8 > (double)*(float *)(this + 96) )
  {
    *(float *)(this + 96) = v8;
    *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 40);
    result = *(_DWORD *)(a2 + 44);
    *(_DWORD *)(this + 28) = result;
  }
  return result;
}
