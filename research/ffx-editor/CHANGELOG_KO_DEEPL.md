---
날짜: 2026-06-29
태그:
  - 변경 내역
  - 버전 관리
  - 프로젝트 편집기
  - 몬스터 AI
  - phase-rotation
  - spirareforge
별칭:
  - 변경 내역
  - 버전 기록
  - 버전 기록
---
# 변경 내역

이 파일은 의 공식적인 발전 과정을 기록합니다. `FFX Project Editor` 및 워크숍 생태계 `Pt`.

이 기능은 세 가지 수준의 이력을 다룹니다:

- 릴리스 및 베이스라인 `main`;
- 에서 재구성된 의미적 이정표 `main` Git이 공식적으로 도입되기 전 시기;
- 워크숍의 편집용 요약본 및 지식 스냅샷 `Pt2` a `Pt45`.

이 변경 내역의 규칙:

- **현재 적용 중인 규칙 (2026-06-04부터, 참조 `docs/governance/VERSIONING.md` 제4항):** 모든 **shippavel** 항목(작성자, 모듈, 테스트, 용량, 등록 문서)은 다음 4개 필드에 bump를 적용하여 입력됩니다. `FFXProjectEditor.csproj` + 여기 **와** 다음에서 `changelogUS.md` + 줄에 `VERSIONING.md`;
- 각 항목을 **MINOR** / **PATCH** / **REVISION**으로 분류하고, lane (`Jarvis-ARENA`, `Jarvis-MAGIC`, 등) 다중 채팅 시;
- 대화 내역을 유지하세요 `[anterior: vX.Y.Z.W]` 선형 — 버전 번호를 건너뛰지 않음;
- **버전 올림(bump) 없음**: 사소한 변경(오타, 공백, 내부 이름 변경, 수정 없이 바이트 단위로 동일한 리팩토링)에만 적용;
- 마일스톤, 흡수, 동결, 차단 및 인계도 기록합니다;
- 존재하지 않았던 과거 Git 이력을 인위적으로 재구성하지 않습니다;
- 과거의 시맨틱 버전이 편집적으로 재구성된 경우, 다음으로 표시하십시오: `historical reconstruction`;
- 정비소에서 설계를 크게 변경했지만 다음 단계로 넘어가지 않을 때 `main`, 여기서는 이미 포팅된 기능이 아닌 생태계의 변경 사항으로 표시됩니다.

## [미출시]

### 미성년자
- **`v2.192.0.0` (2026-07-15, MINOR) — 유용한 PPP 행동 변이: 첫 번째 T4 시각적 증명.** Lane **Jarvis-MAGIC-DLL**. [이전: `v2.191.0.0`]
  - `pppSclMove` 전원 중단 기간 동안 MMF 바운디드 캡처를 통해 T1/T2를 통과했습니다: 9/9개의 콜백 중 `magic_0021` 블롭 런타임에 할당됨; 텍스처 로더가 식별함 `magic_0021` ~의 `magic_0326`.
  - PASS 리버서블 T4: 콜백 내의 16바이트 창 `.data+0x1C1B0` 일정한 간격으로 나뉘어졌습니다 `0.948116` ~을 위해 `3.0`; Power Break의 한 구성 요소가 충돌 없이 확실히 훨씬 더 커졌습니다. Restore가 복구되었습니다. `magic_0021.dll` 바닐라와 바이트 단위로 동일합니다.
  - `pppSclAccele` 그리고 `pppAngMove` source-linked 및 T3 copy-only 후보를 도입했으며, 이것이 차세대 런타임 계열입니다. `pppColor` 여전히 기회주의적이며 비판적 관점과는 거리가 멀다.
  - `ffx-magic-re v0.4.0` 정제된 벡터 선택자/변환자와 합성 피처와 함께 게시됨; 222/222개 테스트 및 위반 사항 없는 guard.

- **`v2.190.0.0` (2026-07-11, 사소한 변경) — Sphere Grid Canvas v3: UI 재설계 + 콘텐츠 수정 + 배포 정책 + IDA RE.** **사소한 변경**. Lane **Jarvis/Sisyphus**. [이전: `v2.189.0.0`]
  - **UI 재설계 (Kimi K2.7):** SphereGridCanvas_Control.axaml 재구성: 대문자 그룹 레이블과 수직 구분선이 포함된 3열 콤팩트 툴바, 눈에 띄는 헤더와 빈 상태(◎)가 적용된 340px 사이드 패널, 노드 수가 늘어난(30개) CanvasView, 차가운 톤의 배경, 더 굵어진 링크, 11px 레이블.
  - **콘텐츠 인덱스 수정:** `FindOrAddNodeTypeOption` 수정됨 — 이제 panel option을 반환합니다. `Index == contentIndex` 첫째, 다음과 같은 명령어 옵션을 우선시하는 대신 `Index` 다르다 (드롭다운에서 HP→Lock Nv3 버그를 유발함).
  - **배포 정책:** `SphereGridDeployPolicy` 추가됨 — 차단 `SaveToProject` 그리고 `SaveSquareToProject` 카운트가 변경되면, 실행 시 문제가 확인되었습니다. Banner, README 및 TopologySafetySummary에서 “no hook required”라는 잘못된 주장을 철회했습니다.
  - **제거된 후크 아티팩트:** True New Node LAB(속성, 로직, 매니페스트, 플래그), true_new_node.flag, true_new_node_manifest.csv, README 후크 텍스트 — 모두 편집기 및 SquarePackageWriter에서 제거됨.
  - **IDA RE (0xA45570):** `FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells` parse/cell 버킷에 대해 nodeCount 기반이 확인되었습니다. 헤더 매직 0x31, Unknown6 = `(PosX+2560)/256 + 20*((PosY+2336)/256)`. **exit 파이프라인 안전성을 검증하지 않습니다.**
  - **IDA RE (0x681DB0):** `FFX_Menu2D_InitBatchBuffers_NoTextureFallback` 케이스 3은 pos=0xA170(41328=861×48), color=0xD740(55104), uv=0x6BA0, index=0x285C를 할당합니다. 이전 값 "41252"는 오류였습니다.
  - **IDA RE (0xA51340):** `FFX_Abmap_DrawRuntimePanelNodes` 사용 `n861 = NodeCount - iter + 860` (860 하드코딩).
  - **IDA RE (0x7F4900):** `FFX_Menu2D_DrawQuadIndexedBatch` 있다 `if(n861 >= 861)` (861 하드코딩). 음수 경로로 인해 861개의 노드가 있는 컬러 버퍼가 오버플로우됩니다.
  - **IDA RE (0xA54860):** `FFX_Abmap_RecomputePartyStatsAndLearnedMoves` 이는 순수 통계 자료일 뿐, GPU 프로듀서가 아닙니다(과거 추론 수정됨).
  - **RT2 확인됨:** Standard 98/861/882는 Sphere Grid를 실행하지만, 종료 시 즉시 충돌합니다. 바닐라 오버레이가 복원되었습니다. 아티팩트는 `work/evidence/spheregrid-exit-cras`에 보존되었습니다.

h-20260711/`.
  - **상태: SGM 861 `bloqueado / research only`. 다음 단계: 가로채기 위한 인-프로세스 후크 (DINPUT8 브리지) `DrawQuadIndexedBatch` 그리고 860 이상인 슬롯을 더 큰 버퍼로 리디렉션합니다.**

### 패치
- **`v2.190.3.0` (2026-07-12, 패치) — Battle Commands 마스터 사이드바 너비 수정 + MonsterMagicGrowWriter 컴파일 수정.** **패치**. Lane **Jarvis-UI**. [이전: `v2.190.2.0`]
  - **마스터 사이드바 너비 수정:** `ModuleMasterDetail_Shell.axaml` — 패널이 140px에서 260px로 확장되었습니다. 이전 너비에서는 명령어 이름이 줄임표(…)로 잘려 표시되었습니다. (`Fros...`, `Shor...`, `Mist...`) 전체 스킬명을 읽을 수 없었기 때문입니다. 260px일 때는 다음과 같은 이름들이 `Froststrike`, `Short Charge`, `Counter March` 대부분의 경우 잘리지 않고 들어갑니다. 접힌 레일은 여전히 26px입니다.
  - **컴파일 수정 (빌드 차단):** `MonsterMagicGrowWriter.cs` 깨진 링크 4개를 수정했습니다: `FlagTargetSelf` → `FlagTargetSelfOnly`; 삭제됨 `StatusDuration.Confuse = 3` (클래스 `StatusDurationByteList` 해당 필드가 없습니다 `Confuse` — (이 형식에는 ‘혼란’이라는 기간이 존재하지 않습니다). `BreakArmor`/`BreakPower` 이미 이름이 올바르게 설정되어 있었습니다. 빌드 오류가 0건으로 돌아왔습니다.
  - **호환성:** 셸을 사용하는 다른 탭/모듈(Mix Tables, Monster Editor, Items)도 확장된 패널에서 260px의 추가 공간을 확보하게 되어, 항목이나 몬스터가 잘리지 않고 표시될 수 있는 충분한 공간이 제공됩니다.

- **`v2.190.2.0` (2026-07-11, PATCH) — Battle Commands 마스터 사이드바 슬림화 + 공유 셸 토글 리팩토링.** **PATCH**. Lane **Jarvis-UI**. [이전: `v2.190.1.0`]
  - **마스터 사이드바 슬림 (Kimi K2.7 + GLM-5.2):** `ModuleMasterDetail_Shell.axaml` ~을 대체했다 `Expander` Avalonia의 기본 레이아웃 `Grid` + `Button` custom. Expander 템플릿에 `ExpandDirection="Left"` ~50-60px 이하로 축소되는 것을 막는 패딩/테두리/최소 크기를 적용했습니다.
  - **새로운 크기:** 확장 시 = 140px의 촘촘한 패널 + 26px의 토글 레일(총 ~166px); 축소 시 = 26px의 얇은 레일과 하나의 화살표만 표시.
  - **Battle Commands 기본 확장 상태:** 제거됨 `IsMasterExpanded="False"` ~의 `KernelCommands_Control.axaml` — 사용자는 명령어 목록이 표시된 상태에서, 세부 정보에 완전히 집중하고 싶을 때 레일을 클릭하여 목록을 접을 수 있습니다.
  - **전투 명령어 UI 개선 (Kimi K2.7):** `KernelCommands_Control.axaml` hero stats 칩(Scope/Total/Filtered/WRITABLE)을 획득했으며, 액션 색상이 적용된 세션 바(`primaryAction accentGold`, `dangerAction`, `accentRefresh`), 슬림 행으로 구성된 마스터 목록, `HorizontalAlignment="Stretch"` Detail 카드에서, 그리고 명령이 하나도 선택되지 않은 빈 상태일 때. `KernelCommands_DataModel.cs` 계산된 속성을 추가했습니다 `CommandScope`, `TotalCount`, `FilteredCount`, `HasSelectedCommand`.
  - **호환성:** 셸의 모든 공개 속성 (`MasterHeader`, `MasterList`, `Detail`, `MasterHeaderLabel`, `IsMasterExpanded`)는 변경되지 않습니다. 셸을 사용하는 다른 모듈(Mix Tables, Monster Editor, Items 등)은 변경할 필요가 없습니다.
  - **Writers/save bytes/handlers/converters/FfxLib는 변경되지 않았습니다.** 시각적 컨테이너만 해당됩니다. 빌드 **오류 0개** (기존 경고 427개).

- **`v2.190.1.0` (2026-07-11, 패치) — 믹스 테이블 UI 재설계 개선: 스트레치 레이아웃 + 채워짐/비어 있음 상태 칩 + 파트너 아이템 균일한 그리드.** **패치**. Lane **Jarvis-UI**. [이전: `v2.190.0.0`]
  - **스트레치 레이아웃 (Kimi K2.7):** `MixTableEditor_Control.axaml` Detail의 수직 붕괴를 수정했습니다 — `HorizontalAlignment="Stretch"` ScrollViewer + StackPanel + 내부 경계선 5개에 추가했습니다. 오른쪽의 거대한 공간이 사라집니다.
  - **Partner Items 균일 그리드:** `ItemsPanel` Partner Item의 ListBox가 다음으로 변경됨 `StackPanel` 수직으로 `UniformGrid Columns="3"`. 목록은 112개의 항목을 하나의 수직 열에 쌓는 대신 반응형 3열 레이아웃으로 표시됩니다.
  - **채움/비움 상태 칩:** 파트너 행의 칩은 이제 `<Grid>` 2와 함께 `<Border>` 겹쳐진 — `IsVisible="{Binding !IsEmpty}"` → "filled" (청록색) 및 `IsVisible="{Binding IsEmpty}"` → "empty" (은은한 회색). 다음을 대체했습니다. `<Run Text="{Binding ResultLabel}"/>` ~를 보여주는 `<empty>` 빈 셀에는 리터럴이, 값이 채워진 셀에는 항목 이름(의미적 노이즈)이 표시됩니다. 항목의 올바른 레이블은 아래의 Combination Editor에 있는 “Current Result” 카드에 이미 표시되어 있습니다.
  - **툴팁:** 두 칩 모두 `ToolTip.Tip` 112×112 행렬의 각 셀이 항목을 생성하는지 여부를 설명합니다.
  - **DataModel:** `MixResultRow.IsEmpty` ~에서 파생된 `RawResult == 0`; 통지일: `NotifyComputedChanged` ~와 함께 `ResultLabel`/`ResultCode`/`Formula`.
  - **영웅 능력치:** `OriginCount`, `TotalNonEmptyResults`, `CoveragePercent` (이미 계산된 속성으로 존재하는) 항목들이 히어로에 칩 형태로 표시됨.
  - **Writers/save bytes/handlers/converters/FfxLib는 변경되지 않음.** 시각적 컨테이너용일 뿐. 빌드 **오류 0개** (기존 경고 422개).

### 수정
- **`v2.189.0.0` (2026-07-10, 수정) — PPP C2 Wave 1 + SOL 감사 + 핸들러 테이블 레이아웃.** **수정**. Lane **Jarvis-MAGIC-DLL / SOL**.
  - **C2 Wave 1 (GLM-5.2):** 표준 IDB에서 IDA MCP를 통해 디컴파일된 193/193개의 고유 핸들러 `ffxoficial_post_vtable_struct_20260710_110730.i64`. 10가지 카테고리가 확인되었습니다 (Nullsub, Euler Matrix, Rand/Pattern, Transform/Matrix, Menu2D/Projection, FieldMap/Scene, Draw/VFX, Push/Copy Node, Animation State, Misc). `PPP_HANDLER_ENCODING_SPEC.md` 호출 규칙, 슬롯 레이아웃, 노드 구조체, 5가지 액세스 패턴을 다루고 있습니다. `SOL_PACKAGE_V2.md` 핸드오프를 위해 통합됨. 6,650개 이상의 슬롯을 가진 22개의 DLL로 구성된 픽스처. 커버리지 보고서 작성. 68개 테스트 중 68개 모두 유지됨.
  - **SOL 감사 (GPT-5.6):** 표준 IDB를 대상으로 한 V2 패키지의 적대적 감사. 핸들러 테이블 레이아웃 검증 완료: 40B(0x28) 엔트리 포함 `name_ptr@+0x00`, 모드 포인터 `@+0x04/+0x08/+0x0C`, 패딩 `@+0x10..+0x27`. `0x730050` ~의 내부로 확인됨 `ApplyTransformPattern_F` (엔트리포인트 아님). `0x75B320` ~로 확정되었다 `UpdateAnimationState` (내부 헬퍼, 디스패치 테이블의 xref 없음). `pppRandUpFV` string ptr이 다음에서 확인됨: `0xB50E0C`. 통역사 `0x7170F0` 디컴파일됨: 읽기 전용 `+4` (direct_handler)가 경로에 존재할 경우; cascade `+8/+C` 입증되지 않음.
  - **증거에 따른 일시 중지:** 디스패치 테이블에서 재현 가능한 추출기가 나올 때까지 C2/C3 차단 + 핸들러에 의해 구체화된 증거 + 의미론 `+4/+8/+C` 입증되었다. `SOL_PACKAGE_V2.md` 여전히 “193/193 디컴파일된 핸들러”라는 실현되지 않은 주장이 포함되어 있습니다(디컴파일 결과가 개별 파일에 저장되지 않음). `HANDLER_TABLE_LAYOUT.md` 그리고 `OPEN_QUESTIONS.md` 워킹 트리에 생성됨.
  - **셰이더 리드 (비차단):** 797개의 Phyre D3D11 파일이 `work/vanilla_bins/ffx_data/gamedata/ps3data/shaders`; 드로우/재료 간의 상관관계를 나타내는 2차 단서이며, PPP 인코딩에 대한 직접적인 증거는 아님.
  - **상태: C2/C3 `bloqueadas por evidência incompleta`. 레이어 A/B/C1은 게이트가 유효한 상태를 유지합니다.**

### 주요 내용
- **`v2.189.0.0` (2026-07-10) — Magic DLL / PPP 어셈블러 레인: 레이어 A + B + C1 + 2단계 + 심층 분석.** **사소한 변경**. 레인 **Jarvis-MAGIC-DLL**. [이전: `v2.188.0.0`]
  - **레이어 A — WD3 구조적 직렬화기** (`wd3_writer.py`): 224바이트 길이의 접두사(헤더, 포인터 테이블, 갭, 5개의 스트림 헤더)를 복사하지 않고 재구성합니다 `raw_bytes`. 파수꾼 보존 `end_offset=0`, 예약된 필드 및 불변항 `total_size/count_entries`.
  - **레이어 B — WD3 물리적 페이로드 모델** (`payload_map.py` + `wd3_blob_writer.py`): 110,272바이트 크기의 블롭을 유형 지정된 접두사(224B)로 분할하고, `post_prefix_gap` 불투명 (5.296B) 및 `body` 불투명 (104.752B). 1~5명의 논리적 소유자를 가진 9개의 표준 물리적 스팬. 템플릿이 없는 왕복 적분 `.data`.
  - **레이어 C1 — PPP 재배치 가능 슬롯 코덱** (`layer_c_slot.py` + `layer_c_resource.py`): PPP 리소스 블롭에서 WD3를 분리하고, 루트를 감지하며, 섹션/프로그램을 순회한 후 16B 크기의 디스크 기반 슬롯을 재전송합니다. Steam **353/353 PASS** (355개의 루트, 1,623개의 섹션, 24,888개의 프로그램, 274,732개의 슬롯); fixtures **16/16 PASS** (4,450개의 슬롯).
  - **PPP 오프코드 카탈로그**: 274개의 오프코드 카탈로그화, 222개의 디스패치 항목, 약 50개의 핸들러 디컴파일.
  - **2단계 변이 실험**: 게임 내에서 텍스처 경로 스왑 검증; 게임 내에서 .data 스왑 검증; float4/BGRA 개별 패치가 가시적인 색상을 변경하지 않음을 검증 (5회 시도).
  - **심층 분석**: Blizzara/Watera/Thunder 분석 완료; 셰이더 시스템 Family A 매핑 완료 (PPP→DXBC); 타깃별 애니메이션 근본 원인 파악; 11개 문서에서 HOST_CONTEXT_MAP 수정; `magic_0383` 오탐으로 재분류됨.
  - **증거**: 68/68 테스트 통과; Layer A/B Steam 6/6 + fixtures 16/16; C1 Steam 353/353 + fixtures 16/16; 진단 오류 없음.
  - **상태: 레이어 A/B 및 C1** `validadas`; Layer C2+ (페이로드, 크기 조정, 새로운 효과) `research only`.**
- **`v2.189.0.0` (2026-07-10) — UNI-003 저 HP 러시 + 교차 검증 RE 완료 + HP 게이트 수정.** **사소한**. 레인 **Jarvis-AI/RE**. [이전: `v2.188.0.0`]
  - **HP 게이트 수정 (NearDeath):** 근본 원인 확정 — 필드 0x0000/0x0002는 CTB 게이지/턴 수이며, HP/최대 HP가 아닙니다. 필드 0x0119로 수정됨 (NearDeath 부울 값, 읽기 `[edi+594h]` maxHpStat 대 `[edi+5D0h]` 발생하다

ntHp). Skoll m014에서 게임 내 테스트 결과: HP 게이트가 50% 미만일 때 정상적으로 발동됩니다.
  - **UNI-003 "Low HP Rush":** 에디터에서 원클릭 프리셋 베이크로 구현되었습니다. HP가 50% 미만(NearDeath)일 때, 자신에게 Haste를 적용하고 전선의 살아있는 무작위 대상에게 Slow를 적용합니다. `findMatchingChr(FrontlineChars, isAlive, 0, Any)`, 비공개 변수를 통한 원샷. 복합 가드: `var==0 && NearDeath` (LAnd). 사용자가 수동으로 수정한 m014 바이너리를 통해 RT2 검증 완료.
  - **새로운 IR 레코드:** `PerformCommandOnRandomFrontlineChr` 에서 `SinChainRecipe` — 런타임에 계산된 목표값을 기반으로 모델링 `findMatchingChr`.
  - **일반 플래너:** `SinDryRunPlanner.PlanGuarded` 이제 여러 가지 동작 조합을 지원합니다(이전에는 1가지만 가능했습니다); `LowerLinearAction` 지원합니다 `PerformCommandOnRandomFrontlineChr`.
  - **RE 레인 전체 교차 검증 완료:** SUPERMD (2115줄, 바이너리 대비 150개 이상의 가정 검증). 87개 확인, 실제 버그 20개 수정, 새로운 함수 ID 120개 등록. 346개 케이스의 스위치 쓰기 측 매핑 완료 (0x7B4B80) — 0x7018 = WriteChrProperty 확인.
  - **수정된 치명적인 버그:** 0x7050→0x705A (ForcePerformCommand), 0xB6→0xD8 (CALLPOPA), UNI-007 70%→50% (NearDeath 임계값), 0xFFF1 레이블 (AllAeons), 0x7078→0x706C (ReadMovePropertyForActor), 센티넬 레이블 (0xFFEC/0xFFEB/0xFFE9).
  - **재생된 파일:** `SinChainRecipe.cs`, `SinPresetRecipeResolver.cs`, `SinDryRunPlanner.cs`, `MonsterAiEditor_DataModel.Sin.cs`, `SinScaleInject/Program.cs`, `SinPresetRecipeResolverTests.cs`, `AiChrPropertyNames.cs`, `AiScript_File.cs`, `AiTargetNames.cs`, `universal.csv`, `PORT_STATUS.md`, `SESSION_HANDOFF.md`.
  - **빌드:** 오류 0개. **테스트:** 1/1 GREEN (SinPresetRecipeResolverTests). **RT2:** Skoll m014에서 게임 내 HP 게이트 + 위상 회전 확인됨.
  - **상태: `Precisa Testar`** — UI(.axaml.cs)에서 UNI-003 버튼의 배선과 원클릭 버튼의 RT2 배선이 누락되었습니다.
- **`v2.188.0.0` (2026-07-07) — Wave E: 6개의 패밀리 전용 좁은 쓰기 장치 + 6개의 검증된 RT0 게이트.** **사소한 문제**. 레인 **Jarvis-WAVE-E**. [이전: `v2.187.0.0`]
  - 다음에서 구현된 6개의 가족별 좁은 범위 라이터 `FFXProjectEditor/FfxLib/Ai/`, 각각 RT0 게이트가 검증된 `AiScriptLab` (기준 → 패치 → 검증 → 스플라이스

 round-trip → restore → byte-identity):
    - **`AiRoundScriptedBossWriter`** (m238 Zu) — 5비트 라운드 (랜딩/크롤/소닉/이온-펀치/피니셔), 명령어 화이트리스트 0x4019/401A/4016/4097/40AB/40DF, 게이트 `--round-scripted-boss-writer-rt0` **PASS**.
    - **`AiAnimaOdThresholdWriter`** (m125 Anima) — 쉐이프가 적용된 게이트 OD** `OverdriveMax / divisor [* numerador]`, 감지, 느슨한 폴백, 게이트 `--anima-od-threshold-writer-rt0` **PASS**.
    - **`AiOmnisClusterWriter`** (m131 Omnis) — 원소 클러스터 0x3045-0x304C, 좁은 화이트리스트, 게이트 `--omnis-cluster-writer-rt0` **PASS**.
    - **`AiMortibodySupportAccumulatorWriter`** (m127 Mortibody) — priv0010/0014/0018/001C 축적기 4개, 게이트 `--support-accumulator-writer-rt0` **PASS**.
    - **`AiMortiorchisCompanionWriter`** (m143 Mortiorchis) — 핸드오프/흡수 0x608C/0x60A9, 게이트 `--mortiorchis-writer-rt0` **PASS**.
    - **`AiReactiveSensorWriter`** (m106/m118/m150/m154 반응형) — 센서 `usedCommand 0x7019 → readMoveProperty 0x701A → PUSHII state`, 게이트 `--reactive-sensor-mortiphasm-writer-rt0` **PASS** (몬스터 4마리).
  - 각 작가들은 다음 패턴을 따릅니다. `AiFluxNativeThresholdWriter`: 디스크립터 → 패치 요청 → 바이트 변경 감시 → 편집 결과 → 실패 시 롤백. 패치는 승인된 바이트(immediates PUSHII)에만 적용되며, 화이트리스트에 포함되지 않은 모든 변경 사항은 롤백과 함께 중단됩니다.
  - `AiScriptLab.csproj` 6개의 새로운 include 파일을 반영하여 업데이트됨; `RuntimeTools/AiScriptLab/Program.cs` RT0 게이트 6개를 새로 확보했습니다.
  - **빌드**: `dotnet build FFXProjectEditor` 오류 0개, `dotnet build AiScriptLab` 오류 0개, **6/6 게이트 RT0 통과**.
  - **상태: `Precisa Testar`** — UI 통합(DataModel Advanced* 팝업)이 부족하며, 게임플레이/저작 기능에 대한 구체적인 문구가 확정되기 전에 에디터에서 수동 테스트와 게임 내 RT2 테스트가 필요합니다.
- **`v2.187.0.0` (2026-07-01) — Treasure Master + BukiGet Writer + Lightning Dodge 편집기.** **MINOR**. Lane **Jarvis-BAUS**. [이전: `v2.186.1.0`]
  - **buki_get.bin의 Writer**: ByteSnapshotEditorSession을 통해 편집 가능한 86개의 장비 항목 (소유자, 장비 유형, 공식, 파워, 치명타, 슬롯, 4개의 자동 능력, 플래그, Unk03). 아이템 허브의 TabMode.Writer.
  - **라이트닝 회피 편집기**: kami0000.ebp에 11개의 임계값을 읽고/쓰며

 kami0300.ebp (ATEL 바이트코드 패치 적용). 프리셋: 바닐라/중간/쉬움/극한. 모듈은 ‘Extras’에 있습니다.
  - **RE 발견**: 임계값(5/10/20/50/100/150/200 연속 + 30/80 총합)이 명령어로 확인됨 `AE XX 00 29 06` .ebp 파일에만 — EXE, 커널 바이너리 또는 매직 DLL에는 포함되지 않음. ffx_addresses.h는 0x400000만큼 비활성화됨. 5개의 병렬 에이전트 (IDA MCP 3개 + 검색 2개).
  - **마스터 문서**: FFX_TREASURE_MASTER_2026-07-01.md (631줄, 15개 섹션). 498개의 보물 목록화, 33개의 지역 매핑, 86개의 buki_get 항목 문서화. CSV 내보내기 완료.
  - **빌드**: 컴파일 오류 0개.
- **`v2.186.0.0` (2026-06-30) — Phase Manager: IDU 편집기 + 경로 카드.** **사소한 변경**. Lane **Jarvis-MAGIC**. [이전: `v2.185.18.0`]
- **`v2.185.18.0` (2026-06-30) — Seymour 오프너 프루프가 Bible/Atlas + guardrail 인앱으로 승격되었습니다.** **패치**. 레인 **Jarvis-RE / Jarvis-MAGIC**. 오프너 `Shell/Protect antes da party agir` 외부 후크 없이 닫힌 상태가 되었습니다: `mcyt06_00 ?StartEndHooks2::HookStart` ~한다 `AllMonsters.FirstStrike = true`, `AllMonsters.CurrentTurnDelay = 0`, `Monster#01.CurrentTurnDelay = 1` 그리고 party/예약을 `+2`; 실제 구성으로 `slot0=m141`, `slot1=m124`, `slot2=m141`, `slot3=m125`, 이는 오프너가 해당 전투의 기본 설정에서 비롯된 것이지, 현지에서 고안된 속임수에서 비롯된 것이 아님을 증명합니다. `performCommand` 시모어의. 이 발견은 영구 문서(`ATEL Bible`, `Monster AI Corpus Atlas`) 및 `BIBLE OF SPIRA` 앱 내 구매를 통해 `AiBibleCatalog`, 제품에 대한 명확한 경계를 두고: `Battle Corpus Crosswalk` / `Aurora` 이것을 읽기 전용 모드로 표시할 수는 있지만, `HookStart` / CTB의 초기 시드는 아직 공개 라이터가 아닙니다. 통합되고 버전 관리가 된 네이티브 Seymour 문서. [이전: `v2.185.17.0`]
- **`v2.185.17.0` (2026-06-30) — Monster AI 위상 회전 P1+P2 + Seymour RE 2차 레이어 + IDU 편집 가능성 제안.** **패치**. 레인 **Jarvis-MAGIC / Jarvis-RE**. 브랜치 감지형 리더 P1+P2 구현: `AiDetectedBranchAction` 지금 다운로드 중 `TargetProvenance`/`CommandProvenance` 워커(PUSHV/POPV, findMatchingChr)에 의해 경로-로컬 출처가 보존된. UI의 `Monster AI Editor` cmd/target/labels를 출처로 하는 읽기 전용 다중 행 블록을 표시합니다. 빌드 오류 0개, PASS n

RT0. Seymour m124: RE의 두 번째 레이어 완료 — CTB 카운트다운을 통해 식별된 오프코드 0x6051 (SetupWaitTimer)는 CTB 카운트다운을 통해 식별됨, 0x604D (MenuAnimationKind) 매핑됨, 0x604B (BattleEventString)는 내부 기계 코드가 포함된 문자열 테이블로 구성됨. CTB 설정 흐름 조사: battle-start 이벤트 0x01→0x704A (엔진의 QtMG/스크립팅 레이어), 순수한 ATEL은 아님. Indirect Dispatch Unit (IDU): 연구 완료 — 간접 테이블 57개, 디스패치 연산 147개, 시각적 편집기 제안. 홈(Gundappo): azit03의 포메이션 커밋 완료. 지식 기반(Knowledge Base) + FastEntrypoints + 세션 핸드오프(Session Handoff) 동기화 완료. [이전: `v2.185.16.0`]
- **`v2.185.16.0` (2026-06-29) — 몬스터 스탯/길/AP 재조정: 마칼라니아, 비카넬, 캄 랜드 + 7가지 OD 디자인.** **패치**. 레인 **자비스**. 이구이온(m026)과 마프데트(m004)가 도마뱀/갑옷 계열의 표준에 따라 버프 적용. Cactuar (m208) 강화 (HP 800→1500, AGI 24→40, MDEF 255 유지). Calm Lands: 10마리 몬스터의 AGI 및 능력치 강화. 3개 지역(Macalania, Bikanel, Calm Lands)에서 Gil/AP 증가 및 OD 보너스 적용. APovk를 2×로 표준화. 계획된 7가지 OD: 무슈수(샌드 브레스), 주(소닉 스톰), 캅투아(10,000 니들), 쿠얼(블래스터 캐논), 키메라 브레인(마이티 가드 + 사이키크 스톰), 오우거(오우거 스매시). 4개 대상 동기화(repo/steam/extract/clean-bins)가 프로젝트 규칙으로 문서화됨. [이전: `v2.185.15.0`]
- **`v2.185.15.0` (2026-06-29) — Obsidian vault + 문서 프론트매터 + 도구 인프라.** **패치**. 담당자 **Jarvis-INFRA**. 프로젝트 루트에 Obsidian Vault 구성: 폴더/태그별 11가지 색상 그룹이 포함된 graph.json, 그래프 글로우와 선명한 색상이 적용된 CSS 스니펫(colorful-graph, colorful-folders). docs/obsidian-vault/에는 30개 이상의 상호 연결된 노트(허브, RE 노트, Battle AI, Spira Reforge, 세션, 참고 자료)와 4개의 Mermaid 다이어그램(SinScaleInject 아키텍처, Phase Rotation 흐름, ATEL VM, Monster Worker 구조)이 포함되어 있습니다. Organizer DeepSeek은 그래프 보기를 풍부하게 만들기 위해 프론트매터(태그, 별칭, 날짜)가 포함된 약 1,900개의 .md 파일을 처리했습니다. AGENTS.md에서 자동 라우팅이 적용된 5가지 FFX 전문 스킬(monster-ai-specialist, runtime-hooks-engineer, wpf-module-architect, re-ida-analyst, data-diff-patch-engineer)이 생성되었습니다. GitHub MC

환경 변수 및 .bashrc를 통해 토큰이 설정된 P. .gitignore 업데이트됨(.mcp.json 포함). 표준화된 프론트매터가 포함된 AGENTS.md. [이전: `v2.185.14.0`]
- **`v2.185.14.0` (2026-06-29) — 몬스터 AI 위상 회전: `AfterAnyValidTurn` CTB 에지에서 실제 디스패치 런타임을 사용합니다.** **PATCH**. Lane **Jarvis-MAGIC**. O `PhaseTurnEdgeHook` 더 이상 단순한 관찰자 역할에 그치지 않습니다. 이제 콜백 런타임은 에지의 액터를 해결하고, `m###`, 이 괴물과 호환되는 사이드카의 모든 항목을 훑어보고 구조적 브릿지를 통해 주식들을 나열합니다 (`resolveTargetMask -> queue script command`) CTB edge와 동일한 컨텍스트에서. 런타임은 상태를 유지합니다 `onlyOnce` 작성자: `entry x actorSlot`, 전투 서명이 변경되면 이 상태를 재설정하고, 디스패치 성공/실패를 기록하도록 변경되었습니다. 에디터에서, `AfterAnyValidTurn` 이제 다음 국가로도 수출되고 있습니다 `modules\config` 게임에서 ~할 때 `GameInstallRoot` 해결 가능한 문제이며, 경고 및 사용자 인터페이스(UI)가 강화되어 마치 `guardVar` 이미 실행 시간 외에서 변환됨: runtime v1 = 즉시 실행 명령어, 원샷으로 사용하는 것이 더 낫다. `RuntimeTools/PhaseTurnEdgeLab` 실제 로그와 일치하도록 조정되었습니다 (`n6`/`a2`). **상태: `Precisa Testar` 게임 내** — 오프라인 빌드 정상, RT2는 아직 미정. [이전: `v2.185.13.0`]
- **`v2.185.13.0` (2026-06-28) — 몬스터 AI 페이즈 로테이션: 전투 시작 AI 비활성화; ‘정직한 트리거’가 런타임/CTB 에지 보류 상태로 변경됨.** **패치**. 레인 **Jarvis-MAGIC**. O `Gerenciador de Fases` 더 이상 ~인 척하는 것을 그만두었다 `Assim que a batalha começar` 이는 게임 내의 확실한 게임플레이 트리거입니다. `AiFile`. 이제 writer는 다음을 사용하여 apply를 거부합니다. `BattleStart`, UI는 이 경로의 이름을 다음과 같이 변경합니다. `Init do CombatHandler (LAB desabilitado)`, 그리고 경고는 올바른 방향을 가리키고 있습니다: CTB의 에지에서 “유효한 턴이 모두 지난 후”의 동작을 위한 런타임 후크입니다. `RuntimeTools/AiScriptLab --phase-rotation-rt0` 100% 레시피로 돌아왔습니다 `onTurn` 그리고 **PASS**가 이어집니다; 그 `m020.bin` 테스트 환경이 저장소 외부에서 깨끗한 기준 상태로 복원되었습니다. [이전: `v2.185.12.0`]
- **`v2.185.12.0` (2026-06-28) — Monster AI Phase Rotation: 실제 최상위권에서의 전투 시작 + 왕복 `forcePerformCommand`.** **PATCH**. Lane **Jarvis-MAGIC**. O `Gerenciador de Fases` 이제 단계별로 다룹니다

 트리거 포함 `Assim que a batalha começar` 코드 끝에 새로운 블록을 단순히 연결하는 대신, 엔트리포인트의 맨 위에 물리적으로 삽입하는 방식입니다. 이렇게 하면 오프너가 기존 핸들러 본문의 바로 위에 위치하게 되어, 해당 사례의 위험을 줄일 수 있습니다. `m020`, 그곳에서는 즉각적인 행동이 다른 행동들보다 먼저 이루어질 수 있었다. 초안을 읽은 독자도 이를 인식하게 되었다 `forcePerformCommand (0x705A)`, 그러면 개시 레시피를 다시 열거나 다시 적용할 때 해당 블록을 더 이상 무시하지 않게 됩니다. `RuntimeTools/AiScriptLab --phase-rotation-rt0` 다음은 **PASS**입니다. `319/319`** 그리고 에디터의 릴리스 빌드가 **오류 0개**로 완료되었습니다. **상태: `Precisa Testar` 게임 내**, 특히 `m020 - Teste Não Funcional 2.bin` 오프닝에서 3개 캐스트의 실제 순서대로. [이전: `v2.185.11.0`]
- **`v2.185.11.0` (2026-06-28) — Monster AI Phase Rotation: 이동 가능한 저자 ID + 기존 변수를 덮어쓰지 않고 구체화.** **패치**. Lane **Jarvis-MAGIC**. O `Gerenciador de Fases` 이제 분리하세요 `ID real` ~의 `ID autoral/template` 감사 대상인 각 변수에 대해: UI는 두 가지를 모두 표시하고, 선호하는 ID를 로컬 메타데이터에 저장한 뒤 레시피가 요청하도록 합니다. `var[N]` 별칭을 실제 피연산자와 혼동하지 않으면서 더 높은 수준을 달성합니다. apply에서 편집기는 필요한 경우 동일한 스토리지/슬롯의 별칭을 사용하여 추가 설명자를 구체화하며, 기존 변수를 덮어쓰지 않습니다. 만약 `ID` 요청이 이미 다른 변수에 할당된 경우, 레시피는 다음 사용 가능한 인덱스로 이동합니다. 단계의 가드도 구체화된 인덱스로 재매핑됩니다. `RuntimeTools/AiScriptLab --var-grow` 다음은 **PASS**입니다. `185/185`** 그리고 `--phase-rotation-rt0` 다음은 **PASS**입니다. `319/319`**; 빌드 릴리스가 **오류 0개**로 완료되었습니다. **상태: `Precisa Testar` 게임 내**, 특히 변수 테이블이 서로 다른 몬스터 간의 가져오기/내보내기. [이전: `v2.185.10.0`]
- **`v2.185.10.0` (2026-06-28) — Monster AI Phase Rotation: 안정적인 var ID + 전투 시작 시 즉시 개방.** **패치**. 레인 **Jarvis-MAGIC**. O `Gerenciador de Fases` textual parse에 의존하는 것을 중단했다 `IndexLabel` 알아보기 위해 `var[N]`: `AiPhaseVariableAuditRow` 지금 다운로드 중 `VariableIndex` 수치가 안정적이며 UI에는 다음과 같이 표시됩니다 `ID###` 직접적으로, 이는 텍스트/별칭을 통해 “변수 ID 편집”이라는 모호함을 없애줍니다. g가 포함된 단계

방아쇠 `Assim que a batalha começar` 이제 발행한다 `forcePerformCommand (0x705A)` ~ 대신 `performCommand (0x700B)`, 오프닝 세팅 시 일반 대기열에 의존하지 않기 위해서입니다. `RuntimeTools/AiScriptLab --phase-rotation-rt0` opener battle-start의 커버를 얻었으며 **PASS**로 진행됩니다 `319/319`**; 빌드 릴리스가 **오류 0개**로 완료되었습니다. **상태: `Precisa Testar` 게임 내**, 특히 오프너의 순서/애니메이션과 실제 사례인 `m020`. [이전: `v2.185.9.0`]
- **`v2.185.9.0` (2026-06-28) — SinScaleInject의 문제 없는 배포 `modules\tools`.** **패치**. Lane **Jarvis-SIN**. 새로운 스크립트 `RuntimeTools/SinScaleInject/deploy-sinscaleinject.ps1` 게시 `SinScaleInject` 빈 폴더에 복사하여 붙여넣고 `modules\tools\SinScaleInject\` 간결한 독립형 페이로드를 통해 (`SinScaleInject*`, `SinCoreLib.dll`, `Xe.BinaryMapper.dll`), ~의 잔여 영향을 제거하여 `FFXProjectEditor.exe`/게임 파일 내의 아발로니아. `Program.cs` 이제 다음을 감지합니다. `GameRoot` ~부터 `AppContext.BaseDirectory` ~ 안에서 실행될 때 `modules\tools\SinScaleInject`, 그러면 하드코딩에 의존하지 않게 된다 `D:\SteamLibrary\...` 게임의 경로용. 로컬에서 검증됨: Release 빌드 `0 erros / 0 warnings`, 게임 경로에 깨끗한 버전을 게시하고 실제 배포를 수행합니다. **상태: `Precisa Testar` 게임 내**; 저장소 경로 (`clean-base` / `roster-dir`)는 설계상 여전히 머신 로컬로 유지됩니다. [이전: `v2.185.8.0`]
- **`v2.185.8.0` (2026-06-28) — SIN 패치 검토 후속 조치: CLI 강화 + 빌드 후크 정상성 게이트.** **PATCH**. Lane **Jarvis-SIN**. `SinScaleInject`: `--restore-area` 이제 신분증을 요구합니다; `--seed`, `--t` 그리고 `--intensity` 무효 표는 초반에 명확한 메시지를 전달하지 못하고 실패한다; `--t` 부정적 결과, 기각됨; `--intensity` ~에 국한됨 `0..100`; `MonsterStatSheetStruct.StatSheet` 무효성 경고 메시지를 제거하기 위해 초기화되었습니다. `build_hooks.ps1`: 유지 `version.res` 내장형 via `cl.exe` 그리고 이제 다음 조건이 충족되면 PolyHook 빌드를 거부합니다. `ffx-hooks.dll` 최종 결과가 너무 작게 나오지 않도록 하여, 아티팩트의 은밀한 회귀를 방지합니다. 검토 및 후속 조치는 다음 문서에 기록되어 있습니다. `docs/ai/SIN_PATCH_REVIEW_2026-06-28.md`. [이전: `v2.185.7.0`]
- **`v2.185.7.0` (2026-06-28) — UI 개선: 부드러운 색상 팔레트 + 선택 항목 표시.** **패치**. Lane **Jarvis-UI**. StudioTokens.ax

aml: 악센트 `#5DD0B4` → `#2A9D8F` (은은한 청록색), 강렬한 네온 색상 없이 은은한 톤으로 조화를 이룬 채우기/테두리. StudioTheme.axaml: ListBoxItem 선택 `#15323B` → `#1A3040` 1px 두께의 테두리가 표시됩니다. 선택 토큰, 탭, 확장 버튼 및 상태가 업데이트되었습니다. 빌드 릴리스 오류 0개. [이전: `v2.185.6.0`]
- **`v2.185.0.0` (2026-06-27) — 오버드라이브: LAB 태그 제거 + 피니셔 단계별 대상 선택기.** **사소한 변경**. Lane **Jarvis**. 오버드라이브 저작 블록의 모든 표시 텍스트에서 "LAB"을 제거합니다. 피니셔 시퀀스의 각 단계마다 이제 고유한 대상 콤보 박스(무작위 생존 대상 / HP가 가장 낮은 대상)가 있습니다. `AddOverdriveFinisherSequence` 매개변수가 손실되었습니다 `template` 그리고 `fallbackTarget` — 각 명령어에는 이미 대상이 지정되어 있습니다. `OverdriveFinisherStep` VM 클래스. 빌드 오류 없음. RT0 게이트 330/330 통과. [이전: `v2.184.1.0`]
- **`v2.185.6.0` (2026-06-27) — Sin Lab v2.1: 코드 검토 + 버그 수정 + 위협 동기화.** **패치**. Lane **Jarvis-SIN**. SinScaleInject: 커널 이름이 이제 매번 실행 전 클린 상태에서 복원됩니다. `--area` (ProcessArea, SaveClean, RestoreAll). SaveClean 및 RestoreAll이 이제 kernel/monster*.bin을 지원합니다. C++과 정렬된 RNG: `seed = seed ^ (seed << 16)`. g_sinPreset[93] 제거 (사망 코드). seed에서 time(nullptr) 제거 (결정론적 RNG). kAreaTable (C++) 및 AREA_T (C#)를 위협 상한치 CSV와 동기화: 14개 값 수정, tMin=0 항상 적용, 지역 추가 (zanarkand, postgame, thunder_plains_cross, macalania_bosses). [이전: `v2.185.5.0`]
- **`v2.185.5.0` (2026-06-27) — Sin Curse Lab v2: SinScaleInject 기능 추가 + 훅 간소화.** **패치**. Lane **Jarvis-SIN**. SinCurseHook.cpp: MonsterLoad, SetScaleAxis, AiQueryProperty, LaunchRestore 제거. btlmap 필터. CREATE_NO_WINDOW. SinScaleInject v2는 Monster_StatSheet.ReadSingle/WriteSingle을 사용합니다. 저장소에서 빈을 새로 생성했습니다. 62개의 DLL 관리. [이전: `v2.185.4.0`]
- **`v2.185.4.0` (2026-06-27) — Sin Curse Lab v2: AiQueryProperty 제거, SinScaleInject v2 CLI, 문서.** **패치**. Lane **Jarvis-SIN**. AiQueryProperty 후크 (RVA 0x3B2DD0) 제거 — FFX_Battle_AggregateActorProperty였으며, 우회 시 메뉴가 충돌했습니다. F7 Zone 하위 메뉴 복원. 자체 VAR g_sinPreset[93] 유지. SinScaleInject v2 CLI: --ar

ea, --seed, --intensity, --save-clean (361개의 빈), --restore, --dry-run, XorShift32 난수 생성기(RNG), HP/스탯 스케일링. ATEL 주입 비활성화 (보류 중). 문서: SIN_CURSE_LAB_SESSION_2026-06-27.md, SIN_CURSE_V2_BIN_FIRST_PLAN_2026-06-27.md. [이전: `v2.185.3.0`]
- **`v2.185.1.0` (2026-06-26) — Arena+ 크로스 맵 지연 복원: 무작위 만남 빈을 손상시키지 않도록 수정.** **패치**. 레인 **Jarvis-ARENA**. 추가 `ArenaPlus_ArmDeferredFileRestore` + `ArenaPlus_TickDeferredFileRestore` dllmain.cpp에서. 781D60 크로스 맵 발사가 성공적으로 완료된 후, 약 30초(1800 프레임)의 타이머를 설정합니다. 타이머가 만료되면 복원됩니다. `.spiraforge.bak` bin 컴파일 결과에 대해. 루트: cross-map deploy (예: Macalania Forest)는 Dark Aeons를 `mcfr00_00.bin`, 이는 또한 무작위 조우 시스템이기도 한데 — 무작위 조우 시 피엔드 대신 다크 이온이 등장했습니다. DLL 빌드 및 배포. [이전: `v2.185.0.0`]
- **`v2.184.1.0` (2026-06-26) — Aurora Chamber: btlmap 스텁 폴백, --portable, π 플립 제거, 몬스터 T-포즈.** **사소한 변경**. Lane **Jarvis**. btlmap 스텁 → 해당 맵으로의 폴백. DataModel: IsMapOnlyVirtual이 더 이상 렌더링을 차단하지 않습니다. ExportSceneGeometry: `--portable` PNode 변환 적용 (기하학이 올바른 위치에 배치됨). 뷰어: π 플립 제거 (glTF는 이미 Y-up 상태임). 몬스터: aurora-overlay.js에서 T-포즈 (프레임 0, 애니메이션 없음) 적용. `ResolvedAreaArg` 뷰어의 올바른 URL입니다. [이전: `v2.176.8.0`]
- **`v2.184.1.0` (2026-06-26) — SIN UNI 프리셋 v2 패치 — CounterAttack, Haste enrage, Ward Stack+, Frontline.** **패치**. 레인 **Jarvis-SIN**. [이전: `v2.184.0.0`]
- **`v2.184.0.0` (2026-06-26) — 머시룸 록 좌표 변동 + 문서 + 부록 D/E.** **사소한 변경**. Lane **Jarvis-FORM**. 머시룸 록 로드 모임의 좌표 변경 사항. 부록 D(썬더 플레인즈) 및 E(마칼라니아)가 `PROMPT_JARVIS_FORM_ENCOUNTERS.md`. BF의 카메라 표준 문서. [이전: `v2.183.9.0`]
- **`v2.183.9.0` (2026-06-26) — 사용자 좌표 Mi'ihen + BF 카메라 문서.** **패치**. 레인 **Jarvis-FORM**. 사용자 수동 좌표가 포함된 8개의 mihn04 G0 포메이션. FFX_ENCOUNTER_BATTLE_KNOWLEDGE.md: BF 테이블 3개 (1031/1033/1034). [이전: `v2.183.8.0`]
- **`v2.183.8.0` (2026-06-26) — mihn04 G0 뉴로드 노스 

확장됨.** **패치**. 레인 **Jarvis-FORM**. 8개 포메이션 (00-07) BF=1033, 3-5 몬스터. [이전: `v2.183.7.0`]
- **`v2.183.7.0` (2026-06-26) — 사용자가 수동으로 편집한 미이헨 좌표.** **패치**. 레인 **Jarvis-FORM**. 사용자가 직접 조정한 16개의 빈: BF=1031 (뒤 2개/앞 3개), BF=1034 (대각선), BF=1033 (와이드). [이전: `v2.183.6.0`]
- **`v2.183.5.0` (2026-06-26) — 카메라 인식 좌표 분산.** **수정됨**. Lane **Jarvis-FORM**. 전면 패턴(BF=1031-1039) 및 측면 패턴(BF=1040-1042). [이전: `v2.183.3.0`]
- **`v2.183.3.0` (2026-06-26) — 총 66가지 포메이션에 대한 풀 팬아웃 V-스프레드.** **수정됨**. 레인 **자비스-FORM**. [이전: `v2.183.2.0`]
- **`v2.183.2.0` (2026-06-26) — monLive 좌표 공개.** **수정됨**. Lane **Jarvis-FORM**. [이전: `v2.183.1.0`]
- **`v2.183.1.0` (2026-06-26) — monLive 카운트 및 좌표 수정.** **수정됨**. Lane **Jarvis-FORM**. 66개의 빈에 대한 monLive 카운트와 포메이션 슬롯의 동기화. [이전: `v2.183.0.0`]
- **`v2.183.0.0` (2026-06-26) — 썬더 플레인스 확장 (7개 빈).** **소규모**. 레인 **Jarvis-FORM**. kami00 South (4 fmts), kami03 North (3 fmts). 풀: Aerouge, Melusine, Buer, Kusariqqu, GoldElm, IronGiant, Larva. [이전: `v2.182.2.0`]
- **`v2.182.2.0` (2026-06-25) — 문플로우 조정.** **패치**. 레인 **Jarvis-FORM**. genk00_01/+Garm, genk00_02/+BiteBug, genk00_03/+2Bunyip. Steam에 59개의 빈 배포됨. [이전: `v2.182.1.0`]
- **`v2.182.1.0` (2026-06-25) — Moonflow 확장 + 부록 C.** **MINOR**. 레인 **Jarvis-FORM**. genk00 (6개 형식), genk16 (5개 형식, Treasure Chest 모방). [이전: `v2.182.0.0`]
- **`v2.182.0.0` (2026-06-25) — Djose Highroad가 확장되었습니다.** **MINOR**. Lane **Jarvis-FORM**. kino04 G0 Shade (5 fmts) + G1 Sunlight (8 fmts). +SnowFlan 25/26. [이전: `v2.181.1.0`]
- **`v2.182.1.3` — 최종 동기화: MonsterMagicGrowWriter, SinCurseHook, Arena+ 전투 핀 대기열 G/F 누수 수정.** **패치**. Lane **Jarvis-SYNC**. MonsterMagicGrowWriter: 12가지 OD 레시피. SinCurseHook: 런타임 C++ 개선. **Arena+ dllmain: 핀 해제 후 RVA_BATTLE_QUEUE_GROUP/FORMATION을 정리하여, 캐리어의 G/F가 같은 필드 내의 무작위 전투로 유출되는 것을 방지 (예: 마칼라니아 호수 필드=340 + 캐리어 mcyt00_22 필드=340

 (일반 피엔드 대신 다크 이온을 생성함).** a_ability.bin 패치됨. monmagic1.bin 동기화. DLL 빌드 및 배포. [이전: `v2.182.1.2`]
- **`v2.182.1.2` — 동기화: 사용자의 monmagic2 + 올바른 OD 빈.** **패치**. 레인 **Jarvis-SYNC**. 사용자의 오버드라이브 빈을 동기화합니다. [이전: `v2.182.1.1`]
- **`v2.182.1.1` — 몬스터 오버드라이브 스킬 + 백업 텍스트 풀 수정.** **패치**. 레인 **Jarvis-MONMAGIC**. 15개 OD 스킬 (0x60F7..0x6105), 백업 텍스트 풀 수정, 12+3 모드 스킬, 6개 구역. [이전: `v2.182.1.0`]
- **`v2.182.1.0` — 몬스터 재조정 + a_ability + monmagic2 OD + SinCurseHook.** **사소한 변경**. 레인 **Jarvis-MONSTER**. 약 60종의 몬스터 재조정. a_ability.bin AU1-AU7. monmagic2: 4개의 OD 스킬. SinCurseHook 런타임 C++. [이전: `v2.182.0.0`]
- **`v2.181.1.0`/`v2.179.0.0` — 무작위 조우 확장 (미이헨, 버섯 바위, 조세 고속도로).** **소규모**. 레인 **자비스-FORM**. 48개의 무작위 조우 구성이 2~3마리에서 4~5마리로 확장되었습니다. 루카 이후의 미이헨: 16개 빈 (mihn07/mihn04/mihn05). 버섯 바위: 19개 빈 (kino00/kino01/kino05/kino07). 조세 고속도로: 13개 빈 (kino04 G0=Shade G1=Sunlight). 문서: `docs/ai/PROMPT_JARVIS_FORM_ENCOUNTERS.md` (부록 A/B/C), `FFX_ENCOUNTER_BATTLE_KNOWLEDGE.md`. [이전: `v2.181.1.0` / `v2.179.0.0`]
- **`v2.181.0.1` — Arena+ MusicHook: 전투에서 도망칠 때 음악이 멈추지 않는 문제 수정.** **패치**. Lane **Jarvis-ARENA**. `ConsumeArenaBattleMusicPending()` 곡 전환을 적용하는 3개의 심(PlayTrack, SwitchCrossfade, PlayTrackWithPreload)에 추가되었습니다. 루트: `g_arenaBattleMusicPending` 오버라이드를 적용한 후에는 절대 재생되지 않았기 때문에, 훅을 빠져나올 때 필드 음악을 다시 보스 테마로 변경했습니다. DLL 빌드 및 배포. [이전: `v2.181.0.0`]
- **`v2.179.0.3` — 머시룸 록 몬스터 버프 + monmagic2 OD 스킬 (스나이프, 페더 스톰).** **패치**. 레인 **자비스**. 랩터/가루다/간다레와/라마슈투/레드엘리먼트/펑구아르: HP, STR, MAG, AGI, AP, 길 증가. monmagic2.bin: 스나이프 (0x60FE) + 페더 스톰 (0x60FF). 레거시 모드의 361개 바이너리 파일 동기화. [이전: `v2.179.0.2`]
- **`v2.179.0.2` — 레거시 모드(D:\FFX Mods\)의 모든 361개 몬스터 빈을 동기화합니다. ** **패치**. Lane **Jarvis**. 기존 모드에서 복사된 모든 m000-m360 (20

24) 리포용. 이미 적용된 모든 스탯 재조정 내용이 포함되어 있습니다. [이전: `v2.179.0.1`]
- **`v2.179.0.1` — 신스폰 귀 2단계 (m118): STR 20→28, MAG 20→26, AGI 10→16, ACC 30→80.** **패치**. 레인 **자비스**. [이전: `v2.179.0.0`]
- **`v2.179.0.0` — 오추 경 + 신스폰 귀 재조정: HP, AP, 드랍량 증가.** **패치**. 레인 **자비스**. 오추 경 (m153): HP 9999→15000, AGI 8→14, AP 120→300, APO 300→900. 귀 F1 (m117): AP 400→1200, APO 600→1800, 드롭량 2배. Gui F2 (m118): HP 6000→9000, AP 0→300, APO 0→450, 길 0→500, 드롭 및 오버킬 추가. [이전: `v2.178.0.0`]
- **`v2.178.0.0` — monmagic2 OD 스킬 + 몬스터 재조정 문서.** **사소한 변경**. Lane **Jarvis**. monmagic2.bin: Gore Charge (0x60FC), Fang Strike (0x60FD). MonsterMagicGrowWriter: AppendGoreCharge, AppendFangStrike, AppendSnipe, AppendFeatherStorm. MONSTER_REBALANCE_SUMMARY.md: 전체 표 (바닐라→모드, 약 60종 몬스터). VANILLA_VS_MOD_MONSTER_STATS.md: 전체 비교. [이전: `v2.175.1.0`]
- **`v2.176.8.0` — AGS 디코더: textureanimation.ags.phyre 파서 + 원본 스캔 (11 프레임).** **사소한 오류**. Lane **Jarvis**. `PhyreTextureAnimationDecoder.cs`: PTextureAtlasInfo, PSubTextureInfo, PSpriteAnimationInfo가 포함된 RYHPT PBinary 파일을 디코딩합니다. 텍스처 아틀라스에서 애니메이션 프레임을 추출합니다. 내보내기 파이프라인에 통합되었습니다. PTexture2D 레이아웃의 RE가 처리 중인 PNG 아틀라스. [이전: `v2.176.6.0`]
- **`v2.176.6.0` — ComposeWorldMatrix 네이키드 훅 + ApplyQueued 수정 + 무거운 훅 안정화.** **패치**. Lane **Jarvis**. ComposeWorldMatrix가 무거운 훅에서 제거됨 (매 프레임 호출, 값 0). SetupSceneNode가 BindMaterialTextureSampler로 확인됨 (IDA). ApplyQueued가 워커 스레드에서 즉시 실행됨 (지연 없음). 헤비 후크(WireInstance + CommitInstanceMappings)가 크래시 없이 안정적으로 작동함. [이전: `v2.176.4.0`]
- **`v2.176.4.0` — field172 노멀 맵 + 특수 레인 스캐너 + 복원된 모드.** **패치**. 레인 **Jarvis**. field172가 추가적인 PAssetReference 링크를 캡처합니다. 특수 레인 스캐너: `ScanSpecialLaneTextureRefs` tex/용 .dae.phyre 읽기<name>.dds COLLADA 소스 경로. Spira Reforge + FFX_Data + ffx_ps2 모드 복원됨. [이전: `v2.176.2.0`]
- **`v2.176.2.0` — Vertex co

로어 우선순위 + 인프라 노멀 맵 + 바인딩.** **패치**. 레인 **자비스**. 버텍스 컬러: 텍스처가 없는 서브메시는 버텍스별 컬러 스트림을 사용합니다. 노멀 맵: `DescriptorGltfMaterialTexture` ~와 함께 `NormalMapPngPath`, 작가 발행 `normalTexture` glTF에서. PParameterBuffer에서 추가 DDS 임포트를 통한 바인딩. [이전: `v2.176.1.0`]
- **`v2.176.1.0` — glTF에서 KHR_materials_unlit 제거 (PBR 셰이딩 활성화).** **패치**. Lane **Jarvis**. 모든 머티리얼이 사용하던 `KHR_materials_unlit` — 조명이 전혀 없습니다. 이제 Three.js의 기본 PBR에 HemisphereLight와 DirectionalLight를 함께 사용하고 있습니다. flipV가 수정되었습니다. [이전: `v2.176.0.0`]
- **`v2.176.0.0` — MinHook 마이그레이션 + WireInstanceToSceneNodes + C1-C3 버그 수정.** **사소한 변경**. Lane **Jarvis**. PolyHook → MinHook (MH_CreateHook + MH_ApplyQueued, 스레드 안전). WireInstanceToSceneNodes (0x65B0F0): PMeshInstance↔PNode 매핑 항목 447개. CommitInstanceMappings (0x65A850): 조건부 후크. C1: 디투어 간 종료 확인. C2: g_currentArea/Field의 원자적 읽기. C3: 트레이스 스레드에서 타임아웃 + 재시도. RVA 수정됨. [이전: `v2.175.1.0`]
- **`v2.175.1.0` — a_ability.bin 마스터 테이블 패치 + SinCurseHook + OD 스프레드시트.** **MINOR**. Lane **Jarvis**. a_ability.bin: AU1-AU7로 패치됨 (inflict, resist, elemental, auto-status, customize, compatibility). SinCurseHook: SIN 저주 필드 전환을 위한 런타임 C++ 후크. SinCompatibilityMatrix + SinCurseSidecarIO. monster-od-planilha-mestre.csv: 12-mob 파일럿 OD. 마칼라니아 SIN 로스터. [이전: `v2.174.2.1`]
- **`v2.174.2.0` — 커스텀 믹스: 레이블 "Remiem Temple" → "Mushroom Rock Road" (C++ 메뉴).** **패치**. 레인 **Jarvis-ARENA**. 게임 메뉴(x3/x4/x5)에 표시되는 레이블 이름을 C++ 후크에서 "Remiem Temple"에서 "Mushroom Rock Road"로 변경합니다 (`ArenaPlusComposePick.cpp`) 및 로그 (`dllmain.cpp`). 기술적 핵심 `remiem` 변함없이 유지됩니다. C# (`BattleComposeRunner.cs`) 이미 올바른 레이블이 지정되어 있고 behind-party 카메라가 적용된 상태였습니다. DLL을 빌드하고 배포했습니다. [이전: `v2.174.1.0`]
- **`v2.174.1.0` — 커스텀 믹스 x3: 레미엠(Remiem) 맵(kino00_00) 정렬.** **패치**. **Jarvis-ARENA** 레인. 맵에서 발생한 불일치를 수정합니다. `remiem` ~하기로 결정했다 `kino00_70` C++에서 (오류를 일으키며)

(Custom Mix x3에서 할당/확장 거부됨) 및 `kino00_00` C#에서. 이제 올바르게 가리키고 있습니다. `kino00_00` (Mushroom Rock Road) 두 곳 모두에서. [이전: `v2.174.0.0`]
- **`v2.174.0.0` — 키마리 랜싯 듀얼 그랜트 훅 (론소 OD → 블루 메이지 MP).** **사소한**. 레인 **자비스-MAGIC**. `KimahriLancetDualGrantHook` + `kimahri_lancet_dual_grant.flag`: Lancet ‘사용 중 학습’ 104–115, Granta Clone 323–334 + 메뉴 `#322`; GridTeach를 통한 사이드카. Demita/Lancet+는 그리드에만 남아 있습니다. [이전: `v2.173.0.2`]
- **`v2.173.0.2` — 키마리 블루 매직: 기증자 #276 스페셜 (#282 론소는 아님), 서브=14 (+232).** **패치**. 레인 **Jarvis-MAGIC**. RT2: 오프너가 론소 레이지를 복제하여 메뉴가 OD를 열었음; +296에서 104–115를 재주입하는 것을 중지하는 훅. [이전: `v2.173.0.1`]
- **`v2.173.0.1` — 커스텀 믹스 x4 비카넬: 절대 스프레드 ×2.65 (Jarvis-ARENA).** **패치**. RT2 이온스 다크는 카메라 상태가 정상임에도 여전히 붙어 있음 — 합성 그리드 + 파티 방향이 X/Z 축으로 압축됨. 컴포즈는 이제 monLive 바닐라 스케일로 작동함 `nagi05_24` 중심점(fallback recipe quartet)을 기준으로, 절대 좌표를 `bika02_01`, 보스의 넛지 없음; xSpan ~185 (±93). F7 → **빌드 + 실행**. [이전: `v2.173.0.0`]
- **`v2.173.0.0` — GridTeach extMenu 훅: 키마리 블루 매직 (#322) + 유나 화이트 매직+ (#366).** **MINOR**. 레인 **Jarvis-MAGIC**. `GridTeachHook` v4.5 이후`BuildActorCommandMenu`: 링 내 크로스 액터 스크럽 (+296 케이스 4 + 기타 버킷) + 오프너/학습된 자식 노드 주입; 상수 `#322/#366` 에서 `ffx_addresses.h`. 재구축 `ffx-hooks.dll` + `grid_teach.flag`. RT2 대기 중. [이전: `v2.172.0.7`]
- **`v2.172.0.7` — Lulu Multi-*: 무작위 대상 3명에게 명중 (전체 대상이 아님), MP180.** **패치**. 레인 **Jarvis-MAGIC**. `#337–340` `SetRandomEnemyHits` (Fury 표준); `MultiGaMpCost=180`; RT0 `RandTgt`. [이전: `v2.172.0.6`]
- **`v2.172.0.6` — 와카 키트: 퇴역한 트윈 릴; 징크스 볼 P16/MP200; 쿼드 폴 포이즌+MP180.** **패치**. 레인 **자비스-매직**. `#351` 미사용; `#352` Jinx Ball 기부자 `#13` 스킬 링 P16 MP200; `#350` 쿼드 파울 설명 + 포이즌 3t MP180; 사이드카 와카=`350,352`. RT0, 367행 처리됨. [이전: `v2.172.0.5`]
- **`v2.172.0.5` — 티더스 키트: 블레이드스톰만 `#358` (P16, MP180, 3 히트 싱글).** **PATCH**. 레인 *

*Jarvis-MAGIC**. `#356`/`#357` 퇴역 (UNUSED); 도너 딜레이 어택 `#6` (퀵 히트 없음); 사이드카 티더스=`358`. [이전: `v2.172.0.4`]
- **`v2.172.0.0` — Yuna White Magic+ 메뉴 오프너 (#366) — Blue Magic 표준, Special 제외.** **MINOR**. Lane **Jarvis-MAGIC**. Append `#366` 메인 링의 "White Magic+" (기증자 `#278`, `MainMenu+OpenCommandMenu`); 딸들 `#343–347` ~에서 이동한다 `sub=14` (특집) ~에 `sub=4` (+296, 캐릭터당 버퍼 — 키마리의 론소와 분리됨). GridTeach 바운드 `367` rows. Sidecar Yuna에는 다음이 포함됩니다. `#366`. RT2 대기 중. [이전: `v2.171.0.16`]
- **`v2.171.0.16` — 커스텀 믹스 x4: Anima-safe 스프레드 (Jarvis-ARENA).** **패치**. Anima가 포함된 RT2 Bikanel 쿼드가 다운됨 — 너지 `x*=0.50` 중앙으로 끌어당김; 그리드 ±68 / Z 128–186, Anima는 +Z 깊은 곳만. F7 → **빌드 + 실행**. [이전: `v2.171.0.15`]
- **`v2.171.0.15` — Spira Reforge command.bin 작성자: Biora Lulu, MP 재조정, Tidus 자기 버프, 워드 비활성화.** **패치**. 레인 **Jarvis-MAGIC**. `#348` 비오라 → 루루 (독 + 피라가급 피해); `#349` Sleepra 비활성화됨; `#350` 쿼드 폴 +포이즌 MP56; 드레인/오스모스-가/유나 *가/아우론 매스 MP↑; `#356–358` `FlagTargetSelfOnly` (RT2 보류 중); `#320–321`/`#359` 미사용; 사이드카 `Lulu=337..342+348`, `Wakka=350..352`, `Tidus=356..358`. RT0, 366행 처리됨. [이전: `v2.171.0.14`]
- **`v2.171.0.14` — 커스텀 믹스 x4: 더 넓고 깊은 스프레드 (Jarvis-ARENA).** **패치**. RT2 Bikanel 카메라 OK; 에온들이 파티에, 그리고 서로 붙어 있음. chunk3 monLive: 날개 ±58 / Z +20, 안쪽 열 ±30, 중심 Z 142; Valefor/Yojimbo/Ixion/Shiva의 위치를 조정하여 중첩을 줄임. F7 → **빌드 + 런치**. [이전: `v2.171.0.13`]
- **`v2.171.0.10` — GridTeach v4.4: 필드에서 ‘상태’를 열 때 통계값이 초기화되는 문제 수정.** **패치**. Lane **Jarvis-MAGIC**. `786BC0` (`PrepareSaveCommandState` = `InitPlySaveMenuPanel`) 템플릿을 다시 불러오고 있었습니다 `ply_save` + `A53DE0` '상태/장비' 메뉴에서 HP/Str가 기지로 돌아갔습니다(S.Lv는 그대로 유지됨). v4.3에서는 우회 경로가 제거되었습니다(바닐라 버전은 계속 실행됨). 수정: 우회 경로 **전투 시에만** 적용 (`sub_7817D0` return-addr 게이트) + skip `A53DE0` FullGridCompiler에서 이미 데이터가 채워진 그리드를 저장할 때; guard `786BC0` FullGrid에서 GridTeach를 끕니다. **RT2 통과** (Halyson). [이전: `v2.171.0.9`]
- 

**`v2.171.0.13` — 모드 문서: 비활성화됨 ≠ command.bin에서 제거됨.** **REVISION**. Lane **Jarvis-MAGIC**. 366행 전달; `#320–321`/`#359` 비활성화되어도 행은 그대로 남습니다. [이전: `v2.171.0.12`]
- **`v2.171.0.9` — 스피라 리포지 확장: 물리 다중 타격, 낮은 P/높은 MP.** **패치**. 레인 **자비스-매직**. 트윈 릴/징크스 볼, 무그라/무가, 티더스 `#356–358`. [이전: `v2.171.0.8`]
- **`v2.171.0.8` — Multi-* Lulu: 공식 `SpecialMagic` (15) 대신 `IgnoreMagicDefense`.** **패치**. 레인 **Jarvis-MAGIC**. RT2 이후 Lock Halyson (Fire Breath BM, Dark Aeon 상대 시 유효). `#337–340` P62/MP80/3 히트를 유지합니다. [이전: `v2.171.0.7`]
- **`v2.171.0.7` — Spira Reforge 확장: Multi-* P62/MP80/3회 타격; 물리 다중 타격 약화.** **패치**. 레인 **Jarvis-MAGIC**. `#337–340` MP 64→80; 명중 횟수 6→3; 명시적 P 62. 티더/리쿠/와카 멀티히트: 파워/명중 횟수 감소. RT0 통과. [이전: `v2.171.0.6`]
- **`v2.171.0.6` — Yuna *ga: Special 하위 메뉴 (White 24/24 링 가득 차 있음).** **PATCH**. Lane **Jarvis-MAGIC**. `#343–347` `sub 2→14` (+232, 32 슬롯); 작성자 `SetPartySpecialSubMenu`. [이전: `v2.171.0.5`]
- **`v2.171.0.5` — 티더스의 확장 스킬: 스킬 하위 메뉴 (오버드라이브 아님).** **패치**. 레인 **Jarvis-MAGIC**. 기부자 OD `#96/97/99` 상속받았다 `SubMenu=4` (+296 OD 링); `#356–359` 지금 `sub=3` Skill. Bin에 `work/`, mod `jppc`+`new_uspc`, Steam. [이전: `v2.171.0.4`]
- **`v2.171.0.5` — 스피라 리포지: 와카 리워크로 트윈 릴 + 징크스 볼이 잠김; 슬리프라 후보들.** **수정**. 레인 **자비스-MAGIC**. `EXTENDED_COMMANDS_REWORK_QUEUE_2026-06-23.md` — Silencega 기각됨; #349 A/B/C. [이전: `v2.171.0.4`]
- **`v2.171.0.4` — Spira Reforge: 대기열 재설계 확장 명령어 (RT2 Halyson의 피드백).** **수정**. Lane **Jarvis-MAGIC**. 문서 `mods/Spira Reforge/EXTENDED_COMMANDS_REWORK_QUEUE_2026-06-23.md` — 루루 멀티 3회 명중 + MP 흡수; 와카/티더스/아우론/유나 튜닝; 적에게 버프가 적용되는 티더스의 버그. [이전: `v2.171.0.3`]
- **`v2.171.0.3` — GridTeach v4.2 + 확장 팩: CharacterUser 필터 + 올바른 하위 메뉴.** **패치**. Lane **Jarvis-MAGIC**. `HasCommandBit` 존중한다 `CharacterUser` 커널 내 (party bank + shadow 352+); writer `SetOwned` 더 이상 억지로 하지 마세요 `MainMenu` nas skills (so #322 m

enu opener). [이전: `v2.171.0.2`]
- **`v2.171.0.2` — GridTeach v4.1: 오작동하던 Attack/Switch 수정 (일명 actor+0x690).** **패치**. Lane **Jarvis-MAGIC**. 액터 섀도 시드 제거; 우회 경로를 통해 352번 이상 ID 처리 `HasCommandBit`. [이전: `v2.171.0.1`]
- **`v2.171.0.1` — Bikanel 사용자 지정 믹스: 카메라 chunk0 `nagi05_24` + 스프레드 파티 행 (Jarvis-ARENA).** **패치**. RT2 사막은 괜찮지만 카메라가 무작위로 움직임 `bika02_01` 단 1개의 에온만 표시되었고, 와이드 폴라 비회전 프레임링이었습니다. 마칼라니아 오픈과 동일한 패턴: 쿼드 기증자의 ATEL chunk0 이식 + 파티 대기열에 따라 배열된 chunk3 스프레드 `nagi05_24`; 스테이지가 계속됩니다 `bika02_01`. F7 → **빌드 + 실행** 필수. [이전: `v2.171.0.0`]
- **`v2.171.0.0` — GridTeach v4: 확장 명령어 RT2 grant (#322–365).** **사소한 문제**. Lane **Jarvis-MAGIC**. `GridTeachHook` 메뉴 바운드 366, 우회 `BuildActorCommandMenu`, 사이드카 18단어 (섀도 ID 352개 이상), 스크립트 `RuntimeTools/SpiraReforgeRt2/set-grid-teach-sidecar.ps1`. Doc `FFX_GRID_TEACH_EXTENDED_BANK_WIDEN_2026-06-23.md`. [이전: `v2.170.0.17`]
- **`v2.170.0.17` — Bikanel 커스텀 믹스: 781D60 bika 토큰 `0x01600001` (Jarvis-ARENA).** **패치**. RT2 로그: `MsBattleEncountExe` ret=-1이지만 `n2` 2를 본 적이 없다 — 전투가 시작되지 않는다; 단지 `781D60` 대열을 짜라. 비카넬 크로스 맵: 배치 `bika02_01` + `781D60(0x01600001)` + 핀 (FGF 아님, 나기 토큰 아님). [이전: `v2.170.0.16`]
- **`v2.170.0.16` — 커스텀 믹스: FGF 지연 + Remiem 컴포즈 수정 (Jarvis-ARENA).** **패치**. Bikanel FGF 즉시 실행은 전투를 시작하지 않았습니다(틱 전에 force-gate가 꺼짐); SetBattleFlags+pin을 사용한 launch deferred. Remiem x3: `kino00_00` (grow OK) 대신 `kino00_70` 다중 영역. [이전: `v2.170.0.15`]
- **`v2.170.0.15` — Spira Reforge: 캐릭터별 RT2 grant 확장 명령어 가이드.** **수정**. Lane **Jarvis-MAGIC**. Doc `mods/Spira Reforge/EXTENDED_COMMANDS_RT2_GRANT_GUIDE.md` — 지도 `#322–365`, 블루 매직 키마리 (메뉴 `#322` + 하위 메뉴 14), GridTeach 사이드카(패키지 단위). [이전: `v2.170.0.14`]
- **`v2.170.0.14` — Custom Mix Bikanel: 네이티브 FGF 출시 (nagi 토큰 아님) (Jarvis-ARENA).** **패치**. 로그로 입증됨 `781D60(0x01AE0017)` 항상 나기 동굴을 위한 대기열을 다시 작성합니다 (`fieldHi=63`); backdrop/pin nagi 해킹이 실패했다. Bikanel: d

eploy `bika02_01.bin` + `MsBattleEncountExe(47/0/1)` + 핀; 동굴은 계속된다 `nagi05_23`+token. [이전: `v2.170.0.13`]
- **`v2.170.0.13` — 스피라 리포지: 키마리 랜셋 듀얼 그랜트 §10.17 (디자인 잠금).** **수정**. 레인 **자비스-MAGIC**. 랜셋 + `RonsoRageId` 몬스터 → OD + 블루 메이지 MP 합산; 훅 TODO. Doc `FFX_KIMAHRI_LANCET_DUAL_GRANT_RESEARCH_2026-06-23.md`. [이전: `v2.170.0.12`]
- **`v2.170.0.12` — Custom Mix Bikanel: 비주얼 배경(Jarvis-ARENA)이 나오기 전의 로스터.** **PATCH**. RT2 로그: 틱과 함께 `field=47` 로드 중에 다시 해결됨 `bika02_01` (Alcyone 등) bin 복합어를 무시함. 현재 크로스맵: pin `nagi05_23` + G/F ~60 프레임 (비주얼 패치 없음); 틱이 발생한 후에만 `field=47 bf=1049` 메쉬 사막으로. [이전: `v2.170.0.11`]
- **`v2.170.0.11` — Spira Reforge: 더블/트리플 드롭 자동 능력 §10.16 + hook 문서.** **수정**. Lane **Jarvis-MAGIC**. 새로운 AA ID 129–130 (아이템 수량 ×2/×3); 후크 `DoubleTripleDropHook` 코딩됨; 절도/강도/뇌물: 미정. [이전: `v2.170.0.10`]
- **`v2.170.0.10` — 스피라 리포지: 오메가 유적 엔드게임 파밍 §15.** **수정**. 레인 **Jarvis-MAGIC**. 장소 = 파밍 난이도 높음; 전리품/길/AP/상자 ↑; 초대형 보스; 고립된 로스터 (공유 대상 제거됨); 첫 번째 보스 → 처치 후 무작위 너프. 스펙 `OMEGA_RUINS_ENDGAME_FARM_SPEC.md`. [이전: `v2.170.0.9`]
- **`v2.170.0.9` — Bikanel 커스텀 믹스: 핀 `nagi05_23` + 시각적 배경 47/1049 (Jarvis-ARENA).** **패치**. RT2 로그로 확인됨 `781D60` 대기열을 다시 작성하여 `fieldHi=63 formation=3` (바닐라 동굴); bf-only는 배경이나 로스터를 변경하지 않습니다. 캐리어의 G/F를 회복시키고, 핀 `g_FFX_Battle_EncounterName`, 시각적 티크 `field=47 bf=1049`. [이전: `v2.170.0.8`]
- **`v2.170.0.8` — Spira Reforge: Sin-skills (SIN 적용 시에만) + 루카 후 OD (§13.2).** **수정**. 레인 **Jarvis-MAGIC**. **오직** SIN 효과가 적용된 상태에서만 발동되는 새로운 몬스터 스킬 (VFX 색상 변경); 루카 이후 오버드라이브 ~1–2/영역, SIN과 **무관**, 대부분 = 새로운 스킬. [이전: `v2.170.0.7`]
- **`v2.170.0.7` — Spira Reforge: §13 — formation vs `m###` (보스 수정됨, 전투 중 추가 몬스터 없음).** **수정**. 레인 **Jarvis-MAGIC**. §13.1 명확화: v0.1에서는 이미 보스의 밸런스를 재조정하여 `m###`/AI; 제13조는 **경기 명단**에만 제한을 둔다 (세이무

r + 4 adds); 5 = **randoms**로 확장. [이전: `v2.170.0.6`]
- **`v2.170.0.6` — Bikanel 커스텀 믹스: BF 전용 사막 + 와이드 카메라 (그래프트 아님) (Jarvis-ARENA).** **패치**.
- **`v2.170.0.5` — Spira Reforge: 전투 범위 — 랜덤 전투 수정, 보스는 SIN 모드에서만 등장.** **수정**. Lane **Jarvis-MAGIC**. §13.1: **무작위 전투**(최대 5명의 적)에 초점을 맞춘 영구 포메이션/빈; **스토리 보스** 빈은 변경 없음; 보스 레이어는 **오직** SIN 토글만 적용 (§5.6). [이전: `v2.170.0.4`]
- **`v2.170.0.4` — Spira Reforge: 적 수가 최대 5명까지 확대된 전투 (디자인 확정).** **수정**. Lane **Jarvis-MAGIC**.
- **`v2.170.0.3` — 커스텀 믹스 비카넬: 에온-와이드 그래프트 카메라 `nagi05_24` (Jarvis-ARENA).** **패치**. 사막 배경 `bika02_01` 배경/파티 앵커를 유지합니다; chunk0 ATEL(배틀 카메라)은 도너 쿼드에서 전송됩니다 `nagi05_24` 출처: `BattleChunk0GraftWriter` — 4마리의 거대한 다크 이온을 상대로는 랜덤 인카운터 카메라를 사용하는 것이 불가능했다. F7 → 배치 후 빌드 + 런치 필수. [이전: `v2.170.0.2`]
- **`v2.170.0.2` — Bikanel 맞춤 믹스: 템플릿 `bika02_01` FGF 47/0/1 (Jarvis-ARENA).** **PATCH**. RT2 배틀 스냅샷 Halyson: 사막 랜덤 = `bika02_01` @ idx **47** bf **1049**, 아니요 `bika03_03` @ 48/0/3 (샌드 웜). 컴포즈 + 메타데이터 정렬됨; 문서 `FFX_ARENA_PLUS_BIKANEL_BIKA02_RT2_2026-06-23.md`. [이전: `v2.170.0.1`]
- **`v2.170.0.1` — 커스텀 믹스: 시나리오 런타임 패치(Jarvis-ARENA)를 비활성화합니다.** **PATCH**. RT2 로그: 틱 `field_idx=36` (마칼라니아 숲) 기본 테이블을 → 키메라로 재설정했습니다. Compose는 이미 시나리오 템플릿을 캐리어의 bin에 저장해 두었으며, launch는 토큰만 대기열에 넣습니다. `781D60`. 패치 `@0xD2C254` 이제 옵트인 (`arena_plus_scenario_backdrop.flag`). [이전: `v2.170.0.0`]
- **`v2.170.0.0` — Field Tier C1: PMeshInstance 맵 + glTF 인스턴스 그룹 + FieldPack 팩토리 (Jarvis-FIELD-RE).** **MINOR**. `ParseInstanceMap()` → `{assetId}.phyre-instance-map.json`; `DescriptorStaticGltfWriter` flag `--instance-group`; PNode parent-chain world compose offline; `RuntimeTools/FieldPackFactory/` (`build-field-pack.ps1`, `mount-work-for-mapviewer.ps1`, `build-fieldpack-chr-subset.ps1`); MapViewer `window.__fieldExplorerReady`; `ffx_addresses.h` 수정 `0x6F6D40` + RVA

 `0x65B0F0`. [이전: `v2.169.0.2`]
- **`v2.169.0.2` — Spira Reforge: B 패키지 스탯 그리드 보상 (인플레이스 패널).** **수정**. Lane **Jarvis-MAGIC**. §12.1.1 고정: STR–LCK 티어에 +1 인상; HP 200→250 / 300→400; MP 기본 스탠다드 = +20/+40 (49+7 노드) → +25 / **+60** (`up_value` 8→12 in `0x24`); 경로 A만 `panel.bin`. [이전: `v2.169.0.1`]
- **`v2.169.0.1` — Bikanel 커스텀 믹스: BF 전용 크로스 맵 + 아레나+ 음악 (Jarvis-ARENA).** **패치**. RT2 로그를 통해 재패치가 `field_idx=48` 로드 중에 해결되었는데 `bika03_03` (샌드웜) 대신 복합 빈 `nagi05_23`. 크로스맵(Bikanel/Remiem)은 이제 패치만 `battlefield_id` (LOWORD @ `0xD2C254`); 캐리어 `field_idx` 변경 없음; chunk0/camera는 이미 compose의 템플릿에 포함되어 있습니다. MusicHook: 45초 대기, Prep/Play/SwitchCrossfade 차단 (필드 트랙 21 제외), 첫 번째 호출 시 리소스 소모 없음 — 오버라이드 145 후 바닐라 138 방지. [이전: `v2.169.0.0`]
- **`v2.169.0.0` — Field Explorer CHR 모델 + PNode 오프라인 디코딩 (Jarvis-FIELD-RE).** **사소한**. MapViewer가 glTF 베이킹된 파일을 시도합니다 (`/work/*_anim`) CHR 핀; 더 큰 핀 + 라벨; PhyreMapExportLab은 다음을 출력합니다 `phyre-scene-graph-report.json` + 깃발 `--node-per-object`. [이전: `v2.168.0.0`]
- **`v2.168.0.0` — Field Explorer: 씬 노드 + 상점/오두막 프록시 (Jarvis-FIELD-RE).** **사소한 문제**. WalkManifest가 읽음 `sceneNodesPlaced`; MapViewer 오버레이가 Phyre 레이어와 소품용 3D 프록시를 렌더링합니다 `f###`; Field Scout가 후크를 다시 활성화합니다 `ComposeWorldMatrix`/`SetupSceneNode` 전투 중 스킵. [이전: `v2.167.0.6`]
- **`v2.167.0.6` — 커스텀 믹스: 스프레드(Jarvis-ARENA)에 Magus (+3)를 적용한 픽스 컴포즈.** **패치**. `AssignSpreadPositions` 픽 수(3)를 사용했을 때 5명의 배우로 구성된 그리드와 충돌 → 크래시 `role grid mismatch` (exit 3762504530). 이제 스프레드에서 Magus를 3슬롯 확장합니다. [이전: `v2.167.0.5`]
- **`v2.167.0.5` — Bikanel/Remiem 커스텀 믹스: 크로스 맵 배경 + 캐리어 핀 (Jarvis-ARENA).** **패치**. 토큰 `nagi05_23` compose를 사용해도 field 63(Cavern)을 강제로 설정했다 `bika03_03`. 크로스맵 최신 패치 `field+bf` 배경 + 핀 `g_FFX_Battle_EncounterName` 복합 캐리어 내 (손상되지 않은 다크 이온). [이전: `v2.167.0.4`]
- **`v2.167.0.4` — F7 Arena+: Enter 키 데바운스 (메뉴 + com

포즈) (Jarvis-ARENA).** **패치**. 서브 메뉴/전투 시작 시 쿨타임 (허브 10f, 컴포지션 24f); Aeon 토글 속도 향상 (7f); 런치/재런치 속도 감소 (28f). Edge-latch 기능으로 Enter 키를 길게 누를 때 잘못된 줄로 이동하는 현상 방지. [이전: `v2.167.0.3`]
- **`v2.167.0.3` — Spira Reforge: 그리드 와이어 — 스탯만 재할당 (기본 스킬은 그대로 유지).** Lane **Jarvis-MAGIC**. **REVISION**. Halyson: ~44개의 스탯이 스킬 교육으로 전환됨 `#322–365`; 바닐라 스킬 노드는 **건드리지** 않습니다; 범프 기능으로 보정합니다 `IncreaseAmount` 나머지 통계(미정). Doc `VISION_AND_ROADMAP.md` §12.1. [이전: `v2.167.0.2`]
- **`v2.167.0.2` — Custom Mix x4 Bikanel: fix Sand Worm vanilla hijack (Jarvis-ARENA).** **패치**. 런타임 패치 `field_idx=48` 다시 해결했다 `bika03_03` (샌드웜)이 토큰 위에 `nagi05_23`. 크로스 맵 (Bikanel/Remiem) → bin compose 내 장면 (`bika03_03` chunk0); field=63일 때만 FGF 패치 (Cavern). [이전: `v2.167.0.1`]
- **`v2.167.0.1` — 커스텀 믹스 x4/x5: 배경 Bikanel/Cavern/Remiem + 카메라 aeon-wide (Jarvis-ARENA).** **패치**. `ScenarioBattlefieldIdForKey` Macalania만 있었는데 → Mix x4 Bikanel이 바닐라에 떨어졌다 `bika03_03` (사막 속의 기계). 현재 bf=1049/1080/1035 + 시각적 패치만 적용됨; lab x4/x5는 캐리어의 와이드 카메라를 사용함 (`nagi05_24`/`_50`) 다크 이온스에게 더 큰 스프레드가 적용된 경기. [이전: `v2.167.0.0`]
- **`v2.167.0.0` — Monster AI Editor: ATEL scaleOwnSize (Jarvis-MAGIC) 스케일링.** **MINOR**. YUNALESCA 카드 적용 `scaleOwnSize` (0x7028) DeathAnimation 후 삽입을 통해 또는 기존 플로트 풀을 복제; 지름길 +10%/+80%; 스크립트의 현재 균일 스케일을 읽음. [이전: `v2.166.0.16`]
- **`v2.166.0.16` — 커스텀 믹스 x4/x5: 빈 시나리오 행 제거 (Jarvis-ARENA).** **패치**. 메뉴에는 4개의 고정 슬롯이 할당되어 있었으며, 시나리오가 3개인 티어의 경우 보스 전까지 빈 바가 표시되었습니다. 동적 레이아웃은 `g_scenarioCount`. [이전: `v2.166.0.15`]
- **`v2.166.0.14` — Custom Mix Forest: 포스트-토큰 배경 패치 (Jarvis-ARENA).** **PATCH**. `781D60` 짊어지고 있었다 `mcyt00_22` 그리고 FGF 36/mcfr을 무시했고; DLL 재패치 `dword_112C254` + 시나리오가 기본값이 아닐 때 토큰 앞/뒤에 표시되는 전투 이름. [이전: `v2.166.0.13`]
- **`v2.166.0.13` — 필드 스카우트: pr

ep/finish walk 원샷 + 자동 인제스트 (Jarvis-FIELD-RE).** **패치**. `prepare-field-scout-walk.ps1` (ULTRA 빌드, 격리 플래그, NativeMenu 비활성화) + `finish-field-scout-walk.ps1`; 편집기 ‘게시’를 클릭하면 새 세션이 자동으로 시작됩니다. [이전: `v2.166.0.12`]
- **`v2.166.0.12` — Macalania Forest 커스텀 믹스: mcfr00 + tableIndex FGF (Jarvis-ARENA).** **PATCH**. RT2 Live Battle Lab: Forest = `36/0/0` + `mcfr00_00` (nao mcyt/id 340); Open = idx 42. [이전: `v2.166.0.11`]
- **`v2.166.0.11` — 배틀 트래커: BTL 스냅샷 + 반응형 레이아웃 (Jarvis-MAGIC).** **패치**. “전투 스냅샷” 카드 (전장, 그룹, 진형, 전선, 경로 커서 등 — Live Battle Lab과 동일한 디코딩) + 4열 그리드 대신 아군/적군 탭. Chr 편집기는 변경 없음. [이전: `v2.166.0.10`]
- **`v2.166.0.10` — 주입된 DLL: 녹색/빨간색 네온 표시 토글 기능 복원 (Jarvis-MAGIC).** **패치**. 알약의 “켜기”/“끄기” 표시가 다시 녹색으로 돌아옴 `#00E87A` 그리고 빨간색 `#FF2A4D` 강렬한 광택; 폴백이 더 이상 칙칙한 회색으로 변하지 않습니다. [이전: `v2.166.0.9`]
- **`v2.166.0.9` — Battle Tracker: 레이아웃 오류 + 목록 대비 (Jarvis-MAGIC).** **패치**. 중첩 그리드 `*,*`/`2*,3*` 세부 정보 패널을 접음(중앙이 비어 있음); 4개의 고정 열로 되돌림 `150,*,300,*` ~와 함께 `MinWidth` ScrollViewer에서. 그룹에 속하지 않은 요소들은 `TextMutedBrush` ~ 대신 `DarkRed`. 장전 시 첫 번째 아군/적을 자동으로 선택합니다. [이전: `v2.166.0.8`]
- **`v2.166.0.8` — F7 메뉴: 애니메이션 네온 바 제거 + 유리 투명도 증가 (Jarvis-ARENA).** **패치**. 아케이드 외부 프레임 및 스윕 효과 제거; 부드러운 테두리가 있는 정적 유리 패널. [이전: `v2.166.0.7`]
- **`v2.166.0.7` — F7 메뉴: 유리 패널 + EN 문자열 + 밝은 배경 (Jarvis-ARENA).** **PATCH**. 네온 테두리가 있는 투명한 헤더/푸터; 허브 텍스트는 영어로 표시 (i18n은 추후 처리). [이전: `v2.166.0.6`]
- **`v2.166.0.6` — F7 메뉴: 반응형 레이아웃 Menu2D (Jarvis-ARENA).** **패치**. `MenuPhysW/H` + 분수 `NX/NY/NW/NH`; 버퍼의 물리적 좌표에 맞춰 균일한 두께로 된 네온 그린 테두리 (`MenuBorderPx`); 1080p/2K/720p를 하드코딩하지 않도록 합니다. [이전: `v2.166.0.5`]
- **`v2.166.0.5` — F7 메뉴: 네온 그린 테두리 + s 정렬

비대칭 (Jarvis-ARENA).** **PATCH**. 금색을 네온 그린으로 변경 (`#50FF90`); 디자인 스페이스 내 대칭 마진; Arena+/Custom Mix 하위 메뉴의 녹색 선택선. [이전: `v2.166.0.4`]
- **`v2.166.0.4` — 커스텀 믹스 x3: 마칼라니아 시나리오 4개 + 피커의 런치 루트 (Jarvis-ARENA).** **패치**. 피커에 Forest/Open/Open2/Remiem; 런치에 루트 적용. [이전: `v2.166.0.3`]
- **`v2.166.0.3` — F7 메뉴: 스피라 지도 복원 (스크림 + 중간 투명도) (Jarvis-ARENA).** **패치**. 어두운 스크림 + `worldmap` atlas 11948 + `ffx_bg` 은은함 + 비네팅; v2.166.0.1의 HDR 오버플로우를 방지합니다. [이전: `v2.166.0.2`]
- **`v2.166.0.2` — 커스텀 믹스: 수정된 마칼라니아 시나리오 + 매니페스트의 런치 경로 (Jarvis-ARENA).** **패치**. Forest = `mcyt00_01`; Open = `mcyt00_21`; 노를 저어라 = `kino00_70` + 필드 220. [이전: `v2.166.0.1`]
- **`v2.166.0.1` — F7 메뉴: 오버레이 월드맵 전체 화면 제거 (오버플로우/흰색 화면 수정) (Jarvis-ARENA).** **패치**. 게임 화면이 깔끔하게 표시되며, 그리드/필드 위에 흰색 사각형이 나타나지 않습니다. [이전: `v2.166.0.0`]
- **`v2.166.0.0` — 커스텀 믹스: 시나리오 선택기 (믹스 전용; 고정 프리셋) (Jarvis-ARENA).** **MINOR**. F7 선택기에서 티어당 3개의 시나리오; lab `--scenario`; manifest `scenario_key`. Gauntlet/Dark Rematch는 변경 없음. [이전: `v2.165.0.1`]
- **`v2.165.0.1` — F7 메뉴: 파란색 워시 제거; 배경 = 깨끗한 스피라 지도 (Jarvis-ARENA).** **패치**. 제거 `ffx_bg` + 파란색 비네트 + 단색 오버레이; 투명도가 높은 worldmap atlas 11948. [이전: `v2.165.0.0`]
- **`v2.165.0.0` — Arena+ Gil 경제: Dark Aeon당 비용 + 프리셋/믹스 합계 (Jarvis-ARENA).** **사소한**. 플래그 `arena_plus_charge_gil.flag`; 도스시에 표 §13.1 (Valefor/Ifrit 100k … Penance 500k); 프리셋 = 보스 합계; 커스텀 믹스 = 픽 합계 (Magus 300k); Gil이 부족하면 차단; 배치 시 깃발 포함. [이전: `v2.164.0.5`]
- **`v2.164.0.5` — 스피라 리포지: 다크 이온(요짐보 제외)의 AP를 높이는 아이디어. **레인** 자비스-MAGIC. **수정**. Halyson: 아레나+ 랭크전에서 다크 이온 승리 시 AP를 **매우** 크게 증가시킴; **다크 요짐보는** 이 적용 대상에서 제외. 문서: `VISION_AND_ROADMAP.md` §5.2.1, `FFX_SPIRA_REFORGE_DARK_AEON_REBALANCE_RESEARCH_2026-06-15.md`. 숫자는 추후 확정 예정; 작성자 `m###

.bin` loot AP. [anterior: `v2.164.0.4`]
- **`v2.164.0.4` — Arena+ 조합 x4/x5: 기증자 프리셋 와이드 + 윙 정렬 (Jarvis-ARENA).** **PATCH**. x4 기증자 `nagi05_24`; 기증자 5명 `nagi05_50`; 중앙에서 가장 큼; 문서 스캔 [이전: `v2.164.0.3`]
- **`v2.164.0.3` — Arena+ compose x4: 스프레드를 더 뒤쪽으로 조정 (Jarvis-ARENA).** **패치**. 그리드 Z +18; Valefor의 양쪽 끝 폭을 줄임. [이전: `v2.164.0.2`]
- **`v2.164.0.2` — Arena+ 허브: 장엄한 자막 + 작은 글꼴 (Jarvis-ARENA).** **패치**. 제목은 그대로 유지; 설명 `DrawStringSub` 별도. [이전: `v2.164.0.1`]
- **`v2.164.0.1` — Arena+ 메뉴: 확인 버튼에서만 이중 클릭 방지 (Jarvis-ARENA).** **패치**. 기본 재사용 대기시간 12→3 프레임; Dark Aeon 하위 메뉴를 열면 UP/DOWN 키로 즉시 이동. [이전: `v2.164.0.0`]
- **`v2.164.0.0` — Arena+ F7 하위 메뉴 + 카메라/chunk0 바이블 (Jarvis-ARENA).** **사소한 변경**. 허브: **Dark Aeon Rematch** / **Aeon Gauntlet** / **Custom Mix**; 문서 [`FFX_ARENA_PLUS_COMPOSE_CAMERA_CHUNK0_TEMPLATE_2026-06-23.md`](docs/reverse/FFX_ARENA_PLUS_COMPOSE_CAMERA_CHUNK0_TEMPLATE_2026-06-23.md) (chunk0 제공자 `mcyt00_21`, 슬롯 스왑, OD 바 ≠ HP 버그, 오로라 재사용). DLL `ArenaPlusMenuKind`. [이전: `v2.163.0.4`]
- **`v2.163.0.4` — Field Explorer: UI에서 Scout 게시 (Jarvis-FIELD-RE).** **PATCH**. Scout 게시 / 마커 업데이트 / 게시 + 필드 열기 버튼; 프로세스 내 새로고침 (두 번째 편집기 생성 없이); PS1 `-SkipOverlayRefresh` UI에서 호출될 때. [이전: `v2.163.0.3`]
- **`v2.163.0.3` — Arena+ 구성: 파티에 스프레드 방향 지정 (캐릭터 뒤쪽 카메라) (Jarvis-ARENA).** **패치**. `BattleComposeRunner`: 기본 캐리어 파티의 Z 중심점을 설정하고, 에온을 반대편에 배치합니다 (`mcyt00_22` 파티 Z≈+2 → 몬스터 Z 음수); 실험실 + 스팀 재구성됨. 음악은 그대로. [이전: `v2.163.0.2`]
- **`v2.163.0.2` — Arena+ 구성: Dark Anima/Yojimbo 슬롯 ID 교체 + Steam 재배포 (Jarvis-ARENA).** **패치**. `BattleComposeRunner`: `0x1153`=힘내, `0x1154`=요짐보 (다음과 일치) `battle-model-catalog.json` / RE 자료집); 스프레드 3배 확대; 연구실 재게시 + `mcyt00_22.bin` 재구성된 (`ixion,shiva,yojimbo` → 슬롯 `0x1150,0x1151,0x1154`). 음악은 **변경되지 않음**. [이전: `v2.163.0.1`]
- **`v2.

163.0.1` — Field Explorer P0: CHR honest overlay + dedupe (Jarvis-FIELD-RE).** **PATCH**. `EncounterOverlayCompiler` + `ChrClassifier`: dedupe por ator (n/c/m/f), `field-encounters.json` v2 (`entities[]`, `chrCounts`, `신선함`), MapViewer layer toggles + labels honestos, publish C1 (`break`→`계속`) + `Resolve-FieldKey` com limite de proximidade, `chr_spawn` com `영역/분야` no hook, ingest `등록 필드` para chr. RT2 Field Actor ainda pendente. [anterior: `v2.163.0.0`]
- **`v2.163.0.0` — SGM 861 F1 인라인 스토어 리디렉션 훅 v1.75 (Jarvis-MAGIC-SGM).** **사소한 변경**. `SphereGridFullGridCompilerHook v1.75`: 내부의 5바이트 스텁 패치 `7F4900` @ `0x3F4C0F` (NEG 작가 준비), `0x3F5208` (NEG pos store), `0x3F57E6` (POS pos store); flag `sg_f1_inline.flag` SKIP860을 리프트하고 vanilla draw860을 허용하며 `STORE-INLINE` remap stale 41252→41328. RE: `docs/reverse/FFX_SPHEREGRID_861_F1_INLINE_STORE_2026-06-23.md`, `work/reverse/ida/f1_inline_patch_sites_2026-06-23.json`, F2 체인 `docs/reverse/FFX_SPHEREGRID_861_F2_ANIM_CAPTURE_STORE_RE_2026-06-23.md`. 게임 내 DLL + RT2 빌드 **테스트 필요**. [이전: `v2.162.9.4`]
- **`v2.162.9.4` — Arena+ 구성: 전체 배포 실험실 + Enter 키 반동 방지 (Jarvis-ARENA).** **PATCH**. 종료 `2147516570` = `ArenaMultiBossLab.dll` 없음 — deploy는 이제 전체 폴더를 다음 위치로 복사합니다. `modules\tools\ArenaMultiBossLab\`. 피커: Confirm 시 상승 에지 + 토글 후 20f 쿨타임 (Enter 키를 누르면 선택 해제되는 문제 수정). [이전: `v2.162.9.3`]
- **`v2.162.9.2` — Spira Reforge: handoff RT2 테스트 하네스 (그리드 진입 전 스킬 부여).** Lane **Jarvis-MAGIC**. **REVISION**. 문서 `docs/ai/PROMPT_SPIRA_REFORGE_COMMAND_RT2_TEST_HARNESS_2026-06-18.md` — 병렬 채팅에 연결: 최소 배포 `command.bin`, `GridTeach` + 사이드카 `grid_teach_learned.bin`, grant via `ffxprobectl call 385D10`, 팩당 연기량 (적하 목록), 테스트 종료 시 **기본값으로 복원** 체크리스트. [이전: `v2.162.9.1`]
- **`v2.162.9.1` — 스피라 리포지: 디자인 잠금 — 오버드라이브→AP 획득 + 티어 T 보상.** 레인 **자비스-MAGIC**. **수정**. Halyson: 오버드라이브→AP 제거 (AP 파밍이 귀찮음); 대체 항목 미정. SIN 모드: **T** 티어 몬스터도 기본 능력치 ↑ 및 추가 드롭 획득 (수치 미기재)

(이 문서). 문서: `FFX_SPIRA_REFORGE_VANILLA_OFFENSIVE_REBALANCE_2026-06-16.md`, `SIN_DIFFICULTY_MODE_SPEC.md` §3.4. [이전: `v2.162.9.0`]
- **`v2.162.9.0` — 수정: MonsterAiEditor 버그 `{StaticResource Spacing*}` + 네온 액센트 색상 복원 (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH**. Halyson이 보고한 두 가지 문제: (1) **버그:** `MonsterAiEditor_Control.axaml` 4건의 사례가 있었습니다 `Padding="{StaticResource SpacingLg/Md}"` 부팅 시 해결되지 않았던 문제들 (핫픽스와 동일한 클래스) `v2.159.6.1` — 토큰 `Spacing*` ~에 살고 있다 `Application.Resources` ~ 이후 `StyleInclude`, 그러니 `StaticResource` 오류; F3 스윕이 사용되었습니다 `{DynamicResource}` 하지만 이 4줄은 수동 파일럿의 `v2.159.6.0` (도망친 자들). 다음으로 변경됨 `{DynamicResource Spacing*}` — 버그를 수정합니다. (2) **“네온 빛이 없는, 보기 흉한” 색상:** o `v2.159.6.0` 15을 정상화했다 `Accent*FillBrush` (Shell/Protect/Regen/Gold/Cycle/Forbidden/Crimson/Undo/Refresh/Move/Haste/Reflect/NulAll/Builder/Reaction)을 매우 어두운 색조로 (`#21506A`/`#1E5E45`/etc.)로 변경하여 네온 테두리의 선명함을 흐리게 했습니다. **더 채도가 높고 선명한** 색조로 복원되었습니다(예: Shell `#21506A`→`#1A6E8C`, Protect `#1E5E45`→`#1E8050`, 골드 `#4A4226`→`#6E5E2A`, 사이클 `#3D4F78`→`#3A5BB0`) — 어두운 필과 네온 테두리 사이의 중간 톤으로, 완전한 네온 색상으로 변하지 않으면서도 존재감을 드러냅니다. 네온 테두리/전경 (`#66D8F0`/`#6FE3B7`/`#AAB4FF`/etc.) **변경되지 않은 상태** (이미 멋졌으니까). 다음을 사용하는 모든 모듈에 영향을 미칩니다. `Accent*` (MonsterAi가 가장 큽니다). 범위: 시각적 컨테이너만 — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음. 릴리스 빌드 **오류 0개** (기존 경고 403개). [이전: `v2.162.8.0`]
- **`v2.162.8.0` — 수정: SGM 861 OOB 슬롯 860 후크 v1.30 (Jarvis-MAGIC-SGM).** **패치**. `SphereGridFullGridCompilerHook v1.30`: 부트 범프 `942B60` 41252→41328, SKIP 확장 (-861/-862), F858 패치(작성자만 +0/+4), ALLOC-TRACE, 프로듀서 감시, 버퍼 861이 준비되면 draw860 재활성화. RE: `docs/reverse/FFX_SPHEREGRID_861_PRODUCER_RE_2026-06-20.md`. DLL 빌드 성공; RT2 게임 내 **테스트 필요**. [이전: `v2.162.7.0`]
- **`v2.162.6.0` — 수정: 명령 팔레트 `Ctrl+K` + 좁은 서랍 `Ctrl+B` (팝업 `IsOpen`, tunnel KeyDown) (Jarvis-UI).** Lane **Ja

rvis-UI**. **PATCH** (D 단계부터 수정하겠다고 약속했으나 오버레이가 전혀 열리지 않던 바로 가기 문제를 수정함). Avalonia 11 `Popup` 필수 **`IsOpen`** — 해당 코드는 `IsVisible` (no-op). **tunnel** 핸들러로 이전된 바로가기 (`KeyDownEvent`) TextBox 및 하위 편집기에 중점을 두고 작동하도록 하기 위해. `PlacementTarget` + `Topmost` 팝업 창에서. 빌드 릴리스 **오류 0개**. [이전: `v2.162.5.0`]
- **`v2.162.5.0` — i18n: 마이그레이션 `ModuleRegistry` (41개 모듈 × 5개 필드) + 대시보드 문자열 + §16–§17 완료 (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH** (F4 i18n 기반 재사용; 새로운 제품 기능 없음). 프롬프트 후 `PROMPT_GLM_PHASE_E_HARD_AND_F`: **205개 키** `Mod_{id}_{Title|Description|Mode|Notes|Scope}` 에서 `Strings.resx` + `Strings.pt.resx` (발전기 `work/_gen_module_i18n_20260622.ps1`); `Strings.Get`/`Strings.Module` 동적 조회; `ModuleCatalogEntry.Localized*` (대시보드, 팔레트, 레일 툴팁, 배너 출처: `SetModule` 오버레이는 언제 `_currentModuleId` 레지스트리를 수정합니다). **+11개 키** 대시보드 (히어로 로드됨/비어 있음, 레이블: Workspace/Modules/Hook). `MainDashboard_Control` 빈다 `LocalizedTitle/Description/Mode` + `{x:Static res:Strings.*}`. `docs/specs/EDITOR_UI_OVERHAUL_PLAN.md` §16–§17에 **DONE** 표시 (`v2.160.0.0`). `PORT_STATUS.md` 조정된 (`v2.162.4.0`→`v2.162.5.0`). **정직성:** 레지스트리가 이미 포르투갈어(PT)였던 경우 포르투갈어 설명은 그대로 유지; 위성에서 번역된 영어(EN) 제목; 68개의 내부 문자열 `SetModule` 리터럴이 백로그로 남아 있습니다. Smoke RT1 + Halyson 병합 대기 중. 컨테이너 전용 범위. 빌드 릴리스 **오류 0개**. [이전: `v2.162.4.0`]
- **`v2.162.4.0` — F 단계 §F4: i18n foundation (`.resx`) (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH** (foundation; 기본적으로 눈에 띄는 동작 변경 없음 — 기본 로케일은 계속 en임). **F 단계**의 네 번째이자 마지막 커밋 (`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F4). 적용 범위: **컨테이너 비주얼 전용** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음. 국제화 인프라를 구축합니다: **이 커밋 이전에는 리포지토리에 0이 있었습니다** `.resx`**; 곳곳에 하드코딩된 문자열. **작성일:** `Resources/Strings.resx` (중립 = en, ~17개의 하중 지지 키: 영웅 칭호, 레일 라벨, 팔레트 자리 표시자

(이전, 동작 레이블, 모드 알약) + `Resources/Strings.pt.resx` (PT-BR 위성) + `Resources/Strings.cs` (정적 액세서리 via `ResourceManager`, 키당 정적 속성 1개 — XAML에서 다음과 같이 바인딩 가능 `{x:Static res:Strings.Xxx}`) + `Strings.ApplyUiCulture()` (읽기 `FFX_UI_LANG=pt|en`; 기본값 = neutral/en; 화살표 `DefaultThreadCurrentUICulture` (XAML 바인딩보다 먼저). **배선:** `App.axaml.cs Initialize()` 불꽃 `Strings.ApplyUiCulture()` ~보다 앞서 `AvaloniaXamlLoader.Load`. 그 `.resx` 는 `EmbeddedResource` glob SDK에 내재된 (`Resources/**/*.resx`) — 위성이 확인된 바에 따르면 `pt\FFXProjectEditor.resources.dll` 이 출력됩니다. **2점 하중 지지 방식의 바인딩 시연:** MainDashboard CTA "작업 공간 폴더 열기" (`{x:Static res:Strings.DashboardCtaOpenWorkspace}` + a11y 이름) + 명령 팔레트 자리 표시자 (`Watermark="{x:Static res:Strings.RailSearchPlaceholder}"`). **솔직히 말해서:** 완전한 i18n은 끝이 없는 작업입니다 (문서 §4.F4). 이 커밋은 기반을 마련하고 패턴을 보여줍니다. 약 50개의 ModuleRegistry Title/Description과 수백 개의 내부 문자열 마이그레이션은 향후 백로그로 남깁니다(2개의 resx 파일에 키 추가 + Strings.cs에 속성 추가 + 리터럴을 `{x:Static}`). 오늘 포르투갈어를 모국어로 하지 않는 사용자는 확인되지 않았으므로, `FFX_UI_LANG` UI에 표시되지 않음 (환경 변수 전용). 핸들러/바인딩/라이터/저장 바이트/훅은 변경되지 않음. 릴리스 빌드 **오류 0개** (기존 경고 403개). **F 단계 전체 완료** (F1-F4). [이전: `v2.162.3.0`]
- **`v2.162.3.0` — F 단계 §F3: 토큰 스윕 — 균일 패딩 → `Spacing*` (67개 파일 내 518개 리터럴); CornerRadius **토큰화되지 않음** (정직함) (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH** (design-system의 마무리 작업; 새로운 기능 없음). **Fase F**의 세 번째 커밋 (`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F3 — "높은 이탈률, 낮은 증분 가치"). 적용 범위: **비주얼 컨테이너만** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음. **패딩 스윕:** 518개의 리터럴 `Padding="N"` (N ∈ {4, 8, 12, 16, 20}) 유니폼이 다음으로 이전됨 `{DynamicResource SpacingXs/Sm/Md/Lg/Xl}` **67개의 파일**에 `.axaml`**에서 `Modules/` 보수적인 스크립트를 통해 (`work/_padding_sweep_20260622.ps1`)

` — só substitui valores que batem **exato** com um token; deixou intactos os ~340 Paddings assimétricos/não-token como `Padding="10,6"`/`Padding="14"`). `MonsterAiEditor2_Control.axaml` **não** migrado (discontinued). **CornerRadius sweep (§F3b) = NO-OP honesto:** os valores `CornerRadius` ativos nos módulos são majoritariamente 5/6/7/14 — **nenhum** bate com os tokens `RadiusSm=8`/`Md=10`/`Lg=12`/`Pill=999`. Forçar o valor mais próximo seria **mudança visual**, não tokenização. O doc citava "158 CornerRadius" mas esse count incluía `MonsterAiEditor2_Control.axaml` (discontinued, ~34 ocorrências de 8/10). Decisão documentada: deixar CornerRadius literal onde não há match exato. Pós-commit: 518 `Padding="{DynamicResource Spacing*}"` em 67 arquivos; 0 `Padding="16"` restantes. Handlers/bindings/writers intocados. Build Release **0 erros** (403 warnings preexistentes). [anterior: `v2.162.2.0`]
- **`v2.162.2.0` — F 단계 §F2: `AutomationProperties.Name` 전체적으로 약 98개의 동작 버튼(a11y) (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH** (접근성 개선; 새로운 기능 없음). **Fase F**의 두 번째 커밋 (`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F2). 적용 범위: **컨테이너 시각 요소만** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음. 액션 버튼 접근성: 이 커밋 이전에는 F2 모듈에 약 8개의 버튼만 있었음 `AutomationProperties.Name` (스크린 리더가 아이콘만 있는 버튼을 읽어주지 못했습니다). **98개의 버튼 추가**: **스크립트를 통해 87개** `work/_a11y_name_sweep_20260622.ps1` (버튼에 표시된 텍스트에서 이름을 추출하며, UTF-8로 읽습니다. 비-ASCII 텍스트나 ◀/▶/…와 같은 아이콘 글리프)를 건너뛰어) 12개의 Core Authoring + SaveEditorHub + (Customization/Shop/MixTable/KernelCommands)에서, + KernelCommands 내 **4개**의 명시적 항목 (◀/▶ "Previous/Next FSB sample", "Import fsbankcl", "Import custom WAV"), + **MainDashboard 내 2개** (Open Workspace + QuickTile `{Binding Title}` — 아이콘 전용, 접근성(a11y) 우선순위 높음), + **Main_Window에서 5개** (음악/설정/작업 공간 경로/뒤로/앞으로 레일 아이콘). 커밋 후: **164건**의 `AutomationProperties.Name` 18개의 파일 중 `Modules/` (이전 F2 범위에서는 ~8). 핸드

lers/bindings/writers는 변경되지 않았습니다. 릴리스 빌드 **오류 0개** (기존 경고 403개). [이전: `v2.162.1.0`]
- **`v2.162.1.0` — F 단계 §F1: 유틸리티 아이콘 (13개 신규) + 스윕 이모지 (8개 파일) `.axaml`) (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH** (시각적 개선: 아이콘; 새로운 기능 없음). **Fase F**의 첫 번째 커밋 (`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F1). 적용 범위: **컨테이너 비주얼 전용** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음. **13개의 새로운 유틸리티 아이콘**이 `Styles/StudioIcons.axaml` (`IconSearch`/`IconAdd`/`IconRemove`/`IconWarning`/`IconUndo`/`IconRedo`/`IconFilter`/`IconOpen`/`IconClose`/`IconChevronDown`/`IconChevronRight`/`IconCheck`/`IconX` — Lucide-like, 뷰박스 24×24, `<StreamGeometry>`). 8개 파일 내의 **스윕 이모지** `.axaml` 목록에 포함된 항목: 🏐/💾/🌅/🗺️ 제목에서 삭제됨 `sectionLabel`/`cardTitle` 및 저장 버튼. 저장 버튼 (`💾 Salvar`) 우승했다 `<PathIcon Data="{DynamicResource IconSave}"/>` + 텍스트 (MonsterAiEditor ×2, EncounterTableExplorer ×1, AuroraChamber ×3). 이모티콘이 포함된 제목 (`🌅`/`🗺️`/`🏐`)에서 이모지가 제거되었습니다(TextBlock 내의 PathIcon 인라인을 정리하는 기능). `SphereGridCanvas_Control.axaml` 이미 깨끗했음 (이모티콘 삭제됨) `v2.159.5.0` OPT-A6). **8개 외 보너스:** 2개 타이틀 `SetModule` user-visible (`"Save Editor 💾"`, `"Sphere Grid 🧩"` 에서 `Main_Window.axaml.cs`) 또한 헤더의 시각적 일관성을 위해 정리되었습니다. 이모지는 `.cs` (댓글 + 상태 문자열) **변경 없음** (범위 외). 릴리스 빌드 **오류 0개** (기존 경고 403개). [이전: `v2.162.0.0`]
- **`v2.162.0.0` — 단계 완료: `ModuleMasterDetail_Shell` 12개의 모든 Core Authoring 모듈(E1-E12) (Jarvis-UI).** Lane **Jarvis-UI**. **MINOR** (단계 종료 마일스톤 — 5개의 PATCH 통합) `v2.161.1.0`→`v2.161.5.0`). **E 단계 전체**의 `docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` (§2 표준 규범 + §3 E9-E12 + §4) 완료됨: **12개의 Core Authoring 모듈**이 수작업으로 개발된 버전에서 마이그레이션됨 `Auto,*` / `2*,5*` / `3*,6*,3*` 그리드 (보더 카드) `Padding=16` (인치 + ScrollViewer) 표준 쉘 (`ModuleMasterDetail_Shell` 접이식 익스팬더가 장착된, `Padding=8`, 조밀함)

. 모듈: **E1 CtbBase, E2 PlayerGrowth, E3 Formation, E4 Treasure, E5 KeyItem, E6 AutoAbility, E7 BukiGetTreasureCatalog, E8 MonEditorSelector** (`v2.161.1.0`) + **E9 CustomizationEditor** (Gear/Aeon 셸 2개를 갖춘 TabControl, `v2.161.2.0`) + **E10 ShopExplorer** (3열 캐스케이딩, 16진수→토큰, `v2.161.3.0`) + **E11 MixTableEditor** (112×112 행렬, `v2.161.4.0`) + **E12 KernelCommands** (이 저장소에서 가장 상세한 파일로, 977줄, 16진수→토큰, `v2.161.5.0`). **하드 아키텍처 결정 사항 (E9-E12):** 커스터마이징에서 외부 TabControl 유지 (2개의 셸); Shop의 MasterHeader에서 소스 선택기가 ComboBox로 변경됨; MixTable의 Detail 내부에서 파트너 축이 Expander로 변경됨; 쉘 상단에 세션 바 유지 + KernelCommands의 Detail 내부에서 "Where Used"가 Expander로 변경됨. 각 모듈은 다음과 같은 기능을 갖추게 되었습니다. `rsp:Responsive.Breakpoints="True"` + 스타일 `UserControl.narrow` 마스터를 다음 위치에서 중단시키는 `<760px`. DataContext/바인딩/핸들러/변환기/`AutoSaveIndicator_Control`/`AtlasEvidenceBadgeStrip`/`IRestorableModule`/`x:Name`모두 변경되지 않음. Writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 손대지 않음. 릴리스 빌드 **오류 0개** (기존 경고 403개 — Jarvis-UI 기준). 다음: **F 단계** (F1 아이콘+이모지, F2 접근성, F3 토큰 점검, F4 국제화). [이전: `v2.161.5.0`]
- **`v2.161.5.0` — E 단계 §E12: `KernelCommands` → `ModuleMasterDetail_Shell` (리포지토리 상세 정보, 3-col + 세션 바 + 16진수) (Jarvis-UI).** Lane **Jarvis-UI**. **패치** (표면적인 개선: 레이아웃 마이그레이션; 새로운 기능 없음). **E 단계**의 마지막 커밋 (`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E12 — 해당 계획에서 **가장 높은 위험**을 가진 항목). 범위: **컨테이너 시각적 요소만** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음; DataContext/bindings/handlers/converters/IRestorableModule은 변경되지 않음. O `KernelCommands_Control.axaml` (977 → ~970줄) 3열 레이아웃으로 전환 (`3*,6*,3*` 명령어 목록 | 편집기 세부 정보 | "사용 위치") + 표준 프로 쉘 세션 바. **아키텍처적 결정:** outer `RowDefinitions="Auto,*"` 유지됨 — **TOP SESSION BAR**는 셸의 **위쪽**에 위치합니다(0행, 변경 없음); 1행의 셸은 `MasterList` = command ListBox (era Col0, `DisplayedCommands`/`선택

tedCommand` + `FilterText` + botões Clonar/Apagar/Adicionar), `상세 정보` = editor (era Col1, ~840 linhas de campos densos preservados byte-a-byte: Identity/Animations/Battle SFX 3 tiers/Menu/Characters/Costs/Attack Data/Element/Properties/Status/Status Special/Extra); a **3ª coluna "Where Used"** (era Col2) vira um **Expander colapsável dentro do Detail** (default colapsado, label "Where Used — monster links"). `x:Name`s preservados (`ThisControl`, `CommandList`, `MonsterLinksList`) — o code-behind referencia `MonsterLinksList.SelectedItem` em `OpenReferenceMonster`. `AutoSaveIndicator_Control` e os 3 converters (`캐릭터`/`DamageFormula`/`HitCalcType`) preservados. **Hex → tokens no mesmo commit:** `#FF6B6B` (LoadError foreground) → `DangerBrush`; `#1A2A3A` (Spira Ward note bg) → `PanelDeepBrush`; `#3A6EA5` (Spira Ward note border) → `PanelStrokeBrush`; `#7EC8FF`/`#B8D4E8` (Spira Ward note foreground) → `AccentCoolBrush` (token exato já existe). Ganhou `rsp:Responsive.Breakpoints="True"` + style `UserControl.narrow` que colapsa o master em `<760px`. **Fecha a Fase E** (E1-E12 completa). Build Release **0 erros** (403 warnings preexistentes). [anterior: `v2.161.4.0`]
- **`v2.161.4.0` — E 단계 §E11: `MixTableEditor` → `ModuleMasterDetail_Shell` (112×112 행렬, 3열) (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH** (표면 다듬기: 레이아웃 마이그레이션; 새로운 기능 없음). **E 단계**의 계속 (`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E11). 적용 범위: **컨테이너 비주얼만** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음; DataContext/bindings/handlers/IRestorableModule은 변경되지 않음. O `MixTableEditor_Control.axaml` (176 → ~200 줄) 수동으로 구현한 그리드를 마이그레이션합니다 `3*,3*,5*` (112×112 매트릭스: 원본 ListBox | 파트너 ListBox | 결과 세부 정보) 표준 셸용. **아키텍처적 결정:** 이 매트릭스는 2단계의 연쇄 선택(origin → partner → result)을 필요로 하며, 표준 마스터-디테일 구조에는 직접 적용할 수 없습니다. Origin(Col0)은 `MasterList` (쉘은 주축에만 적용되며, `OriginFilterText`/`DisplayedOrigins`/`SelectedOrigin`); 파트너(Col1)는 **접을 수 있는 확장기 내의 Detail에 있는 선택기**가 됩니다(기본값은 확장된 상태 — `ResultFilterText`/`D

isplayedResults`/`SelectedResult`, label "Partner Item"); result detail (Col2) vira o topo do Detail (hero `heroBlue` preservado + session + Combination Editor). `AutoSaveIndicator_Control`, `GameIndex_Template` e `AtlasEvidenceBadgeStrip` preservados. Ganhou `rsp:Responsive.Breakpoints="True"` + style `UserControl.narrow` que colapsa o master em `<760px`. **Falta E12** (KernelCommands — maior detail do repo, maior risco). Build Release **0 erros** (403 warnings preexistentes). [anterior: `v2.161.3.0`]
- **`v2.161.3.0` — E 단계 §E10: `ShopExplorer` → `ModuleMasterDetail_Shell` (3-col cascading) (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH** (표면적인 개선: 레이아웃 마이그레이션; 새로운 기능 없음). **E 단계**의 계속 (`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E10). 적용 범위: **컨테이너 비주얼만** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음; DataContext/bindings/handlers/IRestorableModule은 변경되지 않음. O `ShopExplorer_Control.axaml` (361 → ~360 줄) 수동으로 구현한 그리드를 이전합니다 `Auto,Auto,*` (3열 캐스케이딩: 소스 ListBox | 상품 행 ListBox | 슬롯 슬라이스 편집기) 표준 셸용. **아키텍처 결정:** 소스 선택기(Col0)는 **MasterHeader 내의 콤팩트한 ComboBox**로 변경됩니다 (`LoadedSources`/`SelectedSource` + `LoadSummary` + Refresh); shop 행(Col1)은 `MasterList` (`FilterText` + `DisplayedShops`/`SelectedShop` + 필터 피드백); 슬롯 슬라이스 편집기(Col2)는 `Detail` (카드가 빽빽하게 배열된 WrapPanel) `SelectedSlots` (Image/ComboBox + “Advanced details” 확장 기능이 유지된 상태로). `AutoSaveIndicator_Control` 그리고 `AtlasEvidenceBadgeStrip` 보존되었습니다. **Hex → 토큰:** 슬롯의 시각적 배지에는 `#0D1621` (배경) 및 `#274760` (border) inline → `{DynamicResource PanelDeepBrush}` / `{DynamicResource PanelStrokeBrush}`. 우승했다 `rsp:Responsive.Breakpoints="True"` + 스타일 `UserControl.narrow` 마스터를 다음 위치에서 중단시키는 `<760px`. **E11-E12 미해결** (MixTable/KernelCommands). 릴리스 빌드 **오류 0개** (기존 경고 403개). [이전: `v2.161.2.0`]
- **`v2.161.2.0` — E 단계 §E9: `CustomizationEditor` → `ModuleMasterDetail_Shell` (TabControl 내부의 2개 셸) (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH** (po

표면 처리: 레이아웃 변경; 신규 용량 없음). **E 단계**의 계속 (`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E9). 적용 범위: **컨테이너 비주얼만** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음; DataContext/bindings/handlers/IRestorableModule은 변경되지 않음. O `CustomizationEditor_Control.axaml` (396 → ~340 줄) 수동으로 구현한 그리드를 마이그레이션합니다 `3*,7*` (국경 출입 카드 `Padding=16` (팽창 + ScrollViewer) **각각** `TabItem` 정통 프로 쉘 — o `<TabControl>` 외부(Gear / Aeon)는 **유지**되며, 각 내부에서는 `TabItem` 이제 ~에 대한 별도의 인스턴스가 있으며, `ModuleMasterDetail_Shell` (쉘 2개, 헤더 라벨 “Gear Recipes” / “Aeon Recipes”). 2세트의 바인딩 (`GearFilterText`/`DisplayedGearRecipes`/`SelectedGearRecipe`/`GearEditSession` vs `AeonFilterText`/`DisplayedAeonRecipes`/`SelectedAeonRecipe`/`AeonEditSession`)는 쉘 내에서 **격리**되어 있으며, 다른 요소와 섞이지 않습니다. `AutoSaveIndicator_Control` (Gear/Aeon) 및 `AtlasEvidenceBadgeStrip` (Aeon) 보존됨. 적용된 밀도: ListBox 항목 `Padding=12`→`10`, `Margin=0,0,0,10`→`6`, 출처 `16`→`14`, `sectionLabel`/`muted` 이겼다 `FontSize=11`. 우승했다 `rsp:Responsive.Breakpoints="True"` + 스타일 `UserControl.narrow` 두 마스터를 모두 `<760px`. **E10-E12 미해결** (Shop/MixTable/KernelCommands). 빌드 릴리스 **오류 0개** (기존 경고 403개). [이전: `v2.161.1.0`]
- **`v2.161.1.0` — E 단계(일부)(E1-E8): `ModuleMasterDetail_Shell` 8개의 Core Authoring(Jarvis-UI) 모듈. **Lane **Jarvis-UI**. **PATCH** (표면적인 수정: 레이아웃 마이그레이션; 새로운 기능 없음). **E 단계**의 첫 8개 커밋 (`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §4). 범위: **컨테이너 시각적 요소만** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음; DataContext/bindings/handlers/IRestorableModule은 변경되지 않음. **8개 모듈이** 수작업으로 마이그레이션됨 `Auto,*` / `2*,5*` 그리드 (보더 카드) `Padding=16` (팽창형 + ScrollViewer)에서 표준 셸(접을 수 있는 Expander, `Padding=8`, 밀집형): **E1 CtbBase**, **E2 PlayerGrowth**, **E3 Formation** (필드 컨텍스트 카드가 MasterHeader로 변경됨), **E4 Treasure** (카드 종류별 정보는 Detail에 보존됨)

), **E5 KeyItem** (`2*,5*` → `Auto,*`), **E6 AutoAbility** (상세 정보 8장 보존됨), **E7 BukiGetTreasureCatalog** (루트 `Margin=18` 제거됨 + 16진수 `#C9A227` → `WarningBrush`), **E8 MonEditorSelector** (이미 수동 확장 기능이 있었으나 — 셸로 대체됨; 세부 정보 교환은 다음을 통해 `ContentControl Name="ContentFrame"` (Detail 슬롯에 유지됨). 각 모듈은 `rsp:Responsive.Breakpoints="True"` + 스타일 `UserControl.narrow` 마스터를 다음 위치에서 중단시키는 `<760px`. **E9-E12 미포함** (Customization/Shop/MixTable/KernelCommands — 3열/매트릭스 레이아웃, 위험도 높음). 릴리스 빌드 **오류 0개** (기존 경고 403개). [이전: `v2.161.0.0`]
- **`v2.161.0.0` — D 단계 완료: 명령 팔레트 `Ctrl+K` (Jarvis-UI).** Lane **Jarvis-UI**. **MINOR** (새로운 제품 기능: 퍼지 검색이 가능한 명령어 팔레트). **D 단계 전체를 마무리하는** 커밋 `docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` (D1+D2+D3+D4 + 이 D5). 범위: **새로운 빠른 탐색 화면** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음. **새로운 `Modules/Main/CommandPalette_Popup.axaml(.cs)`**: 사용자 정의 UserControl(컨테이너 전용, 핸들러를 인식하지 않음)로 `TextBox` (자리 표시자 "모듈 검색…") + `ItemsControl` data-bound에 `ModuleRegistry.All` 다음으로 필터링됨 `Title.Contains`/`Description.Contains`/`Id.Contains` (IgnoreCase). 각 결과에는 아이콘이 표시됩니다 (via `IconKeyToGeometryConverter.ResolveGeometry`) + 제목 + 설명 (2줄). Enter 키를 누르면 첫 번째 결과가 열립니다(기본 선택됨); 행을 클릭하면 ID로 열립니다; Esc 키를 누르면 닫힙니다. **Wiring에서 `Main_Window`:** 새 `<Popup Name="CommandPalette" PlacementMode="Center" IsLightDismissEnabled="True">` (XAML에서 비워 둠 — 불필요한 XAML 네임스페이스를 피하기 위해 코드-비하인드에서 콘텐츠를 인스턴스화함); `ToggleCommandPalette()` 인스턴스를 캐시하고, 연결 `DispatchRequested`/`CloseRequested` (이벤트)를 호출합니다 `Reset()` 열기 전에. `OnKeyDown` 이긴다 `if (ctrl && e.Key == Key.K) ToggleCommandPalette()`. `Palette_DispatchRequested(id)` 팝업 닫기 + `Dispatch(id)`. **수락:** Ctrl+K를 누르면 중앙 팔레트가 열리고, “save”를 입력하면 → Save Editor가 나타나며, Enter를 누르면 열립니다. **D 단계 전체를 5개의 커밋으로 제출** (`v2.160.1.0` → `v2.160.4.0` 패치 + 이 사소한 수정): 

**약 72개의 모든 컨트롤**에서 다음/이전 기능을 복원할 수 있습니다. `IRestorableModule` (8개의 에디터 + 상태가 명시된 9개의 허브; 나머지는 기본 인터페이스 메서드를 통해 상태가 없음) + 41개 모듈에 대한 명령 팔레트(Ctrl+K). 릴리스 빌드 **오류 0개** (기존 경고 403개). [이전: `v2.160.4.0`]
- **`v2.160.4.0` — D4 단계: `IRestorableModule` 나머지 모든 컨트롤에 대해서는 기본 인터페이스 메서드(Jarvis-UI)를 통해 처리됩니다.** Lane **Jarvis-UI**. **PATCH**. **D 단계**의 네 번째 커밋 (`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D4). 적용 범위: **모든 곳에서 인터페이스를 선언해야 한다** `*_Control` 나머지** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않았습니다. `IRestorableModule.cs` **기본 인터페이스 메서드**를 얻게 됩니다: `CaptureState() => null` 그리고 `RestoreState(state) { }` (기본값: stateless/no-op). 따라서 의미 있는 상태가 없는 컨트롤(읽기 전용 탐색기, 허브, 런타임 랩, 디버그, 트래커, 16가지 추가 기능, Wave-1, 하위 컨트롤)은 다음만 선언하면 됩니다. `, IRestorableModule` 서명란에 — o `Main_Window` 이제 할 수 있습니다 `ContentFrame.Content is IRestorableModule` 유형을 가리지 않고 **어떤** 모듈에서든. **자동 스윕**을 통해 `work/_irestable_stateless_sweep_20260620.ps1`: **65개의 컨트롤이 변경됨** (추가됨 `using FFXProjectEditor.Modules.Common;` + `: UserControl, IRestorableModule`), **9개 생략** (D1/D2/D3에 이미 구현된 8개 + `MonsterAiEditor2_Control` 단종됨). **정직하게 말하자면:** 필터가 적용된 3가지 브라우저(MagicDllBrowser/RuntimeDllManager/Ps3MagicBrowser)는 다음 이유로 기본값인 ‘stateless’를 상속받았습니다. `FilterText` 비공개 DataModels에 존재하며, 컨트롤에는 노출되지 않습니다. 필터의 실제 캡처는 하위 백로그로 남습니다. D1+D2+D3+D4를 통해, **약 72개의 모든 컨트롤**이 이제 선언합니다. `IRestorableModule`; 기존에 있던 것들(편집자 8명 + 허브 9개)은 명시적인 오버라이드를 수행하며, 나머지는 스테이트리스입니다. 빌드 릴리스 **오류 0건** (기존 경고 402건). [이전: `v2.160.3.0`]
- **`v2.160.3.0` — D3 단계: `IRestorableModule` 에서 `SubTabHub_Control` (9개 허브 지원) (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH**. **D 단계**의 세 번째 커밋 (`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D3). 적용 범위: **모든 기반 허브에서 뒤로/앞으로 기능 복원 가능** 

에서 `SubTabHub`** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않았습니다. `SubTabHub_Control.axaml.cs` 구현한다 `IRestorableModule`: 새 필드 `int _activeTabIndex` 추적됨: `SelectTab(index)`; `CaptureState()` 돌아온다 `{["activeTab"] = _activeTabIndex}`; `RestoreState(state)` 불꽃 `SelectTab(idx)` (일반적으로 pill/active/hosted-content를 다시 호출합니다). **9개 허브에 대한 자동 지원:** BattleCommandsHub, ItemsHub, SphereGridHub, TextHub, EnemyDesignHub, CustomizationsHub, StatsHub, EncountersHub, Blitzball — 모두 다음을 사용합니다 `SubTabHub_Control` 출처: `AddTab(...)`, 그러면 한 번의 변경만으로 모든 사용자가 활성 하위 탭 복원 기능을 무료로 이용할 수 있습니다. **정직성:** 각 하위 탭의 내부 콘텐츠(호스팅된 편집기의 필터/선택 기능)는 호스팅된 컨트롤의 책임입니다 — 만약 해당 컨트롤이 또한 `IRestorableModule` (D2는 Treasure/KeyItem/기타 등을 다루었으며), 그 `Main_Window` 이어서 복원 작업을 실행합니다. 빌드 릴리스 **오류 0건** (기존 경고 402건). [이전: `v2.160.2.0`]
- **`v2.160.2.0` — D2 단계: `IRestorableModule` 7가지 간편한 에디터(Jarvis-UI).** Lane **Jarvis-UI**. **PATCH**. **D 단계**의 두 번째 커밋 (`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D2). 적용 범위: **7가지 Core Authoring 편집기에서 복원 가능한 뒤로/앞으로 기능** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음. 구현 `IRestorableModule` (D1에서 정의됨) **7개의 제어**에서: `TreasureEditor_Control`, `AutoAbilityEditor_Control`, `PlayerGrowthEditor_Control`, `CtbBaseEditor_Control`, `KeyItemEditor_Control`, `FormationEditor_Control`, `BukiGetTreasureCatalog_Control`. 각 `CaptureState()` 캡처 `filterText` (문자열) + `selectedIndex` (int? 컬렉션에서 선택한 항목에서 파생된) `Displayed*`); `RestoreState(state)` 필터를 다시 적용합니다 (이를 통해 `ApplyFilter` 출처: `OnFilterTextChanged`)를 사용하여 인덱스를 통해 행을 다시 선택합니다. **에디터별 매핑:** Treasure (`SelectedTreasure`/`DisplayedTreasures`), AutoAbility (`SelectedAbility`/`DisplayedAbilities`), PlayerGrowth (`SelectedCharacter`/`DisplayedCharacters`), CtbBase (`SelectedRow`/`DisplayedRows`), KeyItem (`SelectedItem`/`DisplayedItems`), 형성 (`SelectedBattle`/`Battles` — `Displayed*` 없음

`), BukiGetTreasureCatalog (`SelectedRow`/`표시된 행 수`). **Honestidade:** agora Monster Editor + os 7 editores acima são plenamente restorable via back/forward (voltam pra seleção/filtro exatos). KernelCommands + os hubs (BattleCommands/Items/etc.) viram em D3 (SubTabHub). Build Release **0 erros** (402 warnings preexistentes). [anterior: `v2.160.1.0`]
- **`v2.160.1.0` — D1 단계 완료: 인터페이스 `IRestorableModule` + 리팩토링 `NavigationSnapshot` (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH**. **D 단계**의 첫 번째 커밋 (`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D1). 범위: **탐색 아키텍처 (복원 가능한 뒤로/앞으로 이동)** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE는 변경되지 않음. **새로운 계약** `FFXProjectEditor/Modules/Common/IRestorableModule.cs`: `CaptureState()` → `Dictionary<string,object?>?` (null = 상태 없음) 및 `RestoreState(state)` (항등 연산, null에 대해 안전). D1 이전에는, `Main_Window` 구체적인 유형에 대해 패턴 매칭을 수행했고 (`MonEditorSelector_Control`/`KernelCommands_Control`) 상태를 캡처하기 위해 — ~38개 모듈까지 확장되지 않습니다. 이제 `Main_Window` 제어 장치에 그것이 있는지 물어보세요 `IRestorableModule`. **리팩토링** `NavigationSnapshot`:** 돌다 `record struct (string ModuleId, Dictionary<string,object?>? State)`; enum `NavigationSurfaceKind` **삭제**됩니다. 새 필드 `private string _currentModuleId = "home"` ~의 시작 부분에 설정된 `Dispatch(string moduleId)`. `CaptureCurrentNavigationSnapshot()` 일반 의약품 via `ContentFrame.Content is IRestorableModule`; `IsSameNavigationSurface()` 한 번 비교해 보세요 `ModuleId`; `RestoreNavigationSnapshot()` ~한다 `Dispatch(snapshot.ModuleId)` + `restorable.RestoreState(snapshot.State)`. **3건의 연결 실패 오류 수정** (여전히 참조하고 있었음 `NavigationSurfaceKind`): `MenuItem_MonsterMagic1/2` (L560/568) → `_currentModuleId = "battle-commands-hub"` + `new NavigationSnapshot("battle-commands-hub")` (다음과 동일한 패턴의 `MenuItem_Commands`/`MenuItem_Items` (이미 마이그레이션된 것); `NavigateToMonsterEditor` (L1549) → `new NavigationSnapshot("monster-editor")`. **정직하게 말하자면:** 뒤로/앞으로 기능은 3가지 원본(Home/Monster/KernelCommands)에서 계속 작동하지만, Monster/KernelCommands는 **완전히** 복원될 수 있을 뿐입니다.

le는 해당 컨트롤이 구현될 때 `IRestorableModule` (D2/D4). 그때까지는 스냅샷이 생성되지만, `State` 오다 `null` (모듈로 돌아가며, 하위 선택 항목은 복원하지 않음). 릴리스 빌드 **오류 0개** (기존 경고 402개). [이전: `v2.160.0.0`]
- **`v2.160.0.0` — A–C 단계: ModuleRegistry + Workspace Ready (§17) + 플라이아웃이 없는 아이콘 레일 (§16) (Jarvis-UI).** Lane **Jarvis-UI**. **MINOR**. A–C 단계의 전달 `docs/specs/EDITOR_UI_OVERHAUL_PLAN.md` §16–§17 (Halyson 2026-06-20 결정), 이에 따라 `docs/ai/PROMPT_UI_GLM_REMAINING_BACKLOG_2026-06-20.md`. 범위: **네비게이션 아키텍처 + 데이터 기반 카탈로그 + 아이콘 세트** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE **변경 없음**; 68개의 핸들러 `MenuItem_*` **리팩토링되지 않음** (단순히 호출만 됨). **단계 A — ModuleRegistry (단일 소스):** `ModuleCatalogPolicy.cs` 문서용 스텁에서 권위 있는 카탈로그로 발전 — 신규 `public static class ModuleRegistry` ~와 함께 `IReadOnlyList<ModuleCatalogEntry> All` **41개 항목**(홈 + 10개 핵심 제작 + 5개 지도 + 7개 라이브 + 16개 추가 콘텐츠 + 2개 웨이브-1)으로 채워졌으며, 각 모듈당 하나씩 레일을 따라 배정되었습니다. `ModuleCatalogEntry` 이긴다 `Mode`/`Notes`/`Scope`/`Cluster` (enum `ModuleCluster`) 그 외에도 `Id`/`Title`/`Description`/`IconKey`/`RequiresProject` 원본. 각 리터럴의 정확한 복사본 `SetModule(...)` 에서 `Main_Window.axaml.cs` (재창조된 것이 아님). doc-comment 정책: 신규 `MenuItem_*` 라우팅됨 = 레지스트리에 추가 (**검토 차단**). **단계 A — 아이콘:** `StudioIcons.axaml` **14개 → 54개 아이콘**으로 확장됨 (`<StreamGeometry>` Lucide 스타일, 뷰박스 24×24) — 모듈당 하나의 은유(검+뿔=몬스터, 디스켓=세이브, 해골=적 디자인, 육각 격자=구형 그리드 등). 일관성 검사(스크립트)를 통해 41개 모두 `IconKey`레지스트리의 s는 다음으로 해석됩니다. `StudioIcons`. **B 단계 — §17 Workspace Ready:** `MainDashboard_Control.axaml` 더 이상 6개의 하드코딩된 타일이 아닌, `ItemsControl ItemsSource="{Binding Modules}"` ~와 함께 `DataTemplate` (아이콘 + 제목 + 전체 설명 + 모드 팰릿). `Main_DataModel` 이긴다 `public IReadOnlyList<ModuleCatalogEntry> Modules => ModuleRegistry.All`. 새 컨버터 두 개가 `FFXProjectEditor/Converters/`: `IconKeyToGeo

metryConverter` (resolve string IconKey → Geometry percorrendo `자료` + `병합된 사전` via `TryGetResource(key, ActualThemeVariant, out _)` — necessário porque binding `{DynamicResource {Binding IconKey}}` não funciona para `PathIcon.Data` em Avalonia) e `RequiresProjectEnabledConverter` (`IMultiValueConverter` RequiresProject × IsProjectLoaded → `IsEnabled`). Hero + empty-state CTA + card de Workspace status preservados (§17.4). **Fase C — §16 Icon Rail sem flyouts:** removidos os 5 `Button.Flyout`/`플라이아웃 메뉴` do `IconRailCol` (XAML L156–239) — substituídos por `<StackPanel Name="RailStack">` populado em code-behind por `BuildIconRail()` (1 botão `railIcon` por entry, agrupado por cluster com `Border` 1px como separador). `Popup#RailDrawer` (narrow) troca a lista textual de `Button Classes="nav"` por `<WrapPanel Name="RailDrawerGrid">` (grid de ícones). Handler único `Button_RailModule_Click(sender, e)` lê `태그=ID` → `Dispatch(id)`. `RefreshRailProjectGates()` re-aplica o gate `RequiresProject` quando `Project_Service.IsProjectLoaded` muda. **Fase C — Dispatch genérico:** `OnQuickLaunchRequested` (6 keys hardcoded: monster/kernel/sphere/save/extras/home) substituído por `Dispatch(string moduleId)` com switch de **todos os 41 Ids** → handler `MenuItem_*` existente. Rail, drawer e dashboard passam pelo mesmo caminho. **Aceite:** build Release **0 erros** (402 warnings preexistentes); 0 `플라이아웃 메뉴` no `IconRailCol`; 0 tile hardcoded no dashboard; 41 ícones renderizando no rail + 41 cards no home com ícone dedicado + descrição completa; cards desabilitados quando `RequiresProject && !IsProjectLoaded`. **Bug visual corrigido:** os ícones não renderizavam inicialmente porque `Application.Current.Resources.TryGetValue()` em Avalonia 11 não percorre `병합된 사전` — fix via `ResolveGeometry()` helper compartilhado que itera os merged dicts com `TryGetResource`. [anterior: `v2.159.6.1`]
- **`v2.159.6.1` — 부트 수정: ModuleMasterDetail_Shell(Jarvis-UI)의 P1-7 반경/이동 토큰 및 바인딩. **Lane **Jarvis-UI**. **PATCH**. 핫픽스 이후`v2.159.6.0`. **StudioTheme:** 참조 P1-7 (`RadiusLg/Md/Sm`, `DurationNormal/Fast`)에서는 `{StaticResource ...`를 사용했고

}` mas os tokens estão em `Application.Resources` (`StudioTokens.axaml`) **depois** do `StyleInclude` do tema → `KeyNotFoundException: 정적 리소스 'RadiusLg'를 찾을 수 없습니다.` no boot (processo morria sem janela). Fix: `{DynamicResource ...}`. **ModuleMasterDetail_Shell:** `MasterHeader`/`마스터리스트`/`상세 정보`/`MasterHeaderLabel`/`IsMasterExpanded` agora usam `RelativeSource AncestorType=ModuleMasterDetail_Shell` (antes bindavam o DataModel do módulo → lista/botões/detail vazios no Magic DLL Browser e Runtime DLL Manager). Escopo: UI container only — writers/save/hooks intocados. Build Release **0 erros**. [anterior: `v2.159.6.0`]
- **`v2.159.6.0` — 프론트엔드 P0/P1 시각적 개선: heroGradient sweep + MonsterAi 16진수 토큰 + 좁은 드로어 + P1-7 디자인 토큰 (Jarvis-UI).** Lane **Jarvis-UI**. **PATCH**. P0/P1 백로그 실행 `docs/ai/FRONTEND_AUDIT_P0_P1_2026-06-19.md` 승인된 계획에 따라. 범위: **UI/디자인 시스템 다듬기** — writers/save bytes/hooks/FfxLib/RT0/RT2 **변경 없음**; `MonsterAiEditor2_*` (단종됨) **변경 없음**. **P0-1 (heroGradient sweep):** 25개의 파일에 포함된 26개의 인라인 그라데이션 `Modules/` 이주자 — 18명의 성직자 (`#163245/#0F1821/#214F69`) 보았다 `Classes="heroGradient"`; 8가지 정체성 변형이 새로운 명명된 토큰으로 보존됨 (`heroPurple`/`heroGreen`/`heroBrown`/`heroTeal`/`heroBlue` 에서 `StudioTheme.axaml` + `Color` 토큰 `HeroXxxA/B/CColor` 에서 `StudioTokens.axaml`) — Aurora는 보라색을 유지하고, AutoAbility/Formation/Customization은 녹색을 유지하며, KeyItem은 갈색을 유지하고, AlBhed/CtbBase/PlayerGrowth는 청록색을 유지하며, MixTable은 파란색을 유지합니다. `Main_Window.axaml` 헤더 (팔레트 `PanelDeepColor` (원본)을 의도적으로 보존했습니다. **P0-2 (MonsterAi hex → tokens):** 마이그레이션된 MonsterAiEditor 클러스터의 활성 파일 4개 — **261개의 16진수 리터럴** (Background/BorderBrush/Foreground)이 다음으로 축소되었습니다. `{DynamicResource ...}` 패밀리별(Shell/Protect/Regen/Gold/Forbidden/Cycle + Panel/Stroke), 패밀리 내 드리프트를 정규화하여 (~20개의 청록색 채우기가 1개로 변함) `AccentShellFillBrush`). 생성됨 **14 `AccentXxxForegroundBrush`** 신규 (이전에는 골드 회원만 이용 가능) + **가족 `Border.accentXxx`** (15가지 스타일 + 선택자 `> TextBlock`)에서 `StudioTheme`, `Button.accen`과 평행하게

tXxx` existente. `MonsterAiEditor2_Control.axaml` retém seus 71 hex (discontinued). **P0-4 (drawer narrow):** o bug onde em `Window.narrow` o botão "≡" e `Ctrl+B` não faziam nada visível (estilo `Window.narrow Border#IconRailCol → IsVisible=False` vencia o toggle) foi resolvido — novo `<Popup Name="RailDrawer">` flutuante em `Main_Window.axaml` com os 6 grupos de navegação como botões de texto verticais (mais escaneáveis que ícones 22px em tela pequena), `IsLightDismissEnabled=True`; `ToggleIconRail()` agora branch narrow→Popup / wide→Border. Reusa os MESMOS `MenuItem_*` handlers (zero mudança em handlers). **P1-7 (design tokens estruturais):** novas famílias em `StudioTokens.axaml` — **Spacing** (`SpacingXs/Sm/Md/Lg/Xl` Thickness + `StackGapSm/Md/Lg` doubles), **Radius** (`RadiusSm=8/Md=10/Lg=12/Pill=999` CornerRadius), **Motion** (`재생 속도: 빠름/보통/느림` `sys:TimeSpan`), **Elevation** (`Border.elevation1/2/3` BoxShadow). Adoção piloto: `StudioTheme.axaml` consome `반경 Lg/Md/Sm` em `Border.card`/`cardSoft`/`Button.primaryAction`/`secondaryAction`/`railIcon`/`tabPill`, e `소요 시간: 일반/빠름` nas 3 transições de microinteração (antes literais `0:0:0.12`/`0:0:0.10`); `MonsterAiEditor_Control.axaml` demonstra `SpacingLg/Md` + combo `카드 액센트 쉘` em 4 cards piloto. **Divergências do audit registradas:** P0-3 (Ctrl+B) já estava implementado na working tree (não era mais "comentário mentiroso"); P1-8 (shell) já tinha 2 consumidores; P1-5/P1-6 (arquitetura nav) fora do escopo por alto merge-risk. Build Release **0 erros** (401 warnings preexistentes, nenhum novo). Artefatos de sweep: `work/_hero_gradient_sweep_20260620.ps1`, `work/_monster_ai_hex_sweep_20260620.ps1`. [anterior: `v2.159.5.0`]
- **`v2.159.5.0` — UI Optionals Master: 단일 PATCH로 해결된 옵션 백로그의 28개 ID (Jarvis-UI).** 레인 **Jarvis-UI**. **PATCH**. 전체 실행 `docs/ai/PROMPT_UI_OPTIONALS_MASTER_2026-06-20.md` 제5절 — 미처리된 28개의 ID를 모두 구현함 (OPT-F2는 이미 `v2.159.4.0`, 재작성되지 않음). 범위: UI 다듬기 **컨테이너만** (토큰, 반응형, 접근성, 빈 상태, 필, 이모지) — writers/save bytes/hooks/FfxLib/RT0/RT2는 **변경되지 않음**. **Spri

nt B (재사용 가능한 SubTabHub):** OPT-B1/B2 — `AutomationProperties.Name` 모든 버튼에서 `tabPill` 에서 생성됨 `AddTab()`, 와 `tabA11yName` 선택 사항 (기본값은 레이블 “X 탭”에서 파생됨); OPT-B3 — `BlitzballSubTabHubFactory.Create()` 정적 분석은 다음의 5개 탭 구조를 추출합니다. `MenuItem_Blitzball` (5줄 이하); OPT-B4 — 자리 표시자 복사본 `requiresProject` 이제 허브를 통해 설정 가능 (`RequiresProjectMessage`), 기존 PT 기본값 유지. **스프린트 F (잔여 Magic DLL 브라우저):** OPT-F1 — 헤더 카드 `heroGradient`; OPT-F3 — **2개의 고정 행**에 배치된 작업 버튼(Open/View \| Author/Patch, 이전에는 단일 WrapPanel); OPT-F4 — `IsMasterExpanded` DataModel에 지속됨 (셸에서 TwoWay); OPT-F5 — 디테일의 영웅 `heroGradient`; OPT-F6 — 마스터 비어 있음 `!HasDllList` 표준에 따라 `Border#EmptyState` (아이콘 + 복사, detail이 비어 있는 경우와 동일); OPT-F7 — `StatusSeverity` (없음/정보/경고/위험)에서 파생된 `StatusText` + 새 항목 `StatusSeverityBrushConverter` 오류/알림을 표시합니다 `DangerBrush`/`WarningBrush`; OPT-F8 — `AutomationProperties.Name` 검색 텍스트 상자에서; OPT-F9 — pill `WRITER LAB · native magicFiles DLL · RT2 pending` 헤더에서. **Sprint A + C (Save Editor):** OPT-A1 — 반응형 디자인 (헤더가 세로 방향 StackPanel로 변경되며, 액션이 좁은 영역에 쌓임); OPT-A2 — 헤더 `heroGradient`; OPT-A3 — 알약 `READ-ONLY · FFXED port · RT2 via CLI` 헤더에; OPT-A4 — 전체 SHA256 해시의 클릭 시 복사(클립보드 경유 `TopLevel.Clipboard`, 새로운 `IconCopy`); OPT-C1 — `StatusSeverity` 에서 `StatusSummary` (변환기 재사용); OPT-C2–C5 — Character/Equipment/Items/Blitzball 하위 탭의 마스터 목록 `Expander` 접이식 (`ExpandDirection="Left"`, 기본값 확장). **스프린트 A5/A6/D (스피어 그리드 + 블리츠볼):** OPT-A5 — 이모지 `🏐` 에서 삭제됨 `SetModule` 블리츠볼과 `sectionLabel` 로스터에서; OPT-A6 — `♻️ Restaurar` → "원본 복원", `✕` 링크 → "제거" + a11y; OPT-D1 — v1 반응형 양식 (3열 그리드 → `WrapPanel` (narrow에 쌓이는); OPT-D2 — `ActiveToolMode` DataModel의 enum + 뷰 클래스 `toolActive` 활성 모드 버튼에서 (다음에 반영됨: `PropertyChanged` (코드 비하인드에서); OPT-D3 — `AutomationProperties.Name` Load/Save/Validate CTA에서. **스프린트 E (런타임

잔여 eDll):** OPT-E2 — 배너의 새로고침 버튼 `IsGameClosed`; OPT-E3 — C# 토글 버튼의 16진수 값 (`ToggleBrush`/`ToggleBorderBrush`/`ToggleForeground`/`ToggleGlow`/`RuntimeBrush`) 토큰으로 전환됨 `RuntimeToggle*`/`RuntimeRuntime*` 에서 `StudioTokens` (다음 방법을 통해 해결합니다 `Resources.TryGetValue`, 모듈에 16진수 없음); OPT-E1 — **건너뜀** (토글 DLL은 다음을 통해 동기식으로 작동함 `File.Move`/`File.Copy`, 300ms를 초과하는 눈에 띄는 비동기 작업이 없음 — 7절에 기록됨). 릴리스 빌드 **오류 0개** (기존 경고 401개, 수정된 파일에서는 경고 없음); 0 `#RRGGBB` 우리의 새로운 리터럴 `.axaml` 터치됨. [이전: `v2.159.4.0`]
- **`v2.159.4.0` — Magic DLL Browser: 9 hex → 토큰 + ModuleMasterDetail_Shell (2번째 소비자) + 빈 상태 + 반응형 + 접근성.** Lane **Jarvis-UI**. **PATCH**. **Magic DLL Browser**에서 모듈별 UI 감사를 계속 진행 중입니다 (`Modules/Extras/`), 다음과 같이 `docs/ai/PROMPT_UI_MAGICDLLBROWSER_2026-06-20.md`. (P0) 11명 `#RRGGBB` Chrome (Wave4 편집 지침) `#E8A040`, Value Workbench 제품군 경고 `#E8A040`, 그리고 3개의 RT2 인라인 배지 — 비활성화됨 `#3B1A1A`/`#E85050`/`#F0A0A0`, 제공 `#3B2719`/`#E8A040`/`#F0C070`, 위험 `#2A2A1A`/`#C0A040`/`#E8D080`) 기존 토큰/클래스에서 `StudioTheme`: `WarningBrush` 가이드라인/가족 경고 문구에서; 배지 **rt2-dead** → `Classes="pillDanger"`; 배지 **rt2-timing PROVED** → `Classes="pillWriter"`; 배지 **rt2-timing RISK** → 배경 `PanelAltBrush` + `WarningBrush` (테두리/전경). (P1) **두 번째 소비자**인 `ModuleMasterDetail_Shell` (1번 = RuntimeDllManager): 본문 `ColumnDefinitions="330,*"` hand-rolled는 쉘을 다음과 같이 바꿉니다. `MasterHeaderLabel="Magic DLLs"` — master = 소스 루트 요약 + 검색 + 목록 상자 `magic_*.dll`; 세부 사항 = 액션 히어로 + Wave4 어트리뷰션 + Direct Patch Builder + 고밀도 탭 컨트롤 (섹션/내보내기/가져오기/사운드 (SeSep)/오버레이 슬롯/역할 후보/패밀리 비교기/논리적 디컴파일/문자열/경고). `MinWidth` master ~260은 셸에서 비롯됩니다. (P2) `Border#EmptyState` 자세한 내용은 언제 `!HasSelectedDll` (제목 *"No DLL selected"* + DLL 선택 방법 또는 설정 방법을 안내하는 부제목) `magicFiles\FFX` root); 마스터 브랜치의 빈 상태일 때 `!HasDllList` (새로운 플래그 계산됨 `Dlls.Count > 0`, 알림

위치: `ApplyFilter` (Refresh 및 Search를 포함하기 위해); `rsp:Responsive.Breakpoints` no root + 스타일 `UserControl.narrow` <760px에서 마스터가 접힙니다(작업 WrapPanel이 Extract/Repack과 같은 중요한 버튼을 잘라내지 않습니다). (P3) `AutomationProperties.Name` 디테일의 약 16개 작업 버튼(Open DLL/Extract/Logical Decompile/Repack/Patch Plan/C/ASM Project/Semantic RE Report/Magic Viewer/Phyre Package I/O/Clone/바이트 패치 적용/ASCII 패치 적용/값 패치 준비 및 적용/호스트 오프셋 패치 준비 및 적용/ps3data 복제본 배포/PS3 Magic 및 폴더 열기). 헤더 카드는 다음과 같이 유지됨 `card` 일반 (결정: `heroGradient` 보조 컨텍스트 헤더에서는 부담이 될 수 있습니다(DLL이 선택된 경우 실제 히어로(hero)는 검사 패널에 표시됩니다). **범위 준수:** PE 오버레이, Direct Patch Builder, Value Workbench, 논리적 디컴파일, `MagicDllBrowser_DataModel` 디컴파일/재패키징/패치 로직 및 이벤트 `OpenPs3MagicRequested`/`OpenMagicViewerRequested` + 배선 없음 `Main_Window` 전혀 변경되지 않았습니다 — 시각적 컨테이너만 변경되었습니다 (UI 전용 속성 1개) `HasDllList` 추가됨). 빌드 릴리스 **오류 0개** (기존 경고 401개); 0 `#RRGGBB` 문자 그대로의 `.axaml` 모듈의. [이전: `v2.159.3.0`]
- **`v2.159.3.0` — Save Editor Hub 2단계: 칩 더티 + 페이로드 SHA256 + 세션 보호. **Lane **Jarvis-UI**. **PATCH**. **Save Editor Hub**에서 모듈별로 UI 감사를 계속 진행 중 (`Modules/SaveEditor/`), 다음과 같이 `docs/ai/PROMPT_UI_SAVEEDITOR_HUB_PHASE2_2026-06-20.md`. (P0) 클래스를 사용하여 헤더 카드에 **저장되지 않은 변경 사항** 칩 `autosaveChip`/`autosaveOrb`/`autosaveLabel` 기존의 `StudioTheme`, ~에 연결된 `IsDirty` — 사용자가 캐릭터/길/장비 등을 편집할 때 나타나며, ‘저장’ 또는 ‘다른 이름으로 저장’을 수행하면 사라집니다(DataModel은 이미 초기화됨). `IsDirty`). (P1) **페이로드 SHA256** 짧은 버전 (첫 12자 + "…") via `FfxSaveHash.Sha256Hex(session.Core.Data)` 헤더에 전체 해시(64자)를 표시하는 툴팁이 표시되며, 로드/저장/MC 전환 시 재계산됩니다 — **다음 경우에는** 재계산되지 않습니다. `TouchDirty` (해시 = 메모리 내 블롭의 지문; 더티 ≠ Apply+mutate 전까지 해시 변경 없음). 새로운 속성 `PayloadHashShort`/`PayloadHashFull` 및 방법 `RefreshPayloadHash()` DataModel에서. (P2) **세션 대체 전 확인**: nov

helper `AvaloniaDialog_Util.ConfirmYesNoAsync` (새로운 자산이 없는 Yes/No 모달)은 Load(툴바 + 빈 상태 CTA) 전에 호출되며, MC 슬롯을 변경하기 전에 `IsDirty`; MC 슬롯 콤보는 더 이상 직접적인 TwoWay 바인딩을 사용하지 않고 다음을 거치게 됩니다. `SelectionChanged` 확인 체크박스 + 수동 동기화 조합↔DataModel. **범위 준수:** FFXED 하위 탭, 오프셋, `FfxSaveFile` 작성자, 배치 태그 및 CLI `--ffx-save-rt2` 전혀 변경되지 않았습니다 — 허브 셸과 DataModel에만 새로운 속성이 추가되었습니다. 빌드 릴리스 **오류 0개**. [이전: `v2.159.2.0`]
- **`v2.159.2.0` — 블리츠볼 허브: 중복된 셸을 다음으로 이전 `SubTabHub` 재사용 가능.** Lane **Jarvis-UI**. **PATCH**. O `BlitzballHub_Control` (`Modules/BlitzballHub/`)는 정확히 그 `SubTabHub_Control` 벌써 — 하위 탭 영역 `tabPill`, `tabPillActive`, 지연 로딩 + 탭별 캐시, Writer/Read-only 필러, 오디오 `PlayAlternative()` 클릭 시. O `MenuItem_Blitzball` 이제 하나 만들어 보세요 `SubTabHub_Control` ~와 함께 `AddTab` 5개의 탭(Writer 4개 + Prize Atlas 읽기 전용 1개)에 대해 fluent를 적용하며, 동일한 pill 텍스트와 `requiresProject: false` 모든 경우(4개의 문서 편집기는 각각 고유한 빈 상태를 유지하며, Atlas는 프로젝트 없이 열립니다). The `BlitzballHub_Control` (`.axaml` + `.axaml.cs`)는 **삭제**됩니다 — `grep` 더 이상 찾을 수 없다 `new BlitzballHub_Control()` 제작 중. **범위 준수:** `FfxLib/Blitzball/*`, RT0/RT2, `ByteSnapshotEditorSession` 그리고 5개의 하위 에디터의 내부 콘텐츠는 전혀 변경되지 않았으며, 시각적 컨테이너만 바뀌었습니다. 이는 향후 마이그레이션을 위한 템플릿이 되었습니다. `SaveEditorHub` (7개의 탭이 하드코딩됨). 빌드 릴리스 **오류 0개** (기존 경고 401개). [이전: `v2.159.1.0`]
- **`v2.159.1.0` — 런타임 DLL 매니저: ModuleMasterDetail_Shell 파일럿 + heroGradient + 반응형 디자인 + 오프라인/분리 상태 배너 + 빈 상태 + 접근성(a11y).** Lane **Jarvis-UI**. **PATCH**. **Runtime DLL Manager**에서 모듈별 UI 감사가 계속 진행 중입니다 (`Modules/RuntimeDllManager/`), 다음과 같이 `PROMPT_UI_RUNTIMEDLL_2026-06-20.md`. (P0) Hero 인라인 `#183444/#111C24/#3B4B2D` → `Classes="heroGradient"`; 크롬의 16진수 `#20303B` 에서 삭제됨 `.axaml` (사용 `RailHoverBrush`/`PanelStrokeBrush`). (P1) **가장 먼저 소비된 것

r**의 저장소에서 `ModuleMasterDetail_Shell`: master = 상태 카드 3장 (Game root / FFX open / Hooks); detail = 영웅 + DLL 목록. (P1) `rsp:Responsive.Breakpoints` + 스타일 `UserControl.narrow` 마스터가 다운됩니다. (P2) 배너 `WarningBrush`/`DangerBrush` ~할 때 `IsGameClosed` (게임 종료 — 토글은 디스크만 설정함) 그리고 `IsRuntimeDetached` (프로브/훅 없이 열린 FFX — 실시간 상태가 신뢰할 수 없음). 빈 상태 `Border#EmptyState` ~할 때 `!GameRootReady`. (P3) `AutomationProperties.Name` 상태 체크박스 및 작업 버튼에서; `ToggleA11yName` 항목별. **범위 준수:** 배포/토글/DLL/훅/프로브 로직은 변경되지 않음 — 시각적 컨테이너만 변경. [이전: `v2.159.0.0`]
- **`v2.159.0.0` — Save Editor의 Character 탭: FFXED 호환성 (스킬, 파티, OD 모드, 오버드라이브).** Lane **Jarvis-UI**. **사소한 변경**. Character 탭이 더 이상 스탯과 일괄 처리 버튼만으로 구성되지 않습니다: 신규 `SaveEditor_CharacterBindings` + `FfxSaveCharacterFieldCatalog` FFXED v0.749 패널을 반영함 — 콤보 활성화/오버드라이브 모드, 파티 (7 슬롯 @15768), ~95개 어빌리티(비트필드 @22090), 카운터가 포함된 20가지 오버드라이브 모드, 오버드라이브 및 스페셜 어빌리티, 최대치가 설정된 스피어 레벨/OD 게이지(22088/22086). `FfxSaveCore.ReadSaveBit/WriteSaveBit` >7 비트 수정 (FFXED 의미론) `offset + bit/8`). FFXED와 마찬가지로 UI가 3열로 재구성되었습니다. 빌드 릴리스 **오류 0개**. [이전: `v2.158.2.0`]
- **`v2.158.2.0` — Sphere Grid Builder: 헥스 → 토큰 + 사이드 패널의 빈 상태 + 행 단위의 툴바. **Lane** **Jarvis-UI**. **PATCH**. **Sphere Grid Builder**에서 모듈별로 UI 감사를 계속 진행 중입니다 (`Modules/SphereGridBuilder/`, v1 form + v2 canvas), 다음과 같이 `PROMPT_UI_SPHEREGRID_BUILDER_2026-06-20.md`. (P0) UI의 chrome에 포함된 16진수 리터럴은 토큰으로 변환됩니다: `#C9A227` (경고 문구) → `{DynamicResource WarningBrush}` 에서 `TopologySafetySummary`, `StatusSummary` 그리고 `SaveSummary` (v1); `#F23A3A` (라이브 리스크) → `{DynamicResource DangerBrush}` 에서 `LiveRiskWarning`; `#22FFFFFF`/`#33FFFFFF` (구분 기호) → `{DynamicResource PanelStrokeBrush}` + `Opacity="0.4"`. (P1) 캔버스의 측면 패널이 `Border#EmptyState` (이미 존재하는 스타일) `StudioTheme`) 제목 *"선택된 노드가 없습니다"* + '선택' 모드를 안내하는 부제목 + 

`ModeLabel` ~할 때 `!HasSelection`; 기존 편집 블록은 다음과 같이 변경됩니다 `IsEnabled` 작성자: `IsVisible="{Binding HasSelection}"`. (P1) 과도하게 붐비는 툴바(컨트롤 약 20개가 포함된 단일 WrapPanel)를, 어떤 버튼도 제거하거나 핸들러를 수정하지 않은 채 **열기** / **모드** / **검증·저장**의 3개 고정 행으로 재구성합니다. **범위 준수:** `SphereGridLayoutBuilder`, 세이브 바이트, Square/TrueNewNode 로직 및 렌더링 색상을 `SphereGridCanvasView.cs` 전혀 손대지 않았습니다 — 시각적 컨테이너만 변경되었습니다. 빌드 릴리스 **오류 0개**; 제로 `#RRGGBB` 문자 그대로의 `.axaml` 모듈의 (주석 제외). [이전: `v2.158.1.0`]
- **`v2.158.1.0` — 저장 편집기: 빈 상태 + 접을 수 있는 탐색 메뉴 + 활성 탭. **Lane **Jarvis-UI**. **PATCH**. 모듈별로 UI 감사를 계속 진행 중이며, 이번에는 **저장 편집기**(FFXED 포팅)를 다룹니다. (P0) 언제 `HasSession == false`, 그 `TabHost` 로 대체됩니다 `Border#EmptyState` (이미 존재하는 스타일: `StudioTheme`) 아이콘과 *"No save loaded"*라는 제목, 지원되는 형식(.psu / 25848 바이트 / .ffx PC / .ps2 MC)을 나열한 부제목, 그리고 동일한 핸들러를 가리키는 **Load…**라는 기본 CTA가 있는 `Button_Load` — 역 바인딩을 선호하며 (`IsVisible="{Binding !HasSession}"`) 코드 비하인드의 논리에 관하여. (P1-A) 이제 Equipment/Items/Blitzball/Sphere Grid/Minigame/Misc를 클릭하면 해당 버튼이 활성화됩니다: 제거됨 `tabPillActive` 캐릭터에만 머물러 있던 정적, 그리고 `SelectTab(int)` 7개의 버튼에 클래스를 적용/제거합니다 (다음과 동일한 패턴으로 `SubTabHub_Control`). (P1-B) 약 220px 너비의 고정된 측면 탐색 열이 `Expander` 왼쪽으로 접을 수 있음 (`ExpandDirection="Left"`, 다음 위치에 저장됨 `IsSectionsExpanded` DataModel에서, 기본값이 확장된 상태) — 이미 에서 유효성이 검증된 바로 그 표준 `MonsterAiEditor` 오버홀의 레이어 4에서. (경량 P3) `AutomationProperties.Name` 툴바의 Load/Save/Save As/FFXED 버튼에서. **적용 범위:** FFXED 로직 / `FfxSaveFile` / 배치 태그 / MC 멀티 슬롯 / 저장 형식 / CLI `--ffx-save-rt2` 전혀 변경되지 않았습니다 — 허브의 시각적 컨테이너만 바뀌었습니다. 빌드 릴리스 **오류 0개**. [이전: `v2.158.0.0`]
- **`v2.158.0.0` — UI 감사 후속 조치: 악센트 토큰, 대시보드 빠른 실행 및 전역 바로가기. **Lane **Jarvis-UI**. **MINOR**. 소요 시간 ~100시간

다음의 문구에서 `MonsterAiEditor` 토큰용 `Accent*Fill/BorderBrush` + 스타일 `Button.accent*` 에서 `StudioTokens`/`StudioTheme`. 데이터 기반 대시보드 홈 (`MainDashboard_Control`): 워크스페이스 상태가 반영된 히어로, 반응형 그리드 퀵 런치 및 이벤트 `QuickLaunchRequested` 다음 경로를 통해 `Main_Window`. 앱의 첫 번째 글로벌 바로가기: `Ctrl+B` (IconRail 토글), `Alt+Left`/`Alt+Right` (뒤로/앞으로). 깔끔한 푸터/상태 표시줄 및 사이드바 메뉴 (이모티콘 제거; `PathIcon` (워크스페이스 배지에서). [이전: `v2.157.0.0`]
- **`v2.157.0.0` — SGM 네이티브 노드: 저장 파일의 861번째 노드 읽기/쓰기 + 오프셋 검증기 + RE 세션 3.** Lane **Jarvis-MAGIC-SGM Native**. **MINOR**. RE 검증 (세션 3, `FFX_SPHEREGRID_SAVE_ORCHESTRATOR_RE_2026-06-19.md`)는 다음과 같이 강조한다. `A5BB70`/`A49590` NodeCount 기반이며(클램프 860 없음), 노드 860이 `state[1720/1721]` = **save+10404/10405** (인덱스 1279까지 여유 공간), 벌크 방식을 통해 네이티브로 유지됨 `memcpy` — **사이드카 없음**, 노드 1개 추가. 새로운 라이브러리 `FfxSaveSphereGridRuntimeTable` (원본 지도 `save+8684+2*idx`, 오프셋 분류) + CLI `--spheregrid-extra-node-rt0` (노드 860의 왕복 통신 및 SG 영역의 바이트 식별자) 및 `--spheregrid-save-diff` (게임 내 경험적 오프셋 검증기). `SphereGridFullGridCompilerHook v1.2` 다음에서 읽기 전용 우회 경로를 얻습니다 `A45570` 어떤 로고 `menu+2/+4` (NodeCount/LinkCount) 로드 후 + 레코드 858..862 (FFFF=고스트), 빈 그리드의 원인 파악 중 (asset Square / magic check) 및 L3 게이트 위치: `A49590`. Gates SGM-RT0-08/09 PASS (매트릭스 9/9). 인게임 렌더링(진입/이탈) 및 네이티브 RT2 라운드트립은 **Halyson 보류 중**입니다. [이전: `v2.156.2.0`]
- **`v2.156.2.0` — SGM RT2 복구: 런처/훅 강화 + RT2-03 FAIL 위조 가능.** Lane **Jarvis-MAGIC-SGM-RT2**. **PATCH**. `sgm_rt2_launch.ps1` 이제 vanilla와 Square identity를 구분하고, env에 따라 TrueNewNode를 지웁니다 `0`, 오버레이의 해시를 검증하고, 내보내기 `FFXHOOKS_SG_ASSET_NODES/LINKS`, Square 오버레이를 vanilla observe로 이동하고 RT2-03b용 검증된 사이드카 시드를 생성합니다. `SphereGridFullGridCompilerHook` env/manifest/sidecar별로 신뢰할 수 있는 카운트를 사용하고, seed를 적용합니다. `A53DE0`/`A54860` ~할 때 `WRITE=1`, 그리고 로고 `live/trusted/sidecar/effective`. RT2-02 바닐

**PASS**로 표시됨; RT2-03 Square 861은 **FAIL**(그리드 비어 있음/L3) 상태를 유지하며, 비록 `node=860 00/00 -> 09/00` + 패치 메뉴 로그인됨; RT2-04 차단됨. [이전: `v2.156.1.1`]
- **`v2.156.1.1` — SGM 프롬프트 감사: A-E 레인이 SUPERSEDED로 표시됨 + 현재 RT2 프롬프트. **레인** **Jarvis-MAGIC**. **REVISION**. 팩 `PARALLEL_LANES_SGM_MASTER` 및 프롬프트 `PROMPT_SGM_LANE_A/B/C/D/E_*` 이제 다시 붙여지지 않도록 **SUPERSEDED** 배너가 추가되었습니다; 새 버전 `PROMPT_SGM_CURRENT_RT2_PROOF_2026-06-19.md` 현재 RT2 테스트용 단일 스크립트가 위조 가능하게 변경되었습니다. 런타임 코드 변경 없음. [이전: `v2.156.1.0`]
- **`v2.156.1.0` — SGM 감사 + 전체 그리드 컴파일러 사이드카 라이터 보안 강화.** Lane **Jarvis-MAGIC**. **PATCH**. 새로운 문서 `FFX_SPHEREGRID_SAVE_MIGRATION_AUDIT_AND_NEXT_ACTIONS_2026-06-19.md`; RT2 플레이북은 오직 다음을 가리킵니다 `scripts/sgm/*`; 스크립트 `scripts/sgm` 절대 경로를 사용하여 작동합니다; `SphereGridFullGridCompilerHook` 이제 작성하세요 `profile_key` + 해시 `save/layout/contents` sidecar 작성 전에 env를 확인하고, 완전한 식별자가 없는 경우 쓰기 요청을 거부하여 첫 번째 RT2-04에서 유효하지 않은 JSON이 발생하는 것을 방지합니다. 상태는 **offline-valid / lab-rt2**로 유지되며, RT2 인게임 테스트는 보류 중입니다. [이전: `v2.156.0.0`]
- **`v2.156.0.0` — SGM Lane E complete (오프라인 RT0/RT2 하네스).** Lane **Jarvis-MAGIC-SGM-E**. **MINOR**. 버전 관리된 스크립트 `scripts/sgm/*` (RT0 7/7, RT2 시작, 운영자, 고정 장치 부트스트랩); CLI `--sgm-fixtures-bootstrap`; 오프라인 판정 + 레인 상태 문서; `work/sgm_*.ps1` 래퍼가 나타났습니다. RT0 **오프라인 유효**; RT2 게임 내 **Halyson 대기 중** (RT2-06/08 차단됨). [이전: `v2.155.0.3`]
- **`v2.155.0.3` — Sphere Grid 세이브 오케스트레이터 RE 세션 2 (레인 A).** 레인 **Jarvis-MAGIC-SGM-A**. **REVISION**. 세이브→런타임 캡처 완료 @ 8748/11308 (벌크 별칭 모델, 로더 없음); 맵은 다음 경로를 통해 갭을 기록합니다. `A5BB70`; disasm chunks load/write orchestrator; A47210 오버레이를 반박함. [이전: `v2.155.0.2`]
- **`v2.155.0.2` — 스피어 그리드 세이브 포맷 오류 해결 실험 1단계 (결정 문서, 레인 D).** 레인 **Jarvis-MAGIC-SGM-D**. **개정판**. 문서 `FFX_SPHEREGRID_SAVE_FORMAT_BREAK_LAB_STATUS_2026-06-19.md`: 다운스트림 오프셋 10467 행렬, 판정 결과 Option A **ABANDON**, B **DEFER** (Lane A 간격), C **ABANDON**

**; 킬 기준 + 디자인 랩 스위치 2단계 게이트 적용. 코드 없음 — 일반 에디터와 바이트 단위 동일. 제품 = 사이드카 + 후크. [이전: `v2.155.0.1`]
- **`v2.155.0.1` — 스피어 그리드 세이브 오케스트레이터 IDA RE (레인 A 일부).** 레인 **Jarvis-MAGIC-SGM-A**. **REVISION**. 문서 `FFX_SPHEREGRID_SAVE_ORCHESTRATOR_RE_2026-06-19.md`: ~임을 증명한다 `A5BB70` 런타임 테이블(세이브 버퍼 제외)만 기록하고, 오케스트레이터의 I/O 벌크 맵, A/B 갭 가설, IDA 리네임 큐를 처리합니다. 다음 위치에 추가합니다. `FFX_SPHEREGRID_SAVE_MIGRATION_GAPS_AND_PIPELINE`. [이전: `v2.155.0.0`]
- **`v2.155.0.0` — Sphere Grid 전체 그리드 컴파일러 후크 (실험용 DLL, 기본값은 관찰 전용).** Lane **Jarvis-MAGIC-SGM-C**. **MINOR**. 신규 `SphereGridFullGridCompilerHook` 에서 `FfxHooksDll` — 우회로 5곳 (`A53DE0`/`A47210`/`A49590`/`A5BB70`/`A54860`), 최소한의 JSON 파서 사이드카, split persist 스텁, env `FFXHOOKS_ENABLE_SG_FULL_GRID_COMPILER=1` (기본값: OFF). Doc `FFX_SPHEREGRID_FULL_GRID_COMPILER_HOOK_IMPL_2026-06-19.md`. **lab-rt2** — RT2 통과 없음. [이전: `v2.154.0.0`]
- **`v2.154.0.0` — Sphere Grid Save Migration: 사이드카 C# 읽기/쓰기 라이브러리 + RT0 CLI.** Lane **Jarvis-MAGIC-SGM-B**. **MINOR**. 새로운 라이브러리 `FfxSaveSphereGridExtraStateSidecar` + `FfxSaveSphereGridExtraStateSidecarIO` (원자적 로드/저장, 유효성 검사, `Matches`, `BuildEmptyFromAnalyzer`, 병합 헬퍼); CLI `--spheregrid-sidecar-validate/create/info`; 예시 `work/_samples/sgm/sidecar_v1_minimal.json`; 경로 규칙 `mods/Spira Reforge/save-sidecars/<profile>/<prefix>.sphere-grid-extra.json`. Gates SGM-RT0-05/06 오프라인. [이전: `v2.153.0.0`]
- **`v2.153.0.0` — Sphere Grid 저장 데이터 이전: 분석기 + 사이드카 스키마 + 전체 그리드 컴파일러 사양. **Lane **Jarvis-MAGIC**. **MINOR**. 새로운 읽기 전용 CLI `--spheregrid-save-migration-analyze <save> <dat0X> <dat1X> [--json]` FFXED의 25,848바이트를 Square의 자산과 비교하고, 용량/델타/정책 및 스키마를 보고합니다. `sphere-grid-extra-state.schema.json` 860번 이상의 노드/링크에 대한 사이드카 지속성을 정의함; 문서를 통해 갭 맵을 완성하고, 풀 그리드 컴파일러 후크 사양, 세이브 포맷 브레이크 실습 및 RT0/RT2 매트릭스를 마무리함. [이전: `v2.152.1.0`]
- **`v2.152.1.0` — Task Reward Inspector FROZEN: 에디터에서 UI가 제거되었습니다.** Lane **Jarv

is-MAGIC**. **PATCH**. 제품 ROI가 낮아 전면이 읽기 전용으로 고정됨: **Task Rewards 🏁** 메뉴 및 모듈 `Modules/TaskRewardInspector/*` 삭제됨; CLI `--task-reward-inspect` FROZEN(연구용) 배너가 그대로 표시됩니다. Doc `FFX_TASK_REWARD_INSPECTOR_FROZEN_2026-06-18.md`. 실제 제작 작업은 ‘커널 명령어’ / ‘보물’ / ‘블리츠볼’ / ‘몬 에디터’에서 계속되고 있습니다. [이전: `v2.152.0.0`]
- **`v2.152.0.0` — 스피어 그리드 스퀘어 모드 1단계: 스퀘어 저장 + dat0X+dat1X 전체 패키지 내보내기.** Lane **Jarvis-MAGIC**. **사소한 변경**. Canvas v2에 **Square Mode** 토글 기능과 **Save Square** / **Export Square Package** 버튼이 추가되었습니다. `SphereGridSquarePackageWriter` (`square_grid_manifest.json` + report + README deploy), 저장 후 재기준 설정 via `FromExisting`, manifest delta bridge와 함께 `square_mode=1`. RT2 후크가 R27에서 멈춤; 결과 = Square로 재인증 실패. 계획: `FFX_SPHEREGRID_SQUARE_MODE_FULL_REAUTHOR_PLAN_2026-06-18.md`. [이전: `v2.151.0.0`]
- **`v2.151.0.0` — 태스크 보상 게임 파일 누락: grantAbility, Ronso mon.bin, Tidus counter, corpus mode.** Lane **Jarvis-MAGIC**. **MINOR**. `TaskRewardGameFileLoader` 이제 ATEL을 스캔하세요 `0x01FC`/`0x01FD` (권한 부여/철회), 크로스링크 `mon.bin` RonsoRageId (0..999), battle-gate Tidus @15852, 및 모드 `--all-treasure-grants` / 전체 obtainTreasure 코퍼스용 체크박스 UI (원본 카운터 대 필터링된 카운터). 스냅샷 저장을 통해 표시 `TidusOverdriveUseCount`. [이전: `v2.150.0.0`]
- **`v2.150.0.0` — Task Reward Inspector: 게임 파일 읽기 (커널 + ATEL).** Lane **Jarvis-MAGIC**. **MINOR**. 신규 `TaskRewardGameFileLoader` 읽다 `command.bin`, `takara.bin`, `important.bin` 그리고 다음을 스캔합니다. `.ebp` FFX 프로젝트가 로드되면 (obtainTreasure/hasKeyItem)이 실행됩니다. UI에 ‘Game files’ 패널과 ‘Load’ 버튼이 추가되었습니다. CLI `--game-files [--project]`. Doc `FFX_TASK_REWARD_GAME_FILE_RE_2026-06-18.md`. [이전: `v2.149.1.0`]
- **`v2.149.1.0` — Task Reward Inspector: 레지스트리의 명명된 플래그(저장 기능 없음) + 타당성 문서. **Lane **Jarvis-MAGIC**. **PATCH**. 탭 `Task Rewards 🏁` 이제 보상 항목을 나열합니다. `ffxed_registry` (Shooting Star, Attack Reels, Jecht's Sphere 등)은 세이브 로드를 요구하지 않으며, Live 열은 선택적 세이브로만 채워집니다. 새로운 문서 `doc

s/reverse/FFX_TASK_REWARD_AUTHORING_VIABILITY_2026-06-18.md` mapeia caminhos save-side / ATEL / hook com gates. [anterior: `v2.149.0.0`]
- **`v2.149.0.0` — 에디터의 Task Reward Inspector: 작업/보상에 대한 읽기 전용 탭. ** Lane **Jarvis-MAGIC**. **MINOR**. CLI `--task-reward-inspect` 이제 IconRail에 Avalonia 테마가 추가되었습니다 (`Task Rewards 🏁`): 캐릭터/보상으로 필터링 가능한 인벤토리, 선택한 퀘스트 상세 정보, 세이브/데이터 지역 지도, 오토링 경로, OD 모드/게이지/킬/비트 스냅샷 및 블리츠볼 보상을 위한 25848바이트의 세이브 원본 데이터 선택적 불러오기. 라이터 없음; 오토어링 전에 diff/ATEL 가드레일을 유지합니다. [이전: `v2.148.0.0`]
- **`v2.148.0.0` — UI 편집기 전면 개편 (계획의 4~12단계).** Lane **Jarvis-UI**. **MINOR**. 다음을 완료합니다. `EDITOR_UI_OVERHAUL_PLAN.md`: 무거운 모듈 내부에서 다시 나타나던 내부 사이드바를 제거했습니다 (`MonsterAiEditor`, `MonsterEditor`) — 돌다 `Expander` 접이식 (`Padding="8"`, 항목당 cardSoft 없음); 밀도 (반경 18→12, 패딩 16→12, `Button.nav` 14.12→12.8); 타이포그래피 (`h1`/`h2`/`h3`/`label`/`body`/`muted`); 1줄짜리 헤더 ~40px (워크스페이스 배지 + 아이콘); `Button.dangerAction` + `Border.pillDanger` + `:focus-visible` + `Border#EmptyState`; 푸터 → 1줄 상태 표시줄; 리터럴 색상을 토큰으로 변환 (`PanelDeepColor`, `HeroAccentColor`, `RailHoverBrush`...); 실제 도상 (`PathIcon` + `StudioIcons.axaml`) IconRail 및 헤더에서; 포인터 오버 시 120ms 전환. **오류 0개**로 빌드됨. [이전: `v2.142.0.1`]
- **`v2.142.0.1` — Sphere Grid True New Node hook v5.2: 종료 프로브 8E27E0/8E27B0/A54720.** Lane **Jarvis-MAGIC**. **PATCH**. RT2 R3a에서 바닐라 버전 실행 후 크래시 확인됨`A54860`; v5.2는 UI 비활성화 + 콜백 슬롯-19 + SEH 및 exit-snapshot을 포함한 GPU 정리 기능을 우회합니다. RT2 R4a 필수. [이전: `v2.142.0.0`]
- **`v2.142.0.0` — Task Reward Inspector: 작업, 보상 및 저장 영역에 대한 읽기 전용 인벤토리. **Lane **Jarvis-MAGIC**. **MINOR**. 새로운 CLI `--task-reward-inspect [--save <raw-25848-save>] [--json]` 보상용 바닐라 게이트(티더스/아우론/와카/키마리/루루/리쿠/유나/OD 모드)를 정리하고, 알려진 세이브 지점을 명시하며 (`15788..15852`,

 `22090..24606`, OD 모드, 블리츠볼, 키/미니게임 플래그, 스피어 그리드)를 다루며, 안전한 제작 경로를 제시합니다. 라이터 없음: 블리츠볼 오버드라이브 보상은 특정 보상에 대해 메타데이터 전용/차단 상태로 유지되며, ATEL/키 플래그 이벤트는 RE의 다음 과제로 남습니다. [이전: `v2.141.0.1`]
- **`v2.141.0.1` — Sphere Grid True New Node hook v5.1: 종료 경로 읽기 전용 + A54860 수정 후.** Lane **Jarvis-MAGIC**. **패치**. 훅이 버그를 수정합니다. `after-A5BB70` manifest를 다시 적용했는데 `g_writeApply=1` 비록 `g_writeSave=0`; 경로 `before-A54860` 관찰 전용으로 설정; 트램펄린에서 SEH `A54860`/`A5BB70`. RE가 vanilla의 exit을 매핑했습니다 `A56060 → A5BB70 → A54860 → 8E27E0`; 조사 후 용의자: `FFX_Abmap_DeactivateAndReturnToFieldUI` 및 분해 렌더링 `A54560/A54660`. 문서: `FFX_SPHEREGRID_EXIT_POST_A54860_RE_2026-06-18.md`. RT2 R3 필수. [이전: `v2.141.0.0`]
- **`v2.140.0.8` — Sphere Grid True New Node: 할로케이터 반박됨, 정적 ABMAP 버퍼 입증됨.** Lane **Jarvis-MAGIC**. **REVISION**. Sprint A.5 IDA에서 게이트링 미확인 사항 해결: `dword_2305834`/`g_FFX_AbmapMenuStatePtr` 힙 크기가 부족해서 발생하는 문제가 아닙니다; `FFX_Abmap_InitStaticMenuStateBuffers` (`0xA572E0`)는 포인터를 `word_133F76C+0x36E104` 그리고 초기화 `0x12FC0` 바이트. 노드 레코드는 `1024 * 0x28`, 따라서 노드 860은 버퍼 내에 있습니다. “A5BB70이 OOB를 읽는 이유는 할로케이터가 860이기 때문”이라는 가설은 **반박됨**. 새로운 용의자: 이후 발생한 크래시`A54860`/메뉴의 취약한 창 또는 후크 재작성 `after-A5BB70`; 향후 게이트에서는 SEH/정확한 단계를 구현해야 하며, 할로케이터에 패치를 적용해서는 안 됩니다. [이전: `v2.140.0.7`]
- **`v2.140.0.7` — 스피어 그리드 트루 뉴 노드 RT2 R2 크래시 RE + 세이브 레이아웃 조정.** Lane **Jarvis-MAGIC**. **REVISION**. v5 후크가 포함된 RT2 R2에서 **CRASH** 발생 `after-A54860`; 6개의 하위 에이전트(BG-A–F)가 일치: 가설 A54860 OOB **반증됨** (루프 1024 읽기 전용); 엔진 **헤더 기반** (save/load 시 NodeCount가 하드코딩되지 않음); 충돌 후보 = OOB 읽기 발생 `A5BB70` blob 메뉴 `dword_2305834` 용량이 작음; SG 저장 시 약 1.2 KB의 여유 공간이 있는 것으로 경험적으로 확인됨 (9회 저장). 문서: `FFX_SPHEREGRID_TRUENEWNODE_RT2_R2_VERDICT_2026-06-18.md`, `FFX_SAVE_SPHEREGRID_ADDRESS_MAP_2026-06-18.md`, `FFX_SAVE_FORMAT_AND_SPHEREGRID_LAYOUT_2026-06

-18.md`, `FFX_SPHEREGRID_TRUENEWNODE_HOOK_V6_DRAFT_2026-06-18.md`; handoff `docs/ai/SESSION_HANDOFF_Jarvis-MAGIC_2026-06-18_0154.md`. **Próximo gate:** Sprint A.5 — IDA allocator `dword_2305834` (`sub_A44D30`/`sub_A44EF0`). [anterior: `v2.140.0.6`]
- **`v2.140.0.6` — 스피어 그리드 스퀘어 모드: 오프라인 재작성(핸도프) 전체 계획. **Lane **Jarvis-MAGIC**. **REVISION**. 문서 `docs/reverse/FFX_SPHEREGRID_SQUARE_MODE_FULL_REAUTHOR_PLAN_2026-06-18.md`: Square 스타일의 데이터 흐름(Save당 dat0X+dat1X 한 쌍 완성), True New Node 달성, 다음 에이전트를 위한 editor/hook/RT2/deploy 단계. [이전: `v2.140.0.5`]
- **`v2.140.0.5` — Sphere Grid TRUE NEW NODE hook v5: 라이브 포인터를 통한 메뉴 상태. ** Lane **Jarvis-MAGIC**. **PATCH**. v4 패치 `g_AbmapMenuState` 정적 (`0x6A3704`, IDA에서 xref 0개); v5는 참조 해제합니다 `dword_2305834` (`0x2305834`) exe 파일이 다음과 같이 하는 것처럼 `A49590/A5BB70`. RT2 진입/출구 필수. [이전: `v2.140.0.4`]
- **`v2.140.0.4` — Sphere Grid TRUE NEW NODE hook v4: 비활성 신규 노드에 대한 패치 메뉴 기록을 추가합니다.** Lane **Jarvis-MAGIC**. **PATCH**. `A49590` 노드의 메뉴 레코드가 ≠일 때만 state를 적용합니다. `0xFFFF`; hook v4 초기화 `g_FFX_AbmapMenuState+0x808` apply/save/recompute를 실행하기 전 새로운 슬롯에 대해; 다음 내용을 포함한 매니페스트 `link state=0` (게임 내에서 활성화할 때까지 비활성화됨). **비활성화된** 노드가 있는 RT2 진입/이탈은 여전히 필수입니다. [이전: `v2.140.0.3`]
- **`v2.140.0.3` — Sphere Grid TRUE NEW NODE hook v3: 전체 파이프라인 + 이중 적용.** Lane **Jarvis-MAGIC**. **PATCH**. `SphereGridTrueNewNodeHook` 이제 방향을 틀다 `A45570` (레이아웃), `A47210` (기본 상태 병합), `A5B140` (인접성), `A54860` (재계산) 외에도 `A53DE0/A49590/A5BB70`; 새로운 슬롯의 시드 값 (`>= seeded count`), 다음에서 이중 적용 `A49590`, manifest와 함께 `link state=1` 그리고 LAB 배너는 정직하게. RT2 진입/출구는 여전히 필수입니다. [이전: `v2.140.0.2`]
- **`v2.140.0.1` — 스피어 그리드: 누락된 후크 + Unknown6 가드 + 스피어 패널 + 커널 클론 재로딩.** Lane **Jarvis-MAGIC**. **PATCH**. 배포 `SphereGridTrueNewNodeHook` + `GridTeachHook` (누락된 출처 vs `v2.139.0.0`), `Unknown6` ABMAP 버킷 재계산/검증 + Safe Transplant 대 True New Node LAB, `SphereGridNodeSphereRequirement` 

+ ‘Panel’ 탭, `Ability_Command.CloneDeep` + clone/delete 명령어에서 그래프 재로드; 문서 RE Unknown6/L3/런타임 상태 테이블. RT2 True New Node **아직 미처리**. [이전: `v2.140.0.0`]
- **`v2.140.0.0` — Arena+ 커스텀 믹스 2단계: 체크리스트 F7 + 게임 내 작곡.** 레인 **Jarvis-ARENA**. **MINOR**. 커스텀 믹스 x3/x4/x5 실행 시 기본 피커 열기 (8 틱, Magus +3) → 하위 프로세스 `ArenaMultiBossLab.exe --compose` → 발사체; `--compose` CLI + 전용 통신사 `mcyt00_22`/`nagi05_23`/`nagi05_22`; Duo–Specials 프리셋은 그대로 유지. 설정 `arena_plus_compose_vanilla_btl.txt`. 문서 `FFX_ARENA_PLUS_COMPOSE_PHASE1/2_2026-06-16.md`. [이전: `v2.139.1.1`]
- **`v2.139.1.1` — Field Explorer: walk publish refresh + 드래그 가능한 오버레이 + MapViewer에서 NPC 병합.** Lane **Jarvis-FIELD-RE**. **PATCH**. `--field-explorer-refresh-walk` + `publish-scout-to-editor.ps1` 재생하다 `field-encounters.json` btl.bin 그룹을 삭제하지 않음; Field Explorer 패널 드래그 가능; WalkManifest의 샤드 처리 기능이 더욱 견고해짐; Field Scout는 전투 중에도 안전하게 작동(quiesce + deferred heavy hooks). 50개 필드 워킹 번들 (세션 2026-06-17). [이전: `v2.139.1.0`]
- **`v2.139.1.0` — SIN Possessed 오프너: 1턴 가드 + 후크 초기값 (RT2 m019).** 레인 **Jarvis-MAGIC**. **PATCH**. `BuildFirstTurnGuard` (TurnsTaken&lt;2); 항목 `0` usa guard always-true; 기본 파일럿 `--clear-forced-action` + hook init; `--on-turn`/`--battle-start`. [이전: `v2.139.0.0`]
- **`v2.139.0.0` — Sphere Grid TRUE NEW NODE LAB: 매니페스트 편집기 + 런타임 상태 컴파일러 후크. **Lane **Jarvis-MAGIC**. **MINOR**. 빌더에 시드된 그리드에 추가하기 위한 옵트인 **TRUE NEW NODE LAB** 기능이 추가되었으며, 기록됩니다. `dat02/dat10` + `modules/config/true_new_node_manifest.csv` + `true_new_node.flag`; `FfxHooksDll` 이긴다 `SphereGridTrueNewNodeHook` 매니페스트를 읽고 이를 준수하는 `g_FFX_SphereGridRuntimeStateTable` (`word_112EC7C`) 새로운 노드/링크에 대한 일관된 처리 방식. **필수 RT2 미완료 사항:** Safe Product로 승격하기 전에 Sphere Grid에 충돌 없이 진입/이탈할 수 있어야 함. [이전: `v2.138.4.2`]
- **`v2.138.4.2` — SIN Possessed 오프너: 가드 TurnsTaken + RET (바닐라 블리자라의 폴스루 방지).** 레인 **Jarvis-MAGIC**. **패치**. `performCommand` m166; `stopAfterAction`; p

RT2 m019 조사 기록. [이전: `v2.138.4.1`]
- **`v2.138.4.1` — SIN Possessed 오프너: 확장 후 진입점 재지정 수정 (onTurn이 실제로 블록을 실행함).** Lane **Jarvis-MAGIC**. **PATCH**. [이전: `v2.138.4.0`]
- **`v2.138.4.0` — SIN ‘Possessed’ 오프너: 1턴에 “Yu Yevon에게 홀렸다!” (베이크 + 파일럿 CLI).** 레인 **Jarvis-MAGIC**. **MINOR**. `SinPossessedOpener` (monmagic2 `0x60E7`–`0x60EE`, m166 표준 `performCommand` Self); `--sin-possessed-scan` / `--sin-possessed-pilot`; 굽기 `--possessed-opener`; 게이트 모드 무시 `payload-candidate` 저작 과정에서. [이전: `v2.138.3.0`]
- **`v2.138.3.0` — Monster AI: SIN 갤러리 v2 (실제 유닛 8개; UI에서 일반 프로토타입 100개 제거).** Lane **Jarvis-MAGIC**. **PATCH**. `AiSinPresetCatalog` 이거 한번 읽어봐 `universal.csv`/`boss-presets.csv`; CSV를 출력창에 복사함; Monster AI 갤러리 업데이트됨. [이전: `v2.138.2.0`]
- **`v2.138.2.0` — SIN UNI-005..008: 마칼라니아 프리셋 (듀얼 아이스/워터, 프론트 워테라, 큐어, 화이트 윈드).** 레인 **자비스-MAGIC**. **MINOR**. [이전: `v2.138.1.0`]
- **`v2.138.0.0` — SIN 카탈로그 v2 처음부터 만들기: CSV + boss-bindings; 베이킹 준비 완료된 4개 코어.** Lane **Jarvis-MAGIC**. **MINOR**. [이전: `v2.137.1.0`]
- **`v2.137.0.1` — Field Scout MAX: Opus 코드 검토 (P0/P1/P2 + RE 감사 결과 검증됨) `.i64`).** Lane **Jarvis-FIELD-RE**. **REVISION** (등록 문서; 작성자/행동 없음). `docs/ai/REVIEW_RESULT_FIELD_SCOUT_MAX_v2.137.0.0_Jarvis-FIELD-RE.md`: 조건부 OK 판정 (lab/read-only); **1 P0** (잠금 없는 중복 제거 저장 → race/TOCTOU 힙 오버플로우 발생) `FieldScoutHook.cpp:1055-1074`); P1 (UAF 분해; `max_warp` 너무 넓은 도로 `sub_870AC0` (어떤 액터든 위치를 재설정); P2 (타카라가 플레이어의 좌표를 기록하고, 이중 쓰기 `RecordMaxZoneSlot`, 게이트 `groupByte>0` 0구역 제외, PS `+=` O(n²)); **RE 감사:** 디컴파일된 MAX 함수 4개 (`sub_798FE0`/`sub_870AC0`/`sub_875BA0`/`sub_85A740`) — **바이트 단위로 확인된** RVAs/ABIs, 오류 없음; RT2 갭(coords golden field, obtainTreasure 커버리지, shift17↔btl 그룹)으로 인해 출력이 중단됨 `lab` 에서 `PORT_STATUS`. [이전: `v2.137.0.0`]
- **`v2.137.0.0` — 필드 스카우트 MAX 모드: RE 후크 (타카라/워프/존) + NPC/트리거 오버레이 + RE 아틀라스.** Lan

그리고 **Jarvis-FIELD-RE**. **MINOR**. `field_scout_max.flag` (게이트: 헤비+울트라+맥스); 스카우트 v8: 후크 `sub_798FE0` 타카라, `FFX_Field_WarpActorToPosition`, `FFX_Field_SampleEncounterZoneSlot`; `sceneGroup` @ scene+0x10; 인제스트 `max-events.json`; WalkManifest `npcSpawns`/`triggerSpawns`; MapViewer의 파란색/청록색 마커. 문서 `docs/ai/FIELD_SCOUT_MAX_MODE.md`, **`docs/reverse/FFX_FIELD_SCOUT_RE_ADDRESS_ATLAS_2026-06-17.md`** (RVA/출처/공식), Opus 리뷰 프롬프트. [이전: `v2.136.0.0`]
- **`v2.136.0.0` — 필드 스카우트 ULTRA HEAVY: 카테고리별 세부 플래그 (마스터 + 헤비 게이트).** 레인 **Jarvis-FIELD-RE**. **MINOR**. `field_scout_ultra.flag` + 5개의 하위 플래그 (`field_logic`, `collision`, `encounters`, `scene_env`, `pipeline`); scout v7: `npc_spawn`, `trigger_spawn`, `ultra_*` 정직한 샘플/스텁; 2M 중복 제거; `deploy-field-scout.ps1 -Ultra`. Doc `docs/ai/FIELD_SCOUT_ULTRA_HEAVY_MODE.md`. [이전: `v2.135.0.0`]
- **`v2.135.0.0` — Field Scout + Aurora: 상자(bauro/chest) 획득 및 지도 오버레이. **레인** Jarvis-FIELD-RE**. **MINOR**. Field Scout v6 (`chest_spawn` via scene node/CHR `bauro*` + `area`/`field` (매니페스트 내); ingest `chest-spawns.json`; WalkManifest 샤드; Aurora Field Explorer + MapViewer는 위험 구역(mapout.vpa) 근처에 금색 마커를 표시합니다. [이전: `v2.134.5.0`]
- **`v2.134.5.0` — Field Scout 배포 파이프라인: lab work/ → WalkManifest 편집기 (릴리스 번들).** Lane **Jarvis-FIELD-RE**. **PATCH**. `publish-scout-to-editor.ps1`; `WalkManifest/` + “밟힌” 상태의 Field Explorer 배지; `work/`/`fields/`/`public/maps/` gitignored; csproj CopyToOutputDirectory. [이전: `v2.134.4.0`]
- **`v2.134.4.0` — Field Scout HEAVY v5: Phyre 메쉬의 월드 위치 + CHR 스폰 지점. **레인** Jarvis-FIELD-RE**. **패치**. `scene_node_placed` (wx/wy/wz 출처: `Phyre_PSceneNode_composeWorldMatrix` + 노드 훅 설정), `chr_spawn` (ActiveChrInstance 스캔 + `SetWorldPosition`); 섭취 `scene-nodes-world.json` + `chr-spawns.json`. [이전: `v2.134.3.0`]
- **`v2.134.3.0` — Field Scout HEAVY: 공격적인 캡처 + 오프라인 텍스처 변환 파이프라인.** Lane **Jarvis-FIELD-RE**. **PATCH**. `field_scout_heavy.flag`: 중복 제거 **1M**, thread player-trace 1.5s, polyMeta/sh

textures의 ift17, encounter/zone 후크, 모든 scene 노드, 별도의 JSONL 추적; `install-field-scout-tools.ps1` (texconv), `extract-scout-textures.ps1`, 기본값을 강하게 적용합니다. [이전: `v2.134.2.0`]
- **`v2.134.2.0` — Field Scout v3 world_walk: 전체 워크스루를 위한 최대 캡처. **Lane **Jarvis-FIELD-RE**. **PATCH**. **250k** 힙 중복 제거; 추가 후크 `GetInstanceNameByIndex` → `scene_node`; `LoadAndActivateDriver` PS3Data 전체를 로가; `field_load` 합성 팩을 발행합니다 (`geometry_inferred`); 경로 미지정 `map/area/field`; 섭취 `walk-field-catalog.json` + `deploy-field-scout.ps1`. [이전: `v2.134.1.0`]
- **`v2.134.1.0` — Field Scout v2: 3D 지오메트리 후크 (필드 로드 + .dae.phyre).** Lane **Jarvis-FIELD-RE**. **PATCH**. `graphicFieldMapLoad` + `LoadAndActivateDriver` → manifest `field_load` / `geometry` 플레이어 앵커 포함; 인제스트 스크립트 업데이트됨. [이전: `v2.134.0.0`]
- **`v2.134.0.0` — 필드 스카우트: 이동 중 JSONL 매니페스트 (텍스처 + 플레이어 앵커 + 발견된 필드).** 레인 **Jarvis-FIELD-RE**. **MINOR**. `FieldScoutHook` 에서 `ffx-hooks.dll` (`field_scout.flag`): 최대 65k 개의 에셋 중복 제거, 저장 `modules/field-scout/session-*.jsonl` path/cat/field/tile/px/py/pz/sceneId 포함; 인제스트 `RuntimeTools/FieldScoutLab/process-scout-session.ps1` → 보고서 + PhyreMapExportLab 대기열. Doc `docs/reverse/FFX_FIELD_SCOUT_WALK_MANIFEST_2026-06-17.md`. [이전: `v2.133.0.0`]
- **`v2.133.0.0` — 스피어 그리드 패널 + 익스플로러: “필요한 스피어” 드롭다운 메뉴가 고정됨 `NodeEffectBitfield` + `AppearanceType`.** Lane **Jarvis-MAGIC**. **MINOR**. 파워 / 마나 / 속도 / 능력 / 키 레벨 1–4 (+ 사용자 정의) 프리셋 via `SphereGridNodeSphereRequirement`; `WriteNodeTypes` 두 필드가 그대로 유지됩니다(이전에는 항상 원본에서 상속받았습니다). **Panel** 탭과 **Explorer → Node Types**에 콤보 박스가 추가되었으며, Panel 목록에는 추론된 영역이 표시됩니다. “Key NV3” 작성 방식과 스킬 교육 간의 문제를 수정했습니다 (`0x0400`). **RT2 미완료:** 96 이상 클론에 Ability Sphere를 기록하고 게임 내 비용을 확인해야 함. 파일: `FfxLib/SphereGrid/SphereGridNodeSphereRequirement.cs`, `SphereGrid_File.Write.cs`, `Modules/SphereGridPanel/*`, `Modules/SphereGridExplorer/*`. [이전: `v2.132.0.0`]
- **`v2.132.0.0` — 스피어 그리드 빌더: 채우기

r `panel.bin` ~부터 `command.bin` + 스킬 선택기 + CLI 키마리 론소 파스.** 레인 **자비스-MAGIC**. **MINOR**. `SphereGridPanelGrowWriter` appenda 노드 유형을 `panel.bin` (jp+us) 스킬 템플릿 복제 (`LearnedMove = 0x3000|id`); Builder에 **command.bin** 드롭다운, **인기 패널 (≥96)** 버튼, **적용** 시 자동 확장 기능이 추가됨; JP 인코더 수정 (ASCII로 변환되지 않음) `"Learn …"` (일본어 버전). CLI `--kimahri-ronso-parse [command.bin]` OD Ronso 통계 덤프 (104–115, Lancet, 오프너 282). **RT2 대기 중:** 게임 내에서 클론 스킬 ≥96을 가르칩니다. 파일: `FfxLib/SphereGrid/SphereGridPanelGrowWriter.cs`, `SphereGrid_File.Write.cs`, `Modules/SphereGridBuilder/*`, `Tools/KimahriRonsoParseRt0.cs`, `Program.cs`. [이전: `v2.131.0.0`]
- **`v2.131.0.0` — 커널 명령어: 행 복제/삭제/추가 + 내장 텍스트 풀에서 이름/설명 편집 가능. ** Lane **Jarvis-MAGIC**. **MINOR**. `KernelCommandListMutator` (append/clone/delete in `command.bin` + `monmagic*.bin`); 목록 내의 **복제 / 삭제 / 추가** 버튼 (Monster Commands 1/2와 호환); **Name** + **Description**을 편집할 수 있는 **Identity** 패널 (`DisplayName`/`DisplayDescription` → `NameScriptBytes`/`DescriptionScriptBytes`, **Save**를 통한 왕복 경로 via `Ability_Command.WriteList`). 에디터에서 ‘Path 4’ 작성 잠금 해제 (예: **#320** 클론의 이름을 **Blue Magic**으로 변경, 16진수 표기 제외). **RT2 미처리:** 게임 내 저장 + 불러오기 + 전투 메뉴에서 이름/설명 확인. 파일: `FfxLib/Ability/KernelCommandListMutator.cs` (새), `Modules/BattleKernel/Commands/KernelCommands_*.{axaml,cs}`, `FFXProjectEditor.csproj`, 변경 내역. [이전: `v2.130.3.8`]
- **`v2.130.3.8` — Spira Reforge: 1차 바닐라 공격형 재조정 확정 — 16개 스킬 공격력 버프 + 자동 능력 정리 + MP 스피어 상향.** 레인 **Jarvis-MAGIC**. **검토** (디자인 및 Halyson이 확정된 결정 사항만 포함; 이번 패스에서는 작가 관련 내용이나 행동 방식은 없음). Halyson이 열었습니다 `FFX_PLAYER_COMMAND_CATALOG_0_TO_95_2026-06-16.md` 그리고 이렇게 일침을 가했다: *"마법은 치유까지 포함해 제 역할을 다한다. 하지만 나머지는? 한심하기 짝이 없다. 풀 브레이크? 엿이나 먹어라. 거의 적중도 안 할 뿐만 아니라, MP 99를 소모하고도 주는 데미지는 터무니없다."* 냉정한 진단: `Pow`가 적용된 기본 공격 스킬 20개

er = 16` (= multiplier 1.0× = Attack base) ou `전력 < 16` (= **pior que Attack**); Auron Full Break Power 16 / Acc 36 / MP 99 = crime contra o jogador. **Pacote final cravado (3 frentes em 1 pass):** **(1) Damage buff de 16 skills (Extracts removed):** Wakka 8 status-riders (Sleep/Silence/Dark Attack P16→20 Acc 50→60, Zombie Attack P16→24 Acc 50→60, Busters P16→26 Acc 100, Triple Foul P16→32 Acc 100→90 MP 24→28), Auron 4 Breaks (Power/Magic Break P16→22 Acc 50→80 MP 8→10, Armor/Mental Break P16→24 Acc 36→70 MP 12→14), **Full Break P16→48 (3× damage cravado Halyson) Acc 36→90 MP 99→75**, Tidus 2 Delays (Delay Attack P12→18 MP 5→6, Delay Buster P14→22 MP 10→12), Rikku Mug P16→20. Filosofia: Power ≥ 18 sempre quando skill paga MP; premium MP ⇒ premium Power; Breaks Acc 36-50% sobem 65-90%. **(2) Auto-Ability cleanup:** Slot 12 Half MP Cost **MANTÉM** (justificativa Halyson: Lulu Magic Booster + custos altos = ainda paga Ether/Elixir = balance natural). Slot 13 (ex-One MP Cost, cheese de 1 MP universal) **REMOVIDO → vira Mana Spring** (+5 MP/turno em batalha; regen tick passivo; substitui economia sem virar cheese — em battle de 10 turnos = +50 MP cumulativo). Slot 23 (ex-Break HP Limit) **vira "Break Limits"** (bits `0x0200 | 0x0400` OR em `ability_flags_64`, HP cap + MP cap juntos via engine vanilla; byte-edit puro, zero hook); §10.8 do VISION cravado. Slot 24 (ex-Break MP Limit) **vira "Devil's Bargain"** (+50% dano dado / +50% dano recebido — glass cannon switch simétrico; 2-pass: Pass 1 placeholder funcional agora com bit reassignment, Pass 2 hook damage calc depois com RT2). **(3) MP Sphere node bump (escopo B cravado Halyson "B simplesmente B"):** Standard Grid MP +40 → +60, Expert Grid MP +20 → +30 (escala proporcional 1.5× cross-grid). Edit trivial via `SphereGridNodeTypeEntry.IncreaseAmount` (offset 0x14, ushort) em `SphereGrid_File.cs:519`. **이번 세션에서 확정된 결정 사항:** (a) Halyson이 카탈로그를 열어 문제를 파악함; (b) 20개 스킬 + 4개 자동 능력 카테고리에 대한 버프 표를 제안함; (c) Halyson이 Extracts 제외 + Full Break 3회 적용을 확정; (d) MP 1 제거 + 마나 실드 미적용(새로운 메타 생성)을 확정; (e) §10.8을 확인하며 슬롯 23을 Br로 반전

eak Limits와 슬롯 24가 repurpose("xereca")로 변경됨; (f) Devil's Bargain 슬롯 24를 확정하고 2-pass 관련 주의사항을 이해함; (g) 슬롯 13의 Mana Spring과 Spell Spring 백로그를 다듬음. **분류된 기술적 주의사항:** Devil's Bargain은 후크 데미지 계산 + RE 주소가 필요합니다. `FFX_DamageCalc_*` 보류 중; Mana Spring은 턴 시작 시 발동 + 빈 슬롯 확인이 필요합니다. `ability_flags_64`; 공격 명중률 vs 상태 효과 라이더 명중률 스파이크 미적용 RT2; 트리플 파울 명중률 100→90 스파이크 미적용 (“트리플 보증” 유효, 깨지지 않음); 후반전 풀 브레이크 MP 스케일링 OK (하프 MP 기준 75는 여전히 매우 비쌈); 자동 능력 비트 재할당 슬롯 24는 빈 스캔 플래그가 필요한 `AutoAbilityHardcodedFlagCatalog.cs`. **1단계 기술 계획 (순수 바이트 편집) `v2.131.x` PATCH):** 1.1 `command.bin` 16 스킬 공격력 버프, 1.2 슬롯 23 ‘한계 돌파’, 1.3 슬롯 13 ‘마나 샘’ 자리 표시자, 1.4 슬롯 24 ‘악마와의 거래’ 자리 표시자, 1.5 `panel.bin` MP 노드, 1.6 텍스트 풀, 1.7 RT0/RT1 게이트 바이트 정체성, 1.8 RT2 파일럿. **2단계 (후크 LAB `v2.133.x+`):** 2.1 RE 피해 계산, 2.2 마나 스프링 턴-틱 훅, 2.3 데빌스 바겐 피해 훅, 2.4 RT2 훅. **VISION과의 시너지:** §10.4 QH 너프 (보완 — 스킬 버프 + QH 너프 = 다각화된 공격), §10.5 마법 (변경 없음, 다음 패치), §10.6 OD 루루의 분노 (다음 패치), §10.8 브레이크 HP+MP 소모 (이번 패치 1.2에 확정), §10.9 오론의 비밀 스킬 (강화 — 브레이크 리미트 + 데빌스 바겐 + 브레이크 버프 = “죽일 수 없는 모험가 오론”), §10.10 마법 속도 (Spell Spring 백로그), §10.11/§10.13 (다음 패스), 경로 4 Black Magic Extended (간접적 — 베이스라인 바닐라가 ≥96개의 주문에 대한 맥락을 조성함). **미해결 과제 백로그:** Spell Spring은 다음 빈 슬롯을 기다림 (희생 후보: 슬롯 18 Double AP, 19 Triple AP, 21 Pickpocket, 22 Master Thief — 진행/전리품 치트); 캐릭터별 향후 정체성을 위한 Status/Break Sharpness §10.9. **건드리지 말 것:** 작가 측(writer-side)의 writer/hook/probe/DLL/csproj. 파일: `FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.7` → `v2.130.3.8`); `docs/reverse/FFX_SPIRA_REFORGE_VANILLA_OFFENSIVE_REBALANCE_2026-06-16.md` (신규, 약 280줄, 7개 절: §0 짧은 진실, §1 바닐라 대학살 진단, §2 통합 패키지 c

표 16: 스킬 + 자동 능력 정리 + MP 스피어, §3 기술적 주의사항 6가지, §4 구현 계획 1단계+2단계, §5 미해결 문제, §6 제출 버전, §7 관련 참고 문헌); `CHANGELOG.md` + `changelogUS.md` + `docs/governance/VERSIONING.md` + `docs/ai/SESSION_HANDOFF.md` + `mods/Spira Reforge/VISION_AND_ROADMAP.md` (다음 단계). [이전: `v2.130.3.7` [참조 카탈로그]
- **`v2.130.3.7` — 참고 문서: 96가지 캐릭터 능력 통합 목록 (ID `0..95`)와 함께 `Power`/`MP`/`Formula`/`Acc`/`Hits`/요소/효과 + AbiMap 아키텍처 × 파티 전체 은행.** Lane **Jarvis-MAGIC**. **REVISION** (등록 문서 / 참조 카탈로그; 작성자/행동/RT2 없음; 이미 여러 곳에 흩어져 있는 지식을 하나의 문서로 통합함) `FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` + `FFX_SPELL_LEARN_ABIMAP_INFERNO_2026-06-15.md` + `FFX_BATTLE_COMMAND_MENU_INFERNO_2026-06-15.md` + `CommandCharacter_Dictionary.cs` + `Ability_Command.cs`). Halyson이 모드의 운영 참고 자료로 MD에 있는 96가지 스킬 표를 요청했습니다. 새로운 문서 `docs/reverse/FFX_PLAYER_COMMAND_CATALOG_0_TO_95_2026-06-16.md` (8개 섹션, 약 250줄): §0 TL;DR 95에서 한계치 달성 (물리적 96비트 AbiMap) + 교차 RE 검증; §1 엔진이 메뉴를 결정하는 방식 (`FFX_Btl_IsCommandAvailable @ 0x39BB70` per-char 대 party-wide (com) `CharacterUser` filter); §2 인코딩 `LearnedMove = 0x3000 | id` ~의 `panel.bin` (참조 `SphereGridExplorer_DataModel.cs:30-31`); §3 0..95까지의 전체 카탈로그를 9개 그룹으로 나눈 것 (코어/메뉴 0-5, 스킬 6-21, 스페셜 22-25, 치어 26-31, 키마리/방어/소셜 32-42, **화이트 매직 43-64**, **블랙 매직 65-83**, 에온 메뉴 84-87, 리쿠 엔드게임 88-95)로 나뉘며, FFX HD 리마스터(미국/일본)의 정식 값을 적용 — MP/파워/포뮬러/정확도/타격 횟수/속성/효과; §4 3가지 플래그를 통한 “what the magic IS”의 결정적 시나리오 (`DamageFlags` + `DamageFormula_Enum` + `PreviewFlags`) 치유/부활/정화/물리/마법/상태/버프/중력/흡수 스킬 테이블 포함; §5 그리드를 통해 배울 수 없는 11개의 ID (`missing=[0,1,2,3,4,5,33,84,85,86,87]` 10개 지역 전체 — system/Defend/Aeon/Yojimbo); §6 파티 전체에 적용되는 ID 96+ (오버드라이브, 에온, 모테, 믹스, 의사 AI) 및 분리 설계의 3가지 이유; §7 스피라 리포지와 ‘카민’의 연계에 따른 결과

제4항 `v2.130.3.6`; §8 상호 참조. **해당되지 않음:** writer/hook/probe/DLL/gate. 파일: `FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.6` → `v2.130.3.7`), `docs/reverse/FFX_PLAYER_COMMAND_CATALOG_0_TO_95_2026-06-16.md` (새), `CHANGELOG.md` + `changelogUS.md` + `docs/governance/VERSIONING.md` + `docs/ai/SESSION_HANDOFF.md`. [이전: `v2.130.3.6`]
- **`v2.130.3.6` — Spira Reforge: REALITY CHECK + 3번의 반전 — 경로 4 (`CharacterUser` (내재) 고정 + 스피어 그리드를 통한 습득 가능 고정. 할리슨은 내가 보지 못한 것을 알아차렸다.** 레인 **자비스-MAGIC**. **REVISION** (지난주 목요일, 2026-06-16, 계속) `v2.130.3.3`; 라이터/비헤이비어 없음). 이번 세션의 아키텍처 반복 순서: **(1) v2.130.3.2 pivot:** RE D01을 발견했는데, ids `0..95` 아마 원주민일 텐데, “후크 0개 + 남은 슬롯 62개”로 표시해 두었습니다. **(2) Halyson이 열었습니다 `FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` 그리고 “무슨 말이에요?”라고 물었다:** 2026년 6월 12일자 감사 결과에서 이미 입증되었다 `0/96` 무료 슬롯 — 96개의 ID가 모두 바닐라로 채워져 있습니다. 제가 “62개 남았다”고 말한 것은 **거짓**이었습니다. **(3) v2.130.3.4 방법 3:** append를 제안했습니다 `≥96` + 캐릭터별 후크 화이트리스트 (Nul Ward 스타일의 일반화된 방식), Halyson이 승인했습니다. **(4) Halyson이 제4의 방법을 제안했습니다:** *"CommandBin에서 스킬의 CHARACTER USE(예: TIDUS)를 선택하기만 하면 문제가 해결되지 않을까요? 훅 같은 건 전혀 필요 없을 텐데요"*. **저는 기본 필드를 미처 확인하지 못했습니다** `[Data] public Character_Enum CharacterUser` 에서 `Ability_Command.cs:29`** — 부호 있는 바이트 번호 `command.bin` 각 명령어를 사용할 수 있는 사용자를 제한합니다. 바이트 단위의 정확한 출력: `FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` 86번째 줄에서 Yojimbo Dismiss(id 87)를 인용하고 있으며 `CharacterUser=0x0E` (14=Yojimbo) — 기본 엔진이 이 필드를 기준으로 메뉴를 자동으로 필터링합니다. 기존 UI (`KernelCommands_Control.axaml:434` ComboBox). **방법 4는 1/2/3을 대체합니다** — append `≥96` ~와 함께 `CharacterUser` UI 편집기를 통해 직접 설정된 캐릭터당. 메뉴 필터용 후크는 전혀 없음. **(5) Halyson이 다음과 같이 밝혔다: "스킬은 스피어 그리드를 통해 습득할 수 있다"** — 이로 인해 Nul Ward §H의 ID 관련 주의사항이 다시 적용된다 `≥96` (파티 전체 재로드(reload-by-init)가 grant grid를 덮어씁니다). 해결책: `NulWardTe`를 확장하는 **1개의 범용 훅**

achHook.cpp` (já provado em `v2.130.2.0`) — (a) detour `PrepareSaveCommandState` re-asserta bits ≥96 lendo sidecar; (b) detour panel_teach escreve sidecar quando node ativa. Net hook count: 1 (generalização, não hook novo). Sidecar JSON extends `spira-reforge-flags.schema.json` do Capture Cascade. **Plano técnico atualizado (15 bloqueios honestos catalogados):** Fase 0 ✅ → Fase A append `command.bin` ≥96 com `CharacterUser` (A.1-A.7 por pool char) → Fase B sidecar schema → Fase C Sphere Grid editor scope expansion (`LearnedMove = 0x3000 | id≥96`) → Fase D hook generalizado → Fase E RT0/RT1 writer LAB → Fase F RT2 in-game piloto → Fase G Lulu Fury rows → Fase H `-ja` backlog v0.7+. **Bloqueios pequenos pendentes (spikes):** addr panel_teach runtime, sidecar JSON schema design, side-effects `CharacterUser` filter (Trio of 9999, Doublecast cross-char), Multi-Firaga random-hit field, steal-per-hit Mugra/Mugga, Wakka status-rider per hit, Tidus self-buff stacking, Auron Sentinel++ party-wide buff. **Vantagens Caminho 4 vs alternativas:** (a) zero sacrifício vanilla (coexistência total Firaga + Multi-Firaga, Demi + Demita, Mug + Mugra/Mugga, Sentinel + Sentinel++); (b) net 1 hook (vs 0 do pivot falso, vs 2-3 do Caminho 3); (c) infra ALREADY EXISTING (NulWardTeach hook + sidecar Capture Cascade + editor UI ComboBox); (d) identity vanilla intocada. **Lição honesta documentada:** "sempre que sentir 'zero hook' soando bom demais, abrir os audits existentes antes de propagar a narrativa". **Doc atualizado:** §0 verdade curta (3 reversões + 4ª decisão grid), §1 ownership model (Caminho 4 + grid teach), §7.2 plano técnico (Fases 0-H), §7.3 15 bloqueios honestos, §10 entries `v2.130.3.5` e `v2.130.3.6`. **Não toca:** writer/hook/probe/DLL. Arquivos: `FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.3` → `v2.130.3.6`, pulou `.4`/`.5` por terem sido reversões dentro da mesma sessão de design), `docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` (§0/§1/§7.2/§7.3/§10 reescritos), `CHANGELOG.md` + `changelogUS.md` + `docs/governance/VERSIONING.md` + `docs/ai/SESSION_HANDOFF.md`. [anterior: `v2.130.3.3`]
- **`v2.130.3.3` — 스피라 리포지: 0단계 완료

A — Halyson은 캐릭터당 TBD 풀을 단 한 번에 모두 클리어했습니다(데미타→키마리, 와카 5개 주문, 오론 MAX 팩 6개 주문, 티더스 멀티 히트 + 자기 버프, 리쿠 +1 신규 도적 스킬).** 레인 **Jarvis-MAGIC**. **수정** (2026-06-16일 세 번째 진행, 바로 이어짐) `v2.130.3.2`; 작가/행동 없음). **4개의 추가 결정 (9개 → 13개):** (1) **오너 교체 = 키마리** (기믹 “기괴한 몬스터” + 블루 메이지 테마; 루루가 엘리멘탈 버스트에 집중할 수 있게 함); (2) **와카 풀 = A+B 조합, 5개 주문** — 비오라 (AoE 독 + 대미지) + 슬립라 (AoE 수면) + 쿼드 폴 (AoE 트리플 폴 + 독 = 4가지 상태 이상) + 더블 버스터 (2회 타격 단일, 2가지 상태 이상 콤보 RNG) + 타이드 슬래시 (2회 타격 물리) — “상태 이상 마스터 + 더블 히트 + 기상천외한 기술들”; (3) **아우론 풀 = MAX 팩, 6개 스킬** — 매스 파워 브레이크 + 매스 아머 브레이크 + 매스 매직 브레이크 + 매스 멘탈 브레이크 + **센티넬++** (센티넬 + 물리·마법 방어 차단 + 파티 전체 1턴) + **프로보크** (프로보크 + 자동 센티넬 + 모든 적 도발) — *"아우론은 이 게임의 진짜 탱커다"*; (4) **티더스 방향 = 다중 타격 + 자기 버프, 4~5개 주문** — 스파이럴 슬래시 (3타 단일, +5 STR/시전 상한 25) + 타이달 콤보 (4타 AoE, +5 AGI/시전, 상한 20) + 블레이드스톰 (5회 무작위 타격, +자신에게 속도 증가 1턴) + 아우록스 러시 (시그니처, +AGI 고정 + 속도 증가 3턴) + 선택 사항 치어 스트라이크 (2회 타격 + 자신에게 치어). *"티더스는 항상 가장 빠른 캐릭터였죠. 퀵 히트(Quick Hit)는 너프될 예정이니, 자신의 공격 속도를 높여주는 버프를 부여하는 다중 타격 스킬이 필요합니다"* — 퀵 히트 너프에 대한 직접적인 보상 §10.6; (5) **리쿠 +1 신규 도둑 스킬** — 할리슨이 스킬 풀을 완성하기 위해 “새로 고안된 도둑 스킬”을 요청함; 자비스의 제안: **슬라이트 오브 핸드** (고급화된 머그), **픽포켓** (턴 비용 없는 훔치기; 자비스 기본 설정), **Sticky Fingers** (시전당 +25% 스택), **Backstab** (PDEF 무시), **Cache** (직접 훔치기 풀), **Smoke Bomb** (파티 CTB 건너뛰기). **최종 배분 완료 (0단계):** 루루 6 + 유나 5 + 와카 5 + 리쿠 4 + 키마리 3 + 티더스 4-5 + 오론 6 = **96 슬롯 중 33-34개 주문 = ~35% 예산** (62+ 슬롯이 남음) `-ja` 백로그 v0.7+ + 화이트 매직 엑스트라). **캐릭터 간 콤보:** 오론의 매스 멘탈 브레이크 + 루루의 멀티 피라가 (MDEF 없는 웨이브 버스트); 오론의 센티넬++ + 유나의 P

rotectga/Shellga (2 턴 동안 거의 완전한 무적); 오론의 Provokeja + 와카의 Quad Foul (탱킹 + 대량 상태 이상); 티더스의 Bladestorm + 오론의 Mass Armor Break (티더스의 버스트 + 방어력 없는 대상). **티더스의 자가 버프로 인한 추가 위험:** 무한 STR/AGI 스택 = QH와 유사한 비정상적 상황; 스택 상한선(STR 5 / AGI 4)에 따른 완화 효과 + 전투 종료 시 감소(전투 간 지속되지 않음). **§9.2에 남아 있는 11개의 미해결 문제** — 모두 세부적인 결정 사항(리쿠의 도둑 스킬 최종 명칭, 티더스의 주문 4개 대 5개)이거나 **기술적 난제**(무작위 명중 멀티-피라가)입니다. `command.bin` 필드, 안타당 스틸(Mugra/Mugga), 안타당 와카 상태 효과, 티더스 자기 버프 중첩, 오론 센티넬++ 파티 전체 버프, 키마리 랜싯+ 지속 효과) — **전체적인 디자인을 차단하지는 않으며**, 특정 제작 단계를 차단합니다. 기부자 감사 `0..95` (§9.2 q18) 이제 구체적인 범위가 정해졌습니다: 약 33~34개의 슬롯이 필요합니다. **문서 업데이트:** §3.1.4 데미타 항목을 §3.5.1 키마히 항으로 이동; §3.3 와카 5개 주문 확정; §3.4 리쿠 +1 도적 스킬 (6가지 제안 포함); §3.5 키마히 풀 완성 (데미타 + 블루 메이지 확장 2-3); §3.6 티더스 풀 4-5 멀티히트 + QH 너프 대비 콤보 활용 셀프 버프; §3.7 오론 MAX 팩 6개 주문, 캐릭터 간 콤보 + 위험/완화; §3.8 총 요약: 33~34개 주문 = 예산의 35%; §9.1 13가지 결정; §9.2 11가지 하위 결정/스파이크; §10 항목 `v2.130.3.3`. **VISION §12 업데이트:** 캐릭터별 최종 분배 표 + 팝업 콤보. **변경 없음:** writer/hook/probe/DLL/gate. 파일: `FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.2` → `v2.130.3.3`), `docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` (§3.1.4 이동 + §3.3/§3.4/§3.5/§3.6/§3.7/§3.8/§9/§10 업데이트), `mods/Spira Reforge/VISION_AND_ROADMAP.md` (§12 당구대 최종 단계 + 콤보), `CHANGELOG.md` + `changelogUS.md` + `docs/governance/VERSIONING.md` + `docs/ai/SESSION_HANDOFF.md`. [이전: `v2.130.3.2`]
- **`v2.130.3.2` — Spira Reforge: 아키텍처 피벗 — “확장된 흑마법” 섹션이 “확장된 캐릭터별 명령”으로 명칭 변경됨 (RE D01 적용 + 적용 대상 7명 캐릭터로 확대).** 레인 **Jarvis-MAGIC**. **수정** (즉시 이어짐) `v2.130.3.1`; 작가/행동 없음). Halyson은 다음과 같이 제안했다: *"만약 이 스키 대신에

"‘누구나’ 획득할 수 있게 하려면, ‘특정 캐릭터 전용’으로 설정하지 말아야 하지 않을까?"* — 기존 RE와 비교해 보니, **바닐라 엔진이 이미 ID별로 캐릭터별 소유권을 기본적으로 지원하고 있다는 사실을 알게 되었다 `0..95`**. **중요한 발견 (RE D01 — `FFX_SPELL_LEARN_ABIMAP_INFERNO_2026-06-15.md`):** `FFX_GrantCommandToCharacter @ 0x785D10` **SPLIT AT INDEX 96**이 있습니다: ids `< 96` 은행에 가서 좀 이야기나 해 봐 `word_11307FC[74*char+3151+(id&0xFFF)/16]` (stride 74 단어 = `ply_save` 캐릭터별); ids `>= 96` FLAT 파티 전체 뱅크(스트라이드 없음)로 이동합니다. ⇒ **캐릭터당 학습 가능한 공간은 정확히 96비트이며, ID는 0~95입니다**. ID가 96 이상인 경우 캐릭터별로 학습할 수 없습니다. **시사점:** ID의 재할당 `0..95` = 바닐라 엔진은 **아무런 후크 없이** 각 주문을 누가 보는지 필터링합니다. 기존 방식(ID 96 이상 + Nul Ward 방식의 우회 경로를 통한 제한)은 배제되었습니다. **확장된 분배 (Halyson의 결정 2026-06-16, 인용문 원문 보존):** **루루** (6개 주문, 버스트 캐스터 + HP 흡수) — 멀티-피라가 계열 × 4 + 드레인가 + **오스모스-가 (유나에서 루루로 이동)**, 경우에 따라 데미타; **유나** (5개 주문, 화이트/버프 AoE) — 리플렉트가 + **프로텍트가** + **쉘트가** + 에수나가 + **디스펠트가** (“리플렉트가, 프로텍트가, 쉘트가, 에수나가, 디스펠트가는 유나에게 할당”); **리쿠** (마법 3개, 스틸 마스터) — **카피캣이 그녀만의 전용 스킬로 변경** + **무그라** (2회 타격 단일 대상, 2회 스틸) + **무그가** (AoE 2회 타격, 저피해, "최대 6회까지 스틸 가능!!!!"); **와카** (미정, “더 많은 상태 이상 스킬과 더 미친 것들”); **키마리** (미정, “블루 메이지. 몬스터 스킬은 물론 자신의 오버드라이버까지 마나를 사용해 익힐 수 있다" — 론소 마나 레인 담당); **티더스** (미정, "아이디어는 없지만, 어쩌면 멀티히트 스킬"); **아우론** (“이 게임의 빌어먹을 탱커. 센티넬의 진화형, 어쩌면 더 강력한 범위 브레이크”). **예상 총량: 96 슬롯 중 28~31개 주문 = ~30% 할당량**, 65개 이상의 슬롯이 남아서 `-ja` 백로그 v0.7+ + 향후 계획. **문서 §9.1에 확정된 결정 9건, §9.2** (오너 해임, Wakka/Tidus/Auron 풀, Rikku Copycat 대체, Sphere Grid 와이어, 기증자 0..95 감사, Multi-Firaga 무작위 명중 필드, 타격당 스틸 Mugra/Mugga, Kimahri Blue Mage 코디 Ronso 레인). **이 모델의 장점:** (a)

 제로 훅 커스텀 — 기본 엔진 그대로; (b) 스피어 그리드 트리가 실질적인 의미를 갖게 됨 (다른 트리로 이동 = 실질적인 트레이드오프); (c) 루루 퓨리가 대폭 간소화됨 — 퓨리 풀은 캐릭터별로 기본 설정되며, “퓨리에서 Multi-* 제외” 문제가 더 이상 발생하지 않음; (d) 캐치 캐스케이드 §11 및 SIN 모드 §10.13이 캐릭터별로 서로 다른 전술적 반응을 갖게 됨. **기술 계획 (§7.2):** 0단계: 풀 확정 (TBD) → A단계: 도너 감사 (시작 차단) → B단계: 캐릭터별 제작 (B. Lulu 파일럿, B.1 유나 화이트 AoE, B.2 리쿠 머그 패밀리 (타격당 스폿 스틸 포함), B.3 풀 (TBD)) → 단계 C/D: RT0/RT1/RT2 → 단계 E: 스피어 그리드 와이어 (스피라 그리드 에디터 확장) → 단계 F: 루루 퓨리 행 → 단계 G: 키마히 블루 메이지 (론소 레인에 따라 다름) → 단계 H: -ja 백로그 v0.7+. **VISION_AND_ROADMAP.md §12 재작성:** "확장된 흑마법" → "확장된 캐릭터별 명령어" + 캐릭터별 분배 표 + 차단 사항 + 업데이트된 로드맵. **문서명 개념적으로 변경** (이력 보전을 위해 파일 경로는 유지): `docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` — 11개 섹션, §1 디컴파일 RE D01 바이트 검증 기능이 내장된 캐릭터별 소유권 모델, §3 캐릭터별 배분 (3.1 루루, 3.2 유나, 3.3 와카 미정, 3.4 리쿠, 3.5 키마리 코디, 3.6 티더스 미정, 3.7 오론 미정, 3.8 요약). **다루지 않는 부분:** writer/hook/probe/DLL/gate. 설계 및 로드맵 통합만 다룸. 파일: `FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.1` → `v2.130.3.2`), `docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` (대대적인 수정: 새로운 §1 RE D01, §3 배포 항목 7자 확장, §5/§7/§8/§9/§10/§11 번호 재지정 및 업데이트), `mods/Spira Reforge/VISION_AND_ROADMAP.md` (§12 개정), `CHANGELOG.md` + `changelogUS.md` + `docs/governance/VERSIONING.md` + `docs/ai/SESSION_HANDOFF.md`. [이전: `v2.130.3.1`]
- **`v2.130.3.1` — 스피라 리포지: 확장된 흑마법 — 할리슨의 4가지 확고한 결정 (멀티-피라가 옵션 B, 대상당 드레인 최대치, 데미타와 데미의 공존, 미묘한 차이가 있는 올인클루시브 퓨리).** 레인 **자비스-MAGIC**. **수정** 후의 연쇄 반응`v2.130.3.0` (다른 병렬 Jarvis-MAGIC의 Ronso Mana 사소한 핫픽스). 다음 디자인 문서의 바로 이어지는 내용: `v2.130.2.1`: H와 함께하는 브레인스토밍

앨리슨이 미결 상태였던 마지막 4가지 결정을 확정지었다. **(1) 멀티-피라가 메커니즘 — 옵션 B (무작위 분배) + 기본 MP의 3~5배:** 할리슨: *"옵션 B, 하지만 '멀티 피라가', '멀티-포다세'는 이를 상쇄하기 위해 기본 스킬 MP의 3~5배가 들 거야. 진짜 엄청난 한 방이 될 거야"*. 메커니즘 = 1회 시전 → N회 타격 (5-7회), 각 타격은 무작위 적을 공격합니다 (홀리/코멧/더블캐스트 공식을 통한 엔진 기본 기능). 적들은 RNG에 따라 동일한 멀티-피라가로 1회, 2회, 3회 이상의 타격을 받을 수 있습니다. MP 소모 = 기본값의 4배 (멀티-피라가 = 64 MP), 멀티-울티마 = 200 MP. 자비스의 제안: 4배 MP + 6회 타격으로 시작하여 RT2에서 조정. **확장 가능한 계열** (점진적 출시): v0.5 멀티-피라가 + 멀티-블리자가, v0.6 + 멀티-썬더가 + 멀티-워터가, v0.7 + 멀티-울티마 (포스트-다크니스 §10.11), v0.8+ 백로그 멀티-플레어/멀티-홀리. **(2) 드레인 상한선 — 대상당 9999/대상 (다중 상한):** 할리슨은 그 영향을 충분히 인지한 채로 이 수치를 설정했습니다. 살아있는 적 4명 = 한 번의 시전으로 최대 39,996 HP 회복 = 최고의 공격형 힐러. ⚠ 장시간 아레나 전투를 망가뜨릴 수 있음 — 의도된 사항이며, Halyson의 모드로 엔드게임 판타지입니다. 보상: 모든 것을 파괴할 경우 RT2 이후 MP 소모량이 ~30까지 증가할 수 있습니다. **(3) Demita vs Demi 바닐라 — 공존:** 둘 다 유지하세요. 싱글 데미 (16 MP, 보스 처치용) + 멀티 데미타 (24 MP, 웨이브 클리어용). 플레이어가 도구를 선택합니다. 비용: ID 슬롯 1개 추가. **(4) 미묘한 차이가 있는 Lulu의 올인클루시브 퓨리 (§4 결정 사항 업데이트):** Biora 16회 = 허용 (독 웨이브); 드레인가 16× = 퓨리 전용 상한 9999/픽 (퓨리에서는 대상당 적용되지 않음, 그렇지 않으면 최대 639,936 HP 회복 — “말이 안 됨”); 오스모스-가 16× = 허용 (MP 상한 9999 = 하드 월); 데미타 16× = 허용 (데미타는 사망한 대상에게는 적중하지 않음); **멀티-피라가 16회 = 잠재적 96회 명중 ⇒ 퓨리 멀티-*는 hit_count=1을 사용 (퓨리에서는 싱글 캐스트로 복귀)** 또는 퓨리 풀에서 멀티-*를 제외 (“모두 포함”에 대한 유일한 예외). 최종 결정은 RT2를 조정합니다. **문서 §8에 업데이트된 미해결 사항:** §8.1 결정됨 (4개 확정); §8.2 아직 미해결 (스피어 그리드 와이어, 화이트 매직 AoE 범위, 원소 흡수 혼란, **도너 티어** `0..95` A** 단계 차단, Multi-* 무작위 분포 `command.bin` (스파이크를 통한 필드). **업데이트된 문서:** `docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` §2.2 드레인(대상당 고정 마나 소모), §2.4 해고(c

고정된 옵션 없음), §2.5. 멀티-피라가 (옵션 B + MP 3-5× 고정 + 완전한 원소 표), §4. 퓨리 (주문별 세부 사항), §8. 미해결 사항 (4개 결정됨, 5개 미해결), §9. 업데이트된 제출 버전. **다음 확실한 단계:** A 단계 주문 ID 제공자 감사와 교차 검증 `FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` — Halyson은 지금 참여할지, 아니면 v0.5가 출시될 무렵까지 기다릴지 결정합니다. **다루지 않는 항목:** writer/hook/probe/DLL/gate. 파일: `FFXProjectEditor/FFXProjectEditor.csproj` (캐스케이드 `v2.130.3.0` → `v2.130.3.1`), `docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` (§2.2/§2.4/§2.5/§4/§8/§9 개정), `CHANGELOG.md` + `changelogUS.md` + `docs/governance/VERSIONING.md` + `docs/ai/SESSION_HANDOFF.md`. [이전: `v2.130.3.0`]
- **`v2.130.3.0` — Ronso Mana CRASH 핫픽스 (`hudSafe=26`): 블롭 쓰기 작업이 노드를 더 이상 건드리지 않게 되었습니다 (이전에는 `via=rich>=1 subIdx=0x01` → 크래시); 이제 쓰기 작업은 OPT-IN 방식으로만 수행되며, 안전한 노드만 사용되고, SEH로 보호된 읽기 작업만 허용됩니다. **Lane **Jarvis-MAGIC**. **PATCH** (다음에 의해 유발된 동작상의 크래시를 수정합니다. `hudSafe=25` ~의 `v2.130.1.0` DLL이 재컴파일되거나 배포되었을 때 `v2.130.2.0` (Nul Ward 레인). **근본 원인 (로그 RT2 `%TEMP%\ffx-hooks.log`):** `RonsoMana BLOB-PATCH2 #1 treeId=43 set subIdx=0x01 via=rich>=1 nodeOff=0x1B4 ec=24 (was 0xFF)` — 내 **(3) "가장 풍부한 노드"** 폴백 `hudSafe=25` **“CHUTADO” 노드 인덱스를 작성했습니다** (`0x01`, `ec=24`)에서 `blob[2+43]`. 그로 인해 `Resolve(2,1,43)` **"성공"**이 **OD 링이 아닌** 노드에서 → `finishMenuTree` 허위 콘텐츠를 로드/표시했다 → 게임이 **충돌**했다. (O `0x00` 이전의 `hudSafe<=24` 단순히 −1을 반환했을 뿐이므로 크래시가 발생하지 않았습니다: 호출된 적이 없었습니다 `finishMenuTree`.) 내 추측은 “무너졌지만 안전한 상태를 완전한 시스템 오류로 바꿔버렸다”. **핫픽스(`hudSafe=26`):** (1) **블롭 쓰기 기능은 이제 OPT-IN 방식입니다** — 기록은 `blob[2+treeId]` **env**일 때`FFXHOOKS_RONSO_OD_BLOBWRITE=1`**이 설정되어 있습니다; **기본값 = 아무것도 기록하지 않음** (충돌 방지 빌드, 순수하게 진단용으로 `ODBLOB`); (2) **옵트인(opt-in)을 사용하더라도, 오직 PRINCIPIADO 노드만 기록한다** — (a) 입력에 인코딩된 OD 명령어가 포함된 노드 `0x311A`, 또는 (b) 게임에서 이미 기록된 sibling party-OD 41..47; **절대** c를 자동으로 기록하지 않는다

hute "가장 풍부한 노드" (이 정보는 덤프를 읽은 후 하드코딩할 수 있도록 로그에만 기록됨); (3) **해당 노드의 모든 읽기 작업 (`OdBlobNode`/`OdBlobEntry`) 및 a2=0 블록의 `DumpOdBlobStructureOnce` 이제 SEH로 보호되고 있습니다 (`__try/__except`)** — 오프셋 OOB로 인한 액세스 위반은 크래시 대신 “무효 노드”로 처리됩니다; (4) `mainPtr` a2=0 조건에 대한 타당성 검증이 추가됨 (`> 0x10000`). 이제 로그에 다음과 같이 출력됩니다. `BLOB-PATCH2 #n ... write=0|1 safe=0xXX(how) risky=0xXX(how,ec=..)` (글을 쓰지 않으면 무엇을 할지 보여준다) 그리고 옵트인 + 보안 노드가 있을 때, `BLOB-PATCH2 WROTE ...`. 배너 `hudSafe=25`→`26`. **가역성:** env가 없으면, 동작 방식 = 안전한 기본 버전 (OD 숨김, 크래시 없음). **빌드/배포하지 않음** (다른 Jarvis-MAGIC 레인과 공유되는 DLL) — **다음 재빌드 시 `ffx-hooks.dll` (어떤 레인에서든) 이미 핫픽스를 적용받았습니다**; `ReadLints` clean. 파일: `RuntimeTools/FfxHooksDll/hooks/RonsoManaHook.cpp`. 문서: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §14. [이전: `v2.130.2.1`]
- **`v2.130.2.1` — 스피라 리포지: 확장된 흑마법 — 디자인 확정 (다중 스킬 계열 > -ja 티어; `-ja` 틈새 백로그로 전환; Lulu Fury는 모두 포함).** Lane **Jarvis-MAGIC**. **검토** (설계 문서 + VISION 통합; 이번 단계에서는 작가/행동/RT2 없음). Halyson이 새로운 Black Magic 생성에 대한 브레인스토밍을 시작했습니다. 두 가지 방안을 비교해 보았습니다: (a) **`-ja` 티어** (피라자/블리자자/썬다자/워터자 = +파워가 적용된 -ga 클론, 퓨리 제외) 대 (b) **멀티 스킬** (단일 대상 기본 주문의 AoE 버전으로, 이에 상응하는 AoE 주문이 **없는** 경우). **결정 (Halyson):** 멀티 스킬이 주된 경로로 선정됨; `-ja` 틈새 백로그로 보류 중 (요소당 1개, 엄청난 MP ~80–120, 셀레스티얼 이후, 덤으로 — 버프와 경쟁하지 않음) `-ga` 에서 `VISION §10.5`); Lulu Fury **모든 것이 포함되어 있습니다** (“Fury Drainga 16×는 아름다운 혼돈이자 OD 판타지입니다”). **Multi-Skill이 승리하는 이유:** (1) `TargetFlags.Multi` 이미 **엔진에서 기본적으로 지원**됩니다 (`FfxLib/Ability/Ability_Command.cs:125`) — 싱글 → 멀티 = **명령 행에 1비트**; (2) 주문들은 **바닐라 버전의 실제 공백**(AoE 독, AoE 드레인, AoE 오스모시스 없음)을 메우고 고유한 정체성을 부여한다; (3) `-ja` '계획'과 중복됩니다 `VISION §10.5` 이제 곧 버프가 걸릴 거야 `-ga` Ignore MD와 함께

EF / 파워 스케일링 (“재단조된 피라가”이지 “피라자”가 아님); (4) `VISION §10.11` 이미 같은 이유(개성이 없는 인플라 풀)로 Holyra/Holyga/Wildra를 “재미있긴 한데, 아마 절대 안 쓸 것 같다”고 분류해 두었다; (5) Drainga/Osmose-ga는 다른 전선(T7 장기전 캡처 캐스케이드, SIN 모드 저주, 몬스터 OD 멀티캐스트)을 지원한다. **기술적으로 검증된 첫 번째 스펠 세트 (v0.5+):** **비오라** (AoE 독 + 피해, 클론 비오 + 멀티), **드레인가** (AoE HP 드레인, 캐스트당 상한 9999), **오스모스-가** (AoE MP 흡수, 캐스트당 상한 99), **데미타** (AoE 50% HP, 대상당 상한 9999), **멀티-피라가 계열** (3회 연속 발동, MP 3배 소모의 피라가 AoE — 할리슨의 직접적인 아이디어: *"예를 들어 멀티-피라가>>>>>>"* — 멀티-블리자가/썬더가/워터가/울티마로 확장 가능한 하위 계열). **두 번째 단계 (v0.6+):** 슬로우가, 리플렉트가, 데미-폴 (“차원 분쇄” 75% HP, 단일 대상, MP 소모량 높음), 쿼터가 (25% HP, AoE, MP 소모량 낮음). **문서화된 정직한 차단:** (a) 주문 ID 슬롯 `0..95` — 교차 감사와 `FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` 기부자를 파악하기 위해; (b) 루루 퓨리의 노 젓기 `#12408–#12422` 댐프 대기 중; (c) RT2에 의존하는 캡 균형 소모 (캡 없음 = 공격형 힐러 OP, 캡 부족 = 무용지물 주문); (d) 멀티-피라가 `hit_count` 플레이어 캐스트 RE 스파이크 미처리; (e) 싱글과 동일한 VFX (v0.5에서는 문제없음, v0.6+에서는 Flan Flood 엔진을 통해 색상 변경, 이미 검증됨) `v2.114.0.0`); (f) 스피어 그리드 와이어에 대한 별도 결정. **단계적 기술 계획 (문서 §6.2):** 단계 A: 감사 ID 기부자 (코드 없음, 본 문서), 단계 B: 오프라인 제작 (행 복제 + 멀티 뒤집기 + 파워/MP 조정 + 텍스트 입력), 단계 C: 라이터 LAB, 단계 D: RT2 게임 내 구현, 단계 E: Fury 통합, 단계 F `-ja` 백로그 틈새 (v0.7+). **모드 연동:** 보완 `§10.5` 블랙 버프 마법, 에너지를 공급한다 `§10.6` 루루 퓨리, 지켜내라 `§10.11` 퍼즐 엘리멘탈, 답변해 주세요 `§10.13` Drainga/Osmose-ga를 지원하는 mob OD 멀티캐스트, 지원 `§11` Cascade T7 전투를 기록하세요. **VISION_AND_ROADMAP.md 업데이트:** 새로운 §12 "확장된 흑마법 — 멀티 스킬 계열" (디자인 결정 + 1차/2차 주문 + 로드맵 연계 + 전체 문서); 참고 문헌을 §13으로 재번호 지정. **지속적인 브레인스토밍을 위한 미해결 질문:** 멀티-피라가 메커니즘 A/B/C (고정된 더블캐스트 vs 무작위 분배 vs 하이브리드 방식 등)

ement — 권고 사항 A), 대상별 대 시전별 드레인 상한선, 스피어 그리드 연결, 데미타 대 데미 바닐라 공존, 화이트 매직 AoE (에스나-가?), 도너 티어. **다루지 않는 내용:** 어떤 라이터도, 훅도, 프로브도, DLL도, 오프라인/RT2 게이트도 다루지 않습니다. 문서 및 로드맵 통합만 다룹니다. 새로운 문서: `docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` (10개 섹션, 약 300줄). 재생된 파일: `FFXProjectEditor/FFXProjectEditor.csproj` (4-튜플 범프), `mods/Spira Reforge/VISION_AND_ROADMAP.md` (새로운 §12 + 참고문헌 §13 번호 변경), `CHANGELOG.md` + `changelogUS.md` + `docs/governance/VERSIONING.md` + `docs/ai/SESSION_HANDOFF.md`. [이전: `v2.130.2.0`]
- **`v2.130.2.0` — Nul Ward: “White Magic 메뉴에 아무것도 표시되지 않는” 문제의 근본 원인 발견 + 수정 — 파티 전체 은행이 다음에서 재로드됩니다. `party_data` 전투가 시작될 때마다, 승마 메뉴가 나타나기 전에 그랜트를 제거합니다.** Lane **Jarvis-MAGIC**. **PATCH** (Nul Ward가 표면에 나타나지 않게 하던 동작 버그를 수정함 — 동일한 feature/lab의 `v2.123.4.0`/`v2.124.0.2`; 결정적인 RE가 입증된 `.i64` 실제 + re-assert의 새로운 우회 경로 `NulWardTeachHook`; Halyson이 **공개한** DLL, 재컴파일 및 배포 완료). **증상:** menu-bound의 멀티사이트 수정 후에도 (`v2.124.0.2`) + 로드 시 부여 (로그 `NulWardTeach grant ch=0..6 radiant=1 umbral=1`), 전투 중 백마법에서는 워드가 **나타나지 않았다**. **폐쇄된 RE (idalib MCP, 바이트 검증 완료, 출처: `disasm`):** `sub_7817D0` ("`* BTL INIT`") 호출 `FFX_Btl_PrepareSaveCommandState`@`0x786BC0` ("`-- SAVE RAM CLEAR -- Preparing save game data`") **전투가 시작될 때마다**;에서 `0x786CA3` 그녀는 ~한다 `mov ecx,21h; mov edi,offset dst__0; rep movsd` — 복사 `0x84`커널의 (132) 바이트 `party_data` (테이블 ID 4)에서 `dst__0=0x11307D8`, 트랙 `[0x11307D8,0x113085C)` **전체를 덮는** `g_PartyWideCommandBank`@`0x11307FC` (오프셋 `+0x24` 복사본 내부; 데이터베이스 = 16단어, ID 96..351). ⇒ **전체 파티 데이터베이스가 `party_data` 모든 전투**, 그리고 `party_data` 워드 비트가 없음 → word14=0 → `IsCommandAvailable(320/321)=0` → 배치 루프가 워드를 건너뛰었다 → "아무것도 나타나지 않았다". **의심 대상 제외:** `FFX_Btl_InitPartyWi

deCommandBank`@`0x784960` só dá `OR` em bits 0..130 e é **debug-gated** (`if(unk_112A905){ DebugMaxAll(); Init(); }` — não roda em jogo normal); `sub_78F0B0` (Lancet/blue) e o grant só mexem bit individual. **Correção mental do §H:** `PrepareSaveCommandState` não é só "persistência" — é o **reload ATIVO por-batalha** do banco a partir do `party_data`; qualquer grant de id≥96 ausente do `party_data` (sphere-grid teach incluído) reseta toda batalha. **Categorização corrigida (empírica):** dump do `command.bin` deployado mostra os doadores Nul (NulShock id48, NulTide id49) **e** as wards (320/321) todos com `SubMenuCategorization (바이트 +24) = 0x02` — wards são templatadas dos doadores, então caem na **mesma** categoria de magia branca dos Nul que já aparecem (categorização correta-por-construção; faltava só o bit de disponibilidade vivo). **O FIX (lab `teach_grant`, deployado):** `NulWardTeachHook` agora instala um `PLH::x86Detour` no `FFX_Btl_PrepareSaveCommandState`; o shim chama o original (deixa recarregar o banco do `party_data`) e **re-afirma** `g_PartyWideCommandBank[word14] |= 0x3` (Radiant bit0 + Umbral bit1) no retorno — ou seja, logo após o wipe e antes do `FFX_Btl_BuildActorCommandMenu` semear o ator. Escrita direta no banco (não chamada de grant) pra não re-entrar no menu builder de dentro do init. Log diag (4 primeiros disparos): `NulWardTeach, #n post-PrepareSaveCmdState 후 재확인: bank word14 0xPRE->0xPOST`. Grant one-shot mantido pros menus de field/pré-batalha. **Consequência de design (produção):** como `party_data` é a fonte por-batalha pra ids≥96, o caminho limpo pra uma ward sempre-disponível é adicionar o bit no próprio kernel `party_data` (innata, party-wide), não no sphere grid — um id≥96 ensinado no grid não persiste pós-init sem (a) o bit do `party_data` ou (b) re-assert em runtime como esse detour de lab. **Build/deploy:** `build_hooks.ps1 -WithPolyHook -Release` PASS (12/12 cpp), deploy `install_to_modules.ps1 -EnableApply -EnableTeach` (backup `ffx-hooks.dll.backup-nul-ward-20260616-081633`, novo SHA-prefix `0DE302BDF13D5B14`). Gate `--nul-ward-static` **VERDICT: PASS** (sem regressão; command.bin/exe/flags intactos). `.i64` real: 주석

~에서 `0x786BC0` + `0x786CA3` (황금률). 2개의 새로운 RVA가 `shared/ffx_addresses.h` (`RVA_FFX_BTL_PREPARE_SAVE_COMMAND_STATE`, `RVA_FFX_PARTY_WIDE_COMMAND_BANK`). **RT2 게임 내:** 전투를 시작하고 화이트 매직에서 Radiant/Umbral Ward를 확인한 뒤 로그를 확인 `reassert ... word14 0x0000->0x0003`. 개방된 틈: 너비 `ply_save` pro bit 224/225 (§H) — 로드할 때마다 lab이 다시 적용됩니다. 파일: `RuntimeTools/FfxHooksDll/hooks/NulWardTeachHook.cpp`, `shared/ffx_addresses.h`. 문서: `docs/reverse/FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16.md` §I. [이전: `v2.130.1.0`]
- **`v2.130.1.0` — 론소 마나 (지난 7일): 나는 `DIAG`/`BLOB-PATCH` RT2의 `hudSafe=24` 내가 건너뛰었던 → 블롭 패치에는 ‘무효한 노드’라고 표시되어 있었다 (`subIdx=0x00`); 유효한 노드를 선택하도록 재작성됨 + `ODBLOB` deep dump.** Lane **Jarvis-MAGIC**. **PATCH** (손상된 휴리스틱을 수정함) `PatchCase2BlobForKimahri` + 이미 출시된 훅/RT2에 새로운 읽기 전용 인스트루멘테이션 추가; **코드 완성, 다음 DLL 릴리스 시 빌드/배포 예정** — 다른 팀에서도 사용 중). **발견 사항 (줄 `DIAG`/`BLOB-PATCH` ~의 `%TEMP%\ffx-hooks.log` 내가 한 번도 읽어본 적이 없는 — 그저 대충 훑어보기만 했을 뿐인 `B0 resolve`):** `BLOB-PATCH #1 treeId=43 set entry=0x00 (was 0xFF)` + `DIAG G0-ring-post blob2=0x1B5C8D70 hdr=[03 8A] maxE=138 treeId=43 entry=0x00 slots41/42/43=[FF FF 00] OK` — 즉, `PatchCase2BlobForKimahri` **이미 존재했고 이미 실행 중이었다** (설정됨 `blob[45]` ~의 `0xFF`→`0x00`) 하지만 `Resolve(2,1,43)` **계속 −1**. ⇒ 이전의 대체 방안 (`maxUsed`→거의 항상 `0x00`)는 treeId 43이 **구조적으로 유효하지 않은 노드**를 가리키고 있음을 나타냈습니다: 이는 기본 게이트를 통과하여 `WalkMenuBlobIndex` (`idx!=0xFF`, `43<count`) 하지만 **보조 선택기 `ringKind` 터진다** (`v4>=node.entryCount` 또는 `entry[v4]==0xFFFF`) → `*a3=−1`. **동일한 로그의 추가 증거:** `count=138` (43이 범위 내에 있음 → “카운트가 작음”의 경우는 아님/`43>=count`); `slots 41/42 = 0xFF` (**이 블롭에 등록된 파티 OD가 없음** a2=1 → 형제 기증자가 없음); `DIAG G0-finalize slot=2 od=3065 3064 3066 311A` (**링 버퍼 레이어-A TEM**) `311A`=cmd282 Ronso Rage** — 게이트가 메뉴 트리 레이어 B의 리졸브임은 100% 확실하며, 콘텐츠가 아님을 확인합니다). **수정 사항 (코드, `hudSafe=25`):** (1) **`PatchCas

e2BlobForKimahri` reescrito** — agora decodifica o nó no formato EXATO do `WalkMenuBlobIndex` (`v6=(count+1)/2+2*subIdx`; `nodeOff=*(i16)(blob+2*v6+4)`; `entryCount=*(u16)(blob+nodeOff)`; `entry[k] = *(u16)(blob + nodeOff + 2 + 2*k)`, tudo bounds-clamped) e escolhe `blob[2+43]` por prioridade: **(a)** nó que **contém `0x311A`** (assinatura exata do OD) e suporta `ringKind=1`; **(b)** sibling party-OD 41..47 já registrado com nó selector-capaz; **(c)** nó mais rico que suporta `ringKind=1` (de preferência também 12). Se NADA qualifica, **deixa `0xFF`** (a2=1 não tem nó OD usável → é fix-C/redirect pro a2=0) e loga `NO 실행 가능한 노드`, em vez de escrever lixo `0x00` como antes. (2) **novo `DumpOdBlobStructureOnce`** (read-only, dispara 1× mesmo em log-only) — dumpa os índices party-OD 41..47 do a2=1, o `entryCount`+primeiras entradas dos nós 0..23 (marcando o que tem `<<OD311A>>`), e os índices 41..47/109..115 do a2=0 (MainRing) → **1 RT2 crava o `subIdx` certo OU revela que é redirect pro a2=0**. Helpers novos (todos `static`, bounds-clamped, sem dep de PolyHook): `OdBlobNode`/`OdBlobEntry`/`OdNodeSupportsSelector`/`OdNodeContainsEncodedOd`/`ReadMainRingBlobPtr` (a2=0 = `_BASE` `0xD2A994`). Banner `hudSafe=24`→`25` (confirma DLL nova no log). **NÃO buildei/deployei** (DLL em uso por outra sala — respeitado); `ReadLints` clean; código pronto pro `build_hooks.ps1 -WithPolyHook -Release`. Arquivo tocado: `RuntimeTools/FfxHooksDll/hooks/RonsoManaHook.cpp`. Doc: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §13. [anterior: `v2.130.0.0`]
- **`v2.130.0.0` — Arena+ Multi Dark Aeon 티어 잠금 보고서 CLI (`--print-tier-lock`) + 사이드카 스키마 v1.** Lane **Jarvis-ARENA**. **MINOR** (새로운 기능: 카탈로그 v2 및 사이드카 진행 상황을 교차 참조하는 첫 번째 오프라인 보고서; 스냅샷의 새로운 표준 스키마 LOCKED/READY/CLEARED). **새로운 `RuntimeTools/ArenaMultiBossLab/TierLockReport.cs` + 4개의 깃발이 `Program.cs`:** `--print-tier-lock`, `--progress <path>`, `--out <json>`, `--json`. 표준 모드는 게이트 사유별로 티어별로 그룹화된 인원 보고서를 출력합니다 (`← needs: arena.dark.valefor, ...` (LOCKED 행) 및 fallback `rt2:<status>  risk:<...>  token:<mode>` rows에서는 `prove`가 아닙니다

d`. Modo `--out` ou `--json` emite JSON estrito que casa com o novo schema `mods/Spira Reforge/arena/spira-arena-tier-lock-state.schema.json` v1 (`format`, `format_version`, `generated_utc`, `summary{총계,정리됨,준비됨,잠김}`, `rows[]` com `state` enum `잠김|준비됨|처리됨` + `unlock_requires/missing_requires`). **Regras de gating ja documentadas no schema** (sao as mesmas que o futuro hook de menu F7 vai aplicar). **Run atual contra catalog + sidecar vazio:** 13 rows total -> 9 READY (solos) + 4 LOCKED (duo/trio/quartet/penta gateados pelos solos), 0 CLEARED. **README de `mods/Spira Reforge/arena/` reescrito** com tabela completa dos 5 sidecars + comandos `--print-tier-lock` e `--validate` exemplificados. Lints clean. Build PASS. [anterior: `v2.129.0.0`]
- **`v2.129.0.0` — Arena+ Multi Dark Aeon BattleEndHook 스캐폴드 (레인 3) + 전투 종료 파이프라인의 RE.** 레인 **Jarvis-ARENA**. **MINOR** (새로운 DLL 기능: 전투 정리 과정에 대한 새로운 읽기 전용 PolyHook2 후크, 그리고 전투 종료 파이프라인의 미공개 RE). **IDA + MCP idalib를 통해 수행된 RE** — 함수 이름이 변경되고 주석이 추가됨 `work/reverse/ida/FFX_recon.i64` (적용된 ‘황금률’): `FFX_Battle_EndCleanupDispatcher @ 0x79E650` (는) `sub_79E650`), `FFX_Battle_EffectFreeAtEnd @ 0x7FB090` (는) `sub_7FB090`, 리터럴 로그 "(op)\top_et_battle_effect_free( battle end )")를 출력하고, `FFX_Battle_GetNextEncounterToken @ 0x7C5EE0` (는) `sub_7C5EE0`). 발견된 체인: `FFX_Btl_MainBattleTick @ 0x790C60` 다음과 같은 경우 cleanup을 호출합니다. `sub_888CE0(0,0,0)` 0x20 비트가 켜져 있으며, 그 전에 `FFX_Battle_InitEncounterFromBtlbin` 다시 연결하거나 필드로 돌아가기. **새 파일:** `RuntimeTools/FfxHooksDll/hooks/BattleEndHook.{h,cpp}` (전체 스캐폴드: 우회 경로, 등록 가능한 콜백, 핸들별 디바운스, `BattleEndEvent` struct com `effectHandle`/`nextEncounterTok`/`result`/`sequenceNo`). **5개의 새로운 RVA가 `shared/ffx_addresses.h`:** `RVA_FFX_BATTLE_END_CLEANUP_DISPATCHER`, `RVA_FFX_BATTLE_EFFECT_FREE_AT_END`, `RVA_FFX_BATTLE_GET_NEXT_ENCOUNTER_TOKEN`, `RVA_FFX_BATTLE_MAIN_TICK`, `RVA_FFX_BATTLE_END_EFFECT_HANDLE` (= `dword_1134564[1743]` @ `0x11360A0`). **게이트:** `arena_plus_victory_hook.flag` (env `FFXHOOKS_ENABL

E_ARENA_PLUS_VICTORY_HOOK=1`); default OFF. **Callback default `ArenaPlus_전투종료시` em `dllmain.cpp`** apenas LOGA — NAO grava no `spira-arena-progress.json` ainda. **2 TODOs explicitos para RT2 spike** com Halyson: (a) distinguir vitoria/derrota/fuga via bitmask de `sub_888CE0`; (b) mapear `effectHandle` -> `progress_flag` via correlacao com ultimo `ResolverLogHook` match. Linha de plug-in `ArenaProgress_기록 달성` deixada comentada e explicada no codigo. Build PolyHook PASS 12/12 cpp. Doc completa em `docs/reverse/FFX_ARENA_PLUS_BATTLE_END_HOOK_RE_2026-06-16.md`. **Reversibilidade:** remover flag = vanilla instantaneo; hook nao toca memoria/return. [anterior: `v2.128.0.1`]
- **`v2.128.0.1` — Ronso Mana (지난 6일 RE): 런타임 종료 — o `−1` 키마리의 OD는 `WalkMenuBlobIndex(blob2,43)==0`; 게이지/OD 지원 기능은 완전히 제외됨 (RT2 로그의 `hudSafe=24` 시험).** Lane **Jarvis-MAGIC**. **REVISION** (RE/doc + 코멘트 `.i64` 실제; **아무런** 행동 변화도 없고, **DLL은 그대로** — 다른 방에서는 계속 사용 중). **RT2 로그를 읽어보니 `hudSafe=24` (`%TEMP%\ffx-hooks.log`) 그 우회로 자체가 `B0-resolve` 이미 포착됨 — 버그 #1의 인과 관계를 종결합니다.** 증거: `B0 resolve a1=2 a2=1 treeId=43 a4=1 ->-1` (에서 `ringKind=1` **E** `ringKind=12`)와 함께 `P0 dispatch charge=100 max=100 590=0x0D` (OD-ready 강제: 이 훅은 이미 0x590 비트를 설정하며, `79AF70` 1을 반환합니다, `6C8`, 그리고 피나 `max:=charge`) — **OD는 여전히 숨겨진 상태였다.** ⇒ **OD-ready/charge==max는 게이트가 아니다** (hudSafe 17–24 마무리). 또한: `blob2=0x1B5C8D70` = **활성 힙**의 포인터 (다음은 아님 `system_00` (오프라인의 빈 공간) → 게이트는 블롭의 **인덱스**이며, 런타임 데이터입니다. **구조적 BREAKTHROUGH (기호 연산, 런타임 없음):** `dword_1134564[N] ≡ unk_C8F8D0[N+1217317]` (`(0x1134564−0xC8F8D0)/4=1217317` 정확히) ⇒ `dword_1134564[0]` (count가 `Resolve` 읽기) **바로** 그 카운트가 `PushMenuTreeEntry(797B80)` 증가시키고, 그리고 `dword_1134564[2*v8+1537]` **이것이** 푸시된 입력입니다 → **Push는 정확히 node-def 루프에 `ResolveMenuTreeNode(797D60)`**; `case 2 subtype=1` → `unk_112A994[8]=0x112A9B4=blob2`. **곧 `−1` ~을(를) 줄인다 `WalkMenuBlobIndex(blob2,43)==0`** ⇒ `blob2[2+43]==0xFF` (t

reeId 43 (등록되지 않음) **또는** `43>=blob2[1]` (count≤43). kind=1 (sel=1)과 kind=12 (sel=12) 모두 −1을 반환했으므로, 이는 **1차 게이트**(2차 선택기가 아님)입니다. **`79BB70` (`BuildActorCommandMenu`) 디컴파일되어 게이트의 라이터 역할에서 **제외**됨: 이 라이터는 **링 버퍼 레이어-A**만 구성하며 (`ringBase+1144*slot+catOffset`, 라우팅 `byte24` 1→+120/2→+72/3→+168/4→+296/0xE→+232; 헤더 `dword28` &0x1000→+40/&0x800→+56/그렇지 않으면→+0), **결코** 해결 블롭을 기록하지 않으며 `actor+0xF7C`. **측정값 1개 미비** (`blob2[1]` count + `blob2[2+43]` idx) — **DIAG 턴키 패치(6줄 이하, 읽기 전용)**를 쉴름에 붙여넣을 수 있도록 준비해 두었습니다 `B0-resolve` 문서의 §12.4에서, 3명의 후보자의 피치가 조율된 상태에서 (B=쓰기 `blob2[2+43]`, C=경로로 리디렉션 `a2=0` (Aeons와 같이, A=노드 합성) **1 RT2**의 덤프에 의해 결정됨. **댓글 `.i64` (황금률, 단, 다음의 경우는 제외):** `0x797D60`/`0x797B80`/`0x797420`/`0x7985A0`/`0x112A9B4`. 문서: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §12. [이전: `v2.128.0.0`]
- **`v2.128.0.0` — Arena+ Multi Dark Aeon 커스텀 토큰 리졸버 REDIRECT (스파이크의 옵션 A).** 레인 **Jarvis-ARENA**. **MINOR** (새로운 DLL 기능: 읽기 전용 스파이크에 문서에 설명된 리디렉션 경로가 추가됨) `FFX_ARENA_PLUS_CUSTOM_TOKEN_RESOLVER_HOOK_SPIKE.md`). **훅 `ResolverLogHook` 이제 두 가지 모드가 있습니다:** (a) LOGGER — 기존 동작, 기본값; (b) REDIRECT — 다음을 통한 옵트인 `arena_plus_custom_token_resolver.flag` (env: `FFXHOOKS_ENABLE_ARENA_PLUS_CUSTOM_TOKEN_RESOLVER`). 리디렉션 모드에서, 기본 트램폴린을 호출하기 전에, 심은 테이블을 조회합니다 `customToken -> aliasToken` (필수 범위 HIWORD `0xA001..0xAFFF`); 일치하는 항목이 있으면 해당 토큰이 ‘vanilla’라는 별칭으로 대체되어, 리졸버가 `row` 정식입니다. 다운스트림에서는 일반 토큰과 구별하지 않습니다. 되돌리기 = 플래그 또는 DLL 제거. **헤더의 새로운 API** `hooks/ResolverLogHook.h`:** `SetCustomTokenRedirects(table, count)` (32장, 유효 범위), `SetCustomTokenRedirectEnabled(bool)`, `IsCustomTokenRedirectEnabled()`, `ResolverRedirectHitCount()`. **새로운 사이드카** `mods/Spira Reforge/arena/spira-arena-custom-tokens.{json,schema.json}`** 4개의 항목으로 채워짐 (듀오 `0xA0010

046->0x00DC0046`, trio `0xA0020046->0x00DC0046`, quartet `0xA0030046->0x01AE0046`, penta `0xA0040046->0x01AE0046`). **Carregamento no boot via `ArenaPlus_LoadCustomTokenRedirects()` em `dllmain.cpp`** — busca em `$FFXHOOKS_ARENAPLUS_CUSTOM_TOKENS_PATH` -> `<DllDir>/mods/Spira Reforge/arena/spira-arena-custom-tokens.json` -> `<DllDir>/spira-arena-custom-tokens.json`; falha em I/O ou parse mantem o hook em modo logger (zero regressao). Build PolyHook PASS 11/11 cpp. RT2 in-game **Precisa Testar** (espera ate o launcher gerar token custom; ainda nao foi conectado em UI). [anterior: `v2.127.0.0`]
- **`v2.127.0.0` — Capture Cascade Cap-1 Phase C: 1바이트 작성기 `capturable` (`MonsterCaptureFlagWriter`) + 게이트 `--monster-capture-bit-rt0` 바닐라 코퍼스에서 PASS 361/361. ** Lane **Jarvis-CAPCAS-WRITE**. **MINOR** (새로운 기능: 이 기능의 첫 번째 라이터) `Capture Cascade` / `Yoke of Spira`; 라이브러리 + 게이트, 아직 UI 없음). Cap-1 계획의 Phase C를 구현함 (Phase B `v2.123.3.1` 바이트를 찾았습니다; Phase C가 해당 바이트에 데이터를 기록합니다). **Writer (`FFXProjectEditor/FfxLib/Monster/MonsterCaptureFlagWriter.cs`):** 바이트 단위 (없음 `Monster_File.Read(...).Write()` (전체 구조체), 다음에서 직접 작동합니다. `bytes[StatSheetPointer + 0x78]` ~와 함께 `StatSheetPointer = uint32_le(bytes[0x0C])`. API: `TryGetStatSheetPointer`, `GetCaptureFlagFileOffset`, `ReadCaptureFlag`, `ReadPaddingByte`, `WriteCaptureFlag(monBin, newSlot)` (배열 복제, 바이트 반전, 패딩 유지) `0x00`, 패딩 값이 0이 아닌 몬스터를 알 수 없는 변종으로 거부함); 헬퍼 `IsUncapturable`/`IsVanillaArenaSlot`/`IsSidecarArenaSlot`. 상수 `Uncapturable = 0xFF`, `VanillaArenaSlotMin/Max = 0x00..0x67`, `SidecarArenaSlotMin/Max = 0x68..0xFE` (바닐라 MA = 104 슬롯, 사이드카 = 베스티어리와 충돌 없는 캡처 캐스케이드 지역). **게이트 (`FFXProjectEditor/Tools/MonsterCaptureFlagRt0.cs`):** 다음을 통해 호출합니다 `FFXProjectEditor.exe --monster-capture-bit-rt0 [monsterRoot]`, 몬스터당 3가지 속성을 증명합니다: (1) **동일 값 바이트 정체성** — `WriteCaptureFlag(bin, current)` == `bin` (newSlot==current일 때 writer는 아무 작업도 수행하지 않음); (2) **슬롯 전용 차이점** — `WriteCaptureFlag(bin, target)` ~와 다르다 `bin` **정확히 1바이트**, `[StatSheetPointer +

 0x78]`, com padding `0x00`, todos os outros bytes byte-identical; (3) **flip-and-restore RT0** — `WriteCaptureFlag(WriteCaptureFlag(bin, target), original)` == `bin` (idempotência completa). Target é escolhido fora-da-banda por categoria: uncap (0xFF) → flip pra 0x68 (sidecar), vanilla MA → flip pra 0xFF, etc. **Resultado contra `D:\FFX Extracted\...\jppc\battle\mon` (vanilla):** **VERDICT PASS — 361/361 monstros**, 251 uncap (0xFF), 110 vanilla MA slot, 0 sidecar, 0 padding non-zero, header parse 361/361, same-value RT0 361/361, slot-only diff 361/361, flip-and-restore RT0 361/361. **Excede 6× as 58 amostras do spike Phase B.** Plugado no `RuntimeTools/offline_ci.ps1` `$editorGates` (entre `몬스터` e `만남`) — fica como gate interno permanente. Arquivos novos: `FfxLib/Monster/MonsterCaptureFlagWriter.cs`, `Tools/MonsterCaptureFlagRt0.cs`. Tocados: `Program.cs` (wire `--monster-capture-bit-rt0`), `RuntimeTools/offline_ci.ps1` (`$editorGates`). **NÃO toca:** `m###.bin` (gate read-only — só lê arquivos vanilla, nunca escreve no disco), DLL, runtime, save, hook. Build C# Release PASS (0 erros, 384 warnings baseline). UI Phase C **não** pluggada nesta entrega — ainda biblioteca + gate, sem botão público. **Próximo passo seguro:** Phase D (UI checkbox `캡처 가능` no `MonEditor` + bulk writer pra Dark Aeons + Penance) ou RT2 in-game manual (Halyson edita 1 monstro descartável `0xFF→0x68` em `m###.bin` real, salva, abre o jogo, captura o monstro pra ver se o engine aceita slot fora do range vanilla 0x00..0x67). Doc: `docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_RESULT_2026-06-16.md` §5.1. [anterior: `v2.126.0.0`]
- **`v2.126.0.0` — Arena+ Multi Dark Aeon 카탈로그 검증기 CLI (`--validate`).** 레인 **자비스-아레나**. **마이너** (새로운 수용 인원: `RuntimeTools/ArenaMultiBossLab`: 카탈로그 v2의 첫 번째 오프라인 검증기). 신규 `RuntimeTools/ArenaMultiBossLab/CatalogValidator.cs` + 깃발 `--validate [--catalog <path>] [--vanilla-root <btlRoot>]` 에서 `Program.cs`. 다음 5가지 측면에서 확인하세요: (1) `format/format_version`; (2) 행별 필수 입력 항목 (`token_mode`, `battle_token`, `base_template`, `battle_id`, `raw_monster_ids`, `gil_cost`, `progress_flag`, `

rt2_status`, `위험`, `증거`); (3) consistencia de `unlock_requires` (cada flag deve aparecer como `progress_flag` em outra row, incluindo tier-level `unlock.requires`); (4) regex `0xXXXXXXXX` em `battle_token`, `0xXXXX` per slot em `raw_monster_ids` + anti-gap (slot vazio antes de slot ocupado = ERRO); (5) `레시피` aponta pra arquivo existente. **Sweep opcional de recipes** via subprocess do mesmo CLI com `--dry-run` quando `--vanilla-root` for fornecido (re-roda todas as recipes em `./레시피` automaticamente). Exit codes: 0 OK, 4 catalog inconsistente, 5 recipe dry-run failou. Run atual contra `spira-arena-catalog.json`: **PASS 0 erros / 0 warnings em 13 rows / 13 flags distintas**. [anterior: `v2.125.1.1`]
- **`v2.125.1.1` — Aurora 탄도 마무리 9단계 종료: 계획의 10개 단계 간 상태 조정 (RT2 대기열 완료, 오프라인 100% 종료).** Lane **Jarvis-AURORA**. **검토** (문서 전용 / 종결: `PORT_STATUS.md` + `docs/ai/SESSION_HANDOFF.md` + `KNOWLEDGE_BASE.md` 재조정됨; 행동상의 변화 없음, 이번 작업에서는 writer/probe/DLL을 건드리지 않음). 계획의 주기가 완료됨 `.cursor/plans/aurora_balistica.plan.md` (10단계, Halyson이 승인한 A+B 범위). **이 프로젝트에서 완료된 단계 (Jarvis-AURORA, 2026-06-16):** F0 문서 조정 (REVISION `v2.123.5.1`), F1 프로브 `aurora-calib-v2` MINOR (`v2.125.0.0`), F3 드래그 미리보기 차이점 비교 오프라인 패치 (`v2.125.1.0`). **이전 작업에서 이미 다룬 단계 (마무리 과정에서 확인된 사항으로, 이 일련의 과정에 새로운 변수는 없음):** F5 게이트 `camera-chunk0-edit-rt0` 오프라인은 이미 `BattleCameraScanLab` (`offline_ci.ps1` C08 `BattleCameraScanLab` 이미 포함되어 있습니다 `polar eye round-trip` + `setup FLOAT edit round-trip` + `edit byte-local + reversible` (chunk0의 모든 빈에 카메라 설정이 포함된 경우). F6 PhotoMode 배선 없음 `FfxHooksDll` 이미 마감됨 (`PhotoMode::Tick()` Present 훅에서 액터 업데이트 후 호출되는 `dllmain.cpp:4622`, `PhotoMode::g_base/g_pm` 정의된 `dllmain.cpp:6060`, 브리지 `NativeMenu_OnEdge`/`NativeMenu_OnHeldEnter` 기록일: `StartNativeMenuIfEnabled` `dllmain.cpp:8884`, `PhotoMode::Exit()` 에서 `StopNativeMenu` `dllmain.cpp:8910` — 게임 내 RT2만 빠짐). F7 스파이크 ID

W2S는 3단계 깊이로 통합되었습니다 (`FFX_AURORA_W2S_MATRIX_OWNER_IDA_DEEP_2026-06-15.md`, `FFX_AURORA_W2S_MATRIX_IDA_CHAIN_2026-06-15.md`, `FFX_W2S_D3D11_INFERNO_2026-06-15.md`)에 수락 기준과 로깅 사양이 명시되어 있음; 격차 = 읽기 전용 후크 `selected target id/index` 메인 UI에서 (RVA 대기 중, 해당 세션의 MCP idalib에 대한 로컬 IDA DB 잠금 해제됨). F8 스파이크 IDA 변형 선택기가 3개의 문서로 통합됨 (`FFX_AURORA_ARENA_VARIANT_IDA_DEEP_2026-06-15.md`, `FFX_AURORA_ARENA_VARIANT_SELECTION_RE_2026-06-15.md`, `FFX_ARENA_VARIANT_RUNTIME_INFERNO_2026-06-15.md`); 배지 `runtime selector UNVERIFIED` 의 UI에 배치된 `AuroraChamber` F0에서. **인간 캐릭터에서 잠긴 단계 (Halyson, 게임 내 RT2):** 4번의 골든 전투에서 F2 RT2 calib-v2 (`425/0/0`, `azit03_00`, `bsil`, `klyt00_00`) + 면적/높이별 Y 잔류물 분석 — 전체 레시피는 `docs/reverse/FFX_AURORA_FORCE_BATTLE_CALIBRATION_PROTOCOL_2026-06-15.md`; F3 (RT2) 드래그 위치 전용 — §B의 레시피 `FFX_AURORA_MASTER_RT2_CHECKLIST_2026-06-15.md`; F4 RT2 일반(다크 에온 제외) 성장 (스폰 + AI + 전투 종료 + 정리); F5 RT2 극성 편집; F6 RT2 포토 모드 최소. **사가 종료 후 상태 (PORT_STATUS 조정 완료):** 오로라 챔버 `parcial → parcial+++` (X/Z 동일성 IDA에서 입증됨, Y 잔차 RT2 미처리, 변형에 UNVERIFIED 배지 표시), `aurora-calib-v2` `validado offline / RT2 pendente`, 드래그 오버레이 `validado offline / RT2 pendente`, BattleCameraScanLab `validado offline (gate C08 = 1 dos 29)`, PhotoMode 배선 `validado offline / RT2 pendente`, W2S 대표 `partial / blocked / acceptance criteria definidos`, 변형 선택기 런타임 `partial / inferred / blocked sem IDA db destravado`. **변경 없음:** writers, probes, DLL, build, package — 전체 작업은 문서화 작업이었으며, 이미 각 REVISIONS에 포함되어 출시된 2개의 소규모 개선 사항(probe ctl + overlay UX)이 있습니다. **다음 확실한 단계 (Halyson으로 이관):** 미리 구성된 RT2 큐 실행 (활성 RT2 5개 + 잠금 해제된 IDA 스파이크 1개) — 먼저 F2 calib-v2 (`ffxprobectl aurora-calib-v2 --route 425 0 0` (배틀로얄에서), 그 후 체력에 따라 F3/F4/F5/F6을 누릅니다. [이전: `v2.125.1.0`]
- **`v2.125.1.0` — 오로라 탄도 계산 3단계 완료 (오프라인): 드래그 이전

오버레이에서 차이점 보기 (이전/새 버전/Δ).** Lane **Jarvis-AURORA**. **PATCH** (기존 드래그 모드의 폴란드어 UX) `aurora-overlay.js`; 새로운 기능은 없으며, 새로운 라이터도 없고, 드래그 위치 지정 전용 RT2 이전의 판독 기능만 개선됨). 오로라 계획 3단계의 **오프라인** 부분을 구현 — RT2(실전 전투에서 작은 몬스터 이동, 저장, 강제 전투, 스크린샷, 복원)는 여전히 **휴먼에서 차단된 상태**입니다(Halyson). **다음과 같은 세 가지 변경 사항이 `RuntimeTools/FFXMapViewerWeb/aurora-overlay.js`:** (1) `onPointerDown` 이제 의 원래 좌표를 캡처합니다. `rawAnchors` 드래그를 시작할 때 (교차하며 `userData.role/index`), 다음 위치에 저장: `overlayState.dragging.original = {x,y,z}`. (2) `onPointerMove` setReadout는 `place role[i]:  X 12.34  Y 5.67  Z 8.90` 3부로 구성된 새로운 형식으로: `(orig) → (new) Δ=(+1.23, +0.00, -2.45)` — 명시적 신호 (`+`/`-`) 드래그의 방향을 명확하게 보여준다. (3) `onPointerUp` 지금 전화해 `setAnchorInfo` 지속적인 요약과 함께 ` ${role}[${i}]: Δ=... (orig) → (new)` 다음 이벤트까지 유지됩니다 — 이전에는 커서가 패널에서 벗어나면 표시 내용이 사라졌습니다. **Halyson의 RT2에 대한 장점:** 운영자는 저장하기 전에 각 몬스터를 정확히 얼마나 이동시켰는지 확인할 수 있습니다 (`💾 Salvar posicoes`) — RT2 테스트 로그에 “X축 1.2u, Y축 0u, Z축 -3.5u 이동”을 쉽게 입력할 수 있게 해줍니다. **적용되지 않음:** writer (`AuroraDragBridge`/`BattleArenaPositionWriter`), 오프라인 게이트, FfxHooksDll, probe ctl. **Lints:** `ReadLints` clean. **다음 단계:** 4단계(RT2 grow normal, 비-다크 이온)와 5단계(gate camera-chunk0-edit-rt0 오프라인 + RT2 polar)가 대기 중입니다. RT2 3단계 = 휴먼(Halyson)에서 차단됨. [이전: `v2.125.0.0`]
- **`v2.125.0.0` — 오로라 탄도 시험 1단계: 시험 `aurora-calib-v2` (잔차 identity/flipZ/yaw180 + height_0x534가 포함된 CSV/JSON).** Lane **Jarvis-AURORA**. **MINOR** (새로운 기능: 새로운 모드) `ffxprobectl` 잔차 보정용 새로운 스키마를 적용한 CSV+JSON 파일을 생성하는 기능; 우리가 처음으로 페어링한 경우 `chunk3.monLive` × `actor+0x3B0` × `actor+0x534` (구조화된 프로브에서). 오로라 계획의 **1단계** 구현 (`.cursor/plans/aurora_balistica.plan.md`). **적용된 사양:** `docs/reverse/FFX_AURORA_CALIBRATION_PROBE_SPEC_2026-06-15.md` (XZ 신원 확인 완료 2

026-06-05 IDA; 잔차 Y는 여전히 RT2 대기 중). **방법:** `ffxprobectl aurora-calib-v2 [--route <field> <group> <formation>] [--battle <id>] [--out <json>] [--csv <csv>] [--max-slots <N>]` (읽기 전용, 창 이외의 MMF 계측 기능 없음) `Arm(1, ...)` (기존). **각 슬롯마다 `monLive` ~까지 `min(monCount, max-slots=16)`:** le `chunk3.monLive[s]` 에서 `g_FFX_Battle_AreaChunk + ptr@+0x20 + 16*s` (XYZW), 해결 `actor[s] = *0x11334CC + 0xF90*s`, le `actor+0x3B0` (world XYZW), `actor+0x3C0` (XYZW 캐시(선택 사항)), `actor+0x534` (height float). 3개의 잔차를 계산합니다: `identity = actor - chunk`, `flipz = actor - (cx,cy,-cz)`, `yaw180 = actor - (-cx,cy,-cz)` 구성 요소 포함 `dx/dy/dz` + RMS (전체 + XZ 전용). **승인 (A01과 일치):** `identity_rms_xz < 0.5` 그리고 `identity_rms * 5 < flipz_rms` 그리고 `identity_rms * 5 < yaw180_rms` -> `winner=identity`; 대안은 rms_alternativa<1.0일 때만 성공한다(IDA-proof 이후에는 가능성이 낮음 — "UNEXPECTED — investigate" 경고 표시); actor_array가 유효하지 않거나 세계가 유한하지 않은 경우 슬롯이 차단됨(디스폰/애니메이션) — 경우 `blocked-runtime-state`, 아니요 `fail`. **출력:** JSON (`work/actor_overlay/aurora_calib_<battle_id>_<utcstamp>.json` (기본값)과 `verdict` 연결 (`identity-confirmed-live` / `ALERT-non-identity-winner` / `blocked-runtime-state` / `partial`) + 배열 `rows`; 36개 열로 구성된 병렬 CSV (qpc, battle_id, route field/group/formation, area_chunk_va, actor_array_va, slot, dict_id, chunk_xyzw, actor_xyzw, actor_cache_xyz, height_0x534, identity/flipz/yaw180_dx/dy/dz/rms, identity_rms_xz, winner, reason). **빌드:** `dotnet build RuntimeTools/FfxDinput8Probe/ctl/Ctl.csproj -c Release` PASS (오류 0개, 기존 경고 CS8632/CS0219만 있음). **실행되지 않음:** probe DLL (`ffx-probe.dll`), 게이트 오프라인, FfxHooksDll. **다음 단계:** Halyson과 함께 RT2 calib-v2로 골든 전투 4회 (`azit03_00`, `bsil05`, `klyt00_00` + 다음과 같은 컨트롤 `425/0/0`) — 레시피는 `docs/reverse/FFX_AURORA_FORCE_BATTLE_CALIBRATION_PROTOCOL_2026-06-15.md`. RT2 1단계 = 해당 없음 (프로브 빌드 전용); RT2 2단계 = 인간 대상에서 차단됨 (Halyson). [이전: `v2.124.0.2`]
- **`v2.124.0.2` — Build+deploy의 `ffx-hooks.dll` (DLL 해제): 다음의 고정 메뉴 바인딩을 구체화합니다.

 Nul Ward + Nul Ward 및 RT2용 아이템 스택 상한선 플래그; 오프라인 프리플라이트 GREEN.** 레인 **Jarvis-MAGIC**. **REVISION** (운영: 이미 버전 관리된 코드의 재빌드+배포 + 플래그 생성; 이번 작업에서는 새로운 소스 코드 동작 없음 — menu-bound 수정 사항은 `v2.123.4.0`, 편집기의 LearnedMove 인코딩은 해당 항목 자체의 것입니다). Halyson이 DLL을 공개했습니다(Ronso Mana가 이 DLL 사용을 마쳤습니다). 조치: (1) `build_hooks.ps1 -WithPolyHook -Release` → 10/10 개의 후크가 컴파일되었으며, **다음이 포함됩니다 `NulWardTeachHook.cpp`** 멀티사이트 수정 사항(`cmp r32,140h`/`cmp eax,140h`→322, PLACEMENT 루프를 포함한 모든 사이트에 패치를 적용합니다 `81 FF`=edi) 이전에는 코드 형태로만 존재했던; (2) 다음을 통해 배포 `install_to_modules.ps1 -EnableApply -EnableTeach` — 이전 DLL의 백업 (`ffx-hooks.dll.backup-nul-ward-20260616-071450`), 새로운 SHA 접두사 `95E1D56A8B9269F7`, 깃발 `nul_ward.flag`+`nul_ward_apply.flag`+`nul_ward_teach.flag`+`nul_ward_teach_grant.flag`; (3) **다른 레인의 요청에 따라** 생성된 `modules/item_stack_cap_255.flag` (비어 있음) → 장전 `ItemStackCapHook` (스택 상한 99→255; 다른 레인의 훅, 이미 공유 DLL에 컴파일됨, 기본값 `FFX_ITEM_STACK_CAP_EXTENDED`=255). 게이트 `--nul-ward-static` 현재 **판정: 통과** (exe 바이트 + 322 행 + `engine_lookup_resolves` Radiant@`0x7814`/Umbral@`0x7874` inRange + DLL 문자열 + 배포 플래그 + 새로운 클리어). **RT2 게임 내 출시** (Nul Ward: 320/321 캐스팅 시 공격으로 전환되지 않음, 오프라인에서 이미 검증됨, 흰색 메뉴에 표기되지 않음 + 그리드 기반 학습 + 지속성; 아이템 스택 상한: 문서 §8의 6가지 시나리오 — 포션 100개 스택, 훔치기/드롭/혼합/상점/보물, 회귀 테스트 플래그 해제). 문서: `FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16`, `FFX_ITEM_STACK_CAP_99_RESEARCH_2026-06-16` §8. [이전: `v2.124.0.1`]
- **`v2.124.0.1` — 론소 마나 (지난 5회 RE): “바라 첼라” 이론은 무효 — 진정한 관건은 메뉴 트리의 매듭을 푸는 것 (`ResolveMenuTreeNode`), 게이지하지 마세요.** Lane **Jarvis-MAGIC**. **REVISION** (RE/doc + 이름 변경/주석 추가) `.i64` 실제; **아무런** 동작 변경 없음, **DLL은 그대로** — 다른 방에서도 사용할 수 있음). **RT2의 `hudSafe=24` (v2.123.4.1) 오류가 발생했으며, 로그를 통해 게이지 라인 전체(hudSafe 23/24)가 잘못된 이유를 확인할 수 있습니다:** `

P0 디스패치 #1..#48, 부하=100, 최대=100` em **TODOS os 48 frames** (o pino persistente funcionou, a barra ficou genuinamente cheia todo frame) + bits `0x590=0x0D` + `IsOdReady -> 1` (até `vanilla=1`) + `311A` no anel — **e o OD continuou oculto / "esquerda" bloqueada**. ⇒ **`charge==max` NÃO é o gate.** (Bônus: o log inunda `경고: 명령어 0~49에서 OD 링 헤더를 찾을 수 없음` — `ScanForOdRingHeader` procura no range errado; o header de OD é cmd**282**.) **O gate REAL (provado por decompile idalib):** `FFX_Btl_UI_BuildCommandRing@0x7ACEC0` constrói o anel **principal** (Attack/Skill/Special) via `FFX_Btl_UI_BuildMainCommandRingTree@0x7A07D0` **só quando `kind<=8`**; o anel **Overdrive é `kind=12`** → **PULA `7A07D0`** e depende 100% de `ResolveMenuTreeNode(2, 1, slot + 41) ≥ 0` (só então `sub_7979E0` finaliza). Para Kimahri (slot 2) = `Resolve(2,1,43)`, que retorna **−1**. A causa exata está em `FFX_Btl_UI_WalkMenuBlobIndex@0x797420`: `idx=blob[2+treeId]; cnt=blob[1]; if(idx==0xFF || treeId>=cnt) return 0` → `LookupMenuBlob=0` → `해=−1` → anel OD nunca exibe. **Mapeamento das duas vias:** principal=`Resolve(2, **0**, slot+109)` no blob `g_FFX_MenuTreeBlob_MainRing` (`*0x112A994`) — resolve OK (user vê); OD=`Resolve(2, **1**, slot+41)` no blob `g_FFX_MenuTreeBlob_OdRing` (`*0x112A9B4`) — Kimahri testa `blob[45]`. **Ambos blobs são DADO ESTÁTICO do recurso `system_01`** (via `FFX_Btl_UI_InitMenuBlobPointers@0x783ED0`: `blob = base + *(base+N)`), idênticos com/sem OD → `blob[2+treeId]` é **índice de nó, não bool** (por isso o `hudSafe=19` errou a semântica). **Nada disso lê `0x5BC`/`0x5BD` (charge/max).** **Renames+comentários `.i64` aplicados e salvos (REGRA DE OURO):** `0x112A9B4`→`g_FFX_MenuTreeBlob_OdRing`, `0x112A994`→`g_FFX_MenuTreeBlob_MainRing`, `0x112A9A8`→`g_FFX_MenuBlobBase_system01` + comentários em `0x797420`(fórmula do gate), `0x7985A0`, `0x7ACEC0`, `0x7A07D0`, `0x783ED0`. **EXPERIMENTO DECISIVO (próximo, precisa de 1 sessão DLL):** DIAG no detour de `ResolveMenuTreeNode` quando `a1==2&&a2==1` logando `treeId`, `blobPtr=*0x112A9B4`, `cnt=blob[1]`, ``idx=blob[2+treeId]`, 바닐라의 결과 — **2가지 시나리오**(OD가 가득 찬 것으로 확인된 저장-편집 대 우리의 강제 시나리오) 및 **d

iffar the `idx`/`cnt`** → 고정값을 정확히 표시합니다 (입력 `blob[45]` 유효하거나, treeId를 리디렉션하거나, 또는 `case 3` 연산자별 `actor+0xF7C`). **권장 사항:** 게이지 핀을 원래 상태로 되돌리거나 중화시키십시오. `hudSafe=24` (그 길은 아니다), 오직 `gateMin/drainCost` (소비량이 이미 확정됨). 문서: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §11. [이전: `v2.124.0.0`]
- **`v2.124.0.0` — 아이템 스택 상한 99→255: 신규 `ItemStackCapHook` 에서 `FfxHooksDll` (새로운 기능, 플래그로 제어됨). **Lane **Jarvis-MAGIC**. **MINOR** (새로운 기능: 런타임 시 새로운 후크 + 바닐라 한도를 초과하여 스택 제한을 해제하는 라이터형 패치; 우리가 이 기능을 처음 다룬 사례) `FFX_Inventory_AddItem`). **이 발견(idalib MCP를 통해 입증된 바에 따르면 `FFX_recon.i64` (2026-06-16):** 슬롯당 99개 항목 및 **중앙** 클램프 제한이 하나의 함수 내에서 `FFX.exe` — `FFX_Inventory_AddItem`@`0x003905A0` (IDA 아파트 `0x7905A0`) — **두 개** `push 63h`** 제네릭 헬퍼에 데이터 전달하기 ** `FFX_Math_ClampInt(v, 0, 99)`@`0x0039A0D0`. 14개의 콜러(steal/drop/mix/shop/treasure/event/menu)는 **모두** 이 단일 함수를 통해 처리되며, 다른 경로에 clamp를 복사하여 붙여넣는 일은 없습니다. **로드 시 정규화 없음** (다음에서 입증됨: `FFX_Btl_PrepareSaveCommandState`@`0x786BC0`: 빈 슬롯만 초기화하며, 기존 카운트에 대해서는 오류 메시지를 표시하지 않습니다). 스토리지 (1바이트) `QuantityBase+slot` 저장 + `byte[112]` RAM에서 `0xD30B5C`)는 이미 재할당 없이 0..255를 지원합니다. **선택된 전략:** 바이트-나로우 패치는 255에 도달하지 못합니다 (push imm8 `6A FF` -1인 경우 부호 확장 처리됨) → **트램폴린 + 스텁을 이용한 5바이트 우회 경로** (템플릿과 동일) `NovaSuperDamageHook`). 각 스텁: `push imm32 <cap>` ~을 대체한다 `push 63h`, 2~3바이트를 재전송한 후, 다음 경로를 통해 반환합니다. `jmp rel32` ~을 위해 `0x00390622`/`0x00390652`. 다음을 통해 설정 가능한 캡 `FFXHOOKS_ITEM_STACK_CAP` env (기본값 255, 1~255 범위 내). **게이팅:** `item_stack_cap_255.flag` (기본값은 off = 기본 동작 유지, 자연스러운 회귀 테스트). **패치 적용 전 검증된 센티넬 바이트:** `kExpectedNew[5] = {6A 63 6A 00 53}` (사이트 #1 / 신규 슬롯) 및 `kExpectedExist[5] = {6A 63 8D 04 1E}` (사이트 #2 / 기존 슬롯). 두 번째 쓰기 작업이 실패할 경우 자동 롤백

 (반쯤 설치된 상태로 두지 마세요). PolyHook 빌드 성공 (11/11 cpp, 새로운 `ItemStackCapHook.cpp`), 배포된 DLL (`932352→935936 bytes`, (새로운 후크의 +3584). 이름 변경 및 주석 `.i64` 적용된 사항 (IDA 황금률): `0x7905A0`→`FFX_Inventory_AddItem`, `0x79A0D0`→`FFX_Math_ClampInt`, `0x790500`→`FFX_Inventory_GetItemCount`, `0x784A90`→`FFX_Inventory_DebugMaxAll`, `g_CmdAggregateAvailArrays`→`g_FFX_InventoryAggregate`, 댓글은 `0x79061D`/`0x79064D` (트램폴린 레시피가 포함된 클램프 사이트). **UI 평결 (스파이크 기준):** `safe-above-99-provavel` (getter는 재클램핑 없이 원시 바이트를 반환함; 시각적 위험 = 2자리 레이아웃에서 "100" 이상일 때 오버플로우가 발생할 수 있으나, 포맷터는 `%d` (3자리 숫자를 입력해도 오류 발생 없음). **Phase 3 UI 패치는 사전 적용되지 않음** — RT2 확인. **Phase 4 RT2 6가지 시나리오 레시피** (세이브 편집 Quantity=200, 훔치기/버리기, 상점 구매, 혼합, 포션 사용, UI 렌더링)에서 `docs/reverse/FFX_ITEM_STACK_CAP_99_RESEARCH_2026-06-16.md` §8. RT2 게임 내 **테스트 필요** (Halyson). 문서: `docs/reverse/FFX_ITEM_STACK_CAP_99_RESEARCH_2026-06-16.md`. 새 파일: `RuntimeTools/FfxHooksDll/hooks/ItemStackCapHook.{h,cpp}`. 재생된 파일: `shared/ffx_addresses.h` (새로운 RVA 10개 + 상수), `dllmain.cpp` (include + 플래그 활성화 기능 + InstallItemStackCapHook을 `InstallHooks` + RemoveItemStackCapHook), `FfxHooksDll.vcxproj`, `build_hooks.ps1`. [이전: `v2.123.5.1`]
- **`v2.123.5.1` — Aurora 탄도 분석 완료: 0단계 시작 (문서 조정 + 기존 코멘트 + UNVERIFIED 배지 변형).** Lane **Jarvis-AURORA**. **검토** (문서 + RE/정직성 주석; 새로운 기능 없음; 구조적 동작 변경 없음). 통합된 계획: `.cursor/plans/aurora_balistica.plan.md` (10단계, Halyson이 확인한 범위 A+B: 활성 RT2 5개 + IDA W2S 스파이크 + IDA 변이 선택기 스파이크). **이 REVISION은 0단계만 포함합니다** (프로브 구현 전 문서 조정). **네 가지 변경 사항:** (1) `PORT_STATUS.md` "Aurora Chamber" 라인 — **정직** 관련 문구 수정: 원래는 `transform battle→mundo e DESIGN/UNCALIBRATED (...) flip-Z e hipotese`, 이제 2026-06-05일자 IDA-proof를 반영합니다 (`X/Z = identity`, `Y residual RT2 pendente`, ref `FFX_AURORA_BATTLE_

TO_SCENE_TRANSFORM_IDA_PROVEN_2026-06-05.md` + `FFX_AURORA_MASTER_RT2_CHECKLIST_2026-06-15.md` A01/A04/A10). (2) `PORT_STATUS.md` topo — novo bloco `2026년 6월 16일 업데이트 (오로라 탄도 완료)` resumindo estado real Aurora reconciliado contra A15 + ordem RT2 confirmada (`azit03_00 → klyt00_00 → 드래그 → 확대 → 카메라 → 사진`, depois spike IDA). (3) `RuntimeTools/FFXMapViewerWeb/aurora-overlay.js` — comentario JSDoc do header (linhas 9-10) corrigido: era `RAW 배틀 장소 — 디자인 전용/보정되지 않음`, agora `X/Z 방향의 IDA 검증된 IDENTITY; 영역/모델 높이별 Y 잔차 (actor+0x534) RT2 대기 중; flip-Z는 비교/디버깅 용도로만 유지됨`. (4) `FFXProjectEditor/Modules/AuroraChamber/AuroraChamber_DataModel.cs` — `variantNote` (mostrado em `SceneDetail` quando `_resolver.ResolveScenes(MapKey)` retorna mais de 1 variante) agora exibe `· 런타임 선택기 UNVERIFIED` ao lado dos `_a/_b/_c`, pra deixar claro que o Chamber renderiza qualquer variante que o catalogo escolha enquanto o selector real (story-flag → variante) ainda nao foi provado por RE — ver A04 `FFX_AURORA_ARENA_VARIANT_SELECTION_RE_2026-06-15.md`. **Nao toca:** probe, writers, gates offline, FfxHooksDll. **Proximo (Fase 1):** implementar `aurora-calib-v2` no `RuntimeTools/FfxDinput8Probe/ctl/Program.cs` com saida CSV/JSON (residual `identity_dx/dy/dz/rms`, `flipz_*`, `yaw180_*`, `우승자` enum, `height_0x534`, route + battle id) — spec em `docs/reverse/FFX_AURORA_CALIBRATION_PROBE_SPEC_2026-06-15.md`. RT2 da Fase 0: nao se aplica (doc-only + UI string). [anterior: `v2.123.5.0`]
- **`v2.123.5.0` — Nul Ward 그리드 교육: 범위 `command.bin` 검증 완료 (exe 패치 없음) + 에디터 내 LearnedMove 인코딩 수정 + 오프라인 검증기.** Lane **Jarvis-MAGIC**. **패치** (SphereGridExplorer 에디터의 동작 버그 수정 + 새로운 검증/오프라인 검증기 + RE). **DLL 미수정** (Ronso Mana 레인이 이를 사용 중) — C#/에디터/IDA 전용. **오프라인 RT2 #1 위험 요소 제거:** RE 테스트 결과 `FFX_Kernel_LoadFileToTable`@`0x781E00` (사례 0 `"command"`)는 `command.bin` **verbatim**을 전역 포인터에 저장(`g_CommandKernelTable`@`0x112A92C`, `memcpy` 전체 파일) — **범위 요약 없음**. `FFX_Table_GetEntryBy

IdRange`@`0x7AB890` lê o header de range **direto dos bytes do arquivo**, mapeando exatamente no `EntryListFile`: `numRanges=int16@0`(=Signature=1), `lo=이전 파일 수@8`(=0), `hi=(EntryCount-1)@10`, `stride=EntrySize@12`(0x60), `base=EntryTableFileOffset@16`(0x14); `record = file + 0x14 + id*0x60`. Como o `command.bin` crescido grava `EntryCount-1=321`, ids 320/321 ∈ [0,321] → resolvem **exatamente** pras linhas Radiant/Umbral appendadas. **Sem patch de exe/DLL.** **Novo `CommandKernelLookupVerifier` (FfxLib/Ability)** replica a matemática exata do engine contra os bytes crescidos e foi ligado no gate `--nul-ward-static` (check `engine_lookup_resolves`: prova offline que GetCommandEntryById(320/321) NÃO cai no fallback cmd0). **FIX no editor (SphereGridExplorer):** o dropdown LearnedMove gravava o id **cru** (`0x0140`), mas o on-disk é o id **encodado** (`0x3000|id`) — provado empiricamente pelo `SphereGridRt2Lab` (Armor Break em `panel.bin` = `0x3012`) e exigido pelo gate `(cmd & 0xFFFFF000) == 0x3000` do grant. Agora o dropdown emite `0x3000|id` (Radiant→`0x3140`, Umbral→`0x3141`) e resolve nomes mascarando `& 0xFFF`, então **o usuário pode pôr as wards no sphere grid e elas REALMENTE ensinam** (antes gravava 0x0140 e o grant rejeitava). Renames `.i64`: `0x781E00`→`FFX_Kernel_LoadFileToTable`, `g_CommandKernelTable`/`g_KernelFileSizes`/`g_AAbilityKernelTable`/`g_ItemKernelTable` + comentários provados em `0x781E00`/`0x7AB890`/`0x790AE0` (salvos via `idalib_save`). Builds C# PASS (0 erros). Doc: `docs/reverse/FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16.md` §F/§G. [anterior: `v2.123.4.1`]
- **`v2.123.4.1` — Ronso Mana hudSafe=24: 게이지 가득 차면 지속되는 핀 (`max:=charge`) — “오버드라이브 상태에서 게이지가 가득 차지 않으면 왼쪽으로 이동할 수 없는” 문제 수정. ** Lane **Jarvis-MAGIC**. **패치** (훅 런타임 + RE의 동작 버그 수정). **발견 사항 (로그 및 디컴파일로 입증됨):** FFX는 “사용 가능한 오버드라이브”를 **게이지 가득 찬 상태**와 연동합니다 (`charge==max`) 그리고 HUD/메뉴 렌더러에서 **프레임별로** 이를 **다시 확인**하세요 — **우리의 후크 외부에서**. 일시적인 스푸핑은 `hudSafe=23` setava `max:=charge` 각 트램펄린 주위를 돌며 **복원했다 `max=255` 그 직후** (`EndK

imahriMaxSpoof`), então o frame em que o anel é desenhado via `max=255` (barra não-cheia) → Overdrive escondido / LEFT bloqueado. **Evidência no log RT2 (`hudSafe=23`):** `G0 메뉴 charge=100 max=100` (o spoof FUNCIONOU no build) mas o OD continuou sem aparecer; `IsOdReady ... vanilla=1 ->1` (os bits 0x590 estavam setados, até pelo vanilla) e mesmo assim bloqueado. **RE desta passada (idalib MCP):** `79AF70 = (actor[0x590]>>2)&1`, `79AEE0 = (actor[0x590]>>3)&1` — **ambos forçados e =1, NÃO são o gate**; `792AB0` (`FFX_Btl_BattleMenuInputDispatch`) **constrói o anel OD `kind=12`** quando `79AF70` (logo o anel OD existe); `799AD0`/`799D60`/`7996E0`/`799830` são **resolvedores de máscara de alvo**, não o gate de OD-cheio. Conclusão: o gate vivo é a comparação `charge==max` por-frame no render — fora do alcance de um spoof transiente. **Fix:** `ApplyKimahriRuntimePoolMax` agora **fixa `max := charge` de forma PERSISTENTE** enquanto `charge >= gateMin` (a barra lê 100% cheia pra toda checagem por-frame com o menu de comando aberto; o ATB/CTB fica **pausado** durante o input de comando, então **nenhum ganho de OD é perdido**); abaixo do limiar devolve o pool real (255) pra barra reencher rumo a 0–255. O spoof transiente `시작/끝` foi **aposentado** (no-ops); o dispatch shim agora chama o pino persistente. **Tradeoff conhecido (RT2):** a barra lê cheia enquanto o OD está usável; o ganho de OD pode pausar enquanto a carga estiver na faixa usável (revisitar se o RT2 mostrar stall de ganho — escopar o pino só pro menu). Build PolyHook PASS (10/10), deploy apply mode (SHA `B092B4C6`). RT2 **Precisa Testar** (ir pra esquerda + usar Ronso Rage com carga parcial). Doc: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §10. [anterior: `v2.123.4.0`]
- **`v2.123.4.0` — Nul Ward: teach/menu-surface에 대한 RE VERDICT + menu-bound hook 수정 (이전에는 `cmp 320` 틀림).** Lane **Jarvis-MAGIC**. **PATCH** (다음의 동작 버그를 수정함: `NulWardTeachHook` + RE가 다음에서 승인되었습니다. `.i64` 실제; PATCH 버프 → 리비전 초기화; 이전 HEAD `v2.123.3.1` (병렬 레인 검토였습니다). RE 전체 검색 (idalib MCP에서 `FFX_recon.i64` (실제) Radiant(320)을 가르칠지 여부에 대한 답변

/Umbral(321) via sphere grid + `command.bin` 확장된 버전은 엔드투엔드로 작동합니다. **검증된 체인:** (1) `FFX_GrantCommandToCharacter`@`0x785D10` id≥96인 로테이아를 파티 전체 은행으로 전송 `g_PartyWideCommandBank`@`0x11307FC` — 16 단어/256 비트 = ID 96..351; 라디언트=word14 bit0, 움브랄=word14 bit1; (2) `FFX_Btl_BuildActorCommandMenu`@`0x79BB70` SEED를 생성하려면 전체 데이터베이스를 actor+0x670으로 복사합니다(루프는 `g_CmdAggregateAvailArrays`@`0x113081C` → 은행 = 16단어); (3) `FFX_Btl_IsCommandAvailable`@`0x79AD40` 'actor'라는 단어를 읽어주세요 `818+id/16` (id320→바이트 0x68C 비트 0) — 일관됨; (4) `FFX_SphereGrid_NodeActivateStateMachine`@`0x8CC300` case21 calls grant(char, node.LearnedMove, 1) → 노드 하나에 `LearnedMove=0x3140/0x3141` 가르친다; (5) 지속된다 via `FFX_IsCommandLearnedPersistent`@`0x7850E0` 동일한 비트를 읽습니다. **버그 발견 및 수정:** `BuildActorCommandMenu` **3**개 있습니다 `cmp r32,140h` (두 `81 FE`=esi 집계 루프에서, 하나 `81 FF`=PLACEMENT 루프에서 (화이트 매직 하위 메뉴에 ID를 삽입하는 부분). PLACEMENT만 320/321이 메뉴에 표시되는지 여부를 제어하며; `NulWardTeachHook` 이전에는 **첫 번째** 매치를 패치했었는데 (`81 FE`, 서피싱에 대한 no-op). 수정: 이제 **모든** `cmp r32,140h`→`0x142` (PolyHook PASS 재구축). **문서화된 RT2 위험 사항:** (a) `FFX_Kernel_GetCommandEntryById`@`0x790AE0`→`FFX_Table_GetEntryByIdRange`@`0x7AB890` **cmd 0을 대체하는** 레인지 테이블입니다 — `command.bin` 성장한 유닛은 320/321을 커버하는 범위를 확장해야 합니다(그렇지 않으면 Radiant가 cmd 0이 됩니다); (b) 지속성은 맵의 width limit/special에 따라 달라집니다. `ply_save` 224/225비트(워드 14)를 다룹니다. **설계:** id≥96 = 파티 전체(모든 사람이 습득), 캐릭터별 아님(96비트 상한). 이름 변경 및 코멘트가 적용된 `.i64` 실제 (`FFX_Btl_IsCommandAvailable`, `FFX_Btl_InitPartyWideCommandBank`, `FFX_Btl_PrepareSaveCommandState`, `FFX_Btl_BuildAggregateChildList`, `g_PartyWideCommandBank`, `g_PerCharCmdMenuState`, 등). 문서: `docs/reverse/FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16.md`. [이전: `v2.123.3.1`]
- **`v2.123.3.1` — Spira Reforge: Capture Cascade Cap-1 — bit `capturable` 에서 `m###.bin` 위치 확인됨 (Phase B spike RE 문서 전용).** 레인 **Jarvis-CAPTURE-RE**. **수정** (RE/문서, 변경 사항 없음)

및 행동; 연쇄적으로 `v2.123.3.0` 다른 평행 레인의 MINOR — 이 REVISION은 순수히 문서/RE용이며, 해당 MINOR와 경쟁 관계가 아닙니다). Spike Phase B의 `Capture Cascade` doc-only 모드로 전달됨: 제어하는 바이트 `capturable=true|false` 각각 `m###.bin` 바이트 단위로 위치가 확인되었으며 **58개의 샘플**을 통해 유효성이 검증되었습니다. **판결:** 위치 = `bytes[StatSheetPointer + 0x78]` (어디서 `StatSheetPointer = uint32_le(bytes[0x0C])`); 의미론 = `0xFF` (`sbyte -1`) 포착할 수 없는, `0x00..0x67` capturable (바닐라 몬스터 아레나 104번 테이블의 슬롯); padding `bytes[StatSheetPointer + 0x79]` 항상 `0x00`. 증거 체인 교차 (a) 레거시 에디터 v1.4 `FFXmon4.ini` (16비트 16진수 형식의 “Capture index” 레이블, `00FF` = uncap), (b) struct C# `FfxLib/Monster/Monster_StatSheet.cs` 49~50행 (`[Data] public sbyte ArenaId` + `[Data] public byte ArenaIdPadding`), (c) 현재 UI 바인딩 `MonEditor_Control.axaml` 466행 (“Capture index (Arena)”), (d) 전체 구조 레이아웃 (헤더 `MonsterHeaderFile` 0x40 바이트 + StatSheet 섹션 + `Monster_StatSheet` ArenaId가 오프셋에 있는 스탯 블록 `+0x64` 다음에서 시작하는 StatBlock에 관하여 `section + 0x14` → 파일 상대 경로 `+0x78`). 결과: 예상 슬롯에 따라 21/21 포획 가능 (다음과 정확히 일치하는 매치 포함: `FFXmon4.ini` ~을 위해 `m044=0x28`/`m045=0x29`/`m046=0x2A`/`m193=0x55`/`m194=0x56`), 16/16 보스 제한 해제 `0xFF`, 10/10 Dark Aeons (`m334..m343`)에서 `0xFF`, 3/3 참회 (`m344..m346`)에서 `0xFF`. **중요한 운영상의 수정:** 기존의 전제인 “DA는 `m106..m113`"틀렸어요 — 실제 금액은 `m334..m343` (시음일: `FfxLib/Dictionaries/Monster_Dictionary.cs` 343~356행), ‘Magus Sisters’는 3개의 별도 항목으로 처리되어 (`m341/m342/m343`). DOC-ONLY: 다음에는 아무것도 작성되지 않았습니다. `m###.bin`/DLL/runtime/save/hook 이 세션에서. 실행되지 않음: 게이트키퍼에 대한 IDA 확인 `CanCapture()` (PLAN의 선택적 3단계); 트리 바닐라를 사용한 교차 검증 `D:\FFX Extracted\` (권장 사항이지만 필수 사항은 아님 — 58/58 모드 적용 시 FFXmon4.ini를 통해 바닐라 기대치에 이미 도달함). 아티팩트: `docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_RESULT_2026-06-16.md` (Phase C 작가 레시피가 포함된 전체 RESULT 문서), `work/_capture_re_2026-06-16/parse

_capture_offset.ps1` (parser CLI), `work/_capture_re_2026-06-16/dump_arena_id_evidence.ps1` (bulk dump), `work/_capture_re_2026-06-16/capture_re_evidence_summary.json` (58 rows), `work/_capture_re_2026-06-16/capture_re_evidence_hexdump.txt`. PLAN doc original ganhou banner BLOQUEIO RESOLVIDO + IDs DA corrigidos. `PORT_STATUS.md` ganhou row "Capture Cascade Cap-1 — bit `포착 가능한` localizado" como `게임 내에서 테스트가 필요합니다 (Phase C 작가)`. Cap-1 writer (Phase C, próxima sessão) escreve **1 byte** por monstro mantendo byte-identity dos 8 fields adjacentes. [anterior: `v2.123.3.0` (병렬 브랜치; 출시 시 변경 내역에 항목 추가)]
- **`v2.123.2.0` — Ronso Mana: 명령어 링의 루트 수정 — 링 버퍼의 베이스가 해제되지 않던 문제 (버그 #1).** Lane **Jarvis-MAGIC**. **패치** (런타임 훅 및 RE 관련 동작 버그 수정). **발견 사항:** 명령어 링 버퍼는 **런타임에 할당**되며, 해당 절대 포인터는 BSS 셀에 위치합니다 (`*(u32*)0x2310CD8`). O `7AEFC0`/`79BB70` 한다 `mov edi,[célula]` (**DEREF**) 인덱싱하기 전 `+20592` (정렬 스크래치) / `+1144*slot` (포르-아토르 반지). O `RonsoManaHook.cpp` ~했다 `RVA_FFX_BATTLE_COMMAND_RING_BSS_BASE=0x1F0FCD8` **생 데이터, deref 없음, 게다가 0x1000 오프셋** — 따라서 링에 대한 **모든** 쓰기 작업(템플릿, 슬롯별 헤더 `+0`, OD 행 `+296`)의 `hudSafe 11..21` **화면에 표시된 활성 버퍼와는 전혀 다른** 정적 BSS에 빠지게 되었습니다. 이것이 BSS 링에 대한 주입이 전혀 나타나지 않았던 이유와, 왜 `CopyMenuTemplate_Shim` (우회로) `7AEFC0`)는 항상 조기 반환(`delta = slotPtr - ringBase` (1144의 배수가 결코 아니었다). **수정:** 새 `RVA_FFX_BATTLE_COMMAND_RING_BASE_PTR=0x1F10CD8` (명령어의 imm32에서 추출된 실제 포인터 셀 `mov edi,[..]@0x7AEFC8`) + `BattleCommandRingUiBase()` 이제 해당 셀의 **참조를 해제**합니다 (`*(u32*)(g_base+RVA)`(할당되지 않은 경우 null 검사). 이에 따라, `PatchKimahriCommandRingUi` (+0 헤더), `PatchKimahriMainMenuOverdriveRow` (+296 OD) 및 `CopyMenuTemplate_Shim` (+296 포스트-소트)가 **실제** 링에 처음으로 글을 올립니다. **RE 통과 (IDA):** `7AD980` = 우선순위에 따라 1개의 배열을 정렬 (`key=*(u8*)(GetCommandEntryById+92)`, scratch=`ring+20592`); `7AEFC0`

 8번 호출하고(카테고리당 1번씩), 링을 슬롯별로 정렬합니다. 이름 변경 `.i64`: `7AEFC0`→`FFX_Btl_UI_SortCommandRingSlot`, `7AD980`→`FFX_Btl_UI_SortCmdRingArrayByPrio` + 포인터 셀에 대한 주석 `0x2310CD8`. **DIAG (hudSafe=22):** `DumpKimahriRingState` 따라서 ~의 리드백은 `+0`/`+296` 레알 `G0-finalize` 인코딩된 OD(0x311A)가 정상적으로 적용되는지 확인하기 위함. PolyHook 빌드 PASS (10/10), 배포 적용 모드. RT2 **테스트 필요** (버그 #1: 중간 링에 OD 없음). 문서: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §9. [이전: `v2.123.1.2`]
- **`v2.123.1.2` — Spira Reforge: Capture Cascade 명명 규칙 이중 적용 (내부 코드명 + 플레이어용).** Lane **Jarvis-MAGIC**. **검토** (설계/문서, 코드 없음). Halyson이 2026-06-16에 확정: 이 기능은 서로 다른 역할을 가진 **두 가지 이름**을 유지합니다. **내부** (기술 문서, 변경 내역, 스키마 필드, ID, 프롬프트, 레인 시그니처)에서는 계속 **Capture Cascade**(Cap-1/2/3, `dark_aeons.captured.<id>`, `capture_cascade.patrol_kills`, `arena.dark.<id>`). **플레이어용** (팝업, 모드 README, 모드 페이지) = **스피라의 멍에** (PT) / **Yoke of Spira** (EN) — 예본/성경적(마태복음 11:30) 공명이 FFX 원작의 신정정치적 주제를 반영합니다. **F7 탭 ‘업적’** = **O Jugo** (PT) / **The Yoke** (EN). 업데이트된 기본 팝업 문자열: PT "베사이드는 다크 발레포르의 **멍에** 아래에 있다" / EN "Besaid is now under the **yoke** of Dark Valefor"; 포획 시 전투 텍스트 PT "다크 발레포르가 길들여졌다. 스피라가 떨고 있다." / EN "Dark Valefor has been tamed. Spira trembles." Doc Capture Cascade에 §0 추가 (명명 규칙 표 + Microsoft Threshold/Redstone 비유 근거). VISION_AND_ROADMAP §11에 상호 링크가 포함된 3가지 컨텍스트 표 추가. [이전: `v2.123.1.1`]
- **`v2.123.1.1` — Spira Reforge: 캐스케이드 페이즈 B 핸드오프 프롬프트 캡처 (RE 스파이크 `capturable` bit).** Lane **Jarvis-MAGIC**. **REVISION** (인계 문서, 코드 없음). 신규 `docs/ai/PROMPT_JARVIS_CAPTURE_BIT_M_HEADER_RE_SPIKE_2026-06-16.md` — Capture Cascade의 Phase B 전용 채팅을 열기 위한 전체 프롬프트. 레인 ID: **Jarvis-CAPTURE-RE**. 임무: 오프셋+비트 찾기 `capturable` ~의 헤더에서 `m###.bin` hex diff를 통해 (Sinscale ↔ Dark Valefor + 2 샘플)

(검증 단계) + 선택 사항: IDA `CanCapture` 교차 확인. deliverables: 표(샘플 4개 이상) + RESULT 문서 + 계획 문서 업데이트 + Cap Cascade 마스터 문서 업데이트 + PORT_STATUS + 자체 REVISION 버전 업데이트. 명시된 비목표 사항 (라이터 구현 없음, 런타임 처리 없음, 인게임 캡처 없음). 솔직한 예상 소요 시간 1.5–2시간. Cap-1 (Phase C, v0.5) 잠금 해제. [이전: `v2.123.1.0`]
- **`v2.123.1.0` — 론소 마나: 오버드라이브 재장전 수정 (버그 #2) + 명령 링에 대한 두 번째 검토 완료.** 레인 **자비스-MAGIC**. **패치** (훅 런타임 동작 버그 수정 + RE/문서). **버그 #2 (“Ronso Rage 사용 후 왼쪽으로 이동 시 해제되지 않음”):** `RonsoManaHook.cpp` OD의 디스플레이 게이트를 `gateMin=100` (바닐라 “전체 바”) **40**개 (= `kRonsoSkillCosts[0]`, 오버드라이브 점프 비용). 게이트가 100일 때, 1회 부분 사용 후(드레인 40 → 충전 60 < 100) **모든** 포싱 기능이 `return` 그리고 OD는 100까지 다시 채워질 때까지 사라졌는데, 이는 0–255 범위의 부분 풀 자체와 모순되는 현상이었다. 행별 그레이아웃(`G3`) 여전히 비용이 높은 스킬(비용 > 현재 체력)을 차단하고 있으므로, 게이트를 낮추는 것은 안전합니다. 설치 배너 수정됨 `hudSafe=19`→`hudSafe=21` (로그에 잘못된 버전이 표시되어 진단에 지장을 주었습니다). **지난주 화요일 (RT2 이후) `hudSafe=20` (실패):** 의 완전한 디컴파일 `79BB70`/`79B500`/`7B6BD0`/`79AD40`/`7A07D0`/`797D60` + **오프라인** 덤프 `command.bin` 입증됨: (a) 런타임 시 명령 행 = **0x14 헤더 + 파일 구조체** (앵커 `byte[25]`=CharacterUser=file+5), 따라서 `byte[22]`=MenuFlgs 등; (b) **cmd282 (Ronso Rage)는 링의 OD 헤더입니다** (`MenuFlgs=0x11`→헤더, `MainMenu=True`, `ODCat=19`, `MenuLeft`) — 이전의 “282→cat4 시트 +296”이라는 표기는 **틀렸다**; (c) 루프-2에서 `79BB70`, 헤더에 `Misc2 MenuLeft (0x10)` → `dword[28]&0x1000` → BSS 배열의 **+40** 위치에 있으며, +0 위치(헤더가 보이는 곳)에는 없습니다 — 따라서 282를 강제로 불러와도 중간에 표시되지 않습니다; (d) `resolve=-1` 이는 **red herring**입니다(주 링은 -1일 때도 나타납니다); (e) `797D60 case 3` **por-ator** 블롭 읽기 (`actor+0xF7C`); (f) `79B500` ~한다 `actor[0x590]=save[+16]` **이른 시간** — 우리의 공세 `RefreshMenu_Shim` (트램펄린 사용 전 준비)는 이 할당에 의해 **덮어쓰기/지워짐** → 예

save-edit 복제가 실패한 이유를 확인합니다. 이름 변경 `.i64`: `7B6BD0`→`FFX_Btl_UI_BuildOverdriveTargetList`, `79B500`→`FFX_Btl_RefreshActorMenuState` (+ 댓글 보기 `79BB70`/`797D60`/`79B500`). 문서: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §8. 다음 단계 (버그 #1): 정확한 델타를 비교하기 위한 ‘save-edited’ 대 ‘forced’ 캡처 실험. 수정 사항 #2에 대한 RT2 **테스트 필요**. [이전: `v2.123.0.2`]
- **`v2.123.0.2` — Spira Reforge: Capture Cascade Phase A 락다운 — 확정된 8가지 결정 + 준비된 3가지 아티팩트.** Lane **Jarvis-MAGIC**. **검토** (설계/문서/스키마, 코드 제외). 2026년 6월 16일 Halyson 기획 회의에서 Capture Cascade 문서의 §7에 명시된 미결정 사항 8건을 확정했습니다 (`v2.122.0.1`): D1 Magus Sisters → **Mushroom Rock Road** (가가제트가 아님 — 미이헨 작전의 뒤틀린 향수 + 비극적인 3명의 페이스, 중후반에 T7 엔드게임으로 변모); D2 F7 괴수도감 → **전용 탭 + 전투 후 팝업**, 획득한 **DA가 생성한 아트(GPT 이미지)**를 넣을 수 있는 슬롯 포함; D3 **도주 불가** 순찰; D4 드롭 = **1× 파편 + 1× 희귀 소모품**; D5 포획 시 **킬++로 집계** (1v1 바닐라 및 SIN 래더 해금); D6 **확인 메시지 없음**; D7 세이프존 **T7 몬스터 및 DA 순찰대가 준수**; D8 버프 알림 **포획 후 첫 입장 시에만**. Phase A에서는 3개의 아티팩트를 획득합니다: (a) **사이드카 설계도** `mods/Spira Reforge/save-schemas/spira-reforge-flags.schema.json` v1 (DA 캡처 + `sin_mode.region_overrides` + `conquistas_seen` + `capture_cascade.patrol_kills`/`first_entry_seen` — 사이드카와 **충돌이 해결됨** `spira-arena-progress.json` Jarvis-ARENA의 `v2.123.0.0` (아레나 로우 클리어를 유지하는); (b) **지역 지도** `mods/Spira Reforge/arena/dark-aeon-region-map.json` (8 DA → 표준 구역 + patrol_subzones + safe_zones + 서사 노트); (c) **RE 스파이크 계획 Phase B** `docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_PLAN_2026-06-16.md` (비트 위치를 찾는 데 1~2시간 소요되는 스크립트) `capturable` 에서 `m###` 헤더(hex diff + 선택 사항: IDA). Cap Cascade 마스터 문서 업데이트: §7(lockdown) + §4(최종 맵) + §13(아티팩트 참조). VISION_AND_ROADMAP §11에 “Phase A 아티팩트” 섹션이 추가되었습니다. 4단계 계획 수립 (A=락다운 완료, B=별도의 RE 스파이크 채팅, C=Cap-1 라이터 v0.5

, D=RT2 파일럿). [이전: `v2.123.0.1`]
- **`v2.123.0.1` — Arena+ Multi Dark Aeon: 펜타 스트레치 레시피 + 드라이런 통과.** 레인 **Jarvis-ARENA**. **검토** (레시피/문서, 출시된 동작 변경 없음). 계획 7단계 (스트레치). 신규 `RuntimeTools/ArenaMultiBossLab/recipes/dark_penta_elemental_five.json` + 레시피 문서 `mods/Spira Reforge/arena/recipes/dark_penta_elemental_five.md` 덮으며 `Dark Valefor + Dark Ifrit + Dark Ixion + Dark Shiva + Dark Bahamut` 에서 `nagi05_70` (일명 Dark Yojimbo, 바닐라 monPos 6개 중 5개, 슬롯 5에 액터 없음). 파이프라인 `ArenaMultiBossLab --recipe dark_penta_elemental_five --dry-run` PASS 반대 `nagi05_70.bin.spiraforge.bak`: chunk2 = 5 actors @ 0x18A4 (16 바이트), chunk3 = 6 monLive @ 0x1B04 (96 바이트, 위치 정보만), 재읽기를 통해 슬롯 확인. 카탈로그 행 `dark-penta-elemental-five` 업데이트됨: ID 이름 변경, `token_mode` `blocked->alias` (일명, 그리고 기술적으로 타당한), `evidence` dry-run PASS와 함께, `rt2_status` 계속된다 `blocked` (게임 내 검증 없음) — RT0 바이트 안전성만 검증됨. **펜타를 기능으로 승격하지 않음**: RT2 PASS 4종 세트 달성까지 계속 진행하며, 다음을 포함한 게임 내 시도가 문서화됨: `_RT2_CHECKLIST.md`. MD 레시피에 4가지 경로(PASS / blocked-by-camera / blocked-by-ai / blocked-by-crash)가 포함된 프로모션 계획. [이전: `v2.123.0.0`]
- **`v2.123.0.0` — Arena+ Multi Dark Aeon 진행 상황 사이드카 + FfxHooksDll의 리더/라이터. ** Lane **Jarvis-ARENA**. **MINOR**: (a) 새로운 사이드카 `mods/Spira Reforge/arena/progress/spira-arena-progress.{json,schema.json}` (제15조 관련 서류의 v1 스키마)와 함께 `flags{}` cleared/first_clear_utc/last_clear_utc/clear_count/evidence + `tier_lock_state{}` 선택 사항 (LOCKED/READY/CLEARED); 키는 `progress_flag` 카탈로그에서 (`arena.dark.<slug>`); 사용 규칙 및 catalog<->sidecar 매핑이 포함된 README. (b) 새로운 모듈 `RuntimeTools/FfxHooksDll/hooks/ArenaProgressSidecar.{h,cpp}` — JSON 읽기/쓰기 기능 (최선의 노력 기반, 의존성 없음), `ArenaProgress_Initialize/IsRowCleared/RecordCleared` 게이트드 by `arena_plus_progress.flag` (기본값: 꺼짐), 다음에서 검색 `$FFXHOOKS_ARENAPLUS_PROGRESS_PATH` -> `<DllDir>/mods/Spira Reforge/arena/progress/...` -> 대체 방안 `<DllDir>/spira-arena-progress.json`. `.tmp`를 통한 원자적 지속성 

+ MoveFileEx`. Env `FFXHOOKS_ARENAPLUS_FAKE_CLEAR=flag1,flag2` permite seed manual para teste de UI. (c) `dllmain.cpp` chama `ArenaProgress_Initialize` no `InstallHooks` apos catalog overlay. (d) **Victory detection real ainda nao plugada** — fica como TODO documentado; a Fase 6 do plano admite essa separacao e a API publica `ArenaProgress_RecordCleared(flag, note)` ja esta pronta para receber o consumer quando o hook `battleEnd` existir. Build PolyHook PASS 10/10 cpp. RT2 in-game **Precisa Testar** (via `FFXHOOKS_ARENAPLUS_FAKE_CLEAR`). [anterior: `v2.122.0.1`]
- **`v2.122.0.1` — Spira Reforge: Capture Cascade — 다크 이온을 포획하면 해당 지역이 깨어난다 (디자인 문서 + 로드맵).** Lane **Jarvis-MAGIC**. **REVISION** (디자인/문서, 코드 없음). Halyson의 아이디어 2026-06-16: DA를 처치하면 이미 아레나+ F7에서 해방됨; **포획** 무기를 사용해 DA를 **포획**(flag66 비트 Capture)하고, 마지막 일격을 가하면 DA의 정식 지역을 깨운다. 확정된 결정 사항: 트리거=기본 캡처, 등장 빈도=종소리 동반 희귀 (~5–10%), 되돌림 불가능=세이브 시 단방향; F7의 ‘업적’ 베스티어리, 고등급 드롭, 도주 불가, 기본 베스티어리의 MA에 포함되지 않음. **Cap-1**로 분해 (팝업 + 사이드카 플래그 + SIN · DARK AEONS 사다리 경로 via `unlock_requires: ["dark_aeon.captured.<id>"]` — 이미 출시된 v2 카탈로그에 포함됩니다. `v2.122.0.0`; v0.5), **제2장** (`sin_tier_override=7` SIN 런타임 모드의 캐논릭 피기백 영역에서; v0.6), **Cap-3** (DA-순찰 `m###` T7 몬스터 1~3마리가 등장하는 커스텀 포메이션에서 HP가 약 30~40% 감소하며, 이는 RE의 인카운터 에디터에 따라 달라집니다(v0.7+). DA 맵→정석 구역(입구 8개) + 완화 효과가 적용된 7개의 전투 + 층당 최소 RT2. 문서: `docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_CASCADE_RESEARCH_2026-06-16.md`; 로드맵 §11 + §6 v0.5/v0.6/v0.7에서 `mods/Spira Reforge/VISION_AND_ROADMAP.md`. [이전: `v2.122.0.0`]
- **`v2.122.0.0` — Arena+ Multi Dark Aeon 카탈로그 v2 + DLL 리더 + 커스텀 토큰 해결기 spike.** 레인 **Jarvis-ARENA**. **MINOR**: (a) `mods/Spira Reforge/arena/spira-arena-catalog.schema.json` v1에서 v2로 다음과 같이 발전했습니다. `token_mode`/`base_template`/`raw_monster_ids`/`unlock_requires`/`rt2_status`/`risk`/`recipe` 행별로; (b) `spira-arena-catalog.json` 5가지 티어로 구성되어 있습니다 (솔로 9 바닐라 + 듀오 + 트리오 + 콰르텟 +

 펜타 스트레치); (c) `FfxHooksDll/dllmain.cpp` 이겼다 `ArenaPlus_LoadCatalogOverlay()` + `ArenaPlus_GetRoute(int)` accessor: 언제 `arena_plus_catalog.flag` 활성 + JSON 발견, 슬롯별 오버라이드 `battleToken`/`battleId`/label (예비 값 고정 지정 `kArenaPlusBossRoutes[9]` 항상 실패 시 승리); (d) 새로운 후크 `RuntimeTools/FfxHooksDll/hooks/ResolverLogHook.{h,cpp}` — 읽기 전용 PolyHook 우회 경로 `FFX_Field_ResolveEncounterToken@0x7828B0` 다음과 같이 (token, result, outField, outGroup, outEntry)가 다음을 통해 게이트 처리된 `arena_plus_resolver_log.flag`; (e) RE 문서 `docs/reverse/FFX_ARENA_PLUS_CUSTOM_TOKEN_RESOLVER_HOOK_SPIKE.md` 주석이 달린 디컴파일 결과 (HIWORD = 필드 키, 하위 바이트 LOWORD = 항목 키, 중간 바이트 = 0), 4개의 호출자, 테이블 레이아웃 `g_EncounterFieldTable@0x112A9C8` + `g_EncounterGroupBlobBase@0x112A9CC`, 사양 범위 사용자 정의 토큰 `0xA001..0xAFFF`, 옵션 A 계획 (리디렉션 사전 해결); (f) 적용된 이름 변경 및 주석 `.i64` 실제 (`work/reverse/ida/FFX_recon.i64`) — sub_79D1B0/D1E0/D190/D230가 바뀌었다 `FFX_Field_*EncounterField*/Group*` (황금률). PolyHook PASS 9/9 cpp 빌드. [이전: `v2.121.0.1`]
- **`v2.121.0.1` — Ronso Mana: 명령 반지 파이프라인의 RE 수정 (hudSafe 17/19가 실패한 이유).** Lane **Jarvis-MAGIC**. **수정** (RE/문서, 동작 변경 없음). 링에 대한 IDA 재분석: **표시되는** Attack/Skill/Special 링은 `FFX_Btl_UI_BuildMainCommandRingTree@0x7A07D0` (treeId=`slot+109`, 그냥 `kind<=8`), ~가 아니라 `treeId=slot+41` — 그래서 `resolve(2,1,43)→-1` 그런데도 반지는 여전히 나타났습니다. **오버드라이브** 반지는 `kind=12` (>8)인 경우, `7A07D0` 그리고 이는 100% ~에 달려 있으며 `resolve(2,1,slot+41)`, 이는 블롭 때문에 오류가 발생하는데 `unk_112A9B4` 있다 `blob[2+treeId]==0xFF`. **`blob[2+treeId]` 이는 노드 정의 인덱스이며, 부울 값이 아닙니다** → 해당 패치는 `hudSafe=19` 지시기는 맞췄지만 값의 의미는 틀렸다. 버그 “Ronso Rage가 해제되지 않음”: gate `79AF70` 요구한다 `charge>=100`; 드레인(100→60) 후 OD가 사라짐 → 최적의 선택은 게이트를 낮춰 스킬 비용을 최소화하는 것(~40). 이름 변경 `.i64`: `7A07D0`/`79AF00`(IsAeonMenuSlot 20-27)/`7986B0`/`783ED0` + 댓글 (블롭 형식: `797420`, 배열 `X` 공유됨: `7985A0` xref를 통해 `0x798672`, dr 웹사이트

ain/이체 `0x78F1E5`). 문서: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md`. (참고: `hudSafe=20` — OD 링 헤더 스캔 + 헤더 배열에 기록 — **배포 완료, 테스트 필요**.) [이전: `v2.121.0.0`]
- **`v2.121.0.0` — Arena+ 멀티 다크 이온 제작 레인 (ArenaMultiBossLab + 멀티-앨리어스 레시피).** 레인 **Jarvis-ARENA**. **사소한 변경**: 새로운 CLI `RuntimeTools/ArenaMultiBossLab` JSON 레시피를 결정론적으로 적용합니다 — `chunk2` 출처: `FormationSlotWriter` (슬롯 전용 RT0) + `chunk3` 출처: `BattleArenaPositionWriter` (위치 전용 RT0) 또는 `BattleArenaGrowWriter` (monLive grow cap 8 actors), 재읽기 보호 및 느슨한 파일 배포 기능 포함 `.spiraforge.bak`. 활성 레시피: `dark_duo_valefor_ifrit` (일명 `kino00_70`/token `0x00DC0046`). 레시피 문서 + RT2 체크리스트 템플릿 + 다중 별칭 README는 `mods/Spira Reforge/arena/recipes/`. 전략: B (다중 별칭) + C (RE 후크를 병렬로 해결) + 콘텐츠 우선 (카탈로그 v2/DLL 리더 실행 전 듀오 → 트리오 → 쿼텟). 기본 자료: `docs/reverse/FFX_ARENA_PLUS_MULTI_DARK_AEON_AUTHORING_DOSSIER_2026-06-16.md`. 계획: `.cursor/plans/arena_plus_multi_dark_aeon_*.plan.md`. 오프라인에서 생성된 듀오 배포 RT0 PASS (7780 바이트, chunk2의 16바이트와 chunk3의 48바이트를 제외한 부분은 바이트 단위로 동일함, monLive); **RT2 게임 내 테스트 필요**, 다음을 사용하여 `_RT2_CHECKLIST.md`. [이전: `v2.120.7.0`]
- **`v2.120.7.0` — Ronso Mana hudSafe=19: 레이어 B UI 트리 (797B80/797D60).** 레인 **Jarvis-MAGIC**. **패치**: 우회 `FFX_Btl_UI_PushMenuTreeEntry` + `FFX_Btl_UI_ResolveMenuTreeNode`; 직접 주입 `Push(2,1,treeId,1+12)` + `Resolve` + `7979E0` 에서 `G0-finalize`; 로그 BLOB 사례-4 `0xD35DF0` + 스택 깊이; `ForceKimahri` shim을 통해. RT2 **테스트 필요**. [이전: `v2.120.6.0`]
- **`v2.120.6.0` — 원본 FSB 수정 (seId 하위 바이트, IDA 검증 완료). **Lane **Jarvis-MAGIC**. **PATCH**: `FFX_FmodSfx_ResolveSequence@0x70FB60` → `sub_710370` trunca `seId` ~을 위해 `u8` 에서 조회하기 전에 `9999_common.txt` (예: `9066`→key `106`→FSB `#9`, 아니요 `#85`); 대체 방안 `seId-9000` 하위 바이트가 없을 때만; UI는 SeSep 라이브를 `magic_####.dll`; 번들 맵 재생성 (824/1165). [이전: `v2.120.5.1`]
- **`v2.120.5.1` — Ronso Mana hudSafe=17: ho

ok P0 `792AB0` (중간 링 OD).** Lane **Jarvis-MAGIC**. **PATCH**: 우회 `FFX_Btl_BattleMenuInputDispatch` — 지우기 `+0xDF7`, `+0x590|=0x0C`, 강제 `7ACEC0(1+12)` 정지됨; 모든 내용 기록 `ringKind`; 배포 실습 `-EnableApply`. RT2 **테스트 필요**. [이전: `v2.120.5.0`]
- **`v2.120.5.0` — 수정: 원래 플레이의 FSB 오류 (seId−9000, magicId 아님).** Lane **Jarvis-MAGIC**. **PATCH**: FEV 이벤트 키 맵 `seId-9000` → `9999_common.txt` → FSB 서브송; 휴리스틱 제거 `magicId` (총에 맞은 듯한 'SIM' 같은 무작위 소리가 나던 문제); ◀▶ 버튼으로 서브송 탐색; 번들 맵 재생성. [이전: `v2.120.4.0`]
- **`v2.120.3.0` — Battle Audio Tools 편집기와의 완전한 통합. **Lane **Jarvis-MAGIC**. **PATCH**: 체력 프로브 + **Verify Audio Tools** UI; `FfxFsbBankCl_Service` fsbankexcl을 통해 real 추가; fsbankexcl 번들 가져오기; gate `--audio-tools-health`; CWD/DLL 호환 CLI. [이전: `v2.120.2.0`]
- **`v2.120.2.0` — fsbankcl 번들 (FMOD FSBankEx 4.44.64).** Lane **Jarvis-MAGIC**. **PATCH**: `tools/fsbankcl/` ~와 함께 `fsbankexcl`+DLL; 별칭 `fsbankcl.exe`; locator 지원 `fsbankexcl.exe`. [이전: `v2.120.1.0`]
- **`v2.120.1.0` — fsbankcl 번들 경로 (임포트 + SDK 감지).** Lane **Jarvis-MAGIC**. **PATCH**: `tools/fsbankcl/` 빌드 시; UI **fsbankcl 가져오기** / **fsbankcl 감지 (FMOD SDK)**; 부트스트랩 `-InstallFsbankCl`; 로케이터 SDK 스캔. 바이너리가 자동으로 다운로드되지 않음 — FMOD 설치 후 1회 임포트. [이전: `v2.120.0.0`]
- **`v2.120.0.0` — 전투 SFX 오디오 도구 번들 포함 + 버전별 제공. **Lane **Jarvis-MAGIC**. **MINOR**: `vgmstream` + `fsbext` 에서 `tools/` git에서; 다음 파일 옆에 복사됨 `.exe` 빌드에서; **오디오 도구 복구** UI는 필요한 경우에만 표시; `tools/AUDIO_TOOLS_LICENSES.md`. [이전: `v2.119.0.0`]
- **`v2.119.0.0` — 커스텀 배틀 SFX 2단계: 오버라이트 없는 새로운 seId. **레인** **Jarvis-MAGIC**. **MINOR**: `FsbDumpDatAppender` + `Fsb9999SampleAppendWriter` (FSB 서브송 +1, dump.dat 경유); `FevLegacySequenceWriter` + 사이드카 `9999_common.txt` row; `CommandSoundPackService.NewSeIdAudio` FEV+FSB+common+DLL 트리플 배포; UI 커널 명령어 **새로운 seId 슬롯**; 게이트 `--fsb9999-append-lab`, `--fev9999-sequence-clone-wave9`, `--command-sound-new-seid-pack`; I36 RE 문서; `work/.../wav/` 레이아웃 

+ `cleanup_fsb_audio_scratch.ps1`. RT2 게임 내 **보류 중**. [이전: `v2.118.0.0`]
- **`v2.118.0.0` — Nul Ward 마스터 플랜 (에포크 1–7 랩 스택).** 레인 **Jarvis-MAGIC**. **MINOR**: 네이티브 슬롯 `+0x613/+0x614`, P16 사전 점검 우회 경로, `NulWardTeachHook` (I20 메뉴 바인딩), RT2 판정 파서, ATEL 행 차이, `NulWardLab` gate; 문서 R01/P14/RT2 매트릭스. RT2 게임 내 **보류 중**. [이전: `v2.117.0.2`]
- **`v2.117.0.2` — Ronso 메뉴 RE: AbilityCommandLab `--dump-cmds`.** Lane **Jarvis-MAGIC**. **PATCH**: 라인 덤프용 오프라인 CLI `command.bin` (ODCat, CostOD, 메뉴 플래그); 카탈로그를 보완합니다 (`8f6ac031`, `v2.116.0.3`). 다음 ROI 훅: `792AB0`. [이전: `v2.117.0.1`]
- **`v2.117.0.1` — Flan Flood LAB + MagicDllRt2VerdictCatalog (구현 미완료).** Lane **Jarvis-MAGIC**. **PATCH**: 전달 `--flameflan-flood-pack` / `--flameflan-flood-recolor`, `MagicDllRt2VerdictCatalog`, `MonsterMagicGrowWriter` row #249 `0x60F9`, 파이어 마그마/산호, `FlanFloodDllPossibleTimingPatch`; RT2 문서 원장 (32회 시도), Family D 타이밍, Flan Flood 플레이북. 앞서 언급된 게이트/UI를 완료함 `v2.114`–`v2.117`. [이전: `v2.117.0.0`]
- **`v2.116.0.3` — 지옥 같은 메뉴 RE + AbilityCommandLab `--dump-cmds`.** Lane **Jarvis-MAGIC**. **PATCH**: 카탈로그 `FFX_RONSO_MANA_MENU_DISPLAY_INFERNO` + `FFX_RONSO_MANA_KNOWN_VS_NEW` (레이어 A/B, 버그 `+0xDF7`, 비트 `79AEE0`, `command.bin` ODCat 19/35); CLI `--dump-cmds` 행에 대한 오프라인 덤프용 `command.bin`; 드리프트 참고 `Camera_*` vs 메뉴 UI. 다음 ROI 후크: `792AB0`. [이전: `v2.116.0.2`]
- **`v2.116.0.2` — 의미 변이 2차 검토: PARTIAL 적용 + `ffx_addresses.h`.** Lane **Jarvis-MAGIC**. **PATCH**: IDA 이름 변경 4건 (`7985A0/797420` UI 블롭, `794030` GetActorRecord, `78C330` precheck_structural); Ronso/UI 메뉴의 RVAs `ffx_addresses.h`; W2S `593440/5936A0` 문서가 잠겨 있습니다. 총 **12/12**개의 이름 변경 드리프트가 `.i64`. [이전: `v2.116.0.1`]
- **`v2.116.0.1` — IDA + BIBLE fix에 적용된 Semantic Drift Audit S01–S12. **Lane **Jarvis-MAGIC**. **REVISION**: 패키지 `FFX_RE_SEMANTIC_DRIFT_AUDIT` (12/12, 67개 기호); **8개의 이름 변경**이 `FFX_recon.i64` (UI 메뉴 `797B80/797D60`, `7B2DD0` aggregate, `78

28B0` token, `g_BattlePlayerList`); `AiBibleCatalog` separa `7078` vs `0x7B2DD0`. [anterior: `v2.116.0.0`]
- **`v2.116.0.0` — 능력 SFX 티어 1: 팩 배치 + 편집 가능한 UI + FEV 웨이브 7.** 레인 **Jarvis-MAGIC**. **MINOR**: `CommandSoundPackService` + `--command-sound-pack` (스테이지/배포/복원, RT2 Fire→Firaga 데모); 커널 명령어 **전투 SFX** 편집 가능 (도너 선택기, 미리보기/스테이지/배포/복원); `MagicDllSoundWriter` 백업/기증자 패치; Magic DLL Browser의 **Sound (SeSep)** 탭; `--fev9999-corpus-wave7`; `--command-sound-custom-wizard`; I31 IDA 적용된 이름 변경; I33 FEV RT2 문서 게임 내 **아직 미처리**. [이전: `v2.115.0.1`]
- **`v2.115.0.1` — Magic DLLs: 파란색 vec4 = 타이밍 리스크 (RT2 Flan Flood 0718 확인됨).** Lane **Jarvis-MAGIC**. **PATCH**: `Extras → Magic DLLs (FFX)` Value Workbench는 파란색이 우세한 vec3/vec4를 다음과 같이 분류합니다. `possible timing (cast→hit)` 배지 포함 `timing-risk` 그리고 Family C/D 알림; Wave4 편집 지침 조정 완료; 문서 `FFX_FLAN_FLOOD_DLL_TIMING_RT2_FAIL`, `FFX_MAGIC_DLL_POSSIBLE_TIMING_VEC4_FAMILY_D`. 시각적 색상 = phyre PS3, DLL 휴리스틱 패치 없음. [이전: `v2.115.0.0`]
- **`v2.115.0.0` — Ability SFX inferno: FMOD 파이프라인 + wave6 코퍼스 + hook lab + Commands UI.** Lane **Jarvis-MAGIC**. **MINOR**: I31/I32 RE (`FFX_ABILITY_SFX_FMOD_STREAMING_INFERNO`, `FFX_MAGIC_DLL_ABILITY_SFX_CORPUS_INFERNO`); `--magicdll-sound-corpus-wave6` (587개의 DLL, 510개의 SeSep); `MagicDllSoundWriter` + `--command-sound-rt0`; `AbilitySfxHook` 읽기 전용 실험실; 커널 명령어 **전투 효과음** 읽기 전용 패널; `AbilitySfxLab` 판결. RT2 게임 내 **보류 중**. [이전: `v2.114.0.3`]
- **`v2.114.0.3` — Spira Reforge: ??????????에 빙의됨 (Sin-infected 오프너).** 레인 **Jarvis-HD**. **수정**: 스포일러 없는 바닐라 템플릿 복제본; 스킬 전용 카페톤 패키지. [이전: `v2.114.0.2`]
- **`v2.114.0.2` — Spira Reforge: 스킬 리컬러 ≠ 몬스터 모델.** 레인 **Jarvis-HD**. **수정**: VFX 전용임을 명확히 함; 몬스터 모델 = 백로그. [이전: `v2.114.0.1`]
- **`v2.114.0.1` — Spira Reforge: 신에 감염된 몬스터 스킬 문서.** Lane **Jarvis-HD**. **수정**: `SIN_INFECTED_MONSTER_SKILLS.md` — 새로운 monmagic + 색상 변경; POC Flan Flood 주황색; Sin 스킬 대기열. [

이전: `v2.114.0.0`]
- **`v2.114.0.0` — 플란 플러드: 워터가 클론 LAB (플레임플란 마그마).** 레인 **자비스-MAGIC**. **MINOR**: `--flameflan-flood-pack` / `--flameflan-flood-recolor` — 249번째 행 `0x60F9`, 클론들 `magic_0718/0719` ~의 `0096/0097`, phyre magma/coral, **FFX.exe 패치 미적용**; UI Monster Commands 2 설치/배포. [이전: `v2.113.0.3`]
- **`v2.113.0.3` — INFERNO 전달 + IDA 의미론적 이름 변경 + BIBLE 갱신.** Lane **Jarvis-MAGIC**. **REVISION**: 패키지 `FFX_RE_DEEP_INFERNO_DELIVERY_BUNDLE`; 45개의 의미적 이름 변경이 `FFX_recon.i64` (160개의 자리 표시자 `FFX_I##_` (생략됨); `AiBibleCatalog` +`btlGetCalcResult`/`readMovePropertyForActor`; 감사 프롬프트 드리프트 `FFX_RE_SEMANTIC_DRIFT_AUDIT`. rename에 의해 **차단되지 않는** Hooks/editor. [이전: `v2.113.0.2`]
- **`v2.113.0.2` — Nul Ward 24-plan 통합 매트릭스 (ATEL 56/57).** Lane **Jarvis-MAGIC**. **수정**: `FFX_NUL_WARD_INTEGRATION_MATRIX` — IDA 슬롯 테스트 `+0x613/+0x614` (오퍼코드 56/57), VALIDATED/CUT 상태의 24개 armar/consume/UI 경로. [이전: `v2.113.0.1`]
- **`v2.113.0.1` — Nul Ward 12개 플랜, RT2 이전 RE (IDA 디컴파일).** 레인 **Jarvis-MAGIC**. **수정**: `FFX_NUL_WARD_RESEARCH_PLANS` — 검증된 앵커가 포함된 12가지 계획 (`sub_7B2DD0` 계량기 `+0x60E`, teach id≥96 party bank, 스캔 `0x3032`, Phase B 쓰기 복원). [이전: `v2.113.0.0`]
- **`v2.113.0.0` — Nul Ward 오프라인 프리플라이트 + 훅 수정 + 커널 UI.** 레인 **Jarvis-MAGIC**. **사소한 문제**: `--nul-ward-static` FFX.exe(PE RVA), command.bin 320/321, DLL/flags를 검증함; IDA는 action+0x08 위치에 인코딩된 cmd가 있음을 확인함; `NulWardHook` 수정됨; hook-aware 팩(Tide/Shock inflict 없음); 커널 ID 320/321 패널; `preflight.ps1`. [이전: `v2.112.0.25`]
- **`v2.112.0.25` — Ronso Mana hudSafe=16: 배포 및 훅 적용 `7ACEC0`.** Lane **Jarvis-MAGIC**. **PATCH**: `install_to_modules.ps1` 번들에 포함된 오래된 DLL을 복사함; 후크 `3ACEC0` força ring kind=12; 유지 `79AF70`. RT2 대기 중. [이전: `v2.112.0.24`]
- **`v2.112.0.24` — Ronso Mana hudSafe=15: 미들 링 게이트 `79AF70`.** Lane **Jarvis-MAGIC**. **PATCH**: hook `39AF70` + `actor+0x590|=4` + word `+0x6C8=0` 김하리(Kimahri)의 적재량 ≥100인 경우; hudSafe=14 템플릿 유지. RT2 보류 중. [이전: `v2.112.0

.23`]
- **`v2.112.0.23` — RE Deep INFERNO 프롬프트 GPT (I01–I20 악마의 마라톤).** 레인 **Jarvis-MAGIC**. **수정**: `FFX_RE_DEEP_INFERNO_PROMPT_GPT55` — ATEL VM, 데미지 파이프라인, AI 재장전, 31개의 하드코딩된 AA, 조우 FSM, Magic VM, 메뉴/AbiMap; 보너스 I21–I30. [이전: `v2.112.0.22`]
- **`v2.112.0.22` — RE Deep Wave 3 프롬프트 GPT (R01–R04 IDA 마라톤).**
- **`v2.112.0.21` — Ronso Mana hudSafe=14: 템플릿 7AEFC0 + menuCtx.**
- **`v2.112.0.20` — Spira Reforge 운영 치트시트 (Halyson 1페이지).** Lane **Jarvis-HD**. **수정**: `docs/ai/FFX_SPIRA_REFORGE_HALYSON_CHEATSHEET_2026-06-15.md` — RT2 v0.2 파일, MEGA/MODS 색인 링크, Auto-Abilities 섹션 (#114–#134, #24 Break, CLI 게이트). [이전: `v2.112.0.19`]
- **`v2.112.0.19` — MODS 마라톤 M01–M30 완료: 문서 29개 + 목차 + Spira Reforge 감사.** Lane **Jarvis-MODS-MEGA**. **REVISION**: `FFX_MODS_MEGA_RESEARCH_INDEX` + M01–M29 (운영 요약 ~37–142 줄/문서); Spira Patch/Arena/SIN/QH/Dark 차단 기능 유지; RT2 상위 #134/id129/Break Limits. 연구용. [이전: `v2.112.0.18`]
- **`v2.112.0.18` — Ronso Mana hudSafe=10: 풀 255, OD는 100 이상일 때만.** 레인 **Jarvis-MAGIC**. **패치**: `gateMin=101` 기본값; 최대 255, 지속적; 스킬별 그레이아웃 적용 시 비용은 40–255로 유지. RT2 미확정. [이전: `v2.112.0.17`]
- **`v2.112.0.17` — Ronso Mana hudSafe=9: 스푸핑 수정 vs 풀 최대 255.** Lane **Jarvis-MAGIC**. **PATCH**: 은퇴 `BeginKimahriMaxSpoof` (풀어내다 `max=255` (빌드 시); drain은 `ApplyKimahriRuntimePoolMax`; 로그 `G0 poolMax`. RT2 대기 중. [이전: `v2.112.0.16`]
- **`v2.112.0.16` — Ronso Mana hudSafe=8: 패리티 저장 (최대=255) + 기본 메뉴.** Lane **Jarvis-MAGIC**. **PATCH**: RVA 레이아웃 수정 `01F0FCD8`; `actor+0x5BD=255` 키마리 전용; 주입 `0x311A` 에서 `+0x71A`/`+0x6CB`; hook `7850E0` save-bank cmd 282; G2 드레인 + G0'/G1'/G3' 유지. RT2 보류 중. [이전: `v2.112.0.15`]
- **`v2.112.0.15` — MODS MG의 GPT 5.5 검색: Spira Reforge M01–M30.** Lane **Jarvis-HD**. **REVISION**: 프롬프트 `FFX_MODS_MEGA_RESEARCH_PROMPT` (스파이라 패치, 아레나+, SIN 모드, 파티 메타, 포비든 라이트, IDEAs); `KNOWLEDGE_BASE` + `mods/README`. RT2 없음. [이전: `v2.112.0.14`]
- *

*`v2.112.0.14` — Ronso Mana hudSafe=6: 메인 메뉴(공격/스킬/특수)에서 오버드라이브. ** 레인 **Jarvis-MAGIC**. **패치**: G0' @ `39AD40` (`HasCommandBit` cmd 282 키마리 + 부분 적재); G0 비트 282 전/후 `79BB70`/`79B500`; 배수 후 비트 재연결. RT2 미처리. [이전: `v2.112.0.13`]
- **`v2.112.0.13` — Ronso Mana hudSafe=5: 부분 로딩 시 OD 하위 메뉴를 다시 열기.** Lane **Jarvis-MAGIC**. **PATCH**: `RonsoManaHook` — G1' @ `392170` (OD 파단 강도) + `49BA80` (open spoof) + G0 리프레시 `39B500` + bit cmd 282 @ `39C090`; 고정 `IsKimahriActorPtr` 그저 `Id==2`; G2 드레인 + G3' 그레이아웃 유지; HUD/GetMax 우회 없음. RT2 보류 중. [이전: `v2.112.0.12`]
- **`v2.112.0.12` — MEGA deep 후속 작업 D01–D07 완료 (IDA + 코퍼스 + 블록).** Lane **Jarvis-MEGA-DEEP**. **REVISION**: 문서 7개 깊이 (~260–390줄) + `FFX_MEGA_RESEARCH_DEEP_INDEX`; exports IDA `work/reverse/ida/exports/mega_deep/` 참조된 항목; W2S 소유자/캡 스폰/변형 선택기/핸들러 `0x707A` 차단됨; chunk3, stride `0xF90`, FSM 카메라, Y 저자 검증됨. 연구용. [이전: `v2.112.0.11`]
- **`v2.112.0.11` — Ronso Mana hudSafe=4: G0 메뉴 + G3' 새로고침 + G2 드레인.** 레인 **Jarvis-MAGIC**. **패치**: `RonsoManaHook` — G0 @ `39BB70` (키마리의 체온) `max=charge`), G3' @ `492040` (회색으로 표시된 행), 우회 없이 `897F80`/GetMax. [이전: `v2.112.0.10`]
- **`v2.112.0.3` — Spira Reforge: 전체 맵 + F7 아레나 (NPC wontfix).** 레인 **Jarvis-HD**. **수정**: `mods/Spira Reforge/VISION_AND_ROADMAP.md` — Ribbon/Celestial 안티 메타, 로드맵 v0.2–v0.5, 래더 Dark Aeons + SIN 변형, 아레나 스키마 카탈로그, F7 전용 결정 메뉴. [이전: `v2.112.0.2`]
- **`v2.112.0.2` — Spira 패치 형식 사양 (대량 내보내기/가져오기 초안).** Lane **Jarvis-HD**. **수정판**: `docs/specs/SPIRA_PATCH_FORMAT_2026-06-15.md` — 몬스터, 전리품, 자동 능력 등에 대한 JSON/CSV 스키마, 그리고 `arms_rate`; 예시는 `mods/Spira Reforge/patches/`. 아직 편집기에는 구현되지 않았습니다. [이전: `v2.112.0.1`]
- **`v2.112.0.1` — Ronso 플래그 코멘트 + 버전 관리 MonEditor 모델 항목 수정.** Lane **Jarvis-MAGIC**. **PATCH**: `kimahri_ronso_mana.flag` log/apply 명령어와 함께. [이전: `v2.112.0.0`]
- **`v2.112.0.0` 

— MonEditor: 배틀 모델 카탈로그 (FFXmon) + Model1/Model2 미리보기. **Lane **Jarvis-MAGIC**. **MINOR**: 인제스트 `battle-model-catalog.json`; 이름이 표시되는 피커; 브릿지 `BattleModelCatalogBridge` → 모델 뷰어 (`m###`/`c###`/`s###`); preview dual id1+id2; MAIN MODEL 페어 버튼. Doc `FFX_BATTLE_MODEL_CATALOG_MONEDITOR`. [이전: `v2.111.0.0`]
- **`v2.111.0.0` — Ronso Mana 유선 후크 (`FfxHooksDll` Kimahri (부분 OD LAB).** Lane **Jarvis-MAGIC**. **MINOR**: `RonsoManaHook` G1 게이트 + G3 그레이아웃 (PolyHook) + G2 드레인 @ PE `0x38F1E5`; 플래그 `kimahri_ronso_mana.flag` / `kimahri_ronso_mana_apply.flag`; 배포 실습 `ronso-mana-lab-v2.111.0.0`. RT2 게임플레이 일부 (드레인 PASS). [이전: `v2.110.1.2`]
- **`v2.110.1.2` — MEGA 리서치 마라톤: Aurora 관련 문서 23개 + 감사 + 심층 후속 조치 D01–D07. **Lane **Jarvis-MAGIC**. **검토**: 목차 `FFX_MEGA_RESEARCH_INDEX` + A01–A15/C01–C08; `FFX_MEGA_RESEARCH_AUDIT` (요약 대 원문); 프롬프트 `FFX_MEGA_RESEARCH_DEEP_FOLLOWUP` IDA의 두 번째 마라톤을 위해; `PORT_STATUS` gates 21→29 조정 완료. RT2 없음. [이전: `v2.110.1.1`]
- **`v2.110.1.1` — NovaClamp: fix 게이트 클로버링 EFLAGS (전역 우회).** Lane **Jarvis-MAGIC**. **PATCH**: 스텁이 재실행됨 `cmp eax,ebx` 바닐라 루트에서 — `jle` ~의 플래그를 사용했고 `cmp [ebp+0x1C]` (거의 모든 cmd &lt; `0x3073` clamp 건너뛰기); deploy `ffx-hooks.dll`. RT2: 티더스 재검증 ≤99k + 노바 &gt;99k. [이전: `v2.110.1.0`]
- **`v2.110.1.0` — Event JP 리드 + PPPDRAW 제거 + NovaClamp 스텁 수정.** 레인 **Jarvis-MAGIC**. **패치**: `--event-rt0` 회귀 분석 JP `0x06`/`0x26..0x2F` (`13/13`); `FFXPROBE_PPPDRAW_RETIRED` 프로브/랩에서; 로그 기록 전 새로운 스텁 쓰기. [이전: `v2.110.0.3`]
- **`v2.110.0.3` — 연구 H01–H15: 헤비 패키지 + 색인 + 론소 마나.** 레인 **Jarvis-HEAVY** + **Jarvis-MAGIC**. **검토**: 문서 16개 (`FFX_RESEARCH_CHAT_GENERATED_FILES` + H01–H15); `KNOWLEDGE_BASE` ONDA H; Ronso G1/G3 IDA. RT2 없음. [이전: `v2.110.0.2`]
- **`v2.110.0.2` — RE: IDA flat 대 PE RVA (배틀 섹션) `+0x400000`).** Lane **Jarvis-MAGIC**. **수정**: doc `FFX_IDA_FLAT_VS_PE_RVA_BATTLE_SECTION_2026-06-15.md`; RVA를 포함한 사양/요약/인계 `0x38xxxx`. [이전: `v2.110.0.1`]
- **`v2

.110.0.1` — NovaClamp: fix PE RVAs (0x38EDD5, não 0x78EDD5).** Lane **Jarvis-MAGIC**. **PATCH**: hook falhava silencioso — IDA flat = PE RVA + 0x400000 na seção battle; bytes `7E 02` no build Steam. [anterior: `v2.110.0.0`]
- **`v2.110.0.0` — 새로운 슈퍼 데미지 상한선 우회 LAB (`FfxHooksDll`).** Lane **Jarvis-MAGIC**. **MINOR**: 인라인 후크 @ `FFX.exe+0x38EDD5` — 스킵 클램프 `mov eax,ebx` ~할 때 `[ebp+0x1C]==0x3073` (Nova #115); 공식에 따른 변동 피해; 플래그 `nova_super_damage.flag` / `nova_super_damage_log.flag`; RE 클램프 문서 + RT2 사양, 게임 내 적용 대기 중. [이전: `v2.109.4.1`]
- **`v2.109.4.1` — Arena+: NPC 후크 랩 — RT2 실패, 완화 조치 + RE 해결. **레인** Jarvis-ARENAPLUS. **패치**: 후크 난이도 상향 `013B` (업데이트 없음) `maxIndex` 패치 없음; defer 30f; `sub_86BEC0` @ `0x86BEC0`); **RT2 NPC 오류** — 6번째 옵션이 표시되지 않음; **F7은 여전히 유효**. Doc `FFX_ARENA_PLUS_NPC_NOWWHAT_HOOK_2026-06-15.md` 업데이트됨. [이전: `v2.109.4.0`]
- **`v2.109.4.0` — Arena+: NPC 옵션 "Now what?" → Arena+ (lab).** Lane **Jarvis-ARENAPLUS**. **MINOR**: hook `Common.displayFieldChoice [013B]` 문자열 `0x4A`; `arena_plus_npc.flag`. RT2 NPC **합격하지 못함** — 참조 `v2.109.4.1`. [이전: `v2.109.3.0`]
- **`v2.109.3.0` — ThundaFira: PPPDRAW 인라인 EXE의 hook 기능을 비활성화 (`sub_71B980`).** Lane **Jarvis-MAGIC**. **PATCH**: `FFXPROBE_PPPDRAW_RETIRED`; 오프코드 14–16은 오류를 반환합니다; lab `--pppdraw-tint-capture` 차단됨; `DEAD_ENDS_INDEX` H7–H9. [이전: `v2.109.2.0`]
- **`v2.109.2.0` — ThundaFira: PPP 드로우 훅 폭발 후 발생하는 크래시 수정. **Lane **Jarvis-MAGIC**. **패치**: `PPPDRAW_STOP` hook mid-VFX는 제거하지 마십시오. 제거는 오직 `DLL_PROCESS_DETACH`; 마지막 히트 후 3초 동안 대기합니다. 문서 `FFX_THUNDAFIRA_PPPDRAW_HOOK_CRASH_2026-06-15.md`. [이전: `v2.109.1.0`]
- **`v2.109.1.0` — ThundaFira: PPP 드로우 훅 리타겟 `sub_71B980`.** Lane **Jarvis-MAGIC**. **PATCH**: `ffx-probe` PPPDRAW는 다음 위치에 설치됩니다. `0x71B980` (14 B 프롤로그); tint 구조체 `a3+4`; doc `FFX_THUNDAFIRA_SUB_71B980_IDA_2026-06-15.md`. [이전: `v2.109.0.2`]
- **`v2.109.0.2` — Research queue troxa: RE 패키지 오프라인 (문서 21개).** 레인 **Jarvis-RESEARCH-TROUXA**. **REVISION**: 인덱스 `FFX_RESEARCH_QUEUE_TROUXA_IN

DEX_2026-06-15.md` + dossiers ThundaFira/Magic/Arena+/AutoAbility/FPS/offline-ci/event-text/spheregrid; `KNOWLEDGE_BASE` + `PORT_STATUS` atualizados. Sem mudança de comportamento do produto. [anterior: `v2.109.0.1`]
- **`v2.109.0.1` — Arena+: 디스크 내 FFXED 플래그 + OST 145 멀티 보스 RT2.** Lane **Jarvis-ARENAPLUS**. **패치**: PC 매치 저장 (`gil@0x3D88`, 경기장 `@0x424C`, FFXED `@3273` bit7) OR 런타임 `0x18F4`; F7에서 8개의 다크 이온 COST; 여러 보스가 등장하는 OST 챌린지 (P4 딜레이 개방). [이전: `v2.109.0.0`]
- **`v2.109.0.0` — 세이브 에디터: MC 멀티 슬롯 + 아이템 드롭다운 + RT2.** Lane **Jarvis-SAVE**. **사소한 변경**: 허브 내 슬롯 선택기 `.ps2`; 아이템 콤보 (FFXED 카탈로그); `--ffx-save-rt2` (raw/.ffx/.ps2 멀티 슬롯); 수정 `SaveSlot` 다른 경로에 저장. [이전: `v2.108.0.0`]
- **`v2.108.0.0` — 세이브 에디터: 캐릭터별 무기 콤보 + 전체 C0008i 배치 파일.** Lane **Jarvis-SAVE**. **사소한 사항**: 드롭다운 메뉴가 있는 장비 (T[0–6] 티더스→리쿠, 외형, 자동 공격, 피해 계산식); `weaponCatalogByCharacter` 레지스트리에서; `FfxSaveBatchActions` 액션 슬롯 9–59 (스피어/미니게임/블리츠/기증자 수입); 캐릭터/스피어/미니게임/블리츠볼 탭의 일괄 처리 버튼. [이전: `v2.107.0.0`]
- **`v2.107.0.0` — 세이브 편집기: 완전한 FFXED 포트 (장비→가져오기 + .ps2 MC).** Lane **Jarvis-SAVE**. **사소한 사항**: 기본 탭인 장비 (200 슬롯 + 자동), 아이템/길/키 아이템, 블리츠볼 (60명), 스피어 그리드 (노드 + 일괄 처리), 미니게임 (레지스트리 필드), 기타/가져오기 (기증 지역); `ffxed_registry.json` + `scripts/ffxed_extract_registry.py`; 불러오기/저장하기 `.ps2` 8MB; 배치 C0008i 오류; 대체 파일 FFXED.jar. [이전: `v2.106.0.1`]
- **`v2.106.0.1` — Arena+: FFXED에 맞춰진 Dark Aeon 플래그 (bit7 @ save+3273).** 레인 **Jarvis-ARENAPLUS**. **패치**: F7 메뉴에서 잘못된 배열을 읽어옴 `0x18F4`; 이제 FFXED의 Misc→Optional Bosses에서 일부 기능을 사용합니다 (`0xD2D759..`, 7번째 비트). [이전: `v2.106.0.0`]
- **`v2.105.0.0` — ThundaFira: ppp_dataA 대 PE 분석기 실시간 분석 + 덤프 틴트 영역.** Lane **Jarvis-MAGIC**. **MINOR**: 런타임 실험실 `LiveVsPeAnalyzer` + `--live-vs-pe`; 덤퍼 캡처 `tint_vec4_canonical` @ `0x37710` 그리고 `dataA_cyan_strip`; doc 실행 시 판정≠PE (2758 B 차이). [이전: `v2.104.0.6

`]
- **`v2.104.0.6` — Arena+ OST: 레시피 랩 (오버라이드 + 사운드cmd 트리거 4).** Lane **Jarvis-ARENAPLUS**. **PATCH**: 비동기 모드에서 16→145 직접 스왑을 포기하고, 다음을 사용 `musicOverride` + `soundcmd 23/4/0` + `SwitchCrossfade` (실험실 메뉴에서 확인됨). [이전: `v2.104.0.5`]
- **`v2.104.0.3` — Arena+ OST 후크 v5 (FSM 케이스-8 `PlayTrackWithPreload`).** Lane **Jarvis-ARENAPLUS**. **PATCH**: `InstallMusicHookArenaBattle` 차단하다 `PrepBattleTrack` + `PlayTrackWithPreload` (RVA `0x486940`/`0x486980`) 하드코딩된 16→145를 변경하되, 비동기 큐 26/39는 그대로 유지; 문서 RE P0–P3. [이전: `v2.104.0.2`]
- **`v2.104.0.2` — ThundaFira: PPP 드로우 훅 크래시 수정 (안전한 프로브).** 레인 **Jarvis-MAGIC**. **패치**: 블라인드 EXE 폴백 제거; vtable만 설치 `host+2856` 프롤로그 포함 `55 8B EC`; STOP은 바이트를 복원합니다; `--force-tint` RT2 충돌 후 차단됨. [이전: `v2.104.0.1`]
- **`v2.104.0.1` — ThundaFira: PPP 드로우 훅 수정 (vtable host+2856).** Lane **Jarvis-MAGIC**. **PATCH**: 런타임 시 bind fn 문제 해결 (`off_C64CE8+2856`); cdecl thunk; force tint를 +0/+4로 설정. RT2−를 `0x31B590` (0건). [이전: `v2.104.0.0`]
- **`v2.104.0.0` — ThundaFira: 프로브 후크 틴트 PPP 드로우 (`FFX+0x31B590`).** 레인 **자비스-MAGIC**. **MINOR**: `ffx-probe` PPPDRAW 14–16번 오프코드; lab `--pppdraw-tint-capture`. [이전: `v2.103.0.0`]
- **`v2.103.0.0` — ThundaFira: KeThRes 맵 재배치 + 후크 부착 버퍼 (`sub_72C570`).** 레인 **자비스-MAGIC**. **MINOR**: `MagicDllKeThResRelocAnalyzer` + `--thundafira-kethres-reloc`; 게이트 패치 수정됨 (`dataA+0x58C..0x620`, 2× vec4); `ffx-probe` KETHRES 10–12의 오프코드; lab `--kethres-attach-capture`. [이전: `v2.102.0.1`]
- **`v2.102.0.1` — ThundaFira: RT2 소프트락 이후 KeThRes PPP 패치. **레인** Jarvis-MAGIC. **패치**: `MagicDllKeThResPppPatch` blob/offset-table에 대한 패치 작업을 중단하고, 단지 `float_vec4` 청록색 대역에서 `dataA`. Doc RT2− softlock. [이전: `v2.102.0.0`]
- **`v2.102.0.0` — ThundaFira: KeThRes PPP 오프라인 패치 (`--thundafira-kethres-patch`).** 레인 **자비스-MAGIC**. **MINOR**: `MagicDllKeThResPppPatch` — 분석한다 `ppp_dataA` + 디스크상의 blob, 주황색을 적용 (범위 `ppp-only`); 출력 `magic_0716_kethres_orange.dll`. RT2 게임 내 처리 대기 중. [이전: 

`v2.101.0.1`]
- **`v2.101.0.1` — ThundaFira: KeThRes 정적 덤프 (`--thundafira-kethres-dump`).** Lane **Jarvis-MAGIC**. **PATCH**: `MagicDllKeThResDumper` — PE에서 blob/handle/PPP 카탈로그 추출 `0094` + manifest/hex MD. [이전: `v2.101.0.0`]
- **`v2.101.0.0` — ThundaFira: KeThRes PPP 파서 (`--thundafira-kethres-parse`).** 레인 **자비스-MAGIC**. **MINOR**: `MagicDllKeThResParser` — PPP 오프코드 카탈로그 `0x55D4456F`, `pppKeThRes32x4` + score phyre PS3; IDA draw-path 문서. [이전: `v2.100.0.3`]
- **`v2.100.0.3` — ThundaFira 1단계: RT2 듀오 vec4를 바닥에 (`--offset2`).** Lane **Jarvis-MAGIC**. **PATCH**: `--thundafira-ppp-color-test` 수락 `--offset` + `--offset2` (최대 2) 및 `--rt2-tag` RT2의 B 지점을 이등분하기 위해. [이전: `v2.100.0.2`]
- **`v2.100.0.2` — ThundaFira 1단계: RT2 FAIL로 인해 PPP 런타임 사이트가 중단됨. ** Lane **Jarvis-MAGIC**. **PATCH**: RT2 Halyson — `full_phase1` 광선에 색상이 없고, 애니메이션이 더 빠르거나 평평함 (타이밍과 색상 혼동); 게이트 `--thundafira-ppp-runtime-color` 그저 `--restore`. Doc `FFX_THUNDAFIRA_PHASE1_RUNTIME_PATCH_RT2_FAIL_2026-06-14.md`. [이전: `v2.100.0.1`]
- **`v2.100.0.0` — ThundaFira 1단계: 확장된 PPP 색상 런타임 패치 (기본 브랜치 + 볼트 스폰).** 레인 **Jarvis-MAGIC**. **사소한 변경**: `--thundafira-ppp-runtime-color --site full_phase1` — IDA는 몬스터 캐스트가 **default** 브랜치를 사용한다는 것을 증명했다. `Thundaga_EgoTaskSetup_0094` (LABEL_9 플레이어 ID 제외); host+1072 및 RGBA spawn 브랜치 모두에 패치를 적용합니다. `Thundaga_EgoTaskTick_0094`. Doc `FFX_THUNDAFIRA_PHASE1_RUNTIME_PATCH_2026-06-14.md`. 인간 RT2 미처리. [이전: `v2.99.0.0`]
- **`v2.99.0.0` — ThundaFira: PPP 색상 런타임 패치 (IDA 호스트+1072).** Lane **Jarvis-MAGIC**. **MINOR**: 게이트 `--thundafira-ppp-runtime-color` — 패치 즉시 적용 `.text` 에서 `sub_10006B50` (`magic_0716.dll`); scan `.data` RT2 이후 vec4가 폐기됨. Doc `FFX_THUNDAFIRA_PPP_RUNTIME_COLOR_IDA_2026-06-14.md`. [이전: `v2.98.1.0`]
- **`v2.98.1.0` — ThundaFira: phyre RT2 분류기 (128_128 ≠ 레이).** Lane **Jarvis-MAGIC**. **PATCH**: `ThundagaPhyreClassifier` — RT2 Halyson이 증명했다 `_128_128` 에서 `0716` = 땅에 부딪히는 섬광 / 폭발, **번개는 아님**; `--bolts-orange` 이름이 변경된 comport

WARN을 사용한 그라운드 플래시에 대해 설명합니다. Doc `FFX_THUNDAFIRA_PHYRE_SHEET_RT2_2026-06-14.md`. [이전: `v2.98.0.0`]
- **`v2.98.0.0` — 텍스트: 2바이트 글리프 디코딩/인코딩 (FTCX/FONTk) + EncounterTable 이름 변경 `MapNamePadding`.** 레인 **자비스-MAGIC**. **MINOR**: `FfxEncoding.glyph.cs` — 바이트 `0x06` 그리고 `0x26..0x2F` 더 이상 ~가 아니다 `<C6>`/`<C38..>` 그리고 토큰을 얻었다 `<FTCX:n>`/`<FONTk:n>` 바이트 단위의 왕복(`TextBinary_Util.TryMatchGlyphToken`, 비차단 검사). **PATCH** 외관 수정: `Unknown0C` → `MapNamePadding` 에서 `EncounterTable_File` (IDA 검증: map-name 문자열의 종결자). Worktrees Claude `851-1/2/3/4` 선별 결과: 유용한 것만 남기고 나머지는 버림. [이전: `v2.97.0.0`]
- **`v2.97.0.0` — ThundaFira: Family D PPP 프로브 + 수정된 RT2 리컬러.** 레인 **Jarvis-MAGIC**. **사소한 사항**: 게이트 `--thundafira-ppp-probe` (지원자 `pppColMove`/`pppKeThRes` 에서 `magic_0094`), `--thundafira-ppp-color-test` (수술용 패치 1 오프셋), `--thundafira-recolor --phyre-anim1`; 스플릿 팩 기본값 `716/717` donor와 함께 `0095`; `MagicDllPppColorCandidateScanner`; vec4 헤우리스틱 `0716.dll` **은퇴한** (RT2: `0x31640` = PPP 행렬, 2D 반지름). 문서: `FFX_THUNDAFIRA_HANDOFF_CONTINUE_2026-06-14.md`. [이전: `v2.96.0.0`]
- **`v2.96.0.0` — Kernel monmagic 라이브 동기화 + 알 베드 사전 편집기.** Lane **Jarvis-MAGIC** + 텍스트. **사소한 문제**: `KernelMonsterMagicLiveSync` 읽다 `monmagic1.bin`/`monmagic2.bin` 프로젝트에서 불러오기/저장 시 변수명 및 피연산자를 복제합니다 `0x4xxx`/`0x6xxx` 새로운 `CommandMonster*`, `AiCommandId`, `AiCommandMetadataCatalog` 그리고 Monster AI 피커 (spell LAB에 의한 수동 패치 없음); **Al Bhed Dictionary** 모듈 (`albheddic.bin` (미국 라틴 문자 + 일본어 가나) 및 Rail의 바이트 안전(byte-safe) Writer `???`. RT2 ThundaFira 게임 내 대기 중. [이전: `v2.95.0.0`]
- **`v2.95.0.0` — ThundaFira: LAB의 마법 Thundaga+Multi-Fira + 에디터 내 UI.** Lane **Jarvis-MAGIC**. **MINOR**: 게이트 `--thundafira-pack` (grow monmagic2 #248, 클론 `magic_0716`/`0717`, 텍스처 thunder+fire); `--prism-flare-recolor` (진한 보라색으로 다시 색칠) `magic_0715`); **Monster Commands 2** → Install/Deploy visuals 버튼. [이전: `v2.94.0.0`]
- **`v2.94.0.0` — Magic DLLs: UI에 wave4 출처 표시 + p

Magic Viewer / Phyre Package I/O.** Lane **Jarvis-MAGIC**. **MINOR**: `MagicDllWave4CatalogLoader` 오프라인 분류 체계(범주, 과, 커널 참조, 오버레이 시그니처, 편집 지침)를 `Extras → Magic DLLs (FFX)`; 목록에 있는 배지; **Wave4 Attribution** 카드; **Magic Viewer** 버튼 (`?magic=####`) 및 **Phyre Package I/O** (첫 번째 `.dds.phyre` (PS3용); `scripts/magic_viewer_merge_wave4_catalog.py` wave4를 다음 위치에 병합합니다 `magic-viewer-catalog.json`; 뷰어의 HUD에 W4 배지가 표시됩니다. [이전: `v2.93.0.0`]
- **`v2.93.0.0` — 매직 DLL: wave3 분류 + wave4 딥 코퍼스 + 고아 속성 카탈로그 + Hex-Rays 후처리. **Lane **Jarvis-MAGIC**. **MINOR**: 게이트 `--magicdll-classify-wave3`, `--magicdll-deep-corpus-wave4`, `--magicdll-orphan-catalog`; `MagicDllMoveAnimParser` 수정 `moveAnim=magic_XXXX/None` (+44 주문 링크); 다중 출처 분류 체계 (463 `catalog_and_kernel`, 109 `engine_overlay_carrier`, 9개의 트윈, 2개의 클론); 스크립트 `magic_dll_hexrays_postprocess_host.py`, `magic_dll_hexrays_host_profile.py`, `magic_dll_wave4_rt2_queue.py`; Hex-Rays 2차 배치 처리 + 자동 후처리. wave3/wave4/orphan 카탈로그 문서. RT2 인게임 처리 대기 중. [이전: `v2.92.0.0`]
- **`v2.92.0.0` — Magic DLLs: Hex-Rays ALL 티어 (1829/1829) + idalib 병렬 배치 처리 + RT2 시각적 게이트 준비.** Lane **Jarvis-MAGIC**. **MINOR**: `scripts/magic_dll_hexrays_batch.py` (`--tier all|pinned|shared`, `--workers N`, `--remaining-only`, 격리된 스테이징 `w0..wN`); wave2 코퍼스 **534개 DLL / 1829개 슬롯** Hex-Rays에서 `work/magic_dll_logical_decompile_wave2/hexrays_output/` (6명의 작업자가 참여할 경우 약 16분); 게이트 `--magicdll-rt2-visual-prep` DLL을 생성합니다 `magic_0084`/`magic_0098` + 오프라인 패치 계획. 문서: `FFX_MAGIC_DLL_HEXRAYS_ALL_COMPLETE_2026-06-14.md`, `FFX_MAGIC_DLL_HEXRAYS_PINNED_PROGRESS_2026-06-14.md`, RT2 체크리스트 0084/0098 업데이트됨. 정직성: 디컴파일된 C ≠ 시각적 의미; RT2 인게임 (Prism + lab DLL) 미처리; 코드 슬롯이 없는 코퍼스 내 DLL 약 49개가 대기 중. [이전: `v2.91.1.0`]
- **`v2.91.1.0` — Arena+: OST 배틀 엔트리 후크 v4 + 브리프 Opus + 오프셋 Dark Aeon 정렬.** 레인 **Jarvis-ARENAPLUS**. **패치**: `MusicHook` 이중 가로채기 `PlayTrack(16)` 출처: `soundcmd 23` (prob

e) 기본(vanilla) 폴백을 사용하는 경우; `SwitchCrossfade(16)` arg 교체; 제거 `SwitchCrossfade` 심(shim)에 직접 연결됨 (소음이 발생함). `dllmain` ~하기 전에 보류 중 `781D60`; fallback 스레드는 인터셉트가 발생했을 때만 사용되며, 리소스를 소모하지 않습니다. 설정 실험실 `RuntimeTools/FfxHooksDll/config/arena_plus_music_*.txt`. `MemoryMap.ADDR_DARK_AEON_FLAGS=0xD2E384`; `ffxprobectl arena-flags` RVA 수정됨. 문서: `OPUS_BRIEF_ARENA_PLUS_MUSIC_2026-06-14.md`, `OPUS_BRIEF_ARENAPLUS_RESEARCH_QUEUE_2026-06-14.md`; Arena+ 자료집에 실린 오프셋 교정 배너. RT2 OST는 아직 미정. [이전: `v2.91.0.0`]
- **`v2.91.0.0` — Magic DLLs: 논리적 디컴파일 웨이브 1/2 + 브라우저 UI (Family Comparator, PS3 브리지, 논리적 디컴파일 탭).** Lane **Jarvis-MAGIC**. **MINOR**: `MagicDllLogicalDecompiler` (정적 호스트 오프셋 지문 + 의사코드/슬롯 클러스터링), 게이트 `--magicdll-logical-decompile-wave1` (119개의 DLL 샘플) 및 `--magicdll-logical-decompile-wave2` (583/583 코퍼스 + Hex-Rays의 pinned/shared/all 스레드); `MagicDllFamilyComparator` + `MagicEffectClonePipeline` (deploy ps3data clone); **Logical Decompile** 탭에서 `Extras → Magic DLLs (FFX)` 슬롯별 표/의미 코드, Value Workbench의 Family C/D 알림, PS3 Magic/extract/mods 바로가기 및 브리지 `Open PS3 Magic (HD)`. 문서: `FFX_MAGIC_DLL_LOGICAL_DECOMPILE_WAVE1_2026-06-14.md`, `FFX_MAGIC_DLL_LOGICAL_DECOMPILE_WAVE2_2026-06-14.md`. 빌드 릴리스 0 오류. [이전: `v2.90.1.0`]
- **`v2.90.1.0` — Prism Flare v2 팩 (게임플레이 + 프리즘 DLL 색상 변경 + 배포).** Lane **Jarvis-MAGIC**. **MINOR**: 게이트 `--prism-flare-v2-pack` — 행 #247 파워 42, 불/번개/물, 느림 65%/4t; 색상 변경 `magic_0714/0715` (각각 16개의 vec4 패치, 보라색 프리즘). [이전: `v2.90.0.3`]
- **`v2.90.0.3` — Magic VM: 2+3 클러스터 통과 (MISC→0) + RT2 시각화 0084/0098.** Lane **Jarvis-MAGIC**. **REVISION**: 2차 통과 `analyze_batch` (66 MISC) + 나머지 10개에 대한 Hex-Rays 디컴파일 3회 → `cluster_assignments_pass3.csv` (119/119, 행동 클러스터 포함). 문서: `FFX_MAGIC_VM_MISC_PASS3_DECOMPILES_2026-06-14.md`, `FFX_MAGIC_RT2_VISUAL_0084_0098_2026-06-14.md`. [이전: `v2.90.0.2`]
- **`v2.90.0.2` — Magic VM: 자동화된 클러스터 1단계 (119/119 코어 작업).** Lane **Jarvis-MAGIC**. **REVISION**: `f

unc_query` IDA + `work/magic_vm_cluster/cluster_from_func_query.py` → `cluster_assignments.csv` (9 clusters; 66 MISC aguardam pass 2 callees). Doc clusters atualizado com fila decompile top-3/cluster. [anterior: `v2.90.0.1`]
- **`v2.90.0.1` — 매직 엔진: 통합 허브 + VM 클러스터 + A/C 편집 가이드. **Lane **Jarvis-MAGIC**. **REVISION**: VM EXE를 연결하는 RE 문서, 581개 DLL 분류 및 실전 편집. `FFX_MAGIC_ENGINE_MASTER_2026-06-14.md` (허브), `FFX_MAGIC_VM_OPCODE_CLUSTERS_2026-06-14.md` (7개 클러스터, IDA 표본), `FFX_MAGIC_FAMILY_AC_EDITING_GUIDE_2026-06-14.md` (색상/속도: Value Workbench 기준, A/C 제품군). [이전: `v2.90.0.0`]
- **`v2.90.0.0` — Magic DLLs: 브라우저의 슬롯 0에 대한 바이트 스캔을 통해 A/B/C/D 계열을 분류합니다.** Lane **Jarvis-MAGIC**. **MINOR**: `MagicDllFamilyClassifier` 문 `scripts/scan_ab.py` C#용 — 다음 기준에 따른 사전 분류 `slot_kind_signature` + 슬롯 0의 RVA에서 2048바이트 PE 스캔 (`0xB2C/0xB30` → B, `0xB1C/0xB18` → C). 통합된 `MagicDllSemanticAnalyzer.DetectFamily` 그리고 `InspectionSummary` Magic DLL Browser에서. IDA 검증: 버킷 404에 침투한 13개의 Family C DLL 중 3개 샘플 (`magic_0183`, `magic_0244`, `magic_0700`)는 확인한다 `host+2844/2840` ~ 없이 `host+2860`. 문서: `docs/reverse/FFX_MAGIC_DLL_INFILTRATED_C_VALIDATION_2026-06-14.md`. 게이트 바이트 스캔 13/13 via `work/validate_infiltrated_c/validate.py`. [이전: `v2.89.0.0`]
- **`v2.88.1.5` — Magic DLL: 실제 디컴파일(Hex-Rays)을 통해 두 가지 효과 아키텍처와 검증된 호스트 필드가 밝혀졌다. **Lane **Jarvis-MAGIC**. **REVISION**에 대한 `v2.88.1.4`: 저장소에 RE가 그대로 남아 있음 (디컴파일 + 파일 이름 변경/주석 처리) `.i64`), 제품의 동작에는 변화가 없습니다. “위치에 따른 이름 지정”(휴리스틱) 방식에서 벗어나 `MagicDllSemanticAnalyzer`) 그리고 실제로 디컴파일했다 `magic_0084` 그리고 `magic_0148` IDA에서. 핵심 발견: 코퍼스에는 슬롯 종류 시그니처로는 구분되지 않는 **≥2개의 서로 다른 아키텍처**가 존재한다(둘 다 `code` (모든 슬롯에서): **“자립형 입자” 계열** (`magic_0084`: 1023개의 입자로 구성된 로컬 풀 + 256개의 패킷으로 구성된 링, 루트 없음 `dat_et`; slot1은 렌더링 틱이며; slot4는 **오버레이 테이블 자체를 재작성**하여 다음 단계로 넘어가게 합니다 — `magi`에서도 확인됨

c_0688`) e **família B "root/record-interpreter"** (`magic_0148`: aloca o root de 1.024.000 bytes via host+3212, materializa via host+2860, e chama host+2864=`sub_80CD60` e host+2884=`sub_80BEA0` diretamente). Promovi ~20 host fields de `후보자` para **provado por chamada decompilada cross-DLL** (host+672 actor, +884/+888 timer, +900/+904/+908 phase/start/progress, +2860 materialize, +2864 interpreter, +2872/+2876 Ego obj, +2908 make-packet) e descobri o par novo **host+3216 (free)** de host+3212. Doc: `docs/reverse/FFX_MAGIC_DLL_DECOMPILED_FAMILIES_2026-06-13.md`. Bump do editor para `2.88.1.5`. Guardrail: ainda é RE de bytes, nomes descrevem papel (não símbolo original); slot-kind signature é proxy fraco — o classificador real de família é "slot 0 chama host+2860?". Validação: 2 `.i64` salvos no `magicFiles\FFX` com rename+comment; renames `17/17` (0084) e `10/10` (0148) OK. [anterior: `v2.88.1.4`] — Jarvis-MAGIC
- **`v2.88.1.4` — 심층 분석: 60fps 게임플레이와 30fps 컷신/FMV. **Lane **Jarvis-FPS**. **REVISION**에 대한 `v2.88.1.3`: 리포지토리에 저장된 검색/RE, 제품 동작 변경 없음. 관련 문서 `docs/reverse/FFX_GAMEPLAY_60FPS_DEEP_RESEARCH_2026-06-13.md` 사용자가 제시한 새로운 범위에 부응합니다: 컷신은 30fps로 유지될 수 있으며, 핵심은 게임플레이입니다. 결론: 이는 시청각적 범위를 축소하지만, 문제를 단순한 캡처 작업으로 바꾸지는 않습니다. 게임플레이에서는 여전히 필드, 전투, MSEQ, 카메라, CTB, 마법/VFX, 메뉴, 로딩 및 미니게임을 분리해야 합니다. 이 연구에서는 다음 네 가지 경로를 상세히 설명합니다: `visual 60` 프레임 생성/보간, 프레임 페이싱/VRR/Present Doctor를 통해, 30 프레임 시뮬레이션과 내장 보간기를 사용하여 60 프레임으로 렌더링하고, 그리고 `engine-exact 60fps` 스카우트가 분리 가능한 클럭을 입증할 때까지는 문샷으로 간주한다. 다음 기술적 단계: `fps-scout` CSV/summary의 읽기 전용 `Present`, 하트비트/틱, 게임 모드, MSEQ 커서 및 UnX/SpecialK 호환성을 모든 패치 적용 전에 확인하세요. 편집자 게시물 상단 이동: `2.88.1.4`. 검증: 문헌 출처 링크를 통해 `Test-Path`/`rg`; 빌드 `work\_build_gameplay60_research_28814` 오류 0개 / 기준 경고 366개. [이전: `v2.88.1.3`] — Jarvis-FPS
- **`v2.88.1.3` — 60fps 테스트 / FPS 잠금 해제: 프레임 생성, 프레임 페이싱 및 엔진 정밀도 분리.*

* Lane **Jarvis-FPS**. **수정** 내용: `v2.88.1.2`: 리포지토리에 저장된 검색/RE, 제품 동작 변경 없음. 관련 문서 `docs/reverse/FFX_60FPS_UNLOCK_FEASIBILITY_RESEARCH_2026-06-13.md` 안전한 30→60 단순 캡에 대한 증거는 없다고 결론지으며, 정직한 경로는 다음과 같이 나뉩니다. `visual 60` 프레임 생성/외부 보간을 통해, 30fps에서 프레임 페이싱이 더 우수하며, 30fps 시뮬레이션과 내부 보간을 적용해 60fps로 렌더링하고, 그리고 `engine-exact 60fps` moonshot/research-only로 분류됩니다. 교차 증거: UnX는 곱셈을 통해 스피드 해킹을 수행합니다. `FFX_GameTick` 일반적인 시간 잠금을 해제하는 대신; Special K/UnX는 30의 외부 캡이 로드 성능에 영향을 줄 수 있으며 일부 메뉴는 60으로 실행된다고 경고합니다; 저장소에는 이미 DINPUT8/main-thread, Present hook 및 MSEQ가 포함되어 있습니다 `frameRate=7680 (30fps*256)`, 하지만 magic/battle/cutscene은 아직 프레임 단위의 정확한 타이밍을 지원하지 않습니다. 다음 단계는 다음과 같습니다: `fps-scout` read-only에서 `FfxHooksDll`/`FfxDinput8Probe` 패치를 적용하기 전에 Present, tick, MSEQ 커서 및 게임 모드를 측정합니다. 에디터에서 Bump를 `2.88.1.3`. 검증: 문헌 출처 링크를 통해 `Test-Path`/`rg`; 빌드 `work\_build_fps_research_28813` 오류 0개 / 기준 경고 366개. [이전: `v2.88.1.2`] — Jarvis-FPS
- **`v2.88.1.2` — 매직 DLL: 유사한 마법들 간의 패턴을 분석하여, 시행착오를 최소화하며 색상/속도를 파악합니다.** Lane **Jarvis-MAGIC**. **REVISION**에 대한 `v2.88.1.1`: 리포지토리에 저장된 연구/RE이며, 제품 동작에는 변경 사항이 없습니다. 교차 확인 `AiCommandMetadataCatalog.Generated.cs` (`979` rows, `689` ~와 함께 `moveAnim`), CSV 오버레이 (`581` rows) 및 DLL `magicFiles\FFX\magic_####.dll` 단순한 이름 대신 실제 외관에 따라 분류하기 위해. 주요 결과: `Power`/hits/status는 명령어 행에 표시되고, 시각 정보는 `moveAnim`; 기본 불/번개/물 속성은 단순한 계열을 따릅니다 `nz9/u5`, Ice/curas/Flare 계열은 더 폭넓은 PPP 계열을 사용하며; Cure/Potion 및 여러 Mixes는 비주얼을 재사용합니다; `Death` 동일한 이름이 서로 다른 DLL을 가리킬 수 있음을 보여줍니다; `Death` 일반적인 `magic_0098` 그리고 `Mega Death` `magic_0351` 오버레이/슬롯/텍스처 크기는 공유하지만, 해시/페이로드는 공유하지 않음; 클론 `0714/0715` Fira/Thundara 바닐라 버전에 영향을 주지 않으면서 Prism Flare로 향하는 올바른 길을 계속 이어갑니다. 가드레일: `pppColor`/`pppColMove`/`pppAccele`, floa

ts와 pushes는 RT2/probe가 색상, 속도 또는 타이밍을 검증할 때까지 후보들을 계속 추적합니다. 편집자의 Bump로 `2.88.1.2`. 검증: 다음을 통한 문서적 근거 `Test-Path`/`rg`; 빌드 `work\_build_magic_patterns_28812` 오류 0개 / 기준 경고 366개. [이전: `v2.88.1.1`] — Jarvis-MAGIC
- **`v2.88.1.1` — Arena+ pre-RT2: DLL을 통해 NPC의 새로운 옵션에 맞춰 버전 관리된 조사 패키지. **Lane **Jarvis-ARENA+**. **REVISION**에 대한 `v2.88.1`: 리포지토리에 반영된 연구/RE, 제품 동작 변경 없음. Monster Arena/Arena+의 파일 세트 버전 업데이트: 새로운 탭/크리에이션, DLL을 통한 삽입, 실제 패배 시 Dark Aeon/Penance 플래그, NPC 옵션, 최종 스카우트 및 파일 `nagi0700` pre-RT2. 핵심 발견: 아레나의 소유주는 이 행사 속에서 살아간다 `nagi0700`; `w0E::f05` 메뉴를 구성하세요 `Now what?` 출처: `Common.displayFieldChoice [013B]` 문자열 `[4A]`, `w0E::f07` 선택기를 열려면 `SgEvent.showModularMenu [401D]`, ~를 위한 투쟁을 시작하다 `Battle.launchBattle [7002]` 그리고 패배한 크리에이션 브랜드들 `0x0300..0x0322` 작성자: `Common.setMonsterArenaUnlocked [0210]`. 편집자의 붐프: `2.88.1.1`. 가드레일: `research-only/pre-RT2`; 확장하지 않음 `ArenaUnlocks[35+]`, 편집하지 마세요 `nagi0700.ebp` 그리고 실제 실행 시 trace 전에 row vanilla를 삽입하지 마십시오. 검증: `Test-Path` + `rg` 도큐멘트, KB 및 핸드오프의 앵커; 빌드 `dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_versioning_28811 --no-restore` 오류 0개 / 기준 경고 366개. [이전: `v2.88.1`] — 자비스
- **`v2.88.1` — Magic Viewer Web: 런타임 시뮬레이션 후보작이 메인 무대에 올랐습니다. **Lane **Jarvis-MAGIC**. **PATCH**에 대한 `v2.88.0`: 뷰어에 새로운 모드가 추가되었습니다 `Simulate`, 이는 텍스처 슬라이드쇼를 역방향 구조 체인에 따라 반복되는 루프로 대체하며 (`sub_800530/590/950`, `sub_80CD60`, `sub_817200`, `root+84/root+88`, 오버레이 슬롯 및 페이로드 Phyre). 텍스처는 `ps3data\magic` 이제 시계/프레임 목록이 아닌 효과의 시각적 요소로 포함됩니다. HUD에는 페이즈, 루트 커서, 콜백 코드/데이터 및 DLL의 반복된 별칭이 표시됩니다. Guardrail: 이것은 `Runtime Simulation Candidate`, ~보다 덜 가짜인 `Cycle Surface`, 하지만 아직 프레임 단위 정밀 타이밍, 완전한 오프코드 인터프리터, 또는 RT2 상관 분석 기능은 지원되지 않습니다 

게임 내 callbacks/frame. 에디터에서 Bump를 통해 `2.88.1.0`. 검증: `node --check RuntimeTools\FFXMagicViewerWeb\app.js`; HTTP `http://127.0.0.1:8766/index.html?magic=0688` 200; Chromium 헤드리스 클릭 `Simulate` 데스크톱 및 모바일에서 390px, 페이지 오류/콘솔 오류 없음, 모바일에서 가로 오버플로우 없음, 스크린샷 `work/magic_viewer_runtime_simulation_0688.png` 그리고 `work/magic_viewer_runtime_simulation_0688_mobile.png`; 빌드 `dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_magic_runtime_sim_2881 --no-restore` 오류 0개 / 기준 경고 366개. [이전: `v2.88.0`] — Jarvis-MAGIC
- **`v2.88.0` — 매직 DLL(FFX): 색상, 속도, 타이머 및 후보 벡터를 위한 Value Workbench. **Lane **Jarvis-MAGIC**. **MINOR**에 관하여 `v2.87.1`: 탭 `Extras -> Magic DLLs (FFX) / Role Candidates` 이제 하나가 있다 `Candidate Value Workbench` 선택한 DLL을 스캔하여 다음을 검색하는 편집 가능한 도구 `float32`, `vec3f/vec4f` 그리고 `push imm8/imm32`, 후보를 alpha/cor/scale/speed/timer/flag/count로 분류하고, decimal/float/comma-vector 형식으로 새로운 값을 입력하거나, `Stage Patch` 또는 다음을 사용하여 출력 DLL을 생성하거나 `Apply To Output`. 블록 `Host Context / InitMagicPRX Fields` 이 기능도 지원 대상이 되었습니다: 호스트 필드를 선택하면 DLL 내의 실제 u32 발생 위치를 나열하고, 구체적인 오프셋 참조를 변경할 수 있게 해줍니다. Guardrail: 이름은 후보 목록을 따르며, 변경 사항마다 시각적/게임플레이적 의미를 확인하기 위해 RT2 테스트가 필요합니다. 에디터에서 Bump로 `2.88.0.0`. 검증: `dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_magicdll_value_workbench_probe --no-restore` 오류 0개 / 기준 경고 366개. [이전: `v2.87.1`] — Jarvis-MAGIC
- **`v2.87.1` — 내장형 Magic Viewer: WebView2의 404 오류에 대한 핫픽스. **Lane **Jarvis-MAGIC**. **PATCH** 관련 `v2.87.0`: 문이 `8766` 이미 한 명이 차지하고 있었기 때문에 `http.server` 오래전부터 깊이 뿌리내린 `RuntimeTools/FFXMagicViewerWeb`; 런처는 해당 포트가 활성화되어 있음을 감지하고 다음으로 이동했다 `/RuntimeTools/FFXMagicViewerWeb/index.html`, 그 404 서버에서 말이죠. `MagicViewerLauncher` 이제 repo-root URL을 테스트하고, 응답이 없으면 자동으로 `/index`로 이동합니다.

html`, mantendo o viewer embutido funcional sem depender de matar o servidor manualmente. Bump do editor para `2.87.1.0`. Validacao: HTTP atual provou `/RuntimeTools/FFXMagicViewerWeb/index.html -> 404` e `/index.html -> 200`; build `work\_build_magicviewer_url_hotfix` com 0 erros / 366 avisos baseline. [anterior: `v2.87.0`] — Jarvis-MAGIC
- **`v2.87.0` — Magic DLLs (FFX): 메뉴 내에 Direct Patch Builder가 있습니다. **Lane **Jarvis-MAGIC**. **MINOR**에 관하여 `v2.86.2`: 면적 `Extras -> Magic DLLs (FFX)` 이제 직접 작성한 패널을 통해 다음을 기반으로 바이트 패치 또는 ASCII 패치가 적용된 출력 DLL을 생성합니다. `file offset` 또는 `RVA`, 사용자가 외부 JSON을 직접 구성할 필요 없이 기존 컴파일러/패치 플랜을 재사용합니다. 선택된 원본 파일은 덮어쓰이지 않으며, 버튼은 항상 출력 DLL을 요청합니다. Guardrail 유지: `Role Candidates` 그리고 `Host Context / InitMagicPRX Fields` 증거/후보 이름이 계속 추가되고 있습니다. 실제 동작을 구현하려면 특정 주소의 바이트/문자열/ASM에 패치를 적용해야 하며, 수동 C/ASM 또는 RT2를 사용해야 합니다. 에디터 버전을 `2.87.0.0`. 검증: `dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_magicdll_direct_patch_2870 --no-restore` 오류 0개 / 기준 경고 366개. [이전: `v2.86.2`] — Jarvis-MAGIC
- **`v2.86.2` — Magic Viewer Web이 메인 무대에서 본격적인 DLL/런타임 리더로 자리 잡았습니다. **Lane **Jarvis-MAGIC**. **PATCH**에 대한 `v2.86.1`: o `MagicCorpusIndexer` 지금 바로 읽어보세요 `magicFiles\FFX\magic_####.dll` 그리고 증거를 생성합니다 `runtimeDll` 카탈로그에서 (`runtime-dll-index.json`): PE 종류/머신/타임스탬프, SHA-256, 섹션, 내보내기/가져오기, 문자열/패밀리 및 오버레이 슬롯이 후보 역할이 포함된 CSV 파일에서 보존됩니다. 내장 뷰어는 다음을 열어 표시합니다. `Runtime Map` 메인 뷰포트에서, 어떤 텍스처보다 먼저: DLL, PE, 익스포트/임포트, 섹션, 문자열 패밀리, 페이로드 링크 및 실제 콜백/데이터 슬롯을 표시합니다; `Cycle Surface` 그리고 `Stack Surface` Phyre/texture 페이로드 검사의 보조 방식으로 바뀌었습니다. 에디터의 범프 효과를 `2.86.2.0`. 검증: `MagicCorpusIndexer` 빌드 오류 0건; 빌드 편집기: `work\_build_magic_runtime_reader_2862` 오류 0개 / 경고 366개 (기준선); 로컬 카탈로그 재생성됨 `587 entries`,

 `580 ps3 magic`, `583 runtime DLLs`, `581 overlay rows`; HTTP 200; Edge 헤드리스에서 확인됨 `magic=0688` 그리고 `magic=0003` ~와 함께 `Runtime Map` 활성, `slotCount=16`, 페이지 오류 없이, 스크린샷 포함 `work/magic_viewer_runtime_map_0688.png` 그리고 `work/magic_viewer_runtime_map_0003.png`; 모바일 390px, 수평 오버플로우 없음. 솔직히 말해서: 캐리어 런타임/Phyre의 실제 플레이어; 아직 프레임 단위의 정확한 재생은 지원되지 않으며, 타임라인/컴파일러나 RT2도 마찬가지입니다. [이전: `v2.86.1`] — Jarvis-MAGIC
- **🔮 `v2.86.1` — Battle Commands 브리지 → PS3 Magic + Magic Viewer Web 잠금 해제. **Lane **Jarvis-MAGIC**. **PATCH** 정보 `v2.86.0`: 이미 배포된 기능에 대한 재사용/편의성 및 부트/카탈로그 고정. 필드 `Anim 1 Id` / `Anim 2 Id` 에서 `Battle Commands / Monster Commands` 이제 다음의 요약을 보여줍니다. `magic_####`, 버튼 `View Anim 1/2` 열려면 `Extras / PS3 Magic (HD)` 효과가 이미 적용된 상태이며, 버튼 `Open Folder` 폴더가 다음 위치에 존재할 때 `ps3data\magic`. 또한 내장된 Magic Viewer Web이 다음을 사용하도록 수정합니다. `three`/`OrbitControls` 상대 경로 임포트를 통해, 화면이 멈출 수 있는 의존성을 제거함으로써 `Loading catalog`; WebGL이 실패할 경우, 카탈로그가 아무런 오류 메시지 없이 종료되는 대신 오류가 표시됩니다. 편집자 측에서 다음과 같이 수정해 주세요. `2.86.1.0`. 검증: `dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_versioning_2861` 오류 0건; HTML/vendor/catalog가 HTTP 200 상태로 제공됨; CDP/Chrome에서 확인됨 `585 entries`, `583` 항목 및 `exceptions=[]`; 스크린샷은 `work/magic_viewer_web_smoke_fixed.png`. 정직성: HD 미리보기는 대략적인 텍스처/합성 결과이며, 타임라인/콜백 엔진 정확도는 DLL/런타임 상태를 유지하며 최종 게임플레이를 위해서는 RT2 테스트가 필요합니다. [이전: `v2.86.0`] — Jarvis-MAGIC
- **🔮 `v2.86.0` — 새로운 콘텐츠 제작 연구소. **Lane **Jarvis-MAGIC**. **MINOR**에 관하여 `v2.85.2`: 커밋에 포함된 새로운 콘텐츠 랩 패키지를 공식적으로 버전 관리합니다 `ac2f5ebe`. AutoAbility writer AU1..AU7, Monster Magic/Prism Flare 툴링, Magic DLL(FFX), VBF Extract(추출 전용), PS3 Magic 텍스처 I/O 및 Phyre Package I/O가 포함되어 있습니다. 에디터 버전을 `2.86.0.0`. 정직성: 마법/이펙트/텍스처 랩은 여전히 RT0/오프라인, 텍스처 I/O 동일 형상 및 

RT2 매뉴얼; 타임라인/콜백 엔진-정확한 연속 DLL/런타임. [이전: `v2.85.2`] — Jarvis-MAGIC
- **🧠 `v2.85.2` — Monster AI Editor: ‘Forbidden Rite’ 공개 + 스테이지 매니저 조건 리드백. ** Lane **Jarvis-MAGIC**. **PATCH**에 대한 `v2.85.1`: 공인 도장을 제거합니다 `LAB` Forbidden Rite/var priv/writer의 회전 방식은 이미 저작 흐름으로 검증됨; 제거 `Sequência / Multi-*` 가짜 Multi-*가 판매되는 것을 방지하기 위해 빠른 흐름 방식을 채택하고, 창 내에서 의도된 순서를 유지합니다. `Ação composta`; 턴마다 ‘Forbidden Rite’를 추가하고, 턴 관리자에서 추가 HP를 저장하며; 빌더를 수정합니다 `Condição multivar livre` ~를 다시 열기 위해 `ConditionGuard` 재시작/재감사 후 선택된 단계의 shape stack/RPN을 디코딩하여 (`cond1 cond2 E/OU`) 그리고 해석하기 전에 우연의 여지를 제거합니다. 편집자의 붐으로 `2.85.2.0`. 검증: 격리된 환경에서 빌드 시 오류 0건, `phase-rotation-rt0` 319/319 중 `var1 store when present` 300/300, 그리고 `multivar-guard-rt0` 300/300. 게임 내 RT2는 최종 게임플레이를 위해 여전히 필수입니다. [이전: `v2.85.1`] — Jarvis-MAGIC
- **🧠 `v2.85.1` — Monster AI Editor: 위상 회전 관리자의 안정성.** Lane **Jarvis-MAGIC**. **PATCH**에 대한 `v2.85.0`: 필터/피커가 재구축될 때 스테이지 카드의 스킬 손실 문제를 수정했습니다 `PhaseAbilityOptions`, ~를 사용하여 `SelectedPhaseAbility` 안정적인 예측으로 간주하고 무시하면 `null` ComboBox의 과도 상태; LAB v1 리드백을 재구성합니다. `guard -> performCommand -> mutação de var -> RET/JMP`; 이전에 수행되던 자동 핀 기능을 제거합니다 `Fluxo de Raio`/`Fluxo de Fogo` 맨 위로 이동하고 시각적 선택 해제; 조건/경계 유지 `AliasKey`, UI가 첫 번째 변수로 돌아가는 것을 방지합니다. 편집기의 Bump를 `2.85.1.0`. 검증: 빌드 오류 0개, `phase-rotation-rt0` 319/319 중 `var1 store when present` 300/300, 그리고 `multivar-guard-rt0` 300/300. [이전: `v2.85.0`] — Jarvis-MAGIC
- **🧠 `v2.85.0` — Monster AI Editor: 페이즈 순환 관리자, 다변수 조건 및 시모어 복합 액션. **Lane** Jarvis-MAGIC**. **MINOR** (Monster AI Editor의 새로운 기능으로, 동일한 채팅에 여러 버그 수정 사항이 포함되어 있습니다). 다음을 추가합니다. `PhaseRotationRecipe` LAB v1: `AppendGu`를 통한 단계

ardedAction`, condição própria por fase ou fallback, alvo/chance por fase, mutações de var por fase (`+최소..+최대` e reset), `여기서 멈추세요`/RET e gravação com backup em monstro de teste. A janela de rotação agora audita vars, permite apelidos por monstro, cria var `priv` livre em LAB, monta condições multivar livres e preserva draft por contador/var. Também entra a janela de `복합 동작 · 시모어`, para montar sequências explícitas de habilidades com alvo entendido e Forbidden Rite planejado entre passos. Corrige bugs de estado do builder: avanço/reset escrevem a var explicitamente escolhida, a condição da fase não sobrescreve outras fases, reauditar preserva a var ativa, e o filtro de habilidade não apaga Thunder/Water/etc já usados no draft. AiScriptLab ganhou gates `--var-grow`, `--var-flow`, `--multivar-guard-rt0` e `--phase-rotation-rt0`; validação usada: build 0 erros, `phase-rotation-rt0` 319/319 com `var1 저장 (존재할 경우)` 300/300, e `multivar-guard-rt0` 300/300. Honestidade: writer LAB/offline; RT2 em jogo ainda obrigatório antes de chamar rotação de fase de comportamento final. [anterior: `v2.84.25`] — Jarvis-MAGIC
- **🧠 `v2.84.25` — Monster AI Editor: Yunalesca가 깔끔한 프리셋으로 변경되었으며, 관련 조건들이 주요 작성 워크플로로 이동되었습니다.** Lane **Jarvis-MAGIC**. **누적 패치 +5** `v2.84.20`: 동일한 블록에 빠른 의식, 상태, 고급 편집 기능이 혼재되어 있던 화면의 사용자 경험(UX)/계약을 수정했습니다. 이제 YUNALESCA는 전투 의식 없이, 상태/축복 프리셋만 포함된 영역으로만 남게 되었습니다. `Revezar 1/2`, 없이 `Revezar 1/3`, 없이 `Duplicar cast` 그리고 불필요한 조건문 서두가 생략되었습니다. 조건문 생성기는 `Adicionar / trocar comportamento`, 이 출판사의 대표작: `onTurn`, `Início`, `Sempre`, `onHit`, `Qualquer Hit`, `HP < %` 그리고 `Talvez 1 em K` 다음으로 생성되거나 변경된 동작을 준비하기 시작합니다. 메인 바는 선택된 동작에만 초점이 맞춰졌습니다 (`Trocar habilidade`, `Duplicar ação`, `Subir/Descer`, `Modo: fila/agora`, `Tirar ação`, `Desfazer backup`). 백엔드에는 명시적인 가드 기능을 통해 스킬을 생성하고, 액션 템플릿을 복사하며, 마운트 상태에서 ‘금지된 의식’을 연결할 수 있는 경로가 추가되었으며, 이를 위해 아이템을 판매할 필요는 없습니다. 

이는 Monster AI Editor 외부의 새로운 기능입니다. ‘Forbidden Rite’에 대한 설명이 사실에 맞게 수정되었습니다. 즉, 지정된 지점에서 행동이 생성되거나 변경된 직후 Anti-Ribbon이 적용되며, 다음과 같은 잘못된 경고는 더 이상 표시되지 않습니다. `Multi-*` 반드시 오류가 발생하지는 않습니다. 별도의 출력 빌드는 오류 0개로 통과했습니다. [이전: `v2.84.20.1`] — Jarvis-MAGIC
- **📚 `v2.84.20.1` — 연구: 새로운 오토 어빌리티(무기/갑옷 스킬) 생성 가능성 — 모든 경로 + 공식 레시피(byte-recipe).** Lane **Jarvis-MAGIC**. **REVISION** (4번째 자리: doc/RE/리포지토리에 포함되는 연구이며 **동작은 변경되지 않음** — 어떤 라이터/모듈/바인딩도 수정되지 않음). FFX HD PC에서 새로운 오토 어빌리티를 생성할 수 있는지, 그리고 어떻게 생성할 수 있는지를 확인하는 다중 에이전트 연구 (병렬로 실행되는 파인더 3개 워크플로우 + 적대적 검증). **결론:** 예, “새로운”의 3가지 의미와 **데이터 기반(DATA-DRIVEN) 대 ID별 하드코딩(HARDCODED-POR-ID)**이라는 명확한 구분이 존재합니다. (1) **플래그 조합에 의한 효과**는 데이터 기반이며 **IDA의 오프셋을 통해 입증됨** (`sub_79C610`/`sub_7861B0` OR-레코드 필드 누적 `0x6C` **~** 배우 `switch` ID**) → 바이트만 설정하면 어떤 슬롯이든 해당 효과를 상속받음; **전체 바이트 쿡북**을 디코딩하여 diff를 적용하면 `a_ability.bin` shipado (요소들 `0x11-0x15` Fire`01`/Ice`02`/Thunder`04`/물`08`/Holy`10`; status touch=`0x16+slot=50`/strike=100; stat% `0x55`+`0x56`; 자동차/SOS `0x5A`+`0x10`; 리본 `0x3C+slot=255`+`0x60`). (2) **실제 빈 슬롯 5개 129–133 (`0x81-0x85`)** (전부 0인 날짜) → 테이블을 확장하지 않고 용도 변경. (3) **Grow >0x86:** 놀랍게도 — **엔진이** 135번째 항목을 **수용**합니다 (`sub_7AB890` **파일 헤더**의 count/range를 리터럴 없이 읽습니다. `0x86`; 파일 크기에 따라 크기가 결정되는 버퍼); C# 가드 3개 + RT2 + 바이트 크기 제한으로만 잠금 `0x25800` + 2번째 장비 메뉴 구조 `0xC8=200`. **고정 제한:** ~31개의 어빌리티가 ID별로 하드코딩되어 있습니다(1비트 `0x62/0x64/0x66`, C 언어 핸들러 — 센서/퍼스트 스트라이크/카운터/피어싱/브레이크 리미츠/캡처/등) → **바이트 단위로 재현 불가**; 새로운 KIND 효과(생명력 흡수/반사%)는 **DLL 후크**를 통해서만 가능 (인프라 `DINPUT8` probe + `FfxHooksDll` PolyHook2 **이미 검증됨**) 또는 exe 패치. **ability-as-script (ATEL)**은 후크 프리 방식이라는 주장이 반박됨 p

플레이어가 장착 가능한 아이템 (바인딩 갭). 3개의 독립적인 스트림과 **fahrenheit** 오픈소스 구조체(바이트 단위)를 통해 교차 검증됨. **정직성:** 실제 슬롯 게임플레이를 편집했으며, 모든 것이 런타임/훅 처리됨 = **RT2/LAB 미확정**; `a_ability.bin` 계속 `reader+no-edit guard` 생산 중 (출하 승인 없음). 문서: `docs/reverse/FFX_AUTOABILITIES_NOVAS_MASTER_2026-06-11.md` (목차/결론) + `FFX_NEW_AUTO_ABILITY_FEASIBILITY_2026-06-11.md` (정적) + `FFX_AUTO_ABILITY_NEW_VIA_HOOK_DLL_RUNTIME_FEASIBILITY_2026-06-11.md` (런타임/DLL) + `FFX_AUTOABILITIES_NOVAS_VIAS_E_FORMULAS_COOKBOOK_2026-06-11.md` (12가지 방법 + 레시피 모음). [이전: `v2.84.20`] — Jarvis-MAGIC
- **`v2.84.20` — Monster AI Editor: Forbidden Rite/Anti-Ribbon 및 행동의 인간적 해석에 대한 버그 수정 패치 10개 추가. **Lane **Jarvis-MAGIC**. **누적 패치**에 대한 `v2.84.10`: 표면을 다듬어 `Forbidden Rite LAB` 이는 실제 표준의 일부에 불과한 것을 여전히 보여주고 있었는데 `writeChrProperty(target, field, value)` 이미 지원되고 있었습니다. Anti-Ribbon 드롭다운 메뉴에는 이제 음수 직접 필드가 나열됩니다: `Poison`, `Petrify`, `Power Break`, `Magic Break`, `Armor Break`, `Mental Break`, `Berserk`, `Sleep(255)`, `Slow(255)`, 그 외에도 첨단 기술들 `Provoke`/`Threaten`, 보존하며 `Zombie`, `Confuse`, `Silence(255)`, `Darkness(255)`, `Curse`, `Doom` 그리고 Doom 카운터들. `Zombie`/`Confuse`/`Silence`/`Darkness` 현재 표준에 따라 RT2/인게임으로 검증된 것으로 명시적으로 표시되며, 확장 기능은 동일한 직접 경로를 통해 운영자가 인게임에서 테스트한 것으로 기록됩니다. `Death/KO` 이 항목은 일반 드롭다운 메뉴에서 제외되었는데, 그 이유는 지도에서 `btlActorProperty` 설명한다 `isAlive`, 하나가 아니라 `StatusDeath` 정리됨; 이에 대해서는 별도의 레시피/게이트가 필요합니다. BIBLE과 SIN/Anti-Ribbon 플랜이 업데이트되어, 다음 요원이 이미 해결된 봉쇄를 다시 열 수 없도록 했습니다. 또한 최근 메모에 대한 버전 정보도 포함되어 있습니다. `Multi-*` vs `Sequencial-*`, 다이내믹 사이클, Dark Flan 및 Seymour Natus를 미래의 설계 지식으로 활용합니다. **정직하게 말하자면:** 이는 기존 Monster AI Editor의 버그 수정 및 보안 강화 작업이며, 외부에서 새로운 라이터를 생성하는 것은 아닙니다. `Forbidden Rite LAB`. [이전: `v2.84.10`] — Jarvis-MAGIC
- **🧠 `v2.84.10` — Monster AI Editor: 10개 패치 통합

버그/UX/가드레일 관련 사소한 수정만 있으며, 새로운 기능은 없습니다. **Lane **Jarvis-MAGIC**. **누적된 패치**에 대한 `v2.84.0`: RT2/실제 사용 테스트 결과, Monster AI의 인간 인터페이스에는 탭을 하나 더 추가하는 것이 아니라 계약 조건을 수정해야 한다는 점이 드러났습니다. 이번 수정으로 하위 탭이 제거되었습니다. `Monster AI Editor 2` 탐색 기능을 담당하며 저작권을 `Monster AI Editor` 주요 내용; 큰 블록을 접을 수 있게 함; AEON/YUNALESCA/BIBLE/Live/actions를 사람이 읽기 쉬운 형태로 재배치; 수정 `Talvez` 전체 엔트리포인트를 다시 정의하지 않도록 하는 위치; 다음을 추가합니다. `Pare aqui` ~와 함께 `RET` 제어됨; 네이티브 증거가 없을 때 가짜 콤보를 해제하고 직접 시퀀스로 전환; 배지 획득을 차단 `forçada` 우연히 태어나다; YUNALESCA 상태의 누수 제거; 교체 `NulAll` 진정한 마법을 위해; 마법 시전을 차단합니다. `Início` 런타임이 액션을 대기열에 넣지 않을 때; 조건/워커 라벨 개선; 타겟 연동/첫 번째 스킬/동일 타겟 관련 수정; Shred 스타일의 계산된 타겟 레시피 추가 + HP 감소; 게이트 강화 `AiScriptLab --ai3` local chance, linked rite, target recipe, computed target 및 stop-after의 경우; 다음 항목에 대한 실제 잠금을 유지합니다. `Multi-*` natural + Forbidden Rite 및 RT2 보류 중. **정직하게 말하자면:** 이는 기존 Monster AI Editor의 버그 수정 및 보안 강화이며, 범위 외의 새로운 라이터를 추가하는 것은 아닙니다. [이전: `v2.84.0`] — Jarvis-MAGIC
- **🧩 `v2.84.0` — UI의 완벽한 반응성: 유동적인 프레임 + 모든 창에서 “강제 크기”에 대한 앱 전체 스캔 + 재사용 가능한 브레이크포인트 인프라.** **Jarvis-UI** 트랙 (횡단적 검토 — 거의 모든 모듈의 UI에 적용: MAGIC/MAP/HD). 소유자의 지시를 이행: *"강제 크기는 이제 그만, 모든 것이 반응형이고 자동으로 크기 조절되며, 성능보다 미관을 우선시하고, 비용은 사용자 PC에 떠넘기라"*. **새로운 인프라:** `Styles/Responsive.cs` — 부속 속성 `Responsive.Breakpoints` 클래스를 사용하여 루트를 표시하는 `narrow`/`medium`/`wide` 렌더링된 실제 너비에 따라 다음과 같이 `Style Selector` CSS의 “미디어 쿼리” 역할을 한다. **Frame (`Main_Window`):** 고정된 290/320px 사이드바 → 열 `Auto` ~와 함께 `MinWidth`/`MaxWidth`; 오른쪽의 검사관이 (열 `Auto`→0) 창 너비가 좁을 때는 3열로 표시하고, 넓은 화면에서만 3열로 표시하도록; 

`MinWidth` 1280→1000; 상단 바 포함 `ComboBox` 고정 너비 → `MinWidth`; 활성 브레이크포인트. **앱 전체 스캔 (71개 중 65개) `.axaml` 다중 에이전트 오케스트레이션을 통해 조정됨 — 파일당 하나의 에이전트, 레이아웃에 대한 ‘정밀’ 수정만):** `ColumnDefinitions` 픽셀 기준 137→59 (−78); `StackPanel Orientation="Horizontal"` → `WrapPanel` (×26; 총 252개) 버튼/입력 필드가 잘리는 대신 끊어지도록 하기 위해; `ScrollViewer` 루트가 터질 수 있는 보안 취약점; `Viewbox` 에서 `SphereGridCanvas`; WebView 호스트 (`*Embedded`) 쭉 펴진; `TextWrapping` 누락된 부분; `Width`/`Height` 고정 항목 231→211 및 35→27 (나머지는 내재적 항목입니다: 아이콘, 숫자 입력란, 열 `DataGrid` 및 정렬 폭은 다음 범위 내에서 `WrapPanel` 이미 물이 빠지고 있는 — 잘리지 않음). **MINOR** (새로운 반응형 인프라 + UI의 크로스 플랫폼 호환성). **정직함:** 75개의 화면이 컴파일됨 (릴리스 빌드 **오류 0개**; escaping de `&` / `<` / `>` (녹색 빌드로 보장됨) 및 **없음 `{Binding}`/`Click`/`x:Name` 수정됨** (레이아웃 수정만) — 하지만 **작은 창에서 화면별 시각적 QA는 아직 진행되지 않은 상태**입니다 (75개 화면에서 앱을 실행해 보지 않았습니다. 구조 및 컴파일은 검증되었으나, 외관은 검증되지 않았습니다). 논리/저장/AI/런타임/RT2/Spira Forge와는 무관합니다. 파일: `Styles/Responsive.cs` (새) + `Modules/Main/Main_Window.axaml` + 65 `.axaml` 모듈/컨트롤/템플릿. [이전: `v2.83.0`] — Jarvis-UI
- **🧠 `v2.83.0` — Monster AI Editor 2: 별도의 탭으로 구현된 휴먼 모드, 행동 표면, 다중 선택, 보수적인 드래그 앤 드롭, 덜 압축된 크기 조정, 휴먼 AEON 및 조정된 SIN/HP% 게이트.** Lane **Jarvis-MAGIC** (Monster AI Editor / AI 툴링). 소유자가 요청한 전환을 구현했습니다: Editor 2는 단순한 기술적 복제본에서 벗어나 실제 엔진 위에 구축된 휴먼 윈도우로 거듭났습니다. 새로운 하위 탭 `Monster AI Editor 2` 열기 `MonsterAiEditor2_Control`; 에디터 1은 DevKit/레거드로 유지됩니다. 화면 2는 다음과 같이 구성되어 있습니다. `Normal / Avançado / DevKit`: 오프코드를 출력하지 않는 동작 카드, 패널 `Editar esta ação`, YUNALESCA/BIBLE/SIN/AEON/Live/DevKit을 인간의 이해를 바탕으로 재배치, 인간의 AEON 차이, 보안/컨텍스트 배지 (`ramo condicional`, `outro worker`, `안전한 작업

unica`), combo visual, seleção em lote, limpar lote, comandos batch-aware, drag/drop por alça para grupo consecutivo/autocontido, e layout responsivo que empilha áreas em vez de espremer a janela. Backend novo: `MonsterAiEditor_DataModel.HumanMode.cs`, `.Behavior.cs`, `.HumanDiff.cs`, `.InlineEdit.cs`, `MonsterAiEditor_ActionDrag.cs`, `MonsterAiEditor2_Control.axaml(.cs)` e reuso direto de `AiAutomation`/`AiValidator`/`AiScript_Diff`/`AppendGuardedAction`. Também corrige contratos antigos de HP%: `0x17=MUL`, `0x16=DIV`; SIN-010 deixa de ser bloqueado pelo bug velho e continua honestamente preso a payload/jump-slots/RT2/operator gates. Docs/protótipos versionados: plano de superfície total, pesquisa de acessibilidade humana, protótipo HTML e handoffs de agentes. **MINOR** (nova aba/capacidade de edição humana real). **Honestidade:** RT0/build/gates cobrem estrutura; efeito in-game e patches loose-file como o Skoll `m014` seguem prova RT2/manual. [anterior: `v2.82.0`] — Jarvis-MAGIC
- **🧠 `v2.82.0` — Monster AI Editor: 목록 내에서 직접 수행하는 고수준 액션 편집(어셈블리 코드 없이 버프/스탯의 상태 및 값을 즉시 변경) + 상단에 위치한 클래식 세션 버튼(저장 / 취소 / 복원 / 새로 고침).** Lane **Jarvis-MAGIC** (Monster AI Editor). 소유자가 제기한 *"현재 AI는 실제 지능을 반영하지 못한다"* + *"상단에 클래식 버튼이 없다"*는 불만을 해결합니다. **올바른 재구성 (소유자의 피드백 반영 후):** **인식된 행동 목록 자체가 바로 중요한 지능**입니다 — 버프 (🛡), 스탯 (📊), 명령 (⚔); 이 기능의 장점은 이를 **바로 그 자리에서 편집 가능하게** 만드는 것이며, 오프코드를 표시하는 것이 아닙니다(워커별로 디스어셈블리를 덤프하던 1차 버전은 DevView로 인해 **중복으로 판단되어 폐기**되었습니다). **인라인 편집기 (신규):** 버프/스탯 선택 → **상태/필드** (드롭다운) 및 **값** (입력란) 변경 → **💾 적용**을 누르면 두 피연산자를 **바이트 단위**로 편집합니다 `PUSHII` 기존 문장의 (field + value)를 가져와 다음을 저장합니다. `monster_*.bin` ~와 함께 `.prev.bak` (‘저장’과 같은 경로). 문장의 위치: field instr in `CmdPushOffset`, value는 바로 그 앞의 `CALLPOPA`; 둘 다일 때만 활성화됩니다 `PUSHII` 리터럴 (고정값, 계산되지 않음). **세션별 Chrome (card no t

opo):** 💾 저장 (`HasPendingEdits`) · ↶ 취소 (`.prev.bak`/`CanUndoBackup`) · ♻ 바닐라 복원 (2단계) · ⟳ 업데이트 — 기존 방법을 기반으로 함 (바만 빠졌을 뿐; `Save` (어셈블러 섹션에 묻혀 있었다). **MINOR** (새로운 기능: 목록 내에서 인라인 액션의 첫 번째 편집). **범위/정확성:** **바이트 단위** 편집 (오퍼랜드, 동일한 크기, RT0 검증됨); **삽입/제거/재정렬 및 워커 간 액션 이동은 구조적 규칙을 따릅니다(다음 컷)** — 워커 유형(MotionHandler/CombatHandler)은 코드에서 추론되며, 고정된 레이블이 아닙니다. SIN은 건드리지 않음 (공개 쓰기를 위해 BLOCKED 상태 유지)/런타임/RT2/Aurora/네이티브 메뉴/블리츠볼/상점/믹스/스피어/`Common`(ANIMA)/기타 레인. 빌드 릴리스 **오류 없음**. 파일: `Modules/MonsterAiEditor/MonsterAiEditor_DataModel.InlineEdit.cs` (새) + `MonsterAiEditor_DataModel.cs` + `MonsterAiEditor_DataModel.Automations.cs` (1줄) + `MonsterAiEditor_Control.axaml(.cs)`. [이전: `v2.81.0`] — Jarvis-MAGIC
- **🔌 `v2.81.0` — SIN Gate 6 LIVE glue: 스테이지 오퍼레이터 게이트 처리 + SIN-006 파일럿의 RAM 읽기 전용 확인 — 전투 중에 어떤 이미지가 로드되어 있는지 확인; 실제 스왑은 여전히 수동으로 진행됨; SIN은 공개 쓰기 기능에 대해 계속 BLOCKED 상태입니다.** Lane **Jarvis-YU-YEVON** (MAGIC/SIN). RAM 조사 결과 입증된 공정한 업무 분담을 바탕으로 **SIN→probe 접착제**를 구축: **SIN-006은 스크립트를 확장하며(+15 명령어, +2 점프 슬롯), 확장된 스크립트는 라이브 영역에 인플레이스 주입될 수 없음** — 몬스터 버퍼는 파일의 정확한 크기로 할당되며(WorkerFile은 AiFile 바로 뒤에 연결됨), VM 구조체는 원래 카운트에 따라 미리 크기가 조정됩니다(`FFX_Atel_ComputeScriptChunksSize @0x86A220` / `ComputeScriptDataSize @0x86C050`); 그러면 확대된 이미지는 **RELOAD 경로**(운영자가 파일을 수동으로 교체, 런북 C1-C6)를 통해 들어오며, 콜러는 실시간으로 **확인**만 할 뿐, 절대 쓰기 작업을 수행하지 않습니다. **`FfxLib/Ai/Sin`**: **`SinRt2LiveProbe`** (읽기 전용: `Status` 라이브니스 게임/RAM/프로브/전투; `LocateMonster` RT2 인증을 받은 체인을 재사용합니다. `MonsterAiEditor` — `ADDR_BATTLE_ACTIVE 0xD2A8E0` → `POINTER_BATTLE_ENEMY_LIST 0xD34460` → 보폭 `0xF90` → `Id-0x1000` → `Ptr_script_chunks +0xF

78`; `ClassifyLiveAi` compara byte-exato o AiFile live contra as fatias ORIGINAL e EDITADA → `MatchesOriginal`/`수정된 경기`/`다르다`/`읽을 수 없음`) e **`SinRt2LiveSession`** (`스테이지` operator-gated: re-roda elegibilidade RT2 + round-trip sandbox provado e persiste em `work/sin_rt2_live/` os artefatos `*.original.bin`/`*.sin006.bin`/`MANIFEST.txt` com SHA-256s + aim + efeito-de-tela; `VerifyLive` read-only com skip honesto sem jogo/batalha; guard de stage endurecido com separador — só sob `work/`). `SinSandboxApplyResult` ganha **`EditedMonsterBytes`** (contrato previsto no handoff do PENANCE: o RT2 reusa os MESMOS bytes provados, sem re-emitir). 3 flags novos: **`--sin-pilot-rt2-live-rt0`** (self-test headless: stage prova artefatos+SHAs+`+15`+parse-clean; recusas sem permissão/SIN-009/SIN-010 deixam ZERO arquivos; verify sem jogo → not-ready honesto sem throw; guarda de filesystem + cleanup), **`--sin-pilot-rt2-stage`** (comando do operador, mantém os artefatos) e **`--sin-pilot-rt2-verify`** (comando do operador, read-only: qual imagem está na RAM da batalha — `수정된 경기` prova só o LOAD estrutural; o efeito na tela continua veredito humano). **MINOR** (capacidade NOVA executável: camada LIVE glue + 3 flags). **Escopo/honestidade:** nenhum caminho de escrita em arquivo real/jogo/RAM existe nesta camada; staging não é apply; SIN **continua BLOCKED para escrita pública**; SIN-009/010 continuam fora; `0x16/0x17` intocado. Build 0 erros; `--sin-pilot-rt2-live-rt0` + os 8 gates anteriores todos **PASS**. [anterior: `v2.80.0`] — Jarvis-YU-YEVON
- **🕹️ `v2.80.0` — SIN 체인 빌더 게이트 6: RT2 인게임 파일럿 PREFLIGHT 운영자 게이트 — SIN-006 파일럿 시뮬레이션, RT2 실행되지 않음; 실제 상태 = RT2-pending; SIN은 공개 쓰기 기능에 대해 계속 BLOCKED 상태.** Lane **Jarvis-YU-YEVON** (MAGIC/SIN). SIN Chain Builder의 **Gate 6**을 엽니다: 검증, **헤드리스 모드이며 거짓 보고 없음**, 샌드박스(Gate 5/PENANCE)에서 이미 검증된 SIN-006 컷아웃이 **운영자가 주도하는 RT2 파일럿에서 시연될 수 있음을** 입증 — 실행 중인 게임에는 절대 간섭하지 않고, `dinput8 probe` 또는 실제 파일에서, **게임 내 효과를 명시하지 않고**. *"최소 사례 SIN-006은 조종할 준비가 되었습니다 R"*라고 답하십시오.

"T2 안전 점검, 운영자가 주의해야 할 사항은 무엇인가?"* — 화면상의 확인은 여전히 **사람이 직접 수행해야 하는 단계**입니다(따라서 결과는 **RT2-pending**이며, 절대 자동으로 PASS로 처리되지 않습니다). **의 새로운 클래스`FfxLib/Ai/Sin`**: **`SinRt2PilotGate`** (`SinRt2Eligibility` — 샌드박스보다 **더 엄격한** RT2 적용 기준: (1) 허가 `AllowRt2InGamePilot` 명시적이며 **구분된** `AllowSandboxApply`; (2) **RT2 허용 목록**의 ID = 오늘은 **오직 `SIN-006`**; (3) **본질적인 형태**인 벨트-앤-서스펜더 대 잘못된 라벨링: 단일 매듭, `Trigger=OnTurn` 입증된 해결책과 함께, `Condition=Always` (**HP% 없음/`0x16`-`0x17`**), 전체 `Action` = `GrantChrProperty` **Self 0xFFF3** (**명령 페이로드 없음**)에서), **`SinRt2PilotSession`** (**프리플라이트** 오케스트레이터: RT2 적격성 검사를 실행하고, **검증된 샌드박스 왕복 과정을 재사용**) `SinSandboxApplySession` (복사 → 백업 → 발행 → 보수적 차이 비교 → 바이트 단위 동일 복원), 대상(워커/엔트리포인트)과 확인해야 할 화면 효과를 시뮬레이션한 뒤, **중지** — 실제 적용 및 관찰은 운영자의 단계이며, **여기서는 구현되지 않음**), 그리고 **`SinRt2PilotResult`** (`SinRt2Outcome` `Blocked`/`Skipped`/`SandboxProofFailed`/`PreflightReady` + `SinRt2OperatorVerdict` 기본값 **`Pending`** + 템플릿; `RealApplyDone`/`Rt2Confirmed`/`PublicApplyAllowed` = **구조상 NO**). **적용 범위 (SIN-006만 해당):** SIN-006 + `AllowRt2InGamePilot=true` + 코퍼스 → **PREFLIGHT-READY** (`m201`, OnTurn 작업자 0/ep 2, 차이 **+15 ~0 -0**, **바이트 단위 동일 복원**, 코퍼스/사본 SHA 변경 없음 `B4C0FB90…012F`, 판정 **보류 중**, RT2/RealApply/PublicApply **NO**); **권한 없음**인 경우, SIN-006까지는 **차단됨** (운영자 제어, 샌드박스와 별도의 RT2 권한); **SIN-009** (명령 페이로드 후보) 및 **SIN-010** (HP% / `0x16`-`0x17`) = **RT2 미적격** (allowlist + shape에 의해 차단됨). 새로운 게이트 **`--sin-pilot-rt2-rt0`**: 4가지 경우를 모두 실행하고, RT2-pending 불변 조건을 검증하며 **파일 시스템 보호**를 수행합니다 ( `work/`, 없음 `.prev.bak`/`monster_*.bin` 출력 디렉토리에서, 모든 실제 피처는 읽기 전용이며 해시는 변경되지 않았고, 파일럿 디렉토리는 마지막에 비워짐)이며 **실시간 적용 경로는 없음** (`SinRt2PilotSession` 실제 파일을 작성하지도 않고 pr을 실행하지도 않는다

obe). **MINOR** (실행 가능한 NOVA 기능: RT2 프리플라이트 레이어 + 게이트). **범위/정직성:** SIN **은 여전히 공개 작성을 위해 차단된 상태** — *Gate 6 프리플라이트는 제어된 RT2 파일럿을 검증할 뿐, 템플릿 모음은 아님*; **RT2 검증되지 않았으며, 공개 버튼이 아님**; `Rt2Confirmed=NO`/`RealApplyDone=NO`/`PublicApplyAllowed=NO`. **수정하지 마세요** `0x16/0x17`, SIN-009/010을 **절대** 수정하지 말고, `MonsterAiEditor`; **절대** 만지지 마세요 `monster_*.bin` real/game/probe/Aurora/native-menu/블리츠볼/상점/믹스/스피어/`Common`(ANIMA); Gate 2-5의 검증된 스택을 재사용합니다. 빌드 오류 없음; `--sin-pilot-rt2-rt0` + `--sin-sandbox-rt0` (5번 게이트) + `--sin-aeon-preview-rt0` (4번 게이트) + `--sin-validate-rt0` (3번 게이트) + `--sin-dryrun-rt0` (2번 게이트) + `--aicmdmeta-rt0` + `--spiraatlas-rt0` + `--aiasm-rt0` 모두 **PASS**. 문서: `docs/ai/SIN_YU_YEVON_RT2_INGAME_PILOT_RESULT_2026-06-10.md` + `docs/ai/SIN_YU_YEVON_RT2_OPERATOR_RUNBOOK_2026-06-10.md` + `docs/ai/HANDOFF_YU_YEVON_SIN_AUTHORING_PROMOTION_NEXT_2026-06-10.md`. [이전: `v2.79.0`] — Jarvis-YU-YEVON
- **🛡️ `v2.79.0` — SIN 체인 빌더 게이트 5: 백업/적용 SANDBOX 오퍼레이터 게이트 — 일회용 사본에 적용하고 바이트 단위로 동일한 데이터를 롤백함; SIN은 공개 쓰기 시 BLOCKED 상태를 유지함.** Lane **Jarvis-PENANCE** (MAGIC/SIN). SIN 체인 빌더의 **Gate 5**를 엽니다: 다음을 증명합니다. `SinApplyPlan` 검증(Gate 3/NEMESIS)을 거치고 AEON(Gate 4/OMEGA)에 의해 검토된 내용은 **샌드박스/제어된 복사본에서 적용 및 취소**할 수 있습니다. — 게임 본체를 건드리지 않고, 사용자의 실제 파일을 건드리지 않으며, **RT2나 공개 버튼 없이** 가능합니다. *백업/적용 샌드박스는 공개 저작이 아닙니다.* **샌드박스 전용** 신규 클래스는 **`FfxLib/Ai/Sin`**: **`SinSandboxApplyGate`** (`SinSandboxEligibility` — 8가지 읽기 전용 조건: 구조적으로 유효 · `ApplyAcceptable` 다음 false · 권한 `AllowSandboxApply` 명시적이고 별도 · AEON ADDED-only · **스캐폴딩 제거 범위 외의 중대한 차단 요소 없음**, 게이트 5가 해결하는 차단 요소를 구분하는 규칙 (`plan-blocker`/`rung-ladder`) 레알(payload candidate/blocked, `divmul-integrity`, `jump-slots`, step-blocker)), **`SinSandboxApplySession`** (오케스트레이터: 복사 → 쓰기 전 백업 → emit rea

l 복사본만 → 실제 차이점 확인 → 수정되지 않은 원본 확인 → 복원 → 바이트 단위 동일), **`SinSandboxBackup`** (`.prev.bak` 사본 + 프리이미지 해시 + `Restore`), **`SinSandboxRestoreVerifier`** (SHA-256 + 바이트 비교) 및 **`SinSandboxApplyResult`** (검토 가능한 결과 + 출력 템플릿). **검증된 코덱을 통해 REAL 적용:** 적격 레시피의 경우, **실제 몬스터의 일회용 사본**을 불러옵니다 (코퍼스에서 읽기 전용 → `work/`), **를 통해 선형 배열을 구성합니다.`AppendGuardedAction`(영원한 진리) `PUSHII 1`)** — 코드 끝에 **추가**(기존 오프셋은 유지)하는 유일한 깔끔하고 자동 재배치 가능한 방법으로, 다음을 수행합니다. `SpliceAiFileIntoMonsterGrow`, 다시 읽기 (다시 파싱, 정리됨 = rung `offline-emittable`), 실행 **`AiScript_Diff.Compare(original, edited)` REAL** (원하는 **ADDED** 블록만, **0 modified / 0 removed** = rung) `AEON-reviewed`, 드리프트 없음) + `AiValidator.ValidateRebuilt` (rung `AiScriptLab-clean`), 그리고 나서야 **사본에 작성**합니다 (다음 단계에서 `.prev.bak` = rung `backup-ready`). **3가지 파일럿 레시피 (정직성 결정, 그린 포스 아님):** **SIN-006** (베벨의 베일, 1턴 자기 버프; 대상 Self 확인됨, **명령 페이로드 없음**, 0x16/0x17 없음) = **유일한 적격 사례** → 샌드박스에서 실제 적용 (`m201`, OnTurn은 다음을 통해 해결됨 `AiWorkerMapping.TryResolveCombatOnTurn`, diff **+15 ~0 -0**, **바이트 단위 동일 복원**, 원본/코퍼스 해시 변함 없음); **SIN-009** (마에스터의 명령; 페이로드 **후보**) = 보수적인 **차단** (일회용 사본이라 해도 부정직한 페이로드를 작성할 변명이 될 수 없음; 결정 사항 문서화됨); **SIN-010** (파플레인 통행료, HP%) = **차단됨**, **`0x16` DIV 대 목표 HP% 곱셈** (`divmul-integrity`) — *0x16/0x17은 다른 레인의 전용 PATCH이며, 여기서는 절대로 수정되지 않습니다*. 추가 증거: **허가가 없으면 `AllowSandboxApply`, SIN-006까지 BLOCKED**(operator-gated) 상태가 되며, 동일한 보수적 술어에 의해 **예상치 못한 diff(tamper)는 거부**됩니다 (`+0 ~1 -0 → conservative=False`); **원본은 결코 기록되지 않는다** (`AppliedToOriginal=NO`, 코퍼스 내 실제 소스 및 참조 사본 E에 대한 해시 검증). 새로운 게이트 **`--sin-sandbox-rt0`**: 3가지 레시피를 실행하고, 백업/복원/격리 테스트를 수행하며, **파일 시스템 저장**(외부에 아무것도 기록하지 않음) 

~의 `work/`, 없음 `.prev.bak`/`monster_*.bin` 출력 디렉토리에는 해시가 변경되지 않은 모든 실제 고정 장치가 읽기 전용으로 저장되며, 작업이 끝나면 샌드박스 디렉토리가 완전히 정리됩니다(잔여물 없음, 커밋된 적 없음). **MINOR** (새로운 실행 가능 기능: 샌드박스 적용 레이어 + 게이트; 하나의 복사본 내에서 offline-emittable/AiScriptLab-clean/AEON-reviewed/backup-ready 단계를 모두 통과). **범위/정직성:** SIN **은 여전히 공개 쓰기 기능이 차단된 상태** — 게이트 5는 샌드박스/복사본에만 적용되며, **RT2가 아니며, 공개 버튼도 아님**; `PublicApplyAllowed=NO`/`Rt2=NO` 구조상. public/save/runtime/RT2/UI/버튼에 writer를 생성하지 않습니다. `MonsterAiEditor`; 재생하지 않음 `monster_*.bin` real/Aurora/native-menu/블리츠볼/상점/믹스/스피어/`Common`(ANIMA); 재사용 `SinDryRunPlanner`/`SinPlanValidator`/`SinAeonDiffPlanner` + `AiScript_File.AppendGuardedAction`/`SpliceAiFileIntoMonsterGrow`/`AiScript_Diff`/`AiValidator` (왕복 요금은 이미 345/345로 확인되었으며, `--aiasm-rt0`). 빌드 오류 없음; `--sin-sandbox-rt0` + `--sin-aeon-preview-rt0` (4번 게이트) + `--sin-validate-rt0` (3번 게이트) + `--sin-dryrun-rt0` (2번 게이트) + `--aicmdmeta-rt0` + `--spiraatlas-rt0` + `--aiasm-rt0` 모두 **PASS**. 문서: `docs/ai/SIN_PENANCE_BACKUP_APPLY_SANDBOX_RESULT_2026-06-10.md` + `docs/ai/HANDOFF_PENANCE_SIN_RT2_PILOT_NEXT_2026-06-10.md`. [이전: `v2.78.1`] — Jarvis-PENANCE
- **🎨 `v2.78.1` — UI 개선: 일관된 색상 표준 (Fluent의 “갈색” 제거) + Monster Editor / 탐색 / Prize Table 세련화.** Lane **Jarvis-RIN** (UI 개선). **색상:** Fluent의 크롬 색상 재조정 (`Expander`/`ListBox`/`ListBoxItem`/`TabItem`) + 공유 필드용 ControlTemplates 4개 (`Property`/`PropertyBool`/`GameIndex`/`Loot`) + 스튜디오의 차가운 색상 팔레트를 위한 자동 저장 토큰 — **앱 전체**의 기본 따뜻한 회색/“갈색”과 테두리를 제거합니다 `AliceBlue` (Fluent의 ThemeDictionary는 리소스 오버라이드를 무시했지만, 글로벌 스타일은 이를 해결합니다). **Monster Editor:** 스타일 `Label`/`Separator` 범위, 헤더 `cardTitle` (스탯+전리품), 균일한 타일로 평평하게 배열된 스탯 박스 그리드, 전리품 헤더는 굵기 20 → `cardTitle`. **탐색:** 새로운 허브 **Encounters & Formation** (읽기 전용 Encounter Table + 쓰기 가능한 Formation Editor, 하위 탭); **"Spira Forge" → "맵 & 장면"** (탐색 메뉴 외부의 Field Hub,

 (코드에 유지됨); 텍스트/참조 + 블리츠볼을 Core Authoring으로 이동하고 **"Next Wave" 카드 삭제** ( `&` "지도 및 맵" 섹션에서 **모든 레인의 릴리스 빌드를 망가뜨렸던** 오류). **상금 표:** 3단계 트리 `Expander` achatada (인라인 추첨; “N차 추첨”은 추첨 횟수가 1회 이상일 때만 via `ShowLabel`), 테두리가 없는 상단 행에 패밀리 스트라이프 + 호버 효과 적용, 대회 페이지는 기본적으로 필터 없이 열리며, 배당률은 `ScrollViewer` 자체 (MaxHeight 400) + 칩 `pillWriter` “프리미엄 %가 없는” 앰버, `Detail` 축약된, 체인이/정직함이 옮겨진 간결한 영웅 `Expander` "About"가 접혀 있습니다. **Prize Atlas 조정 완료:** 배당률 관련 언급에는 "별도 그룹 / 1:1 매칭 불가 / 상금 비율 없음"이라는 주의 사항이 포함됩니다. **PATCH** (이미 출시된 기능의 시각적 개선; 의문점 해소→PATCH). **Presentation-only:** writer/parser/binding에는 영향을 미치지 않음 (`Value` TwoWay, `IsPrize`, `EditSession.*` 등(원문 그대로); 트리 = 이에 대한 뷰 `PrizeStructRow` (DTO 없음). 빌드 오류 0개; `--blitzball-prizestruct-rt0` + `--spiraatlas-rt0` **PASS**. [이전: `v2.78.0`] — Jarvis-RIN
- **🌌 `v2.78.0` — SIN Chain Builder Gate 4: AEON diff 미리보기 `SinApplyPlan` 검증됨 (읽기 전용) — 차이점을 표시하며, 적용하지 않음; SIN은 쓰기 권한이 BLOCKED 상태로 유지됨.** Lane **Jarvis-OMEGA** (MAGIC/SIN). SIN Chain Builder의 **Gate 4**를 열며: 다음을 가져옵니다. `SinApplyPlan` (Gate 2/SHINRYU)는 이미 다음 기관에 의해 검증되었습니다. `SinPlanValidator` (게이트 3/네메시스)를 통해 **실제/제어된 스크립트를 대상으로 계획이 실행되었을 경우 AEON이 보여줬을 diff**를 생성합니다 — 여전히 **몬스터를 불러오지 않고, 실제 워커를 diff하지 않고, `Rebuild`/`Splice`/`AiScript_Diff`, 백업도 없고, 디스크도 없으며, 아무것도 적용하지 않은 상태에서**. 단 한 가지 질문에만 답합니다: *"이 검증된 계획이 발행된다면, AEON은 어떤 diff를 보여줄 것인가?"*. **의 새로운 클래스들**`FfxLib/Ai/Sin`**: **`SinAeonDiffPreview`**/**`SinAeonDiffPreviewStep`**/**`SinAeonDiffPreviewRow`** (다음의 어휘를 반영한) `AiScript_Diff`: `Added`/`Modified`/`Removed`/`Unchanged`, + `Context` 가이드선 `;` 목록에서 — 표시되지만 집계되지 않음), **`SinAeonDiffPlanner`** (`Plan(SinApplyPlan, SinPlanValidationResult)` → `SinAeonDiffPreview`; 계획과 검증 결과만 읽습니다. 둘 다 read

-only; 편의 오버로드 `Plan(SinChainRecipe)` (전체 체인을 돌리고) 그리고 **`SinAeonPreviewFormatter`** (결정론적 텍스트). **정직한 모델:** 로드된 몬스터가 없으므로 실제 before-image는 존재하지 않음 → 계획된 모든 명령어는 **ADDED** 라인이며, 대상은 **`synthetic/control fixture`** (`vanilla/current: <none at planned insertion point>`); **MODIFIED == 0** 및 **REMOVED == 0**은 설계상 고정값입니다(이 문제를 해결하려면 실제 워커 = 게이트 5 적용/백업이 필요합니다). 게이트 4는 **게이트 3을 준수합니다**: `StructurallyValid` 검증기에서 온 것이며, `ApplyAllowed` 이는 **고정된(false hard-wired)** 설정이므로, 어떤 후보도 작성 준비 완료 상태가 되지 않으며, **DIV/MUL(`0x16`/`0x17`)는 그대로 불러오며, 수정되지 않습니다** — HP% 레시피(SIN-010)는 블록을 그대로 출력합니다 `Blocked/warning: unresolved 0x16 DIV vs intended HP% multiply semantics. / No public apply. / No RT2 proof.` 그리고 3번 게이트는 계속해서 블로커를 불러오고 있다 `divmul-integrity`. **3개의 파일럿:** SIN-006 (선형, 12 ADDED) 및 SIN-009 (선형, 3 ADDED) = *구조적으로 유효, 적용 차단*; SIN-010 (GuardedAction, 16 ADDED) = 위와 동일 **+ 필수 HP% 블록**. 새로운 읽기 전용 게이트 **`--sin-aeon-preview-rt0`**: 3명의 파일럿을 배치하고, 미리보기를 생성한 다음, 확인합니다.** `ApplyAllowed=false`, 합성 diff-target, ADDED≥1/MODIFIED=0/REMOVED=0, 후보 없음→작성 준비 완료, 결정론적 미리보기, SIN-010에 DIV/MUL 블록 존재 + **파일 시스템 보호** (출력 디렉터리의 전후 스냅샷 → **새 파일 없음, 없음 `.prev.bak`, 없음 `monster_*.bin`**). **MINOR** (새로운 실행 가능 기능: AEON diff 미리보기 + gate). **범위/정확성:** SIN **은 여전히 쓰기 차단 상태** — *Gate 4는 diff 미리보기를 표시하지만 diff를 적용하지는 않음*; *"Clean for DESIGN은 WRITING에 대해 잠금 해제되지 않음"* — 또한 깨끗한 diff 미리보기도 쓰기 잠금을 해제하지 않습니다. writer/save/를 수행하지 마십시오.`Rebuild`/`Splice`/AEON-real/backup/RT2/버튼/UI; 터치하지 마세요 `monster_*.bin`/runtime/Aurora/native-menu/블리츠볼/상점/믹스/스피어/`Common`(ANIMA)도, `MonsterAiEditor`; 읽기만 `FfxLib/Ai/Sin/*`. 빌드 오류 없음; `--sin-aeon-preview-rt0` + `--sin-validate-rt0` (3번 게이트) + `--sin-dryrun-rt0` (2번 게이트) + `--aicmdmeta-rt0` + `--spiraatlas-rt0` + `--aiasm-rt0` (AiScriptLab) 모두 **PASS**. 문서: `docs/ai/SIN_OMEGA_AEON_DIFF

_PREVIEW_RESULT_2026-06-10.md` + `docs/ai/HANDOFF_OMEGA_SIN_BACKUP_APPLY_GATE_NEXT_2026-06-10.md`. [anterior: `v2.77.0`] — Jarvis-OMEGA
- **🔱 `v2.77.0` — SIN Chain Builder Gate 3: AiScriptLab의 검증 브리지 `SinApplyPlan` (읽기 전용) — 플랜을 검증할 뿐, 적용하지는 않습니다; SIN은 쓰기 차단(BLOCKED) 상태를 유지합니다.** Lane **Jarvis-NEMESIS** (MAGIC/SIN). SIN Chain Builder의 **Gate 3**을 엽니다: 다음을 가져옵니다. `SinApplyPlan` SHINRYU (Gate 2)의 미리보기 전용 버전이며, AiScriptLab과 호환되는 검수를 거쳤습니다. **`AiValidator`**, 아직 **몬스터를 소환하지 않은 상태에서, `Rebuild`/`Splice`, AEON diff 없이, 디스크 없이, 그리고 아무것도 적용하지 않은 상태에서**. 단 하나의 질문에만 답해 주세요: *"이 preview-only 플랜은 구조적으로 타당합니까(이 플랜이 생성할 바이트코드가 잘 형성되어 있습니까), 그리고 apply 단계로 넘어가기 위해 해결해야 할 실질적인 차단 사항/경고/오류는 무엇입니까?"*. 새로운 클래스는 **`FfxLib/Ai/Sin`**: **`SinPlanValidator`** (`Validate(SinApplyPlan) → SinPlanValidationResult`, 오직 의 정적 테이블만 읽습니다. `AiScript_File` + `AiStackModel` + 해당 계획), **`SinPlanValidationResult`** (다음의 어휘를 반영함: `AiValidationReport` 계획 수준에서: `Errors`/`Blockers`/`Warnings`/`Infos`, `StructurallyValid` = 오류 없음, `ApplyAcceptable` = **Gate 3에서는 기본적으로 false**이며 **`SinAiScriptLabBridge`** (단일 스트림에 대한 저수준 검증은 `AiInstruction`, 없이 `AiScriptFile`). **검증 (오프라인 SÓLIDO 하위 집합, 다음과 동일함: `AiValidator` (미국):** (1) 검증된 48개의 모든 오프코드 ∈ (`AiScript_File.IsKnownOpcode`); (2) `HasOperand` 크기 규정에 부합합니다 `0x80` (`IsOperandBearing`) — 그렇지 않으면 `Emit()` 정렬이 어긋남; (3) 명령어당 RT0 (`Emit()` 동일한 오프코드+연산자에 대해 재디코딩); (4) 문장별 스택 균형 조정 via `AiStackModel` (선형 본문이 net 0에서 종료됨; 가드 하나가 D7/POPXNCJMP를 위해 **정확히 1개의 bool**을 남김). **3가지 파일럿 레시피에 대한 판정:** 모두 **구조적으로는 유효하지만 apply-BLOCKED** (미리보기 전용) — SIN-006/SIN-009 (선형)은 net 0에 스택이 있음; SIN-010 (HP-가드)는 가드가 정확히 1개의 부울 값을 남기고 net 0에서 동작합니다. **SHINRYU의 DIV/MUL 관련 발견 사항에 대한 명시적 처리 (NEMESIS 결정 = 예상된 BLOCKER로 유지, 수정하지 않음):** 방향성은 입증되었으며 (`0x16=DIV`/`0x17=MUL

` por censo de 345 monstros + IDA `FFX_Atel_InterpretWorkerOpcodes@0x864180` + FFXDataParser), então o `MUL` do `AiSnippetLibrary` ligado a `0x16` é bug confirmado — mas a **reconciliação completa** (corrigir a constante + re-validar TODO consumidor: `MonsterAiEditor`, `AiAutomation`, `--aiasm-rt0`/`--ai2`/`--ai3` + re-provar RT0/RT2) é um **PATCH dedicado fora de uma gate de validação read-only** (e RT2 é proibido pro Gate 3). Insight estrutural que prova por que tem de ser BLOCKER e não Error: `AiStackModel` dá **net -1 pra DIV E pra MUL** → a pilha balanceia idêntico, o byte re-parseia, e **só o RT2 pega a aritmética errada**. O validador surfa isso como **Warning + Blocker** com a evidência toda, e o gate confirma que a receita HP% **continua blocked** e que **NÃO foi corrigida silenciosamente** (o planner ainda emite `0x16`, `AiSnippetLibrary` intocado). **Extensão aditiva (não-quebra):** `SinPlannedStep` ganhou `GuardOps`/`BodyOps` (as `AiInstruction` cruas que o planner já calculava) pra o validador inspecionar **exatamente** o que o planner produziu (fonte única; default vazio → toda construção do Gate 2 segue compilando e o `--sin-dryrun-rt0` continua PASS). Novo gate read-only **`--sin-validate-rt0`**: valida os 3 pilotos e assere estruturalmente-válido + apply-NÃO-aceitável + blockers honestos + escada de promoção insatisfeita + nenhum candidate→authoring-ready + (SIN-010) blocker DIV/MUL presente e não-corrigido; validação determinística. **MINOR** (capacidade NOVA executável: validador + gate). **Escopo/honestidade:** SIN **continua BLOCKED para escrita** — *Gate 3 valida planos, não aplica planos*; *"Clean for DESIGN não é unlocked for WRITING"* — e estrutura-limpa também não destrava escrita. NÃO faz writer/save/`재구축`/`Splice`/AEON diff/backup/RT2/botão/UI; NÃO toca `monster_*.bin`/runtime/Aurora/native-menu/Blitzball/Shop/Mix/Sphere/`일반`(ANIMA) nem o `MonsterAiEditor`. Build 0 erros; `--sin-validate-rt0` + `--sin-dryrun-rt0` (Gate 2, sem regressão) + `--aicmdmeta-rt0` + `--spiraatlas-rt0` + `--aiasm-rt0` (AiScriptLab, 346/346 RT0 no corpus real) todos **PASS**. Docs: `docs/ai/SIN_NEMESIS_AISCRIPTLAB_VALIDATION_RESULT_2026-06-10.md` + `doc

s/ai/HANDOFF_NEMESIS_SIN_AEON_DIFF_GATE_NEXT_2026-06-10.md`. [anterior: `v2.76.0`] — Jarvis-NEMESIS
- **🐉 `v2.76.0` — SIN Chain Builder Gate 2: 시뮬레이션 / 미리보기 플래너 (`SinApplyPlan`) — 미리보기 전용, SIN은 쓰기 권한이 계속 차단된 상태입니다.** Lane **Jarvis-SHINRYU** (MAGIC/SIN). SIN Chain Builder의 **Gate 2**를 열어 YEVON 사양(Gate 1, 설계)을 **실행 가능한 미리보기 레이어**로 변환합니다: 사용자가 AI 의도를 구성하면 플래너가 **정확히 어떤 결과가 생성될지** 보여줍니다 — 적용, 저장, 몬스터에 바이트코드 기록 또는 공개 버튼 생성은 필요 없습니다. 새로운 네임스페이스 **`FfxLib/Ai/Sin`**: `SinChainRecipe` (최소 구체적 IR: 트리거/조건/액션/콤보/페이로드/대상), `SinApplyPlan` (검토 가능한 읽기 전용 계획: 계획된 단계, 지침, 분기/스택 구조, 증거, 장애 요인, 승진 사다리의 관문, `ApplyAllowed=false` (하드 와이어드), `SinDryRunPlanner` (**읽기 전용**으로 설정: 검증된 스니펫을 선택합니다.) `AiSnippetLibrary` 그리고 **메모리 내에서 템플릿을 확장** — 호출하지 않음 `Rebuild`/`AppendGuardedAction`/splice, 몬스터를 불러오지 않음, 실행되지 않음 `AiValidator`, 전화하지 마세요 `AiAutomation`), `SinDryRunPreview` (결정론적 텍스트 연재) 및 `SinPilotRecipes` (필수 시범 레시피 3가지: SIN-006 베벨의 베일 = 1턴 자기 버프; SIN-009 마에스터의 명령 = 강제/실행 명령; SIN-010 파플레인 통행료 = HP<50% 시 방어 행동). **정직한 페이로드 등급** (`SinDryRunPlanner.ClassifyPayload`, 출처: `AiCommandMetadataCatalog.IsKnownAiPerformOperandCategory`): 항목/GATTA (`0x2xxx`) 및 비-AI = **차단됨**; AI 수행 명령 = **후보** (절대 증명되지 않음 — Firaga조차도) `0x3049`, 여기서 RT2는 오퍼랜드 스왑이었으며, SIN이 승인한 블록은 아님). **결과 (드라이 런에서 즉시 확인됨):** 검증된 스니펫 `guard-hp-below-pct-force-cmd` ** opcode를 발행합니다 **`0x16` (검증된 표에 따른 DIV** `0x16=DIV`/`0x17=MUL`) 여기서 HP% 언어가 **MULTIPLY**를 의미하는 곳 — 잠재적인 불일치가 `AiSnippetLibrary` (상수 `MUL` ~와 관련이 있다 `0x16`); **프리뷰에서 경고/블로커로 표시되었으며, 여기서는 수정되지 않음** (이미터 수정은 ‘프리뷰 전용’ 범위를 벗어남; 스니펫에 대한 RT0/RT2 재검증이 필요함). 새로운 읽기 전용 게이트 **`--sin-dryrun-rt0`**: 3명의 조종사를 탑승시키고, 생성합니다

 결정론적 미리보기이며, 아무것도 저장되거나 기록되지 않았다고 주장하며, `ApplyAllowed=false`, rung=preview-only, 정직한 차단 요소 존재, 승격 기준 100% 미달, **authoring-ready로 승격된 후보자 없음**. **MINOR** (새로운 실행 가능 기능: 플래너 드라이런 + 게이트; YEVON의 인계에 따라 실행 가능 기능을 갖추었기 때문에 REVISION 단계에서 정확히 벗어남). **범위/정직성:** SIN **은 여전히 쓰기(WRITING)에 대해 차단됨** — 게이트 2는 프리뷰/드라이런이며, 작성(authoring)이 아님; *"Clean for DESIGN은 WRITING에 대해 잠금 해제되지 않았습니다."* writer/parser/runtime/Aurora/native-menu/Blitzball/Shop/Mix/Sphere/에는 영향을 미치지 않습니다.`Common`(ANIMA)/save도, 심지어 `MonsterAiEditor` (UI 미리보기 = Gate 3+); 읽기 전용 `FfxLib/Ai/*`. 빌드 오류 없음; `--sin-dryrun-rt0` + `--aicmdmeta-rt0` + `--spiraatlas-rt0` + `--aiasm-rt0` (AiScriptLab) 모두 **PASS**. 문서: `docs/ai/SIN_SHINRYU_DRY_RUN_EMITTER_RESULT_2026-06-10.md` + `docs/ai/HANDOFF_SHINRYU_SIN_AISCRIPTLAB_GATE_NEXT_2026-06-10.md`. [이전: `v2.75.0`] — Jarvis-SHINRYU
- **🏐 `v2.75.0` — 블리츠볼 상금 표가 트리 구조로 변경됨: 리그/토너먼트 → 1위/2위/3위/최다 득점자 → 추첨 → 상금 (+ 추첨 감지 기능 재검증 완료).** Lane **Jarvis-NIMROOK** (상금 관리). 상금 표 (459개의 상금 지수 + 390개의 배당률) `bltz0200.ebp`) 더 이상 카테고리별 평면 아코디언 형태가 아니라 **3단계 RE 검증 트리**로 바뀝니다: **대회** (리그/토너먼트) → **시상** (1위/2위/3위 + **최다 득점자** — 순위와 관계없이 최다 득점자가 속한 팀에 수여되는 상) → **추첨 N** (하나의 `switch GetRandomInRange`) → 편집 가능한 보상 버킷. 파서에서 새로 추가된 기능 `BlitzballPrizeStructure_File.FindRollSwitchStarts`/`DrawStartFor` (읽기 전용, 바이트 안전): 각 추첨의 한도는 call입니다. `GetRandomInRange` (오퍼코드 `B5 A6 00`) — **68회의 추첨이 확인됨** `bltz0200.ebp` 실제 (459개의 상금 사이트 모두 배정됨; 프리-퍼스트-롤 1개 미배정), 게이트 `--blitzball-prizestruct-rt0` 모델을 검증하기 위해 확장되었습니다. **정직성:** 배당률(ODDS)은 여전히 별도의 범주로 분류됩니다(특정 상금과 짝을 이루지 않음). 이는 한 번의 추첨 내에서 상금 개수 ≠ 롤 구간 개수이기 때문입니다(데이터 검증 결과, 67/68). — “이 상금에는 X%의 확률이 있다”고 주장하는 것은 증거를 조작하는 것과 같습니다. + **탭 이름 변경 `Atlas`→`Pr

ize Atlas`** + **reconciliação do `차단됨`**: o Prize Atlas (read-only) dizia "liga/torneio/artilheiro = blocked (runtime/save)"; o texto agora explica que isso vale **só pro prêmio que caiu no save** — a atribuição + odds são game-file editáveis (aba Prize Table, RT0 provado) e o reward = aba Prize Pool (takara). + legenda de cadeia (Prize Table escolhe o índice → Prize Pool diz o reward) nas abas de prêmio. **MINOR** (capacidade NOVA: API de estrutura de sorteio RE-provada no parser + 1ª árvore hierárquica de prêmio). Escopo: writer/`EditSession`/`SetPrizeIndexAt`/`SetThresholdAt` **intocados** (só leitura nova + apresentação); não toca save/runtime/SIN/`일반`/provider Atlas nem o código de outras lanes (em cima do baseline commitado do RIN v2.74.x). Build 0 erros; `--blitzball-prizestruct-rt0` (68 draws) + `--spiraatlas-rt0` + roster/recruit/treasure RT0 todos PASS. Doc: `docs/ai/HANDOFF_NIMROOK_BLITZBALL_PRIZE_UI_DIAGNOSIS_2026-06-10.md`. [anterior: `v2.74.1`] — Jarvis-NIMROOK
- **🪗 `v2.74.1` — 접을 수 있는 사이드바 섹션 + 세션 간 상태 유지.** Lane **Jarvis-RIN** (UX). 사이드바의 각 섹션 카드(Core Authoring · Spira Forge · Live Tools · Next Wave · Extras · ???)가 **클릭 가능한 헤더**로 변경되었습니다(카드의 시각적 디자인은 유지됨: `sectionLabel` + `cardTitle` + 쉐브론)을 통해 버튼 그룹을 **접거나 펼 수** 있습니다. 각 섹션의 접힌 상태는 새로운 기능을 통해 **세션 간에 저장 및 유지**됩니다. `Services/SidebarState_Service` (`LocalAppData/FFXProjectEditor/sidebar-state.json`, ~의 관례를 따르며 `last-project.txt`) — 특정 섹션을 수정하지 않은 경우 해당 섹션을 닫을 수 있으며, 편집기를 다시 열어도 계속 닫힌 상태로 유지됩니다. 생성자에서 적용됨 (`ApplySidebarState`)에 저장되고 토글에 기록됩니다 (`SidebarSection_Toggle`). **가산적**인 클래스들에서 `StudioTheme.axaml` (`Button.sectionHeader` 투명/마우스 커서 모양, 제목에 호버 시 청록색 + `TextBlock.sectionChevron`); 쉐브론 ▾ (열림) / ▸ (닫힘). **표시만:** 의 6개 카드를 재구성합니다. `Main_Window` (헤더 + `StackPanel` (접이식이라고 명명됨) + 편의성 지속성 서비스 1개 (오류 발생 시 아무 반응 없음, 펼쳐진 상태로 열림). writer/parser/runtime/save/provider/기타 레인에는 영향을 미치지 않습니다. **PATCH** (편의성/UX;

 의문 해소→PATCH). 빌드 결과 **오류 0개 / 경고 361개**; v2.74.1.0에서 편집기 다시 열림. [이전: `v2.74.0`] — Jarvis-RIN
- **🗂️ `v2.74.0` — 통합 탐색: 4개의 새로운 허브(전투 명령, 아이템, 스피어 그리드, 텍스트/참조) + 구성 요소 `SubTabHub` 재사용 가능 + 간결한 사이드바.** **Jarvis-RIN** 레인의 두 번째 AI 묶음 (Halyson의 방대한 메모). 새로운 범용 컴포넌트 **`SubTabHub_Control`** (`Modules/SubTabHub`): FFX 스타일의 하위 탭 영역 (재사용 `tabPill`/블리츠볼 모드 알약) 코드를 통해 생성됨 `AddTab(label, factory, modo, pílula, requiresProject)`, **lazy-load** (각 하위 탭은 첫 번째 선택 시에만 컨트롤을 생성하고 캐시함) 및 **guard `requiresProject`** (프로젝트가 필요한 탭은 충돌 대신 플레이스홀더를 표시합니다). 그 위에는 **4개의 허브**가 있으며(각각 기존 컨트롤을 호스팅하며, 내부 구조는 건드리지 않습니다): **(1) 전투 명령** → `Comandos/Magias de Personagem` (command.bin) · `Monster Commands 1` (monmagic1) · `Monster Commands 2` (monmagic2); **(2) 아이템** → `Items` (item.bin) · `Key Items` (important.bin, guard) · `Shop` (슬롯 페이로드 저장됨) — 숍과 키 아이템은 여기까지 별도의 화면에서 표시되었습니다; **(3) 스피어 그리드** → `Explorer (DB)` · `Builder` · `Canvas` (3번이 1번으로 변경됨; Explorer는 프로젝트를 요구하지만, Builder/Canvas는 프로젝트 없이 열림); **(4) 텍스트 / 참조** → `String Explorer` · `Macro Explorer` · `Weapon Names` · `Battle Text` · `Event Explorer` (5개가 1개로 줄었습니다). 각 하위 탭은 실제 파일/범위에 맞춰 정직한 모드(쓰기 가능: 호박색 / 읽기 전용: 청록색)로 표시됩니다. **사이드바:** Core Authoring이 23개에서 15개로 줄었습니다; **Auto-Abilities는 이제 Customizations / Aeons에 통합되었습니다**; **Monster AI Explorer가 메뉴에서 제거되었습니다** (핸들러/코드는 유지되었으며, 탐색 옵션만 제거했습니다). **범위 (RIN):** 탐색/호스팅 전용 — 4개의 새로운 핸들러는 `Main_Window` 건설한다 `SubTabHub` 공장을 통해 (`CreateKernelCommandsControl(...)` 커널 테이블용; `new XxxControl()` (나머지) 그리고 기존 핸들러들은 코드에 그대로 남아 있습니다 (`ShowKernelCommands`/`CreateKernelCommandsControl` 변경되지 않음 = 뒤로/앞으로 및 nav-restore는 계속 작동함). **절대** writer/parser/runtime/save/SIN/provider나 그 어떤 것의 내부도 건드리지 마십시오. 

다른 레인의 모듈(MAGIC/Sphere); 다음의 내비게이션 라인만 편집합니다. `Main_Window` (공유 파일) + 추가 `Modules/SubTabHub`. Battle Commands에서 누락된 기능들(전체 검색, 하위 탭 검색, **다중 편집**)은 후속 업데이트로 미루었습니다(명령어 편집기의 로직을 수정해야 하기 때문 = lane MAGIC). **MINOR** (새로운 탭/탐색 모듈 4개 + 새로운 재사용 가능한 컴포넌트). 빌드 결과 **오류 0개 / 경고 361개**; v2.74.0.0에서 편집기 재개. [이전: `v2.73.0`] — Jarvis-RIN
- **🏐 `v2.73.0` — 블리츠볼 허브: 5개의 개별 화면이 ‘블리츠볼’ 탭 하나로 통합되었으며, 하위 탭과 명확한 모드 표시줄이 추가되고 5개 창의 시각적 완성도가 개선되었습니다.** 탐색 기능 통합 + UX 개선 (**Jarvis-RIN** 레인). 사이드바에는 **5개의 개별 버튼**이 있었는데 (`Blitzball Prizes`/`Roster`/`Recruits`/`Prizes (Edit)`/`Prize Table`) 서로 충돌하는 이름들이 있었는데(3개는 “prize”라고 표기되어 있었음); 이제는 **단 하나의 버튼**입니다 `Blitzball 🏐`** 새로운 모듈을 여는 **`BlitzballHub_Control`** (`Modules/BlitzballHub`) FFX 스타일의 띠에 **5개의 하위 탭**이 있는 (알약 `tabPill`, **청록색** 밑줄이 그어진 활성 탭): **로스터 · 신인 선수 · 상금 총액 · 상금 배분표 · 아틀라스**. 각 하위 탭에는 띠 바로 아래에 **간결한 모드 설명**이 표시됩니다 — `WRITER LAB · <arquivo> · RT0 proven · RT2 pending` (호박색) 글씨체 4번, `READ-ONLY · Spira Data Atlas` (청록색) 아틀라스에서 — 허브의 외부 “모드” 배지가 중립으로 바뀌었기 때문에 (`Atlas + Writer Lab`) 더 이상 단일 방식을 고수할 수 없습니다. **lazy-load** 탭(각 UserControl은 첫 번째 선택 시에만 생성되어 캐시됨) → 허브는 **결코 4개를 보유하지 않습니다** `ByteSnapshotEditorSession` 동시에**. **5개의 창에 대한 시각적 개선** (프레젠테이션용만 — writer/parser/binding/DataModel은 수정되지 않음): 새로운 클래스를 사용한 작은 히어로 `heroGradient` (복사된 3개의 리터럴 그라디언트를 제거했습니다), `Save` 지금 `primaryAction` (청록색) 4번 글자 위치(이전에는 각 화면의 스타일화된 ‘-’ 버튼이 있던 곳), 8개의 상자가 있는 **Roster** `cardSoft` **표**로 표시(헤더 정렬, a/b/c/type 오른쪽 정렬), **Prize Table** **카테고리별로 아코디언 형식으로 그룹화** (5개의 접을 수 있는 그룹 — 리그/토너먼트 순위, 리그/토너먼트 득점왕, 롤 임계값/배당률 — 기본적으로 접혀 있으며, 해당 색상 계열의 점과 카운트 표시가 함께)

ites; 텍스트 필터는 일치하는 그룹을 자동으로 확장하여 약 849개의 옵션을 정리하고, **색상 계열별** 한 줄씩 (청록색=상금 지수, 호박색=배당률) + 요약된 텍스트 + 표준화된 여백, **상금 풀**은 수량/원시 유형별로 그룹화되어 `cardSoft` 그리고 간결한 Quantity 열, 오프셋이 적용된 **Recruits** `@0x` 자막과 플레이어 콤보를 주요 요소로 제거하고, 그리드에 **색상별 증거 표시**가 적용된 **Atlas**(proved-candidate=청록색 / partial=호박색 / metadata-only=파란색 / blocked=위험) 및 리터럴 색상(`#9AD7E2`/`#9EB0C2`) 토큰으로 교환됩니다. **추가**되는 새로운 클래스들 `StudioTheme.axaml` (`tabPill`/`tabPillActive`, `heroGradient`, `pillWriter`/`pillReadonly`, `numField`) — 존재하지 않던 선택기 → 다른 화면에서 **회귀 현상 없음** (전체 테마는 건드리지 않았습니다. `TabControl`, (바로 tab 크루를 사용하는 8개의 화면에 영향을 주지 않기 위해서입니다). 새로운 프레젠테이션 컨버터 2개 (`PrizeFamilyBrushConverter`, `EvidenceStatusBrushConverter`). **MINOR** (새로운 내비게이션 모듈/AI + 재사용 가능한 첫 번째 하위 탭 영역; 폴리싱 작업만으로는 PATCH에 해당하겠지만, 새로운 모듈에 포함되어 함께 적용됨). **작성기/파서/런타임/저장/SIN/Atlas 프로바이더/기타 레인**은 건드리지 않습니다; 5개 `*_Control.axaml.cs` 그리고 DataModels는 그대로 유지되었습니다. 빌드 결과 **오류 0개 / 경고 361개**가 발생했습니다 ( `.exe` (편집기가 열려 있었다는 이유만으로 복사하지 않았을 뿐 — 코드와는 무관함). [이전: `v2.72.0`] — Jarvis-RIN
- **🏐 `v2.72.0` — 블리츠볼 상금표: 이제 배당률(추첨 기준치 390)도 편집할 수 있습니다 — “모든 항목을 수정”.** 탭 확장 `Blitzball Prize Table 🏐` (`v2.71.0`): 459개의 상금 지수 외에도, 이제 확률을 정의하는 **390개의 즉시 임계값**을 편집합니다 — 경계값 `case >= N` / `case <= M` ~에 관하여 `GetRandomInRange(100)` (바이트코드 `29 AE <thr> 0E/0F D7/D6` = `DUP·PUSHII·GE/LE·jump`). 다음으로 가져온 버킷은 `roll >= lo` 그리고 `roll <= hi` ~가 있다`(hi-lo+1)%` 확률; 버킷을 넓히면 = 해당 상을 받을 확률이 높아집니다. 새로운 `BlitzballPrizeStructure_File.FindRollThresholds`/`SetThresholdAt` (**상금 사이트에서 ≤768B로 스캔한 것**, 관련 없는 스위치는 절대 건드리지 않기 위해) — 똑같은 2바이트 라이터를 사용한다 (`Event_File.PatchScriptUInt16`). 통합 UI: 필터에 **"Roll Thr"** 기능이 추가됩니다.

eshold (odds)"**, 각 행은 인라인 편집이 가능하며(prize 행은 실시간으로 산출된 보상을 표시하고, threshold 행은 버킷의 상한을 표시합니다). Gate `--blitzball-prizestruct-rt0` 확장 및 **PASS** `bltz0200.ebp` 실제: 459 상금 + **390 임계값** (195 `<=` / 195 `>=` = 완벽한 쌍), 편집되지 않은 바이트는 동일하며, prize-index **및** threshold의 편집은 모두 **2바이트 단위로 분리되어** 있습니다 (`<=10 → <=50` @0xC108), 재검토 결과 두 가지 모두 확인되었습니다. **사소한 문제** (새로운 기능: 배당률 편집). save/runtime/SIN/기타 레인에는 영향을 미치지 않습니다. 빌드 오류 0개 / 경고 361개; `--blitzball-prizestruct-rt0` **PASS**. 문서: `docs/reverse/FFX_BLITZBALL_PRIZE_STRUCTURE_RE_2026-06-10.md`. [이전: `v2.71.0`] — Jarvis-CHAPPU
- **🏐 `v2.71.0` — 블리츠볼 상금표: 각 순위/추첨에 따라 주어지는 상금을 편집하세요 (즉시 지급되는 459개는 `bltz0200.ebp`) — “blocked”를 반박한다.** 읽기 전용 탐색기 (`v2.62.0`) 표시되어 있었다 `BlitzballLeague/TournamentPrizeIndex`/`TopScorer` **처럼`blocked` (실행/저장)** — **너무 보수적**: 그는 단지 **읽기/표시** 측면만 보았을 뿐 `bltz0201` (`PrizeIndex + 220 → Treasure Label`). **할당**은 `bltz0200.ebp` ATEL에 **459개의 즉시 상수**로: `Set Blitzball*PrizeIndex[slot] = <prize-index>` 스위치에서 `GetRandomInRange(100)` (상금의 무작위 분배). 편집 가능한 게임 파일, 모집과 동일(단, 255를 초과하므로 **2바이트**로 즉시 처리됨). 새로운 모듈/탭 **`Blitzball Prize Table 🏐`** (`Modules/BlitzballPrizeStructEditor`): prize-index의 인라인 편집 기능이 있는 459개 사이트 목록(변수/보상/지수별로 필터링 가능) + **실시간으로 해결되는 보상** (takara `prize+220`, 또는 MacroDict#8 (100개 이상). 새로운 기본 요소 `Event_File.PatchScriptUInt16`/`ReadScriptUInt16` (2바이트 즉시 패치, 길이를 보존하는 방식 via `ScriptChunkOverride`) + `FfxLib/Blitzball/BlitzballPrizeStructure_File.cs` (스캔/`SetPrizeIndexAt`) + 게이트 `Tools/BlitzballPrizeStructRt0.cs` (`--blitzball-prizestruct-rt0`). **입증됨** `bltz0200.ebp` 실제 (222.464 B): **459개 사이트** (리그 141개 + 토너먼트 188개 + 리그-TS 65개 + 토너먼트-TS 65개 = 코퍼스 개수 초과), 편집되지 않은 바이트는 완전히 동일하며, 1개의 상금 인덱스 편집이 **2바이트 단위로 분리됨** (리그 1위 `0x0001→0x0099` @0xC0A2), re

-read가 확인합니다. **RE 결과:** ATEL의 var-ids는 **파일별**입니다 (`0x28` bltz0201 대 `0x30` bltz0200에서); bltz0200의 ID (`0x30`/`0x31`/`0x32`/`0x33`) 스위치/셋을 통해 입증됨. **정직성:** 각 순위가 어떤 상금 지수를 부여하는지 편집 (게임 파일, RT0 격리 입증, RT2 보류 중); 각 지수가 제공하는 보상 = 타카라 (aba `Blitzball Prizes (Edit)`); 오즈(롤의 임계값)는 아직 공개되지 않은 또 다른 즉시 실행 요소 집합입니다. **MINOR** (새로운 모듈 + 새로운 2바이트 라이터). 세이브/런타임/SIN/기타 레인에는 영향을 미치지 않습니다. 빌드 오류 0개 / 경고 361개; `--blitzball-prizestruct-rt0` **PASS**. 문서: `docs/reverse/FFX_BLITZBALL_PRIZE_STRUCTURE_RE_2026-06-10.md`. [이전: `v2.70.0`] — Jarvis-CHAPPU
- **🏐 `v2.70.0` — 블리츠볼 상품 편집기: 게임 파일(takara.bin 220..320)에 있는 101가지 블리츠볼 상품을 편집할 수 있는 UI. **새로운 모듈/탭**`Blitzball Prizes (Edit) 🏐`** (`Modules/BlitzballPrizesEditor`) 블리츠볼 상금 풀을 관리하는 곳 (상금 0..100 → 타카라 로우 220+k → 보상; proved-candidate 규칙은 `v2.62.0`): 101개의 보상이 포함된 마스터-디테일 구조로, 각 보상에는 **항목 드롭다운**(이름/ID별 필터) + **수량** + Raw Type/Kind/reward 정보가 표시됩니다. **내부에서 다음을 재사용합니다. `TreasureEditor_DataModel` 검증됨** (항목 사전, 이름 확인, `ByteSnapshotEditorSession`, 전체 테이블 라이터)를 220~320행으로 필터링 → **save는 Treasures 탭의 라이터와 동일**하며, 다음과 같이 기록합니다. `takara.bin` 편집된 상금을 제외한 498개의 항목을 바이트 단위로 그대로 보존합니다. 등록일: `Main_Window` (nav + `SetModule`). **정직성:** **"Writable (Lab)"** 배지 — POOL(각 상금 인덱스가 제공하는 보상)을 편집할 수 있으며, 리그/토너먼트/이벤트별로 어떤 상을 받는지(= 런타임/세이브)는 편집할 수 없습니다; 장비/키 아이템 상금이나 Kind에 대한 세밀한 제어를 원한다면 ‘Treasures’ 탭을 사용하세요. 읽기 전용 익스플로러를 보완합니다. `Blitzball Prizes 🏐` (`v2.62.0`) 실제 버전과 비교하여. **MINOR** (새 모듈/탭). 재사용 `TreasureEditor_DataModel`/`Treasure_File`/`Item_Dictionary`; **새로운** 라이터를 생성하지 않으며, save-do-jogador/runtime/SIN/기타 레인을 건드리지 않습니다. 빌드 오류 0개 / 경고 361개. [이전: `v2.69.0`] — Jarvis-CHAPPU
- **🏐 `v2.69.0` — 블리츠볼 신인 편집기: 누구를 영입할지 선택할 수 있는 UI

 각 위치에서 (게임 파일; 라이터 `v2.67.0` (검증됨).** 새로운 모듈/탭 **`Blitzball Recruits 🏐`** (`Modules/BlitzballRecruitEditor`) 게임 파일에서 직접 자유 계약 선수 영입을 편집하는 기능으로, **~34개의 영입 필드 이벤트**(루카/킬리카/과도살람/칼름 랜드/에어십/베사이드/…, 코퍼스에서 서명을 통해 파생된)를 나열합니다. `AE 28 00 14 AE <id> 00 A3`), 이벤트별로 각 **모집 사이트**에 **60명의 플레이어 목록이 담긴 드롭다운 메뉴**가 표시됩니다 (이름이 확인된 `macrodic.dcp` 출처: `BlitzballPlayerNames`) 그곳에서 누가 채용되는지 다시 확인하기 위해서입니다. 이미 검증된 라이터를 사용합니다. `BlitzballRecruit_File`/`Event_File.PatchScriptByte` (게이트 `--blitzball-recruit-rt0`)를 통해 `ByteSnapshotEditorSession` **이벤트별** (저장/취소/원본 복원/자동 저장, MacroExplorer 멀티 소스 미러). 다음 위치에 기록됨: `Main_Window` (nav + `SetModule`). **정직성:** **"Writable (Lab)"** 배지 — 신입 플레이어의 플레이어 ID만 재지정 (게임 파일, **EXE 패치 없음**; RT0 격리 검증 완료, 게임 내 RT2는 미확정); 각 선수는 보통 **2개의 사이트**(두 개의 코드 브랜치)를 가지고 있습니다 → 두 곳을 모두 변경하여 한 번에 재지정하세요; 모집의 가용성/게이팅은 이벤트 논리를 따릅니다; 선수 스탯 = Blitzball Roster 탭, 이름 = Macro Explorer. **MINOR** (새로운 모듈/탭; 이전: Blitzball Roster Editor) `v2.68.0` = MINOR). Reusa 작가/`Event_File`/`MacroDictionary_File`/`BlitzballPlayerNames`/`ByteSnapshotEditorSession` 기존의 것들; **새로운** 라이터를 생성하지 않으며 save/runtime/SIN/기타 레인을 건드리지 않습니다. 빌드 오류 0개 / 경고 361개; `--blitzball-recruit-rt0` PASS. [이전: `v2.68.0`] — Jarvis-CHAPPU
- **🏐 `v2.68.0` — 블리츠볼 로스터 편집기: 60명의 선수에 대한 능력치/성장 수치를 시각적으로 표시하는 UI (게임 파일; 작성자 `v2.66.0` (검증됨).** 새로운 모듈/탭 **`Blitzball Roster 🏐`** (`Modules/BlitzballRosterEditor`) 파일 내 60명의 플레이어의 stat-growth 곡선을 시각적으로 편집하는 기능 `bltz0002.ebp`: 플레이어 목록 (**읽기 전용 이름**이 해결된 `macrodic.dcp` 출처: `BlitzballPlayerNames`) + 8가지 능력치(HP/SP/AT/EN/PA/SH/BL/CA) 편집기, 각 능력치마다 4개의 부동소수점 값이 있음 `a/b/c/growthType` 편집 가능, **Lv 1/50/99 값의 실시간 미리보기** 및 공식. 이미 검증된 라이터를 사용하세요 `BlitzballRoster_File` (gate `--

블리츠볼-로스터-rt0`) via `ByteSnapshotEditorSession` (save/undo/restore-original/auto-save, espelho exato do `TreasureEditor`). Registrado no `Main_Window` (nav + `SetModule`). **Honestidade:** badge **"Writable (Lab)"** — escreve só os stats/growth (RT0 byte-identity provado, in-game RT2 pendente); **nomes são read-only aqui** (editar no Macro Explorer); techs/level/EXP/custo = save-side; match-engine/efeitos de técnica = EXE-native (ver address map). **MINOR** (módulo/aba NOVO; precedente: Blitzball Prize Explorer `v2.62.0` = MINOR). Reusa writer/`Event_File`/`MacroDictionary_File`/`블리츠볼 선수 이름` existentes; **não** cria writer novo nem toca outras lanes/runtime/save/SIN. Build 0 erros / 361 warnings; `--블리츠볼-로스터-rt0` PASS. [anterior: `v2.67.0`] — Jarvis-CHAPPU
- **🏉 `v2.67.0` — 블리츠볼: 게임 파일에서 모집 정보 편집 가능 — 즉시 적용 가능한 패쳐 ATEL에서 `.ebp` (RT0 검증됨).** 각 위치에서 리크루트되는 대상은 필드 이벤트의 ATEL 바이트코드 내 **1바이트 크기의 immediate**이며, 그 서명은 `AE 28 00 14 AE <playerId> 00 A3` (`PUSHII 40 · ADD · PUSHII <playerId> · write-array`) 귀하의 팀에 append를 수행합니다 (`BlitzballTeamPlayers[count+40]`). 새로운 원시형 `Event_File.PatchScriptByte` (ATEL 청크에 1바이트 패치, **길이 보존** 방식 via `ScriptChunkOverride`) + `FfxLib/Blitzball/BlitzballRecruit_File.cs` (`FindSites`/`SetRecruit`/`SetRecruitAt`) + 게이트 `Tools/BlitzballRecruitRt0.cs` (`--blitzball-recruit-rt0`). **입증됨** `guad0000.ebp`: 6개 사이트 (Giera `0x1F`/Auda `0x22`/Nav `0x21` × 2개 분기), 편집 불가 읽기→쓰기 바이트 동일 (189.696 B), Giera→Wakka로 재지정 (`0x1F`→`0x33`) **2바이트 단위로 분리**된 상태에서 지정된 오프셋에서 재읽기를 통해 신입 사원을 확인합니다. 서명 유효성 확인 vs `guad0000`/`lchb0000`/`hiku0500` (알 베드 사이키스 전체). **정직성:** 누가 어디에서 모집되는지를 변경합니다(게임 파일, **EXE 패치 없음**); 모집 가능 여부/게이팅은 이벤트의 논리에 따릅니다. **사소한 변경** (새로운 모집 스크립트 작성자; 이 유형의 첫 번째 도구). 파일 추가 및 디스패치 1개만 추가됨 `Program.cs`; save/runtime/SIN/기타 레인은 실행하지 않습니다. 빌드 오류 0개 / 경고 361개; `--blitzball-recruit-rt0` **PASS**. 문서: `docs/reverse/FFX_BLITZBALL_ENGINE_IDA_SCOUT_2

026-06-10.md` (Recrutamento). [anterior: `v2.66.0.1`] — Jarvis-CHAPPU
- **🏉 `v2.66.0.1` — 블리츠볼: 편집 가능한 선수 이름 확정 (macrodic chunk 7) + 인레인 액세서.** **수정** (코드는 적용되지만 동작은 변함없음 — 액세서가 아직 소비되지 않음; RE/prep). 다음을 디코딩했습니다. `new_uspc/menu/macrodic.dcp` 실제로 확인해 본 결과, 60명의 플레이어 이름이 매크로임을 입증했습니다 `0x700+idx` = **청크 7** (문자 집합 FFX `byte−0x0F`; 101개 항목): `0x702`=Datto, `0x703`=레티, `0x704`=Jassu, `0x705`=보타, `0x706`=Keepa, `0x707`=빅슨…; `0x700`/`0x701` = **이름 변경이 가능한** 캐릭터(티더스/와카)에 대한 언급. → 모듈에서 **오늘부터 편집 가능** `MacroExplorer` (읽기+쓰기 `macrodic.dcp` (SafeWriter/되돌리기/유효성 검사/라운드 트립 포함). 새로운 읽기 전용 액세서리 `FfxLib/Blitzball/BlitzballPlayerNames.cs` (목차↔매크로 `0x700+idx`, `TryGetName`) 미래 시제의 **전치사**로서 `BlitzballRosterEditor` UI에서 이름을 인라인으로 표시/편집합니다. 터치하지 마세요. `MacroExplorer` (텍스트 레인)이나 다른 레인은 없으며, 파일 1개와 문서만 추가됩니다. 빌드 결과: 오류 0개 / 경고 361개. 문서: `docs/reverse/FFX_BLITZBALL_ROSTER_BASE_RE_2026-06-10.md §3` + `docs/ai/BLITZBALL_100PCT_EDITOR_CHECKLIST_2026-06-10.md`. [이전: `v2.66.0`] — Jarvis-CHAPPU
- **🏉 `v2.66.0` — 블리츠볼 로스터(60명의 선수 통계/성장도)를 이제 게임 파일에서 편집할 수 있습니다 — 작성자 `.ebp` Atel-variable 검증 완료 (RT0 바이트 동일 + 돌연변이 격리).** **GAME FILE에서(세이브 파일이 아닌) 블리츠볼 기본 데이터를 편집하는 최초의 작성자.** 60명의 선수들의 기본 능력치 + 성장 곡선은 `bltz0002.ebp` Atel 변수로서 `0x126..0x12E` (8개 통계 항목 × 60명 선수 × 4개 실수형 값 `a,b,c,growthType`; 성장 공식 해설: `gt -1`→1, `0`→a+b·Lv, `1`→a+b·Lv^c, `2`→a+b·Lv−c·Lv², `3`→a+b·Lv+c·Lv²). 새로운 원시함수 `Event_File.PatchEventDataElement(varId, idx, bytes)` (`FfxLib/Event/Event_File.AtelVar.cs`): Atel eventData 변수의 인플레이스 패처, 훅을 통해 **길이를 유지하며** 적용 `ScriptChunkOverride` 이미 존재하는 → `Write()` 편집된 슬라이스를 제외하고 바이트 단위로 동일한 데이터를 다시 패키징합니다. 새로운 파일 클래스 읽기/쓰기 `FfxLib/Blitzball/BlitzballRoster_File.cs` (60×8 growth를 디코딩/편집) + 게이트 `Tools/BlitzballRosterRt0.cs` (`--blitzball-roster-rt0`). **검증됨:** 읽은 사람:

te-exato 대 FFXDataParser 덤프 (플레이어0 HP = `70 + 30·Lv + 0.711·Lv²`); no-edit 읽기→쓰기 **바이트 동일** (5,445,248 B); **유효한 480/480 growthType**; 예상 오프셋에서 **대상 요소의 4바이트에 국한된** 1개의 부동소수점 패치 (`@0x491680`). **RE (누락된 부분):** 변수의 값 기반 = `worker0_header + 0x30` (하드코딩 없이 견고하게 해결). **정직하게 말하자면:** 오직 stats/growth만 파일에서 가져온 데이터이며, 이름은 문자열 매크로입니다. `0x700+idx` (writer는 존재하지만 연결이 필요함), **포지션/기술 정의/시동 엔진 = EXE (IDA 미처리)**, 습득한 기술/비용/계약/레벨/EXP = **저장** (게임 파일 범위 외). **아직 UI 없음** (다음 단계 = `BlitzballRosterEditor`). **MINOR** (새로운 기능: 게임 파일 내 최초의 블리츠볼 로스터 작성기). 세이브(CHAPPU/체크섬), 런타임, SIN 및 기타 레인은 건드리지 않고, 단지 새로운 파일을 추가하고 dispatch를 1개 추가할 뿐입니다. `Program.cs`. 빌드 오류 0개 / 경고 361개; `--blitzball-roster-rt0` **PASS** (편집 불가, 바이트 동일 + 돌연변이 격리). 문서: `docs/reverse/FFX_BLITZBALL_ROSTER_BASE_RE_2026-06-10.md` + `docs/ai/BLITZBALL_100PCT_EDITOR_CHECKLIST_2026-06-10.md`. [이전: `v2.65.3`] — Jarvis-CHAPPU
- **🗺 Spira Data Atlas / FFXDataParser 브리지 — 거대 파서 전선의 마무리.** 게임 전체에 걸친 조사/카탈로그화 전선에 버전별 운영 마무리가 이루어졌습니다: 로컬 브리지는 `tools/ffxdataparser_bridge` 에 기반한 읽기 전용 재분류를 재현하기 위해 강화되었습니다. `FFXDataParser`, Step0/v5, 추가 v6 P0, 세분화된 v7 ATEL 및 의미론적 v8 ATEL 레이어가 포함되어 있습니다. 데이터의 출처를 놓치지 않도록 출처 및 인계 문서가 포함되었습니다 (`HANDOFF_SPIRA_DATA_ATLAS_PARSERS_GIGANTES_2026-06-09.md`, `SPIRA_DATA_ATLAS_PARSERS_GIGANTES_PROVENANCE_MAP_2026-06-09.md`), PRE1/PRE2는 `takara.bin`/`buki_get.bin`, command/magic 로케일 스키마, 로케일 인식 파서 계층, unknown/evidence 상태 및 Step0-C 상호 연결. 그 결과, 무엇이 `proved`, `partial`, `read-only`, `metadata-only`, `blocked` 그리고 `RT2-pending`: 파서 코퍼스는 구조/존재 여부를 검증하며, 런타임 효과나 작성자 권한은 검증하지 않습니다.
- **📚 Spira Data Atlas / BIBLE OF SPIRA — 읽기 전용 제공자가 14,739개 항목으로 확장됨

그들에게.** 제공업체 `SpiraDataAtlasCatalog` 그리고 BIBLE은 이제 아틀라스를 실제 연구 가능한 맥락으로 인식하고 있다: `74` 아틀라스 항목, `54` 마스터 레이어, `1601` 파싱되지 않은 원본 파일, `615` call-shapes, `89` branch-shapes, `202` field-shapes, `3283` workers 및 `656` 명령어 사이트 요약. 최종 패키지는 Step0-C의 “6가지 격차”를 해소했습니다: `1604` monster-presence 행 (편성/슬롯별), `979` SIN 자격 요건 기준 `AiCommandMetadata`, `1190` 이름/모델별 행 `w_name.bin`, `312` 블리츠볼 이벤트 심판 여러분, `76` 블리츠볼 상금 심판 파생 항목 `bltz0200/0201`, `20` PC/Aeon fine rows 및 `2493` Sphere Grid 노드. 내장 CSV 리더가 이제 여러 줄로 구성된 레코드와 게이트를 지원하게 되었습니다. `--spiraatlas-rt0` / `--aicmdmeta-rt0` 지나갔습니다. 새로운 라이터 없이: Treasure/Shop/Sphere/Monster AI/SIN은 이를 먼저 컨텍스트, 배지 및 감사 용도로 사용합니다. SIN Chain Builder는 여전히 AiScriptLab, AEON diff, 백업 및 RT2에 의존하고 있습니다.
- **🧠 Monster AI Editor — SIN 위협 탐색 기능 개선.** **Spira Instinct Network**의 읽기 전용 갤러리에 정확한 위협 필터 기능이 추가되었습니다. `T1`..`T10`, 대역 필터를 유지하면서 (`T1-T3`, `T4-T6`, `T7-T8`, `T9-T10`) 및 다음 기준에 따른 선택적 정렬을 추가하여 `SIN-001 -> SIN-100`, `Threat 1 -> 10`, `Threat 10 -> 1` 또는 검색 관련성. 선택한 죄의 미리보기에는 이제 위협 범위가 명시되어 있습니다 (`baixo`, `medio`, `alto`, `dark`, `proibido`) 및 구체화 정책 (`materializavel primeiro`, `espera chain builder`, `somente lab`, 등). 새로운 라이터 없이, 런타임/게임에 손을 대지 않고: 향후 체인 빌더가 출시되기 전까지 100개의 프리셋을 탐색할 수 있는 오프라인 UX/카탈로그. 임시 빌드: 오류 0개 / 경고 0개. — Jarvis-Codex
- **🧠 BattleTracker / SIN — 스티키 상태 오프라인 매핑.** 라이브 게임에 손을 대지 않고도, ‘Forbidden Rite’ 전선에 문서가 추가되었습니다. `docs/ai/SIN_STICKY_STATUS_OFFLINE_MAPPING_2026-06-08.md`: `AiChrPropertyNames` 341개의 필드가 있습니다 (`0x0000..0x0159`)이며 노출하지 않는다 `status_full_auto_*`/`status_innate_auto_*` ATEL 필드로 알려져 있습니다. 당분간 sticky는 런타임 상태로 유지됩니다. `MemoryChr` (`0x62A..0x634`) 또는 향후 라이브/DINPUT8, 순수한 Monster AI는 아닙니다. BattleTracker에는 이제 **Forbidden Rite / Sticky Bytes**라는 읽기 전용 트랙이 표시되며, `Suffer`, `Durations`,

 `Extra`, `Doom`, `Full auto`, `Innate auto` 그리고 간결한 요약으로, 차기 RT2에서 PowerShell에 대한 의존도를 줄였습니다. 빌드 편집기 오류 0개 / 경고 361개. — Jarvis-Codex
- **🧠 Monster AI Editor — Forbidden Rite 고정형 제거 방지 RT2 LAB.** Ribbon 방지 패키지 이후 `m034 -> Tidus`, 라이브 테스트를 통해 단순히 우회할 수 있는 것과 제거할 수 없는 것을 구분해 냈습니다: 스티키 없이, `Eye Drops` 미스 타이틀을 따고 떠났다 `Darkness=255`, 하지만 Holy Water/제거로 지워졌습니다 `Zombie/Confuse/Curse`, 남은 `Silence/Darkness/Doom`. 그 후, LAB 런타임 스크립트가 다음과 같이 표시했습니다. `status_full_auto=0102/0806/4400` 그리고 `status_innate_auto=0102/0806/4400` ~와 함께 `suffer=0102`, `sil/dark=255/255`, `extra=4400`, `doom=5/5`; 150초 동안 제거 아이템/마법이 패키지를 떨어뜨리지 않았고, 둠이 데미지를 입혔다 `5 -> 4 -> 5`. Guardrail: 이것이 바로 런타임 테스트입니다 `MemoryChr`, writer가 아닌 ATEL/SIN 버튼을 매핑할 때까지 `full_auto/innate_auto` 필드로 설정하거나 live/DINPUT8 경로를 사용하도록 설정합니다. — Jarvis-Codex
- **🧠 Monster AI Editor — Forbidden Rite RT2: Tidus에서 검증된 안티-리본 팩.** 첫 번째 직접 연결 팩 `writeChrProperty(Character#1, field, value)` Ribbon과 함께 배틀로얄을 치르며 `m034`: 티더스가 받았다 `Zombie`, `Confuse`, `Silence(255)`, `Darkness(255)`, `Curse` 그리고 `Doom(cur=4/init=5)`. 런타임 읽기: `suffer=0x0102`, `turns[sleep/sil/dark]=0/255/255`, `extra=0x4400`. O `m034` lab의 도는 다음으로 재구성되었습니다. `HP=1.000.000`, `Agility=100` 그리고 `Accuracy=255` 생존하고 더 빠르게 행동하기 위해. **Forbidden Rite LAB**의 UI에는 이제 Zombie/Confuse/Silence/Darkness/Curse/Doom 및 Doom 카운터가 올바른 기본값과 함께 표시됩니다. 아직 공개된 SIN 프리셋은 아닙니다: 광범위한 대상, 적대적 치유, 턴당 처벌은 별도의 RT2가 필요합니다. 빌드 에디터 오류 0개 / 경고 361개. — Jarvis-Codex
- **🧠 몬스터 AI 편집기 — Forbidden Rite LAB 안티-리본.** 워크벤치에 **리본**을 가진 캐릭터를 상대로 직접 상태 이상을 테스트할 수 있는 최초의 좁은 범위의 LAB 라이터가 추가되었습니다: **Forbidden Rite LAB** 카드는 단일 대상을 선택합니다 (`Character#1/#2/#3`, `FrontlineChars`, `TargetActors`, `LastAttacker`), 선택하세요 `Zombie`/`Curse`/`Doom`, 금액 `1`, 그리고 다음 위치에 저장합니다. `CombatHandler.onTurn` 백업을 사용하여 실제 `writeChrProperty(target, field, value)` (`PUSHII <target> -> PUSHII <field>

 -> PUSHII <value> -> CALLPOPA 7018`). A rota fica separada de ``setStatField(70AB)`: 서명 혼동을 방지하기 위함; 공개된 SIN 프리셋이 아니며, Ribbon + AEON/BattleTracker를 장착한 캐릭터가 RT2까지 바이패스 여부를 확인할 때까지는 바이패스라고 선언하지 않습니다. 빌드 에디터 오류 0개 / 경고 361개. — Jarvis-Codex
- **🧠 몬스터 AI 에디터 — SIN 100개 프리셋 + 위협 필터.** **Spira Instinct Network** 갤러리가 **100개 프리셋**으로 구성된 읽기 전용 선반을 개설했습니다: 이번 신규 추가분에는 `Tribunal of Yevon`, `Fayth Erosion`, `Guado Excommunication`, `Spectral Keeper Wheel`, `Penance Arm Doctrine`, `Omega Scripture`, `Anima Pain Engine`, `Bevelle Inquisition`, `Yu Pagoda Spiral` 그리고 `Sin Eternal Return`. UI는 이제 다음을 기준으로 필터링합니다. `Threat` (`T1-T3`, `T4-T6`, `T7-T8`, `T9-T10`, `T10`) 티어/상태 외에도, 목록을 숫자 순서대로 정렬합니다 `SIN-001` -> `SIN-100`; `Tier` 기술적 위험은 여전히 존재하며 `Threat` 게임 내 위협은 계속된다. 새로운 작가 없음: `T10` 이는 금지된 레시피를 위한 쇼케이스/실험실일 뿐, 공개 버튼이 아닙니다. — Jarvis-Codex
- **🧠 Monster AI Editor — SIN Lethal Expansion + anti-Ribbon 플랜.** SIN 카탈로그가 58개에서 **80개의** 읽기 전용 프리셋으로 늘어났으며, 치명적/안티-메타 패키지가 추가되었습니다: `Yunalesca's Mercy`, `Ribbon Funeral`, `Rotting Benediction`, `Maester's Noose`, `Penance Clock`, `Anti-Phoenix Liturgy`, `Seymour's Verdict`, `Faythless Prayer`, `All-Life Reversal`, `Yu Yevon's Hunger`, `Omega Pattern` 등. BIBLE에는 가드레일이 설치되어 `Ribbon bypass nao e magia normal` 그리고 `Status direto no battle actor`, 그리고 다음 필드들 외에도 `StatusCurse`, `StatusDoom`, `DoomCounter`, `StatusResistanceZombie` 및 부분적 면제. 새로운 계획: `docs/ai/SIN_LETHAL_EXPANSION_AND_RIBBON_BYPASS_PLAN_2026-06-08.md`. 카탈로그는 이제 다음과 같이 구분합니다 `Tier A/B/C/LAB` 기술적 위험 및 `Threat 1-10` 게임 내 위협 요소로서, T10은 《파이널 판타지 X》의 금지된 레시피에만 할당되어 있습니다. 새로운 작성자도 없고 우회 방법이 입증된 바도 없는 상황에서, 다음 관문은 리본을 착용한 캐릭터를 상대로 한 RT2로, 일반 명령어와 `writeChrProperty(target, StatusZombie/Curse/Doom, 1)`. 빌드 에디터: 오류 0개 / 경고 361개. — Jarvis-Codex
- **🧠 몬스터 AI 에디터 — UI에서 SIN 갤러리 읽기 전용 모드 활성화됨.** **Spira Instinct Network*의 카드 4장 모크업

* 58개의 프리셋을 탐색할 수 있는 체계적인 카탈로그로 바뀌었습니다 (`False Calm`, `Cycle of Ruin`, `Yevon's Maw`, `Unsent Choir`, `Diamante de Shiva`, 등), 텍스트/기본 요소 검색, 필터 `Todos`/`Tier A`/`Tier B`/`Tier C / LAB`/`A-now`, 선택 가능한 카드와 동작, 기본 요소, 위험도, 다음 게이트가 포함된 미리보기. 여전히 새로운 라이터는 없습니다: 패널은 쇼케이스/기획된 저작 기능입니다; 프리셋을 실제 버튼으로 변환하려면 여전히 BIBLE 항목, AiValidator, AEON diff, 백업 및 RT2가 필요합니다. 빌드 에디터 오류 0개 / 경고 361개. — Jarvis-Codex
- **🧠 BIBLE/SIN 연구 도구 — 몬스터 AI 전체 목록 + 명령서 그리모어 + 58명의 SIN 후보.** O `RuntimeTools/AiScriptLab` 다음과 같은 두 가지 읽기 전용 모드가 추가되었습니다: `--sin-census`, 이는 워커, 감지된 액션, 명령어, 필드, 대상 및 패턴 플래그를 기반으로 몬스터별 아틀라스를 생성하며; 그리고 `--sin-grimoire`, 여기에는 다음을 통해 사용할 수 있는 867개의 명령어가 나열되어 있습니다. `AiCommandId` 그리고 저자 식별을 위한 휴리스틱 역할에 따라 분류합니다. 실제 코퍼스에서 테스트됨: AiFiles 361개, 스크립트 346개, 330개 `CombatHandler.onTurn` 해결됨, 470개의 명령어 사용, 67개의 필드 읽기, 171개의 필드 쓰기, 37개의 대상. 새로운 문서: `BIBLE_OF_SPIRA_MONSTER_AI_CORPUS_ATLAS_2026-06-08.md`, `SIN_COMMAND_GRIMOIRE_2026-06-08.md` 그리고 `SIN_PRESET_CANDIDATES_2026-06-08.md` 58개의 후보 프리셋이 있는 (`False Calm`, `Cycle of Ruin`, `Yevon's Maw`, `Unsent Choir` 등)으로 표시된 `A-now`/`B-chain`/`C-frontier`/`LAB-only`. 새로운 라이터도, 새로운 공개 버튼도 없습니다. 이는 미래의 SIN Chain Builder를 위한 검증 가능한 기반입니다. — Jarvis-Codex
- **🔎 `v2.65.3` — SEYMOUR 감사: 124개 ATEL `unknown-call-shape` 아틀라스의 데이터를 신뢰할 수 있는 클래스(읽기 전용, 바이트 검증)로 분류했습니다.** **ATEL Call-Shape Audit (SIN 이전).** 해당 `124` v8의 의미론적 패스가 분류하지 않았던 필드 쓰기(`field-write-unknown-call-shape`)는 전체 코퍼스(FFXDataParser target/text, 346개 스크립트)에 대해 **바이트코드** 수준에서 분석되었으며, **전부** 두 개의 검증된 클래스로 분류되었고, **나머지는 0개**였다. **(1) `0x70A8 btlSetMotionData` — 116행 (100%):** 균일한 모양 `PUSHII actor · PUSHII field · (PUSHII|PUSHF) value · CALLPOPA` = `(actor, field, value)` **motionProperty** 네임스페이스에서 (필드 `0x00..0x09`, 모두 `AiMotion`에 지정된 것들

PropertyNames`); actor é ref REAL (113× Self `0xFFF3` + Monster#01/#02/#03 `오후 0시 15분/16분/17분`), em 25 monstros → classe **`set-motion-data-actor-field-value`** (irmão explicit-actor do `0x70B2 setMotionField`; **NÃO** é `setStatField`). **(2) `0x7032 setActorFacingAngle` — 8 rows:** NÃO é field-write — é `(배우, 각도)` 2-push **sem field-id**; vazaram pro catálogo por **falso-positivo de regex** (só ângulos FLOAT renderizam `.facingAngle = 90.0 [42B40000h]` e o regex v7 pegou o `.0 [16진수]` do decimal; os 63 sites-irmãos com ângulo inteiro `= 90 [5Ah]` não vazaram) → classe **`not-field-write`**. **Mudanças:** bridge `tools/ffxdataparser_bridge/build_atel_semantic_catalog.ps1` (`Get-FieldWriteSemanticKind` + risk notes) reclassifica os dois call-ids; o v8 regenera com `0` unknown (116+8 nas classes novas); a contagem de `AtelFieldWriteShape` fica **`202`** (relabel preserva a cardinalidade da chave `callId|fieldHex|fieldName|semanticKind|fieldCategory`, provado before/after); o pass `unknown-health` cai de `199 → 75` (os 124 ATEL saem do bucket "blocked-until-audited"); narrativas do `SpiraDataAtlasCatalog` (`atlas:필드 호출 도형` + guardrail + `atlas:알 수 없는 건강`) atualizadas; asserts `--spiraatlas-rt0` movidos (`세부 항목 21316→21192`, `알 수 없는 건강 관련 행 199→75`) + **2 asserts-trava novos** (`0` unknown call-shapes remanescentes + `0x70A8` motion-data presente). **Honestidade:** classificar ≠ autorizar writer — todo `AtelFieldWriteShape` segue `읽기 전용;쓰기 권한 없음`, `70A8` continua sem botão/escrita, nada promovido pro SIN. **Achado de fidelidade (read-only):** o decoder do EDITOR (`AiScript_File.cs`) **não** glossa `70A8` (ausente de `FieldArgBack`/`함수용 필드명`) e o `AiStackModel` não tem a aridade dele → gap de display handoff p/ a lane MAGIC (`docs/ai/HANDOFF_SEYMOUR_ATEL_DECODER_GLOSS_GAP_2026-06-10.md`), sem efeito de gameplay. **PATCH** (refina/classifica catálogo read-only existente, resolve um data-blocker do SIN; precedente `v2.61.3`/`v2.62.1`; 의문점 해소→PATCH). 새로운 라이터 없음; runtime/AURORA/VALEFOR/native-menu/SIN-chain-builder/CHAPPU/save는 처리하지 않음. 적대적 워크플로우를 통해 검증됨 (반박자 3명 + 완전성 검토)

ic). 빌드 오류 0개 / 경고 361개; `--spiraatlas-rt0` + `--aicmdmeta-rt0` + `AiScriptLab --ai2` (346/346) PASS. 문서: `docs/ai/ATLAS_SEYMOUR_ATEL_CALL_SHAPE_AUDIT_RESULT_2026-06-10.md`. [이전: `v2.65.2`] — Jarvis-SEYMOUR
- **🔧 `v2.65.2` — 스피어 그리드: 빈 노드의 중복 콘텐츠 보존 (0xFFFF) + 폴란드어 아틀라스 등장 위치.** **아틀라스 폴란드어 / 증거 정리 (Jarvis-BARTHELLO).** **(A) 스피어 그리드 강화 (바이트 정확도):** 없음 `SphereGrid_File.Builder.cs` (writer LAYOUT v2, 게이트 처리됨) `--spheregrid-layout-rt0`), 저작/편집의 과정 `AddNode`/`NodeWith` 녹화하고 있었다 `RedundantContent = (ushort)(contentIndex & 0xFF)` → **빈** 노드(content `0xFF`) 그로 인해 발생했다 `0x00FF`, 제공된 데이터와는 다르게 나타납니다. 코퍼스(scout Jarvis-AURON, **3,444/3,444 노드**: 저바이트 == ContentIndex, 고바이트는 Expert의 빈 노드 23개에서만 설정됨)는 빈 노드 = **`0xFFFF`**, 가득 = `0x00<content>`. 새로운 비공개 헬퍼 `RedundantContentFor(contentIndex)` 유행하는 쉐핑 관례를 반영한다 (empty→`0xFFFF`, 채워짐→`0x00NN`). `FromExisting`/`Clone` 계속 복사하세요 `RedundantContent` **verbatim** → 편집되지 않은 왕복 **바이트 단위 동일** (변경되지 않음, 게이트에서 재검증됨). 새로운 assert가 `--spheregrid-edit-rt0` (합성 + 코퍼스의 3개 그리드): `SetNodeContent(idx, 0xFF)` → 레이아웃 저장 `0xFFFF` node+0x06 + 내용 바이트 `0xFF` + 재읽기: 비어 있음. 게임플레이 위험도 낮음 (중복 필드; 게임이 콘텐츠에서 `dat09/10/11` + reach-lists — AURON이 두 바이너리에 대해 IDA 검증을 마쳤으나, 이미 배포된 라이터에서 정확도 차이가 발생합니다. **(B)** `AiBibleWhereAppears.For` 폴란드어 (읽기 전용):** 해당 사례 추가됨 `aeon-growth` (Atlas 도메인은 `v2.64.0` (빈 폴백으로 넘어가던) 부분에 “표시되는 위치/매핑”이라는 명확한 문구를 추가함; 업데이트됨 `sphere-grid-node` (이전에는 "Unknown6은 원시/알 수 없음으로 처리됨"이었음) AURON의 번다운을 반영하기 위해 — `Node.Unknown6` **게임플레이가 비활성 상태(두 바이너리 모두 IDA로 검증됨)**이며, 잔여 요소는 메뉴 레이아웃/비주얼(메타데이터 전용)일 수 있으나, 임의로 추가된 게임플레이 의미론은 없습니다. **PATCH** (이미 출시된 라이터에서 잠재된 정확도 버그 수정 — "소비자가 혜택을 볼 것" → 예, 바이트 단위 정확도 — + 텍스트 읽기 전용 다듬기; 

의문 해소→PATCH). 새로운 라이터도, 새로운 UI도, 제공자/게이트 카운트 변경도 없음 (`--spiraatlas-rt0` (손상되지 않은), 엔진 `Common` (ANIMA), runtime/AURORA/VALEFOR/native-menu/SIN, CHAPPU/save, 실제 그리드 토폴로지도 아님(노드 생성/이동/재연결 시 경계를 따름). 빌드 오류 0개 / 경고 361개; `--spheregrid-edit-rt0` + `--spheregrid-layout-rt0` + `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS. 문서: `docs/ai/ATLAS_BARTHELLO_POLISH_RESULT_2026-06-10.md`. [이전: `v2.65.1`] — Jarvis-BARTHELLO
- **🧪 `v2.65.1` — PlayerGrowthEditor에 Atlas 증거 배지 추가 + Sphere None/Passive 레이블 (읽기 전용, 값 보호, 편집 시 숨김).** **Atlas UI Sweep.** (1) **PlayerGrowthEditor:** 신규 `<common:AtlasEvidenceBadgeStrip>` "Growth Curves" 카드(ply_rom.bin)에서 이미 생성된 액세서를 사용하여 `SpiraDataAtlasCatalog.TryGetPlayerGrowthStat(source, characterIndex, field, currentRawValue)` (`v2.65.0`, TIDUS). 신작 `AtlasEvidenceInfo? SelectedCharacterEvidence` 에서 `PlayerGrowthEditor_DataModel`, 슬롯 변경 시 재계산되며 `CharacterRowChanged` (편집) → **hide-on-edit**: 이 배지는 두 파일/카드를 모두 포괄하는, 성장 게이트를 통해 검증된 3가지 값을 기준으로 합니다 (`ply_save` HP 베이스 + `ply_rom` AP max + HP 계수 A — 다음과 동일한 룩업 테이블 `--spiraatlas-rt0` 테스트: 520 / 22000 / 6), 그리고 어떤 앵커라도 바이트 기반 코퍼스에서 벗어나면 스트립이 숨겨집니다 (Mix 배지의 앵커와 동일한 깊이). `v2.64.1`/Aeon `v2.64.3`). (2) **라벨스 스피어 (정직한, `partial`):** `sphere.bin ActionValue=0x0000` 지금은 **"None / Passive"**라고 표시되며 `RangeValue=0x00` "Unknown" 대신 **"None"**이 표시됩니다 — 이 `0x00` 이는 코퍼스에서 세 번째로 타당한 값이며(터치 효과가 없는 구의 약 40%, 스카우트 Jarvis-AURON), 생소한 것은 아닙니다. 드롭다운 메뉴에 “None” 옵션이 추가되었으며, 레이블의 폴백 값이 수정되었습니다. (3) **`AiBibleWhereAppears.For`:** 읽기 전용 사례 `player-growth` 그리고 `mix` (런타임 효과를 유발하지 않는, "어디에 나타나는지"를 솔직하게 기술한 텍스트; `sphere-grid-node` (이미 존재함). **PATCH** (기존 기능 재사용: 액세서를 사용하는 UI + 엔진 `Common` ANIMA에서 이미 제작된 것들 + 라벨 마무리 작업; 직접적인 선례: Mix 배지 `v2.64.1`/Aeon `v2.64.3`/쇼핑 `v2.61.2` PATCH였습니다; 의문 해소→PATCH). writer nov 없음

o: SphereGridExplorer 배지는 이미 존재했습니다 (`v2.60.1`), 플레이어 성장 및 스피어 토폴로지의 writer/save는 **변경되지 않음**. provider/gate는 건드리지 않음 (`--spiraatlas-rt0` (손상되지 않은), 엔진 `Common` (단순히 실행만 함), runtime/Aurora/native-menu/SIN, TIDUS/BRASKA/JECHT/RIKKU/WAKKA/VALEFOR/AURORA도 없음. 빌드 오류 0개 / 경고 361개; `--spiraatlas-rt0` + `--player-rt0` + `--spheregrid-layout-rt0` + `--aicmdmeta-rt0` PASS. 문서: `docs/ai/ATLAS_LULU_PLAYER_GROWTH_SPHERE_BADGE_UI_RESULT_2026-06-10.md`. [이전: `v2.65.0`] — Jarvis-LULU
- **🧬 `v2.65.0` — Spira Data Atlas의 PC/Player Growth (읽기 전용, `proved-candidate`, 바이트 기반, 작업 독립적).** PC 성장/통계 데이터의 실제 출처를 제공자에 연결: 신규 `SpiraDataAtlasDetailKind.PlayerGrowthStat` + 값 보호된 액세서리 `SpiraDataAtlasCatalog.TryGetPlayerGrowthStat(source, characterIndex, field, currentRawValue)`. 출처 = **`ply_save.bin`** (기본/현재 통계) + **`ply_rom.bin`** (성장 ROM: AP 곡선 `ApReq A/B/C/Max` + 자가 성장 계수 `*CoefA/B`), 바로 그 `PlayerGrowthEditor` edita (파서 `PlayerKernel_File`, RT0 인증: `--player-rt0`). **20개의 슬롯**(0–6 PC, 7 게스트=시모어, 8–17 이온, 18–19 매핑되지 않음)은 **바이트 단위로 정리된 표**에서 가져온 것입니다(`FfxLib/SpiraDataAtlas/PlayerGrowthData.cs`, 생성자: `tools/ffxdataparser_bridge/build_player_growth_index.ps1 -EmitCSharp` ~부터 `.bin`), 따라서 다음이 포함되지 않은 모든 빌드에는 `work/` (≠ `PcAeonFineStat`, 이는 다음의 여부에 달려 있는데 `work/pc_save_stats_catalog.csv` (그리고 스냅샷뿐입니다). 이름은 런타임에 다음을 통해 해결됩니다. `Character_Enum` (단일 진실의 원천). **정직성 (명백하지 않음):** 스탯 성장 계수는 **Aeon 전용**입니다 — PC/게스트의 계수는 0으로 설정되어 있습니다 (PC는 **Sphere Grid**를 통해 스탯을 성장시킵니다); 이 ROM에서 PC의 유일한 성장 경로는 **AP 곡선**입니다. 축은 다음과 다릅니다. `sum_grow.bin` BRASKA 제공 (자동 레벨링 ≠ 사용자 지정 레시피). **지역별:** `ply_save`/`ply_rom` **위치에 불변이 아닙니다** ( `new_uspc` jppc/inpc와는 다릅니다; 집계된 표 = `new_uspc`, 편집자가 불러오는 지역). 게임 내 레벨당 AP / 계수당 획득량 공식 = **`RT2-pending`** (테스트된 바이트/필드, 역산되지 않은 런타임 산술). Value-guard = 

에디터의 동일한 값 공간 → 필드 편집 (원본과 다름), 알 수 없는 슬롯/소스/필드 → 액세서리 `false` → 배지 일부 (Aeon/Shop/Mix 미러). 게이트 `--spiraatlas-rt0` `21296 → 21316` (+20; 모두 고유) + **18개의 새로운 어세트** (개수 20/8/10/2; PC 계수 0; Aeon 계수 0이 아님; uspc 영역; Tidus BaseHp 520 / ply_rom AP max 22000 / Valefor HpCoef 6 조회; value-guard `9999` 숨김; 범위 외 슬롯/소스/필드 누락; 도메인 검색; BIBLE 도메인 플레이어 성장). 읽기 전용: **writer/UI/runtime/SIN 없음**; 재생되지 않음 `WriteSave`/`WriteRom`, `PlayerGrowthEditor` UI, 엔진 `Common` ANIMA(소비 전용)도, BRASKA/AURON/JECHT/RIKKU/WAKKA/VALEFOR/AURORA/SIN도 아닙니다. 빌드 오류 0개 / 경고 361개; `--player-rt0` + `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS. 문서: `docs/ai/ATLAS_TIDUS_PC_GROWTH_PROVIDER_RESULT_2026-06-10.md` + 스카우트 `docs/ai/ATLAS_TIDUS_PC_GROWTH_SCOUT_RESULT_2026-06-10.md`. [이전: `v2.64.3`] — Jarvis-TIDUS
- **🦅 `v2.64.3` — 사용자 정의 편집기(Customization Editor)의 Aeon Growth 증거 배지(읽기 전용, 값 보호, 편집 시 숨김).** 다음을 연결하세요. `<common:AtlasEvidenceBadgeStrip>` 의 **"Aeon Grow / Teach"** 탭에서 `CustomizationEditor` (card "Recipe Editor"), 이미 생성된 액세서를 사용하여 `SpiraDataAtlasCatalog.TryGetAeonGrowthRecipe(entryIndex, currentResultRaw, currentItemRaw)` (`v2.64.0`). 새 `AtlasEvidenceInfo? SelectedAeonEvidence` 에서 `CustomizationEditor_DataModel`, 선택 변경 시 및 선택된 행이 트리거될 때 재계산됨 `RawResult` (`AeonRecipeChanged`) → **hide-on-edit**: 습득한 스킬/스탯을 수정하거나, 비용 아이템(상충되는 원재료) 또는 범위 외의 지수를 수정하면 액세서가 반환됩니다. `null` 그리고 스트립이 숨겨집니다(배지 스테일 없음), Mix의 정확한 미러(`v2.64.1`). 10가지 스탯 레시피를 완료하면 배지를 획득합니다 **`partial`** (cost-semantics: 편집기가 렌더링합니다 `Primary× item`, 하지만 게임 내에서는 비용이 1개 아이템/적용당입니다). **Writer나 비용 표시를 수정하지 않음** (범위 외). 엔진을 재사용합니다 `Common` ANIMA 제품 (소비용만). PC는 계속 `blocked` (PC 행 없음) 및 Sphere `metadata-only` (조인 없음) — 표시할 내용이 없습니다. 프로바이더/게이트 변경 없음 (`--spiraatlas-rt0` 손상되지 않은, `21296` 상세 정보 / 77 Aeon). 빌드 오류 0개 / 경고 361개; `--customization-rt0` 

+ `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS. JECHT/Mix, TIDUS/PC, AURON/Sphere, RIKKU/WAKKA/VALEFOR/AURORA/SIN은 재생되지 않습니다. 참고: `docs/ai/ATLAS_BRASKA_AEON_GROWTH_BADGE_UI_RESULT_2026-06-10.md`. [이전: `v2.64.2`] — Jarvis-BRASKA
- **🏐 `v2.64.2` — 블리츠볼 세이브 라이터 LAB + 오프셋 SAVE-PROVED와 실제 세이브(토너먼트 없음) 비교.** 블리츠볼 상금 오프셋이 RE에서 **save-proved**로 변경되었습니다: 실제 세이브 파일을 찾았습니다 (`Documents\SQUARE ENIX\...\FINAL FANTASY X\ffx_000..006`, 7개의 슬롯 `0x6900` = `0x40 header + 0x68C0 SaveData`)와 `ffx_000` 정확하게 해독했습니다(‘liga’ = 메가엘릭서/메가포션/스피드 스피어, ‘torneio’ = 엘릭서/슈퍼 골키퍼/포션 등) — **암호화나 압축이 없는 일반 텍스트**로 저장 (gil/story/battle_count는 정상), `--base 0x40` 확인됨. 헤더 `0x40` 구독 중입니다 `"cxs"` + 플레이 시간/위치; **SaveData의 체크섬과 일치하는 필드가 없음** (차단용 체크섬이 없는 것으로 보이지만, 게임 내 로드 1회가 누락됨). 새로운 LAB 라이터 `Tools/BlitzballSaveWrite.cs` (`--blitz-save-write <in> <field> <value> <out>`): **새 파일**에 1개의 prize-index u16을 기록합니다(원본을 절대 덮어쓰지 않으며, 인플레이스 덮어쓰기를 거부함). before/after는 Atlas 카탈로그를 통해 해결됩니다. 다음의 복사본에서 유효성이 검증되었습니다. `ffx_006`: `tournament0 25 (Elixir) -> 50 (Saturn Crest)`, diff = 정확히 2바이트, 나머지는 바이트 단위로 동일. `BlitzballSaveRead.Resolve` 돌았다 `internal ResolvePrize` (작성자가 재사용함). **세이브 파일 (ffx_NNN) ≠ 게임 파일**: 세이브 파일을 편집하면 이 진행 상황이 변경됩니다; 풀을 변경하면 (`takara.bin` (220..320)는 Treasure/RIKKU입니다. Atlas UI/Shop/Treasure/Mix/Common/Aurora/Bahamut/SIN은 건드리지 마세요. 빌드 오류 0개 / 경고 361개. 문서: `docs/ai/BLITZBALL_SAVE_RUNTIME_WRITER_SCOUT_2026-06-09.md`. [이전: `v2.64.1`] — Jarvis-WAKKA
- **⚗️ `v2.64.1` — 믹스 테이블 편집기(Mix Table Editor)의 Atlas 증거 배지(읽기 전용, 값 보호, 편집 시 숨김).** 액세서를 연결하여 UI를 읽기 전용으로 설정 `SpiraDataAtlasCatalog.TryGetMixCombination` (게시일: `v2.63.0`)에서 `MixTableEditor`: **"Combination Editor"** 카드(세부 정보 패널)에는 이제 `<common:AtlasEvidenceBadgeStrip>` 선택한 믹스 조합에서 — 조합당 하나의 스트립(줄 단위가 아님; 6,328회의 조회 및 노이즈 방지), Treasure/Shop과 정확히 동일. `Mix

TableEditor_DataModel` ganhou `[ObservableProperty] AtlasEvidenceInfo? SelectedMixEvidence` + `RefreshSelectedMixEvidence()` (`TryGetMixCombination(origin.Index, result.PartnerIndex, result.RawResult) → AtlasEvidenceInfo.ForDetail`), chamado em `OnSelectedResultChanged` (cobre troca de combinação E de origin via cascata) e em `ResultChanged` quando `RawResult` muda (cobre edição do resultado via `ResultRef→SyncBack→NotifyComputedChanged` e o "Set Empty"). **Hide-on-edit:** editar o resultado p/ outro item, "Set Empty" (raw 0), célula vazia/espelho do triângulo superior, ou par fora do corpus → accessor `false`/`null` → a strip **auto-esconde** (`IsVisible=false`); ordem `(원본, 파트너)` irrelevante (canonicalização max/min no accessor). **REUSO** da capacidade `v2.63.0` + da infra `일반` da ANIMA (só consumida) → **PATCH** (precedente: badges UI de Shop `v2.61.2`/`v2.61.5` foram PATCH). Sem writer novo: `--mixtable-rt0` segue **byte-identical** (25108/25108). Não toca o motor `일반` (ANIMA), o provider, Treasure/Shop (RIKKU), BRASKA/WAKKA/AURORA/BAHAMUT/SIN. Revisado por workflow adversarial de **5 lentes** (hide-on-edit, writer/read-only, ANIMA-boundary, XAML-binding, honesty) + síntese → `ship`, 0 defeitos. Build 0 erros / 361 warnings; `--spiraatlas-rt0` (Mix 6328) + `--mixtable-rt0` (byte-identical) + `--aicmdmeta-rt0` PASS. Doc: `docs/ai/ATLAS_JECHT_MIX_BADGE_UI_RESULT_2026-06-10.md`. [anterior: `v2.64.0`] — Jarvis-JECHT
- **🦅 `v2.64.0` — Spira Data Atlas의 Aeon 성장/맞춤 설정 (읽기 전용, `proved-candidate`, Aeon 전용, 편집본).** 다음을 삽입하세요. `sum_grow.bin` (FFX의 Aeon 사용자 정의 테이블)을 프로바이더에서 detail kind read-only로 설정: 신규 `SpiraDataAtlasDetailKind.AeonGrowthRecipe` + 값 보호된 액세서리 `SpiraDataAtlasCatalog.TryGetAeonGrowthRecipe(entryIndex, currentResultRaw, currentItemRaw)`. **Aeon-ONLY:** `sum_grow.bin` 636바이트입니다 (헤더 `0x14` + **77개 항목 × 8B**, `Target` 항상 `0x007F`=Aeon, `jppc`==`inpc` 바이트 동일) → 67개의 능력 레시피 (결과 카테고리 3 → 명령어) + 10개의 능력치 레시피 (결과 카테고리 0 → 능력치 옵션, 보조=1). **PC나 스피어 그리드 관련 행은 없습니다** (`PcAeonFineStat` 이는 또 다른 코퍼스입니다; 그리드의 위상은 

`sphere.bin`/`panel.bin`). **출처 미상-`work/`:** 77개의 행은 **바이트 단위로 컴파일된** 테이블에서 가져온 것입니다 (`FfxLib/SpiraDataAtlas/SumGrowAeonRecipeData.cs`, 생성자: `build_sum_grow_aeon_fine_index.ps1 -EmitCSharp` ~부터 `sum_grow.bin`), 따라서 다음이 포함되지 않은 모든 빌드에는 `work/` (≠ Mix/Sphere/Shop, 이는 다음 요소에 의존하므로 `work/`). 이름/라벨은 런타임에 의해 `AeonCustomizationEntry`+편집자 자체 사전 (단일 신뢰 소스, RT0 검증 완료) `--customization-rt0`), 결코 새롭게 재창조된 적이 없다. **스탯 레시피 비용 = `partial`** (편집기가 렌더링합니다 `Primary× item`; 게임 내에서는 1회 사용당 아이템 1개가 소모되며, `Primary` (증가분) — 칼럼에 표기됨 `evidence` (`;cost-semantics-partial`), 텍스트뿐만 아니라. Gate `--spiraatlas-rt0` `21219 → 21296` 상세 정보 (+77 이온; 모두 고유) + **13개의 새로운 어세트** (개수 77/67/10; Aeon 전용; PC 없음; Sphere 없음; 조회 능력 66→Ultima/Supreme Gem; 조회 스탯 67→HP+100/Power Sphere/비용-부분; 값-가드 `0x9999` 숨기기; 범위 외 인덱스 누락; 도메인 검색; BIBLE 도메인 aeon-growth). 읽기 전용: writer/UI/runtime/SIN 없음; RIKKU/WAKKA/JECHT/BAHAMUT/AURORA는 실행되지 않음, 엔진 `Common` 배지(ANIMA)도 `WriteAeon`/저장 경로. **YUNA 백로그의 Q1 대기열 잠금 해제** (이전에는 `blocked`). Scout에서 4-렌즈 적대적 워크플로우를 통해 검증됨. 빌드 오류 0개 / 경고 361개; `--customization-rt0` + `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS. 문서: `docs/ai/ATLAS_BRASKA_SUM_GROW_FINE_SCOUT_RESULT_2026-06-10.md` + `docs/ai/HANDOFF_BRASKA_SUM_GROW_FINE_INDEXER_NEXT_2026-06-10.md`. [이전: `v2.63.0`] — Jarvis-BRASKA
- **⚗️ `v2.63.0` — Spira Data Atlas의 믹스 세부 정보 유형 (읽기 전용, `proved-candidate`, value-guarded).** Atlas에서 Mix의 첫 번째 정직한 앵커: 새로운 `SpiraDataAtlasDetailKind.MixCombination` + 액세서리 `SpiraDataAtlasCatalog.TryGetMixCombination(originIndex, partnerIndex, currentRawResult)` 파서-캐노니컬 데이터셋을 연결하면 `work/step0_consolidated_v5/mix_combinations.csv` (**6,328행 = 112×113/2, 중복 키 0개**)가 프로바이더에 있습니다. 이 `prepare.bin` 112×112 크기의 **하단 삼각형** 행렬입니다 (원점 `O` 파트너 슬롯에서만 0이 아닌 결과가 나타납니다 `0..O`), 따라서 순서가 정해지지 않은 각 쌍은

ado `{a,b}` origin=max, partner=min인 단일 표준 셀에 존재하며; 키 `mix:0x{0x2000+max}+0x{0x2000+min}` 지수를 통해 재구성할 수 있다 `(origin, partner)` 편집자 주 **추측 없이**. `result_hex` 편집기가 다음과 같이 읽는 바로 그 little-endian 단어입니다. `MixResultRow.RawResult` (바이트 단위로 동일한 편집기 리더, 작성자: `--mixtable-rt0`; 동일한 엔디안성을 가진 파서) → value-guard = 동일한 공간 내의 정수 비교: 결과를 수정하면 매치가 깨지고 배지가 숨겨집니다(스탈 없음); 빈 셀(원시 0, 상단 삼각형의 전체 미러 포함)은 단락 처리됩니다. **단일 출처:** value-dict + detail은 동일한 CSV에서 추출됩니다. Gate `--spiraatlas-rt0` `14891 → 21219` 상세 정보 (+6,328 Mix; 모두 고유) + **8개의 새로운 어세트** (개수 6,328; 조회 0+0→울트라 포션) `0x30AC`; 정경 순서 `(3,1)==(1,3)`; value-guard `0x9999` 숨김; 빈 셀 raw-0 누락; 테이블 외 인덱스 누락; 도메인 검색; BIBLE 도메인 mix). 읽기 전용: writer/UI/runtime/SIN 없음; Mix 편집기(writer), Treasure/Shop(RIKKU), 엔진에는 **영향을 미치지 않음** `Common` ANIMA 배지(검색을 통해서만 사용 가능)나 Aurora/Bahamut/native-menu도 아닙니다. **YUNA 백로그의 Q2 대기열을 해제합니다** (이전에는 `blocked`). UI의 배지 와이어 = 다음 핸드오프 (`docs/ai/HANDOFF_JECHT_MIX_ATLAS_PROVIDER_NEXT_2026-06-10.md`). 빌드 오류 0건 / 경고 361건; `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS. 문서: `docs/ai/ATLAS_JECHT_MIX_DETAIL_KIND_SCOUT_RESULT_2026-06-10.md`. [이전: `v2.62.1.1`] — Jarvis-JECHT
- **🏐 `v2.62.1.1` — 블리츠볼 세이브 리더/차이점 비교(읽기 전용) (prize save의 스카우트 RE).** 읽기 전용 CLI 도구 (`Tools/BlitzballSaveRead.cs` + dispatch 번호 `Program.cs`) 저장 파일을 여는 `.dat` 그리고 블리츠볼의 4가지 상금 지수를 해독하고 (`league`/`tournament` × `prize[3]`/`top-scorer`) 재승인된 오프셋에서 (SaveData @ `file+0x40`, BlitzballData @ `+0x1984`; 리그 상금 @ 저장 파일 `0x1A3C`, 토너먼트 `0x1A42`, 최다 득점자 `0x1A48`/`0x1A4A`), 이미 구축된 Atlas 데이터셋을 통해 각 보상 값을 산출합니다. 모드: `--blitz-save-read <save>` (해독) 그리고 `--blitz-save-diff <before> <after>` (save-compare: A와 B의 상금 비교 + 전체 파일의 바이트 차이, BlitzballData 내의 실행 횟수 표시 및 u16 디코딩) `old->new`). `--base` ov

오류가 있을 수 있음 (디스크 기반은 **아직** 라이브로 확인되지 않음). 기반 `SaveData` RVA `0xD2CA90` IDA에 의해 확인됨 (`sub_785300` 돌아오다 `imagebase+0xD2CA90`) + Fahrenheit + MemoryMap; `sub_8B5450` (memcpy `0x68C0` ~의 `SaveFile+0x40`) 파일 레이아웃을 확인합니다. **100% 읽기 전용: save/game/RAM에 아무것도 기록되지 않습니다.** 합성 스모크 테스트(디코딩 + 보상 해결 + 변경 사항 파악을 위한 diff)를 통해 검증되었습니다. Atlas UI / Shop/Treasure/Mix / Common / Aurora/Bahamut/SIN은 건드리지 않았습니다. 빌드 오류 0개 / 경고 361개. 문서: `docs/ai/BLITZBALL_SAVE_RUNTIME_WRITER_SCOUT_2026-06-09.md`. [이전: `v2.62.1`] — Jarvis-WAKKA
- **🔗 `v2.62.1` — 단일 소스(FONTE ÚNICA)를 사용하는 아이템 샵 밸류 가드 (드리프트 제거 + 피연산자 랜드마인 고정).** 아이템 샵 밸류 가드의 강화: 프로바이더가 이제 `slot_value_hex` 동일한 CSV 파일에서 (`item_shop_command_crosslink.csv`) detail을 생성하는 `atlas:item-shop`, 두 번째 파일 대신 (`item_shop_slots.csv`) — value와 detail은 이제 같은 행에 표시되며 **서로 달라서는 안 됩니다**. 브릿지 `build_spira_atlas_step0c_crosslinks.ps1` 이제 방송합니다 `slot_value_hex` 크로스링크 칼럼에서 **잠복한 지뢰를 제거한다**: 수학 `slot_value + 0x2000` (다음 시기에 작성됨: `slot_value_hex` (비어 있음/원시 지수)는 이제 계산에 포함될 것입니다 `0x4000` 이제 파서가 인코딩된 전체 값을 출력하므로 (`0x2000` (p/ Potion) → FALSE와 결합 `Attack` (AI 명령어) — 바로 가드레일의 범주 오류입니다. `item_operand_hex` 설계상 비어 있습니다(game-index 항목 ≠ AI 연산 대상). 3가지 관점(드리프트/단일 소스, 연산 대상/인코딩, 회귀/기어)의 적대적 워크플로우를 통해 검증됨 — `sound`; 수정된 댓글 2개. **멀티레인 참고 사항:** PROVIDER의 절반이 `v2.62.0` (커밋 `2bc3d7b0`, lane WAKKA, `git add` (광범위한 경쟁자); 이 커밋은 HEAD를 일관성 있게 만드는 BRIDGE의 절반을 포함합니다. Gear는 변경되지 않았습니다. writer/UI/runtime은 포함되지 않았으며, Treasure/Mix/Common/Aurora/native-menu도 변경되지 않았습니다. 빌드 결과 오류 0개 / 경고 361개; `--spiraatlas-rt0` PASS (9개 상점: 장비 5개 + 아이템 4개) + `--aicmdmeta-rt0` PASS. 문서: `docs/ai/ATLAS_RIKKU_ITEM_SHOP_SINGLE_SOURCE_RESULT_2026-06-09.md`. [이전: `v2.62.0`] — Jarvis-RIKKU
- **🏐 `v2.62.0` — 블리츠볼 프라이즈 익스플로러: UI 재설계

Atlas 전용 광고 모듈.** 새로운 모듈 `Modules/BlitzballPrizeExplorer` (Reference/RE 그룹의 **Blitzball Prizes 🏐** 탭, 프로젝트 게이트 없음) 이미 마감된 카탈로그를 사용하는 `SpiraDataAtlasCatalog.BlitzballPrizeDetails` (도메인 `blitzball-prize`): **prize id · takara index · reward resolved · kind · evidence** 열을 갖춘 검색 가능한 DataGrid, 상태/증거 및 종류별 필터, **규칙**이 표시된 배너 `prize 0..100 -> takara 220..320 -> reward`** (검증된 후보 오프라인), 및 출처/규칙/"어디에 표시되는지"/제한 사항이 포함된 상세 패널 + `<common:AtlasEvidenceBadgeStrip>` (Atlas/BIBLE 배지). 정직성 유지: treasure = `proved-candidate` (절대 RT2 아님); 리그/토너먼트/이벤트 관련 64개 스크립트 사이트는 다음과 같이 명시적으로 표시됩니다. `blocked` (이벤트당 보상은 런타임/세이브); tech = `partial`; 오버드라이브 = `metadata-only` — 현재 레이블 외에는 아무것도 녹색으로 변하지 않습니다. 새로운 읽기 전용 액세서리(소문자) `SpiraDataAtlasCatalog.BlitzballPrizeDetails` (lazy, dev `work/` (only) + 게이트에 2개의 어세트 `--spiraatlas-rt0` (229행 = 164개 카탈로그 + 64개 사이트 + 1개 가드레일; 도메인 확인). 라이터 및 런타임 미지원; RIKKU/Shop/Treasure/Mix는 실행되지 않음, 엔진 `Common` ANIMA(소모만)이나 Aurora/Bahamut/SIN은 제외. 빌드 오류 0개 / 경고 361개; `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS. 문서: `docs/ai/ATLAS_WAKKA_BLITZBALL_UI_RESULT_2026-06-09.md`. [이전: `v2.61.5`] — Jarvis-WAKKA
- **🛍️ `v2.61.5` — 아이템 상점의 아틀라스 증거 배지 (가치 보호) — 장비+아이템 세트를 완성합니다.** 장비 상점에서 검증된 가치 보호 기능을 복제합니다 (`v2.61.2`) 아이템 샵으로, 이제 `v2.61.1`+코퍼스 잠금 해제 시 항목에 바이트 단위의 1:1 원시 값이 할당되었습니다. 새로운 읽기 전용 액세서리 `SpiraDataAtlasCatalog.TryGetShopItemSlot(bank, slot, currentRawValue)` + 게으른 `_shopItemSlotValues` (읽기 `item_shop_slots.csv`, dev `work/` only, 컴파일된 폴백 없음) — 의 정확한 미러 `TryGetShopGearSlot`: 해결 `atlas:item-shop:item-shop-0x{bank}-slot-{n}` **오직** 다음의 경우에만 `RawValue` 슬롯의 현재 값은 여전히 코퍼스와 일치합니다 (디스크상의 ushort LE = 게임 인덱스 항목들 `0x2xxx`(편집기 내 동일한 공간)이며, ≠ 0이다. `ShopExplorer_DataModel` 이제 다음을 계산합니다 `Evidence` shop-kind(switch Gear/Item)에 의해; o `<common:AtlasEvidenceBadgeStrip>` 카드에 

**이미 공유되었던** 슬롯 (`v2.61.2`), 그러면 XAML을 변경하지 않고도 항목에 배지가 표시됩니다. 슬롯을 편집하면 행이 재구성되고 스트립이 숨겨집니다(스탈 현상 없음). Gate `--spiraatlas-rt0` **아이템 어세트 4개**를 획득했습니다 (lookup `0x2000`/포션, 불일치 `0x9999` 숨김, 빈 슬롯 raw 0, no-corpus 슬롯 3), 모두 PASS (기어는 계속 PASS). 재생성됨 `work/step0_consolidated_v5/item_shop_slots.csv` ~와 함께 `slot_value_hex` (404/404, 개발자 전용, 커밋되지 않음). 읽기 전용: 작성자 없음, Treasure/Mix/Common/Aurora/native-menu/runtime 수정 금지; 엔진 `Common` ANIMA에서 실행 시 오류 없이 완료됨. 빌드 오류 0개 / 경고 361개; `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS. 문서: `docs/ai/ATLAS_RIKKU_SHOP_ITEM_BADGE_UI_RESULT_2026-06-09.md`. [이전: `v2.61.4`] — Jarvis-RIKKU
- **🎮 `v2.61.4` — WIRED의 Native Menu Shell `ffx-hooks.dll` (5단계 적용, 기본값은 OFF).** 5.1단계 패치(적대적 검토 완료, 차단 사항 없음)가 **적용**되었습니다. `dllmain.cpp` (최소 패치: 오직 `dllmain.cpp`, +166줄, 0개 삭제) — 다음을 활성화합니다. `NativeMenuShell.h` (‘NOSSO’라는 텍스트가 포함된 기본 메뉴) 오로라 브리지 (`PhotoModeActions.h`) 펌프를 경유하여 우회 `FFX_Menu_PerFramePump 0x8A9C50` (`int __cdecl(uint)`, IDA 검증 완료, 메인 스레드). **기본값은 OFF:** `FFXHOOKS_ENABLE_NATIVE_MENU=1` 우회 경로를 설정하세요. 메뉴는 **F7** 단축키로만 열립니다. **오로라 계약 수락 및 이행:** `PhotoMode::Tick()` = **선택지 A** (상단 `AuroraD3DRender`, 조기 반납 전에, 다음과 같이 `FFXHOOKS_ENABLE_AURORA_OVERLAY=1`, hunk AURORA 소유); FREEZE = 유일한 소유자 `g_pm.frozen`; `NtSuspendProcess` **금지**; `PhotoMode::g_base=g_base` init에서. wire는 **단순히 호출할 뿐입니다** `PhotoMode::*`** — **RAM 카메라라고 쓰지 마세요 (`0xD378A0`)도, RAM**도 아닙니다. 빌드 `-WithPolyHook -Release` **PASS** (`dllmain`+`MusicHook`+`ElementHook` → `ffx-hooks.dll`). **6A/NPC 단계는** 이번 패치에서 **제외**되었습니다. **RT2-보류 중:** 메뉴/필드 내에서 F7 키를 누르면 기본 "사진 모드" 팝업이 표시되어야 합니다 (일회성 저장). 문서: `docs/ai/HANDOFF_BAHAMUT_NATIVE_MENU_WIRE_BLUEPRINT_2026-06-09.md`. [이전: `v2.61.3`] — Jarvis-BAHAMUT
- **📒 `v2.61.3` — Atlas 제공업체: `BlitzballPrizeRef` 76줄 분량의 원시 스크랩 대신 정규화된(읽기 전용) 데이터.** `SpiraDat`의 prize 섹션

aAtlasCatalog` deixou de varrer `bltz0200/0201` cru e passou a ler o dataset normalizado do WAKKA (`work/step0_블리츠볼_상품_참조_2026-06-09`): **164 prize-index rows** (101 treasure `합격 후보자` via `prize+220 -> takara 220..320 -> reward`, fechado por 3 fontes offline — Fahrenheit `blitz_prize.cs` + `bltz0201 보물 획득` + `bltz0200/0201 Treasure-Label` — sobre takara RT0; 60 tech `부분적`; 3 overdrive `메타데이터 전용`) + **64 script-sites `차단됨`** (prêmio por-evento é variável de runtime/save). Guardrail reescrito: regra `합격 후보자` offline, prêmio concreto por liga/torneio `차단됨`, nunca RT2, nunca writer. Gate `--spiraatlas-rt0` subiu de `14739` para **`14891`** detalhes (`블리츠볼 상금 참조 번호 76 -> 228`) e ganhou asserts data-grounded (treasure 101 / tech 60 / overdrive 3 / sites 64; prize 0 -> takara 220 Hi-Potion; prize 100 -> takara 320 Phoenix Down; treasure `합격 후보자`-não-RT2; overdrive `메타데이터 전용`; site `차단됨`). Patch verificado por review adversarial de 4 agentes antes de aplicar. Sem UI, sem writer, sem SIN/runtime; não toca Shop/Treasure/Mix (RIKKU), o motor de badges `일반` (ANIMA) nem Aurora/native-menu. Build 0 erros / 361 warnings; `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS. Doc: `docs/ai/ATLAS_WAKKA_BLITZBALL_PROVIDER_INTEGRATION_RESULT_2026-06-09.md`. [anterior: `v2.61.2`] — Jarvis-WAKKA
- **🏷️ `v2.61.2` — Shop Explorer의 Atlas 증거 배지 (장비 전용, 가치 보호).** 다음을 연결하는 읽기 전용 UI: `TryGetShopGearSlot` (에서 검증됨) `v2.61.1`)에서 `ShopExplorer`: **gear-shop**의 각 슬롯에는 다음과 같이 표시됩니다 `<common:AtlasEvidenceBadgeStrip>` 해당 슬롯의 장비 보상에서 ‘출현 위치’/배지 — **오직** `RawValue` 현재 버전도 여전히 코퍼스와 일치합니다. `ShopEditableSlotRow.Evidence` (`init`)는 `From()`: `source.Kind == Gear && TryGetShopGearSlot(entry.Index, slot.SlotIndex, slot.RawValue)`. 행은 모든 변경 시마다 재구성되므로 (콤보박스/비우기/실행 취소/취소/저장/새로 고침 → `RebuildSelectedSlots`), 슬롯을 편집하면 기록이 재계산되고 **스트립이 숨겨집니다** (오래된 배지 없음). **아이템 상점에는 배지가 절대 부여되지 않습니다** (저장 `Kind == Gear` + 더블 가드: 코퍼스에 해당 항목이 없음); 슬롯이 비어 있음

o (raw 0)에서 단락이 발생합니다. 3가지 렌즈를 활용한 적대적 워크플로우(전체 라이프사이클 / item-shop+binding / honesty)를 통해 검증됨 → 모두 `sound`, 결함 0건. 인프라 재사용 `Common` ANIMA의 (모터를 건드리지 않은); 새로운 라이터, 새로운 파서, SIN/runtime/Aurora/native-menu가 없는. Tier `parser-corpus`+`RT0`+`read-only`, 결코 `proved` 런타임. 빌드 0개 오류 / 361개 경고; `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS (게이트 없음) `--shop*` 에서 `Program.cs`). 문서: `docs/ai/ATLAS_RIKKU_SHOP_GEAR_BADGE_UI_RESULT_2026-06-09.md`. [이전: `v2.61.1`] — Jarvis-RIKKU
- **🛒 `v2.61.1` — 기어 샵의 아틀라스 밸류 가드 슬롯 (`proved-candidate`) + 아이템 상점, 솔직히 말해서 `blocked`.** Shop 스카우트 2차 라운드 (`HANDOFF_ATLAS_RIKKU_SHOP_SLOT_VALUE_INDEXER`): Treasure에서 검증된 것과 동일한 value-guard를 Shop에서도 해제. 8명의 요원(포렌식 5명 + 공격 시뮬레이션 2명 + 종합 분석 1명)으로 구성된 워크플로우를 통해 검증됨: `RawValue` 에디터 내 슬롯의 값은 디스크에 저장된 원시 ushort 리틀 엔디안 형식이며 (`ShopTable_File` ≡ `ReadBaselineSlotValue`), 그리고 `slot_value_hex` ~의 `gear_shop_slots.csv` (445/445 거주, 비율 `shop_arms.bin`) 바로 그 단어입니다 — 따라서 guard는 동일한 공간에서 정수 비교 연산이며, **off-by-one 오류가 없습니다** (목록 `MinIndex=0`, 인덱스 0 = 예약된 NULL 항목, 첫 번째 판매 가능 기어 = 인덱스 1 = `0x01`). 새로운 읽기 전용 액세서리 `SpiraDataAtlasCatalog.TryGetShopGearSlot(bank, slot, currentRawValue)` + 게으른 `_shopGearSlotValues` (dev `work/` only, 컴파일된 폴백 없음, Sphere Grid 노드와 동일): 해결됨 `atlas:gear:gear-shop-0x{bank}-slot-{n}` **오직** 해당 슬롯의 현재 값이 코퍼스와 일치할 때(그리고 ≠ 0) → 슬롯을 편집하면 배지가 숨겨집니다(스탈 없음). 게이트 `--spiraatlas-rt0` **5개의 내구성 어서트**를 획득했습니다 (Tidus 긍정 조회/값 1, 값 가드 불일치 999 숨김, 빈 슬롯 raw 0, 본문이 없는 뱅크, 에지 `0x2E`/427), 모두 PASS. **아이템 상점 = `blocked`**: 코퍼스에는 원시 값이 저장되지 않습니다 (`item_shop_slots.csv.slot_value_hex` 100% 비어 있음 — `ItemShopDataObject.toString()` (이름만 출력함); string-guard는 가짜 안전성이 보장되지 않음 (포션/피닉스 다운/해독제 x47 → 유효하지 않음; 자리 표시자 + 미국판 대 일본판 → 위음성). Unlock = 파서에서 1줄 패치 + 재실행 (코퍼스 작업, 이 코드 외)

. 솔직한 티어: `proved read-only candidate (parser-corpus + reader-semantics + RT0)`, **절대** `runtime`/`byte-grounded` (없음 `arms_shop.bin` (여기에서 헥스덤프되었습니다). UI도, 라이터도, SIN도, 런타임도 없이, 엔진에 손을 대지 않고 `Common` (ANIMA). 빌드 오류 0개 / 경고 361개; `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS. 문서: `docs/ai/ATLAS_RIKKU_SHOP_SLOT_VALUE_INDEXER_RESULT_2026-06-09.md`. [이전: `v2.61.0`] — Jarvis-RIKKU
- **🐉 `v2.61.0` — 기본 메뉴 3단계: 기본 목록의 row-source를 다시 닫음 + `list-read` (프로브) + 실시간 검증된 선택 항목 읽기.** 네이티브 인게임 메뉴 경로(Yojimbo→**Jarvis-BAHAMUT**)를 이어가며, 3단계의 1번 문제("네이티브 목록의 행은 어디서 오는가?")는 IDA를 통해 해결되었습니다: 목록의 **INPUT** (`FFX_Menu_List_UpdateInput 0x8B4460`)는 **100% 일반적**이다 — 152B 객체 필드의 순수한 산술 연산(`+40` state, `+48` count, `+50` top, `+52` target, `+58` 페이지, `+66` 슬롯, `+69` 결과, `+70` scroll, `+72` 선택됨, `+28` validator), **전역 변수를 전혀 건드리지 않으며**, 서로 다른 **10개의 빌더**에서 재사용되지만, **모든 네이티브 드로우는 아이템 형태**입니다: scene3 목록 (`FFX_Menu_CreateScene3ScrollableList 0x8B4FB0` → 그리기 `0x8B4A00` → 행 `0x8B4B20`)는 다음의 행들을 읽습니다. `unk_159EC30[64*i]` (64바이트 구조체) + `byte_1866250[]` (유형), **항목 이름**은 다음으로 결정됩니다. `0x86C3C0(id→tabela)` 그리고 선택 사항인 레이블을 바로 `rowPtr+32` (유형 1); scene3/33/34를 불러오며 Customize의 전역 변수에 의존합니다. 바이너리에는 “자유 텍스트 목록”을 그리는 기능이 **존재하지 않습니다** — 따라서 우리 텍스트가 포함된 네이티브 목록(아레나 쉘 / Aurora의 포토 모드) **DLL의 드로우 콜백이 필요합니다** (5단계, 매뉴얼 §4에 명시된 경로), **문서화된 수작업 방식**(일반 입력)을 사용해야 합니다 `0x8B4460` + 기본 도형을 이용한 DLL 드로잉 `sub_8F5F70` 창 / `sub_9016B0` 문자열 / `sub_8C0640` 커서, 읽기 중 `+69`/`+72`). 오늘 프로브를 통해 전달됨: 새로운 동사 **`ffxprobectl list-read [handleHex]`**(읽기 전용)으로 **메뉴 객체 풀을 스캔** (`g_FFX_MenuObjPool 0x18408C0`, 32개 슬롯 × 152B) — 활성화된 모든 네이티브 목록/팝업을 찾아 콜백을 통해 식별하며 — 글로벌 단축키 외에도 (`dword_1866214`/`186A5DC`/`23CC120`). **✅ RT2 PASS (생중계, 2026-06-09

):** **장비 맞춤 설정** 화면에서, 풀 스캔이 탐색한 목록을 가져왔습니다 (slot[3] `@0x017A0A88`, `input=0x8D57E0` = 의 래퍼 `0x8B4460` (일반명) 및 `+72`/`SELECTED` **커서를 실시간으로 추적했습니다 (35→42)**. 그 동안 Halyson은 → 3단계 “탐색 가능한 기본 목록에서 선택 항목 읽기”를 수행했으며, **아무것도 입력하지 않고도 성공했습니다**. (보너스: `+62 = group 0x101` 재설정된 객체의 값이 일치합니다 `FFX_MenuObj_Reset` (IDA) — 메모리에 대한 오프셋이 확인됨.) RAM / Aurora / 카메라에는 영향을 미치지 않음.) `dllmain.cpp` / 저장; IDA 읽기 전용 (복사본 `_claude_ida`(문서의 rename-queue 참조). 빌드 `ffxprobectl` 오류 0개. **5단계 (블루프린트):** 네이티브 쉘의 바로 붙여넣기 가능한 스켈레톤이 `RuntimeTools/NativeMenuShell/NativeMenuShell.h` (+README) — 객체 수동 구현 + 드로우 콜백 (창+행+커서) + 폰트 인코더 + Aurora의 Photo Mode 동작을 위한 분리형 브릿지; ABI/오프셋 확인 완료 (IDA 검증 워크플로우) 및 **적대적 검토** 완료 (FFX-vs-IDA 2가지 관점 + C++ → 크래시/컴파일 오류 없음); x86 가드 + OOB 방지 클램프 + 주석이 달린 부하 지지 불변식; **와이어드 방식 아님, 건드리지 않음** `dllmain.cpp`**. **단계 5.1 (와이어 청사진, 적용되지 않음):** 평면도 + 패치 초안 (`docs/ai/HANDOFF_BAHAMUT_NATIVE_MENU_WIRE_BLUEPRINT_2026-06-09.md` + `docs/patches/BAHAMUT_NATIVE_MENU_WIRE_DRAFT_2026-06-09.patch`) 껍질을 `ffx-hooks.dll` 펌프를 우회하여 `FFX_Menu_PerFramePump 0x8A9C50` (`int __cdecl(uint)`, IDA 검증 완료, 메인 스레드) — 기본적으로 OFF (`FFXHOOKS_ENABLE_NATIVE_MENU` + 단축키 F7), 브릿지는 호출만 한다 `PhotoMode::*`; 대립적 검토 완료 (2개의 렌즈) **블로커 없음** (컴파일 검토자가 스크래치 트리에 적용했으며, `git apply --recount --check` exit 0); `dllmain.cpp` 수정되지 않음/커밋되지 않음. 문서: `docs/reverse/FFX_NATIVE_MENU_LIST_ROW_SOURCE_2026-06-09.md`. [이전: `v2.60.2`] — Jarvis-BAHAMUT
- **💰 `v2.60.2` — 트레저 에디터(기어 상자)의 아틀라스 증거 배지 + 트레저 크로스링크 정정.** 스카우트 `HANDOFF_ATLAS_RIKKU_TREASURE_SHOP_MIX_CROSSLINK_SCOUT` “Treasure에 안정적인 키가 없다”는 사건을 재조사했다. `v2.60.1` 그리고 장비 상자의 경우 **그 반대를 입증**했는데: 그 `source_key` 크로스링크의 `treasure-buki-get` 불투명하지 않다 — 그것은 `treasure:0x{index:X4}`, 

편집기 줄 인덱스에서 바로 재구성 가능. 바이트 기반 확인: `(treasure_index, buki_get_id)` 크로스링크 ≡ `(logical_index, type)` ~의 `takara.bin` **82줄(Kind=0x05, 0개의 불일치)**에 대해. 새로운 읽기 전용 액세서리 `SpiraDataAtlasCatalog.TryGetTreasureGear(treasureIndex, expectedBukiGetRow)` 해결하다 `atlas:gear:treasure-0x{index}` **value-guard 사용 시**: Treasure는 편집 가능한 모듈이므로, 배지는 다음 조건이 충족될 때만 표시됩니다. `buki_get` 현재 트렁크 상태는 여전히 코퍼스와 일치합니다 — Kind를 다시 장착하거나 교체하면 스트립이 숨겨집니다(오래된 배지 없음). 다음 카드에 적용됨: "Gear Pickup / buki_get" `TreasureEditor` 출처: `AtlasEvidenceInfo.ForDetail` + `<common:AtlasEvidenceBadgeStrip>` (배지 `parser-corpus`+`RT0`+`read-only`, 결코 `proved`). **Shop**은 `partial` (위치 기반 키 `0x{banco}:slot:{n}` 안정적이고 재조립이 가능하지만, 아이템 상점에서는 오직 `display_text` 그리고 gear-shop에는 슬롯별 인덱스가 없기 때문에, 편집 가능한 모듈에는 명확한 value-guard가 없습니다 → 오탐지 없이 UI 적용이 지연됩니다). **Mix**는 `blocked` (아틀라스에는 Mix의 detail kind가 존재하지 않음; 이를 생성하는 것은 앵커를 새로 만드는 것과 같다). **BukiGet** = 중복/1:many (이미 takara를 자가 참조함). Gate `--spiraatlas-rt0` 내구성 있는 어세트 3개(긍정적 조회 + 값 보호 + 비기어 미스)를 획득했으며, 모두 PASS로 판정되었습니다. 라이터, SIN, 런타임 없이, 배지 엔진을 건드리지 않고 `Common`. 빌드 오류 0개 / 경고 361개; `--spiraatlas-rt0`, `--aicmdmeta-rt0` 그리고 `--treasure-rt0` PASS. 문서: `docs/ai/ATLAS_RIKKU_TREASURE_SHOP_MIX_CROSSLINK_SCOUT_RESULT_2026-06-09.md`. [이전: `v2.60.1`] — Jarvis-RIKKU
- **🔮 `v2.60.1` — Sphere Grid Explorer의 Atlas 증거 배지(두 번째 읽기 전용 애플리케이션).** 배지 인프라의 `v2.60.0` 두 번째 집을 얻었습니다: 에서 노드를 선택하면 `Sphere Grid Explorer`, 패널에는 증거 배지가 표시됩니다 (`parser-corpus` + `RT0` + `read-only`), 노드의 출처 및 “어디에 나타나는지”, 출처: `AtlasEvidenceInfo.ForDetail` + `<common:AtlasEvidenceBadgeStrip>`. 새로운 소문자 읽기 전용 액세서리 `SpiraDataAtlasCatalog.TryGetSphereGridNode(layout, nodeIndex)` (거울 `TryGetMonsterDetail`) 매핑한다 `SourceKind` (기본/표준/전문가 → `OSG`/`SSG`/`ESG`) + 노드의 인덱스 `atlas:sphere-grid-node:{layout}:{index}` — id idên

카탈로그에 나와 있는 것과 일치하면 노드가 해결됩니다. 어떤 미션에서든 스트립은 **숨겨집니다**(가짜 배지 없음). **크로스링크의 정직성 (Halyson이 강조한 규칙):** 요청된 4개의 모듈 중 Sphere Grid만이 안정적인 크로스링크를 가지고 있습니다. `Treasure` (`sourceKey` (buki_get 인덱스의 불투명하고 되돌릴 수 없는), `Shop` (아틀라스의 키는 뱅크+슬롯이며, `item_operand_hex` 항목이 비어 있는 상태로 전달되며, 피연산자를 기준으로 매핑하면 범주 오류가 발생합니다) 그리고 `Mix` (아틀라스에 Mix의 detail kind가 존재하지 않음) **의도적으로 제외됨** — 그곳에 배지를 강제로 추가하면 “안정적인 크로스링크 없음 → 숨기기”라는 가드레일을 위반하게 됩니다. Writer, SIN, 런타임 없이, 배지 엔진을 건드리지 않고. 빌드 오류 0개 / 경고 361개; `--spiraatlas-rt0` PASS (2493개의 스피어-그리드 노드) 및 `--aicmdmeta-rt0` PASS. 적대적 에이전트에 의해 검증됨: 결함 0개. [이전: `v2.60.0`] — Jarvis-MAGIC
- **🏷️ `v2.60.0` — Monster AI Editor에 적용된 재사용 가능한 읽기 전용 Atlas 증거 배지.** 첫 번째 레이어 `HANDOFF_ATLAS_READONLY_MODULE_BADGES`: 항목별로 데이터의 출처와 신뢰할 수 있는 범위를 보여주는 재사용 가능한 인증 배지 구성 요소입니다. 작성자 정보, 적용 절차, SIN 번호 없이도 사용 가능합니다. 신규 `Modules/Common/AtlasEvidenceBadgeStrip.axaml(.cs)` (속성을 가진 UserControl 드롭인) `Evidence`) + `Modules/Common/AtlasEvidenceBadge.cs` (`AtlasEvidenceBadge` 중증도에 따라 색상 구분 + `AtlasEvidenceInfo` 배지/출처/"어디에 표시되는지", 팩토리 `ForBibleEntry`/`ForDetail`). **핵심 결정 (대립적 검토 후):** 단 하나의 엔진 — 바로 `AiBibleEvidence` 다음과 같이 설정되었습니다. `Derive(...)` 그리고 이 스트립은 다음을 통해 정식 배지를 재사용합니다. `entry.EvidenceBadges`, 따라서 Monster AI의 인라인 스트립과 BIBLE의 전체 창은 **결코 일치하지 않는다**; `IDA` 별도의 구조적 배지는 그대로 유지되며 **절대** 뒤집히지 않습니다 `proved` 녹색 (리뷰 과정에서 버그를 발견하여 수정함). 토큰 추가됨 `partial` 임무에서 요청한 것. “게임에서 어디에 나오는지”는 `AiBibleWhereAppears` (BIBLE과 모듈 간의 단일 DRY 소스). 의 BIBLE 인라인 패널에 적용됨 `Monster AI Editor`: 선택한 항목에 대해 배지 + 출처 + “표시 위치” 확장 기능; (기존에 있던) **📖 전체 가이드 열기** 버튼을 누르면 해당 항목에 초점을 맞춘 BIBLE이 열립니다. 런타임, SIN, 저장 경로 또는 provide를 건드리지 않습니다.

r `SpiraDataAtlasCatalog`. 빌드 오류 0개 / 경고 361개; `--spiraatlas-rt0` 그리고 `--aicmdmeta-rt0` PASS; `AiScriptLab --ai2` PASS (검증 결과 346/346). [이전: `v2.59.0`] — Jarvis-MAGIC
- **📚 `v2.59.0` — BIBLE OF SPIRA / Atlas UI 2.0: 멀티 배지 증거 탐색 + 필터 + 출처 패널(읽기 전용).** 창 `BIBLE OF SPIRA` 새로운 필진 없이도 증거 기반 건강 정보 탐색 기능을 충실히 갖추게 되었습니다. `AiBibleEntry` 이제 Atlas의 구조화된 출처 정보를 불러옵니다 (`SourcePath`, `WriterPolicy`, `DetailKind`) 및 유일한 증거 토큰 공급원 (`AiBibleEvidence`) 오직 기존 항목들에서만 파생된 것으로, 결코 새로운 증거를 만들어내지 않습니다. 각 항목에는 **다중 배지**가 표시됩니다 (`blocked`, `RT2`, `IDA`, `proved`, `RT0`, `parser-corpus`, `presence-index`, `metadata-only`, `semantic-candidate`, `RT2-pending`, `read-only`) 중증도에 따라 색상이 구분되며, 정확성을 유지하는 툴팁 (`RT0` = Atlas의 파싱/카탈로그 무결성, 런타임 권한이 아님; `parser-corpus` (구조/존재 여부 검증, 효과 검증 아님). 새로운 **증거** 필터 (`Todas`, `Proved/RT0`, `Parser corpus`, `Metadata-only`, `Blocked`, `RT2 pending`)는 ‘유형/영역’ 및 ‘검색(집계 포함)’과 연동됩니다. 아틀라스에서 파생된 항목에는 **아틀라스: 기원 및 정책** 패널이 표시되며, 여기에는 `Domain`, `DetailKind`, `WriterPolicy` 그리고 `SourcePath` (원본 CSV 파일을 추출하지 않고). **"게임 내 등장 위치"**는 도메인별로 적절한 표현으로 재작성되었습니다 (`monster-presence` = 교육 이수 여부/참가 시간대, 행동이 아님; `sin-eligibility` = 대기열, 승인 없음; `gear-name-model` = 줄 `w_name.bin`, 보상의 최종 명칭이 아님; `blitzball-prize` = 메타데이터 전용; Sphere `Unknown6` = 미가공/알 수 없음). 검색 기능이 이제 다음을 허용하게 되었습니다 `metadata-only`/`blocked`/`RT2-pending`/`domain:*` 토큰을 통해 `SearchBlob`. 임시 빌드: 오류 0개 / 경고 361개; `--spiraatlas-rt0` 그리고 `--aicmdmeta-rt0` PASS (`979/867/112`). 런타임, SIN 라이터 또는 공급자를 건드리지 않고 `SpiraDataAtlasCatalog`: 읽기 전용/UX입니다. [이전: `v2.58.0`] — Jarvis-MAGIC
- **🛰 `v2.58.0` — 편집기의 Aurora Overlay Lab: 다음을 위한 영구 설정 `ffx-hooks.dll`.** 새로운 모듈 `Live Tools -> Aurora Overlay Lab` 런타임 오버레이를 제어하기 위해

그리고 `modules\config\aurora_overlay.ini`, 기존 플래그를 동기화하여 (`aurora_overlay.flag`, `aurora_overlay_d3d11.flag`, `aurora_w2s_sniff.flag`) 및 GDI/D3D11 모드, W2S 스캔, D3D 스니프, 예산/쿨다운, 리프레시 등의 노브를 표시하고 `Auto-pause hits`. DLL은 `.ini` 부팅 시 환경 변수를 오버라이드 상태로 유지하며; `d3d_sniff_autopause_hits=3` D3D 폴백 매트릭스가 아직 유효한 동안 콘스탄트 버퍼에 대한 심층 검사를 일시 중지합니다. 패널은 게임 루트를 정규화합니다/`FFX.exe`/`modules`, DLL/config/log를 표시하고, 열기 `%TEMP%\ffx-hooks.log`, Steam을 통해 출시 appid `359870`, ~일 때 알려줍니다. `FFX.exe` vivo는 다른 루트에 위치하며, 설정을 기록할 때 I/O 오류를 방지합니다. 이전 런타임 테스트: FFX vivo에서 D3D11 인프레임 라벨; 이번 테스트에서 에디터 빌드가 검증되었습니다. `0 Erro(s)` / `361 Aviso(s)` 그리고 DLL 배포. [이전: `v2.57.0`] — Jarvis-Codex
- **⚔ `v2.57.0` — 커스텀 보스 크리에이터: 드롭1/훔치기/뇌물을 위한 ‘고급 전리품’ 라이트.** 스탯 패널에 **‘고급 전리품’** 카드가 추가되었으며, 다음 항목에 대한 선택적 오버라이드 기능이 포함되어 있습니다. `Drop1` 흔함/드물음, `Steal` 흔한/드문 그리고 `Bribe`: 항목 ID, 수량 및 해당되는 경우 원시 확률. 비어 있거나 유효하지 않은 필드는 `Loot usado`; **Preview / Diff**는 다음을 통해 이름을 해결합니다. `Item_Dictionary` 그리고 다음과 같은 변화를 보여줍니다. `Potion x1 → Dark Matter x2`, 또한 상속받은 유효하지 않은 필드를 나열합니다. 클로너는 이제 다음을 적용합니다 `LootFile` 복사/상속된 전체 값, 게다가, `Gil/AP` + 드롭1/훔치기/뇌물(경미); `.bossrecipe.json` 이 오버라이드 항목들은 입력 완료 시 저장됩니다. 솔직히 말해서: `Drop2`, 오버킬 드롭과 장비/능력 풀은 몬스터 에디터/다음 버전에서 계속 유지됩니다. 빌드 에디터 오류 0개 / 경고 361개. [이전: `v2.56.0`] — Jarvis-Codex
- **🧠 `v2.56.0` — Monster AI Editor: 필드/스탯 설정 + 삼위일체/BIBLE의 최종 다듬기.** **TRINDADE DO MONSTER AI** 헤더를 중앙 정렬하여 워크플로우의 실제 호출로 만들었습니다. `AEON observa · BIBLE ensina · SIN cria`. Workbench는 미세 조정 영역에 **Plantar field/stat** 카드를 추가했습니다: 다음을 검색합니다 `btlActorProperty` ~의 `AiChrPropertyNames`, 소수점을 선택하거나 `0xNN`, 그리고 다음 위치에 저장합니다. `onTurn` 올바른 형식을 사용하여 백업된 실제 데이터 `PUSHII <field> · PUSHII <value> · CALLPOPA 70AB` (`setStatField(field,value)`, `actorRef` 없이

`, sem confundir com `writeChrProperty`). O default prioriza `OverdriveMax`, `오버드라이브 전류`, `showOverdriveBar` e reações de hit, exatamente para casos tipo Dark Shiva/overdrive. A BIBLE inline recebeu cores de seleção/detalhe mais coesas com Spira/FFX e deixou de parecer um bloco de terminal colado. Build editor 0 erros / 361 warnings. [anterior: `v2.55.4`] — Jarvis-Codex
- **⚔ `v2.55.4` — 커스텀 보스 생성기: `Loot usado` 명시적인 선택 사항이 됩니다.** 왼쪽 열에는 **사용된 전리품** 카드가 모드와 함께 추가되었습니다. `Herdar loot da base` 또는 `Copiar loot de outro m###`, 자체 필터, 소스 목록 및 Gil/AP, 드롭/스틸/뇌물, 원시 확률을 포함한 기술 요약. 전리품 소스를 변경하면, 필드 `Gil`, `AP` 그리고 `AP Overkill` 선택한 블록에 따라 달라지며, 수동으로 덮어쓸 수도 있습니다. `Criar Monstro` 이제 다음을 복사할 수 있습니다. `LootFile` 왕복 처리된 정수를 보존하고 그 위에 간단한 보상을 다시 적용하고; `.bossrecipe.json` 기록하다 `LootSource` (`inherit-base-loot`/`copy-monster-loot`) 그리고 이 선택 사항을 가져오고 내보내는 과정을 거칩니다. **미리보기/차이점**에서 최종 IA와 최종 전리품을 표시하고, 보상과 실제 전리품을 비교해 줍니다. 빌드 에디터 오류 0개 / 경고 361개. [이전: `v2.55.3`] — Jarvis-Codex
- **⚔ `v2.55.3` — 커스텀 보스 크리에이터: 더 이상 어둠 속에서 스탯을 입력할 필요가 없는 보스 프리셋.** 이 탭에는 스탯 상단에 **보스 프리셋** 블록이 추가되었으며, 여기에는 다섯 가지 기능이 있습니다: `Dark Lite`, `Tanque`, `Canhão`, `Veloz` 그리고 `Herdar tudo`. 프리셋은 `m###` 기준값을 설정하고, HP/MP/오버킬/스탯/모델 ID 및 길/AP/AP 오버킬을 클램프가 적용된 배율로 채우며, 연쇄적인 곱셈을 방지하기 위해 항상 기준값부터 시작합니다; `Herdar tudo` 레시피를 가볍게 만들기 위해 수치 오버라이드를 지웁니다. 프리셋을 클릭해도 아무것도 저장되지 않으며, **Preview / Diff** 카드에는 적용 전에 결과가 표시됩니다. `Criar Monstro`. 빌드 편집기: 오류 0개 / 경고 361개. [이전: `v2.55.2`] — Jarvis-Codex
- **⚔ `v2.55.2` — 커스텀 보스 생성기: 보스 생성 전 미리보기/차이점 확인.** 이 탭의 스탯 패널에 **미리보기/차이점** 카드가 추가되었으며, 베이스, 대상, 이름, AI 소스, 스탯 또는 보상을 변경할 때마다 업데이트됩니다. 미리보기 기능은 최종 결과를 `m###` 기반 및 표시 `base → novo` 이사 전용

HP/MP/오버킬/스탯/모델 ID/길/AP/AP 오버킬의 실제 값; 입력된 필드가 유효하지 않은 경우, 쓰기 작업 전에 ‘상속됨’으로 표시됩니다. 또한 대상도 요약합니다. `m### → m###`, 최종 AI(다른 몬스터의 전체 프로필을 상속하거나 복사) 기능을 제공하며, 대상 ID가 이미 존재할 경우 경고합니다. 새로운 라이터 기능 없음: 무작정 생성하는 것을 줄이기 위한 정직한 읽기/미리보기 기능입니다. 빌드 에디터 오류 0개 / 경고 361개. [이전: `v2.55.1`] — Jarvis-Codex
- **🧠 `v2.55.1` — Monster AI Editor: AEON/BIBLE/SIN 트리니티 + 상단에 빠른 SIN.** 화면에서는 이제 삼위일체를 모듈과 시각적으로 구분합니다: **AEON**은 간결한 기본형 diff/restore 영역으로 바뀌었고, **BIBLE OF SPIRA**는 요약문 옆에 읽기 전용 ATEL 매뉴얼로 남아 있습니다. `O que este monstro faz`, 그리고 **SIN / Spira Instinct Network**가 1클릭 빠른 프리셋 패널로 추가되었습니다. Workbench는 하단의 미세 조정 기능(현재 AI 목록 + 행동 추가/변경)으로 변경되었으며, 스킬 선택기에는 카테고리가 추가되었습니다. `Todas` Character/monmagic1/monmagic2를 통합하면서, 액션 버튼에 대비 효과와 아이콘이 추가되었고, DevKit은 맨 끝에 검은색의 단일 기술 확장 패널로 바뀌었습니다. 이제 상태 프리셋에는 Shell, Regen 및 NulBlaze/NulTide/NulShock/NulFrost가 포함됩니다. `writeChrProperty` 그리고 ~의 필드 `AiChrPropertyNames`; 새로운 병렬 라이터 없음. 빌드 편집기 오류 0개 / 경고 361개. [이전: `v2.55.0`] — Jarvis-Codex
- **⚔ `v2.55.0` — 커스텀 보스 생성기: UI에서 보스 레시피 가져오기/내보내기/왕복 기능.** 왼쪽 열에 **레시피** 카드가 추가되었으며, 여기에는 버튼들이 있습니다. `Importar` 그리고 `Exportar` ~을 위해 `.bossrecipe.json`. ‘내보내기’를 클릭하면 현재 초안의 레시피를 저장하며, 새 레시피는 생성하지 않습니다. `m###.bin`; 스키마 가져오기 및 유효성 검사 `ffx.bossrecipe.v1`/버전 1 및 기본 몬스터, 대상 ID, 이름, 모드/AI 출처, 능력치 및 기본 보상을 다시 적용 (`RewardGil`, `RewardAp`, `RewardApOverkill`) 화면의 입력란에 입력합니다. 대상(target)이 이미 존재하는 경우, 가져오기 기능은 상태 메시지를 통해 이를 알리고, 사용자가 다음을 클릭하기 전에 ID를 변경할 수 있도록 합니다. `Criar Monstro`. 솔직히 말해서: 레시피는 메타데이터/오프라인 에디터입니다. 보스 생성 기능은 여전히 생성 버튼을 통해 이루어지며, 배치/RT2는 여전히 포메이션 에디터/배틀 샌드박스/게임 내 기능을 통해 진행됩니다. 빌드 에디터 오류 0개 / 경고 361개. [이전: `v2.54.0`] — Jarvis-Codex
- **⚔ `v2.54.0` — Battle Sandbox v2: 최대 8명의 적,

 지역별 경로 및 스프레드/카메라 플래너.** **Battle Sandbox** 탭에서 `LiveBattleLab` 더 이상 수직형 A/B/C 레이아웃이 아닌, 8개의 적 슬롯과 각 슬롯별 HP, 빠른 AI를 갖춘 콤팩트한 레이아웃으로 바뀌었습니다. 이제 경로는 미리 정해진 목록 중에서 선택할 수 있으며, `btl.bin` (`map/battleId/field/group/formation`) 또는 수동으로 편집할 수 있으며, **경로 준비** 버튼을 누르면 8개의 편대 슬롯과 위치가 저장됩니다. `MonsterLive` ~의 `btl_*` 해결됨, 백업 완료 `.sandbox.btl.bak`, 재사용하여 `BattleArenaAuthor`, `Battle_File.WriteWithFormationSlots()` 그리고 `BattleArenaPositionWriter`. 이 플래너에는 스프레드가 포함되어 있습니다 (`2 linhas compactas`, 오픈, 보스+추가 몬스터, 복도, 원)을 분석하여 모든 몬스터가 화면에 담길 수 있도록 카메라 설정을 추천하며, 카메라 자동 기록 기능은 Aurora/RT2에서 기존 방식대로 유지됩니다. `Force Battle` 여전히 DINPUT8 프로브가 연결되어 있어야 한다고 표시됩니다. 솔루션 빌드 결과: 오류 0개 / 경고 361개; 로컬 스크린샷은 `work/screenshots/battle-sandbox-tab.png`. [이전: `v2.53.0`] — Jarvis-MAGIC
- **⚔ `v2.53.0` — 커스텀 보스 크리에이터: 생성 과정에서 AP/길로 지급되는 간단한 보상.** 해당 탭에 이제 **간단한 보상** 블록이 추가되어 편집할 수 있습니다.** `Gil`, `AP` 그리고 `AP Overkill` ~의 `LootFile` 복제됨; 비어 있거나 유효하지 않은 필드는 기본 몬스터의 값을 상속받습니다. 복제기는 원래의 전리품 섹션을 그대로 유지하며, 해당 필드가 채워졌을 때만 다시 스탬프를 찍어, 몬스터 에디터에 드롭/스틸/장비를 그대로 유지합니다. 레시피 `.bossrecipe.json` 기록하다 `RewardGil`, `RewardAp` 그리고 `RewardApOverkill` 사용 시와 `ProofStatus` 이제 이러한 오버라이드를 참조하게 되었습니다. 빌드 편집기 결과, 이 작업 트리에서 오류 0개 / 경고 361개가 발생했습니다. [이전: `v2.52.0`] — Jarvis-Codex
- **⚔ `v2.52.0` — 커스텀 보스 크리에이터: 첫 번째 사이드카 `.bossrecipe.json` 생성된 클론에 대해.** 사용자 정의 보스를 생성할 때, 모듈은 이제 다음을 기록합니다. `m###.bossrecipe.json` 의 같은 디렉토리에 `m###.bin`, UTC 날짜, 소스 몬스터, 대상 몬스터, 이름, AI 출처가 포함된 스키마 v1 (`inherit-base-ai` 또는 `copy-monster-ai`), stats/ModelId/이름의 오버라이드 및 테스트의 정확한 상태. 사이드카는 판도를 바꾸지는 않지만, 생성 과정을 재현 가능하게 만들고 미래의 첫 번째 토대를 마련합니다. `Boss Recipe` 내보내기/가져오기 가능. 빌드 편집기 오류 0개 / 경고 357개 기준. [이전: `v2.

51.0`] — Jarvis-Codex
- **⚔ `v2.51.0` — 커스텀 보스 생성기: `IA usada` AI Source picker를 통해 명시적인 선택이 가능해집니다.** 탭 `Custom Boss Creator` 더 이상 AI를 암묵적인 유산으로 숨기지 않게 되었습니다. 이제 모드가 지정된 **사용된 AI** 카드가 있습니다. `Herdar IA da base` 또는 `Copiar IA de outro m###`, 자체 필터, 출처 목록 및 기술 요약 (`AiFile`, 워커, 명령어, 구조적 검증). 보스를 생성할 때, 클론은 `AiFile` 다른 몬스터의 전체 프로필로, 쓰기 작업 전에 ATEL 코덱/검증기를 통해 검증됨; 스탯, 이름 및 ModelId는 기존 흐름에 그대로 유지됨. 이전에는 아무 동작도 하지 않는 필드로 존재했던 기본 몬스터 필터가 이제 실제로 필터링 기능을 수행합니다. 참고: AI 프로필 전체를 복사하며, 워커/구간, 전리품/보상 및 스테이지의 통합은 향후 업데이트에서 다룰 예정입니다. 빌드 에디터 오류 0개 / 경고 357개 (기준치). [이전: `v2.50.1`] — Jarvis-Codex
- **🧠 `v2.50.1` — Monster AI Editor: BIBLE OF SPIRA + SIN 워크벤치가 메인 스트림에 포함되었습니다.** 화면은 `Monster AI Editor` 두 가지 별개의 개념을 중심으로 재구성되었습니다: **BIBLE OF SPIRA**는 읽기 전용 참조 자료로, 이와 함께 `O que este monstro faz`, 그리고 **SIN / Spira Instinct Network**를 2열 구성의 저자 패널로 활용합니다. 목록 `IA atual do monstro` 더 높아졌으며, 별도의 스크롤 기능이 추가되었습니다. 오른쪽 패널에는 선택한 스킬, 초기 버프, 빠른 프리셋 등이 집중되어 있으며 `SIN Templates` 소형차. `Live Battle Target` 방금 편집된 부분 근처로 올라갔고, Workers/오퍼랜드/어셈블러/구조 모델이 블록으로 밀려 들어갔다 `DevKit`. 빠른 프리셋은 이제 기존 기본 요소를 재사용하여 10가지 실제 작업을 제공합니다 (`Haste`, `Protect`, `Reflect`, `Defensivo`, `Agressivo`, `Enrage`, `Revezar 1/2`, `Revezar 1/3`, `Repetir cast`, `Combo 2 hits`), 별도의 라이터 인스턴스를 생성하지 않고. 빌드 에디터: 오류 0개 / 경고 357개 (기준치). [이전: `v2.50.0`] — Jarvis-Codex
- **🎚 `v2.50.0` — Difficulty Director v2: 오프라인에서 ‘Encounter Danger’ 및 ‘Challenge’ 모드 이용 가능.** 이 모듈은 `Modules/DifficultyDirector` 더 이상 단순히 ~의 경유지가 아니게 되었다 `m###.bin`: 이제 다음을 읽거나 미리 보거나 작성할 수도 있습니다. `Danger` ~의 그룹들 중 `btl.bin` 출처: `EncounterTable_File.Write()` 백업 포함 `.difficulty.bak`, 몬스터와 함께 적용하려면 토글하고 5개 그룹의 미리보기를 확인하세요

영향을 받습니다. 확장된 프리셋: `Exploração` (위험 0) 및 `Caçador` (최고 난이도). 오프라인 챌린지 모드: `True Nightmare`, `Speed Run Assist`, `Explorer`, `Hunter` 그리고 `Equalizer` (로드된 데이터 세트의 평균을 기준으로 HP/MP/스탯을 정규화합니다). 정직성: `One-Hit`, `No-Overdrives`, adaptive/live scaling 및 probe는 IDA/runtime까지 이 범위에서 제외됩니다. 즉, writer는 오프라인 상태입니다. 빌드를 시도했으나, 기존 XAML 오류로 인해 차단되었습니다. `MonsterAiEditor_Control.axaml` (다른 레인의 클릭 핸들러), 이 모듈이 아닌. [이전: `v2.49.0`] — Jarvis-Codex
- **⚔ `v2.49.0` — Live Battle Lab의 Battle Sandbox: A/B/C 패키지 구성, HP/IA 신속 적용, 프로브를 통한 Force Battle 발동. **새로운 탭 **Battle Sandbox** 내의 `LiveBattleLab`: 몬스터 피커 `m###`, 슬롯별로 편집 가능한 HP, AI 빠른 프리셋 (`Original`, `Agressivo`, `Defensivo`, `Enrage`) 및 백업 패키지를 적용하는 버튼 `.sandbox.bak`. **Force Battle** 버튼은 입력값을 재사용합니다 `field/group/formation` 그리고 기존 DINPUT8/메인 스레드 브리지 경로; 화면에는 이 구성의 실제 구성 요소가 여전히 `btl_*` workspace/Formation Editor를 제외하고. 빌드 에디터 오류 0개. [이전: `v2.48.0`] — Jarvis-MAGIC
- **🎚 `v2.48.0` — 난이도 디렉터: 프로젝트 내 모든 몬스터의 HP/MP/스탯을 조정하는 전역 슬라이더.** 새로운 모듈 `Modules/DifficultyDirector` Core Authoring 내, 프리셋을 사용하여 `Fácil/Normal/Difícil/Dark Aeon`, HP, MP, 힘, 마력, 방어력/마법 방어력 및 기타 능력치를 조정하는 전체 슬라이더, 탑 임팩트 미리보기 및 오프라인 라이터 기능을 통해 `Monster_File.Write()`. 각 `m###.bin` 백업을 수신합니다 `.difficulty.bak` 첫 번째 쓰기 작업 이전에 생성된 백업이며, UI에서 해당 백업을 복원할 수 있습니다. 게임은 다음 몬스터 로딩 시 변경 사항을 감지합니다. 라이브 스케일링은 여전히 적용 대상에서 제외됩니다. 빌드 에디터 오류 0건. [이전: `v2.47.1`] — Jarvis-MAGIC
- **📚 `v2.47.1` — Monster AI Editor: 기존 프리셋/자동화 기능을 한눈에 볼 수 있는 AI 행동 라이브러리. **새로운 **행동 라이브러리** 카드가 `Monster AI Editor` 검색 기능 및 시각적 템플릿 (`Counter-Attack`, `Cura quando HP baixo`, `Revezar habilidades`, `Enrage HP baixo`, `Buff defensivo`, `Multi-cast`). 이 구현은 이미 제공된 자동화 기능과 스니펫을 활용합니다.

난자 (`AiAutomation`, `AiSnippetLibrary`, 방어용 프리셋, 템플릿으로 선택된 액션 ⚔), 별도의 라이터를 만들지 않고. HP% 조건문은 검증된 오프라인 구조로 정확히 표시되어 있으며, RT2의 인게임 동작은 프로브를 통해 확인 중입니다. 빌드 에디터 오류 0개. [이전: `v2.47.0`] — Jarvis-MAGIC
- **📖 `v2.47.0` — Monster AI Editor: BIBLE OF SPIRA, 모듈 내의 ATEL 컨텍스트 기반 읽기 전용 성경.** 신규 `FfxLib/Ai/AiBibleCatalog.cs` 함수 및 필드 항목 구조 `btlActorProperty`, 타깃, 오프코드, 패턴 및 가드레일을 실제 사전(`AiChrPropertyNames`, `AiTargetNames`, `AiScript_File.CallName/Mnemonic`). O `Monster AI Editor` **BIBLE OF SPIRA** 카드를 획득했습니다. 검색어: `70AB`/`Overdrive`/`PUSHII`/`Shiva` 및 서명 세부 정보, 스택 형태, 증거 및 위험. 이제 AI Assembler에서 한 줄을 선택하면 해당 항목이 자동으로 불러옵니다(예: `CALLPOPA 70AB` → `setStatField`). ‘mission doc’의 제목이 ‘BIBLE OF SPIRA’로 변경되었으며, 다음 인물이 서명했습니다. `setStatField/getStatField` 표준화된: `setStatField(field,value)` 받지 못합니다 `actorRef`; 명시적 액터는 `writeChrProperty(actor,field,value)`. **새로운 라이터도, 시바 버튼도, 새로운 바이트도 없음** — 오직 컨텍스트/가드레일만. 빌드 에디터 오류 0개; `AiScriptLab --names` PASS. [이전: `v2.46.1`] — Jarvis-MAGIC
- **🧠 `v2.46.1` — AI 어셈블러: “가독성” 열 — 어셈블러의 각 행은 다음과 같이 표시됩니다 `MNEMÔNICO  gloss` 단순히 투명한 글로스만 바르는 것보다는.** `AiAsmRow.ReadableText` 어울린다 `AiScript_File.Mnemonic(opcode)` + `OperandGloss(opcode, operand)` 읽기 쉬운 단일 문자열로: `PUSHII  0xFF03  (alvo: Self)`, `CALLPOPA  Battle.performCommand`, `JMP  → jump[3]`, `ADD` (피연산자 없음). 의 열 `ListBox` AI Assembler의 경우 (이전에는 글로스만 표시되었음, 예: `0xFF03  (alvo: Self)`) 이제 전체 텍스트를 표시합니다; 오프코드 툴팁 (`OpcodeHelp`)는 마우스를 올렸을 때 그대로 유지됩니다. `OnPropertyChanged(nameof(ReadableText))` opcode 및 operand 세터에서 호출되므로, 편집 시 열이 실시간으로 업데이트됩니다. RT0에는 영향을 미치지 않습니다(뷰만 해당). 파일 없음 `AiOpcodeNames.cs` 생성됨 — `Mnemonic()` 이미 존재했고 공개된 내용입니다. [이전: `v2.46.0`] — Jarvis-MAGIC
- **🔍 `v2.46.0` — 

AEON (Assembly Evolution Observation Node): 수정된 AI와 기본 AI를 녹색/빨간색/노란색 하이라이트로 비교.** 신규 `FfxLib/Ai/AiScript_Diff.cs` 두 가지를 비교한다 `AiScriptFile` 작성자: `(worker, offset)` 그리고 분류한다 `Unchanged/Modified/Added/Removed`. O `Monster AI Editor` **Diff vs Vanilla** 오픈 카드를 획득했습니다: 다음 경로를 통해 추출된 참조를 불러옵니다 `Path_FfxPs2Root`, 녹색=추가, 빨간색=삭제, 노란색=수정된 부분을 표시하며, 크기 변화가 있을 때 알림을 제공하고 오프셋을 기준으로 한 차이점 비교 결과가 대략적으로 표시되며, 두 번의 클릭으로 확인 후 기본 버전으로 복원하는 기능을 제공합니다 + `.prev.bak`. 바닐라가 없으면 크래시 없이 솔직한 메시지가 표시됩니다. 새로운 게이트 `AiScriptLab --diff` PASS: `m000` 동일 = 델타 0; `m001` 메모리에서 변경된 연산자 = 1개 수정, 0개 추가/삭제. 빌드 편집기 오류 0개. [이전: `v2.45.0`] — Jarvis-MAGIC
- **🎵 `v2.45.0` — 편집기 내의 완전한 음악 플레이어: 카탈로그에 포함된 89개의 트랙을 UI에서 선택할 수 있습니다.** `AudioStudio_Service` 이제 즉시 미리보기를 표시합니다 (`SetTrack`/`PreviewSelectedMusicTrack`) 보존하며 `SelectedTrackId` 환경 설정에서; 메인 창에 버튼이 추가되었습니다 `▶ Preview`, 넓은 콤보 박스와 현재 재생 중인 트랙, 상태, 음악/FX 전환 버튼, 카탈로그 카운터가 포함된 **음악 플레이어** 카드. 사용 `Assets/Audio/Music/music_catalog.json` + `Catalog/*.wav` (89개 트랙)이며 여전히 EDITOR 전용 플레이어로만 작동합니다 — 게임 내 음악 교체 기능은 지원되지 않으며, 이는 여전히 hook/IDA에 의존합니다. 빌드 에디터 오류 0개. [이전: `v2.44.0`] — Jarvis-MAGIC
- **⚔ `v2.44.0` — 커스텀 보스 크리에이터: 모든 몬스터 복제 + 편집 → 새로운 m###.bin (커스텀 몬스터 제작 파이프라인의 첫 단계).** 새로운 모듈 `Modules/CustomBossCreator` + `FfxLib/Monster/MonsterCloner.cs`. 흐름: 기본 몬스터를 선택하고(m000–m346 또는 존재하는 m### 중 하나), 새 ID를 설정하며(첫 번째 빈 슬롯으로 347+가 자동으로 제안됨), 능력치(HP/MP/HpOverkill/힘/방어력/마법력/마법 방어력/민첩성/운/회피/명중) 및 ModelId를 개별적으로 편집하고(빈 필드 = 베이스에서 상속), 표시 이름을 입력한 후 **⚔ 몬스터 생성**을 클릭합니다. 이 `MonsterCloner.Clone()` 독립적인 복사를 위해 Write→Read 왕복 처리를 수행하고, 슬롯 전용 오버레이(통계) 또는 전체 재구축(이름)을 `Monster_StatSheet`, es

~에 믿음을 두다 `battle/mon/_m###/m###.bin` (폴더를 자동으로 생성)하고 이름을 `Monster_Dictionary` 실행 시 — 포메이션 에디터는 이미 새로운 몬스터를 올바른 이름으로 인식합니다. AI, 전리품 및 게임 내 이름은 기본값에서 상속되며(나중에 몬스터 AI 에디터/몬스터 에디터에서 수정 가능), 정확성: 클론이 파일을 생성하며, 몬스터를 전투에 배치하는 과정은 포메이션 에디터를 통해 계속 진행됩니다(기존 .btl 파일의 슬롯 교체). 오프라인 게이트: Monster_File 작성자 검증 완료(왕복 시 바이트 단위 동일). [이전: `v2.43.1`] — Jarvis-MAGIC
- **🪝 `v2.43.1` — ffx-hooks.dll 0단계: C++ 엔진 후크 레이어 골격 (PolyHook2, x86) — DLL이 게임 내에서 충돌 없이 로드되며, 공유 메모리가 준비되었고, 주석이 달린 후크들이 IDA 분석을 기다리고 있습니다.** 새로운 C++ DLL `RuntimeTools/FfxHooksDll/` ~와 공존한다 `ffx-probe.dll` 기존 기능 (이를 대체하지 않음): 모듈 로더 (`dinput8.dll`)는 둘 다 `modules\` 자동으로. 0단계: `dllmain.cpp` 스켈레톤 — 로딩 시 2초 동안 대기(스레드 + Sleep, 절대로 DllMain에 직접 후크하지 말 것), 다음의 베이스 클래스를 가져와 `FFX.exe`, 공유 메모리 블록을 생성합니다 `Local\FFXHooksBlock_v1` (256바이트: 매직/버전, `musicOverrideTrackIndex`, `musicSeq`, `elementFlagsExt`), 그리고 다음 위치에 저장합니다. `%TEMP%\ffx-hooks.log`. **이 단계에서는 실제 후크가 설치되지 않음** — 게이트: 게임이 정상적으로 실행되며 + 다음 내용이 로그에 표시됨 `[ffx-hooks] Fase 0 skeleton loaded`. 주석이 달린 스텁: `hooks/MusicHook.cpp` (thiscall `FFX_FmodMusic_PlayTrackByIndex`, 1단계 — 대기 중 `RVA_FMOD_PLAY_TRACK` (IDA를 통해), `hooks/ElementHook.cpp` (Earth/Wind/Dark 요소의 인라인 훅 플래그 비트 0x20/0x40/0x80, 2단계). VS2022 프로젝트 `FfxHooksDll.vcxproj` (Win32 전용 — 게임은 x86 기반이며, vcpkg 매니페스트 모드는 `polyhook2:x86-windows` + `zydis:x86-windows`). 스크립트 `build_hooks.ps1` ~와 함께 `-Deploy` (복사하여 `modules\`): 기본 모드 `cl.exe` PolyHook2 없음 (0단계) 또는 `-WithPolyHook` MSBuild+vcpkg를 통해 (1단계 이상). `shared/ffx_addresses.h` 모든 RVA를 주석이 달린 PLACEHOLDERS로 중앙 집중화합니다(RVA별 IDA 작업). [이전: `v2.43.0`] — Jarvis-MAGIC
- **⚡ `v2.43.0` — EncounterTable: 저장 버튼 + 그룹별 편집 가능한 Danger + 전역 Danger (기능 1+4).** O `EncounterTableExplorer` 단순한 뷰어에서 만남 편집기로 발전했습니다. `Encount

erTableGroupRow` e `EncounterTableFormationRow` agora são `ObservableObject` parciais: `위험` (por grupo, 0–255) e `무게` (por formação, 0–255) são editáveis via slider interativo; editar o `위험` reflete em `group.Danger` imediatamente (e atualiza o label `발생 없음/드물음/보통/높음/최대`); editar `무게` recalcula automaticamente `group.총중량`. Presets por grupo: botões `미팅 없음 (0) / 보통 (50) / 강함 (128) / 최대로 (255)`. **Salvar:** botão `💾 btl.bin 저장` chama `EncounterTable_File.Write()` (slot-only, byte-local), cria `btl.bin.bak` na 1ª vez; `↩ 바닐라 버전으로 복원` copia o `.bak` de volta. **Danger Global:** 4 botões de preset (`⚡ 미팅 없음 / 보통 / 강함 / 최강`) no card "Editar e Salvar" aplicam o valor a TODOS os grupos de TODOS os mapas de uma vez, com feedback de quantos grupos foram afetados. O `데이터 모델` mantém `_loadedEncounterFile` e `_encounterFilePath` para reutilizar o mesmo objeto lido sem re-parse. Build editor 0 erros. [anterior: `v2.42.0`] — Jarvis-MAGIC
- **🎥 `v2.42.0` — AURORA: IDA에서 카메라 시야를 100% 보정 완료 + MapViewer에서 황금색 눈 드래그 완료.** 브리핑 완료 `HANDOFF_CAMERA_POLAR_CALIBRATION_CODEX_2026-06-07`: 핸들러 `camSetPolar(0x6004)` IDA를 통해 확정되었습니다 (`0x6004 -> 0x7B9260 -> 0x7BB550 -> 0x7C4760`, 카메라 슬롯 `+12`)와 같이 `horizontalDeg, elevationDeg, distance`, 공식 `x=refX+cos(h)*cos(e)*dist`, `y=refY+sin(e)*dist`, `z=refZ+sin(h)*cos(e)*dist`. 오로라의 금색 마커가 더 이상 “대략”이 아닙니다: `BuildCameraMarker` 실수 공식을 사용하며, Place 모드에서 이제 **황금 눈**을 드래그할 수 있습니다. 편집기가 역계산을 수행합니다. `horizontal/elevation/distância` 그리고 다음을 통해 3개의 float 값을 기록합니다. `WithFloat` (바이트 로컬, 백업 1회), 공유 풀에 대한 경고를 유지합니다. Gate `BattleCameraScanLab`: `camSetPolar0x6004=10944`, 별도의 타겟 인식 변형 `103854`, 극좌표 exato를 설정하며 `809/855`, 눈으로 편집 가능 `802/855`, **polar eye round-trip 802/802**. `camSetBtlPolar*`/`camSetChrPolar2` 단순 역전과는 확실히 다릅니다. 편집자 오류 0개. [이전: `v2.41.0`] — Jarvis-Codex/AURORA
- **🎥 `v2.41.0` — AURORA: MapViewer에서 직접 카메라를 드래그(ref/look-at)합니다.** “방법은”에 대한 답변 

"MapViewer에서 카메라를 조작할 수 있나요?": **Place 모드**에서, **청록색 구체(ref = look-at)**는 이제 몬스터와 마찬가지로 드래그할 수 있습니다 — 씬의 바닥에서 드래그한 후 놓으면, **💾 **위치 저장**을 통해 새로운 위치가 기록됩니다. `refSetPos(x,y,z)` chunk0 (**바이트 로컬, EXATO**, 백업 1회) — 동일한 세이브 파일 내의 몬스터 드래그와 결합됩니다(다른 지역). Reader는 ref의 float-pool 인덱스를 노출합니다 (`Establishing.RefX/Y/Zindex`); `ApplyCameraRefDragToDisk` ~를 통해 작성 `BattleCameraSetup_File.WithFloat`; `aurora-overlay.js` 시안색 구체를 드래그의 대상으로 태그합니다 (`role=camera_ref`) 다리를 건너기를 거부하며 `/drag`. **황금 눈(각도/거리)은 아직 드래그되지 않습니다** — IDA에서 극좌표계 보정이 완료될 때까지 기다려 주세요(곧 진행 예정); 당분간은 패널의 노브를 통해 편집해 주세요. (추가로: 빌드를 수정했습니다. `BattleCameraScanLab` 새로운 기호들로 인해 깨져버린 `Ai*Names` 다른 레인에서 — 잠금을 해제합니다 `offline_ci`.) 편집기 오류 0개, 게이트 통과 (float 855/855). [이전: `v2.40.1`] — Jarvis-AURORA
- **🪄 `v2.40.1` — AI 어셈블러: “수정 시도” 버튼 (레벨 3, 정직한 자동 수정).** 브로커 창을 닫으면: Validate/Save 옆에 **🪄 수정 시도** 버튼이 나타납니다. **정직한 기준(개발자 본인의 기준):** **단 하나의 정답**이 있을 때만 수정을 적용하며, 그 외에는 추측하지 않고 제안만 합니다. 어셈블러 모델(이 모델은 `HasOperand` (opcode 단독의 경우) 유일하고 확실한 해결책은 **제거 대상으로 표시했지만 점프/엔트리포인트의 대상이 되는 명령어를 복원하는 것**입니다 — 이 명령어는 반드시 남아 있어야 합니다(분기 경로를 다시 지정하면 동작이 변경되어 오류가 발생할 수 있음). 이 버튼은 반복적으로 재검증하여, 이러한 고아 대상들을 복원하고(사례 1 “무언가를 제거했더니 고장 났다”를 해결하며), 유일한 해결책이 없는 오류(무효한 오프코드, OOB 점프 인덱스, 레벨 1 스택 비어 있음)에 대해서는 **보고서에서 어떻게 해야 할지 설명하지만 직접 처리하지는 않음** — “당신의 의도를 추측하지 않겠습니다.” 수정된 개수와 당신의 결정을 기다리는 잔여 개수를 보고합니다. `MonsterAiEditor_DataModel.Assembler.TryAutoFixAssembler` (다음과 같이 사용하세요 `AiValidator` 게이트 테스트 완료; 연산자/오퍼코드 편집이나 삭제 작업은 절대 수행하지 않음). 빌드 편집기 오류 0개; `--ai2`/`--ai3` PASS (RT0 바이트 동일 — VM 제거 플래그만 복원하고, 바이트는 변경하지 않음). **솔직히 말해서:** 의도를 추측하는 자동 수정 기능은 = 은밀한 버그이므로, 버튼은 그대로 유지됩니다.

의도적인 찬양. [이전: `v2.40.0`] — Jarvis-MAGIC
- **🩹 `v2.40.0` — AI 어셈블러: 스택 검사기 (레벨 1+2) — 편집으로 인해 스택이 비워질 때 경고하고, 수정 방법을 알려줍니다.** 소유자가 어셈블리 오류를 수정하는 데 도움을 주는 “미니 AI 검사기”를 요청했습니다. 검증기는 이미 무효한 오프코드 / 고아 점프 / 인덱스 OOB를 감지했지만, **수동 편집 시 발생하는 오류 1번인 스택 불균형은 감지하지 못했습니다**. 이제 감지합니다. **RE-grounded (FFXDataParser):** 신규 `FfxLib/Ai/AiStackModel.cs` = 오프코드별 스택 효과 (출처: `OPCODE_STACKPOPS`) + **269개 함수의 개수** (입력 개수 `ScriptFuncLib`; accessor = subject?+index+value?). O `AiValidator` 스택 깊이를 시뮬레이션하고(entrypoint/jump-target에서 0으로 재설정) 언더플로우를 보고합니다. **솔직한 핵심 지적:** 파서의 인수 개수는 실제 VM과 100% 일치하지 않습니다(입증됨: `setSelfFloating 0x7029` 파서가 2라고 표시하고, 코퍼스가 1을 반환합니다) — 따라서 절대 카운트(유효한 코드에서는 잘못된 결과를 낼 수 있음) 대신, **원본 대 수정본** 스택을 비교합니다: 두 스택 모두에 아르리티 노이즈가 존재하지만 서로 상쇄되므로, 오직 **사용자가 편집한 부분**에서 발생한 오류만 남게 됩니다. 메시지(레벨 2)는 포르투갈어로 어디에서 스택이 비었는지 + **수정 방법**을 알려줍니다("인수였던 PUSH를 다시 넣으세요; 모든 문장은 인수를 푸시한 뒤 호출합니다"). 유효성 검사 패널에서 자동으로 이동합니다. 게이트 `--ai2`: **validator clean 346/346** (코퍼스에서 오탐이 없음) + **stack-break caught 1/1** (arg-push를 제거했을 때 감지됨을 증명함); `--ai3` PASS; RT0 바이트 동일 (분석 전용, 0바이트). 빌드 편집기 오류 0개. **정직하게 말하자면:** 편집으로 인해 추가된 내용을 감지함; 일부 함수의 정밀 아리티 = 공개 RE (코퍼스 기반 보정 = 향후 계획). [이전: `v2.39.2`] — Jarvis-MAGIC
- **🏷️ `v2.39.2` — 프로젝트 Burn-Down 명칭: 원시 라벨 스캐너 + Monster AI의 첫 번째 안전한 별칭.** 리포지토리 전체에 걸친 소각 계획 시작 `campo 0xNN`, `stat 0xNN`, `comando 0xNN`, `raw`, `Unknown`/`Unk` 무분별한 이름 변경 없이 일반 ID를 처리할 수 있는 새로운 도구 `RuntimeTools/NameAuditLab` 재고 목록 `.cs`/`.axaml`/`.md`/`.ps1`, 구분 `EditorUi`, `CoreDisplay`, `CoreInternal`, `LabTool`, `Documentation` 그리고 `Other`, 그리고 그 부분집합만을 표시하고 `review now`; 현재 결과: **2445건의 검사 결과, 497건의 편집/표시, 11건의 검토 대기 중**, 검사실/

docs/offsets는 설계상 원시 16진수 형식을 유지합니다. 첫 번째 안전한 별칭이 적용되었습니다: Monster AI 자동화 부품 목록에는 이제 다음과 같이 표시됩니다. `writeChrProperty StatusDurationHaste (0x0038)` / `setStatField stat_round (0x00DA)` ~할 때 `AiChrPropertyNames` ID를 닫습니다; 알 수 없는 항목은 계속됩니다 `campo 0xNNNN`. 문서: `docs/ai/MISSION_PROJECT_WIDE_NAME_BURN_DOWN_2026-06-07.md`, `docs/reverse/FFX_PROJECT_NAME_BURN_DOWN_SCAN_2026-06-07.md`; AI 바이트 변경 없음. [이전: `v2.39.1`] — Jarvis-Codex
- **🏷️ `v2.39.1` — Monster AI: 공개 파서를 활용한 NAME 감사 (이름 없이 사용된 0개의 호출 ID; 불확실한 필드는 16진수 형식으로 표시됨).** 브리프 실행 `docs/ai/MISSION_NAME_AUDIT_WITH_PARSERS_2026-06-07.md` "이름보다 일관성"이라는 규칙에 따라: `ScriptFuncLib` + `ScriptConstants` + 코퍼스 출처: `AiScriptLab --names`, 바이트를 변경하지 않고. 사전 추가됨 `AiMotionPropertyNames`, `AiMovePropertyNames` 그리고 `AiSaveDataVariableNames`; 이제 함수별로 필드-스페이스를 분해하면 (`btlActorProperty` ~을 위해 `700F/7018/70AA/70AB`, `motionProperty` ~을 위해 `70AC/70B2`, `moveProperty` ~을 위해 `701A/7078`) 및 `saveData` 파서 기반 이름이 있을 경우 이를 표시합니다. 수정됨 `0x701A` ~을 위해 `readMoveProperty` 그리고 16진수 형식으로 표현되는 사용된 콜 ID를 추가했으며 (`7009`, `7029`, `7032`, `7050`, `7078`, `70A8`). 게이트 `--names`: **사용된 호출 ID 160개, 이름이 지정되지 않은 호출 ID 0개; 명명된 공간에 있는 필드 285개; 16진수로 유지된 리터럴 5개** (`0x0156`, `0x0157`, `0xFFFB`, `0xFFEF`, `0xFFDF`) parser/corpus/IDA가 닫히지 않아서. `--ai2`/`--ai3` PASS; 편집기 오류 0개. Doc `docs/reverse/FFX_AI_NAME_AUDIT_WITH_PARSERS_2026-06-07.md`. [이전: `v2.39.0`] — Jarvis-Codex
- **🎥 `v2.39.0` — AURORA: MapViewer의 카메라 3D 마커 (씬 렌더링에서 카메라가 어디에 위치해 있는지/어디를 향하고 있는지 확인 가능).** “내가 보는 방식”의 #2: Aurora의 3D 렌더링이 이제 **설정된 카메라**를 표시합니다 — **금색 구체 = 시선** (카메라 위치), **청록색 구체 = 참조점** (카메라가 정확히 포착하는 지점), **시선→참조점 선** + 바닥의 스템. chunk0에서 계산됨: `refSetPos(x,y,z)` (맞습니다, 장면의 동일한 프레임 = 신원 확인) + `camSetPolar(ângulo,distância)` → `olho = ref + polar`. 리더 `BattleCameraSetup_File.Establishing` (1번째 refPos + 1번째 극성; 게이트: **

ref 855/855, polar 846/855**), 모델 `AuroraCameraMarker` 오버레이에서 다음으로 렌더링 `aurora-overlay.js` (앵커와 같은 그룹이며, Y-up 플립을 상속받음). **정확히 말하자면:** 참조 값은 정확하지만, **시선 방향은 대략적인** 것입니다 — 극좌표 체계(각도 대 거리, 고도)에 대한 약정은 아직 **바이트 단위로 확인되지 않았습니다**, 따라서 마커는 "카메라 (대략)"로 표시되며 고도는 시각적 추측치입니다; 화면(및 프로브/게임 내)을 통해 확인하고 정밀하게 조정하십시오. 에디터 오류 0개. 문서 `docs/reverse/FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07.md`. [이전: `v2.38.1`] — Jarvis-AURORA
- **📊 `v2.38.1` — Monster AI Editor: 명명된 STAT 액션 (“stat 0xNN” 끝) — `setStatField` 동일한 테이블을 사용합니다.** 소유자가 화면에서 📊 스탯이 여전히 원시 데이터로 표시되고 있음을 지적했습니다("stat 0xDA = 8"). **발견 사항 (FFXDataParser ScriptFuncLib 교차 확인):** `setStatField`(0x70AB)/`getStatField`(0x70AA)는 **동일한 indexType**을 사용합니다 `btlActorProperty`** 그 `readChrProperty`(0x700F)/`writeChrProperty`(0x7018) — 즉, 필드 테이블이 똑같다는 뜻이며, 제가 가정한 “구분된 공간”이라는 가정은 틀렸던 것입니다. 왜 원본 그대로 남아 있었는지: ID는 다음과 같은 형식이고 `0xDA/0xDB/0xE6` ~가 있다 `name=null` 파서에서 (단순히 `internalName`: `stat_round`/`stat_round_return`/`stat_attack_inc_speed`), 그리고 1세대 `AiChrPropertyNames` 이름이 친숙한 것들만 가져왔습니다. **수정:** 영어 이름이 없을 때 **게임 내 내부 심볼을 대체값으로** 포함하도록 사전(dictionary)을 재생성했고(222 → **341개 필드**), 이를 탐지기의 stat 브랜치에 병합했습니다. 이제 "stat 0xDA = 8"은 **"stat_round = 8"**으로 표시됩니다. `FfxLib/Ai/AiChrPropertyNames.cs` + `AiAutomation` (Stat 지사 via `StatusFieldName`). 게이트 `--ai3` PASS (4156개 통계값 감지; RT0 바이트 동일 — 표시만 다름); 편집기 오류 0개. **솔직히 말해서:** 영어 이름은 RE-pública이며, `internalName` **게임의 진정한 상징**입니다 (유형 "unknown" = 세부적인 의미는 100% 반영되지 않았지만, 이 상징은 정직하며 16진수보다 낫습니다). [이전: `v2.38.0`] — Jarvis-MAGIC
- **🎥 `v2.38.0` — AURORA: 패널에서 전투 카메라의 실제 매개변수(각도 · 거리 · 위치 · 롤)를 편집할 수 있습니다.** “그걸 어떻게 확인하고 편집하나요?”라는 질문에 대한 답변: 🎥 카메라 카드에 **“🎚 카메라 매개변수 (편집 가능)”**이 추가되었습니다. **RE (IDA를 통해 + `FFXDataParser`, d의 팁

ono):** 전투 카메라는 chunk0에서 스크립트로 계산됩니다 — Camera 네임스페이스를 호출합니다 (`camSetPolar(ângulo,distância)`, `refSetPos(x,y,z)`, `camSetRoll`, `camSetScrDpt`) 풀의 **FLOAT 상수**로 매개변수를 지정합니다. 새로운 리더 `FfxLib/BattleMap/BattleCameraSetup_File.cs` 모든 호출을 추출하고, 부동 소수점을 해결하며, 편집 가능한 **각기 다른 노브**를 처리합니다; `WithFloat` **byte-local** 플로트 풀을 생성합니다(크기는 동일하며, 재사용 `AiScript_File.EditFloatConst`), 나머지 청크는 그대로 유지합니다. 패널에는 **유형별**(polar/refPos/roll/screenDepth)로 **그룹화된** 노브가 **필터 및 검색 기능**과 함께 나열되며(카메라는 전투당 약 730컷의 시네마틱 스크립트이므로, 따라서 그룹/검색을 통해 탐색하며, 단순한 목록 형태는 아닙니다), 각각 편집 가능합니다. "💾 카메라 매개변수 저장"은 변경된 부동 소수점 값을 적용합니다(한 번 백업 + 재로드). Gate `BattleCameraScanLab` 확장: **카메라 포함 855 빈, 623,981 콜, 플로트 라운드트립 편집 855/855** (바이트 로컬 + 가역적). **정확히 말하자면:** float 값을 편집하면 이를 공유하는 모든 컷이 변경됩니다; 커스텀 앵글은 인-파일(in-file) 방식입니다(이전 결론인 "= 씬 오더링"을 뒤집음); 인-게임 효과 = RT2. Doc `docs/reverse/FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07.md` §6. 빌드 오류 0건. [이전: `v2.37.3`] — Jarvis-AURORA
- **🎨 `v2.37.3` — SPHERE GRID CANVAS: 확대/축소에 따라 크기가 조정되며 깔끔한 벡터 아이콘을 사용합니다(아틀라스가 잘못 잘렸습니다).** v2.37.1 버전에 대한 개발자의 피드백: Explorer의 아틀라스(`icon_atlas.png`) **셀이 잘못 잘려 나갔다** (Lv1-4 및 기타 여러 흉한 셀들) 그리고 노드가 **확대할 때 줄어들었다** (고정 화면 크기 → 화면에서 사라짐). 두 가지 수정 사항: **(1) 반경이 확대/축소에 따라 조정된다** — `CurrentNodeRadius = clamp(26×scale, 5..42px)`, 따라서 확대 = 더 큰 오브(아이콘이 선명하게 보임), 축소 = 더 작음(전체 보기); 아이콘/텍스트가 함께 크기가 조정됩니다. **(2) 벡터 아이콘** — **game-icons.net (CC BY)**의 글리프로 다시 돌아갔습니다 (`SphereGridIcons.cs`, SVG 경로 → `Geometry.Parse`) **줌 수준에 상관없이 잘리지 않고** 크기가 조정되는 것(비트맵 아틀라스 제외): locks = 깔끔한 **"L{n}"** 배지(nv1-4는 더 이상 잘리지 않음), 아이콘이 있는 스탯(HP/MP/힘/방어/마법/민첩/운/스킬) 및 나머지 = 크기 조절된 텍스트 배지(ACC/EVA/MDF/WHT/BLK/SPL/SKL). 카테고리별 컬러 오브 유지 + 글로우/호버/캡션/ant

i-VAIDARMERDA/소리. 빌드 오류 0개; CC-BY 크레딧 `SPHERE_GRID_ICON_CREDITS.txt`. [이전: `v2.37.2`] — Jarvis-MAGIC
- **🎯 `v2.37.2` — Monster AI Editor: #8 실제 지정 대상 (자신 / 적 / 아군 / 캐릭터#N…) — 파서가 센티넬의 잠금을 해제했습니다.** “파서를 확인해 보세요”에 따르면: `FFXDataParser/ScriptConstants.putEnum("btlActor")` 이것은 IDA가 제공하지 않았던 타겟 센티넬 맵과 **정확히** 일치합니다(ATEL 해결 시 타임아웃이 발생했습니다). 이제 이름이 지정되었으며 **코퍼스와 일관성을 갖췄습니다**: **-13/0xFFF3 = Self** (입증됨), **-14/0xFFF2 = FrontlineChars** (몬스터의 "적" = 캐릭터들; 가장 흔한 리터럴 센티넬이었음, 272회), **-6/-7/-8 = 캐릭터 #1/#2/#3**, **-15/0xFFF1 = AllMonsters** (몬스터의 “아군” — White Wind→몬스터 치유와 일치), **-17 = LastAttacker**, **-5 = AllActors**, **-3 = TargetActors**, **-20 = AllAeons**, `0x10NN = MonsterType`… (enemy/ally는 몬스터의 관점에서 표시됩니다). 이에 따라 **🎯 표적 변경**(v2.33.0)은 더 이상 “예를 들어 복사” 방식이 아니라 **명명된 표적 모드 드롭다운**으로 바뀌었습니다 — 이는 작성자가 처음부터 #8에서 원했던 “한 명/모든 적/모든 아군”입니다; 작업 목록에는 “대상: FrontlineChars”가 표시되며, **디스어셈블러/오퍼랜드 편집기**는 센티넬(0xFFE9–0xFFFF, 명확한 범위)을 “(대상: Self/…)”로 표시합니다. 새 기능 `FfxLib/Ai/AiTargetNames.cs` (btlActor, 코덱의 함수/속성 맵과 동일한 공개 출처); 드롭다운 메뉴에서 선택 + `AiScript_File.OperandGloss`. 게이트 `--ai2`/`--ai3` PASS (RT0 바이트 동일, 손상 없음 — 글로스만 변경, 변경된 바이트 없음); 빌드 편집기 오류 0개. **정직하게 말하자면:** Self는 바이트 단위로 검증됨; 나머지 이름들은 공개 RE에서 유래했으며 코퍼스와 일관성이 있음 (세밀한 의미론 = RT2). [이전: `v2.37.1`] — Jarvis-MAGIC
- **🩸 `v2.37.0` — Monster AI Editor: “HP가 X% 미만일 경우” 조건 검증 완료 (IDA+코퍼스) + 222개의 명명된 속성 필드 (“0xNN 필드” 끝).** Halyson은 IDA를 사용하라고 지시하며 “한 줄이 하나의 숫자인 설정 파일일 것”이라고 추측했는데 — **두 가지 모두 정확했다**. RE에서 `FFX_recon.i64`: 네이티브 디스패치 ATEL = `handler = *(FuncspaceTables[funcId>>12] + 16*(funcId&0xFFF))` (슬롯 +0 CALLPOPA / +12 CALL); `readChrProperty` (0x700F) = `0x7A4D70` → switch `field→속성`

그리고` (`sub_7B2DD0`). Cruzei com o **FFXDataParser/ScriptConstants.putBattleActorProperty** (a "config" que o dono intuiu) + o corpus: **field 0x00 = HP** (stat_hp, a propriedade MAIS lida do corpus — 306×), **0x02 = maxHP** (137×), **0x119 = NearDeath** (= IDA case 281 `current<max/2`). Opcodes aritméticos provados (`* 0x16` etc.). **#11 REAL shipado:** snippet guardado **"Se HP abaixo de X% → forçar comando"** = idioma `HP*100 < maxHP*X` (fields 0/2 corpus-provados) — o enrage de chefe de verdade, não mais um chute (a versão anterior v2.35.0 era genérica porque o field de HP não estava provado; agora está). **Nomeação:** novo `FfxLib/Ai/AiChrPropertyNames.cs` (222 fields nomeados, mesma proveniência pública do mapa de funções do codec) ligado no detector de buff/stat → as ações de status agora aparecem "Haste/Protect/StatusPoison/HP/maxHP…" em vez de "campo 0xNN". Gate `--ai2`: **HP%-enrage 346/346** + conditional 346/346; `--ai3` PASS. Docs: `docs/reverse/FFX_AI_NATIVE_DISPATCH_AND_CHRPROPERTY_FIELDMAP_2026-06-07.md` (+ rename-queue pro `.i64`). **Honesto:** estrutura provada offline, efeito in-game = RT2; o gauge 0xDA/218=HP%×256 existe no IDA mas o corpus não usa (usei o caminho que a IA usa de verdade, 0/2). Build do editor red por WIP da lane Sphere Grid (alheio); meus arquivos são todos FfxLib, gate-validados. [anterior: `v2.36.0.1`] — Jarvis-MAGIC
- **🎥 AURORA — 전투 카메라 샷 테이블(IDA, 문서 전용)의 RE: "shot" = 카메라 노드에 대한 참조이며, 위치/FOV가 아님.** “100% 사용자 정의 앵글이 가능한가요?”라는 질문에 대한 답변: **플로트 테이블을 통해서는 불가능합니다.** 디코딩 및 이름이 변경된 체인은 `FFX_recon.i64`: `camReq`→`FFX_Battle_Camera_RequestShot`→`CmdQueue_Push`→`BindQueuedShots`→`ShotTable_Dispatch`(@0x7985A0)→`ShotTable_Walk`(@0x797420). O `shotIndex` BLOB을 색인화합니다 (`[1]`=count, `[2+shot]`=셀렉터, u16 오프셋 테이블 → **노드 ID** 하위 테이블, 0xFFFF=없음)이며 **카메라 노드**(씬/이펙트에 베이킹된 애니메이션 경로)로 해결됩니다. 위치/FOV는 **노드를 추적**하여 얻어지며, 레코드에는 부동 소수점 값이 없습니다. 소스 = 파일에서 로드된 컨테이너 (`+4`=ATEL 스크립트, `+8`=표): via를 통한 효과 `FFX_MagicFile_LoadDllByMagicId` (`magic_NNNN.dll`); `g_CameraShotC`를 통한 전투

hannels[8]` (kind2/id1) + `actor+0xF7C` (kind3). **Implicação:** trocar entre os ângulos existentes = operando SHOT do camReq (já no painel, v2.36.0); **ângulo custom = authoring de nó/animação de câmera na cena Phyre / effect DLL** (scene-authoring, encosta na lane MAP), NÃO um writer no per-battle bin. 13 renames + 2 comentários de layout salvos no `.i64`. Doc: `docs/reverse/FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07.md`. *(RE/IDA = 문서 전용, csproj는 업데이트되지 않음.)* — Jarvis-AURORA
- **✨ `v2.37.1` — SPHERE GRID CANVAS: 사실적인 비주얼 (에디터 아틀라스를 통한 FFX의 실제 아이콘) + 가독성 높은 노드 + 실시간 안티-VAIDARMERDA + 색상/캡션/글로우/호버/사운드.** 작성자는 “예쁘게 만들어 주세요 + 자동 알림”을 요청했으며, v1 버전은 아이콘이 없는 아주 작은 점이었다고 지적했습니다. **핵심 발견:** 에디터에는 이미 Explorer의 멋진 렌더러가 탑재되어 있었습니다 (`SphereGridPreview_Control` + `Assets/SphereGrid/icon_atlas.png`) — 그래서 **진짜 아틀라스를 훔쳐왔다** (예전에 올렸던 game-icons.net은 제외했다). 이제 캔버스: **(1) FFX의 정통 아이콘** — 알록달록한 오브 + 스프라이트 `icon_atlas.png` 작성자: `AppearanceType` (STR/DEF/MAG/HP/MP/white/black/special/skill/lock) 또는 텍스트 배지 (AGI/ACC/EVA/LCK…), 익스플로러와 마찬가지로, 다음 경로를 통해 `SphereGridNodeVisualInfo` 조립된 `panel.bin` (같은 논리 `CreatePreviewVisual`/`BuildShortLabel`). **(2) 가독성 있는 노드** — 오브 ~12px (이전 5.5) + 기본 줌 시 가독성 있는 수준으로 열림 (더 이상 828개의 노드가 빽빽하게 표시되지 않음) + LOD (개요 화면의 점) + 뷰포트 컬링. **(3) 실시간 오류 방지** — 노드 40개 미만 드래그 또는 링크 클릭 → 노드 **빨간색** + 즉시 배너 표시 (Validate 클릭 불필요; 변경된 노드/프레임만 간단히 검사). **(4)** 카테고리별 색상 + 패널의 **라벨**, 선택된 노드에 **깜박이는 글로우** (DispatcherTimer), **호버** 시 점등, **사운드** via `AudioStudio_Service` (FFX UI SFX 포함; 프로젝트가 비공개이므로 공개됨 — 소유자 수정). **이미지 AI 없음** — 에디터에 기본으로 포함되어 있던 게임의 실제 스프라이트입니다. 빌드 오류 0개; 에디터가 충돌 없이 실행됩니다. [이전: `v2.37.0`] — Jarvis-MAGIC
- **🎥 `v2.36.0` — AURORA: Aurora Chamber의 카메라 패널 (컷 편집) `camReq` 전투: 앵글/샷 + 타겟).** 검증된 리더/카메라 게이트 위에 (문서 전용: chun

k0는 AiFile ATEL, RT0 863/863이며, `camReq` (100% 편집 가능, 바이트 단위), 이제 UI: **"🎥 카메라"** 카드에는 클립 목록이 표시됩니다 `camReq` (`0x703F`) **SHOT**(앵글, 1부터 시작) 및 **TARGET**(프레임에 잡힌 배우, -1=없음)을 편집할 수 있는 선택된 배틀; **💾 카메라 저장**은 **same-length byte-local** 연산자 패치(다른 청크의 오프셋 유지), 일회성 백업 기능을 적용하고 다시 불러옵니다. 다음을 통해 읽기/쓰기 수행: `FfxLib/BattleMap/BattleCameraScript_File` (AI와 동일한 코덱). 파일: `Modules/AuroraChamber/{AuroraChamber_DataModel.cs (CameraShots/PopulateCameraRows/SaveCameraShots), _Control.axaml (card + lista editável), _Control.axaml.cs}` (코드는 이미 `c211a5f2`). 빌드 오류 없음 (편집기 열림 = `.exe` 정지됨; 별도 출력된 빌드로 확인됨). **정직하게 말하자면:** 스크립트가 이미 참조하고 있는 앵글/타깃 간 전환; 100% 사용자 정의 앵글(새로운 위치/시야각) = 샷 테이블의 RE `sub_797D60` (보류 중, IDA). 게임 내 효과 = RT2 (바이트 안전 + 가역적, 게이트 `BattleCameraScanLab`). [이전: `v2.35.0`] — Jarvis-AURORA
- **🎭 `v2.35.0` — Monster AI Editor: 행동 프리셋 (#10) + 검증된 “N 미만” 조건 (#11) + 문서화된 경계 조건 #12/#13.** “이 모든 것 처리하기” 백로그 중 처리 가능한 부분은 모두 마무리합니다. **#10 — 🎭 원클릭 프리셋** (이미 검증된 자동화 기능으로 구성, 전투 워커 자동 선택 + 성장 효과 검증 완료): **🛡 방어형** (Protect+Haste 자체), **⚔ 공격형** (피커에서 선택한 스킬을 항상 강제 적용), **🔥 분노** (선택된 스킬 + Haste 자체), **🎲 교대** (2번 중 1번 선택). **#11 — "N 미만" 조건:** Behavior Library에 저장된 새로운 스니펫 `Se propriedade do chr (self) ABAIXO de N → forçar comando` = 코퍼스의 **#1 조건 언어** (`readChrProperty` 0x700F는 **980개의 분기**를 생성합니다; 비교 `LT 0x0B` (인구조사에서 확인된), `field`+`limiar`+`comando` 사용자가 지정한 값 — **참고:** HP의 정확한 필드 ID는 바이트 단위로 검증되지 않습니다(검증된 상태인 0x38/0x31/0x32를 사용하십시오; HP = RE 경계)이므로, 이는 일반적인 값이며 단순히 “HP%”를 무작위로 산출하는 버튼이 아닙니다. **#12 (턴 N)** 및 **#13 (실시간 테스트)** = **경계로 문서화됨** (턴에 대한 네이티브 게터는 없음 — 몬스터별 priv-var 카운터이며, 1-in-K RNG 프록시는 이미

 shipa; live는 길이 보존 편집만 지원하며, grow = 게임 재로딩) v2.33.0 문서에 명시됨. 논리: `AiSnippetLibrary` (발췌문 `guard-chrprop-lt-force-cmd`) + DataModel의 프리셋 (`ApplyPreset*`,로 구성된다 `AddAbility`/`AddSelfBuff`). 게이트 `--ai2`: **조건부 스니펫 346/346** (확장, 점프 테이블 확장, 재파싱, 유효성 검사); `--ai3` PASS. 빌드 오류 없음. **정직하게 말하자면:** 오프라인에서 구조 검증 완료; readChrProperty의 효과 및 아리티 = RT2. [이전: `v2.34.0`] — Jarvis-MAGIC
- **🩺 `v2.34.0` — 배틀 트래커: 작동함 (실시간 전투 데이터 읽기) — 자동 초기 읽기, 정확한 상태 표시 + RT2 쓰기 잠금.** 배틀 트래커가 **비어 있는 상태로** 열렸습니다 (흰색 패널 2개, "Load Ingame"이 반응 없음). 원인은 **주소가 아니었습니다** — 실행 중인 RAM에서 확인했습니다 (FFX.exe PID 24716, 전투 `azit03_01`) 전체 체인이 올바른지: `ADDR_BATTLE_ACTIVE`(rva `0xD2A8E0`)=1, `ENEMY_LIST`/`PLAYER_LIST`(rva `0xD34460`/`0xD334CC`) 해결하다, stride `0xF90`, 의 오프셋 `MemoryChr` (`Id`@0xE, `Max_hp`@0x594, `Hp`@0x5D0, `In_battle`@0xDC8) 타격, 포메이션 슬롯 `[0,4,6]` == 다음 3명의 플레이어는 `In_battle=1`. 백엔드 (`Binarysharp.MSharp` x64에서 FFX x86을 실행하는 것도 작동합니다 — `new MemorySharp` + `Read<byte>(rva, isRelative:true)` 올바른 값을 반환합니다. **원인은 UX였습니다:** `DataModel` **1차 판독에서는 절대 발사하지 않았다** (o `ArenaTracker` 생성자에서 읽습니다(Battle Tracker는 그렇지 않음), 그리고 타이머는 자동 새로고침이 켜져 있을 때만 읽었습니다. **수정 사항:** (1) 생성자에서 초기 읽기 수행; (2) 타이머는 매 틱마다 **정확한 상태**를 유지하고 **전투 시작 시 첫 번째 사진을 자동으로 채움**(자동 새로고침 설정 불필요)하며, 전투 종료 시 초기화; (3) `ReadInfo` 오류를 처리하는 try/catch 문과 가드 조건(포인터 0 / null 바이트 / 범위를 벗어난 슬롯); (4) `MemSharp_Service.IsAvailable()` 더 이상 attach +에서 터지지 않습니다 `IsAttached`; (5) UI에 **상태 배너**가 추가되었습니다("FFX 미검출" / "동반, 전투 없음" / "전투 중: 이름 · N 명의 적, M 명의 아군")과 **RT2 쓰기 잠금**(체크박스, 기본값 **OFF = 읽기 전용**) 기능을 추가하여, 이름이 변경된 "⚠ 게임에 저장" 버튼을 제어합니다. 새로운 검증 도구: `RuntimeTools/BattleTrackerProbe` (동일한 DLL을 사용하여 실시간 읽기 경로를 테스트합니다). 파일: `Modules/BattleTracke

r/{BattleTracker_DataModel.cs, BattleTracker_Control.axaml}`, `Services/MemSharp_Service.cs`, `RuntimeTools/BattleTrackerProbe/*`, doc `docs/reverse/FFX_BATTLE_TRACKER_LIVE_READ_PROVEN_2026-06-07.md`. Build do módulo OK (validado em worktree HEAD limpo; o build cheio do editor está quebrado por WIP `AiTargetOption` de outra lane, alheio a esta mudança). **Honesto:** READ provado na tela/RAM; a **escrita** (Load Ingame → `WriteProcessMemory`) segue RT2 (jogo aberto + trava ligada). [anterior: `v2.33.0`] — Jarvis-MAGIC
- **🎯 `v2.33.0` — Monster AI Editor: 대상 변경 (#8) + 멀티캐스트 / 2번째 스킬 (#9), 코퍼스 마이닝을 기반으로 함.** 목록에서 두 가지 더, **RE/코퍼스를 먼저 활용해 추측 없이** 완성. 새로운 스캐너는 `AiScriptLab` (`--targets`, `--cond`) **1,645개의 명령 사이트**와 **10,520개의 브랜치**를 채굴했습니다 (문서 `docs/reverse/FFX_AI_TARGET_ENCODING_AND_CONDITION_GETTERS_2026-06-07.md`). **#8 — 🎯 대상 변경:** 대상은 command-id 앞의 push입니다; **54%는 연산 처리되며 (PUSHV findMatchingChr)**, **46%는 리터럴 센티넬(PUSHII)**입니다 — 오직 이들만이 1개의 피연산자로 대체 가능합니다(길이 보존, = RT2에서 입증된 편집). 솔직히 말해: **self (-13/0xFFF3)**만이 바이트 단위로 검증되었습니다; 나머지 음수 센티넬들은 정확한 의미가 RE 경계인 타겟 모드들입니다. 따라서 편집기는 **"자신" + "이 몬스터의 다른 액션에서 대상 복사"**(게임 내에서 이미 정상 작동하는 센티넬)를 제공하지만, 의미론은 명시하지 않습니다. **#9 — ⧉+ 멀티캐스트:** 선택된 행동 바로 뒤에 피커에서 선택한 스킬을 삽입하며, 대상과 모드를 복제합니다(시모어 스타일의 연속 2개 행동; 리빌드를 통한 성장). 순수한 논리 `AiAutomation.{ChangeTargetInstructions,InsertSecondCommand}` + `AiDetectedAction` 이겼다 `TargetPushOffset/TargetOperand/TargetIsLiteral`. 게이트 `--ai3`: **대상 변경 195/195** (757개의 리터럴 대상), **두 번째 명령어 삽입 294/294**; 그 외 모든 항목(add/rng/detect/remove buff-stat/reorder/change/duplicate/toggle/self-buff/copy)은 PASS로 처리됨; `--ai2` PASS. 빌드 0 오류. **정직하게 말하자면:** 오프라인에서 구조 검증 완료; 게임 내 효과 = RT2 (멀티캐스트: 두 개가 같은 턴에 해결되는지 확인). 각 센티넬 매핑→모드 + HP%/턴 = 경계 (문서 참조). [이전: `v2.32.0`] — Jarvis-MAGIC


- **🎥 AURORA — chunk0에서 편집 가능한 검증된 전투용 카메라 (`camReq`): 863번의 전투에 대한 스캔 + 게이트 (문서만, csproj 변경 없음).** 복구 작업 재개 (카메라 패널). **핵심 발견 사항:** 전투용 카메라는 chunk3에 없습니다 (`+0x2C` (상수임) — **스크립트 기반**이며, **전투별 TODO bin의 chunk0은 순수한 AiFile ATEL**로, 몬스터 AI 코덱(`AiScript_File`) **바이트가 동일한 863/863 (RT0)**을 재전송 — 코덱이 이전에 본 적이 없는 코퍼스에서 새로운 증거 (`declared@+0x10 == len(chunk0)`). 각 컷은 하나의 `camReq` (func-id `0x703F`)는 2개의 즉시 operand를 pop합니다: **SHOT** (각도, 1-based; 엔진은 shot-1을 사용) 및 **TARGET** (프레임에 잡힌 액터, `0xFFFF`=없음). **IDA에 깊이 뿌리내린 의미론** (`FFX_Atel_Battle_camReq @0x7A5E10` → `FFX_Battle_Camera_RequestShot @0x797BD0`): 첫 번째 pop = 바로 직전의 push = TARGET (`v3`); 2번째 팝 = SHOT (`v4`); **이전 내용을 수정합니다** — 그 `0xFFFF` 호출 시 CONSTANTE가 하드코딩되어 있었으며, 피연산자는 아니었습니다. 코퍼스: **646개 빈 / 3736회 호출, 피연산자의 100%는 `PUSHII` 즉시 → 100% 편집 가능한 바이트 단위**; SHOT은 거의 항상 1(→ 인덱스 0), TARGET은 다양함(28이 주를 이룸). 새로운 순수 로직 `FfxLib/BattleMap/BattleCameraScript_File.cs` (chunk0 추출 → 디코딩 → 목록 `camReq` (shot/target 출처 + 바이트 단위 로컬 동일 길이 편집, 다른 청크의 오프셋은 유지) + gate **`BattleCameraScanLab`** (no `offline_ci.ps1`): **walk 종료 863/863 · RT0 863/863 · 샷+타겟 왕복 편집 646/646** (바이트 로컬 + 가역적). 추가 발견: 전투 스크립트는 `0x5F=POPF2`/`0x6D=PUSHF2` (유효한, 몬스터 명부에 등재되지 않은). 이름 변경/댓글은 다음 위치에 저장됨: `FFX_recon.i64`. 문서: `docs/reverse/FFX_BATTLE_CAMERA_CAMREQ_CORPUS_PROVEN_2026-06-07.md`. **정직한 경계:** 이를 통해 **스크립트가 이미 참조하고 있는 샷/타겟 간에 전환**할 수 있습니다; 100% 사용자 정의 각도(위치/시야각)의 경우 샷 테이블의 RE가 필요합니다 (`sub_797D60`) — IDA 처리 중. **다음:** 이 리더 상단의 Aurora Chamber에 있는 “카메라” 패널. *(테스트/RE/lab = 문서 전용, csproj 파일은 수정하지 않음.)* — Jarvis-AURORA
- **🟢 `v2.32.0` — Monster AI Editor: 모든 액션(⚔ 명령어 · 🛡 버프/상태 · 📊 스탯)을 유형별로 필터링하여 표시 + 명령어 이름 변경

이름 없는 사용자 (#6 및 #7).** 소유자의 목록에 있는 두 가지 요청. **#6 — 명령어뿐만 아니라 모든 항목을 나열하기:** “몬스터의 행동” 기능이 이제 **버프/상태(`writeChrProperty 0x7018`)** 및 **통계 (`setStatField 0x70AB`)**, **유형별 필터 드롭다운** (전체 / ⚔ 명령어 / 🛡 버프 / 📊 스탯)이 있습니다. 각 액션은 아이콘과 친숙한 이름을 표시합니다(알려진 상태 = "Haste/Protect/Reflect", 그 외에는 "0xNN 필드"; 대상이 자기 반사일 경우 "(자체)"; 0일 경우 "= 값" 또는 "제거"). **이동 / 복제 / 제거**는 이제 모든 유형에 적용됩니다 (런 중 스택에 영향을 주지 않는 일반적인 제거). `[pushes…][call]`); **교체 / 강제↔대기열**은 **명령어 전용**입니다 (저장 + 경고). **#7 — 이름이 없는 명령어 이름 변경:** ID가 `performCommand` 사전에는 해당 용어가 등재되어 있지 않습니다 (예: `comando 0x60AB`), **✏ 이름 변경** 필드가 나타나며, 이를 통해 **영구적으로 저장되는** 친숙한 이름을 지정할 수 있습니다 (`%LocalAppData%\FFXProjectEditor\ai-command-labels.json`)이며, 편집기 전체에서 모든 몬스터에 적용됩니다. 새로운 순수 논리: `FfxLib/Ai/AiAutomation.DetectActions` (command+buff+stat; `DetectCommandActions` (필터링된 보기로 변경됨) + `FfxLib/Ai/AiCommandLabels.cs` (부팅 시 로드되며, 편집할 때마다 저장됨; 게이트에서는 비어 있음 ⇒ 효과가 없음). 게이트 `--ai3` 확장: **버프/스탯 감지 = 4020개 버프 (제거 가능 3698개) + 4156개 스탯 (4156)**, **버프/스탯 제거 30/30** (일반 제거는 정확한 실행에 따라 축소되며 재분석됨), **재정렬 325/325** (이제 모든 유형의 인접 대상에 적용됨); add/rng/change/duplicate/toggle/self-buff/copy는 PASS로 유지; `--ai2` PASS. 빌드 0 오류. **정직하게 말하자면:** 오프라인에서 검증된 구조; 게임 내 효과 = RT2. 바이트 단위로 검증된 3개의 필드 ID만 이름이 부여되며(나머지는 "0xNN 필드", 정직하게 말하자면). [이전: `v2.31.1`] — Jarvis-MAGIC
- **🧩 `v2.31.1` — SPHERE GRID CANVAS: 저작 기능 패키지 (파손 방지 검증, 시각화, 스탬프, 링크 관리자 + 다중 선택).** 소유자가 요청한 네 가지 기능으로, 모두 엔진 탐지 기능을 통해 조정되었습니다(가까운 노드/교차 링크로 인한 오류): **(1) 오류 방지 검증** — 바이트 안전성 외에도, 이제 **근접성**(2개 노드 간 거리 40 단위 미만, 단선 확인됨) 및 **링크 교차**(기본 측정값 = 0이므로 모든 경우가 실제 위험; 세그먼트 교차 테스트 등)에 대해 경고합니다.

및 비인접 링크)와 **연결성** (정보: 링크가 없는 구성 요소/노드 수 — 참고: 기본 Expert 버전은 25개의 구성 요소를 제공하므로, 이는 오류가 아닌 정보입니다). **(2) 시각화** — **참조 격자** (43단계에서 확대 시 나타나는 점들), **선택된 노드의 링크 및 인접 노드 강조 표시**, 그리고 **캔버스상의 유형명** (읽기 `panel.bin`; 항상 선택된 상태이며, 모두 “이름” 토글 + 확대/축소 기능으로 채워짐). **(3) 스탬프** — **◇ 다이아몬드** (4개 노드 + 4개 링크) 및 **— 선** (3개 노드) 버튼은 **이미 간격이 조정된(≥2×43) 상태이며 연결된** 도형을 붙여넣습니다 = 구조상 엔진 호환; 캔버스를 클릭하여 위치를 조정합니다. **(4) 링크 관리자 + 다중 선택** — 노드 패널에는 **✕ 제거** + “노드 #에 연결” 상자가 있는 링크 목록이 표시됩니다; 그리고 **Shift+드래그** = 선택 상자 → **Delete로 그룹 제거** (인덱스 혼란을 방지하기 위해 내림차순으로 RemoveNode). 라이브러리의 검증된 뮤테이터에 대한 모든 내용. 빌드 오류 0건; 편집기가 충돌 없이 정상 실행. **솔직히 말하자면:** 근접/교차 경고는 **대략적인** 휴리스틱입니다(엔진의 정확한 상한선이 아님); 연결성은 참고용 정보입니다. [이전: `v2.31.0`] — Jarvis-MAGIC
- **🟢 `v2.31.0` — 몬스터 AI 편집기: 다른 몬스터의 AI 복사 · 원래 AI 복원.** 목록에서 두 가지 더: **📋 AI 복사** — 스크립트가 있는 294종의 몬스터 중 아무 몬스터나 선택하여 전체 AiFile을 복사한 뒤, **이 몬스터의 스탯/전리품은 그대로 유지**합니다(AiFile의 영역만 변경되며, grow-aware 스플라이스 및 유효성 검사 적용); 원하는 대로 이미 동작하는 다른 몬스터의 행동 방식을 이 몬스터에 빠르게 적용할 수 있는 방법입니다. **♻️ 원래 AI 복원** — **추출된 참조**의 몬스터에 대한 바닐라 AI를 다시 복사합니다 (`<ffx_ps2>\ffx\master\jppc\battle\mon\_mNNN\mNNN.bin`, 예: `D:\FFX Extracted`) — AI로 수행된 모든 편집 내용을 취소합니다(과거 세션의 편집도 포함되며, 이는 `.prev.bak` (1단계). 둘 다 `.prev.bak` 이전. 레우사 `SaveNewAi` (ValidateRebuilt + grow-splice + backup + reload). 게이트 `--ai3`: **copy ai 346/346** (몬스터에 AiFile 스플라이스 → 다시 슬라이스 → 재파싱, 명령어 수 동일); 그 외 모든 항목(add/rng/detect/remove/reorder/change/duplicate/toggle/buff)은 PASS로 처리됨. 빌드 오류 0개. **솔직히 말해서:** 오프라인에서 구조 검증 완료; 게임 내 효과 = RT2. (복원하려면 ffx_ps 루트 권한 필요)

2번 참조 항목이 설정됨.) [이전: `v2.30.0`] — Jarvis-MAGIC
- **🟢 `v2.30.0` — Monster AI Editor: 추가 1-클릭 동작 (복제 · 강제↔대기열 · 자기 버프 · 취소).** 요청된 기능 목록을 이어가면: **⧉ 복제 (2회 시전)** — 선택한 액션 바로 뒤에 해당 액션의 3단 조합을 복사합니다(반복을 통한 다중 시전; 성장 + 재분석); **⚡ 강제↔대기열** — 호출을 다음 중 하나로 전환합니다. `forcePerformCommand` (force) 및 `performCommand` (큐), 길이 보존 연산자 1개; **🛡 자신에게 버프 부여** (Haste/Protect/Reflect via `writeChrProperty`, “언제”를 항상/가끔과 동일하게 사용; 전투 워커의 자동 선택, 저장된 성장); **↶ 되돌리기 (백업)** — 이제 모든 저장 시 `.prev.bak` 덮어쓰기 전 (1단계 되돌리기). 새로운 로직은 `FfxLib/Ai/AiAutomation.cs` (`DuplicateActionInstructions`/`ToggleForceInstructions`/`AddSelfBuff` + 버프 프리셋); 중앙 집중식 저장 위치: `WriteMonsterWithBackup`/`SaveNewAi`. 게이트 `--ai3` 확장: **중복 294/294**, **토글 294/294**, **자가 버프 346/346** (추가/무작위/탐지/제거/재정렬/변경 항목은 모두 PASS). 빌드 오류 0개. **정직하게 말하자면:** 모두 오프라인에서 검증됨 (구조/길이); 게임 내 효과 = RT2. 버프의 필드 ID(0x38/0x31/0x32)는 스니펫에 문서화된 것과 동일함 — 더 많은 ID를 마이닝하면 추가 상태 정보를 제공하겠습니다. [이전: `v2.29.0`] — Jarvis-MAGIC
- **🐉 AURORA — 게임 내에서 검증된 몬스터 추가 (RT2): 에디터로 추가된 2마리의 다크 이온이 전투에 정상적으로 로드되었으며, 플레이 가능하고 크래시 없이 작동함 (문서만, csproj 수정 없음).** 이정표: Halyson이 포메이션/아레나 제작을 통해 전투에 몬스터 2마리(다크 이온 클래스)를 추가했습니다(Aurora Chamber ➕ / Formation Editor)를 통해 전투에 몬스터 2마리(다크 이온 클래스)를 추가했고, **FFX HD가 전투를 불러와 추가 액터를 완전한 액터로 스폰시켰으며, 다크 발레포르가 AI를 실행하고 에너지 레이를 발사했습니다** (초반 턴에 플레이 가능, FPS 30). chunk3/GROW 체인의 "정직: 게임 내 미확인" 주사위 경로를 닫습니다 (v2.27.0/51): **엔진이 수정된 몬스터 수를 수용하고 추가 액터를 실행합니다** — chunk2 (구성, 플래그 `0x1000`) + chunk3 (앵커 `+0x20`) 스폰 루프 덕분에 정상적으로 작동함 (데이터 무결성 유지; 데이터 손상이 발생했다면 로드되지 않았을 것임). **하지만 Energy Ray에서 게임이 크래시됨** = **콘텐츠 불일치, 바이트 손상이 아님**: Dark Aeon (거대 모델 +

 전체 화면 오버드라이브 + (자체 아레나를 차지하는) 카메라/효과를, 이를 위해 설계되지 않은 신(Sin) 아레나에서 사용하면 엔진이 버벅거립니다. **솔직한 평가:** 게임 운영상 안전합니다(로딩+스폰+AI 작동); **안정성을 위해서는 아레나에 적합한 콘텐츠가 필요합니다** — 다크 이온이 최악의 사례입니다(안정적인 전투를 위해 일반 몬스터나 로스터에 있는 몬스터를 사용하세요). 배너 + 문서 모델 §7 업데이트됨. 문서: `docs/reverse/FFX_AURORA_GROW_INGAME_PROVEN_2026-06-07.md`. **다음:** 레짐-1 대 레짐-2; 여유 시간 없는 전투; 아레나에 적합한 몬스터를 통한 안정성. *(테스트/RT2 = 문서 전용, csproj 파일을 수정하지 않음.)* — Jarvis-AURORA
- **🔧 `v2.29.0` — 몬스터 AI 편집기: 이동(위/아래), 교체 및 행동 제거 — 이제 몬스터를 처음부터 끝까지 편집할 수 있습니다.** 자동화 기능(v2.24.0/49)에 더해, "몬스터 액션" 목록에 3가지 새로운 작업이 추가되었으며, 모두 **length-preserving**(add/remove보다 훨씬 더 안전함)입니다: **▲ 위로 / ▼ 아래로** (인접한 액션을 건너뛰며 액션 순서를 재정렬 — `Rebuild` 명령어의 ID에 따라 점프/진입점을 재매핑하므로, 제어 흐름은 이동된 블록을 따르게 됩니다. 이동된 항목은 다시 클릭할 수 있도록 선택된 상태로 유지됩니다) 및 **✏ 위에서 선택한 스킬로 교체** (선택한 액션 명령의 피연산자만 피커의 스킬로 재작성합니다 — 이는 RT2-live에서 검증된 Firaga→Thundaga 1바이트 방식과 정확히 동일하며, 이제 MonMagic2/Multi-Fira를 포함한 모든 명령에서 작동합니다). 순수 논리: `FfxLib/Ai/AiAutomation.cs` (`MoveActionInstructions`/`ChangeActionInstructions` + `CmdPushOffset` 에서 `AiDetectedAction`); 독립형 트라이어드에만 제공됩니다(유효성 검사기가 나머지는 차단합니다). 게이트 `--ai3` 확장: **재정렬 237/237** (아래로 이동, 길이 유지, 재파싱, 동일한 명령어 멀티셋) + **변경 294/294** (슬롯이 Firaga로 변경, 길이 유지, 재파싱). add/rng/detect/remove는 계속 PASS. 빌드 오류 0개. **정직하게 말하자면:** 오프라인에서 구조 검증 완료; 이동 시 실행 순서가 변경되고, 교체 시 명령어가 변경됨 — 게임 내 효과 = RT2 (의도된 것으로, 제작자의 목표임). 복잡한 사례(비사소한 대상 / 무언가가 액션으로 전환되는 경우)는 고급 AI 어셈블러의 영역입니다. [이전: `v2.28.1`] — Jarvis-MAGIC
- **🧩🎮 `v2.28.1` — SPHERE GRID CANVAS: 토폴로지 편집 (게임 내 검증 완료) (+300 HP) + 개선 (이름별 노드 유형, 스냅) 

실제 간격, 복원/백업).** **MARCO:** Halyson이 **Canvas(v2.25.0)에서 Standard 그리드를 편집하고 저장한 후, FFX가 이를 불러와 → 탐색하여 → 추가된 노드를 활성화했습니다 (+300 HP가 캐릭터에 적용됨)** — *"게임 내 편집된 토폴로지 = 검증되지 않음"*이라는 경고가 **화면에 표시됨** (lib-검증 → 캔버스 → 저장 → 실제 엔진 순서의 사이클이 소유자의 손에서 중단됨). **엔진 관련 발견 사항:** 노드 간 거리가 너무 가까워지거나 링크가 교차하면 엔진이 **그리드를 파괴합니다** (오프라인 바이트 안전 ≠ 엔진 안전); "실제 크기" 바닐라 **측정값 = 기본 간격 ~43un** (평균 링크 ~77, dat01/02/03). 툴링으로 구현됨: **(1) snap-to-43** (노드를 배치하거나 드래그하면 바닐라 그리드에 정렬됨; 기본적으로 켜져 있으며, 토글 가능); **(2) 근접 경고** Validate에서 표시 (2개 노드가 40un 미만일 경우 플래그 표시 = 파손 위험; 권고 사항이며, byte-safe를 차단하지 않음); **(3) 이름으로 노드 유형 선택 드롭다운** (읽기 `panel.bin` 출처: `ReadNodeTypes` → “힘 +1”/“HP +200”/“Lv.1 잠금”… 헥스 대신; 노드 `FFh`=유형이 지정되지 않으면 게임 내에서 레벨 3 자물쇠 모양으로 렌더링되었으나, 이제 올바른 유형을 설정할 수 있음); **(4) ♻️ 원본 복원** (프로젝트에서 추출한 참조의 기본 그리드를 복사함 = 게임을 충돌시킨 저장 데이터를 취소함) + **백업 `.prev.bak`** "프로젝트에 저장"을 수행하기 전에 자동으로 실행됩니다. 빌드 오류 0건; 편집기가 충돌 없이 정상적으로 실행됩니다. 메모리/간격 제약 조건이 기록되었습니다. **솔직히 말해서:** 토폴로지 편집 기능은 이제 **게임 내에서 검증**되었습니다(로딩+활성화); 한계(근접/교차)는 엔진의 정확한 상한이 아닌 **측정된** 휴리스틱 값입니다 — 추가 테스트/RE를 통해 정교화될 예정이며(링크 교차 감지는 향후 구현 예정). [이전: `v2.28.0`] — Jarvis-MAGIC
- **➕ `v2.28.0` — AURORA: UI에서 몬스터 추가/제거 기능(Aurora Chamber의 버튼).** GROW(v2.27.0)에 인터페이스가 추가되었습니다: 순수 오케스트레이터 `FfxLib/BattleMap/BattleArenaAuthor.cs` **chunk2(형성) + chunk3(앵커)를 락스텝으로 동기화**하며, 오로라 챔버에 2개의 버튼(**➕ 몬스터 추가 / ➖ 몬스터 제거**, “위치 저장” 옆)이 있습니다. **2가지 모드:** "add"는 여유 공간이 있을 경우 아레나의 **예비 앵커**를 사용합니다 (`formação-viva < MonsterPositionCount`) = 다음 슬롯만 채우고, **chunk2만, grow 없음**; 그렇지 않으면 **chunk3이 확장됨** (모드 2

, `BattleArenaGrowWriter`). 이 새로운 슬롯은 **마지막으로 살아남은 몬스터를 복제**합니다 (종 + 플래그 `0x1000`); remove는 마지막으로 활성화된 슬롯을 지웁니다. backup-once를 사용하여 저장합니다 (`.aurora.bak`) + `ReloadSelectedBattle`. 게이트 `BattleArenaGrowLab` 확장 (저자 링크): **AUTHOR 추가 694/694 + 제거 302/302** (재디코딩 완료, 슬롯 복제/정리, 라이브 포메이션 ±1) 및 RT0 700/700 + ADD 696/696 + REMOVE 393/393. 에디터 컴파일 오류 0개 (exe 멈춤 = 에디터 열림; 임시 출력 파일의 빌드 결과 확인). 문서 업데이트됨 `FFX_AURORA_CHUNK3_PAYLOAD_MODEL_2026-06-07.md`. **정확히:** 바이트 안전 오프라인; 게임에서 새로운 카운트 = **RT2/probe**(화면 내 배너)를 지원합니다. UX: 포메이션 에디터에서 종류 조정 + 맵 뷰어에서 위치 드래그. — Jarvis-AURORA
- **🐉 `v2.27.0` — AURORA: chunk3의 구조적 GROW (바이트 단위의 몬스터 추가/제거) — "chunk3" 블록이 떨어졌습니다.** 답변: `HANDOFF_AURORA_CHUNK3_RESOLVE_2026-06-07`. 이전에는 앵커를 **이동**만 할 수 있었지만(v2.12.0), 이제는 몬스터의 **개수**를 변경할 수 있습니다. **패킹 모델에 대한 수정 사항 (코퍼스 863, 검증됨):** area-record는 8개의 배열을 포인터별로 고정된 순서대로 묶습니다 (`origin<party<partyB<aeon<monA<monLive<monB<camera`, 863/863); **용량 = 다음 포인터 − 포인터**; **`monLive`(+0x20)는 TIGHT** (==`MonsterPositionCount@+0x06`, 856/863) 반면 **`monA`(+0x1C) ~12** 및 **를 예약`monB`(+0x24) 예약 3..78** → 예약 공간이 크기 조정 없이 더 큰 카운트를 수용합니다. “신비한 간격”은 바로 이 예약 공간이었습니다; `+0x30..+0x5C` = 영역/카메라당 6개의 부동 소수점 값 (비포인터). **`BattleArenaGrowWriter.GrowMonsters`** = 파일 끝부분의 스플라이스 삽입/삭제 `monLive` + 재도장만 `monB`(+0x24)/카메라(+0x2C) + 청크 테이블 + `+0x06`; 단일 영역 경비 + 밀집 + 예비 ≥ 상한 (HardActorCap=8 보수적; 데이터 상한=15 znkd09). 게이트 **`BattleArenaGrowLab` PASS** (no `offline_ci.ps1`): **RT0 no-edit 700/700** 바이트 동일, **ADD +1 696/696**, **REMOVE −1 393/393** (깨끗한 재디코딩). 적격하지 않은 항목은 정직하게 거부됨 (149개 다중 영역 + 6개 비타이트 + 13개 비정상 예비 → MOVE를 통해 계속 편집 가능). 변환 전투→장면 조정 완료 = **동일성** (핸드오프 2.3). 문서 `docs/reverse/FFX_AURORA_CHUNK3_PAYLOAD_MODEL_2026-06-07.md`. 빌드 오류 0개. **솔직히 말해서:*

* 바이트 세이프 오프라인 (RT0) ≠ 게임이 새로운 카운트를 수용함 — **게임 내 미확인** (RT2/프로브 + 소유자 승인; 스폰 루프의 정확한 상한선 = IDA 미확정). — Jarvis-AURORA
- **🔎 `v2.26.0` — Monster AI Editor: 누락된 스킬 + "Monster Commands 2" 검색 (MonMagic2 카테고리 = `0x6000`).** 자동화 화면에서 소유자가 요청한 두 가지 사항: (1) 스킬 **검색** (드롭다운 메뉴에 300개 이상의 항목이 있었음) 및 (2) "**Monster Commands 2의 스킬을 찾을 수 없음**" (Multi-Fira 등). (2)의 원인 — **RE 발견:** 연산자의 `performCommand` 이다 `(category<<12)|id`, 그리고 **대문자 nibble은 테이블 선택자입니다** (`FfxCommon_Util.GetGameCategory`/`GameCategory_Enum`): `3`=command.bin (캐릭터), `4`=monmagic1, **`6`=monmagic2**. O `AiCommandId` 3과 4만 매핑했음 → 편집기는 **해당 부분을 인식하지 못했음** `0x6xxx`** (MonMagic2), 코퍼스에서는 **291개 사이트**(보스/에이온)를 사용하고 있음에도 불구하고. 증거: 편집자의 공식 열거 목록 + 코퍼스 히스토그램 (nibbles 3=369 / 4=985 / **6=291** / 5=0; 예: `0x60AB`=Multi-Fira #171) + Firaga의 이전 RT2. **수정:** `AiCommandId` 이겼다 `Monster2 = 0x6000` (`EncodeMonster2`/`DictFor`/`IsCommandOperand`/`AllOptions`) → 이제 MonMagic2 명령어를 **해독하고, 나열하며, 추가 및 제거할 수 있게** 되었습니다; **명령어별 멀티캐스트**(Multi-Fira, 바로 이것입니다)를 해제합니다. 자동화 선택기: 이해하기 쉬운 레이블이 붙은 3가지 카테고리(캐릭터 / 몬스터 1 / **몬스터 2**) + **검색창** (이름 또는 16진수, 예: "Multi", "60AB")을 통해 선택 항목을 유지한 채 필터링할 수 있습니다. 고급 Behavior Library에도 Monster2가 추가되었습니다. Gate `--ai2` 확장: **mon2 rt 247/247**, **MultiFira=True**; `--ai3` **1645개의 액션**을 감지하게 되었습니다(기존 1354개 → +291 = 이전에 보이지 않던 MonMagic2 정확히 해당), 278/278개를 제거합니다. Doc RE: `docs/reverse/FFX_AI_PERFORMCOMMAND_CATEGORY_NIBBLE_2026-06-07.md`. 빌드 오류 0개, 게이트 통과. [이전: `v2.25.0`] — Jarvis-MAGIC
- **🧩 `v2.25.0` — SPHERE GRID CANVAS (v2 VISUAL): 그래프에서 Original/Standard/Expert 편집 + 노드 드래그/연결.** 라이브러리 기반 위에 부족했던 UI (FromExisting + 뮤테이터, 게이트) `--spheregrid-edit-rt0`). 새로운 nav **"Sphere Grid Canvas 🧩"** (Builder v1 옆) → **custom-drawn** 컨트롤 (`SphereGridCanvasView`: `Render` + 포인트

수동으로, 800개 이상의 도형으로 구성된 ItemsControl이 아닌 — 기본 제공되는 그리드에는 약 828개의 노드/848개의 링크가 있습니다). **열기** Original/Standard/Expert (다음 경로를 통해 `ReadLayout`→`FromExisting`, 프로젝트의 abmap 또는 대체용으로 추출된 참조) 또는 **새로 만들기** (처음부터); **노드 드래그** = `MoveNode`, **휠** = 커서 확대/축소, **오른쪽 버튼** = 이동, **+Link** 모드에서 노드 2개를 클릭하면 = `AddLink`, **+노드** 모드에서 빈 공간을 클릭하면 = `AddNode`, **Delete**는 노드를 제거합니다 (`RemoveNode`). 선택한 노드의 측면 패널 (PosX/PosY/cluster/content → `UpdateNode`). **저장:** 사본 `.dat` (레이아웃 + 콘텐츠) 비파괴적, 또는 **프로젝트에 저장** (abmap의 dat0X/dat1X, 프로젝트가 로드되어 있어야 함). 렌더링: 클러스터 = 희미한 영역, 직선/곡선 링크(2차 베지에 곡선을 통한 앵커), 채워진/비어 있는 노드, 선택 시 = 금색 윤곽선. **v1 from-scratch는 그대로 유지**(자체 내비게이션). 빌드 오류 0건; 편집기가 충돌 없이 실행됨. **정직하게 말씀드리면:** WriteLayout은 바이트 단위 정확도(round-trip RT0 검증 완료)를 보장하지만, 게임 내에서 **새로 생성되거나 편집된** 토폴로지를 불러오는 기능은 아직 검증되지 않았습니다(화면에 정직한 경고 배너 표시) — 신뢰하기 전에 게임 내에서 테스트해 보시기 바랍니다. [이전: `v2.24.0`] — Jarvis-MAGIC
- **🤖 `v2.24.0` — Monster AI Editor: 원클릭 자동화 (소프트웨어의 “AI”가 바이트코드를 생성합니다).** 소유자는 비전문가 사용자를 위해, 편집기가 **오류 없이** ATEL 바이트코드를 직접 생성하고 저장 전에 유효성을 검증해 주는 기능을 요청했습니다(이 편집기는 편집에는 훌륭했지만, 처음부터 새로 만드는 데는 형편없었습니다). 모듈 상단에 **"✨ 자동화 (1-클릭)"** 카드가 새로 추가되었으며, **➕ 능력 추가** 기능(마법/능력을 선택할 수 있는 사용자 친화적인 드롭다운 메뉴를 통해 `AiCommandId` + "언제": 항상 / 때때로 1-in-K → AI가 전투 워커와 엔트리포인트를 자동으로 선택하며, 다음을 통해 점프 테이블이 확장됩니다. `AppendGuardedAction`, grow-aware를 검증하고 저장) 및 **➖ 액션 제거** (몬스터가 이미 수행하는 명령어 액션을 이름으로 해독하여 나열하고, 스택 중립 삼중항을 제거 `[alvo][comando][CALLPOPA]` 출처: `Rebuild` + relink, 유효성 검사기가 dangle 문제를 차단합니다). + **"기술 모드 (실제 이름)"** 토글을 통해 목록을 니모닉/원시 16진수로 재표기합니다 (기술에 정통한 사용자를 위해). 자유 편집(AI 어셈블러 + Behaviour Library)은 **변함없이** 고급 모드로 유지됩니다. 순수 로직은 **`FfxLib/Ai/AiAutomation.cs`** (편집자 주 없음, 그대로 `AiCommandId`/`

AiSnippetLibrary`) → testável e gateável. Novo gate **`AiScriptLab --ai3`** prova sobre o corpus (361 m*.bin, 346 c/ script): **add-ability 346/346** + **rng-guard 346/346** (auto-pick valida + re-parseia limpo como grow), **detect 1354 ações / 255 scripts**, **remove 241/241** (Rebuild encolhe exatamente a tríade dropada, re-parseia limpo) + **14 corretamente barradas** pelo validador (algo desvia pra ação). `--ai2` segue PASS. Build 0 erros. **Honesto:** estrutura provada OFFLINE; o **comportamento in-game de uma habilidade ADICIONADA depende de QUAL entrypoint roda por turno — NÃO é byte-provado** (só a estrutura é, 692/692), por isso o auto-pick de entrypoint é heurístico (maior-span), reportado de forma transparente e marcado **experimental/RT2** (confirmar via probe DINPUT8). Multi-cast/multi-alvo/condicionais HP%-turno seguem pendentes (corpus/âncora). [anterior: `v2.23.3`] — Jarvis-MAGIC
- **🐉 `v2.23.3` — 포메이션 에디터: 빈 슬롯에 추가된 몬스터가 이제 “필드에서 생존 중” 플래그를 상속받습니다.** 소유자가 슬롯 04-07에 몬스터를 추가했으나, **이 몬스터들은 살아있는 것으로 인식되지 않았습니다** (오로라 “살아있는 몬스터는 4마리뿐”). 화면상의 증거: 원래 슬롯(00-03)에는 raw가 있습니다 `10DEh`/`10E2h` (**니블 높음 `0x1000`**); 추가된 항목들은 사라졌다 `0030h`/`0136h` (**니블 높음 `0x0000`**). O `0x1000` 포메이션에서 ‘활성’ 상태인 몬스터 플래그입니다 — 작가가 넣었던 `0` 이전에는 비어 있던 자리를 채우면서 `FFFFh`. Fix (`FormationSlotRow`): 빈 슬롯을 채울 때, **해당 배틀의 활성 ‘형제’ 슬롯에서 상위 니블을 상속받는다** (배틀당, 제거 없음; 기본값 `0x1000` (포메이션이 100% 비어 있었다면). 여전히 슬롯 전용 바이트 세이프(gate FormationSlotLab 858/858)입니다. **추가 진단 (저장 버그가 아님):** 저장과 읽기는 동일한 경로를 사용합니다 (`GetPathBattle`); 문제는 ‘금액’이었지, 어느 편이냐는 게 아니었다. **솔직히 말해서:** (1) `0x1000`=‘vivo’는 화면상의 증거에 기반한 가설입니다 — **게임 내에서 테스트**; (2) 오로라 맵에는 **아레나(chunk3)에서 정의한 몬스터 앵커**만 존재합니다(예: 4) — 이 외의 몬스터를 추가하려면 새로운 아레나 앵커가 필요합니다(아레나 제작 = 이번 수정 범위 외). 빌드 0 오류. [이전: `v2.23.2`]
- **🧩 Sphere Grid Builder v2 (기본: 기존 그리드 편집) — 라이브러리 + 게이트, 제외

 csproj.** v1 (`v2.22.0`)는 오직 처음부터 만들었을 뿐입니다; 읽은 모델(`SphereGridLayoutFile` + 항목)은 `init`-only (변경 불가), “원본/표준/전문가” 편집을 잠금. 새로운 기반은 `SphereGridLayoutBuilder`: **`FromExisting(grid)`** 빌더는 각 클러스터/노드/링크를 **필드별**로 복제하여 생성합니다 (다음은 유지됩니다 `Unused*`/`Unknown6`/`RedundantContent` + 실제 헤더 단어 + 콘텐츠 파일의 바이트) — 다음을 통과하지 못함 `Add*` (이 필드의 값을 0으로 초기화합니다). + 변환기 **`UpdateNode`/`MoveNode`/`SetNodeContent`/`SetNodeCluster`/`UpdateCluster`/`MoveCluster`/`UpdateLink`/`RemoveLink`/`RemoveNode`** (색인 재매핑 + 중복 링크 정리 포함)**/`RemoveCluster`**. 편집 = `FromExisting → mutar → Build → WriteLayout`, ~에 대해서는 언급하지 않고 `init`-only. 새로운 게이트 **`--spheregrid-edit-rt0`** (`Tools/SphereGridLayoutEditRt0`, +에서 `offline_ci.ps1`): 3개의 실제 그리드(dat01/02/03)에서 **(1)** 비편집 테스트 `FromExisting→Build` **레이아웃과 콘텐츠**에서 바이트 단위로 동일함, **(2)** `MoveNode` 해당 노드의 **PosX의 2바이트만** 변경합니다(제로 필드 블리드), **(3)** `SetNodeContent`/`RemoveNode` 유효한 왕복; + 코퍼스가 없는 합성 사례 + 범위 외 긍정 포착. 3개 모두 **PASS** (원본 828→제거 시 827개). 경험적: `RedundantContent==contentByte` 828/828 마디; `Unknown6` 0이 아닌 노드당 (보존됨). **솔직히 말해서:** LIB + GATE만 구현된 상태입니다 — **UI(캔버스 + 로드/편집)가 누락되어 있으며**, **편집된 토폴로지를 게임에 로드하는 기능은 아직 검증되지 않았습니다** (오프라인에서 정상 작동한다고 해서 ≠ 엔진이 출시된 적이 없는 그리드를 수용한다는 의미는 아닙니다). 빌드 오류 0개, 3개의 게이트 spheregrid 통과. *(라이브러리 + 게이트, UI 없음 = 문서 전용; csproj 버전 업데이트 없음 — UI가 출시되면 업데이트됨.)* — Jarvis-MAGIC
- **🔄 `v2.23.2` — 오로라: “디스크 전투 재실행”(지도에 다른 모듈의 세이브 데이터를 반영함).** 소유자가 포메이션 에디터에서 포메이션을 편집했는데, 몬스터들이 오로라의 지도에 **표시되지 않았다**. 조사 결과: 파이프라인은 **정상**이며, 오로라가 바인딩된다. `formation slot[i] → monster-live anchor[i]` ~와 함께 `MonsterId`/`Model` (`/work/phyre_chr_anim/models/mNNN/mNNN_animated.gltf`, **340개의 HD 모델이 존재한다**, 서버 루트 URL이 올바름). 원인은 **캐시 상태** 때문이었다: `RefreshCatalog` 장면 목록만 다시 불러오고, 진행 중인 전투의 데이터는 불러오지 않습니다 — 따라서

 외부에서 수행된 구성 작업은 재선택할 때까지 반영되지 않았습니다. 수정: 새 버전 `ReloadSelectedBattle()` (배틀 읽기 재실행 = 디스크의 chunk2 구성 + chunk3 앵커 재읽기) + “렌더링” 옆의 **"🔄 디스크에서 배틀 재읽기"** 버튼. (배틀 익스플로러에는 이미 “Refresh” 기능이 있었으며, 매 내비게이션마다 새로 생성됨 — 이 기능은 이미 그 안에 포함되어 있었습니다.) "Changed: False" + "맵에 몬스터 없음"의 **복합 근본 원인**은 포메이션 저장이 제대로 되지 않았던 것이었음 — **v2.23.1**에서 수정됨 (combo-blank). 빌드 0 오류. [이전: `v2.23.1`]
- **🐛 `v2.23.1` — 포메이션 에디터: 이미 채워진 슬롯에 이제 몬스터 이름이 표시됩니다 (로딩 시 표시 오류 수정).** 사용자는 포메이션의 8개 슬롯 중 이미 값이 설정된 슬롯(raw 10DEh/10E2h)에 대해 콤보박스가 **비어 있는** 상태로 열렸다고 지적했습니다. — 수동으로 선택한 후에야 이름이 표시되었습니다(비어 있는 FFFFh 슬롯조차도 "(비어 있음)" 대신 공백으로 표시됨). 원인: Avalonia의 함정 — `SelectedItem` load(객체 초기화자)에서 설정된 값은 각 행의 ComboBox가 `ItemsSource` (RelativeSource를 통해 바인딩), 그러면 선택이 제대로 처리되지 않아 빈 상태로 남습니다. 수정: 다음을 채운 후 `Slots`, 각 `SelectedMonster` (null→값 전환)에서 `Dispatcher.UIThread.Post(..., Background)` — 그러면 콤보박스가 이미 채워진 Items를 기준으로 다시 정렬합니다. 저장됨: `slotsSyncing` **더티로 표시되지 않도록** 하기 위함(실제 편집이 이루어질 때까지 load는 계속 "Changed: false" 상태를 유지함). 빌드 오류 0개. [이전: `v2.23.0`]
- **🔮 `v2.23.0` — 마법 뷰어(PS3 Magic HD)의 SPELL 이름: join best-effort (소유자가 승인함).** 소유자가 바이트 검증된 가입 없이도 이름을 표시하라고 지시했습니다("이제 진짜로 해야 해", 2026-06-07 — **명시적 오버라이드**를 통해 no-fabricate 규칙을 무시함). 신규 `MagicSpellNameResolver` (FfxLib/Dictionaries): magic_#### (id 0..1023, 12비트) → 시도 `CommandCharacter` → `CommandMonster1` → `CommandMonster2` → `Item` (모두 `Dictionary<ushort,string>`), 반환 `nome ~fonte` (예: `Firaga ~char-cmd`) 또는 `magic_####` 매핑되지 않는 경우. **PS3 Magic (HD)**에서 문제가 발생함 (`Ps3MagicBrowser`): `Ps3MagicEntry.SpellNameDisplay` 목록 제목과 상세 정보 헤더가 바뀌고, 검색은 이름으로 이루어집니다. **솔직히 말해서:** 그 `~fonte` ‘가설’로 분류된 브랜드이며, 바이트 단위로 검증되지 않았습니다(카탈로그에는 “no”라고 기재되어 있습니다).

 "names proved"); 소유자가 화면에서 확인하면, 이름이 잘못된 것이 있으면 오프셋/딕셔너리를 수정합니다. 빌드 오류 0개. [이전: `v2.22.0`]
- **🧩 `v2.22.0` — SPHERE GRID BUILDER (v1, 처음부터): 드디어 UI에서 검증된 라이브러리.** 그리드 토폴로지(클러스터/노드/링크/위치)는 HARD-LOCKED 상태였으며; `SphereGridLayoutBuilder`+`WriteLayout` (게이트 `--spheregrid-build-rt0` PASS)는 화면이 없었습니다. 새로운 네비게이션 **"Sphere Grid Builder 🧩"** (Core Authoring, Sphere Grid Explorer 옆) → 양식 기반: **클러스터 추가 / 노드 추가 / 링크 추가** → 실시간 목록 → **유효성 검사** (라이브러리의 범위 검사) → **빌드 및 저장** (`.dat` 출처: `WriteLayout`, 바이트 안전, 프로젝트 루트 또는 exe 디렉터리에 저장됨). “ZERO의 스피어 그리드 생성”이라는 헤드라인이 드디어 실제로 사용 가능해졌습니다. **v1 솔직한 평가:** 시각적 캔버스 없음(번호로 위치 지정); 기존 노드의 값 편집은 여전히 스피어 그리드 익스플로러에서 진행됩니다. **게임 내 상태 재확인 (질문하신 내용):** o `WriteLayout` 바이트 단위 정확도(라운드트립 RT0 입증됨)이지만, **게임에 새로운 토폴로지를 불러오는 것은 여전히 입증되지 않았음** — 오프라인 안전성 ≠ 엔진이 이전에 배포한 적이 없는 그리드를 수용함(화면에 정직한 배너 표시). 빌드 0 오류. [이전: `v2.21.0`]
- **❓ `v2.21.0` — 네비게이션의 "???" 카테고리: 편집기가 없는 3개의 Wave-1 계열은 이제 읽기 전용 브라우저를 갖게 되었습니다.** 소유자의 요청: **리더+라이터, 바이트 안전성, 게이트 RT0가 검증되었으나 화면이 전혀 없는** Wave-1 계열을 별도의 카테고리에 분류해 주세요. 3개를 찾았습니다(다른 모든 모듈은 이미 배선 완료됨): **`buki_get.bin`** (무기-보물 목록), **`albheddic.bin`** (알 베드 사전), **`battle_script.bin`** (포인터/스크립트 테이블). 내비게이션 끝부분에 새로운 카드 **"???"** (에디터가 없는 웨이브 1) → 버튼 3개 → 일반 컨트롤 1개 `UnwiredCatalog_Control(family)` 파일(워크스페이스 마스터 또는 추출된 참조)을 처리하고 FfxLib의 리더를 통해 읽기 전용 항목을 나열하는 (`BukiGetTreasureCatalog_File`/`AlBhedDictionary_File`/`PointerScriptTable_File`, 디코더 `FfxEncoding.UsDecoder`). 솔직히 말해서: 라이터는 존재합니다(RT0 바이트와 동일하며 편집되지 않음)만, **편집은 이 화면의 범위 밖입니다**. 빌드 오류 0개. [이전: `v2.20.1`]
- **🔌 `v2.20.1` — 비활성화된 “Extras” 탭이 다시 활성화되었습니다: source-root가 추출된 참조를 자동으로 감지합니다.** 소유자는 **Tex

tures (TM2), PS3 Magic (HD), PS2 Models (RSD), PS2 Audio (.wd), Project/Pipeline, Magic Effects 및 Presentation Containers**가 비어 있는 상태로 열렸습니다. 원인: `Project_Service` 해결했다 `Path_FfxPs2Root`/`Path_Ps3DataRoot` 걷다 `master→ffx→ffx_ps2` — 하지만 로드된 워크스페이스는 **Steam-mod master**입니다 (`...\data\mods\ffx_ps2\ffx\master`), 그 `ffx_ps2` 그것들밖에 없는데 `.bin` 수정된 (ZERO 소스 자산)이며, 다음이 없습니다 `ps3data`. 수정: 이제 리졸버는 **알려진 추출 루트**를 우선적으로 선택합니다 (`D:\FFX Extracted\FFX` → `ffx_ps2` + `ffx_data\gamedata\ps3data`, 와 `Directory.Exists` guard + 프로젝트 파생 버전에 대한 fallback + 수동 오버라이드 "Set ffx_ps2 Root..."). 이러한 루트는 읽기 전용 브라우저(8개 모듈) 전용입니다 — **커널 작성자들은 ProjectPath(master)**를 그대로 사용합니다. 이제 8개의 탭이 올바른 참조로 자동으로 채워집니다. 빌드 오류 0개. [이전: `v2.20.0`]
- **🗺️ `v2.20.0` — 편집기 내 내장형 MAP SCENE EDITOR (브라우저 없이): WebView2 표준을 따르는 세 번째 뷰어.** 소유자의 요청("에디터 내부에 Model Viewer Embedded와 비슷하게 만들어 주세요"): 새로운 내비게이션 **"Map Scene Editor 🗺️"** (Spira Forge 카드, Aurora 옆) → `SetModule` 전시회 `MapSceneEditorEmbedded_Control` **편집 가능한 맵 장면 랩**을 호스팅하는 (`RuntimeTools/FFXMapViewerWeb` Jarvis-MAP 레인: **299개 맵**, 클릭 한 번으로 서브메시 선택 + 기즈모 + 머티리얼/조명 패널 + 사이드카 `map-edits.json`) 창 내부의 WebView2 패널에서. **다음의 재사용 `WebView2Host` 공유** (모델 b36 / Magic b37) — 이제 3개의 뷰어가 하나의 임베드 인프라를 사용합니다. 신규 `MapSceneEditorLauncher` (http 8768, Aurora 8765/Magic 8766/Model 8767과는 다름 + 캐시 버스트 + exit 시 파이썬 종료) + `MapSceneEditorEmbedded_Control/DataModel`. 빌드 오류 0건, 편집기가 충돌 없이 다시 실행됨. **조정:** Jarvis-MAGIC이 소유자의 요청에 따라 Jarvis-MAP 레인의 웹을 탑재 중 — 알림은 `SESSION_HANDOFF`. [이전: `v2.19.2`]
- **🗺️ 렌더링 시 HOOK 사양: 렌더링마다 머티리얼→텍스처 자동 기록 (SpecialK의 “Highlight Selected” 기능을 대체) — RE 문서 전용, csproj 변경 없음.** RE 데이터베이스 복사: 최적의 후크 지점 확인 = `FFX_Phyre_BindNamedTextureUnit_DrawTime` @ `0x67DAC0` (RVA `0x27DAC0`), **드로우당 텍스처 단위당 1회**라고도 합니다*

* 플러시 때문에 `FFX_Phyre_FlushTextureUnitBinds_PerDraw` (0x67E990). 프로브용 정확한 레시피: `__stdcall(arg0=slot dst, arg1=descritor)`; **textureKey = ASCII 문자열 `[[arg1+0x94]+0x20]`** (= 정규화된 텍스처 이름 = 파일의 기본 이름) `.dds`우리 익스포터의 /import-path는 1:1로 `Compressed_<CHK>.dds` + PNG 파일 `tex/`); 저렴한 필터 건너뛰기 `FrameBuffer`/`RealFrameBuffer`/`NoTexture`. **정직하게 말하자면:** 바인드 사이트(글로벌 상태에 의해 제어되는 루프)의 엔진에는 FileMaterialId/MeshId/SubmeshId가 존재하지 않습니다. `dword_CCC81C`, (물질적 대상이 아니라) — 정확한 연결 열쇠는 **텍스처의 이름**입니다 (`honest-limit`); 디스크립터 포인터는 중복 제거에만 사용됨; 서브메시별 모호성 해소 = draw 제출 시 두 번째 선택적 후크 (이번 실행에서는 발견되지 않음). 검증된 체인: `0x642560→0x67E990→0x67DAC0→0x6A3240→0x66E680→sub_4D5910`. 데이터베이스 내 이름 변경 및 주석 추가 복사 + `idb_save`. 사양: `docs/reverse/FFX_PHYRE_DRAWTIME_BIND_HOOK_SPEC_2026-06-07.md`. *(RE/lab = 문서 전용, 에디터의 csproj 파일을 업데이트하지 않습니다.)*
- **🗺️ 화면에서 검증된 필드 WARP (probe/ctl — doc/lab, csproj 업데이트 없음): 플레이어를 맵의 임의의 좌표로 실시간으로 순간이동시킵니다.** Verb 구현 완료 `ffxprobectl whereami/backup-pos/restore-pos/nudge/pos/warp` (`RuntimeTools/FfxDinput8Probe/ctl/Program.cs`, 첨가물, 빌드 OK) 및 실행 중인 FFX.exe와 대조 실행 (프로브 `hooked=1`): `whereami` 플레이어의 실시간 위치를 읽습니다 (`inst+0x0C/10/14`, 걷는 것으로 확인됨 = X/Z가 뒤따름), 그리고 `nudge`/`pos` **순간이동 후 딱 달라붙는다** — **할리슨은 화면 속에서 캐릭터가 위치를 바꾸는 것을 확인했다**. 필드 워프 `structural`→**확인됨**. **발견 사항:** 프레임당 리버트가 발동되지 않음 (`inst write + reseat` field-actor 캐시가 없어도 충분하다 — spec §1A의 오프라인 이론을 정교화한다). 이는 고충실도 RenderDoc 캡처의 전제 조건이다(맵 표면까지 이동). 진행 중: 영역 간 `warp <sceneId>`, 표 `sceneId→área`, field-actor 문제 해결. 사양/RE: `docs/ai/FFX_FIELD_WARP_TOOL_SPEC_2026-06-06.md` + `docs/reverse/FFX_FIELD_*_2026-06-06.md`. *(probe/ctl lab/RE = 문서 전용; 편집기의 csproj 파일을 업데이트하지 않습니다.)*
- **🐉 `v2.19.2` — 임베드 수정 사항: WebView2가 패널을 채우고 크기 조정 시 이에 맞춰 조정됩니다(두 뷰어 모두 해당).** 화면에서 WebView2는 임베드

arcado는 화면 한쪽 구석에서만 렌더링되었고(hiDPI 디스플레이에서 약 67%), 주변이 ‘검은색’으로 표시되며 편집기의 크기에 맞춰지지 않았습니다. 원인: `SyncControllerBounds` 곱해졌다 `Bounds × RenderScaling` 그리고 Avalonia는 이미 호스트 창 → **DPI 중복 계산**(~1/scale의 콘텐츠)을 고려하고 있습니다. 수정됨: `WebView2Host` (공유된 내용이니, **Model Viewer v2.19.0과 Magic Viewer v2.19.1을 한 번에** 수정하세요): **부모 창의 실제 client rect**를 기준으로 WebView의 크기를 조정합니다 (`GetParent`+`GetClientRect`, 스케일 계산 없음) + **크기 조정 시마다 재동기화** (`EffectiveViewportChanged` + `ArrangeOverride` 승인됨 `DispatcherPriority.Background` (Avalonia 실행 후 네이티브 호스트를 재설정해야 실행 가능). 빌드 0 오류. 화면 확인 = 사용자의 눈으로 직접 확인. [이전: `v2.19.1`]
- **🪄 `v2.19.1` — 편집기에 내장된 MAGIC VIEWER (브라우저 미사용): v2.19.0의 WebView2를 재사용합니다.** 제안자에게 직접 답변 (“처음부터 편집기 ‘내부’에서 처리하는 게 목표였고, 브라우저를 여는 건 바보 같은 짓”): **“Magic Viewer (Web)”**이 더 이상 외부 브라우저를 열지 않습니다 — 이제 브라우저는 `SetModule` ~를 보여주며 `MagicViewerEmbedded_Control`, **창 내부의 WebView2 패널**. **다음의 재사용 `WebView2Host` 공유**: Model Viewer가 v2.19.0으로 업데이트되었습니다(두 뷰어에 중복 없이 하나의 임베딩 인프라를 제공합니다). 새로운 기능 `MagicViewerEmbedded_Control/DataModel` + `MagicViewerLauncher.EnsureServerAndGetUrl` (로컬 HTTP 서버 8766 + 캐시 무효화 기능을 활성화하고 WebView에서 해당 서버로 접속); **다시 로드** + **브라우저에서 열기** 버튼 (대체 기능). **동기화 (동일한 브랜치 내 2개의 채팅):** 다른 채팅이 커밋할 때까지 기다렸고 `WebView2Host` (v2.19.0)을 정상적으로 사용하기 위해서는 — 손상된 트리가 없어야 하며, 해당 레인의 코드 감사 결과에서 발견된 사항이 `HANDOFF_CODE_AUDIT_HD_MODELS_2026-06-06.md`. **빌드 오류 0건, 편집기가 충돌 없이 다시 실행됩니다.** [이전: `v2.19.0`]
- **🐉 `v2.19.0` — 에디터에 내장된 모델 뷰어(브라우저 없이): 패널 내의 네이티브 WebView2.** 플롯 트위스트 2단계: 816개 모델에 사용된 바로 그 three.js 뷰어가 이제 **에디터 창 내부**의 패널에서 실행됩니다 — ‘추가 기능’ 카드에 새로운 **“모델 뷰어 (내장) 🐉”** 버튼이 추가되었습니다 → `SetModule` 다음과 같이 표시합니다. `ModelViewerEmbedded_Control` **Edge WebView2**를 다음을 통해 호스팅하는 `NativeControlHost` (win32 상호운용성: 자식 HWND + `CoreWe

bView2Controller`, bounds sincronizados em `ArrangeOverride`, HiDPI por `렌더 스케일링`). Usa o **runtime WebView2 Evergreen JÁ instalado** (sem bundle Chromium — nuget `Microsoft.Web.WebView2` 1.0.2592.51, ~poucos MB; **NÃO** o CEF pesado que bumparia ~100MB). O painel sobe o mesmo http server (`ModelViewerLauncher.서버 확인 및 URL 가져오기`, porta 8767, cache-bust) e navega o WebView pra ele; botões "Reload" + "Open in Browser" (fallback). `Program.cs`/AppBuilder **intocado**. **Build 0 erros.** Spike provado num worktree isolado (juiz: compila + 0 warnings novos) antes de trazer pro main. Fase 1 (browser, v2.18.0) segue como fallback. **Decisão do dono junto:** galeria abre no **rest pose LIMPO** (animação opt-in) — paramos o whack-a-mole de animação offline; animação real = mocap depois (fila). Doc `FFX_MODELVIEWER_EDITOR_2026-06-06.md`. [anterior: `v2.18.1`]
- **🔧 `v2.18.1` — 자체 감사: 제(Jarvis) 실수 6건 수정 (두 채팅에 대한 대립적 검토 과정에서 발견되었으며, 각 발견 사항은 다른 담당자가 재확인함):**
  - **Ps3MagicBrowser**: 각 폴더의 첫 번째 텍스처가 UI 스레드에서 동기식으로 디코딩되고 (제가 제거했다고 말한 멈춤 현상) **그리고** 백그라운드에서 다시 디코딩되었습니다 — 이제 row[0]은 백그라운드에서 처리되며, `DecodeRows` 이미 디코딩된 행을 건너뛰고 (더블 디코딩 종료), 그리고 `decodeGeneration` 돌았다 `volatile` (워커↔UI 가시성).
  - **몬스터 AI 편집기**: 헥스 편집 (`AiEditRow`) 또는 AI 어셈블러의 오프코드/오퍼랜드 (`AiAsmRow`) **화면에 표시된 의미를 업데이트하지 않았다** — `AiEditRow` 이제 발사한다 `OnPropertyChanged(Meaning)` 명령어 E의 16진수 설정에서; `AiAsmRow` 돌았다 `ObservableObject` 그리고 Meaning/Label/HasOperand를 알립니다.
  - **OpcodeHelp**: 잘못된 오퍼코드 툴팁 (`StartsWith("PUSHFF")` 결코 결혼하지 않을 터였다; `PUSHF` (float-const가 레지스터 도움말에서 빠졌음) — 다음을 통해 처리되도록 재작성됨 `OperandKindOf` (검증됨), 불안정한 니모닉 접두사 때문이 아닙니다.
  - **MagicViewerLauncher**: 이것이 바로 “Waiting for catalog” 오류의 근본 원인이었습니다 — 파이썬이 실행되지 않았음에도 브라우저를 열고 “성공”을 반환했었죠; 이제 `EnsureViewerServer` bool을 반환하며, 폴링 시간이 ~6초로 늘어났고(콜드 스타트), 실패 시 **정직한 상태**를 반환하며, URL에서 **캐시 버스트**(스텁이 오래된 경우)가 발생하고, **ProcessExit에서 파이썬을 종료**합니다.

** (프로세스가 유출되지 않음).
  *(내 파일에만 적용됩니다. 다른 채팅에서 있었던 실수들은 `docs/ai/HANDOFF_CODE_AUDIT_HD_MODELS_2026-06-06.md` 그분이 확인하고 수정할 수 있도록 — 그의 레인은 건드리지 않았습니다.)* csproj 업데이트.
- **🐉 `v2.18.0` — 편집기 내 MODEL VIEWER (HD): 텍스처가 적용되고 애니메이션이 포함된 816개 모델의 3D 갤러리.** “이건 에디터 내에서 실행되어야 할 것 같다”는 반전이 기능으로 구현되었습니다: ‘추가 기능’ 카드에 새로운 **“모델 뷰어 (HD) 🐉”** 버튼이 추가되어, 이를 클릭하면 `RuntimeTools/FFXModelViewerWeb` (three.js + GLTFLoader)를 localhost HTTP를 통해 제공 (Magic Viewer/Aurora에서 검증된 것과 동일한 방법 — `python -m http.server`, 별도의 **8767** 포트; HTTP는 필수입니다. `fetch()` 카탈로그 + GLTFLoader의 `/work/...`). 이 뷰어는 **애니메이션 갤러리**로, **816개 모델**이 통합된 카탈로그입니다 (`modelviewer-catalog.json`, HD 레인의 베이스라인에서 생성됨 — pc/sum/npc/mon/obj/wep), **카테고리별 필터링 + 평가 + 검색**, 썸네일, 그리고 **애니메이션 클립 재생** (AnimationMixer + 클립 선택기) + 궤도/그리드/와이어/회전/맞춤. HD 시리즈(META 1 + 순수 HD)에서 베이킹된 glTF 파일을 그대로 사용하며 — 재베이킹이 필요 없습니다. `ModelViewerLauncher.cs` (의 복제본) `MagicViewerLauncher`) + [ ]의 버튼 `Main_Window.axaml`/handler. **빌드 오류 없음; 서버 테스트 완료 (카탈로그/index/gltf = 200).** **csproj 업데이트** (실제 UI 기능). **2단계 준비 완료 (책임자 결정):** 동일한 뷰어를 에디터의 WebView 패널에 탑재 (브라우저 없이) — NuGet 패키지 1개 필요; three.js 엔진은 호스트에 구애받지 않습니다. 문서: `FFX_MODELVIEWER_EDITOR_2026-06-06.md`. [이전: `v2.17.0`]
- **🗺️ 맵 씬 에디터 — 뷰어(읽기 전용)가 편집 가능한 랩으로 변경됨 (doc/lab — csproj 변경 없음):** o `RuntimeTools/FFXMapViewerWeb` 독립형 편집 레이어가 추가되었습니다(이후 중단된 SPIRA FORGE가 이를 계승함 — Forge를 실행할 필요도, 통합된 콕핏도, C#으로 재작성할 필요도 없음). **(c0)** three.js **로컬 벤더화** (오프라인, CDN 없이 — `vendor/three/` 589개의 jsm 파일, MIT; importmap은 fallback unpkg가 주석 처리된 위치를 가리킴). **(M1)** **클릭을 통한 서브메시 선택** (`editor/selection.js`): 기증자로부터 복제된 레이캐스터 `aurora-overlay.js`, 안정된 키 체계 `keyOf="meshId:submeshId"`, 워크 모드/포인터 잠금 상태에서 안전함 (+ 가드 `isGizmoEngaged`: 레이스 지즈

mo-vs-국가대표팀 (드래그 전, 비공개). **검증 완료**: **실제 벤더화된 GLTFLoader r165**를 실행하여 `azit00` 실제: 1 메쉬/14 프리미티브 → 14 `THREE.Mesh`, 각각 `geometry.userData.{submeshId,meshId,fileMaterialId}`, 고유 키 14개, 충돌 0건. **(c2/M2)** **사이드카 `map-edits.json`** (진실의 출처, 불변의 glTF에 키별 diff를 재적용 — glTF는 절대로 재직렬화되지 않음; `editor/mapEdits.js` baseline-once + reset + layer; **증명된 항등성** 대 실제three@0.165.0: 1회 적용 == 4회 적용, 형제 요소 유지, localStorage 왕복, 항등성을 갖춘 light) + **gizmo** MIT TransformControls (`editor/gizmo.js`, LOCAL → Y축 아래로 뒤집은 ‘집’을 입력) + **소재/조명 패널** (`editor/materialLightPanel.js`, 클론-온-라이트). **(M3)** 새로운 C# 라이터 **`PhyreDdsWriterLab`**: 왕복 `.dds.phyre` 5개의 실제 샘플(DXT1/DXT5)에서 **바이트 단위 정확도 입증** — ‘decode-only’ 추출기의 역방향; 그리고 **쓰기 방향 판정**: `.phyre` **재기록 가능** — 오프라인에서 MIT roelin 계통을 통해 (유출된 PhyreEngine SDK 제외) — 문서 `FFX_PHYRE_WRITER_FEASIBILITY_2026-06-06.md`. **(M4)** `PhyreModelExportLab` 추가 플래그 획득 **`nodePerObject`** (기본값 OFF: 레거시와 바이트 단위 동일; ON = 서브메시 배치당 1노드/1메시) — 정직한 상한값은 객체 단위가 아닌 서브메시 배치 단위입니다. **(M5)** **객체별 배치 RE CRACKED (오프라인)**: placement = `PNode::m_localMatrix` (PMatrix4 inline, 64B, struct **+0x10** 오프셋); world는 런타임에 순차적으로 생성됩니다. `m_parent` (반사 설명자를 통해 검증됨) `sub_5055B0` + 걷기 `sub_5067C0`, db 복사) + scene-load/material-bind 체인의 RE (`graphicFieldMapLoad`→바인드 코어 `0x65BA20`; 텍스처 애니메이션은 재료에서만 적용 `*Mat_CTA*`). **정직:** **이번 실행에서는 화면상 확인 불가** (프로젝트 규칙: 시각적 진실 = Halyson) — JS 검증: `node --check` + 실제 로더의 하네스 + 상대방 검토; C# 작성: `dotnet build` + 바이트 단위의 왕복 전송. M1/M2 = 데이터 로직이 검증된 SCAFFOLD; 내구성(3b)은 실험실 단계를 따릅니다. 계획: `docs/ai/FFX_MAP_SCENE_EDITOR_20_STEP_PLAN_2026-06-06.md`; 재고 정리: `docs/ai/FFX_MAP_SCENE_EDITOR_BUILD_CLOSEOUT_2026-06-06.md`. *(lab/RE = 문서 전용, 편집기의 csproj 파일을 업데이트하지 않습니다.)*
- **🐉 목표 1 해결됨**

DA — Phyre의 parent-map이 오프라인 상태입니다 (doc/lab/RE — csproj 업데이트 없음): `m_matrixParents` (`PMesh` f44) 바이트 단위 정확도 + 회수된 HD 잔여량의 약 절반.** 코덱스가 제시한 목표 `blocked-by-probe` (parent-map PNode)가 IDA를 통해 추출되었습니다: Phyre 스켈레트의 바이트 단위 parent-map은 **입니다.`PMesh::m_matrixParents`** (`PArray<int32>`, 구조체 오프셋 40 → 파일 링크 **f44**, ArrayLink `@ DataOffset+ObjectsSize+Offset`, root=−1). 출처: `.dae.phyre` == 프로브의 **6/6 바이트 단위** 실시간 캡처 (c001/c004/c005/n042/n054/n043) → **"오프라인 불가능"을 위조** (Codex가 잘못된 필드를 포착함: PNode→PNode, 3-9%). 수정됨 `phyre_chr_gate` (다음 내용을 읽어보세요) `m_matrixParents` (폭발을 유발하던 ~5%의 휴리스틱 대신 실제 값을 사용). **남은 59개에 적용 (리베이크 + 블렌더 QA: 반대 입장의 심사위원 및 회의론자 참여): 16개 클린 + 13개 토션 = 29/59 사용 가능 (49%), 100% 오프라인; 모션 캡처 59→30; 애니메이션 캐스트 사용 가능률 91%→95%.** IDA 코멘트 저장 위치: `0x490330` (사본 `FFX_recon_modellane.i64` + rename-queue). **실시간 모션 캡처 세션(당일)**을 통해 플레이 가능한 에온(Valefor/Ifrit/Anima/Yojimbo/Magus)에 대한 캡처 파이프라인이 검증되었습니다. 그리고 7개의 “고장난 에온”이 **소환 효과/소품 모델**(나무/그림자/데칼)이며, 크리처가 아니라는 사실을 확인했습니다. 게임 내에서 잘 렌더링되었습니다. **6개는 분류에서 제외 → 크리처 잔여량 30→24**. 확인됨: `ffxprobectl spawn 0x30NN` (slot=s-id)는 화면에 어떤 모델이든 표시합니다. 문서: `docs/reverse/FFX_PHYRE_MATRIXPARENTS_OFFLINE_SOLVED_2026-06-06.md` + `FFX_AEON_MOCAP_SPAWN_AND_SUM_PROPS_2026-06-06.md`. **마무리 (PURO-HD 베이크): 잔여량 59→9.** 정적 PURO-HD 베이크 구현 (Phyre 스켈레톤, 리타겟팅 없음) `.chr`): Blender QA에서 잔여 24개 중 **13개 클린 + 2개 토션 복구** (정적), **9**개 남음 (8개 모노 + s013, 대부분 노메시); 애니메이션 캐스트 **91%→98% 사용 가능**. 참고: 15개는 정적 모델입니다(애니메이션 없음 — 순수 HD 모션 패스/모캡 데이터가 부족함). 문서 `FFX_HD_PUREHD_STATIC_RESCUE_2026-06-06.md` + 요금제 `docs/ai/FFX_HD_PUREBAKE_10STEP_PLAN_2026-06-06.md`. *(RE/lab = 문서 전용, 편집기의 csproj 파일을 업데이트하지 않습니다.)*
- **🪄 `v2.17.0` — Magic Viewer 완료 (3레인 병렬 워크플로우): 편집기에 연동된 웹 뷰어 + 세련된 메뉴 + RE의 `root+88` 닫힘:**
  - **La

ne A — 편집기에 연결된 웹 뷰어:** o `FFXMagicViewerWeb` (Codex가 구축한 — Spell Index, Package Graph, Texture Stack, Runtime Evidence, Effect Stage, Crosswalk + 6개의 인덱스/카탈로그)는 **고아** 상태였습니다(에디터에 버튼이 전혀 없음). 새로운 **"Magic Viewer (Web) 🪄"** 버튼 (Extras 그룹, "PS3 Magic (HD)" 옆) + `MagicViewerLauncher.cs` ~에 쓰이는 `RuntimeTools/FFXMagicViewerWeb` 출처: `python -m http.server` (포트 8766, Aurora 8765와는 다름)을 통해 브라우저를 실행합니다 — Aurora/MapViewer와 동일한 방식입니다 (HTTP 필수: o `app.js` ~한다 `fetch()` 카탈로그에서 → `file://` (CORS-hang을 발생시킬 것이다). 경로를 사용하지 않았다 `file://` SpiraForgeHub에서.
  - **Lane B — 다듬어진 마법 메뉴 2개** (읽기 전용, 쓰기 권한 없음): PS2 `Magic Effects` **검색**(패키지/레인 + 커널/레인)과 **정직한 빈 상태**(빈 패널 대신 실행 가능한 메시지) 기능이 추가되었으며, “Counts” 카드가 “Summary”와 중복되지 않게 되었습니다. PS3 `Magic (HD)`: **UI 스레드 외부에서** 썸네일 디코딩 (용량이 큰 폴더에서도 더 이상 멈추지 않음 — 행에 "대기 중"으로 표시되며 다음을 통해 스트리밍됨 `Dispatcher`(구버전 pass에 대한 generation-token 포함), **텍스처 이름으로 검색**, 그리고 Open Folder/Open File 버튼과 함께 `IsEnabled` (더 이상 dead-click이 아님). *(ID로 지정된 주문 이름은 여전히 BLOCKED 상태입니다 — name-table이 존재하지 않으므로, 조인 `magic.bin→magic_####` (원인-결과 관계가 차단된 것이지, 제가 지어낸 게 아닙니다.)*
  - **Lane C — RE의 `root+88` (Pass12, 문서 전용, 실제 데이터베이스에 적용됨) `FFX_recon.i64`):** Pass11의 열린 2개를 닫았습니다. **(1) 런타임 루트를 채우는 대상:** `sub_7FD9A0` (`FFX_Magic_MaterializeRuntimeRoot`) 설치 `FFX_Magic_RuntimeRootTable[0x12A4080]` 부트스트랩(bin-load)에 한 번 들어가면 0으로 초기화됩니다 `root+88`; 각 단계는 테이블을 교체하지 않고 — 동일한 루트를 재사용하며 그 자리에서 변경합니다. **(2) 최종 작성자: `root+88`:** `sub_817200` = **0x21** 오프코드의 핸들러, 위치: `FFX_Magic_OpcodeHandlerTable` (`0xC48EC8`); 가족 내에서 `0x1000` 쓰다 `root+84`=`root+88`=워크카피에서 동일한 커서를 사용하며, 단계가 끝날 때 루트에 쓰기 백업이 이루어집니다. 이름 변경 5회 + 주석 `[pass12]` 적용되어 실제 데이터베이스에 저장됨. Doc `docs/reverse/FFX_MAGIC_ROOT88_WRITER_PASS12_2026-06-06.md`. *(솔직히 말해서: 스펠→구체적인 오프코드, 엔진 정확도의 타이밍, 그리고 라이터에 대한 완전한 커버리지는 여전히 BLOCKED 상태입니다.)*
  - csproj 업데이트 (

실제 UI: 출시 + 마무리). *(C 레인은 RE/문서 전용이지만 동일한 입력란에 입력됩니다.)*
- **🧠 `v2.16.0` — Monster AI Editor가 이제 제대로 작동합니다: 의미 해독 + 스킬 이름 + 필터 (+ 크래시 수정):**
  - **동일한 크래시 문제 해결:** "Monster Commands 1/2"(KernelCommands)를 열면 에디터가 종료되던 문제 — 두 개의 선택 핸들러(`CommandList_SelectionChanged` + `MonsterLinks_SelectionChanged`)는 **null인 지정된 XAML 필드를 `EndInit`** (그리고 로드 시간이 300ms를 넘으면 타임아웃이 발생했습니다). 지금은 `sender` (항상 유효함).
  - **각 명령어는 그 의미를 나타냅니다** (Edit Operands 및 AI Assembler): `CALL 7010`→`Battle.findMatchingChr`, `CALLPOPA 700B`→`Battle.performCommand`, `POPV`→`var[1]`, 점프→`→ jump[n]`. 헬퍼 `AiScript_File.OperandGloss(opcode,operand)` + `OpcodeHelp` (오퍼코드별 툴팁) + 설명.
  - **명령/스킬의 피연산자는 ‘이름’을 표시합니다:** `PUSHII 0x3049`→`⚔ Firaga` (출처: `AiCommandId`/`CommandCharacter_Dictionary`), 더 이상 "12361 [3049h]"가 아닙니다.
  - **명령어 필터:** 이름/니모닉/16진수로 필터링할 수 있는 🔎 검색창(‘Firaga’나 ‘3049’를 입력하면 ~300줄을 일일이 스크롤할 필요 없이 바로 찾을 수 있음) + “X/Y” 카운터.
  - **이름이 표시된 몬스터 목록:** `m004`→`m004 · Mafdet` (다음 방법을 통해 해결합니다 `Monster_Dictionary`, ID에 대한 대체값).
  - 모듈 설명 수정 (이전에는 "read-only"였으나, 편집: Edit Operands + AI Assembler + Behavior Library). csproj 버전 업데이트 (실제 UI).
- **🎨 `v2.15.1` — 몬스터 명령 / 전투 명령 / 아이템: Shop Explorer 표준에 맞춰 속성 편집기를 개편함 (50열 스프레드시트 종료):** o `KernelCommands_Control` **약 50개 열로 이루어진 거대한 DataGrid**에서 빠져나왔다(소유자가 요구했던 그 “엉망진창인 속성”, 비표준인 `FFX_EDITOR_UI_CONVENTIONS.md`) **카드 상세 정보** 표준 형식: 왼쪽에 명령어 목록, 오른쪽에 그룹별 카드(Identity/Animations/Menu/Characters-Targeting/Costs/Attack Data/Element)가 표시된 상세 패널, **플래그가 WrapPanel 내의 체크박스로 변경됨** (80열 대신 가독성 향상), 용량이 큰 그룹(Properties, Status chance/duration, Status Special/Buffs, Extra)은 **접힌 Expander**로 처리되며, "Where Used / Monster Links"는 세 번째 열에 그대로 유지됩니다. **편집 가능한 필드가 하나도 누락되지 않음** (열별 diff)

아니요; Name/Description만 읽기 전용으로 유지됩니다(세터 없이 디코딩된 게터입니다). 핸들러/이벤트/공개 메서드는 그대로 유지됩니다(Save/Undo/Discard/LoadIngame, 필터, OpenMonsterRequested, RestoreViewState). 빌드 오류 없음, 0개. *(에이전트가 격리된 워크트리에서 수행, 빌드 결과 녹색까지 완료, 그대로 적용.)* csproj 업데이트 (실제 UI).
- **🖱️ `v2.15.0` — Aurora DRAG-TO-PLACE + 스탠딩 맵 (플립) + 드래그 가능한 패널 (개발자가 VIVO에서 확인):**
  - **드래그 앤 플레이스:** MapViewer에서 "Place mode" → 몬스터(구)를 평면 위로 드래그 → 놓기 → 새로운 좌표가 에디터로 돌아오고, **"💾 위치 저장"** 버튼(에디터 **E** 및 오버레이 내부)이 `.bin` **byte-safe** 배틀의 (다음에 위임함) `BattleArenaPositionWriter` 검증됨; X/Y/Z만 변경되고, W는 유지되며, 백업 `.aurora.bak` (자동). 생존 확인: `azit03_00` 단, chunk3의 위치 배열에서만 diff가 발생합니다.
  - **웹 채널→에디터 (누락되었던 부분):** `AuroraDragBridge` — `TcpListener` **운영 체제가 선택한 포트**에서 (아니요 `HttpListener`/고정문: 떼를 지어 몰려든 `python -m http.server` 문 앞에서 쪼그려 앉기 + `HttpListener` (urlacl/admin 필요). 최소 HTTP/1.1 (CORS + `POST /drag` + `POST /save`); 해당 페이지는 딥링크를 통해 뷰어로 이동합니다 (`&drag=<porta>`). 새로운 게이트 `--dragbridge-selftest`: POST→버퍼→읽기 왕복 **PASS**.
  - **`Battle_File.WriteWithMonsterPositions`** (포메이션 작성 1단계) — 누락된 포지션 입력, 미러링 `WriteWithFormationSlots`.
  - **거꾸로 된 맵 수정됨:** Phyre 지오메트리는 Y-down인 반면 glTF/Three.js는 Y-up → 지오메트리 **및** 앵커 그룹에서 X축을 기준으로 180° 회전 (원점이 동일 → 정렬됨). 드래그 플립에 구애받지 않음 (`group.worldToLocal`).
  - **오버레이 UX:** 제목 표시줄을 통해 **드래그 가능**한 “🌅 Aurora 오버레이” 패널 + 각 컨트롤에 표시되는 **툴팁**.
  - csproj 업데이트 (Aurora에서 활성화된 UI 기능). 게이트 `--kernelcmd-roundtrip`/`--dragbridge-selftest` 문서 전용으로 남습니다.
- **🐛 `v2.14.3` — Monster Commands(monmagic) 실행 시 크래시, 종료 + 워크스페이스 지속성 + Aurora 내 이름:**
  - **크래시:** "Monster Commands 1/2"를 실행하면 에디터가 종료됨 (NPE 발생) `Ability_Command.WriteList`→`WriteBytesIntoTextFile`, 이미 `BuildFile()` (시공사의).

 **근본 원인:** 모델의 이름이 변경되었습니다 `UnusedText1/2*`→`JapaneseOnlyText1/2*` + 에서 우승했다 `Original*Offset` (preserve-only v2.14.1)이지만, **UI 래퍼** (`KernelCommands_Wrapper`, `MonsterStatSheet_Wrapper`)에는 기존 이름이 그대로 남아 있고 오프셋은 제거되었습니다 → `PropertyUtil.CopyProperties` **이 필드들을** `Wrap`/`Unwrap` → null로 변환됨 → preserve-only가 실패하고, append-rebuild로 넘어가면서 monmagic의 빈 JP-only 필드에서 NPE가 발생했습니다. **수정:** 두 래퍼에서 전체 라운드트립 수행 (이름 변경 + `Original*Offset`) + `FfxEncoding.WriteBytesIntoTextFile` null-safe. **새로운 게이트** `--kernelcmd-roundtrip`** (`Tools/KernelCommandRoundtripRt0`) GUI의 정확한 경로를 확인합니다 (`ReadList→Wrap→Unwrap→WriteList`) **바이트 동일 4/4** (command/item/monmagic1/2) — 이것이 `AbilityCommandLab` (직접 경로) 구조적으로는 보이지 않았다. Wired에서 `offline_ci` → **26개 게이트 통과**.
  - **워크스페이스 지속성:** 폴더 `master` 업로드된 파일은 다음 위치에 저장됩니다. `%LocalAppData%\FFXProjectEditor\last-project.txt` 그리고 **시작 시 자동으로 복원됨** (우선순위: CLI 인자 → 가장 최근에 로드된 항목 → 기본값). 한 번만 로드하면 영구적으로 기억되며, 기본적으로 더 이상 Steam-mod로 전환되지 않습니다.
  - **전역 크래시 로거** (`%LocalAppData%\FFXProjectEditor\crash.log`, 출처: `Utils/CrashLog`) + 수비적 부하가 `KernelCommands` (앱을 종료하는 대신 설명이 포함된 빨간색 오류 메시지).
  - **오로라 챔버:** 몬스터의 앵커에 이제 **이름**이 표시됩니다 (`🔴 <nome>`) 대신 "monster (live)" (`_currentLineup`→`AuroraAnchorRow`).
  - 문서만 확인하는 동승: `docs/governance/FFX_EDITOR_UI_CONVENTIONS.md` (패널 레이아웃 = Shop Explorer, 50열 DataGrid 아님) + DINPUT8 규칙 철회 (프로브 없음) + 체크리스트에 다국어 메모/MagicViewer 추가. csproj 업데이트 (UI 기능).
- **🈶 `v2.14.2` — BattleTextExplorer에 JP 글꼴이 추가되었습니다(진짜 한자, 더 이상 `<MISS>`) + 새로운 게이트 2개:** o `BattleTextExplorer_DataModel.ReloadSources` 지금 다운로드 중 `jppc/battle/kernel/btl_txt.bin` ~와 함께 `JpDecoder` — 2바이트 크랙(v2.14.0)의 가시적인 성과. 새로운 게이트를 통해 **헤드리스 모드에서 검증됨** `--btltext-jp-decode` (`Tools/BtlTextJpDecodeRt0`): JP `btl_txt.bin` = 128개 항목 / 451단어 → **44개의 한자**가 포함됨 `<K:n>` (은행 `base.ftc`), **0 

`<MISS>`**, 그리고 **왕복 무손실 451/451** (디코딩→인코딩==바이트). 현실이 추측을 정교화했다: **전투** 관련 텍스트는 일반 데이터베이스만 사용한다 `<K:n>` (없음 `<FTCX>`/`F2`/`F3`/`F5` — 이는 이벤트별입니다). **유령 버그 수정:** 플래그 `--btltexttable-rt0` 는 헤더에 다음과 같이 공지되었는데, `BtlTextTableRt0.cs` 하지만 **한 번도 wired에 실린 적이 없다 `Program.cs`** — 백그라운드에서 실행하면 GUI(WinExe, stdout 0)로 넘어가면서 "출력 없이 종료"되었습니다. 현재 와이어드(기본 JP, 언어 폴백): JP **PASS** (3982/3982) + US **PASS** (1910/1910). `--wave1-rt0` 다음은 **12/12 PASS**입니다; `--btltext-jp-decode` wired no `offline_ci.ps1` → **25개 게이트 통과** (이전에는 24개였습니다). *(2개 게이트는 문서 전용이었으며, csproj 파일의 변경은 탐색기 UI의 JP 소스에서 비롯된 것입니다.)*
- **💾 `v2.14.1` — MonMagic Save가 바이트 안전(byte-safe)이 되었습니다(드리프트 현상이 발생하던 마지막 라이터가 제거됨):** o `Ability_Command.WriteList` **preserve-only** 모드가 추가되었습니다: 읽기 시 텍스트 풀의 원래 오프셋을 캡처하고, 텍스트 편집이 없는 저장 시 **원본 풀을 그대로 재출력**합니다(각 스크립트를 원래 오프셋에 배치 → 공유된 문자열, 예: monmagic의 여러 빈 필드들이 모두 오프셋 0에 위치하며, 중복되지 않고 공유됩니다). 재읽기를 통한 검증: 편집으로 인해 스크립트의 크기나 내용이 변경된 경우, 평소와 같이 추가(append) 방식으로 처리됩니다. 이를 통해 **명령어/항목을 손상시키던 중복 제거(dedup)** 없이 monmagic의 드리프트 문제를 해결합니다 (앞서 반박된 바 있음). 게이트 `AbilityCommandLab`: **command/item RT0 4/4 + monmagic RT0 4/4** (이전에는 0/4 드리프트였음) + 모든 곳에 위치한 1-flag-edit; **monmagic이 CERTIFIED로 승격됨** (드리프트가 이제 게이트를 통과하지 못함). `offline_ci` PASS. csproj 수정 (커널 편집기의 저장 기능이 이제 monmagic에 바이트 단위로 정확히 반영됨).
- **🈶 `v2.14.0` — JP 텍스트 디코더는 2바이트 한자를 읽습니다 (오늘의 크랙 성과):** 무손실 코덱 `FfxEncoding` 이제 **2바이트 소스 리드**를 인식합니다 (`0x06`/`0x26-0x2F`, 다음에서 합격한 `docs/reverse/FFX_EVENT_TEXT_ENCODING_CRACKED_2026-06-06.md`) 그리고 **읽을 수 있는 글리프 참조**를 표시합니다 — `<FTCX:n>` (행사 한자), `<K:n>` (한자: `base.ftc`), `<F2/F3/F5:n>` (기타 은행) — 대신 `<C..>`+`<MISS>` 앞서 언급된 왜곡 현상. **100% 대칭 인코더** (토큰↔정확한 바이트). 새로운 게이트 `--jptext-rt0` 이벤트 코퍼스 내의 예시 (367번부터

파일, **18,935개의 JP 스크립트, 15,467개는 2바이트 글리프 포함**): **글리프 드리프트 = 0** + **항등적인** 코덱 (기존 문자 별칭은 1회 정규화 후 안정화됨 = 안전함; no-edit는 원래 바이트를 그대로 반환함). 이는 직접적으로 `BattleTextExplorer` (무손실 형식을 사용하세요). `offline_ci` = **23개 게이트** 통과. **csproj 붐프** (UI에서 용량 확인 가능).
- **🧱 ZERO의 Sphere Grid BUILDER + 검증기 (오프라인 검증 완료 — csproj 업데이트 없음: 라이브러리 + 게이트, UI 없음):** `SphereGridLayoutBuilder` (`AddCluster`/`AddNode`/`AddLink` → `Build()`)는 메모리 내에 전체 그리드를 구축하여 `WriteLayout` 검증됨, **범위 검증기** 포함 (`Validate()` 범위를 벗어난 링크/클러스터를 거부함 → 게임을 중단시키는 파일을 절대 전송하지 않음). 새로운 게이트 `--spheregrid-build-rt0` (`Tools/SphereGridLayoutBuildRt0`) 테스트: build→WriteLayout→ReadLayout **동일한 구조** + **두 번째 통과 시 바이트 동일** (이멱적 직렬화) + 유효성 검사기의 **positive-catch** (범위를 벗어난 인덱스를 가진 그리드는 거부 + `Build()` (발사). 이는 “스피어 그리드를 제로에서 창조하기”의 절반에 해당하는 창작 과정입니다 (그 `WriteLayout` (시리얼라이저의 절반이었습니다). **CI: 22개 게이트** (에디터 내부 15개 + 랩 7개). 나머지 기능의 사양은 `docs/ai/FFX_UNLOCKED_FEATURES_DESIGN_2026-06-06.md`.
- **🌐 Sphere Grid LAYOUT/TOPOLOGY 작성기 (오프라인 검증 완료 — csproj 변경 없음: 라이브러리 + 게이트, 아직 UI 미포함):** `SphereGrid_File.WriteLayout` 메모리에 있는 모델의 그리드 전체 토폴로지(헤더 + 클러스터 + 위치가 지정된 노드 + 링크)를 다시 직렬화합니다. 이를 통해 **"ZERO에서 스피어 그리드 생성"** 기능이 잠금 해제됩니다(이전에는 노드 값만 편집 가능했고, 토폴로지는 HARD-LOCKED 상태였습니다). 새로운 게이트 `--spheregrid-layout-rt0` (`Tools/SphereGridLayoutRt0`) dat01/dat02/dat03(Original/Standard/Expert)의 편집 불가 바이트 식별 테스트 — read→WriteLayout==original. **확장된 CI:** `offline_ci.ps1` 이제 편집기의 14개 내부 게이트가 작동합니다 (`--wave1-rt0`+12 + `--spheregrid-layout-rt0`) 7개의 랩 외에 = **21개의 게이트 통과**. **바이트 보존 리팩토링** (게이트 그대로 유지): 헬퍼 `AppendTextScript` 추출됨 (표준에서 중복 제거됨, `Ability_Command`+`Monster_StatSheet`) + 이름 변경 `UnusedText1/2*`→`JapaneseOnlyText1/2*` (시험지 `FFX_REPO_ARCHAEOLOGY`; BinaryMapper는 오프셋 기반이므로 ⇒ RT0-safe). + 문서 

`docs/reverse/FFX_EVENT_OFFLINE_DECODE_PASS_2026-06-05.md` (정적 디코더 EV01) + `PORT_STATUS`/`RUNTIME_TOOLS_INDEX` 최신 정보.
- **`v2.11.0` — 🧠 상용화된 AI 어셈블러 (실용적인 괴물급 AI 편집기):** 코덱의 “100% 자유로운 AI
  편집” 기능이 정식 기능으로 추가되었습니다. 레인 관련 새로운 소식 `FfxLib/Ai` + `Modules/MonsterAiEditor`:
  - **행동 라이브러리** (`AiSnippetLibrary`): 매개변수 설정이 가능한 템플릿으로, 그 바이트는
    코퍼스에서 검증된 언어들을 반영합니다 — 선형 (`force-cmd`/`perform-cmd`/`grant-field`/`set-stat`/`raw-call`)
    및 조건부 (RNG 1-in-K 순환, 카운터/페이즈 “이벤트 발생 시 명령 강제”).
  - **프리플라이트 검증기** (`AiValidator`): opcode∈48, HasOperand vs 0x80, **고아 분기/진입점**
    (불투명한 throw 대신 구체적으로 어떤 것인지 표시), 피연산자 범위, RT0 자체 점검, 재구축 드라이런, 확장/축소;
    `SaveAssembler` 수비적인 태도를 보였다 (블로킹 실수).
  - **사용자 친화적인 명령 선택기** (`AiCommandId`): performCommand 연산자 ↔ 이름 via `(cat<<12)|id`
    ~에 관하여 `CommandCharacter/CommandMonster1_Dictionary`; UI의 드롭다운 메뉴 (더 이상 원시 16진수 값이 아님).
  - **새로운 코덱 기본형** (`AiScript_File`): `GrowWorkerJumpTable` (워커의 점프 테이블에 슬롯 추가
    — 새로운 분기 활성화) + `AppendGuardedAction` (저장된 액션을 엔트리포인트에 미리 추가하면서
    핸들러를 유지) + `OperandKindOf`.
  - **UI**에서 `MonsterAiEditor`: 카드 동작 라이브러리 + ‘Validate’ 버튼/보고서 + 명령 드롭다운.
  - **Gate `AiScriptLab --ai2` PASS** (실제 코퍼스 361): jump-grow **898/898 워커**, guarded-action
    **692/692** (첫 번째+마지막 엔트리포인트) + 합성 센티넬 1/1, 유효성 검사기 클린 346/346, AiCommandId
    620/620, positive-catch 8/8/8 (편집기 경로를 통한 jumpOOB). `--` 원본 RT0 **361/361 무결**.
  - 적대적 검토(4명의 검토자)에서 2개의 버그(one-past-end 센티넬 루프)를 발견하고 수정함; `OperandKind`
    (에디터 저장 파일에 드롭됨), 게이트에서 멈춤. 문서: `docs/reverse/FFX_AI_JUMPTABLE_GROW_PROVEN_2026-06-05.md`
    + `docs/ai/FFX_AI_ASSEMBLER_PRODUCTIZED_2026-06-05.md`.
  - ⚠️ 오프라인에서 검증된 구조; **게임 내 동작(RT2)은 Halyson의 승인을 기다리는 중** (테스트). 템플릿
    "HP 25% 미만 아군 치유" 및 "t에서 분노 발동"

N번 우편함: 배송되지 않음 (바이트 부족 - HP 필드/카운터 확인 필요).
- **🐉 HD 모델 레인 — 텍스처 적용 및 베이크 처리된 캐릭터/NPC + 시각적 QA (문서 전용, 범프 없음):** §7.2/§7.4의
  `SUCESSOR_FFX_HD_MODELOS_MASTER_2026-06-05.md` sum/npc에 대해 닫힘.
  - **텍스처 (매니페스트 기반):** `extract-texture-batch` 에서 `RuntimeTools/PhyreModelExportLab` 이겼다
    **`--from-manifest`** 다음을 읽는 `g_fileNames[]` ~의 `<id>.ahwin32` (= 공식 자산 매니페스트)를 통해 게임이 불러오는
    정확한 텍스처를 추출합니다. **305개의 PNG 파일** (PC/NPC/서머), 출처 지도 `texture-provenance-map.json`,
    **0개의 무음 불일치**. RE: o `ahwin32` 읽기 쉬운 C 헤더입니다 — 상호 참조를 해결합니다 (`c906←c106`,
    `c908←c108`, `c806←c805`) 그리고 다양한 질감 (`c101+c101_01`, `n238+n238_hair`, `n356←n238_hair`) 왕복이 아닙니다.
    보너스 발견물: NPC의 장비 상속 키 = `0x6NNN` 에서 `.chr` (nXXX→kNNN 매핑, 222/222 유효).
    문서 `docs/reverse/FFX_AHWIN32_ASSET_MANIFEST_2026-06-05.md`.
  - **Bake (메쉬+텍스처+애니메이션):** 드라이버 `work/_scratch_mgrp/bake_cast.py` 출처: `phyre_chr_gate`. **정적
    253/253** (전체 캐스트에 텍스처 적용, 깨끗함). 애니메이션: 자체 이동 합산, NPC 상속 `skl/<base>`.
  - **시각적 QA (워크플로우, 시각 검사 담당자 21명):** F3D를 통해 선별된 애니메이션 248개 — 157개 정상 / 58개 뒤틀림 /
    33개 분해. 33개 모델의 바인딩 피커(rest/A1)는 수정되지 않았습니다.
  - **🔧 Blender를 통한 수정 (2026-06-06): F3D가 스키닝된 애니메이션에서 잘못된 결과를 보여주었습니다.** Blender 진단 (메쉬
    `EXPLODE_RATIO≈1.0`, 성장하지 않음) + 정확한 렌더링 (이브이)을 통해 “폭발한” 캐릭터들의 **신체는 온전**하며, 단지
    사지나 액세서리만 늘어난 것임을 입증했다. 재QA (Blender 렌더링에 대한 8명의 에이전트) **수정 결과: 175 clean (71%) / 59
    토션 (24%) / 14 익스플로디드 (6%)**로 수정 — **20개 모델 복구**, 오프라인 베이크는 항상 **~94% 사용 가능**했습니다.
    14개의 정품 모델 = **11개의 Aeons + 3개의 NPC** (비휴머노이드 리그; 모션 캡처/RE 부모 맵 필요). 업데이트된 규칙: **
    블렌더 화면이 결정하며, F3D는 틀렸다**. 파이프라인 `work/_scratch_mgrp/blender_{diagnose,render_anim,batch_render}.py`.
  - **🎯 리타겟팅 문제 해결됨 (다음 경로를 통해) `--retarget-delta` (2026-06-06): 175→215 클린 (87%).** 새로운 플래그가
    `phyre_chr_gate` 상속받은 모션을 **델타**로 적용하는 

NPC**의 REST에 대한 frame0 (`M=restLocal·inv(m0)·mf`),
    기지의 비율을 강제로 적용하는 대신 NPC의 비율을 유지합니다. RE는 (IDA)를 통해 리맵핑이 `.chr@0x30` 이미
    적용된 상태였습니다 — 원인은 **retarget rest-pose**였으며, remap이 아니었습니다 (문서 `FFX_INHERITED_MOTION_REMAP_RUNTIME_2026-06-06.md`).
    파일럿+배치 73개 실패 + Blender 재-QA + **모델별 최상 결과 유지**: **+40개 정상, 44개 복구, 회귀 0건**
    (1개는 회귀할 우려가 있어 제외). **애니메이션 적용된 NPC = 200/222 클린 (90%), 0개 폭발**; **8개의 Aeons**가 폭발한 상태로 남아 있음
    (메시 면역 → 모캡). A1의 위험 없이 MASTER §2.4의 "A1-universal" 문제를 해결합니다.
  - **🐉 전체 출연진 오프라인 확정 (2026-06-06): 498/643 클린 (77%), 90% 사용 가능.** 나머지 대상(obj/wep/pc)에 대해 QA-Blender-fiel +
    retarget-delta + keep-best를 적용: 46 클린/55, 파티 클린. 그리고 **340마리의 몬스터**. 기존의
    몬스터 QA(bbox)는 "0 폭발"이라고 표시되어 있었으나 = **거짓**; Blender 충실 QA(29개 에이전트)에서 **127개의 실제 오류**를 발견;
    상속된 66개에 retarget-delta 적용 → **36개 승격**, 몬스터 206→**237 클린**. **애니메이션 총합 (643): 498 클린 /
    86 토션 / 51 폭발 / 8 블랭크.** 잔여물 (9%) = 메쉬 불일치/바인드 퇴화 → 모캡/RE-메쉬, 리타겟팅 불가.
  - **obj/wep/pc (2026-06-06):** 동일한 확장 파이프라인 — static **obj 110/110 + wep 79/79 + pc 34/49**
    (15개 pc 오류 = 더미 슬롯) `c8xx` ~ 없이 `.chr` PS2). **전체 HD 캐스트 정적 모델 = 476개.** obj/wep은 거의
    모두 리지드 모델 (애니메이션은 드물게 25/7); 화면 무작위 점검: f001/w001/c004=Auron 깨끗함.
  - 갤러리 `work/cast_hd_gallery.html` (모델 뷰어, 정적/애니메이션 전환, 합계/NPC/오브젝트/무기/PC 필터). 모두
    `work/` (gitignored): 명령어만 코드로 간주됩니다. **csproj 버전 번호 변경 없음** (RuntimeTools의 lab/RE).
- 등록 문서 `docs/ai/FFX_TOOLBOX.md` 생성됨 (생존 등록 §11의
  `FFX_TOOLBOX_DISCOVERY_PLAYBOOK_2026-06-05.md`): **온라인** 스캔 +
  FFX HD/PS2 외부 도구 라이선스 검증 (VBF, Phyre, 커널 `.bin`, ATEL, FMOD,
  TM2, FMV) 및 편집기의 NuGets. 거부된 주요 결과: **External File Loader
  (ffgriever, BSD-2)** 재패키징이 필요 없는 loose-file, **Kaitai Struct** (런타임 C# MIT)를 이용한
  C#+JS 리더 생성, **fahrenheit** (MIT, C#) 모드 프레임워크 c

hook+DLL, 그리고
  **FFXDataParser가 라이선스가 없음(연구용)**이라는 확인. 열 `testado?`
  아직도 `❌` — 코퍼스 대조 테스트(오라클) 미완료, 해당 문서에 계획 기재됨. 문서 전용:
  **csproj 업데이트 없음** (lab/RE 문서 전용 규칙).
- FFX HD/PS2의 대용량 검색을 위해 2026-06-02 신규 릴리스가 통합되었으며,
  툴링은 읽기 전용으로 설정되었고 Claude/Codex로 인계됨:
  - `Ps3MapViewerLab` 목록화하다 `ps3data\map`/`btlmap` 그리고 첫 번째
    영역/슬라이스 스캔을 생성했으며;
  - `PhyreMapExportLab` 열렸다 `map/azit/azit00` 정적 glTF로, 그 후
    연결됨 `.dds.phyre` PNG 텍스처 후보로;
  - `FFXMapViewerWeb` orbit/walk/no-clip 기능이 포함된 로컬 Three.js 뷰어로 변경되었으며,
    manifest/export/validator 패널과 기본 텍스처가 적용된 타깃이 포함되었습니다;
  - `PhyreSkinnedAnimExportLab` 스킨 처리 및 애니메이션이 적용된
    몬스터의 프론트 익스포트를 기록했으나, 증거 자료 외에는 별도의 자료나 애니메이션을 제공하지 않았습니다;
  - `ReverseHarness`, `SphereGridRuntimeProbe` 그리고 `SphereGridRt2Lab` 다음과 같이 생성했습니다.
    PS2/Sphere Grid/런타임 검색용 읽기 전용 게이트.
- 다음 `azit00` 이제 검증된 텍스처 패키지가 있습니다:
  - `static-debug.gltf`, `static-textured.gltf` 그리고
    `static-textured-vertex-color.gltf`;
  - 14개의 프리미티브, 4,896개의 정점, 1,632개의 삼각형;
  - 7개의 3D 루트 텍스처 `.dds.phyre` PNG로 디코딩되어 다음을 통해 연결됨
    `fileMaterialId` 후보;
  - 텍스처가 적용된 타깃에서 glTF-Validator 오류 0개/경고 0개;
  - F3D 및 Three.js를 로딩/렌더링에 대한 외부 테스트로 사용.
- IDA 평면/Phyre 소재 `azit00` 이제 10단계로 구성된 경로를 기록하여
  입증한다 `PMaterial`/`PParameterBuffer`"실제 게임 소재" 바인딩을 호출하기 전에
  실제 텍스처 슬롯.
- 맵 파서/익스포터는 이제 `phyre-link-dump.json` 그리고
  `phyre-string-index.json`; 첫 번째 구조적 소견은 다음과 같다
  `PMaterial 0..13 -> PParameterBuffer 12..25` 그리고 텍스처 슬롯 표시가
  `PParameterBuffer.parentFieldOffset=172`.
- `azit00` 이제 Phyre의 링크 테이블을 통한 비교 바인딩도 지원됩니다:
  - 신규 `material-slot-analysis.json`;
  - 새 `static-textured-phyre-slots.gltf` 및 변형
    `static-textured-phyre-slots-vertex-color.gltf`;
  - `PMesh.parentFieldOffset=52 -> PMat

erial 7..13 ->
    PParameterBuffer 19..25 -> field172 -> sharedDataId 10..16`;
  - 명시적 연결 `sharedDataId 10..16 -> root texture slot 0..6`;
  - 14/14 개의 서브메시가 다음으로 연결됨
    `bound_by_pmesh_pmaterial_pparameterbuffer_field172_candidate`;
  - glTF-Validator 0/0, F3D nonblank 및 Three.js (메시 14개/마테리얼 14개
    텍스처 적용/버텍스 4,896개);
  - 아직 **아니다** `engine_exact_material`; IDA는 승격 전에 필드 172와
    셰이더 매개변수를 확인해야 합니다.
- 2026-06-02일자 IDA/런타임 조사가 이제 버전 번호 없이 문서화되었습니다.
  게임 바이너리:
  - 인덱스/오라클 `.mgrp` 에서 `docs/reverse/mgrp_oracle_2026-06-02/`;
  - MGRP 및 Sphere Grid용 IDA 프로브 스크립트;
  - 프로모션/미확인 항목 계획 `docs/reverse/WRITER_PROMOTION_GATES.md`.
- 마스터 패키지 `DOSSIÊ FFX 01-06-2026` 이제 다음 항목과 통합되었습니다:
  - `58` 묶음 파일;
  - 묶음별 명세서;
  - 버전 관리된 Git-safe 사본은 `docs/history/DOSSIÊ FFX 01-06-2026/`;
  - GitHub의 제한으로 인해 차단된 초대형 외부 바이너리에 대한 제외 보고서.
- 드디어 통합된 방대한 양의 문서 `Pt2..Pt45`, 다음을 포함:
  - 워크숍 분야별로 구분된 기초 자료;
  - 통합 마스터 아틀라스;
  - `KNOWLEDGE_BASE.md` 루트를 유일한 진입점으로;
  - 통합된 공식 병합 계획;
  - 위성 파일 첨부 `Pt6/Pt9`;
  - 프로젝트의 공식 기술 분야.
- 캠페인 `Pt50..Pt58` 이제 공식적인 흡수 계획도 마련되었습니다:
  - `merge em docs`
  - `Extras agora`
  - `Extras depois`
  - `research congelada`
  - `limpeza historica`
- 캠페인 기획에는 이제 두 가지 원시 자산 트리가 모두 포함됩니다:
  - `ps3data`
  - `ffx_ps2`
- `Pt6` 이제 공식적인 일시 중단 패키지도 추가되었습니다:
  - 경영진 정리
  - 자회사 개요
  - 런타임/AI 아틀라스
  - 후속 버전 부트스트랩
- 캠페인 `Pt52..Pt58` 이제 공식 발표도 나왔습니다:
  - 성숙도 요약표
  - 판정 결과 `Extras agora`
  - ~의 판결 `Extras depois`
  - `research congelada`
  - ~에서 유래한 종이 `Pt67`
- `Pt50` 그리고 `Pt51` 이제 공식 기록 삭제 기능도 추가되었습니다:
  - split `ps3data` vs `ffx_ps2`
  - 원산지 규정집
  - 패싯 

인용 의무
- ~의 후속 기관 `Pt6` 에서 실제 코드의 첫 번째 단계를 밟았다 `LiveBattleLab`:
  - 수락 계약서 `Pt47/Pt48` 드디어 실행 가능해졌다 (표면 읽기 전용
    de `Ptr_script_*` + 자연 캡처 데이터의 CSV 내보내기(코호트/틱/라벨 포함);
  - 오리진 추적 기능을 통해 해당 아티팩트 내에서 자연 캡처와 벤치 리플레이를 구분;
  - 클레임 상한선 **변경 없음** (`structural dispatch/VM watch candidate`);
  - 자세한 내용은 `docs/history/LIVEBATTLE_CONTRACT_WIRING_2026-05-31.md`.

### 추가됨
- `RuntimeTools/Ps3MapViewerLab/` ~의 읽기 전용 카탈로그 작성자로서
  `ps3data\map`/`btlmap`.
- `RuntimeTools/PhyreMapExportLab/` 지도용 별도의 Lab 파일을 내보내는 방법
  Phyre HD, 매니페스트, 디스크립터 리포트, glTF 디버그, 텍스처가 적용된 glTF 및
  텍스처 바인딩 리포트가 포함된 파일.
- `RuntimeTools/FFXMapViewerWeb/` 파일럿용 정적 Three.js 뷰어
  `map/azit/azit00`.
- `RuntimeTools/PhyreSkinnedAnimExportLab/` 수출용 별도 프론트
  몬스터의 스킨/애니메이션.
- `RuntimeTools/ReverseHarness/`, `RuntimeTools/SphereGridRuntimeProbe/` 그리고
  `RuntimeTools/SphereGridRt2Lab/` 역방향 검증용 읽기 전용 랩으로.
- MapViewer/Phyre/PS2/runtime에 대한 2026-06-02 버전 이력 문서:
  - `docs/history/FFX_PS3_MAPVIEWER_PROJECT_PLAN_2026-06-02.md`
  - `docs/history/FFX_PHYRE_MAP_EXPORT_LAB_10_STEP_PLAN_2026-06-02.md`
  - `docs/history/FFX_PHYRE_MAP_EXPORT_LAB_AZIT00_STATIC_CANDIDATE_2026-06-02.md`
  - `docs/history/FFX_PHYRE_MAP_EXPORT_LAB_AZIT00_TEXTURE_CANDIDATE_2026-06-02.md`
  - `docs/history/FFX_PHYRE_MAP_MATERIAL_IDA_PLAN_2026-06-02.md`
  - `docs/history/FFX_PHYRE_MAP_MATERIAL_LINK_DUMP_FINDINGS_2026-06-02.md`
  - `docs/history/FFX_MODELVIEWER_SKINNED_ANIM_EXPORT_2026-06-02.md`
  - `docs/history/FFX_EXE_MGRP_ORACLE_2026-06-02.md`
  - `docs/history/FFX_REVERSE_HARNESS_2026-06-02.md`
  - `docs/history/FFX_SPHEREGRID_EDITOR_V2_GATES_2026-06-02.md`
  - `docs/history/FFX_SPHEREGRID_IDA_RUNTIME_PROBE_2026-06-02.md`
  - `docs/history/FFX_PS2_*_2026-06-02.md`
- `docs/reverse/harness/` 보조 디코딩/프로브용 스크립트 및
  `docs/reverse/spheregrid_oracle_2026-06-02/`.
- `docs/history/CHAT_MASTER_DOSSIER_2026-06-01.md` 이 메인 채팅을 완전히 재구성하는 방식으로.
- `docs/history/DOSSIÊ FFX 01-06-2026/INDEX.md` 파일 모음의 주 색인으로.
- `docs/history/DOSSIÊ FFX 01-06-2026/GIT_EXCLUSION_REPORT.md` 전체 로컬 패키지에만 포함된 유일한 대형 아티팩트를 등록하기 위해.
- `Pt21` 다음에 대한 구조적 독자 흡수율:
  - `important.bin`
  - `a_ability.bin`
- `ProductionSafetySmoke` 다음 두 가족을 대상으로 한 강화 조치:
  - `Read`
  - `No-Edit Byte Identity`
  - `Reread`
- `docs/history/PT21_PT22_R

EADER_NOEDIT_GUARDS.md`를 안전한 Pt21/Pt22 슬라이스에 대한 운영용 의사결정 로그로 사용합니다.
- `Pt16` `Slice 1` 흡수:
  - 계약에 텍스트 토큰을 추가하는 `FFXProjectEditor/FfxLib/Text/*`
  - 순수 검증 / 왕복 결정 유틸리티
  - `TextLabTools/TextContractHarness` 최초의 프로덕션 측 스모크 소비자
- 해결하기 어려운 현안 문제에 대한 프론티어 스냅샷:
  - `docs/history/BATTLE_AI_FRONTIER_2026-05-31.md`
  - `docs/history/MODELVIEWER_BINDING_FRONTIER_2026-05-31.md`
- `Pt23` a `Pt34` 이제 다음과 같은 분야에서 역사적 지식의 기반으로 확고히 자리 잡았습니다:
  - `docs/history/PT23_TO_PT34_KNOWLEDGE_BASE.md`
  - `docs/history/PT23_TO_PT34_CHANGELOGS.md`
  - `docs/history/PT23_TO_PT34_BRANCH_MAP.md`
- `Pt23` a `Pt45` 이제 다음에서 코드가 활용할 수 있는 지식 기반으로도 확고히 자리 잡았습니다:
  - `docs/history/PT23_TO_PT45_CODE_KNOWLEDGE_BASE.md`
  - `docs/history/PT23_TO_PT45_CHANGELOGS.md`
  - `docs/history/PT23_TO_PT45_BRANCH_MAP.md`
- 캠페인 전체를 둘러볼 수 있는 새로운 백과사전:
  - `KNOWLEDGE_BASE.md`
  - `docs/history/PT2_TO_PT11_KNOWLEDGE_BASE.md`
  - `docs/history/PT12_TO_PT22_KNOWLEDGE_BASE.md`
  - `docs/history/PT23_TO_PT45_KNOWLEDGE_BASE.md`
  - `docs/history/PT2_TO_PT45_MASTER_KNOWLEDGE_BASE.md`
  - `docs/history/PT6_PT9_DEPENDENT_WORKSHOPS_ANNEX.md`
  - `docs/history/NON_FFX_EDITOR_THREADS_ANNEX.md`
  - `docs/history/PT_FAMILY_LINES_ANNEX.md`
  - `docs/history/OFFICIAL_MERGE_PLAN_2026-05-31.md`
- 자산 덤프에 대한 전체 트리 검색 계획:
  - `docs/history/PS3DATA_FULL_TREE_RESEARCH_PLAN.md`
  - `docs/history/PS2_FULL_TREE_RESEARCH_PLAN.md`
- PS2/Extras 기수 흡수 공식 계획:
  - `docs/history/PT50_TO_PT58_ABSORPTION_PLAN.md`
- PS2/Extras 시리즈의 공식 종료:
  - `docs/history/PT52_TO_PT58_CLOSEOUT_REPORT_2026-05-31.md`
- 이 듀오의 공식적인 경력 정리 `Pt50/Pt51`:
  - `docs/history/PT50_PT51_HISTORICAL_CLEANUP_2026-05-31.md`
- 유용한 새로운 동결 패키지 `Pt6`:
  - `docs/history/PT6_TEMPORARY_CLOSEOUT_2026-05-31.md`
  - `docs/history/PT6_CHILD_WORKSHOPS_COMPENDIUM.md`
  - `docs/history/PT6_RUNTIME_AI_DISCOVERY_ATLAS.md`
  - `docs/history/PT6_SUCCESSOR_BOO

TSTRAP.md`
- 편집 이력 참조:
  - `history/pt23-battleai-structure`
  - `history/pt24-exactlaunch-seam`
  - `history/pt25-selectorbank-materialization`
  - `history/pt26-battlestate-diff`
  - `history/pt27-routereplay-truth`
  - `history/pt28-battlecapacity-prep`
  - `history/pt29-keyitem-crashfix`
  - `history/pt30-autoability-crashfix`
  - `history/pt31-geometryviewport-block`
  - `history/pt32-chrcarrier-decode`
  - `history/pt33-aislice-payload`
  - `history/pt34-legacybridge-narrowing`

### 변경됨
- `RuntimeTools/PhyreModelExportLab/PhyreTextureExtractor.cs` 지금 표시
  일반 추출 `.dds.phyre -> PNG`, 맵과 몬스터별로 재사용 가능.
- `RuntimeTools/PhyreModelExportLab/DescriptorStaticGltfWriter.cs` 이제
  다음과 같은 방식으로 다양한 텍스처를 출력할 수 있습니다 `fileMaterialId`, `TEXCOORD_0` 및 변형
  `Color Float4 -> COLOR_0`.
- `FFXProjectEditor.sln` 이제 다음이 포함됩니다 `ReverseHarness` 실험 과제로서
- `KNOWLEDGE_BASE.md` 그리고 `docs/ai/SESSION_HANDOFF.md` MapViewer/Phyre/IDA 전선의
  새로운 진입 지점이 반영되었습니다.
- `KeyItemEditor` public surface는 ‘작성자 중심’ 표현에서 다음과 같이 재분류되었습니다. `Guarded` 구조 검사 및 수정 불가 보증.
- `AutoAbilityEditor` public surface는 ‘작성자 중심’ 표현에서 다음과 같이 재분류되었습니다. `Guarded` 구조 검사 및 수정 불가 보증.
- `PORT_STATUS.md` and `docs/history/PRODUCTION_ABSORPTION_MATRIX.md` 이제 구별하다 `reader + no-edit guard` 진정으로 작가 친화적인 부분에서 발췌한 내용입니다.
- `Pt19 / CurrentSurfaceLab` 이제 다음에서 반영됩니다 `main` ~와 함께 `Readme.md` 현재 쉘에 대해 재청취됨;
- 레거시 배치 파일 `ReadmeAssets` 로 대체되었습니다 `6` 현재 빌드의 추적 가능한 캡처:
  - `CurrentWorkspaceOverview`
  - `CurrentMonsterEditor`
  - `CurrentItems`
  - `CurrentBattleExplorer`
  - `CurrentLiveBattleLab`
  - `CurrentStringExplorer`
- 텍스트 줄에는 다음을 구분하기 위한 명시적인 기호가 추가되었습니다:
  - `EncodeSafe`
  - `DecodeOnly`
  - `RawPreserve`
  - `UnknownRisk`
- 라운드트립에 대한 기술적 결정은 이제 다음과 같이 공식적으로 설명할 수 있습니다:
  - `ReuseOriginalBytes`
  - `ReencodeAllowed`
  - `Blocked`
- `Pt29` 그리고 `Pt30` 더 이상 단순한 채팅 기록에 그치지 않고, 크래시 수정 및 보안 강화에 대한 문서화된 역사적 기록으로 자리 잡게 됩니다.
- 공식 흡수 대기열은 이제 다음과 같이 명시됩니다:
  - `merge agora`
  - `merge depois`
  - `Extras/read-only`
  - `knowledge only`
- 선 `Pt50..Pt58` 이제 다음과 같이 명확히 명시되어 있습니다:
  - `Pt56`, `Pt52`, `Pt54`, `Pt58` = 소프트웨어에서 지금 공격하기
  - `Pt57` 그리고 ~의 일부 `Pt53/Pt55` = 나중에 공격, 아직 읽기 전용
  - `Pt53`, `Pt55`, `Pt57` = 과장 없이 적극적으로 연구하기
  - `Pt50`, `Pt51` = 지우기

깨끗한 물이 되기 전의 역사
- 내에서 명확히 우선순위가 부여된 첫 번째 신제품 `Extras` 다음과 같이 변경됩니다:
  - `MagicPackageViewer`
  - `BatEffPackageViewer`
  - `MagicEffectCrosswalkExplorer`
  - `never blind merge`
- 선 `Pt6` 더 이상 ‘thread viva’와 ‘packets upstreams’ 사이에 흩어져 있지 않고, 향후 참조를 위해 단일한 편집적 정리본으로 통합됩니다.

### 검증됨
- `dotnet build RuntimeTools\PhyreMapExportLab\PhyreMapExportLab.csproj`:
  오류 0개 / 경고 0개.
- `map_azit_azit00.static-textured.gltf` 그리고
  `map_azit_azit00.static-textured-vertex-color.gltf`:
  glTF-Validator 오류 0개 / 경고 0개 / 정보 0개 / 힌트 0개.
- F3D는 텍스처가 적용된 타깃의 비공백 스크린샷을 렌더링했습니다. `azit00`.
- `FFXMapViewerWeb` 콘솔 오류 없이 Three.js에서 텍스처가 적용된 타깃을 로드했습니다.
  로컬 스모크에서.
- 공개 README에는 이제 실제로 재검증된 Windows 표면이 `main`;
- README에 포함된 모든 스크린샷은 현재 셸에서 캡처한 것이며, 오래된 작업 자료에서 가져온 것이 아닙니다.
- `Pt23` a `Pt34` 이제 다음 항목에 대한 최소한의 출처 정보가 포함됩니다:
  - 목적
  - 유용성
  - 병합 가능성
  - 워크숍별 간단한 변경 내역
- `Pt35` a `Pt39` 이제 다음과 같이 명확히 정리됩니다:
  - 언어 `binding truth`
  - ~의 뚜렷한 특징 `owner/target/parentage/commit`
  - 가드레일 받침대 `Pt6` 그리고 `Pt23`
- `Pt44` 더 이상 ‘새 프론트’가 아닌, 다음의 읽기 전용 크로스워크로 존재하게 됩니다:
  - `formation 0..7`
  - `enemy actor rows 0..10`
  - `rawMonsterId -> corpus`
  - `composition truth` vs `actor-surface truth`
- 선거 운동의 늦은 종료 `Pt6` 이제 다음의 연구 결과도 정리하고 있습니다:
  - `Pt46 / AIBlobParityGrammarLab`
  - `Pt47 / AIRuntimeDispatchLab`
  - `Pt48 / SafeAIMicroProbeLab`
  런타임/AI의 유산 중 하나로, 라이터나 패처가 없더라도 마찬가지입니다.
- `Pt40` a `Pt45` AI 캠페인으로 정직하게 기록되어 있지만, 아직 코드에서 현실로 구현된 결과는 없습니다.
- 전체 캠페인 `Pt2..Pt45` 이제 레이어별로도 탐색할 수 있게 되었습니다:
  - 기존 베이스 `Pt2..Pt11`
  - 중간 기지 `Pt12..Pt22`
  - 무거운 베이스 `Pt23..Pt45`
  - 메모리/런타임/바인딩/가드가 통합된 단일 아틀라스
- `Pt23..Pt45` 또한 다음과 같이 명시적으로 부속되어 있습니다:
  - 의 위성들 `Pt6`
  - 의 위성들 `Pt9`
  - 생산상의 예외 `Pt29/30`
- 접두사가 없는 FFX 스레드 `FFX Editor` 이제 다음과 같이 공식적으로 분류됩니다:
  - 라인 운영 래퍼 `Extras / ps3data`
  - 해당 라인의 유용한 소규모 워크숍 `Pt6 / Pt23`
  - 보존된 지식, 아카이브 가능한 스레드
- 거대 기업들 

프로젝트의 라인들도 이제 공식적으로 제품군으로 분류됩니다:
  - `Model Viewer / Binding`
  - `Battle / AI / Runtime Truth`
  - `Text Safety`
  - `Kernel / Shop`
  - `Tooling / Safety / Release`
  - `Production Crashfixes`

### 참고 사항
- `Pt24` 를 꽉 눌렀다 `exact launch seam`, 하지만 natural owner도 해결되지 않았고 final commit도 해결되지 않았다.
- `Pt33` 그리고 `Pt35` 꽉 조였다 `ModelViewerLab`, 하지만 그 정도까지만 `AI Slice + .chr` 구조용 브리지로서 그리고 `composition` 바인딩 결정으로서.
- `Pt29` 그리고 `Pt30` 이는 직접적인 생산 가치를 지니고 합병 가능성이 높은 이번 워크숍 시리즈의 첫 번째 뚜렷한 신호들입니다.
- `Pt6` 최근 몇 라운드 동안 유용한 좁히기 효과가 있었음에도 불구하고, 새로운 인과적 이득이 거의 발생하지 않아 일시적으로 중단되었습니다.

### 계획
- 의 향후 후속 모델 `Pt6`, 하지만 이미 새로운 부트스트랩과 아틀라스 기반으로 개발되고 있어, 원시 스레드는 제공되지 않습니다;
- 경우에 따라 좁은 파일럿 `Pt15` 셸의 시작 단계로 들어가지 않고 읽기 전용 모드로;

### 백로그
- `Pt16` `Slice 2` 그리고 `Slice 3` 이 흐름에서 여전히 제외된 것들:
  - `TextSourceCapability`
  - `Index*`
  - UI 배선 `StringExplorer`
- `important.bin` 후보 돌연변이의 범위는 `Pt22` 기술적 미해결 과제만 남음:
  - `0x10 + 0x12`
  - `0x13`
- `a_ability.bin` 다음에 의해 측정된 녹색/노란색 구역 `Pt22` 기술적 미해결 과제만 남습니다.
- `arms_rate.bin` 유망한 오라클 결과에도 불구하고, 고립된 사이드카 돌연변이는 프로덕션 브랜치에서만 여전히 처리 대기 상태로 남아 있습니다.
- `Pt14` 여전히 런타임/디버그용 테스트 라인일 뿐, 프로덕션용 프레임워크로 이식된 것은 아닙니다.

### 차단됨
- `btl_txt.bin` writer 및 encode에 대해서는 여전히 차단된 상태입니다;
- `w_name.bin` 일반 작성자에게는 계속 차단된 상태입니다;
- `Field String` 앱에서 계속 잠겨 있습니다;
- `important.bin` and `a_ability.bin` 공개 변형 안전 작성자 클레임에 대해서는 계속 차단된 상태로 유지됩니다;
- `Pt22` Oracle 범위 검색 결과만으로는 작성자 승격이 승인되지 않습니다.
- 다음의 블라인드 포트는 `runtime + memory + encounter tooling` 여전히 금지되어 있다.

## [v2.13.0] - 2026-06-05
### 추가됨
- **🌅 AURORA COCKPIT (야간 Jarvis) — 세 가지 연결:** (1) **MapViewer가 실제로 렌더링됨** — `AuroraSceneRenderer` 길을 열다 `file://` (브라우저가 차단합니다 `fetch()` glTF/catalog → “Loading map”에서 멈추던 문제); 이제 정상적으로 로드됩니다 `http://127.0.0.1:8765/...` + `EnsureViewerServer` (올라간다 `python -m http.server` (혼자). 화면에서 렌더링이 확인되었습니다. (2) **EncounterTable → Aurora** — 테이블 중 하나를 더블 클릭하여 `EncounterTableExplorer` 열기 `AuroraChamber` 이미 그 장면의 렌더링이 진행 중인데 `map` (`RequestOpenAuroraChamberForMap` + `AuroraChamber_DataModel.SelectSceneByMapKey` + 브리지 `Main_Window`). (3) **몬스터의 렌더링** — `AuroraChamber` ~을 주입한다 `model` 앵커를 통해 라인업 구성(chunk2)을 확인 `Battle_File.Read().Formation`, 슬롯↔닻, `Monster_Dictionary`); `aurora-overlay.js` 다음에서 실제 glTF 파일을 불러옵니다. `work/phyre_chr_anim/models/mNNN` 출처: `GLTFLoader` + `AnimationMixer` (애니메이션; 실시간 스케일 슬라이더). 추가 효과, 구체로 변형.
### 참고 사항
- 에디터 컴파일 오류 0개. MapViewer 렌더링 확인됨; 몬스터 렌더링은 추가적 효과 적용됨(스케일/외관 확인을 위해 소유자의 클릭이 필요함). 중복 제거는 다음 문서에 기록됨: `docs/ai/FFX_OVERNIGHT_2026-06-05_JARVIS.md` (Aurora/EncounterTable/FormationEditor = 표준; Field Hub/SpiraForgeHub = 비활성; SaveTracker = 폐기 예정인 스텁). 푸시 없음 (Halyson의 승인이 보류 중).

## [v2.12.0] - 2026-06-05
### 추가됨
- **🌅 AURORA — 포메이션 위치 지정기 (값만 지정, "몬스터 위치 지정" 잠금 해제):** 신규
  `FfxLib/BattleMap/BattleArenaPositionWriter.cs` chunk3의 앵커 배열에 배우들의 X/Y/Z 값을 다시 기록합니다
  (필드 내 몬스터 = 포인터 `+0x20`; 또한 party/aeon/staging은 `role`) **IN PLACE**, 값만 변경:
  헤더/포인터/카운트/기타 청크를 건드리지 않고, W를 그대로 보존합니다. 'battle'→'cena' 변환이 **동일성**을 갖기 때문에
  (IDA v2.10.0.1에서 입증됨), 'cena'에서 선택된 좌표는 그대로 기록됩니다. 동일한 슬롯 안전(slot-safe) 표준을 따르며
  `FormationSlotWriter` (저장 + 일회성 백업) `WriteLooseFile`).
### 검증됨
- **Gate RT0 `RuntimeTools/BattleArenaPositionLab` — PASS (종료 코드 0):** 실제 btl 코퍼스에서 **862/862 쓰기 가능** —
  RT0 (수정 없음 == 바이트 동일) 862/862, POSITION-ONLY (배열 내로 제한된 차이) `+0x20`) 862/862, RE-READ 862/862,
  + SAVE LIFECYCLE (임시 사본에서 편집 불가/편집/복원) PASS.
- **CI 여유 공간 종료:** `RuntimeTools/offline_ci.ps1` 이제 오로라의 3개 게이트가 실행됩니다 —
  **BiancaCatalogLab + AuroraChamberLab + BattleArenaPositionLab** (이전에는 제외되어 있었습니다). CI 완료
  **PASS (7/7 게이트)**: ReverseHarness, AiScriptLab, FormationSlotLab, AbilityCommandLab + 3개의 새로운 실험실.
### 연기됨
- **게임 내 이동 위치 반영 (RT2)** = DINPUT8 프로브 (해제) + 게임 실행. 라이터는 오프라인에서 바이트 안전성을 검증하며,
  게임 내 화면이 최종 판단 기준이 됩니다. 몬스터 슬롯 추가/제거(개수 변경) = 구조적(Rebuild), 다음 단계.

## [v2.11.1] - 2026-06-05
### 추가된 기능
- **📜 이벤트 편집기 — 단어 검색 + 언어 구분 (개발자 요청):** o `EventExplorer` (1) 텍스트 내용을 기준으로 대사를 필터링하는 **단어 검색** 필드와 (2) **언어 필터**(체크박스
  영어/일본어, **기본값 영어**) — 이전에는 JP와 EN이 같은 목록에 포함되어 있었습니다(일본어가 먼저 표시되어 ‘일본어 벽’ 현상이 발생).
  리팩토링됨 `EventExplorer_DataModel` (`allTextRows` + `ApplyTextFilter`, English-first) + axaml (검색용 TextBox +
  JP/US용 CheckBoxes). **Writer는 건드리지 않음** (Tier 1은 계속 `--event-rt0` 397/397 + 수정 12/12).
### 참고 사항
- 바닐라 버전에는 **JP (chunk 1)** + **EN (chunk 4)** 트랙만 포함되어 있으며, 포르투갈어 트랙은 없습니다. `.ebp` (PT는 번역 주입을 의미하며,
  writers의 적용 범위를 벗어납니다). 단어 검색은 선택된 이벤트 내에서 이루어집니다.

## [v2.10.0.1] - 2026-06-05
### 검증됨 (RE / IDA, 오프라인)
- **🌅 AURORA — 전투→장면 변환 = 정체성, IDA에서 검증됨 (Z축 반전 가설 반박):** 전투 엔진이
  는 chunk3(battle-local)의 좌표를 **문자 그대로** 액터의 월드 노드로 복사합니다 — **Z-플립, 스케일 또는
  회전 없이**; Y축에만 액터별 모델 높이가 적용됩니다 (`actor+0x534`). 그 장면은 `.dae.phyre` == 버텍스 프레임
  Phyre 1:1, **P_cena(X,Y,Z) = P_battle(X,Y,Z)** (s=1, R=I, T=0). 증명된 체인: `FFX_Battle_AreaChunk_GetSetPosition`
  (`0x7AC000`; chunk3 기본 `0x112A9B0`; 4개의 부동소수점 수치를 그대로 복사; 액터 @의 세계 좌표`+0x3B0`) →
  `FFX_Battle_ResolveActorPlacement` (`0x7A9AE0`) → `FFX_Battle_GetActorByIndex` (`0x794030`, stride `0xF90` == 적
  RT2). 플립-Z 가설은 필드 밖 열(party-back Z≈-168)을 포함시킨 데서 비롯된 오류였다. 문서:
  `docs/reverse/FFX_AURORA_BATTLE_TO_SCENE_TRANSFORM_IDA_PROVEN_2026-06-05.md` (+ rename-queue p/ a `.i64` (실제).
### 변경 사항 (오로라 챔버 — 정직성)
- 오로라 챔버 배너/오버레이: "전투→UNCALIBRATED 세계/가설" → **"정체성 (IDA-입증)"**. 오버레이는
  앵커를 장면 좌표에 직접 매핑하며(기본값은 이미 정체성이었습니다), Z축 반전 토글은 **반박됨/비교**로 변경됩니다;
  `coordSpace` ~의 `aurora-actors.json` = `scene_world_identity_ida_proven`.
### Deferred
- **실시간 확인 (probe):** 읽기 `actor+0x3B0` azit03의 포스 배틀에 등장하는 살아있는 괴물들을 확인하고 `≈ chunk3`
  (잔여량 ~0) + 정확한 Y-온도 측정. Halyson에서 프로브 승인됨; 오픈 세트에만 의존 (기존 프로브를 통한 READ,
  새로운 코드 없음). SPIRA FORGE는 정지 상태 유지.

## [v2.10.0] - 2026-06-05
### 추가 사항
- **📜 이벤트 스크립트 작가 — 1단계 (에디터의 작가 관련 마지막 큰 결함, 수정됨):** o `Event_File`
  (`.ebp` / 컨테이너 **EV01**)이 더 이상 읽기 전용이 아닙니다. **컷신/이벤트 대화 편집이 버튼으로 변경되었습니다.**
  - **`FfxLib/Event/Event_File.Write.cs` (새 기능):** EV01 컨테이너를 바이트 단위로 재포장 — 각 청크의 정렬을 재조정
    a `0x40`, 재계산된 절대 오프셋 테이블 + EOF 종결자 (매직 + 센티넬) `0xFFFFFFFF` 보존됨).
    편집 없음 = 원문 그대로 보장; 편집된 텍스트 = 재사용 `TextTable_File.Write` (chunks JP=1/EN=4); ATEL 스크립트 (0),
    Unknown 2 및 FTCX (3)를 바이트 단위로 보존. Tier 2 후크 `ScriptChunkOverride` (chunk-0의 수정본을 다시 스티치함).
  - **`Event_File.cs`:** 원시 헤더 캡처 + 텍스트 테이블; null 포인터 필드 문자열 항목을 허용
    (8개 파일)하며 청크를 그대로 보존합니다(문서화된 편집 가능한 프론티어 텍스트).
  - **`TextTable_File.Write` (가산 과부하 `includeTrailingPadding`):** 내부 패딩 없이 테이블+풀을 생성할 수 있습니다
    (컨테이너가 0x40으로 다시 패딩합니다). **오류가 발생하지 않습니다** `--textstr-rt0`** (기본값 = 기존 동작).
  - **`Modules/EventExplorer` 대화 상자 편집기로 변경됨:** 편집 가능한 JP/EN 문자열 (TextBox TwoWay) +
    **"Save dialogue"** 버튼으로, 이를 다시 패키징하여 저장합니다. `.ebp`.
- **📜 이벤트 스크립트 작성자 — Tier 2 (chunk 0 = ATEL 스크립트, append/PATCH):** 전투용 ATEL 코덱이
  (`FfxLib/Ai/AiScript_File.cs`, **읽기 전용 기증자로** 사용됨)은 이벤트 스크립트(동일한 AiFile 계열)를 읽거나 편집합니다.
  - **PATCH 바이트 단위 피연산자 검증 완료** (12/12): chunk-0의 피연산자를 편집하면 해당 바이트만 변경되며, 컨테이너는
    나머지 부분은 동일하게 재조립하고, 재읽기 시 새로운 피연산자를 불러옵니다.
  - GROW (AppendCode)는 **문서화된 경계**입니다: `AppendCode` 기증자(battle용으로 제작됨,
    DATA 섹션의 디스크립터)는 이벤트 스크립트가 사용하는 **헤더 상주** 디스크립터를 재배치하지 않습니다 (`[0x38..scriptStart)`) — 다음이 필요합니다.
    이벤트 인식 재배치 (AI Assembler 레인과 조율).
### 검증됨
- **Gate `--event-rt0` (`Tools/EventRt0.cs`) — PASS:** no-edit 읽기→쓰기 **397/397** 바이트 동일; **편집
  왕복 12/12** (문자열 교환 → 재포장 → 

재검토: 편집된 문자열은 확인됨, 청크는 변경 없이 원문 그대로, 이뎀포텐트).
- **Gate `--eventscript-rt0` (`Tools/EventScriptRt0.cs`) — PASS:** 코덱 chunk-0 RT0 **397/397**; 컨테이너 오버라이드
  **397/397**; **오퍼랜드 패치 byte-local 12/12**. 편집기가 0개의 오류 없이 컴파일되었습니다.
- **컨테이너 EV01 검증 완료 (397/397):** 매직 EV01, 첫 번째 청크 @0x40, 정렬 0x40 (위반 0건),
  연속성 (단절 0회), EOF==파일 크기, 센티넬 `0xFFFFFFFF`. Docs에서 `docs/reverse/FFX_EVENT_*_2026-06-05.md`
  (컨테이너, FTCX=폰트 시트 4bpp, Unknown2=“SeSep” 사운드 큐, ATEL 방언, 패딩/텍스트 테이블, 참조, IDA 호스트).
### Honesty / Deferred
- Tier 1 = **텍스트** (대화) 바이트 안전 및 검증됨; 포인터 항목이 null인 8개의 EN 파일은 원문 그대로 유지됨 (아직
  텍스트 편집 불가). Tier 2 = 검증된 **패치**; **추가/확장** 및 구조적 제작 (FTCX 글리프 시트 +
  Unknown2 신호 + 전체 이벤트 ATEL 어셈블러) = 문서화되었으나 확정되지 않은 Tier 3. 검증 단계에서는
  오프라인 바이트-RT0 방식을 우선적으로 채택했으며, 편집된 대화의 인게임 RT2 방식은 공개 기능 출시 전에 권장됩니다.

## [v2.9.0] - 2026-06-05
### 추가됨
- **🌅 AURORA CHAMBER — 레이어 3 (통합), 새로운 모듈 `Modules/AuroraChamber`:** 🌙 BIANCA (btlmap의
  25개 장면 카탈로그)를 MapViewer에 연결하고 chunk3에서 **배우들의 좌표**를 추출합니다. 오로라와 비앙카에게 바칩니다. 💛
  - **Scene Picker**는 `BattleMapCatalog_File`/`BattlefieldSceneResolver` (읽기 전용) — 영역 및 맵 키별로 장면을 나열하거나 선택합니다.
  - **렌더**는 `PhyreMapExportLab` (btlmap 장면의 glTF를 필요에 따라 내보내기)하고 다음을 엽니다. `FFXMapViewerWeb` 출처
    딥링크 `?catalog=`/`?map=`/`?actors=` — **장면별 미니 카탈로그**, 절대 재생하지 마세요 `catalog.json` 공유하지도 않고 다시 작성하지도 않는다 `app.js`.
  - **좌표** (새로운 리더를 통해) **`FfxLib/BattleMap/BattleArenaAnchors_File.cs`** (순수/Avalonia-free):
    chunk3(rec 영역 96B, 포인터)를 디코딩합니다 `+0x10..+0x2C`, 살아있는 괴물들 `+0x20`, elem 16B XYZW Y-up), battle-local 앵커를 나열하고
    JSON을 Encounter Authoring으로 내보냅니다.
- **MapViewer의 추가 오버레이** (`RuntimeTools/FFXMapViewerWeb/aurora-overlay.js` + 1 `<script>` 에서 `index.html`):
  앵커 기즈모 `?actors=` + “pick” 모드 (y=0 평면에서의 레이캐스트 → 월드 좌표). 비침입적 (hooka
  `window.ffxMapViewerDebug`; no-op 없음 `?actors`/pick; 절대 `app.js`).
### 검증됨
- **Gate RT0 `RuntimeTools/AuroraChamberLab` — PASS (종료 0):** GOLDEN 디코딩 **5/5 정확** (azit03_00/dome00_00/
  klyt00_00/sins02_00/mihn00_00 == 문서에 검증된 좌표); 코퍼스 **862/862** 정리됨 (0 NaN/Inf, 살아있는 몬스터에서 W==0
  ); 결정론적; 파이프라인 BIANCA→장면→전투→앵커 **52/52** 장면이 앵커와 매핑됨.
- **btlmap 렌더링 검증됨:** `PhyreMapExportLab export --area btlmap/azit/azit03_a` → 실제 텍스처가 적용된 glTF (68
  텍스처, 10,804개의 삼각형, `gatePass: true`). 컴파일러에서 **0개의 오류**가 발생했습니다(HEAD와 분리된 워크트리에서 확인됨).
### Honesty / Deferred
- 씬 브리지 (EncounterTable `map` → btlmap) = **입증됨**. Transform battle→mundo = **설계 가설,
  미보정** (P_장면 = R·s·P_전투 + T; Z축 반전/요 180도 미해결) — 앵커는 전투 위치의 원시값이며,
  엔진 정확도가 아닙니다. 프로브를 통한 보정 = Wave 3 (Halyson의 승인 필요). **SPIRA FORGE는 중단된 상태**

**; Aurora는
  MapViewer + BIANCA(읽기 전용/추가 기능)만 사용하며, 허브는 연결하지 않습니다.

## [v2.8.0] - 2026-06-05
### 추가됨
- **🌙 BIANCA — 오로라 상공회의소 설립 (레이어 1, 읽기 전용):** `FfxLib/BattleMap/BattleMapCatalog_File.cs`
  (**25개 구역 / 56개 장면**의 HD 영상을 수록한 `ps3data/btlmap` — `<área>NN_<variante>` c/ `mdl/d3d11/<leaf>.dae.phyre`)
  + `FfxLib/BattleMap/BattlefieldSceneResolver.cs`. Puro/Avalonia-free, 에디터에서 컴파일됨 (오류 0개).
- **EncounterTable→장면 연결 문제 해결 + 검증됨:** 핵심은 ** 필드입니다.**`map` (6ch = 영역+NN, 예: "azit03")**, 아님
  o `battlefield` u16 (이것은 **글로벌 아레나 ID**이며, 여러 맵을 넘나듭니다 — `bf=1061` (nagi/test/tori/zzzz). 문서:
  `docs/reverse/FFX_BATTLEFIELD_SCENE_BRIDGE_2026-06-05.md`.
- **해독된 캐릭터 좌표 (RE):** 전투별 빈(bin)의 chunk3 = 영역 레코드 96B; **살아있는 몬스터가
  포인터에 `+0x20`** (float32 X, Y, Z, W; Y-up; W=0; stride 16; 편대 슬롯 ↔ 엔트리). 파티 `+0x10`, 에온 `+0x18`,
  카메라 `+0x2C`. 문서: `docs/reverse/FFX_BATTLE_FORMATION_POSITION_CHUNK3_DECODED_2026-06-05.md`.
- **3D 파이프라인 확정 (레이어 2):** `PhyreMapExportLab` btlmap 장면 내보내기 **코드 변경 없이**
  (`-- export --ps3-root <ps3data> --area btlmap/azit/azit03_a`). 액터 오버레이 계획 + 프로브를 통한
  좌표 보정 (DESIGN): `docs/ai/FFX_AURORA_COORDINATE_SYSTEM_AND_CALIBRATION_2026-06-05.md` (Halyson의 승인을 받은 경우에만 테스트).
### 검증됨
- **Gate RT0 `RuntimeTools/BiancaCatalogLab` — PASS (종료 0):** 전체 카탈로그 (디스크 56 == 카탈로그 56) +
  결정론적; 56/56 장면, 정확히 1명의 주 모델 포함; **설명할 수 없는 누락 0건**이 있는 연결부 (22개 맵
  HD 고아 맵 = cut/PS2 전용 EXPECTED; 4개 고아 장면 bika04/grid00/nagi03/sfia00 = 보스/스토리 EXPECTED).
### 연기됨
- **좌표 보정 (프로브)** 및 **🌅 오로라 챔버 내 통합** (오버레이 + 드래그-투-라이트): 디자인 완료;
  DINPUT8 프로브는 Halyson의 승인이 필요하며 SPIRA FORGE는 일시 중지됨.

## [v2.7.1] - 2026-06-05
### 추가/검증
- **WAVE 1 WRITER-COMPLETENESS — 12개 게이트가 적용된 바이트-페이설 패밀리 (스윕 `--wave1-rt0`: RT0 12/12 PASS):**
  WeaponNameTable, MacroDictionary, NameDescriptionTextTable, NameDescriptionTextPrefixTable, BtlTextTable,
  SphereGrid, ShopGearCatalog, BukiGetTreasureCatalog, AlBhedDictionary, PointerScriptTable, BattleTextTable,
  ShopTable. **preserve-only** 표준 (원본 복제 + 편집 가능한 필드 재설정; `WriteIdentity` 다음과 같은
  재구축 손실이 있던 분들께: WeaponName/Macro/NameDescPrefix/SphereGrid/ShopTable). 새로운 게이트 스윕 `Tools/Wave1Rt0.cs`.
- **ShopItemCatalog**: **읽기 전용 프로젝션**이 확인됨 `Ability_Command` (item.bin, 이미 게이트 처리됨) — 라이터 갭이 아닙니다.
- 에디터 **~기능적으로 완료됨**: 이미 게이트 처리된 부분에 더해, 이제 데이터베이스는 대부분 바이트 세이프합니다.

## [v2.7.0] - 2026-06-05
### 추가 사항
- **AI 어셈블러 GROW/SHRINK 잠금 해제 (구조적 루즈 파일 저장)** — 신규 `AiScript_File.SpliceAiFileIntoMonsterGrow`:
  AiFile 파티션을 크기가 다른 파티션으로 교체하고, AiFile을 **16-pad**로 조정하며, **다음 섹션들을 이동**하고
  **헤더의 섹션 포인터**를 다시 작성합니다 (`m###.bin`), AiFile을 **원문 그대로**(codeLength를 덮어쓰지 않고)
  저장합니다. 이제 UI의 AI Assembler는 grow/shrink를 저장합니다(이전에는 길이 보존만 가능). 덮어쓰기 원인에 대한 문서화
  + 설계상 수정됨(옵션 B: 최소 표면적, 다음은 변경하지 않음 `Monster_File.Write` → `--monster-rt0` (계속 361/361).
- **로더의 RE (IDA, 무료):** `docs/reverse/FFX_AIFILE_LOADER_RENAME_QUEUE_2026-06-05.md` — 로더는
  VM의 크기를 **워커 수 + 워커당 데이터 길이(16으로 반올림)**에 따라 결정하며 (파티션/DeclaredLength/codeLength에 따라 결정하지 않음),
  **파일 내 포인터를 신뢰합니다** → grow 시 재할당이 보장되며 **트레일링 패드는 안전합니다**. (황금률: rename-queue.)
### 검증됨
- **`--aiasm-rt0` 확장 — PASS:** no-edit 재구축 346/346, 레이아웃 재조정 346/346, 스플라이스 346/346, **GROW 346/346**
  (삽입 → 성장 인식 스플라이스 → 깨끗한 재읽기 + 꼬리/헤더 문자 그대로 보존 + 16-정렬 + 항등적),
  **SHRINK 346/346** (대상 외 명령어 제거 → 음수 델타 → 깨끗한 재읽기 + 꼬리 부분 보존). `--monster-rt0`
  **361/361** (회귀 없음). 코퍼스 정렬: 16/32/64/128/256, 후행 패드 0.
- **화면에서 클릭 확인된 UI:** 에디터 실행 (마스터 자동 로드) → Monster AI Editor → **"AI Assembler
  (free-edit)"**가 편집 가능한 명령어 목록(opcode/operand/remove)과 함께 렌더링됨 + 구조 삽입/저장 +
  미리보기. 스크린샷 `work/spira_forge_qa/monster_ai_assembler_v01.png`.
### 연기됨
- grow의 **게임 내 검증 (RT2)**: install에 성장된 m###.bin을 기록하고, DINPUT8 프로브를 통해 전투를 강제 실행해야 함
  (공유) — Halyson의 명시적인 승인을 받은 경우. 오프라인 + RE를 통해 바이트/게임 안전성을 검증하며, 게임 내 화면이 최종 판단 기준이 됩니다.

## [v2.6.0] - 2026-06-05
### 추가된 기능
- **UI 내 AI 어셈블러** (`Modules/MonsterAiEditor`, 부가 기능) — 바이트 단위 연산자 편집기 위에 **전체 명령어**
  (삽입 / 제거 / 수정)를 자유롭게 편집할 수 있는 영역. 재구성된 AiFile은
  `AiScript_File.Rebuild` (RT0 검증: old→new 매핑을 통해 엔트리포인트 및 점프 테이블 재배치). 편집 가능한 목록
  (오퍼코드/오퍼랜드 16진수 + 제거 체크박스), 선택 항목 뒤에 삽입, 변경 사항 미리보기. **저장 기능은 편집 시에만 허용
  길이 보존** (동일 `codeLength`) → 바이트 안전 방식의 스플라이스 via `SpliceAiFileIntoMonster`. **GROW/SHRINK = LAB**
  (정직한 메시지): loose-file 저장을 위해서는 헤더를 고려한 레이아웃 재조정 + 정렬 패딩 + 게임 내 유효성 검증이 필요합니다.
- **새로운 RT0 헤드리스 게이트 3개** (writer-completeness):
  - `--ctbbase-rt0` → `CtbBase_File` (**ctb_base.bin**), 보존 전용.
  - `--mixtable-rt0` → `MixTable_File` (**prepare.bin**), 보존 전용.
  - `--aiasm-rt0` → **AI Assembler의 구조적 저장**을 검증합니다(편집 없이 재구축 + 레이아웃 재조정 + 바이트 동일 스플라이스).
    그리고 코퍼스의 AiFile→WorkerFile 정렬을 측정합니다.
### 검증 완료
- **CtbBase RT0** (255개 항목 / 530 B) + **MixTable RT0** (112개 원본 / 25108 B): 바이트 단위 동일.
- **AI Assembler**: 편집 없음 재구축 **346/346**, 레이아웃 저장 **346/346**, **스플라이스 저장 346/346** (UI 경로) —
  **길이 보존 및 바이트 안전 편집**. Grow=LAB (원인: 헤더 0x34의 `Monster_File` 겹쳐진다 `AiFile[0..4)`=codeLength
  + grow는 WorkerFile의 정렬을 깨뜨립니다(코퍼스 16/32/64/128/256 정렬, 0 후행 패드).
### 차단됨 / LAB
- **AI Assembler GROW/SHRINK loose-file save** + 이번 세션에서 UI 렌더링 클릭 검증 미실시 (모듈의 표준 정직한 갭).

## [v2.4.4] - 2026-06-05
## [v2.5.0] - 2026-06-05
### 추가됨
- **FFX MapViewer 디버그 슬라이스 (웹 뷰어):** o `RuntimeTools/FFXMapViewerWeb` 이제 다음의 로컬 컨트롤을 표시합니다.
  `Spector.js` (`Open Spector`, `Capture Next Frame`, `Export Last Capture`) 및 첫 번째 패널 `Material Debug`
  glTF 소재의 라이브 인벤토리가 로드된 상태에서, 텍스처 슬롯별 선택기, 팩트 칩 및 카드
  (`map`, `normalMap`, `aoMap`, `envMap`, 등).
- **마감된 구현 문서:** `docs/history/FFX_MAPVIEWER_SPECTOR_MATERIAL_DEBUG_IMPLEMENTATION_2026-06-05.md`
  입력된 내용, 검증된 내용, 그리고 명시적으로 검증 대상에서 제외된 내용을 기록합니다.
### 검증됨
- `FFXMapViewerWeb/app.js` 구문 검사에서 통과했습니다.
- HTTP를 통한 로컬 검증 + Chrome 헤드리스 모드에서 `map/azit/azit00`: 뷰어가 로드되고, 지도가 렌더링되었으며, 새로운
  컨트롤이 나타나고 패널이 `Material Debug` 로드된 glTF를 기반으로 렌더링되었습니다.
- 새로운 미리보기에는 ‘정직한’ 폴백 방식이 적용되었습니다: 런타임/브라우저가 재사용 가능한 픽셀을
  신뢰할 수 있는 방식으로 제공하지 못할 경우, 뷰어는 `Frame preview unavailable` / `Texture preview unavailable on this source surface`
  타당한 시각적 증거인 척하는 대신.

## [v2.4.4] - 2026-06-05
### 추가 사항
- **Handoff encounter → 포메이션** (SPIRA FORGE): Field Hub에서 encounter peek에 이제 **선택 가능한 필드 전투
  목록**이 표시됩니다. 하나를 선택하면 `FieldContext.SelectedBattleId` 그리고 **포메이션 에디터는 바로
  이 배틀로 이동합니다** (포메이션을 불러옵니다). 쉘 플러밍 없이 공유 스파인을 통해 마스터플랜의 “영역을 클릭하고 포메이션을 변경”하는 기능을
  실행합니다. `FieldContext` 이겼다 `SelectedBattleId`/`SelectBattle`.
- **EncounterIdMapLab** (`RuntimeTools`) — id encounter↔btl_* 스키마에 대한 읽기 전용 조사.
### 유효성 확인됨
- **EncounterIdMapLab:** `EncounterTable.BattleId` 826/863에 있는 btl_* 폴더와 **1:1로 매핑** (예: `azit03_00`);
  폴더가 없는 37개의 BattleID + 매칭되지 않은 37개의 폴더 (특별 전투/이벤트) — handoff가 존재하는 항목만 필터링합니다.
- 에디터 빌드 오류 0개; `offline_ci` 4개의 게이트 통과; 화면에서 핸드오프 확인됨 (`azit03_00` Hub → Formation Editor
  전투 화면으로 바로 넘어갔습니다(7개의 청크). 스크린샷 `work/spira_forge_qa/handoff_encounter_to_formation_v04.png`.

## [v2.4.3.1] - 2026-06-05
### 리버스 / 증명
- **HD 스킨 매트릭스-팔레트 디코딩됨 (오프라인) — 다리의 코일은 바인딩되지 않았습니다.** 핸드오프의 §3 가설을 반박합니다.
  (`CONTINUE_AQUI_PERNAS_HD`): "52" 지도 `m_skeletonMatrices` → “79 joints” **는 IDA 파일이 아니라 Phyre 파일에 있습니다**.
  - 스킨 팔레트는 `PMatrix4[0..51]` (출처: `PMesh` 필드 12); `== m_skeletonMatrices` vivo **바이트 단위**
    (`maxDist=0.00000`).
  - map slot→node는 `int` 각각의 **오프셋 12**에서 `PSkeletonJointBounds[j]` (52개 슬롯 → 52개 노드, 일대일 대응).
  - 결합 `m_defaultPose` 출처: `m_matrixParents` **정확히** 원본 inverse-bind를 재현합니다: `0/52` 노드들이 서로 다릅니다.
    따라서 `--hd-defpose+--hd-parents` **이미 게임의 실제 바인드입니다**.
  - 히스토리컬 코일의 근본 원인: bake 없이 `--hd-defpose/--hd-parents` 폴백으로 전환된다 `invBind = PMatrix4[52+b]`
    (원시 LOCAL 매트릭스) → 메쉬가 폭발합니다. defpose+parents 방식이 해결책이며 **이미 갤러리의 기본 설정입니다**.
  - 새로운 읽기 전용 프로브: `work/_scratch_mgrp/phyre_palette_probe` (팔레트를 찾고, 정확한 바인드를 확인한 후, 출력합니다)
    `node_to_slot.json`) 및 `phyre_legs_probe` (매처; 우연의 일치에 의한 매칭 함정을 보여준다).
### 검증됨
- **화면이 결정한다 (F3D):** 파티 전체의 **탄탄하고 깔끔한** 다리 — c001 (티더스), c005 (와카), c007 (리쿠) —
  강제 휴식, 전투 (id5_c4318 t0.0–0.9), 쪼그려 앉은 자세에서 4가지 종아리 각도, 멀티 클립 (c4333/c4365/c4886).
  수치: 다리 조인트의 위치/월드 = 완벽한 리지드 바디 (스케일=1, 디테일=+1, 직교 0.0000). IDA 없음.
  전체 테스트는 `docs/reverse/FFX_HD_SKIN_PALETTE_DECODED_LEGS_NOT_BIND_2026-06-05.md`.

## [v2.4.3] - 2026-06-05
### 추가됨
- **Writer-completeness gate wave (커널 테이블)** — 기존에 존재했으나 바이트 게이트 처리를 한 번도 받지 않았던 라이터를 검증하는 4개의 새로운 RT0 헤드리스 게이트로, 편집 가능한 콘크리트 베이스의 4개 패밀리를 완성합니다:
  - `--keyitem-rt0` (`Tools/KeyItemRt0`) → `KeyItem_File` (**important.bin**), 쓰기 전용 보존 (원본
    바이트 복제 + 재인쇄만 `PrimerByte10`/`OrderingByte13`).
  - `--treasure-rt0` (`Tools/TreasureRt0`) → `Treasure_File` (**takara.bin**), 왕복 전체 디코딩 (4바이트/항목).
  - `--customization-rt0` (`Tools/CustomizationRt0`) → `Customization_File` gear **kaizou.bin** + aeon **sum_grow.bin**
    (헤더의 접두사/접미사를 보존하고 디코딩된 항목을 다시 전송함).
  - `--autoability-rt0` (`Tools/AutoAbilityRt0`) → `AutoAbility_File.WriteAbilities` (**a_ability.bin**,
    DATA 섹션), writer는 읽기 전용입니다. (읽기 `arms_rate.bin` 단순히 계약 조건을 충족시키기 위해서일 뿐입니다. arms_rate라고 적지도 않고, 비용을 청구하지도 않습니다.
    `WriteAbilitiesAndText`/텍스트 재포장.)
### 검증 완료
- **RT0 바이트 동일 4/4** 실제 파일과 비교 시 (`jppc/battle/kernel/`): important.bin (64개 항목, 3674 B),
  takara.bin (503개 항목, 2012 B), kaizou.bin (125) + sum_grow.bin (77), a_ability.bin (134개 항목, 19590 B).
  **편집 없음 저장 = 바이트 동일; 편집 = 바이트 로컬** (Monster/Encounter를 해결했던 것과 동일한 preserve-only 표준).
  “important.bin/a_ability.bin blocked for mutation-safe writer claims”라는 역사적인 문제점을 부분적으로 해결했습니다:
  필드(데이터 섹션) 편집은 이제 검증되었습니다; **텍스트 풀의 재포장은 여전히 클레임이 제기되지 않은 상태** (동일한
  monmagic 드리프트 위험 — 이 게이트 외부).

## [v2.4.2] - 2026-06-05
### 추가
- **포메이션 편집기 — “무엇이 어디서 싸우나”**: 전투 목록에 이제 **포메이션(몬스터) 라벨**이
  전투별로 인라인으로 표시됩니다(예: `[m003 - Murussu, m003 - Murussu, m009 - Dingo]`). Lazy + 캐시 + cap (≤90개 전투
  표시; 목록이 가득 차면 지역별로 필터링하라는 메시지가 표시됨). 읽기 전용; 마스터플랜의 “해당 지역에 스폰되는 몬스터가 있는 구역
” 기능을 에디터에서 구현 (엔카운터↔가시적 구성의 통합).

## [v2.4.1] - 2026-06-05
### 추가됨
- **`FormationSlotWriter`** (`FfxLib/Battle`) — SAVE 경로(바이트 안전)를 추출하여 **Avalonia-free** 프로덕션 헬퍼로
  전환 (슬롯 전용 저장 + 1회 백업) `.spiraforge.bak` + write). 현재 Formation
  Editor에서 사용 중 (`PersistSnapshot`) **그리고** 헤드리스 게이트를 통해 테스트됨 — 중복 제거 로직, 에디터와 테스트에서 동일한 코드.
### 검증됨
- **`FormationSlotLab` — SAVE LIFECYCLE check** (**TEMP** 사본에 대한 생성 경로, 워크스페이스/애셋은 건드리지 않고,
  읽기 전용 유지): (a) 편집 없음 저장 = 디스크와 바이트 단위 동일 + 백업==원본; (b) 편집 저장 = 디스크에 슬롯만
  저장 + 재읽기 일치 + 백업 보존; (c) 백업 복원 = 바이트 단위 동일. **PASS.** v0.2의
  명백한 격차를 해소함 (디스크에 저장된 인앱 저장 기능 검증 완료, 되돌릴 수 있음). 코퍼스는 **858/858**을 유지함; `offline_ci` 4개의 게이트 통과.

## [v2.4.0] - 2026-06-05
### 추가됨
- **`EncounterTable_File.Rebuild`** (구조적) — 다음과 달리 `Write` slot-only: chunk1을
  Entries/Groups/Formations(가변 카운트 + 테이블 생성)에서 다시 생성하고, 새로운 dataOffsets를 할당하며,
  chunk0과 chunk-table을 재구성하고, **block-sharing**과 패딩을 유지합니다. Gate `--encounter-rebuild-rt0`. **구조적인
  "만남 만들기"의 기반.**
### 검증됨
- 만남 재구성 (`btl.bin` 96개 테이블 / 192개 그룹 / 863개 포메이션): **편집 불가 RT0 바이트 동일
  (4096/4096)** + grow-test (포메이션 1개 추가, 끝 주소 0x1000→0x1002, 2개의 청크 무결성 유지) **유효**.
- **TextTable 필드 문자열 라이터 인증됨** (`spcodedic.bin` 16/16 RT0) — 가족 잠금 해제 `TextTable_File`;
  **트레일링 패딩** 드리프트 수정. 솔직한 참고 사항: `help_txt.bin` StringExplorer에는
  이번 추출에서 ‘MORTOS’가 포함되어 있습니다(파일 없음) — 이 writer는 실제 필드 문자열에서 검증되었습니다(`spcodedic.bin`).

## [v2.3.2] - 2026-06-05
### 추가됨
- **AbilityCommandLab** (`RuntimeTools/AbilityCommandLab`) — 어빌리티 라이터의 RT0 게이트
  (`Ability_Command.ReadList`→`WriteList`), 그 `KernelCommands` 이미 저장에 사용하고 있지만 바이트 게이트 처리는 한 번도 받은 적이 없습니다.
  에디터 프로젝트(무거운 디버그 트리)를 참조하며, FfxLib의 정적 메서드만 호출합니다. 다음을 통해 연결되어 있습니다. `offline_ci.ps1`.
### 검증 완료
- **command.bin + item.bin (JP+US): 인증된 바이트 안전 라이터** — RT0 바이트 동일 4/4 + 1-플래그
  (1바이트) 4/4. **PASS.** 이는 “새로운 블랙 매직” 드림 기능(command.bin에 포함)의 검증된 기반입니다.
### 차단됨
- **monmagic1/2 (JP+US): 라이터 드리프트** (RT0 0/4 — 텍스트 파일 재포장 시 ~3–4KB 증가, firstDiff `@0x1C`). 원인:
  monmagic의 원본은 텍스트를 **공유/중복 제거**하며, `WriteList` 다시 첨부 (`FfxEncoding.WriteBytesIntoTextFile`
  단순히 append만 수행함; command/item은 순수한 append → 호환됨). **위험:** MonMagic의 Save는 `KernelCommands` 파일 크기가
  부풀어 오른다 — 중복 제거 기능을 지원하는 writer가 통과할 때까지 단계적으로 처리한다. 감사 + 수정 대상: `docs/reverse/FFX_ABILITY_WRITER_AUDIT_2026-06-05.md`.

## [v2.3.1] - 2026-06-04
### 추가 사항
- **Battle_File 리더의 안정성** — `Battle_File.Read` 이제 꼬리 청크가
  EOF 너머를 가리키는 15개의 btl_* 파일을 열어주세요 (`kino03_*`, `mihn05_*`, `cdsp00_02`): past-EOF 청크(및 그 이후 부분)를 전체 파일을 거부하는 대신
  없는 것으로 처리하며, 이전 청크(@2 형성 포함)는 유효한 상태로 유지됩니다. 이러한 배틀은 이제
  Formation Editor에서 편집할 수 있습니다.
### 유효성 확인됨
- Gate `FormationSlotLab`: writable이 843에서 **858/858**로 증가함 (읽기 실패 0회); RT0 858/858 + 슬롯 전용
  858/858 + 재읽기 858/858 **PASS**. 이전의 843개는 그대로 유지됨.

## [v2.3.0] - 2026-06-04
### 추가됨
- **SPIRA FORGE v0.2 — 포메이션 에디터** (`Modules/FormationEditor`): 허브의 첫 번째 EDITOR. btl_*의 포메이션에 포함된 8개의
  몬스터(16바이트)를 다음을 통해 변경합니다. `Battle_File.WriteWithFormationSlots`, **바이트 안전 슬롯 전용**.
  가시를 삼킨다 `FieldContext` (허브에서 선택한 필드 영역을 기준으로 배틀을 사전 필터링합니다). 몬스터 선택기
  (`Monster_Dictionary` + Empty, 원본의 상위 니블을 보존합니다). Save는 백업과 함께 워크스페이스에 루즈 파일을 저장합니다.
  `.spiraforge.bak` + 보관 `AssertSlotOnlyDiff`, 출처: `ByteSnapshotEditorSession` (되돌리기/취소). 오프라인, 프로브 없음.
- **Gate RT0 헤드리스** `RuntimeTools/FormationSlotLab` (의존성이 없는 프로덕션 파일만 링크),
  다음에 연결된 `offline_ci.ps1` (멈춤 `-BtlRoot`). 추가된 읽기 전용 멤버들 `Battle_File`
  (`FormationChunkOffset`/`FormationSlotsOffset`/`FormationSlotsLength`).
### 검증됨
- `FormationSlotLab` 코퍼스 내에서 `btl`: RT0 843/843 + 슬롯 전용 843/843 + 재읽기 843/843 **PASS** (라이터 바이트 안전).
  (당시 리더에서 15개의 btl_*을 파싱할 수 없었음 — v2.3.1에서 수정됨.)

## [v2.2.0] - 2026-06-04
### 추가됨
- **SPIRA FORGE 0단계 v0.1 — Field Hub** (`Modules/SpiraForgeHub` + `Services/FieldContext.cs`): 탐색
  메뉴는 다음을 기준으로 구성됩니다. `field_token`. CSV 브릿지를 통해 데이터를 가져오는 필드 선택기
  (`ps3data-map-btlmap-fieldid-bridge.csv`, 357개 필드, **structural-candidate**). 다음에서 공개된 필드를 선택하세요.
  `FieldContext` (관측 가능한 싱글톤)과 2명의 읽기 전용 소비자: **맵 딥링크**
  (`?map=map/<area>/<field>` (FFXMapViewerWeb용) + **전투 미리보기** (읽기 `btl.bin` 출처: `EncounterTable_File`,
  join 후보 지역↔지도). csproj를 통해 출력으로 복사된 CSV `<Content>`. 오프라인; 피커는 프로젝트 없이 실행됩니다.
  라이터도, 프로브도 없습니다.
### 검증됨
- 빌드 오류 0개; 화면에서 검증됨 (필드 `azit03` → 피커 + 딥링크 + BTL.bin의 실제 데이터를 활용한 엔카운터 엿보기).
  스크린샷 `work/spira_forge_qa/field_hub_v01.png`.

## [v2.1.1] - 2026-06-04
### 검증됨
- **PlayerKernel 작성자** (`PlayerKernel_File.WriteSave`/`WriteRom`) 새로운 게이트를 통해 바이트 단위로 정확하게 검증됨
  `--player-rt0`: `ply_save.bin` (3098) + `ply_rom.bin` (2161) -> **편집 불가 RT0 바이트 동일**. (라이터는
  이미 슬롯 전용으로 존재했으나, 이제 **게이트 처리**되었습니다.)

## [v2.1.0] - 2026-06-04
### 추가됨
- **EncounterTable 라이터** (`EncounterTable_File.Write`) — 읽기 전용 -> 읽기-쓰기 **슬롯 전용**: 다음을 유지합니다.
  `btl.bin` 바이트 단위로 처리하고 편집 가능한 필드만 다시 스탬프 처리합니다 (table `Id`/`Unknown0C`, 그룹
  `Battlefield`/`Danger`/`TotalWeight`, 교육 `Id`/`Weight`). 게이트 `--encounter-rt0` 편집기에서.
### 유효성 검사 완료
- `battle/kernel/btl.bin`: 96개 테이블 / 192개 그룹 / 863개 구성 -> **편집 불가 RT0 바이트 동일 (4096/4096)**.

## [v2.0.0] - 2026-06-04

> **새로운 시대 — 메이저 업데이트.** 에디터가 "파일 오프라인 편집"에서 **실시간 런타임 편집**으로 진화했습니다
> 검증 완료**로 진화했습니다: RAM에서 몬스터 AI 바이트코드를 편집하고 **화면**에서 행동이 변화하는 것을 확인할 수 있으며, 크래시 없이,
> 되돌릴 수 있습니다 — 프로젝트의 **최고의 목표 #1**이 실현되었습니다. MAJOR = 새로운 **기능 등급** (
> 계약/저장/빌드 위반이 아닙니다 — 단지 기능을 추가하고 안정성을 강화했을 뿐입니다). `-beta` RT2/God-Mode가 아직
> 게이트가 적용된 UI로 상용화되지 않았기 때문입니다. **Claude Code / VSCode + Codex 2차 계정 연동**의 이정표.

### 하이라이트
- 🏆 **화면에서 검증된 RT2 라이브 AI 편집:** RAM에서 실시간으로 몬스터 AI 바이트코드를 편집 (DINPUT8 프로브),
  화면에서 행동이 변경됨 — **Flame Flan Firaga→Thundaga**, 크래시 없이, 되돌릴 수 있음. 체인: `enemy-list`
  (`0xD34460`) → `MemoryChr.Ptr_script_chunks` (`+0xF78`) → AiFile 라이브 **=== `m0NN.bin` 바이트 단위로 동일한 디스크**.
- 💉 **어떤 몬스터에게든 어떤 어빌리티든 주입 (라이브):** id `performCommand` = `(cat<<12)|abilityId`
  전역 스킬을 발동한다 — 몬스터가 해당 스킬을 “가지고” 있을 필요는 없다. 증거: **스콜이 이프릿의 헬파이어를** 화면에 뱉어냈다.
- 🐉 **실시간 적 편집:** 몬스터를 **다크 시바**로 변환 (ID + 실제 스탯 + 1.1M/4M HP),
  **자동 스캔**, **주사위 부활** (사망 플래그 + KO), 모든 것이 `MemoryChr` + probe.

### 추가됨
- **AI 어셈블러** — `AiScript_File.AppendCode`: 지침을 첨부하고 **데이터 섹션의 모든 오프셋을
  재배치** (+delta) → 더 크고 유효한 AiFile (“IA 추가” 경로, 로컬 바이트 예산 외).
- **AI 제어 흐름 편집기** (float/int const + 점프 대상), 바이트 로컬, `AiScript_File`.
- **모듈 `Monster AI Editor`** (Avalonia): 주석이 달린 디스어셈블러 (147개 호출 + 73개 필드 + 부동소수점 변수 + 변수 +
  점프 레이블 + 추론된 워커 유형), 피연산자 편집 + 로스 파일 저장.
- **`FfxProbe_Service`** — bridge editor↔probe DINPUT8 (메인 스레드에서 READ/WRITE/CALL, ASLR 안전).
- mod/RE 문서: `FFX_AI_RT2_LIVE_EDIT_PROVEN`, `FFX_LIVE_INGAME_EDITOR_MOD_IDEA` (전투의 갓 모드),
  `FFX_MUSIC_SYSTEM_AND_MOD_IDEA` (Music Remapper), `FFX_AI_BYTECODE_OPCODE_TABLE_PROVEN`,
  `CODEX_MAPVIEWER_WATCH_JARVIS`, `FFX_MAP_DEVELOPMENT_TOOL_MASTERPLAN` (Spira Forge).

### 변경/검증됨
- **`Monster_File.Write` 수리됨 → 게이트 `--monster-rt0`: 361/361 바이트 동일** (이전에는 0/361):
  StatSheet/Loot에서 preserve-only 적용 + 헤더의 서명/패딩 보존 (패딩이 겹쳤음) `AiFile[0..3]`).
- **AI 코덱** `AiScript_File`**: RT0 361/361 + oracle-parity 디스어셈블리 + CI 오프라인 (`offline_ci.ps1`).
- IDA에 저장된 VM ATEL (`FFX_Atel_*`, `g_FFX_Atel_VmContext`, 액터, FMOD 플레이어 처리).

### 차단됨 / 연기됨 (솔직히)
- **실시간 3D 모델 / 시각적 리바이브** = 모델 뷰어 레인 (Codex); 플래그 `MemoryChr` 렌더링을 다시 생성하지 않습니다.
- **실시간 음악 변경** = FMOD API는 `__thiscall`, probe는 cdecl 전용 → probe에 op thiscall이 필요함
  (게임을 종료한 상태에서 재빌드). 발견된 플레이어: `FFX_FmodMusic_PlayTrackByIndex` (181 트랙); PS2의 FIFO SPU는 하드디스크에 스텁으로 연결되어 있습니다.
- **무거운 어빌리티를 발동**할 때 자산이 로드되지 않으면 **크래시**할 수 있습니다(다크 이프릿의 헬파이어로 인해 게임이 멈췄습니다).
- **God Mode 모듈** = 라이브 테스트를 거쳤으나, 아직 게이트가 포함된 UI로 정식 구현되지는 않았습니다.

### Labs에서 가져옴 / 다중 에이전트
- Arco **Claude Code / VSCode** (AI 에디터 캠페인: ATEL 코덱 100% 디코딩 → RT2 라이브)에
  **2번째 Codex 계정과의 통합** (MapViewer 레인 / 모델-텍스처): 익스포터가 머티리얼-롤 신호를 노출
  (TextureSampler1/normalMap/reflection/water/PhyreWaterShader), 외부 뷰어
  (**glTF-Sample-Viewer**를 오라클로 사용; 갭은 익스포터 측에서 확인됨, 쉘이 아님) 및 마스터플랜
  **Spira Forge**의 시작. 다중 에이전트 협업 `docs/ai/CODEX_MAPVIEWER_WATCH_JARVIS.md`.

## [v1.7.0] - 2026-06-04
### 추가 사항
- **AI Assembler (AI를 100% 자유롭게 편집)** — 두 가지 기본 요소가 `AiScript_File`:
  - **`AppendCode`**: 마지막에 지침을 첨부하고 데이터 섹션을 재배치합니다.
  - **`Rebuild`**: **어디에서나** 명령어를 삽입/제거/편집** + 모든
    **점프 + 진입점** (링크어 old→new) + 데이터 섹션을 자동으로 재배치합니다. 고아 분기 (명령어 제거) -> 명백한 오류.
### 검증됨
- `m337` (Dark Shiva): **no-edit Rebuild = 바이트 단위 동일 (RT0)**; 중간에 삽입 -> `codeLen +3`, walk 종료,
  작업자들이 해결, **삽입 후 엔트리포인트가 재배치됨 `0x2D1`→`0x2D4` 혼자**; grow-test (AppendCode) RT0.

## [v1.6.0] - 2026-06-04
### 검증됨
- **`Monster_File.Write` 수리됨 -> 게이트 `--monster-rt0`: 361/361 바이트 동일** (이전 0/361): StatSheet/Loot에서 '보존 전용'
  + 보존 `Signature`/`Padding` 헤더에서 (패딩이 겹쳐서 `AiFile[0..3]`).

## [v1.5.0] - 2026-06-04
### 검증됨 / 차단됨
- **사운드 시스템 RE'd:** FMOD 플레이어 **`FFX_FmodMusic_PlayTrackByIndex`** (181곡) 발견됨; **라이브
  음악 차단됨** (API `__thiscall`, cdecl 전용 프로브). 문서 `FFX_MUSIC_SYSTEM_AND_MOD_IDEA` (Music Remapper).

## [v1.4.0] - 2026-06-04
### 검증 완료 (실전 적용)
- **몬스터 간 능력 주입 기능 검증 완료:** `performCommand` id = `(cat<<12)|abilityId` 능력을 발동한다
  GLOBAL — 몬스터가 해당 능력을 “가지고” 있을 필요는 없다. 증거: **스콜이 화면에 이프릿의 헬파이어를 뱉어냈다**.

## [v1.3.1] - 2026-06-04
### 수정 / 검증 완료 (실전 적용)
- 적의 실제 체력 회복을 통해 `Hp@0x5D0` (아니 `Current_hp`); **KO** 청소 (`Status_suffer`); 데이터 복원
  정제됨 (사망 플래그). **자동 스캔** (상태 `Scan`) 라이브 적용.

## [v1.3.0] - 2026-06-04
### 검증 완료 (라이브)
- **적을 다크 시바로 변환** (라이브): `Id` + 실제 통계 `m337` + **1.1M/4M HP**, 출처: `MemoryChr`
  (`POINTER_BATTLE_ENEMY_LIST 0xD34460`, stride `0xF90`) + probe.

## [v1.2.0] - 2026-06-04
### 추가됨
- **모듈 `Monster AI Editor`** (Avalonia): 주석이 달린 디스어셈블러 (147개 호출 + 73개 필드 + 부동소수점 + 변수 +
  점프 라벨) + 피연산자 편집 + 분리 파일 저장.
- **AI 제어 흐름 편집기** (float/int const + 점프 대상), 바이트 단위.
- **`FfxProbe_Service`** — 브리지 에디터<->프로브 DINPUT8 (메인 스레드에서 READ/WRITE/CALL, ASLR 안전).

## [v1.1.0] - 2026-06-04
### 검증 완료 (🏆 HEADLINE — 최우선 목표 #1)
- **RT2 라이브 AI 편집 화면상 검증:** **라이브 RAM**에서 몬스터 AI 바이트코드 편집 (DINPUT8 프로브) ->
  화면상의 동작이 변경됨 (**Flame Flan Firaga→Thundaga**), 크래시 없이, 되돌릴 수 있음. 체인: `enemy-list
  0xD34460` -> `MemoryChr.Ptr_script_chunks +0xF78` -> AiFile vivo **=== `바이트 단위 복제본** 디스크의 `m0NN.bin`.
  문서: `docs/reverse/FFX_AI_RT2_LIVE_EDIT_PROVEN_2026-06-04.md`.

## [v1.0.0] - 2026-06-01

이 편집기가 지식의 열람, 검증 및 탐색을 위한 실질적인 플랫폼으로서 성숙 단계에 접어들었으며, 다음과 같은 기능을 갖추고 있습니다. `Extras` ~를 정당화하기에 충분한 `1.0` 런타임, AI, 신체 재현 문제가 해결된 척하지 않고 솔직하게 말하자면.

### 주요 내용
- 이 에디터는 더 이상 단순한 도메인별 에디터 모음이 아니라, 통합 플랫폼으로도 기능하게 되었습니다. `read-only exploration`.
- 선 `Extras` 현재 쉘 내에서 6개의 실제 전선을 담당하고 있습니다:
  - `PS2 Knowledge`
  - `Textures (TM2 + TXC/CLT/FMT/SPS2 support lane)`
  - `BIN-FTC Atlas`
  - `Project / Pipeline`
  - `Magic Effects`
  - `Presentation Containers`
  - `Battle Corpus Crosswalk`
- 이 프로젝트는 이제 읽기 자료, 아틀라스, 출처 정보가 충분히 확보되어 다음과 같이 취급될 수 있습니다. `1.0` 검증 플랫폼으로서의 편집자.

### 추가됨
- `Pt67` ~처럼 `Extras / Magic Effects`, 다음을 포함하여:
  - `MagicPackageViewer`
  - `BatEffPackageViewer`
  - `MagicEffectCrosswalkExplorer`
- `Pt57` ~처럼 `Extras / Presentation Containers` ~을 위해 `.vpa/.ebp/.omd/.sps2`.
- `Pt44` ~처럼 `Extras / Battle Corpus Crosswalk` ~을 위해 `formation -> actor row -> corpus`.
- ~의 확장 `Pt52` 다음과 같이:
  - `FtcHeaderInspector`
  - `BinSidecarGraph`
  - `Signature Group` 셸에서
- ~의 전개 `Pt56` 다음과 같이:
  - `TxcCltPairExplorer`
  - [출처]의 메타데이터 `fmt` 그리고 `sps2`
- `docs/history/PS3DATA_CHECKLIST_MASTER_2026-06-01.md` 트리 마스터 체크리스트로서 `ps3data`.
- `docs/history/EDITOR_READONLY_ABSORPTION_REPORT_2026-06-01.md` 표면 읽기 전용(surface read-only)이 될 수도 있고 그렇지 않을 수도 있는 모든 항목에 대한 지도와 같은 역할을 합니다.

### 변경 사항
- 앱 버전이 다음과 같이 업데이트되었습니다. `1.0.0`.
- o `PS2 Knowledge` 이제 레지스트리 자체에 ~의 생생한 존재가 반영된다 `Pt44`, `Pt57` 그리고 `Pt67`.
- 다음 사항에 대한 점검: `Extras` 새로운 표면에서 ‘뿌리’ 스크롤을 획득하고, 이름 표기가 덜 어색해졌습니다.
- `PORT_STATUS.md`, `KNOWLEDGE_BASE.md` 그리고 `docs/history/README.md` 이제 공식적으로 ‘웨이브’를 인정하고 있다 `1.0`.

### 검증됨
- 빌드 `Release` 웨이브와 함께 지나갔다 `1.0.0`.
- 선 `Extras` 이어서 다음과 같이 명시하고 있다:
  - `read-only`
  - `do not promote`
  - `no runtime proof` 적절한 곳에
  - `pipeline/support only` 적절한 곳에

### 참고 사항
- 이 `1.0` 이는 독서 및 검증 플랫폼으로서 편집자의 성숙함을 의미합니다.
- 이 `1.0` 다음과 같은 의미는 아닙니다:
  - `magic solved`
  - `AI solved`
  - `ModelViewer playback solved`
  - writer 정식 출시

## [v0.11.0-beta.2] - 2026-06-01

제품 라인의 실질적인 발전 `Extras` 에서 `main`.

### 주요 내용
- `Extras` 편집기에서 단순한 평면이 아닌 살아있는 표면으로 변했습니다.
- 셸이 이제 동반 루트를 인식합니다:
  - `master`
  - `ffx_ps2`
  - `ps3data`
- PS2 읽기 전용 제품의 첫 번째 물량이 이제 UI에 표시됩니다:
  - `PS2 Knowledge`
  - `Textures (TM2)`
  - `BIN-FTC Atlas`
  - `Project / Pipeline`

### 추가됨
- 공동 설립 `Extras`:
  - `ExtrasSourceResolver`
  - `ExtrasEvidenceBadgeModel`
  - `ExtrasProvenanceModel`
  - `ExtrasReadonlyBoundaryModel`
  - `ExtrasFileOpenService`
- `Extras / PS2 Knowledge` PS2 캠페인의 읽기 전용 허브로서.
- `Extras / Textures (TM2)` ~의 첫 번째 솔직한 시각적 표면으로서 `Pt56`.
- `Extras / BIN-FTC Atlas` ~의 읽기 전용 브라우저로서 `Pt52`.
- `Extras / Project / Pipeline` 의 초기 표면으로 `Pt54`, 다음을 포함하여:
  - `CdIndexExplorer`
  - `ProjectDescriptorViewer`
  - `AbmapSupportGraph`
- 워크숍/파일 그룹별 새 가이드 `ffx_ps2`:
  - `docs/history/PT52_BIN_FTC_FILE_MEANING_GUIDE_2026-06-01.md`
  - `docs/history/PT53_BATTLE_MAGIC_FILE_MEANING_GUIDE_2026-06-01.md`
  - `docs/history/PT54_PROJECT_ABMAP_FILE_MEANING_GUIDE_2026-06-01.md`
  - `docs/history/PT56_TEXTURE_PALETTE_FILE_MEANING_GUIDE_2026-06-01.md`
  - `docs/history/PT57_PRESENTATION_CONTAINER_FILE_MEANING_GUIDE_2026-06-01.md`
  - `docs/history/PT58_FFX_PS2_OWNERSHIP_AND_LINKAGE_GUIDE_2026-06-01.md`

### 변경 사항
- 앱 버전이 다음과 같이 업데이트되었습니다. `0.11.0-beta.2`.
- `Pt54` 더 이상 ~가 아니었다 `implementation-ready` 그리고 실수 모듈로 셸에 접속하여 `Extras`.
- `Pt58` 이제 이 기능은 소프트웨어에서 단순한 개념이 아니라, 배지, 출처 및 읽기 전용 경계를 갖춘 탐색 가능한 허브로 나타납니다.
- `KNOWLEDGE_BASE.md` 그리고 `docs/history/README.md` 이제 새로운 냉장 가이드들을 색인화하고 있습니다. `ffx_ps2`.

### 검증 완료
- 에디터의 릴리스 빌드가 새로운 모듈을 통해 `Project / Pipeline`.
- 선 `Extras` 계속 읽기 전용 상태로 유지되며 저장됨:
  - 라이터 없음
  - 재패키징 없음
  - 최종 디코딩 클레임 없음
  - 콜드 리서치와 런타임 증명을 혼합하지 않음

### 참고 사항
- `Pt53` 여전히 마법 축의 강력한 보스로 군림하고 있다:
  - `kernel -> mag_* -> bat_eff`
- `Pt55` 여전히 가드레일에 부착된 상태로 `Pt9`.
- `Pt57` 여전히 중요한 콜드 아틀라스이지만, 아직 심층적인 해독은 이루어지지 않았다.

## [v0.10.0-beta.1] - 2026-05-31

통합 베타 버전 `main` 공방들의 첫 번째 대규모 흡수 물결이 끝난 후.

### 주요 내용
- `Shop Explorer` 카탈로그, 실제 삽화, 그리고 보수적인 관점에서 선별된 작가들의 작품을 통해 주류에 진입했다.
- `RuntimeTools/StepBridgeLab` 그리고 `RuntimeTools/RuntimeInspectorLab` 쉘의 시작 과정을 방해하지 않고 독립형 툴링으로 포함되었습니다.
- `ProductionSafetySmoke` 더 이상 문제 있는 가족들을 숨기지 않고, 이를 입증하기 시작했다 `Read`, `No-Edit Byte Identity` 그리고 `Reread` ~을 위해 `important.bin` 그리고 `a_ability.bin`.
- `README` 그리고 현재 공개된 스크린샷들은 현재 셸을 반영하고 있습니다. `main`, 낡은 작업장 유산을 물려받지 않는다.

### 추가됨
- 흡수 `Pt8 / ShopAndWeaponNameResearchLab` 에서:
  - `Shop Explorer`
  - `FfxLib/Shop`
  - `Assets/Shop`
  - 저장된 작가: `item_shop.bin` 그리고 `arms_shop.bin`
- 흡수 `Pt12 / StepBridgeLab` 에서 `RuntimeTools/StepBridgeLab`;
- 흡수 `Pt13 / RuntimeInspectorLab` 에서 `RuntimeTools/RuntimeInspectorLab`;
- 흡수 `Pt17 / SaveSafetyLab` 에서 `ProductionAuditTools/ProductionSafetySmoke`;
- 슬라이스의 안전한 흡수를 위한 `Pt21 + Pt22` 에서:
  - `NameDescriptionTextPrefixTable_File`
  - `reader + no-edit guard` ~을 위해 `important.bin`
  - `reader + no-edit guard` ~을 위해 `a_ability.bin`
- `docs/history/PT21_PT22_READER_NOEDIT_GUARDS.md` 해당 부분의 생산 결정 로그로;
- `ReadmeAssets` 다음으로 업데이트됨 `6` 현재 빌드의 추적 가능한 캡처.

### 변경 사항
- `KeyItemEditor` 공개적으로 재분류되어 `Guarded`, 구조적 분석과 편집 금지 보장에 중점을 두고;
- `AutoAbilityEditor` 공개적으로 재분류되어 `Guarded`, 동일한 보수적 관점을 바탕으로;
- `PORT_STATUS.md` 그리고 `docs/history/PRODUCTION_ABSORPTION_MATRIX.md` 이제 명확하게 구분된다 `reader + no-edit guard` ~의 `writer-safe`;
- `README` 현재 쉘에 대해 재심리가 진행되었으며, `main`;
- `CHANGELOG` 그리고 `changelogUS` 주요 노선의 새로운 안정화 단계를 반영하게 되었다.

### 검증됨
- `Shop Explorer` 그리고 저장된 그 클립은 이제 다음의 공식 화면을 구성하게 되었는데, `main`;
- `StepBridgeLab` 그리고 `RuntimeInspectorLab` 주 트리에 독립된 도구로 추가되었습니다;
- `ProductionSafetySmoke` 전시하기 시작했다 `important.bin` 그리고 `a_ability.bin` 구조적 분석이 정확하고 편집 없이 바이트 식별자가 유지된;
- o `README` publico는 이제 완전히 새롭게 재탄생한 Windows Surface를 다음과 같이 설명합니다. `main`;
- 모든 스크린샷은 `README` 현재 쉘에서 나온 것이지, 오래된 작업장 자료에서 나온 것이 아닙니다.

### Deferred
- `Pt16 / Slice 1` 별도의 브랜치에서는 준비가 완료되었지만, 아직 `main`;
- `Pt14` 그리고 `Pt15` 이번 릴리스에서는 실제 코드 통합 없이 런타임/디버그/아키텍처 측면에서 유용한 기능으로 남아 있습니다;
- `AI Probe` 그리고 `Pt6 / BattleStructureLab` 여전히 우선순위는 높지만, 아직 런타임/AI 측면에서 더 큰 릴리스를 주장하기에는 부족합니다.

### 차단됨
- `btl_txt.bin` writer 및 encode에 대해서는 여전히 차단된 상태입니다;
- `w_name.bin` 일반 작성자에게는 계속 차단된 상태입니다;
- `Field String` 앱에서 계속 잠겨 있습니다;
- `important.bin` 그리고 `a_ability.bin` mutation-safe 작성자에 대한 공개 클레임은 여전히 차단된 상태입니다.
- 범위의 오라클 결과: `Pt22` 그 자체만으로는 작가의 홍보를 허용하지 않습니다;
- `Repeat Exact Encounter` 그리고 런타임/AI 분야의 주요 흐름들은 여전히 본격적인 대중화 단계에 이르지 못하고 있다.

## [v0.9.0-beta.1] - 2026-05-31

에디터와 이를 둘러싼 생태계의 실제 규모를 솔직하게 반영한 첫 번째 버전입니다.

### 메인 브랜치 주요 내용
- 공식 등록 `main` ~처럼 `v0.9.0-beta.1`;
- 비공개 Git 베이스라인을 보존하고 버전 관리됨;
- `PORT_STATUS.md` 생산 흡수량의 실시간 원장 역할을 하게 됩니다;
- `docs/governance/` 워크플로우, 버전 관리 및 다음 작업 순서를 통합합니다;
- `docs/history/` 레지스트리, 브랜치 맵, 타임라인 및 흡수 매트릭스를 통합합니다.

### 메인 파일에 존재하는 프로덕션 서피스
- `Monster Editor`;
- `Battle Explorer`;
- `Sphere Grid Explorer`;
- `Sphere Grid Editor v1`;
- `Encounter Table Explorer`;
- `Monster AI Explorer`;
- `String Explorer` 안전한 Writer를 사용하여 `Monster Localizations 1/2/3`;
- `Live Battle Lab`;
- `PlayerGrowthEditor`;
- `CtbBaseEditor`;
- `MixTableEditor`;
- `KeyItemEditor`;
- `AutoAbilityEditor`;
- `Shop Explorer` 저장된 슬라이스가 있는 `Shop`.

### 워크숍에서 얻은 내용
- `Pt3 / TextLab`
  - `TextLabTools`;
  - `ProductionAuditTools`;
  - 텍스트/몬스터용 하네스 및 릴리스(보수적).
- `Pt5 / KernelTablesLab`
  - `PlayerGrowthEditor`;
  - `CtbBaseEditor`;
  - `MixTableEditor`;
  - 이를 뒷받침하는 역사적 맥락 `KeyItemEditor`.
- `Pt7 / AutoAbilityLab`
  - `AutoAbilityEditor`;
  - 보수적인 파서 `AutoAbility_File.cs` 그리고 `Arms_Rate.cs`.
- `Pt8 / ShopAndWeaponNameResearchLab`
  - `Shop Explorer`;
  - `FfxLib/Shop`;
  - `Assets/Shop`;
  - 저장된 작가: `item_shop.bin` 그리고 `arms_shop.bin`.

### 거버넌스 및 버전 관리
- `docs/history/PT_VERSIONING_REGISTRY.md`;
- `docs/history/PT_BRANCH_MAP.md`;
- 다음 작품들의 편집용 미니 버전: `Pt2` a `Pt20`;
- 워크숍별 역사 태그;
- 프로덕션 환경에 대한 브랜치/커밋/변경 내역 정책이 정의됨.

### 검증됨
- 의 비공개 기준선 `main` 다음과 같이 게시됨 `baseline-2026-05-31`;
- 오디오 아래 `Git LFS` 에서 `FFXProjectEditor/Assets/Audio/**`;
- 빌드 `Release` 주 라인;
- 부분적인 흡수 `Shop` 보수적인 절제 범위에서 기술적으로 검증됨;
- `AutoAbilityEditor` 보수적인 게이트를 통해 검증됨;
- 텍스트 툴킷 및 이미 생산 라인에서 처리된 몬스터 스트링의 안전한 추출.

### 여전히 차단됨
- `btl_txt.bin` writer/serializer/encode;
- `Field String` 작가;
- `w_name.bin` 작성자;
- blind port의 `LiveBattleLab`, `MemSharp_Service.cs` 그리고 `MemoryBtl.cs` labs에서 제공;
- `ModelViewer v2` 최종 시청자로서;
- 홍보 `Repeat Exact Encounter` 마치 이미 입증된 것처럼.

### 왜 아직 베타 버전인가
- `Pt6 / BattleStructureLab` 여전히 관찰적 증거에 치우쳐 있으며, 명확하게 통합되지 않음;
- `Pt9 / ModelViewerLab` 아직 최종 확정된 정적 뷰포트가 없는 상태입니다;
- `Pt12` a `Pt20` 아직 툴링, 하드닝, 전략 및 거버넌스 단계가 마무리되고 있는 중입니다;
- 런타임, AI, 메모리 분야에는 여전히 실질적인 통합이 진행 중인 강력한 흐름이 있습니다.

## 역사적 의미 재구성

중요한 편집자 주:

- 아래 항목들은 역사적 과정을 기록하고 있습니다 `v0.1.0` a `v0.8.0-beta.1` 프로젝트에 대한 통합된 해석으로서;
- 이들은 실제 과거의 Git 태그와 일치하지 않는다;
- 이들은 편집기가 이미 한 개보다 훨씬 더 컸다는 사실을 지우지 않기 위해 존재한다 `v0.1.0` Git이 도입된 시점의 리터럴;
- 이 사다리를 조립하는 데 사용된 근거는 `PRODUCTION_V2_HANDOFF.md`, `FFX_PRIORITY_BUILD_MANIFEST.md`, `PORT_STATUS.md`, `PROJECT_HISTORY_MASTER.md`, `WORKSHOP_TIMELINE.md`, `PRODUCTION_ABSORPTION_MATRIX.md`, `PT_VERSIONING_REGISTRY.md` 및 워크숍의 인수인계.

## [v0.8.0-beta.1] - 역사적 재구성 (Git 공식 SemVer 이전)

이 생태계가 이미 대규모의 모듈식 편집기로서, 여러 전문 분야가 동시에 활발히 운영되는 단계에 접어든 시점.

### 이 단계의 주요 화면
- `Monster Editor`;
- `Battle Explorer`;
- `Sphere Grid Explorer`;
- `Sphere Grid Editor v1`;
- `Encounter Table Explorer`;
- `Monster AI Explorer`;
- `String Explorer` 안전한 경로를 따라 `Monster Localizations`;
- `Live Battle Lab`;
- 강력한 커널 라인업과 `PlayerGrowthEditor`, `CtbBaseEditor` 그리고 `MixTableEditor`.

### 생태계 부담
- `Pt2 + Pt9` 놓다 `ModelViewerLab` 진정한 정찰 및 실제 인계 단계에서;
- `Pt8` 닫기 `Shop` 슬라이스를 잘 방어하고 정직하게 막아낸다 `w_name.bin`;
- `Pt6` 이미 ~에 대한 대화를 주도하고 있다 `runtime + AI + proof`;
- 이 제작물은 더 이상 “그저 또 하나의 에디터”로 보이지 않고, 커뮤니티의 평균 수준을 훨씬 뛰어넘는 모딩 생태계로 거듭납니다.

### 여전히 부족한 점
- `ModelViewer v2` 최종 뷰포트로;
- `Repeat Exact Encounter` 입증됨;
- `w_name.bin` 작가;
- `btl_txt.bin` 광범위한 작성자;
- 런타임용 대규모 툴링의 원활한 통합.

## [v0.7.0] - 역사적 재구성 (Git 도입 전 공식 SemVer)

주 흐름이 “더 많은 모듈”에서 “더 많은 시험”으로 바뀌는 지점.

### 추가됨
- `BattleStructureLab` 구형 웨이브 시리즈 중 기술적으로 가장 복잡한 모델이 되었습니다;
- `BattleRuntimeProbe`, 시퀀싱 워처와 셀렉터/뱅크의 나링이 핵심 논의 주제로 떠오른다;
- `Force Battle / Repeat Encounter` 더 이상 희망적 사고에 그치지 않고 실제 관찰 실험으로 다루어지게 된다.

### 변경 사항
- 공식적인 우선순위가 다음과 같이 변경됨: `runtime + AI + proof`;
- 제작진은 이제 ‘엔카운터 리플레이’가 여전히 더 많은 `Repeat Route (Unsafe)` 보다 `Exact Encounter`;
- 프로젝트의 위험 수준이 높아진다.

### 아직 안전하지 않음
- [ ]의 맹목적 병합 `runtime/memory`;
- 정확한 리플레이 재생;
- 작업장 총 운반비 `Pt6` ~을(를) 위한 `main`.

## [v0.6.0] - 역사적 재구성 (Git 도입 전 공식 SemVer)

커널 라인과 보조 시스템에 대한 보수적인 강화가 더 이상 약속에 그치지 않고 본격적인 편집기의 일부가 된 마일스톤.

### 추가됨
- `AutoAbilityEditor` 보수적인 게이트를 갖춘 독자적인 라인으로 성장한다;
- `KeyItemEditor` 실제 흡수 범위에 들어간다;
- 생산은 이미 다음과 더 원활하게 연동된다 `Customization / Aeons` 및 기타 리밸런싱 블록.

### 변경 사항
- 포지션 전략이 “랩에서 복사하기”에서 “검증된 전략을 흡수하기”로 변경됨;
- 다음과 같은 모호한 바이트들: `62h..67h` 계속 유지되게 된다 `raw/read-only` 임의로 지어낸 의미를 부여하는 대신;
- 커널 라인은 더 이상 실험적 단계가 아니며, 더 엄격한 편집 기준을 적용받게 됩니다.

### 여전히 누락된 항목
- `Shop` 정직한 작가;
- `w_name.bin` 안전함;
- 다음 물결에 충분히 대응할 수 있을 만큼 강력한 런타임 계측 기능.

## [v0.5.0] - 역사적 재구성 (Git 공식 SemVer 도입 전)

강력한 물결의 전환점은 `KernelTablesLab`.

### 추가됨
- `PlayerGrowthEditor`;
- `CtbBaseEditor`;
- `MixTableEditor`;
- 성숙한 트레일 `KeyItemEditor`;
- 초기 준비 상태: `Auto-Abilities`, `Item Shop / Gear Shop` 그리고 `w_name.bin`.

### 변경 사항
- 에디터가 더 이상 전투/몬스터 표면에만 의존하지 않고, 실제로 주목할 만한 커널 레이어를 갖추게 되었습니다;
- 리밸런싱 모딩의 상당 부분이 자체 UI에서 가능해졌습니다;
- 향후 더 정교한 통합을 위한 기반이 마련되었습니다.

### 여전히 부족한 점
- 최종 검증 `Auto-Abilities` 생산 과정에서;
- `Shop` 보수적인 작가로서;
- 신뢰할 수 있는 의미론 `w_name.bin`.

## [v0.4.0] - 역사적 재구성 (Git 도입 전 공식 SemVer)

프로젝트가 실제 판단 기준에 따라 텍스트에서 “예”와 “아니오”를 표현하는 법을 배우게 된 마일스톤.

### 추가됨
- `TextRegressionHarness` 회귀 요법으로서;
- 안전한 게이트로 `Name / Description`;
- 안전한 게이트를 통해 `Monster Localizations 1/2/3`;
- 이후 다음과 같은 결과로 이어지게 될 툴링 `TextLabTools` 그리고 `ProductionAuditTools`.

### 변경 사항
- 이전에는 일반적으로 다음과 같이 불리던 텍스트 형식 `Unsupported` 다음과 같이 구분됩니다:
  - `reader provado`;
  - `writer conservador`;
  - `blocked`;
- `Field String` 그리고 `btl_txt.bin` 더 이상 “거의 다 된” 것처럼 낭만적으로 묘사되지 않게 된다.

### Still Missing
- 작가: `Battle Text`;
- 정직한 잠금 해제 `Field String`;
- 잘 알려지지 않은 문자 집합에 대한 인코딩 안전성.

## [v0.3.0] - 역사적 재구성 (Git 이전 공식 SemVer)

에디터가 단순한 파일 브라우저를 넘어 AI, 런타임 및 높은 게임플레이 가치를 지닌 인터페이스를 다루기 시작한 시점.

### 추가됨
- `Monster AI Explorer`;
- 본격적인 첫 번째 단계는 `Live Battle Lab`;
- 파서 코퍼스, 명령어, 강제 동작 및 활성 상태 간의 연계가 더욱 강화됨;
- 인카운터 및 스크립트 동작 검색을 위한 표면이 개선됨.

### 변경 사항
- AI가 더 이상 부차적인 주제가 아닌 제품 우선순위가 됨;
- 런타임 검증 개념이 에디터의 핵심 DNA로 완전히 자리 잡음;
- 이 프로젝트는 거의 아무도 제공하지 않는 기능을 제공함으로써 커뮤니티와 더욱 명확하게 차별화됨.

### 여전히 부족한 점
- 더 심층적인 턴별 검증;
- 안전한 AI 패치 기능;
- 정확한 엔카운터 툴링.

## [v0.2.0] - 역사적 재구성 (Git 도입 전 공식 SemVer)

대규모且가시적인 시스템을 위한 에디터의 구조적 확장의 이정표.

### 추가됨
- `Sphere Grid Explorer`;
- `Sphere Grid Editor v1`;
- `Encounter Table Explorer`;
- 전투 구조 및 만남 표를 위한 더욱 견고한 표면.

### 변경 사항
- 에디터가 “몇 개의 강력한 도메인” 단계에서 벗어나, 탐색 가능한 여러 개의 넓은 영역을 갖춘 도구로 발전했습니다;
- 게임 도메인 간의 탐색이 더욱 일관성 있게 개선되었습니다;
- 이 프로젝트는 모딩 제품군으로서 실질적인 위상을 갖추게 되었습니다.

### 여전히 부족한 점
- `Encounter Table Editor`;
- 공격적인 스피어 그리드 토폴로지;
- 더욱 심도 있는 AI/런타임.

## [v0.1.0] - 역사적 재구성 (Git 도입 전 공식 SemVer)

일회용 프로토타입을 훨씬 뛰어넘는, 본격적인 편집기가 이미 존재했던 최소한의 기준점.

### 추가됨
- `Monster Editor`;
- `Battle Commands / Items / Monster Commands`;
- `Battle Explorer`;
- 제품을 특징짓기에 충분히 실제적인 쓰기 가능한 표면이며, 모의(mock)가 아니다.

### 변경 사항
- 이 프로젝트는 본격적인 Git이 등장하기 전부터 이미 사용 가능한 편집기로 자리 잡았습니다;
- 메인 브랜치는 이미 독자적인 정체성을 갖추고 있었으며, 그 존재를 정당화하기 위해 “개념 증명”에 의존하지 않았습니다;
- 이 역사적인 버전은 다음과 같이 말하기에 타당한 시점입니다. `FFX Project Editor` 이미 편집자였지만, 아직은 현재 규모와는 거리가 멀었습니다.

### 여전히 누락됨
- `Sphere Grid` 편집 가능;
- 전용 엔카운터 툴링;
- 심층 AI/런타임;
- 공식 거버넌스/버전 관리;
- 전문 워크숍 생태계.

## [baseline-2026-05-31] - 2026-05-31

프로덕션에서 Git으로의 초기 데이터 정직하게 가져오기.

### 추가됨
- 비공개 저장소 `ffx-editor-main`;
- 브랜치 `main`;
- 태그 `baseline-2026-05-31`;
- `.gitattributes`;
- `Git LFS` 에서 `FFXProjectEditor/Assets/Audio/**`.

### 보존됨
- `_labs` 기준선 밖으로 벗어났습니다;
- `publish/`, `bin/`, `obj/` 그리고 무시해도 되는 보고서는 계속 무시되었습니다;
- 베이스라인은 과거 기록을 조작하지 않았습니다.

### 검증됨
- 베이스라인 커밋이 성공적으로 게시되었습니다;
- `origin/main` 그리고 `baseline-2026-05-31` Git의 동일한 초기 커밋을 가리키며;
- 베이스라인 게시 후 로컬 작업 트리가 정리됨.

### 참고 사항
- 이 베이스라인은 가져온 사진일 뿐, 제품의 의미론적 릴리스가 아닙니다.
- 이는 거버넌스, 버전 관리 및 통합 작업이 시작되기 전에 Git에 생산 버전을 고정하기 위해 존재합니다.

## 워크숍 미니 버전 이력

참고:

- `Pt1` 여기에 표시되지 않는 이유는, 해당 항목이 통합 레지스트리에서 공식 워크벤치/버전 관리 라인으로 지정되지 않았기 때문입니다. `2026-05-31`;
- 이 파동의 버전별 시간축은 `Pt2`.

## [pt2-v0.3.0-superseded.1] - 2026-05-31

### 사명
- ~ 라인을 개설하고 `ModelViewerLab`;
- 이해하다 `mon`, `.ebp` 및 관련 가족;
- 아직 존재하지 않는 렌더러와 정직한 리콘을 구분한다.

### 진화
- 쉘을 분리하여 `ModelViewerLab`;
- 내보낼 수 있는 아티팩트;
- 분류 `PROVED / STRUCTURAL / GUESS`;
- 역사적 기반은 이후 공식적으로 다음으로 이전되었으며 `Pt9`.

### 메인 브랜치 결과
- 직접적인 기능적 통합 없음;
- 해당 계통의 기원으로 인정된 레거시 `ModelViewer`.

### 최종 상태
- 다음 버전으로 대체됨 `Pt9`;
- 별도의 독립된 계보가 아니라 역사적 기원으로서는 여전히 중요합니다.

## [pt3-v0.8.0-freeze.1] - 2026-05-31

### 사명
- 텍스트 형식을 검토한다;
- 안전한 리더를 검증한다;
- 진정으로 보수적인 라이터만을 장려한다.

### 진화
- `TextRegressionHarness`;
- 이전에 다음과 같이 분류되었던 가정의 재분류 `Unsupported`;
- 안전한 게이트를 통해 `Name / Description`;
- 안전한 게이트를 통해 `Monster Localizations 1/2/3`;
- 계속 유지하겠다는 솔직한 결심 `btl_txt.bin` 그리고 `Field String` 프로모션 대상에서 제외됨.

### 본점 실적
- `TextLabTools` 흡수됨;
- `ProductionAuditTools` 흡수됨;
- 메인 라인에서 텍스트/몬스터를 안전하게 잘라내어 흡수함.

### 최종 상태
- 동결됨;
- 제작용 텍스트 경계의 기준으로 계속 유효함.

## [pt4-v0.5.0-hold.1] - 2026-05-31

### 목표
- 세련된 시각적 마무리 작업 수행;
- 런타임에 영향을 주지 않고 셸/테마 실험;
- 실제로 이식 가능한 자산과 내부 브랜딩 자산을 분리.

### 발전 과정
- `StudioTokens`, `StudioTheme`, dense shell, 대시보드, 트래커 및 자산 수집;
- 병렬 라인 `FFXMenuWorkshopConcept`;
- 숙성된 수준에 충분히 도달한 시각적 패키지이지만, 무작정 병합하기에는 아직 이르다.

### 메인 브랜치 결과
- 자산 기반의 부분적 공유;
- 전체 패키지에 대한 정식 포팅 없음.

### 최종 상태
- 보류;
- 전체 워크숍 병합이 아닌, 블록 단위로 정리된 포팅 후보로 유지됨.

## [pt5-v0.9.0-final.1] - 2026-05-31

### 목표
- 커널 테이블 파서 및 편집기를 통합;
- 게이트가 닫힐 때마다 연구 결과를 생산 모듈로 전환.

### 발전 과정
- `PlayerGrowthEditor`;
- `CtbBaseEditor`;
- `MixTableEditor`;
- 근거가 된 문장 `KeyItemEditor`;
- 재분배 `Auto-Abilities` ~을(를) 위한 `Pt7`.

### 메인 브랜치 결과
- 생산 환경에서 발생한 가장 큰 실제 흡수 물결 중 하나;
- 안전한 커널이 이제 `main`.

### 최종 현황
- 최종;
- 워크숍 종료, 주요 성과는 이미 제작팀에 반영됨.

## [pt6-v0.7.0-beta.1] - 2026-05-31

### 임무
- 전투의 런타임 타당성 입증;
- 전투 시나리오 및 순서 결정 시 추측을 줄임;
- 실질적인 근거를 제공하여 `Force Battle / Repeat Encounter`.

### 진화
- `BattleRuntimeProbe`;
- 시퀀싱 감시기;
- 셀렉터/뱅크 로그;
- 슬롯 선택기의 범주 좁히기;
- 전투 및 해체 과정에 대한 보다 정확한 관측 기록.

### 메인 브랜치 결과
- 로드맵 및 프로덕션 위험 평가 기준에 큰 영향을 미침;
- 아직까지 이 중 어느 것도 런타임/메모리 관련 깔끔한 병합으로 이어지지 않음.

### 최종 상태
- 베타 단계이며 우선순위가 높음;
- 활성 상태이며, 부하가 크고, 기술적 가치가 높으며, 맹목적인 포팅 시 위험이 높음.

## [pt7-v0.9.0-final.1] - 2026-05-31

### 미션
- 격리 `Auto-Abilities` 커널 퀄리티;
- 의미론을 부풀리지 않는 보수적인 편집기를 검증한다.

### 진화
- `AutoAbilityEditor`;
- `AutoAbility_File.cs`;
- `Arms_Rate.cs`;
- 유지하기 위한 명시적 게이트 `62h..67h` ~처럼 `raw/read-only`.

### 메인 브랜치 결과
- 실제 생산 환경에서 검증된 적용;
- 가드레일이 유지된 상태에서 랩에서 메인 브랜치로 이관된 가장 깔끔한 사례 중 하나.

### 최종 상태
- 완료;
- 완료된 역사적 워크숍으로 취급되어야 함.

## [pt8-v0.7.0-freeze.1] - 2026-05-31

### 목표
- 최소한의 정직한 라이터를 마무리하여 `Shop`;
- 다음 질문에 솔직하게 답하십시오. `w_name.bin` 준비되었든 안 되었든.

### 진화
- 작가 저장됨 `item_shop.bin`;
- writer 저장 위치: `arms_shop.bin`;
- 다음의 명시적 의존성: `shop_arms.bin` 기어 쪽;
- `w_name.bin` research-only로 유지되고 writer에 대해서는 차단됨.

### 메인 브랜치 결과
- 실제 부분 흡수 `Shop`:
  - `Shop Explorer`;
  - `FfxLib/Shop`;
  - `Assets/Shop`;
  - 다음 문서에 기록된 가드레일 `docs/history/PT8_SHOP_GUARDRAILS.md`.

### 최종 상태
- 동결/비활성화됨;
- `Shop` 보수적인 편집 모드로 전환되었습니다;
- `w_name.bin` 여전히 제외되어 있으며 차단된 상태입니다.

## [pt9-v0.6.0-alpha.1] - 2026-05-31

### 미션
- 다음 라인을 공식적으로 계속 이어가기 `ModelViewerLab`;
- 동결 `ModelViewer v1`;
- 의 실제 목표를 재정의하다 `ModelViewer v2`.

### 진화
- `PT9_CONTINUATION_PACK.md`;
- `ModelViewer v1` recon + clues로 인식되며, 최종 뷰어가 아님;
- 사운드트랙 `mot/regmot` e bridges PS2/Chargeur/FFXDumper;
- 향후 통합을 위한 가장 유력한 후보로 `Monster Editor`.

### 메인 브랜치 결과
- 아직 기능적 통합은 없음;
- 연구 및 범위 좁히기 측면에서 높은 가치.

### 최종 상태
- 알파 버전 활성화됨;
- 실제 정적 뷰포트 구현을 아직 입증해야 함.

## [pt10-v0.2.0-final.1] - 2026-05-31

### 목표
- 패스 구현 `read-only` ~의 `btl_txt.bin`;
- 정리하다 `US vs JP`, `W0..W3`, 접두사 및 쌍.

### 진화
- 마커/쌍/접두사의 문서 분류법;
- 행렬 `W0..W3`;
- 다음을 다시 한 번 강조하자면 `Battle Text` 계속 읽기 전용 상태로 유지됨.

### 메인 브랜치 결과
- 문서화 및 가드레일 역할만 수행;
- 도입된 기능은 없음.

### 최종 상태
- 최종/읽기 전용;
- 워크숍은 라이터 준비 상태가 아닌 문서화 단계에서 완료됨.

## [pt11-v0.3.0-blocked.1] - 2026-05-31

### 목표
- 다음을 위한 최소한의 안전한 라이터 구현을 시도하기 `btl_txt.bin`.

### 진화
- 통제된 변이;
- 차이점 감사;
- 사소한 변이에서도 의미적 오염이 없음을 입증.

### 메인 브랜치 결과
- 증거 및 가드레일 관련 읽기 전용 패키지만 통합 가능;
- writer/encode는 계속 차단됨.

### 최종 상태
- 차단 동결(blocked-freeze);
- 워크숍은 기술적 근거를 바탕으로 “거부”라는 입장을 분명히 하는 역할을 수행했습니다.

## [pt12-v0.3.0-package.1] - 2026-05-31

### 미션
- Ghidra의 출력 결과와 프로젝트에 유용한 아티팩트 간에 가교 역할을 구축한다.

### 발전 과정
- 유망한 파서;
- 바인딩 코드 생성기;
- 심볼 카탈로그;
- 독립형 툴링으로 통합 검토가 가능한 패키지.

### 메인 브랜치 결과
- 아직 통합된 사례 없음;
- 다음 통합 물결을 위한 통합 브랜치 개설됨.

### 최종 상태
- 패키지 준비 완료;
- 다음 통합 단계에서 포함될 유력한 후보; `Pt8`.

## [pt13-v0.3.0-package.1] - 2026-05-31

### 임무
- 런타임 툴링을 위한 .NET 레이아웃/구조체 검사기를 개발한다.

### 발전 과정
- 검사 툴링;
- 오프셋/크기 보고서;
- 메모리 민감형 타입에서 실제 불일치 탐지.

### 메인 브랜치 결과
- 아직 병합되지 않음;
- 다음 릴리스를 위한 병합 브랜치 개설됨.

### 최종 상태
- 패키지 준비 완료;
- 다음 릴리스와 함께 또는 그 직후에 포함될 유력한 후보 `Pt12`.

## [pt14-v0.2.0-architecture.1] - 2026-05-31

### 임무
- 체계적인 캡처에 대한 연구 `printf` 및 내부 디버그 문자열.

### 발전 과정
- 아키텍처 및 초기 후보안;
- 캡처 가드레일;
- 아직 프로덕션에 투입할 수 있는 훅에 대한 확실한 증거는 없음.

### 메인 브랜치 결과
- 통합되지 않음;
- 병합 전에 새로운 집중 검토 단계가 필요합니다.

### 최종 상태
- 아키텍처 보류;
- 해당 브랜치는 최소 검증 기준을 충족하거나 하드 블록으로 지정되어야 합니다.

## [pt15-v0.2.0-architecture.1] - 2026-05-31

### 목표
- 런타임 핸들 및 이벤트 버스 설계.

### 발전 과정
- 라이프사이클 아키텍처;
- 이벤트 계약;
- 스레딩/재진입 위험 매핑 완료;
- 아직 프로덕션에 적용할 수 있는 최소 슬라이스가 준비되지 않음.

### 메인 브랜치 결과
- 통합되지 않음;
- 병합 가능 상태로 간주되기 전에 읽기 전용 최소 슬라이스가 필요합니다.

### 최종 상태
- 아키텍처 보류(architecture-hold);
- 완성된 코드가 아닌 방향성으로서 유용합니다.

## [pt16-v0.2.0-architecture.1] - 2026-05-31

### 목표
- 인코딩 아키텍처를 정리하고 `index types` 충동적으로 새로운 Writer 버전을 잠금 해제하지 않고.

### 진화
- 분류 체계 제안;
- 매트릭스 `decode-only / encode-safe / raw-control`;
- 아직 흡수된 작은 첨가 슬라이스가 없습니다.

### 메인 브랜치 결과
- 흡수 없음;
- 여전히 기다리고 있음 `Slice 1` 작고 안전합니다.

### 최종 상태
- 아키텍처 보류;
- 향후 중요한 방향이지만, 아직 즉시 병합되지는 않을 예정입니다.

## [pt17-v0.3.0-guardrail.1] - 2026-05-31

### 목표
- 세이브 안전성, 왕복(round-trip) 및 드리프트 분류 기능을 강화합니다.

### 발전 과정
- 위험 매트릭스;
- 세이브/재로드 하네스;
- 아직 해결되지 않은 주요 오류 신호, 포함 `important.bin` 그리고 `a_ability.bin + arms_rate.bin`.

### 메인 브랜치 결과
- 실제 델타는 여전히 분리되어 정직한 클레임으로 통합되어야 함;
- 해당 라인의 일부는 기존 툴링에 이미 반영된 것으로 보이지만, 전부는 아님.

### 최종 상태
- guardrail-baseline;
- 새로운 기능이 아닌 강화 조치로서 여전히 관련성이 있습니다.

## [pt18-v0.3.0-governance.1] - 2026-05-31

### 목표
- 릴리스, 변경 내역, 기준선, 태그 및 편집 워크플로를 체계화한다.

### 발전 과정
- 정책 `CHANGELOG`;
- 버전 관리 정책;
- 브랜치/병합 정책;
- 워크숍 게시를 위한 안전한 순서 통합.

### 메인 브랜치 결과
- 대부분 이미 다음으로 통합됨: `docs/governance/`;
- 핵심 가치가 생산 거버넌스로 바뀌었다.

### 최종 상태
- 거버넌스-기준선;
- 미래의 변화보다는 게임의 규칙으로서 더 많이 받아들여졌다.

## [pt19-v0.3.0-surface.1] - 2026-05-31

### 미션
- 조율 `README`, 스크린샷 및 Surface는 현재 편집기를 사용하여 게시됩니다.

### Evolution
- 스크린샷 검토;
- 자산 정책 `README`;
- 기존 스크린샷을 최신 버전이며 추적 가능한 이미지로 교체.

### 메인 브랜치 결과
- 상당 부분이 이미 로컬 작업 트리에 반영된 것으로 보임;
- 최종 델타는 다른 작업과 혼합되지 않도록 별도로 분리해야 함.

### 최종 상태
- surface-baseline;
- 런타임/코어용이 아닌, 공개 발표용 주요 라인입니다.

## [pt20-v0.2.0-strategy.1] - 2026-05-31

### 임무
- 전체 프레임워크를 가져오지 않고 외부 툴링을 선택적으로 도입하는 방안을 연구한다.

### 진행 상황
- 통합 매트릭스;
- 비교 `STEP`, 검사 및 디버깅 도구;
- 생태계를 무분별하게 복제하기보다는 점진적인 통합을 권장합니다.

### 메인 브랜치 결과
- 아직 병합되지 않음;
- 다음을 위한 운영 로드맵 역할을 함: `Pt12 -> Pt13`.

### 최종 상태
- strategy-baseline;
- 통합 방향으로 계속 진행되며, 병합 완료 상태는 아님.


