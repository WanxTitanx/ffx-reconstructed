// Function: sub_A24B00
// Address: 0xa24b00
// Size: 0x18d
// Prototype: 

int __thiscall sub_A24B00(int *this)
{
  int v2; // edi
  int v3; // edi
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi

  v2 = *(this + 4082);
  if ( v2 )
  {
    if ( (unsigned __int8)sub_596100(*(this + 4082)) )
      sub_59C6D0(v2);
    v3 = *(this + 4082);
    if ( v3 )
    {
      sub_49FAE0();
      Phyre_Memory_AlignedFree(v3);
    }
    *(this + 4082) = 0;
  }
  v4 = *(this + 4083);
  if ( v4 )
  {
    if ( (unsigned __int8)sub_596100(*(this + 4083)) )
      sub_59C6D0(v4);
    v5 = *(this + 4083);
    if ( v5 )
    {
      sub_49FAE0();
      Phyre_Memory_AlignedFree(v5);
    }
    *(this + 4083) = 0;
  }
  v6 = *(this + 4084);
  if ( v6 )
  {
    if ( (unsigned __int8)sub_596110(*(this + 4084)) )
      sub_59CBF0(v6);
    v7 = *(this + 4084);
    if ( v7 )
    {
      sub_501E30();
      Phyre_Memory_AlignedFree(v7);
    }
    *(this + 4084) = 0;
  }
  v8 = *(this + 4085);
  if ( v8 )
  {
    if ( (unsigned __int8)sub_596110(*(this + 4085)) )
      sub_59CBF0(v8);
    v9 = *(this + 4085);
    if ( v9 )
    {
      sub_501E30();
      Phyre_Memory_AlignedFree(v9);
    }
    *(this + 4085) = 0;
  }
  v10 = *(this + 4109);
  if ( v10 )
  {
    if ( (unsigned __int8)sub_596110(*(this + 4109)) )
      sub_59CBF0(v10);
    v11 = *(this + 4109);
    if ( v11 )
    {
      sub_501E30();
      Phyre_Memory_AlignedFree(v11);
    }
    *(this + 4109) = 0;
  }
  v12 = *(this + 4110);
  if ( v12 )
  {
    if ( (unsigned __int8)sub_596110(*(this + 4110)) )
      sub_59CBF0(v12);
    v13 = *(this + 4110);
    if ( v13 )
    {
      sub_501E30();
      Phyre_Memory_AlignedFree(v13);
    }
    *(this + 4110) = 0;
  }
  return sub_A24A60(this);
}

