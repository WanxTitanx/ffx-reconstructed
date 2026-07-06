# FFX Reconstructed

**Uma engine funcional para Final Fantasy X, reconstruída do zero via engenharia reversa.**

Este projeto nasceu de um esforço massivo de reverse engineering: **45.114 funções nomeadas**, **291 structs**, **91 vtables**, e **milhares de horas de análise** da build Steam do FFX (versão internacional) usando IDA Pro + Hex-Rays. Todo o código é original, escrito em C++ puro, compilável com MSVC e capaz de rodar um executável Windows que abre janela, inicializa D3D11, desenha na tela e aceita input do teclado.

---

## Estado Atual

O projeto está em **fase de reconstrução ativa**. A engine base já é funcional:

### ✅ Funciona agora
- **Game loop completo** — PeekMessage não-bloqueante, delta time via QueryPerformanceCounter, clamp anti-spiral-of-death
- **D3D11 nativo** — Device, swap chain, render target view criados via LoadLibrary + GetProcAddress (zero dependência estática de d3d11.lib)
- **Shaders inline HLSL** — Vertex + pixel shaders compilados via D3DCompile em runtime a partir de strings C incorporadas
- **Render queue** — Sistema de quad batching com buffer de vértices dinâmico até 2048 quads por frame, matriz de projeção ortográfica, DrawIndexed otimizado com batch sorting por textura
- **Input de teclado** — Polling de 256 teclas via GetAsyncKeyState com detecção de borda de subida
- **Menu ESC** — Overlay com toggle pela tecla M, navegação por setas, highlight com accent teal (#2A9D8F), fechar com Enter/Esc
- **Texturas** — Carregamento de PNG/JPG/BMP/TGA via stb_image, cache de até 64 SRVs, sistema de registro de atlas por ID
- **DrawWindow** — Janelas 9-slice com bordas 2px, cantos accent, title bar, gradiente de fundo
- **DrawString** — Renderização de texto com fallback para retângulos coloridos, suporte a 3 tamanhos de fonte e múltiplas linhas
- **DrawPlasma** — Efeito gradiente animado (placeholder para o plasma procedural original)
- **Sistema de save** — CRC-16 CCITT completo, I/O de arquivo real com CreateFile/ReadFile/WriteFile, gerenciamento de 7 slots, acesso a dados de personagem (HP, MP, stats, equipment, aeons)
- **Fullscreen** — Alternância via F11, resize de janela com recreate do backbuffer
- **FPS counter** — Barra colorida no canto superior esquerdo (verde >48fps, amarelo >30fps, vermelho abaixo)
- **Lua 5.1** — VM completa compilada e linkada (27 arquivos .c, sem modificações)

### 🔄 Em andamento
- **Battle HUD** — Sistema de atores (12 slots), action queue, CTB, ATEL scripts. Data model funcional, rendering visual sendo implementado
- **Menu sistema** — Pool de 32 slots, contexto por menuId, scroll, páginas, navegação, confirm/cancel. API de alto nível funcional, páginas de configuração sendo construídas
- **Sistema de atlas** — 6 texturas de menu registradas (meswin, menu_new, ffx_bg, stonetexture, summonbg, icon), dispatch por atlas ID implementado

### ❌ Stub (próximos passos)
- **Field/3D** — Carregamento de cenas, render 3D, câmera, iluminação — 5% implementado
- **Battle HUD rendering** — HP bars, CTB ring, overdrive gauge, status icons — 0% implementado
- **Save/Load UI** — Orquestrador de save crystal com freeze de cena — 10% implementado
- **PhyreEngine Type System** — PClassDescriptor, PNamespace — PClass system parcial, type system completo necessário para carregar assets
- **FMOD Audio** — Música e SFX — stub
- **Steam API** — Conquistas, cloud save — stub
- **Iggy UI** — Sistema de UI do PhyreEngine — stub
- **DirectInput / XInput** — Gamepad, controles analógicos — stub

---

## Arquitetura

```
ffx-reconstructed/
├── src/
│   ├── ffx/                    # Core game logic
│   │   ├── main.cpp            # Entry point, game loop, init chain
│   │   ├── ffx_renderer.cpp    # D3D11 device, swapchain, shaders
│   │   ├── ffx_renderqueue.cpp # Deferred quad batching pipeline
│   │   ├── ffx_texture.cpp     # Texture manager (stb_image + SRV cache)
│   │   ├── ffx_input.cpp       # Keyboard input polling
│   │   ├── ffx_menu.cpp        # Escape menu system + menu2D primitives
│   │   ├── ffx_battle.cpp      # Battle data model + actions
│   │   ├── ffx_field.cpp       # Field/scene system
│   │   ├── ffx_save.cpp        # Save/load + CRC-16 + slot management
│   │   └── ffx_debug.cpp       # Debug logging + dev tools
│   ├── phyre/                  # PhyreEngine stubs + implementations
│   ├── include/                # Project headers
│   ├── lua-real/               # Lua 5.1 VM (real, full)
│   ├── bullet/                 # Bullet Physics stubs
│   └── lua/                    # Lua bridge stubs
├── stubs/                      # Middleware stubs (Steam, FMOD, Iggy, D3D11, Win32)
├── include/                    # Third-party headers (Bullet, FMOD, ImGui, Lua, stb, zlib)
└── CMakeLists.txt              # Visual Studio 2022/2026, Win32, /MD /O2 /LTCG
```

### Pipeline de Renderização

```
FFX_Renderer_BeginFrame()
  ├── OMSetRenderTargets(1, &RTV, NULL)
  └── ClearRenderTargetView(RTV, clearColor)

[Scene drawing]
  ├── FFX_RenderQueue_PushRect()    — quads sólidos/gradiente
  ├── FFX_RenderQueue_PushQuad()    — quads com UV + cores por vértice
  ├── FFX_RenderQueue_PushQuadTex() — quads texturizados com SRV
  └── FFX_Renderer_DrawTestTriangle() — triângulo RGB de teste

FFX_RenderQueue_Flush()
  ├── Map vertex buffer (WRITE_DISCARD)
  ├── Build orthographic projection matrix
  ├── Batch quads by SRV (minimize state changes)
  ├── Set IA/VS/PS state
  └── DrawIndexed()

FFX_Renderer_EndFrame()
  └── SwapChain->Present(1, 0)
```

---

## Como Compilar

### Requisitos
- **Windows 10+**
- **Visual Studio 2022 ou 2026** com suporte a desktop C++
- **CMake** 3.20+ (incluído no VS)

### Build
```bash
cd ffx-reconstructed
cmake -S . -B build -G "Visual Studio 17 2022" -A Win32
cmake --build build --config Release
```

O executável será gerado em `build/Release/FFX_Reconstructed.exe`.

### Comandos
| Tecla | Ação |
|-------|------|
| `M` | Toggle menu ESC |
| `↑/↓` | Navegar no menu |
| `Enter` | Confirmar / fechar menu |
| `Esc` | Fechar menu / sair do jogo |
| `F11` | Alternar fullscreen |

---

## A Jornada

Este é o resultado de um dos maiores esforços de reverse engineering de Final Fantasy X já realizados:

- **45.114 funções** completamente analisadas e renomeadas na base IDA
- **291 structs** mapeadas, incluindo PClassDescriptor (sistema de tipos), PRenderer, PAnimation, Bullet physics, sistema de HUD, e mais
- **91 vtables** identificadas e tipadas no .rdata
- **~95,7% de cobertura** de stubs convertidos em implementações reais
- **~76.500+ linhas** de código de reconstrução geradas
- **25+ bibliotecas open-source** integradas: Bullet Physics, Lua 5.1, zlib, stb, ImGui, FMOD (stub), Steam (stub)

A base de conhecimento deste projeto está documentada em:
- `src/include/ffx_structs.h` — 20 structs do FFX/PhyreEngine com campos nomeados
- `src/include/ffx_vtables.h` — 4 vtables com 35 entries mapeadas

---

## Licença

MIT — Este é um projeto de pesquisa e engenharia reversa educacional. Não contém código original da Square Enix, apenas implementações originais baseadas em observação do comportamento do software. O jogo Final Fantasy X é propriedade da Square Enix.
