// Function: sub_8E24C0
// Address: 0x8e24c0
int __cdecl sub_8E24C0(int a1)
{
  int v1; // esi
  int result; // eax

  unk_187150C = -1;
  v1 = sub_8E2270(a1);
  switch ( v1 )
  {
    case 0:
      sub_8AA0B0(3, 0);
      sub_8AAD20(1);
      result = v1;
      break;
    case 1:
      sub_8AA0B0(2, 0);
      sub_8AAD20(1);
      result = v1;
      break;
    case 2:
      sub_8AA0B0(4, 0);
      sub_8AAD20(1);
      result = v1;
      break;
    case 4:
      sub_8AA0B0(6, 0);
      sub_8AAD20(1);
      result = v1;
      break;
    case 5:
      sub_8AA0B0(7, 0);
      sub_8AAD20(1);
      result = v1;
      break;
    case 7:
      sub_8AA0B0(9, 0);
      sub_8AAD20(1);
      goto LABEL_12;
    case 8:
      sub_8AA0B0(10, 0);
      sub_8AAD20(1);
      result = v1;
      break;
    case 10:
      sub_8AA0B0(15, 0);
      sub_8AAD20(1);
      result = v1;
      break;
    case 15:
      sub_8AA0B0(21, 0);
      sub_8AAD20(1);
      result = v1;
      break;
    case 20:
      sub_8AA0B0(20, 0);
      sub_8AAD20(1);
      result = v1;
      break;
    default:
LABEL_12:
      result = v1;
      break;
  }
  return result;
}
