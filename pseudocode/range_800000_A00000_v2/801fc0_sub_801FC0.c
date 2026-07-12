// Function: sub_801FC0
// Address: 0x801fc0
unsigned __int8 __cdecl sub_801FC0(int a1, int a2)
{
  int v3; // ebx
  unsigned __int8 result; // al
  double v5; // st7
  int v6; // eax
  int v7; // esi
  __int64 v8; // [esp-34h] [ebp-6Ch]
  __int64 n2622; // [esp-14h] [ebp-4Ch]
  __int64 n2622_1; // [esp-10h] [ebp-48h]
  _BYTE v11[28]; // [esp+10h] [ebp-28h] BYREF
  int v12; // [esp+2Ch] [ebp-Ch]
  int v13; // [esp+30h] [ebp-8h]
  float v14; // [esp+34h] [ebp-4h]
  float v15; // [esp+40h] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 544);
  result = byte_12A8480[*(unsigned __int8 *)(v3 + 24)];
  if ( (result & *(_BYTE *)(v3 + 179)) == 0 )
  {
    *(_DWORD *)(a1 + 24) = *(_DWORD *)(v3 + 200);
    v14 = 256.0;
    *(_DWORD *)(a1 + 16) = 0;
    *(_DWORD *)(a1 + 20) = 0;
    switch ( *(_BYTE *)(v3 + 168) )
    {
      case 1:
        v14 = *(float *)(v3 + 60);
        break;
      case 2:
        if ( *(float *)(v3 + 60) <= 255.0 )
        {
          if ( *(float *)(v3 + 60) >= 0.0 )
          {
            v13 = (int)*(float *)(v3 + 60);
            *(_BYTE *)(a1 + 27) = v13;
          }
          else
          {
            *(_BYTE *)(a1 + 27) = 0;
          }
        }
        else
        {
          *(_BYTE *)(a1 + 27) = -1;
        }
        break;
      case 3:
        *(_DWORD *)(a1 + 16) = (int)*(float *)(v3 + 60) << 16;
        break;
      case 4:
        *(_DWORD *)(a1 + 20) = (int)*(float *)(v3 + 60) << 16;
        break;
      default:
        break;
    }
    switch ( *(_BYTE *)(v3 + 169) )
    {
      case 1:
        v14 = *(float *)(v3 + 76);
        break;
      case 2:
        if ( *(float *)(v3 + 76) <= 255.0 )
        {
          if ( *(float *)(v3 + 76) >= 0.0 )
          {
            v13 = (int)*(float *)(v3 + 76);
            *(_BYTE *)(a1 + 27) = v13;
          }
          else
          {
            *(_BYTE *)(a1 + 27) = 0;
          }
        }
        else
        {
          *(_BYTE *)(a1 + 27) = -1;
        }
        break;
      case 3:
        *(_DWORD *)(a1 + 16) = (int)*(float *)(v3 + 76) << 16;
        break;
      case 4:
        *(_DWORD *)(a1 + 20) = (int)*(float *)(v3 + 76) << 16;
        break;
      default:
        break;
    }
    v5 = v14 * 0.000000476837158203125;
    *(_BYTE *)(a1 + 8) = *(_BYTE *)(v3 + 194);
    v15 = v5;
    *(_BYTE *)(a1 + 9) = *(_BYTE *)(v3 + 195);
    *(_DWORD *)a1 = *(unsigned __int16 *)(v3 + 192);
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v3 + 208);
    sub_7EA610((void *)(a1 + 128), v15);
    sub_7E9760(a1 + 128, a1 + 128, v3 + 48, v3 + 144);
    v6 = sub_801E20((_DWORD *)a1, (unsigned __int16 *)v3);
    sub_7E82C0(a1 + 128, v6, a1 + 128);
    *(_DWORD *)(a1 + 28) = 0;
    *(_DWORD *)(a1 + 64) = *(_DWORD *)(v3 + 196);
    *(_DWORD *)(a1 + 56) = 0;
    *(_DWORD *)(a1 + 60) = 0;
    *(_DWORD *)(a1 + 32) = a1 + 128;
    *(_DWORD *)(a1 + 68) = 0;
    *(_DWORD *)(a1 + 4) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(a1 + 48) = a1 + 128;
    *(_DWORD *)(a1 + 52) = *(_DWORD *)(a2 + 84);
    v12 = unknown_libname_742(*(_DWORD *)(v3 + 224));
    HIDWORD(v8) = v3;
    LODWORD(v8) = 0;
    if ( sub_645580(v8) )
    {
      sub_7186F0(0, v3, v11, a1);
      HIDWORD(n2622) = v3;
      LODWORD(n2622) = 0;
      return FFX_MagicHost_CommitDrawableResources(n2622);
    }
    else
    {
      v7 = FFX_MagicHost_ClassifyPppOpcodeByte(*(unsigned __int8 *)(a1 + 8));
      if ( (*(_DWORD *)a1 & 0x2000) == 0 )
        v7 |= sub_712DE0(*(_DWORD *)(a1 + 68));
      if ( (*(_BYTE *)a1 & 8) != 0 )
        v7 |= 0x40u;
      HIDWORD(n2622_1) = v3;
      LODWORD(n2622_1) = 0;
      return sub_711260(n2622_1, v11, a1, v7);
    }
  }
  return result;
}
