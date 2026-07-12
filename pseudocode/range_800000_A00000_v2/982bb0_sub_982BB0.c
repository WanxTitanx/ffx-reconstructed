// Function: sub_982BB0
// Address: 0x982bb0
float *__thiscall sub_982BB0(float *this)
{
  float v2; // [esp+4h] [ebp-14h]
  float v3; // [esp+4h] [ebp-14h]
  float v4; // [esp+4h] [ebp-14h]
  float v5; // [esp+8h] [ebp-10h]
  float v6; // [esp+Ch] [ebp-Ch]
  float v7; // [esp+10h] [ebp-8h]
  float v8; // [esp+14h] [ebp-4h]

  v7 = *(this + 1);
  v8 = *this;
  v6 = *(this + 2);
  v5 = *(this + 3);
  v2 = v8 * v8 + v7 * v7 + v6 * v6 + v5 * v5;
  v3 = sqrt(v2);
  v4 = 1.0 / v3;
  *this = v8 * v4;
  *(this + 1) = v7 * v4;
  *(this + 2) = v6 * v4;
  *(this + 3) = v4 * v5;
  return this;
}
