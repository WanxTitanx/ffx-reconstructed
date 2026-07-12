// Function: sub_93C150
// Address: 0x93c150
int __cdecl sub_93C150(int a1, int n50)
{
  int result; // eax

  *(_DWORD *)(unk_193C0F0 + 3048) = a1;
  *(_DWORD *)(unk_193C0F0 + 3052) = n50;
  sub_849B60(*(_DWORD *)(unk_193C0F0 + 3048), n50);
  *(_DWORD *)(unk_193C0F0 + 3056) = 1;
  *(_DWORD *)(unk_193C0F0 + 3060) = sub_849AE0(*(_DWORD *)(unk_193C0F0 + 3048));
  result = sub_849AF0(*(_DWORD *)(unk_193C0F0 + 3048));
  *(_DWORD *)(unk_193C0F0 + 3064) = result;
  return result;
}
