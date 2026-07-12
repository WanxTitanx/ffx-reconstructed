// Function: sub_9BC3C0
// Address: 0x9bc3c0
int __thiscall sub_9BC3C0(float *this, float a2, int a3, float a4)
{
  int v4; // ebx
  double v6; // st7
  int v7; // eax
  int v8; // eax
  int v9; // edi
  float v11; // [esp+1Ch] [ebp+8h]
  float v12; // [esp+1Ch] [ebp+8h]
  float v13; // [esp+20h] [ebp+Ch]
  float v14; // [esp+20h] [ebp+Ch]
  float v15; // [esp+20h] [ebp+Ch]

  v4 = 0;
  if ( a3 )
  {
    v11 = *(this + 60) + a2;
    *(this + 60) = v11;
    v6 = a4;
    if ( v11 >= (double)a4 )
    {
      v4 = (int)(v11 / v6);
      v12 = (float)v4;
      *(this + 60) = *(this + 60) - v6 * v12;
    }
  }
  else
  {
    a4 = a2;
    v13 = fabs(a2);
    *(this + 60) = a2;
    if ( v13 >= 0.00000011920929 )
    {
      v4 = 1;
      a3 = 1;
    }
    else
    {
      v4 = 0;
      a3 = 0;
    }
  }
  if ( (*(int (__thiscall **)(float *))(*(_DWORD *)this + 12))(this) )
  {
    v7 = (*(int (__thiscall **)(float *))(*(_DWORD *)this + 12))(this);
    unk_193F658 = ((*(int (__thiscall **)(int))(*(_DWORD *)v7 + 44))(v7) & 0x10) != 0;
  }
  v8 = *(_DWORD *)this;
  if ( v4 )
  {
    v9 = v4;
    if ( v4 > a3 )
      v9 = a3;
    v14 = (float)v9;
    v15 = v14 * a4;
    (*(void (__thiscall **)(float *, _DWORD))(v8 + 148))(this, LODWORD(v15));
    (*(void (__thiscall **)(float *))(*(_DWORD *)this + 156))(this);
    if ( v9 > 0 )
    {
      do
      {
        (*(void (__thiscall **)(float *, _DWORD))(*(_DWORD *)this + 144))(this, LODWORD(a4));
        (*(void (__thiscall **)(float *))(*(_DWORD *)this + 72))(this);
        --v9;
      }
      while ( v9 );
    }
  }
  else
  {
    (*(void (__thiscall **)(float *))(v8 + 72))(this);
  }
  (*(void (__thiscall **)(float *))(*(_DWORD *)this + 108))(this);
  return v4;
}
