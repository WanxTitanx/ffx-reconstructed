// Function: sub_8D0140
// Address: 0x8d0140
void __cdecl sub_8D0140(int a1, float a2, float a3, int a4, int a5)
{
  int v5; // eax
  float v6; // [esp+8h] [ebp-28h]
  float v7; // [esp+Ch] [ebp-24h]
  _BYTE v8[4]; // [esp+2Ch] [ebp-4h] BYREF

  if ( !a5 )
    a3 = a3 - FFX_Menu2D_ScaleY_1080to416(79.0) * (double)*(__int16 *)(a1 + 70) * 0.000244140625;
  if ( a4 >= 0 && a4 < *(unsigned __int16 *)(a1 + 48) )
  {
    v7 = FFX_Menu2D_ScaleY_1080to416(60.0);
    v6 = FFX_Menu2D_ScaleX_1920to512(740.0);
    sub_8F5F70(a2, a3, v6, v7, 5);
    v5 = LOWORD(MEMORY[0x1597730][a4]);
    if ( (_WORD)v5 )
    {
      sub_7ABBF0(v5, v8);
      sub_8E67F0(LOWORD(MEMORY[0x1597730][a4]), a2, a3, 0.0);
    }
  }
}
