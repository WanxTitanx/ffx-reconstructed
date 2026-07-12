// Function: FFX_Magic_ProcessPendingQueue_structural
// Address: 0x800090
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

  if ( !unk_23C3642 )
  {
LABEL_8:
    v2 = (_BYTE *)unk_23C3648;
    if ( unk_23C3648 )
    {
      if ( unk_23C3648 != -1 )
      {
        v3 = unknown_libname_741(*(_DWORD *)(unk_23C3648 + 8));
        if ( *v2 == 2 )
        {
          unk_11A0063 = 1;
          sub_8873B0(v3, 0);
          unk_23C3520 = v2;
        }
        unk_23C3648 = -1;
      }
    }
    else
    {
      v6 = (_BYTE *)unk_23C364C;
      if ( unk_23C364C && unk_23C364C != -1 )
      {
        v7 = unknown_libname_741(*(_DWORD *)(unk_23C364C + 8));
        if ( *v6 == 2 )
        {
          unk_11A0063 = 1;
          sub_8873B0(0, v7);
          unk_23C3524 = v6;
        }
        unk_23C364C = -1;
      }
    }
    return;
  }
  switch ( n3_8 )
  {
    case 2:
      if ( !sub_887880(0) )
      {
        n3_8 = 3;
        sub_8874C0();
      }
      return;
    case 3:
      if ( sub_8878A0(0) )
        return;
      n3_8 = 0;
      v0 = LOBYTE(unk_23C3640[0]) + 1;
      v1 = unk_23C3642-- == 1;
      ++unk_23C3640[0];
      if ( v1 )
        goto LABEL_8;
      break;
    case 1:
      n3_8 = 2;
      return;
    default:
      v0 = unk_23C3640[0];
      break;
  }
  n3_8 = 2;
  v4 = v0 & 0x1F;
  v5 = unk_23C3540[v4];
  if ( v5 && !FFX_Magic_SeSep_RegisterPendingRecord_structural(v5, dword_23C35C0[v4]) )
    n3_8 = 3;
}
