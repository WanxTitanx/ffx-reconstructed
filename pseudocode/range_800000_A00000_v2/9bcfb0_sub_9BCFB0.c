// Function: sub_9BCFB0
// Address: 0x9bcfb0
int __thiscall sub_9BCFB0(
        int this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        float a11,
        float a12,
        float a13)
{
  int v14; // eax
  int v15; // edi
  int v16; // esi
  char *dst; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // esi
  char *dst_1; // [esp+1Ch] [ebp-Ch]
  int v23; // [esp+24h] [ebp-4h]

  v14 = *(_DWORD *)(this + 52);
  v15 = *(_DWORD *)(this + 48);
  if ( v15 == v14 )
  {
    v16 = 2 * v15;
    if ( !v15 )
      v16 = 1;
    if ( v14 < v16 )
    {
      if ( v16 )
        dst = (char *)sub_9D4CE0(192 * v16, 16);
      else
        dst = 0;
      v18 = *(_DWORD *)(this + 48);
      dst_1 = dst;
      v23 = v18;
      if ( v18 > 0 )
      {
        v19 = 0;
        do
        {
          if ( dst )
          {
            qmemcpy(dst, (const void *)(v19 + *(_DWORD *)(this + 56)), 0xC0u);
            v18 = v23;
          }
          v19 += 192;
          dst += 192;
          v23 = --v18;
        }
        while ( v18 );
      }
      if ( *(_DWORD *)(this + 56) )
      {
        if ( *(_BYTE *)(this + 60) )
          sub_9D4D50(*(_DWORD *)(this + 56));
        *(_DWORD *)(this + 56) = 0;
      }
      *(_BYTE *)(this + 60) = 1;
      *(_DWORD *)(this + 56) = dst_1;
      *(_DWORD *)(this + 52) = v16;
    }
  }
  ++*(_DWORD *)(this + 48);
  v20 = *(_DWORD *)(this + 56) + 192 * v15;
  *(_DWORD *)(v20 + 124) = a5;
  sub_9C0C90(v20, a2, a3, a4, a6, a7, a8, a9, a10, LODWORD(a11), LODWORD(a12), LODWORD(a13));
  return v20;
}
