// Function: sub_89DB10
// Address: 0x89db10
int __cdecl sub_89DB10(float a1, int a2)
{
  int v2; // esi
  int v3; // eax
  int v5; // [esp-14h] [ebp-18h]
  _WORD *v6; // [esp-Ch] [ebp-10h]

  v2 = 16 * LODWORD(a1);
  v6 = (_WORD *)((char *)&unk_133F4DE + 16 * LODWORD(a1));
  *v6 = 0;
  *(_WORD *)((char *)&unk_133F4DC + v2) = 0;
  v3 = a2;
  v5 = a2;
  *(_DWORD *)((char *)&unk_133F4D0 + v2) = 1;
  *(_DWORD *)((char *)&n7_0 + v2) = 7;
  *(_DWORD *)((char *)&unk_133F4D8 + v2) = v3;
  sub_8B9600(7, v5, &a1, v6, 1, 0);
  *(_WORD *)((char *)&unk_133F4DC + v2) = (int)a1;
  return 1;
}
