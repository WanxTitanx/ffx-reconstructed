# FFX.exe Decompilation — Batch 31: Game Entry Points

**Database:** ffxoficial_COPY.i64 (session ffx-session-002)
**Date:** 2026-07-28
**Type:** Entry point mapping / boot chain analysis

---

## Summary

FFX.exe não tem uma `WinMain` tradicional — o entry point é o CRT stub `start` (0x9493c7) que roteia para `__tmainCRTStartup`. A inicialização real do jogo acontece via **8 static initializers registrados na seção CRT$XIU**, que constroem os singletons do PhyreEngine e FFX antes de qualquer frame ser renderizado. O lançador (FFX&X-2_LAUNCHER.exe) é um processo separado (64-bit C# .NET) que executa FFX.exe como child process.

---

## Boot Chain

```
Windows Loader
    │
    ├── FFX&X-2_LAUNCHER.exe (64-bit C# .NET)
    │   ├── Config screen (language, resolution, etc)
    │   ├── Steam API init
    │   └── CreateProcess(FFX.exe)
    │
    └── FFX.exe (32-bit, MSVC 2012)
        │
        ├── 1. CRT Entry @ 0x9493c7
        │   └── _start → __tmainCRTStartup
        │
        ├── 2. CRT$XIU Static Initializers (8+ registrados)
        │   ├── FFX_Math_Init12StepSinCosTable  (tabela seno/cosseno)
        │   ├── FFX_System_Host_Constructor     (69KB singleton, 79 fases)
        │   ├── FFX_Atel_InitVmAndRegisterFuncspaces  (5 VMs, 1499 opcodes)
        │   ├── Phyre_PConsoleLog_Init          (logging)
        │   ├── Phyre_Allocator_Init            (memory allocators)
        │   ├── FFX_BtlUI_InitCursorRingState   (CTB cursor ring)
        │   ├── FFX_Mscd_InitFileRead           (file I/O queue)
        │   └── Engine_InitGlobalPointers       (global state)
        │
        ├── 3. main() / WinMain equivalent
        │   ├── CreateWindow (CreateWindowExW import)
        │   ├── D3D9 init (GetProcAddress → d3d9.dll)
        │   ├── FMOD init (fmodex.dll)
        │   ├── Steam API init (steam_api.dll)
        │   └── Enter game loop
        │
        └── 4. Game Loop (infinite)
            ├── ProcessInput (DirectInput8Create?)
            ├── Update
            │   ├── Field update (FieldVM + FieldScript)
            │   ├── Battle update (CTB + AI + Damage)
            │   └── Sound update (FMOD + command queue)
            ├── Render (PhyreEngine via D3D9)
            └── Present (D3D9 swapchain)
```

---

## Launcher (64-bit C# .NET)

`FFX&X-2_LAUNCHER.exe` é um processo separado que:
1. Mostra tela de configuração (idioma, resolução, gráficos)
2. Inicializa Steam API
3. Escreve configurações no registro
4. Cria processo FFX.exe com argumentos de linha de comando

**Não faz parte da RE do FFX.exe** — é um wrapper .NET independente. O FFX.exe roda como child process.

---

## CRT Entry (0x9493c7)

O entry point `start` em 0x9493c7 é o stub MSVC CRT padrão:

```asm
; CRT startup stub (simplified)
start:
    __security_init_cookie()
    __tmainCRTStartup() {
        __scrt_acquire_startup_lock()
        _initterm(__xi_a, __xi_z)    // Static initializers (CRT$XIU)
        _initterm(__xc_a, __xc_z)    // C++ static constructors
        main()                        // User entry point
        __scrt_release_startup_lock()
    }
```

FFX.exe usa o entry point **`main`** (não `WinMain`), indicando que é uma aplicação console ou usa o subsistema `GUI` com entry point `main`. Isso é comum para jogos que não precisam de console window.

---

## Static Initializers (CRT$XIU)

Os seguintes initializers são chamados via `_initterm` antes de `main()`:

| Initializer | Address | Tamanho | Propósito |
|-------------|---------|---------|-----------|
| `FFX_Math_Init12StepSinCosTable` | 0x82e620 | ~80B | Tabela sin/cos 12-step (30°) |
| `FFX_System_Host_Constructor` | 0x64ddb0 | 3.482B | Scene host singleton (69KB) |
| `FFX_Atel_InitVmAndRegisterFuncspaces` | ~0x6349f0+ | 5.919B | 5 VMs, 1499 opcodes |
| `Phyre_InitMathConstants` | — | — | PhyreEngine math tables |
| `Phyre_Allocator_Init` | — | — | Memory allocators |
| `FFX_Mscd_InitCdEnv` | 0x76c670 | ~200B | MSCD CDROM env init |
| `FFX_BtlUI_InitCursorRingState` | 0x64d070 | ~100B | CTB cursor ring state |
| `Engine_InitGlobalPointers` | — | — | Global pointer table (vtables) |

**Total de init estático: ~10KB de código de inicialização** executado antes mesmo do jogo mostrar a primeira tela.

---

## main() / Game Init

Após os static initializers, `main()` executa:

### 1. Window Creation (CreateWindowExW)

FFX.exe importa `CreateWindowExW` do USER32 — a janela é criada via Win32 API padrão.

### 2. D3D9 Device Creation

PhyreEngine carrega `d3d9.dll` via `GetProcAddress` (não aparece como import explícito). O device D3D9 é criado com:
- `D3D9Create`
- `CreateDevice`
- `Present` (importado dinamicamente)

### 3. FMOD Sound Init

`FMOD::System::init` é chamado via import do `fmodex.dll`:
- Initialize FMOD Ex 3.7
- Set up 3D audio listener
- Allocate sound channels

### 4. Steam API Init

`SteamAPI_Init` via `steam_api.dll`:
- Inicializa integração Steam
- Registra callbacks (SteamAPI_RegisterCallback)
- Verifica ownership do jogo

### 5. Asset Loading (MSCD)

`FFX_Mscd_InitFileRead` + `FFX_Mscd_ConfigureSectionLoad`:
- Inicializa file I/O queue (64 slots)
- Monta tabela de arquivos VBF
- Prepara streaming de assets

### 6. Main Scene Load

`FFX_FieldMap_LoadEntry_graphicFieldMapLoad` (0x6403c0):
- Carrega primeira cena (título/menu)
- Ativa scene graph via PhyreEngine PWorld/PEntity
- Inicia game loop

---

## Game Loop (Frame Pipeline)

```
while (running) {
    // 1. INPUT
    DirectInput8_GetDeviceState(keyboard)
    DirectInput8_GetDeviceState(mouse)
    XInputGetState(controller)
    
    // 2. UPDATE
    FFX_FieldVM_Dispatch()        → field scripting
    FFX_FieldOp_Dispatch()        → field script ops
    FFX_Atel_Dispatch()           → ATEL VM (cutscenes/UI)
    FFX_Battle_UpdateAI()         → monster AI
    FFX_Battle_UpdateCTB()        → turn scheduling
    FFX_Sound_ProcessCommandQueue() → sound commands
    
    // 3. RENDER
    Phyre::PRendering::BeginScene()
    Phyre::PCluster::FlushDrawClusters()
    Phyre::PPostProcessing::Apply()
    Phyre::PText::Render()
    
    // 4. PRESENT
    D3D9::Present(swapchain)
}
```

---

## Key Findings

1. **FFX.exe não tem WinMain** — entry point `main` (não `WinMain`). Usa subsistema GUI com entry point main.

2. **Launcher é processo separado** — FFX&X-2_LAUNCHER.exe (64-bit C# .NET) configura e lança FFX.exe.

3. **8+ static initializers** registrados em CRT$XIU — constroem singletons antes de main().

4. **2 maiores initializers**: `System_Host_Constructor` (3482B) + `Atel_InitVmAndRegisterFuncspaces` (5919B) = ~9.4KB de init na boot.

5. **D3D9 carregado dinamicamente** — PhyreEngine usa `GetProcAddress`, não import explícito.

6. **FMOD e Steam API são DLLs externas** — carregadas pelo loader do Windows (import table).

7. **Cadeia de init**: CRT → static init (singletons) → main (window/D3D/audio) → game loop.

8. **SinCos table é o primeiro init** — `Init12StepSinCosTable` roda antes de qualquer singleton.

9. **CreateWindowExW é o único import de window** — FFX.exe cria janela via Win32 API.

10. **Sem anti-debug / anti-tamper** — entry point é CRT padrão sem obfuscation.

---

## Domínios Restantes (não cobertos nos batches 0001-0031)

| Domínio | Prefixo | Funcs | Prioridade |
|---------|---------|-------|------------|
| Menu2D | `FFX_Menu2D_*` | ~200 | Média |
| Monster AI | `FFX_MonsterAI_*` / `FFX_Encounter_*` | ~300 | Alta (modding) |
| Virtuos | `FFX_Virtuos_*` | ~20 | Baixa (stubs) |
| Shader Interop | `FFX_ShaderInterop_*` / `FFX_ShaderPreprocessor_*` | ~50 | Média |
| AI Script | `FFX_Ai*` | ~300 | Alta |
| Input | `FFX_Input_*` | ~30 | Baixa |
| Field Sky | `FFX_Sky*` / `FFX_Cloud*` | ~40 | Baixa |
| RPC/Debug | `FFX_Rpc*` | ~30 | Baixa |
| **Total pendente** | | **~950** | |
