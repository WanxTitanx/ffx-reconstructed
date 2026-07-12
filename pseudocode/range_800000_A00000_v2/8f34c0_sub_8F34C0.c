// Function: sub_8F34C0
// Address: 0x8f34c0
void __cdecl sub_8F34C0(int a1, float a2, int a3)
{
  int v3; // edi
  unsigned __int16 v4; // cx
  int v5; // ebx
  unsigned __int16 *v6; // esi
  int n255; // eax
  unsigned __int16 *v8; // eax
  __int16 v9; // si
  unsigned __int8 n3; // al
  bool v11; // zf
  int n3_1; // ebx
  unsigned __int16 *v13; // ecx
  int n255_1; // eax
  unsigned __int16 *v15; // eax
  char *v16; // esi
  int v17; // eax
  float v18; // [esp+4h] [ebp-48h]
  float v19; // [esp+8h] [ebp-44h]
  char *KernelString; // [esp+Ch] [ebp-40h]
  float v21; // [esp+Ch] [ebp-40h]
  float v22; // [esp+10h] [ebp-3Ch]
  unsigned __int8 v23; // [esp+10h] [ebp-3Ch]
  float v24; // [esp+14h] [ebp-38h]
  float v25; // [esp+14h] [ebp-38h]
  float v26; // [esp+1Ch] [ebp-30h]
  float v27; // [esp+34h] [ebp-18h]
  float v28; // [esp+34h] [ebp-18h]
  int v29; // [esp+34h] [ebp-18h]
  float v30; // [esp+34h] [ebp-18h]
  float v31; // [esp+34h] [ebp-18h]
  float v32; // [esp+34h] [ebp-18h]
  int v33; // [esp+38h] [ebp-14h] BYREF
  float v34; // [esp+3Ch] [ebp-10h]
  int v35; // [esp+40h] [ebp-Ch]
  float v36; // [esp+44h] [ebp-8h]
  int v37; // [esp+48h] [ebp-4h] BYREF

  v3 = sub_7ABBF0(a1, &v37);
  sub_798EC0(v3);
  if ( *(_BYTE *)(v3 + 11) )
  {
    sub_8F9230(0, 0, 512, 416);
    v4 = 0;
    v5 = 0;
    v36 = 0.0;
    if ( *(_BYTE *)(v3 + 11) )
    {
      v6 = (unsigned __int16 *)(v3 + 14);
      do
      {
        n255 = *v6;
        if ( (_WORD)n255 != 255 )
        {
          v8 = (unsigned __int16 *)sub_7909C0(n255, &v37);
          sub_905290(v37 + *v8, (int)&v33, 0, 0.77999997);
          v4 = LOWORD(v36);
          LODWORD(v34) = SLOWORD(v36);
          if ( *(float *)&v33 > (double)SLOWORD(v36) )
          {
            v4 = (int)*(float *)&v33;
            LODWORD(v36) = v4;
          }
        }
        ++v5;
        ++v6;
      }
      while ( v5 < *(unsigned __int8 *)(v3 + 11) );
    }
    LODWORD(v34) = (__int16)v4;
    if ( FFX_Menu2D_ScaleX_1920to512(300.0) <= (double)(__int16)v4 )
      v9 = LOWORD(v36);
    else
      v9 = (int)FFX_Menu2D_ScaleX_1920to512(300.0);
    n3 = *(_BYTE *)(v3 + 11);
    if ( n3 > 3u )
    {
      v34 = (float)(52 * (n3 - 3));
      *(float *)&a3 = *(float *)&a3 - FFX_Menu2D_ScaleY_1080to416(v34);
    }
    v34 = (float)(52 * *(unsigned __int8 *)(v3 + 11) - 2);
    v26 = FFX_Menu2D_ScaleY_1080to416(v34);
    v34 = FFX_Menu2D_ScaleX_1920to512(90.0) + (double)v9;
    FFX_Menu2D_DrawRoundedPanel9Slice(a2, a2, a3, v34, v26, 0);
    v11 = *(_BYTE *)(v3 + 11) == 0;
    v35 = 0;
    if ( !v11 )
    {
      n3_1 = 3;
      v13 = (unsigned __int16 *)(v3 + 14);
      LODWORD(v36) = 3;
      LODWORD(v34) = v3 + 14;
      do
      {
        n255_1 = *v13;
        if ( (_WORD)n255_1 == 255 )
        {
          v36 = (float)SLODWORD(v36);
          v36 = FFX_Menu2D_ScaleY_1080to416(v36) + *(float *)&a3;
          v24 = v36;
          v36 = FFX_Menu2D_ScaleX_1920to512(16.0) + a2;
          v22 = v36;
          KernelString = (char *)FFX_Table_GetKernelString(1, 4101, 0);
          FFX_Menu2D_DrawKernelString(KernelString, v22, v24, 0.0, 0.77999997);
        }
        else
        {
          v15 = (unsigned __int16 *)sub_7909C0(n255_1, &v37);
          v16 = (char *)(v37 + *v15);
          v23 = *((_BYTE *)v15 + 104);
          v21 = FFX_Menu2D_ScaleY_1080to416(36.0);
          v19 = FFX_Menu2D_ScaleX_1920to512(29.0);
          v27 = (float)(n3_1 + 4);
          v28 = FFX_Menu2D_ScaleY_1080to416(v27) + *(float *)&a3;
          v18 = v28;
          *(float *)&v29 = FFX_Menu2D_ScaleX_1920to512(11.0) + a2;
          sub_8E6AF0(v29, v18, v19, v21, v23, 0x80u, 0x80u, 0x80u, 0x80u);
          v30 = (float)SLODWORD(v36);
          v31 = FFX_Menu2D_ScaleY_1080to416(v30) + *(float *)&a3;
          v25 = v31;
          v32 = FFX_Menu2D_ScaleX_1920to512(45.0) + a2;
          FFX_Menu2D_DrawKernelString(v16, v32, v25, 0.0, 0.77999997);
        }
        v17 = *(unsigned __int8 *)(v3 + 11);
        v13 = (unsigned __int16 *)(LODWORD(v34) + 2);
        n3_1 += 52;
        ++v35;
        LODWORD(v34) += 2;
        v36 = *(float *)&n3_1;
      }
      while ( v35 < v17 );
    }
  }
}
