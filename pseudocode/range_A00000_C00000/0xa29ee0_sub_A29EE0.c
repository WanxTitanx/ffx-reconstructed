// Function: sub_A29EE0
// Address: 0xa29ee0
// Size: 0x1fb
// Prototype: 

int __userpurge sub_A29EE0@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4, int a5)
{
  int v6; // eax
  int result; // eax
  float v8; // edx
  int v9; // edi
  bool v10; // al
  bool v11; // al
  void *v12; // eax
  int v13; // eax
  _DWORD *p_Size; // edi
  int v15; // eax
  int v16; // eax
  int v17; // eax
  unsigned int v18; // eax
  int v19; // ecx
  _DWORD *v20; // esi
  _DWORD v22[3]; // [esp+4h] [ebp-20h] BYREF
  int v23; // [esp+10h] [ebp-14h]
  float Src; // [esp+14h] [ebp-10h] BYREF
  float v25; // [esp+18h] [ebp-Ch]
  float v26; // [esp+1Ch] [ebp-8h]
  void *v27; // [esp+20h] [ebp-4h]

  v6 = sub_A3E9B0(a5);
  a1[13] = v6;
  if ( !v6 )
    return 7;
  LODWORD(v8) = a4 + 28 != *(_DWORD *)(a4 + 28) ? *(_DWORD *)(a4 + 28) : 0;
  memset(v22, 0, sizeof(v22));
  v23 = 0;
  Src = 0.0;
  LODWORD(v25) = a4 + 28;
  v26 = v8;
  v27 = &unk_CA5268;
  sub_65EE30(v22);
  if ( !v23 )
    return 7;
  v9 = v22[0] + LODWORD(Src);
  if ( !(v22[0] + LODWORD(Src)) )
    return 0;
  v10 = (a1[10] & 0x80) != 0;
  if ( (a1[10] & 0x80) == 0 )
    *((_BYTE *)a1 + 12) = 5;
  if ( !v10 )
    *((_BYTE *)a1 + 13) = 1;
  v11 = (a1[10] & 0x80) != 0;
  if ( (a1[10] & 0x80) == 0 )
    *((_BYTE *)a1 + 14) = 2;
  if ( !v11 )
    *((_BYTE *)a1 + 15) = 2;
  if ( (a1[10] & 0x80) == 0 )
    *((_BYTE *)a1 + 16) = 2;
  result = sub_58D110(a2, a3);
  if ( !result )
  {
    v25 = 0.0;
    v12 = *(void **)(a1[12] + 32);
    LODWORD(Src) = 66;
    v27 = v12;
    LODWORD(v26) = a1 + 3;
    v13 = sub_56CD50("BitmapFontTexture");
    p_Size = *(_DWORD **)(v9 + 4);
    if ( !v13 || (result = sub_56E7E0(v13, &Src)) == 0 )
    {
      v15 = sub_56CD50("LinearClampSampler");
      if ( !v15 || (result = sub_56E770(v15, a1 + 3)) == 0 )
      {
        v16 = sub_4E6BA0(a4, 0, 0);
        *a1 = v16;
        if ( !v16 )
          return 14;
        Src = 1.0;
        v25 = 1.0;
        v26 = 1.0;
        result = sub_A2A650(&Src);
        if ( !result )
        {
          memcpy(*(void **)(*a1 + 4), p_Size, *p_Size);
          v17 = a1[1];
          if ( v17 == 1 )
            goto LABEL_34;
          v18 = v17 & 0x7FFFFFFF;
          if ( v18 <= 1 )
          {
            if ( v18 )
              v19 = (int)(a1 + 2);
            else
              v19 = 0;
          }
          else
          {
            v19 = a1[2];
          }
          v20 = a1 + 2;
          if ( a1 != (_DWORD *)-8 )
          {
            *v20 = 0;
            if ( (_DWORD *)v19 != v20 && (int)a1[1] >= 0 )
              Phyre_Memory_AlignedFree(v19);
            a1[1] = 1;
LABEL_34:
            result = sub_48C610(0, *a1);
            if ( result )
              return result;
            return 0;
          }
          return 13;
        }
      }
    }
  }
  return result;
}

