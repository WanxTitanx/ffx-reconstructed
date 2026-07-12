// Function: sub_A65060
// Address: 0xa65060
// Size: 0x428
// Prototype: 

int __cdecl sub_A65060(unsigned __int16 a1, unsigned __int16 a2)
{
  int v2; // edi
  void *v3; // eax
  char *v4; // edi
  char *v5; // edi
  char v6; // cl

  v2 = dword_12A4080[a1];
  sub_7E64F0(46, 2);
  nullsub_93("     (%3d)umax", *(unsigned __int16 *)(v2 + 52));
  nullsub_93("     (%3d)umc", *(unsigned __int16 *)(v2 + 54));
  nullsub_93("     (%3d)uc", *(unsigned __int16 *)(v2 + 56));
  nullsub_93("    (%4d)v", unk_232278A);
  nullsub_93("    (%4x)no", *(__int16 *)(v2 + 2));
  nullsub_93("(%8x)f", *(_DWORD *)(v2 + 4));
  nullsub_93("(%8x)osua", v2);
  nullsub_93("(%8x)free_a", *(_DWORD *)(v2 + 40));
  sub_7E64F0(33, 10);
  v3 = *(void **)(v2 + 88);
  if ( !v3 )
    v3 = &unk_11A1240;
  nullsub_93("(%8x)pa.(%8x)pta", *(_DWORD *)(v2 + 84), v3);
  if ( a1 )
    v4 = (char *)(v2 + 4352);
  else
    v4 = (char *)off_C88AA4;
  v5 = &v4[256 * a2];
  sub_7E64F0(54, 21);
  nullsub_93("(%3d)osu", a2);
  sub_7E64F0(46, 21);
  nullsub_93("(%3d)en", (unsigned __int8)v5[24]);
  sub_7E64F0(28, 21);
  nullsub_93("(%4x)no", *((unsigned __int16 *)v5 + 13));
  sub_7E64F0(40, 22);
  nullsub_93("(%8x)r", *((_DWORD *)v5 + 50));
  sub_7E64F0(28, 22);
  switch ( v5[186] )
  {
    case 0:
      nullsub_93("(normal)fin");
      break;
    case 3:
      nullsub_93("   (cir)fin");
      break;
    case 4:
      nullsub_93("   (sph)fin");
      break;
    case 5:
      nullsub_93(" (cir_y)fin");
      break;
    case 6:
      nullsub_93("   (rel)fin");
      break;
    case 7:
      nullsub_93("  (cir2)fin");
      break;
    case 8:
      nullsub_93("(cir_gw)fin");
      break;
    case 9:
      nullsub_93("(cirzgw)fin");
      break;
    default:
      nullsub_93("(......)fin");
      break;
  }
  sub_7E64F0(51, 22);
  v6 = v5[187];
  switch ( v6 )
  {
    case 1:
      nullsub_93("  (anm)draw");
      break;
    case 2:
      nullsub_93("(model)draw");
      break;
    case 3:
      nullsub_93(" (part)draw");
      break;
    case 4:
      nullsub_93("(flash)draw");
      break;
    case 6:
      nullsub_93("(gline)draw");
      break;
    case 9:
      nullsub_93(" (anmm)draw");
      break;
    case 11:
      nullsub_93("(etovl)draw");
      break;
    case 18:
      nullsub_93("(mimic)draw");
      break;
    default:
      if ( v6 >= 0 )
        nullsub_93("(.....)draw");
      else
        nullsub_93("  (ovl)draw");
      break;
  }
  sub_7E64F0(27, 23);
  nullsub_93("(%4x)local", *((unsigned __int16 *)v5 + 92));
  if ( *((_DWORD *)v5 + 47) )
  {
    sub_7E64F0(39, 23);
    nullsub_93("(%7x)mlc", *((_DWORD *)v5 + 47));
  }
  else
  {
    sub_7E64F0(39, 23);
    nullsub_93("(.......)mlc");
  }
  sub_7E64F0(52, 23);
  nullsub_93("(%4x)flag", *((unsigned __int16 *)v5 + 88));
  sub_7E64F0(40, 24);
  nullsub_93(
    "(%4x.%4x.%4x.%4x)w",
    (unsigned __int8)v5[16],
    (unsigned __int8)v5[17],
    (unsigned __int8)v5[18],
    (unsigned __int8)v5[19]);
  sub_7E64F0(26, 24);
  nullsub_93("(%8x)etc", v5 + 168);
  sub_7E64F0(24, 25);
  nullsub_93("(%8x.%8x.%8x.%8x)i", *(_DWORD *)v5, *((_DWORD *)v5 + 1), *((_DWORD *)v5 + 2), *((_DWORD *)v5 + 3));
  sub_7E64F0(10, 27);
  nullsub_93(
    "(%4.4f.%4.4f.%4.4f.%4.4f)sp.uvws",
    *((float *)v5 + 28),
    *((float *)v5 + 29),
    *((float *)v5 + 30),
    *((float *)v5 + 31));
  nullsub_93(
    "(%4.4f.%4.4f.%4.4f.%4.4f)  .xyzt",
    *((float *)v5 + 32),
    *((float *)v5 + 33),
    *((float *)v5 + 34),
    *((float *)v5 + 35));
  nullsub_93(
    "(%4.4f.%4.4f.%4.4f.%4.4f)s .",
    *((float *)v5 + 20),
    *((float *)v5 + 21),
    *((float *)v5 + 22),
    *((float *)v5 + 23));
  nullsub_93(
    "(%4.4f.%4.4f.%4.4f.%4.4f)  .",
    *((float *)v5 + 24),
    *((float *)v5 + 25),
    *((float *)v5 + 26),
    *((float *)v5 + 27));
  nullsub_93(
    "(%4.4f.%4.4f.%4.4f.%4.4f)v .",
    *((float *)v5 + 12),
    *((float *)v5 + 13),
    *((float *)v5 + 14),
    *((float *)v5 + 15));
  nullsub_93(
    "(%4.4f.%4.4f.%4.4f.%4.4f)  .",
    *((float *)v5 + 16),
    *((float *)v5 + 17),
    *((float *)v5 + 18),
    *((float *)v5 + 19));
  return nullsub_93(
           "(%4.4f.%4.4f.%4.4f.%4.4f)p .xyz",
           *((float *)v5 + 36),
           *((float *)v5 + 37),
           *((float *)v5 + 38),
           *((float *)v5 + 39));
}

