// Function: sub_8950B0
// Address: 0x8950b0
void __thiscall sub_8950B0(void *this)
{
  double v1; // st7
  double v2; // st6
  float *v3; // esi
  float v4; // [esp+8h] [ebp-14h]
  float v5; // [esp+Ch] [ebp-10h]
  float v6; // [esp+Ch] [ebp-10h]
  float v7; // [esp+10h] [ebp-Ch]
  float v8; // [esp+10h] [ebp-Ch]
  float v9; // [esp+18h] [ebp-4h]
  float v10; // [esp+18h] [ebp-4h]
  float v11; // [esp+18h] [ebp-4h]
  float v12; // [esp+18h] [ebp-4h]

  if ( unk_133D6A0 != 1 && unk_133C8FD && (*(_DWORD *)sub_785350(this) & 0x400) != 0 )
  {
    v9 = (float)unk_133F660;
    v7 = v9;
    v10 = (float)unk_133F65C;
    v5 = v10;
    v11 = (float)SLOWORD(flt_133F658);
    v4 = v11;
    v12 = (float)unk_133F654;
    sub_8E8940(v12, v4, v5, v7);
    v1 = 1.0;
    v2 = 0.77999997;
    v3 = (float *)&unk_133F5E8;
    do
    {
      if ( *((_WORD *)v3 - 8) )
      {
        v8 = v1;
        v6 = v2;
        sub_9016B0(0, *((_DWORD *)v3 + 2), *(v3 - 1), *v3, 0, v6, v8);
        v1 = 1.0;
        v2 = 0.77999997;
      }
      v3 += 7;
    }
    while ( (int)v3 < (int)&flt_133F658 );
    sub_8E5CD0();
  }
}
