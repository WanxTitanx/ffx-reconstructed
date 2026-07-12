// Function: sub_9BB5F0
// Address: 0x9bb5f0
void __thiscall sub_9BB5F0(_DWORD *this, float a2)
{
  int v3; // esi
  double v4; // st7
  int v5; // eax
  int v6; // edi
  float v7; // [esp+4h] [ebp-10h]

  v3 = 0;
  if ( (int)*(this + 52) > 0 )
  {
    v4 = a2;
    do
    {
      v5 = *(this + 54);
      v6 = *(_DWORD *)(v5 + 4 * v3);
      if ( (*(_BYTE *)(v6 + 216) & 3) == 0 )
      {
        v7 = v4;
        sub_9B5000(*(_DWORD *)(v5 + 4 * v3), v7);
        sub_9B4960(v6, a2);
        sub_9B5340((float *)v6, a2, v6 + 80);
        v4 = a2;
      }
      ++v3;
    }
    while ( v3 < *(this + 52) );
  }
}
