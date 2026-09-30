// FFX Render: Load PPP resource blob
int *__fastcall FFX_Render_LoadPppResourceBlob(FFXMagicHost *host, void *blob, _DWORD *lpBuffer)
{
  unsigned __int8 v3; // al
  int Size; // esi
  _DWORD *v5; // esi
  int *n564; // eax
  int v7; // ebx
  float *v8; // edi
  double v9; // st7
  void *hudContext; // edx
  FFX_CharacterId charId; // ecx
  size_t n0x100000; // eax
  int n564_1; // [esp+4h] [ebp-4h]
  _DWORD *lpBuffera; // [esp+10h] [ebp+8h]

  unk_CEC1E0 = 1; /*0x72a8f0*/
  MEMORY[0xD2C248] = lpBuffer; /*0x72a8fa*/
  FFX_MagicHost_RelocatePppResourceBlob(host, blob);// "pppAccele" /*0x72a8ff*/
  FFX_MagicHost_AttachPppResourceBuffer(&MEMORY[0xCEC21C], MEMORY[0xD2C248], &unk_CEC248, 0x40000); /*0x72a919*/
  if ( !MEMORY[0xCEC214] ) /*0x72a928*/
  {
    v3 = *((_BYTE *)MEMORY[0xD2C248] + 1); /*0x72a92f*/
    if ( v3 ) /*0x72a934*/
    {
      Size = v3 << 13; /*0x72a939*/
      MEMORY[0xCEC214] = FFX_Heap_AllocGameArenaDebugFill_wrapper(Size); /*0x72a949*/
      FFX_MagicHost_LinkResourceBufferRange(&unk_CEC22C, MEMORY[0xCEC214], Size); /*0x72a94e*/
    }
  }
  MEMORY[0xCEC200] = 0; /*0x72a95b*/
  unk_CEC1FC = 0; /*0x72a965*/
  FFX_Magic_InitSlotEntryConditional(1); /*0x72a96f*/
  FFX_Magic_InitAndSetSlotEntryCond((int)&MEMORY[0xCEC21C], 34307); /*0x72a97e*/
  v5 = MEMORY[0xD2C248]; /*0x72a983*/
  n564 = 0; /*0x72a989*/
  unk_CEC208 = 1; /*0x72a98e*/
  unk_D2C24C = 0; /*0x72a998*/
  n564_1 = 0; /*0x72a9a2*/
  if ( *((_WORD *)MEMORY[0xD2C248] + 2) ) /*0x72a9a9*/
  {
    v7 = 0; /*0x72a9ba*/
    lpBuffera = &unk_D30258; /*0x72a9bc*/
    v8 = (float *)&unk_D2C28C; /*0x72a9bf*/
    do /*0x72aa96*/
    {
      *((_DWORD *)v8 - 3) = Std_IdentityFunc_B(0); /*0x72a9cb*/
      *v8 = 0.0; /*0x72a9ce*/
      v8[1] = *(float *)&v5[v7 + 8]; /*0x72a9d8*/
      v8[2] = *(float *)&v5[v7 + 9]; /*0x72a9df*/
      v8[3] = *(float *)&v5[v7 + 10]; /*0x72a9e6*/
      v8[4] = *(float *)&v5[v7 + 11]; /*0x72a9ed*/
      v8[5] = *(float *)&v5[v7 + 12]; /*0x72a9f4*/
      v8[6] = *(float *)&v5[v7 + 13]; /*0x72a9fb*/
      v8[7] = *(float *)&v5[v7 + 14]; /*0x72aa02*/
      v8[8] = *(float *)&v5[v7 + 15]; /*0x72aa09*/
      v8[9] = *(float *)&v5[v7 + 16]; /*0x72aa10*/
      v8[10] = *(float *)&v5[v7 + 17]; /*0x72aa17*/
      v8[11] = *(float *)&v5[v7 + 18]; /*0x72aa1e*/
      v8[12] = *(float *)&v5[v7 + 19]; /*0x72aa25*/
      *(v8 - 15) = *(float *)&v5[v7 + 20]; /*0x72aa2c*/
      *(v8 - 7) = *(float *)&v5[v7 + 22]; /*0x72aa36*/
      *(v8 - 6) = *(float *)&v5[v7 + 23]; /*0x72aa40*/
      v9 = *(float *)&v5[v7 + 24]; /*0x72aa44*/
      *(lpBuffera - 2) = 0; /*0x72aa48*/
      *(lpBuffera - 1) = 0; /*0x72aa4f*/
      *(v8 - 5) = v9; /*0x72aa56*/
      *lpBuffera = 0; /*0x72aa59*/
      FFX_BtlUI_HudParty_GetElement(charId, hudContext); /*0x72aa60*/
      if ( BYTE2(v5[v7 + 26]) == 2 ) /*0x72aa6d*/
        unk_D2C24C = 1; /*0x72aa6f*/
      v5 = MEMORY[0xD2C248]; /*0x72aa79*/
      n564 = (int *)*((unsigned __int16 *)MEMORY[0xD2C248] + 2); /*0x72aa82*/
      lpBuffera += 19; /*0x72aa86*/
      v7 += 20; /*0x72aa8b*/
      v8 += 32; /*0x72aa8e*/
      ++n564_1; /*0x72aa91*/
    }
    while ( n564_1 < (int)n564 ); /*0x72aa96*/
  }
  unk_CEC218 = 0; /*0x72aa9e*/
  if ( *((_WORD *)v5 + 2) == 40 /*0x72aabf*/
    || (n564 = (int *)FFX_FieldEngine_Dispatch_65E010(), v5 = MEMORY[0xD2C248], n564 == (int *)564) )
  {
    unk_CEC218 = 1; /*0x72aac1*/
  }
  if ( !MEMORY[0xCEC210] ) /*0x72aad2*/
  {
    if ( *((_BYTE *)v5 + 2) ) /*0x72aad4*/
    {
      if ( *((_BYTE *)v5 + 2) == 1 ) /*0x72aade*/
      {
        n0x100000 = 0x100000; /*0x72aaea*/
        goto LABEL_19; /*0x72aaef*/
      }
      if ( *((_BYTE *)v5 + 2) == 2 ) /*0x72aae1*/
      {
        n0x100000 = 1310720; /*0x72aae3*/
LABEL_19:
        MEMORY[0xCEC1F0] = n0x100000; /*0x72aaf6*/
        n564 = FFX_Heap_AllocGameArenaDebugFill_wrapper(n0x100000); /*0x72aafc*/
        MEMORY[0xCEC210] = n564; /*0x72ab04*/
        MEMORY[0xCEC1F8] = 0; /*0x72ab09*/
        MEMORY[0xCEC1F4] = 0; /*0x72ab13*/
        return n564; /*0x72ab13*/
      }
    }
    n0x100000 = 786432; /*0x72aaf1*/
    goto LABEL_19; /*0x72aaf1*/
  }
  return n564; /*0x72ab1d*/
}