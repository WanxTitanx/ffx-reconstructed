// Function: sub_A3E730
// Address: 0xa3e730
// Size: 0x8c
// Prototype: 

_DWORD *__thiscall sub_A3E730(_DWORD *this)
{
  _DWORD *v1; // edx
  int v2; // eax

  *this = &Phyre::PUtility::`vftable';
  *(this + 2) = "Text";
  *(this + 3) = 255;
  v1 = dword_C901A8;
  if ( dword_C901A8[0] )
  {
    do
    {
      v2 = *v1;
      if ( *(_DWORD *)(*v1 + 12) >= 0xFFu )
        break;
      v1 = (_DWORD *)(v2 + 4);
    }
    while ( *(_DWORD *)(v2 + 4) );
  }
  *(this + 1) = *v1;
  *v1 = this;
  *this = &Phyre::PText::PUtilityText::`vftable';
  unk_1A858F4 = &unk_1A85920;
  unk_1A858F8 = &unk_1A85930;
  unk_1A858FC = &unk_1A85940;
  unk_1A85900 = &unk_1A85950;
  unk_1A85904 = &unk_1A85960;
  unk_1A85908 = &unk_1A85970;
  unk_1A8590C = &unk_1A85980;
  return this;
}

