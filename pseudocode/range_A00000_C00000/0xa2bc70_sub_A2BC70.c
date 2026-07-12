// Function: sub_A2BC70
// Address: 0xa2bc70
// Size: 0x71
// Prototype: 

int *__thiscall sub_A2BC70(int *this, int *a2)
{
  int v2; // esi
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // ecx
  int v9; // [esp+14h] [ebp+8h]

  v2 = *a2;
  v9 = a2[1];
  v4 = 0;
  v5 = v2 & 0x7FFFFFFF;
  if ( v5 )
  {
    v6 = sub_42FC60(48 * v5, 4);
    v4 = v6;
    if ( v6 )
      sub_A2ADC0(v6, v9, v5);
  }
  v7 = *(this + 1);
  if ( v7 != v4 && *this >= 0 && v7 )
    Phyre_Memory_AlignedFree(*(this + 1));
  *(this + 1) = v4;
  *this = v5;
  return this;
}

