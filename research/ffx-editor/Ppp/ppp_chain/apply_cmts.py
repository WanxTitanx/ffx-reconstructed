import idc

cmts = [
    (0x737830, "PPP draw model (pppDrawMdl): builds VFX texture slot for a PPP resource descriptor. args: a1=?, a2=program, a3=program_data (+4 = resource key u16, guard != 0xFFFF = disabled), a4=slot (+12 = state base ptr). Reads FFX_PppResourceDescriptorTablePtr for the 32B descriptor array."),
    (0x7378cc, "Packing: quantized 13-bit coords (>>19 & 0x1FFF) after WordPair_Reinterleave + ShortVector_MultiplyAndPack - active node transform prep before draw."),
    (0x737a1f, "Descriptor lookup: v6 = *(*FFX_PppResourceDescriptorTablePtr + 32) + 32*key. Entry+28 = resolved ptr (Std_IdentityFunc = identity, so raw ptr); flags &1 -> 128 / &2; u16 at +22."),
    (0x737aed, "Texture key u64 = program + FFX_PppGlobalOffsetKey(0x230FD20). Cache hit -> AllocVfxParticleSlots; miss -> ClassifyPppOpcodeByte + BuildVfxTextureAndFinalize_structural / BuildVfxTextureAndCommitDrawable_structural."),
    (0x737b26, "flag&4 -> FFX_Model_LoadCharacterModelWithFlag8000 (model draw); else FFX_MagicHost_CommitDrawableResources."),
    (0x711540, "Bind PPP resource to drawable. Contract: (key u64, ?, ?, ?) -> CreateVfxRenderDataBuffer, halves per-draw counts (slot+144 count, slot+148 array stride 108), ValidateGeometry, then ApplyPppDrawableColors + CommitDrawableResources."),
    (0x711561, "CreateVfxRenderDataBuffer fail -> FFX_TextureSlot_ReleaseByKey (undo binding)."),
    (0x711910, "PPP build drawable from opcode. Entry: (a1=program low32, a2=param_ptr/record, a3=slot). Cache hit -> ProcessCmd + CommitDrawableResources; miss -> BuildTexturePathFromOpcode (sprintf %d_%d_0_0_%d_%d.dds.phyre) + ValidateGeometry + ProcessCmd, else ReleaseByKey."),
    (0x71195b, "CommitDrawableResources = finalize texture slot binding after ProcessCmd fills vertex/uv/index buffers."),
    (0x7186f0, "AllocVfxParticleSlots: allocates VFX particle/draw records for a PPP resource descriptor. args: (texture key u64, descriptor entry (a2, +28 = resolved ptr), flags v17 (a3)). Sets FFX_PppTexelDensityScale (256.0/512.0 per magic id 102/103/515/667), FFX_PppTexelInvDensity = 0.0078125/scale."),
    (0x718d6b, "Draw record shape (FFX_MagicHost_AllocPppDrawRecord): +0 flags byte, +1 bool(a3+68), +16 dword record+0, +20 dword a3+56, +24 descriptor+28 ptr, +28 u16 opcode id (slot+8 & 0x3FFF), +32 0x40B matrix, +96 0x40B src(a3+68), +160/+164 dwords a3+16/+20, +176..+188 4 floats scale, +192..+204 4 texture slot ptrs, +240..+252 4x more slots, +256 dword a3+60, +272/+336/+400 0x40B matrices, +468 0x40B global src_6."),
    (0x718fb0, "Per-opcode particle slot alloc loop: stride 108B, cap 3240 (30 slots); case 0/1: AllocPppParticleSlot per texture slot (up to 4 or count at DataPtr+196); case 7: 48B stride; case 6: memset vertex buffer, 2*count bytes."),
    (0x712080, "Relocate PPP resource blob BEFORE section use (self-relative ptr fixup). Blob header: +6 u16 section count, +8 u16 pair count, +10 u16 ptr count, +12 u16 pair2 count, +16 dword section ptr array, +20 dword record array, +24 dword ptr array, +28 dword pair array. Every pointer field is blob-relative offset -> += blob base (Std_IdentityFunc_B(lpBuffer + x))."),
    (0x712103, "Per-section: FFX_MagicHost_RelocatePppSection resolves dispatch-table indices (a2 + 40*idx, 40 = 0x28 entry size) to handler pointers."),
    (0x7121d0, "Relocate PPP section: header +2[2] = vertex table rel ptr, +2[3] = record offsets rel ptr; record list: +0 next rel, +38 i16 count of triples at +52 (stride 16B): first dword of triple = DISPATCH TABLE INDEX (a2 + 40*idx -> handler ptr), others blob-relative."),
    (0x800620, "RelocatePppResourceAccel: POPULATES FFX_PppResourceDescriptorTablePtr at runtime -> &byte_11333C4[1829996] (0x12F2030). Copies 3 ptrs from obj+208 blob (+20/+24/+28), then RelocatePppResourceBlob unless IsLargePppResource."),
    (0x925210, "InitObjectBuffer: writes FFX_PppResourceDescriptorTablePtr = buffer ptr, builds descriptor +32/+36/+40 from runtime table slices (SelectRuntimeTableSlice(table,8,idx): slice+20 -> +32, +24 -> +36, +28 -> +40), then RelocatePppResourceBlob per slice. Also AttachPppResourceBuffer + PppMemAlloc arena."),
    (0xa54760, "KeyholeTexture_Init: 4th RelocatePppResourceBlob caller ('pppKeThRes48' blob at MEMORY[0x2305800]); zeroes blob words +2..+6 then relocates. Keyhole dispatch table (0xC86080) resource."),
    (0x716a30, "FreeResourceBufferChain: reveals allocator arena layout at *FFX_PppResourceDescriptorTablePtr: +0 freelist small, +8 threshold, +16 freelist large (ptr > threshold -> +16 pool), +32 descriptor array."),
]
for addr, text in cmts:
    ok = idc.set_cmt(addr, text, 0)
    print(hex(addr), "cmt ok=", ok)
