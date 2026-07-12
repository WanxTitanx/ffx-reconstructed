// Function: sub_9B4D20
// Address: 0x9b4d20
void __thiscall sub_9B4D20(int this)
{
  float v1; // [esp-10h] [ebp-1Ch]
  float v2; // [esp-Ch] [ebp-18h]
  float v3; // [esp-8h] [ebp-14h]

  if ( (*(_BYTE *)(this + 216) & 3) == 0 )
  {
    v1 = *(float *)(this + 368) * *(float *)(this + 384);
    v2 = *(float *)(this + 372) * *(float *)(this + 388);
    v3 = *(float *)(this + 376) * *(float *)(this + 392);
    *(float *)(this + 432) = *(float *)(this + 432) + v1;
    *(float *)(this + 436) = v2 + *(float *)(this + 436);
    *(float *)(this + 440) = v3 + *(float *)(this + 440);
  }
}
