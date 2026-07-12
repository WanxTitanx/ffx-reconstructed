// Function: sub_93E570
// Address: 0x93e570
void *__usercall sub_93E570@<eax>(int a1@<edi>, int a2, int a3, int n46)
{
  int v4; // esi
  _BYTE *v5; // esi
  int v6; // edi
  int v7; // edx
  const char **p_n10; // eax
  const char *n10_1; // ecx
  unsigned int v10; // esi
  char *NAME:; // ecx
  char v12; // al
  int v13; // eax
  int v14; // edi
  void *n10; // eax
  int v16; // eax
  int v17; // eax
  int n6; // edi
  int v19; // ecx
  int v20; // ecx
  int v21; // eax
  int n6_1; // edi
  int v23; // ecx
  int v24; // edi
  const char *v25; // edi
  int v26; // eax
  int v27; // eax
  int i; // eax
  int v29; // eax
  int v30; // eax
  int v31; // edx
  int v32; // ecx
  int v33; // edx
  int v34; // ecx
  int v35; // edx
  int v36; // ecx
  int n64; // eax
  int v38; // ecx
  int v39; // [esp-4h] [ebp-224h]
  _BYTE *v40; // [esp+8h] [ebp-218h]
  int n4; // [esp+10h] [ebp-210h]
  const char **p_n10_1; // [esp+14h] [ebp-20Ch]
  int v43; // [esp+14h] [ebp-20Ch]
  int v44; // [esp+14h] [ebp-20Ch]
  int v45; // [esp+18h] [ebp-208h]
  int v46; // [esp+18h] [ebp-208h]
  int v47; // [esp+18h] [ebp-208h]
  char Buffer[512]; // [esp+1Ch] [ebp-204h] BYREF

  v4 = sub_84AEC0(a2);
  v39 = a1;
  switch ( a3 )
  {
    case 32769:
      v5 = (_BYTE *)FFX_Memory_Alloc(0x224u, a1);
      v40 = v5;
      if ( !v5 )
        sub_76F0B0("ms != NULL", "..\\program\\lib\\src\\camera_debug.c", 468);
      memset(v5, 0, 0x224u);
      sub_84B560(a2, v5);
      sub_84B6A0(a2);
      n4 = 4;
      v6 = 0;
      v7 = 1;
      p_n10 = (const char **)&n10_3;
      while ( 1 )
      {
        while ( 1 )
        {
          n10_1 = *p_n10;
          p_n10_1 = p_n10;
          v45 = v7;
          if ( *p_n10 != (const char *)10 )
            break;
          v6 += 12;
          ++p_n10;
          n4 = 4;
          ++v7;
        }
        if ( !n10_1 )
          break;
        v10 = strlen(n10_1);
        sub_84A470(a2, v7, n10_1, n4, v6, 14 * v10, 10);
        n4 += 16 * v10;
        p_n10 = p_n10_1 + 1;
        v7 = v45 + 1;
      }
      sub_84A470(a2, 256, "OK", n4 + 58, v6, 24, 10);
      *v40 = aName_1[0]; // "NAME:"
      if ( aName_1[0] ) // "NAME:"
      {
        NAME: = aName_1; // "NAME:"
        do
        {
          v12 = *++NAME:;
          NAME:[v40 - aName_1] = v12; // "NAME:"
        }
        while ( *NAME: );
      }
      v13 = v6 + 14;
      v14 = v6 + 24;
      *((_DWORD *)v40 + 136) = v13;
      *((_DWORD *)v40 + 128) = 0;
      sub_84A470(a2, 257, "^", 140, v14 + 8, 14, 12);
      sub_84A470(a2, 258, "v", 140, v14 + 28, 14, 12);
      sub_84A470(
        a2,
        259,
        asc_C61384, // "                                      "
        8,
        v14,
        120,
        8);
      sub_84A470(
        a2,
        260,
        asc_C61384, // "                                      "
        8,
        v14 + 9,
        120,
        8);
      sub_84A470(
        a2,
        261,
        asc_C61384, // "                                      "
        8,
        v14 + 18,
        120,
        8);
      sub_84A470(
        a2,
        262,
        asc_C61384, // "                                      "
        8,
        v14 + 27,
        120,
        8);
      sub_84A470(
        a2,
        263,
        asc_C61384, // "                                      "
        8,
        v14 + 36,
        120,
        8);
      sub_84A470(
        a2,
        264,
        asc_C61384, // "                                      "
        8,
        v14 + 45,
        120,
        8);
      sub_942360(a2, v40, 264, 17);
      return 0;
    case 32771:
      nullsub_34();
      if ( *(_DWORD *)(v4 + 532) )
        FFX_Memory_Delete(*(_DWORD *)(v4 + 532), a1);
      FFX_Memory_Delete(v4, v39);
      return 0;
    case 32774:
      switch ( n46 )
      {
        case 256:
          nullsub_34();
          sprintf(
            Buffer,
            "host:%s%s",
            aFfxProjCamera, // "/ffx/proj/camera/"
            (const char *)(v4 + 5));
          sub_942030(&unk_25D60A0, Buffer);
          unk_25D5F9C = 1;
          return 0;
        case 257:
          v16 = *(_DWORD *)(v4 + 540);
          if ( v16 > 0 )
            *(_DWORD *)(v4 + 540) = v16 - 1;
          v17 = *(_DWORD *)(v4 + 540);
          n6 = 0;
          v19 = v17 << 9;
          v46 = v17;
          v43 = v17 << 9;
          while ( v17 < *(_DWORD *)(v4 + 536) )
          {
            sub_9411F0(a2, n6 + 259, v19 + *(_DWORD *)(v4 + 532));
            ++n6;
            v17 = v46 + 1;
            v19 = v43 + 512;
            ++v46;
            v43 += 512;
            if ( n6 >= 6 )
              return 0;
          }
          do
          {
            sub_9411F0(a2, n6 + 259, (int)" ");
            ++n6;
          }
          while ( n6 < 6 );
          return 0;
        case 258:
          v20 = *(_DWORD *)(v4 + 540);
          if ( v20 + 6 < *(_DWORD *)(v4 + 536) )
            *(_DWORD *)(v4 + 540) = v20 + 1;
          v21 = *(_DWORD *)(v4 + 540);
          n6_1 = 0;
          v23 = v21 << 9;
          v47 = v21;
          v44 = v21 << 9;
          while ( v21 < *(_DWORD *)(v4 + 536) )
          {
            sub_9411F0(a2, n6_1 + 259, v23 + *(_DWORD *)(v4 + 532));
            ++n6_1;
            v21 = v47 + 1;
            v23 = v44 + 512;
            ++v47;
            v44 += 512;
            if ( n6_1 >= 6 )
              return 0;
          }
          do
          {
            sub_9411F0(a2, n6_1 + 259, (int)" ");
            ++n6_1;
          }
          while ( n6_1 < 6 );
          return 0;
        case 259:
        case 260:
        case 261:
        case 262:
        case 263:
        case 264:
          v24 = *(_DWORD *)(v4 + 540) + n46 - 259;
          if ( v24 >= *(_DWORD *)(v4 + 536) )
            return 0;
          v25 = (const char *)(*(_DWORD *)(v4 + 532) + (v24 << 9));
          if ( !v25 )
            return 0;
          nullsub_34();
          sprintf(Buffer, "host:%s%s", byte_25D5FA0, v25);
          v26 = sub_62FBE0(Buffer, 1);
          if ( v26 < 0 )
          {
            v27 = dword_25D5F94;
            if ( *v25 == 46 )
            {
              if ( dword_25D5F94 >= 0 )
              {
                do
                {
                  if ( byte_25D5FA0[v27] == 47 )
                    break;
                  --v27;
                }
                while ( v27 >= 0 );
              }
              for ( i = v27 - 1; i >= 0; --i )
              {
                if ( byte_25D5FA0[i] == 47 )
                  break;
              }
              v29 = i + 1;
              byte_25D5FA0[v29] = 0;
              dword_25D5F94 = v29;
            }
            else
            {
              for ( byte_25D5FA0[dword_25D5F94] = *v25; *v25; byte_25D5FA0[dword_25D5F94] = *v25 )
              {
                ++v25;
                ++dword_25D5F94;
              }
              byte_25D5FA0[dword_25D5F94++] = 47;
              byte_25D5FA0[dword_25D5F94] = 0;
            }
            sub_942360(a2, v4, 264, 17);
            sprintf(Buffer, "name:%s", byte_25D5FB1);
          }
          else
          {
            FFX_FileIO_IopDevice_Close(v26);
            sprintf(Buffer, "name:%s%s", byte_25D5FB1, v25);
          }
          sub_942030(v4, Buffer);
          *(_DWORD *)(v4 + 512) = 0;
          if ( Buffer[0] )
          {
            v30 = 0;
            do
              *(_DWORD *)(v4 + 512) = ++v30;
            while ( Buffer[v30] );
          }
          *(_DWORD *)(v4 + 512) -= 5;
          return 0;
        default:
          n10 = n10_3;
          v31 = 0;
          if ( !n10_3 )
            return 0;
          break;
      }
      break;
    case 32785:
      sub_848820(2);
      sub_848860(*(_DWORD *)(v4 + 544));
      sub_848880((const char *)v4);
      sub_848820(9 * *(_DWORD *)(v4 + 512) + 47);
      sub_848860(*(_DWORD *)(v4 + 544) + 2);
      sub_848880("_");
      return 0;
    default:
      return 0;
  }
  while ( n10 == (void *)10 || n46 != v31 + 1 )
  {
    n10 = *(&off_C612C4 + v31++);
    if ( !n10 )
      return n10;
  }
  if ( n46 == 43 )
  {
    v32 = *(_DWORD *)(v4 + 512);
    if ( !v32 )
      return 0;
    *(_BYTE *)(v32 + v4 + 4) = *(_BYTE *)(v32 + v4 + 5);
    v33 = 0;
    if ( *(_BYTE *)(*(_DWORD *)(v4 + 512) + v4 + 5) )
    {
      v34 = *(_DWORD *)(v4 + 512);
      do
      {
        ++v33;
        *(_BYTE *)(v33 + v34 + v4 + 4) = *(_BYTE *)(v33 + v34 + v4 + 5);
        v34 = *(_DWORD *)(v4 + 512);
      }
      while ( *(_BYTE *)(v34 + v33 + v4 + 5) );
    }
    --*(_DWORD *)(v4 + 512);
    return 0;
  }
  else if ( n46 == 44 )
  {
    v35 = 0;
    *(_BYTE *)(*(_DWORD *)(v4 + 512) + v4 + 5) = *(_BYTE *)(*(_DWORD *)(v4 + 512) + v4 + 6);
    if ( !*(_BYTE *)(*(_DWORD *)(v4 + 512) + v4 + 6) )
      return 0;
    v36 = *(_DWORD *)(v4 + 512);
    do
    {
      ++v35;
      *(_BYTE *)(v35 + v36 + v4 + 5) = *(_BYTE *)(v35 + v36 + v4 + 6);
      v36 = *(_DWORD *)(v4 + 512);
    }
    while ( *(_BYTE *)(v36 + v35 + v4 + 6) );
    return 0;
  }
  else
  {
    n64 = *(_DWORD *)(v4 + 512);
    if ( n46 == 45 )
    {
      if ( !n64 )
        return 0;
      *(_DWORD *)(v4 + 512) = n64 - 1;
      return 0;
    }
    else if ( n46 == 46 )
    {
      if ( n64 == 64 )
        return 0;
      *(_DWORD *)(v4 + 512) = n64 + 1;
      return 0;
    }
    else
    {
      if ( n64 == 64 )
        return 0;
      v38 = 0;
      if ( *(_BYTE *)v4 )
      {
        do
          ++v38;
        while ( *(_BYTE *)(v38 + v4) );
      }
      if ( v38 >= n64 + 5 )
      {
        do
        {
          *(_BYTE *)(v38 + v4) = *(_BYTE *)(v38 + v4 - 1);
          --v38;
        }
        while ( v38 >= *(_DWORD *)(v4 + 512) + 5 );
      }
      *(_BYTE *)(*(_DWORD *)(v4 + 512) + v4 + 5) = *(_BYTE *)*(&n10_3 + v31);
      ++*(_DWORD *)(v4 + 512);
      return 0;
    }
  }
}
