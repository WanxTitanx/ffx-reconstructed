// Function: sub_882720
// Address: 0x882720
int __cdecl sub_882720(int a1, int a2)
{
  int result; // eax

  sub_88FA60(a1 + 4, a2 + 2);
  sub_88F450(unk_1328A34, 0, &unk_B5D760);
  switch ( sub_873A40() )
  {
    case 0:
      result = sub_88F450(unk_1328A34, 0, &unk_B5D76C);
      break;
    case 2:
      result = sub_88F450(unk_1328A34, 0, &unk_B5D77C);
      break;
    case 3:
      result = sub_88F450(unk_1328A34, 0, &unk_B5D790);
      break;
    case 4:
      result = sub_88F450(unk_1328A34, 0, &unk_B5D7A0);
      break;
    default:
      result = sub_88F450(unk_1328A34, 0, &unk_B5D7B0);
      break;
  }
  return result;
}
