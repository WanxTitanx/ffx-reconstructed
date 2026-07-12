// Function: sub_A25990
// Address: 0xa25990
// Size: 0x5f
// Prototype: 

void __usercall sub_A25990(int a1@<esi>)
{
  int v1; // eax
  int v2; // esi

  if ( !unk_1984C68 )
  {
    v1 = FFX_Memory_Alloc_w(0x7Cu, a1);
    v2 = v1;
    if ( v1 )
    {
      *(float *)(v1 + 4) = -1.0;
      *(float *)(v1 + 8) = -1.0;
      *(_DWORD *)(v1 + 12) = 0;
      *(_DWORD *)(v1 + 116) = 0;
      *(_WORD *)v1 = 0;
      *(_BYTE *)(v1 + 2) = 0;
      *(_BYTE *)(v1 + 120) = GetSystemMetrics(23) != 0;
      unk_1984C68 = v2;
    }
    else
    {
      unk_1984C68 = 0;
    }
  }
}

