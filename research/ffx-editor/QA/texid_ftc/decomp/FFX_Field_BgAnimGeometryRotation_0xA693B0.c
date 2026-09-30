// FFX Field: BG anim geometry rotation
// bad sp value at call has been detected, the output may be wrong!
int __usercall FFX_Field_BgAnimGeometryRotation@<eax>(
        int a1@<ebp>,
        void *hudContext@<edx>,
        FFX_CharacterId charId@<ecx>,
        int a4,
        int a5,
        float *a6)
{
  void *hudContext_1; // edx
  FFX_CharacterId charId_1; // ecx
  void *hudContext_2; // edx
  FFX_CharacterId charId_2; // ecx
  void *hudContext_3; // edx
  FFX_CharacterId charId_3; // ecx
  int frame_; // edi
  int v13; // esi
  int frame__1; // edi
  int v15; // esi
  int frame__2; // edx
  int v17; // esi
  long double v19; // [esp-90h] [ebp-9Ch]
  long double v20; // [esp-90h] [ebp-9Ch]
  long double v21; // [esp-90h] [ebp-9Ch]
  long double v22; // [esp-90h] [ebp-9Ch]
  float v23; // [esp-84h] [ebp-90h]
  float v24; // [esp-84h] [ebp-90h]
  float v25; // [esp-84h] [ebp-90h]
  float v26; // [esp-84h] [ebp-90h]
  float v27; // [esp-84h] [ebp-90h]
  float v28; // [esp-84h] [ebp-90h]
  float v29; // [esp-84h] [ebp-90h]
  float v30; // [esp-84h] [ebp-90h]
  float FFX_Field_Global_C88C60; // [esp-84h] [ebp-90h]
  float v32; // [esp-84h] [ebp-90h]
  _DWORD v33[35]; // [esp-80h] [ebp-8Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v33[32] = a1; /*0xa693bc*/
  v33[33] = retaddr; /*0xa693c0*/
  v19 = unk_22FB180 * 3.141592025756836 * 0.00048828125; /*0xa69407*/
  v23 = sin(v19); /*0xa6941c*/
  FFX_Field_Global_C88C18 = v23 * 40.0; /*0xa6942e*/
  FFX_Field_Global_C88C1C = 0.0; /*0xa69436*/
  v24 = cos(v19); /*0xa69447*/
  FFX_Field_Global_C88C20 = v24 * 40.0; /*0xa69459*/
  FFX_Field_Global_C88C2C = 0.0; /*0xa69461*/
  v20 = FFX_Field_Global_C88C28 * 3.141592025756836 * 0.00048828125; /*0xa69479*/
  v25 = sin(v20); /*0xa69484*/
  FFX_Field_Global_C88C30 = v25 * 40.0; /*0xa69496*/
  v26 = cos(v20); /*0xa694a7*/
  FFX_Field_Global_C88C34 = v26 * 40.0; /*0xa694b9*/
  v21 = FFX_Field_Global_C88C40 * 3.141592025756836 * 0.00048828125; /*0xa694d1*/
  v27 = sin(v21); /*0xa694dc*/
  FFX_Field_Global_C88C44 = v27 * 0.0; /*0xa694ee*/
  FFX_Field_Global_C88C48 = v27 * 40.0; /*0xa694fa*/
  v28 = cos(v21); /*0xa6950b*/
  FFX_Field_Global_C88C4C = v28 * 40.0; /*0xa6951d*/
  v22 = FFX_Field_Global_C88C58 * 3.141592025756836 * 0.00048828125; /*0xa69535*/
  v29 = sin(v22); /*0xa69540*/
  FFX_Field_Global_C88C5C = v29 * 50.0; /*0xa69552*/
  v30 = cos(v22); /*0xa69563*/
  FFX_Field_Global_C88C60 = v30 * 80.0; /*0xa69575*/
  FFX_Field_Global_C88C60 = FFX_Field_Global_C88C60; /*0xa69581*/
  FFX_Field_Global_C88C64 = FFX_Field_Global_C88C60; /*0xa69587*/
  MEMORY[0x22FB1D8] = 32772; /*0xa695aa*/
  MEMORY[0x22FB1E0] = 1089; /*0xa695b4*/
  unk_22FB188 = FFX_Field_Global_C88C18 * -1.0; /*0xa695be*/
  v32 = 0.0 * -1.0; /*0xa695c8*/
  unk_22FB18C = v32; /*0xa695d4*/
  unk_22FB190 = FFX_Field_Global_C88C20 * -1.0; /*0xa695e2*/
  unk_22FB194 = 1.0; /*0xa695ea*/
  unk_22FB198 = v32; /*0xa695f2*/
  unk_22FB19C = FFX_Field_Global_C88C30 * -1.0; /*0xa69600*/
  unk_22FB1A0 = FFX_Field_Global_C88C34 * -1.0; /*0xa6960e*/
  unk_22FB1A4 = 1.0; /*0xa69614*/
  unk_22FB1A8 = FFX_Field_Global_C88C44 * -1.0; /*0xa69622*/
  unk_22FB1AC = FFX_Field_Global_C88C48 * -1.0; /*0xa69630*/
  unk_22FB1B0 = FFX_Field_Global_C88C4C * -1.0; /*0xa6963e*/
  unk_22FB1B4 = 1.0; /*0xa69644*/
  unk_22FB1B8 = FFX_Field_Global_C88C5C * -1.0; /*0xa69652*/
  unk_22FB1BC = FFX_Field_Global_C88C60 * -1.0; /*0xa69660*/
  unk_22FB1C0 = -1.0 * FFX_Field_Global_C88C64; /*0xa69670*/
  unk_22FB1C4 = 1.0; /*0xa69676*/
  FFX_BtlUI_HudParty_SetAnimFrame(charId, hudContext, (int)&frame_); /*0xa6967c*/
  FFX_BtlUI_HudParty_SetAnimFrame(charId_1, hudContext_1, (int)&frame__0); /*0xa6968e*/
  FFX_BtlUI_HudParty_SetAnimFrame(charId_2, hudContext_2, (int)&frame__1); /*0xa696a0*/
  FFX_BtlUI_HudParty_SetAnimFrame(charId_3, hudContext_3, (int)&frame__2); /*0xa696b2*/
  frame_ = frame_; /*0xa696c8*/
  v13 = unk_22FB1FC; /*0xa696d3*/
  unk_22FB210 = unk_22FB200; /*0xa696d5*/
  unk_22FB214 = unk_22FB204; /*0xa696e2*/
  frame_ -= 256; /*0xa696e7*/
  unk_22FB1FC -= 128; /*0xa696ed*/
  unk_22FB208 = frame_ + 256; /*0xa6970a*/
  frame__1 = frame__0; /*0xa69713*/
  unk_22FB20C = v13 + 128; /*0xa69715*/
  frame__0 -= 256; /*0xa69723*/
  unk_22FB240 = unk_22FB230; /*0xa69738*/
  unk_22FB238 = frame__1 + 256; /*0xa69742*/
  v15 = unk_22FB22C + 128; /*0xa69748*/
  unk_22FB22C -= 128; /*0xa6974b*/
  unk_22FB23C = v15; /*0xa69759*/
  unk_22FB244 = unk_22FB234; /*0xa6975f*/
  unk_22FB268 = frame__1 + 256; /*0xa69777*/
  unk_22FB270 = unk_22FB260; /*0xa69788*/
  frame__1 -= 256; /*0xa69792*/
  frame__2 = frame__2; /*0xa69798*/
  frame__2 -= 256; /*0xa6979e*/
  unk_22FB26C = unk_22FB25C + 128; /*0xa697ab*/
  unk_22FB274 = unk_22FB264; /*0xa697b5*/
  unk_22FB25C -= 128; /*0xa697bf*/
  n1006632960 = frame__2; /*0xa697cb*/
  *(&n1006632960 + 1) = unk_22FB28C; /*0xa697d1*/
  v17 = unk_22FB28C + 128; /*0xa697e2*/
  *(_QWORD *)&n16 = qword_22FB290; /*0xa697ea*/
  qword_22FB2A0 = qword_22FB290; /*0xa697f5*/
  unk_22FB28C -= 128; /*0xa69800*/
  unk_22FB298 = frame__2 + 256; /*0xa69806*/
  unk_22FB29C = v17; /*0xa6980c*/
  nullsub_98(&unk_22FB1C8, 14, 0, 0); /*0xa69812*/
  FFXVu0InversMatrix(a6, a6); /*0xa6981f*/
  return FFX_PostProc_ArenaStack_AllocTexFmtPush(a4, (int)v33, 0); /*0xa698a7*/
}