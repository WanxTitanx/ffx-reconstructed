// Function: FFX_Abmap_ApplySphereGridStateToMenuRuntime
// Address: 0xa49590
// Size: 0x204
// Prototype: int()

// [Jarvis naming goal 2026-06-17] Applies Sphere Grid runtime state table onto menu runtime nodes/content/status.
int FFX_Abmap_ApplySphereGridStateToMenuRuntime()
{
  _BYTE *RuntimeStateTable; // eax
  __int16 *v1; // ecx
  _BYTE *RuntimeStateTable_1; // edi
  int v3; // esi
  int v4; // edx
  unsigned __int8 v5; // al
  int v6; // edx
  int v7; // esi
  double v8; // st7
  double v9; // st7
  int result; // eax
  float v11; // [esp+8h] [ebp-4h]
  float v12; // [esp+8h] [ebp-4h]

  RuntimeStateTable = FFX_SphereGrid_GetRuntimeStateTable();
  v1 = (__int16 *)dword_2305834[0];
  RuntimeStateTable_1 = RuntimeStateTable;
  v3 = 0;
  if ( *(__int16 *)(dword_2305834[0] + 2) > 0 )
  {
    v4 = 0;
    do
    {
      if ( v1[v4 + 1031] != -1 )
      {
        v5 = RuntimeStateTable_1[2 * v3];
        if ( v5 == 0xFF )
          v1[v4 + 1031] = -1;
        else
          v1[v4 + 1031] = v5;
        HIBYTE(v1[v4 + 1044]) = RuntimeStateTable_1[2 * v3 + 1];
        v1 = (__int16 *)dword_2305834[0];
      }
      ++v3;
      v4 += 20;
    }
    while ( v3 < v1[1] );
  }
  v6 = 0;
  if ( v1[2] > 0 )
  {
    v7 = 0;
    do
    {
      LOBYTE(v1[v7 + 21514]) = RuntimeStateTable_1[v6 + 2560];
      v1 = (__int16 *)dword_2305834[0];
      ++v6;
      v7 += 10;
    }
    while ( v6 < *(__int16 *)(dword_2305834[0] + 4) );
  }
  v1[34918] = *((_WORD *)RuntimeStateTable_1 + 1920);
  *(_WORD *)(dword_2305834[0] + 69916) = *((_WORD *)RuntimeStateTable_1 + 1921);
  *(_WORD *)(dword_2305834[0] + 69996) = *((_WORD *)RuntimeStateTable_1 + 1922);
  *(_WORD *)(dword_2305834[0] + 70076) = *((_WORD *)RuntimeStateTable_1 + 1923);
  *(_WORD *)(dword_2305834[0] + 70156) = *((_WORD *)RuntimeStateTable_1 + 1924);
  *(_WORD *)(dword_2305834[0] + 70236) = *((_WORD *)RuntimeStateTable_1 + 1925);
  *(_WORD *)(dword_2305834[0] + 70316) = *((_WORD *)RuntimeStateTable_1 + 1926);
  *(_BYTE *)(dword_2305834[0] + 71115) = RuntimeStateTable_1[3864];
  *(_BYTE *)(dword_2305834[0] + 71116) = RuntimeStateTable_1[3865];
  if ( *(_BYTE *)(dword_2305834[0] + 71115) )
  {
    if ( *(_BYTE *)(dword_2305834[0] + 71115) == 1 )
    {
      v8 = -3640.0;
      goto LABEL_18;
    }
    if ( *(_BYTE *)(dword_2305834[0] + 71115) == 2 )
    {
      v8 = -7281.0;
      goto LABEL_18;
    }
  }
  v8 = 0.0;
LABEL_18:
  v11 = v8;
  *(_DWORD *)(dword_2305834[0] + 70464) = (int)v11;
  switch ( *(_BYTE *)(dword_2305834[0] + 71116) )
  {
    case 1:
      v9 = 0.5;
      break;
    case 2:
      v9 = 0.25;
      break;
    case 3:
      v9 = 0.125;
      break;
    default:
      v9 = 1.0;
      break;
  }
  v12 = v9;
  *(float *)(dword_2305834[0] + 70488) = v12;
  *(float *)(dword_2305834[0] + 70484) = v12;
  *(float *)(dword_2305834[0] + 70480) = v12;
  result = dword_2305834[0];
  if ( v12 <= 0.375 )
    *(_DWORD *)(dword_2305834[0] + 71344) = -2;
  else
    *(_DWORD *)(dword_2305834[0] + 71344) = 2;
  return result;
}

