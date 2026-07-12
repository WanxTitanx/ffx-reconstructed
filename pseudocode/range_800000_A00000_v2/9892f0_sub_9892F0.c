// Function: sub_9892F0
// Address: 0x9892f0
void __thiscall sub_9892F0(int *this, int a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // ebx
  int v7; // ebx
  int v8; // eax
  int *v9; // eax
  char v10[4]; // [esp+10h] [ebp-28h] BYREF
  int v11; // [esp+14h] [ebp-24h]
  int v12; // [esp+18h] [ebp-20h]
  int v13; // [esp+1Ch] [ebp-1Ch]
  char v14; // [esp+20h] [ebp-18h]
  int v15; // [esp+24h] [ebp-14h]
  int v16; // [esp+28h] [ebp-10h]
  int v17; // [esp+34h] [ebp-4h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  if ( *this )
  {
    v3 = 0;
    v4 = 0;
    v5 = 0;
    v14 = 1;
    v13 = 0;
    v11 = 0;
    v12 = 0;
    v6 = *(this + 3);
    v17 = 0;
    if ( v6 > 0 )
    {
      v3 = sub_9D4CE0(4 * v6, 16);
      v4 = v11;
      v16 = v3;
      v5 = v6;
      v14 = 1;
      v13 = v3;
      v12 = v6;
    }
    v7 = *this;
    v15 = v7;
    if ( *(_DWORD *)(v7 + 40) )
    {
      sub_988AB0((int)this, *(_DWORD *)(v7 + 36), (int)v10, -2);
      sub_988AB0((int)this, *(_DWORD *)(v7 + 40), (int)v10, -2);
      sub_9D4D50(*(this + 1));
      *(this + 1) = v7;
    }
    else
    {
      if ( v4 == v5 )
      {
        if ( v5 < 1 )
        {
          v8 = sub_9D4CE0(4, 16);
          v4 = v11;
          v16 = v8;
          if ( v13 )
          {
            sub_9D4D50(v13);
            v4 = v11;
          }
          v3 = v16;
          v14 = 1;
          v13 = v16;
          v12 = 1;
        }
        v7 = v15;
      }
      v9 = (int *)(v3 + 4 * v4);
      if ( v9 )
      {
        *v9 = v7;
        v4 = v11;
      }
      v11 = v4 + 1;
    }
    *this = sub_98A060((int)&savedregs, (int)this, (int)v10, a2);
    v17 = -1;
    if ( v13 )
    {
      if ( v14 )
        sub_9D4D50(v13);
    }
  }
}
