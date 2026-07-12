// Function: FFX_Abmap_SaveMenuRuntimeToSphereGridState
// Address: 0xa5bb70
// Size: 0x127
// Prototype: int()

// [Jarvis naming goal 2026-06-17] Saves ABMAP menu runtime back to Sphere Grid state table on exit path.
int FFX_Abmap_SaveMenuRuntimeToSphereGridState()
{
  _BYTE *RuntimeStateTable; // eax
  int v1; // ecx
  _BYTE *RuntimeStateTable_1; // edi
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // esi
  int result; // eax

  RuntimeStateTable = FFX_SphereGrid_GetRuntimeStateTable(); /*0xa5bb72*/
  v1 = dword_2305834[0]; /*0xa5bb77*/
  RuntimeStateTable_1 = RuntimeStateTable; /*0xa5bb7d*/
  v3 = 0; /*0xa5bb81*/
  if ( *(__int16 *)(dword_2305834[0] + 2) > 0 ) /*0xa5bb87*/
  {
    v4 = 0; /*0xa5bb89*/
    do /*0xa5bbb7*/
    {
      RuntimeStateTable[2 * v3] = *(_BYTE *)(v4 + v1 + 2062); /*0xa5bb98*/
      RuntimeStateTable[2 * v3 + 1] = *(_BYTE *)(v4 + v1 + 2089); /*0xa5bba3*/
      v1 = dword_2305834[0]; /*0xa5bba7*/
      ++v3; /*0xa5bbad*/
      v4 += 40; /*0xa5bbb2*/
    }
    while ( v3 < *(__int16 *)(dword_2305834[0] + 2) ); /*0xa5bbb7*/
  }
  v5 = 0; /*0xa5bbbb*/
  if (... [2212 chars total]