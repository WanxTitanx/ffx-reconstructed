// Function: sub_A58080
// Address: 0xa58080
// Size: 0x153

int __cdecl sub_A58080(int a1)
{
  int v1; // edi
  unsigned int v2; // esi
  __int16 v3; // cx
  __int16 v4; // ax
  int result; // eax

  v1 = 80 * a1 + dword_2305834[0] + 69768; /*0xa5809a*/
  v2 = (unsigned __int16)((*(unsigned __int8 *)(v1 + 78) << 14) + 0x2000); /*0xa580b2*/
  sub_A47C60((__int16 *)v1); /*0xa580b5*/
  *(float *)(v1 + 16) = flt_C44BE0[((int)(v2 + 0x4000) >> 4) & 0xFFF] * *(float *)(v1 + 60) + *(float *)v1; /*0xa580dc*/
  *(float *)(v1 + 20) = *(float *)(v1 + 4) - flt_C44BE0[v2 >> 4] * *(float *)(v1 + 60); /*0xa580ee*/
  *(float *)(v1 + 24) = 0.0; /*0xa580f3*/
  *(float *)(v1 + 28) = 1.0; /*0xa580f8*/
  if ( (*(_BYTE *)(v1 + 78) & 4) != 0 ) /*0xa58101*/
  {
    v3 = unk_2305818; /*0xa58110*/
    v4 = unk_2305814; /*0xa58116*/
  }
  else
  {
    v3 = unk_2305820; /*0xa58103*/
    v4 = unk_230581C; /*0xa58109*/
  }
  switch ( *(_BYTE *)(v1 + 78) & 3 ) /*0xa5812a*/
  {
    case 0: /*0xa5812a*/
      *(_WORD *)(v1 + 72) = -v4; /*0xa58133*/
      *(_WORD *)(v1 + 70) = v... [2144 chars total]