// Function: sub_A44A50
// Address: 0xa44a50
// Size: 0xdd
// Prototype: 

BOOL __thiscall sub_A44A50(char *this, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  _DWORD *v6; // esi
  int v7; // eax
  HANDLE *v9; // [esp+20h] [ebp+14h]

  v9 = (HANDLE *)(this + 488 * a5);
  WaitForSingleObject(v9[141], 0xFFFFFFFF);
  WaitForSingleObject(v9[127], 0xFFFFFFFF);
  v5 = ((int)v9[124] + 7) % 8;
  v9[126] = (char *)v9[126] - 1;
  v9[124] = (HANDLE)v5;
  v6 = v9[v5 + 116];
  ReleaseSemaphore(v9[127], 1, 0);
  v6[2] = a2;
  v6[8] = a4;
  v6[5] = a3;
  v6[6] = v6 + 8;
  v6[4] = 2;
  WaitForSingleObject(v9[139], 0xFFFFFFFF);
  v7 = ((int)v9[137] + 7) % 8;
  v9[137] = (HANDLE)v7;
  v9[v7 + 128] = v6;
  v9[138] = (char *)v9[138] + 1;
  ReleaseSemaphore(v9[139], 1, 0);
  return ReleaseSemaphore(v9[140], 1, 0);
}

