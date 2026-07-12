// Function: sub_993000
// Address: 0x993000
int __thiscall sub_993000(int this, int a2, float *a3, float *a4)
{
  int result; // eax
  int v6; // ebx
  int v7; // edi
  int v8; // edx
  _WORD *v9; // ecx

  if ( *(_BYTE *)(this + 72) )
  {
    sub_990330(this, a3, a4, 1.0);
    result = sub_993300(a2, 0, *(_DWORD *)(this + 68), 0);
    v6 = 0;
    if ( *(int *)(this + 164) > 0 )
    {
      v7 = 0;
      do
      {
        v8 = v7 + *(_DWORD *)(this + 172);
        ++v6;
        v9 = (_WORD *)(*(_DWORD *)(this + 148) + 16 * *(_DWORD *)(v8 + 12));
        v7 += 32;
        *(_WORD *)v8 = *v9;
        *(_WORD *)(v8 + 2) = v9[1];
        *(_WORD *)(v8 + 4) = v9[2];
        *(_WORD *)(v8 + 6) = v9[3];
        *(_WORD *)(v8 + 8) = v9[4];
        result = (unsigned __int16)v9[5];
        *(_WORD *)(v8 + 10) = result;
      }
      while ( v6 < *(_DWORD *)(this + 164) );
    }
  }
  return result;
}
