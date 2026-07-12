// Function: sub_A4F630
// Address: 0xa4f630
// Size: 0x2f4
// Prototype: 

int __cdecl sub_A4F630(__int16 *a1, int a2, int a3, int a4, int a5)
{
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int result; // eax
  int v9; // ecx
  double v10; // st7
  double v11; // st7
  double v12; // st6
  int v13; // esi
  int v14; // eax
  char v15; // [esp-18h] [ebp-1D4h]
  int v16; // [esp+10h] [ebp-1ACh]
  int ItemCount; // [esp+14h] [ebp-1A8h]
  int v18; // [esp+18h] [ebp-1A4h]
  float v19; // [esp+18h] [ebp-1A4h]
  float v20; // [esp+1Ch] [ebp-1A0h]
  int v21; // [esp+1Ch] [ebp-1A0h]
  float v22; // [esp+1Ch] [ebp-1A0h]
  int v23; // [esp+1Ch] [ebp-1A0h]
  float v24; // [esp+1Ch] [ebp-1A0h]
  int v25[3]; // [esp+20h] [ebp-19Ch] BYREF
  float v26; // [esp+2Ch] [ebp-190h]
  int n128; // [esp+30h] [ebp-18Ch]
  int n128_1; // [esp+34h] [ebp-188h]
  int n128_2; // [esp+38h] [ebp-184h]
  int n128_3; // [esp+3Ch] [ebp-180h]
  float v31; // [esp+40h] [ebp-17Ch]
  float v32; // [esp+44h] [ebp-178h]
  float v33; // [esp+48h] [ebp-174h]
  float v34; // [esp+4Ch] [ebp-170h]
  int n128_4; // [esp+50h] [ebp-16Ch]
  int n128_5; // [esp+54h] [ebp-168h]
  int n128_6; // [esp+58h] [ebp-164h]
  int n128_7; // [esp+5Ch] [ebp-160h]
  float v39; // [esp+60h] [ebp-15Ch]
  float v40; // [esp+64h] [ebp-158h]
  float v41; // [esp+68h] [ebp-154h]
  float v42; // [esp+6Ch] [ebp-150h]
  int n128_8; // [esp+70h] [ebp-14Ch]
  int n128_9; // [esp+74h] [ebp-148h]
  int n128_10; // [esp+78h] [ebp-144h]
  int n128_11; // [esp+7Ch] [ebp-140h]
  float v47; // [esp+80h] [ebp-13Ch]
  float v48; // [esp+84h] [ebp-138h]
  float v49; // [esp+88h] [ebp-134h]
  float v50; // [esp+8Ch] [ebp-130h]
  int n128_12; // [esp+90h] [ebp-12Ch]
  int n128_13; // [esp+94h] [ebp-128h]
  int n128_14; // [esp+98h] [ebp-124h]
  int n128_15; // [esp+9Ch] [ebp-120h]
  char Str[256]; // [esp+B8h] [ebp-104h] BYREF

  v16 = (unsigned __int16)*(_DWORD *)(a2 + 8);
  ItemCount = FFX_Inventory_GetItemCount(v16);
  v5 = a1[16];
  n128 = 128;
  n128_1 = 128;
  n128_2 = 128;
  n128_3 = 128;
  n128_4 = 128;
  n128_5 = 128;
  n128_6 = 128;
  n128_7 = 128;
  n128_8 = 128;
  n128_9 = 128;
  n128_10 = 128;
  n128_11 = 128;
  n128_12 = 128;
  n128_13 = 128;
  n128_14 = 128;
  n128_15 = 128;
  v20 = (float)(a4 - v5);
  v6 = a5 - 2;
  v7 = a1[6] - v5;
  *(float *)v25 = v20;
  v31 = v20;
  v18 = a5 - 2;
  v21 = a4 + v7;
  result = a5 + 18;
  v22 = (float)v21;
  v9 = a1[5] - 1;
  v10 = v22;
  v23 = a5 + 18;
  v39 = v10;
  v47 = v10;
  if ( a5 + 18 > v9 )
  {
    result = a1[5] - 3 + a1[7];
    if ( v6 < result )
    {
      if ( v6 >= v9 )
      {
        if ( a5 + 18 > result )
          v23 = a1[5] - 3 + a1[7];
      }
      else
      {
        v18 = v9;
      }
      v19 = (float)v18;
      *(float *)&v25[1] = v19;
      v24 = (float)v23;
      v32 = v24;
      v48 = v24;
      v40 = v19;
      *(float *)&v25[2] = 0.35742188;
      if ( a3 % 2 )
      {
        v26 = 0.32910156;
        v11 = 0.32910156;
        v33 = 0.35742188;
        v12 = 0.37402344;
      }
      else
      {
        v26 = 0.25097656;
        v11 = 0.25097656;
        v33 = 0.35742188;
        v12 = 0.29589844;
      }
      v34 = v12;
      v41 = 0.64746094;
      v49 = 0.64746094;
      v42 = v11;
      v50 = v12;
      sub_63EAE0((int)v25, Str, 6);
      v13 = a5 - 1;
      if ( *(_BYTE *)(a2 + 4) )
      {
        v14 = sub_8F0700(unk_230FD2C + 16, v16, a4, v13, 1);
        v15 = 1;
      }
      else
      {
        v14 = sub_8F0700(unk_230FD2C + 16, v16, a4, v13, 0);
        v15 = 0;
      }
      unk_230FD2C = v14;
      return sub_A59630(ItemCount, a4 + a1[6] - 36, v13, v15);
    }
  }
  return result;
}

