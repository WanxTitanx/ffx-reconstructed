// Function: sub_81D050
// Address: 0x81d050
int __cdecl sub_81D050(int a1, int a2, int a3)
{
  FILE *v3; // eax
  const char *FMOD_SFX_ERROR!_There_are_battle_streaming_sound_is_started!!!_; // [esp-4h] [ebp-4h]

  if ( n670 == -1 )
  {
    FMOD_SFX_ERROR!_There_are_battle_streaming_sound_is_started!!!_ = "FMOD SFX ERROR! There are battle streaming sound is started!!!\n";
LABEL_5:
    v3 = __iob_func();
    return fprintf(v3 + 2, FMOD_SFX_ERROR!_There_are_battle_streaming_sound_is_started!!!_);
  }
  if ( dword_C49498 == -1 )
  {
    FMOD_SFX_ERROR!_There_are_battle_streaming_sound_is_started!!!_ = "FMOD SFX ERROR! Try to start battle streaming soun"
                                                                      "d without set sequence id!!!\n";
    goto LABEL_5;
  }
  return sub_67A550(dword_C49498, a3, a2);
}
