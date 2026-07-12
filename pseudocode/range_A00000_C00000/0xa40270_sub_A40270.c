// Function: sub_A40270
// Address: 0xa40270
// Size: 0x1cb
// Prototype: 

_DWORD *sub_A40270()
{
  int v0; // eax
  _DWORD *Singleton; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  int v4; // eax
  int v5; // eax

  Phyre_TypeRegistry_Register(Size_8);
  v0 = dword_1A85A58;
  unk_1A85A20 |= 0x10u;
  if ( (dword_1A85A58 & 1) == 0 )
  {
    dword_1A85A58 |= 1u;
    Singleton = Phyre_PTypeDefault_Uint32_GetSingleton();
    Phyre_PClassDataMember_Init(dword_1A85A2C, (size_t)Size_8, (int)Singleton, "m_planeCount", 0, 0, 0);
    atexit(sub_B0BA30);
    v0 = dword_1A85A58;
  }
  if ( (v0 & 2) == 0 )
  {
    dword_1A85A58 = v0 | 2;
    v2 = Phyre_PTypeDefault_Uint32_GetSingleton();
    Phyre_PClassDataMember_Init(dword_1A85A5C, (size_t)Size_8, (int)v2, "m_vertexCount", 4, 0, 0);
    atexit(sub_B0BA40);
    v0 = dword_1A85A58;
  }
  if ( (v0 & 4) == 0 )
  {
    dword_1A85A58 = v0 | 4;
    v3 = Phyre_PTypeDefault_Uint32_GetSingleton();
    Phyre_PClassDataMember_Init(dword_1A85A88, (size_t)Size_8, (int)v3, "m_edgeCount", 8, 0, 0);
    atexit(sub_B0BA00);
    v0 = dword_1A85A58;
  }
  if ( (v0 & 8) == 0 )
  {
    dword_1A85A58 = v0 | 8;
    v4 = sub_45FE40();
    Phyre_PClassDataMember_Init(dword_1A85AB4, (size_t)Size_8, v4, "m_minBounds", 16, 0, 0);
    atexit(sub_B0BA20);
    v0 = dword_1A85A58;
  }
  if ( (v0 & 0x10) == 0 )
  {
    dword_1A85A58 = v0 | 0x10;
    v5 = sub_45FE40();
    Phyre_PClassDataMember_Init(dword_1A85AE0, (size_t)Size_8, v5, "m_maxBounds", 32, 0, 0);
    atexit(sub_B0BA10);
  }
  return Phyre_PClassDescriptor_RegisterWithNamespace((int)Size_8);
}

