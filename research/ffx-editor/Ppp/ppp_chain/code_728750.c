// Jarvis-HEAVY H01: allocates PPP draw record from six pools. Record stride is 0x214 bytes; ApplyPppDrawableColors writes source record pointer + channel data into returned block.
// FFX MagicHost: Alloc PPP draw record
int __cdecl FFX_MagicHost_AllocPppDrawRecord(int a1)
{
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; // edx
  int n100000; // eax
  int v3; // ecx

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = -1;// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x728753*/
  n100000 = 100000; /*0x728760*/
  if ( dword_CEC198[6] < 342 && dword_CEC198[12] < 100000 ) /*0x72876f*/
  {
    n100000 = dword_CEC198[12]; /*0x728771*/
    [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = 0; /*0x728773*/
  }
  if ( dword_CEC198[7] < 342 && n100000 > dword_CEC198[13] ) /*0x728789*/
  {
    n100000 = dword_CEC198[13]; /*0x72878b*/
    [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = 1; /*0x72878d*/
  }
  if ( dword_CEC198[8] < 342 && n100000 > dword_CEC198[14] ) /*0x7287a6*/
  {
    n100000 = dword_CEC198[14]; /*0x7287a8*/
    [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = 2; /*0x7287aa*/
  }
  if ( dword_CEC198[9] < 342 && n100000 > dword_CEC198[15] ) /*0x7287c3*/
  {
    n100000 = dword_CEC198[15]; /*0x7287c5*/
    [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = 3; /*0x7287c7*/
  }
  if ( dword_CEC198[10] < 342 && n100000 > dword_CEC198[16] ) /*0x7287e0*/
  {
    n100000 = dword_CEC198[16]; /*0x7287e2*/
    [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = 4; /*0x7287e4*/
  }
  if ( dword_CEC198[11] < 342 && n100000 > dword_CEC198[17] ) /*0x7287fb*/
  {
    [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = 5; /*0x7287fd*/
LABEL_19:
    ++dword_CEC198[[Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg + 6]; /*0x728802*/
    v3 = 532 * dword_CEC198[[Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg + 6]; /*0x728813*/
    dword_CEC198[[Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg + 12] += a1; /*0x728819*/
    return v3 + dword_CEC198[[Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg] - 532; /*0x72882f*/
  }
  if ( [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg != -1 ) /*0x728833*/
    goto LABEL_19; /*0x728833*/
  return 0; /*0x72882e*/
}