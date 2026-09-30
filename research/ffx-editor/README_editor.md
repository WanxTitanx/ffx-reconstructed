---
date: 2026-09-16
tags:
  - ffx-project-editor
  - spira-reforge-studio
  - ffx-mod-studio
  - runtime-verification
  - monster-editor
  - battle-explorer
  - aurora-chamber
  - noclip
aliases:
  - Spira Reforge Studio
  - FFX Mod Studio
  - FFX Project Editor
---

<div align="center">

<img src="ReadmeAssets/SpiraReforgeStudio.png" width="160" alt="Spira Reforge Studio logo"/>

# Spira Reforge Studio

**Desktop modding studio for FINAL FANTASY X / X-2 HD Remaster (Steam, PC)** — file authoring, 3D viewers and live runtime tooling.

[![Version](https://img.shields.io/badge/version-2.244.2.2-informational)](CHANGELOG.md)
[![Status](https://img.shields.io/badge/status-BETA-red)](PORT_STATUS.md)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Windows%20x64%20%C2%B7%20Linux-blue)](#requirements)
[![Game](https://img.shields.io/badge/game-FFX%20HD%20Remaster%20(Steam)-green)](https://store.steampowered.com/app/359870/)
[![.NET](https://img.shields.io/badge/.NET-8.0-purple)](https://dotnet.microsoft.com/download/dotnet/8.0)
[![UI](https://img.shields.io/badge/UI-Avalonia%2011.2.3-blueviolet)](https://avaloniaui.net/)
[![i18n](https://img.shields.io/badge/i18n-9%20languages-orange)](docs/ai/I18N_CODING_RULES.md)

[🇧🇷 Português](#-português) · [🇺🇸 English](#-english)

</div>

---

## 🇧🇷 Português

Studio desktop para modding de **Final Fantasy X HD Remaster**: edição byte-safe de arquivos do jogo, viewers 3D embutidos (noclip) e ferramentas de runtime ao vivo contra o `FFX.exe`. O binário ainda identifica-se internamente como `FFXProjectEditor`.

> **Status honesto:** software jovem em desenvolvimento ativo. Domínios marcados `Writable` têm writers byte-safe provados (RT0); superfícies `Read-Only` são explorers/atlases sem escrita; labs de runtime ficam **OFF por padrão** até gates explícitos. Nada aqui promete mais do que o código prova.

### Destaques recentes

- **NoClip auto-suficiente (2.244.0.0):** o viewer 3D embutido semeia o skeleton de dados via CDN oficial `z.noclip.website` (~2 MB core + fetch-through lazy sob `/data`) — Monster Studio, Magic Studio e Aurora Chamber funcionam **em máquina limpa**, sem pipeline local de extração. Fallback para browser externo no Linux.
- **Aurora Chamber (2.244.1.0/2.244.2.0):** catálogo BIANCA + MapViewer + **batalha real renderizada** (popup WebView2 / browser externo). O **EditViewer** agora abre o palco real da batalha com `?edit=1` — gizmo de drag XZ, `S` salva sidecar, `R` reseta — e o "Salvar posições" faz merge dos deltas do sidecar para o `.bin` (âncora `monster_live`).
- **Música auto-import (2.244.0.0):** detecta o `ffx_music_bank00.fsb` da instalação, decodifica as 10 faixas aprovadas via `vgmstream-cli` empacotado (SHA-256 pinado por plataforma) e publica pra tocar offline — zero cliques, toggle no flyout.
- **AI Assistant com modo Agente (2.244.x):** BYOK (sua chave, só em memória), modos Chat/Proposta/**Agente** com tool-calling real (tools read-only confinadas por PathGuard + budgets), e `BytePatchAdapter` tornando propostas executáveis de verdade — **nada é escrito sem receita provada + aprovação humana**. Feature gate opt-in (default OFF).
- **Seletor de pasta do jogo:** game root independente do workspace `master` — badge no header, persistido, com precedência pick → workspace → `FFX_GAME_ROOT` → Steam.
- **Command palette (`Ctrl+K`)**, dashboard de workspace com todos os módulos, **UI em 9 idiomas** (PT/EN/ES/FR/DE/IT/JA/KO/ZH).

### Superfície pública

| Cluster | Módulo | Modo |
|---|---|---|
| **Autoria** | Monster Editor | Writable — stats/loot/resistências de `m###.bin` |
| | Magic DLL Editor | Writer byte-safe — `magic_XXXX.dll`, 184 schemas, RT0 gate |
| | Battle Commands | Writers: `command.bin`, `monmagic1/2.bin` |
| | Items (hub) | Writers: `item.bin`, `takara.bin`, shop payload, `prepare.bin` (Mix Table) |
| | Customizations / Aeons | Writers: `kaizou.bin`, `sum_grow.bin`, `a_ability.bin`, `arms_rate.bin` |
| | Stats | Writers: `ply_save.bin`, `ply_rom.bin`, `ctb_base.bin` |
| | Enemy Design | Monster AI (ATEL) + Custom Boss Creator + Difficulty Director |
| | Sphere Grid | Explorer + Panel writer + Builder/Canvas offline |
| | Treasure Map | Editor visual de baús nos mapas (`takara.bin`) |
| | Text / Reference | Writers: `w_name.bin`, `btl_txt.bin`; String/Macro/Event read-only |
| | Blitzball | Writers: roster/recruits/prize pool/prize table + Atlas read-only |
| | Save Editor | Port nativo do FFXED — saves `.psu`/PS2/PC `.ffx`, checksum recalculado |
| | Al Bhed Dictionary | Writer: `albheddic.bin` (US + JP) |
| **Mapas & Cenas** | Encounters & Formation | Routing read-only + writer byte-safe dos 8 slots `btl_*` |
| | Aurora Chamber | BIANCA + MapViewer + EditViewer/RealGame noclip (batalha real + gizmo) |
| | Aurora Field Explorer | ~299 campos HD + overlay de encounters do `btl.bin` |
| | Battle Explorer | Inspeção multi-chunk (ATEL, formação, posições) |
| **Live** | Injected DLLs | Switchboard de DLLs de runtime (ffx-hooks) |
| | Inventory / Arena Tracker | Telemetria ao vivo, read-heavy |
| | AI Assistant | **Opt-in** — BYOK, Chat/Proposta/Agente, zero escrita direta |
| **Extras** | Thunder Plains | Patcher EBP — lightning dodge (`kami*.ebp`) |
| | Monster Studio / Magic Studio | Viewers 3D embutidos (noclip) — modelos PS2 + 372 magias |
| | Textures TM2 / BIN-FTC / Pipeline / Containers | Atlases read-only com proveniência honesta |
| | VBF Extract | Extração local de arquivos VBF |
| | PS2 Audio (.wd) | Parse + decode PS-ADPCM→WAV via vgmstream |

> Labs não-públicos (dev-only): Map Scene Editor, Live Battle Lab, Aurora Overlay Lab, Battle Tracker, Debug Menu, Magic DLL Browser, Phyre Package I/O, Battle Corpus Crosswalk.

### Requisitos

- **Windows 10/11 x64** (alvo oficial; pacote win-x64 self-contained) — **Linux** funciona com viewers via browser externo.
- .NET 8 para rodar do fonte (o pacote publicado é self-contained).
- Pasta extraída `ffx_ps2/ffx/master` contendo `new_uspc` **e** `jppc`.
- `FFX.exe` rodando para as superfícies de runtime.
- WebView2 no Windows para os viewers embutidos (runtime incluso no Win11).

### Executar

```powershell
dotnet run --project FFXProjectEditor\FFXProjectEditor.csproj -- "D:\path\to\ffx_ps2\ffx\master"
```

Aponte para uma pasta que termine em `master` (ou use o seletor de workspace no dashboard) e navegue pela rail lateral / `Ctrl+K`.

### Screenshots

Ver [Screenshots](#screenshots-1) — compartilhadas entre os idiomas.

---

## 🇺🇸 English

Desktop studio for modding **Final Fantasy X HD Remaster**: byte-safe game-file authoring, embedded 3D viewers (noclip) and live runtime tooling against `FFX.exe`. The binary still identifies internally as `FFXProjectEditor`.

> **Honest status:** young software under active development. `Writable` domains have proven byte-safe writers (RT0); `Read-Only` surfaces are explorers/atlases with no writes; runtime labs stay **OFF by default** behind explicit gates. Nothing here claims more than the code proves.

### Recent highlights

- **Self-sufficient NoClip (2.244.0.0):** the embedded 3D viewer seeds its data skeleton from the official `z.noclip.website` CDN (~2 MB core + lazy fetch-through under `/data`) — Monster Studio, Magic Studio and Aurora Chamber work **on a clean machine**, no local extraction pipeline required. External-browser fallback on Linux.
- **Aurora Chamber (2.244.1.0/2.244.2.0):** BIANCA catalog + MapViewer + the **real rendered battle** (WebView2 popup / external browser). **EditViewer** now opens the actual battle stage with `?edit=1` — XZ drag gizmo, `S` saves the sidecar, `R` resets — and "Save positions" merges the sidecar deltas into the `.bin` (`monster_live` anchor).
- **Music auto-import (2.244.0.0):** detects the install's `ffx_music_bank00.fsb`, decodes the 10 approved tracks with the bundled `vgmstream-cli` (per-platform SHA-256 pinned) and publishes them for offline playback — zero clicks, flyout toggle.
- **AI Assistant with Agent mode (2.244.x):** BYOK (your key, memory-only), Chat/Proposal/**Agent** modes with real tool-calling (read-only tools confined by PathGuard + budgets), and `BytePatchAdapter` making proposals genuinely executable — **nothing is written without a proven recipe + human approval**. Opt-in feature gate (default OFF).
- **Game folder picker:** game root independent from the `master` workspace — header badge, persisted, precedence pick → workspace → `FFX_GAME_ROOT` → Steam.
- **Command palette (`Ctrl+K`)**, workspace dashboard listing every module, **9-language UI** (PT/EN/ES/FR/DE/IT/JA/KO/ZH).

### Public surface

| Cluster | Module | Mode |
|---|---|---|
| **Authoring** | Monster Editor | Writable — `m###.bin` stats/loot/resistances |
| | Magic DLL Editor | Byte-safe writer — `magic_XXXX.dll`, 184 schemas, RT0 gate |
| | Battle Commands | Writers: `command.bin`, `monmagic1/2.bin` |
| | Items (hub) | Writers: `item.bin`, `takara.bin`, shop payload, `prepare.bin` (Mix Table) |
| | Customizations / Aeons | Writers: `kaizou.bin`, `sum_grow.bin`, `a_ability.bin`, `arms_rate.bin` |
| | Stats | Writers: `ply_save.bin`, `ply_rom.bin`, `ctb_base.bin` |
| | Enemy Design | Monster AI (ATEL) + Custom Boss Creator + Difficulty Director |
| | Sphere Grid | Explorer + Panel writer + offline Builder/Canvas |
| | Treasure Map | Visual chest editor on field maps (`takara.bin`) |
| | Text / Reference | Writers: `w_name.bin`, `btl_txt.bin`; String/Macro/Event read-only |
| | Blitzball | Writers: roster/recruits/prize pool/prize table + read-only Atlas |
| | Save Editor | Native FFXED port — `.psu`/PS2/PC `.ffx` saves, checksum recomputed |
| | Al Bhed Dictionary | Writer: `albheddic.bin` (US + JP) |
| **Maps & Scenes** | Encounters & Formation | Read-only routing + byte-safe writer for the 8 `btl_*` slots |
| | Aurora Chamber | BIANCA + MapViewer + EditViewer/RealGame noclip (real battle + gizmo) |
| | Aurora Field Explorer | ~299 HD fields + `btl.bin` encounter overlay |
| | Battle Explorer | Multi-chunk inspection (ATEL, formation, positions) |
| **Live** | Injected DLLs | Runtime DLL switchboard (ffx-hooks) |
| | Inventory / Arena Tracker | Live telemetry, read-heavy |
| | AI Assistant | **Opt-in** — BYOK, Chat/Proposal/Agent, zero direct writes |
| **Extras** | Thunder Plains | EBP patcher — lightning dodge (`kami*.ebp`) |
| | Monster Studio / Magic Studio | Embedded 3D viewers (noclip) — PS2 models + 372 spells |
| | Textures TM2 / BIN-FTC / Pipeline / Containers | Read-only atlases with honest provenance |
| | VBF Extract | Local VBF archive extraction |
| | PS2 Audio (.wd) | Parse + PS-ADPCM→WAV decode via vgmstream |

> Non-public dev labs: Map Scene Editor, Live Battle Lab, Aurora Overlay Lab, Battle Tracker, Debug Menu, Magic DLL Browser, Phyre Package I/O, Battle Corpus Crosswalk.

### Requirements

- **Windows 10/11 x64** (official target; self-contained win-x64 package) — **Linux** runs with external-browser viewers.
- .NET 8 to run from source (the published package is self-contained).
- An extracted `ffx_ps2/ffx/master` folder containing both `new_uspc` **and** `jppc`.
- `FFX.exe` running for the live runtime surfaces.
- WebView2 on Windows for embedded viewers (bundled with Win11).

### Run

```powershell
dotnet run --project FFXProjectEditor\FFXProjectEditor.csproj -- "D:\path\to\ffx_ps2\ffx\master"
```

Point it at a folder ending in `master` (or use the workspace picker on the dashboard) and navigate via the left rail / `Ctrl+K`.

### Screenshots

**Aurora Chamber — EditViewer rendering the real `bsil03` battle stage** (noclip, `?edit=1` gizmo: drag XZ / `S` save / `R` reset). WebView2 popup on Windows, external browser on Linux.

<img src="ReadmeAssets/AuroraEditViewer.png" width="900"/>

**Workspace dashboard** — module grid, environment probe, workspace/output cards.

<img src="ReadmeAssets/WorkspaceOverview.png" width="900"/>

**Monster Editor** — Bunyip loaded: stats, loot and mirror targets (`Production` · byte-safe writer).

<img src="ReadmeAssets/MonsterEditor.png" width="900"/>

**Battle Explorer** — `azit03_00`: binary summary, ATEL footprint, encounter-table references.

<img src="ReadmeAssets/BattleExplorer.png" width="900"/>

**Items hub** — `item.bin` writable grid (Potion), with Key Items / Treasures / Gear / Shop / Mix Table sub-tabs.

<img src="ReadmeAssets/ItemsHub.png" width="900"/>

**Save Editor** — native FFXED port: Character/Equipment/Items/Blitzball/Sphere Grid/Minigame sections.

<img src="ReadmeAssets/SaveEditor.png" width="900"/>

### Notes

- Screenshots captured from the shipping `v2.244.2.2` package on Windows 11, 2026-09-16.
- Sister project: [`ffx-hooks`](../ffx-hooks) — the runtime engine hook layer (DINPUT8 bridge, live gameplay toggles) that powers the Live surfaces.
- Downloads: [github.com/WanxTitanx/ffx-editor-releases](https://github.com/WanxTitanx/ffx-editor-releases/releases/latest).

## License

Spira Reforge Studio is licensed under the **GNU General Public License v3.0** — see [LICENSE](LICENSE).

- Portions of the codebase were extracted or adapted from the GPL-3.0 FFX modding ecosystem (fahrenheit, ZanarkandWorkshop); their provenance is recorded in-file and in [NOTICE](NOTICE).
- Bundled third-party components keep their own licenses (noclip.website is MIT, Avalonia/.NET are MIT, the OpenJDK jlink image is GPLv2+Classpath Exception, etc.) — full inventory in [NOTICE](NOTICE) and `release/THIRD_PARTY_NOTICES.txt`.
- Fan-made tooling, not affiliated with or endorsed by Square Enix. No game assets are distributed.
