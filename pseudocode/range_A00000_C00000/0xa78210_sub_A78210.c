// Function: sub_A78210
// Address: 0xa78210
// Size: 0x5b
// Prototype: 

int __cdecl sub_A78210(int a1, int a2, int *a3)
{
  int n1074266127; // esi
  int result; // eax

  n1074266127 = FFX_FieldVM_PopOperand(a1, a3);
  nullsub_34();
  if ( n1074266127 != 1074266127 && n1074266127 != 1074266128 && n1074266127 != 1074266129
    || (result = sub_860A30()) != 0 )
  {
    result = sub_821870(n1074266127);
  }
  unk_22FB4D4 = 1;
  return result;
}

