// Function: sub_A26A20
// Address: 0xa26a20
// Size: 0x1a6
// Prototype: 

int __thiscall sub_A26A20(_DWORD *this, int a2, int a3)
{
  double v3; // st7
  double v4; // st5
  double v5; // st4
  int result; // eax
  int v7; // edi
  int v8; // edi
  float v9; // [esp+0h] [ebp-8h]
  float v10; // [esp+0h] [ebp-8h]
  float v11; // [esp+0h] [ebp-8h]
  float v12; // [esp+0h] [ebp-8h]
  float v13; // [esp+4h] [ebp-4h]
  float v14; // [esp+4h] [ebp-4h]

  v13 = (float)a2;
  v9 = v13;
  v14 = (float)a3;
  v3 = v9;
  v10 = v9 / v14;
  v4 = v10;
  v5 = flt_C6B270;
  if ( flt_C6B270 == v10 )
  {
    result = a3;
    if ( *(this + 6)
      || *(this + 7)
      || *(this + 8) != a2
      || *(this + 9) != a3
      || *(this + 10) != a2
      || *(this + 11) != a3 )
    {
      *(this + 8) = a2;
      *(this + 10) = a2;
      *(this + 6) = 0;
      *(this + 7) = 0;
      *(this + 9) = a3;
      *(this + 11) = a3;
      return sub_A265A0(this);
    }
  }
  else if ( v5 <= v4 )
  {
    v12 = v5 * (1.0 / v4);
    v8 = (int)((1.0 - v12) * v3 * 0.5);
    result = (int)(v3 * v12);
    if ( *(this + 6) != v8
      || *(this + 7)
      || *(this + 8) != result
      || *(this + 9) != a3
      || *(this + 10) != a2
      || *(this + 11) != a3 )
    {
      *(this + 9) = a3;
      *(this + 11) = a3;
      *(this + 6) = v8;
      *(this + 7) = 0;
      *(this + 8) = result;
      *(this + 10) = a2;
      return sub_A265A0(this);
    }
  }
  else
  {
    v11 = v4 * 0.5625;
    v7 = (int)((1.0 - v11) * v14 * 0.5);
    result = (int)(v14 * v11);
    if ( *(this + 6)
      || *(this + 7) != v7
      || *(this + 8) != a2
      || *(this + 9) != result
      || *(this + 10) != a2
      || *(this + 11) != a3 )
    {
      *(this + 8) = a2;
      *(this + 10) = a2;
      *(this + 6) = 0;
      *(this + 7) = v7;
      *(this + 9) = result;
      *(this + 11) = a3;
      return sub_A265A0(this);
    }
  }
  return result;
}

