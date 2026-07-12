// Function: sub_A1B4C0
// Address: 0xa1b4c0
// Size: 0x9a
// Prototype: 

int __thiscall sub_A1B4C0(int this, int a2)
{
  int result; // eax
  unsigned int v4; // eax
  int v5; // edx
  int v6; // edi
  int v7; // ecx
  int v8; // ebx

  if ( *(_UNKNOWN **)this == &unk_CA34CC )
    return 7;
  if ( (unsigned __int8)sub_596140() || (result = sub_58DD30((_DWORD *)this)) == 0 )
  {
    v4 = *(_DWORD *)(this + 32) & 0x7FFFFFFF;
    v5 = v4;
    if ( !v4 )
      v5 = 1;
    v6 = v5 != *(_DWORD *)(this + 8) + 1 ? *(_DWORD *)(this + 8) + 1 : 0;
    if ( v4 <= 1 )
    {
      if ( v4 )
        v7 = this + 36;
      else
        v7 = 0;
    }
    else
    {
      v7 = *(_DWORD *)(this + 36);
    }
    v8 = v7 + 20 * v6;
    while ( *(int *)(v8 + 16) > 0 )
      PhyreThread_Sleep(1u);
    result = sub_597CF0(v6, a2);
    if ( !result )
      *(_BYTE *)(this + 4) = 2;
  }
  return result;
}

