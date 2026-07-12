// Function: sub_A2D9E0
// Address: 0xa2d9e0
// Size: 0xb4
// Prototype: 

int __thiscall sub_A2D9E0(int *this, unsigned int a2)
{
  unsigned int v4; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int v10; // ecx
  int v11; // [esp+Ch] [ebp-4h]
  int v12; // [esp+18h] [ebp+8h]

  v4 = *this & 0x7FFFFFFF;
  if ( a2 != *this )
  {
    if ( a2 < v4 )
      v4 = a2;
    v11 = *(this + 1);
    if ( a2 )
    {
      v5 = sub_42FC60(48 * a2, 4);
      v12 = v5;
      if ( !v5 )
        return 13;
      sub_A2ADC0(v5, v11, v4);
      v6 = a2 - v4;
      v7 = 3 * v4;
      v8 = v12;
      sub_A2D1A0(v12 + 16 * v7, v6);
    }
    else
    {
      v8 = 0;
    }
    v10 = *(this + 1);
    if ( v10 != v8 && *this >= 0 )
    {
      if ( v10 )
        Phyre_Memory_AlignedFree(*(this + 1));
    }
    *(this + 1) = v8;
    *this = a2;
  }
  return 0;
}

