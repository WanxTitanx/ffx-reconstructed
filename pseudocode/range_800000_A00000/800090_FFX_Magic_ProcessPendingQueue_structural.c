// Function: FFX_Magic_ProcessPendingQueue_structural
// Address: 0x800090
// Size: 0x149

void FFX_Magic_ProcessPendingQueue_structural()
{
  char v0; // al
  bool v1; // zf
  _BYTE *v2; // esi
  int v3; // eax
  unsigned __int16 v4; // ax
  int v5; // ecx
  _BYTE *v6; // esi
  int v7; // eax

  if ( !word_23C3642 ) /*0x800098*/
  {
LABEL_8:
    v2 = (_BYTE *)unk_23C3648; /*0x8000f8*/
    if ( unk_23C3648 ) /*0x800101*/
    {
      if ( unk_23C3648 != -1 ) /*0x80010a*/
      {
        v3 = unknown_libname_741(*(_DWORD *)(unk_23C3648 + 8)); /*0x800113*/
        if ( *v2 == 2 ) /*0x80011e*/
        {
          unk_11A0063 = 1; /*0x800123*/
          sub_8873B0(v3, 0); /*0x80012a*/
          unk_23C3520 = v2; /*0x800132*/
        }
        unk_23C3648 = -1; /*0x800138*/
      }
    }
    else
    {
      v6 = (_BYTE *)unk_23C364C; /*0x800196*/
      if ( unk_23C364C && unk_23C364C != -1 ) /*0x8001a3*/
      {
        v7 = unknown_libname_741(*(_DWORD *)(unk_23C364C + 8)); /*0x8001a8*/
        if ( *v6 == 2 ) /*0x8001b3*/
        {
          unk_11A0063 = 1; /*0x8001b8*/
          sub_8873B0(0, v7); /*0x8001bf*/
          unk_23C3524 = v6; /*0x8001c7*/
        }
        unk_23C364C = -1; /*0x8001cd*/
      }
    }
    return; /*0x800143*/
  }
  switch ( n3_8 ) /*0x8000a1*/
  {
    case 2: /*0x8000a1*/
      if ( !sub_887880(0) ) /*0x8000a5*/
      {
        n3_8 = 3; /*0x8000b5*/
        sub_8874C0(); /*0x8000bc*/
      }
      return; /*0x8000bc*/
    case 3: /*0x8000a1*/
      if ( sub_8878A0(0) ) /*0x8000c7*/
        return; /*0x8000d1*/
      n3_8 = 0; /*0x8000d7*/
      v0 = LOBYTE(unk_23C3640[0]) + 1; /*0x8000e2*/
      v1 = word_23C3642-- == 1; /*0x8000e9*/
      ++unk_23C3640[0]; /*0x8000f0*/
      if ( v1 ) /*0x8000f6*/
        goto LABEL_8; /*0x8000f6*/
      break;
    case 1: /*0x8000a1*/
      n3_8 = 2; /*0x800148*/
      return; /*0x80014f*/
    default:
      v0 = unk_23C3640[0]; /*0x800150*/
      break;
  }
  n3_8 = 2; /*0x800159*/
  v4 = v0 & 0x1F; /*0x80016c*/
  v5 = unk_23C3540[v4]; /*0x80016f*/
  if ( v5 && !FFX_Magic_SeSep_RegisterPendingRecord_structural(v5, dword_23C35C0[v4]) ) /*0x800182*/
    n3_8 = 3; /*0x80018e*/
}
