// Function: sub_A20CD0
// Address: 0xa20cd0
// Size: 0x2fa
// Prototype: 

int __thiscall sub_A20CD0(int this, int a2, int a3)
{
  int result; // eax
  int v5; // ecx
  int v6; // eax
  bool v7; // zf
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // esi
  unsigned int v16; // edi
  int v17; // eax
  _BYTE dst[64]; // [esp+20h] [ebp-C8h] BYREF
  _BYTE src[64]; // [esp+60h] [ebp-88h] BYREF
  _BYTE v20[16]; // [esp+A0h] [ebp-48h] BYREF
  _BYTE v21[16]; // [esp+B0h] [ebp-38h] BYREF
  float v22; // [esp+C0h] [ebp-28h]
  int Src; // [esp+C4h] [ebp-24h] BYREF
  int v24; // [esp+C8h] [ebp-20h]
  int v25; // [esp+CCh] [ebp-1Ch]
  int v26; // [esp+D0h] [ebp-18h]
  float v27; // [esp+D4h] [ebp-14h]
  float v28; // [esp+D8h] [ebp-10h]
  int v29; // [esp+E4h] [ebp-4h]
  float v30; // [esp+F4h] [ebp+Ch]
  int v31; // [esp+F4h] [ebp+Ch]

  if ( *(_DWORD *)(this + 16084) != 1 )
    return 20;
  if ( !*(_DWORD *)(this + 16280) )
    return 20;
  v28 = *(float *)(this + 16276);
  if ( v28 == 0.0 )
    return 20;
  v27 = *(float *)(this + 16284);
  if ( v27 == 0.0 )
    return 20;
  sub_451160(a3);
  qmemcpy(dst, src, sizeof(dst));
  sub_573E70(src, dst);
  v5 = *(_DWORD *)(this + 16216);
  if ( !v5 )
    goto LABEL_36;
  v6 = *(_DWORD *)(this + 16324);
  Src = 66;
  v7 = *(_BYTE *)(v6 + 4) == 0;
  v24 = 0;
  v8 = v7 ? *(_DWORD *)v6 : 0;
  v26 = v8;
  v25 = this + 16104;
  result = sub_56E7E0(v5, &Src);
  if ( !result )
  {
LABEL_36:
    v9 = *(_DWORD *)(this + 16212);
    if ( !v9 )
      goto LABEL_37;
    v10 = *(_DWORD *)(this + 16316);
    Src = 66;
    v7 = *(_BYTE *)(v10 + 4) == 0;
    v24 = 0;
    v11 = v7 ? *(_DWORD *)v10 : 0;
    v26 = v11;
    v25 = this + 16104;
    result = sub_56E7E0(v9, &Src);
    if ( !result )
    {
LABEL_37:
      v12 = *(_DWORD *)(this + 16352);
      if ( !v12 )
        goto LABEL_21;
      v13 = *(_DWORD *)(this + 16304);
      Src = 66;
      v7 = *(_BYTE *)(v13 + 4) == 0;
      v24 = 0;
      v14 = v7 ? *(_DWORD *)v13 : 0;
      v26 = v14;
      v25 = this + 16104;
      result = sub_56E7E0(v12, &Src);
      if ( !result )
      {
LABEL_21:
        sub_5B3760(LODWORD(v28), 0);
        v29 = 0;
        sub_5B3760(LODWORD(v27), 0);
        LOBYTE(v29) = 1;
        v15 = sub_5BB2D0(v21, 0);
        if ( !v15 )
        {
          v15 = sub_5BB750(v20);
          if ( !v15 )
          {
            v30 = *(float *)(this + 16028);
            v27 = *(float *)(this + 16024);
            v28 = *(float *)(this + 16020);
            v22 = *(float *)(this + 16016);
            v15 = sub_5BAF40(v22, v28, v27, v30);
            if ( !v15 )
            {
              v15 = sub_5B5FD0(1);
              if ( !v15 )
              {
                v15 = sub_A206D0(a2, this + 15892);
                if ( !v15 )
                {
                  v16 = 0;
                  if ( *(_DWORD *)(this + 16080) )
                  {
                    v17 = this + 20;
                    v31 = this + 20;
                    while ( 1 )
                    {
                      v15 = sub_A206D0(a2, v17);
                      if ( v15 )
                        break;
                      ++v16;
                      v17 = v31 + 124;
                      v31 += 124;
                      if ( v16 >= *(_DWORD *)(this + 16080) )
                        goto LABEL_30;
                    }
                  }
                  else
                  {
LABEL_30:
                    v15 = sub_5B6AF0(1);
                    if ( !v15 )
                    {
                      v15 = sub_5BB2D0(0, 0);
                      if ( !v15 )
                        v15 = sub_5BB750(0);
                    }
                  }
                }
              }
            }
          }
        }
        LOBYTE(v29) = 0;
        nullsub_24(v20);
        v29 = -1;
        nullsub_24(v21);
        return v15;
      }
    }
  }
  return result;
}

