// Function: sub_8EC2F0
// Address: 0x8ec2f0
char *__cdecl sub_8EC2F0(
        char *a1,
        float n214,
        float a3,
        unsigned __int8 a4,
        char n128,
        char a6,
        char a7,
        char a8,
        float a9,
        float a10)
{
  char *v10; // edi
  char n97; // al
  char *v12; // esi
  char v13; // al
  char v14; // al
  char *v15; // esi
  double v16; // st7
  char *result; // eax
  int n3; // eax
  int v19; // [esp+4h] [ebp-120h]
  int v20; // [esp+Ch] [ebp-118h] BYREF
  int v21; // [esp+10h] [ebp-114h] BYREF
  float v22; // [esp+14h] [ebp-110h]
  double v23; // [esp+18h] [ebp-10Ch]
  _BYTE v24[256]; // [esp+20h] [ebp-104h] BYREF
  float n355; // [esp+134h] [ebp+10h]

  memset(v24, 0, sizeof(v24));
  v10 = a1;
  n97 = *a1;
  v12 = v24;
  if ( *a1 )
  {
    while ( n97 < 48 || n97 > 57 )
    {
      if ( n97 < 65 || n97 > 90 )
      {
        if ( n97 < 97 || n97 > 122 )
        {
          switch ( n97 )
          {
            case ' ':
              *v12 = 58;
              goto LABEL_30;
            case '-':
              *v12 = 71;
              goto LABEL_30;
            case '/':
              *v12 = 73;
              goto LABEL_30;
            case ':':
              *v12 = 74;
              goto LABEL_30;
            default:
              goto LABEL_31;
          }
          goto LABEL_31;
        }
        if ( FFX_Game_GetRegion(v19) > 0 && FFX_Game_GetRegion(v19) < 9 )
        {
          *v12 = *v10 + 15;
          goto LABEL_30;
        }
        if ( FFX_Game_GetRegion(v19) )
        {
          if ( FFX_Game_GetRegion(v19) != 10 && FFX_Game_GetRegion(v19) != 9 )
            goto LABEL_32;
          *v12 = *v10 + 19;
          goto LABEL_30;
        }
        v14 = *v10 - 23;
        *v12 = 44;
        v12[1] = v14;
        v12 += 2;
      }
      else
      {
        if ( FFX_Game_GetRegion(v19) > 0 && FFX_Game_GetRegion(v19) < 9 )
        {
          *v12 = *v10 + 15;
          goto LABEL_30;
        }
        if ( FFX_Game_GetRegion(v19) )
        {
          if ( FFX_Game_GetRegion(v19) != 10 && FFX_Game_GetRegion(v19) != 9 )
            goto LABEL_32;
          *v12 = *v10 + 25;
          goto LABEL_30;
        }
        v13 = *v10 - 17;
        *v12 = 44;
        v12[1] = v13;
        v12 += 2;
      }
LABEL_31:
      ++v10;
LABEL_32:
      n97 = *v10;
      if ( !*v10 )
        goto LABEL_33;
    }
    *v12 = n97;
LABEL_30:
    ++v12;
    goto LABEL_31;
  }
LABEL_33:
  v23 = a3;
  *v12 = 0;
  v15 = v24;
  n355 = v23 - FFX_Menu2D_ScaleY_1080to416(9.0);
  sub_640F60(&v21, &v20);
  *((float *)&v23 + 1) = (float)v21;
  v16 = *((float *)&v23 + 1);
  *((float *)&v23 + 1) = (float)v20;
  *((float *)&v23 + 1) = v16 / *((float *)&v23 + 1);
  *((float *)&v23 + 1) = *((float *)&v23 + 1) / 1.230769276618958;
  memset(&unk_1841D10, 0, 0x40u);
  unk_25D09B8 = 0;
  n214 = n214;
  unk_25D09AC = 0;
  n355 = n355;
  unk_25D09B0 = 0;
  unk_25D09B4 = 0;
  ::n128 = n128;
  unk_25D09A1 = a6;
  unk_25D09A2 = a7;
  unk_25D09A3 = a8;
  result = (char *)a4;
  unk_25D09BB = a4;
  if ( v24[0] )
  {
    do
    {
      n3 = sub_8DF600(*v15) - 1;
      if ( n3 )
      {
        if ( n3 == 3 )
        {
          sub_8B71F0(v15, &unk_1841D10);
          if ( FFX_Game_GetRegion(v19) > 0 && FFX_Game_GetRegion(v19) < 9 && (*v15 == 74 || *v15 == 73) )
          {
            n214 = (8.0 - unk_1841D2C) / *((float *)&v23 + 1) * 0.5 + n214;
            sub_643CA0(1);
            sub_640F80(0);
            v22 = a9 * 0.8999999761581421;
            sub_8FBAE0((int)&::n128, (int)&unk_1841D10, v22);
            sub_640F80(1);
            sub_8FB940((int)&::n128, (int)&unk_1841D10, v22);
            sub_643CA0(0);
            n214 = ((unk_1841D2C + (8.0 - unk_1841D2C) * 0.5) / *((float *)&v23 + 1) + a10) * a9 + n214;
          }
          else
          {
            sub_643CA0(1);
            sub_640F80(0);
            sub_8FBAE0((int)&::n128, (int)&unk_1841D10, a9);
            sub_640F80(1);
            sub_8FB940((int)&::n128, (int)&unk_1841D10, a9);
            sub_643CA0(0);
            sub_8E8ED0((int)&::n128, (int)&unk_1841D10, a9);
          }
        }
      }
      else
      {
        n214 = n214;
        n355 = n355 + 16.0;
      }
      result = (char *)sub_8DFD70(v15);
      v15 = result;
    }
    while ( *result );
  }
  return result;
}
