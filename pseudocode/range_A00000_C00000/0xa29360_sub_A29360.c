// Function: sub_A29360
// Address: 0xa29360
// Size: 0x23d
// Prototype: 

_DWORD *__thiscall sub_A29360(_DWORD *this, int a2, char a3)
{
  _DWORD *v4; // esi
  _DWORD *v5; // edx
  bool v6; // zf
  int v7; // ebx
  unsigned int j; // esi
  int v9; // ebx
  unsigned int i; // esi
  int v11; // eax
  int v13; // [esp+0h] [ebp-68h]
  int v14; // [esp+4h] [ebp-64h]
  float v15[16]; // [esp+10h] [ebp-58h] BYREF
  int v16; // [esp+50h] [ebp-18h]
  int v17; // [esp+54h] [ebp-14h]
  _DWORD *this_1; // [esp+58h] [ebp-10h]
  int v19; // [esp+64h] [ebp-4h]

  this_1 = this;
  sub_433800();
  v19 = 1;
  sub_4338D0();
  v4 = this + 41;
  sub_4F2940(this);
  v15[0] = 1.0;
  v15[1] = 0.0;
  v15[2] = 0.0;
  v15[3] = 0.0;
  v15[4] = 0.0;
  v15[6] = 0.0;
  v15[7] = 0.0;
  v15[8] = 0.0;
  v15[9] = 0.0;
  v15[11] = 0.0;
  v15[12] = 0.0;
  v15[13] = 0.0;
  v15[14] = 0.0;
  v15[5] = 1.0;
  v15[10] = 1.0;
  v15[15] = 1.0;
  sub_451270(v15);
  *(this + 86) = a2;
  *(this + 87) = 0;
  *(this + 88) = 0;
  *((float *)this + 90) = 0.0;
  *((float *)this + 91) = 0.0;
  *(this + 89) = 0;
  *((_BYTE *)this + 372) = a3;
  *((float *)this + 92) = 0.64999998;
  LOBYTE(v19) = 3;
  *((float *)this + 94) = 1.0;
  *((float *)this + 95) = 1.0;
  *((float *)this + 96) = 1.0;
  *((float *)this + 97) = 1.0;
  *((float *)this + 98) = 1.0;
  *((float *)this + 99) = 1.0;
  *((float *)this + 100) = 1.0;
  *((float *)this + 101) = 1.0;
  v5 = (_DWORD *)*(this + 1);
  if ( v5 != this + 14 && (int)*this >= 0 )
    sub_434310(v5, *this & 0x7FFFFFFF);
  *(this + 1) = this + 14;
  *this = -2147483647;
  v6 = *((_BYTE *)this + 372) == 0;
  *(this + 18) = 2;
  if ( v6 )
  {
    if ( *(this + 24) != 2 )
    {
      v9 = sub_42FC60(128, 4);
      v16 = v9;
      if ( v9 )
      {
        for ( i = 0; i < 2; ++i )
        {
          v17 = v9 + (i << 6);
          LOBYTE(v19) = 5;
          if ( v17 )
            sub_55DDC0(v13, v14);
          LOBYTE(v19) = 3;
        }
        sub_434F40(v9, 2);
        goto LABEL_19;
      }
    }
  }
  else if ( *(this + 24) != 3 )
  {
    v7 = sub_42FC60(192, 4);
    v17 = v7;
    if ( v7 )
    {
      for ( j = 0; j < 3; ++j )
      {
        v16 = v7 + (j << 6);
        LOBYTE(v19) = 4;
        if ( v16 )
          sub_55DDC0(v13, v14);
        LOBYTE(v19) = 3;
      }
      sub_434F40(v7, 3);
LABEL_19:
      v4 = this + 41;
    }
  }
  sub_4F8D00(this);
  v11 = a2 + 4;
  if ( a2 == -4 )
    v11 = *v4 + 48;
  v4[4] = v11;
  *(this + 42) = this + 74;
  return this;
}

