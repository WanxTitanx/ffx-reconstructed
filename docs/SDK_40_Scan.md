# SDK 4.00 Scan Results

## Status: SDK 4.00 NOT DOWNLOADED

PS3 SDK 4.00 (fev 2012) não está baixado nem extraído. A análise abaixo usa o PhyreEngine SDK 3.1.5.0 (`F:\ffx-reconstructed\EnginesExtras\Phyre_Engine\Phyre Engine\`) como substituto, que é a versão pública mais próxima do FFX HD (2013).

---

## SDK 3.1.5.0 Scan — Resultados

### Version
- **PhyreVersion.h**: `#define PHYRE_VERSION 0x30105000` = 3.1.5.0
- Comparação com FFX.exe: FFX.exe usa **3.9.0.0** ("SacSlicer") — muito mais novo. O SDK público 3.1.5.0 é de 2011, FFX HD é 2013. A versão interna da Sony/Squaresoft é anos-luz à frente.

### SacSlicer
- **NÃO ENCONTRADO** — a string `%%PVER%%3.9.0.0 "SacSlicer"` no FFX.exe é metadado de build interno, não um identificador de SDK público. O SDK público 3.1.5.0 não tem essa string.

### PBinary (Serialização)
- **ENCONTRADO** — `PhyreBinarySerialization.h` (48KB)
  - Namespace `Phyre::PSerialization::PBinary`
  - Classe `PPlatformClassLayout` — suporte a platform ID, pointer size, endianness, EBCO
  - `PhyreClusterHeader.h` + `PhyreClusterReaderBinary.h` + `PhyreClusterWriterBinary.h` — cluster I/O
  - `PhyreClusterHeader*.h` para D3D11/GCM/GL/GXM/Null — cluster headers por plataforma
  - `PhyreInstanceListConvert.h` — instance list conversion
  - **Total: 60+ headers de serialização**

### PCluster
- **ENCONTRADO** — serialização binária completa de PCluster (resource manager do engine)
  - `PClusterDependencyLoader` removido em 3.1.5.0 ("Removed the PClusterDependencyLoader class" — Readme)
  - Cluster loading usa `PClusterHeader` + `PClusterReaderBinary` + `PStreamFile`

### MSCD
- **NÃO ENCONTRADO** — MSCD (Multi-System CDROM) é código Square Enix, NÃO parte do PhyreEngine SDK. O FFX.exe usa MSCD como wrapper entre o codec FFX e o sistema de arquivos (VBF/PSARC).

### PSARC
- **NÃO ENCONTRADO** — formato Sony PSARC (utilizado para assets PS3) não faz parte do PhyreEngine SDK

### VBF
- **NÃO ENCONTRADO** — formato VirtuosBigFile (utilizado no port PC) não faz parte do PhyreEngine SDK

### Release 3.1.5.0 Highlights (do Readme)
- Added Video playback utility (consistente com VP8/VP9 no FFX.exe)
- Upgraded to FMOD 4.36.00
- Upgraded to Scaleform 4.0.13
- Added multiple viewports
- Removed PClusterDependencyLoader

---

## Conclusão

| Termo | SDK 3.1.5.0 | FFX.exe | Relação |
|-------|------------|---------|---------|
| SacSlicer | ❌ (string ausente) | ✅ (%%PVER%%) | Metadado de build interno |
| PBinary | ✅ (serialização) | ✅ (uso interno) | SDK público cobre o formato |
| PCluster | ✅ (headers) | ✅ (uso intenso) | SDK cobre o formato |
| MSCD | ❌ (ausente) | ✅ (63 funcs) | Código Square Enix |
| PSARC | ❌ | ✅ (assets PS3) | Sony, fora do SDK |
| VBF | ❌ | ✅ (Virtuos) | Virtuos, fora do SDK |
| FMOD | 4.36.00 | Ex 3.7 | SDK é mais velho |
| Scaleform | 4.0.13 | — | UI (não encontrado em FFX.exe) |
| Vídeo playback | ✅ (amostra) | ✅ (libvpx) | SDK explica feature, FFX usa libvpx |

**SDK 4.00 desnecessário para RE.** O SDK 3.1.5.0 já cobre PBinary, PCluster, serialização e headers C++ suficientes. Os gaps (MSCD, VBF, PSARC, ATEL) são código Square Enix/Virtuos — não viriam de SDK Sony mesmo.
