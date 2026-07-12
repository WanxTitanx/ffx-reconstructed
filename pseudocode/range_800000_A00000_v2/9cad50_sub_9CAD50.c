// Function: sub_9CAD50
// Address: 0x9cad50
const char *__thiscall sub_9CAD50(float *this, float *a2, int a3)
{
  float *v4; // eax
  float *v5; // ecx
  int n3; // edx
  float *v7; // eax
  float *v8; // ecx
  int n3_1; // edx

  sub_9D4B80(a2, a3);
  v4 = a2 + 12;
  v5 = this + 87;
  n3 = 3;
  do
  {
    v4 += 4;
    *(v4 - 5) = *(v5 - 3);
    v5 += 4;
    *(v4 - 4) = *(float *)((char *)v4 + (char *)(this + 84) - (char *)(a2 + 11) - 16);
    *(v4 - 3) = *(v5 - 5);
    *(v4 - 2) = *(v5 - 4);
    --n3;
  }
  while ( n3 );
  a2[23] = *(this + 96);
  v7 = a2 + 28;
  a2[24] = *(this + 97);
  v8 = this + 103;
  a2[25] = *(this + 98);
  n3_1 = 3;
  a2[26] = *(this + 99);
  do
  {
    v7 += 4;
    *(v7 - 5) = *(v8 - 3);
    v8 += 4;
    *(v7 - 4) = *(float *)((char *)v7 + (char *)(this + 100) - (char *)(a2 + 27) - 16);
    *(v7 - 3) = *(v8 - 5);
    *(v7 - 2) = *(v8 - 4);
    --n3_1;
  }
  while ( n3_1 );
  a2[39] = *(this + 112);
  a2[40] = *(this + 113);
  a2[41] = *(this + 114);
  a2[42] = *(this + 115);
  a2[43] = *(this + 120);
  a2[44] = *(this + 121);
  a2[45] = *(this + 122);
  a2[46] = *(this + 116);
  a2[47] = *(this + 117);
  a2[48] = *(this + 118);
  a2[49] = *(this + 119);
  return "btConeTwistConstraintData";
}
