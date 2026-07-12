// Function: sub_9B5BF0
// Address: 0x9b5bf0
float *__thiscall sub_9B5BF0(float *this, float a2, float a3)
{
  float *p_n1065353216; // eax
  bool v4; // cc
  float *p_n1065353216_1; // eax
  int n1065353216; // [esp+0h] [ebp-8h] BYREF
  int v7; // [esp+4h] [ebp-4h] BYREF

  n1065353216 = 1065353216;
  v7 = 0;
  if ( a2 >= 0.0 )
  {
    p_n1065353216 = (float *)&n1065353216;
    if ( a2 <= 1.0 )
      p_n1065353216 = &a2;
  }
  else
  {
    p_n1065353216 = (float *)&v7;
  }
  v4 = a3 >= 0.0;
  *(this + 116) = *p_n1065353216;
  n1065353216 = 1065353216;
  a2 = 0.0;
  if ( v4 )
  {
    p_n1065353216_1 = (float *)&n1065353216;
    if ( a3 <= 1.0 )
      p_n1065353216_1 = &a3;
    *(this + 117) = *p_n1065353216_1;
  }
  else
  {
    *(this + 117) = a2;
    return &a2;
  }
  return p_n1065353216_1;
}
