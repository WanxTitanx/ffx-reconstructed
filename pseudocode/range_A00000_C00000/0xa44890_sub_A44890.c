// Function: sub_A44890
// Address: 0xa44890
// Size: 0xc5
// Prototype: 

int __thiscall sub_A44890(_BYTE *this)
{
  int result; // eax
  int v3; // esi
  int v4; // [esp+0h] [ebp-1Ch]

  result = unk_CCC830;
  v3 = unk_CCC868;
  if ( !unk_CCC830 )
  {
    if ( FFX_Memory_Alloc_w(0x340u, v4) )
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
    sub_821DE0(1);
    *(this + 4) = 0;
    result = sub_6D74D0(v4);
    if ( result )
    {
      if ( !*(_BYTE *)(result + 1788) )
      {
        result = sub_6DA5E0(result);
        *(this + 4) = 1;
      }
    }
  }
  return result;
}

