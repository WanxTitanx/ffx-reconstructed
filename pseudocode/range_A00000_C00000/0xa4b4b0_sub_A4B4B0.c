// Function: sub_A4B4B0
// Address: 0xa4b4b0
// Size: 0x29e
// Prototype: 

int sub_A4B4B0()
{
  int v0; // eax
  int v1; // edi
  _DWORD *v2; // esi
  int v3; // ebx
  unsigned __int8 v4; // al
  unsigned __int8 *v5; // edi
  int v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+0h] [ebp-10h]
  unsigned __int8 v9; // [esp+Fh] [ebp-1h]

  v0 = FFX_Memory_Alloc(0x1ECu, v7);
  v1 = dword_2305834[0];
  v2 = (_DWORD *)v0;
  v3 = *(__int16 *)(dword_2305834[0] + 4);
  v4 = 1 << *(_BYTE *)(dword_2305834[0] + 71100);
  v2[122] = 12288;
  v9 = v4;
  if ( v3 )
  {
    v5 = (unsigned __int8 *)(v1 + 43029);
    do
    {
      --v3;
      if ( (v4 & *(v5 - 1)) != 0 )
      {
        if ( v5 - 13 == *(unsigned __int8 **)(dword_2305834[0] + 71160) )
        {
          switch ( *(_BYTE *)(dword_2305834[0] + 71100) )
          {
            case 0:
              v2[80] = &unk_1000100;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 1:
              v2[80] = &unk_1000200;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 2:
              v2[80] = &unk_1000000;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 3:
              v2[80] = &unk_1000001;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 4:
              v2[80] = &unk_1000201;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 5:
              v2[80] = &unk_1000101;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 6:
              v2[80] = &unk_1000300;
              goto LABEL_13;
            default:
              goto LABEL_13;
          }
        }
        else
        {
          switch ( *(_BYTE *)(dword_2305834[0] + 71100) )
          {
            case 0:
              v2[80] = 256;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 1:
              v2[80] = 512;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 2:
              v2[80] = 0;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 3:
              v2[80] = 1;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 4:
              v2[80] = 513;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 5:
              v2[80] = 257;
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
            case 6:
              v2[80] = 768;
              goto LABEL_13;
            default:
LABEL_13:
              sub_A521A0(v2, *(_DWORD *)(v5 + 3), *v5);
              break;
          }
        }
      }
      else
      {
        v2[80] = v2[88];
        v2[81] = v2[89];
        v2[82] = v2[90];
        v2[83] = v2[91];
        v2[84] = v2[92];
        v2[85] = v2[93];
        v2[86] = v2[94];
        v2[87] = v2[95];
        sub_A51720(v2, *(_DWORD *)(v5 + 3), *v5);
      }
      v4 = v9;
      v5 += 20;
    }
    while ( v3 );
  }
  return FFX_Memory_Delete((int)v2, v8);
}

