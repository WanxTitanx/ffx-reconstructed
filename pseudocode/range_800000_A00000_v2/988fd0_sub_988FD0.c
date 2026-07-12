// Function: sub_988FD0
// Address: 0x988fd0
void __thiscall sub_988FD0(int *this)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // ebx
  int v6; // ebx
  int v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // ecx
  bool v10; // zf
  _BYTE v11[4]; // [esp+10h] [ebp-28h] BYREF
  int v12; // [esp+14h] [ebp-24h]
  int v13; // [esp+18h] [ebp-20h]
  _DWORD *v14; // [esp+1Ch] [ebp-1Ch]
  char v15; // [esp+20h] [ebp-18h]
  int v16; // [esp+24h] [ebp-14h]
  _DWORD *v17; // [esp+28h] [ebp-10h]
  int v18; // [esp+34h] [ebp-4h]

  if ( *this )
  {
    v2 = 0;
    v3 = 0;
    v4 = 0;
    v15 = 1;
    v14 = 0;
    v12 = 0;
    v13 = 0;
    v5 = *(this + 3);
    v18 = 0;
    if ( v5 > 0 )
    {
      v2 = sub_9D4CE0(4 * v5, 16);
      v3 = v12;
      v17 = (_DWORD *)v2;
      v4 = v5;
      v15 = 1;
      v14 = (_DWORD *)v2;
      v13 = v5;
    }
    v6 = *this;
    v16 = v6;
    if ( *(_DWORD *)(v6 + 40) )
    {
      sub_988AB0((int)this, *(_DWORD *)(v6 + 36), (int)v11, -2);
      sub_988AB0((int)this, *(_DWORD *)(v6 + 40), (int)v11, -2);
      sub_9D4D50(*(this + 1));
      *(this + 1) = v6;
    }
    else
    {
      if ( v3 == v4 )
      {
        if ( v4 < 1 )
        {
          v7 = sub_9D4CE0(4, 16);
          v3 = v12;
          v17 = (_DWORD *)v7;
          if ( v14 )
          {
            sub_9D4D50(v14);
            v3 = v12;
          }
          v2 = (int)v17;
          v15 = 1;
          v14 = v17;
          v13 = 1;
        }
        v6 = v16;
      }
      v8 = (_DWORD *)(v2 + 4 * v3);
      if ( v8 )
      {
        *v8 = v6;
        v3 = v12;
      }
      v12 = v3 + 1;
    }
    sub_987F10((int)this, (int)v11);
    v9 = v14;
    v10 = v15 == 0;
    *this = *v14;
    v18 = -1;
    if ( !v10 )
      sub_9D4D50(v9);
  }
}
