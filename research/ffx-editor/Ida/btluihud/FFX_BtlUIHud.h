#pragma pack(push, 1)
struct FFX_BtlUIHud {
  int entryTab; /* +0x0000 VALID: dword at +0 read as list/entry head; cmp==1 gate (DrawSortedActorList 6d378e, CullHud 6c90ee [esi+eax*4]); deref as ptr (EnemyPartyProtoData 6d1bf9) */
  unsigned __int8 readyFlag; /* +0x0004 VALID: byte flag gates body (RenderPostProcessEffect 6d4f7a) */
  unsigned __int8 flag_0005; /* +0x0005 VALID: byte flag gates body (RenderWithPostProcess 6d57da) */
  char pad_0006[2]; /* +0x0006 */
  float hdrFloat_0008; /* +0x0008 VALID: fld [esi+8] (RenderWithPostProcess 6d57f3) */
  char pad_000C[20]; /* +0x000C */
  int listNext_0020; /* +0x0020 VALID: PInstanceList_Init self-link [this+0x20]=&this+0x20 (ctor chain via +4) */
  int listPrev_0024; /* +0x0024 VALID: self-link (ctor) */
  int listCount_0028; /* +0x0028 VALID: zeroed by PInstanceList_Init (+4 obj +9*4) */
  int instanceBlockHead; /* +0x002C VALID: AlignedLinkedListBlock_Init(this+0x2C,76,20,4,"PInstanceList"); head dword read as sub-this (RenderPostProcessEffect 6d4fa3) */
  char pad_0030[4]; /* +0x0030 */
  int listIterEnd_0034; /* +0x0034 SUSPECTED: compared vs walking node (RenderWithPostProcess 6d5810) */
  int field_0038; /* +0x0038 VALID: dword r/w in RenderWithPostProcess (6d5858) */
  char pad_003C[4]; /* +0x003C */
  int listCount_0040; /* +0x0040 VALID: dword read in DrawSortedActorList (6d38bf) */
  int listField_0044; /* +0x0044 VALID: =0 in PInstanceList_Init (+4 obj +16*4) */
  int listField_0048; /* +0x0048 VALID: =3 in PInstanceList_Init (+4 obj +17*4) */
  int nodeNext_004C; /* +0x004C CONFIRMED: ctor self-links [4C]=&[4C] (FFX_ShaderParameter_ProcessGroup 6c7ef5) */
  int nodePrev_0050; /* +0x0050 CONFIRMED: ctor self-links [50]=&[4C] (6c7ef7) */
  char pad_0054[4]; /* +0x0054 */
  int shaderContainerPtr; /* +0x0058 VALID: *([+0x58]+16) deref chain (RenderPostProcessEffect 6d4fc5) */
  int field_005C; /* +0x005C VALID: dword r/w (RenderPostProcessEffect/RenderHudActor) */
  float slotKeyTab[5]; /* +0x0060 VALID: float reads fld [edi+60h..] + dword-indexed [esi+ebx*4+60h] (DrawSortedActorList, RenderHudActor) */
  unsigned int streamFlags_0074; /* +0x0074 VALID: bytes +74/+75 written 0/1 as stream busy flags (RenderPostProcessEffect 6d4f7e); dword cmp==0 (StPtrProto 6d2f25); ctor-zeroed */
  int field_0078; /* +0x0078 VALID: dword cmp (StPtrProto 6d2f2d); ctor-zeroed */
  int field_007C; /* +0x007C VALID: ctor-zeroed dword (ctor 6c7f16-2b) */
  int textureDescPtr; /* +0x0080 VALID: ptr used as this for PTextureDescription_ValidateAndSetConfig (StPtrProto 6d2fc8); ctor-zeroed */
  char pad_0084[0x8C]; /* +0x0084 */
  char protoPool_0110[0x180]; /* +0x0110 SUSPECTED: AtbHpPtrProto writes 16-dword tables at +0x110/+0x190/+0x210 (0x80 stride) */
  char lockA_0290[16]; /* +0x0290 CONFIRMED: eh-vector ctor builds 2x _ReaderWriterLock (8B) here (ctor 6c7f35) */
  char lockB_02A0[16]; /* +0x02A0 CONFIRMED: 2nd pair of _ReaderWriterLock (ctor 6c7f53) */
  char protoPool_02B0[0x208]; /* +0x02B0 SUSPECTED: continues proto pool; 16-dword writes at +0x2B0/+0x330/+0x3B0/+0x430 */
  int slotCountA[64]; /* +0x04B8 VALID: [edi+ebx*4+4B8h] = clamped bucket count >=1 (PartyPtrProto 6d34f4) */
  int slotCountB[64]; /* +0x05B8 VALID: [+ebx*4] second clamped count (PartyPtrProto 6d34fb) */
  float slotFloatC[64]; /* +0x06B8 VALID: float store per slot (PartyPtrProto 6d3428) */
  float slotFloatD[64]; /* +0x07B8 VALID: float store per slot (PartyPtrProto 6d3432) */
  int postFxChain; /* +0x08B8 CONFIRMED: stores Phyre_PostProcessing_EffectChain(this+4) result; read/compared in RenderHudActor (6c9f80), Enemy/OvrProtoData */
  int postFxTab[256]; /* +0x08BC SUSPECTED: dword array indexed ecx*4 (RenderHudActor 6cadfe); bound=gap to 0xCBC */
  int fontCachePtr; /* +0x0CBC CONFIRMED: stores FFX_Scaleform_FontCache(&instanceList,...) (AtbHpPtrProto 6d1d12) */
  char pad_0CC0[4]; /* +0x0CC0 */
  int sortOutA[16]; /* +0x0CC4 CONFIRMED: RadixPass results, [edi]=eax loop (AtbHpPtrProto 6d1cbe) */
  int sortOutB[16]; /* +0x0D04 CONFIRMED: p_m_float3C[16]=v6 (6d1cd1) */
  int sortInA[16]; /* +0x0D44 CONFIRMED: RadixPass arg2 = this+0xD44 (6d1cb0) */
  int sortInB[16]; /* +0x0D84 CONFIRMED: RadixPass arg2 = this+0xD84 (6d1cc0) */
  unsigned __int8 protoFlagA[16]; /* +0x0DC4 VALID: byte[i]=0 loop (6d1cd4) */
  unsigned __int8 protoFlagB[16]; /* +0x0DD4 VALID: byte[i]=0 loop (6d1cd8) */
  int protoListPtr; /* +0x0DE4 VALID: dword obj ptr, deref as _DWORD** (AtbHpPtrProto 6d1d91..) */
  int actorNode[8]; /* +0x0DE8 CONFIRMED: 8 node ptrs iterated (v8=this+0xDE8,+4 step x8; ComputeHudActorScreenPositions 6c8607); memset region start */
  char pad_0E08[0x1E0]; /* +0x0E08 */
  int slotEnableGridA[64]; /* +0x0FE8 CONFIRMED: memset 0x100 (ClearHudActorBuffer 6d18b1 + AtbHpPtrProto 6d1ef9); cmp==1 checks (ComputeHud 6c8622) */
  int slotEnableGridB[64]; /* +0x10E8 CONFIRMED: parallel grid, cmp==1 (ComputeHud 6c8633) */
  int slotGridC[64]; /* +0x11E8 SUSPECTED: dword write 1 (AtbHpPtrProto 6d1fb0 via [eax-100h]) */
  int slotGridD[64]; /* +0x12E8 VALID: [ebx+edi*4+12E8h]=1 (ActorAp 6ce6d4); lea base (HpPtrProto 6d1f84) */
  float uvPairTab[256]; /* +0x13E8 VALID: 8-byte-stride float2 UV pairs for gauge tiles (PartyPtrProto 6d3538 +8*idx; reads at 13EC/13F0/13F4) */
  float slotMatrix[64][16]; /* +0x17E8 VALID: PMatrix4_copy16f into +0x17E8+64*i (PartyPtrProto 6d33fa) - X-rotated transforms per slot; bound=gap */
  float slotScaleA[64]; /* +0x27E8 VALID: float store per slot (PartyPtrProto 6d35fc) */
  float slotScaleB[64]; /* +0x28E8 VALID: 0.5*v70 per slot (PartyPtrProto 6d3606) */
  int slotFlagE[64]; /* +0x29E8 VALID: [+idx*4]==1 selects 10x/20x gauge mult (PartyPtrProto 6d344b) */
  unsigned __int8 slotByteTabF[256]; /* +0x2AE8 VALID: byte reads at +0x2AE9 (ActorAp 6ce632); block at +0x2B68 used by CullHud; char buf at +0x2BA8 cmp 0x63 (ActorActor 6ce89f) */
  char pad_2BE8[0x2C0]; /* +0x2BE8 */
  int slotTabG[64]; /* +0x2EA8 VALID: [ebx+edi*4+2EA8h]=eax store (ActorAp 6ce6f0) */
  char pad_2FA8[4]; /* +0x2FA8 */
  char protoBlocks[0x7FC]; /* +0x2FAC VALID: block bases 0x2FAC/0x2FB4 (RenderHudActor 6ca98d, Enemy/OvrProtoData lea); PartyProtoData strides slot<<0xA into it (6d1949) */
  int slotHandleTab[64]; /* +0x37A8 VALID: [esi+eax*4+37A8h] compared to node ptrs / ==0 (RenderHudActor 6ca96f); bound 64 assumed */
  char pad_38A8[0x700]; /* +0x38A8 */
  char phSharedB[8]; /* +0x3FA8 CONFIRMED: ctor calls Phyre_PSharedPtr_GetRefCount(this+0x3FA8) (6c7f71) */
  int slotHandleTab2[5]; /* +0x3FB0 VALID: [esi+eax*4+3FB0h] compared to node ptrs (RenderHudActor 6ca4ed); lea base (HpPtrProto 6d1fcd) */
  char textureDescA[0x1C]; /* +0x3FC4 CONFIRMED: 5-byte init {1,1,2,2,2} then Phyre_Texture_DeferredCreateFromFormat(this+0x3FC4) (HpPtrProto 6d1e4b-93); ctor shared-ptr init here */
  unsigned int flags_3FE0; /* +0x3FE0 VALID: dword &0x80 create-gate (HpPtrProto 6d1e56) */
  char pad_3FE4[4]; /* +0x3FE4 */
  char textureDescB[0x14]; /* +0x3FE8 CONFIRMED: init {0,0,2,2,2} then DeferredCreateFromFormat(this+0x3FE8) (HpPtrProto 6d1e9e-e6) */
  int field_3FFC; /* +0x3FFC VALID: base of tail-state accesses (StringFormatSkip) */
  char pad_4000[4]; /* +0x4000 */
  unsigned int flags_4004; /* +0x4004 VALID: dword &0x80 create-gate (HpPtrProto 6d1ea9) */
  char pad_4008[4]; /* +0x4008 */
  unsigned __int8 needsInitFlag; /* +0x400C CONFIRMED: set 1 by mode branches (HudActorAll 6ccf60+), consumed->0 in RenderHudActor (6c9fcf/6c9fea) */
  char pad_400D[3]; /* +0x400D */
  int field_4010; /* +0x4010 VALID: =0 init (HpPtrProto 6d1fe7) */
  int field_4014; /* +0x4014 VALID: =0 init (HpPtrProto 6d1fed) */
  float enemyBarPosY; /* +0x4018 CONFIRMED: fstp [ecx+4018h] <- stack arg4 (HudActorActorEnemy 6cebbf); init 90.0 (6d23b5); SUSPECTED axis */
  float enemyBarPosX; /* +0x401C CONFIRMED: fstp [ecx+401Ch] <- stack arg0 (6cebb6); SUSPECTED axis */
  float hudVecA[4]; /* +0x4020 VALID: vec4 set {0,-1,0,0} mode 4798 / {-0.3,-0.7,0.3,0} init (HudActorAll 6ccf42-5a, HpPtrProto 6d23cc-ea) */
  unsigned __int8 flag_4030; /* +0x4030 VALID: byte flag =0/=1 (HudActorAll 6cce68) */
  char pad_4031[3]; /* +0x4031 */
  float hudClipRect[4]; /* +0x4034 VALID: rect = globals {-10,190,170,570} (HudActorAll 6ccf16-3a) */
  unsigned __int8 flag_4044; /* +0x4044 VALID: byte flag =1 (HudActorAll 6cce6f); gates ActorActor (6ce829) */
  char pad_4045[3]; /* +0x4045 */
  int modeFilterFn; /* +0x4048 CONFIRMED: fn ptr Menu2D_Filter_* assigned per mode (IsOne 6cce76, IsOneOr8235 6cd061, IsNot8323, IsNot8516Nor8302) */
  unsigned __int8 flag_404C; /* +0x404C VALID: byte flag =1/=0 (HudActorAll 6cce80) */
  char pad_404D[3]; /* +0x404D */
  int hudModeId; /* +0x4050 CONFIRMED: = n20 mode arg, dispatched by giant switch (HudActorAll 6cce44-4d) */
  unsigned __int8 flag_4054; /* +0x4054 VALID: byte =0 (HudActorAll 6cce87) */
  char pad_4055[3]; /* +0x4055 */
  int field_4058; /* +0x4058 VALID: dword =0 (HudActorAll 6cce8e) */
  int field_405C; /* +0x405C VALID: dword =0 (HudActorAll 6cce98) */
  int hudState; /* +0x4060 CONFIRMED: ctor=3 (6c7f76); !=0 enables render (RenderHudActor 6c9fb0) */
  unsigned __int8 flag_4064; /* +0x4064 CONFIRMED: ctor=0 (6c7f80) */
  char pad_4065[3]; /* +0x4065 */
};
#pragma pack(pop)
