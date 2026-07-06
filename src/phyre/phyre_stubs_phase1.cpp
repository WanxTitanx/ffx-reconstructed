// phyre_stubs_phase1.cpp — Stubs para FASE 1 do plano de reconstrução
// Mantido separado de phyre_stubs.cpp para preservar cache .obj com 256 stubs

// === Type_ConstructDispatcher (Fase 1a) ===
void Phyre_Timer_Reset(void *self) {}
void *Phyre_ThreadInfo_GetTLSStorage() { static char tls[64]; return tls; }
int Phyre_TLS_GetValue(void *tls, int idx) { return 0; }
int Phyre_Shader_CompileProgram(void *self) { return 0; }

// === ClusterContext_Create (Fase 1b) ===
// Dependências já stubadas no cache principal

// === Texture (Fase 1c/1d/1e) ===
// Dependências já stubadas no cache principal
