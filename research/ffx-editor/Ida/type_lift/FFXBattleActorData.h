#pragma pack(push, 1)
struct FFXBattleActorData {
  int modelHandle; /* +0x000 */
  int fieldAttachId; /* +0x004 */
  int characterId; /* +0x008 */
  unsigned __int8 actorSlotIndex; /* +0x00C */
  char _pad0D; /* +0x00D */
  __int16 formId; /* +0x00E */
  char pad16[20]; /* +0x010 */
  unsigned __int8 isReadyToSpawn; /* +0x024 */
  char pad37[971]; /* +0x025 */
  unsigned __int8 pendingCommandId; /* +0x3F0 */
  char pad1009; /* +0x3F1 */
  __int16 actionTargetSlot; /* +0x3F2 */
  unsigned __int8 hasActiveAction; /* +0x3F4 */
  char pad1012; /* +0x3F5 */
  unsigned __int8 prevStateCache; /* +0x3F6 */
  unsigned __int8 sourceStateValue; /* +0x3F7 */
  char pad1015[44]; /* +0x3F8 */
  unsigned __int8 currentMotionId; /* +0x424 */
  char pad1060[37]; /* +0x425 */
  unsigned __int8 menuActionState; /* +0x44A */
  char pad1098[5]; /* +0x44B */
  unsigned __int8 commandSubMode; /* +0x450 */
  unsigned __int8 actionLockedFlag; /* +0x451 */
  char pad1105[138]; /* +0x452 */
  float maxHp; /* +0x4DC */
  float maxMp; /* +0x4E0 */
  char pad1436[10]; /* +0x4E4 */
  unsigned __int8 turnDamagePercent; /* +0x4EE */
  char pad1467[7]; /* +0x4EF */
  unsigned __int8 commandStyle; /* +0x4F6 */
  unsigned __int8 commandStyleCounter; /* +0x4F7 */
  char pad1476[68]; /* +0x4F8 */
  unsigned __int8 statusFlagA; /* +0x53C */
  unsigned __int8 statusFlagB; /* +0x53D */
  unsigned __int8 statusFlagC; /* +0x53E */
  char pad1547[50]; /* +0x53F */
  unsigned __int8 overdriveActionState; /* +0x571 */
  unsigned __int8 overdriveLevel; /* +0x572 */
  char pad1600[28]; /* +0x573 */
  unsigned __int8 preDeathStateCache; /* +0x58F */
  unsigned __int8 preDeathSourceValue; /* +0x590 */
  char _pad591[3]; /* +0x591 */
  int maxHpStat; /* +0x594 */
  int maxMpStat; /* +0x598 */
  char _pad59C[3]; /* +0x59C */
  unsigned __int8 reflectActiveFlag; /* +0x59F */
  char pad1739_pre[8]; /* +0x5A0 */
  unsigned __int8 strength; /* +0x5A8 */
  unsigned __int8 defense; /* +0x5A9 */
  unsigned __int8 magic; /* +0x5AA */
  unsigned __int8 magicDefense; /* +0x5AB */
  unsigned __int8 agility; /* +0x5AC */
  unsigned __int8 luck; /* +0x5AD */
  unsigned __int8 evasion; /* +0x5AE */
  unsigned __int8 accuracy; /* +0x5AF */
  char unk_5B0[8]; /* +0x5B0 */
  unsigned __int8 deathVsZombieFlag; /* +0x5B8 */
  char unk_5B9; /* +0x5B9 */
  unsigned __int8 poisonTickHpPercent; /* +0x5BA */
  char unk_5BB; /* +0x5BB */
  unsigned __int8 odGauge; /* +0x5BC */
  unsigned __int8 odGaugeMax; /* +0x5BD */
  char unk_5BE[2]; /* +0x5BE */
  char unk_5C0[4]; /* +0x5C0 */
  unsigned __int8 provokeAggressorSlot; /* +0x5C4 */
  unsigned __int8 threatenAggressorSlot; /* +0x5C5 */
  char unk_5C6[10]; /* +0x5C6 */
  int currentHp; /* +0x5D0 */
  int currentMp; /* +0x5D4 */
  char unk_5D8[6]; /* +0x5D8 */
  unsigned __int8 equipStatusInflict[25]; /* +0x5DE */
  unsigned __int8 equipStatusInflictDur[13]; /* +0x5F7 */
  unsigned __int16 equipStatusInflictExtra; /* +0x604 */
  unsigned __int16 sufferStatusWord; /* +0x606 */
  unsigned __int8 statusDurationSlots[13]; /* +0x608 */
  char unk_615; /* +0x615 */
  unsigned __int16 statusExtraFlags; /* +0x616 */
  unsigned __int16 sufferStatusWordUndo; /* +0x618 */
  unsigned __int8 statusDurationUndo[13]; /* +0x61A */
  char unk_627; /* +0x627 */
  unsigned __int16 statusExtraFlagsUndo; /* +0x628 */
  unsigned __int16 stagingStatusWords[3]; /* +0x62A */
  unsigned __int16 innateStatusWords[3]; /* +0x630 */
  unsigned __int16 sosStatusWords[3]; /* +0x636 */
  unsigned __int8 hasSosAbility; /* +0x63C */
  unsigned __int8 derivedActionState; /* +0x63D */
  unsigned __int8 hpTier; /* +0x63E */
  unsigned __int8 prevHpTier; /* +0x63F */
  unsigned __int8 itemBuffs; /* +0x640 */
  unsigned __int8 statusResist[25]; /* +0x641 */
  unsigned __int16 statusResistExtra; /* +0x65A */
  unsigned __int8 ctbFinalWaitValue; /* +0x65C */
  unsigned __int8 ctbWaitTimeBase; /* +0x65D */
  unsigned __int8 strChargeLevel; /* +0x65E */
  unsigned __int8 defChargeLevel; /* +0x65F */
  unsigned __int8 magChargeLevel; /* +0x660 */
  unsigned __int8 mdefChargeLevel; /* +0x661 */
  unsigned __int8 agiChargeLevel; /* +0x662 */
  unsigned __int8 luckChargeLevel; /* +0x663 */
  char unk_664[44]; /* +0x664 */
  unsigned __int16 statusBitmaskGroup[16]; /* +0x690 */
  char unk_6B0[12]; /* +0x6B0 */
  unsigned __int16 autoAbilityEffectsMap[3]; /* +0x6BC */
  __int16 statusBitfieldB; /* +0x6C2 */
  char unk_6C4[14]; /* +0x6C4 */
  unsigned __int8 ctbTickAge; /* +0x6D2 */
  char unk_6D3[14]; /* +0x6D3 */
  unsigned __int8 odSecondaryCounter; /* +0x6E1 */
  char unk_6E2[2]; /* +0x6E2 */
  int currentStrength; /* +0x6E4 */
  int currentMagic; /* +0x6E8 */
  int currentAgility; /* +0x6EC */
  char pad6F0[4]; /* +0x6F0 */
  int maxComputedStat; /* +0x6F4 */
  char unk_6F8[9]; /* +0x6F8 */
  unsigned __int8 selectedDeathType; /* +0x701 */
  char unk_702[18]; /* +0x702 */
  unsigned __int8 odOverrideEnable; /* +0x714 */
  unsigned __int8 odOverrideSelector; /* +0x715 */
  char unk_716[16]; /* +0x716 */
  char odSecondaryCounterInc[2]; /* +0x726 */
  char odGaugeInc[2]; /* +0x728 */
  char unk_72A[2]; /* +0x72A */
  int inlineActionId; /* +0x72C */
  char pad730[124]; /* +0x730 */
  int overdriveGauge; /* +0x7AC */
  unsigned __int8 pad7B0; /* +0x7B0 */
  unsigned __int8 damageFlag; /* +0x7B1 */
  char pad7B2[24]; /* +0x7B2 */
  unsigned __int8 hasQueuedAction; /* +0x7CA */
  unsigned __int8 subStateMode; /* +0x7CB */
  char pad7CC[2]; /* +0x7CC */
  unsigned __int8 lastDamageSourceActorId; /* +0x7CE */
  char pad7CF[2]; /* +0x7CF */
  unsigned __int8 actorTurnState; /* +0x7D1 */
  char pad7D2; /* +0x7D2 */
  unsigned __int8 turnSkipFlag; /* +0x7D3 */
  char pad7D4[5]; /* +0x7D4 */
  unsigned __int8 postDamageFlag; /* +0x7D9 */
  char pad7DA[2]; /* +0x7DA */
  unsigned __int8 mainStateMode; /* +0x7DC */
  char pad7DD[27]; /* +0x7DD */
  unsigned __int8 actionRingIndex; /* +0x7F8 */
  char unk_7F9[181]; /* +0x7F9 */
  unsigned __int8 agilityCtb; /* +0x8AE */
  char unk_8AF[144]; /* +0x8AF */
  unsigned __int8 statusBitfieldA; /* +0x93F */
  char unk_940[996]; /* +0x940 */
  char unk_D24[16]; /* +0xD24 */
  unsigned int resultRow2Accum[3]; /* +0xD34 */
  char unk_D40[136]; /* +0xD40 */
  unsigned __int8 inBattleFlag; /* +0xDC8 */
  char unk_DC9[3]; /* +0xDC9 */
  unsigned __int8 deathStateSeq; /* +0xDCC */
  char unk_DCD[7]; /* +0xDCD */
  unsigned __int8 actionDisabledFlag; /* +0xDD4 */
  char unk_DD5; /* +0xDD5 */
  unsigned __int8 canActFlag; /* +0xDD6 */
  unsigned __int8 inCtbList; /* +0xDD7 */
  char unk_DD8[13]; /* +0xDD8 */
  unsigned __int8 actionSlot; /* +0xDE5 */
  unsigned __int8 pendingActionRingCount; /* +0xDE6 */
  char unk_DE7; /* +0xDE7 */
  unsigned __int8 pendingActionRank; /* +0xDE8 */
  char unk_DE9[15]; /* +0xDE9 */
  unsigned __int8 swappedInFlag; /* +0xDF8 */
  char unk_DF9[55]; /* +0xDF9 */
  unsigned int actorStateKeys[88]; /* +0xE30 */
};
#pragma pack(pop)
