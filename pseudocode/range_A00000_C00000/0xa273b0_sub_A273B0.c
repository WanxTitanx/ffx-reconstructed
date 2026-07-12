// Function: sub_A273B0
// Address: 0xa273b0
// Size: 0x29c
// Prototype: 

char __thiscall sub_A273B0(int *this)
{
  int *this_1; // esi
  int v2; // ebx
  _DWORD *v3; // edi
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  int *this_3; // ecx
  int v8; // eax
  int v9; // esi
  int *this_4; // ebx
  double v11; // st7
  int v12; // ecx
  unsigned int v13; // edi
  int v14; // eax
  int v15; // esi
  int v16; // ecx
  double v17; // st7
  double v18; // st7
  double v19; // st6
  _DWORD *v20; // edi
  int (__cdecl *v22)(int); // [esp-8h] [ebp-B0h]
  int (__cdecl *v23)(int); // [esp-4h] [ebp-ACh]
  _DWORD v24[34]; // [esp+Ch] [ebp-9Ch] BYREF
  int v25; // [esp+94h] [ebp-14h] BYREF
  __int64 v26; // [esp+98h] [ebp-10h]
  int *this_2; // [esp+A0h] [ebp-8h]
  char v28; // [esp+A7h] [ebp-1h]

  this_1 = this;
  this_2 = this;
  v28 = 0;
  sub_42E1D0(off_C6B28C, off_C6B290[0], off_C6B294, off_C6B298[0]);
  v2 = (int)(this_1 + 96);
  sub_A8FFD0(this_1 + 96);
  v3 = this_1 + 104;
  sub_A90420(this_1 + 104);
  v25 = 0;
  v4 = sub_427B80(&v25) + 3;
  v5 = v25;
  this_1[90] = 1;
  this_1[91] = 0;
  this_1[94] = 0;
  this_1[95] = 0;
  this_1[92] = 0;
  this_1[93] = 0;
  this_1[89] = v5;
  this_1 += 88;
  *this_1 = v4;
  v6 = sub_A8F650(v2, v3, this_1);
  this_3 = this_2;
  *this_1 += v6;
  this_3[89] -= v6;
  v8 = sub_A8F650(v2, v3, this_1) + 4;
  this_2[89] -= v8;
  *this_1 += v8;
  sub_A8F650(v2, v3, this_1);
  v9 = (int)(this_2 + 108);
  if ( !sub_A910E0(this_2 + 108, v2) )
  {
    this_4 = this_2;
    if ( !sub_A921B0(v9, this_2 + 136) )
    {
      v11 = sub_429170(this_4[165]);
      v12 = this_4[165];
      v26 = (__int64)v11;
      v13 = (__int64)v11;
      v14 = sub_429180(v12);
      v23 = off_C6B2A0;
      v15 = v14;
      v22 = off_C6B29C[0];
      this_4[169] = 4096;
      sub_A3DDF0(0x100000, v14 << 13, v22, v23);
      memset(v24, 0, sizeof(v24));
      v16 = this_4[68];
      v24[0] = 136;
      v24[6] = 4096;
      *(double *)&v26 = (double)sub_425200(v16);
      v17 = *(double *)&v26 * 0.000000001;
      *(double *)&v26 = (double)v13;
      v18 = v17 * *(double *)&v26;
      HIDWORD(v26) = 2 * v15;
      v19 = (double)(2 * v15);
      if ( (v15 & 0x40000000) != 0 )
        v19 = v19 + 4294967296.0;
      v24[4] = v13;
      v20 = this_4 + 167;
      v24[3] = v15;
      v24[5] = 2;
      v24[11] = sub_A27EE0;
      v26 = (__int64)(v18 * v19);
      v24[1] = v26;
      if ( FMOD::System::createSound(this_4[166], 0, 1224, v24, this_4 + 167) )
      {
        sub_A3DF20(this_4 + 32);
      }
      else
      {
        FMOD::Sound::setUserData(*v20, this_4);
        if ( !FMOD::System::playSound(this_4[166], -1, *v20, 0, this_4 + 168) )
        {
          FMOD::Channel::setPriority(this_4[168], 0);
          return 1;
        }
      }
    }
  }
  return v28;
}

