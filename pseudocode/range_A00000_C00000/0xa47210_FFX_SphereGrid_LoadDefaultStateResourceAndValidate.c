// Function: FFX_SphereGrid_LoadDefaultStateResourceAndValidate
// Address: 0xa47210
// Size: 0x1bd
// Prototype: int()

// [Jarvis naming goal 2026-06-17 pass2] Loads/validates Sphere Grid default-state resources 17/18/19 against runtime state table masks; separate from layout resources 9/10/11.
int FFX_SphereGrid_LoadDefaultStateResourceAndValidate()
{
  char v0; // bl
  int v1; // eax
  void (__cdecl **CoreWorkPtr)(int); // esi
  int RuntimeStateTable; // eax
  unsigned __int8 *v4; // ecx
  int n7; // esi
  int v6; // edi
  unsigned __int8 *v7; // edx
  _BYTE *v8; // ecx
  int RuntimeStateTable_3; // esi
  int n255; // eax
  int RuntimeStateTable_4; // edx
  int v12; // esi
  unsigned __int8 *v13; // ebx
  _BYTE *v14; // ecx
  int n255_1; // eax
  int RuntimeStateTable_2; // [esp+8h] [ebp-494h]
  int n7_1; // [esp+Ch] [ebp-490h]
  int RuntimeStateTable_1; // [esp+10h] [ebp-48Ch]
  unsigned __int8 *v19; // [esp+14h] [ebp-488h]
  __int16 n49; // [esp+18h] [ebp-484h] BYREF
  _WORD v21[3]; // [esp+1Ah] [ebp-482h] BYREF
  _BYTE v22[1144]; // [esp+20h] [ebp-47Ch] BYREF

  sub_A5A2E0(3); /*0xa47227*/
  sub_A... [3902 chars total]