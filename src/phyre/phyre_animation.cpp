// ============================================================================
// FFX.EXE — Animation System Stubs
// ============================================================================
#include "../include/ffx_structs.h"

// Phyre_Animation_UpdateBones — Atualiza transformações dos ossos
void Phyre_Animation_UpdateBones(void *self, void *bones, int count) {}

// Phyre_Animation_BlendShapes — Blend de shapes de animação
void Phyre_Animation_BlendShapes(void *self, float blend) {}

// Phyre_Animation_GetDuration — Retorna duração da animação
float Phyre_Animation_GetDuration(void *self) { return 0.0f; }

// Phyre_AnimationScheduler_ExecuteLuaCall — Executa chamada Lua no scheduler
int Phyre_AnimationScheduler_ExecuteLuaCall(void *self, const char *func) {
  return 0;
}

// Phyre_AnimationDataSource_CopyNameString — Copia nome do data source
void Phyre_AnimationDataSource_CopyNameString(void *self, char *out,
                                              int maxLen) {}

// Phyre_AnimationDataSource_ClearOutputSlot — Limpa slot de saída
void Phyre_AnimationDataSource_ClearOutputSlot(void *self, int slot) {}

// Phyre_Animation_BoneTransform — Computa transformação de osso
void Phyre_Animation_BoneTransform(void *self, int boneIndex, float *matrix) {}

// FFX_TexAnim_FindByName — Encontra animação de textura pelo nome
int FFX_TexAnim_FindByName(void *self, const char *name) { return -1; }

// FFX_TexAnim_NextFrameToken — Avança para próximo frame da animação
int FFX_TexAnim_NextFrameToken(void *self) { return 0; }

// FFX_TexAnim_SetupChannelMatrices — Configura matrizes do canal
void FFX_TexAnim_SetupChannelMatrices(void *self, void *matrices) {}

// FFX_TexAnim_SetupFrameData — Configura dados do frame
void FFX_TexAnim_SetupFrameData(void *self, int frame) {}

// FFX_TexAnim_FileCache_LazyInit — Inicialização lazy do cache de arquivos
int FFX_TexAnim_FileCache_LazyInit(void *self) { return 0; }

// FFX_TexAnim_GetFileCache — Obtém cache de arquivos
void *FFX_TexAnim_GetFileCache(void *self) { return 0; }

// FFX_TexAnim_RemoveByHash — Remove textura por hash
int FFX_TexAnim_RemoveByHash(void *self, int hash) { return 0; }

// FFX_TexAnim_BuildAndBind — Constrói e vincula textura animada
int FFX_TexAnim_BuildAndBind(void *self, int slot, const char *name) {
  return 0;
}

// FFX_Chr_SetupAudioLightShading — Configura shading de luz de áudio do
// personagem
void FFX_Chr_SetupAudioLightShading(void *self, int lightIndex,
                                    float intensity) {}

// Phyre_Animation_LoadSkeleton — Carrega skeleton da animação
int Phyre_Animation_LoadSkeleton(void *self, const char *path) { return 0; }

// Phyre_Animation_FindBoneByName — Busca osso pelo nome
int Phyre_Animation_FindBoneByName(void *self, const char *name) { return 0; }

// Phyre_Animation_ApplyTransform — Aplica transformação nos ossos
void Phyre_Animation_ApplyTransform(void *self, int boneIndex, float *matrix) {}

// Phyre_Animation_InterpolateFrames — Interpola entre quadros de animação
void Phyre_Animation_InterpolateFrames(void *self, float t, int from, int to) {}

// Phyre_Animation_BlendLayers — Combina camadas de animação
void Phyre_Animation_BlendLayers(void *self, int layerCount, float *weights) {}

// Phyre_Animation_GetFrameCount — Retorna número de quadros
int Phyre_Animation_GetFrameCount(void *self) { return 0; }

// Phyre_Animation_GetBoneCount — Retorna número de ossos
int Phyre_Animation_GetBoneCount(void *self) { return 0; }

// Phyre_Animation_SetPlaybackSpeed — Define velocidade de reprodução
void Phyre_Animation_SetPlaybackSpeed(void *self, float speed) {}

// Phyre_Animation_UpdateTime — Atualiza tempo da animação
void Phyre_Animation_UpdateTime(void *self, float deltaTime) {}

// Phyre_AnimationDataSource_ReadFloat — Lê valor float do data source
float Phyre_AnimationDataSource_ReadFloat(void *self, int slot) { return 0.0f; }

// Phyre_AnimationDataSource_ReadVector3 (0xNNNN) — Lê vetor 3D do data source
int Phyre_AnimationDataSource_ReadVector3(void *self) { return 0; }

// Phyre_AnimationDataSource_GetChannelIndex (0xNNNN) — Obtém índice do canal
int Phyre_AnimationDataSource_GetChannelIndex(void *self) { return 0; }

// Phyre_AnimationDataSource_GetBufferKeyIndex (0xNNNN) — Obtém índice da chave
// no buffer
int Phyre_AnimationDataSource_GetBufferKeyIndex(void *self) { return 0; }

// Phyre_AnimationDataSource_IsBufferKeyValid (0xNNNN) — Verifica se chave do
// buffer é válida
int Phyre_AnimationDataSource_IsBufferKeyValid(void *self) { return 0; }

// Phyre_AnimationDataSource_GetBufferLimit (0xNNNN) — Retorna limite do buffer
int Phyre_AnimationDataSource_GetBufferLimit(void *self) { return 0; }

// FFX_TexAnim_LoadSequence (0xNNNN) — Carrega sequência de textura animada
int FFX_TexAnim_LoadSequence(void *self) { return 0; }

// FFX_TexAnim_Release (0xNNNN) — Libera textura animada
int FFX_TexAnim_Release(void *self) { return 0; }

// Phyre_Animation_GetDuration_Stub (0xNNNN) — Stub alternativo para duração
// (int)
int Phyre_Animation_GetDuration_Stub(void *self) { return 0; }

// FFX_TexAnim_FindBySlotIndex (0xNNNN) — Encontra textura animada pelo índice
// do slot
int FFX_TexAnim_FindBySlotIndex(void *self, int slotIndex) { return -1; }

// FFX_TexAnim_FindIndexByName (0xNNNN) — Busca índice de textura animada pelo
// nome
int FFX_TexAnim_FindIndexByName(void *self, const char *name) { return -1; }

// FFX_TexAnim_FindByNameInManager (0xNNNN) — Busca textura animada pelo nome no
// gerenciador
int FFX_TexAnim_FindByNameInManager(void *self, const char *name) { return -1; }

// FFX_TexAnim_StringListNext (0xNNNN) — Próximo elemento na lista de strings de
// textura animada
int FFX_TexAnim_StringListNext(void *self) { return 0; }

// FFX_TexAnim_StringListNextNoCheck (0xNNNN) — Próximo elemento sem verificação
int FFX_TexAnim_StringListNextNoCheck(void *self) { return 0; }

// FFX_TexAnim_StringListPredicate (0xNNNN) — Predicado para filtro em lista de
// strings
int FFX_TexAnim_StringListPredicate(void *self, const char *candidate) {
  return 0;
}

// Phyre_Animation_GetKeyframeTransform (0x5Exxxx) — Obtém transformação de um
// keyframe
int Phyre_Animation_GetKeyframeTransform(void *self) { return 0; }

// Phyre_Animation_GetKeyframeTransformEx (0x5Exxxx) — Obtém transformação
// estendida de keyframe
int Phyre_Animation_GetKeyframeTransformEx(void *self) { return 0; }

// Phyre_Animation_TransformBlend (0x5Exxxx) — Combina/interpola transformações
// de animação
int Phyre_Animation_TransformBlend(void *self) { return 0; }

// Phyre_Animation_SkeletonProcess (0x5Exxxx) — Processa a hierarquia do
// skeleton
int Phyre_Animation_SkeletonProcess(void *self) { return 0; }

// Phyre_Animation_GetBoneTransform (0x5Exxxx) — Retorna a matriz de
// transformação de um osso
int Phyre_Animation_GetBoneTransform(void *self) { return 0; }

// Phyre_Animation_SetBoneTransform (0x5Exxxx) — Define a matriz de
// transformação de um osso
int Phyre_Animation_SetBoneTransform(void *self) { return 0; }

// Phyre_Animation_GetBlendWeight (0x5Exxxx) — Obtém o peso de blend de um
// canal/osso
int Phyre_Animation_GetBlendWeight(void *self) { return 0; }

// Phyre_Animation_SetBlendWeight (0x5Exxxx) — Define o peso de blend de um
// canal/osso
int Phyre_Animation_SetBlendWeight(void *self) { return 0; }
