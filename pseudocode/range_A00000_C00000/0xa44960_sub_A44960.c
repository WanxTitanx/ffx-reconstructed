// Function: sub_A44960
// Address: 0xa44960
// Size: 0xba
// Prototype: 

int __thiscall sub_A44960(_BYTE *this)
{
  int result; // eax
  int v3; // esi
  int v4; // eax
  int v5; // [esp+0h] [ebp-1Ch]

  result = unk_CCC830;
  v3 = unk_CCC868;
  if ( !unk_CCC830 )
  {
    if ( FFX_Memory_Alloc_w(0x340u, v5) )
      result = sub_680020();
    else
      result = 0;
    unk_CCC830 = result;
  }
  if ( !*(_BYTE *)(result + 824)
    && !*(_BYTE *)(result + 828)
    && *(_DWORD *)result != 2
    && (!v3 || !*(_BYTE *)(v3 + 112)) )
  {
    v4 = sub_6D74D0(v5);
    if ( v4 )
    {
      if ( *(this + 4) )
        sub_6DA5E0(v4);
    }
    return sub_821DE0(0);
  }
  return result;
}

