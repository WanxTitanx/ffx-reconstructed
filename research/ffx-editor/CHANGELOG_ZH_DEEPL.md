---
日期：2026-06-29
標籤：
  - 變更紀錄
  - 版本控制
  - 專案編輯器
  - 怪物 AI
  - 階段輪替
  - spirareforge
別名：
  - 變更紀錄
  - 版本歷史
  - 版本記錄
---
# 變更紀錄

本檔案記錄了該專案的官方演變歷程`FFX Project Editor` 以及工坊生態系統`Pt`.

它涵蓋三個層級的歷史紀錄：

- 版本與基準線的`main`;
- 從`main` 在官方 Git 推出之前的時期；
- 研討會的編輯精華版與知識快照`Pt2` a`Pt45`.

本變更紀錄的規則：

- **現行規則（自 2026-06-04 起生效，詳見`docs/governance/VERSIONING.md` 第 4 節)：**所有可發送**（writer、模組、證明、容量、註冊文件）的新增項目，都會對以下 4 個欄位進行更新：`FFXProjectEditor.csproj` + 點此進入 **以及** 進入`changelogUS.md` + 行在`VERSIONING.md`;
- 請為每個條目分類：**MINOR** / **PATCH** / **REVISION**；並以 lane 簽名 (`Jarvis-ARENA`,`Jarvis-MAGIC`，等等）在多方聊天時；
- 保持對話串`[anterior: vX.Y.Z.W]` 線性 — 不跳過版本號；
- **不進行版本遞增**，僅適用於瑣碎變更（錯字、空格、內部重命名、字節完全相同且未修正的重構）；
- 亦會記錄里程碑、合併、凍結、鎖定及交接；
- 不偽造從未存在過的舊 Git 歷史；
- 當舊的語義版本經編輯性重建時，請標記為`historical reconstruction`;
- 當某間車廠大幅變更設計，卻未納入`main`, 此處列為生態系統變更，而非已移植的功能。

## [未發行]

### 未成年人
- **`v2.192.0.0` (2026-07-15, MINOR) — 有用的 PPP 行為突變：首個 T4 視覺證明。** Lane **Jarvis-MAGIC-DLL**。[先前：`v2.191.0.0`]
  -`pppSclMove` 在 Power Break 期間通過了 T1/T2 測試，且 MMF 捕獲值在界限內：9/9 個回調函式`magic_0021` 分配給 Blob 執行階段；紋理載入器已區分`magic_0021` 來自`magic_0326`.
  - 可逆 T4 PASS：回調函式中的 16 位元組視窗`.data+0x1C1B0` 是以均勻的間距排列的`0.948116` 至`3.0`；Power Break 的其中一個元件明顯變得更大，且未發生當機。Restore 已恢復運作`magic_0021.dll` 與原版完全相同。
  -`pppSclAccele` 以及`pppAngMove` 已接收 source-linked 和 T3 copy-only 候選方案；這些是下一代執行時家族。`pppColor` 仍抱持投機心態，且偏離了批判的軌道。
  -`ffx-magic-re v0.4.0` 已發布，包含經過安全處理的向量選擇器／切換器及合成測試用例；222/222 項測試，且 Guard 未出現違規情況。

- **`v2.190.0.0` (2026-07-11, 次要) — Sphere Grid Canvas v3：介面重新設計 + 內容修正 + 部署政策 + IDA RE.** **次要**. Lane **Jarvis/Sisyphus**. [前一版：`v2.189.0.0`]
  - **使用者介面重新設計（Kimi K2.7）：** SphereGridCanvas_Control.axaml 已重新建構：3 行緊湊式工具列，搭配大寫分組標籤與垂直分隔線；340px 側邊欄，帶有突出顯示的標題與空狀態（◎）；CanvasView 節點數量增加至 30 個，背景色更冷調，連結線條更粗，標籤字體為 11px。
  - **內容索引修正：**`FindOrAddNodeTypeOption` 已修正 — 現在會傳回包含 panel option 的`Index == contentIndex` 首先，與其優先考慮那些可能存在的命令選項，不如`Index` 不同（會導致下拉選單中出現 HP→Lock Nv3 的錯誤）。
  - **部署政策：**`SphereGridDeployPolicy` 已新增 — 封鎖`SaveToProject` 以及`SaveSquareToProject` 當計數值發生變化時，已驗證的待處理執行時間。已撤回 Banner、README 及 TopologySafetySummary 中「無需掛鉤」的錯誤聲明。
  - **已移除的 Hook 相關檔案：** True New Node LAB（屬性、邏輯、清單、標記）、true_new_node.flag、true_new_node_manifest.csv、README 中的 Hook 文字 — 所有內容均已從編輯器及 SquarePackageWriter 中移除。
  - **IDA RE (0xA45570)：**`FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells` 已確認 parse/cell 桶採用 nodeCount 驅動模式。標頭魔數 0x31，Unknown6 =`(PosX+2560)/256 + 20*((PosY+2336)/256)`. **無法證明 exit 管道的安全性。**
  - **IDA RE (0x681DB0)：**`FFX_Menu2D_InitBatchBuffers_NoTextureFallback` 案例 3 分配的參數如下：pos=0xA170（41328=861×48）、color=0xD740（55104）、uv=0x6BA0、index=0x285C。 歷史記錄「41252」有誤。
  - **IDA RE (0xA51340)：**`FFX_Abmap_DrawRuntimePanelNodes` 使用`n861 = NodeCount - iter + 860` (860 硬編碼)。
  - **IDA RE (0x7F4900)：**`FFX_Menu2D_DrawQuadIndexedBatch` 有`if(n861 >= 861)` (861 硬編碼)。負路徑會導致包含 861 個節點的色彩緩衝區溢出。
  - **IDA RE (0xA54860)：**`FFX_Abmap_RecomputePartyStatsAndLearnedMoves` 這僅是統計數據，並非 GPU 產生器（已修正歷史推論）。
  - **RT2 已確認：** Standard 98/861/882 可開啟 Sphere Grid，但在關閉時會立即當機。 已還原原版 Overlay。相關異常現象已保存於 `work/evidence/spheregrid-exit-cras`

h-20260711/`。
  - **狀態：SGM 861`bloqueado / research only`. 下一步：使用進程內掛鉤（DINPUT8 橋接）來攔截`DrawQuadIndexedBatch` 並將 ≥ 860 的槽位重新導向至更大的緩衝區。**

### 修補程式
- **`v2.190.3.0` (2026-07-12，修補程式) — 修復 Battle Commands 主側邊欄寬度問題 + 修復 MonsterMagicGrowWriter 編譯問題。** **修補程式**。Lane **Jarvis-UI**。[先前：`v2.190.2.0`]
  - **主側邊欄寬度修正：**`ModuleMasterDetail_Shell.axaml` — 擴展面板從 140px → 260px。先前因寬度不足，會將指令名稱截斷並以省略號替代（`Fros...`,`Shor...`,`Mist...`) 因為無法完整顯示技能名稱。當寬度為 260px 時，像`Froststrike`,`Short Charge`,`Counter March` 在大多數情況下可無需裁切直接套用。折疊後的導覽列寬度仍為 26px。
  - **編譯修正（建置阻滯）：**`MonsterMagicGrowWriter.cs` 修正了 4 處失效的連結：`FlagTargetSelf` →`FlagTargetSelfOnly`; 已移除`StatusDuration.Confuse = 3` (該類別`StatusDurationByteList` 沒有欄位`Confuse` —（此格式中不存在「混亂持續時間」一說）。`BreakArmor`/`BreakPower` 名稱已經正確了。Build 又恢復到 0 個錯誤。
  - **相容性：**其他使用 shell 的分頁／模組（如 Mix Tables、Monster Editor、Items）在展開的面板中也增加了 260px 的空間——這足以讓您的項目／怪物顯示完整，不會被截斷。

- **`v2.190.2.0` (2026-07-11, PATCH) — 戰鬥指令主側邊欄精簡化 + 共用外殼切換功能重構。** **PATCH**。Lane **Jarvis-UI**。[先前：`v2.190.1.0`]
  - **Master 窄版側邊欄 (Kimi K2.7 + GLM-5.2)：**`ModuleMasterDetail_Shell.axaml` 取代了`Expander` Avalonia 原生佈局`Grid` +`Button` 自訂。Expander 的範本包含`ExpandDirection="Left"` 設定了最小內邊距／邊框，導致無法縮減至 ~50-60px 以下。
  - **新尺寸：** 展開狀態 = 140px 的密集面板 + 26px 的切換欄（總計約 166px）；收起狀態 = 26px 的細長切換欄，僅顯示一個箭頭。
  - **Battle Commands 預設展開狀態：** 已移除`IsMasterExpanded="False"` 來自`KernelCommands_Control.axaml` — 使用者在指令清單可見的狀態下進入，若想完全專注於詳細資訊，可點擊側邊欄將其收起。
  - **戰鬥指令介面優化 (Kimi K2.7)：**`KernelCommands_Control.axaml` 新增了英雄級統計資料圖示（Scope/Total/Filtered/WRITABLE），以及帶有動作顏色的會話欄（`primaryAction accentGold`,`dangerAction`,`accentRefresh`)，以窄行呈現的主清單，`HorizontalAlignment="Stretch"` 在「詳細資訊」的卡片中，以及當未選取任何指令時的空狀態。`KernelCommands_DataModel.cs` 新增了計算屬性`CommandScope`,`TotalCount`,`FilteredCount`,`HasSelectedCommand`.
  - **相容性：** 殼層的所有公開屬性（`MasterHeader`,`MasterList`,`Detail`,`MasterHeaderLabel`,`IsMasterExpanded`) 保持不變；其他使用該外殼程式的模組（如 Mix Tables、Monster Editor、Items 等）無需進行任何變更。
  - **Writers/save bytes/handlers/converters/FfxLib 均未修改。** 僅為視覺化容器。編譯過程 **0 個錯誤**（原有 427 個警告）。

- **`v2.190.1.0` (2026-07-11，更新) — 混合表格介面重新設計優化：伸縮佈局 + 已填/未填狀態標籤 + 合作夥伴項目統一網格。** **更新**。Lane **Jarvis-UI**。[先前：`v2.190.0.0`]
  - **拉伸佈局（Kimi K2.7）：**`MixTableEditor_Control.axaml` 修正了 Detail 的垂直崩潰問題 —`HorizontalAlignment="Stretch"` 在 ScrollViewer 中新增 + StackPanel + 5 個內部邊框。右側的巨大空白便消失了。
  - **Partner Items 均勻網格：**`ItemsPanel` 從「合作夥伴項目」的 ListBox 變更為`StackPanel` 垂直至`UniformGrid Columns="3"`. 清單會轉為響應式三欄佈局，而非將 112 項內容堆疊在單一垂直欄中。
  - **狀態標籤（已填滿／空）：** 「合作夥伴行」的標籤現在是`<Grid>` 第 2 頁`<Border>` 重疊 —`IsVisible="{Binding !IsEmpty}"` → “filled”（青綠色）和`IsVisible="{Binding IsEmpty}"` → 「empty」（悶灰色）。取代了`<Run Text="{Binding ResultLabel}"/>` 其中顯示`<empty>` 在空格中顯示字面內容，而在已填入內容的格子中顯示項目名稱（語義雜訊）——項目的正確標籤已顯示在下方的「組合編輯器」中的「當前結果」卡片上。
  - **工具提示：** 這兩張卡片都獲得了`ToolTip.Tip` 說明 112×112 矩陣中的某個儲存格何時會生產某項商品、何時不會生產。
  - **資料模型：**`MixResultRow.IsEmpty` 源自`RawResult == 0`；於`NotifyComputedChanged` 連同`ResultLabel`/`ResultCode`/`Formula`.
  - **英雄屬性：**`OriginCount`,`TotalNonEmptyResults`,`CoveragePercent` （已作為計算屬性存在）以晶片形式顯示於主角身上。
  - **Writers/save bytes/handlers/converters/FfxLib 未作修改。** 僅為視覺化容器。編譯 **0 個錯誤**（422 個既有警告）。

### 修訂
- **`v2.189.0.0` (2026-07-10，修訂版) — PPP C2 第一波 + SOL 稽核 + 處理常式表佈局。** **修訂版**。Lane **Jarvis-MAGIC-DLL / SOL**。
  - **C2 第一波 (GLM-5.2)：** 透過 IDA MCP 在標準 IDB 中反編譯出的 193/193 個唯一處理程序`ffxoficial_post_vtable_struct_20260710_110730.i64`. 已識別出 10 個類別（Nullsub、Euler Matrix、Rand/Pattern、Transform/Matrix、Menu2D/Projection、FieldMap/Scene、Draw/VFX、Push/Copy Node、Animation State、Misc）。`PPP_HANDLER_ENCODING_SPEC.md` 內容涵蓋呼叫規約、槽位佈局、節點結構以及 5 種存取模式。`SOL_PACKAGE_V2.md` 已為交接工作完成整合。包含 22 個 DLL 的測試套件，擁有 6,650 多個測試槽位。已編寫覆蓋率報告。68/68 項測試均已維護完畢。
  - **SOL 審計 (GPT-5.6)：** 針對標準 IDB 進行的 V2 套件對抗性審計。已驗證處理器表佈局：40B (0x28) 條目，其中`name_ptr@+0x00`, 模式指標`@+0x04/+0x08/+0x0C`, 填充`@+0x10..+0x27`.`0x730050` 已確認為……的中場球員`ApplyTransformPattern_F` （非入口點）。`0x75B320` 已確認為`UpdateAnimationState` （內部輔助函式，未與分派表建立交叉引用）。`pppRandUpFV` 已確認的字串指針位於`0xB50E0C`. 解釋器`0x7170F0` 已反編譯：僅供閱讀`+4` (direct_handler) 位於可見路徑中；級聯`+8/+C` 未經證實。
  - **基於證據的暫停：** C2/C3 被鎖定，直至取得可重現的調度表提取器 + 由處理器具體化的證據 + 語義`+4/+8/+C` 已通過驗證。`SOL_PACKAGE_V2.md` 其中仍包含一項未實現的聲明：「193/193 個已反編譯的處理器」（反編譯結果未儲存於個別檔案中）。`HANDLER_TABLE_LAYOUT.md` 以及`OPEN_QUESTIONS.md` 在工作樹中建立。
  - **著色器負責人（非阻塞）：** 797 個 Phyre D3D11 檔案位於`work/vanilla_bins/ffx_data/gamedata/ps3data/shaders`；用於分析「draw」與「material」之間相關性的次要線索，並非 PPP 編碼的直接證據。
  - **狀態：C2/C3`bloqueadas por evidência incompleta`. 層 A/B/C1 維持閘門有效。**

### 重點摘要
- **`v2.189.0.0` (2026-07-10) — Magic DLL / PPP Assembler 通道：A + B + C1 層級 + 第二階段 + 深度分析。** **次要**。通道 **Jarvis-MAGIC-DLL**。[前一則：`v2.188.0.0`]
  - **層 A — WD3 結構化序列化器** (`wd3_writer.py`): 重建 224 位元組的前綴（標頭、指標表、間隙、5 個流標頭），且不進行複製`raw_bytes`. 守護者`end_offset=0`, 保留欄位與不變量`total_size/count_entries`.
  - **B 層 — WD3 物理有效載荷模型** (`payload_map.py` +`wd3_blob_writer.py`): 將 110,272 位元組的 blob 分割為具類型的前綴 (224B)，`post_prefix_gap` 不透明 (5.296B) 以及`body` 不透明（104.752B）。9 個標準物理跨段，各擁有 1 至 5 個邏輯所有者。無模板的往返積分`.data`.
  - **層 C1 — PPP 可重新配置插槽編解碼器** (`layer_c_slot.py` +`layer_c_resource.py`)：將 WD3 與 PPP 資源 blob 分離，偵測根節點，遍歷區段／程式，並重新發送 16B 的磁碟槽位。 Steam **353/353 通過**（355 個根節點、1,623 個區段、24,888 個程式、274,732 個槽位）；測試案例 **16/16 通過**（4,450 個槽位）。
  - **PPP 指令碼目錄**：已編目 274 個指令碼，222 個調度條目，約 50 個反編譯處理常式。
  - **第二階段變異實驗**：已在遊戲中驗證紋理路徑交換；已在遊戲中驗證 .data 交換；已驗證 float4/BGRA 個別修補並不會改變可見顏色（5 次嘗試）。
  - **深度分析**：分析了 Blizzara/Watera/Thunder；繪圖著色器系統 Family A 已映射（PPP→DXBC）；找出目標導向動畫的根本原因；在 11 份文件中修正了 HOST_CONTEXT_MAP；`magic_0383` 重新歸類為假陽性。
  - **證據**：68/68 次測試通過；Layer A/B Steam 6/6 + 測試案例 16/16；C1 Steam 353/353 + 測試案例 16/16；零診斷錯誤。
  - **狀態：A/B 層與 C1 層**`validadas`; Layer C2+（有效載荷、尺寸調整、新特效）`research only`.**
- **`v2.189.0.0` (2026-07-10) — UNI-003 低生命值衝鋒 + 交叉驗證 RE 完成 + 生命值門檻修正。** **輕微**。路線 **Jarvis-AI/RE**。[先前：`v2.188.0.0`]
  - **HP 門戶修正（NearDeath）：** 最終根本原因 — 字段 0x0000/0x0002 為 CTB 計量表／回合數，並非 HP／最大 HP。 已修正為欄位 0x0119（NearDeath 布林值，讀取`[edi+594h]` maxHpStat 對比`[edi+5D0h]` curre

ntHp)。已在 Skoll m014 遊戲中透過 RT2 驗證：當 HP 低於 50% 時，HP 閾值機制能正確觸發。
  - **UNI-003「低血量衝鋒」：** 已作為編輯器中的一鍵預設效果實裝。當血量 < 50%（瀕死狀態）時，會對自身施加「加速」效果，並透過`findMatchingChr(FrontlineChars, isAlive, 0, Any)`，透過私有變數進行一次性呼叫。複合守護程序：`var==0 && NearDeath` (LAnd)。由使用者手動修改的 m014 二進位檔通過 RT2 驗證。
  - **新的 IR 記錄：**`PerformCommandOnRandomFrontlineChr` 在`SinChainRecipe` — 透過以下方式在執行階段計算出的目標模型`findMatchingChr`.
  - **通用排程器：**`SinDryRunPlanner.PlanGuarded` 現在支援多項動作組合（先前僅支援 1 項）；`LowerLinearAction` 支援`PerformCommandOnRandomFrontlineChr`.
  - **RE 通道完整交叉驗證：** SUPERMD（2115 行，針對二進位檔驗證了 150 多個假設）。87 項已確認，20 個實際錯誤已修正，120 個新函式 ID 已歸檔。 已映射 346 個案例的開關寫入端 (0x7B4B80) — 確認 0x7018 = WriteChrProperty。
  - **已修正的關鍵錯誤：** 0x7050→0x705A (ForcePerformCommand)、0xB6→0xD8 (CALLPOPA)、UNI-007 70%→50% (NearDeath 閾值)、 0xFFF1 標籤 (AllAeons)、0x7078→0x706C (ReadMovePropertyForActor)、哨兵標籤 (0xFFEC/0xFFEB/0xFFE9)。
  - **播放過的檔案：**`SinChainRecipe.cs`,`SinPresetRecipeResolver.cs`,`SinDryRunPlanner.cs`,`MonsterAiEditor_DataModel.Sin.cs`,`SinScaleInject/Program.cs`,`SinPresetRecipeResolverTests.cs`,`AiChrPropertyNames.cs`,`AiScript_File.cs`,`AiTargetNames.cs`,`universal.csv`,`PORT_STATUS.md`,`SESSION_HANDOFF.md`.
  - **編譯：** 0 個錯誤。 **測試：** 1/1 GREEN（SinPresetRecipeResolverTests）。**RT2：** 在 Skoll m014 關卡中，遊戲內已確認 HP gate + PhaseRotation 功能正常。
  - **狀態：`Precisa Testar`** — UI（.axaml.cs）中 UNI-003 按鈕的接線尚未設定，且「一鍵式」按鈕的 RT2 尚未設定。
- **`v2.188.0.0` (2026-07-07) — Wave E：6 個特定家族的窄寫入器 + 6 個經過驗證的 RT0 閘門。** **次要**。Lane **Jarvis-WAVE-E**。[前一項：`v2.187.0.0`]
  - 六種針對特定家族的窄寫入器，實作於`FFXProjectEditor/FfxLib/Ai/`，每個都經過在`AiScriptLab` (基準 → 修補 → 驗證 → 拼接)

 round-trip → restore → byte-identity)：
    - **`AiRoundScriptedBossWriter`** (m238 Zu) — 每回合 5 次攻擊（著地／匍匐／音速／永恆懲罰／終結技），指令白名單 0x4019／401A／4016／4097／40AB／40DF，閘門`--round-scripted-boss-writer-rt0` **PASS**。
    - **`AiAnimaOdThresholdWriter`** (m125 Anima) — 帶有造型設計的 OD 閘門`OverdriveMax / divisor [* numerador]`, 偵測鬆散備用機制, 閘門`--anima-od-threshold-writer-rt0` **PASS**。
    - **`AiOmnisClusterWriter`** (m131 Omnis) — 元素集群 0x3045-0x304C，白名單狹窄，傳送門`--omnis-cluster-writer-rt0` **PASS**。
    - **`AiMortibodySupportAccumulatorWriter`** (m127 Mortibody) — 4 個 priv0010/0014/0018/001C 蓄電器，閘極`--support-accumulator-writer-rt0` **PASS**。
    - **`AiMortiorchisCompanionWriter`** (m143 Mortiorchis) — 交接/吸收 0x608C/0x60A9，閘門`--mortiorchis-writer-rt0` **PASS**。
    - **`AiReactiveSensorWriter`** (m106/m118/m150/m154 反應式) — 感測器`usedCommand 0x7019 → readMoveProperty 0x701A → PUSHII state`, 閘門`--reactive-sensor-mortiphasm-writer-rt0` **PASS**（4隻怪物）。
  - 每位作家都遵循以下模式：`AiFluxNativeThresholdWriter`: 描述符 → 修補請求 → 位元組變更防護機制 → 編輯結果 → 失敗時回滾。修補程式僅修改授權的位元組（立即數 PUSHII）；任何未列入白名單的差異都會導致操作中止並回滾。
  -`AiScriptLab.csproj` 已更新，新增了 6 個包含檔案；`RuntimeTools/AiScriptLab/Program.cs` 新增了 6 個 RT0 閘口。
  - **版本**：`dotnet build FFXProjectEditor` 0 個錯誤，`dotnet build AiScriptLab` 0 個錯誤，**6/6 閘位 RT0 通過**。
  - **狀態：`Precisa Testar`** — 尚需 UI 整合（DataModel Advanced* 彈出視窗）、編輯器中的手動煙霧效果，以及在進行深入的遊戲玩法／內容創作設計前，需先完成 RT2 遊戲內測試。
- **`v2.187.0.0` (2026-07-01) — Treasure Master + BukiGet Writer + Lightning Dodge 編輯器。** **次要**。Lane **Jarvis-BAUS**。[前一篇：`v2.186.1.0`]
  - **buki_get.bin 的寫入器**：可透過 ByteSnapshotEditorSession 編輯 86 項裝備資料（擁有者、裝備類型、配方、威力、暴擊、插槽、4 項自動技能、標記、Unk03）。 物品中心（Items Hub）中的 TabMode.Writer。
  - **閃電閃避編輯器**：讀取／寫入 kami0000.ebp 中的 11 個閾值，以及

 kami0300.ebp 透過 ATEL 字節碼修補程式。預設模式：原版／中等／簡單／極難。模組位於「額外內容」中。
  - **RE 發現**：閾值 (5/10/20/50/100/150/200 連續值 + 30/80 總值) 被定位為指令`AE XX 00 29 06` 位於 .ebp 檔案中 — 並非位於 EXE、核心二進位檔或 magic DLL 中。ffx_addresses.h 偏移量為 0x400000。5 個並行處理程序（3 個 IDA MCP + 2 個搜尋程序）。
  - **主文件**：FFX_TREASURE_MASTER_2026-07-01.md（631 行，15 個章節）。 已編目 498 項寶藏，已繪製 33 個區域地圖，已記錄 86 筆 buki_get 條目。已匯出 CSV 檔案。
  - **建置**：0 個編譯錯誤。
- **`v2.186.0.0` (2026-06-30) — Phase Manager：IDU 編輯器 + 路線卡。** **次要更新**。Lane **Jarvis-MAGIC**。[前一版：`v2.185.18.0`]
- **`v2.185.18.0` (2026-06-30) — 西摩開局變招已升級為《Bible/Atlas》並新增應用內護欄。** **修補程式**。車道 **Jarvis-RE / Jarvis-MAGIC**。該開局`Shell/Protect antes da party agir` 在沒有外部鉤子的情況下保持關閉狀態：`mcyt06_00 ?StartEndHooks2::HookStart` 做`AllMonsters.FirstStrike = true`,`AllMonsters.CurrentTurnDelay = 0`,`Monster#01.CurrentTurnDelay = 1` 並將「派對／預訂」推至`+2`；採用皇家編制`slot0=m141`,`slot1=m124`,`slot2=m141`,`slot3=m125`，這證明了開場招式源自遭遇戰的原生設定，而非在`performCommand` 西摩的。這項發現已被歸入永久性文件（`ATEL Bible`,`Monster AI Corpus Atlas`) 以及至`BIBLE OF SPIRA` 透過應用程式內`AiBibleCatalog`，並為產品設定合理的邊界：`Battle Corpus Crosswalk` /`Aurora` 可以將其以唯讀模式顯示出來，但`HookStart` / CTB 的初始版本目前尚未公開發布。Seymour 原生文件已整合並進行版本控制。[前一版：`v2.185.17.0`]
- **`v2.185.17.0` (2026-06-30) — Monster AI 相位旋轉 P1+P2 + Seymour RE 第二層 + IDU 可編輯性提案。** **修補程式**。路徑 **Jarvis-MAGIC / Jarvis-RE**。已實作分支敏感型讀取器 P1+P2：`AiDetectedBranchAction` 現在正在載入`TargetProvenance`/`CommandProvenance` 由 walker 保留來源路徑（PUSHV/POPV、findMatchingChr）。UI 的`Monster AI Editor` 顯示來源為 cmd/target/labels 的只讀多行區塊。0 個建置錯誤，PASS n

RT0. Seymour m124：第二層 RE 已完成 — 指令碼 0x6051 （SetupWaitTimer）透過 CTB 倒數計時識別，0x604D（MenuAnimationKind）已映射，0x604B（BattleEventString）以包含內部機器碼的字串表形式結構化。 已調查 CTB 設定流程：戰鬥開始事件 0x01→0x704A（引擎的 QtMG/腳本層），並非純粹的 ATEL。 間接調度單元 (IDU)：研究完成 — 57 個間接表格、147 次調度操作，提出視覺化編輯器提案。 Home（Gundappo）：azit03 的編隊配置已提交。知識庫 + FastEntrypoints + 會話交接已同步。[先前：`v2.185.16.0`]
- **`v2.185.16.0` (2026-06-29) — 怪物屬性／吉爾／AP 重新平衡：馬卡拉尼亞、比卡內爾、寧靜之地 + 7 款 OD 設計。** **更新**。Lane **Jarvis**。Iguion (m026) 與 Mafdet (m004) 依照蜥蜴族／裝甲族標準獲得強化。 Cactuar (m208) 獲得強化（HP 800→1500，AGI 24→40，MDEF 維持 255）。 寧靜之地：10 隻怪物的 AGI 及各項屬性均獲得強化。3 個區域（馬卡拉尼亞、比卡內爾、寧靜之地）的吉爾/AP 因 OD 加成而提升。APovk 統一調整為 2×。 規劃中的 7 種 OD：穆舒蘇（沙之呼吸）、祖（音速風暴）、卡克塔爾（10,000 根針）、庫爾（爆破砲）、奇美拉大腦（強大守護 + 精神風暴）、食人魔（食人魔重擊）。 4 目標同步機制（repo/steam/extract/clean-bins）已作為專案規範記錄在案。[先前：`v2.185.15.0`]
- **`v2.185.15.0` (2026-06-29) — Obsidian 儲存庫 + 文件前置資訊 + 工具基礎架構。** **修補程式**。Lane **Jarvis-INFRA**。 在專案根目錄中設定 Obsidian Vault：graph.json 包含 11 組按資料夾／標籤分類的色彩群組，CSS 程式碼片段（colorful-graph、colorful-folders）搭配圖形光暈效果與鮮豔色彩。 docs/obsidian-vault/ 內含 30 多則相互連結的筆記（樞紐、RE 筆記、Battle AI、Spira Reforge、會議紀錄、參考資料）＋ 4 張 Mermaid 圖表（SinScaleInject 架構、Phase Rotation 流程、ATEL VM、Monster Worker 結構）。 DeepSeek 組織工具已處理約 1900 個帶有前置資訊（標籤、別名、日期）的 .md 檔案，以豐富圖形檢視。 創建了 5 項 FFX 專業技能（monster-ai-specialist、runtime-hooks-engineer、wpf-module-architect、re-ida-analyst、data-diff-patch-engineer），並在 AGENTS.md 中啟用自動路由功能。GitHub MC

已透過環境變數 + .bashrc 設定 P 的憑證。已更新 .gitignore（包含 .mcp.json）。AGENTS.md 採用標準化的前置資訊。[先前：`v2.185.14.0`]
- **`v2.185.14.0` (2026-06-29) — Monster AI 相位旋轉：`AfterAnyValidTurn` 在 CTB edge 上具備即時調度執行能力。** **PATCH**。Lane **Jarvis-MAGIC**。該`PhaseTurnEdgeHook` 不再僅是觀察者：回調執行階段現在會解析邊緣的行為者，並找出`m###`, 掃描所有與這頭怪獸相容的 sidecar 輸入端，並透過結構橋接將動作依序排列（`resolveTargetMask -> queue script command`) 與 CTB edge 處於相同的情境中。執行環境會維持狀態`onlyOnce` 由`entry x actorSlot`，當戰鬥的簽名變更時，會重置此狀態，並開始記錄調度成功／失敗的狀態。在編輯器中，的 sidecar`AfterAnyValidTurn` 現在也出口至`modules\config` 遊戲中當`GameInstallRoot` 這個問題是可以解決的，而且警告/UI 已收緊，以免假裝`guardVar` 已在非輪值期間變異：runtime v1 = 立即執行指令，最適合用作一次性指令。`RuntimeTools/PhaseTurnEdgeLab` 已與實際日誌對齊（`n6`/`a2`). **狀態：`Precisa Testar` 遊戲內** — 離線版本已建立，RT2 尚待處理。[先前：`v2.185.13.0`]
- **`v2.185.13.0` (2026-06-28) — Monster AI 相位旋轉：戰鬥開始 AI 已停用；「誠實觸發」已變更為「執行時／CTB 邊界待定」。** **修補程式**。線路 **Jarvis-MAGIC**。該`Gerenciador de Fases` 不再假裝`Assim que a batalha começar` 這是遊戲內一個可靠的遊戲機制觸發點`AiFile`. 該寫入程式現在會拒絕帶有`BattleStart`，使用者介面會將此路徑重新命名為`Init do CombatHandler (LAB desabilitado)`，而相關提示則指向正確的解決方案：在 CTB 的邊緣處使用 hook runtime，以實現「在任何有效輪次結束後」的行為。`RuntimeTools/AiScriptLab --phase-rotation-rt0` 回到了100%的食譜`onTurn` 接著是 **PASS**；該`m020.bin` 測試環境已還原至儲存庫外的乾淨基準狀態。[先前：`v2.185.12.0`]
- **`v2.185.12.0` (2026-06-28) — Monster AI 相位旋轉：實際頂端開局 + 往返`forcePerformCommand`.** **PATCH**. Lane **Jarvis-MAGIC**. 該`Gerenciador de Fases` 現在處理各階段

 帶扳機的`Assim que a batalha começar` 作為在入口點頂端進行的實體插入，而非僅將新區塊串接在程式碼末尾。這能讓開啟器（opener）字面意義上位於舊處理常式主體的上方，並降低發生該情況的風險`m020`，在這種情況下，立即採取的行動可能會在其他行動之前就耗盡該回合的行動點數。草案的讀者也開始意識到`forcePerformCommand (0x705A)`，因此重新開啟／重新套用開帳分錄時，便不會再忽略這些區塊。`RuntimeTools/AiScriptLab --phase-rotation-rt0` 以下是 **PASS`319/319`** 且編輯器的 Release 版本建置結果顯示 **0 個錯誤**。**狀態：`Precisa Testar` 遊戲內**，尤其是`m020 - Teste Não Funcional 2.bin` 開場時三支劇組的實際排序如下。[上一則：`v2.185.11.0`]
- **`v2.185.11.0` (2026-06-28) — Monster AI 相位旋轉：可攜式作者識別碼 + 實體化時不覆寫現有變數。** **修補程式**。Lane **Jarvis-MAGIC**。該`Gerenciador de Fases` 現在分開`ID real` 來自`ID autoral/template` 針對每個受審計的變數：使用者介面會顯示兩者，將首選的 ID 儲存至本地元資料中，並讓食譜進行調用`var[N]` 更高，同時不會將別名與實際操作數混淆。在 apply 階段，編輯器會在必要時使用同一儲存空間／槽位的別名來實體化額外的描述符，而不會覆寫現有的變數；如果`ID` 若該請求已被另一變數佔用，則該請求將提升至下一個空閒索引。各階段的守護程序也會重新映射至實體化索引。`RuntimeTools/AiScriptLab --var-grow` 以下是 **PASS`185/185`** 以及`--phase-rotation-rt0` 以下是 **PASS`319/319`**；編輯器的 Release 版本建置已完成，**0 個錯誤**。**狀態：`Precisa Testar` 遊戲內**，特別是具有不同變數表的怪物之間的匯入／匯出。[前一則：`v2.185.10.0`]
- **`v2.185.10.0` (2026-06-28) — Monster AI 相位旋轉：變量 ID 保持穩定，且戰鬥開始時立即開局。** **更新**。路線 **Jarvis-MAGIC**。該`Gerenciador de Fases` 不再依賴對`IndexLabel` 以了解`var[N]`:`AiPhaseVariableAuditRow` 現在正在載入`VariableIndex` 數值穩定，且使用者介面顯示`ID###` 直接進行，這消除了「根據文字／別名編輯變數 ID」所產生的歧義。以 g 開頭的階段

拉繩`Assim que a batalha começar` 現在已發行`forcePerformCommand (0x705A)` 而非`performCommand (0x700B)`，以免在開場佈置時必須依賴一般排隊流程。`RuntimeTools/AiScriptLab --phase-rotation-rt0` 獲得了「opener battle-start」的報導，並繼續**PASS**`319/319`**；編輯器的 Release 版本建置已完成，**0 個錯誤**。**狀態：`Precisa Testar` 遊戲內**，主要是開場動畫的順序與實際情況，以及`m020`. [上一頁：`v2.185.9.0`]
- **`v2.185.9.0` (2026-06-28) — SinScaleInject 已順利部署至`modules\tools`.** **PATCH**. Lane **Jarvis-SIN**. 新腳本`RuntimeTools/SinScaleInject/deploy-sinscaleinject.ps1` 發布`SinScaleInject` 放入乾淨的資料夾中，並替換`modules\tools\SinScaleInject\` 透過一個精簡的獨立有效載荷（`SinScaleInject*`,`SinCoreLib.dll`,`Xe.BinaryMapper.dll`)，消除來自`FFXProjectEditor.exe`/遊戲資料夾中的阿瓦洛尼亞。`Program.cs` 現在可偵測到`GameRoot` 自`AppContext.BaseDirectory` 當在……內執行時`modules\tools\SinScaleInject`, 這樣就不再依賴硬編碼了`D:\SteamLibrary\...` 用於遊戲的路徑。已於本地驗證：Release 版本`0 erros / 0 warnings`, 在遊戲路徑中進行乾淨的發布與實際部署。**狀態：`Precisa Testar` 遊戲內**；儲存庫路徑（`clean-base` /`roster-dir`) 依設計仍為機器本機。[前一項：`v2.185.8.0`]
- **`v2.185.8.0` (2026-06-28) — SIN 修補程式審查後續：CLI 強化 + 建置掛鉤的合理性檢查。** **修補程式**。Lane **Jarvis-SIN**。`SinScaleInject`:`--restore-area` 現在需要出示身分證；`--seed`,`--t` 以及`--intensity` 無能之輩往往早早失敗，且訊息明確；`--t` 被駁回的否定意見；`--intensity` 僅限於`0..100`;`MonsterStatSheetStruct.StatSheet` 已初始化以移除無效性警告。`build_hooks.ps1`: 維持`version.res` 透過內建方式`cl.exe` 現在，如果`ffx-hooks.dll` 最終尺寸過小，以避免 artefact 的「靜默退化」。審查與後續追蹤已記錄於`docs/ai/SIN_PATCH_REVIEW_2026-06-28.md`. [上一頁：`v2.185.7.0`]
- **`v2.185.7.0` (2026-06-28) — 使用者介面優化：柔和色調 + 可見選取標示。** **修補程式**。Lane **Jarvis-UI**。StudioTokens.ax

aml：重音符號`#5DD0B4` →`#2A9D8F` （柔和的青綠色），內填色／邊框採用柔和色調，不含刺眼的霓虹色。StudioTheme.axaml：ListBoxItem 選取項`#15323B` →`#1A3040` 帶有 1px 可見邊框。已更新選取標記、分頁標籤、展開按鈕及狀態。Build Release 0 錯誤。 [上一版：`v2.185.6.0`]
- **`v2.185.0.0` (2026-06-27) — Overdrive：移除 LAB 標籤 + 終結技各階段的目標選擇器。** **次要**。Lane **Jarvis**。從「Overdrive」自訂區塊的所有可見文字中移除「LAB」。 終結技連段的每個階段現在都有各自的目標下拉選單（隨機活體 / 血量最低）。`AddOverdriveFinisherSequence` 遺失了參數`template` 以及`fallbackTarget` — 每個指令都已預設其目標。`OverdriveFinisherStep` VM 類別。建置 0 錯誤。RT0 閘 330/330 通過。[上一項：`v2.184.1.0`]
- **`v2.185.6.0` (2026-06-27) — Sin Lab v2.1：程式碼審查 + 錯誤修正 + 威脅同步。** **修補程式**。Lane **Jarvis-SIN**。SinScaleInject：內核名稱現在會在每次執行前從「clean」狀態還原`--area` (ProcessArea, SaveClean, RestoreAll)。SaveClean 和 RestoreAll 現已涵蓋 kernel/monster*.bin。與 C++ 對齊的 RNG：`seed = seed ^ (seed << 16)`. 移除 g_sinPreset[93]（死碼）。從種子中移除 time(nullptr)（確定性隨機數生成器）。 kAreaTable (C++) 與 AREA_T (C#) 已與威脅上限 CSV 檔案同步：修正 14 個數值，tMin 始終為 0，並新增區域（zanarkand、postgame、thunder_plains_cross、macalania_bosses）。[先前：`v2.185.5.0`]
- **`v2.185.5.0` (2026-06-27) — Sin Curse Lab v2：SinScaleInject 功能已啟用 + 簡化鉤子。** **修補程式**。Lane **Jarvis-SIN**。SinCurseHook.cpp：移除 MonsterLoad、SetScaleAxis、AiQueryProperty 及 LaunchRestore。 btlmap 過濾器。CREATE_NO_WINDOW。SinScaleInject v2 使用 Monster_StatSheet.ReadSingle/WriteSingle。從儲存庫重新生成 Clean bins。管理 62 個 DLL。[先前：`v2.185.4.0`]
- **`v2.185.4.0` (2026-06-27) — Sin Curse Lab v2：移除 AiQueryProperty，SinScaleInject v2 CLI，文件。** **修補程式**。Lane **Jarvis-SIN**。移除 AiQueryProperty 掛鉤 (RVA 0x3B2DD0) — 該處原為 FFX_Battle_AggregateActorProperty，繞道處理會導致選單當機。F7 區域子選單已還原。 保留專屬變數 g_sinPreset[93]。SinScaleInject v2 CLI：--ar

ea、--seed、--intensity、--save-clean（361 個桶）、--restore、--dry-run、XorShift32 隨機數產生器、HP/屬性縮放。ATEL 注入功能已停用（待處理）。 文件：SIN_CURSE_LAB_SESSION_2026-06-27.md、SIN_CURSE_V2_BIN_FIRST_PLAN_2026-06-27.md。[前一版：`v2.185.3.0`]
- **`v2.185.1.0` (2026-06-26) — Arena+ 跨地圖延遲還原：避免損壞隨機遭遇區塊。** **修補程式**。Lane **Jarvis-ARENA**。新增`ArenaPlus_ArmDeferredFileRestore` +`ArenaPlus_TickDeferredFileRestore` 在 dllmain.cpp 中。當 781D60 跨地圖發射成功後，會觸發約 30 秒（1800 幀）的計時器。計時器到期後，將恢復`.spiraforge.bak` 關於該複合二進位檔。根源：cross-map deploy（例如：Macalania Forest）寫道 Dark Aeons 在`mcfr00_00.bin`，這也屬於隨機遭遇機制——隨機遭遇會生成「黑暗永恆」而非「惡魔」。建立並部署 DLL。[上一則：`v2.185.0.0`]
- **`v2.184.1.0` (2026-06-26) — Aurora Chamber：btlmap 存根改為回退機制，移除 --portable 及 π 翻轉，怪物 T 姿勢。** **次要**。Lane **Jarvis**。btlmap 存根 → 回退至對應的地圖。 DataModel：IsMapOnlyVirtual 不再阻塞渲染。ExportSceneGeometry：`--portable` 套用 PNode 變換（幾何體定位正確）。檢視器：已移除 π 翻轉（glTF 預設即為 Y 軸向上）。怪物：在 aurora-overlay.js 中採用 T 姿勢（第 0 幀，無動畫）。`ResolvedAreaArg` 以取得檢視器的正確網址。[上一頁：`v2.176.8.0`]
- **`v2.184.1.0` (2026-06-26) — SIN UNI 預設設定 v2 補丁 — CounterAttack、Haste enrage、Ward Stack+、Frontline。** **補丁**。線路 **Jarvis-SIN**。[先前版本：`v2.184.0.0`]
- **`v2.184.0.0` (2026-06-26) — 蘑菇岩座標變動 + 文件 + 附錄 D/E。** **輕微變更**。Lane **Jarvis-FORM**。 Mushroom Rock Road 聚會地點的座標變更。已將附件 D（Thunder Plains）及 E（Macalania）新增至`PROMPT_JARVIS_FORM_ENCOUNTERS.md`. BF 提供的相機規格文件。[上一頁：`v2.183.9.0`]
- **`v2.183.9.0` (2026-06-26) — 使用者座標 Mi'ihen + BF 鏡頭文件。** **修補檔**。Lane **Jarvis-FORM**。8 組 mihn04 G0 陣型，附有使用者手動設定的座標。 FFX_ENCOUNTER_BATTLE_KNOWLEDGE.md：3 張 BF 表格（1031/1033/1034）。[先前：`v2.183.8.0`]
- **`v2.183.8.0` (2026-06-26) — mihn04 G0 Newroad North

擴充。** **PATCH**。Lane **Jarvis-FORM**。8 種陣型 (00-07) BF=1033，3-5 隻怪物。[先前：`v2.183.7.0`]
- **`v2.183.7.0` (2026-06-26) — 由使用者手動編輯的 Mi'ihen 座標。** **修補檔**。Lane **Jarvis-FORM**。16 個由使用者手動調整的頻段：BF=1031（2 後/3 前）、BF=1034（對角線）、BF=1033（寬頻）。[先前：`v2.183.6.0`]
- **`v2.183.5.0` (2026-06-26) — 具相機感知能力的座標擴散。** **已修正**。Lane **Jarvis-FORM**。 正面（BF=1031-1039）與側面（BF=1040-1042）標準。[前文：`v2.183.3.0`]
- **`v2.183.3.0` (2026-06-26) — 所有 66 種陣型皆採用全扇出 V 型散開陣型。** **已修正**。萊恩 **賈維斯-陣型**。[先前：`v2.183.2.0`]
- **`v2.183.2.0` (2026-06-26) — monLive 座標分佈。** **已修正**。Lane **Jarvis-FORM**。[先前：`v2.183.1.0`]
- **`v2.183.1.0` (2026-06-26) — monLive 計數 + 座標修正。** **已修正**。Lane **Jarvis-FORM**。將 monLive 計數與 66 個儲存格的編隊槽進行同步。[先前：`v2.183.0.0`]
- **`v2.183.0.0` (2026-06-26) — 雷霆平原擴充（7 個箱）。** **輕微**。 車道 **Jarvis-FORM**。kami00 南（4 個格式）、kami03 北（3 個格式）。池：Aerouge、Melusine、Buer、Kusariqqu、GoldElm、IronGiant、Larva。[前一則：`v2.182.2.0`]
- **`v2.182.2.0` (2026-06-25) — 月流調整。** **修補程式**。Lane **Jarvis-FORM**。genk00_01/+Garm、genk00_02/+BiteBug、genk00_03/+2Bunyip。59 個二進位檔已部署至 Steam。[先前版本：`v2.182.1.0`]
- **`v2.182.1.0` (2026-06-25) — Moonflow 擴充 + 附錄 C.** **輕微變更**. 車道 **Jarvis-FORM**。genk00（6 種格式），genk16（5 種格式，寶箱模仿者）。[前一則：`v2.182.0.0`]
- **`v2.182.0.0` (2026-06-25) — Djose Highroad 擴充。** **次要更新**。車道 **Jarvis-FORM**。kino04 G0 Shade（5 個格式）+ G1 Sunlight（8 個格式）。+SnowFlan 於 25/26。[先前：`v2.181.1.0`]
- **`v2.182.1.3` — 最終同步：MonsterMagicGrowWriter、SinCurseHook、Arena+ 遭遇戰標記佇列 G/F 洩漏修復。** **修補程式**。Lane **Jarvis-SYNC**。MonsterMagicGrowWriter：12 種 OD 配方。SinCurseHook：執行時 C++ 改進。 **Arena+ dllmain：在固定點解除後清除 RVA_BATTLE_QUEUE_GROUP/FORMATION，以防止載體的 G/F 洩漏至同一戰場上的隨機遭遇戰 （例如：Macalania Lake 戰場=340 + 載具 mcyt00_22 戰場=340

 會生成「黑暗永恆」而非普通惡魔）。** 已修補的 a_ability.bin。monmagic1.bin 同步。編譯並部署 DLL。[先前：`v2.182.1.2`]
- **`v2.182.1.2` — 同步：使用者的 monmagic2 + 正確的 OD 區段。** **PATCH**。Lane **Jarvis-SYNC**。同步使用者的 Overdrive 區段。[先前：`v2.182.1.1`]
- **`v2.182.1.1` — 《Monster Overdrive》技能 + 備用文字庫修正。** **修補檔**。 通道 **Jarvis-MONMAGIC**。15 項 OD 技能 (0x60F7..0x6105)、備份文字庫修正、12+3 項模組化技能、6 個區域。[先前：`v2.182.1.0`]
- **`v2.182.1.0` — 怪物平衡調整 + a_ability + monmagic2 OD + SinCurseHook。** **輕微調整**。路線 **Jarvis-MONSTER**。 重新平衡約 60 隻怪物。a_ability.bin AU1-AU7。monmagic2：4 項 OD 技能。SinCurseHook 執行時程式碼為 C++。[先前：`v2.182.0.0`]
- **`v2.181.1.0`/`v2.179.0.0` — 隨機遭遇擴充（米伊亨、蘑菇岩、喬塞高地）。** **次要**。萊恩 **賈維斯-FORM**。48 種隨機遭遇陣型，敵人數量從 2-3 隻擴充至 4-5 隻。 盧卡之後的米伊亨：16 個區塊 (mihn07/mihn04/mihn05)。 蘑菇岩：19 個資料檔 (kino00/kino01/kino05/kino07)。 喬塞高地：13 個資料檔 (kino04 G0=陰影 G1=陽光)。 文件：`docs/ai/PROMPT_JARVIS_FORM_ENCOUNTERS.md` （附件 A/B/C），`FFX_ENCOUNTER_BATTLE_KNOWLEDGE.md`. [上一頁：`v2.181.1.0` /`v2.179.0.0`]
- **`v2.181.0.1` — Arena+ MusicHook：修正了逃離戰鬥時音樂不會停止的問題。** **修補程式**。Lane **Jarvis-ARENA**。`ConsumeArenaBattleMusicPending()` 已新增至 3 個執行歌曲切換的 shim（PlayTrack、SwitchCrossfade、PlayTrackWithPreload）。根目錄：`g_arenaBattleMusicPending` 在套用覆寫後從未被播放過，因此當跳過該鉤子時，會將戰場音樂切回頭目主題曲。編譯並部署 DLL。[前一則：`v2.181.0.0`]
- **`v2.179.0.3` — 蘑菇岩怪物的增益效果 + monmagic2 超限技能（狙擊、羽暴風）。** **補丁**。路線 **賈維斯**。 Raptor/Garuda/Gandarewa/Lamashtu/RedElement/Funguar：HP、STR、MAG、AGI、AP、Gil 提升。monmagic2.bin：Snipe (0x60FE) + Feather Storm (0x60FF)。 361 個來自經典模組的同步 bin 檔。[前一版：`v2.179.0.2`]
- **`v2.179.0.2` — 同步舊版模組（D:\FFX Mods\）中的所有 361 個怪物資料夾。** **修補檔**。Lane **Jarvis**。所有從舊版模組複製的 m000-m360（20

24) 針對該儲存庫。已包含所有已套用的屬性重新平衡。[先前：`v2.179.0.1`]
- **`v2.179.0.1` — 罪孽之子 鬼 第2階段 (m118)：STR 20→28，MAG 20→26，AGI 10→16，ACC 30→80。** **更新**。Lane **Jarvis**。[先前：`v2.179.0.0`]
- **`v2.179.0.0` — 奧楚男爵 + 罪孽之子鬼 重新平衡：生命值、法力值、掉落物提升。** **更新**。線路 **賈維斯**。 奧楚領主 (m153)：生命值 9999→15000，敏捷 8→14，法力值 120→300，法力值上限 300→900。 鬼 F1 (m117)：AP 400→1200，APO 600→1800，掉落物加倍。 鬼 F2 (m118)：HP 6000→9000，AP 0→300，APO 0→450，吉爾 0→500，新增掉落物與過量傷害。[先前：`v2.178.0.0`]
- **`v2.178.0.0` — monmagic2 特殊技能 + 怪物平衡調整文件。** **輕微調整**。Lane **Jarvis**。monmagic2.bin：Gore Charge (0x60FC)、Fang Strike (0x60FD)。 MonsterMagicGrowWriter：AppendGoreCharge、AppendFangStrike、AppendSnipe、AppendFeatherStorm。MONSTER_REBALANCE_SUMMARY.md：完整基礎版→模組對照表（約 60 種怪物）。 VANILLA_VS_MOD_MONSTER_STATS.md：完整對比表。[先前版本：`v2.175.1.0`]
- **`v2.176.8.0` — AGS 解碼器：textureanimation.ags.phyre 解析器 + 原始掃描（11 幀）。** **輕微**。Lane **Jarvis**。`PhyreTextureAnimationDecoder.cs`: 解碼包含 PTextureAtlasInfo、PSubTextureInfo 及 PSpriteAnimationInfo 的 RYHPT PBinary 檔案。從紋理圖集提取動畫幀。已整合至匯出流程中。PTexture2D 佈局中的 PNG 圖集尚待重新編譯。[前一項：`v2.176.6.0`]
- **`v2.176.6.0` — ComposeWorldMatrix 裸鉤 + ApplyQueued 修正 + 重型鉤子運作穩定。** **修補程式**。Lane **Jarvis**。已將 ComposeWorldMatrix 從重型鉤子中移除（每幀皆被呼叫，但無實質作用）。 已確認 SetupSceneNode 為 BindMaterialTextureSampler（IDA）。ApplyQueued 會在工作執行緒中立即執行（無延遲）。重型鉤子（WireInstance + CommitInstanceMappings）運作穩定且不會當機。[先前：`v2.176.4.0`]
- **`v2.176.4.0` — field172 法線貼圖 + 特殊車道掃描器 + 已還原的模組。** **更新檔**。車道 **Jarvis**。field172 擷取了額外的 PAssetReference 連結。特殊車道掃描器：`ScanSpecialLaneTextureRefs` 讀取 .dae.phyre 至 tex/<name>.dds COLLADA 來源路徑。已還原 Spira Reforge + FFX_Data + ffx_ps2 模組。[先前：`v2.176.2.0`]
- **`v2.176.2.0` — Vertex co

光照優先級 + 法線貼圖基礎 + 綁定。** **修補程式**。Lane **Jarvis**。頂點顏色：無貼圖的子網格使用「每頂點」顏色流。法線貼圖：`DescriptorGltfMaterialTexture` 與`NormalMapPngPath`, 作家發表`normalTexture` 在 glTF 中。透過在 PParameterBuffer 中導入額外的 DDS 來進行綁定。[先前：`v2.176.1.0`]
- **`v2.176.1.0` — 已從 glTF 中移除 KHR_materials_unlit（啟用 PBR 著色）。** **修補程式**。Lane **Jarvis**。所有材質皆使用`KHR_materials_unlit` — 照明為零。現在改用 Three.js 原生的 PBR，搭配 HemisphereLight 與 DirectionalLight。已修正 flipV。[先前：`v2.176.0.0`]
- **`v2.176.0.0` — MinHook 遷移 + WireInstanceToSceneNodes + C1-C3 錯誤修正。** **次要更新**。 Lane **Jarvis**。PolyHook → MinHook (MH_CreateHook + MH_ApplyQueued，執行緒安全)。WireInstanceToSceneNodes (0x65B0F0)：447 筆 PMeshInstance↔PNode 配對條目。 CommitInstanceMappings (0x65A850)：條件式掛鉤。C1：繞道處理間的關機檢查。C2：g_currentArea/Field 的原子讀取。C3：追蹤執行緒中的超時與重試。已修正 RVA 錯誤。[先前：`v2.175.1.0`]
- **`v2.175.1.0` — a_ability.bin 主資料表修補程式 + SinCurseHook + OD 試算表。** **次要**。Lane **Jarvis**。a_ability.bin：已套用 AU1-AU7 修補程式（造成、抗性、元素、自動狀態、自訂、相容性）。 SinCurseHook：用於 SIN 詛咒屬性轉換的 C++ 執行時鉤子。SinCompatibilityMatrix + SinCurseSidecarIO。monster-od-master-spreadsheet.csv：12 隻怪物試運行 OD。Macalania SIN 名單。[先前：`v2.174.2.1`]
- **`v2.174.2.0` — 自訂混合：將標籤「Remiem Temple」→「Mushroom Rock Road」（C++ 選單）。** **修補檔**。賽道 **Jarvis-ARENA**。 將遊戲選單（x3/x4/x5）中可見的標籤名稱，透過 C++ hook 從「Remiem Temple」改名為「Mushroom Rock Road」（`ArenaPlusComposePick.cpp`) 以及日誌中 (`dllmain.cpp`). 技術關鍵`remiem` 保持不變。C# (`BattleComposeRunner.cs`) 已經標記正確，並套用了「camera behind-party」標籤。DLL 已編譯並部署完成。[前一項：`v2.174.1.0`]
- **`v2.174.1.0` — 自訂混音 x3：Remiem 場景（kino00_00）的對齊。** **PATCH**。**Jarvis-ARENA** 賽道。修正了場景中存在的差異，該差異在於`remiem` 決定要`kino00_70` 在 C++ 中（導致錯誤）

（在「自訂混音 x3」中出現「分配/擴充遭拒」）以及`kino00_00` 在 C# 中。現在已正確指向`kino00_00` (Mushroom Rock Road) 在兩者中皆有。[上一頁：`v2.174.0.0`]
- **`v2.174.0.0` — 基馬里 雙刃蘭塞特鉤（羅索 OD → 藍魔導士 MP）。** **次要**。車道 **賈維斯-MAGIC**。`KimahriLancetDualGrantHook` +`kimahri_lancet_dual_grant.flag`: 《刺胳針》「邊用邊學」專欄 104–115 頁，《格蘭塔》第 323–334 期 + 目錄`#322`; 透過 GridTeach 使用的 sidecar。Demita/Lancet+ 僅保留在網格中。[上一則：`v2.173.0.2`]
- **`v2.173.0.2` — 基馬里 藍魔法：捐贈者 #276 特別版（非 #282 羅恩索），sub=14 (+232)。** **PATCH**。 通道 **Jarvis-MAGIC**。RT2：選單會觸發 OD，因為開場動畫複製了 Ronso Rage；已修正鉤子在 +296 處停止重新注入 104–115 的問題。[先前：`v2.173.0.1`]
- **`v2.173.0.1` — 自訂混音 x4 Bikanel：絕對擴散 ×2.65（Jarvis-ARENA）。** **PATCH**。RT2 aeons Dark 儘管鏡頭狀態正常，但仍相互黏著 — 合成網格 + 隊伍方向壓縮 X/Z。Compose 現已支援 monLive vanilla 縮放`nagi05_24` 以質心為起點（備用配方四重奏），將絕對座標寫入`bika02_01`，無首領提示；xSpan ~185 (±93)。F7 → **建構 + 啟動**。[上一頁：`v2.173.0.0`]
- **`v2.173.0.0` — GridTeach 擴充選單掛鉤：金哈里 藍魔法 (#322) + 尤娜 白魔法+ (#366)。** **次要**。萊恩 **Jarvis-MAGIC**。`GridTeachHook` v4.5 後`BuildActorCommandMenu`: 跨作用元在環上的 scrub 操作（+296 case 4 + 其餘桶）+ 注入 opener／已學習的女兒節點；常數`#322/#366` 在`ffx_addresses.h`. 重建`ffx-hooks.dll` +`grid_teach.flag`. RT2 待處理。[上一則：`v2.172.0.7`]
- **`v2.172.0.7` — Lulu Multi-*：對隨機目標（非全體）造成 3 次命中，MP180。** **更新**。路線 **Jarvis-MAGIC**。`#337–340` `SetRandomEnemyHits` (Fury 規格)；`MultiGaMpCost=180`; RT0`RandTgt`. [上一頁：`v2.172.0.6`]
- **`v2.172.0.6` — Wakka 套組：已退役的 Twin Reel；Jinx Ball P16/MP200；Quad Foul poison+MP180。** **PATCH**。Lane **Jarvis-MAGIC**。`#351` 未使用；`#352` Jinx Ball 捐款人`#13` 技能戒指 P16 MP200；`#350` Quad Foul 描述 + Poison 3t MP180；副駕駛 Wakka=`350,352`. RT0 已處理 367 行。[上一頁：`v2.172.0.5`]
- **`v2.172.0.5` — 提達套組：僅含「刀刃風暴」`#358` (P16、MP180、3 擊單發)。** **PATCH**。Lane *

*Jarvis-MAGIC**。`#356`/`#357` 已停用 (UNUSED)；捐贈者延遲攻擊`#6` （無「Quick Hit」）；Tidus 的 sidecar=`358`. [上一頁：`v2.172.0.4`]
- **`v2.172.0.0` — Yuna White Magic+ 選單開啟器 (#366) — Blue Magic 標準版，非 Special 版。** **輕微**。Lane **Jarvis-MAGIC**。附錄`#366` 主戒圈上的「White Magic+」（供體`#278`,`MainMenu+OpenCommandMenu`); 女兒們`#343–347` 從……遷徙至`sub=14` (特別) 致`sub=4` (+296，每名角色專屬緩衝值——與基馬里的「隆索」效果隔離)。GridTeach 綁定`367` 行。Sidecar Yuna 包含`#366`. RT2 待處理。[上一則：`v2.171.0.16`]
- **`v2.171.0.16` — 自訂混合 x4：Anima-safe 擴散（Jarvis-ARENA）。** **PATCH**。配備 Anima 的 RT2 Bikanel 四通道系統發生崩潰 — nudge`x*=0.50` 向中心拉；網格 ±68 / Z 128–186，僅 Anima +Z 深層。F7 → **建構 + 啟動**。[上一頁：`v2.171.0.15`]
- **`v2.171.0.15` — Spira Reforge command.bin 撰寫者：Biora Lulu，MP 重新平衡，Tidus 自我增益，護符已停用。** **更新**。路線 **Jarvis-MAGIC**。`#348` 比奧拉 → 露露（毒屬性＋「菲拉加」等級的傷害）；`#349` Sleepra 已停用；`#350` 四重犯規＋毒 MP56；吸取／滲透-ga／尤娜 *ga／奧隆 群體 MP↑；`#356–358` `FlagTargetSelfOnly` (RT2 待定)；`#320–321`/`#359` 未使用；側車`Lulu=337..342+348`,`Wakka=350..352`,`Tidus=356..358`. RT0 已處理 366 行。[上一頁：`v2.171.0.14`]
- **`v2.171.0.14` — 自訂混合 x4：更寬廣且更深邃的擴散（Jarvis-ARENA）。** **補丁**。RT2 Bikanel 攝影機正常；aeons 在隊伍中及彼此之間緊密相連。chunk3 monLive：翅膀 ±58 / Z +20，內側排 ±30，中心 Z 142；微調 Valefor/Yojimbo/Ixion/Shiva 以減少重疊。 F7 → **建構 + 啟動**。[先前：`v2.171.0.13`]
- **`v2.171.0.10` — GridTeach v4.4：修復了在戰場上開啟「狀態」視窗時數值會重置的問題。** **修補程式**。Lane **Jarvis-MAGIC**。`786BC0` (`PrepareSaveCommandState` =`InitPlySaveMenuPanel`) 正在重新載入範本`ply_save` +`A53DE0` 在「狀態/裝備」選單中 — HP/Str 會恢復至基地值（S.Lv 保持不變）。v4.3 已移除繞道機制（原版仍可運行）。修正：繞道機制僅限戰鬥中生效（`sub_7817D0` return-addr 閘) + skip`A53DE0` 在 FullGridCompiler 中，當儲存已填入資料的網格時；guard`786BC0` 在 FullGrid 中，若 GridTeach 處於關閉狀態。**RT2 通過** (Halyson)。[上一則：`v2.171.0.9`]
-

**`v2.171.0.13` — Mod 文件：已停用 ≠ 已從 command.bin 中移除。** **REVISION**。Lane **Jarvis-MAGIC**。Handoff 366 行；`#320–321`/`#359` 停用後，行仍保留。[上一頁：`v2.171.0.12`]
- **`v2.171.0.9` — Spira Reforge 強化版：低 P／高 MP 的物理多段攻擊。** **補丁**。路線 **Jarvis-MAGIC**。Twin Reel／Jinx Ball、Mugra／Mugga、Tidus`#356–358`. [上一頁：`v2.171.0.8`]
- **`v2.171.0.8` — Multi-* Lulu：配方`SpecialMagic` (15) 而不是`IgnoreMagicDefense`.** **修補程式**. Lane **Jarvis-MAGIC**. RT2 後的 Lock Halyson（Fire Breath BM 可對抗 Dark Aeon）。`#337–340` 維持 P62/MP80/3 次命中。[前一則：`v2.171.0.7`]
- **`v2.171.0.7` — Spira Reforge 擴充版：Multi-* P62/MP80/3 次命中；物理多重命中微調。** **更新**。路線 **Jarvis-MAGIC**。`#337–340` MP 64→80；命中次數 6→3；明確標示的 P 值 62。提達斯／瑞庫／瓦卡 多段擊中：威力／命中次數降低。RT0 通過。[前一則：`v2.171.0.6`]
- **`v2.171.0.6` — Yuna *ga：Special 子選單（White 24/24 環已滿）。** **PATCH**。Lane **Jarvis-MAGIC**。`#343–347` `sub 2→14` (+232，32 個插槽)；寫入器`SetPartySpecialSubMenu`. [上一頁：`v2.171.0.5`]
- **`v2.171.0.5` — 提達斯進階技能：技能子選單（非超載模式）。** **修補程式**。Lane **Jarvis-MAGIC**。OD 捐贈者`#96/97/99` 繼承`SubMenu=4` (+296 OD 環)；`#356–359` 現在`sub=3` Skill. Bin 進入`work/`, mod`jppc`+`new_uspc`, Steam。[上一頁：`v2.171.0.4`]
- **`v2.171.0.5` — Spira Reforge：Wakka 重製鎖定「雙捲軸」＋「厄運之球」；Sleepra 為候選方案。** **修訂**。路線 **Jarvis-MAGIC**。`EXTENDED_COMMANDS_REWORK_QUEUE_2026-06-23.md` — Silencega 遭駁回；#349 A/B/C。[上一則：`v2.171.0.4`]
- **`v2.171.0.4` — Spira Reforge：排程重構擴充指令（RT2 Halyson 回饋）。** **修訂版**。Lane **Jarvis-MAGIC**。文件`mods/Spira Reforge/EXTENDED_COMMANDS_REWORK_QUEUE_2026-06-23.md` — 露露「多重攻擊 3 次」+「吸取 MP」；瓦卡／提達／奧隆／尤娜的屬性調整；提達的「對敵人施加增益效果」漏洞。[前一則：`v2.171.0.3`]
- **`v2.171.0.3` — GridTeach v4.2 + 擴充套件：CharacterUser 篩選器 + 正確的子選單。** **修補程式**。Lane **Jarvis-MAGIC**。`HasCommandBit` 尊重`CharacterUser` 在核心中（party bank + shadow 352+）；寫入器`SetOwned` 別再勉強了`MainMenu` nas skills（所以 #322 m

enu opener）。[上一頁：`v2.171.0.2`]
- **`v2.171.0.2` — GridTeach v4.1：修復攻擊/切換功能失效的問題（別名 actor+0x690）。** **修補程式**。Lane **Jarvis-MAGIC**。移除 actor 陰影種子；透過 detour 移除 ID 352 以上項目`HasCommandBit`. [上一頁：`v2.171.0.1`]
- **`v2.171.0.1` — Bikanel 自訂混音：chunk0 攝影機`nagi05_24` + 散射派對行（Jarvis-ARENA）。** **補丁**。RT2 沙漠模式正常，但鏡頭會隨機變動`bika02_01` 僅顯示 1 個 Aeon；未旋轉的 Widen Polar 構圖。與 Macalania Open 的模式相同：將供體四邊形中的 chunk0 ATEL 嫁接至由隊伍隊列引導的 chunk3 擴展中`nagi05_24`; 實習持續中`bika02_01`. F7 → **建置 + 執行** 為必選步驟。[上一頁：`v2.171.0.0`]
- **`v2.171.0.0` — GridTeach v4：擴充指令 RT2 grant (#322–365)。** **輕微**。Lane **Jarvis-MAGIC**。`GridTeachHook` 選單編號 366，繞道`BuildActorCommandMenu`, sidecar 18 個單字（陰影 ID 352+），腳本`RuntimeTools/SpiraReforgeRt2/set-grid-teach-sidecar.ps1`. Doc`FFX_GRID_TEACH_EXTENDED_BANK_WIDEN_2026-06-23.md`. [上一頁：`v2.170.0.17`]
- **`v2.170.0.17` — Bikanel 自訂混合包：781D60 bika 代幣`0x01600001` (Jarvis-ARENA)。** **PATCH**。RT2 日誌：`MsBattleEncountExe` ret=-1 但`n2` 從未出現過 2 — 戰鬥未開始；僅`781D60` 排隊。Bikanel 跨地圖：部署`bika02_01` +`781D60(0x01600001)` + 密鑰（非 FGF，非 nagi 代幣）。[前一則：`v2.170.0.16`]
- **`v2.170.0.16` — 自訂混搭：FGF 延遲 + Remiem 組合修正 (Jarvis-ARENA)。** **修補程式**。 Bikanel 的即時 FGF 無法啟動戰鬥（force-gate 在 tick 發生前即關閉）；使用 SetBattleFlags+pin 進行延遲發動。Remiem x3：`kino00_00` (grow OK) 而不是`kino00_70` 多區域。[上一頁：`v2.170.0.15`]
- **`v2.170.0.15` — Spira Reforge：RT2 角色擴充指令指南。** **修訂版**。Lane **Jarvis-MAGIC**。Doc`mods/Spira Reforge/EXTENDED_COMMANDS_RT2_GRANT_GUIDE.md` — 地圖`#322–365`, 藍魔奇馬里（選單`#322` + 子選單 14)，GridTeach 側邊欄（按套件）。[上一項：`v2.170.0.14`]
- **`v2.170.0.14` — Bikanel 自訂混合：推出原生 FGF（非 nagi 代幣）（Jarvis-ARENA）。** **修補程式**。日誌已證實`781D60(0x01AE0017)` 總是將佇列重新寫入納吉洞穴（`fieldHi=63`); backdrop/pin nagi 的駭客技巧均告失敗。Bikanel：d

eploy`bika02_01.bin` +`MsBattleEncountExe(47/0/1)` + 圖釘；洞穴持續延伸`nagi05_23`+token。[上一頁：`v2.170.0.13`]
- **`v2.170.0.13` — 《Spira Reforge》：Kimahri 雙持 Lancet 獎勵 §10.17（設計鎖定）。** **修訂**。Lane **Jarvis-MAGIC**。Lancet +`RonsoRageId` 來自怪物的 → OD + 藍魔導士 MP 合併；全體勾選。Doc`FFX_KIMAHRI_LANCET_DUAL_GRANT_RESEARCH_2026-06-23.md`. [上一頁：`v2.170.0.12`]
- **`v2.170.0.12` — Bikanel 自訂混音：在視覺背景（Jarvis-ARENA）之前播放曲目列表。** **PATCH**。RT2 日誌：標記為`field=47` 在載入過程中重新解析`bika02_01` (Alcyone 等) 忽略複合二進位數。現在進行跨地圖操作：定位`nagi05_23` + G/F 約 60 幀無視覺補丁；僅在 tick 之後出現`field=47 bf=1049` 前往沙漠網格。[上一頁：`v2.170.0.11`]
- **`v2.170.0.11` — Spira Reforge：雙倍／三倍掉落自動能力 §10.16 + 掛鉤文件。** **修訂版**。Lane **Jarvis-MAGIC**。 新自動能力 ID 129–130（×2/×3 道具數量）；連結`DoubleTripleDropHook` 已編碼；偷竊／搶劫／賄賂 待定 餘額。[前一項：`v2.170.0.10`]
- **`v2.170.0.10` — 《Spira Reforge》：終局階段「Omega Ruins」刷怪指南 §15.** **修訂版**。路線 **Jarvis-MAGIC**。 地點 = 難度較高的刷怪點；戰利品/吉爾/AP/寶箱 ↑；超強頭目；獨立陣容（已移除共享角色）；首名頭目 → 擊殺後隨機削弱。專精`OMEGA_RUINS_ENDGAME_FARM_SPEC.md`. [上一頁：`v2.170.0.9`]
- **`v2.170.0.9` — Bikanel 自訂混音：pin`nagi05_23` + 視覺背景 47/1049 (Jarvis-ARENA)。** **修補程式**。RT2 日誌已驗證`781D60` 將佇列重新寫入至`fieldHi=63 formation=3` (vanilla 洞穴)；bf-only 不會改變場景或陣容。恢復載具的 G/F，固定`g_FFX_Battle_EncounterName`, 視覺勾選標記`field=47 bf=1049`. [上一頁：`v2.170.0.8`]
- **`v2.170.0.8` — Spira Reforge：Sin-skills（僅限 SIN 狀態）＋盧卡後 Overdrive (§13.2)。** **修訂**。 Lane **Jarvis-MAGIC**。**僅**在 SIN 效果下觸發的全新怪物技能（VFX 重新上色）；盧卡之後的 Overdrive 約 1–2 次/區域，**與 SIN 無關**，多數為新技能。[先前：`v2.170.0.7`]
- **`v2.170.0.7` — 《Spira Reforge》：第13節 — 陣型對決`m###` （首領已調整，戰鬥中無額外敵人）。** **修訂**。Lane **Jarvis-MAGIC**。闡明 §13.1：v0.1 已重新平衡首領在`m###`/AI；第13條僅限於**該場比賽的參賽名單**（不包括塞穆

r + 4 次加法）；擴展至 5 = **隨機數**。[前一項：`v2.170.0.6`]
- **`v2.170.0.6` — Bikanel 自訂混搭：僅限 BF 的沙漠地圖 + 廣角鏡頭（非嫁接）（Jarvis-ARENA）。** **補丁**。
- **`v2.170.0.5` — Spira Reforge：戰鬥範圍 — 已修改的隨機遭遇，頭目僅限 SIN 模式。** **修訂版**。Lane **Jarvis-MAGIC**。 §13.1：專注於 **隨機遭遇戰**（最多 5 名敵人）的永久陣容/bin；**劇情頭目** 的 bin 保持原樣；頭目層級 **僅** 透過 SIN 開關啟用 (§5.6)。[先前：`v2.170.0.4`]
- **`v2.170.0.4` — 《Spira Reforge》：戰鬥規模擴展至最多 5 名敵人（設計鎖定）。** **修訂**。Lane **Jarvis-MAGIC**。
- **`v2.170.0.3` — Bikanel 自訂混音：aeon-wide graft 鏡頭`nagi05_24` (Jarvis-ARENA)。** **PATCH**。沙漠場景`bika02_01` 保留背景/派對錨點；chunk0 ATEL（戰鬥鏡頭）來自捐贈四機位`nagi05_24` 來源`BattleChunk0GraftWriter` — 面對 4 隻巨型黑暗永恆者時，隨機遭遇相機根本無計可施。F7 → 部署後必須執行「建構 + 發射」。[先前：`v2.170.0.2`]
- **`v2.170.0.2` — Bikanel 自訂混合：範本`bika02_01` FGF 47/0/1（Jarvis-ARENA）。** **PATCH**。RT2 戰鬥快照 Halyson：沙漠隨機 =`bika02_01` @ idx **47** bf **1049**，不`bika03_03` @ 48/0/3（沙蟲）。Compose 與元資料已對齊；文件`FFX_ARENA_PLUS_BIKANEL_BIKA02_RT2_2026-06-23.md`. [上一頁：`v2.170.0.1`]
- **`v2.170.0.1` — 自訂混合：關閉場景的執行時修補程式（Jarvis-ARENA）。** **修補程式**。RT2 日誌：帶有`field_idx=36` (Macalania Forest) 重新解析了 vanilla → Chimera 的表格。Compose 已將場景模板寫入載體的 bin 目錄；launch 僅需將 token 加入佇列`781D60`. 修補程式`@0xD2C254` 現在採用「主動訂閱」機制（`arena_plus_scenario_backdrop.flag`). [上一頁：`v2.170.0.0`]
- **`v2.170.0.0` — Field Tier C1：PMeshInstance 地圖 + glTF 實例群組 + FieldPack 工廠 (Jarvis-FIELD-RE)。** **次要**。`ParseInstanceMap()` →`{assetId}.phyre-instance-map.json`;`DescriptorStaticGltfWriter` flag`--instance-group`; PNode 父鏈 世界 組合 離線;`RuntimeTools/FieldPackFactory/` (`build-field-pack.ps1`,`mount-work-for-mapviewer.ps1`,`build-fieldpack-chr-subset.ps1`); MapViewer`window.__fieldExplorerReady`;`ffx_addresses.h` 修正`0x6F6D40` + RVA

 `0x65B0F0`. [上一頁：`v2.169.0.2`]
- **`v2.169.0.2` — Spira Reforge：B 套組 屬性網格補償（原地面板）。** **修訂版**。Lane **Jarvis-MAGIC**。 鎖定 §12.1.1：STR–LCK 層級提升 +1；HP 200→250 / 300→400；標準版 MP 基礎值 = +20/+40（49+7 節點）→ +25 / **+60**（`up_value` 8→12 英寸`0x24`); 僅限路線 A`panel.bin`. [上一頁：`v2.169.0.1`]
- **`v2.169.0.1` — Bikanel 自訂混音：僅限 bf 的跨地圖 + Arena+ 音樂（Jarvis-ARENA）。** **修補檔**。RT2 日誌證實重新修補檔`field_idx=48` 在載入期間已解決`bika03_03` (Sand Worm) 而非複合二進位數`nagi05_23`. Cross-map（Bikanel/Remiem）目前僅提供補丁`battlefield_id` (LOWORD @`0xD2C254`); 承運商`field_idx` 保持原樣；chunk0/camera 已預先包含在 Compose 的範本中。 MusicHook：45 秒待處理，攔截 Prep/Play/SwitchCrossfade（第 21 軌除外），首次觸發時不消耗資源 — 避免在覆寫 145 後出現 vanilla 138。[先前：`v2.169.0.0`]
- **`v2.169.0.0` — Field Explorer CHR 模型 + PNode 離線解碼 (Jarvis-FIELD-RE)。** **次要**。MapViewer 嘗試載入烘焙後的 glTF 檔案 (`/work/*_anim`) 在 CHR 引腳上；較大的引腳 + 標籤；PhyreMapExportLab 會輸出`phyre-scene-graph-report.json` + 標記`--node-per-object`. [上一頁：`v2.168.0.0`]
- **`v2.168.0.0` — Field Explorer：場景節點 + 商店／小屋的代理（Jarvis-FIELD-RE）。** **次要**。WalkManifest 讀取`sceneNodesPlaced`; MapViewer 覆蓋層繪製 Phyre 圖層及物件的 3D 代理物件`f###`; Field Scout 重新啟用鉤子`ComposeWorldMatrix`/`SetupSceneNode` 在戰鬥中使用「跳過」。[上一頁：`v2.167.0.6`]
- **`v2.167.0.6` — 自訂組合：在陣容中加入配備「Magus」（+3）的「fix compose」（Jarvis-ARENA）。** **更新**。`AssignSpreadPositions` 使用「選取次數計數」（3）對比 5 名演員的網格 → 當機`role grid mismatch` (exit 3762504530)。現在將 Magus 在陣型中的佔位擴增 3 格。[先前：`v2.167.0.5`]
- **`v2.167.0.5` — 自訂混搭 Bikanel/Remiem：跨地圖背景 + 載具別針（Jarvis-ARENA）。** **PATCH**。代幣`nagi05_23` 即使使用 compose，仍會強制設定 field 63（Cavern）`bika03_03`. Cross-map 現已發布更新`field+bf` 場景 + 別針`g_FFX_Battle_EncounterName` 在複合載體中（完好的「黑暗永恆」）。[前一則：`v2.167.0.4`]
- **`v2.167.0.4` — F7 Arena+：消除 Enter 鍵的回彈（選單 + 配合

姿勢) (Jarvis-ARENA)。** **更新**。 開啟子選單／戰鬥時的冷卻時間（10f 主介面，24f 組隊介面）；Aeon 的切換速度更快（7f）；Launch／Relaunch 速度較慢（28f）。Edge-latch 可避免長按 Enter 鍵時誤觸錯誤的行。[先前：`v2.167.0.3`]
- **`v2.167.0.3` — Spira Reforge：網格線 — 重新賦予「節點」屬性（原版技能保持不變）。** Lane **Jarvis-MAGIC**。**REVISION**。Halyson：約44個狀態/屬性節點轉化為技能教學`#322–365`；原版技能結節 **不會** 被觸發；請透過「bump」來彌補`IncreaseAmount` 其餘的統計數據（待定）。Doc`VISION_AND_ROADMAP.md` §12.1. [前文：`v2.167.0.2`]
- **`v2.167.0.2` — 自訂混編 x4 Bikanel：修復 Sand Worm vanilla 劫持（Jarvis-ARENA）。** **修補程式**。執行時修補程式`field_idx=48` 重新解決`bika03_03` (沙蟲) 位於代幣上方`nagi05_23`. 跨地圖（Bikanel/Remiem）→ bin 編排中的場景（`bika03_03` chunk0）；僅當 field=63（Cavern）時才套用 FGF 修補程式。[前一則：`v2.167.0.1`]
- **`v2.167.0.1` — 自訂混音 x4/x5：背景 Bikanel/Cavern/Remiem + aeon-wide 鏡頭（Jarvis-ARENA）。** **更新檔**。`ScenarioBattlefieldIdForKey` 只有 Macalania → Mix x4 Bikanel 會掉落 vanilla`bika03_03` （沙漠中的機器）。目前 bf=1049/1080/1035 + 僅視覺更新；實驗室 x4/x5 使用載體的廣角鏡頭（`nagi05_24`/`_50`) 對「黑暗永恆」的讓分幅度更大。[前一則：`v2.167.0.0`]
- **`v2.167.0.0` — Monster AI Editor：ATEL scaleOwnSize 縮放（Jarvis-MAGIC）。** **輕微**。YUNALESCA 卡片適用`scaleOwnSize` (0x7028) 透過 DeathAnimation 結束後的插入操作，或對現有浮點數組進行倍增；捷徑 +10%/+80%；讀取腳本的當前均勻縮放比例。[先前：`v2.166.0.16`]
- **`v2.166.0.16` — 自訂組合 x4/x5：移除空的場景行（Jarvis-ARENA）。** **修補程式**。選單原本保留了 4 個固定槽位；包含 3 個場景的層級在頭目戰前會出現空白欄位。動態佈局由`g_scenarioCount`. [上一頁：`v2.166.0.15`]
- **`v2.166.0.14` — 自訂混合森林：後標記背景排隊修補程式（Jarvis-ARENA）。** **修補程式**。`781D60` 正搬運`mcyt00_22` 並忽略 FGF 36/mcfr；DLL 重新修補`dword_112C254` + 當情境不為預設值時，戰鬥名稱應置於標記之前／之後。[先前：`v2.166.0.13`]
- **`v2.166.0.13` — 戰場偵察員：pr

ep/完成單次走點 + 自動匯入 (Jarvis-FIELD-RE)。** **修補程式**。`prepare-field-scout-walk.ps1` (ULTRA 版本、隔離標記、NativeMenu 關閉) +`finish-field-scout-walk.ps1`; 「發佈」編輯器會自動載入新工作階段。[上一頁：`v2.166.0.12`]
- **`v2.166.0.12` — 自訂混音「馬卡拉尼亞森林」：mcfr00 + tableIndex FGF (Jarvis-ARENA)。** **PATCH**。RT2 實戰實驗室：森林 =`36/0/0` +`mcfr00_00` (非 mcyt/id 340)；Open = idx 42。[上一則：`v2.166.0.11`]
- **`v2.166.0.11` — 戰況追蹤器：BTL 快照 + 響應式佈局（Jarvis-MAGIC）。** **修補程式**。「戰鬥快照」卡片（戰場、部隊、陣型、前線、路線游標等——與 Live Battle Lab 採用相同的解碼方式）＋以「盟軍／敵軍」分頁取代 4 欄網格。Chr 編輯器未作修改。[先前版本：`v2.166.0.10`]
- **`v2.166.0.10` — 注入式 DLL：已恢復綠色／紅色霓虹燈切換功能（Jarvis-MAGIC）。** **修補程式**。藥丸的「開啟」／「關閉」狀態恢復為綠色`#00E87A` 和紅色`#FF2A4D` 具有強烈的光暈效果；備用顏色不再呈現酸灰色。[先前：`v2.166.0.9`]
- **`v2.166.0.9` — 戰鬥追蹤器：版面顯示異常 + 清單對比度（Jarvis-MAGIC）。** **修補程式**。嵌套網格`*,*`/`2*,3*` 收起詳細資訊面板（中央留白）；恢復為 4 欄固定佈局`150,*,300,*` 與`MinWidth` 在 ScrollViewer 中。陣型外的盟友會使用`TextMutedBrush` 而非`DarkRed`. 裝填時自動選取第一個盟友／敵人。[上一頁：`v2.166.0.8`]
- **`v2.166.0.8` — F7 選單：移除動態霓虹光條 + 增加玻璃透明度（Jarvis-ARENA）。** **修補程式**。移除街機外框與掃描效果；採用邊緣平滑的靜態水晶面板。[先前版本：`v2.166.0.7`]
- **`v2.166.0.7` — F7 選單：玻璃面板 + 英文字串 + 較淺色的背景（Jarvis-ARENA）。** **PATCH**。帶霓虹邊框的透明頁首／頁尾；中樞介面文字採用英文（後續將進行國際化）。[上一頁：`v2.166.0.6`]
- **`v2.166.0.6` — F7 選單：Menu2D 響應式佈局（Jarvis-ARENA）。** **修補程式**。`MenuPhysW/H` + 分數`NX/NY/NW/NH`; 與緩衝區物理座標相符、厚度均勻的霓虹綠邊框（`MenuBorderPx`); 不再硬編碼 1080p/2K/720p。[先前：`v2.166.0.5`]
- **`v2.166.0.5` — F7 選單：霓虹綠邊框 + s 對齊

非對稱（Jarvis-ARENA）。** **PATCH**。將金色替換為霓虹綠（`#50FF90`); 設計空間中的對稱邊界；Arena+/Custom Mix 子選單中的綠色選取線。[上一頁：`v2.166.0.4`]
- **`v2.166.0.4` — 自訂組合 x3：4 個 Macalania 場景 + 選場器的起飛路線（Jarvis-ARENA）。** **更新檔**。選場器中的 Forest/Open/Open2/Remiem；起飛時套用該路線。[先前：`v2.166.0.3`]
- **`v2.166.0.3` — F7 選單：斯皮拉地圖（恢復原狀）（練習賽畫面 + 中等透明度）（Jarvis-ARENA）。** **更新檔**。深色練習賽畫面 +`worldmap` atlas 11948 +`ffx_bg` 細膩 + 浮水印；避免 v2.166.0.1 版的 HDR 溢出。[上一版：`v2.166.0.2`]
- **`v2.166.0.2` — 自訂混搭：修正後的 Macalania 場景 + 清單檔案的啟動路徑（Jarvis-ARENA）。** **修補程式**。Forest =`mcyt00_01`; 開啟 =`mcyt00_21`; 划槳 =`kino00_70` + 欄位 220。[上一頁：`v2.166.0.1`]
- **`v2.166.0.1` — F7 選單：移除全螢幕世界地圖疊加層（修復畫面溢出／空白問題）（Jarvis-ARENA）。** **修補檔**。遊戲畫面顯示清晰；網格／場地上方不再出現白色方塊。[先前：`v2.166.0.0`]
- **`v2.166.0.0` — 自訂混音：場景選擇器（僅限混音；固定預設）(Jarvis-ARENA)。** **次要**。F7 選擇器中每級 3 個場景；實驗室`--scenario`; manifest`scenario_key`. 《Gauntlet》／《Dark Rematch》維持不變。[先前：`v2.165.0.1`]
- **`v2.165.0.1` — F7 選單：移除藍色洗色效果；背景 = 純淨的斯皮拉地圖（Jarvis-ARENA）。** **修補檔**。移除`ffx_bg` + 藍色邊框 + 純色疊加層；世界地圖集 11948，高不透明度。[上一頁：`v2.165.0.0`]
- **`v2.165.0.0` — Arena+ Gil 經濟模型：每顆 Dark Aeon 的成本 + 預設值／混音中的總和（Jarvis-ARENA）。** **次要**。標記`arena_plus_charge_gil.flag`; 資料表 §13.1（Valefor/Ifrit 100k … Penance 500k）；預設組合 = 頭目總和；自訂組合 = 選定目標總和（Magus 300k）；若吉爾不足則鎖定；部署包含旗幟。 [上一頁：`v2.164.0.5`]
- **`v2.164.0.5` — Spira Reforge：在「暗黑永恆」中採用高AP策略（Yojimbo除外）。** 線路 **Jarvis-MAGIC**。 **修訂**。Halyson：大幅提升 Arena+ 天梯中《Dark Aeon》勝利的 AP；**《Dark Yojimbo》不包含**在此次調整範圍內。文件：`VISION_AND_ROADMAP.md` §5.2.1，`FFX_SPIRA_REFORGE_DARK_AEON_REBALANCE_RESEARCH_2026-06-15.md`. 數字待定；撰寫 `m###

.bin` loot AP. [anterior: `v2.164.0.4`]
- **`v2.164.0.4` — Arena+ 組合 x4/x5：捐贈者預設寬版 + 翼形排序（Jarvis-ARENA）。** **PATCH**。x4 捐贈者`nagi05_24`; 5位捐贈者`nagi05_50`；中央處較大；文件掃描 [前一頁：`v2.164.0.3`]
- **`v2.164.0.3` — Arena+ 組合 x4：將陣型向後方擴散（Jarvis-ARENA）。** **更新**。Z 格 +18；Valefor 兩翼寬度縮減。[先前：`v2.164.0.2`]
- **`v2.164.0.2` — Arena+ 中心：史詩級字幕 + 較小字體（Jarvis-ARENA）。** **修補程式**。標題保持不變；描述`DrawStringSub` 分開。 [上一頁：`v2.164.0.1`]
- **`v2.164.0.1` — Arena+ 選單：僅在「確認」按鈕上啟用防雙擊功能（Jarvis-ARENA）。** **修補程式**。預設冷卻時間 12→3 幀；開啟「Dark Aeon」子選單時，立即透過上/下方向鍵進行導航。[先前：`v2.164.0.0`]
- **`v2.164.0.0` — Arena+ F7 子選單 + 鏡頭/chunk0 設定檔 (Jarvis-ARENA)。** **輕微**。中樞：**Dark Aeon Rematch** / **Aeon Gauntlet** / **Custom Mix**；文件 [`FFX_ARENA_PLUS_COMPOSE_CAMERA_CHUNK0_TEMPLATE_2026-06-23.md`](docs/reverse/FFX_ARENA_PLUS_COMPOSE_CAMERA_CHUNK0_TEMPLATE_2026-06-23.md) (chunk0 提供者`mcyt00_21`, 技能槽交換、OD 條 ≠ HP 漏洞、極光重複使用)。DLL`ArenaPlusMenuKind`. [上一頁：`v2.163.0.4`]
- **`v2.163.0.4` — Field Explorer：在使用者介面上發佈 Scout（Jarvis-FIELD-RE）。** **PATCH**。按鈕：發佈 Scout／更新標記／發佈並開啟 Field；在當前進程中重新整理（不啟動第二個編輯器）；PS1`-SkipOverlayRefresh` 當從使用者介面呼叫時。[上一頁：`v2.163.0.3`]
- **`v2.163.0.3` — Arena+ 設定：將鏡頭角度調整為跟隨隊伍（鏡頭位於角色後方）（Jarvis-ARENA）。** **更新**。`BattleComposeRunner`: 將原版航母隊伍的 Z 軸重心移至對側，並將永恆體放置於該側（`mcyt00_22` party Z≈+2 → 怪物 Z 負值）；實驗室與 Steam 已重建。音樂完好無損。[前一則：`v2.163.0.2`]
- **`v2.163.0.2` — Arena+ 組建：交換「Dark Anima」／「Yojimbo」插槽 ID 並重新部署 Steam（Jarvis-ARENA）。** **更新**。`BattleComposeRunner`:`0x1153`=Anima,`0x1154`=《保鑣》（對應於`battle-model-catalog.json` / RE 專題；跨頁加寬 3 倍；重新發布的實驗室報告 +`mcyt00_22.bin` 重新組合（`ixion,shiva,yojimbo` → 插槽`0x1150,0x1151,0x1154`). 音樂 **未經修改**。[上一則：`v2.163.0.1`]
- **`v2.

163.0.1` — Field Explorer P0: CHR honest overlay + dedupe (Jarvis-FIELD-RE).** **PATCH**. `EncounterOverlayCompiler` + `ChrClassifier`: dedupe por ator (n/c/m/f), `field-encounters.json` v2 (`entities[]`, `chrCounts`, `新鮮度`), MapViewer layer toggles + labels honestos, publish C1 (`break`→`繼續`) + `Resolve-FieldKey` com limite de proximidade, `chr_spawn` com `區域／領域` no hook, ingest `註冊欄位` para chr. RT2 Field Actor ainda pendente. [anterior: `v2.163.0.0`]
- **`v2.163.0.0` — SGM 861 F1 內嵌商店重定向掛鉤 v1.75 (Jarvis-MAGIC-SGM)。** **次要更新**。`SphereGridFullGridCompilerHook v1.75`: 其中的 5 位元組存根修補程式`7F4900` @`0x3F4C0F` (NEG 撰稿人準備)，`0x3F5208` (NEG pos store)，`0x3F57E6` (POS 門市系統)；標誌`sg_f1_inline.flag` 支援 SKIP860，並允許使用 vanilla draw860 與`STORE-INLINE` 將過期資源重新映射 41252→41328。回覆：`docs/reverse/FFX_SPHEREGRID_861_F1_INLINE_STORE_2026-06-23.md`,`work/reverse/ida/f1_inline_patch_sites_2026-06-23.json`, F2 鏈`docs/reverse/FFX_SPHEREGRID_861_F2_ANIM_CAPTURE_STORE_RE_2026-06-23.md`. 編譯 DLL + RT2 遊戲內模組 **需進行測試**。[上一則：`v2.162.9.4`]
- **`v2.162.9.4` — Arena+ 指令：完整部署實驗室 + 消除 Enter 鍵回彈（Jarvis-ARENA）。** **PATCH**。退出`2147516570` =`ArenaMultiBossLab.dll` 缺失 — 立即部署，將整個資料夾複製到`modules\tools\ArenaMultiBossLab\`. 選取器：在「確認」時觸發上升沿，並於切換後有 20f 的冷卻時間（已修正按下 Enter 鍵時會取消選取的問題）。[先前：`v2.162.9.3`]
- **`v2.162.9.2` — Spira Reforge：RT2 測試框架交接（在網格生成前授予技能）。** Lane **Jarvis-MAGIC**。**修訂版**。文件`docs/ai/PROMPT_SPIRA_REFORGE_COMMAND_RT2_TEST_HARNESS_2026-06-18.md` — 貼至平行聊天室：最低部署`command.bin`,`GridTeach` + 側車`grid_teach_learned.bin`, 經由`ffxprobectl call 385D10`, 每包煙（貨運清單），測試結束時執行 **還原預設設定** 的檢查清單。[先前：`v2.162.9.1`]
- **`v2.162.9.1` — Spira Reforge：設計鎖定 — Overdrive→AP 輸出 + T 級別獎勵。** 線 **Jarvis-MAGIC**。 **修訂**。Halyson：移除「超載→AP」（刷AP很煩）；替代方案待定。SIN模式：**T**級的小怪也會獲得基礎屬性提升↑及更多掉落物（無具體數值）

（此文件）。文件：`FFX_SPIRA_REFORGE_VANILLA_OFFENSIVE_REBALANCE_2026-06-16.md`,`SIN_DIFFICULTY_MODE_SPEC.md` §3.4. [前文：`v2.162.9.0`]
- **`v2.162.9.0` — 已修復：MonsterAiEditor 錯誤`{StaticResource Spacing*}` + 恢復霓虹色調（Jarvis-UI）。** Lane **Jarvis-UI**。**PATCH**。Halyson 回報的兩個問題：(1) **錯誤：**`MonsterAiEditor_Control.axaml` 共有 4 筆紀錄`Padding="{StaticResource SpacingLg/Md}"` 這些問題在開機時無法解決（與該熱修補程式屬於同一類別）`v2.159.6.1` — 代幣`Spacing*` 居住於`Application.Resources` 在……之後`StyleInclude`，那麼`StaticResource` 錯誤；F3 掃描已使用`{DynamicResource}` 但這四行是手動試飛的`v2.159.6.0` （逃脫的）。改為`{DynamicResource Spacing*}` — 修正此錯誤。(2) **「難看、沒有霓虹色」的顏色：**該`v2.159.6.0` 將15個數值歸一化`Accent*FillBrush` (Shell/Protect/Regen/Gold/Cycle/Forbidden/Crimson/Undo/Refresh/Move/Haste/Reflect/NulAll/Builder/Reaction) 採用極深的色調 (`#21506A`/`#1E5E45`/etc.)，掩蓋了霓虹燈邊緣的亮度。已還原為**更飽和／鮮豔**的色調（例如：Shell`#21506A`→`#1A6E8C`, 保護`#1E5E45`→`#1E8050`, Gold`#4A4226`→`#6E5E2A`, 週期`#3D4F78`→`#3A5BB0`) — 介於深色填充與霓虹色邊框之間的半色調，既能突顯存在感，又不至於變成純霓虹色。霓虹色邊框／前景 (`#66D8F0`/`#6FE3B7`/`#AAB4FF`/etc.) **保持原樣**（原本就很美了）。這會影響所有消耗`Accent*` (MonsterAi 是最強的)。範圍：僅限視覺容器 — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 均未修改。發行版建置 **0 個錯誤**（403 個既有警告）。[先前：`v2.162.8.0`]
- **`v2.162.8.0` — 修正：SGM 861 OOB 插槽 860 hook v1.30 (Jarvis-MAGIC-SGM)。** **修補程式**。`SphereGridFullGridCompilerHook v1.30`: 開機異常`942B60` 41252→41328，擴展 SKIP (-861/-862)，F858 修補程式僅限寫入者 +0/+4，ALLOC-TRACE，製程監控，當 861 緩衝區就緒時重新啟用 draw860。RE：`docs/reverse/FFX_SPHEREGRID_861_PRODUCER_RE_2026-06-20.md`. DLL 編譯成功；RT2 遊戲內 **需測試**。[上一則：`v2.162.7.0`]
- **`v2.162.6.0` — 修正：指令面板`Ctrl+K` + 窄抽屜`Ctrl+B` (彈出視窗`IsOpen`, tunnel KeyDown) (Jarvis-UI)。** Lane **Ja

rvis-UI**. **PATCH**（修正了自 D 階段起便承諾但始終無法開啟覆蓋視窗的快捷方式）。Avalonia 11`Popup` 要求 **`IsOpen`** — 該程式碼曾使用`IsVisible` (no-op)。已遷移至 **tunnel** 處理程式的捷徑 (`KeyDownEvent`) 以便專注於 TextBox／子編輯器運作。`PlacementTarget` +`Topmost` 在彈出視窗中。Build Release **0 個錯誤**。[上一則：`v2.162.5.0`]
- **`v2.162.5.0` — i18n：遷移`ModuleRegistry` (41 個模組 × 5 個欄位) + 儀表板字串 + §16–§17 已完成 (Jarvis-UI)。** Lane **Jarvis-UI**。 **PATCH**（重用 F4 i18n 基礎架構；無新增產品功能）。後續提示`PROMPT_GLM_PHASE_E_HARD_AND_F`: **205 個鍵**`Mod_{id}_{Title|Description|Mode|Notes|Scope}` 在`Strings.resx` +`Strings.pt.resx` (發電機`work/_gen_module_i18n_20260622.ps1`);`Strings.Get`/`Strings.Module` 動態查詢；`ModuleCatalogEntry.Localized*` (儀表板、色盤、側邊欄工具提示、橫幅，來源：`SetModule` overlay 當`_currentModuleId` 修改登錄檔）。**+11 個登錄鍵** 儀表板（英雄已載入／空，標籤為「工作區／模組／掛鉤」）。`MainDashboard_Control` 賓達`LocalizedTitle/Description/Mode` +`{x:Static res:Strings.*}`.`docs/specs/EDITOR_UI_OVERHAUL_PLAN.md` 標記為 **DONE** 的 §16–§17（`v2.160.0.0`).`PORT_STATUS.md` 已核對 (`v2.162.4.0`→`v2.162.5.0`). **誠實度：** 當註冊表原本已是葡萄牙語時，提供完整的葡萄牙語描述；衛星版中已翻譯的英文標題；68 個內部字串`SetModule` 字面值已列入待處理清單。Smoke RT1 + Halyson 待合併。範圍僅限容器。建置發行版 **0 個錯誤**。[前一則：`v2.162.4.0`]
- **`v2.162.4.0` — F 階段 §F4：i18n 基礎架構 (`.resx`) (Jarvis-UI)。** Lane **Jarvis-UI**。**PATCH**（foundation；預設情況下無明顯行為變更——預設語言仍為 en）。**F 階段** 的第四個也是最後一個提交（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F4)。範圍：**僅視覺容器** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 未受影響。建立國際化基礎架構：**在此提交之前，該儲存庫的國際化設定為 0**`.resx`**；處處都有硬編碼的字串。**建立日期：**`Resources/Strings.resx` (中立 = en，約 17 個承重鍵：英雄頭銜、軌道標籤、調色板佔位符)

較舊的、動作標籤、模式按鈕) +`Resources/Strings.pt.resx` (PT-BR 衛星) +`Resources/Strings.cs` (透過靜態存取器`ResourceManager`，每個鍵對應 1 個靜態屬性 — 可在 XAML 中設定為`{x:Static res:Strings.Xxx}`) +`Strings.ApplyUiCulture()` (讀作`FFX_UI_LANG=pt|en`; 預設 = neutral/en; 箭頭`DefaultThreadCurrentUICulture` （在任何 XAML 綁定之前）。**接線：**`App.axaml.cs Initialize()` 火焰`Strings.ApplyUiCulture()` 在……之前`AvaloniaXamlLoader.Load`. 這些`.resx` 是`EmbeddedResource` 由 glob SDK 隱含的 (`Resources/**/*.resx`) — 經確認該衛星`pt\FFXProjectEditor.resources.dll` 已發出。**兩點承重綁定示範：** MainDashboard 的「開啟工作區資料夾」CTA（`{x:Static res:Strings.DashboardCtaOpenWorkspace}` + a11y 名稱) + 指令面板佔位符 (`Watermark="{x:Static res:Strings.RailSearchPlaceholder}"`). **誠實而言：** 完整的 i18n 是一項永無止境的工作（文件 §4.F4）。 此提交奠定了基礎並展示了模式；約 50 個 ModuleRegistry 的標題／描述以及數百個內部字串的遷移，則留作未來的待辦事項（在 2 個 resx 檔案中新增鍵值、在 Strings.cs 中新增屬性，並將字面值替換為`{x:Static}`). 今天尚未識別出任何非PT用戶，因此`FFX_UI_LANG` 未在 UI 中顯示（僅環境變數）。處理常式／綁定／寫入器／儲存位元組／掛鉤均未受影響。Release 版本建置 **0 個錯誤**（原有 403 個警告）。 **完成整個 F 階段**（F1-F4）。[先前：`v2.162.3.0`]
- **`v2.162.3.0` — F 階段 §F3：代幣清算 — 均勻填充 →`Spacing*` (67 個檔案中共有 518 個字面值)；CornerRadius **未進行標記化**（如實）(Jarvis-UI)。** Lane **Jarvis-UI**。 **PATCH**（design-system 的修飾；無新增功能）。**F 階段** 的第三次提交（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F3 — 「高流失率、低增量價值」）。範圍：**僅限視覺容器** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 均未受影響。 **填充掃描：** 518 個字面常數`Padding="N"` 已遷移至的制服 (N ∈ {4,8,12,16,20})`{DynamicResource SpacingXs/Sm/Md/Lg/Xl}` 共 **67 個檔案**`.axaml`** 來自`Modules/` 透過保守型腳本（`work/_padding_sweep_20260622.ps1`）

` — só substitui valores que batem **exato** com um token; deixou intactos os ~340 Paddings assimétricos/não-token como `Padding="10,6"`/`Padding="14"`). `MonsterAiEditor2_Control.axaml` **não** migrado (discontinued). **CornerRadius sweep (§F3b) = NO-OP honesto:** os valores `CornerRadius` ativos nos módulos são majoritariamente 5/6/7/14 — **nenhum** bate com os tokens `半徑 Sm=8`/`Md=10`/`Lg=12`/`Pill=999`. Forçar o valor mais próximo seria **mudança visual**, não tokenização. O doc citava "158 CornerRadius" mas esse count incluía `MonsterAiEditor2_Control.axaml` (discontinued, ~34 ocorrências de 8/10). Decisão documentada: deixar CornerRadius literal onde não há match exato. Pós-commit: 518 `Padding="{DynamicResource Spacing*}"` em 67 arquivos; 0 `Padding="16"` restantes. Handlers/bindings/writers intocados. Build Release **0 erros** (403 warnings preexistentes). [anterior: `v2.162.2.0`]
- **`v2.162.2.0` — F 階段 §F2：`AutomationProperties.Name` 全球範圍內約 98 個動作按鈕（a11y）（Jarvis-UI）。** Lane **Jarvis-UI**。**PATCH**（無障礙功能修訂；無新增功能）。**F 階段** 的第二個提交（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F2). 範圍：**僅限視覺容器** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 均未受影響。動作按鈕的可存取性：在此提交之前，F2 模組中僅有約 8 個按鈕具備`AutomationProperties.Name` （螢幕閱讀器無法讀出僅含圖示的按鈕）。**新增 98 個按鈕**：**其中 87 個透過腳本實現**`work/_a11y_name_sweep_20260622.ps1` （名稱取自按鈕的可見文字；以 UTF-8 格式讀取；跳過含有非 ASCII 文字或圖示字形（如 ◀/▶/… 以避免亂碼）於 12 個 Core Authoring + SaveEditorHub + (Customization/Shop/MixTable/KernelCommands) 中，以及 **4 個明確標示的** 項目在 KernelCommands 中（◀/▶ 「上一則／下一則 FSB 範例」、「匯入 fsbankcl」、「匯入自訂 WAV」），以及 **MainDashboard 中的 2 項**（開啟工作區 + QuickTile`{Binding Title}` — 僅圖示，優先考量無障礙性 (a11y)，+ **Main_Window 中有 5 處**（音樂／設定／工作區路徑／返回／前進 導覽列圖示）。提交後：**共 164 處**`AutomationProperties.Name` 共 18 個檔案`Modules/` （相較於先前 F2 範圍內的約 8）。Hand

lers/bindings/writers 未受影響。建置發行版 **0 個錯誤**（原有 403 個警告）。[先前：`v2.162.1.0`]
- **`v2.162.1.0` — F 階段 §F1：實用圖示（13 個新圖示）＋ 掃描表情符號（8 個檔案）`.axaml`) (Jarvis-UI)。** Lane **Jarvis-UI**。**PATCH**（視覺優化：圖示；無新增功能）。**F 階段**的首個提交 (`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F1)。範圍：**僅限視覺化容器** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 保持不變。**13 個新實用程式圖示** 位於`Styles/StudioIcons.axaml` (`IconSearch`/`IconAdd`/`IconRemove`/`IconWarning`/`IconUndo`/`IconRedo`/`IconFilter`/`IconOpen`/`IconClose`/`IconChevronDown`/`IconChevronRight`/`IconCheck`/`IconX` — Lucide-like，viewBox 24×24，`<StreamGeometry>`). **Sweep 表情符號** 共 8 個檔案`.axaml` 已列出：🏐/💾/🌅/🗺️ 已從標題中移除`sectionLabel`/`cardTitle` 以及「儲存」按鈕。「儲存」按鈕（`💾 Salvar`) 贏得了`<PathIcon Data="{DynamicResource IconSave}"/>` + 文字（MonsterAiEditor ×2、EncounterTableExplorer ×1、AuroraChamber ×3）。帶有表情符號的標題（`🌅`/`🗺️`/`🏐`) 的表情符號已被移除（使用 PathIcon 內嵌於 TextBlock 中的清理程式）。`SphereGridCanvas_Control.axaml` 已經清理乾淨了（已移除的表情符號在`v2.159.5.0` OPT-A6)。**8 項以外的獎勵：** 2 項頭銜`SetModule` user-visible (`"Save Editor 💾"`,`"Sphere Grid 🧩"` 在`Main_Window.axaml.cs`) 也因標題的視覺一致性而被刪除。表情符號在`.cs` （註解 + 狀態字串）**未受影響**（不在範圍內）。發行版建置 **0 個錯誤**（403 個既有警告）。[先前：`v2.162.0.0`]
- **`v2.162.0.0` — 第一階段已完成：`ModuleMasterDetail_Shell` 所有 12 個 Core Authoring 模組（E1-E12）（Jarvis-UI）。** Lane **Jarvis-UI**。**次要**（階段結束里程碑 — 整合 5 個 PATCH）`v2.161.1.0`→`v2.161.5.0`). 該項目的**整個E階段**`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` （§2 標準規範 + §3 E9-E12 + §4）已完成交付：**12 個 Core Authoring 模組** 已從手動開發版本遷移完成`Auto,*` /`2*,5*` /`3*,6*,3*` 網格（邊界卡）`Padding=16` 膨脹 + ScrollViewer）對標準 shell（`ModuleMasterDetail_Shell` 配備可收合式擴展器，`Padding=8`, 濃密)

. 模組：**E1 CtbBase、E2 PlayerGrowth、E3 Formation、E4 Treasure、E5 KeyItem、E6 AutoAbility、E7 BukiGetTreasureCatalog、E8 MonEditorSelector** (`v2.161.1.0`) + **E9 CustomizationEditor**（包含 2 個 Gear/Aeon 外殼的 TabControl，`v2.161.2.0`) + **E10 ShopExplorer** (3 欄層疊式佈局，十六進位→代幣，`v2.161.3.0`) + **E11 MixTableEditor**（112×112 矩陣，`v2.161.4.0`) + **E12 KernelCommands**（此儲存庫中最詳盡的檔案，共 977 行，將十六進位數轉換為代碼片段，`v2.161.5.0`). **硬性架構決策 (E9-E12)：** 在「自訂設定」中保留外部 TabControl（2 個外殼）； Shop 中的 MasterHeader 內，來源選擇器（source picker）改為下拉式選單（ComboBox）；MixTable 的 Detail 內，合作夥伴軸（partner axis）改為展開框（Expander）；KernelCommands 的 Detail 內，會話列（session bar）維持在介面殼層上方，且「使用位置」（Where Used）改為展開框（Expander）。每個模組皆獲得`rsp:Responsive.Breakpoints="True"` + 樣式`UserControl.narrow` 導致主節點在`<760px`. DataContext/綁定/處理常式/轉換器/`AutoSaveIndicator_Control`/`AtlasEvidenceBadgeStrip`/`IRestorableModule`/`x:Name`所有檔案均未變更。Writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 保持原樣。發行版建置 **0 個錯誤**（403 個既有警告 — Jarvis-UI 基準）。 下一階段：**F 階段**（F1 圖示+表情符號、F2 無障礙、F3 標記掃描、F4 國際化）。[上一階段：`v2.161.5.0`]
- **`v2.161.5.0` — E 階段 §E12：`KernelCommands` →`ModuleMasterDetail_Shell` (儲存庫詳細資訊，3 欄 + 會話列 + 十六進位) (Jarvis-UI)。** Lane **Jarvis-UI**。 **修補程式**（表面修飾：佈局遷移；無新增功能）。**E 階段**的最後一次提交（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E12 — 該計畫中**風險最高**的項目）。 範圍：**僅視覺化容器** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 保持原樣；DataContext/bindings/handlers/converters/IRestorableModule 未經修改。該`KernelCommands_Control.axaml` (977 → ~970 行) 將版面配置轉換為三欄式 (`3*,6*,3*` 指令清單 | 編輯器詳細資訊 | 「使用位置」）+ 經典 Pro Shell 工作列。**架構決策：** outer`RowDefinitions="Auto,*"` 維持不變 — **TOP SESSION BAR** 位於 shell **上方**（第 0 行，未變更）；第 1 行的 shell 則有`MasterList` = command ListBox (era Col0,`DisplayedCommands`/`Selec

tedCommand` + `FilterText` + botões Clonar/Apagar/Adicionar), `詳細資訊` = editor (era Col1, ~840 linhas de campos densos preservados byte-a-byte: Identity/Animations/Battle SFX 3 tiers/Menu/Characters/Costs/Attack Data/Element/Properties/Status/Status Special/Extra); a **3ª coluna "Where Used"** (era Col2) vira um **Expander colapsável dentro do Detail** (default colapsado, label "Where Used — monster links"). `x:Name`s preservados (`ThisControl`, `CommandList`, `MonsterLinksList`) — o code-behind referencia `MonsterLinksList.SelectedItem` em `OpenReferenceMonster`. `AutoSaveIndicator_Control` e os 3 converters (`角色`/`DamageFormula`/`HitCalcType`) preservados. **Hex → tokens no mesmo commit:** `#FF6B6B` (LoadError foreground) → `DangerBrush`; `#1A2A3A` (Spira Ward note bg) → `PanelDeepBrush`; `#3A6EA5` (Spira Ward note border) → `PanelStrokeBrush`; `#7EC8FF`/`#B8D4E8` (Spira Ward note foreground) → `AccentCoolBrush` (token exato já existe). Ganhou `rsp:Responsive.Breakpoints="True"` + style `UserControl.narrow` que colapsa o master em `<760px`. **Fecha a Fase E** (E1-E12 completa). Build Release **0 erros** (403 warnings preexistentes). [anterior: `v2.161.4.0`]
- **`v2.161.4.0` — E 階段 §E11：`MixTableEditor` →`ModuleMasterDetail_Shell` (112×112 矩陣，3 欄) (Jarvis-UI)。** Lane **Jarvis-UI**。 **PATCH**（表面修整：佈局遷移；無新增功能）。延續 **E 階段**（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E11)。範圍：**僅限視覺容器** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 保持原樣；DataContext/bindings/handlers/IRestorableModule 未經修改。該`MixTableEditor_Control.axaml` (176 → ~200 行) 遷移手動編寫的網格`3*,3*,5*` (112×112 矩陣：來源 ListBox | 夥伴 ListBox | 結果詳細資訊) 適用於標準 Shell。 **架構決策：** 此矩陣需要進行 2 次串接選取（origin → partner → result），無法直接套用標準的主從詳情模式。Origin（Col0）將轉為`MasterList` (僅針對主軸的殼體，`OriginFilterText`/`DisplayedOrigins`/`SelectedOrigin`); partner (Col1) 會變成 **可折疊擴展器中 Detail 內的選擇器**（預設為展開狀態 —`ResultFilterText`/`D

isplayedResults`/`SelectedResult`, label "Partner Item"); result detail (Col2) vira o topo do Detail (hero `heroBlue` preservado + session + Combination Editor). `AutoSaveIndicator_Control`, `GameIndex_Template` e `AtlasEvidenceBadgeStrip` preservados. Ganhou `rsp:Responsive.Breakpoints="True"` + style `UserControl.narrow` que colapsa o master em `<760px`. **Falta E12** (KernelCommands — maior detail do repo, maior risco). Build Release **0 erros** (403 warnings preexistentes). [anterior: `v2.161.3.0`]
- **`v2.161.3.0` — E 階段 §E10：`ShopExplorer` →`ModuleMasterDetail_Shell` (3 欄級聯繫) (Jarvis-UI)。** Lane **Jarvis-UI**。**PATCH**（表面修飾：佈局遷移；無新功能）。**E 階段**的延續（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E10)。範圍：**僅限視覺容器** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 保持原樣；DataContext/bindings/handlers/IRestorableModule 未經修改。該`ShopExplorer_Control.axaml` (361 → ~360 行) 遷移自訂網格`Auto,Auto,*` (3 欄級聯動：來源 ListBox | 商店商品行 ListBox | 槽位切片編輯器) 標準 Pro Shell。**架構決策：** 來源選擇器（Col0）將轉變為 **MasterHeader 中的緊湊型 ComboBox**（`LoadedSources`/`SelectedSource` +`LoadSummary` + Refresh）；商店行（Col1）變為`MasterList` (`FilterText` +`DisplayedShops`/`SelectedShop` + 濾波器回饋）；切片編輯器插槽（Col2）會將`Detail` (由卡片組成的密集型 WrapPanel`SelectedSlots` （包含 Image/ComboBox 及保留的「進階詳細資訊」展開選項）。`AutoSaveIndicator_Control` 以及`AtlasEvidenceBadgeStrip` 保留下來。**Hex → 代幣：**該插槽的視覺徽章原本有`#0D1621` (背景) 以及`#274760` (邊框) 內聯 →`{DynamicResource PanelDeepBrush}` /`{DynamicResource PanelStrokeBrush}`. 贏了`rsp:Responsive.Breakpoints="True"` + 樣式`UserControl.narrow` 導致主節點在`<760px`. **尚缺 E11-E12**（MixTable/KernelCommands）。發行版編譯 **0 個錯誤**（403 個既有警告）。[前一版：`v2.161.2.0`]
- **`v2.161.2.0` — E 階段 §E9：`CustomizationEditor` →`ModuleMasterDetail_Shell` (TabControl 內有 2 個 shell) (Jarvis-UI)。** Lane **Jarvis-UI**。**PATCH** (po

表面處理：佈局遷移；無新增產能）。**E階段**的延續（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E9)。範圍：**僅限視覺容器** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 保持原樣；DataContext/bindings/handlers/IRestorableModule 未經修改。該`CustomizationEditor_Control.axaml` (396 → ~340 行) 將手動編寫的網格遷移`3*,7*` (邊境卡`Padding=16` （膨脹 + ScrollViewer）的 **每個**`TabItem` 標準 Pro Shell — 該`<TabControl>` 外部（Gear / Aeon）是**保留**的；在每個`TabItem` 現在已有專屬的`ModuleMasterDetail_Shell` （2 個外殼，標籤分別為「Gear Recipes」／「Aeon Recipes」）。這兩組綁定（`GearFilterText`/`DisplayedGearRecipes`/`SelectedGearRecipe`/`GearEditSession` vs`AeonFilterText`/`DisplayedAeonRecipes`/`SelectedAeonRecipe`/`AeonEditSession`) 會被**隔離**在各自的 shell 中——不會相互干擾。`AutoSaveIndicator_Control` (Gear/Aeon) 以及`AtlasEvidenceBadgeStrip` (Aeon) 已保留。套用密度：ListBox 項目`Padding=12`→`10`,`Margin=0,0,0,10`→`6`, 來源`16`→`14`,`sectionLabel`/`muted` 贏得了`FontSize=11`. 贏了`rsp:Responsive.Breakpoints="True"` + 樣式`UserControl.narrow` 將這兩組主資料庫合併為`<760px`. **尚缺 E10-E12**（Shop/MixTable/KernelCommands）。發行版編譯 **0 個錯誤**（403 個既有警告）。[前一版：`v2.161.1.0`]
- **`v2.161.1.0` — 部分 E 階段（E1-E8）：`ModuleMasterDetail_Shell` 包含 8 個 Core Authoring（Jarvis-UI）模組。** Lane **Jarvis-UI**。**PATCH**（表面修整：版面配置遷移；無新增功能）。**E 階段**的前 8 個提交（`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §4)。 範圍：**僅視覺容器** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 保持原樣；DataContext/bindings/handlers/IRestorableModule 未作變更。**8 個模組已從手動編寫版本遷移**`Auto,*` /`2*,5*` 網格（邊界卡）`Padding=16` （膨脹 + ScrollViewer）對應標準殼層（可收合的 Expander，`Padding=8`, 密集型)：**E1 CtbBase**、**E2 PlayerGrowth**、**E3 Formation**（場地情境卡已改為 MasterHeader）、**E4 Treasure**（各類別專屬卡牌仍保留於 Detail 中）

), **E5 KeyItem** (`2*,5*` →`Auto,*`), **E6 AutoAbility**（保留了 8 張詳細資訊卡片）、**E7 BukiGetTreasureCatalog**（根目錄`Margin=18` 已移除 + 十六進位`#C9A227` →`WarningBrush`)，**E8 MonEditorSelector**（原本已有手動擴展功能——現已由 shell 取代；透過`ContentControl Name="ContentFrame"` 保留在「詳細資訊」插槽中）。每個模組都獲得了`rsp:Responsive.Breakpoints="True"` + 樣式`UserControl.narrow` 導致主節點在`<760px`. **尚缺 E9-E12**（Customization/Shop/MixTable/KernelCommands — 3 欄/矩陣佈局，風險較高）。發行版 **0 個錯誤**（403 個既有警告）。[先前：`v2.161.0.0`]
- **`v2.161.0.0` — D 階段 已完成：命令面板`Ctrl+K` (Jarvis-UI)。** Lane **Jarvis-UI**。**次要更新**（新產品功能：具備模糊搜尋功能的指令選單）。此提交**完成了整個 D 階段**的`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` (D1+D2+D3+D4 + 這個 D5)。範圍：**新的快速導覽介面** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 未受影響。**新`Modules/Main/CommandPalette_Popup.axaml(.cs)`**：自訂 UserControl（僅限容器，不支援處理常式），具備`TextBox` (佔位符 "搜尋模組…") +`ItemsControl` 與...進行資料綁定`ModuleRegistry.All` 篩選條件：`Title.Contains`/`Description.Contains`/`Id.Contains` (IgnoreCase)。每個結果都會顯示圖示（透過`IconKeyToGeometryConverter.ResolveGeometry`) + 標題 + 描述（2 行）。按下 Enter 鍵可開啟第一個結果（預設選取）；點擊某一行則會根據 ID 開啟該結果；按下 Esc 鍵關閉。**Wiring 在`Main_Window`:** 新增`<Popup Name="CommandPalette" PlacementMode="Center" IsLightDismissEnabled="True">` (XAML 中留空 — 內容在程式碼後端實例化，以避免額外的 XAML 命名空間)；`ToggleCommandPalette()` 載入實例，啟動`DispatchRequested`/`CloseRequested` (活動) 並呼叫`Reset()` 在開啟之前。`OnKeyDown` 贏得`if (ctrl && e.Key == Key.K) ToggleCommandPalette()`.`Palette_DispatchRequested(id)` 關閉彈出視窗 +`Dispatch(id)`. **操作說明：** 按下 Ctrl+K 打開中央調色板，輸入「save」→ 出現「Save Editor」選項，按下 Enter 即可開啟。**D 階段全部內容分 5 次提交** (`v2.160.1.0` →`v2.160.4.0` 修補程式 + 此次小更新)：

可透過以下方式在 **所有約 72 個控制項** 上恢復「上一頁／下一頁」功能：`IRestorableModule` (8 個編輯器 + 9 個具有明確狀態的樞紐；其餘透過預設介面方法以無狀態方式運作) + 41 個模組上的命令面板 Ctrl+K。建置發行版 **0 個錯誤**（403 個既有警告）。[先前：`v2.160.4.0`]
- **`v2.160.4.0` — D4 階段：`IRestorableModule` 透過預設介面方法（Jarvis-UI）處理所有其餘控制項。** Lane **Jarvis-UI**。**PATCH**。**D 階段** 的第四次提交（`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D4). 適用範圍：**在所有`*_Control` 其餘** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 保持原樣。`IRestorableModule.cs` 新增 **預設介面方法**：`CaptureState() => null` 以及`RestoreState(state) { }` （預設為無狀態／無操作）。因此，無實質狀態的控制項（唯讀探索器、樞紐、執行時實驗室、除錯、追蹤器、16 項附加功能、Wave-1、子控制項）只需宣告`, IRestorableModule` 在簽名處 — —`Main_Window` 現在可以做了`ContentFrame.Content is IRestorableModule` 在 **任何** 模組中，不分類型。透過 **自動掃描**`work/_irestable_stateless_sweep_20260620.ps1`: **65 項控制項已變更**（新增`using FFXProjectEditor.Modules.Common;` +`: UserControl, IRestorableModule`)，**9 個跳過**（其中 8 個已在 D1/D2/D3 中實作 +`MonsterAiEditor2_Control` 已停用）。**誠實而言：**這 3 款具備過濾功能的瀏覽器（MagicDllBrowser/RuntimeDllManager/Ps3MagicBrowser）之所以繼承了預設的「無狀態」模式，是因為它們的`FilterText` 它們存在於私有資料模型中，未在控制項中公開 — 篩選器的實際擷取功能則作為較小的待辦事項保留。透過 D1+D2+D3+D4，**所有約 72 個控制項** 現已宣告`IRestorableModule`；已參與的（8 位編輯者 + 9 個樞紐）會進行明確的覆寫，其餘則為無狀態。建置發布 **0 個錯誤**（402 個既有警告）。[先前：`v2.160.3.0`]
- **`v2.160.3.0` — D3 階段：`IRestorableModule` 在`SubTabHub_Control` （涵蓋 9 個樞紐）（Jarvis-UI）。** Lane **Jarvis-UI**。**PATCH**。**D 階段** 的第三次提交（`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D3). 適用範圍：**所有基座型集線器皆可恢復「上一頁／下一頁」功能**

在`SubTabHub`** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 保持原樣。`SubTabHub_Control.axaml.cs` 實施`IRestorableModule`: 新欄位`int _activeTabIndex` 追蹤至`SelectTab(index)`;`CaptureState()` 返回`{["activeTab"] = _activeTabIndex}`;`RestoreState(state)` 火焰`SelectTab(idx)` （通常會重新命名為 pill/active/hosted-content）。**9 個樞紐的自動支援：** BattleCommandsHub、ItemsHub、SphereGridHub、TextHub、EnemyDesignHub、CustomizationsHub、StatsHub、EncountersHub、Blitzball — 所有樞紐均使用`SubTabHub_Control` 來源`AddTab(...)`, 如此一來，所有使用者都能透過單一變更，免費獲得「活躍子分頁」的還原功能。**誠實聲明：** 每個子分頁的內部內容（託管編輯器的篩選器／選取範圍）應由託管控制項負責——若該控制項亦實作`IRestorableModule` （D2 已涵蓋 Treasure/KeyItem/等），該`Main_Window` 隨後執行 restore 指令。Build Release **0 個錯誤**（402 個既有警告）。[前一項：`v2.160.2.0`]
- **`v2.160.2.0` — D2 階段：`IRestorableModule` 在 7 個簡易編輯器（Jarvis-UI）中。** Lane **Jarvis-UI**。**PATCH**。**D 階段** 的第二個提交（`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D2). 範圍：**7 款 Core Authoring 編輯器中可還原的「後退/前進」功能** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 均未修改。實作`IRestorableModule` （定義於 D1）在 **7 個控制組** 中：`TreasureEditor_Control`,`AutoAbilityEditor_Control`,`PlayerGrowthEditor_Control`,`CtbBaseEditor_Control`,`KeyItemEditor_Control`,`FormationEditor_Control`,`BukiGetTreasureCatalog_Control`. 每個`CaptureState()` 擒獲`filterText` (字串) +`selectedIndex` (int? 源自集合中選取的項目`Displayed*`);`RestoreState(state)` 重新套用濾鏡（這會重新套用該`ApplyFilter` 來源`OnFilterTextChanged`) 並根據索引重新選取該列。**編輯器映射：** Treasure (`SelectedTreasure`/`DisplayedTreasures`), AutoAbility (`SelectedAbility`/`DisplayedAbilities`), PlayerGrowth (`SelectedCharacter`/`DisplayedCharacters`), CtbBase (`SelectedRow`/`DisplayedRows`), KeyItem (`SelectedItem`/`DisplayedItems`), 形成 (`SelectedBattle`/`Battles` — 不含 `Displayed*`

`), BukiGetTreasureCatalog (`SelectedRow`/`顯示的列數`). **Honestidade:** agora Monster Editor + os 7 editores acima são plenamente restorable via back/forward (voltam pra seleção/filtro exatos). KernelCommands + os hubs (BattleCommands/Items/etc.) viram em D3 (SubTabHub). Build Release **0 erros** (402 warnings preexistentes). [anterior: `v2.160.1.0`]
- **`v2.160.1.0` — D1 階段已完成：介面`IRestorableModule` + 重構`NavigationSnapshot` (Jarvis-UI)。** Lane **Jarvis-UI**。**PATCH**。**D 階段** 的第一個提交 (`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D1). 範圍：**導覽架構（可還原的「上一頁／下一頁」）** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE 均未修改。**新合約**`FFXProjectEditor/Modules/Common/IRestorableModule.cs`:`CaptureState()` →`Dictionary<string,object?>?` (null = 無狀態) 且`RestoreState(state)` （冪等、對 null 安全）。在 D1 之前，該`Main_Window` 對具體類型進行模式匹配（`MonEditorSelector_Control`/`KernelCommands_Control`) 用於擷取狀態——無法擴展至約 38 個模組。現在的`Main_Window` 詢問控制端是否為`IRestorableModule`. **重構`NavigationSnapshot`:** 轉為`record struct (string ModuleId, Dictionary<string,object?>? State)`; 該枚舉`NavigationSurfaceKind` 已**移除**。新增欄位`private string _currentModuleId = "home"` 設定於……之初`Dispatch(string moduleId)`.`CaptureCurrentNavigationSnapshot()` 透過一般管道`ContentFrame.Content is IRestorableModule`;`IsSameNavigationSurface()` 比較一下吧`ModuleId`;`RestoreNavigationSnapshot()` 做`Dispatch(snapshot.ModuleId)` +`restorable.RestoreState(snapshot.State)`. **已修正 3 處斷裂的呼叫**（仍引用了`NavigationSurfaceKind`):`MenuItem_MonsterMagic1/2` (L560/568) →`_currentModuleId = "battle-commands-hub"` +`new NavigationSnapshot("battle-commands-hub")` （與`MenuItem_Commands`/`MenuItem_Items` （已遷移）；`NavigateToMonsterEditor` (L1549) →`new NavigationSnapshot("monster-editor")`. **誠實聲明：**「上一頁／下一頁」功能在 3 個原始版本（Home／Monster／KernelCommands）中仍可正常運作，但 Monster／KernelCommands 僅能**完全**還原

當您的控制項實作時`IRestorableModule` (D2/D4)。在此之前，快照已建立，但`State` 來吧`null` （返回模組，不還原子選項）。建置發行版 **0 個錯誤**（402 個既有警告）。[上一頁：`v2.160.0.0`]
- **`v2.160.0.0` — A–C 階段：ModuleRegistry + Workspace Ready（§17）+ 無飛出選單的圖示欄（§16）（Jarvis-UI）。** Lane **Jarvis-UI**。**次要**。A–C 階段的交付`docs/specs/EDITOR_UI_OVERHAUL_PLAN.md` §16–§17（Halyson 2026年6月20日之裁決），依據`docs/ai/PROMPT_UI_GLM_REMAINING_BACKLOG_2026-06-20.md`. 範圍：**導覽架構 + 數據驅動型目錄 + 圖示系統** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE **未修改**；68 個處理常式`MenuItem_*` **未重構**（僅被呼叫）。**A 階段 — ModuleRegistry（單一來源）：**`ModuleCatalogPolicy.cs` 從文件存根演變為權威目錄 — 新增`public static class ModuleRegistry` 與`IReadOnlyList<ModuleCatalogEntry> All` 共填入 **41 項**（主頁 + 10 項核心撰寫 + 5 張地圖 + 7 項直播 + 16 項額外內容 + 2 項第一波內容），每個模組各一項，並依既定流程進行。`ModuleCatalogEntry` 贏得`Mode`/`Notes`/`Scope`/`Cluster` (enum`ModuleCluster`) 此外，`Id`/`Title`/`Description`/`IconKey`/`RequiresProject` 原文。各項文字內容的忠實複本`SetModule(...)` 在`Main_Window.axaml.cs` （未重新制定）。doc-comment 政策：新`MenuItem_*` 已路由 = 追加至登錄檔（**審查阻擋項**）。**A 階段 — 圖標設計：**`StudioIcons.axaml` 從 **14 → 54 個圖示** 擴充至（`<StreamGeometry>` 類似 Lucide 的風格，視口 24×24）—— 每個模組專屬一個隱喻（劍＋犄角＝怪物、軟碟＝存檔、骷髏＝敵人設計、六邊形網格＝球體網格等）。 一致性檢查（腳本）確認所有 41 個`IconKey`登錄檔中的 s 解析為`StudioIcons`. **B 階段 — §17 Workspace Ready：**`MainDashboard_Control.axaml` 不再有 6 個硬編碼的磁磚，而是變成`ItemsControl ItemsSource="{Binding Modules}"` 與`DataTemplate` （圖示 + 標題 + 完整說明 + 模式標籤）。`Main_DataModel` 贏得`public IReadOnlyList<ModuleCatalogEntry> Modules => ModuleRegistry.All`. 兩台全新的轉換器在`FFXProjectEditor/Converters/`: `IconKeyToGeo

ometryConverter` (resolve string IconKey → Geometry percorrendo `資源` + `合併字典` via `TryGetResource(key, ActualThemeVariant, out _)` — necessário porque binding `{DynamicResource {Binding IconKey}}` não funciona para `PathIcon.Data` em Avalonia) e `需要已啟用的專案轉換器` (`IMultiValueConverter` RequiresProject × IsProjectLoaded → `IsEnabled`). Hero + empty-state CTA + card de Workspace status preservados (§17.4). **Fase C — §16 Icon Rail sem flyouts:** removidos os 5 `Button.Flyout`/`下拉式選單` do `IconRailCol` (XAML L156–239) — substituídos por `<StackPanel Name="RailStack">` populado em code-behind por `BuildIconRail()` (1 botão `railIcon` por entry, agrupado por cluster com `邊界` 1px como separador). `Popup#RailDrawer` (narrow) troca a lista textual de `按鈕 Classes="nav"` por `<WrapPanel Name="RailDrawerGrid">` (grid de ícones). Handler único `Button_RailModule_Click(sender, e)` lê `標籤=ID` → `Dispatch(id)`. `RefreshRailProjectGates()` re-aplica o gate `RequiresProject` quando `Project_Service.IsProjectLoaded` muda. **Fase C — Dispatch genérico:** `OnQuickLaunchRequested` (6 keys hardcoded: monster/kernel/sphere/save/extras/home) substituído por `Dispatch(string moduleId)` com switch de **todos os 41 Ids** → handler `MenuItem_*` existente. Rail, drawer e dashboard passam pelo mesmo caminho. **Aceite:** build Release **0 erros** (402 warnings preexistentes); 0 `下拉式選單` no `IconRailCol`; 0 tile hardcoded no dashboard; 41 ícones renderizando no rail + 41 cards no home com ícone dedicado + descrição completa; cards desabilitados quando `RequiresProject && !IsProjectLoaded`. **Bug visual corrigido:** os ícones não renderizavam inicialmente porque `Application.Current.Resources.TryGetValue()` em Avalonia 11 não percorre `合併字典` — fix via `ResolveGeometry()` helper compartilhado que itera os merged dicts com `TryGetResource`. [anterior: `v2.159.6.1`]
- **`v2.159.6.1` — 啟動修復：ModuleMasterDetail_Shell（Jarvis-UI）的 P1-7 半徑/運動標記 + 綁定。** 車道 **Jarvis-UI**。**PATCH**。後續熱修復`v2.159.6.0`. **StudioTheme：** 參考資料 P1-7 (`RadiusLg/Md/Sm`,`DurationNormal/Fast`) 會使用 `{StaticResource ...

}` mas os tokens estão em `Application.Resources` (`StudioTokens.axaml`) **depois** do `StyleInclude` do tema → `KeyNotFoundException：找不到靜態資源「RadiusLg」` no boot (processo morria sem janela). Fix: `{DynamicResource ...}`. **ModuleMasterDetail_Shell:** `MasterHeader`/`MasterList`/`詳細資訊`/`MasterHeaderLabel`/`IsMasterExpanded` agora usam `RelativeSource AncestorType=ModuleMasterDetail_Shell` (antes bindavam o DataModel do módulo → lista/botões/detail vazios no Magic DLL Browser e Runtime DLL Manager). Escopo: UI container only — writers/save/hooks intocados. Build Release **0 erros**. [anterior: `v2.159.6.0`]
- **`v2.159.6.0` — 前端 P0/P1 視覺優化：heroGradient sweep + MonsterAi 十六進位代碼 + 窄版抽屜式選單 + P1-7 設計代碼（Jarvis-UI）。** Lane **Jarvis-UI**。**PATCH**。執行 P0/P1 的待辦事項清單`docs/ai/FRONTEND_AUDIT_P0_P1_2026-06-19.md` 依據已核准的計畫。範圍：**UI / 設計系統的修飾** — writers/save bytes/hooks/FfxLib/RT0/RT2 **未修改**；`MonsterAiEditor2_*` (已停用) **未修改**。**P0-1 (heroGradient sweep)：** 25 個檔案中共有 26 個內嵌漸變`Modules/` 已遷移 — 18 位教士 (`#163245/#0F1821/#214F69`) 看到`Classes="heroGradient"`; 8 種身分保留變體，作為新的命名標記（`heroPurple`/`heroGreen`/`heroBrown`/`heroTeal`/`heroBlue` 在`StudioTheme.axaml` +`Color` 代幣`HeroXxxA/B/CColor` 在`StudioTokens.axaml`) — Aurora 維持紫色，AutoAbility/Formation/Customization 維持綠色，KeyItem 維持棕色，AlBhed/CtbBase/PlayerGrowth 維持青綠色，MixTable 維持藍色。`Main_Window.axaml` 頁首（色盤`PanelDeepColor` （原始）內容已刻意保留。**P0-2 (MonsterAi hex → tokens)：** 已遷移的 MonsterAiEditor 叢集中的 4 個「活躍」檔案 — **261 個十六進位常量**（Background/BorderBrush/Foreground）已壓縮為`{DynamicResource ...}` 按系列（Shell/Protect/Regen/Gold/Forbidden/Cycle + Panel/Stroke）分類，並將系列內的色偏進行標準化（約 20 個青綠色填充變為 1）`AccentShellFillBrush`). 已建立 **14`AccentXxxForegroundBrush`** 新增（原先僅限 Gold 會員）+ **家庭`Border.accentXxx`** (15 種樣式 + 選擇器`> TextBlock`) 在`StudioTheme`, 與 `Button.accen` 平行

tXxx` existente. `MonsterAiEditor2_Control.axaml` retém seus 71 hex (discontinued). **P0-4 (drawer narrow):** o bug onde em `Window.narrow` o botão "≡" e `Ctrl+B` não faziam nada visível (estilo `Window.narrow Border#IconRailCol → IsVisible=False` vencia o toggle) foi resolvido — novo `<Popup Name="RailDrawer">` flutuante em `Main_Window.axaml` com os 6 grupos de navegação como botões de texto verticais (mais escaneáveis que ícones 22px em tela pequena), `IsLightDismissEnabled=True`; `ToggleIconRail()` agora branch narrow→Popup / wide→Border. Reusa os MESMOS `MenuItem_*` handlers (zero mudança em handlers). **P1-7 (design tokens estruturais):** novas famílias em `StudioTokens.axaml` — **Spacing** (`字距Xs/Sm/Md/Lg/Xl` Thickness + `StackGapSm/Md/Lg` doubles), **Radius** (`RadiusSm=8/Md=10/Lg=12/Pill=999` CornerRadius), **Motion** (`速度：快速／正常／慢速` `sys:TimeSpan`), **Elevation** (`Border.elevation1/2/3` BoxShadow). Adoção piloto: `StudioTheme.axaml` consome `RadiusLg/Md/Sm` em `Border.card`/`cardSoft`/`Button.primaryAction`/`secondaryAction`/`railIcon`/`tabPill`, e `常規/快速處理時間` nas 3 transições de microinteração (antes literais `0:0:0.12`/`0:0:0.10`); `MonsterAiEditor_Control.axaml` demonstra `SpacingLg/Md` + combo `卡片裝飾殼` em 4 cards piloto. **Divergências do audit registradas:** P0-3 (Ctrl+B) já estava implementado na working tree (não era mais "comentário mentiroso"); P1-8 (shell) já tinha 2 consumidores; P1-5/P1-6 (arquitetura nav) fora do escopo por alto merge-risk. Build Release **0 erros** (401 warnings preexistentes, nenhum novo). Artefatos de sweep: `work/_hero_gradient_sweep_20260620.ps1`, `work/_monster_ai_hex_sweep_20260620.ps1`. [anterior: `v2.159.5.0`]
- **`v2.159.5.0` — UI 可選功能總覽：透過單一 PATCH 結案 28 項可選功能待辦事項（Jarvis-UI）。** 專案線 **Jarvis-UI**。 **PATCH**。完整執行`docs/ai/PROMPT_UI_OPTIONALS_MASTER_2026-06-20.md` 第 5 節 — 所有 28 個待處理的 ID 均已實作（OPT-F2 已在`v2.159.4.0`, 未重新編譯）。範圍：UI 優化 **僅限容器**（代碼片段、響應式設計、無障礙性、空狀態、藥丸式按鈕、表情符號）—— writers/save bytes/hooks/FfxLib/RT0/RT2 **未修改**。**Spri

nt B（可重複使用的 SubTabHub）：** OPT-B1/B2 —`AutomationProperties.Name` 所有按鈕上`tabPill` 產生於`AddTab()`，與`tabA11yName` 可選（預設值取自標籤：「X 標籤」）；OPT-B3 —`BlitzballSubTabHubFactory.Create()` 靜態分析提取了由 5 個分頁組成的結構，該結構來自`MenuItem_Blitzball` (≤5 行)；OPT-B4 — 佔位符的副本`requiresProject` 現在可透過集線器進行設定（`RequiresProjectMessage`)，保留舊版 PT 預設值。**Sprint F（Magic DLL Browser 殘留）：** OPT-F1 — 標頭卡`heroGradient`; OPT-F3 — 位於 **2 行固定位置** 的動作按鈕（Open/View \| Author/Patch，先前為單一 WrapPanel）；OPT-F4 —`IsMasterExpanded` 已儲存至資料模型（Shell 中啟用 TwoWay）；OPT-F5 — 詳細資訊的英雄`heroGradient`; OPT-F6 — 主節點為空`!HasDllList` 依標準`Border#EmptyState` (圖示 + 複製，與「詳細資訊為空」對應)；OPT-F7 —`StatusSeverity` (無/資訊/警告/危險) 源自`StatusText` + 新增`StatusSeverityBrushConverter` 顯示錯誤／警告訊息於`DangerBrush`/`WarningBrush`; OPT-F8 —`AutomationProperties.Name` 在「搜尋」文字方塊中；OPT-F9 — 選項按鈕`WRITER LAB · native magicFiles DLL · RT2 pending` 在頁首。**Sprint A + C（儲存編輯器）：** OPT-A1 — 響應式設計（頁首轉為垂直 StackPanel，操作按鈕在窄區域中堆疊）；OPT-A2 — 頁首`heroGradient`; OPT-A3 — 藥丸`READ-ONLY · FFXED port · RT2 via CLI` 在標頭中；OPT-A4 — 點擊後複製完整的 SHA256 雜湊值（透過剪貼簿`TopLevel.Clipboard`, 新的`IconCopy`); OPT-C1 —`StatusSeverity` 在`StatusSummary` （重複使用轉換器）；OPT-C2–C5 —「字元／裝備／道具／閃電球」子分頁的主清單位於`Expander` 可折疊的 (`ExpandDirection="Left"`, 預設展開)。**Sprint A5/A6/D (Sphere Grid + Blitzball)：** OPT-A5 — 表情符號`🏐` 已從`SetModule` 《閃電球》的標題以及`sectionLabel` 名單中的球員；OPT-A6 —`♻️ Restaurar` →「還原原始狀態」，`✕` 在連結中 → 「移除」 + a11y；OPT-D1 — v1 響應式表單（3 欄網格 →`WrapPanel` （堆疊於 narrow）；OPT-D2 —`ActiveToolMode` DataModel 中的枚舉 + 視圖類別`toolActive` 在「模式」按鈕處（透過`PropertyChanged` （在程式碼後端中）；OPT-D3 —`AutomationProperties.Name` 在「載入／儲存／驗證」的 CTA 中。**Sprint E（執行時

殘留 eDll)：** OPT-E2 — 橫幅上的「Refresh」按鈕`IsGameClosed`; OPT-E3 — C# 切換按鈕的十六進位值 (`ToggleBrush`/`ToggleBorderBrush`/`ToggleForeground`/`ToggleGlow`/`RuntimeBrush`) 轉為代幣`RuntimeToggle*`/`RuntimeRuntime*` 在`StudioTokens` (透過以下方式解決：`Resources.TryGetValue`, 模組中無十六進位數）；OPT-E1 — **跳過**（toggle DLL 透過`File.Move`/`File.Copy`，沒有任何可察覺的異步操作超過 300 毫秒 — 詳見第 7 節）。Release 版本 **0 個錯誤**（401 個既有警告，修改過的檔案中無警告）；零`#RRGGBB` 新字句在`.axaml` 播放過的。[上一頁：`v2.159.4.0`]
- **`v2.159.4.0` — Magic DLL Browser：9 個十六進位值 → 標記 + ModuleMasterDetail_Shell（第 2 個使用者）+ 空狀態 + 響應式設計 + 無障礙功能。** Lane **Jarvis-UI**。**PATCH**。 持續對 **Magic DLL Browser** 進行模組逐一的 UI 審計（`Modules/Extras/`)，根據`docs/ai/PROMPT_UI_MAGICDLLBROWSER_2026-06-20.md`. (P0) 那11位`#RRGGBB` Chrome（Wave4 編輯指引）`#E8A040`, Value Workbench 產品系列警告`#E8A040`，以及那 3 枚 RT2 內嵌徽章 — 已失效`#3B1A1A`/`#E85050`/`#F0A0A0`, 提供`#3B2719`/`#E8A040`/`#F0C070`, 風險`#2A2A1A`/`#C0A040`/`#E8D080`) 從現有的代幣／類別中提取`StudioTheme`:`WarningBrush` 在指引／家庭警示文字中；徽章 **rt2-dead** →`Classes="pillDanger"`; 徽章 **rt2-timing 已驗證** →`Classes="pillWriter"`; 標籤 **rt2-timing RISK** → 背景`PanelAltBrush` +`WarningBrush` (邊框/前景)。 (P1) **第二位使用者** 來自`ModuleMasterDetail_Shell` (第 1 項 = RuntimeDllManager)：主體`ColumnDefinitions="330,*"` 手捲將外殼翻轉為`MasterHeaderLabel="Magic DLLs"` — master = 來源根目錄摘要 + 搜尋 + 清單方塊`magic_*.dll`; 詳細資訊 = 動作英雄 + Wave4 歸屬 + 直接補丁生成器 + 高密度標籤控制項（區段／匯出／匯入／音效（SeSep）／疊加槽／角色候選名單／家族比較器／邏輯反編譯／字串／警告）。`MinWidth` master ~260 來自 shell。（P2）`Border#EmptyState` 在細節上，當……時`!HasSelectedDll` （標題 *「未選取 DLL」* + 副標題，指引使用者選擇 DLL / 設定`magicFiles\FFX` root）；當主分支處於空狀態時`!HasDllList` (新計算出的標記`Dlls.Count > 0`, 通知

位於`ApplyFilter` 以涵蓋「Refresh」和「Search」）；`rsp:Responsive.Breakpoints` 非根目錄 + 樣式`UserControl.narrow` 當寬度小於 760px 時，主面板會收起（動作的 WrapPanel 不會裁切「萃取」/「重新打包」等關鍵按鈕）。(P3)`AutomationProperties.Name` 在「detail」介面的約 16 個操作按鈕中（開啟 DLL／解壓縮／邏輯反編譯／重新打包／修補計畫／C／ASM 專案／語義 RE 報告／Magic 檢視器／Phyre 套件 I/O/複製/套用位元組修補程式/套用 ASCII 修補程式/預備+套用值修補程式/預備+套用主機偏移修補程式/部署 ps3data 複製本/開啟 PS3 Magic 及資料夾）。標頭卡維持為`card` 一般（決定：`heroGradient` 若出現在次要上下文的標頭中會造成負擔——當選取了 DLL 時，真正的英雄會出現在檢視窗格中）。**適用範圍：** PE 覆蓋、Direct Patch Builder、Value Workbench、邏輯反編譯、`MagicDllBrowser_DataModel` 反編譯／重新打包／修補邏輯與事件`OpenPs3MagicRequested`/`OpenMagicViewerRequested` + 接線編號`Main_Window` 完全未經修改——僅視覺容器有所變更（1 項僅限 UI 的屬性）`HasDllList` 已新增）。建置版本 **0 個錯誤**（401 個既有警告）；零`#RRGGBB` 字面意思是`.axaml` 該模組。[上一頁：`v2.159.3.0`]
- **`v2.159.3.0` — 儲存編輯器樞紐第二階段：晶片篡改 + SHA256 有效載荷 + 會話保護。** Lane **Jarvis-UI**。**PATCH**。持續對 **儲存編輯器樞紐** 進行模組化的 UI 審計（`Modules/SaveEditor/`)，根據`docs/ai/PROMPT_UI_SAVEEDITOR_HUB_PHASE2_2026-06-20.md`. (P0) 在標頭卡中使用類別時出現 **未儲存的變更** 提示`autosaveChip`/`autosaveOrb`/`autosaveLabel` 現有的`StudioTheme`，連結至`IsDirty` — 當使用者編輯「角色／吉爾／裝備／等」時會出現，並在「儲存／另存新檔」後消失（資料模型此時已重置為零）`IsDirty`). (P1) 短版 **SHA256 有效載荷**（前 12 個字元 + "…"）透過`FfxSaveHash.Sha256Hex(session.Core.Data)` 位於頁首，附有顯示完整雜湊值（64 個字元）的工具提示；於載入／儲存／MC 切換時重新計算 — **不會**於`TouchDirty` (hash = 記憶體中 blob 的指紋；在執行 Apply+mutate 之前，dirty ≠ hash 變更)。新屬性`PayloadHashShort`/`PayloadHashFull` 與方法`RefreshPayloadHash()` 在 DataModel 中。(P2) **替換會話前的確認**：nov

該輔助程式`AvaloniaDialog_Util.ConfirmYesNoAsync` （是／否模式，無新增資產）會在 Load 之前（工具列 + 空狀態 CTA）以及在切換 MC 插槽之前被呼叫，當`IsDirty`; MC 插槽組合不再直接使用 TwoWay 綁定，而是改為透過`SelectionChanged` 搭配確認守護程式 + 手動同步組合↔DataModel。**範圍符合：** FFXED 子分頁、偏移量、`FfxSaveFile` 寫入程式、批次標籤與命令列介面`--ffx-save-rt2` 完全未作修改——僅有 hub shell 和 DataModel 新增了屬性。建置版本 **0 個錯誤**。[上一版：`v2.159.2.0`]
- **`v2.159.2.0` — Blitzball Hub：將重複的 shell 遷移至`SubTabHub` 可重複使用。** Lane **Jarvis-UI**。**PATCH**。該`BlitzballHub_Control` (`Modules/BlitzballHub/`) 完全複製了該`SubTabHub_Control` 已經——子標籤區塊`tabPill`,`tabPillActive`, 懶加載 + 按分頁快取、Writer/Read-only 模式、音訊`PlayAlternative()` 點擊後。該`MenuItem_Blitzball` 現在來建立一個`SubTabHub_Control` 與`AddTab` 針對 5 個分頁（4 個 Writer + 1 個 Prize Atlas 唯讀）進行流暢化處理，並採用相同的 pill 文字以及`requiresProject: false` 在所有情況下（4 個文字編輯器均保留各自專屬的「空白」狀態；Atlas 則在無專案狀態下開啟）。該`BlitzballHub_Control` (`.axaml` +`.axaml.cs`) 被 **刪除** —`grep` 找不到`new BlitzballHub_Control()` 正在生產中。**範圍已符合要求：**`FfxLib/Blitzball/*`, RT0/RT2,`ByteSnapshotEditorSession` 而這 5 個子編輯器的內部內容完全未經修改——僅有視覺容器有所變更。這將成為未來遷移的範本，用於`SaveEditorHub` （7 個硬編碼的分頁標籤）。發行版建置 **0 個錯誤**（401 個既有警告）。[先前：`v2.159.1.0`]
- **`v2.159.1.0` — 執行時 DLL 管理員：ModuleMasterDetail_Shell 原型 + heroGradient + 響應式設計 + 離線／分離狀態橫幅 + 空狀態 + 無障礙 (a11y)。** Lane **Jarvis-UI**。**PATCH**。 持續對 **Runtime DLL Manager** 進行模組逐一的 UI 審核（`Modules/RuntimeDllManager/`)，根據`PROMPT_UI_RUNTIMEDLL_2026-06-20.md`. (P0) 內嵌英雄`#183444/#111C24/#3B4B2D` →`Classes="heroGradient"`; Chrome 的十六進位碼`#20303B` 已從`.axaml` (使用`RailHoverBrush`/`PanelStrokeBrush`). (P1) **第1個被消耗的

r** 來自該儲存庫的`ModuleMasterDetail_Shell`: 主資料 = 3 張狀態卡（Game root / FFX open / Hooks）；詳細資料 = 英雄 + DLL 清單。（P1）`rsp:Responsive.Breakpoints` + 樣式`UserControl.narrow` 收起主選單。（P2）橫幅廣告`WarningBrush`/`DangerBrush` 當……時`IsGameClosed` （遊戲已關閉 — 切換鍵僅會發動「磁碟」技能）以及`IsRuntimeDetached` （未使用探針／掛鉤開啟 FFX — 即時狀態不可靠）。空狀態`Border#EmptyState` 當……時`!GameRootReady`. (P3)`AutomationProperties.Name` 在狀態核取方塊和動作按鈕中；`ToggleA11yName` 按項目。**範圍符合要求：**部署／切換／DLL／掛鉤／探測的邏輯均未更動——僅視覺化容器。[先前：`v2.159.0.0`]
- **`v2.159.0.0` — Save Editor 的「角色」分頁：與 FFXED 保持一致（技能、隊伍、OD 模式、超驅動）。** Lane **Jarvis-UI**。**次要更新**。「角色」分頁不再僅限於屬性與批次處理按鈕：新增`SaveEditor_CharacterBindings` +`FfxSaveCharacterFieldCatalog` 模擬 FFXED v0.749 介面 — 連段、啟動／超驅動模式、隊伍（7 個槽位 @15768）、 約 95 種能力（位元陣列 @22090），20 種附帶計數器的超驅動模式、超驅動技能與特殊能力，以及球體等級／超驅動計量表（最大值為 22088／22086）。`FfxSaveCore.ReadSaveBit/WriteSaveBit` 修正大於 7 的位元（語義 FFXED）`offset + bit/8`). 介面已重新規劃為 3 欄布局，與 FFXED 相同。Build Release **0 個錯誤**。[先前：`v2.158.2.0`]
- **`v2.158.2.0` — Sphere Grid Builder：六邊形 → 標記 + 側邊面板的空白狀態 + 垂直排列的工具列。** Lane **Jarvis-UI**。**PATCH**。繼續對 **Sphere Grid Builder** 進行模組化的 UI 審核（`Modules/SphereGridBuilder/`, v1 form + v2 canvas)，依據`PROMPT_UI_SPHEREGRID_BUILDER_2026-06-20.md`. (P0) UI 中 Chrome 的十六進位字面量會轉換為代號：`#C9A227` (警告文字) →`{DynamicResource WarningBrush}` 在`TopologySafetySummary`,`StatusSummary` 以及`SaveSummary` (v1);`#F23A3A` (即時風險) →`{DynamicResource DangerBrush}` 在`LiveRiskWarning`;`#22FFFFFF`/`#33FFFFFF` (分隔符) →`{DynamicResource PanelStrokeBrush}` +`Opacity="0.4"`. (P1) 畫布的側邊面板變成一個`Border#EmptyState` （此樣式已存在於`StudioTheme`) 標題為 *「未選取任何節點」*，並附有說明「選取」模式的副標題 +

`ModeLabel` 當……時`!HasSelection`；現有的編輯區塊會切換為`IsEnabled` 由`IsVisible="{Binding HasSelection}"`. (P1) 過於擁擠的工具列（單一 WrapPanel 包含約 20 個控制項）已重新整理為 3 行固定佈局 — **開啟** / **模式** / **驗證·儲存** — 且未移除任何按鈕，亦未修改處理常式。 **符合範圍：**`SphereGridLayoutBuilder`, 儲存位元組、Square/TrueNewNode 邏輯以及渲染顏色在`SphereGridCanvasView.cs` 完全未經修改——僅視覺化容器有所變更。建置版本 **0 個錯誤**；零`#RRGGBB` 字面意思是`.axaml` 模組內容（不包括註解）。[上一頁：`v2.158.1.0`]
- **`v2.158.1.0` — 儲存編輯器：空狀態 + 可收合的導覽欄 + 活躍分頁。** Lane **Jarvis-UI**。**PATCH**。持續進行模組式的 UI 審核，目前正在審查 **儲存編輯器**（FFXED 移植版）。(P0) 當`HasSession == false`，該`TabHost` 被一個`Border#EmptyState` （此樣式已存在於`StudioTheme`) 附有圖示，標題為 *"No save loaded"*，副標題列出支援的格式（.psu / 25848 位元組 / .ffx PC / .ps2 MC），並設有指向同一處理程式的首要 CTA **Load…**`Button_Load` — 傾向採用反向綁定（`IsVisible="{Binding !HasSession}"`) 關於程式碼後端（code-behind）的邏輯。（P1-A）現在點擊「裝備／物品／閃電球／球格／迷你遊戲／其他」會標記該按鈕為活躍狀態：已移除`tabPillActive` 靜態內容原本只存在於「角色」中，而且`SelectTab(int)` 將該類別套用至／清除於 7 個按鈕上（與`SubTabHub_Control`). (P1-B) 寬度約為 220px 的固定式側邊導覽欄會變成一個`Expander` 可向左折疊 (`ExpandDirection="Left"`, 已儲存的狀態位於`IsSectionsExpanded` 在 DataModel 中，預設為展開狀態）——此標準已在`MonsterAiEditor` 在翻新工程的第 4 層。（輕度 P3）`AutomationProperties.Name` 工具列上的「載入／儲存／另存新檔／FFXED」按鈕。**範圍符合：** FFXED 邏輯／`FfxSaveFile` / 批次標籤 / MC 多槽位 / 儲存格式 / CLI`--ffx-save-rt2` 完全未經修改——僅有樞紐的視覺容器有所變更。建置發布 **0 個錯誤**。[先前：`v2.158.0.0`]
- **`v2.158.0.0` — UI 審核後續處理：重音符號、儀表板快速啟動及全域快捷鍵。** Lane **Jarvis-UI**。**輕微**。預計耗時約 100 小時

前文所述的`MonsterAiEditor` 用於代幣`Accent*Fill/BorderBrush` + 風格`Button.accent*` 在`StudioTokens`/`StudioTheme`. 以數據為導向的儀表板首頁 (`MainDashboard_Control`): 具備工作區狀態的 hero、響應式快速啟動網格及事件`QuickLaunchRequested` 路由至`Main_Window`. 該應用程式的首批全球快捷方式：`Ctrl+B` (切換 IconRail)，`Alt+Left`/`Alt+Right` (上一頁/下一頁)。簡潔的頁尾／狀態列及側邊欄選單（已移除表情符號；`PathIcon` （在工作區的徽章上）。[上一頁：`v2.157.0.0`]
- **`v2.157.0.0` — SGM 原生節點：讀取／寫入儲存檔中的第 861 個節點 + 偏移量驗證器 + RE 第 3 場。** Lane **Jarvis-MAGIC-SGM Native**。**MINOR**。RE 驗證（第 3 場，`FFX_SPHEREGRID_SAVE_ORCHESTRATOR_RE_2026-06-19.md`) 強調說`A5BB70`/`A49590` 是基於 NodeCount 的（未對 860 進行限制），且節點 860 落在`state[1720/1721]` = **save+10404/10405**（至索引 1279 為止為空閒區段），透過批量操作原生保留`memcpy` — **無側車**，可額外獲得 1 個節點。新庫`FfxSaveSphereGridRuntimeTable` (原生地圖`save+8684+2*idx`, 偏移量分類) + CLI`--spheregrid-extra-node-rt0` (節點 860 的往返傳輸，包含 SG 區域的位元組標識) 以及`--spheregrid-save-diff` （遊戲內實證偏移量測試工具）。`SphereGridFullGridCompilerHook v1.2` 在……中新增唯讀繞道`A45570` 那個標誌`menu+2/+4` (NodeCount/LinkCount) 載入後 + 記錄 858..862 (FFFF=ghost)，正在排查網格為空的原因（asset Square / magic check）以及 L3 閘道位於`A49590`. Gates SGM-RT0-08/09 通過（9/9 對照表）。遊戲內渲染（進入／退出）及原生 RT2 往返處理仍處於 **待定 Halyson** 狀態。[先前：`v2.156.2.0`]
- **`v2.156.2.0` — SGM RT2 復原：啟動器／掛鉤強化 + RT2-03 FAIL 可偽造。** Lane **Jarvis-MAGIC-SGM-RT2**。**PATCH**。`sgm_rt2_launch.ps1` 現在將 vanilla 與 Square identity 分開，並根據環境變數清除 TrueNewNode`0`, 驗證覆蓋層的雜湊值，並匯出`FFXHOOKS_SG_ASSET_NODES/LINKS`，將 Square 疊加層移至 vanilla observe，並為 RT2-03b 建立經過驗證的 sidecar seed。`SphereGridFullGridCompilerHook` 採用按封包／貨運清單／輔助封包計算的可靠計數方式，並在`A53DE0`/`A54860` 當……時`WRITE=1`，並登入`live/trusted/sidecar/effective`. RT2-02 vanil

觀察到 **PASS**；RT2-03 Square 861 仍顯示 **FAIL**（網格為空／L3），即使`node=860 00/00 -> 09/00` + 已登入修補程式選單；RT2-04 已鎖定。[先前：`v2.156.1.1`]
- **`v2.156.1.1` — SGM 提示審計：A-E 通道標記為「已取代」+ 當前 RT2 提示。** 通道 **Jarvis-MAGIC**。**修訂版**。該套件`PARALLEL_LANES_SGM_MASTER` 以及提示字元`PROMPT_SGM_LANE_A/B/C/D/E_*` 現在已加上 **已取代** 的橫幅，以免再次被貼上；新版`PROMPT_SGM_CURRENT_RT2_PROOF_2026-06-19.md` 這已成為目前唯一可偽造 RT2 測試的腳本。無需變更執行時程式碼。[先前：`v2.156.1.0`]
- **`v2.156.1.0` — SGM 審計 + 全網格編譯器 sidecar 寫入器強化。** Lane **Jarvis-MAGIC**。**PATCH**。新文件`FFX_SPHEREGRID_SAVE_MIGRATION_AUDIT_AND_NEXT_ACTIONS_2026-06-19.md`; RT2 操作手冊僅指向`scripts/sgm/*`; 腳本`scripts/sgm` 它們是透過絕對路徑運作的；`SphereGridFullGridCompilerHook` 現在請填寫`profile_key` + 雜湊值`save/layout/contents` 在寫入 sidecar 之前先透過 env 傳送，並拒絕未提供完整身分識別的寫入請求，以避免在首次 RT2-04 中出現無效的 JSON。狀態仍為 **offline-valid / lab-rt2**；遊戲內的 RT2 尚待處理。[先前：`v2.156.0.0`]
- **`v2.156.0.0` — SGM Lane E 完整版（離線 RT0/RT2 線束）。** Lane **Jarvis-MAGIC-SGM-E**。**次要**。版本化腳本`scripts/sgm/*` (RT0 7/7、RT2 啟動、操作員、固定裝置初始化)；CLI`--sgm-fixtures-bootstrap`; 離線判定 + 車道狀態文件;`work/sgm_*.ps1` 已看到外殼。RT0 **離線驗證**；RT2 遊戲內 **待 Halyson 處理**（RT2-06/08 遭封鎖）。[先前：`v2.155.0.3`]
- **`v2.155.0.3` — Sphere Grid 儲存協調器 RE 第 2 場（A 通道）。** 通道 **Jarvis-MAGIC-SGM-A**。**修訂版**。 封存資料→執行時 @ 8748/11308（批量別名模型，無載入器）；地圖透過以下方式寫入空隙：`A5BB70`; 反編譯 load/write 協調器的區塊；駁斥 A47210 覆蓋層。[前一則：`v2.155.0.2`]
- **`v2.155.0.2` — 球形網格存檔格式破壞實驗 第 1 階段（決策文件，D 路線）。** 路線 **Jarvis-MAGIC-SGM-D**。**修訂版**。文件`FFX_SPHEREGRID_SAVE_FORMAT_BREAK_LAB_STATUS_2026-06-19.md`: 下游偏移量 10467 的矩陣，裁決結果：選項 A **放棄**、B **延後**（車道 A 間隙）、C **放棄**

**；淘汰標準 + 設計實驗室切換器 第二階段已啟動。零程式碼 — 標準編輯器，位元組完全一致。產品 = sidecar + hook。[前一則：`v2.155.0.1`]
- **`v2.155.0.1` — 《Sphere Grid》存檔協調器 IDA RE（A 通道部分）。** 通道 **Jarvis-MAGIC-SGM-A**。**修訂版**。文件`FFX_SPHEREGRID_SAVE_ORCHESTRATOR_RE_2026-06-19.md`: 證明`A5BB70` 僅寫入執行時表（非儲存緩衝區）、編排器的批次 I/O 映射、A/B 間隙假設、IDA 重命名佇列。追加至`FFX_SPHEREGRID_SAVE_MIGRATION_GAPS_AND_PIPELINE`. [上一頁：`v2.155.0.0`]
- **`v2.155.0.0` — Sphere Grid 全網格編譯器掛鉤（實驗室 DLL，預設為唯讀）。** Lane **Jarvis-MAGIC-SGM-C**。**次要**。新增`SphereGridFullGridCompilerHook` 在`FfxHooksDll` — 5 處繞道（`A53DE0`/`A47210`/`A49590`/`A5BB70`/`A54860`), 極簡 JSON 解析器 sidecar、split 持久化存根、環境變數`FFXHOOKS_ENABLE_SG_FULL_GRID_COMPILER=1` (預設為關閉)。Doc`FFX_SPHEREGRID_FULL_GRID_COMPILER_HOOK_IMPL_2026-06-19.md`. **lab-rt2** — 未通過 RT2。[上一項：`v2.154.0.0`]
- **`v2.154.0.0` — Sphere Grid 存檔遷移：sidecar C# 讀寫函式庫 + RT0 CLI。** Lane **Jarvis-MAGIC-SGM-B**。**次要更新**。新函式庫`FfxSaveSphereGridExtraStateSidecar` +`FfxSaveSphereGridExtraStateSidecarIO` (原子式載入／儲存、驗證、`Matches`,`BuildEmptyFromAnalyzer`, 合併輔助程式); CLI`--spheregrid-sidecar-validate/create/info`; 範例`work/_samples/sgm/sidecar_v1_minimal.json`; 路徑約定`mods/Spira Reforge/save-sidecars/<profile>/<prefix>.sphere-grid-extra.json`. Gates SGM-RT0-05/06 離線。[上一則：`v2.153.0.0`]
- **`v2.153.0.0` — Sphere Grid 存檔遷移：分析器 + sidecar 架構 + 全網格編譯器規格。** Lane **Jarvis-MAGIC**。**次要**。新的唯讀 CLI`--spheregrid-save-migration-analyze <save> <dat0X> <dat1X> [--json]` 比較 FFXED 的 25,848 位元組與 Square 的資產，並彙報容量／差異／政策；資料結構`sphere-grid-extra-state.schema.json` 為節點/鏈路 860+ 定義 sidecar 持久性；文件完成缺口地圖、全網格編譯器掛鉤規格、儲存格式中斷實驗室以及 RT0/RT2 矩陣。[前文：`v2.152.1.0`]
- **`v2.152.1.0` — 任務獎勵檢查器 FROZEN：已從編輯器中移除使用者介面。** Lane **Jarv

is-MAGIC**。**PATCH**。由於產品 ROI 過低，前端已凍結為唯讀狀態：**Task Rewards 🏁** 選單及模組`Modules/TaskRewardInspector/*` 已刪除；CLI`--task-reward-inspect` 仍顯示「FROZEN（僅供研究）」橫幅。Doc`FFX_TASK_REWARD_INSPECTOR_FROZEN_2026-06-18.md`. 實際的內容編輯工作仍在「核心指令」／「寶藏」／「閃電球」／「Mon 編輯器」中進行。[上一頁：`v2.152.0.0`]
- **`v2.152.0.0` — 球形網格方格模式 第一階段：儲存方格 + 完整匯出 dat0X+dat1X 資料包。** Lane **Jarvis-MAGIC**。 **次要更新**。Canvas v2 新增 **方格模式** 切換功能，以及 **儲存方格** / **匯出方格套件** 按鈕，`SphereGridSquarePackageWriter` (`square_grid_manifest.json` + 報告 + README 部署)，儲存後透過`FromExisting`, manifest delta bridge 搭配`square_mode=1`. RT2 hook 在 R27 處卡住；結果 = reauthor 離線，顯示為 Square。計畫：`FFX_SPHEREGRID_SQUARE_MODE_FULL_REAUTHOR_PLAN_2026-06-18.md`. [上一頁：`v2.151.0.0`]
- **`v2.151.0.0` — 任務獎勵遊戲檔案缺失：grantAbility、Ronso mon.bin、Tidus counter、corpus mode。** Lane **Jarvis-MAGIC**。**MINOR**。`TaskRewardGameFileLoader` 現在掃描 ATEL`0x01FC`/`0x01FD` (授予／撤銷權限)，交叉連結`mon.bin` RonsoRageId (0..999)、戰鬥之門 Tidus @15852，以及模式`--all-treasure-grants` / 用於完整「obtainTreasure」語料庫的核取方塊介面（原始計數器與篩選後計數器）。儲存快照會顯示`TidusOverdriveUseCount`. [上一頁：`v2.150.0.0`]
- **`v2.150.0.0` — 任務獎勵檢查器：讀取遊戲檔案（核心 + ATEL）。** Lane **Jarvis-MAGIC**。**次要**。新增`TaskRewardGameFileLoader` 閱讀`command.bin`,`takara.bin`,`important.bin` 並掃描`.ebp` 當 FFX 專案載入時，會執行 (obtainTreasure/hasKeyItem)。使用者介面新增了「遊戲檔案」面板及「載入」按鈕；命令列介面`--game-files [--project]`. Doc`FFX_TASK_REWARD_GAME_FILE_RE_2026-06-18.md`. [上一頁：`v2.149.1.0`]
- **`v2.149.1.0` — 任務獎勵檢查器：註冊表中未儲存的命名標記 + 可行性文件。** Lane **Jarvis-MAGIC**。**PATCH**。該分頁`Task Rewards 🏁` 現在列出獎勵點數的`ffxed_registry` （流星、攻擊捲軸、傑克特之球等）無需載入存檔；「Live」欄位僅在選擇存檔時才會填入。新文件 `doc

s/reverse/FFX_TASK_REWARD_AUTHORING_VIABILITY_2026-06-18.md` mapeia caminhos save-side / ATEL / hook com gates. [anterior: `v2.149.0.0`]
- **`v2.149.0.0` — 編輯器中的「任務獎勵檢視器」：任務／獎勵的唯讀分頁。** Lane **Jarvis-MAGIC**。**次要**。命令列介面`--task-reward-inspect` IconRail 現已推出 Avalonia 介面（`Task Rewards 🏁`)：可依角色／獎勵篩選的物品清單、選取任務的詳細資訊、存檔／資料區域地圖、編寫路徑，以及可選載入 25848 位元組的原始存檔檔，用於 OD 模式／計量表／擊殺數／位元資料的快照，加上 Blitzball 獎勵。 無寫入功能；在內容編輯前會保留 diff/ATEL 的安全防護機制。[先前版本：`v2.148.0.0`]
- **`v2.148.0.0` — 介面編輯器全面改版（計畫第 4 至 12 層）。** Lane **Jarvis-UI**。**次要**。完成`EDITOR_UI_OVERHAUL_PLAN.md`: 移除了在大型模組內會再次出現的內部側邊欄（`MonsterAiEditor`,`MonsterEditor`) — 轉為`Expander` 可折疊的 (`Padding="8"`，每項不包含 cardSoft）；密度（半徑 18→12，間距 16→12，`Button.nav` 14.12→12.8）；排版（`h1`/`h2`/`h3`/`label`/`body`/`muted`); 1 行寬的頁首 ~40px（工作區標章 + 圖示）；`Button.dangerAction` +`Border.pillDanger` +`:focus-visible` +`Border#EmptyState`; 頁尾 → 單行狀態列；將字面色彩提升為標記 (`PanelDeepColor`,`HeroAccentColor`,`RailHoverBrush`...); 真實圖像學（`PathIcon` +`StudioIcons.axaml`) 在 IconRail 和頁首；游標懸停時的轉場效果為 120 毫秒。編譯 **0 個錯誤**。[上一則：`v2.142.0.1`]
- **`v2.142.0.1` — Sphere Grid True New Node hook v5.2：退出探測點 8E27E0/8E27B0/A54720。** Lane **Jarvis-MAGIC**。**PATCH**。RT2 R3a 已確認原版遊戲在後續階段發生當機`A54860`; v5.2 繞過 UI 停用 + 回呼槽-19 + 帶有 SEH 和 exit-snapshot 的 GPU 釋放。必須使用 RT2 R4a。[先前版本：`v2.142.0.0`]
- **`v2.142.0.0` — 任務獎勵檢視器：任務、獎勵及存檔區域的唯讀清單。** Lane **Jarvis-MAGIC**。**MINOR**。新 CLI`--task-reward-inspect [--save <raw-25848-save>] [--json]` 列出標準獎勵關卡（提達斯／奧隆／瓦卡／基馬里／露露／莉庫／尤娜／OD 模式），並說明已知的存檔區域（`15788..15852`,

 `22090..24606`, OD 模式、閃電球、關鍵/迷你遊戲標記、球體網格）並列印出安全的內容製作路徑。無撰寫者：閃電球超載獎勵仍僅限元資料／被封鎖，僅適用於特定獎勵，而 ATEL 事件／關鍵標記則將作為 RE 的下一個重點。[前文：`v2.141.0.1`]
- **`v2.141.0.1` — Sphere Grid True New Node hook v5.1：退出路徑僅供觀察 + 針對 A54860 之後的回報。** Lane **Jarvis-MAGIC**。**PATCH**。此 Hook 修正了錯誤`after-A5BB70` 該程式會重新套用 manifest 檔案，並使用`g_writeApply=1` 儘管`g_writeSave=0`; 路徑`before-A54860` 保持只讀狀態；SEH 位於跳板中`A54860`/`A5BB70`. RE 重新映射了原版 exit 指令`A56060 → A5BB70 → A54860 → 8E27E0`；調查後的嫌疑人：`FFX_Abmap_DeactivateAndReturnToFieldUI` 以及拆解渲染圖`A54560/A54660`. 文件：`FFX_SPHEREGRID_EXIT_POST_A54860_RE_2026-06-18.md`. 必須包含 RT2 和 R3。[上一則：`v2.141.0.0`]
- **`v2.140.0.8` — Sphere Grid True New Node：分配器被駁斥，靜態 ABMAP 緩衝區已證實。** Lane **Jarvis-MAGIC**。**REVISION**。Sprint A.5 IDA 已關閉未知閘門：`dword_2305834`/`g_FFX_AbmapMenuStatePtr` 並非源於堆記憶體容量不足；`FFX_Abmap_InitStaticMenuStateBuffers` (`0xA572E0`) 將指標初始化為`word_133F76C+0x36E104` 並歸零`0x12FC0` 位元組。節點記錄是`1024 * 0x28`，因此節點 860 位於緩衝區內。假設「A5BB70 讀取 OOB 是因為分配器是 860」**已被駁斥**。新嫌疑對象：後續當機——`A54860`/易碎的選單視窗或重新撰寫掛鉤`after-A5BB70`; 後續的閘門應實作 SEH/精確階段，而非修補分配器。[先前：`v2.140.0.7`]
- **`v2.140.0.7` — Sphere Grid True New Node RT2 R2 當機 RE + 存檔佈局整合。** Lane **Jarvis-MAGIC**。**REVISION**。RT2 R2 搭配 v5 hook 時發生 **當機** 於`after-A54860`; 6 個子代理（BG-A–F）達成一致：假設 A54860 OOB **被推翻**（迴圈 1024 唯讀）；引擎 **以標頭為驅動**（NodeCount 在儲存／載入時未硬編碼）； 疑似當機原因 = OOB 讀取發生於`A5BB70` 若為 blob 選單`dword_2305834` 容量不足；經實證確認，SG 儲存檔中約有 1.2 KB 的可用空間（9 次儲存）。文件：`FFX_SPHEREGRID_TRUENEWNODE_RT2_R2_VERDICT_2026-06-18.md`,`FFX_SAVE_SPHEREGRID_ADDRESS_MAP_2026-06-18.md`, `FFX_SAVE_FORMAT_AND_SPHEREGRID_LAYOUT_2026-06

-18.md`, `FFX_SPHEREGRID_TRUENEWNODE_HOOK_V6_DRAFT_2026-06-18.md`; handoff `docs/ai/SESSION_HANDOFF_Jarvis-MAGIC_2026-06-18_0154.md`. **Próximo gate:** Sprint A.5 — IDA allocator `dword_2305834` (`sub_A44D30`/`sub_A44EF0`). [anterior: `v2.140.0.6`]
- **`v2.140.0.6` — 球形網格方格模式：離線重新授權完整計畫（交接）。** Lane **Jarvis-MAGIC**。**修訂版**。文件`docs/reverse/FFX_SPHEREGRID_SQUARE_MODE_FULL_REAUTHOR_PLAN_2026-06-18.md`：Square 風格的工作流程（每次儲存時完成 dat0X+dat1X 對），True New Node 成就，以及編輯器／hook／RT2／部署階段，以供下一個代理程式使用。[上一則：`v2.140.0.5`]
- **`v2.140.0.5` — Sphere Grid TRUE NEW NODE hook v5：透過即時指標控制選單狀態。** Lane **Jarvis-MAGIC**。**PATCH**。v4 已修補`g_AbmapMenuState` 靜態 (`0x6A3704`, IDA 中無 xref）；v5 解除引用`dword_2305834` (`0x2305834`) 就像該可執行檔在`A49590/A5BB70`. 必須使用 RT2 進入／退出。 [上一頁：`v2.140.0.4`]
- **`v2.140.0.4` — Sphere Grid TRUE NEW NODE hook v4：針對非活躍的新節點修補選單記錄。** Lane **Jarvis-MAGIC**。**PATCH**。`A49590` 僅在節點的選單記錄 ≠ 時才套用狀態`0xFFFF`; hook v4 初始化`g_FFX_AbmapMenuState+0x808` 在執行「apply」、「save」或「recompute」之前，適用於新槽位；manifest 包含`link state=0` （在遊戲中啟用前處於停用狀態）。RT2 進入／退出時，**關閉**節點仍為強制要求。[先前：`v2.140.0.3`]
- **`v2.140.0.3` — Sphere Grid TRUE NEW NODE hook v3：完整處理流程 + 雙重套用。** Lane **Jarvis-MAGIC**。**PATCH**。`SphereGridTrueNewNodeHook` 現在轉向`A45570` (版面配置)，`A47210` (預設狀態合併)，`A5B140` (相鄰性)，`A54860` (重新計算) 此外`A53DE0/A49590/A5BB70`; 強制生成新插槽的種子 (`>= seeded count`)，在`A49590`, 標語為`link state=1` 以及「誠實 LAB」橫幅。RT2 進出仍屬強制性。[上一則：`v2.140.0.2`]
- **`v2.140.0.1` — Sphere Grid：缺失的鉤子 + Unknown6 守護者 + 球體面板 + 核心克隆重新載入。** Lane **Jarvis-MAGIC**。**PATCH**。交付`SphereGridTrueNewNodeHook` +`GridTeachHook` (缺失的來源 vs`v2.139.0.0`),`Unknown6` ABMAP 重新計算/驗證桶 + Safe Transplant 對比 True New Node LAB，`SphereGridNodeSphereRequirement` 

+ 「Panel」分頁，`Ability_Command.CloneDeep` + 在「複製/刪除」指令中重新載入圖表；文件 RE Unknown6/L3/執行時狀態表。RT2 True 新節點 **尚待處理**。[前一項：`v2.140.0.0`]
- **`v2.140.0.0` — Arena+ 自訂混音 第 2 階段：F7 檢查清單 + 遊戲內編曲。** 路線 **Jarvis-ARENA**。** 次要 **。自訂混音 x3/x4/x5 開啟原生選曲器（8 格，Magus +3）→ 子程序`ArenaMultiBossLab.exe --compose` → 發射載具；`--compose` CLI + 專用電信業者`mcyt00_22`/`nagi05_23`/`nagi05_22`；Duo–Specials 預設設定保持不變。設定`arena_plus_compose_vanilla_btl.txt`. 文件`FFX_ARENA_PLUS_COMPOSE_PHASE1/2_2026-06-16.md`. [上一頁：`v2.139.1.1`]
- **`v2.139.1.1` — Field Explorer：Walk Publish Refresh + 可拖曳疊加層 + 在 MapViewer 中合併 NPC。** Lane **Jarvis-FIELD-RE**。**PATCH**。`--field-explorer-refresh-walk` +`publish-scout-to-editor.ps1` 再生`field-encounters.json` 不刪除 btl.bin 群組；Field Explorer 面板可拖曳；WalkManifest 提供更穩健的碎片處理；Field Scout 具備戰鬥安全性（靜止狀態 + 延遲執行大型掛鉤）。Walk 套件包含 50 個欄位（2026-06-17 會議）。[上一則：`v2.139.1.0`]
- **`v2.139.1.0` — SIN 被附身開局：第一回合防守 + 預設鉤子起手（RT2 m019）。** 線 **Jarvis-MAGIC**。**PATCH**。`BuildFirstTurnGuard` (TurnsTaken&lt;2); 條目`0` 使用 always-true 守護程序；預設駕駛員`--clear-forced-action` + hook init;`--on-turn`/`--battle-start`. [上一頁：`v2.139.0.0`]
- **`v2.139.0.0` — Sphere Grid TRUE NEW NODE LAB：清单編輯器 + 執行時狀態編譯器掛鉤。** Lane **Jarvis-MAGIC**。**次要更新**。Builder 新增可選擇啟用的 **TRUE NEW NODE LAB** 功能，用於在已初始化的網格中追加資料，並進行寫入`dat02/dat10` +`modules/config/true_new_node_manifest.csv` +`true_new_node.flag`;`FfxHooksDll` 贏得`SphereGridTrueNewNodeHook` 閱讀該宣言並遵守`g_FFX_SphereGridRuntimeStateTable` (`word_112EC7C`) 針對新節點／連結的一致性。**必須完成 RT2：** 在將產品升級為「安全產品」之前，確保進出 Sphere Grid 時不會發生當機。[先前：`v2.138.4.2`]
- **`v2.138.4.2` — SIN 附魔開局：守衛 TurnsTaken + RET（避免原版 Blizzara 的穿透效果）。** 路線 **Jarvis-MAGIC**。** 補丁 **。`performCommand` m166;`stopAfterAction`; p

已記錄的 RT2 m019 調查。[上一則：`v2.138.4.1`]
- **`v2.138.4.1` — SIN Possessed 開場技：修正擴充後入口點的重定向（onTurn 確實會執行該區塊）。** Lane **Jarvis-MAGIC**。**PATCH**。[先前：`v2.138.4.0`]
- **`v2.138.4.0` — SIN 《Possessed》起手牌：「被尤·耶文附身！」於第1回合（烘焙＋駕駛員 CLI）。** 車道 **Jarvis-MAGIC**。**次要**。`SinPossessedOpener` (monmagic2`0x60E7`–`0x60EE`, m166 標準`performCommand` Self）；`--sin-possessed-scan` /`--sin-possessed-pilot`; 烘烤`--possessed-opener`; 閘門模式忽略`payload-candidate` 在內容製作方面。[上一頁：`v2.138.3.0`]
- **`v2.138.3.0` — Monster AI：SIN v2 圖庫（8 個真實單元；移除 100 個通用 UI 原型）。** Lane **Jarvis-MAGIC**。**PATCH**。`AiSinPresetCatalog` 看看這個`universal.csv`/`boss-presets.csv`; 已將 CSV 複製至輸出欄位；Monster AI 圖庫已更新。[上一則：`v2.138.2.0`]
- **`v2.138.2.0` — SIN UNI-005..008：Macalania 預設（雙冰／水，前排 Watera、Cure、White Wind）。** Lane **Jarvis-MAGIC**。**MINOR**。[上一則：`v2.138.1.0`]
- **`v2.138.0.0` — SIN 目錄 v2 從頭開始：CSV + boss-bindings；4 個核心已準備好進行烘焙。** Lane **Jarvis-MAGIC**。**MINOR**。[上一則：`v2.137.1.0`]
- **`v2.137.0.1` — Field Scout MAX：Opus 程式碼審查（P0/P1/P2 + 已通過驗證的 RE 審計於`.i64`).** Lane **Jarvis-FIELD-RE**. **REVISION**（登錄檔；無寫入者／行為）。`docs/ai/REVIEW_RESULT_FIELD_SCOUT_MAX_v2.137.0.0_Jarvis-FIELD-RE.md`: 判定結果為「有保留的通過」（實驗室／唯讀）；**1 P0**（無鎖重複資料刪除儲存 → 競態條件／TOCTOU 堆疊溢出發生於`FieldScoutHook.cpp:1055-1074`); P1（UAF 拆解；`max_warp` 太寬了，經由`sub_870AC0` 重新定位任何角色）；P2（Takara 記錄玩家的座標，進行雙重寫入`RecordMaxZoneSlot`, 閘門`groupByte>0` 排除第0區，PS`+=` O(n²))；**RE 審計：** 4 個 MAX 函式已反編譯 (`sub_798FE0`/`sub_870AC0`/`sub_875BA0`/`sub_85A740`) — RVAs/ABIs **已逐位元組確認**，無誤；RT2 缺口（座標黃金區、obtainTreasure 覆蓋範圍、shift17↔btl 群組）阻礙了`lab` 在`PORT_STATUS`. [上一頁：`v2.137.0.0`]
- **`v2.137.0.0` — Field Scout MAX MODE：RE 鉤點（takara/warp/zone）＋NPC／觸發器疊加層＋RE 地圖集。** Lan

以及 **Jarvis-FIELD-RE**。**MINOR**。`field_scout_max.flag` (gate: heavy+ultra+max); scout v8: hooks`sub_798FE0` takara,`FFX_Field_WarpActorToPosition`,`FFX_Field_SampleEncounterZoneSlot`;`sceneGroup` @ scene+0x10; 匯入`max-events.json`; WalkManifest`npcSpawns`/`triggerSpawns`; MapViewer 藍色／青色標記。文件`docs/ai/FIELD_SCOUT_MAX_MODE.md`, **`docs/reverse/FFX_FIELD_SCOUT_RE_ADDRESS_ATLAS_2026-06-17.md`**（RVAs／來源／公式），Opus 審閱提示。[上一則：`v2.136.0.0`]
- **`v2.136.0.0` — 場地偵察 ULTRA HEAVY：按類別細分標記（主通道 + 重型通道）。** 路線 **Jarvis-FIELD-RE**。**次要**。`field_scout_ultra.flag` + 5 個子標誌 (`field_logic`,`collision`,`encounters`,`scene_env`,`pipeline`); scout v7:`npc_spawn`,`trigger_spawn`,`ultra_*` 真實的樣本／存根；去重 2M；`deploy-field-scout.ps1 -Ultra`. Doc`docs/ai/FIELD_SCOUT_ULTRA_HEAVY_MODE.md`. [上一頁：`v2.135.0.0`]
- **`v2.135.0.0` — Field Scout + Aurora：擒獲寶箱（bauro/chest）並在地圖上疊加標示。** 路線 **Jarvis-FIELD-RE**。**次要路線**。Field Scout v6 (`chest_spawn` 透過 scene node/CHR`bauro*` +`area`/`field` （在貨運清單中）；裝載`chest-spawns.json`; WalkManifest 碎片；Aurora Field Explorer + MapViewer 會在危險區域旁標示金色標記（mapout.vpa）。[上一頁：`v2.134.5.0`]
- **`v2.134.5.0` — Field Scout 發布管道：實驗室工作/ → WalkManifest 編輯器（發行套件）。** Lane **Jarvis-FIELD-RE**。**PATCH**。`publish-scout-to-editor.ps1`;`WalkManifest/` + Field Explorer 徽章呈現「被踩扁」的狀態；`work/`/`fields/`/`public/maps/` gitignored；csproj CopyToOutputDirectory。[上一項：`v2.134.4.0`]
- **`v2.134.4.0` — Field Scout HEAVY v5：Phyre 網格的世界坐標 + CHR 出生點。** 路線 **Jarvis-FIELD-RE**。** 更新 **。`scene_node_placed` (wx/wy/wz 經由`Phyre_PSceneNode_composeWorldMatrix` + 設定節點掛鉤)，`chr_spawn` (ActiveChrInstance 掃描 +`SetWorldPosition`); 攝入`scene-nodes-world.json` +`chr-spawns.json`. [上一頁：`v2.134.3.0`]
- **`v2.134.3.0` — Field Scout HEAVY：積極擷取 + 離線 texconv 處理流程。** Lane **Jarvis-FIELD-RE**。**PATCH**。`field_scout_heavy.flag`: 去重 **1M**，player-trace 執行緒 1.5 秒，polyMeta/sh

textures 中的 ift17、encounter/zone 鉤子、所有場景節點、獨立的 JSONL 追蹤；`install-field-scout-tools.ps1` (texconv)，`extract-scout-textures.ps1`, 部署「heavy default」。[上一則：`v2.134.2.0`]
- **`v2.134.2.0` — Field Scout v3 world_walk：完整通關的最高擷取量。** Lane **Jarvis-FIELD-RE**。**PATCH**。堆疊去重 **250k**；額外掛鉤`GetInstanceNameByIndex` →`scene_node`;`LoadAndActivateDriver` log all PS3Data;`field_load` 發行合成套裝 (`geometry_inferred`); 路徑鬆散`map/area/field`; 攝入`walk-field-catalog.json` +`deploy-field-scout.ps1`. [上一頁：`v2.134.1.0`]
- **`v2.134.1.0` — Field Scout v2：3D 幾何鉤子（field load + .dae.phyre）。** Lane **Jarvis-FIELD-RE**。**PATCH**。`graphicFieldMapLoad` +`LoadAndActivateDriver` → manifest`field_load` /`geometry` 包含播放器錨點；已更新匯入腳本。[先前：`v2.134.0.0`]
- **`v2.134.0.0` — 場地偵察員：行走時的 JSONL 資料（貼圖 + 玩家錨點 + 已發現的區域）。** 路線 **Jarvis-FIELD-RE**。**次要**。`FieldScoutHook` 在`ffx-hooks.dll` (`field_scout.flag`): 對多達 65,000 個資產進行去重，並儲存`modules/field-scout/session-*.jsonl` 包含 path/cat/field/tile/px/py/pz/sceneId；匯入`RuntimeTools/FieldScoutLab/process-scout-session.ps1` → 報表 + 佇列 PhyreMapExportLab. Doc`docs/reverse/FFX_FIELD_SCOUT_WALK_MANIFEST_2026-06-17.md`. [上一頁：`v2.133.0.0`]
- **`v2.133.0.0` — 球形網格面板 + 探索器：「所需球體」下拉選單會記錄下來`NodeEffectBitfield` +`AppearanceType`.** Lane **Jarvis-MAGIC**. **MINOR**. 預設值：力量／法力／速度／技能／鍵位（1–4 級）（+ 自訂）透過`SphereGridNodeSphereRequirement`;`WriteNodeTypes` 兩個欄位仍會保留（先前總是繼承自原始欄位）。**Panel** 標籤頁與 **Explorer → Node Types** 新增下拉式選單；Panel 的清單會顯示推斷出的球體。修正「Key NV3」的編輯功能與技能教學之間的衝突（`0x0400`). **待處理的 RT2：** 在等級 ≥96 的克隆體上錄製「能力球」，並在遊戲內確認消耗值。檔案：`FfxLib/SphereGrid/SphereGridNodeSphereRequirement.cs`,`SphereGrid_File.Write.cs`,`Modules/SphereGridPanel/*`,`Modules/SphereGridExplorer/*`. [上一頁：`v2.132.0.0`]
- **`v2.132.0.0` — 《Sphere Grid Builder》：填充

r`panel.bin` 自`command.bin` + 技能選擇器 + Kimahri Ronso CLI 解析。** Lane **Jarvis-MAGIC**。**MINOR**。`SphereGridPanelGrowWriter` 將節點類型附加至`panel.bin` (jp+us) 複製技能範本 (`LearnedMove = 0x3000|id`); Builder 新增 **command.bin** 下拉選單、**熱門面板 (≥96)** 按鈕，以及在 **套用** 時自動擴展功能；修復 JP 編碼器（從不使用 ASCII）`"Learn …"` （日文版本）。CLI`--kimahri-ronso-parse [command.bin]` OD Ronso 的統計資料（104–115，《Lancet》，開場 282）。**RT2 待定：** 該角色在遊戲中教授克隆技能，等級 ≥96。檔案：`FfxLib/SphereGrid/SphereGridPanelGrowWriter.cs`,`SphereGrid_File.Write.cs`,`Modules/SphereGridBuilder/*`,`Tools/KimahriRonsoParseRt0.cs`,`Program.cs`. [上一頁：`v2.131.0.0`]
- **`v2.131.0.0` — 核心指令：複製／刪除／新增資料列，並可在內嵌文字池中編輯名稱／描述。** Lane **Jarvis-MAGIC**。**MINOR**。`KernelCommandListMutator` (在...中新增/複製/刪除)`command.bin` +`monmagic*.bin`); 清單中的 **複製 / 刪除 / 新增** 按鈕（與 Monster Commands 1/2 功能對應）；可編輯 **名稱** 與 **說明** 的 **Identity** 面板（`DisplayName`/`DisplayDescription` →`NameScriptBytes`/`DescriptionScriptBytes`, 往返機票在 **Save** 透過`Ability_Command.WriteList`). 在編輯器中解鎖「路徑 4」的創作功能（例如：將克隆體 **#320** 重新命名為 **Blue Magic**，且不使用十六進位數）。**待處理的 RT2：** 遊戲內存檔與載入，以及在戰鬥選單中確認名稱／描述。檔案：`FfxLib/Ability/KernelCommandListMutator.cs` (新)，`Modules/BattleKernel/Commands/KernelCommands_*.{axaml,cs}`,`FFXProjectEditor.csproj`, 更新日誌。[上一頁：`v2.130.3.8`]
- **`v2.130.3.8` — Spira Reforge：第一階段「原版進攻平衡調整」已確定 — 16 項技能進攻加成 + 自動技能整理 + MP 球體提升。** 路線 **Jarvis-MAGIC**。 **修訂**（僅限設計／由 Halyson 敲定的決策；本次修訂未涉及劇本撰寫或角色行為）。Halyson 開啟了`FFX_PLAYER_COMMAND_CATALOG_0_TO_95_2026-06-16.md` 並斷言：*「魔法確實發揮了應有的作用，甚至包括治療。但其餘的呢？簡直可悲。Full Break？去你的，不僅幾乎打不中，花掉99點MP卻只造成可笑的傷害。」* 犀利評析：20項原版攻擊型技能，附帶`Pow

er = 16` (= multiplier 1.0× = Attack base) ou `功率 < 16` (= **pior que Attack**); Auron Full Break Power 16 / Acc 36 / MP 99 = crime contra o jogador. **Pacote final cravado (3 frentes em 1 pass):** **(1) Damage buff de 16 skills (Extracts removed):** Wakka 8 status-riders (Sleep/Silence/Dark Attack P16→20 Acc 50→60, Zombie Attack P16→24 Acc 50→60, Busters P16→26 Acc 100, Triple Foul P16→32 Acc 100→90 MP 24→28), Auron 4 Breaks (Power/Magic Break P16→22 Acc 50→80 MP 8→10, Armor/Mental Break P16→24 Acc 36→70 MP 12→14), **Full Break P16→48 (3× damage cravado Halyson) Acc 36→90 MP 99→75**, Tidus 2 Delays (Delay Attack P12→18 MP 5→6, Delay Buster P14→22 MP 10→12), Rikku Mug P16→20. Filosofia: Power ≥ 18 sempre quando skill paga MP; premium MP ⇒ premium Power; Breaks Acc 36-50% sobem 65-90%. **(2) Auto-Ability cleanup:** Slot 12 Half MP Cost **MANTÉM** (justificativa Halyson: Lulu Magic Booster + custos altos = ainda paga Ether/Elixir = balance natural). Slot 13 (ex-One MP Cost, cheese de 1 MP universal) **REMOVIDO → vira Mana Spring** (+5 MP/turno em batalha; regen tick passivo; substitui economia sem virar cheese — em battle de 10 turnos = +50 MP cumulativo). Slot 23 (ex-Break HP Limit) **vira "Break Limits"** (bits `0x0200 | 0x0400` OR em `ability_flags_64`, HP cap + MP cap juntos via engine vanilla; byte-edit puro, zero hook); §10.8 do VISION cravado. Slot 24 (ex-Break MP Limit) **vira "Devil's Bargain"** (+50% dano dado / +50% dano recebido — glass cannon switch simétrico; 2-pass: Pass 1 placeholder funcional agora com bit reassignment, Pass 2 hook damage calc depois com RT2). **(3) MP Sphere node bump (escopo B cravado Halyson "B simplesmente B"):** Standard Grid MP +40 → +60, Expert Grid MP +20 → +30 (escala proporcional 1.5× cross-grid). Edit trivial via `SphereGridNodeTypeEntry.IncreaseAmount` (offset 0x14, ushort) em `SphereGrid_File.cs:519`。**本次會議中敲定的決策順序：** (a) Halyson 開啟目錄，確認問題；(b) 我提議建立包含 20 項技能 + 4 類自動能力之增益表； (c) Halyson 確定將「萃取物」移出並採用 3 次「完全分解」；(d) 確定移除 1 點 MP 且不採用「法力護盾」（建立新目標）；(e) 我確認第 10.8 條，將第 23 號插槽逆轉為 Br

eak Limits 與第 24 槽位改為「xereca」用途；(f) 確定了第 24 槽位的「Devil's Bargain」配置，並理解了 2-pass 的注意事項；(g) 優化了第 13 槽位的「Mana Spring」及「Spell Spring」的待處理清單。 **已歸檔的技術注意事項：**「魔鬼交易」需計算鉤子傷害 + RE 位址`FFX_DamageCalc_*` 待處理；Mana Spring 需要回合開始時觸發效果 + 識別出可用的位元在`ability_flags_64`; 擊中命中率 vs 狀態附加效果命中率——RT2 待定突增；三重犯規命中率 100→90 待定突增（驗證「三重保證」不會失效）； 後期遊戲中全破MP縮放無誤（75在半MP狀態下仍過於昂貴）；自動能力位元重新分配槽位24需掃描可用標誌於`AutoAbilityHardcodedFlagCatalog.cs`. **第一階段技術計畫（純字節編輯`v2.131.x` 修補程式)：** 1.1`command.bin` 16 項技能攻擊加成，1.2 第 23 槽「突破極限」，1.3 第 13 槽「魔力之泉」佔位符，1.4 第 24 槽「魔鬼交易」佔位符，1.5`panel.bin` MP 節點、1.6 文字池、1.7 RT0/RT1 閘門位元組標識、1.8 RT2 導引信號。**第二階段（hooks LAB`v2.133.x+`):** 2.1 RE 傷害計算、2.2 魔力之泉回合計時鉤、2.3 惡魔交易傷害鉤、2.4 RT2 鉤。**與 VISION 的協同效應：** §10.4 QH 削弱（補充 — 技能強化 + QH 削弱 = 多元攻擊），§10.5 法術（不調整，下個版本），§10.6 OD 露露狂怒（下個版本），§10.8 破界 HP+MP 融合（本 1.2 階段已確定），§10.9 奧隆隱藏技能（強化 — 破界極限 + 惡魔交易 + 破界增益 = 「不死之身、敢於冒險的奧隆」），§10.10 魔法速度（Spell Spring 待處理清單），§10.11/§10.13（下輪處理），路徑 4 黑魔法擴展（間接 — 基礎原版設定為 ≥96 個法術提供背景）。 **待解決問題清單：** 法術泉正等待下一個空缺插槽（犧牲候選名單：插槽 18 雙倍 AP、19 三倍 AP、21 扒手、22 盜賊大師 — 進度/戰利品作弊手段）；角色專屬身分狀態/突破銳度 §10。9. **勿觸碰：** 寫入端（writer-side）的 writer/hook/probe/DLL/csproj。檔案：`FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.7` →`v2.130.3.8`);`docs/reverse/FFX_SPIRA_REFORGE_VANILLA_OFFENSIVE_REBALANCE_2026-06-16.md` （新內容，約280行，7個節：§0 簡短事實，§1 標準大屠殺診斷，§2 整合包 c

包含表 16 技能 + 自動能力清理 + MP 球體、§3 技術性注意事項（6 項）、§4 實施計畫（第 1 階段與第 2 階段）、§5 待解決問題、§6 交付版本、§7 交叉參考）；`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md` +`mods/Spira Reforge/VISION_AND_ROADMAP.md` （下一頁）。[上一頁：`v2.130.3.7` 參考目錄]
- **`v2.130.3.7` — 參考文件：96 項角色技能的彙整目錄（ID：`0..95`) 與`Power`/`MP`/`Formula`/`Acc`/`Hits`/元素/效果 + AbiMap 架構 × 全隊銀行。** Lane **Jarvis-MAGIC**。 **修訂**（登記文件／參考目錄；無撰稿人／行為／RT2；僅將原本分散於各處的知識整合至一份文件中`FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` +`FFX_SPELL_LEARN_ABIMAP_INFERNO_2026-06-15.md` +`FFX_BATTLE_COMMAND_MENU_INFERNO_2026-06-15.md` +`CommandCharacter_Dictionary.cs` +`Ability_Command.cs`). Halyson 要求提供 MD 中的 96 項技能表，作為此模組的運作參考。新文件`docs/reverse/FFX_PLAYER_COMMAND_CATALOG_0_TO_95_2026-06-16.md` （8 節，約 250 行）：§0 TL;DR：在 95 上達到極限（AbiMap 96 位元實體）＋交叉 RE 驗證；§1 引擎如何決定選單（`FFX_Btl_IsCommandAvailable @ 0x39BB70` 「單人」與「全隊」的區別`CharacterUser` filter）；§2 編碼`LearnedMove = 0x3000 | id` 從`panel.bin` (參考資料`SphereGridExplorer_DataModel.cs:30-31`); §3 完整目錄 0..95 分為 9 組（核心/選單 0-5、技能 6-21、特殊 22-25、應援 26-31、基馬里/防禦/社交 32-42、 **白魔法 43-64**、**黑魔法 65-83**、艾翁選單 84-87、莉庫終局 88-95），採用《FFX HD Remaster》（美版／日版）的正統數值 — MP／力量／公式／命中率／命中次數／元素／效果；§4 透過 3 個標記決定「魔法是什麼」的關鍵劇本（`DamageFlags` +`DamageFormula_Enum` +`PreviewFlags`) 包含「治療／復活／淨化／物理／魔法／狀態／增益／重力／吸取」技能表；§5 透過網格無法傳授的 11 個 ID（`missing=[0,1,2,3,4,5,33,84,85,86,87]` 在所有 10 個區域中 — system/Defend/Aeon/Yojimbo）； §6 96+ ID 全隊效果（超驅動、永恆、死亡、混合、偽 AI），其分離設計有 3 項理由；§7 斯皮拉重鑄與「漫步者」連結所帶來的後果

第 4 項的`v2.130.3.6`; §8 交叉引用。**不涉及：** writer/hook/probe/DLL/gate。檔案：`FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.6` →`v2.130.3.7`),`docs/reverse/FFX_PLAYER_COMMAND_CATALOG_0_TO_95_2026-06-16.md` (新)，`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md`. [上一頁：`v2.130.3.6`]
- **`v2.130.3.6` — Spira Reforge：REALITY CHECK + 3 次逆轉 — 路線 4 (`CharacterUser` （原生）固定 + 透過 Sphere Grid 固定的學習能力。Halyson 察覺到了我未曾注意到的細節。** Lane **Jarvis-MAGIC**。**修訂**（2026年6月16日上週四，續）`v2.130.3.3`；無寫入器／行為）。本節的架構迭代順序：**(1) v2.130.3.2 pivot：** 發現 RE D01，其中 ids`0..95` 這些應該是原生魚，我標記為「零釣鉤 + 剩餘 62 個魚槽」。**(2) Halyson 開啟了`FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` 並問道：「這是怎麼回事？」：** 2026年6月12日的審計報告已證實`0/96` 免費插槽 — 所有 96 個 ID 均已被 vanilla 佔用。我先前所述的「尚餘 62 個」是 **錯誤的**。**(3) v2.130.3.4 方案 3：** 我提議採用 append 方式`≥96` + 每角色白名單鉤子（通用版 Nul Ward 風格），Halyson 已批准。 **(4) Halyson 提出第四種方案：** *「在 CommandBin 中，難道不就是由我選擇某個角色的『使用技能』（例如 TIDUS），問題就解決了嗎？根本不需要任何鉤子。」* **我之前並未注意到這個原生欄位`[Data] public Character_Enum CharacterUser` 在`Ability_Command.cs:29`** — 有符號位元組 no`command.bin` 該設定會限制哪些使用者能執行各命令。字節精確的證明：`FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` 第 86 行引用了 Yojimbo Dismiss（ID 87），其中包含`CharacterUser=0x0E` (14=Yojimbo) — 原生引擎會根據此欄位自動篩選選單。現有使用者介面 (`KernelCommands_Control.axaml:434` 下拉式選單 (ComboBox)。**方法 4 取代方法 1/2/3** — append`≥96` 與`CharacterUser` 透過 UI 編輯器直接設定的每項技能。完全不使用選單過濾器的鉤子。**(5) Halyson 強調：「技能將可透過 Sphere Grid 學習」** — 這重新觸發了 Nul Ward §H 針對 ID 的注意事項`≥96` （全伺服器初始化時重新載入會覆寫 grant grid）。解決方案：**1 個通用鉤子**，透過擴展 `NulWardTe

achHook.cpp` (já provado em `v2.130.2.0`) — (a) detour `PrepareSaveCommandState` re-asserta bits ≥96 lendo sidecar; (b) detour panel_teach escreve sidecar quando node ativa. Net hook count: 1 (generalização, não hook novo). Sidecar JSON extends `spira-reforge-flags.schema.json` do Capture Cascade. **Plano técnico atualizado (15 bloqueios honestos catalogados):** Fase 0 ✅ → Fase A append `command.bin` ≥96 com `CharacterUser` (A.1-A.7 por pool char) → Fase B sidecar schema → Fase C Sphere Grid editor scope expansion (`LearnedMove = 0x3000 | id≥96`) → Fase D hook generalizado → Fase E RT0/RT1 writer LAB → Fase F RT2 in-game piloto → Fase G Lulu Fury rows → Fase H `-ja` backlog v0.7+. **Bloqueios pequenos pendentes (spikes):** addr panel_teach runtime, sidecar JSON schema design, side-effects `CharacterUser` filter (Trio of 9999, Doublecast cross-char), Multi-Firaga random-hit field, steal-per-hit Mugra/Mugga, Wakka status-rider per hit, Tidus self-buff stacking, Auron Sentinel++ party-wide buff. **Vantagens Caminho 4 vs alternativas:** (a) zero sacrifício vanilla (coexistência total Firaga + Multi-Firaga, Demi + Demita, Mug + Mugra/Mugga, Sentinel + Sentinel++); (b) net 1 hook (vs 0 do pivot falso, vs 2-3 do Caminho 3); (c) infra ALREADY EXISTING (NulWardTeach hook + sidecar Capture Cascade + editor UI ComboBox); (d) identity vanilla intocada. **Lição honesta documentada:** "sempre que sentir 'zero hook' soando bom demais, abrir os audits existentes antes de propagar a narrativa". **Doc atualizado:** §0 verdade curta (3 reversões + 4ª decisão grid), §1 ownership model (Caminho 4 + grid teach), §7.2 plano técnico (Fases 0-H), §7.3 15 bloqueios honestos, §10 entries `v2.130.3.5` e `v2.130.3.6`. **Não toca:** writer/hook/probe/DLL. Arquivos: `FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.3` → `v2.130.3.6`, pulou `.4`/`.5` por terem sido reversões dentro da mesma sessão de design), `docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` (§0/§1/§7.2/§7.3/§10 reescritos), `CHANGELOG.md` + `changelogUS.md` + `docs/governance/VERSIONING.md` + `docs/ai/SESSION_HANDOFF.md`. [anterior: `v2.130.3.3`]
- **`v2.130.3.3` — 《Spira Reforge》：第0階段 完成

A — Halyson 僅用一次操作就將所有角色待定（TBD）法術池全數鎖定（德米塔→基馬里、瓦卡 5 個法術、奧隆 MAX 包 6 個法術、提達多段攻擊＋自我增益、莉庫＋1 個新盜賊技能）。** Lane **Jarvis-MAGIC**。**修訂**（2026年6月16日第三次更新，緊接上文）`v2.130.3.2`; 沒有任何寫手／行為模式）。 **額外鎖定 4 項決策（從 9 → 13）：** (1) **解僱隊長 = 基馬里**（「奇異怪物」機制 + 藍魔導士主題；釋放露露專注於元素爆發）； (2) **瓦卡技能池 = A+B組合，5個法術** — 比奧拉（範圍中毒＋傷害）＋睡眠拉 （範圍睡眠）＋「四重犯規」（範圍三重犯規＋中毒＝4種狀態）＋「雙重破壞者」（2連擊單體，2種狀態隨機組合）＋「潮汐斬」（2連擊物理）——「狀態大師＋雙重擊＋瘋狂招式」； (3) **奧隆技能組 = 滿套技能，6 個法術** — 群體破防 + 群體破甲 + 群體破魔 + 群體破心 + **哨兵++**（哨兵 + 物理/魔法格擋 + 全隊 1 回合） + **挑釁** （挑釁＋自動「哨兵」＋嘲諷所有敵人）—— *「奧隆就是這遊戲裡他媽的坦克」*； (4) **提達的技能配置 = 多段攻擊 + 自我增益，4-5 個法術** — 螺旋斬（3 段單體攻擊，+5 力量／施法上限 25）+ 潮汐連擊（4 段範圍攻擊， +5 AGI/施放，上限 20) + 刀刃風暴（5 連擊隨機，+自身加速 1 回合）+ 野牛衝鋒（招牌技能，+固定 AGI + 加速 3 回合）+ 可選 應援一擊（2 連擊 + 自身應援）。 *「提達斯向來都是最快的。快速一擊肯定會被削弱，因此需要多段攻擊技能來提供提升自身屬性的增益效果」* — 針對快速一擊削弱的直接補償 §10.6； (5) **莉庫 +1 新增盜賊技能** — 哈利森要求「自創盜賊技能」以完善技能池；賈維斯建議：**手部技巧**（精進版「搶劫」）、**扒竊** （無回合消耗的偷竊；預設為 Jarvis），**粘手**（每次施放堆疊 +25%），**背刺**（無視物理防禦），**藏匿**（直接竊取技能池），**煙霧彈**（跳過隊伍 CTB）。 **最終完整分配（第 0 階段）：** 露露 6 + 尤娜 5 + 瓦卡 5 + 莉庫 4 + 基馬里 3 + 提達斯 4-5 + 奧隆 6 = **96 個法術槽中分配 33-34 個法術 = 約 35% 配額**（剩餘 62+ 用於`-ja` backlog v0.7+ + white magic extras)。**跨角色連段：** 奧隆「集體精神崩潰」＋露露「多重菲拉加」（無 MDEF 的波動爆發）；奧隆「哨兵++」＋尤娜 P

rotectga/Shellga（2回合近乎完全的無敵狀態）；奧隆「挑釁」＋瓦卡「四重犯規」（坦克＋群體狀態異常）；提達斯「刀刃風暴」＋奧隆「群體破甲」（提達斯爆發傷害＋目標無防禦力）。 **提達斯自我增益帶來的風險：** 無限堆疊 STR/AGI = 類似 QH 的退化現象；堆疊上限（5 STR / 4 AGI）的緩解效果 + 每場戰鬥結束後的衰減（戰鬥間不會持續）。 **第9.2節中剩餘的11個未解問題** — 均為細微的次要決策（莉庫盜賊技能的最終名稱、提達斯4個對5個法術）或**技術性突發狀況**（多重菲拉加的隨機命中）`command.bin` 場地效果、每擊竊取 Mugra/Mugga、Wakka 每擊狀態附加、Tidus 自我增益疊加、Auron Sentinel++ 全隊增益、Kimahri Lancet+ 持續效果）—— **不阻礙整體設計**，僅阻礙特定階段的編寫。捐贈者審計`0..95` (§9.2 q18) 現已確定具體範圍：約需 33-34 個插槽。 **文件更新：** §3.1.4 將「Demita」移至 §3.5.1「Kimahri」；§3.3 Wakka 鎖定 5 種法術；§3.4 Rikku 增加 1 項盜賊技能，附 6 項建議； §3.5 基馬希完整法術池（「解僱」＋藍魔導士擴充 2-3）；§3.6 提達斯法術池 4-5 種多段擊中＋自我增益，搭配對抗 QH 的連擊；§3.7 奧隆 MAX 套組 6 種法術，包含跨角色連擊＋風險/減傷； §3.8 總結：共 33-34 個法術 = 佔預算 35%； §9.1 13 項決策； §9.2 11 項子決策／突發狀況； §10 開場`v2.130.3.3`. **VISION §12 更新：** 各角色最終分配表 + 彈出式連段。**未涉及：** writer/hook/probe/DLL/gate。檔案：`FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.2` →`v2.130.3.3`),`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` （已移至第3.1.4節 + 已更新第3.3節／第3.4節／第3.5節／第3.6節／第3.7節／第3.8節／第9節／第10節），`mods/Spira Reforge/VISION_AND_ROADMAP.md` (§12 最後一桌 + 連擊)，`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md`. [上一頁：`v2.130.3.2`]
- **`v2.130.3.2` — Spira Reforge：架構轉向 — 「擴展黑魔法」改名為「擴展角色指令」（RE D01 測試版 + 適用範圍擴展至 7 個角色）。** Lane **Jarvis-MAGIC**。**修訂**（立即續接`v2.130.3.1`；沒有任何寫入器／行為）。Halyson 提議道：*「如果不用這些滑雪板，而是……

「既然『任何人』都能取得它們，我們為什麼不讓它們變成『僅限 X 角色』呢？」* ——我比對了現有的 RE，並發現 **原生引擎已經原生支援按角色設定 ID 的所有權**`0..95`**. **關鍵發現（RE D01 —`FFX_SPELL_LEARN_ABIMAP_INFERNO_2026-06-15.md`):**`FFX_GrantCommandToCharacter @ 0x785D10` 包含 **SPLIT AT INDEX 96**：ids`< 96` 去銀行聊聊吧`word_11307FC[74*char+3151+(id&0xFFF)/16]` (stride 74 個單字 =`ply_save` 按角色）；ID`>= 96` 將其存入全派對銀行（無步長）。⇒ **每個角色的可學習空間精確為 96 位元，ID 範圍為 0..95**。ID ≥ 96 無法透過「每個角色」的方式進行學習。**影響：** ID 的重新分配`0..95` = 原版引擎會篩選「誰」能看見每個法術，且**完全不使用任何鉤子**。舊方法（ID ≥96 加上 Nul Ward 風格的繞道機制來進行限制）已被捨棄。 **擴展分配方案（Halyson 於 2026-06-16 決議，引文保留）：** **露露**（6 個法術，爆發型施法者 + 吸血）——多重「菲拉加」系列 × 4 + 「吸血」+ **「滲透加」（從尤娜移至露露）**，可能包含「迪米塔」； **尤娜**（5 個法術，白色/增益範圍攻擊） — 反射加 + **防護加** + **護殼加** + 復原加 + **驅散加**（「反射加、防護加、護殼加、復原加、驅散加由尤娜負責」）； **莉庫**（3 個法術，偷取大師） — **「Copycat」成為她的專屬技能** + **Mugra**（2連擊單體，2次偷取） + **Mugga**（範圍2連擊，低傷害，「可偷取6次!!!!」）； **瓦卡**（待定，「更多狀態技能和更瘋狂的招式」）；**基馬里**（待定，「藍魔導士。 可學習怪物技能，甚至連牠們的超驅動都能透過魔力來使用」——由 Ronso 負責魔力路線協調）；**提達**（待定，「毫無頭緒，但或許會有多段擊中技能」）； **奧隆**（「這遊戲裡他媽的坦克。哨兵的進化版，或許擁有更強力的範圍破防技能」）。**預估總數：96個技能槽中的28-31個法術 = 約30%的配額**，尚餘65+個技能槽可用於`-ja` 待辦事項 v0.7+ + 未來規劃。**文件 §9.1 中已確定 9 項決策，§9.2**（解僱負責人、Wakka/Tidus/Auron 技能池、Rikku 模仿者替代方案、球網連線、捐贈者 0..95 審計、多重菲拉加隨機命中場、每次命中竊取的 Mugra/Mugga、Kimahri 藍魔導士協調 Ronso 路線）。 **此模型的優勢：** (a)

 零鉤客製化 — 原生基礎引擎；(b) 球形網格樹獲得實際意義（轉移至另一棵樹＝真正的取捨）；(c) 露露的「狂怒」機制大幅簡化 — 狂怒池採用基礎設定的「每角色獨立」機制，「將 Multi-* 排除於狂怒之外」不再是問題； (d) 「連鎖捕獲」§11 與「SIN 模式」§10.13 將針對每位角色提供不同的戰術回應。**技術計畫 (§7.2)：** 第 0 階段：鎖定池（待定）→ 第 A 階段：捐贈者審計（阻斷啟動）→ 第 B 階段：按角色編寫（B. Lulu 試飛版、B.1 尤娜 白色範圍攻擊、B.2 莉庫 穆格家族搭配每次命中竊取突刺、B.3 池（待定）） → 階段 C/D：RT0/RT1/RT2 → 階段 E：球網連線（斯皮拉網格編輯器擴充） → 階段 F：露露狂怒行 → 階段 G：基馬里藍魔導士（取決於隆索路線） → 階段 H：-ja 待辦清單 v0.7+。 **VISION_AND_ROADMAP.md 第 12 節重寫：**「擴展黑魔法」→「擴展角色專屬指令」＋角色分配表＋封鎖機制＋更新路線圖。 **文件名稱已進行概念性重命名**（為保留歷史紀錄，檔案路徑維持不變）：`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` — 11 個章節，§1 採用「按角色」所有權模型，內建 D01 反編譯 RE 並經過位元組驗證，§3 按角色分配（3.1 露露、3.2 尤娜、3.3 瓦卡 待定、 3.4 莉庫、3.5 基馬里協調、3.6 提達（待定）、3.7 奧隆（待定）、3.8 摘要）。**不涉及：** writer/hook/probe/DLL/gate。僅限設計與路線圖整合。檔案：`FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.1` →`v2.130.3.2`),`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` （大幅改寫：新增第1段 RE D01、第3段擴充7個字元、第5/7/8/9/10/11段重新編號並更新），`mods/Spira Reforge/VISION_AND_ROADMAP.md` （§12 重寫），`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md`. [上一頁：`v2.130.3.1`]
- **`v2.130.3.1` — 《Spira Reforge：延伸黑魔法》 — 4項關鍵決策：Halyson（多重Firaga選項B、最高單體目標吸血上限、Demita與Demi共存、包含所有細微差異的Fury）。** Lane **Jarvis-MAGIC**。 **修訂** 後續連鎖反應——`v2.130.3.0` （Ronso Mana 針對另一條平行 Jarvis-MAGIC 路線的輕微熱修）。此為以下設計文件的直接延續：`v2.130.2.1`: 與 H 的腦力激盪

艾莉森敲定了最後 4 項待定決策。**(1) 多重菲拉加機制 — 選項 B（隨機分配）＋ 3-5 倍基礎 MP：** 哈莉森：*「選項 B，但『多重菲拉加』、『多重幹死你』將消耗基礎技能 MP 的 3~5 倍來彌補，這可是超猛的連擊啊」*。 機制 = 1 次施放 → N 次命中（5-7 次），每次命中會隨機擊中一名敵人（透過聖光/彗星/雙重施放公式實現的原生引擎機制）。敵人可能根據隨機數值（RNG）受到同一個「多重菲拉加」的 1、2 或 3 次以上命中。 MP 消耗 = 4× 預設基礎值（Multi-Firaga = 64 MP），Multi-Ultima = 200 MP。Jarvis 建議：初期設定為 4× MP + 6 次命中，並調整 RT2。**可擴展系列**（漸進式推出）：v0.5 次多重菲拉加 + 多重布利扎加，v0.6 + 多重桑達加 + 多重沃特加，v0.7 + 多重烏爾蒂瑪（黑暗效果後 §10.11），v0.8+ 待處理的多重弗萊爾／多重聖光。 **(2) 吸血上限 — 每目標 9999/目標（多目標上限）：** Halyson 設定此數值時已充分考量其影響。4 名存活敵人 = 單次施法最多可恢復 39,996 HP = 頂級「進攻型治療者」。 ⚠ 可能破壞長時間的競技場戰局 — 此為刻意設計，屬 Halyson 的模組，屬於終局幻想設定。補償機制：若造成全面破壞，MP 消耗在 RT2 後可能攀升至 ~30。**(3) Demita 對比 Demi 原版 — 可並存：** 請保留兩者。 單體型 Demita（16 MP，頭目殺手）＋群體型 Demita（24 MP，波次清場）。玩家自行選擇工具。 代價：額外佔用 1 個 ID 槽位。**(4) Lulu 的「全包式」狂怒機制（含細微差異，§4 決策已更新）：** Biora 16× = 可行（毒波）； Drainga 16× = 僅限狂怒狀態下 9999/次上限（狂怒狀態下非按目標計算，否則最多可治療 639,936 HP ——「完全不合邏輯」）； Osmose-ga 16× = 可行（MP 上限 9999 = 硬性限制）；Demita 16× = 可行（Demi 不會命中已死亡目標）； **多重菲拉加 16× = 潛在 96 次命中 ⇒ 狂怒模式下的多重*技能使用 hit_count=1（在狂怒模式下恢復為單次施放）** 或將多重*技能從狂怒技能池中排除（這是「包含所有」規則的唯一例外）。最終決定將調整 RT2。 **文件第 8 節中更新的未決問題：** §8.1 已決（4 項確定）；§8.2 仍未決（Sphere Grid 線路、白魔法範圍效果、元素吸收混淆、**捐贈者的層級**）`0..95` 封鎖 A** 階段，多* 隨機分配`command.bin` field via spike）。**文件已更新：**`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` §2.2 裁員（按目標設定的上限），§2.4 解僱（c

（已固定），§2。5 多重菲拉加（選項 B + 固定 3-5× MP + 完整元素表），§4 狂怒（各法術的細微差異），§8 待議事項（4 項已標記並決定，5 項仍待商榷），§9 更新後的提交版本。 **下一步行動：** A 階段法術 ID 來源交叉核對與`FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` — Halyson 決定是現在就加入，還是等到 v0.5 接近發布時再加入。**不涉及：** writer/hook/probe/DLL/gate。檔案：`FFXProjectEditor/FFXProjectEditor.csproj` (瀑布`v2.130.3.0` →`v2.130.3.1`),`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` （§2.2/§2.4/§2.5/§4/§8/§9 已更新），`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md`. [上一頁：`v2.130.3.0`]
- **`v2.130.3.0` — Ronso Mana CRASH 緊急修補程式 (`hudSafe=26`): 對 blob 的寫入操作不再觸發節點（原先是`via=rich>=1 subIdx=0x01` → 當機）；現在的寫入方式為「選擇加入」模式 + 僅安全節點 + 由 SEH 保護的讀取操作。** Lane **Jarvis-MAGIC**。**PATCH**（修正由`hudSafe=25` 來自`v2.130.1.0` 當 DLL 被重新編譯／部署至`v2.130.2.0` 來自 Nul Ward 通道）。**根本原因（日誌 RT2`%TEMP%\ffx-hooks.log`):**`RonsoMana BLOB-PATCH2 #1 treeId=43 set subIdx=0x01 via=rich>=1 nodeOff=0x1B4 ec=24 (was 0xFF)` — 我所使用的 **(3)「最豐富的節點」** 備用方案`hudSafe=25` **寫入了一個被踢出的節點索引** (`0x01`,`ec=24`) 在`blob[2+43]`. 這使得`Resolve(2,1,43)` **「成功」**於一個**非 OD 環**的節點上 →`finishMenuTree` 載入／顯示了虛假內容 → 遊戲 **當機**。（該`0x00` 舊的`hudSafe<=24` 它只會傳回 −1，因此並不會導致程式當機：因為它從來不會被呼叫`finishMenuTree`.) 我的操作「讓原本『崩潰但仍可運作』的狀態演變成完全當機」。**該熱修補程式（`hudSafe=26`):** (1) **blob 的寫入功能現已改為「選擇加入」模式** — 僅在`blob[2+treeId]` 當寄件人 **`FFXHOOKS_RONSO_OD_BLOBWRITE=1`** 已設定；**預設值 = 不寫入任何內容**（防當機版本，純粹透過`ODBLOB`); (2) **即使採用選擇加入機制，也僅記錄「初級」節點** — (a) 其輸入中包含編碼 OD 指令的節點`0x311A`，或 (b) 遊戲已記錄過的同級方-OD 41..47；**絕不**自動記錄 c

hute「最富有的節點」（此資訊僅記錄於日誌中，以便在讀取轉儲檔後進行硬編碼）；(3) **所有節點的讀取資料（`OdBlobNode`/`OdBlobEntry`) 以及 a2=0 的區塊`DumpOdBlobStructureOnce` 現在已配備 SEH 裝甲（`__try/__except`)** — 任何因越界偏移量（OOB）引起的存取違規，都會被處理為「無效節點」並清除，而非導致系統當機； (4)`mainPtr` a2=0 通過了合理性檢查 (`> 0x10000`). 日誌現在會輸出`BLOB-PATCH2 #n ... write=0|1 safe=0xXX(how) risky=0xXX(how,ec=..)` （展示若不寫作會做什麼），而當選擇加入且節點安全時，`BLOB-PATCH2 WROTE ...`. 橫幅`hudSafe=25`→`26`. **可逆性：** 若未啟用 env，行為即為安全的原生模式（隱藏 OD，不會當機）。**尚未編譯／部署**（與其他 Jarvis-MAGIC 通道共用的 DLL）— **下次重新編譯時`ffx-hooks.dll` （無論哪條路線）都已取得該熱修補程式**；`ReadLints` clean。檔案：`RuntimeTools/FfxHooksDll/hooks/RonsoManaHook.cpp`. 文件：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §14. [前文：`v2.130.2.1`]
- **`v2.130.2.1` — 《斯皮拉重鑄：延伸黑魔法》 — 設計鎖定（多技能家族 > -ja 層級；`-ja` 轉為利基後備清單；Lulu Fury 包含所有內容）。** Lane **Jarvis-MAGIC**。 **修訂**（設計文件 + 整合至 VISION；本次迭代中未涉及任何寫入器／行為／RT2）。Halyson 發起了關於創建新「黑魔法」的腦力激盪。我比較了兩條路線：(a) **`-ja` 層級**（Firaja/Blizzaja/Thundaja/Waterja = 帶有 +Power 的 -ga 克隆版，不包含 Fury）vs (b) **多技能**（原版單體法術的範圍版，且這些法術**沒有**對應的範圍版本）。 **決策（Halyson）：** 多重技能作為主要路線勝出；`-ja` 被歸類為利基待辦事項（每個元素 1 項，工作量極大～80–120，天界之後，錦上添花——不會與增益效果產生衝突）`-ga` 在`VISION §10.5`); 露露·弗瑞 **包含一切**（「弗瑞·德萊恩加 16× 是美麗的混沌，過載的幻想」）。**為什麼「多技能」能勝出：** (1)`TargetFlags.Multi` 已經是 **引擎的原生功能** （`FfxLib/Ability/Ability_Command.cs:125`) — 單體 → 群體 = **指令列中佔用 1 位元**；(2) 法術填補了 **原版中的實際空缺**（缺乏範圍性毒、範圍性吸血、範圍性滲透），並賦予其獨特風格；(3)`-ja` 與「計畫」一詞重複`VISION §10.5` 已經要開始增益了`-ga` 搭配 Ignore MD

EF / 威力調整（「重鑄的菲拉加」，而非「菲拉賈」）；(4)`VISION §10.11` 已將 Holyra/Holyga/Wildra 歸類為「有趣，但可能永遠不會用」，原因相同（缺乏獨特性的技能池）；(5) Drainga/Osmose-ga 則用於支援其他戰線（T7 級「Capture Cascade」的長期戰鬥、SIN 模式的詛咒、怪物 OD 多重施法）。 **技術上已驗證的第一批法術（v0.5+）：** **Biora**（範圍毒效＋傷害，Bio分身＋多重施放），**Drainga**（範圍吸血，HP上限 9999／次施放）， **Osmose-ga**（範圍吸取 MP，上限 99/次施放），**Demita**（範圍 50% HP，上限 9999/目標）， **多重菲拉加系列**（3× 菲拉加 範圍連發，MP消耗為三倍 — 直接源自 Halyson 的構想：*「例如多重菲拉加>>>>>>」* — 可擴展至多重布利扎加／雷電加／水加／終極加的子系列）。 **第二波（v0.6+）：** 慢速咒、反射咒、半墜落（「次元碾壓」75% 生命值，單體，MP 消耗高），四分之一咒（25% 生命值，範圍，MP 消耗低）。 **已記錄的真實阻擋機制：** (a) 法術 ID 槽位`0..95` — 與……進行交叉審計`FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` 用以識別捐贈者；(b) 露露·弗瑞划船`#12408–#12422` 待處理的傷害；(c) 依賴 RT2 的魔法值上限消耗（無上限 = 透過攻擊治療的 OP，上限過低 = 法術失效）；(d) 多重菲拉加`hit_count` player-cast RE spike 待定；(e) 視覺特效與單人模式完全相同（v0.5 版本適用，v0.6+ 版本透過 Flan Flood 引擎重新上色，已通過測試）`v2.114.0.0`); (f) Sphere Grid 線路相關決策另行處理。**增量技術計畫（文件第 6.2 節）：** A 階段：審核 ID 捐贈者（無代碼，本文件），B 階段：離線編寫（複製行 + 多重翻轉 + 調整力量/MP + 文字輸入），C 階段：寫入器實驗室，D 階段：RT2 遊戲內，E 階段：Fury 整合，F 階段`-ja` backlog niche (v0.7+)。**與模組整合：** 補充功能`§10.5` 黑色增益魔法，提供能量`§10.6` 露露·弗瑞，請保持`§10.11` 《元素拼圖》，請回答`§10.13` 支援 Drainga/Osmose-ga 的 mob OD 多播，支援`§11` 記錄 Cascade T7 的戰鬥。 **VISION_AND_ROADMAP.md 已更新：**新增第 12 節「擴展黑魔法 — 多技能家族」（設計決策 + 第一／第二波法術 + 路線圖關聯內容 + 完整文件）；參考資料重新編號為第 13 節。 **供持續腦力激盪的開放性問題：** 多重菲拉加機制 A/B/C（硬編碼雙重施法 vs 隨機分配 vs 混合型 el

ement — 建議 A)，目標為單位的「Drainga」與施法為單位的「Drainga」對比，球形網線，Demita 與 Demi 原版版本的共存，白魔法範圍攻擊（Esuna-ga？），供能者層級。 **不涉及：** 任何寫入程式、任何鉤子、任何探針、任何 DLL、任何離線閘道／RT2。僅限文件 + 路線圖整合。新文件：`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` （10 節，約 300 行）。涉及的檔案：`FFXProjectEditor/FFXProjectEditor.csproj` (bump 4-tuple)，`mods/Spira Reforge/VISION_AND_ROADMAP.md` （新增第12條＋重新編號「參考文獻」為第13條），`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md`. [上一頁：`v2.130.2.0`]
- **`v2.130.2.0` — Nul Ward：「白魔法選單中什麼都沒有顯示」的根本原因 已查明 + 已修正 — 全隊共享的銀行已從`party_data` 每次戰鬥初始化時，會在「騎乘」選單出現前清除該增益效果。** Lane **Jarvis-MAGIC**。**PATCH**（修復了導致 Nul Ward 無法浮現的行為錯誤 — 與以下相同的 feature/lab：`v2.123.4.0`/`v2.124.0.2`; 已證實的決定性RE位於`.i64` 實際 + 新的 re-assert 繞道在`NulWardTeachHook`; 由 Halyson **釋出** 的 DLL（已完成重新編譯與部署）。**問題症狀：** 即使在針對 menu-bound 的多站點修正後（`v2.124.0.2`) + 載入時授予權限 (日誌`NulWardTeach grant ch=0..6 radiant=1 umbral=1`)，這些護符在戰鬥中的白魔法中**並未出現**。**已關閉的 RE（idalib MCP，經 byte 驗證，透過`disasm`):**`sub_7817D0` ("`* BTL INIT`") 呼叫`FFX_Btl_PrepareSaveCommandState`@`0x786BC0` ("`-- SAVE RAM CLEAR -- Preparing save game data`") 在 **每次戰鬥初始化時**；於`0x786CA3` 她會`mov ecx,21h; mov edi,offset dst__0; rep movsd` — 複製`0x84`(132) 位元組的內核`party_data` (表格 ID 4) 至`dst__0=0x11307D8`, 曲目`[0x11307D8,0x113085C)` **完全涵蓋**該`g_PartyWideCommandBank`@`0x11307FC` (偏移量`+0x24` 在副本內；資料庫 = 16 個單詞，ID 為 96..351)。⇒ **整個全黨資料庫被覆寫自`party_data` 每一場戰役**，以及`party_data` 沒有守護位 → word14=0 →`IsCommandAvailable(320/321)=0` → 放置循環跳過了守衛 → 「什麼都沒有出現」。**已排除的嫌疑對象：** `FFX_Btl_InitPartyWi

來自 CommandBank`@`0x784960` só dá `OR` em bits 0..130 e é **debug-gated** (`if(unk_112A905){ DebugMaxAll(); Init(); }` — não roda em jogo normal); `sub_78F0B0` (Lancet/blue) e o grant só mexem bit individual. **Correção mental do §H:** `PrepareSaveCommandState` não é só "persistência" — é o **reload ATIVO por-batalha** do banco a partir do `party_data`; qualquer grant de id≥96 ausente do `party_data` (sphere-grid teach incluído) reseta toda batalha. **Categorização corrigida (empírica):** dump do `command.bin` deployado mostra os doadores Nul (NulShock id48, NulTide id49) **e** as wards (320/321) todos com `子選單分類 (byte +24) = 0x02` — wards são templatadas dos doadores, então caem na **mesma** categoria de magia branca dos Nul que já aparecem (categorização correta-por-construção; faltava só o bit de disponibilidade vivo). **O FIX (lab `teach_grant`, deployado):** `NulWardTeachHook` agora instala um `PLH::x86Detour` no `FFX_Btl_PrepareSaveCommandState`; o shim chama o original (deixa recarregar o banco do `party_data`) e **re-afirma** `g_PartyWideCommandBank[word14] |= 0x3` (Radiant bit0 + Umbral bit1) no retorno — ou seja, logo após o wipe e antes do `FFX_Btl_BuildActorCommandMenu` semear o ator. Escrita direta no banco (não chamada de grant) pra não re-entrar no menu builder de dentro do init. Log diag (4 primeiros disparos): `NulWardTeach 重新設定 #n post-PrepareSaveCmdState：銀行字元組 14 0xPRE→0xPOST`. Grant one-shot mantido pros menus de field/pré-batalha. **Consequência de design (produção):** como `party_data` é a fonte por-batalha pra ids≥96, o caminho limpo pra uma ward sempre-disponível é adicionar o bit no próprio kernel `party_data` (innata, party-wide), não no sphere grid — um id≥96 ensinado no grid não persiste pós-init sem (a) o bit do `party_data` ou (b) re-assert em runtime como esse detour de lab. **Build/deploy:** `build_hooks.ps1 -WithPolyHook -Release` PASS (12/12 cpp), deploy `install_to_modules.ps1 -EnableApply -EnableTeach` (backup `ffx-hooks.dll.backup-nul-ward-20260616-081633`, novo SHA-prefix `0DE302BDF13D5B14`). Gate `--nul-ward-static` **VERDICT: PASS** (sem regressão; command.bin/exe/flags intactos). `.i64` 實際值：註解

在`0x786BC0` +`0x786CA3` （黃金法則）。2 個新的 RVA 位於`shared/ffx_addresses.h` (`RVA_FFX_BTL_PREPARE_SAVE_COMMAND_STATE`,`RVA_FFX_PARTY_WIDE_COMMAND_BANK`). **遊戲內 RT2：** 發起戰鬥並確認「光輝/暗影守護」是否已施放於白法技能上，並檢查日誌`reassert ... word14 0x0000->0x0003`. 開放邊緣：寬度為`ply_save` pro bit 224/225 (§H) — 每次載入時，lab 都會重新套用。檔案：`RuntimeTools/FfxHooksDll/hooks/NulWardTeachHook.cpp`,`shared/ffx_addresses.h`. 文件：`docs/reverse/FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16.md` §I. [前文：`v2.130.1.0`]
- **`v2.130.1.0` — 羅恩索·馬納（上週七）：我讀了那篇`DIAG`/`BLOB-PATCH` 來自 RT2`hudSafe=24` 我原本是跳過了 → 該 blob 的修補程式顯示「節點無效」（`subIdx=0x00`); 已重新編寫，以選擇「有效」節點 +`ODBLOB` 深度轉儲。** Lane **Jarvis-MAGIC**。**PATCH**（修正了損壞的啟發式演算法）`PatchCase2BlobForKimahri` + 在已發布的鉤子/RT2 中新增唯讀儀表；**程式碼已完成，將於下個 DLL 版本中進行編譯/部署** — 另一間部門正在使用）。**發現（行數`DIAG`/`BLOB-PATCH` 從`%TEMP%\ffx-hooks.log` 我從未讀過——只是用 grep 搜尋過`B0 resolve`):**`BLOB-PATCH #1 treeId=43 set entry=0x00 (was 0xFF)` +`DIAG G0-ring-post blob2=0x1B5C8D70 hdr=[03 8A] maxE=138 treeId=43 entry=0x00 slots41/42/43=[FF FF 00] OK` — 也就是說，`PatchCase2BlobForKimahri` **已經存在且正在運行**（已設定）`blob[45]` 來自`0xFF`→`0x00`) 但該`Resolve(2,1,43)` **仍為 −1**。⇒ 舊的備用方案（`maxUsed`→幾乎總是`0x00`) 指出 treeId 43 指向一個 **結構上無效的節點**：它通過了主要閘門的`WalkMenuBlobIndex` (`idx!=0xFF`,`43<count`) 但 **次要選擇器`ringKind` 爆發** (`v4>=node.entryCount` 或`entry[v4]==0xFFFF`) →`*a3=−1`. **同一日誌中的其他證據：**`count=138` (43 在範圍內 → 並非「計數過小」的情況／`43>=count`);`slots 41/42 = 0xFF` (**此 blob 中未記錄任何派對 OD** a2=1 → 沒有同級捐贈者)；`DIAG G0-finalize slot=2 od=3065 3064 3066 311A` (**環形緩衝區層-A TEM**)`311A`=cmd282 Ronso Rage** — 確認該傳送門百分之百是 B 層選單樹的解析結果，而非內容）。**修正方案（程式碼、`hudSafe=25`):** (1) **`PatchCas

e2BlobForKimahri` reescrito** — agora decodifica o nó no formato EXATO do `WalkMenuBlobIndex` (`v6=(count+1)/2+2*subIdx`; `nodeOff=*(i16)(blob+2*v6+4)`; `entryCount=*(u16)(blob+nodeOff)`; `entry[k]=*(u16)(blob+nodeOff+2+2*k)`, tudo bounds-clamped) e escolhe `blob[2+43]` por prioridade: **(a)** nó que **contém `0x311A`** (assinatura exata do OD) e suporta `ringKind=1`; **(b)** sibling party-OD 41..47 já registrado com nó selector-capaz; **(c)** nó mais rico que suporta `ringKind=1` (de preferência também 12). Se NADA qualifica, **deixa `0xFF`** (a2=1 não tem nó OD usável → é fix-C/redirect pro a2=0) e loga `NO 可行節點`, em vez de escrever lixo `0x00` como antes. (2) **novo `DumpOdBlobStructureOnce`** (read-only, dispara 1× mesmo em log-only) — dumpa os índices party-OD 41..47 do a2=1, o `entryCount`+primeiras entradas dos nós 0..23 (marcando o que tem `<<OD311A>>`), e os índices 41..47/109..115 do a2=0 (MainRing) → **1 RT2 crava o `subIdx` certo OU revela que é redirect pro a2=0**. Helpers novos (todos `static`, bounds-clamped, sem dep de PolyHook): `OdBlobNode`/`OdBlobEntry`/`OdNodeSupportsSelector`/`OdNodeContainsEncodedOd`/`ReadMainRingBlobPtr` (a2=0 = `_BASE` `0xD2A994`). Banner `hudSafe=24`→`25` (confirma DLL nova no log). **NÃO buildei/deployei** (DLL em uso por outra sala — respeitado); `ReadLints` clean; código pronto pro `build_hooks.ps1 -WithPolyHook -Release`. Arquivo tocado: `RuntimeTools/FfxHooksDll/hooks/RonsoManaHook.cpp`. Doc: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §13. [anterior: `v2.130.0.0`]
- **`v2.130.0.0` — Arena+ Multi Dark Aeon 等級鎖定報告 CLI (`--print-tier-lock`) + sidecar 架構 v1.** Lane **Jarvis-ARENA**. **MINOR**（新增功能：首份離線報告，整合 v2 目錄與 sidecar 進度；快照 LOCKED/READY/CLEARED 的新標準架構）。**新`RuntimeTools/ArenaMultiBossLab/TierLockReport.cs` + 4 面旗幟在`Program.cs`:**`--print-tier-lock`,`--progress <path>`,`--out <json>`,`--json`. 預設模式會根據閘口原因，按層級彙總並列印人員報告（`← needs: arena.dark.valefor, ...` 在 LOCKED 行中）及備用方案`rt2:<status>  risk:<...>  token:<mode>` 在 rows 中未`通過測試

d`. Modo `--out` ou `--json` emite JSON estrito que casa com o novo schema `mods/Spira Reforge/arena/spira-arena-tier-lock-state.schema.json` v1 (`格式`, `格式版本`, `generated_utc`, `summary{總計、已清除、已準備就緒、已鎖定}`, `rows[]` com `state` enum `已鎖定|已就緒|已清除` + `unlock_requires/missing_requires`). **Regras de gating ja documentadas no schema** (sao as mesmas que o futuro hook de menu F7 vai aplicar). **Run atual contra catalog + sidecar vazio:** 13 rows total -> 9 READY (solos) + 4 LOCKED (duo/trio/quartet/penta gateados pelos solos), 0 CLEARED. **README de `mods/Spira Reforge/arena/` reescrito** com tabela completa dos 5 sidecars + comandos `--print-tier-lock` e `--驗證` exemplificados. Lints clean. Build PASS. [anterior: `v2.129.0.0`]
- **`v2.129.0.0` — Arena+ Multi Dark Aeon BattleEndHook 框架（第 3 通道）＋戰鬥清理流程的逆向工程。** 通道 **Jarvis-ARENA**。 **次要更新**（DLL 新功能：關於戰鬥清理的全新唯讀 PolyHook2 鉤子，以及戰鬥結束流程的未公開反編譯結果）。**透過 IDA + MCP idalib 進行的反編譯** — 函式已重新命名並註解於`work/reverse/ida/FFX_recon.i64` （適用「黃金法則」）：`FFX_Battle_EndCleanupDispatcher @ 0x79E650` (曾是`sub_79E650`),`FFX_Battle_EffectFreeAtEnd @ 0x7FB090` (曾是`sub_7FB090`, 輸出字面日誌「(op)\top_et_battle_effect_free( battle end )」，`FFX_Battle_GetNextEncounterToken @ 0x7C5EE0` (曾是`sub_7C5EE0`). 發現的鏈條：`FFX_Btl_MainBattleTick @ 0x790C60` 在以下情況下呼叫 cleanup：`sub_888CE0(0,0,0)` 第 0x20 位元已啟用，在`FFX_Battle_InitEncounterFromBtlbin` 重新串接或返回該欄位。**新檔案：**`RuntimeTools/FfxHooksDll/hooks/BattleEndHook.{h,cpp}` (完整的框架：繞道機制、可註冊回調、透過處理程序實現的防抖功能、`BattleEndEvent` struct com`effectHandle`/`nextEncounterTok`/`result`/`sequenceNo`). **5 個新 RVAs 在`shared/ffx_addresses.h`:**`RVA_FFX_BATTLE_END_CLEANUP_DISPATCHER`,`RVA_FFX_BATTLE_EFFECT_FREE_AT_END`,`RVA_FFX_BATTLE_GET_NEXT_ENCOUNTER_TOKEN`,`RVA_FFX_BATTLE_MAIN_TICK`,`RVA_FFX_BATTLE_END_EFFECT_HANDLE` (=`dword_1134564[1743]` @`0x11360A0`). **Gate：**`arena_plus_victory_hook.flag` (env `FFXHOOKS_ENABL

E_ARENA_PLUS_VICTORY_HOOK=1`); default OFF. **Callback default `ArenaPlus_戰鬥結束時` em `dllmain.cpp`** apenas LOGA — NAO grava no `spira-arena-progress.json` ainda. **2 TODOs explicitos para RT2 spike** com Halyson: (a) distinguir vitoria/derrota/fuga via bitmask de `sub_888CE0`; (b) mapear `effectHandle` -> `progress_flag` via correlacao com ultimo `ResolverLogHook` match. Linha de plug-in `ArenaProgress_RecordCleared` deixada comentada e explicada no codigo. Build PolyHook PASS 12/12 cpp. Doc completa em `docs/reverse/FFX_ARENA_PLUS_BATTLE_END_HOOK_RE_2026-06-16.md`. **Reversibilidade:** remover flag = vanilla instantaneo; hook nao toca memoria/return. [anterior: `v2.128.0.1`]
- **`v2.128.0.1` — Ronso Mana（上週六 RE）：RUNTIME 已關閉 — o`−1` Kimahri 的 OD 會降低`WalkMenuBlobIndex(blob2,43)==0`; 已永久淘汰的 gauge/OD-ready（來自 RT2 日誌的`hudSafe=24` （試稿）。** Lane **Jarvis-MAGIC**。**修訂**（RE/doc + 註解於`.i64` 實際情況；**完全**沒有行為改變，**DLL 未受影響** — 另一間教室仍繼續使用）。**我讀了 RT2 的日誌，`hudSafe=24` (`%TEMP%\ffx-hooks.log`) 那段繞道本身`B0-resolve` 已捕獲 — 關閉錯誤 #1 的因果鏈。** 證據：`B0 resolve a1=2 a2=1 treeId=43 a4=1 ->-1` (在`ringKind=1` **E**`ringKind=12`) 與`P0 dispatch charge=100 max=100 590=0x0D` (強制啟用 OD-ready：該鉤子已設定 0x590 位元，`79AF70` 返回 1，`6C8`，以及皮納`max:=charge`) — **而 OD 仍處於隱藏狀態。** ⇒ **OD-ready/charge==max 並非觸發條件**（結束 hudSafe 17–24）。此外：`blob2=0x1B5C8D70` = **活堆** 指標（而非`system_00` 離線空值）→ gate 是 blob 的 **索引**，屬於執行時資料。 **結構性突破（符號運算，無執行時資料）：**`dword_1134564[N] ≡ unk_C8F8D0[N+1217317]` (`(0x1134564−0xC8F8D0)/4=1217317` 正確) ⇒`dword_1134564[0]` (請注意，該`Resolve` （讀作）**正是**該計數器，該`PushMenuTreeEntry(797B80)` 增加，並`dword_1134564[2*v8+1537]` **這是**被推送的輸入 → **Push 會精確地將資料傳入`ResolveMenuTreeNode(797D60)`**;`case 2 subtype=1` →`unk_112A994[8]=0x112A9B4=blob2`. **隨後`−1` 將……減少至`WalkMenuBlobIndex(blob2,43)==0`** ⇒`blob2[2+43]==0xFF` (t

reeId 43 未註冊）**或**`43>=blob2[1]` (count≤43)。由於 kind=1 (sel=1) 且 kind=12 (sel=12) 兩者皆為 −1，因此是 **主閘極**（而非次級選擇器）。**`79BB70` (`BuildActorCommandMenu`) 已反編譯並從 gate 寫入器中移除**：它僅組建 **環形緩衝區層-A** (`ringBase+1144*slot+catOffset`, 路由`byte24` 1→+120/2→+72/3→+168/4→+296/0xE→+232；標頭`dword28` &0x1000→+40/&0x800→+56/否則→+0)，**不會**寫入解析結果的 blob，也不會`actor+0xF7C`. **尚缺 1 次測量** (`blob2[1]` count +`blob2[2+43]` idx) — 我已將 **DIAG 現成修補程式（≤6 行，唯讀）** 準備好，可直接貼入 shim 中`B0-resolve` 在該文件的第12.4節中，3位固定音高候選者已調校完畢（B=寫下`blob2[2+43]`, C=重定向至路徑`a2=0` 如同 Aeons 一樣（A=合成節點），由 **1 RT2** 的資料傾印所決定。 **評論`.i64` （黃金法則，保留）：**`0x797D60`/`0x797B80`/`0x797420`/`0x7985A0`/`0x112A9B4`. 文件：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §12. [前文：`v2.128.0.0`]
- **`v2.128.0.0` — Arena+ Multi Dark Aeon 自訂代幣解析器 REDIRECT（spike 的選項 A）。** 通道 **Jarvis-ARENA**。 **次要**（DLL 新增功能：唯讀模式的 spike 已新增文件中所述的 redirect 路徑）`FFX_ARENA_PLUS_CUSTOM_TOKEN_RESOLVER_HOOK_SPIKE.md`). **該 hook`ResolverLogHook` 目前有 2 種模式：** (a) LOGGER — 先前行為，預設模式；(b) REDIRECT — 透過`arena_plus_custom_token_resolver.flag` (env:`FFXHOOKS_ENABLE_ARENA_PLUS_CUSTOM_TOKEN_RESOLVER`). 在重定向模式下，在呼叫原生 trampoline 之前，shim 會查詢一張表格`customToken -> aliasToken` (必填範圍 HIWORD`0xA001..0xAFFF`); 若有匹配，該標記將被替換為別名 vanilla，使解析器返回一個`row` 合法。下游無法與普通代幣區分；撤銷 = 移除標記或 DLL。**標頭中的新 API`hooks/ResolverLogHook.h`:**`SetCustomTokenRedirects(table, count)` (第 32 章，有效範圍)，`SetCustomTokenRedirectEnabled(bool)`,`IsCustomTokenRedirectEnabled()`,`ResolverRedirectHitCount()`. **新款側車`mods/Spira Reforge/arena/spira-arena-custom-tokens.{json,schema.json}`** 已填入 4 筆資料（雙字節 `0xA0010

046->0x00DC0046`, trio `0xA0020046→0x00DC0046`, quartet `0xA0030046→0x01AE0046`, penta `0xA0040046→0x01AE0046`). **Carregamento no boot via `ArenaPlus_LoadCustomTokenRedirects()` em `dllmain.cpp`** — busca em `$FFXHOOKS_ARENAPLUS_CUSTOM_TOKENS_PATH` -> `<DllDir>/mods/Spira Reforge/arena/spira-arena-custom-tokens.json` -> `<DllDir>/spira-arena-custom-tokens.json`; falha em I/O ou parse mantem o hook em modo logger (zero regressao). Build PolyHook PASS 11/11 cpp. RT2 in-game **Precisa Testar** (espera ate o launcher gerar token custom; ainda nao foi conectado em UI). [anterior: `v2.127.0.0`]
- **`v2.127.0.0` — Capture Cascade Cap-1 Phase C：1 位元組的寫入器，來自`capturable` (`MonsterCaptureFlagWriter`) + 閘門`--monster-capture-bit-rt0` vanilla 語料庫中的 PASS 361/361。** Lane **Jarvis-CAPCAS-WRITE**。**MINOR**（新功能：該特徵的首個寫入器）`Capture Cascade` /`Yoke of Spira`；資料庫 + 閘道，目前仍無使用者介面）。實現 Cap-1 計畫的 C 階段（B 階段`v2.123.3.1` 定位到該位元組；C 階段會寫入該位元組）。**Writer (`FFXProjectEditor/FfxLib/Monster/MonsterCaptureFlagWriter.cs`):** 位元組層級（不含`Monster_File.Read(...).Write()` 完整結構體)，直接在`bytes[StatSheetPointer + 0x78]` 與`StatSheetPointer = uint32_le(bytes[0x0C])`. API：`TryGetStatSheetPointer`,`GetCaptureFlagFileOffset`,`ReadCaptureFlag`,`ReadPaddingByte`,`WriteCaptureFlag(monBin, newSlot)` (複製陣列、翻轉位元組、保留填充位元組)`0x00`, 拒絕將填充值不為零的怪物視為未知變體）；輔助函式`IsUncapturable`/`IsVanillaArenaSlot`/`IsSidecarArenaSlot`. 常數`Uncapturable = 0xFF`,`VanillaArenaSlotMin/Max = 0x00..0x67`,`SidecarArenaSlotMin/Max = 0x68..0xFE` (vanilla MA = 104 槽位，sidecar = 不會與怪物圖鑑發生衝突的 Capture Cascade 區域)。**Gate (`FFXProjectEditor/Tools/MonsterCaptureFlagRt0.cs`):** 透過以下方式呼叫`FFXProjectEditor.exe --monster-capture-bit-rt0 [monsterRoot]`，證明每個怪物具有以下 3 項特性：(1) **同值位元組身分** —`WriteCaptureFlag(bin, current)` ==`bin` (當 newSlot==current 時，writer 為無操作)； (2) **僅槽差異** —`WriteCaptureFlag(bin, target)` 有別於`bin` 在 **精確地 1 位元組** 的位置，位於 `[StatSheetPointer +

 0x78]`, com padding `0x00`, todos os outros bytes byte-identical; (3) **flip-and-restore RT0** — `WriteCaptureFlag(WriteCaptureFlag(bin, target), original)` == `bin` (idempotência completa). Target é escolhido fora-da-banda por categoria: uncap (0xFF) → flip pra 0x68 (sidecar), vanilla MA → flip pra 0xFF, etc. **Resultado contra `D:\FFX Extracted\...\jppc\battle\mon` (vanilla):** **VERDICT PASS — 361/361 monstros**, 251 uncap (0xFF), 110 vanilla MA slot, 0 sidecar, 0 padding non-zero, header parse 361/361, same-value RT0 361/361, slot-only diff 361/361, flip-and-restore RT0 361/361. **Excede 6× as 58 amostras do spike Phase B.** Plugado no `RuntimeTools/offline_ci.ps1` `$editorGates` (entre `怪物` e `相遇`) — fica como gate interno permanente. Arquivos novos: `FfxLib/Monster/MonsterCaptureFlagWriter.cs`, `Tools/MonsterCaptureFlagRt0.cs`. Tocados: `Program.cs` (wire `--monster-capture-bit-rt0`), `RuntimeTools/offline_ci.ps1` (`$editorGates`). **NÃO toca:** `m###.bin` (gate read-only — só lê arquivos vanilla, nunca escreve no disco), DLL, runtime, save, hook. Build C# Release PASS (0 erros, 384 warnings baseline). UI Phase C **não** pluggada nesta entrega — ainda biblioteca + gate, sem botão público. **Próximo passo seguro:** Phase D (UI checkbox `可擷取的` no `MonEditor` + bulk writer pra Dark Aeons + Penance) ou RT2 in-game manual (Halyson edita 1 monstro descartável `0xFF→0x68` em `m###.bin` real, salva, abre o jogo, captura o monstro pra ver se o engine aceita slot fora do range vanilla 0x00..0x67). Doc: `docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_RESULT_2026-06-16.md` §5.1. [anterior: `v2.126.0.0`]
- **`v2.126.0.0` — Arena+ Multi Dark Aeon 目錄驗證器 命令列介面 (`--validate`).** Lane **Jarvis-ARENA**. **MINOR**（新容量為`RuntimeTools/ArenaMultiBossLab`：首個 v2 目錄離線驗證器）。新功能`RuntimeTools/ArenaMultiBossLab/CatalogValidator.cs` + 標記`--validate [--catalog <path>] [--vanilla-root <btlRoot>]` 在`Program.cs`. 從以下 5 個方面進行檢查：(1)`format/format_version`; (2) 每行必填欄位 (`token_mode`,`battle_token`,`base_template`,`battle_id`,`raw_monster_ids`,`gil_cost`,`progress_flag`, `

rt2_status`, `風險`, `證據`); (3) consistencia de `unlock_requires` (cada flag deve aparecer como `progress_flag` em outra row, incluindo tier-level `unlock.requires`); (4) regex `0xXXXXXXXX` em `battle_token`, `0xXXXX` per slot em `raw_monster_ids` + anti-gap (slot vazio antes de slot ocupado = ERRO); (5) `食譜` aponta pra arquivo existente. **Sweep opcional de recipes** via subprocess do mesmo CLI com `--dry-run` quando `--vanilla-root` for fornecido (re-roda todas as recipes em `./食譜` automaticamente). Exit codes: 0 OK, 4 catalog inconsistente, 5 recipe dry-run failou. Run atual contra `spira-arena-catalog.json`: **PASS 0 erros / 0 warnings em 13 rows / 13 flags distintas**. [anterior: `v2.125.1.1`]
- **`v2.125.1.1` — Aurora 彈道最終階段第 9 階段結案：對照計畫中 10 個階段的狀態（RT2 待處理清單已完成，離線狀態 100% 結案）。** Lane **Jarvis-AURORA**。 **審查**（僅限文件／結案：`PORT_STATUS.md` +`docs/ai/SESSION_HANDOFF.md` +`KNOWLEDGE_BASE.md` 已進行比對；行為未見任何變化，本次執行過程中未觸及任何寫入程式／探針／DLL）。完成該計畫的循環`.cursor/plans/aurora_balistica.plan.md` （10 個階段，範圍 A+B 已獲 Halyson 批准）。**本系列中已完成之階段（Jarvis-AURORA，2026-06-16）：** F0 文件核對（REVISION`v2.123.5.1`)，F1 探針`aurora-calib-v2` MINOR (`v2.125.0.0`), F3 離線拖曳預覽差異 PATCH (`v2.125.1.0`). **先前工作已涵蓋的階段（於結案時發現，此系列中無新進展）：** F5 關卡`camera-chunk0-edit-rt0` 離線功能已由`BattleCameraScanLab` (`offline_ci.ps1` C08`BattleCameraScanLab` 已包含`polar eye round-trip` +`setup FLOAT edit round-trip` +`edit byte-local + reversible` 在所有 chunk0 的 bin 檔案中（包含相機設定）。F6 PhotoMode 接線在`FfxHooksDll` 已滿額 (`PhotoMode::Tick()` 在 Present hook 中更新演員後被呼叫，位於`dllmain.cpp:4622`,`PhotoMode::g_base/g_pm` 已定義`dllmain.cpp:6060`, 橋`NativeMenu_OnEdge`/`NativeMenu_OnHeldEnter` 記錄於`StartNativeMenuIfEnabled` `dllmain.cpp:8884`,`PhotoMode::Exit()` 在`StopNativeMenu` `dllmain.cpp:8910` — 遊戲內僅缺少 RT2）。F7 突發 ID

W2S 已彙總為 3 層深度的文件（`FFX_AURORA_W2S_MATRIX_OWNER_IDA_DEEP_2026-06-15.md`,`FFX_AURORA_W2S_MATRIX_IDA_CHAIN_2026-06-15.md`,`FFX_W2S_D3D11_INFERNO_2026-06-15.md`) 其中已明確定義了接受準則與日誌記錄規格；差距在於：從`selected target id/index` 在主使用者介面中（RVA 待處理，且未解鎖本工作階段 MCP idalib 的 IDA 本地資料庫）。F8 突發事件：IDA 變體選擇器已整合至 3 份文件中（`FFX_AURORA_ARENA_VARIANT_IDA_DEEP_2026-06-15.md`,`FFX_AURORA_ARENA_VARIANT_SELECTION_RE_2026-06-15.md`,`FFX_ARENA_VARIANT_RUNTIME_INFERNO_2026-06-15.md`); 徽章`runtime selector UNVERIFIED` 植入於 UI 的`AuroraChamber` 在 F0。**人類角色中被鎖定的階段（Halyson、遊戲內 RT2）：** F2 RT2 calib-v2 在 4 場黃金戰役中（`425/0/0`,`azit03_00`,`bsil`,`klyt00_00`) + 根據面積／高度分析殘留物 Y — 完整配方請見`docs/reverse/FFX_AURORA_FORCE_BATTLE_CALIBRATION_PROTOCOL_2026-06-15.md`; F3 (RT2) 僅拖曳位置 — 參見 §B 中的說明`FFX_AURORA_MASTER_RT2_CHECKLIST_2026-06-15.md`; F4 RT2 正常生長（非黑暗）Aeon（生成 + AI + 戰鬥結束 + 清理）；F5 RT2 極性編輯；F6 RT2 最低 PhotoMode。**傳奇篇結束後的狀態（PORT_STATUS 已同步）：** 極光之室`parcial → parcial+++` (X/Z 身分已由 IDA 驗證，Y 殘餘值 RT2 待處理，變體上標示為 UNVERIFIED)，`aurora-calib-v2` `validado offline / RT2 pendente`, 拖曳覆蓋層`validado offline / RT2 pendente`, BattleCameraScanLab`validado offline (gate C08 = 1 dos 29)`, PhotoMode 接線`validado offline / RT2 pendente`, W2S 負責人`partial / blocked / acceptance criteria definidos`, 變體選擇器執行階段`partial / inferred / blocked sem IDA db destravado`. **不涉及：** 程式設計師、探針、DLL、建置、套件 — 整個專案僅涉及文件編寫，加上 2 項小幅更新（探針控制 + 介面覆蓋層），這些更新已分別在各自的修訂版本中發布。 **下一步（移交給 Halyson）：** 執行預先組建的 RT2 佇列（5 個活躍的 RT2 + 1 個已解鎖的 IDA 尖峰測試）—— 首先執行 F2 calib-v2（`ffxprobectl aurora-calib-v2 --route 425 0 0` 在「大戰」中），接著依體力狀況按 F3/F4/F5/F6。[上一頁：`v2.125.1.0`]
- **`v2.125.1.0` — 「Aurora」彈道測試第三階段（離線）：阻力預估

在疊加視圖中檢視差異（舊版／新版／Δ）。** Lane **Jarvis-AURORA**。**PATCH**（針對現有拖曳模式的波蘭語使用者體驗優化）`aurora-overlay.js`；沒有新增功能，沒有新寫入器，僅在「僅拖曳位置」的 RT2 之前改善了讀取效果）。 實作「Aurora」計畫第三階段的 **離線** 部分——RT2（在真實戰鬥中移動小型怪物、儲存、強制戰鬥、截圖、還原）仍 **卡在人類階段**（Halyson）。**三項變更於`RuntimeTools/FFXMapViewerWeb/aurora-overlay.js`:** (1)`onPointerDown` 現在擷取原始的座標`rawAnchors` 在開始拖曳時（穿越`userData.role/index`)，並儲存至`overlayState.dragging.original = {x,y,z}`. (2)`onPointerMove` setReadout 傳入的參數為`place role[i]:  X 12.34  Y 5.67  Z 8.90` 改為新的三部分格式：`(orig) → (new) Δ=(+1.23, +0.00, -2.45)` — 明確的訊號 (`+`/`-`) 使拖曳的方向顯而易見。(3)`onPointerUp` 現在打電話`setAnchorInfo` 附有持續顯示的摘要` ${role}[${i}]: Δ=... (orig) → (new)` 能保留至下一個事件發生為止——先前，當游標離開面板時，讀數便會消失。**對 Halyson RT2 的優勢：**操作員能在儲存前精確得知每隻怪物被移動了多少距離（`💾 Salvar posicoes`) — 將「X 軸移動 1.2u、Y 軸移動 0u、Z 軸移動 -3.5u」轉換為 RT2 的測試日誌格式。**不處理：** writer (`AuroraDragBridge`/`BattleArenaPositionWriter`), 離線閘道、FfxHooksDll、探測控制台。**Lints：**`ReadLints` 已清理。**下一階段：** 第 4 階段（RT2 正常成長的非黑暗永恆）與第 5 階段（gate camera-chunk0-edit-rt0 離線 + RT2 極性）仍在排隊中。 RT2 第 3 階段 = 卡在人類角色（Halyson）處。[前一階段：`v2.125.0.0`]
- **`v2.125.0.0` — 「奧羅拉」彈道測試第一階段：試驗`aurora-calib-v2` (CSV/JSON，含殘餘身分識別/flipZ/yaw180 + height_0x534)。** Lane **Jarvis-AURORA**。**MINOR**（新功能：新模式的`ffxprobectl` 該程式會產生採用新殘差校準模式的 CSV+JSON 檔案；這是我們首次進行配對`chunk3.monLive` ×`actor+0x3B0` ×`actor+0x534` （在結構化探測中）。實施「奧羅拉」計畫的**第一階段**（`.cursor/plans/aurora_balistica.plan.md`). **所採用的規格：**`docs/reverse/FFX_AURORA_CALIBRATION_PROBE_SPEC_2026-06-15.md` (XZ 身分已驗證 2

026-06-05 IDA；殘差 Y 仍處於 RT2 待處理狀態）。**操作方式：**`ffxprobectl aurora-calib-v2 [--route <field> <group> <formation>] [--battle <id>] [--out <json>] [--csv <csv>] [--max-slots <N>]` (唯讀，除視窗外不包含 MMF 儀表)`Arm(1, ...)` （現有）。**針對每個插槽`monLive` 直到`min(monCount, max-slots=16)`:** le`chunk3.monLive[s]` 在`g_FFX_Battle_AreaChunk + ptr@+0x20 + 16*s` (XYZW)，解決`actor[s] = *0x11334CC + 0xF90*s`, le`actor+0x3B0` (world XYZW)，`actor+0x3C0` (XYZW 快取，可選)，`actor+0x534` (高度浮點數)。計算 3 個殘差：`identity = actor - chunk`,`flipz = actor - (cx,cy,-cz)`,`yaw180 = actor - (-cx,cy,-cz)` 含組件`dx/dy/dz` + RMS（完整版 + 僅限 XZ）。**已接受（與 A01 匹配）：**`identity_rms_xz < 0.5` E`identity_rms * 5 < flipz_rms` E`identity_rms * 5 < yaw180_rms` ->`winner=identity`; 替代方案僅在 rms_alternativa<1.0 時才成立（根據 IDA-proof 分析，此情況極不可能發生 — 會觸發「UNEXPECTED — investigate」警示）；若 actor_array 無效或世界非有限（消失／動畫），則槽位被封鎖 — 此情況`blocked-runtime-state`, 不`fail`. **輸出：** JSON (`work/actor_overlay/aurora_calib_<battle_id>_<utcstamp>.json` 預設) 與`verdict` 合併（`identity-confirmed-live` /`ALERT-non-identity-winner` /`blocked-runtime-state` /`partial`) + 陣列`rows`; 36 欄的並行 CSV 檔案（qpc、battle_id、route field/group/formation、area_chunk_va、actor_array_va、slot、dict_id、chunk_xyzw、actor_xyzw、actor_cache_xyz、 height_0x534, identity/flipz/yaw180_dx/dy/dz/rms, identity_rms_xz, winner, reason)。**Build:**`dotnet build RuntimeTools/FfxDinput8Probe/ctl/Ctl.csproj -c Release` PASS（0 個錯誤，僅有既有的警告 CS8632/CS0219）。**未執行：** probe DLL（`ffx-probe.dll`)，離線閘道，FfxHooksDll。**下一階段：** 使用 Halyson 進行 RT2 calib-v2，於 4 場黃金戰役中（`azit03_00`,`bsil05`,`klyt00_00` + 一個控制項，例如`425/0/0`) — 食譜在`docs/reverse/FFX_AURORA_FORCE_BATTLE_CALIBRATION_PROTOCOL_2026-06-15.md`. RT2 第一階段 = 不適用（僅限探針組建）；RT2 第二階段 = 在人類身上受阻（Halyson）。[先前：`v2.124.0.2`]
- **`v2.124.0.2` — Build+deploy 來自`ffx-hooks.dll` (已釋放的 DLL)：實作與固定選單綁定的

 Nul Ward + 武器標記 Nul Ward 及 RT2 的物品堆疊上限；離線預檢結果為 GREEN。** 線路 **Jarvis-MAGIC**。 **審查**（運作層面：已版本化的程式碼重新建置與部署，以及旗標建立；本次無任何新原始碼行為 — 菜單綁定問題的修正來自`v2.123.4.0`，編輯器的 LearnedMove 編碼來自其自身的條目）。Halyson 已釋出該 DLL（Ronso Mana 已停止使用它）。待辦事項：(1)`build_hooks.ps1 -WithPolyHook -Release` → 已編譯 10/10 個鉤子，**包括`NulWardTeachHook.cpp`** 使用多站點修復程式 (`cmp r32,140h`/`cmp eax,140h`→322，修補所有網站，包括 PLACEMENT 迴圈`81 FF`=edi) 先前僅以程式碼形式存在；(2) 透過`install_to_modules.ps1 -EnableApply -EnableTeach` — 先前 DLL 的備份（`ffx-hooks.dll.backup-nul-ward-20260616-071450`)，新的 SHA 前綴`95E1D56A8B9269F7`, 旗幟`nul_ward.flag`+`nul_ward_apply.flag`+`nul_ward_teach.flag`+`nul_ward_teach_grant.flag`; (3) **應另一條車道的請求**，設立`modules/item_stack_cap_255.flag` (空) → 裝填`ItemStackCapHook` (堆疊上限 99→255；由另一條路徑撰寫的鉤子，已編譯至共用 DLL 中，預設值`FFX_ITEM_STACK_CAP_EXTENDED`=255)。閘門`--nul-ward-static` 目前 **評定結果：通過** (exe 位元組 + 322 行 +`engine_lookup_resolves` Radiant@`0x7814`/Umbral@`0x7874` inRange + DLL 字串 + 部署標誌 + 新增清除功能）。**RT2 遊戲內版本已釋出**（Nul Ward：施放 320/321 非攻擊型法術已在離線環境驗證成功，尚待在白色選單中顯示 + 網格教學 + 效果持久化； 物品堆疊上限：文件第 8 節的 6 種情境 — 堆疊 100 瓶藥水、Steal/Drop/Mix/Shop/Treasure，回歸測試標誌關閉）。文件：`FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16`,`FFX_ITEM_STACK_CAP_99_RESEARCH_2026-06-16` §8. [前文：`v2.124.0.1`]
- **`v2.124.0.1` — 羅恩索·馬納（上週五 RE）："滿格"理論已不成立 — 真正的關鍵在於解決選單樹的結點（`ResolveMenuTreeNode`)，請勿進行估算。** Lane **Jarvis-MAGIC**。**修訂**（文件審閱 + 重新命名/註解於`.i64` 真實；**完全**沒有行為上的改變，**DLL 未被修改** — 另一間房間可以使用它）。**RT2 的`hudSafe=24` (v2.123.4.1) 發生錯誤，且日誌顯示整個儀表列（hudSafe 23/24）為何出錯：** `

P0 調度 #1..#48 電荷=100 最大值=100` em **TODOS os 48 frames** (o pino persistente funcionou, a barra ficou genuinamente cheia todo frame) + bits `0x590=0x0D` + `IsOdReady ->1` (até `vanilla=1`) + `311A` no anel — **e o OD continuou oculto / "esquerda" bloqueada**. ⇒ **`charge==max` NÃO é o gate.** (Bônus: o log inunda `警告：在指令 0-49 中未找到 OD ring 標頭` — `ScanForOdRingHeader` procura no range errado; o header de OD é cmd**282**.) **O gate REAL (provado por decompile idalib):** `FFX_Btl_UI_BuildCommandRing@0x7ACEC0` constrói o anel **principal** (Attack/Skill/Special) via `FFX_Btl_UI_BuildMainCommandRingTree@0x7A07D0` **só quando `kind<=8`**; o anel **Overdrive é `kind=12`** → **PULA `7A07D0`** e depende 100% de `ResolveMenuTreeNode(2,1,slot+41)>=0` (só então `sub_7979E0` finaliza). Para Kimahri (slot 2) = `Resolve(2,1,43)`, que retorna **−1**. A causa exata está em `FFX_Btl_UI_WalkMenuBlobIndex@0x797420`: `idx=blob[2+treeId]; cnt=blob[1]; if(idx==0xFF || treeId>=cnt) return 0` → `LookupMenuBlob=0` → `解＝−1` → anel OD nunca exibe. **Mapeamento das duas vias:** principal=`Resolve(2,**0**,slot+109)` no blob `g_FFX_MenuTreeBlob_MainRing` (`*0x112A994`) — resolve OK (user vê); OD=`Resolve(2,**1**,slot+41)` no blob `g_FFX_MenuTreeBlob_OdRing` (`*0x112A9B4`) — Kimahri testa `blob[45]`. **Ambos blobs são DADO ESTÁTICO do recurso `system_01`** (via `FFX_Btl_UI_InitMenuBlobPointers@0x783ED0`: `blob = 基數 + *(基數+N)`), idênticos com/sem OD → `blob[2+treeId]` é **índice de nó, não bool** (por isso o `hudSafe=19` errou a semântica). **Nada disso lê `0x5BC`/`0x5BD` (charge/max).** **Renames+comentários `.i64` aplicados e salvos (REGRA DE OURO):** `0x112A9B4`→`g_FFX_MenuTreeBlob_OdRing`, `0x112A994`→`g_FFX_MenuTreeBlob_MainRing`, `0x112A9A8`→`g_FFX_MenuBlobBase_system01` + comentários em `0x797420`(fórmula do gate), `0x7985A0`, `0x7ACEC0`, `0x7A07D0`, `0x783ED0`. **EXPERIMENTO DECISIVO (próximo, precisa de 1 sessão DLL):** DIAG no detour de `ResolveMenuTreeNode` quando `a1==2&&a2==1` logando `treeId`, `blobPtr=*0x112A9B4`, `cnt=blob[1]`, ``idx=blob[2+treeId]`，vanilla 的回報 — 在 **2 種情境** 下（經證實的 OD 滿載儲存-編輯 vs 我們的強制情境）以及 **d

區分這些`idx`/`cnt`** → 顯示固定值的確切數值（輸入`blob[45]` 有效，或重新導向 treeId，或填入`case 3` 每台設備`actor+0xF7C`). **建議：** 將的量規銷恢復原狀／消除其作用`hudSafe=24` （這不是正確的方法），僅保留`gateMin/drainCost` （用量已確認無誤）。文件：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §11. [前文：`v2.124.0.0`]
- **`v2.124.0.0` — 物品堆疊上限 99→255：新增`ItemStackCapHook` 在`FfxHooksDll` （新功能，由旗標觸發）。** Lane **Jarvis-MAGIC**。**MINOR**（新功能：運行時新增 hook + 類似寫入器的修補程式，可解除棧容量限制，使其超越原生極限；這是我們首次實作此功能）`FFX_Inventory_AddItem`). **這項發現（經由 idalib MCP 在`FFX_recon.i64` (2026-06-16)：**每個插槽限99項，且**中央**夾具在單一功能中`FFX.exe` —`FFX_Inventory_AddItem`@`0x003905A0` (IDA 公寓`0x7905A0`) — 共有 **兩`push 63h`** 傳入通用輔助函式參數 **`FFX_Math_ClampInt(v, 0, 99)`@`0x0039A0D0`. 這 14 個呼叫器（steal/drop/mix/shop/treasure/event/menu）**全部**都透過這個單一函數進行處理——其他路徑中並未出現 clamp 的複製貼上。**載入時不進行歸一化**（已於`FFX_Btl_PrepareSaveCommandState`@`0x786BC0`：僅初始化空的槽位，不會對現有的計數提出異議）。儲存空間（1 位元組在`QuantityBase+slot` 在「儲存 +」中`byte[112]` 在 RAM 中`0xD30B5C`) 現已支援 0..255，無需重新分配。**選用的策略：** byte-narrow 修補程式無法達到 255（push imm8`6A FF` 原本應為 -1 的符號延伸 → **透過 trampoline + stub 進行 5 位元組的繞道**（如同範本`NovaSuperDamageHook`). 每個存根：`push imm32 <cap>` 取代`push 63h`, 重播偏移的 2..3 位元組，並透過`jmp rel32` 為了`0x00390622`/`0x00390652`. 可透過以下方式設定 Cap：`FFXHOOKS_ITEM_STACK_CAP` env（預設值 255，限制範圍 1..255）。**閘控：**`item_stack_cap_255.flag` （預設為關閉 = 保留原始行為，進行自然回歸測試）。**修補程式套用前已驗證的哨兵位元組：**`kExpectedNew[5] = {6A 63 6A 00 53}` (網站 #1 / 新增欄位) 以及`kExpectedExist[5] = {6A 63 8D 04 1E}` (網站 #2 / 現有槽位)。若第二次寫入失敗，則自動回滾

 （不要讓它處於半安裝狀態）。PolyHook 編譯通過（11/11 個 C++ 檔案，包含新的`ItemStackCapHook.cpp`)，已部署的 DLL Release 版本 (`932352→935936 bytes`, 新掛鉤的 +3584)。重新命名與註解`.i64` 適用規則（IDA黃金法則）：`0x7905A0`→`FFX_Inventory_AddItem`,`0x79A0D0`→`FFX_Math_ClampInt`,`0x790500`→`FFX_Inventory_GetItemCount`,`0x784A90`→`FFX_Inventory_DebugMaxAll`,`g_CmdAggregateAvailArrays`→`g_FFX_InventoryAggregate`, 留言請至`0x79061D`/`0x79064D` （使用 trampoline 配方製作的 clamp sites）。**UI 判定（來自 spike）：**`safe-above-99-provavel` (getter 返回原始位元組，未重新限制範圍；視覺風險 = 2 位數的佈局在「100」以上可能發生溢出，但格式化器`%d` 可接受 3 位數且不會當機）。**第 3 階段 UI 修補程式未主動套用** — RT2 已確認。 **Phase 4 RT2 包含 6 種情境**（存檔編輯 Quantity=200、偷取/掉落、商店購買、混合、使用藥水、UI 渲染）於`docs/reverse/FFX_ITEM_STACK_CAP_99_RESEARCH_2026-06-16.md` §8. RT2 遊戲內 **需測試**（Halyson）。文件：`docs/reverse/FFX_ITEM_STACK_CAP_99_RESEARCH_2026-06-16.md`. 新增檔案：`RuntimeTools/FfxHooksDll/hooks/ItemStackCapHook.{h,cpp}`. 播放過的檔案：`shared/ffx_addresses.h` (10 個新的 RVAs+常數)，`dllmain.cpp` (包含 + 旗標啟用程式 + InstallItemStackCapHook 在`InstallHooks` + RemoveItemStackCapHook)，`FfxHooksDll.vcxproj`,`build_hooks.ps1`. [上一頁：`v2.123.5.1`]
- **`v2.123.5.1` — Aurora 彈道分析收尾：第 0 階段啟動（文件核對 + 歷史註解 + UNVERIFIED 標籤變體）。** Lane **Jarvis-AURORA**。 **審查**（文件 + RE/誠信註解；無新功能；未調整結構行為）。整合方案於`.cursor/plans/aurora_balistica.plan.md` (10 個階段，Halyson 已確認範圍 A+B：5 個活躍的 RT2 + IDA W2S 突變 + IDA 變體選擇器)。**此版本僅發布第 0 階段**（探針實作前的文件整合）。 **四項變更：** (1)`PORT_STATUS.md` 「Aurora Chamber」系列 — **誠實**一詞已修正：原本是`transform battle→mundo e DESIGN/UNCALIBRATED (...) flip-Z e hipotese`, 現已反映 2026-06-05 的 IDA-proof（`X/Z = identity`,`Y residual RT2 pendente`, 參照 `FFX_AURORA_BATTLE_

TO_SCENE_TRANSFORM_IDA_PROVEN_2026-06-05.md` + `FFX_AURORA_MASTER_RT2_CHECKLIST_2026-06-15.md` A01/A04/A10). (2) `PORT_STATUS.md` topo — novo bloco `更新 2026-06-16（奧羅拉彈道計算完成）` resumindo estado real Aurora reconciliado contra A15 + ordem RT2 confirmada (`azit03_00 → klyt00_00 → drag → grow → camera → photo`, depois spike IDA). (3) `RuntimeTools/FFXMapViewerWeb/aurora-overlay.js` — comentario JSDoc do header (linhas 9-10) corrigido: era `RAW 戰鬥模式 — 僅限設計／未校準`, agora `X/Z 方向的 IDA 驗證身分；各區域/模型高度的 Y 殘差 (actor+0x534) RT2 待處理；翻轉 Z 軸僅用於比較/除錯`. (4) `FFXProjectEditor/Modules/AuroraChamber/AuroraChamber_DataModel.cs` — `variantNote` (mostrado em `場景詳情` quando `_resolver.ResolveScenes(MapKey)` retorna mais de 1 variante) agora exibe `· 執行時選擇器 未經驗證` ao lado dos `_a/_b/_c`, pra deixar claro que o Chamber renderiza qualquer variante que o catalogo escolha enquanto o selector real (story-flag → variante) ainda nao foi provado por RE — ver A04 `FFX_AURORA_ARENA_VARIANT_SELECTION_RE_2026-06-15.md`. **Nao toca:** probe, writers, gates offline, FfxHooksDll. **Proximo (Fase 1):** implementar `aurora-calib-v2` no `RuntimeTools/FfxDinput8Probe/ctl/Program.cs` com saida CSV/JSON (residual `identity_dx/dy/dz/rms`, `flipz_*`, `yaw180_*`, `贏家` enum, `height_0x534`, route + battle id) — spec em `docs/reverse/FFX_AURORA_CALIBRATION_PROBE_SPEC_2026-06-15.md`. RT2 da Fase 0: nao se aplica (doc-only + UI string). [anterior: `v2.123.5.0`]
- **`v2.123.5.0` — 零區網格教學：範圍為`command.bin` 已驗證（無 exe 修補檔）＋編輯器中 LearnedMove 編碼修正 ＋ 離線驗證器。** 通道 **Jarvis-MAGIC**。**修補檔**（修正 SphereGridExplorer 編輯器中的行為錯誤 ＋ 新的離線驗證／驗證器 ＋ RE）。 **未修改的 DLL**（Ronso Mana 正在使用此版本）— 僅限 C#/編輯器/IDA。**RT2 #1 風險已於離線環境中消除：** RE 證實`FFX_Kernel_LoadFileToTable`@`0x781E00` (案例 0`"command"`) 載入`command.bin` **逐字** 存入全域指標 (`g_CommandKernelTable`@`0x112A92C`,`memcpy` （整個檔案）— **不進行範圍彙總**。`FFX_Table_GetEntryBy

IdRange`@`0x7AB890` lê o header de range **direto dos bytes do arquivo**, mapeando exatamente no `EntryListFile`: `numRanges=int16@0`(=Signature=1), `lo=PreviousFileCount@8`(=0), `hi=(EntryCount-1)@10`, `stride=EntrySize@12`(0x60), `base=EntryTableFileOffset@16`(0x14); `record = file + 0x14 + id*0x60`. Como o `command.bin` crescido grava `EntryCount-1=321`, ids 320/321 ∈ [0,321] → resolvem **exatamente** pras linhas Radiant/Umbral appendadas. **Sem patch de exe/DLL.** **Novo `CommandKernelLookupVerifier` (FfxLib/Ability)** replica a matemática exata do engine contra os bytes crescidos e foi ligado no gate `--nul-ward-static` (check `engine_lookup_resolves`: prova offline que GetCommandEntryById(320/321) NÃO cai no fallback cmd0). **FIX no editor (SphereGridExplorer):** o dropdown LearnedMove gravava o id **cru** (`0x0140`), mas o on-disk é o id **encodado** (`0x3000|id`) — provado empiricamente pelo `SphereGridRt2Lab` (Armor Break em `panel.bin` = `0x3012`) e exigido pelo gate `(cmd & 0xFFFFF000)==0x3000` do grant. Agora o dropdown emite `0x3000|id` (Radiant→`0x3140`, Umbral→`0x3141`) e resolve nomes mascarando `& 0xFFF`, então **o usuário pode pôr as wards no sphere grid e elas REALMENTE ensinam** (antes gravava 0x0140 e o grant rejeitava). Renames `.i64`: `0x781E00`→`FFX_Kernel_LoadFileToTable`, `g_CommandKernelTable`/`g_KernelFileSizes`/`g_AAbilityKernelTable`/`g_ItemKernelTable` + comentários provados em `0x781E00`/`0x7AB890`/`0x790AE0` (salvos via `idalib_save`). Builds C# PASS (0 erros). Doc: `docs/reverse/FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16.md` §F/§G. [anterior: `v2.123.4.1`]
- **`v2.123.4.1` — Ronso Mana hudSafe=24：gauge-full 的「持續指示針」（`max:=charge`) — 修復了「在 Overdrive 模式下，若能量條未滿便無法向左移動」的問題。** Lane **Jarvis-MAGIC**。 **修補程式**（修正鉤子執行時行為的錯誤 + RE）。**發現（經日誌 + 反編譯證實）：** FFX 將「可使用的 Overdrive」與 **能量條滿格** 綁定（`charge==max`) 並在 HUD/選單的渲染器中 **逐幀重新檢查** — **在我們的鉤子之外**。該暫時的偽造`hudSafe=23` setava`max:=charge` 在每個彈跳床周圍，但**會恢復`max=255` 緊接著**（`EndK

imahriMaxSpoof`), então o frame em que o anel é desenhado via `max=255` (barra não-cheia) → Overdrive escondido / LEFT bloqueado. **Evidência no log RT2 (`hudSafe=23`):** `G0 選單 charge=100 max=100` (o spoof FUNCIONOU no build) mas o OD continuou sem aparecer; `IsOdReady ... vanilla=1 ->1` (os bits 0x590 estavam setados, até pelo vanilla) e mesmo assim bloqueado. **RE desta passada (idalib MCP):** `79AF70 = (actor[0x590]>>2)&1`, `79AEE0 = (actor[0x590]>>3)&1` — **ambos forçados e =1, NÃO são o gate**; `792AB0` (`FFX_Btl_BattleMenuInputDispatch`) **constrói o anel OD `kind=12`** quando `79AF70` (logo o anel OD existe); `799AD0`/`799D60`/`7996E0`/`799830` são **resolvedores de máscara de alvo**, não o gate de OD-cheio. Conclusão: o gate vivo é a comparação `charge==max` por-frame no render — fora do alcance de um spoof transiente. **Fix:** `ApplyKimahriRuntimePoolMax` agora **fixa `max := charge` de forma PERSISTENTE** enquanto `charge>=gateMin` (a barra lê 100% cheia pra toda checagem por-frame com o menu de comando aberto; o ATB/CTB fica **pausado** durante o input de comando, então **nenhum ganho de OD é perdido**); abaixo do limiar devolve o pool real (255) pra barra reencher rumo a 0–255. O spoof transiente `開始／結束` foi **aposentado** (no-ops); o dispatch shim agora chama o pino persistente. **Tradeoff conhecido (RT2):** a barra lê cheia enquanto o OD está usável; o ganho de OD pode pausar enquanto a carga estiver na faixa usável (revisitar se o RT2 mostrar stall de ganho — escopar o pino só pro menu). Build PolyHook PASS (10/10), deploy apply mode (SHA `B092B4C6`). RT2 **Precisa Testar** (ir pra esquerda + usar Ronso Rage com carga parcial). Doc: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §10. [anterior: `v2.123.4.0`]
- **`v2.123.4.0` — Nul Ward：teach/menu-surface 的重新審核結果 + menu-bound hook 的修正（先前修補了`cmp 320` 錯誤）。** Lane **Jarvis-MAGIC**。**PATCH**（修正行為上的錯誤，位於`NulWardTeachHook` + RE 已通過審核於`.i64` 原始版本；PATCH 版本號遞增 → 版本號歸零；前一個 HEAD`v2.123.3.1` （這是平行車道的「REVISION」）。完整的「RE」查詢（idalib MCP 在`FFX_recon.i64` （實際）來回答是否要教授 Radiant(320)

/Umbral(321) 透過球形網格 +`command.bin` 擴展後以端對端方式運作。**已驗證鏈：** (1)`FFX_GrantCommandToCharacter`@`0x785D10` 將 ID≥96 的路由導向全伺服器範圍的資料庫`g_PartyWideCommandBank`@`0x11307FC` — 16 字元/256 位元 = 識別碼 96..351；Radiant=word14 bit0，Umbral=word14 bit1；(2)`FFX_Btl_BuildActorCommandMenu`@`0x79BB70` 透過將整個資料庫複製到 actor+0x670 來建立 SEED（迴圈在`g_CmdAggregateAvailArrays`@`0x113081C` → 資料庫 = 16 個單字）；（3）`FFX_Btl_IsCommandAvailable`@`0x79AD40` 讀取「actor」一詞`818+id/16` (id320→位元組 0x68C 第 0 位元) — 一致；(4)`FFX_SphereGrid_NodeActivateStateMachine`@`0x8CC300` case21 呼叫 grant(char, node.LearnedMove, 1) → 一個節點，其`LearnedMove=0x3140/0x3141` 教導；(5) 持續透過`FFX_IsCommandLearnedPersistent`@`0x7850E0` 讀取相同的位元。**已發現並修正的錯誤：**`BuildActorCommandMenu` 有 **3**`cmp r32,140h` (二`81 FE`=esi 在聚合迴圈中，一個`81 FF`=在 PLACEMENT 迴圈中編輯（該迴圈會將 ID 插入「白魔法」子選單中）。只有 PLACEMENT 迴圈會控制 320/321 是否出現在選單中；該`NulWardTeachHook` 以前會修補 **第一場** 比賽（`81 FE`（no-op 用於表面化）。已修正：現在會修補 **所有** 的`cmp r32,140h`→`0x142` (重建 PolyHook PASS)。**已記錄的 RT2 風險：** (a)`FFX_Kernel_GetCommandEntryById`@`0x790AE0`→`FFX_Table_GetEntryByIdRange`@`0x7AB890` 這是具有 **cmd 0 備用機制** 的範圍表 —`command.bin` (a) 隨著地圖規模擴大，需要將覆蓋範圍延伸至 320/321（否則 Radiant 會變成 cmd 0）；(b) 持久性取決於地圖的寬度，在 limit/special 模式下`ply_save` 涵蓋第 224/225 位元（第 14 字）。**設計：** id≥96 = 全隊適用（全員皆可學習），非角色專屬（上限為 96 位元）。重新命名與註解已套用至`.i64` real (`FFX_Btl_IsCommandAvailable`,`FFX_Btl_InitPartyWideCommandBank`,`FFX_Btl_PrepareSaveCommandState`,`FFX_Btl_BuildAggregateChildList`,`g_PartyWideCommandBank`,`g_PerCharCmdMenuState`，等等）。文件：`docs/reverse/FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16.md`. [上一頁：`v2.123.3.1`]
- **`v2.123.3.1` — 《Spira Reforge：Capture Cascade Cap-1》 — bit`capturable` 在`m###.bin` 已定位（Phase B spike RE 僅文件）。** 通道 **Jarvis-CAPTURE-RE**。**修訂**（RE/文件，無變更）

與行為；鏈式連結至`v2.123.3.0` 另一條平行分支的次要更新——此版本純屬文件/審查性質，與該次要更新不構成競爭）。Spike Phase B 的`Capture Cascade` 以「僅文件」模式傳送：控制該字節的`capturable=true|false` 在每個`m###.bin` 已逐位元組定位，並透過 **58 個樣本** 進行驗證。**結論：** 位置 =`bytes[StatSheetPointer + 0x78]` (其中`StatSheetPointer = uint32_le(bytes[0x0C])`); 語義 =`0xFF` (`sbyte -1`) 無法捕捉的，`0x00..0x67` 可佔用（原版《怪物競技場》第104張表格中的欄位）；填充`bytes[StatSheetPointer + 0x79]` 總是`0x00`. 交叉證據鏈（a）舊版編輯器 v1.4`FFXmon4.ini` (標籤「Capture index」以 16 位元十六進位數表示，`00FF` = uncap)，(b) struct C#`FfxLib/Monster/Monster_StatSheet.cs` 第49至50行（`[Data] public sbyte ArenaId` +`[Data] public byte ArenaIdPadding`), (c) 當前的 UI 綁定`MonEditor_Control.axaml` 第 466 行（「Capture index (Arena)」），(d) 完整結構佈局（標題`MonsterHeaderFile` 0x40 位元組 + StatSheet 區段 +`Monster_StatSheet` StatBlock 中 ArenaId 位於偏移位置`+0x64` 關於從...開始的StatBlock`section + 0x14` → 檔案相對路徑`+0x78`). 證明：21/21 個可捕獲的目標，其插槽數符合預期（包括與`FFXmon4.ini` 至`m044=0x28`/`m045=0x29`/`m046=0x2A`/`m193=0x55`/`m194=0x56`)，16/16 首領無上限於`0xFF`, 10/10 《Dark Aeons》（`m334..m343`) 在`0xFF`, 3/3 懺悔 (`m344..m346`) 在`0xFF`. **重要運作修正：** 舊有的假設「DA 位於`m106..m113`「是錯的——正確的數字是」`m334..m343` （品嚐於`FfxLib/Dictionaries/Monster_Dictionary.cs` 第 343 至 356 行），其中《Magus Sisters》被列為 3 個獨立條目（`m341/m342/m343`). DOC-ONLY：未在`m###.bin`/DLL/runtime/save/hook 在此會話中。未執行：IDA 對 gatekeeper 的確認`CanCapture()` （PLAN 的第 3 步為可選步驟）；使用標準樹模型進行交叉驗證`D:\FFX Extracted\` （建議採用但非強制 — 58/58 模組已透過 FFXmon4.ini 達到原版預期效果）。神器：`docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_RESULT_2026-06-16.md` (RESULT 包含 Phase C 撰稿人收入的完整文件)，`work/_capture_re_2026-06-16/parse

_capture_offset.ps1` (parser CLI), `work/_capture_re_2026-06-16/dump_arena_id_evidence.ps1` (bulk dump), `work/_capture_re_2026-06-16/capture_re_evidence_summary.json` (58 rows), `work/_capture_re_2026-06-16/capture_re_evidence_hexdump.txt`. PLAN doc original ganhou banner BLOQUEIO RESOLVIDO + IDs DA corrigidos. `PORT_STATUS.md` ganhou row "Capture Cascade Cap-1 — bit `可捕獲的` localizado" como `需要進行遊戲內測試（Phase C 撰稿人）`. Cap-1 writer (Phase C, próxima sessão) escreve **1 byte** por monstro mantendo byte-identity dos 8 fields adjacentes. [anterior: `v2.123.3.0`（並行分支；發布時將在該版本的變更日誌中記錄）]
- **`v2.123.2.0` — Ronso Mana：修復命令環的根本問題 — 環形緩衝區的基址未被解引用（錯誤 #1）。** Lane **Jarvis-MAGIC**。 **修補程式**（修正運行時掛鉤行為錯誤 + RE）。**發現：** 命令環緩衝區是 **在運行時分配的**；其絕對指標位於 BSS 區塊中（`*(u32*)0x2310CD8`). 該`7AEFC0`/`79BB70` 做`mov edi,[célula]` (**DEREF**) 在建立索引之前`+20592` (排序暫存區) /`+1144*slot` （波-阿托環）。該`RonsoManaHook.cpp` 曾使用`RVA_FFX_BATTLE_COMMAND_RING_BSS_BASE=0x1F0FCD8` **原始資料，未經 deref，且還偏移了 0x1000** —— 因此環狀結構中的 **所有** 寫入操作（模板、每個插槽的標頭`+0`, OD 行`+296`) 中的`hudSafe 11..21` 落入了一個靜態的 BSS 區，而該區**從來都不是顯示中的動態緩衝區**。這解釋了為何 BSS 環中的任何寫入操作都從未出現，以及為何該`CopyMenuTemplate_Shim` (繞道至`7AEFC0`) 總是會提前歸還 (`delta = slotPtr - ringBase` 從未是 1144 的倍數）。**修正：** 新增`RVA_FFX_BATTLE_COMMAND_RING_BASE_PTR=0x1F10CD8` （實際的指針單元，取自該指令的 imm32）`mov edi,[..]@0x7AEFC8`) +`BattleCommandRingUiBase()` 現在 **取消引用** 該儲存格（`*(u32*)(g_base+RVA)`（若未分配，則進行空值檢查）。因此，`PatchKimahriCommandRingUi` (+0 標題)，`PatchKimahriMainMenuOverdriveRow` (+296 OD) 以及`CopyMenuTemplate_Shim` (+296 後選) 首次在**真實**環中發文。**RE 已通過（IDA）：**`7AD980` = 按優先級對 1 個陣列進行排序 (`key=*(u8*)(GetCommandEntryById+92)`, scratch=`ring+20592`);`7AEFC0`

 呼叫它 8 次（每類別一次），並按插槽順序排列戒指。重新命名`.i64`:`7AEFC0`→`FFX_Btl_UI_SortCommandRingSlot`,`7AD980`→`FFX_Btl_UI_SortCmdRingArrayByPrio` + 在指針儲存單元中的註解`0x2310CD8`. **DIAG (hudSafe=22)：**`DumpKimahriRingState` 因此，該讀回的`+0`/`+296` 雷亞爾在`G0-finalize` 用於確認編碼後的 OD（0x311A）是否成功傳送。PolyHook 建置通過（10/10），部署至應用模式。RT2 **需測試**（錯誤 #1：OD 位於中間環）。文件：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §9. [前文：`v2.123.1.2`]
- **`v2.123.1.2` — Spira Reforge：Capture Cascade 採用雙重命名規範（內部代號 + 玩家可見名稱）。** Lane **Jarvis-MAGIC**。 **修訂**（設計／文件，不含程式碼）。Halyson 於 2026-06-16 確認：此功能保留 **兩個名稱**，各自扮演不同角色。 **內部**（技術文件、變更紀錄、資料結構欄位、ID、提示字串、Lane 簽名）仍維持 **Capture Cascade**（Cap-1/2/3，`dark_aeons.captured.<id>`,`capture_cascade.patrol_kills`,`arena.dark.<id>`). **玩家可見內容**（彈出視窗、模組 README、模組頁面）= **斯皮拉之軛**（PT） / **Yoke of Spira**（英文）——其中蘊含的耶沃恩／聖經意象（馬太福音 11:30）呼應了《最終幻想 X》原版的神權政治主題。 **F7 成就分頁** = **軛** (PT) / **The Yoke** (EN)。 更新標準彈出視窗字串：PT「貝賽德正處於黑暗瓦爾菲爾的**軛**之下」／EN「Besaid is now under the **yoke** of Dark Valefor」；捕獲時的戰鬥文字 PT「黑暗瓦爾菲爾已被馴服。 斯皮拉為之震顫。」／EN「Dark Valefor has been tamed. 斯皮拉顫抖著。」 擒獲連鎖（Doc Capture Cascade）新增 §0（命名規範表 + 基於 Microsoft Threshold/Redstone 類比的理由）。 VISION_AND_ROADMAP §11 新增包含相互連結的 3 種情境表格。[先前：`v2.123.1.1`]
- **`v2.123.1.1` — Spira Reforge：擷取「Cascade Phase B」交接提示（RE 突增）`capturable` bit)。** Lane **Jarvis-MAGIC**。**REVISION**（交接文件，不含程式碼）。新`docs/ai/PROMPT_JARVIS_CAPTURE_BIT_M_HEADER_RE_SPIKE_2026-06-16.md` — 用於開啟 Capture Cascade B 階段專用聊天室的完整提示。通道識別碼：**Jarvis-CAPTURE-RE**。任務：定位偏移量與位元`capturable` 在的頁首中`m###.bin` 透過十六進位差異比對 (Sinscale ↔ Dark Valefor + 2 個樣本)

（驗證）＋可選 IDA`CanCapture` 交叉核對。交付成果：包含 ≥4 個樣本的表格 + RESULT 文件 + 計畫文件更新 + Cap Cascade 主文件更新 + PORT_STATUS + 自行調整 REVISION 版本號。 未明確列出的目標（不實作寫入器、不涉及執行時、不進行遊戲內擷取）。誠實估計耗時 1.5–2 小時。解鎖 Cap-1（Phase C，v0.5）。[先前：`v2.123.1.0`]
- **`v2.123.1.0` — Ronso Mana：修復 Overdrive 的重新裝填問題（錯誤 #2）＋ 指揮環的第二輪重寫。** Lane **Jarvis-MAGIC**。 **修補程式**（修正鉤子執行時程中的行為錯誤 + 重新審查/文件）。**錯誤 #2（「使用後向左移動時，Ronso Rage 無法釋放」）：**`RonsoManaHook.cpp` 將 OD 的顯示閘門降低至`gateMin=100` (香草「滿條」）供 **40** 人份 (=`kRonsoSkillCosts[0]`, Overdrive Jump 的消耗量）。當 gate 設定為 100 時，經過 1 次部分使用（消耗 40 → 剩餘 60 < 100）後，**所有** 強制功能都會`return` 而 OD 會消失，直到重新填滿至 100 為止——這與 0–255 的部分數值範圍本身相矛盾。逐行灰階處理（`G3`) 仍會阻擋高成本技能（成本 > 當前能量），因此降低門檻是安全的。已修正安裝橫幅`hudSafe=19`→`hudSafe=21` （日誌顯示的版本不正確，妨礙了診斷）。**上上週的 RE（RT2 之後）`hudSafe=20` （失敗）：** 完整反編譯`79BB70`/`79B500`/`7B6BD0`/`79AD40`/`7A07D0`/`797D60` + **離線** 擷取檔`command.bin` 已驗證：(a) 執行時命令列 = **0x14 的標頭 + 檔案結構體**（錨點`byte[25]`=CharacterUser=file+5)，因此`byte[22]`=MenuFlgs 等； (b) **cmd282 (Ronso Rage) 這是環狀結構的 OD 標頭** (`MenuFlgs=0x11`→頁首，`MainMenu=True`,`ODCat=19`,`MenuLeft`) — 原先的讀取值「282→cat4 頁 +296」是**錯誤的**；(c) 在 loop-2 的`79BB70`, 標題為`Misc2 MenuLeft (0x10)` →`dword[28]&0x1000` → 位於 BSS 陣列的 **+40** 處，而非 +0（可見的標頭）——因此，即使強制顯示 282，也不會將其顯示在中間；(d)`resolve=-1` 這是**紅鯡魚**（即使設定為-1，主環仍會出現）；（e）`797D60 case 3` 讀取 **por-ator** 數據塊 (`actor+0xF7C`); (f)`79B500` 做`actor[0x590]=save[+16]` **早些** —— 我們在`RefreshMenu_Shim` (在跳床之前做好準備) 會被此賦值 → exp **覆寫／清除** →

請說明為何複製 save-edit 失敗。重新命名`.i64`:`7B6BD0`→`FFX_Btl_UI_BuildOverdriveTargetList`,`79B500`→`FFX_Btl_RefreshActorMenuState` (+ 留言於`79BB70`/`797D60`/`79B500`). 文件：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §8. 下一步（錯誤 #1）：進行「save-edited」與「forced」擷取的實驗，以比較確切的差異。針對修正 #2 的 RT2 **需進行測試**。[前一項：`v2.123.0.2`]
- **`v2.123.0.2` — 《Spira Reforge：Capture Cascade Phase A》封鎖階段 — 8 項已定案決策 + 3 件預備神器** Lane **Jarvis-MAGIC**。 **修訂**（設計／文件／架構，不含程式碼）。Halyson 於 2026 年 6 月 16 日的規劃會議中，已針對《Capture Cascade》文件第 7 節中尚待決定的 8 項決策達成共識（`v2.122.0.1`): D1 《魔法姐妹》 → **蘑菇岩之路**（非《Gagazet》——《米伊亨行動》的扭曲懷舊感＋3位悲劇性的「信仰」，從遊戲中前期轉變為T7終局內容）； D2 F7 怪物圖鑑 → **專屬分頁 + 戰後彈出視窗**，內含可放置由 DA 擒獲的 **生成藝術（GPT-image）** 的插槽； D3 **無法逃脫**的巡邏；D4 掉落物 = **1× 碎片 + 1× 稀有消耗品**；D5 捕獲 **計為擊殺++**（解鎖 1v1 原版模式及 SIN 天梯）； D6 **無確認提示**；D7 安全區 **由 T7 怪物及 DA 巡邏隊共同遵守**；D8 增益效果 **僅在捕獲後首次進入時公告**。 A 階段會掉落 3 件神器：(a) **側車設計圖**`mods/Spira Reforge/save-schemas/spira-reforge-flags.schema.json` v1（DA 擷取畫面 +`sin_mode.region_overrides` +`conquistas_seen` +`capture_cascade.patrol_kills`/`first_entry_seen` — **已解決衝突** 與 sidecar`spira-arena-progress.json` 出自 Jarvis-ARENA`v2.123.0.0` 用於維持競技場行清除狀態）；(b) **區域地圖**`mods/Spira Reforge/arena/dark-aeon-region-map.json` (8 DA → 標準區域 + patrol_subzones + safe_zones + 敘事備註)；(c) **RE 突發事件應變計畫 B 階段**`docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_PLAN_2026-06-16.md` （1–2 小時的路線，用以尋找該點）`capturable` 在`m###` 透過十六進位差異比對（可選 IDA）處理標頭。更新了 Cap Cascade 主文件 §7（封鎖階段）+ §4（最終地圖）+ §13（參考 artefact）。 VISION_AND_ROADMAP §11 新增「Phase A 產出物」區塊。定義了 4 個階段的計畫（A=鎖定階段完成，B=RE 尖峰討論獨立進行，C=Cap-1 寫入器 v0.5

, D=RT2 試飛員)。[上一頁：`v2.123.0.1`]
- **`v2.123.0.1` — Arena+ Multi Dark Aeon：五倍擴展配方 + 模擬測試通過。** 線路 **Jarvis-ARENA**。** 修訂 **（配方/文件，已發布版本的行為未變更）。計畫第 7 階段（擴展）。新版本`RuntimeTools/ArenaMultiBossLab/recipes/dark_penta_elemental_five.json` + 食譜文件`mods/Spira Reforge/arena/recipes/dark_penta_elemental_five.md` 覆蓋`Dark Valefor + Dark Ifrit + Dark Ixion + Dark Shiva + Dark Bahamut` 在`nagi05_70` （別名：Dark Yojimbo，6 個 vanilla monPos 中的第 5 個，第 5 個插槽無角色）。Pipeline`ArenaMultiBossLab --recipe dark_penta_elemental_five --dry-run` PASS 反對`nagi05_70.bin.spiraforge.bak`: chunk2 = 5 個演員 @ 0x18A4 (16 位元組)，chunk3 = 6 個 monLive @ 0x1B04 (96 位元組，僅位置資訊)，重新讀取以確認時槽。目錄列`dark-penta-elemental-five` 更新：ID 已重新命名，`token_mode` `blocked->alias` （別名，且在技術上屬合法），`evidence` 搭配 dry-run PASS，`rt2_status` 仍然`blocked` （無遊戲內測試）— 僅通過 RT0 位元組安全性驗證。**尚未提升** 至五項功能：仍維持在 RT2 PASS 四項功能階段，並已記錄遊戲內測試嘗試，使用`_RT2_CHECKLIST.md`. MD 配方中的 4 種推廣方案（PASS／被攝影機擋住／被 AI 擋住／因碰撞被擋住）。[上一頁：`v2.123.0.0`]
- **`v2.123.0.0` — Arena+ Multi Dark Aeon 進度 sidecar + FfxHooksDll 中的讀寫功能。** 通道 **Jarvis-ARENA**。 **次要**：(a) 新的 sidecar`mods/Spira Reforge/arena/progress/spira-arena-progress.{json,schema.json}` （第15節檔案的v1版本）附`flags{}` 已結算/首次結算_UTC/最後結算_UTC/結算次數/憑證 +`tier_lock_state{}` 可選（LOCKED/READY/CLEARED）；透過`progress_flag` 目錄中的 (`arena.dark.<slug>`); 包含使用規則及 catalog<->sidecar 對應關係的 README 文件。(b) 新增模組`RuntimeTools/FfxHooksDll/hooks/ArenaProgressSidecar.{h,cpp}` — 盡力而為的 JSON 讀寫器（無依賴項），`ArenaProgress_Initialize/IsRowCleared/RecordCleared` 由……發布`arena_plus_progress.flag` (預設為關閉)，搜尋於`$FFXHOOKS_ARENAPLUS_PROGRESS_PATH` ->`<DllDir>/mods/Spira Reforge/arena/progress/...` -> 備用方案`<DllDir>/spira-arena-progress.json`. 透過 `.tmp` 實現原子級持久化

+ MoveFileEx`. Env `FFXHOOKS_ARENAPLUS_FAKE_CLEAR=flag1,flag2` permite seed manual para teste de UI. (c) `dllmain.cpp` chama `ArenaProgress_Initialize` no `InstallHooks` apos catalog overlay. (d) **Victory detection real ainda nao plugada** — fica como TODO documentado; a Fase 6 do plano admite essa separacao e a API publica `ArenaProgress_RecordCleared(flag, note)` ja esta pronta para receber o consumer quando o hook `battleEnd` existir. Build PolyHook PASS 10/10 cpp. RT2 in-game **Precisa Testar** (via `FFXHOOKS_ARENAPLUS_FAKE_CLEAR`). [anterior: `v2.122.0.1`]
- **`v2.122.0.1` — Spira Reforge：Capture Cascade — 捕獲 Dark Aeon 可喚醒該區域（設計文件 + 路線圖）。** Lane **Jarvis-MAGIC**。**修訂版**（設計/文件，不含程式碼）。 Halyson 2026-06-16 構想：擊殺 DA 即可在 Arena+ F7 中釋放他；使用原版 Capture 武器（66 位元 Capture 標記）**捕獲** DA 並給予致命一擊，將喚醒 DA 的正史區域。 已確定決策：觸發機制=原版「Capture」，遭遇頻率=罕見並伴隨提示音（~5–10%），可逆性=在存檔中為單向；怪物圖鑑「成就」F7，高階掉落，無法逃脫，不計入原版怪物圖鑑的MA值。 分解為 **Cap-1**（彈出視窗 + 附帶標記 + 透過 SIN · DARK AEONS 梯度系統）`unlock_requires: ["dark_aeon.captured.<id>"]` — 適用於已於...發行的 v2 型錄`v2.122.0.0`; v0.5)，**第2章** (`sin_tier_override=7` 在 SIN 執行階段模式下的標準 piggyback 區域；v0.6），**Cap-3**（DA-巡邏`m###` 在自訂陣型中，面對 1–3 隻 T7 怪物時，HP 約減少 30–40%，具體取決於 RE 遭遇編輯器；v0.7+）。DA 地圖→標準區域（8 個入口）＋7 處需應對的衝突點（附緩解機制）＋每層至少 1 次 RT2。文件：`docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_CASCADE_RESEARCH_2026-06-16.md`; 路線圖 §11 + §6 v0.5/v0.6/v0.7 於`mods/Spira Reforge/VISION_AND_ROADMAP.md`. [上一頁：`v2.122.0.0`]
- **`v2.122.0.0` — Arena+ Multi Dark Aeon 目錄 v2 + DLL 讀取器 + 自訂代幣解析器 spike.** Lane **Jarvis-ARENA**. **次要**：(a)`mods/Spira Reforge/arena/spira-arena-catalog.schema.json` 從 v1 演進至 v2，採用`token_mode`/`base_template`/`raw_monster_ids`/`unlock_requires`/`rt2_status`/`risk`/`recipe` 依行； (b)`spira-arena-catalog.json` 包含 5 種模式（單人 9 關卡經典模式 + 雙人 + 三人 + 四人 +

 Penta stretch）；（c）`FfxHooksDll/dllmain.cpp` 贏得了`ArenaPlus_LoadCatalogOverlay()` +`ArenaPlus_GetRoute(int)` accessor：何時`arena_plus_catalog.flag` 已找到 active + JSON，將覆寫各插槽的設定`battleToken`/`battleId`/標籤（預設值為硬編碼`kArenaPlusBossRoutes[9]` 總是因失敗而勝出）；（d）新鉤子`RuntimeTools/FfxHooksDll/hooks/ResolverLogHook.{h,cpp}` — 唯讀 PolyHook 繞道機制在`FFX_Field_ResolveEncounterToken@0x7828B0` 該日誌 (token、result、outField、outGroup、outEntry) 由`arena_plus_resolver_log.flag`; (e) RE 文件`docs/reverse/FFX_ARENA_PLUS_CUSTOM_TOKEN_RESOLVER_HOOK_SPIKE.md` 附註解的反編譯（HIWORD = 欄位鍵，低位元組 LOWORD = 條目鍵，中位元組 = 0），4 個呼叫者，表格佈局`g_EncounterFieldTable@0x112A9C8` +`g_EncounterGroupBlobBase@0x112A9CC`, 規格範圍自訂標記`0xA001..0xAFFF`, 方案 A（預先解決重定向）；(f) 已套用的重命名與註解`.i64` real (`work/reverse/ida/FFX_recon.i64`) — sub_79D1B0/D1E0/D190/D230 已轉為`FFX_Field_*EncounterField*/Group*` （黃金法則）。PolyHook 編譯通過 9/9 cpp。[上一則：`v2.121.0.1`]
- **`v2.121.0.1` — Ronso Mana：修正了指令環的處理流程（因 hudSafe 17/19 出現錯誤）。** Lane **Jarvis-MAGIC**。 **修訂**（RE/文件，行為未變更）。對命令環進行 IDA 重新分析：**可見** 的攻擊/技能/特殊環來自`FFX_Btl_UI_BuildMainCommandRingTree@0x7A07D0` (treeId=`slot+109`，僅`kind<=8`)，而非來自`treeId=slot+41` — 因此`resolve(2,1,43)→-1` 但那枚戒指還是出現了。這枚名為**Overdrive**的戒指是`kind=12` (>8)，跳過`7A07D0` 而且這完全取決於`resolve(2,1,slot+41)`，但會失敗，因為該 blob`unk_112A9B4` 有`blob[2+treeId]==0xFF`. **`blob[2+treeId]` 這是一個節點定義的索引，而非布林值** → 該修補程式`hudSafe=19` 指針位置正確，但數值的語義有誤。錯誤「Ronso Rage 無法釋放」：gate`79AF70` 要求`charge>=100`；在 drain（100→60）後，OD 消失 → 最佳解是將 gate 調低至技能成本最低的點（~40）。重新命名`.i64`:`7A07D0`/`79AF00`(IsAeonMenuSlot 20-27)/`7986B0`/`783ED0` + 評論（blob 格式為`797420`, 陣列`X` 分享於`7985A0` 透過 xref`0x798672`, dr 網站

ain/轉帳`0x78F1E5`). 文件：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md`. （註：`hudSafe=20` — 掃描 OD 環形標頭 + 寫入標頭陣列 — 目前已 **部署，需進行測試**。） [上一則：`v2.121.0.0`]
- **`v2.121.0.0` — Arena+ Multi Dark Aeon 製作路線（ArenaMultiBossLab + 多重別名配方）。** 路線 **Jarvis-ARENA**。 **次要更新**：新的命令列介面（CLI）`RuntimeTools/ArenaMultiBossLab` 以確定性方式套用 JSON 配方 —`chunk2` 來源`FormationSlotWriter` (僅插槽型 RT0) +`chunk3` 來源`BattleArenaPositionWriter` (僅位置型 RT0) 或`BattleArenaGrowWriter` (monLive grow cap 8 actors)，具備 re-read guard 功能並採用 loose-file 部署方式`.spiraforge.bak`. 已啟用的食譜：`dark_duo_valefor_ifrit` (別名`kino00_70`/token`0x00DC0046`). 說明文件 + RT2 檢查清單範本 + 多個別名 README 位於`mods/Spira Reforge/arena/recipes/`. 策略：B（多別名）+ C（並行處理 RE 鉤子）+ 內容優先（在目錄 v2/DLL 讀取器之前先處理雙重 → 三重 → 四重組合）。基礎資料集：`docs/reverse/FFX_ARENA_PLUS_MULTI_DARK_AEON_AUTHORING_DOSSIER_2026-06-16.md`. 計畫：`.cursor/plans/arena_plus_multi_dark_aeon_*.plan.md`. 離線生成的 Duo deploy RT0 通過 (7780 位元組，其中 chunk2 的 16 位元組與 chunk3 的 48 位元組在 monLive 環境下完全相同)；**RT2 遊戲內 需測試**，使用`_RT2_CHECKLIST.md`. [上一頁：`v2.120.7.0`]
- **`v2.120.7.0` — Ronso Mana hudSafe=19：B層 UI 樹狀結構 (797B80/797D60)。** 路線 **Jarvis-MAGIC**。** 修補程式 **：繞道`FFX_Btl_UI_PushMenuTreeEntry` +`FFX_Btl_UI_ResolveMenuTreeNode`; 直接注入`Push(2,1,treeId,1+12)` +`Resolve` +`7979E0` 在`G0-finalize`; 對應案例-4 的日誌大物件`0xD35DF0` + 堆疊深度；`ForceKimahri` 經由 shim。RT2 **需測試**。[上一則：`v2.120.6.0`]
- **`v2.120.6.0` — 修復原始 FSB（seId 低位元組，經 IDA 驗證）。** Lane **Jarvis-MAGIC**。**PATCH**：`FFX_FmodSfx_ResolveSequence@0x70FB60` →`sub_710370` 截斷`seId` 至`u8` 在查詢之前，於`9999_common.txt` (例如：`9066`→key`106`→FSB`#9`, 不是`#85`); 備用方案`seId-9000` 僅當低位位元缺失時；UI 讀取來自`magic_####.dll`; 重新生成之捆綁地圖 (824/1165)。[前一頁：`v2.120.5.1`]
- **`v2.120.5.1` — Ronso Mana hudSafe=17: ho

好 P0`792AB0` (中環外徑)。** Lane **Jarvis-MAGIC**。**PATCH**：繞道`FFX_Btl_BattleMenuInputDispatch` — 清除`+0xDF7`,`+0x590|=0x0C`, force`7ACEC0(1+12)` 若卡住；記錄所有內容`ringKind`; 部署實驗室`-EnableApply`. RT2 **需測試**. [上一則：`v2.120.5.0`]
- **`v2.120.5.0` — 修正原始 Play 錯誤的 FSB（seId−9000，非 magicId）。** Lane **Jarvis-MAGIC**。**PATCH**：FEV 事件金鑰地圖`seId-9000` →`9999_common.txt` → FSB 子串；移除啟發式演算法`magicId` （會發出類似「SIM」被擊中的隨機聲音）；◀▶ 按鈕用於瀏覽子曲目；內建地圖已重新生成。[上一頁：`v2.120.4.0`]
- **`v2.120.3.0` — 完全整合 Battle Audio Tools 編輯器。** Lane **Jarvis-MAGIC**。**PATCH**：生命值探測器 + **驗證音訊工具** 介面；`FfxFsbBankCl_Service` 透過 fsbankexcl 追加實體資料；匯入 fsbankexcl 套件；gate`--audio-tools-health`; 支援 CWD/DLL 的 CLI。[上一項：`v2.120.2.0`]
- **`v2.120.2.0` — fsbankcl 套件 (FMOD FSBankEx 4.44.64)。** Lane **Jarvis-MAGIC**。**PATCH**：`tools/fsbankcl/` 與`fsbankexcl`+DLL；別名`fsbankcl.exe`; 定位器接受`fsbankexcl.exe`. [上一頁：`v2.120.1.0`]
- **`v2.120.1.0` — fsbankcl 套件路徑（匯入 + SDK 偵測）。** Lane **Jarvis-MAGIC**。**PATCH**：`tools/fsbankcl/` 在建置階段；UI **匯入 fsbankcl** / **偵測 fsbankcl (FMOD SDK)**；啟動程序`-InstallFsbankCl`; locator SDK 掃描。二進位檔無法自動下載 — FMOD 安裝後需手動匯入 1 次。[先前：`v2.120.0.0`]
- **`v2.120.0.0` — 附帶戰鬥音效工具套件 + 不同版本。** Lane **Jarvis-MAGIC**。 **次要**：`vgmstream` +`fsbext` 在`tools/` 在 Git 中；複製到`.exe` 在建置中；僅在缺少時顯示 **音訊修復工具** 介面；`tools/AUDIO_TOOLS_LICENSES.md`. [上一頁：`v2.119.0.0`]
- **`v2.119.0.0` — 自訂戰鬥音效第二階段：新增 seId，且不覆蓋原有設定。** 通道 **Jarvis-MAGIC**。 **次要**：`FsbDumpDatAppender` +`Fsb9999SampleAppendWriter` (FSB 子頻道 +1 透過 dump.dat)；`FevLegacySequenceWriter` + 側車`9999_common.txt` row;`CommandSoundPackService.NewSeIdAudio` 三重部署 FEV+FSB+common+DLL；UI 核心指令 **新增 seId 插槽**；閘門`--fsb9999-append-lab`,`--fev9999-sequence-clone-wave9`,`--command-sound-new-seid-pack`; I36 RE 文件;`work/.../wav/` 版面配置

+`cleanup_fsb_audio_scratch.ps1`. RT2 遊戲內 **待定**。[上一則：`v2.118.0.0`]
- **`v2.118.0.0` — 努爾區總體規劃（第1–7時期實驗室堆疊）。** 萊恩 **賈維斯-MAGIC**。**次要**：原生插槽`+0x613/+0x614`, P16 預檢繞道,`NulWardTeachHook` (I20 選單綁定)、RT2 判定解析器、ATEL 行差異比較、`NulWardLab` gate；文件 R01/P14/RT2 矩陣。RT2 遊戲內 **待定**。[上一則：`v2.117.0.2`]
- **`v2.117.0.2` — RE: AbilityCommandLab 簡要選單`--dump-cmds`.** Lane **Jarvis-MAGIC**. **PATCH**：用於轉儲行資料的離線 CLI`command.bin` (ODCat、CostOD、選單標誌)；補充「地獄」目錄 (`8f6ac031`,`v2.116.0.3`). 下一個 ROI 鉤子：`792AB0`. [上一頁：`v2.117.0.1`]
- **`v2.117.0.1` — Flan Flood LAB + MagicDllRt2VerdictCatalog（尚待實作）。** Lane **Jarvis-MAGIC**。**PATCH**：交付`--flameflan-flood-pack` /`--flameflan-flood-recolor`,`MagicDllRt2VerdictCatalog`,`MonsterMagicGrowWriter` 第 249 行`0x60F9`, 熔岩/珊瑚色,`FlanFloodDllPossibleTimingPatch`; RT2 記錄本（32 次嘗試）、Family D 計時方案、Flan Flood 戰術手冊。已完成先前在`v2.114`–`v2.117`. [上一頁：`v2.117.0.0`]
- **`v2.116.0.3` — 地獄菜單 RE + AbilityCommandLab`--dump-cmds`.** Lane **Jarvis-MAGIC**. **PATCH**：目錄`FFX_RONSO_MANA_MENU_DISPLAY_INFERNO` +`FFX_RONSO_MANA_KNOWN_VS_NEW` (A/B 層，錯誤`+0xDF7`, 位元`79AEE0`,`command.bin` ODCat 19/35）；CLI`--dump-cmds` 用於離線匯出行資料`command.bin`; 漂移註記`Camera_*` vs 選單 UI。下一個 ROI 鉤子：`792AB0`. [上一頁：`v2.116.0.2`]
- **`v2.116.0.2` — 語義漂移第二輪：已套用 PARTIAL +`ffx_addresses.h`.** Lane **Jarvis-MAGIC**. **PATCH**：+4 個 IDA 重新命名 (`7985A0/797420` UI blob，`794030` GetActorRecord,`78C330` precheck_structural）；RVAs Ronso/UI 選單位於`ffx_addresses.h`; W2S`593440/5936A0` 文件已被鎖定。總計 **12/12** 次重命名漂移未發生於`.i64`. [上一頁：`v2.116.0.1`]
- **`v2.116.0.1` — 語義漂移審計 S01–S12 已應用於 IDA + BIBLE 修正版。** Lane **Jarvis-MAGIC**。**REVISION**：套件`FFX_RE_SEMANTIC_DRIFT_AUDIT` (12/12，67個符號)；**8次重命名**於`FFX_recon.i64` (UI 選單`797B80/797D60`,`7B2DD0` aggregate, `78

28B0` token, `g_BattlePlayerList`); `AiBibleCatalog` separa `7078` vs `0x7B2DD0`. [anterior: `v2.116.0.0`]
- **`v2.116.0.0` — 能力特效第1級：部隊部署 + 可編輯介面 + FEV 第7波。** 戰線 **Jarvis-MAGIC**。 **次要**：`CommandSoundPackService` +`--command-sound-pack` (預覽/部署/還原，RT2 Fire→Firaga 示範版)；可編輯的 **戰鬥音效** 核心指令（來源選擇器，預覽/預覽/部署/還原）；`MagicDllSoundWriter` 備份／來源修補程式；Magic DLL Browser 的 **Sound (SeSep)** 標籤頁；`--fev9999-corpus-wave7`;`--command-sound-custom-wizard`; I31 IDA 已重新命名；I33 FEV 遊戲內 RT2 文件 **尚待處理**。[先前：`v2.115.0.1`]
- **`v2.115.0.1` — Magic DLLs：藍色 vec4 = 時序風險（RT2 Flan Flood 0718 已確認）。** Lane **Jarvis-MAGIC**。**PATCH**：`Extras → Magic DLLs (FFX)` Value Workbench 將以藍色為主的 vec3/vec4 歸類為`possible timing (cast→hit)` 附有徽章`timing-risk` 以及 Family C/D 通知；Wave4 編輯指引已對齊；文件`FFX_FLAN_FLOOD_DLL_TIMING_RT2_FAIL`,`FFX_MAGIC_DLL_POSSIBLE_TIMING_VEC4_FAMILY_D`. 視覺效果 = phyre PS3，非啟發式 DLL 修補程式。[前一項：`v2.115.0.0`]
- **`v2.115.0.0` — 能力音效「地獄」：FMOD 處理流程 + wave6 音效庫 + hook lab + 指令介面。** Lane **Jarvis-MAGIC**。**次要**：I31/I32 RE (`FFX_ABILITY_SFX_FMOD_STREAMING_INFERNO`,`FFX_MAGIC_DLL_ABILITY_SFX_CORPUS_INFERNO`);`--magicdll-sound-corpus-wave6` (587 個 DLL 檔案，510 個 SeSep)；`MagicDllSoundWriter` +`--command-sound-rt0`;`AbilitySfxHook` 唯讀實驗室；核心指令 **戰鬥音效** 唯讀面板；`AbilitySfxLab` 評斷。RT2 遊戲內 **待定**。[上一則：`v2.114.0.3`]
- **`v2.114.0.3` — 《Spira Reforge》：被 ?????????? 附身（受「罪」感染的開場）。** Lane **Jarvis-HD**。**修訂版**：不含劇透的原版克隆模板；僅含技能的「惡魔」套裝。[先前版本：`v2.114.0.2`]
- **`v2.114.0.2` — Spira Reforge：技能配色調整 ≠ 怪物模型。** 負責 **Jarvis-HD**。**修訂**：澄清為僅限視覺特效；怪物模型 = 待處理清單。[先前：`v2.114.0.1`]
- **`v2.114.0.1` — 《Spira Reforge：受辛感染的怪物技能文件》。** Lane **Jarvis-HD**。**修訂版**：`SIN_INFECTED_MONSTER_SKILLS.md` — 新版 monmagic + 配色調整；POC Flan Flood 亮橙色；Sin 技能排隊。[

上一頁：`v2.114.0.0`]
- **`v2.114.0.0` — 弗蘭·弗拉德：沃特加克隆實驗室（火焰弗蘭岩漿）。** 萊恩 **賈維斯-MAGIC**。 **次要**：`--flameflan-flood-pack` /`--flameflan-flood-recolor` — 第 249 行`0x60F9`, 克隆體`magic_0718/0719` 來自`0096/0097`, phyre magma/coral, **未包含 FFX.exe 修補檔**；UI Monster Commands 2 安裝／部署。[上一則：`v2.113.0.3`]
- **`v2.113.0.3` — INFERNO 交付 + IDA 語義重命名 + BIBLE 更新。** Lane **Jarvis-MAGIC**。**REVISION**：套件`FFX_RE_DEEP_INFERNO_DELIVERY_BUNDLE`; 45 項語義重命名於`FFX_recon.i64` (160 個佔位符`FFX_I##_` （被忽略的）；`AiBibleCatalog` +`btlGetCalcResult`/`readMovePropertyForActor`; 審計偏移提示`FFX_RE_SEMANTIC_DRIFT_AUDIT`. 重命名操作 **不會** 阻斷 Hooks/editor。[先前：`v2.113.0.2`]
- **`v2.113.0.2` — Nul Ward 24 計畫整合矩陣（ATEL 56/57）。** Lane **Jarvis-MAGIC**。**修訂版**：`FFX_NUL_WARD_INTEGRATION_MATRIX` — IDA 試玩老虎機`+0x613/+0x614` (指令碼 56/57)，24 條 armar/consume/UI 路徑，狀態為 VALIDATED/CUT。[上一頁：`v2.113.0.1`]
- **`v2.113.0.1` — Nul Ward 12 個 RE 計畫（RT2 前，IDA 反編譯）。** Lane **Jarvis-MAGIC**。**修訂**：`FFX_NUL_WARD_RESEARCH_PLANS` — 12 項經實證有效的方案（`sub_7B2DD0` 計數器`+0x60E`, 教導 ID≥96 派對銀行, 掃描`0x3032`, B 階段回寫)。[上一頁：`v2.113.0.0`]
- **`v2.113.0.0` — Nul Ward 離線預檢 + 掛鉤修復 + 核心使用者介面。** Lane **Jarvis-MAGIC**。 **次要**：`--nul-ward-static` 驗證 FFX.exe（PE RVA）、command.bin 320/321、DLL/flags；IDA 檢測到 @ action+0x08 處的編碼命令；`NulWardHook` 已修正；支援鉤子的套件（不造成 Tide/Shock 傷害）；Kernel 識別碼 320/321 的面板；`preflight.ps1`. [上一頁：`v2.112.0.25`]
- **`v2.112.0.25` — Ronso Mana hudSafe=16：固定部署 + 掛鉤`7ACEC0`.** Lane **Jarvis-MAGIC**. **PATCH**：`install_to_modules.ps1` 從套件中複製舊的 DLL；hook`3ACEC0` força ring kind=12; 維持`79AF70`. RT2 待處理。[上一則：`v2.112.0.24`]
- **`v2.112.0.24` — Ronso Mana hudSafe=15：中環通道`79AF70`.** Lane **Jarvis-MAGIC**. **PATCH**：hook`39AF70` +`actor+0x590|=4` + word`+0x6C8=0` 適用於 Kimahri，載重≥100；維持模板 hudSafe=14。RT2 待處理。[先前版本：`v2.112.0

.23`]
- **`v2.112.0.23` — RE Deep INFERNO GPT 提示詞（I01–I20 惡魔馬拉松）。** Lane **Jarvis-MAGIC**。**REVISION**：`FFX_RE_DEEP_INFERNO_PROMPT_GPT55` — ATEL VM、傷害處理流程、AI 重新載入、31 個硬編碼的 AA、遭遇狀態機、Magic VM、選單／AbiMap；I21–I30 獎勵。[前一項：`v2.112.0.22`]
- **`v2.112.0.22` — RE Deep Wave 3 GPT 提示詞（R01–R04 IDA 馬拉松）。**
- **`v2.112.0.21` — Ronso Mana hudSafe=14：範本 7AEFC0 + menuCtx.**
- **`v2.112.0.20` — Spira Reforge 操作速查表（Halyson 1 頁）。** Lane **Jarvis-HD**。**修訂**：`docs/ai/FFX_SPIRA_REFORGE_HALYSON_CHEATSHEET_2026-06-15.md` — RT2 v0.2 序列，MEGA/MODS 索引連結，Auto-Abilities 區段（#114–#134、#24 Break、CLI 閘門）。[上一頁：`v2.112.0.19`]
- **`v2.112.0.19` — MODS 馬拉松 M01–M30 已完成：29 份文件 + 目錄 + Spira Reforge 審計。** Lane **Jarvis-MODS-MEGA**。**修訂**：`FFX_MODS_MEGA_RESEARCH_INDEX` + M01–M29（操作摘要約 37–142 行/文件）；保留 Spira Patch/Arena/SIN/QH/Dark 的封鎖機制；RT2 排行榜第 134 名/id129/Break Limits。僅供研究使用。[前一則：`v2.112.0.18`]
- **`v2.112.0.18` — Ronso Mana hudSafe=10：池 255，OD 僅高於 100。** Lane **Jarvis-MAGIC**。**PATCH**：`gateMin=101` 預設；上限 255，持續生效；依技能進行灰階處理，維持 40–255 的消耗。RT2 待定。[前一項：`v2.112.0.17`]
- **`v2.112.0.17` — Ronso Mana hudSafe=9：修正偽造值與泳池上限 255 的衝突。** Lane **Jarvis-MAGIC**。**PATCH**：退役`BeginKimahriMaxSpoof` (化解`max=255` （在建構時）；drain 使用`ApplyKimahriRuntimePoolMax`; 日誌`G0 poolMax`. RT2 待處理。[上一則：`v2.112.0.16`]
- **`v2.112.0.16` — Ronso Mana hudSafe=8：奇偶校驗儲存值（最大值=255）＋原生選單。** Lane **Jarvis-MAGIC**。**PATCH**：修正 RVA 佈局`01F0FCD8`;`actor+0x5BD=255` 僅限金哈里；注入`0x311A` 在`+0x71A`/`+0x6CB`; hook`7850E0` save-bank cmd 282；維持 G2 排水 + G0'/G1'/G3'。RT2 待處理。[上一則：`v2.112.0.15`]
- **`v2.112.0.15` — MODS MG 針對 GPT 5.5 的研究：Spira Reforge M01–M30。** Lane **Jarvis-HD**。**修訂**：提示詞`FFX_MODS_MEGA_RESEARCH_PROMPT` (Spira Patch、Arena+、SIN 模式、團隊策略、Forbidden Rite、IDEAs)；`KNOWLEDGE_BASE` +`mods/README`. 無 RT2。[上一則：`v2.112.0.14`]
- *

*`v2.112.0.14` — Ronso Mana hudSafe=6：主選單中的「Overdrive」（攻擊／技能／特殊）。** 戰線 **Jarvis-MAGIC**。** 更新 **：G0' @`39AD40` (`HasCommandBit` cmd 282 Kimahri + 部分載入）；G0 位元 282 之前／之後`79BB70`/`79B500`; 排水後重新連接位元。RT2 待處理。[前一項：`v2.112.0.13`]
- **`v2.112.0.13` — Ronso Mana hudSafe=5：以部分載入狀態重新開啟 OD 子選單。** Lane **Jarvis-MAGIC**。**PATCH**：`RonsoManaHook` — G1' @`392170` (OD 斷裂應力) +`49BA80` (open spoof) + G0 刷新`39B500` + bit cmd 282 @`39C090`; 固定`IsKimahriActorPtr` 僅`Id==2`；維持 G2 drain + G3' greyout；不使用 HUD/GetMax 繞道。RT2 待處理。[前一則：`v2.112.0.12`]
- **`v2.112.0.12` — MEGA 深度後續研究 D01–D07 已完成（IDA + 語料庫 + 阻塞）。** Lane **Jarvis-MEGA-DEEP**。**修訂**：7 份深度文件（約 260–390 行）+`FFX_MEGA_RESEARCH_DEEP_INDEX`; exports IDA`work/reverse/ida/exports/mega_deep/` 所引用的項目；W2S 擁有者／容量生成／變體選擇器／處理器`0x707A` 被鎖定；chunk3、stride`0xF90`, FSM 相機，Y 撰寫的試拍作品。僅供研究使用。[上一頁：`v2.112.0.11`]
- **`v2.112.0.11` — Ronso Mana hudSafe=4：G0 選單 + G3' 刷新 + G2 清空。** 線路 **Jarvis-MAGIC**。** 修補程式 **：`RonsoManaHook` — G0 @`39BB70` (金哈里 時間)`max=charge`), G3' @`492040` （灰色行），直截了當`897F80`/GetMax。[上一頁：`v2.112.0.10`]
- **`v2.112.0.3` — Spira Reforge：完整視圖 + F7 競技場（NPC wontfix）。** 路線 **Jarvis-HD**。 **修訂**：`mods/Spira Reforge/VISION_AND_ROADMAP.md` — 反「Ribbon/Celestial」策略、v0.2–v0.5 路線圖、Dark Aeons + SIN 變體天梯、Arena 模式清單、僅限 F7 鍵的選單設定。[前一項：`v2.112.0.2`]
- **`v2.112.0.2` — Spira Patch 格式規範（批量匯出／匯入草案）。** Lane **Jarvis-HD**。**修訂版**：`docs/specs/SPIRA_PATCH_FORMAT_2026-06-15.md` — 怪物、戰利品、自動技能的 JSON/CSV 資料結構，以及`arms_rate`；範例見於`mods/Spira Reforge/patches/`. 目前尚未在編輯器中實作。[上一則：`v2.112.0.1`]
- **`v2.112.0.1` — Ronso 標記評論 + 版本控制 MonEditor 模型條目修訂。** Lane **Jarvis-MAGIC**。**PATCH**：`kimahri_ronso_mana.flag` 附有 log/apply 指令。[上一頁：`v2.112.0.0`]
- **`v2.112.0.0` 

— MonEditor：戰鬥模型目錄（FFXmon）＋ Model1/Model2 預覽。** Lane **Jarvis-MAGIC**。**MINOR**：匯入`battle-model-catalog.json`; 名稱可見的選取器；橋接器`BattleModelCatalogBridge` → 模型檢視器 (`m###`/`c###`/`s###`); 預覽雙 ID1+ID2；MAIN MODEL 配對按鈕。文件`FFX_BATTLE_MODEL_CATALOG_MONEDITOR`. [上一頁：`v2.111.0.0`]
- **`v2.111.0.0` — Ronso Mana 線控鉤 (`FfxHooksDll` Kimahri（部分 OD LAB）。** Lane **Jarvis-MAGIC**。**MINOR**：`RonsoManaHook` G1 閘極 + G3 灰階 (PolyHook) + G2 漏極 @ PE`0x38F1E5`; 旗幟`kimahri_ronso_mana.flag` /`kimahri_ronso_mana_apply.flag`; 部署實驗室`ronso-mana-lab-v2.111.0.0`. RT2 部分遊戲畫面（drain PASS）。[上一則：`v2.110.1.2`]
- **`v2.110.1.2` — MEGA 研究馬拉松：23 份 Aurora 文件 + 審計 + 深度後續追蹤 D01–D07。** Lane **Jarvis-MAGIC**。**修訂**：目錄`FFX_MEGA_RESEARCH_INDEX` + A01–A15/C01–C08；`FFX_MEGA_RESEARCH_AUDIT` （摘要與證據）；提示`FFX_MEGA_RESEARCH_DEEP_FOLLOWUP` 為第二場 IDA 馬拉松；`PORT_STATUS` 閘位 21→29 已進行對帳。無 RT2。[前一項：`v2.110.1.1`]
- **`v2.110.1.1` — NovaClamp：修正了導致 EFLAGS 被篡改的問題（全局繞過）。** Lane **Jarvis-MAGIC**。**PATCH**：存根程式會重新執行`cmp eax,ebx` 在 vanilla 路線上 —`jle` 曾使用來自`cmp [ebp+0x1C]` (幾乎所有的 cmd &lt;`0x3073` 跳過 clamp）；部署`ffx-hooks.dll`. RT2 重新驗證蒂達斯 ≤99k + 諾瓦 &gt;99k。[先前：`v2.110.1.0`]
- **`v2.110.1.0` — Event JP 引導程式 + PPPDRAW 已移除 + NovaClamp 存根修正。** 通道 **Jarvis-MAGIC**。** 修補程式 **：`--event-rt0` JP 回歸分析`0x06`/`0x26..0x2F` (`13/13`);`FFXPROBE_PPPDRAW_RETIRED` 在 probe/lab 中；在記錄之前新增 stub 寫回功能。[先前：`v2.110.0.3`]
- **`v2.110.0.3` — 研究 H01–H15：heavy 套件 + 索引 + Ronso Mana。** Lane **Jarvis-HEAVY** + **Jarvis-MAGIC**。**修訂**：16 份文件 (`FFX_RESEARCH_CHAT_GENERATED_FILES` + H01–H15）；`KNOWLEDGE_BASE` H波；G1/G3 IDA型低頻振顫。無RT2。[前一項：`v2.110.0.2`]
- **`v2.110.0.2` — 回覆：IDA flat 對決 PE RVA（對戰專區）`+0x400000`).** Lane **Jarvis-MAGIC**. **修訂**：doc`FFX_IDA_FLAT_VS_PE_RVA_BATTLE_SECTION_2026-06-15.md`; 規格書／簡報／交接文件（含RVA）`0x38xxxx`. [上一頁：`v2.110.0.1`]
- **`v2

.110.0.1` — NovaClamp: fix PE RVAs (0x38EDD5, não 0x78EDD5).** Lane **Jarvis-MAGIC**. **PATCH**: hook falhava silencioso — IDA flat = PE RVA + 0x400000 na seção battle; bytes `7E 02` no build Steam. [anterior: `v2.110.0.0`]
- **`v2.110.0.0` — 新型超級傷害上限繞過 LAB (`FfxHooksDll`).** Lane **Jarvis-MAGIC**. **MINOR**: 內嵌鉤子 @`FFX.exe+0x38EDD5` — 跳線夾`mov eax,ebx` 當……時`[ebp+0x1C]==0x3073` (Nova #115)；公式造成的傷害值會有所變化；標記`nova_super_damage.flag` /`nova_super_damage_log.flag`; RE clamp 文件 + RT2 遊戲內規格尚待確認。[前一則：`v2.109.4.1`]
- **`v2.109.4.1` — Arena+：NPC 鉤子實驗室 — RT2 失敗，需透過減傷機制 + RE 來解決。** 戰線 **Jarvis-ARENAPLUS**。** 更新 **：鉤子機制強化`013B` （不頂帖）`maxIndex` 無修補程式；延遲 30f；`sub_86BEC0` @`0x86BEC0`); **RT2 NPC 發生錯誤** — 第 6 個選項未顯示；**F7 仍有效**。文件`FFX_ARENA_PLUS_NPC_NOWWHAT_HOOK_2026-06-15.md` 已更新。[先前：`v2.109.4.0`]
- **`v2.109.4.0` — Arena+：NPC 選項「Now what？」→ Arena+ (lab)。** Lane **Jarvis-ARENAPLUS**。**MINOR**：hook`Common.displayFieldChoice [013B]` 字串`0x4A`;`arena_plus_npc.flag`. RT2 NPC **未通過** — 參見`v2.109.4.1`. [上一頁：`v2.109.3.0`]
- **`v2.109.3.0` — ThundaFira：淘汰內嵌式 PPPDRAW hook EXE (`sub_71B980`).** Lane **Jarvis-MAGIC**. **PATCH**：`FFXPROBE_PPPDRAW_RETIRED`; 指令碼 14–16 會回傳錯誤；lab`--pppdraw-tint-capture` 已鎖定；`DEAD_ENDS_INDEX` H7–H9. [前一頁：`v2.109.2.0`]
- **`v2.109.2.0` — ThundaFira：修復了 PPP 繪製鉤點爆炸後的當機問題。** Lane **Jarvis-MAGIC**。**PATCH**：`PPPDRAW_STOP` 請勿在 VFX 運行期間解除安裝 hook；僅在`DLL_PROCESS_DETACH`; 擷取會在最後一次點擊後等待 3 秒。文件`FFX_THUNDAFIRA_PPPDRAW_HOOK_CRASH_2026-06-15.md`. [上一頁：`v2.109.1.0`]
- **`v2.109.1.0` — ThundaFira：PPP 拉鉤重新鎖定目標`sub_71B980`.** Lane **Jarvis-MAGIC**. **PATCH**：`ffx-probe` PPPDRAW 安裝於`0x71B980` (14 B 序言)；tint 結構體`a3+4`; doc`FFX_THUNDAFIRA_SUB_71B980_IDA_2026-06-15.md`. [上一頁：`v2.109.0.2`]
- **`v2.109.0.2` — 研究佇列「TROUXA」：RE 套件離線（21 份文件）。** 通道 **Jarvis-RESEARCH-TROUXA**。** 修訂版本 **：索引 `FFX_RESEARCH_QUEUE_TROUXA_IN

DEX_2026-06-15.md` + dossiers ThundaFira/Magic/Arena+/AutoAbility/FPS/offline-ci/event-text/spheregrid; `KNOWLEDGE_BASE` + `PORT_STATUS` atualizados. Sem mudança de comportamento do produto. [anterior: `v2.109.0.1`]
- **`v2.109.0.1` — Arena+：光碟中的 FFXED 標記 + OST 145 多頭首領 RT2。** Lane **Jarvis-ARENAPLUS**。**PATCH**：PC 對戰存檔 (`gil@0x3D88`, 競技場`@0x424C`, FFXED`@3273` bit7) 或 執行時`0x18F4`; F7 關卡中需消耗 8 個「黑暗永恆」；多頭首領的 OST 挑戰（P4 延遲開放）。[上一則：`v2.109.0.0`]
- **`v2.109.0.0` — 存檔編輯器：多槽位 MC + 道具下拉選單 + RT2.** Lane **Jarvis-SAVE**。**次要功能**：中樞介面的槽位選擇器`.ps2`; 道具組合（FFXED 目錄）；`--ffx-save-rt2` (raw/.ffx/.ps2 多槽位)；已修正`SaveSlot` 儲存至替代路徑。[上一頁：`v2.108.0.0`]
- **`v2.108.0.0` — 存檔編輯器：各角色武器組合 + 完整的 C0008i 批次檔。** Lane **Jarvis-SAVE**。 **次要**：帶下拉選單的裝備（T[0–6] Tidus→Rikku、外觀、自動攻擊、傷害公式）；`weaponCatalogByCharacter` 在登錄檔中；`FfxSaveBatchActions` 動作選單 9–59（球體／迷你遊戲／閃電球／進口捐贈者）；「角色」、「球體」、「迷你遊戲」、「閃電球」分頁中的批次按鈕。[上一頁：`v2.107.0.0`]
- **`v2.107.0.0` — 存檔編輯器：完整版 FFXED（裝備→匯入 + .ps2 MC）。** Lane **Jarvis-SAVE**。 **次要功能**：原生分頁「裝備」（200 格 + 自動配置）、「道具／吉爾／關鍵道具」、「閃電球」（60 名球員）、「球體網格」（節點 + 批次處理）、「迷你遊戲」（登錄表欄位）、「其他／匯入」（來源區域）；`ffxed_registry.json` +`scripts/ffxed_extract_registry.py`; 載入／儲存`.ps2` 8MB；批次 C0008i 審查；備用 FFXED.jar。[上一項：`v2.106.0.1`]
- **`v2.106.0.1` — Arena+：Dark Aeon 的旗幟已與 FFXED 對齊（bit7 @ save+3273）。** 頻道 **Jarvis-ARENAPLUS**。 **更新檔**：F7 選單讀取了錯誤的陣列`0x18F4`；現在採用 FFXED「Misc→Optional Bosses」中的部分內容（`0xD2D759..`, 第 7 位元)。[上一頁：`v2.106.0.0`]
- **`v2.105.0.0` — ThundaFira：ppp_dataA 對比 PE 分析器即時處理 + 擷取色調區域。** Lane **Jarvis-MAGIC**。**次要**：執行時實驗室`LiveVsPeAnalyzer` +`--live-vs-pe`; 翻斗車截圖`tint_vec4_canonical` @`0x37710` 以及`dataA_cyan_strip`; 執行時版本≠PE（差異為 2758 B）。[先前版本：`v2.104.0.6

`]
- **`v2.104.0.6` — Arena+ 原聲帶：實驗配方（覆寫 + soundcmd 觸發器 4）。** Lane **Jarvis-ARENAPLUS**。**PATCH**：放棄在非同步模式下直接交換 16→145；使用`musicOverride` +`soundcmd 23/4/0` +`SwitchCrossfade` （已於實驗室菜單中驗證）。[上一項：`v2.104.0.5`]
- **`v2.104.0.3` — Arena+ OST hook v5 (FSM case-8)`PlayTrackWithPreload`).** Lane **Jarvis-ARENAPLUS**. **PATCH**：`InstallMusicHookArenaBattle` 攔截`PrepBattleTrack` +`PlayTrackWithPreload` (RVA`0x486940`/`0x486980`) 將硬編碼的 16→145 進行替換，同時保持 26/39 的非同步佇列不變；參見 RE P0–P3 文件。[先前：`v2.104.0.2`]
- **`v2.104.0.2` — ThundaFira：修復 PPP 繪製掛鉤當機問題（安全探測）。** Lane **Jarvis-MAGIC**。**修補程式**：移除無效的備用 EXE 檔案；僅安裝 vtable`host+2856` 附有序言`55 8B EC`; STOP 會還原位元組；`--force-tint` RT2 當機後被鎖定。[上一則：`v2.104.0.1`]
- **`v2.104.0.1` — ThundaFira：PPP 繪製掛鉤修正（vtable host+2856）。** Lane **Jarvis-MAGIC**。**PATCH**：在執行時解決函式綁定問題（`off_C64CE8+2856`); cdecl thunk; 將 tint 強制設為 +0/+4。RT2− 設為`0x31B590` (0 次點擊)。[上一則：`v2.104.0.0`]
- **`v2.104.0.0` — ThundaFira：探針掛鉤著色 PPP 繪製 (`FFX+0x31B590`).** Lane **Jarvis-MAGIC**. **MINOR**：`ffx-probe` 指令碼 PPPDRAW 14–16；標籤`--pppdraw-tint-capture`. [上一頁：`v2.103.0.0`]
- **`v2.103.0.0` — ThundaFira：KeThRes 地圖重新定位 + 掛鉤附加緩衝區 (`sub_72C570`).** Lane **Jarvis-MAGIC**. **MINOR**：`MagicDllKeThResRelocAnalyzer` +`--thundafira-kethres-reloc`; 已修正閘門修補程式 (`dataA+0x58C..0x620`, 2× vec4);`ffx-probe` KETHRES 10–12 指令碼；實驗室`--kethres-attach-capture`. [上一頁：`v2.102.0.1`]
- **`v2.102.0.1` — ThundaFira：KeThRes PPP 補丁（軟鎖後版本）RT2。** 線路 **Jarvis-MAGIC**。**補丁**：`MagicDllKeThResPppPatch` 不再修補 blob/offset-table；僅`float_vec4` 在青色波段`dataA`. Doc RT2− softlock. [上一頁：`v2.102.0.0`]
- **`v2.102.0.0` — ThundaFira：KeThRes PPP 離線修補程式 (`--thundafira-kethres-patch`).** Lane **Jarvis-MAGIC**. **MINOR**：`MagicDllKeThResPppPatch` — 分析`ppp_dataA` + 磁碟上的 blob，套用橘色色調（範圍`ppp-only`); 輸出`magic_0716_kethres_orange.dll`. RT2 遊戲內待處理。[上一則：

`v2.101.0.1`]
- **`v2.101.0.1` — ThundaFira：KeThRes 的靜態轉儲 (`--thundafira-kethres-dump`).** Lane **Jarvis-MAGIC**. **PATCH**：`MagicDllKeThResDumper` — 從 PE 中提取 blob/handle/PPP 目錄`0094` + manifest/hex MD。[上一則：`v2.101.0.0`]
- **`v2.101.0.0` — ThundaFira：KeThRes PPP 解析器 (`--thundafira-kethres-parse`).** Lane **Jarvis-MAGIC**. **MINOR**：`MagicDllKeThResParser` — PPP 指令碼目錄`0x55D4456F`,`pppKeThRes32x4` + PS3 遊戲《Phyre》的得分；IDA 繪製路徑文件。[上一則：`v2.100.0.3`]
- **`v2.100.0.3` — ThundaFira 第一階段：RT2 雙人組 vec4 地面戰（`--offset2`).** Lane **Jarvis-MAGIC**. **PATCH**：`--thundafira-ppp-color-test` 接受`--offset` +`--offset2` (最多 2) 以及`--rt2-tag` 以 RT2 為基準將 B 支一分為二。[前一項：`v2.100.0.2`]
- **`v2.100.0.2` — ThundaFira 第一階段：RT2 失敗，導致 PPP 執行時網站停用。** Lane **Jarvis-MAGIC**。**修補程式**：RT2 Halyson —`full_phase1` 光束無色彩，動畫速度更快／更扁平（時序與色彩辨識混淆）；閘門`--thundafira-ppp-runtime-color` 僅`--restore`. Doc`FFX_THUNDAFIRA_PHASE1_RUNTIME_PATCH_RT2_FAIL_2026-06-14.md`. [上一頁：`v2.100.0.1`]
- **`v2.100.0.0` — ThundaFira 第 1 階段：擴展版 PPP 執行階段修補程式（預設分支 + 螺栓生成）。** 車道 **Jarvis-MAGIC**。 **次要**：`--thundafira-ppp-runtime-color --site full_phase1` — IDA 證實，怪物陣容使用的是 **default** 分支的`Thundaga_EgoTaskSetup_0094` (不包含 LABEL_9 玩家 ID)；修補 host+1072 及 RGBA spawn 這兩條分支，位置在`Thundaga_EgoTaskTick_0094`. Doc`FFX_THUNDAFIRA_PHASE1_RUNTIME_PATCH_2026-06-14.md`. 待處理的人類 RT2。[上一則：`v2.99.0.0`]
- **`v2.99.0.0` — ThundaFira：PPP 運行時修補程式（IDA 主機+1072）。** Lane **Jarvis-MAGIC**。**MINOR**：gate`--thundafira-ppp-runtime-color` — 即時修補程式`.text` 在`sub_10006B50` (`magic_0716.dll`); 掃描`.data` vec4 在 RT2 之後已退役。Doc`FFX_THUNDAFIRA_PPP_RUNTIME_COLOR_IDA_2026-06-14.md`. [上一頁：`v2.98.1.0`]
- **`v2.98.1.0` — ThundaFira：phyre RT2 分類器（128_128 ≠ 射線）。** Lane **Jarvis-MAGIC**。**PATCH**：`ThundagaPhyreClassifier` — RT2 Halyson 已驗證`_128_128` 在`0716` = 地面上的衝擊閃光／爆炸，**並非**閃電；`--bolts-orange` 重新命名為 comport

主要用於搭配 WARN 的地面閃光燈。Doc`FFX_THUNDAFIRA_PHYRE_SHEET_RT2_2026-06-14.md`. [上一頁：`v2.98.0.0`]
- **`v2.98.0.0` — 文字：2 位元組字形解碼／編碼 (FTCX/FONTk) + 重新命名 EncounterTable`MapNamePadding`.** 萊恩 **賈維斯-MAGIC**. **MINOR**：`FfxEncoding.glyph.cs` — 位元組`0x06` 以及`0x26..0x2F` 不再是`<C6>`/`<C38..>` 並將其轉換為代幣`<FTCX:n>`/`<FONTk:n>` 包含雙向位元組傳輸 (`TextBinary_Util.TryMatchGlyphToken`, 非阻塞式檢查）。**PATCH** 外觀修正：`Unknown0C` →`MapNamePadding` 在`EncounterTable_File` (IDA 已驗證：map-name 字串的結尾符號)。Worktrees Claude`851-1/2/3/4` 篩選結果：僅保留有用的部分；其餘皆遭剔除。[上一頁：`v2.97.0.0`]
- **`v2.97.0.0` — ThundaFira：Family D PPP 探針 + 修正後的 RT2 配色。** 車道 **Jarvis-MAGIC**。**次要**：閘門`--thundafira-ppp-probe` (候選人`pppColMove`/`pppKeThRes` 在`magic_0094`),`--thundafira-ppp-color-test` (1 偏移量的外科補片)，`--thundafira-recolor --phyre-anim1`; 預設分裝包`716/717` 含捐贈者`0095`;`MagicDllPppColorCandidateScanner`; vec4 啟發式演算法在`0716.dll` **退休** (RT2：`0x31640` = PPP 矩陣，2D 半徑）。文件：`FFX_THUNDAFIRA_HANDOFF_CONTINUE_2026-06-14.md`. [上一頁：`v2.96.0.0`]
- **`v2.96.0.0` — monmagic 即時同步核心 + 阿爾貝德詞典編輯器。** Lane **Jarvis-MAGIC** + 文字。 **次要**：`KernelMonsterMagicLiveSync` 閱讀`monmagic1.bin`/`monmagic2.bin` 在載入／儲存專案時，會複製名稱與操作數`0x4xxx`/`0x6xxx` 新的，用於`CommandMonster*`,`AiCommandId`,`AiCommandMetadataCatalog` 以及 Monster AI 選角工具（無需透過 Spell LAB 手動套用補丁）；**Al Bhed 辭典** 模組（`albheddic.bin` US Latin + JP 假名）搭配 Rail 中的字元安全寫入器`???`. RT2 ThundaFira 遊戲內待處理。[上一則：`v2.95.0.0`]
- **`v2.95.0.0` — ThundaFira：LAB 魔法 Thundaga+Multi-Fira + 編輯器中的使用者介面。** Lane **Jarvis-MAGIC**。**MINOR**：傳送門`--thundafira-pack` (grow monmagic2 #248，克隆體`magic_0716`/`0717`, 紋理 thunder+fire);`--prism-flare-recolor` (重新上色為深紫色`magic_0715`); **Monster Commands 2** → 「安裝／部署視覺化元件」按鈕。[上一頁：`v2.94.0.0`]
- **`v2.94.0.0` — Magic DLLs：UI 中的 wave4 版權標示 + p

Magic Viewer / Phyre Package I/O 來源。** Lane **Jarvis-MAGIC**。 **次要**：`MagicDllWave4CatalogLoader` 將離線分類學資料（類別、科、核心參考、覆蓋簽名、編輯指引）注入至`Extras → Magic DLLs (FFX)`; 清單中的徽章；**Wave4 Attribution** 卡片；**Magic Viewer** 按鈕 (`?magic=####`) 以及 **Phyre Package I/O**（第一版`.dds.phyre` （PS3）；）`scripts/magic_viewer_merge_wave4_catalog.py` 將 wave4 合併至`magic-viewer-catalog.json`; 檢視器的 HUD 顯示 W4 徽章。[上一頁：`v2.93.0.0`]
- **`v2.93.0.0` — Magic DLLs：wave3 分類 + wave4 深度語料庫 + 孤立來源歸屬目錄 + Hex-Rays 後處理。** Lane **Jarvis-MAGIC**。**次要**：gates`--magicdll-classify-wave3`,`--magicdll-deep-corpus-wave4`,`--magicdll-orphan-catalog`;`MagicDllMoveAnimParser` 修正`moveAnim=magic_XXXX/None` (+44 咒語連結)；多來源分類學 (463`catalog_and_kernel`, 109`engine_overlay_carrier`, 9 個雙生體、2 個克隆體）；腳本`magic_dll_hexrays_postprocess_host.py`,`magic_dll_hexrays_host_profile.py`,`magic_dll_wave4_rt2_queue.py`; 批次處理 Hex-Rays 二次分析 + 自動後處理。Wave3/Wave4/孤立物件目錄文件。RT2 遊戲內處理待處理。[上一項：`v2.92.0.0`]
- **`v2.92.0.0` — Magic DLLs：Hex-Rays ALL 層級 (1829/1829) + idalib 平行批次處理 + RT2 視覺預處理閘道。** Lane **Jarvis-MAGIC**。 **次要**：`scripts/magic_dll_hexrays_batch.py` (`--tier all|pinned|shared`,`--workers N`,`--remaining-only`, 隔離式預演環境`w0..wN`); wave2 資料集 **534 個 DLL / 1829 個槽位** Hex-Rays 於`work/magic_dll_logical_decompile_wave2/hexrays_output/` （約16分鐘，6名工作人員）；閘口`--magicdll-rt2-visual-prep` 產生實驗室 DLL 檔案`magic_0084`/`magic_0098` + 離線修補方案。文件：`FFX_MAGIC_DLL_HEXRAYS_ALL_COMPLETE_2026-06-14.md`,`FFX_MAGIC_DLL_HEXRAYS_PINNED_PROGRESS_2026-06-14.md`, RT2 檢查清單 0084/0098 已更新。誠實度：C 語言反編譯 ≠ 視覺語義；RT2 遊戲內（Prism + 實驗室 DLL）待處理；語料庫中約有 49 個 DLL 因缺乏程式碼槽而排入待處理清單。[先前：`v2.91.1.0`]
- **`v2.91.1.0` — Arena+：OST 戰鬥進入鉤子 v4 + Opus 簡報 + 對齊的 Dark Aeon 偏移。** 通道 **Jarvis-ARENAPLUS**。 **更新**：`MusicHook` 雙重攔截`PlayTrack(16)` 來源`soundcmd 23` (可能

e) 採用基礎方案作為備用方案；`SwitchCrossfade(16)` 交換 arg；移除`SwitchCrossfade` 直接作用於墊片上（導致無聲）。`dllmain` 在「arma pending」之前`781D60`; 備用執行緒僅在攔截時且未消耗的情況下才會啟動。實驗室設定`RuntimeTools/FfxHooksDll/config/arena_plus_music_*.txt`.`MemoryMap.ADDR_DARK_AEON_FLAGS=0xD2E384`;`ffxprobectl arena-flags` 已修正 RVA。文件：`OPUS_BRIEF_ARENA_PLUS_MUSIC_2026-06-14.md`,`OPUS_BRIEF_ARENAPLUS_RESEARCH_QUEUE_2026-06-14.md`；Arena+ 資料夾中的平版印刷橫幅已修正。RT2 OST 尚待處理。[上一則：`v2.91.0.0`]
- **`v2.91.0.0` — Magic DLLs：邏輯反編譯波段 1/2 + 瀏覽器介面（家族比較器、PS3 橋接器、邏輯反編譯分頁）。** Lane **Jarvis-MAGIC**。 **次要更新**：`MagicDllLogicalDecompiler` (靜態主機偏移指紋 + 偽代碼/插槽聚類)，閘門`--magicdll-logical-decompile-wave1` (119 個 DLL 範例) 以及`--magicdll-logical-decompile-wave2` (583/583 資料集 + Hex-Rays 的 pinned/shared/all 佇列)；`MagicDllFamilyComparator` +`MagicEffectClonePipeline` (部署 ps3data 複製本)；在 **Logical Decompile** 標籤頁中`Extras → Magic DLLs (FFX)` 包含各插槽的表格／偽代碼、Value Workbench 中的 Family C/D 提示、PS3 Magic／extract／mods 快捷方式以及橋接功能`Open PS3 Magic (HD)`. 文件：`FFX_MAGIC_DLL_LOGICAL_DECOMPILE_WAVE1_2026-06-14.md`,`FFX_MAGIC_DLL_LOGICAL_DECOMPILE_WAVE2_2026-06-14.md`. 建置版本 0 無錯誤。 [上一版：`v2.90.1.0`]
- **`v2.90.1.0` — Prism Flare v2 套件（遊戲畫面 + Prism DLL 配色修改 + 部署）。** 線路 **Jarvis-MAGIC**。 **次要**：傳送門`--prism-flare-v2-pack` — 第 247 行 力量 42，火／雷／水，速度降低 65%／4 回合；重新上色`magic_0714/0715` （每組 16 個 vec4 補丁，紫色棱鏡）。[上一頁：`v2.90.0.3`]
- **`v2.90.0.3` — Magic VM：第 2+3 組叢集通過（MISC→0）+ RT2 視覺 0084/0098。** Lane **Jarvis-MAGIC**。**REVISION**：第 2 次通過`analyze_batch` (66 其他) + 將剩餘的 10 個 Hex-Rays 進行反編譯 →`cluster_assignments_pass3.csv` (119/119，具行為型群組)。文件：`FFX_MAGIC_VM_MISC_PASS3_DECOMPILES_2026-06-14.md`,`FFX_MAGIC_RT2_VISUAL_0084_0098_2026-06-14.md`. [上一頁：`v2.90.0.2`]
- **`v2.90.0.2` — Magic VM：自動化第 1 階段叢集 (119/119 核心操作)。** Lane **Jarvis-MAGIC**。**REVISION**：`f

unc_query` IDA + `work/magic_vm_cluster/cluster_from_func_query.py` → `cluster_assignments.csv` (9 clusters; 66 MISC aguardam pass 2 callees). Doc clusters atualizado com fila decompile top-3/cluster. [anterior: `v2.90.0.1`]
- **`v2.90.0.1` — Magic 引擎：統一樞紐 + VM 叢集 + A/C 編輯指南。** Lane **Jarvis-MAGIC**。**REVISION**：連結 VM EXE 的 RE 文件、581 個 DLL 的分類及實務編輯。`FFX_MAGIC_ENGINE_MASTER_2026-06-14.md` (樞紐)，`FFX_MAGIC_VM_OPCODE_CLUSTERS_2026-06-14.md` (7 個聚類，IDA 樣本)，`FFX_MAGIC_FAMILY_AC_EDITING_GUIDE_2026-06-14.md` （顏色／速度透過 Value Workbench 設定，A/C 系列）。[上一頁：`v2.90.0.0`]
- **`v2.90.0.0` — Magic DLLs：透過瀏覽器第 0 槽位的位元組掃描，對 A/B/C/D 家族進行分類。** Lane **Jarvis-MAGIC**。 **MINOR**：`MagicDllFamilyClassifier` 門`scripts/scan_ab.py` 針對 C# — 依以下條件進行預先分類：`slot_kind_signature` + 在插槽 0 的 RVA 處掃描 2048 位元組的 PE 檔案 (`0xB2C/0xB30` → B，`0xB1C/0xB18` → C). 整合於`MagicDllSemanticAnalyzer.DetectFamily` 以及在`InspectionSummary` 來自 Magic DLL Browser。IDA 驗證：在桶 404 中被植入的 13 個 Family C DLL 檔案中，有 3 個樣本（`magic_0183`,`magic_0244`,`magic_0700`) 證實`host+2844/2840` 沒有`host+2860`. 文件：`docs/reverse/FFX_MAGIC_DLL_INFILTRATED_C_VALIDATION_2026-06-14.md`. 閘極位元組掃描 13/13 透過`work/validate_infiltrated_c/validate.py`. [上一頁：`v2.89.0.0`]
- **`v2.88.1.5` — Magic DLLs：實際反編譯（Hex-Rays）揭露了兩種效果架構，並證實了主機欄位。** Lane **Jarvis-MAGIC**。**修訂版** 關於`v2.88.1.4`: 已將 RE 保留在儲存庫中（反編譯 + 重新命名／註解在`.i64`)，且產品行為未發生任何變化。我捨棄了「依位置命名」的方式（即`MagicDllSemanticAnalyzer`) 並真的進行了反編譯`magic_0084` 以及`magic_0148` 在 IDA 中。核心發現：該語料庫包含 **≥2 種不同的架構**，而槽類型簽名無法將其區分開來（兩者皆具有`code` 在所有插槽中）：**「自含粒子」家族**（`magic_0084`: 1023 個粒子的本地池 + 256 個封包的環，無根節點`dat_et`; slot1 是繪圖時鐘；slot4 **會重新寫入其自身的覆蓋表** 以進入下一階段 — 此點亦在 `magi` 中得到確認

c_0688`) e **família B "root/record-interpreter"** (`magic_0148`: aloca o root de 1.024.000 bytes via host+3212, materializa via host+2860, e chama host+2864=`sub_80CD60` e host+2884=`sub_80BEA0` diretamente). Promovi ~20 host fields de `候選人` para **provado por chamada decompilada cross-DLL** (host+672 actor, +884/+888 timer, +900/+904/+908 phase/start/progress, +2860 materialize, +2864 interpreter, +2872/+2876 Ego obj, +2908 make-packet) e descobri o par novo **host+3216 (free)** de host+3212. Doc: `docs/reverse/FFX_MAGIC_DLL_DECOMPILED_FAMILIES_2026-06-13.md`. Bump do editor para `2.88.1.5`. Guardrail: ainda é RE de bytes, nomes descrevem papel (não símbolo original); slot-kind signature é proxy fraco — o classificador real de família é "slot 0 chama host+2860?". Validação: 2 `.i64` salvos no `magicFiles\FFX` com rename+comment; renames `17/17` (0084) e `10/10` (0148) OK. [anterior: `v2.88.1.4`] — Jarvis-MAGIC
- **`v2.88.1.4` — 深入研究：60fps 遊戲玩法搭配 30fps 的過場動畫／FMV。** Lane **Jarvis-FPS**。關於 **REVISION**`v2.88.1.3`：在儲存庫中保留了研究/RE，產品行為未作變更。該文件`docs/reverse/FFX_GAMEPLAY_60FPS_DEEP_RESEARCH_2026-06-13.md` 回應了使用者提出的新建議：過場動畫可維持 30fps，重點在於遊戲玩法。 結論：這雖縮小了視聽範圍，但並未將問題簡化為單純的渲染問題；遊戲玩法仍需區分場景、戰鬥、MSEQ、鏡頭、CTB、魔法／視覺特效、選單、載入畫面及迷你遊戲。該研究詳細闡述了四種路線：`visual 60` 透過幀生成／插值、幀步調／VRR／Present Doctor，以 60 幀率渲染並搭配 30 幀率模擬及內建插值器，以及`engine-exact 60fps` 在 Scout 證明時鐘可分離之前，這仍屬「登月計畫」。下一項技術步驟：`fps-scout` 唯讀模式，附 CSV/摘要檔來自`Present`，心跳/滴答聲、遊戲模式、MSEQ 游標以及在套用任何補丁前的 UnX/SpecialK 相容性。編輯器更新至`2.88.1.4`. 驗證：透過以下來源的文件錨點`Test-Path`/`rg`; 建置`work\_build_gameplay60_research_28814` 0 個錯誤 / 366 個基準警示。[上一版：`v2.88.1.3`] — Jarvis-FPS
- **`v2.88.1.3` — 60fps 測試／FPS 解鎖：區分幀生成、幀節奏與引擎精確度。*

* Lane **Jarvis-FPS**。關於**REVISION**`v2.88.1.2`：在儲存庫中保留了研究/RE，產品行為未作變更。該文件`docs/reverse/FFX_60FPS_UNLOCK_FEASIBILITY_RESEARCH_2026-06-13.md` 結論是，目前尚無證據顯示存在一條安全的、單一的 30→60 級路線；正確的路線可分為`visual 60` 透過幀生成／外部插值，30fps 下的幀節奏表現更佳；以 30fps 模擬並搭配內部插值渲染 60fps，以及`engine-exact 60fps` 作為「登月計畫／僅限研究」。交叉證據：UnX 透過倍增來進行速度作弊`FFX_GameTick` 與其解鎖標準幀率；Special K/UnX 提醒，30 幀的外部限制可能會影響載入速度，且部分選單以 60 幀運行；儲存庫中已包含 DINPUT8/main-thread、Present hook 及 MSEQ`frameRate=7680 (30fps*256)`，但魔法／戰鬥／過場動畫目前仍未達到幀級精準的時序。下一步的具體做法是：`fps-scout` 唯讀模式`FfxHooksDll`/`FfxDinput8Probe` 在套用任何補丁之前，請先測量 Present、tick、MSEQ 游標及遊戲模式。編輯器更新至`2.88.1.3`. 驗證：透過以下來源的文件連結`Test-Path`/`rg`; 建置`work\_build_fps_research_28813` 0 個錯誤 / 366 個基準警示。[上一版：`v2.88.1.2`] — Jarvis-FPS
- **`v2.88.1.2` — 魔法 DLL：透過分析相似法術之間的模式，以減少試錯次數來鎖定法術的顏色與施放速度。** Lane **Jarvis-MAGIC**。關於 **REVISION**`v2.88.1.1`: 研究／RE 已存入儲存庫，產品行為未變更。已核對`AiCommandMetadataCatalog.Generated.cs` (`979` 行，`689` 與`moveAnim`), CSV 疊加層 (`581` 行) 和 DLL 檔案`magicFiles\FFX\magic_####.dll` 以便根據實際外觀而非單純名稱進行分組。主要發現：`Power`/hits/status 位於命令列中；視覺效果則位於`moveAnim`；基礎的「火／雷／水」屬性遵循簡單的屬性相剋關係`nz9/u5`, Ice/curas/Flare-like 採用更廣泛的 PPP 系列；Cure/Potion 以及多種 Mixes 則重複使用相同的外觀；`Death` 證明名稱相同可能指向不同的 DLL；`Death` 常見的`magic_0098` 以及`Mega Death` `magic_0351` 共享疊加層／插槽／貼圖尺寸，但不共享雜湊值／有效載荷；克隆體`0714/0715` 繼續朝著「棱鏡閃光」的正確方向前進，同時不影響原版菲拉／桑達拉。安全防護措施：`pppColor`/`pppColMove`/`pppAccele`, floa

ts 和 pushes 會持續追蹤候選方案，直到 RT2/probe 驗證其顏色、速度或時序為止。編輯者將此貼文置頂至`2.88.1.2`. 驗證：透過以下來源的文件佐證`Test-Path`/`rg`; 建置`work\_build_magic_patterns_28812` 0 個錯誤 / 366 個基準警示。[上一版：`v2.88.1.1`] — Jarvis-MAGIC
- **`v2.88.1.1` — Arena+ pre-RT2：針對透過 DLL 在 NPC 中新增選項而進行版本控制的調查套件。** Lane **Jarvis-ARENA+**。關於 **REVISION**`v2.88.1`：將研究／RE 保留在儲存庫中，產品行為維持不變。對 Monster Arena／Arena+ 的檔案集進行版本更新：新增分頁／創作項目、透過 DLL 插入、因實際敗北觸發的 Dark Aeon／Penance 標記、NPC 選項、最終偵察員以及相關檔案`nagi0700` pre-RT2。核心發現：競技場的主人就生活在活動之中`nagi0700`;`w0E::f05` 建立選單`Now what?` 來源`Common.displayFieldChoice [013B]` 字串`[4A]`,`w0E::f07` 透過以下方式開啟選擇器：`SgEvent.showModularMenu [401D]`，發起爭取`Battle.launchBattle [7002]` 以及遭擊敗的創作品牌`0x0300..0x0322` 由`Common.setMonsterArenaUnlocked [0210]`. 編輯的置頂貼文，以`2.88.1.1`. 護欄：`research-only/pre-RT2`; 不要展開`ArenaUnlocks[35+]`, 勿編輯`nagi0700.ebp` 且在執行實機追蹤前，請勿插入原始資料列。驗證：`Test-Path` +`rg` 在資料夾、KB 和 handoff 的錨點中；建置`dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_versioning_28811 --no-restore` 0 個錯誤 / 366 個基準警示。[上一版：`v2.88.1`] — 賈維斯
- **`v2.88.1` — Magic Viewer Web：運行時模擬候選方案在主舞台上亮相。** Lane **Jarvis-MAGIC**。關於 **PATCH**`v2.88.0`：該檢視器新增了`Simulate`，將紋理幻燈片切換為由反向結構鏈驅動的連續循環（`sub_800530/590/950`,`sub_80CD60`,`sub_817200`,`root+84/root+88`、疊加槽及 Phyre 有效載荷）。該的貼圖`ps3data\magic` 現在它們是以效果的視覺素材形式出現，而非作為時鐘／幀清單；HUD 顯示階段、根游標、回調程式碼／資料以及 DLL 中的重複別名。Guardrail：這是`Runtime Simulation Candidate`，比……更不虛假`Cycle Surface`，但目前仍缺乏幀精確的時序、完整的指令碼解釋器，以及 RT2 相關聯功能

遊戲中的 callbacks/frame。編輯器中的 Bump 功能用於`2.88.1.0`. 驗證：`node --check RuntimeTools\FFXMagicViewerWeb\app.js`; HTTP`http://127.0.0.1:8766/index.html?magic=0688` 200；Chromium 無介面模式點擊`Simulate` 在桌面版和行動版上，390px 時無頁面錯誤／控制台錯誤，行動版無水平溢出，附螢幕截圖`work/magic_viewer_runtime_simulation_0688.png` 以及`work/magic_viewer_runtime_simulation_0688_mobile.png`; 建置`dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_magic_runtime_sim_2881 --no-restore` 0 個錯誤 / 366 個基準警示。[上一版：`v2.88.0`] — Jarvis-MAGIC
- **`v2.88.0` — Magic DLLs (FFX)：用於調整色彩、速度、計時器及候選向量的 Value Workbench。** Lane **Jarvis-MAGIC**。**MINOR** 關於`v2.87.1`：該分頁`Extras -> Magic DLLs (FFX) / Role Candidates` 現在有一個`Candidate Value Workbench` 可編輯工具，用於掃描所選的 DLL 檔案以搜尋`float32`,`vec3f/vec4f` 以及`push imm8/imm32`，將候選值分類為 alpha/cor/scale/speed/timer/flag/count，並允許以 decimal/float/comma-vector 格式填入新值，提供`Stage Patch` 或使用以下方式產生輸出 DLL：`Apply To Output`. 該區塊`Host Context / InitMagicPRX Fields` 也已納入支援：選取主機欄位，列出 DLL 中實際的 u32 出現位置，並允許替換具體的偏移量參考。Guardrail：名稱仍屬候選名單，每次變更都需要進行 RT2 測試以確認視覺語義／遊戲玩法。編輯器更新至`2.88.0.0`. 驗證：`dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_magicdll_value_workbench_probe --no-restore` 0 個錯誤 / 366 個基準警示。[上一版：`v2.87.1`] — Jarvis-MAGIC
- **`v2.87.1` — 內建 Magic Viewer：WebView2 的 404 錯誤熱修補程式。** Lane **Jarvis-MAGIC**。**PATCH** 關於`v2.87.0`：修正了門`8766` 那裡已經被一個佔用了`http.server` 古老的、深深植根於`RuntimeTools/FFXMagicViewerWeb`; 啟動器偵測到該埠處於活躍狀態，並導向至`/RuntimeTools/FFXMagicViewerWeb/index.html`，就在這個 404 伺服器上。`MagicViewerLauncher` 現在會測試 repo-root 這個 URL，如果它沒有回應，就會自動轉至 `/index。

html`, mantendo o viewer embutido funcional sem depender de matar o servidor manualmente. Bump do editor para `2.87.1.0`. Validacao: HTTP atual provou `/RuntimeTools/FFXMagicViewerWeb/index.html -> 404` e `/index.html -> 200`; build `work\_build_magicviewer_url_hotfix` com 0 erros / 366 avisos baseline. [anterior: `v2.87.0`] — Jarvis-MAGIC
- **`v2.87.0` — Magic DLLs (FFX)：Direct Patch Builder 直接內建於選單中。** Lane **Jarvis-MAGIC**。**MINOR** 關於`v2.86.2`：面積`Extras -> Magic DLLs (FFX)` 現在提供了一個直接編寫的控制面板，可從以下來源產生帶有位元組修補程式或 ASCII 修補程式的輸出 DLL：`file offset` 或`RVA`，重新利用現有的編譯器／修補計畫，無需使用者自行組建外部 JSON。所選的原始檔案不會被覆寫：按鈕總是會要求提供輸出 DLL。Guardrail 維持不變：`Role Candidates` 以及`Host Context / InitMagicPRX Fields` 仍有相關證據／候選名稱；要實現實際行為，必須針對特定位址修補位元組／字串／ASM，可透過手動 C/ASM 或 RT2 進行。將編輯器版本號提升至`2.87.0.0`. 驗證：`dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_magicdll_direct_patch_2870 --no-restore` 0 個錯誤 / 366 個基準警示。[上一版：`v2.86.2`] — Jarvis-MAGIC
- **`v2.86.2` — Magic Viewer Web 已成為主舞台上真正的 DLL/執行時檔案閱讀器。** Lane **Jarvis-MAGIC**。關於 **PATCH**`v2.86.1`: o`MagicCorpusIndexer` 現在直接閱讀`magicFiles\FFX\magic_####.dll` 並產生證據`runtimeDll` 在目錄中 (`runtime-dll-index.json`): 從包含候選角色的 CSV 檔案中保留的 PE 類型/機器/時間戳記、SHA-256、區段、匯出/匯入、字串/字形家族及疊加槽位。內建檢視器會開啟並顯示`Runtime Map` 在主視口中，於任何貼圖之前顯示：呈現 DLL、PE、匯出/匯入、區段、字串族、有效載荷連結以及實際的回呼/資料槽；`Cycle Surface` 以及`Stack Surface` 已轉為 Phyre/texture payload 的次要檢查模式。編輯器中的 Bump 功能已轉為`2.86.2.0`. 驗證：`MagicCorpusIndexer` 建置 0 個錯誤；建置編輯器位於`work\_build_magic_runtime_reader_2862` 0 個錯誤 / 366 個基準警示；已使用`587 entries`,

 `580 ps3 magic`,`583 runtime DLLs`,`581 overlay rows`; HTTP 200; Edge 無頭模式已驗證`magic=0688` 以及`magic=0003` 與`Runtime Map` 資產，`slotCount=16`，無頁面錯誤，附有螢幕截圖，位於`work/magic_viewer_runtime_map_0688.png` 以及`work/magic_viewer_runtime_map_0003.png`; 行動版 390px，無水平溢出。實情：使用 carrier runtime/Phyre 的真實播放器；目前仍無法實現幀級精確播放，timeline/compiler 及 RT2 亦無法做到。[上一則：`v2.86.1`] — Jarvis-MAGIC
- **🔮`v2.86.1` — Ponte Battle Commands → PS3 Magic + Magic Viewer Web 已解鎖。** 頻道 **Jarvis-MAGIC**。**更新** 關於`v2.86.0`：關於已發布功能的再利用／便利性，以及開機設定／目錄。這些欄位`Anim 1 Id` /`Anim 2 Id` 在`Battle Commands / Monster Commands` 現在顯示摘要`magic_####`, 按鈕`View Anim 1/2` 點此開啟`Extras / PS3 Magic (HD)` 效果已過濾，以及按鈕`Open Folder` 當該資料夾存在於`ps3data\magic`. 同時也修正了內建的 Magic Viewer Web，使其使用`three`/`OrbitControls` 透過相對路徑的 imports 來載入本地檔案，藉此消除可能導致畫面卡住的依賴關係`Loading catalog`; 若 WebGL 發生錯誤，系統會顯示錯誤訊息，而非默默終止目錄。編輯器已將此問題上報至`2.86.1.0`. 驗證：`dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_versioning_2861` 錯誤數為 0；HTML/供應商/目錄透過 HTTP 200 狀態碼傳送；CDP/Chrome 已確認`585 entries`,`583` 項目及`exceptions=[]`; 螢幕截圖位於`work/magic_viewer_web_smoke_fixed.png`. 誠實說明：HD 預覽為近似紋理／合成效果；時間軸／回調引擎精準度仍維持在 DLL／執行時層級，且需通過 RT2 測試方能進行最終遊戲遊玩。[前文：`v2.86.0`] — Jarvis-MAGIC
- **🔮`v2.86.0` — 新內容創作實驗室。** Lane **Jarvis-MAGIC**。**MINOR** 關於`v2.85.2`: 正式發布已納入提交的新內容實驗室套件`ac2f5ebe`. 包含 AutoAbility writer AU1..AU7、Monster Magic/Prism Flare 工具、Magic DLLs (FFX)、僅支援提取功能的 VBF Extract、PS3 Magic 貼圖輸入/輸出以及 Phyre Package 輸入/輸出。編輯器已升級至`2.86.0.0`. 誠實：魔法／特效／紋理的實驗室仍分別分為 RT0／離線、同形狀紋理 I/O 以及

RT2 手冊；時間軸／回調引擎精確的連續 DLL／執行時。 [上一頁：`v2.85.2`] — Jarvis-MAGIC
- **🧠`v2.85.2` — Monster AI Editor：公開「禁忌儀式」＋讀取階段管理員的狀態。** Lane **Jarvis-MAGIC**。**PATCH** 關於`v2.85.1`: 移除公章`LAB` 來自《禁忌儀式》/var priv/writer 的輪替機制，已證實為作者權限流程；移除`Sequência / Multi-*` 為避免出售偽造的 Multi-* 產品，採用快速處理流程，並在視窗中維持預定的順序`Ação composta`；每回合追加「禁忌儀式」，並在「回合管理器」中儲存額外生命值；修正建構器`Condição multivar livre` 以重新開放該`ConditionGuard` 在重新啟動／重新審核後所選階段的，透過解碼形狀堆疊／RPN（`cond1 cond2 E/OU`) 並在解讀前移除隨機尾數。編輯者將此貼文置頂至`2.85.2.0`. 驗證：在隔離環境中進行建置，0 個錯誤，`phase-rotation-rt0` 319/319 其中`var1 store when present` 300/300，以及`multivar-guard-rt0` 300/300。遊戲中的 RT2 仍為最終遊戲流程的必備條件。[前一則：`v2.85.1`] — Jarvis-MAGIC
- **🧠`v2.85.1` — Monster AI Editor：相位旋轉管理器的穩定性。** Lane **Jarvis-MAGIC**。關於 **PATCH**`v2.85.0`: 修正了當篩選器／選卡器重新建構時，關卡卡牌會出現技能消失的問題`PhaseAbilityOptions`，使用`SelectedPhaseAbility` 作為穩定投影並忽略`null` ComboBox 的過渡狀態；重建 LAB v1 的讀回功能`guard -> performCommand -> mutação de var -> RET/JMP`; 移除原本會觸發的自動固定功能`Fluxo de Raio`/`Fluxo de Fogo` 跳至頂部並清除視覺選取範圍；保留條件／守護者，透過`AliasKey`，避免使用者介面回到第一個變數。將編輯器的 Bump 調整為`2.85.1.0`. 驗證：建置 0 個錯誤，`phase-rotation-rt0` 319/319 其中`var1 store when present` 300/300，以及`multivar-guard-rt0` 300/300。[上一頁：`v2.85.0`] — Jarvis-MAGIC
- **🧠`v2.85.0` — Monster AI Editor：相位輪替管理器、多變數條件與西摩複合動作。** Lane **Jarvis-MAGIC**。 **MINOR**（Monster AI Editor 的新功能，並在同一則聊天訊息中彙整了多項錯誤修正）。新增了`PhaseRotationRecipe` LAB v1：透過 `AppendGu` 執行的階段

ardedAction`, condição própria por fase ou fallback, alvo/chance por fase, mutações de var por fase (`+最小值..+最大值` e reset), `請在此停下`/RET e gravação com backup em monstro de teste. A janela de rotação agora audita vars, permite apelidos por monstro, cria var `priv` livre em LAB, monta condições multivar livres e preserva draft por contador/var. Também entra a janela de `複合動作 · 西摩`, para montar sequências explícitas de habilidades com alvo entendido e Forbidden Rite planejado entre passos. Corrige bugs de estado do builder: avanço/reset escrevem a var explicitamente escolhida, a condição da fase não sobrescreve outras fases, reauditar preserva a var ativa, e o filtro de habilidade não apaga Thunder/Water/etc já usados no draft. AiScriptLab ganhou gates `--var-grow`, `--var-flow`, `--multivar-guard-rt0` e `--phase-rotation-rt0`; validação usada: build 0 erros, `phase-rotation-rt0` 319/319 com `若存在，則將 var1 儲存起來` 300/300, e `multivar-guard-rt0` 300/300. Honestidade: writer LAB/offline; RT2 em jogo ainda obrigatório antes de chamar rotação de fase de comportamento final. [anterior: `v2.84.25`] — Jarvis-MAGIC
- **🧠`v2.84.25` — Monster AI Editor：Yunalesca 已轉為乾淨預設，相關條件已移至主要創作流程中。** Lane **Jarvis-MAGIC**。**累積修補程式 +5** 以上`v2.84.20`：修正了該畫面中的使用者體驗／合約設定，此前該區塊仍將快速儀式、狀態與進階編輯混雜於同一區塊中。YUNALESCA 現已僅作為狀態／祝福預設值的專用區域，不包含戰鬥儀式，也不包含`Revezar 1/2`，沒有`Revezar 1/3`，沒有`Duplicar cast` 且省略了冗餘的條件前置語句。條件建構子已重新配置至`Adicionar / trocar comportamento`，該出版社的招牌作品：`onTurn`,`Início`,`Sempre`,`onHit`,`Qualquer Hit`,`HP < %` 以及`Talvez 1 em K` 開始準備接下來要建立／更換的行為。主選單列現在僅聚焦於所選的動作（`Trocar habilidade`,`Duplicar ação`,`Subir/Descer`,`Modo: fila/agora`,`Tirar ação`,`Desfazer backup`). 後端新增了帶有明確守護的途徑，可在騎乘狀態下建立技能、複製行動模板並綁定「禁忌儀式」，且無需出售

這是一項 Monster AI Editor 之外的新功能。已調整「禁忌儀式」的描述以符合事實：該功能會在授權點處建立／變更行為後立即套用「反緞帶」效果；且不會顯示先前錯誤的提示，即`Multi-*` 必然會發生錯誤。在獨立輸出環境中編譯時，未出現任何錯誤。[先前：`v2.84.20.1`] — Jarvis-MAGIC
- **📚`v2.84.20.1` — 研究：創建全新「自動能力」（武器／護甲技能）的可行性 — 涵蓋所有路線 + 配方手冊（byte-recipe）。** Lane **Jarvis-MAGIC**。 **修訂**（第 4 位數字：文件/RE/納入儲存庫的研究，且 **不改變行為** — 未觸及任何寫入器/模組/綁定）。 多代理研究（3 個工作流程，並行運行搜尋器 + 對抗性驗證），以釐清是否及如何能在 FFX HD PC 版中創建新的自動能力。 **結論：** 是的，包含「新」的 3 種含義，以及 **資料驅動 vs 透過 ID 硬編碼** 的明確區分。 (1) **透過旗標組合產生的效果**屬於資料驅動型，且**已透過 IDA 的偏移量驗證**（`sub_79C610`/`sub_7861B0` OR-累積記錄欄位`0x6C` 在演員 **sem`switch` 透過 ID**) → 任何插槽僅需設定位元組即可繼承該效果； **完整的位元組食譜** 透過 diff 解碼`a_ability.bin` 已發貨（項目`0x11-0x15` Fire`01`/Ice`02`/Thunder`04`/水`08`/Holy`10`; 狀態 touch=`0x16+slot=50`/strike=100; stat%`0x55`+`0x56`; 自動/SOS`0x5A`+`0x10`; 功能區`0x3C+slot=255`+`0x60`). (2) **5 個實際可用插槽 129–133 (`0x81-0x85`)** (全零日期) → 重新分配，無需擴展資料表。 (3) **擴展 >0x86：** 出乎意料——**引擎接受**第 135 個條目 (`sub_7AB890` 讀取 **檔案標頭** 中的 count/range，不包含字面值`0x86`; 緩衝區大小依據檔案大小而定）；僅由 3 個 C# 守護程式 + RT2 + 位元組大小限制所鎖定`0x25800` + 第二套裝備選單結構`0xC8=200`. **硬性限制：** 約 31 項能力是透過 ID 硬編碼的（1 位元在`0x62/0x64/0x66`, C 語言處理程式 — 感測器／首擊／反擊／穿透／突破極限／擒獲／等）→ **無法透過位元組重現**；新類型的 KIND 效果（吸血／反射%）僅能透過 **DLL 掛鉤** 實現（基礎架構`DINPUT8` probe +`FfxHooksDll` PolyHook2 **已驗證**）或 exe 修補程式。**ability-as-script (ATEL)** 已被駁斥為無鉤式（hook-free）方法

玩家可裝備（綁定間隙）。經 3 個獨立串流交叉驗證，並與 **fahrenheit** 開源結構體（逐位元組）比對。 **誠實聲明：** 經編輯的真實插槽遊戲畫面，且所有內容均為運行時/鉤子操作 = **RT2/LAB 待定**；`a_ability.bin` 接下來的內容`reader+no-edit guard` 處於生產環境（無發貨授權）。文件：`docs/reverse/FFX_AUTOABILITIES_NOVAS_MASTER_2026-06-11.md` (目錄／結論) +`FFX_NEW_AUTO_ABILITY_FEASIBILITY_2026-06-11.md` (靜態) +`FFX_AUTO_ABILITY_NEW_VIA_HOOK_DLL_RUNTIME_FEASIBILITY_2026-06-11.md` (執行階段/DLL) +`FFX_AUTOABILITIES_NOVAS_VIAS_E_FORMULAS_COOKBOOK_2026-06-11.md` (12 種方法 + 食譜集)。[上一頁：`v2.84.20`] — Jarvis-MAGIC
- **`v2.84.20` — Monster AI Editor：針對《Forbidden Rite/Anti-Ribbon》及行為的人類可讀性，新增 10 個錯誤修復補丁。** Lane **Jarvis-MAGIC**。**累積補丁** 關於`v2.84.10`: 修整表面`Forbidden Rite LAB` 該標準仍僅呈現了實際標準中的一個子集`writeChrProperty(target, field, value)` 先前已支援此功能。Anti-Ribbon 下拉式選單現在會列出負值直接欄位：`Poison`,`Petrify`,`Power Break`,`Magic Break`,`Armor Break`,`Mental Break`,`Berserk`,`Sleep(255)`,`Slow(255)`，此外還有先進的`Provoke`/`Threaten`，並維持`Zombie`,`Confuse`,`Silence(255)`,`Darkness(255)`,`Curse`,`Doom` 以及《毀滅戰士》的反制措施。`Zombie`/`Confuse`/`Silence`/`Darkness` 在現行標準下，這些會明確標記為「RT2/遊戲內」已驗證；該擴展則會註明為由操作員透過同一條直連路徑進行遊戲內測試。`Death/KO` 之所以未列入標準下拉選單中，是因為該地圖的`btlActorProperty` 闡述`isAlive`，而不是一個`StatusDeath` 已清理；這需要單獨的處方／閘門。已更新《聖經》及 SIN／Anti-Ribbon 計畫，以防止下一位特工重新開啟已解決的封鎖。同時也對近期關於`Multi-*` vs`Sequencial-*`、動態循環、Dark Flan 以及 Seymour Natus，作為未來設計的參考。**誠實聲明：**這是對現有 Monster AI Editor 的錯誤修復與強化；並不會在`Forbidden Rite LAB`. [上一頁：`v2.84.10`] — Jarvis-MAGIC
- **🧠`v2.84.10` — Monster AI Editor：10 個修補檔的整合

一些關於錯誤/使用者體驗/安全防護措施的小修正，沒有新增功能。** Lane **Jarvis-MAGIC**。關於**累積性修補程式**`v2.84.0`：RT2/實際使用測試顯示，Monster AI 的人類介面需要進行合約修正，而非新增一個分頁。此項調整將移除該子分頁`Monster AI Editor 2` 導航功能，並將作者權集中於`Monster AI Editor` 主要；使大型區塊可折疊；將 AEON/YUNALESCA/BIBLE/Live/actions 重新歸類為供人閱讀的內容；修正`Talvez` 位置，以免重新載入整個入口點；新增`Pare aqui` 與`RET` 受控；當沒有原生證明時，會將虛假組合降級並切換為直接序列；防止徽章`forçada` 純屬偶然地誕生；清除 YUNALESCA 狀態的洩漏；交換`NulAll` 對真實魔法；阻擋在`Início` 當執行時環境未將動作排入佇列時；優化條件標籤／工作單位標籤；修正「綁定目標／首個技能／同一目標」機制；新增「Shred 風格」的計算目標配方＋較低生命值；強化關卡門檻`AiScriptLab --ai3` 針對本地機率、關聯儀式、目標配方、計算目標及停止後；維持對以下項目的實際鎖定：`Multi-*` 自然 + 《Forbidden Rite》及待處理的 RT2。**誠實聲明：**這是針對現有 Monster AI Editor 的錯誤修復／強化；並未新增超出範圍的寫入器。[前一則：`v2.84.0`] — Jarvis-MAGIC
- **🧩`v2.84.0` — 介面（UI）全面響應式設計：流暢幀率 + 跨應用程式掃描所有視窗的「強制尺寸」設定 + 可重複使用的斷點基礎架構。** Lane **Jarvis-UI**（橫向掃描 — 涵蓋幾乎所有模組的 UI：MAGIC/MAP/HD）。 遵循業主指示：*「不再使用固定尺寸，一切皆為響應式且可自動調整大小，美觀優先於效能，將計算負載轉嫁給用戶的電腦」*。**新基礎架構：**`Styles/Responsive.cs` — 附屬屬性`Responsive.Breakpoints` 透過類別來標記根節點`narrow`/`medium`/`wide` 根據實際渲染的寬度，進行`Style Selector` 發揮類似 CSS「媒體查詢」的功能。**Frame (`Main_Window`):** 290/320px 的固定側邊欄 → 欄位`Auto` 與`MinWidth`/`MaxWidth`；右側的檢查員收回（欄位`Auto`→0) 當視窗寬度不足時，僅在寬螢幕上顯示 3 欄；

`MinWidth` 1280→1000；頂部工具列包含`ComboBox` 固定寬度 →`MinWidth`; 已啟用的斷點。**應用程式範圍內掃描 (65/71)`.axaml` 透過多代理協調機制進行調整——每個檔案對應一個代理，僅進行「精準」的版面配置調整）：**`ColumnDefinitions` 以像素計 137→59 (−78)；`StackPanel Orientation="Horizontal"` →`WrapPanel` (×26；共 252) 讓按鈕／輸入欄位斷開，而非被截斷；`ScrollViewer` 一個安全機制，讓根目錄可能爆表；`Viewbox` 在`SphereGridCanvas`; WebView 的主機 (`*Embedded`) 伸展；`TextWrapping` 缺失之處；`Width`/`Height` 固定欄位 231→211 及 35→27（其餘為內建欄位：圖示、數值欄位、欄位）`DataGrid` 以及對齊寬度在`WrapPanel` 已經退潮——不會被截斷）。**次要**（響應式設計的新基礎架構 + UI 的跨平台相容性）。**誠實而言：**這 75 個畫面都能成功編譯（Release 版本 **0 個錯誤**；轉義符處理`&` /`<` /`>` （由綠色版本保證）且 **沒有`{Binding}`/`Click`/`x:Name` 已進行修改**（僅為版面配置調整）——但**針對小視窗的逐螢幕視覺品質檢查仍是待處理的人工步驟**（尚未在 75 種螢幕尺寸上執行應用程式；結構與編譯已通過測試，外觀尚未測試）。 不涉及邏輯/儲存/AI/執行時/RT2/Spira Forge。檔案：`Styles/Responsive.cs` (新) +`Modules/Main/Main_Window.axaml` + 65`.axaml` 模組／控制項／範本。[上一頁：`v2.83.0`] — Jarvis-UI
- **🧠`v2.83.0` — Monster AI Editor 2：將「人類模式」以獨立分頁形式實作，具備行為介面、多選功能、保守式拖放、縮放時壓縮較少、人類版 AEON，以及已協調的 SIN/HP% 閘門。** Lane **Jarvis-MAGIC**（Monster AI Editor / AI 工具組）。實現了業主要求的重大轉變：Editor 2 不再是技術上的複製品，而是成為了基於真實引擎之上的「人類視窗」。新增子分頁`Monster AI Editor 2` 開啟`MonsterAiEditor2_Control`；編輯器 1 將保留為 DevKit／舊版。畫面 2 組織`Normal / Avançado / DevKit`: 不釋放指令碼的行為卡、控制面板`Editar esta ação`, YUNALESCA/BIBLE/SIN/AEON/Live/DevKit 經由人類理解重新配置，AEON 人類差異，安全／情境徽章 (`ramo condicional`,`outro worker`, `安全可操作`

nica`), combo visual, seleção em lote, limpar lote, comandos batch-aware, drag/drop por alça para grupo consecutivo/autocontido, e layout responsivo que empilha áreas em vez de espremer a janela. Backend novo: `MonsterAiEditor_DataModel.HumanMode.cs`, `.Behavior.cs`, `.HumanDiff.cs`, `.InlineEdit.cs`, `MonsterAiEditor_ActionDrag.cs`, `MonsterAiEditor2_Control.axaml(.cs)` e reuso direto de `AiAutomation`/`AiValidator`/`AiScript_Diff`/`AppendGuardedAction`. Também corrige contratos antigos de HP%: `0x17=MUL`, `0x16=DIV`; SIN-010 deixa de ser bloqueado pelo bug velho e continua honestamente preso a payload/jump-slots/RT2/operator gates. Docs/protótipos versionados: plano de superfície total, pesquisa de acessibilidade humana, protótipo HTML e handoffs de agentes. **MINOR** (nova aba/capacidade de edição humana real). **Honestidade:** RT0/build/gates cobrem estrutura; efeito in-game e patches loose-file como o Skoll `m014` seguem prova RT2/manual. [anterior: `v2.82.0`] — Jarvis-MAGIC
- **🧠`v2.82.0` — Monster AI Editor：在清單中直接進行高階操作編輯（即時變更增益效果／屬性的狀態與數值，無需彙編）＋頂部設有經典操作按鈕（儲存／撤銷／還原／更新）。** Lane **Jarvis-MAGIC**（Monster AI Editor）。解決了擁有者提出的 *「當前 AI 未能反映真實智慧」* 以及 *「頂部缺少經典按鈕」* 這兩項抱怨。 **正確的重新框架（根據擁有者回饋）：** **已識別的動作清單本身就是** 關鍵的智慧 — 增益效果（🛡）、屬性（📊）、指令（⚔）； 其價值在於使其**能直接在該處編輯**，而非顯示操作碼（最初一個會按工作線輸出反彙編碼的版本，因與 DevView 功能重複而**被淘汰**）。 **內嵌編輯器（新功能）：** 選取一個增益效果／屬性 → 變更 **狀態／欄位**（下拉選單）與 **數值**（輸入欄） → **💾 套用** 將對兩個操作數進行 **位元組級** 編輯`PUSHII` 現有陳述式的 (field + value)，並儲存該`monster_*.bin` 與`.prev.bak` （與「儲存」的路徑相同）。該陳述式的位置：field instr 在`CmdPushOffset`, 位於`CALLPOPA`; 僅在兩者皆為時才生效`PUSHII` 字面值（固定值，非計算結果）。**會話 Chrome（card no t

opo)：** 💾 儲存 (`HasPendingEdits`) · ↶ 撤銷 (`.prev.bak`/`CanUndoBackup`) · ♻ 還原原版（2 個步驟） · ⟳ 更新 — 基於現有的方法（只差那個橫桿；該`Save` （埋藏在匯編器區段中）。**MINOR**（新功能：在清單內直接執行內聯操作的首個版本）。**範圍／準確性：** **位元組局部** 編輯（操作數，相同大小，經 RT0 驗證）； **插入／移除／重新排序以及在工作處理器之間「移動」動作仍遵循結構化規則（下個版本將實作）** — 工作處理器的類型（MotionHandler／CombatHandler）是從程式碼推斷出來的，而非預先設定的標籤。 不觸及 SIN（遵循 BLOCKED 規則以供公開寫入）/runtime/RT2/Aurora/native-menu/Blitzball/Shop/Mix/Sphere/`Common`(ANIMA)/其他語系。Build Release **0 個錯誤**。檔案：`Modules/MonsterAiEditor/MonsterAiEditor_DataModel.InlineEdit.cs` (新) +`MonsterAiEditor_DataModel.cs` +`MonsterAiEditor_DataModel.Automations.cs` (1 行) +`MonsterAiEditor_Control.axaml(.cs)`. [上一頁：`v2.81.0`] — Jarvis-MAGIC
- **🔌`v2.81.0` — SIN Gate 6 LIVE 連結：階段操作員控制 + 對 SIN-006 驅動程式的 RAM 唯讀驗證 — 驗證戰鬥中載入的是哪個映像；實際的交換操作仍需手動進行；SIN 對公眾寫入仍處於「封鎖」狀態。** Lane **Jarvis-YU-YEVON** (MAGIC/SIN)。 根據 RAM 檢測所證實的「誠實分工」，建構 **SIN→probe 連結**：**SIN-006 擴充了腳本（+15 條指令、+2 個跳轉槽），而擴充後的腳本無法直接注入 live 區域** — 怪物緩衝區的分配大小與檔案完全一致（WorkerFile 緊接在 AiFile 之後），且 VM 結構是根據原始計數預先尺寸設定的（`FFX_Atel_ComputeScriptChunksSize @0x86A220` /`ComputeScriptDataSize @0x86C050`); 因此，放大後的影像會透過 **RELOAD 路徑** 傳入（由操作員手動交換檔案，執行 C1-C6 運行手冊），而貼合器在實際運作中僅會進行 **驗證**，絕不會寫入。**`FfxLib/Ai/Sin`**: **`SinRt2LiveProbe`** (唯讀：`Status` 遊戲活躍度／RAM／探測／戰鬥；`LocateMonster` 採用經 RT2 驗證的鏈條，`MonsterAiEditor` —`ADDR_BATTLE_ACTIVE 0xD2A8E0` →`POINTER_BATTLE_ENEMY_LIST 0xD34460` → stride`0xF90` →`Id-0x1000` → `Ptr_script_chunks +0xF

78`; `ClassifyLiveAi` compara byte-exato o AiFile live contra as fatias ORIGINAL e EDITADA → `MatchesOriginal`/`已編輯的比賽`/`Diverges`/`無法閱讀`) e **`SinRt2LiveSession`** (`實習` operator-gated: re-roda elegibilidade RT2 + round-trip sandbox provado e persiste em `work/sin_rt2_live/` os artefatos `*.original.bin`/`*.sin006.bin`/`MANIFEST.txt` com SHA-256s + aim + efeito-de-tela; `VerifyLive` read-only com skip honesto sem jogo/batalha; guard de stage endurecido com separador — só sob `work/`). `SinSandboxApplyResult` ganha **`EditedMonsterBytes`** (contrato previsto no handoff do PENANCE: o RT2 reusa os MESMOS bytes provados, sem re-emitir). 3 flags novos: **`--sin-pilot-rt2-live-rt0`** (self-test headless: stage prova artefatos+SHAs+`+15`+parse-clean; recusas sem permissão/SIN-009/SIN-010 deixam ZERO arquivos; verify sem jogo → not-ready honesto sem throw; guarda de filesystem + cleanup), **`--sin-pilot-rt2-stage`** (comando do operador, mantém os artefatos) e **`--sin-pilot-rt2-verify`** (comando do operador, read-only: qual imagem está na RAM da batalha — `已編輯的比賽` prova só o LOAD estrutural; o efeito na tela continua veredito humano). **MINOR** (capacidade NOVA executável: camada LIVE glue + 3 flags). **Escopo/honestidade:** nenhum caminho de escrita em arquivo real/jogo/RAM existe nesta camada; staging não é apply; SIN **continua BLOCKED para escrita pública**; SIN-009/010 continuam fora; `0x16/0x17` intocado. Build 0 erros; `--sin-pilot-rt2-live-rt0` + os 8 gates anteriores todos **PASS**. [anterior: `v2.80.0`] — Jarvis-YU-YEVON
- **🕹️`v2.80.0` — SIN Chain Builder 第 6 道閘口：RT2 遊戲內試行版 PREFLIGHT 由操作員控制 — 模擬 SIN-006 試行版，不執行 RT2；實際狀態 = RT2-pending；SIN 對公開寫入仍處於 BLOCKED 狀態。** Lane **Jarvis-YU-YEVON** (MAGIC/SIN)。開啟 SIN Chain Builder 的 **Gate 6**：證明， **無頭模式且無虛假狀態**，證明已在沙盒（Gate 5/PENANCE）中驗證過的 SIN-006 切片，**適合在由操作員主導的 RT2 試運行中進行模擬** — 且絕不觸及正在運行的遊戲，在`dinput8 probe` 或是一個真實的檔案，且**未聲稱具有遊戲內效果**。回答 *「最低規格機體 SIN-006 已準備好可供駕駛 R

「T2 已確認安全，操作員還需注意什麼？」* — 螢幕上的確認仍屬 **人工步驟**（因此結果為 **RT2-pending**，絕不會自動顯示「通過」）。**中的新類別`FfxLib/Ai/Sin`**: **`SinRt2PilotGate`** (`SinRt2Eligibility` — RT2 的適用範圍比沙盒 **更為狹窄**：(1) 許可`AllowRt2InGamePilot` 明確且**與**`AllowSandboxApply`; (2) **RT2 允許清單** 中的 id = 今天 **僅`SIN-006`**; (3) **固有形狀** 雙重保險設計，以防標籤錯誤：單一結，`Trigger=OnTurn` 經證實已解決，`Condition=Always` (**無生命值百分比/`0x16`-`0x17`**)，全部`Action` =`GrantChrProperty` 在 **Self 0xFFF3**（**無指令有效載荷**）中），**`SinRt2PilotSession`**（**preflight** 協調器：執行 RT2 資格檢查，**重複使用已驗證的沙盒往返流程**）`SinSandboxApplySession` （複製 → 備份 → 發送 → 保守差異比對 → 字節級精確還原），模擬目標（工作節點／入口點）＋待確認的螢幕效果，並**暫停**——實際套用＋觀察由操作員執行， **此處未實作**），以及 **`SinRt2PilotResult`** (`SinRt2Outcome` `Blocked`/`Skipped`/`SandboxProofFailed`/`PreflightReady` +`SinRt2OperatorVerdict` 預設 **`Pending`** + 範本；`RealApplyDone`/`Rt2Confirmed`/`PublicApplyAllowed` = **因設計原因不適用**)。**適用範圍（僅限 SIN-006）：** SIN-006 +`AllowRt2InGamePilot=true` + 語料庫 → **PREFLIGHT-READY** (`m201`, OnTurn 工作節點 0/第 2 集, 差異 **+15 ~0 -0**, **還原字節完全相同**, 語料庫／副本 SHA 值未變更`B4C0FB90…012F`, 判定結果 **待定**, RT2/RealApply/PublicApply **否**）；**未獲授權**的情況下，直至 SIN-006 皆為 **被封鎖**（由操作員控制，RT2 授權與沙箱分開）； **SIN-009**（指令有效載荷候選）與 **SIN-010**（HP% /`0x16`-`0x17`) = **不符合 RT2 資格**（遭允許清單 + shape 阻擋）。新閘道 **`--sin-pilot-rt2-rt0`**：執行這 4 種情況，驗證 RT2-pending 的不變式 + **檔案系統守護**（未寫入`work/`, 沒有`.prev.bak`/`monster_*.bin` 在輸出目錄中，所有實際的固定裝置皆為唯讀且雜湊值未變更，且在結尾處清空測試目錄），且 **沒有即時套用的路徑**（`SinRt2PilotSession` 從不寫入實際檔案，也不執行 pr

obe)。**MINOR**（可執行 NOVA 功能：RT2 預檢層 + gate）。 **適用範圍／真實性：** SIN **仍處於「BLOCKED」狀態，無法公開寫入** — *Gate 6 預檢僅驗證受控的 RT2 試行版本，而非範本庫*；**未經 RT2 驗證，非公開按鈕**；`Rt2Confirmed=NO`/`RealApplyDone=NO`/`PublicApplyAllowed=NO`. **不要**修正`0x16/0x17`，**請勿**修改 SIN-009/010，**請勿**在`MonsterAiEditor`; **不要**碰`monster_*.bin` real/遊戲/probe/Aurora/native-menu/閃電球/商店/組合/球體/`Common`(ANIMA)；重新使用 Gate 2-5 已驗證的堆疊。編譯 0 個錯誤；`--sin-pilot-rt2-rt0` +`--sin-sandbox-rt0` (5號登機口) +`--sin-aeon-preview-rt0` (4號登機口) +`--sin-validate-rt0` (3號登機口) +`--sin-dryrun-rt0` (第 2 號閘口) +`--aicmdmeta-rt0` +`--spiraatlas-rt0` +`--aiasm-rt0` 全部 **通過**。文件：`docs/ai/SIN_YU_YEVON_RT2_INGAME_PILOT_RESULT_2026-06-10.md` +`docs/ai/SIN_YU_YEVON_RT2_OPERATOR_RUNBOOK_2026-06-10.md` +`docs/ai/HANDOFF_YU_YEVON_SIN_AUTHORING_PROMOTION_NEXT_2026-06-10.md`. [上一頁：`v2.79.0`] — Jarvis-YU-YEVON
- **🛡️`v2.79.0` — SIN Chain Builder Gate 5：備份／套用 SANDBOX 操作員控制 — 套用至一次性副本並撤銷字節完全相同的區塊；SIN 維持 BLOCKED 狀態以進行公開寫入。** Lane **Jarvis-PENANCE** (MAGIC/SIN)。 開啟 SIN Chain Builder 的 **Gate 5**：證明一個`SinApplyPlan` 經 Gate 3/NEMESIS 驗證並由 AEON（Gate 4/OMEGA）審查的內容，可於 **沙盒／受控副本中套用與撤銷** —— 無需觸及遊戲本身，亦無需觸及用戶的實際檔案， **無需 RT2 且無公開按鈕**。*沙盒備份／套用並非公開編輯功能。* 新的沙盒專用類別位於 **`FfxLib/Ai/Sin`**: **`SinSandboxApplyGate`** (`SinSandboxEligibility` — 8 項唯讀條件：結構上有效 ·`ApplyAcceptable` 繼續 false · 權限`AllowSandboxApply` 明確且獨立 · AEON ADDED-only · **除可清除的支架外，無任何關鍵阻斷器**，此規則用於區分第 5 道閘（Gate 5）所解決的阻斷器（`plan-blocker`/`rung-ladder`) 實際值（有效載荷候選/被封鎖，`divmul-integrity`,`jump-slots`, step-blocker)), **`SinSandboxApplySession`**（協調器：複製 → 寫入前備份 → 重新執行）

（僅在副本上操作 → 實際差異比對 → 驗證原始檔未遭修改 → 還原 → 位元組完全一致），**`SinSandboxBackup`** (`.prev.bak` 副本 + 預影像雜湊值 +`Restore`), **`SinSandboxRestoreVerifier`** (SHA-256 + 位元組比對) 以及 **`SinSandboxApplyResult`**（可檢查的結果 + 輸出範本）。**透過經過驗證的編解碼器套用 REAL：**對於符合資格的食譜，載入一份**真實怪物的拋棄式副本**（語料庫的唯讀副本 →`work/`)，透過 ** 組裝線性機身`AppendGuardedAction`(永遠守護真理`PUSHII 1`)** — 唯一一種乾淨且可自行重新定位的方法，會 **將程式碼附加至末尾**（現有偏移量保持不變），並執行`SpliceAiFileIntoMonsterGrow`, 重新讀取（重新解析乾淨 = rung`offline-emittable`)，執行 **`AiScript_Diff.Compare(original, edited)` REAL**（僅包含所需的 **ADDED** 區塊，**0 項修改 / 0 項移除** = 階梯）`AEON-reviewed`, 無漂移) +`AiValidator.ValidateRebuilt` (rung`AiScriptLab-clean`)，然後才**在副本上書寫**（在`.prev.bak` = rung`backup-ready`). **3 項試行配方（基於誠信的決定，非綠色力量）：** **SIN-006**（貝維爾面紗，第1回合自我增益；目標為已驗證的自身，**無指令有效載荷**，無0x16/0x17）= **唯一符合資格者** → 在沙盒中實際應用（`m201`, OnTurn 已透過以下方式解決：`AiWorkerMapping.TryResolveCombatOnTurn`, diff **+15 ~0 -0**, **字節級完全還原**, 原始檔／語料庫雜湊值未變更); **SIN-009**（學士令；有效載荷 **候選**）= **被封鎖**（採取保守立場；一次性副本不能作為編寫不誠實有效載荷的藉口；決策已記錄在案）； **SIN-010**（Farplane Toll，HP%）= 因 **`0x16` DIV 與目標 HP%-乘數** (`divmul-integrity`) — *0x16/0x17 是其他路線的專用 PATCH，此處絕不會進行修正*。進一步證據：**未經許可`AllowSandboxApply`，直到 SIN-006 為止皆處於 BLOCKED** 狀態（由運算子觸發）；任何 **意外的差異（篡改）** 都會被相同的保守判準所拒絕（`+0 ~1 -0 → conservative=False`); **原文從未被寫下** (`AppliedToOriginal=NO`, 參考副本 E 及語料庫中真實來源的雜湊驗證)。新閘門 **`--sin-sandbox-rt0`**：執行這 3 個指令，測試備份／還原／隔離功能，以及 **檔案系統保護**（未將任何資料寫入外部）

來自`work/`, 沒有`.prev.bak`/`monster_*.bin` 在輸出目錄中，所有實際的固定裝置皆為唯讀且雜湊值未變更，沙盒目錄在結束時已清空——無殘留，且從未提交）。 **次要**（NOVA 可執行功能：沙盒套用層 + 閘門；在單一副本中同時通過 offline-emittable/AiScriptLab-clean/AEON-reviewed/backup-ready 等階段）。 **範圍／真實性：** SIN **仍對公開寫入處於封鎖狀態** — Gate 5 僅在沙盒／副本中生效，**並非 RT2，亦非公開按鈕**；`PublicApplyAllowed=NO`/`Rt2=NO` 依設計。請勿在 public/save/runtime/RT2/UI/按鈕中建立`MonsterAiEditor`; 請勿觸碰`monster_*.bin` real/Aurora/native-menu/閃電球/商店/組合包/魔晶球/`Common`(ANIMA)；再利用`SinDryRunPlanner`/`SinPlanValidator`/`SinAeonDiffPlanner` +`AiScript_File.AppendGuardedAction`/`SpliceAiFileIntoMonsterGrow`/`AiScript_Diff`/`AiValidator` （已驗證的往返票價為 345/345，由`--aiasm-rt0`). 編譯 0 個錯誤；`--sin-sandbox-rt0` +`--sin-aeon-preview-rt0` (4號登機口) +`--sin-validate-rt0` (3號登機口) +`--sin-dryrun-rt0` (2號閘口) +`--aicmdmeta-rt0` +`--spiraatlas-rt0` +`--aiasm-rt0` 全部 **通過**。文件：`docs/ai/SIN_PENANCE_BACKUP_APPLY_SANDBOX_RESULT_2026-06-10.md` +`docs/ai/HANDOFF_PENANCE_SIN_RT2_PILOT_NEXT_2026-06-10.md`. [上一頁：`v2.78.1`] — Jarvis-PENANCE
- **🎨`v2.78.1` — 介面優化：色彩風格統一（去除 Fluent 的「棕色」）＋ 精修 Monster Editor／導覽／獎勵表。** Lane **Jarvis-RIN**（介面優化）。**色彩：** 重新調整 Fluent 的鍍鉻色（`Expander`/`ListBox`/`ListBoxItem`/`TabItem`) + 4 個共用欄位 ControlTemplates（`Property`/`PropertyBool`/`GameIndex`/`Loot`) + 工作室冷色調調色板的自動儲存代碼 — 移除 **應用程式全域** 的預設暖灰色／「棕色」以及邊框`AliceBlue` （全局樣式優於 Fluent 的 ThemeDictionary，後者會忽略屬性的覆寫）。**Monster Editor：**樣式`Label`/`Separator` 包含作用域、標頭`cardTitle` (屬性+戰利品)，屬性框以均勻的方格排列，戰利品欄位的標題採用 20 號粗體字 →`cardTitle`. **導覽：** 新增 **「遭遇與陣型」** 中心（只讀的「遭遇表」＋可編輯的「陣型編輯器」，含子分頁）；**「Spira Forge」→「地圖與場景」**（導覽外的「戰場中心」，

 （保留在程式碼中）；文字／參考資料 + 閃電球已移至 Core Authoring，且 **「Next Wave」卡片已刪除**（我避開了`&` 在「地圖與場景」標題下，該問題曾**導致所有路線的 Release 版本建置失敗**）。**獎勵表：** 3 級樹`Expander` 平抽（Draw inline；僅當透過抽籤進行的抽籤次數大於 1 次時，才稱為「第 N 次抽籤」）`ShowLabel`)，無邊框的獎項列搭配家族風格條紋＋懸停效果，比賽頁面預設以無篩選狀態開啟，賠率顯示於`ScrollViewer` 本身 (MaxHeight 400) + 晶片`pillWriter` 琥珀「無百分比溢價」，`Detail` 縮短版，精簡版英雄，將「連鎖/誠實」移至`Expander` 「關於」已收起。**獎金圖譜已核對：** 提及賠率之處均附有以下備註：「分屬不同組別／非一對一配對／無獎金百分比」。 **PATCH**（已發布的視覺優化；若仍有疑慮→請參閱PATCH）。**僅供展示：** 不涉及寫入器／解析器／綁定（`Value` TwoWay，`IsPrize`,`EditSession.*` 等（逐字引用）；樹 = 對這些的檢視`PrizeStructRow` （無 DTO）。建構過程無錯誤；`--blitzball-prizestruct-rt0` +`--spiraatlas-rt0` **PASS**。[上一頁：`v2.78.0`] — Jarvis-RIN
- **🌌`v2.78.0` — SIN Chain Builder Gate 4：AEON diff 預覽`SinApplyPlan` 已驗證（唯讀）— 顯示差異，但不進行套用；SIN 仍處於寫入鎖定狀態。** Lane **Jarvis-OMEGA** (MAGIC/SIN)。開啟 SIN Chain Builder 的 **Gate 4**：取得`SinApplyPlan` (Gate 2/SHINRYU) 已由`SinPlanValidator` (Gate 3/NEMESIS)，並產生**若該計畫是針對真實／受控的腳本發動時，AEON 會顯示的 diff** —— 目前**尚未載入怪物、尚未對真實工作節點進行 diff，也尚未`Rebuild`/`Splice`/`AiScript_Diff`，無備份、無磁碟且未套用任何設定**。僅回答一個問題：*「若此經驗證的計畫被發行，AEON 會顯示什麼樣的差異？」*。新增的類別在 **`FfxLib/Ai/Sin`**: **`SinAeonDiffPreview`**/**`SinAeonDiffPreviewStep`**/**`SinAeonDiffPreviewRow`**（反映了`AiScript_Diff`:`Added`/`Modified`/`Removed`/`Unchanged`, +`Context` 標記線`;` 清單中的項目 — 顯示但未計入），**`SinAeonDiffPlanner`** (`Plan(SinApplyPlan, SinPlanValidationResult)` →`SinAeonDiffPreview`; 僅讀取計畫 + 驗證結果，兩者皆為讀取

-only；便利性重載`Plan(SinChainRecipe)` （讓整個鏈條轉動）和 **`SinAeonPreviewFormatter`**（確定性文字）。**誠實模型：**由於並未載入任何怪物，因此不存在真正的 before-image → 所有預定的指令都是一條針對 **`synthetic/control fixture`** (`vanilla/current: <none at planned insertion point>`); **MODIFIED == 0** 且 **REMOVED == 0**（這是設計上的特性，要解決此問題需使用實際的處理節點 = Gate 5 的應用/備援節點）。Gate 4 **遵循 Gate 3 的規則**：`StructurallyValid` 來自驗證器，`ApplyAllowed` 這是**硬編碼的**，沒有任何候選元素會成為「可編寫」狀態，而**DIV/MUL 的結果 (`0x16`/`0x17`) 已載入，未經修正** — HP% 處方箋 (SIN-010) 會原樣列印該區塊`Blocked/warning: unresolved 0x16 DIV vs intended HP% multiply semantics. / No public apply. / No RT2 proof.` 而第 3 號閘口仍在載入阻擋程式`divmul-integrity`. **3 個測試案例：** SIN-006（線性，12 個新增）與 SIN-009（線性，3 個新增）= *結構上有效，應用受阻*； SIN-010（受保護動作，16 個新增）= 同上 **+ 強制性 HP% 區塊**。新增唯讀閘門 **`--sin-aeon-preview-rt0`**：載入 3 位車手、產生預覽，並確認`ApplyAllowed=false`, 合成 diff-target，ADDED≥1/MODIFIED=0/REMOVED=0，無候選項目→已準備好進行編寫，確定性預覽，SIN-010 中存在 DIV/MUL 區塊 + **檔案系統快照** （輸出目錄的前後快照 → **無新檔案，無`.prev.bak`, 沒有`monster_*.bin`**). **MINOR**（新增可執行功能：AEON 差異預覽 + gate）。 **範圍／真實性：** SIN **仍處於寫入封鎖狀態** — *Gate 4 顯示差異預覽，但不套用差異*；*「Clean for DESIGN 並未解鎖寫入權限」* — 且乾淨的差異預覽也不會解鎖寫入權限。 不執行寫入/儲存/`Rebuild`/`Splice`/AEON-real/backup/RT2/按鈕/UI；請勿觸碰`monster_*.bin`/runtime/Aurora/native-menu/Blitzball/Shop/Mix/Sphere/`Common`(ANIMA) 甚至連`MonsterAiEditor`; 僅供閱讀`FfxLib/Ai/Sin/*`. 編譯 0 個錯誤；`--sin-aeon-preview-rt0` +`--sin-validate-rt0` (3號登機口) +`--sin-dryrun-rt0` (2號閘口) +`--aicmdmeta-rt0` +`--spiraatlas-rt0` +`--aiasm-rt0` (AiScriptLab) 全部 **通過**。文件：`docs/ai/SIN_OMEGA_AEON_DIFF`

_PREVIEW_RESULT_2026-06-10.md` + `docs/ai/HANDOFF_OMEGA_SIN_BACKUP_APPLY_GATE_NEXT_2026-06-10.md`. [anterior: `v2.77.0`] — Jarvis-OMEGA
- **🔱`v2.77.0` — SIN Chain Builder Gate 3：AiScriptLab 的驗證橋接器`SinApplyPlan` (唯讀) — 驗證計畫，不執行；SIN 仍處於寫入封鎖狀態。** Lane **Jarvis-NEMESIS** (MAGIC/SIN)。開啟 SIN Chain Builder 的 **Gate 3**：取得`SinApplyPlan` SHINRYU（Gate 2）的預覽版，並已通過**與 AiScriptLab 相容的**檢查／`AiValidator`**，目前**尚未召喚怪物，也未`Rebuild`/`Splice`，未啟用 AEON diff、未使用磁碟，且未套用任何設定**。 僅回答一個問題：*「這個僅限預覽的計畫在結構上是否可接受（它所產生的字節碼是否格式正確），以及還有哪些真正的阻礙、警告或錯誤，使其仍無法進行應用？」*。新增的類別在 **`FfxLib/Ai/Sin`**: **`SinPlanValidator`** (`Validate(SinApplyPlan) → SinPlanValidationResult`，僅讀取來自`AiScript_File` +`AiStackModel` + 該計畫)，**`SinPlanValidationResult`**（與以下詞彙相對應：`AiValidationReport` 在計畫層級上：`Errors`/`Blockers`/`Warnings`/`Infos`,`StructurallyValid` = 無錯誤，`ApplyAcceptable` = **預設為 false**（在 Gate 3 中）) 以及 **`SinAiScriptLabBridge`**（針對單一串流進行的低階驗證）`AiInstruction`，沒有`AiScriptFile`). **核對（離線 SÓLIDO 子集，與`AiValidator` （美國）：** (1) 所有操作碼 ∈ 已驗證的 48 個（`AiScript_File.IsKnownOpcode`); (2)`HasOperand` 符合尺寸規定`0x80` (`IsOperandBearing`) — 否則`Emit()` 錯位；(3) 每指令 RT0 (`Emit()` 重新解碼為相同的指令碼+操作數）； (4) 透過每條陳述式進行堆疊平衡`AiStackModel` （線性體在 net 0 處結束；一個守護指令為 D7/POPXNCJMP 保留 **精確 1 個布林值**）。 **3 個試行方案的結論：** 所有方案 **在結構上均有效，但 apply-BLOCKED**（僅限預覽）— SIN-006/SIN-009（線性）堆疊位於 net 0； SIN-010（HP-guard）的守護指令會留下**精確 1 個布林值**，且操作位於 net 0。 **針對 SHINRYU 的 DIV/MUL 發現已明確處理（NEMESIS 決策 = 維持為預期中的 BLOCKER，不予修正）：** 方向已獲證實（`0x16=DIV`/`0x17=MUL

` por censo de 345 monstros + IDA `FFX_Atel_InterpretWorkerOpcodes@0x864180` + FFXDataParser), então o `MUL` do `AiSnippetLibrary` ligado a `0x16` é bug confirmado — mas a **reconciliação completa** (corrigir a constante + re-validar TODO consumidor: `MonsterAiEditor`, `AiAutomation`, `--aiasm-rt0`/`--ai2`/`--ai3` + re-provar RT0/RT2) é um **PATCH dedicado fora de uma gate de validação read-only** (e RT2 é proibido pro Gate 3). Insight estrutural que prova por que tem de ser BLOCKER e não Error: `AiStackModel` dá **net -1 pra DIV E pra MUL** → a pilha balanceia idêntico, o byte re-parseia, e **só o RT2 pega a aritmética errada**. O validador surfa isso como **Warning + Blocker** com a evidência toda, e o gate confirma que a receita HP% **continua blocked** e que **NÃO foi corrigida silenciosamente** (o planner ainda emite `0x16`, `AiSnippetLibrary` intocado). **Extensão aditiva (não-quebra):** `SinPlannedStep` ganhou `GuardOps`/`BodyOps` (as `AiInstruction` cruas que o planner já calculava) pra o validador inspecionar **exatamente** o que o planner produziu (fonte única; default vazio → toda construção do Gate 2 segue compilando e o `--sin-dryrun-rt0` continua PASS). Novo gate read-only **`--sin-validate-rt0`**: valida os 3 pilotos e assere estruturalmente-válido + apply-NÃO-aceitável + blockers honestos + escada de promoção insatisfeita + nenhum candidate→authoring-ready + (SIN-010) blocker DIV/MUL presente e não-corrigido; validação determinística. **MINOR** (capacidade NOVA executável: validador + gate). **Escopo/honestidade:** SIN **continua BLOCKED para escrita** — *Gate 3 valida planos, não aplica planos*; *"Clean for DESIGN não é unlocked for WRITING"* — e estrutura-limpa também não destrava escrita. NÃO faz writer/save/`重建`/`Splice`/AEON diff/backup/RT2/botão/UI; NÃO toca `monster_*.bin`/runtime/Aurora/native-menu/Blitzball/Shop/Mix/Sphere/`Common`(ANIMA) nem o `MonsterAiEditor`. Build 0 erros; `--sin-validate-rt0` + `--sin-dryrun-rt0` (Gate 2, sem regressão) + `--aicmdmeta-rt0` + `--spiraatlas-rt0` + `--aiasm-rt0` (AiScriptLab, 346/346 RT0 no corpus real) todos **PASS**. Docs: `docs/ai/SIN_NEMESIS_AISCRIPTLAB_VALIDATION_RESULT_2026-06-10.md` + `doc

s/ai/HANDOFF_NEMESIS_SIN_AEON_DIFF_GATE_NEXT_2026-06-10.md`. [anterior: `v2.76.0`] — Jarvis-NEMESIS
- **🐉`v2.76.0` — SIN Chain Builder Gate 2：模擬執行／預覽規劃工具 (`SinApplyPlan`) — 僅限預覽，SIN 仍處於寫入封鎖狀態。** Lane **Jarvis-SHINRYU** (MAGIC/SIN)。 開啟 SIN Chain Builder 的 **Gate 2**，將 YEVON 的規格（Gate 1，設計）轉化為 **可執行的預覽層**： 使用者建立一個 AI 意圖，規劃器便會顯示 **實際會產生的結果** — 無需套用、儲存、將字節碼寫入怪物，或建立公開按鈕。新命名空間 **`FfxLib/Ai/Sin`**:`SinChainRecipe` (具體的IR：觸發條件／條件／動作／組合／有效載荷／目標)，`SinApplyPlan` （可檢視的唯讀計畫：預定步驟、指示、分支／堆疊結構、證據、阻礙因素、晉升階梯的關卡、`ApplyAllowed=false` 硬連線)，`SinDryRunPlanner` (降低 **唯讀**：選擇經過驗證的片段來自`AiSnippetLibrary` 並 **在記憶體中擴展該範本** — 不會呼叫`Rebuild`/`AppendGuardedAction`/splice，不載入怪物，無法運行`AiValidator`，請不要打電話`AiAutomation`),`SinDryRunPreview` （確定性文字序列化）以及`SinPilotRecipes` （3 項必備試行配方：SIN-006 貝維爾面紗 = 第 1 回合自我增益；SIN-009 學士的諭令 = 強制/執行指令；SIN-010 法普蘭過路費 = HP<50% 時觸發的防護動作）。 **真實載荷分級** (`SinDryRunPlanner.ClassifyPayload`，來源：`AiCommandMetadataCatalog.IsKnownAiPerformOperandCategory`): 項目/GATTA (`0x2xxx`) 且非 AI = **被封鎖**；AI 執行指令 = **候選**（絕非已證實——連 Firaga 亦然）`0x3049`，其 RT2 為操作數交換，而非由 SIN 授權的區塊）。**發現（乾跑時立即成功）：** 已驗證的程式碼片段`guard-hp-below-pct-force-cmd` 發出 opcode **`0x16` (DIV** 根據已驗證的表格)`0x16=DIV`/`0x17=MUL`) 其中 HP% 語言意指 **MULTIPLY** —— 潛在的差異在於`AiSnippetLibrary` (該常數`MUL` 與……有關`0x16`); **在預覽中被標記為警告/阻擋項，此處尚未修正**（修正發射器超出「僅預覽」的範圍；需對程式碼片段進行 RT0/RT2 重新驗證）。新的唯讀閘門 **`--sin-dryrun-rt0`**：安排 3 名車手，生成

 確定性預覽，並確認未儲存／寫入任何內容，`ApplyAllowed=false`, rung=preview-only, 存在誠實的阻礙因素, 晉升路徑 100% 未達標，且 **沒有任何候選人晉升至 authoring-ready 狀態**。 **次要**（新增可執行能力：規劃器模擬執行 + 關卡；正因具備可執行能力，故從「審查」階段移出，依據 YEVON 的交接說明）。 **範圍／誠信度：** SIN **仍處於寫入封鎖狀態** — 閘門 2 屬於預覽／乾跑，而非撰寫； *「Clean for DESIGN 不等同於 unlocked for WRITING。」* 切勿觸及 writer/parser/runtime/Aurora/native-menu/Blitzball/Shop/Mix/Sphere/`Common`(ANIMA)/save 甚至連`MonsterAiEditor` (UI 預覽 = Gate 3+)；僅限讀取`FfxLib/Ai/*`. 編譯 0 個錯誤；`--sin-dryrun-rt0` +`--aicmdmeta-rt0` +`--spiraatlas-rt0` +`--aiasm-rt0` (AiScriptLab) 全部 **通過**。文件：`docs/ai/SIN_SHINRYU_DRY_RUN_EMITTER_RESULT_2026-06-10.md` +`docs/ai/HANDOFF_SHINRYU_SIN_AISCRIPTLAB_GATE_NEXT_2026-06-10.md`. [上一頁：`v2.75.0`] — Jarvis-SHINRYU
- **🏐`v2.75.0` — 閃電球獎項表變為樹狀圖：聯賽／錦標賽 → 第1名／第2名／第3名／最佳射手 → 抽籤 → 獎項（+ 抽籤檢測功能已重新通過審核）。** Lane **Jarvis-NIMROOK**（獎勵組織）。獎勵表（459 個獎勵索引 + 390 個賠率在`bltz0200.ebp`) 不再是按類別劃分的平面摺疊式選單，而是變成了一棵 **經過重新驗證的 3 層樹狀結構**： **比賽**（聯賽／錦標賽）→ **獎項**（第1／2／3名 + **最佳射手** — 頒發給擁有最佳射手的隊伍，與名次無關）→ **抽籤 N**（一個`switch GetRandomInRange`) → 可編輯的獎勵區間。解析器中的新功能`BlitzballPrizeStructure_File.FindRollSwitchStarts`/`DrawStartFor` (唯讀、位元組安全)：每次抽籤的上限為 call`GetRandomInRange` (指令碼`B5 A6 00`) — **68 次經實測的抽獎活動** 於`bltz0200.ebp` 實際（已分配所有 459 個獎金名額；1 個「首輪前」孤兒名額），門檻`--blitzball-prizestruct-rt0` 已擴展以驗證模型。**誠實聲明：**賠率仍屬獨立類別（未與獎項配對），因為在同一場抽獎中，獎項數量 ≠ 滾動區間數量（經數據集驗證，67/68） — 聲稱「此獎項有 X% 的中獎機率」等同於捏造證據。+ **重新命名分頁`Atlas`→`Pr

ize Atlas`** + **reconciliação do `被封鎖`**: o Prize Atlas (read-only) dizia "liga/torneio/artilheiro = blocked (runtime/save)"; o texto agora explica que isso vale **só pro prêmio que caiu no save** — a atribuição + odds são game-file editáveis (aba Prize Table, RT0 provado) e o reward = aba Prize Pool (takara). + legenda de cadeia (Prize Table escolhe o índice → Prize Pool diz o reward) nas abas de prêmio. **MINOR** (capacidade NOVA: API de estrutura de sorteio RE-provada no parser + 1ª árvore hierárquica de prêmio). Escopo: writer/`EditSession`/`SetPrizeIndexAt`/`SetThresholdAt` **intocados** (só leitura nova + apresentação); não toca save/runtime/SIN/`Common`/provider Atlas nem o código de outras lanes (em cima do baseline commitado do RIN v2.74.x). Build 0 erros; `--blitzball-prizestruct-rt0` (68 draws) + `--spiraatlas-rt0` + roster/recruit/treasure RT0 todos PASS. Doc: `docs/ai/HANDOFF_NIMROOK_BLITZBALL_PRIZE_UI_DIAGNOSIS_2026-06-10.md`. [anterior: `v2.74.1`] — Jarvis-NIMROOK
- **🪗`v2.74.1` — 可收合的側邊欄區塊 + 跨會話狀態保留。** Lane **Jarvis-RIN** (UX)。 側邊欄的每個區塊卡片（核心編輯 · Spira Forge · Live Tools · Next Wave · 額外功能 · ???）都變成了一個 **可點擊的標題**（同時保留卡片的外觀：`sectionLabel` +`cardTitle` + 箭頭符號）可 **收合／展開** 按鈕群組。各區段的收合狀態會透過新功能 **儲存並在不同會話間保留**`Services/SidebarState_Service` (`LocalAppData/FFXProjectEditor/sidebar-state.json`，仿照該慣例的`last-project.txt`) — 若未對某個區段進行任何操作，即可將其關閉，且在重新開啟編輯器時該區段仍會保持關閉狀態。此功能已應用於建構器中（`ApplySidebarState`) 並儲存於切換開關中 (`SidebarSection_Toggle`). **加法**類別在`StudioTheme.axaml` (`Button.sectionHeader` 透明／游標呈手形，將游標懸停於標題上時顯示青綠色 +`TextBlock.sectionChevron`); 箭頭符號 ▾（開啟） / ▸（關閉）。**僅顯示：** 重新整理該頁面的 6 張卡片`Main_Window` (頁首 +`StackPanel` （稱為「可折疊」）+ 1 項便利性持久化服務（故障 = 靜默處理，預設展開顯示）。不涉及 writer/parser/runtime/save/provider/其他通道。**PATCH**（便利性/使用者體驗；

 疑難排解→PATCH)。建置結果為 **0 個錯誤 / 361 個警告**；編輯器已於 v2.74.1.0 重新開啟。[先前版本：`v2.74.0`] — Jarvis-RIN
- **🗂️`v2.74.0` — 整合式導覽：4 個新匯聚樞紐（戰鬥指令、道具、球形網格、文字／參考）＋ 組件`SubTabHub` 可重複使用 + 精簡側邊欄。** 該路線的第二波 AI **Jarvis-RIN**（Halyson 的大量註解）。新的通用元件 **`SubTabHub_Control`** (`Modules/SubTabHub`): FFX 風格的子選單欄（重複使用`tabPill`/Blitzball 模式小工具）透過程式碼建構，透過`AddTab(label, factory, modo, pílula, requiresProject)`, **lazy-load**（每個子分頁僅在首次選取時建立控制項，並進行快取）以及 **guard`requiresProject`**（需要設計的選項卡會顯示佔位符，而非直接當機）。在其上方，**4 個樞紐**（每個樞紐皆「容納」現有的控制項，且不更動其內部結構）：**(1) 戰鬥指令** →`Comandos/Magias de Personagem` (command.bin) ·`Monster Commands 1` (monmagic1) ·`Monster Commands 2` (monmagic2)；**(2) 項目** →`Items` (item.bin) ·`Key Items` (important.bin, guard) ·`Shop` (已儲存的槽位載荷) — 商店與關鍵道具從獨立畫面移至此處；**(3) 球體網格** →`Explorer (DB)` ·`Builder` ·`Canvas` (3 變為 1；Explorer 要求專案，Builder/Canvas 則無需專案即可開啟)；**(4) 文字／參考資料** →`String Explorer` ·`Macro Explorer` ·`Weapon Names` ·`Battle Text` ·`Event Explorer` (5 變為 1)。每個子分頁皆以真實檔案／範圍為依據，誠實地顯示模式標籤（寫入模式為琥珀色／唯讀模式為青綠色）。 **側邊欄：** 核心創作功能從 23 個按鈕減少至 15 個；**自動能力現已整合至「自訂設定／永恆」中**；**怪物 AI 探索器已從選單中移除**（處理程式／程式碼仍保留，僅移除了導覽選項）。 **作用範圍 (RIN)：** 僅限導覽／託管 — 新增的 4 個處理程式位於`Main_Window` 建造`SubTabHub` 透過工廠 (`CreateKernelCommandsControl(...)` 針對核心表格；`new XxxControl()` （其餘部分）而舊的處理程序則保留在程式碼中（`ShowKernelCommands`/`CreateKernelCommandsControl` 未受影響 = 「後退/前進」及「nav-restore」仍可正常運作）。**請勿**觸碰 writer/parser/runtime/save/SIN/provider，亦勿觸碰任何組件的內部結構

其他通道的模組（MAGIC/Sphere）；僅編輯該通道的導航行`Main_Window` (共享檔案) + 新增`Modules/SubTabHub`. 《Battle Commands》中尚缺的功能（通用搜尋、子分頁搜尋、**多重編輯**）將留待後續版本處理（這些功能會影響命令編輯器的邏輯 = lane MAGIC）。 **小更新**（4 個新分頁／導覽模組 + 新的可重複使用元件）。建置結果為 **0 個錯誤 / 361 個警告**；編輯器已於 v2.74.0.0 重新開放。[先前版本：`v2.73.0`] — Jarvis-RIN
- **🏐`v2.73.0` — Blitzball Hub：將 5 個獨立視窗整合為 1 個「Blitzball」標籤頁，內含子標籤頁、直觀的模式選單，並對 5 個視窗進行視覺優化。** 整合導航功能與使用者體驗（由 **Jarvis-RIN** 負責）。 側邊欄原本有 **5 個獨立按鈕**（`Blitzball Prizes`/`Roster`/`Recruits`/`Prizes (Edit)`/`Prize Table`) 過去有幾個名稱會互相衝突（其中 3 個都稱作「prize」）；現在則改為 **1 個按鈕**`Blitzball 🏐`** 開啟新模組 **`BlitzballHub_Control`** (`Modules/BlitzballHub`) 附有 **5 個子標籤**，採用類似《最終幻想 X》的條狀佈局（藥丸`tabPill`, 帶有 **青綠色** 下劃線的活躍分頁)：**選手名單 · 新秀 · 獎金池 · 獎金分配表 · Atlas**。每個子分頁在橫槓正下方都會顯示一個 **簡明直觀的摘要** —`WRITER LAB · <arquivo> · RT0 proven · RT2 pending` (琥珀色) 在寫作的第四部分，`READ-ONLY · Spira Data Atlas` (青綠色) 在 Atlas 中 — 因為樞紐的外接「模式」徽章已轉為中性 (`Atlas + Writer Lab`) 且無法再僅採用單一模式。**lazy-load** 標籤（每個 UserControl 僅在首次選取時建立並進行快取）→ 匯流排 **絕不會保留 4`ByteSnapshotEditorSession` 同時**。**5 個視窗的視覺優化**（僅限介面呈現——未觸及任何寫入器／解析器／綁定／資料模型）：採用新類別的較小英雄`heroGradient` （刪除了 3 個複製的字面梯度），`Save` 現在在`primaryAction` (青綠色) 在「書寫」的 4 個按鈕上（先前是每個畫面上的風格化「減號」按鈕），**名單** 包含 8 個方框`cardSoft` 以 **表格** 形式呈現（標題對齊，a/b/c/type 列於右側），**獎金表** **按類別分組至摺疊式選單中**（5 個可收合的群組 — 聯賽／錦標賽排名、聯賽／錦標賽最佳射手、投注門檻／賠率 — 預設為收合狀態，附有同色系的小圓點 + 計數器）

ites；文字篩選器會自動展開符合條件的群組），以整理這約 849 個選項， **每行按色系區分**（青綠色=獎金指數，琥珀色=賠率）＋簡化文字＋標準化填充間距，**獎金池**中的「數量/原始類型」則歸類於`cardSoft` 以及精簡的 Quantity 欄位，**Recruits** 帶有偏移量`@0x` 將副標題和播放器組合移至次要位置，**Atlas** 在網格中採用 **彩色提示點**（proved-candidate=青綠色 / partial=琥珀色 / metadata-only=藍色 / blocked=危險），並使用文字顏色（`#9AD7E2`/`#9EB0C2`) 兌換成代幣。在`StudioTheme.axaml` (`tabPill`/`tabPillActive`,`heroGradient`,`pillWriter`/`pillReadonly`,`numField`) — 原本不存在的選項 → 其他畫面出現 **零回歸**（我並未修改`TabControl`，正是為了不影響那 8 台使用原始 tab 的螢幕）。2 台新的簡報轉換器（`PrizeFamilyBrushConverter`,`EvidenceStatusBrushConverter`). **MINOR**（全新導航模組／AI + 首個可重複使用的子標籤區；單就優化而言應屬 PATCH，但因搭上新模組的順風車）。 **不**涉及 writer/parser/runtime/save/SIN/Atlas 提供者/其他通道；這 5 個`*_Control.axaml.cs` 而 DataModels 則保持不變。編譯結果為 **0 個錯誤 / 361 個警告**（該`.exe` 最終並未複製，只是因為編輯器當時處於開啟狀態——這與程式碼無關）。[上一則：`v2.72.0`] — Jarvis-RIN
- **🏐`v2.72.0` — 閃電球獎金表：現在也能編輯賠率（抽籤的 390 個門檻）—「全面調整」。** 標籤頁擴充功能`Blitzball Prize Table 🏐` (`v2.71.0`): 除了 459 個獎金指數外，現在還會計算定義「機率」的 **390 個即時閾值** — 這些就是邊界`case >= N` /`case <= M` 關於`GetRandomInRange(100)` (位元組碼`29 AE <thr> 0E/0F D7/D6` =`DUP·PUSHII·GE/LE·jump`). 由`roll >= lo` 以及`roll <= hi` 有 ~`(hi-lo+1)%` 中獎機率；擴大選號範圍＝中該獎項的機率更高。新`BlitzballPrizeStructure_File.FindRollThresholds`/`SetThresholdAt` （**從某獎勵網站掃描並截取至 ≤768B**，以避免觸及任何無關的開關）— 它們使用相同的 2 位元組寫入器（`Event_File.PatchScriptUInt16`). 統一使用者介面：濾鏡新增了 **"Roll Thr

eshold (odds)**，每行皆支援內聯編輯（獎金行顯示即時計算出的獎勵；閾值行顯示桶的上限）。Gate`--blitzball-prizestruct-rt0` 擴展並在**PASS**中`bltz0200.ebp` 實際：459 獎金 + **390 門檻** (195`<=` / 195`>=` = 完美配對），未編輯部分位元組完全相同，而獎勵指數 **與** 閾值的編輯部分均 **各自獨立於 2 位元組**（`<=10 → <=50` @0xC108)，重新讀取後確認兩者皆正確。**輕微**（新功能：賠率編輯）。不影響 save/runtime/SIN/其他通道。建置結果：0 個錯誤 / 361 個警告；`--blitzball-prizestruct-rt0` **PASS**。文件：`docs/reverse/FFX_BLITZBALL_PRIZE_STRUCTURE_RE_2026-06-10.md`. [上一頁：`v2.71.0`] — Jarvis-CHAPPU
- **🏐`v2.71.0` — 閃電球獎項表：編輯各名次／抽獎所對應的獎項（459 項即時獎項在`bltz0200.ebp`) — 駁斥了「被封鎖」的說法。** 唯讀版瀏覽器 (`v2.62.0`) 標示`BlitzballLeague/TournamentPrizeIndex`/`TopScorer` 如何 **`blocked` (執行時間/儲存)** — **過於保守**：他只看到了 **讀取/顯示** 方面的`bltz0201` (`PrizeIndex + 220 → Treasure Label`). **歸屬** 位於`bltz0200.ebp` 例如 ATEL 中的 **459 個即時常數**：`Set Blitzball*PrizeIndex[slot] = <prize-index>` 在某個交換器上`GetRandomInRange(100)` （獎勵的隨機分配）。可編輯的遊戲檔案，與招募功能相同（只是由於數值超過 255，因此採用 **2 位元組** 的即時處理）。新模組／分頁 **`Blitzball Prize Table 🏐`** (`Modules/BlitzballPrizeStructEditor`): 可篩選清單（依變數／獎勵／指數），包含 459 個具備 prize-index 內嵌編輯功能且 **獎勵即時計算** 的網站（takara`prize+220`，或 MacroDict#8（收錄超過 100 個詞條）。新的基本詞`Event_File.PatchScriptUInt16`/`ReadScriptUInt16` (立即修補的 2 位元組，透過 保持長度的方式)`ScriptChunkOverride`) +`FfxLib/Blitzball/BlitzballPrizeStructure_File.cs` (掃描/`SetPrizeIndexAt`) + 閘門`Tools/BlitzballPrizeStructRt0.cs` (`--blitzball-prizestruct-rt0`). **已驗證**於`bltz0200.ebp` 實際 (222.464 B)：**459 個網站** (141 聯賽 + 188 錦標賽 + 65 聯賽-TS + 65 錦標賽-TS = 符合語料庫計數)，未編輯且位元組完全相同，僅有 1 項獎項索引 **在 2 位元組範圍內** 被編輯（聯賽第 1 名`0x0001→0x0099` @0xC0A2)，回覆

-read 確認。**RE 發現：** ATEL 的 var-ids 是 **按檔案** 區分（`0x28` 在 bltz0201 對戰`0x30` 在 bltz0200 中）； bltz0200 的 ID（`0x30`/`0x31`/`0x32`/`0x33`) 經 switch/Set 驗證。**誠實度：** 編輯每個名次所對應的獎勵指數（遊戲檔案、RT0 隔離已驗證、RT2 待處理）；每個指數所提供的獎勵 = takara (aba`Blitzball Prizes (Edit)`); 機率（擲骰閾值）是另一組尚未公開的即時變數。**MINOR**（新模組 + 新的 2 位元組寫入器）。不涉及儲存/執行時/SIN/其他通道。建置結果：0 個錯誤 / 361 個警告；`--blitzball-prizestruct-rt0` **PASS**。文件：`docs/reverse/FFX_BLITZBALL_PRIZE_STRUCTURE_RE_2026-06-10.md`. [上一頁：`v2.70.0`] — Jarvis-CHAPPU
- **🏐`v2.70.0` — 閃電球獎品編輯器：用於在遊戲檔案（takara.bin 220..320）中編輯 101 項閃電球獎品的介面。** 新增模組／分頁 **`Blitzball Prizes (Edit) 🏐`** (`Modules/BlitzballPrizesEditor`) 負責管理閃電球獎金池（獎金 0..100 → Takara Row 220+k → 獎勵；proved-candidate 規則已於`v2.62.0`): 主從式列表，顯示 101 項獎勵，每項皆附有 **項目下拉選單**（可依名稱／ID 篩選）＋ **數量** ＋ 已解析的 Raw Type／Kind／reward。**內部重用`TreasureEditor_DataModel` 已驗證**（項目字典、名稱解析、`ByteSnapshotEditorSession`, 完整資料表寫入器) 篩選第 220 至 320 行 → **save 就是「Treasures」分頁中的同一個寫入器**，寫入`takara.bin` 除經編輯的獎項外，其餘 498 筆條目均以位元組為單位完整保留。記錄於`Main_Window` (nav +`SetModule`). **誠實度：** **「可寫入（實驗室）」** 徽章 — 編輯 POOL（每個獎勵索引對應的獎勵），而非您在聯盟／錦標賽／活動中獲得的具體獎勵（＝執行時／儲存時）； 若要設定裝備／關鍵道具獎勵或精細控制 Kind，請使用「Treasures」分頁。此功能可補充「探索者」的唯讀模式`Blitzball Prizes 🏐` (`v2.62.0`) 與正式版本相比。**MINOR**（新模組／新分頁）。Reusa`TreasureEditor_DataModel`/`Treasure_File`/`Item_Dictionary`; **不會**建立新的寫入器，也不會觸及玩家儲存檔／執行時／SIN／其他通道。建置結果：0 個錯誤／361 個警告。[前一版：`v2.69.0`] — Jarvis-CHAPPU
- **🏐`v2.69.0` — 《閃電球》招募編輯器：用於切換招募對象的介面

 在每個位置（遊戲檔案；寫入器`v2.67.0` （已驗證）。** 新增模組／分頁 **`Blitzball Recruits 🏐`** (`Modules/BlitzballRecruitEditor`) 該程式直接在遊戲檔案中編輯自由球員的招募內容：列出了**約34項招募場地活動**（盧卡／基利卡／瓜多薩拉姆／寧靜之地／飛空艇／貝賽德／……，這些名稱是根據語料庫中的簽名推導而來`AE 28 00 14 AE <id> 00 A3`)，並會依活動顯示每個 **招募網站**，每個網站附有 **包含 60 名玩家的下拉式選單**（經解析的姓名來自`macrodic.dcp` 來源`BlitzballPlayerNames`) 用於重新標示在那裡被招募的人。使用已經經過驗證的寫入器`BlitzballRecruit_File`/`Event_File.PatchScriptByte` (gate`--blitzball-recruit-rt0`) 透過一個`ByteSnapshotEditorSession` **按事件**（儲存／撤銷／還原原始狀態／自動儲存，與多來源 MacroExplorer 功能相同）。記錄於`Main_Window` (nav +`SetModule`). **誠實度：** **「Writable (Lab)」** 徽章 — 僅重新指向新兵的玩家 ID（遊戲檔案，**無 EXE 修補程式**；已驗證 RT0 隔離，遊戲內 RT2 尚待確認）； 每位球員通常有 **2 個位置**（兩個程式碼分支）→ 將兩者同時修改以徹底重新指向；招募的可用性／門檻設定遵循事件邏輯；球員數據 = Blitzball 陣容分頁，名稱 = Macro Explorer。 **次要**（新模組／新分頁；前身：Blitzball Roster Editor`v2.68.0` = 未成年人）。Reusa 撰文／`Event_File`/`MacroDictionary_File`/`BlitzballPlayerNames`/`ByteSnapshotEditorSession` 現有項目；**不會**建立新的 Writer，也不會觸及 save/runtime/SIN/其他通道。建置結果：0 個錯誤 / 361 個警告；`--blitzball-recruit-rt0` PASS。[上一頁：`v2.68.0`] — Jarvis-CHAPPU
- **🏐`v2.68.0` — 閃電球陣容編輯器：60 名球員的數據／成長值視覺化介面（遊戲檔案；撰稿人`v2.66.0` （已驗證）。** 新增模組／分頁 **`Blitzball Roster 🏐`** (`Modules/BlitzballRosterEditor`) 該功能可直觀地顯示檔案中 60 名玩家的 stat-growth 曲線`bltz0002.ebp`: 玩家清單（包含已解析的 **唯讀名稱** 來自`macrodic.dcp` 來源`BlitzballPlayerNames`) + 8 項屬性（HP/SP/AT/EN/PA/SH/BL/CA）的編輯器，每項屬性皆包含 4 個浮點數`a/b/c/growthType` 可編輯、**Lv 1/50/99 數值的即時預覽** 以及公式。請使用已通過測試的 Writer`BlitzballRoster_File` (gate `--

blitzball-roster-rt0`) via `ByteSnapshotEditorSession` (save/undo/restore-original/auto-save, espelho exato do `TreasureEditor`). Registrado no `Main_Window` (nav + `SetModule`). **Honestidade:** badge **"Writable (Lab)"** — escreve só os stats/growth (RT0 byte-identity provado, in-game RT2 pendente); **nomes são read-only aqui** (editar no Macro Explorer); techs/level/EXP/custo = save-side; match-engine/efeitos de técnica = EXE-native (ver address map). **MINOR** (módulo/aba NOVO; precedente: Blitzball Prize Explorer `v2.62.0` = MINOR). Reusa writer/`Event_File`/`MacroDictionary_File`/`閃電球球員名稱` existentes; **não** cria writer novo nem toca outras lanes/runtime/save/SIN. Build 0 erros / 361 warnings; `--blitzball-roster-rt0` PASS. [anterior: `v2.67.0`] — Jarvis-CHAPPU
- **🏉`v2.67.0` — 閃電球：可在遊戲檔案中編輯招募名單 — 立即下載 ATEL 修補程式至`.ebp` (已驗證 RT0)。** 每個位置被招募的對象，是 field event 的 ATEL 字節碼中一個 **1 位元組的立即數**：其簽名`AE 28 00 14 AE <playerId> 00 A3` (`PUSHII 40 · ADD · PUSHII <playerId> · write-array`) 將其加入您的團隊中 (`BlitzballTeamPlayers[count+40]`). 新的原始元素`Event_File.PatchScriptByte` (ATEL 區塊中的 1 位元組修補程式，透過 **長度保留** 方式)`ScriptChunkOverride`) +`FfxLib/Blitzball/BlitzballRecruit_File.cs` (`FindSites`/`SetRecruit`/`SetRecruitAt`) + 閘門`Tools/BlitzballRecruitRt0.cs` (`--blitzball-recruit-rt0`). **已驗證**於`guad0000.ebp`: 6 個網站 (Giera`0x1F`/Auda`0x22`/Nav`0x21` × 2 分支)，不可編輯 讀取→寫入 位元組完全相同 (189,696 B)，重新指向 Giera→Wakka (`0x1F`→`0x33`) **以 2 位元組為單位隔開** 位於預期的偏移量處，重新讀取以確認新成員。簽名已驗證 vs`guad0000`/`lchb0000`/`hiku0500` （完整版 Al Bhed Psyches）。**誠實聲明：**此模組僅變更「誰」在何處被招募（僅修改遊戲檔案，**不含 EXE 補丁**）；招募的可用性／觸發條件仍遵循事件的既有邏輯。 **輕微修改**（全新的招募寫入程式；此類工具的首款）。僅新增檔案 + 1 次派遣`Program.cs`; 不執行 save/runtime/SIN/其他執行路徑。建置結果：0 個錯誤 / 361 個警告；`--blitzball-recruit-rt0` **PASS**。文件：`docs/reverse/FFX_BLITZBALL_ENGINE_IDA_SCOUT_2`

026-06-10.md` (Recrutamento). [anterior: `v2.66.0.1`] — Jarvis-CHAPPU
- **🏉`v2.66.0.1` — 閃電球：已確認可編輯的球員名稱（macrodic 區塊 7）＋ 場內存取器。** **修訂**（程式碼已加入但行為未變 — 存取器尚未被使用；RE/prep）。我已解碼該`new_uspc/menu/macrodic.dcp` 實際上，我已證實這 60 名玩家的名稱 = 巨集`0x700+idx` = **第 7 區塊** (字元集 FFX`byte−0x0F`; 101 筆條目）：`0x702`=Datto,`0x703`=萊蒂，`0x704`=Jassu，`0x705`=博塔，`0x706`=Keepa,`0x707`=比克森……；`0x700`/`0x701` = 關於可**重新命名**的角色（提達斯／瓦卡）。→ **今日起**即可在模組中編輯`MacroExplorer` (讀+寫`macrodic.dcp` （含 SafeWriter／撤銷／驗證／往返處理）。新的唯讀存取器`FfxLib/Blitzball/BlitzballPlayerNames.cs` (索引↔巨視)`0x700+idx`,`TryGetName`) 作為未來時態的 **prep**`BlitzballRosterEditor` 使用者介面顯示／編輯內嵌名稱。不觸及`MacroExplorer` （文字分支）或其他分支；僅新增 1 個檔案 + 文件。建置結果：0 個錯誤 / 361 個警告。文件：`docs/reverse/FFX_BLITZBALL_ROSTER_BASE_RE_2026-06-10.md §3` +`docs/ai/BLITZBALL_100PCT_EDITOR_CHECKLIST_2026-06-10.md`. [上一頁：`v2.66.0`] — Jarvis-CHAPPU
- **🏉`v2.66.0` — 閃電球 陣容名單（60 名球員的數據／成長值）現已可在遊戲檔案中編輯 — 撰文者`.ebp` 已驗證的 Atel-variable（與 RT0 位元組完全相同 + 突變隔離）。** **首位直接在 GAME FILE（而非存檔）中編輯 Blitzball 基礎資料的修改者。** 60 名球員的基礎數據與成長曲線均存於`bltz0002.ebp` 作為 Atel 變數`0x126..0x12E` (8 項統計數據 × 60 名球員 × 4 個浮點數`a,b,c,growthType`; 解密成長公式：`gt -1`→1,`0`→a+b·Lv,`1`→a+b·Lv^c,`2`→a+b·Lv−c·Lv²，`3`→a+b·Lv+c·Lv²)。新的原始函數`Event_File.PatchEventDataElement(varId, idx, bytes)` (`FfxLib/Event/Event_File.AtelVar.cs`): 透過 hook 對 Atel 的 eventData 變數進行 **保留長度** 的就地修補`ScriptChunkOverride` 已經存在 →`Write()` 重新封裝與原始內容完全相同的資料（僅編輯過的區段除外）。新的可讀寫檔案類別`FfxLib/Blitzball/BlitzballRoster_File.cs` (解碼／編輯 60×8 growth) + 閘波`Tools/BlitzballRosterRt0.cs` (`--blitzball-roster-rt0`). **已驗證：** 由 朗讀

te-exato 與 FFXDataParser 的資料擷取結果（玩家0 生命值 =`70 + 30·Lv + 0.711·Lv²`); 唯讀→可寫 **位元組相同** (5,445,248 B); **480/480 個有效的 growthType**; 1 個浮點數的修補程式 **與目標元素的 4 個位元組隔離**，位於預期的偏移量處 (`@0x491680`). **RE（缺失的部分）：** 變數的值基礎 =`worker0_header + 0x30` （解決方案穩健，未硬編碼）。**誠實聲明：** 僅有 stats/growth 為檔案中的資料；名稱 = 字串巨集`0x700+idx` (寫入器已存在，尚待連結)，**位置/技術設定/啟動引擎 = EXE (待進行 IDA 分析)**， 已學技術/成本/合約/等級/經驗值 = **儲存**（超出遊戲檔案範圍）。**目前尚無使用者介面**（下一步 =`BlitzballRosterEditor`). **MINOR**（新功能：遊戲檔案中首個閃電球名單寫入程式）。不會觸及存檔（CHAPPU/校驗和）、執行時檔案、SIN 或其他通道；僅在`Program.cs`. 編譯 0 個錯誤 / 361 個警告；`--blitzball-roster-rt0` **PASS**（無編輯且位元組完全相同 + 突變隔離）。文件：`docs/reverse/FFX_BLITZBALL_ROSTER_BASE_RE_2026-06-10.md` +`docs/ai/BLITZBALL_100PCT_EDITOR_CHECKLIST_2026-06-10.md`. [上一頁：`v2.65.3`] — Jarvis-CHAPPU
- **🗺 Spira Data Atlas / FFXDataParser 橋接模組 — 巨型解析器前線工作告一段落。** 涵蓋整款遊戲的研究／目錄編製前線工作，現已達成一個帶版本號的運作性收尾：位於`tools/ffxdataparser_bridge` 已進行強化，以重現基於`FFXDataParser`，包含 Step0/v5 層、額外的 v6 P0 層、v7 ATEL 粒度層以及 v8 ATEL 語義層。已納入來源與交接文件，以確保不會遺失資料來源（`HANDOFF_SPIRA_DATA_ATLAS_PARSERS_GIGANTES_2026-06-09.md`,`SPIRA_DATA_ATLAS_PARSERS_GIGANTES_PROVENANCE_MAP_2026-06-09.md`)，PRE1/PRE2 用於`takara.bin`/`buki_get.bin`、command/magic 地區設定架構、支援地區設定的解析器層、unknown/evidence 狀態，以及 Step0-C 交叉連結。結果清楚地說明了什麼是`proved`,`partial`,`read-only`,`metadata-only`,`blocked` 以及`RT2-pending`: parser-corpus 驗證結構／存在性，而非執行時效果或寫入者的授權。
- **📚 Spira Data Atlas / BIBLE OF SPIRA — 讀取專用資料提供者已擴充至 14,739 項詳細資料

給他們。** 該服務供應商`SpiraDataAtlasCatalog` 而《聖經》如今也將《阿特拉斯》視為一個可供研究的真實背景：`74` 圖鑑條目，`54` 主圖層，`1601` 未經處理的解析檔案，`615` call-shapes,`89` 枝條形狀，`202` field-shapes,`3283` 工人和`656` command-site 摘要。最終方案已彌補 Step0-C 中的「6 項缺口」：`1604` monster-presence rows 按陣型／槽位，`979` SIN 資格標準（透過）`AiCommandMetadata`,`1190` 名稱／型號的行`w_name.bin`,`312` 閃電球賽事裁判們，`76` 源自《閃電球》獎項的裁判`bltz0200/0201`,`20` PC/Aeon 細行與`2493` Sphere Grid 節點。內建的 CSV 讀取器現已支援多行記錄及閘道`--spiraatlas-rt0` /`--aicmdmeta-rt0` 已完成。由於尚未推出新版寫入器：Treasure/Shop/Sphere/Monster AI/SIN 會優先將其用於背景設定、徽章及稽核；SIN Chain Builder 仍依賴 AiScriptLab、AEON diff、備份及 RT2。
- **🧠 Monster AI 編輯器 — 優化 SIN 威脅導航功能。** **Spira Instinct Network** 的唯讀圖庫新增了精確的威脅篩選功能`T1`..`T10`，同時保留頻段濾波器（`T1-T3`,`T4-T6`,`T7-T8`,`T9-T10`) 並新增可選的依`SIN-001 -> SIN-100`,`Threat 1 -> 10`,`Threat 10 -> 1` 或搜尋相關性。選取的「罪」預覽現在明確顯示了威脅範圍（`baixo`,`medio`,`alto`,`dark`,`proibido`) 以及實體化政策（`materializavel primeiro`,`espera chain builder`,`somente lab`，等等）。未導入新編譯器，也未修改執行時環境／遊戲：並提供離線使用者體驗／目錄，以便在未來的鏈建立工具推出前瀏覽 100 個預設值。臨時建置結果：0 個錯誤／0 個警告。— Jarvis-Codex
- **🧠 BattleTracker / SIN — 離線狀態映射功能。** 未觸及正式遊戲，Forbidden Rite 陣營已獲得該文件`docs/ai/SIN_STICKY_STATUS_OFFLINE_MAPPING_2026-06-08.md`:`AiChrPropertyNames` 共有 341 個欄位（`0x0000..0x0159`) 且不暴露`status_full_auto_*`/`status_innate_auto_*` 作為 ATEL 字段而為人所知；目前 sticky 仍維持在執行階段`MemoryChr` (`0x62A..0x634`) 或未來的 live/DINPUT8，並非純粹的 Monster AI。BattleTracker 現已顯示一個唯讀音軌 **Forbidden Rite / Sticky Bytes**，其中包含`Suffer`,`Durations`,

 `Extra`,`Doom`,`Full auto`,`Innate auto` 以及簡明摘要，降低對下個 RT2 版本中 PowerShell 的依賴。Build 編輯器 0 個錯誤 / 361 個警告。— Jarvis-Codex
- **🧠 Monster AI Editor — 《禁忌儀式》防移除 RT2 實驗室。** 在反 Ribbon 套件於`m034 -> Tidus`，實機測試區分了哪些只是繞過機制、哪些則是無法移除的：沒有黏著效果，`Eye Drops` 當了選美小姐後便離開了`Darkness=255`，但「聖水／清除」已將其清除`Zombie/Confuse/Curse`，剩餘`Silence/Darkness/Doom`. 隨後，一則 LAB 執行時寫入標記了`status_full_auto=0102/0806/4400` 以及`status_innate_auto=0102/0806/4400` 與……一同`suffer=0102`,`sil/dark=255/255`,`extra=4400`,`doom=5/5`；在 150 秒內，移除型道具／法術並未釋放該包裹，而「毀滅」仍持續造成傷害`5 -> 4 -> 5`. Guardrail：這是執行時測試`MemoryChr`, 非 ATEL 撰寫者／SIN 按鈕，直至完成映射`full_auto/innate_auto` 作為字段，或採用 live/DINPUT8 路徑。— Jarvis-Codex
- **🧠 Monster AI Editor — Forbidden Rite RT2：已在 Tidus 上驗證的反 Ribbon 套件。** 首個透過`writeChrProperty(Character#1, field, value)` 在「大逃殺」模式中擊敗了 Ribbon`m034`: 提達收到了`Zombie`,`Confuse`,`Silence(255)`,`Darkness(255)`,`Curse` 以及`Doom(cur=4/init=5)`. 執行時讀取：`suffer=0x0102`,`turns[sleep/sil/dark]=0/255/255`,`extra=0x4400`. 該`m034` 該實驗室的數據已重新彙整為`HP=1.000.000`,`Agility=100` 以及`Accuracy=255` 為了生存並加快行動速度。**Forbidden Rite LAB** 的使用者介面現已列出殭屍/混淆/沉默/黑暗/詛咒/厄運以及厄運對策，並設定了正確的預設值。 目前尚未公開 SIN 預設值：廣域目標、敵對治療及回合懲罰需自行打造 RT2。建構編輯器 0 個錯誤 / 361 個警告。— Jarvis-Codex
- **🧠 怪物 AI 編輯器 — Forbidden Rite LAB 反-Ribbon。** Workbench 新增了首個專用 LAB 寫入器，用於直接對抗擁有 **Ribbon** 的角色來測試狀態效果：卡牌 **Forbidden Rite LAB** 選擇單一目標（`Character#1/#2/#3`,`FrontlineChars`,`TargetActors`,`LastAttacker`)，請選擇`Zombie`/`Curse`/`Doom`, 數值`1`，並儲存至`CombatHandler.onTurn` 使用備份的實際運作`writeChrProperty(target, field, value)` (`PUSHII<target> -> PUSHII<field>

 -> PUSHII<value> -> CALLPOPA 7018`). A rota fica separada de ``setStatField(70AB)` 以避免混淆簽名；這並非公開的 SIN 預設值，且在確認裝備 Ribbon + AEON/BattleTracker 的角色可繞過 RT2 之前，不會聲稱具備繞過功能。Build 編輯器顯示 0 個錯誤 / 361 個警告。— Jarvis-Codex
- **🧠 怪物 AI 編輯器 — SIN 100 個預設值 + 威脅篩選器。** **Spira Instinct Network** 的圖庫新增了一個包含 **100 個預設值** 的唯讀區塊：這批新內容包含`Tribunal of Yevon`,`Fayth Erosion`,`Guado Excommunication`,`Spectral Keeper Wheel`,`Penance Arm Doctrine`,`Omega Scripture`,`Anima Pain Engine`,`Bevelle Inquisition`,`Yu Pagoda Spiral` 以及`Sin Eternal Return`. 使用者介面現在會根據`Threat` (`T1-T3`,`T4-T6`,`T7-T8`,`T9-T10`,`T10`) 除了等級／狀態之外，還會將清單按數字順序排列`SIN-001` ->`SIN-100`;`Tier` 技術風險依然存在，且`Threat` 遊戲內的威脅持續存在。沒有新的編劇：`T10` 這是禁用配方展示區／實驗室，並非公開按鈕。—— Jarvis-Codex
- **🧠 Monster AI Editor — SIN 致命擴充包 + 反Ribbon方案。** SIN 目錄中的唯讀預設從 58 個增加至 **80 個**，並新增了致命／反元策略套件：`Yunalesca's Mercy`,`Ribbon Funeral`,`Rotting Benediction`,`Maester's Noose`,`Penance Clock`,`Anti-Phoenix Liturgy`,`Seymour's Verdict`,`Faythless Prayer`,`All-Life Reversal`,`Yu Yevon's Hunger`,`Omega Pattern` 等等。《聖經》新增了防護欄，用以`Ribbon bypass nao e magia normal` 以及`Status direto no battle actor`，此外還有以下欄位：`StatusCurse`,`StatusDoom`,`DoomCounter`,`StatusResistanceZombie` 以及部分豁免權。新計畫：`docs/ai/SIN_LETHAL_EXPANSION_AND_RIBBON_BYPASS_PLAN_2026-06-08.md`. 目錄現在會將`Tier A/B/C/LAB` 作為技術風險以及`Threat 1-10` 作為遊戲內的威脅，T10 僅適用於《最終幻想 X》中被禁止的代碼。既無新寫入程式，也無經證實的繞過聲稱：下一個關卡是針對配備「緞帶」角色的 RT2，比較普通指令與`writeChrProperty(target, StatusZombie/Curse/Doom, 1)`. 建置編輯器 0 個錯誤 / 361 個警告。 — Jarvis-Codex
- **🧠 怪物 AI 編輯器 — SIN 圖庫在 UI 中已啟用唯讀模式。** **Spira Instinct Network* 的四張卡牌模擬圖

* 轉變為一個結構化的目錄，內含 58 個可瀏覽的預設值（`False Calm`,`Cycle of Ruin`,`Yevon's Maw`,`Unsent Choir`,`Diamante de Shiva`、等），文字／基本元素搜尋、篩選`Todos`/`Tier A`/`Tier B`/`Tier C / LAB`/`A-now`, 可選卡牌及包含行為、基本元素、風險與下個關卡的預覽。目前仍無新寫入器：該面板屬展示／規劃中的創作功能；要將預設值轉為實際按鈕，仍需 BIBLE 條目、AiValidator、AEON diff、備份及 RT2。 建構編輯器 0 個錯誤 / 361 個警告。 — Jarvis-Codex
- **🧠 BIBLE/SIN 研究工具 — 完整的怪物 AI 普查 + 指令魔典 + 58 個 SIN 候選名單。** O`RuntimeTools/AiScriptLab` 新增了兩種唯讀模式：`--sin-census`，該功能會根據怪物生成包含工作節點、偵測到的動作、指令、欄位、目標及模式標記的圖譜；以及`--sin-grimoire`，其中列出了可透過`AiCommandId` 並根據作者歸因的啟發式角色進行分類。在真實語料庫中進行測試：361 個 AiFiles、346 個腳本、330`CombatHandler.onTurn` 已解決，使用 470 個指令，讀取 67 個欄位，寫入 171 個欄位，並處理 37 個目標。新增文件：`BIBLE_OF_SPIRA_MONSTER_AI_CORPUS_ATLAS_2026-06-08.md`,`SIN_COMMAND_GRIMOIRE_2026-06-08.md` 以及`SIN_PRESET_CANDIDATES_2026-06-08.md` 共有 58 個候選預設 (`False Calm`,`Cycle of Ruin`,`Yevon's Maw`,`Unsent Choir` 等）標記為`A-now`/`B-chain`/`C-frontier`/`LAB-only`. 沒有新的寫入器，就沒有新的公開按鈕；這是未來 SIN Chain Builder 可審計的基礎。 — Jarvis-Codex
- **🔎`v2.65.3` — SEYMOUR 審計報告：124 家 ATEL`unknown-call-shape` Atlas 中的問題已按可靠類別（唯讀、位元組級驗證）進行分類。** **ATEL 呼叫型態稽核（SIN 之前）。** 這些`124` v8 語義分析器未將其歸類的 field-writes（`field-write-unknown-call-shape`) 已針對整個語料庫（FFXDataParser target/text，346 個腳本）在 **字節碼** 層級進行了審計，並**完全**分解為兩個已驗證的類別，**剩餘 0 個**。**(1)`0x70A8 btlSetMotionData` — 116 行 (100%)：** 均勻形狀`PUSHII actor · PUSHII field · (PUSHII|PUSHF) value · CALLPOPA` =`(actor, field, value)` 在 **motionProperty** 命名空間中（欄位`0x00..0x09`, 均列於 `AiMotion` 中

PropertyNames`); actor é ref REAL (113× Self `0xFFF3` + Monster#01/#02/#03 `0x15/16/17時`), em 25 monstros → classe **`設定動作資料的行為者欄位值`** (irmão explicit-actor do `0x70B2 setMotionField`; **NÃO** é `setStatField`). **(2) `0x7032 setActorFacingAngle` — 8 rows:** NÃO é field-write — é `(演員、角度)` 2-push **sem field-id**; vazaram pro catálogo por **falso-positivo de regex** (só ângulos FLOAT renderizam `.facingAngle = 90.0 [42B40000h]` e o regex v7 pegou o `.0 [十六進位]` do decimal; os 63 sites-irmãos com ângulo inteiro `= 90 [5Ah]` não vazaram) → classe **`非字段寫入`**. **Mudanças:** bridge `tools/ffxdataparser_bridge/build_atel_semantic_catalog.ps1` (`Get-FieldWriteSemanticKind` + risk notes) reclassifica os dois call-ids; o v8 regenera com `0` unknown (116+8 nas classes novas); a contagem de `AtelFieldWriteShape` fica **`202`** (relabel preserva a cardinalidade da chave `callId|fieldHex|fieldName|semanticKind|fieldCategory`, provado before/after); o pass `unknown-health` cai de `199 → 75` (os 124 ATEL saem do bucket "blocked-until-audited"); narrativas do `SpiraDataAtlasCatalog` (`atlas:field-call-shapes` + guardrail + `atlas:unknown-health`) atualizadas; asserts `--spiraatlas-rt0` movidos (`詳細條目 21316→21192`, `未知健康資料列 199→75`) + **2 asserts-trava novos** (`0` unknown call-shapes remanescentes + `0x70A8` motion-data presente). **Honestidade:** classificar ≠ autorizar writer — todo `AtelFieldWriteShape` segue `唯讀；無寫入權限`, `70A8` continua sem botão/escrita, nada promovido pro SIN. **Achado de fidelidade (read-only):** o decoder do EDITOR (`AiScript_File.cs`) **não** glossa `70A8` (ausente de `FieldArgBack`/`FieldNameForFunc`) e o `AiStackModel` não tem a aridade dele → gap de display handoff p/ a lane MAGIC (`docs/ai/HANDOFF_SEYMOUR_ATEL_DECODER_GLOSS_GAP_2026-06-10.md`), sem efeito de gameplay. **PATCH** (refina/classifica catálogo read-only existente, resolve um data-blocker do SIN; precedente `v2.61.3`/`v2.62.1`；疑難排解→PATCH）。未新增寫入器；不涉及 runtime/AURORA/VALEFOR/native-menu/SIN-chain-builder/CHAPPU/save。已透過對抗性工作流程驗證（3 個反駁者 + 完備性標準）

ic)。編譯過程 0 個錯誤 / 361 個警告；`--spiraatlas-rt0` +`--aicmdmeta-rt0` +`AiScriptLab --ai2` (346/346) PASS. 文件：`docs/ai/ATLAS_SEYMOUR_ATEL_CALL_SHAPE_AUDIT_RESULT_2026-06-10.md`. [上一頁：`v2.65.2`] — Jarvis-SEYMOUR
- **🔧`v2.65.2` — 球形網格：保留空節點的冗餘內容 (0xFFFF) + 波蘭語《Atlas》出現位置資料。** **波蘭語地圖集 / 證據清理 (Jarvis-BARTHELLO)。** **(A) 球形網格強化 (位元組精確度)：** 未`SphereGrid_File.Builder.cs` (writer LAYOUT v2，由`--spheregrid-layout-rt0`)，作者／編輯的路徑`AddNode`/`NodeWith` 正在錄製`RedundantContent = (ushort)(contentIndex & 0xFF)` → 指向一個 **空** 節點（內容`0xFF`) 這會產生`0x00FF`，這與預先提供的資料不符。該語料庫（scout Jarvis-AURON，**3,444/3,444 個節點**：低位字節 == ContentIndex，高位字節僅在 Expert 的 23 個空節點中被設定）證明了空節點 = **`0xFFFF`**, 滿 =`0x00<content>`. 新的私有輔助函式`RedundantContentFor(contentIndex)` 反映了該配對的慣例（empty→`0xFFFF`, 填滿→`0x00NN`).`FromExisting`/`Clone` 繼續複製`RedundantContent` **逐字** → 未經編輯的往返 **位元組完全相同**（未經修改，經閘道器重新驗證）。新增的斷言位於`--spheregrid-edit-rt0` (合成 + 語料庫中的 3 個網格)：`SetNodeContent(idx, 0xFF)` → 版面配置儲存`0xFFFF` 位於節點+0x06 + 內容位元組`0xFF` + 重新讀取空值。遊戲性風險低（冗餘欄位；遊戲讀取內容來自`dat09/10/11` + reach-lists — 已由 AURON 透過 IDA 驗證（兩份二進位檔），但這是已發布寫入器中的忠實度差異。**(B)**`AiBibleWhereAppears.For` 波蘭語（唯讀）：** 已新增此情況`aeon-growth` (Atlas 網域已於`v2.64.0` （原本會落入空的備用方案）並附上如實說明「顯示位置／對應關係」；已更新`sphere-grid-node` （原先為：「Unknown6 維持為『原始／未知』」），以反映 AURON 的燃盡圖 ——`Node.Unknown6` 這是 **遊戲玩法惰性（已透過 IDA 驗證兩個二進位檔）**，可能的殘留內容 = 選單佈局／視覺效果（僅含元資料），未包含任何虛構的遊戲玩法語義。 **修補程式**（修正已發布寫入器中潛在的準確性錯誤 — 「消費者將受益」→ 是的，位元組級準確性 — 並針對文字讀取功能進行了細部優化；

消除疑慮→PATCH）。沒有新的寫入器、沒有新的使用者介面、也不改變提供者／閘道計數（`--spiraatlas-rt0` 完好無損），引擎`Common` (ANIMA)、runtime/AURORA/VALEFOR/native-menu/SIN、CHAPPU/save，亦無實際電網拓撲（建立／移動／重新連接節點時會遵循邊界）。Build 0 個錯誤 / 361 個警告；`--spheregrid-edit-rt0` +`--spheregrid-layout-rt0` +`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文件：`docs/ai/ATLAS_BARTHELLO_POLISH_RESULT_2026-06-10.md`. [上一頁：`v2.65.1`] — Jarvis-BARTHELLO
- **🧪`v2.65.1` — 在 PlayerGrowthEditor 中新增 Atlas 證據標章 + 標籤 Sphere None/Passive（唯讀、值保護、編輯時隱藏）。** **Atlas UI 全面更新。** (1) **PlayerGrowthEditor：** 新增`<common:AtlasEvidenceBadgeStrip>` 在「Growth Curves」卡片（ply_rom.bin）中，使用已建立的存取器`SpiraDataAtlasCatalog.TryGetPlayerGrowthStat(source, characterIndex, field, currentRawValue)` (`v2.65.0`, TIDUS)。新`AtlasEvidenceInfo? SelectedCharacterEvidence` 在`PlayerGrowthEditor_DataModel`，在時段調換時重新計算，並在`CharacterRowChanged` (編輯) → **hide-on-edit**：該徽章基於 3 個經 growth gate 驗證的數值，涵蓋這兩份檔案／卡片（`ply_save` HP 基礎值 +`ply_rom` AP max + HP 係數 A — 與以下相同的查表值`--spiraatlas-rt0` 測試：520 / 22000 / 6），若任何錨點偏離字節基礎語料庫，該片段便會隱藏（與 Mix 徽章的錨點深度相同）`v2.64.1`/Aeon`v2.64.3`). (2) **標籤領域（誠實的，`partial`):**`sphere.bin ActionValue=0x0000` 現在顯示 **「None / Passive」**，且`RangeValue=0x00` 顯示 **"None"** 而不是 "Unknown" — 該`0x00` 這是語料庫中的第三個有效值（約佔無觸發效果球體的 40%，來源：Jarvis-AURON 探測器），並非未知的；下拉選單中已預設「None」選項，並修正了標籤的預設值。(3) **`AiBibleWhereAppears.For`:** 唯讀情況`player-growth` 以及`mix` (誠實的文字「出現在哪裡」，不觸發執行時效果；`sphere-grid-node` （已存在）。**PATCH**（現有功能的再利用：UI 調用存取器 + 引擎`Common` ANIMA 已製作的設計 + 標籤修飾；直接前例：Mix 徽章`v2.64.1`/Aeon`v2.64.3`/商店`v2.61.2` 是 PATCH；解決爭議→PATCH）。沒有 writer nov

o：SphereGridExplorer 徽章原本就已經存在（`v2.60.1`)，玩家成長與球體拓撲的寫入／儲存功能**保持原樣**。不涉及提供者／閘道（`--spiraatlas-rt0` 完好無損），引擎`Common` （僅已使用），runtime/Aurora/native-menu/SIN，亦無 TIDUS/BRASKA/JECHT/RIKKU/WAKKA/VALEFOR/AURORA。建置結果：0 個錯誤 / 361 個警告；`--spiraatlas-rt0` +`--player-rt0` +`--spheregrid-layout-rt0` +`--aicmdmeta-rt0` PASS. 文件：`docs/ai/ATLAS_LULU_PLAYER_GROWTH_SPHERE_BADGE_UI_RESULT_2026-06-10.md`. [上一頁：`v2.65.0`] — Jarvis-LULU
- **🧬`v2.65.0` — Spira Data Atlas 中的 PC/Player Growth（唯讀，`proved-candidate`, 位元組為基準、工作／獨立)。** 將 PC 成長／統計數據的真實來源整合至服務提供者中：新`SpiraDataAtlasDetailKind.PlayerGrowthStat` + 帶有值保護的存取器`SpiraDataAtlasCatalog.TryGetPlayerGrowthStat(source, characterIndex, field, currentRawValue)`. 來源 = **`ply_save.bin`**（基礎/當前數據）+ **`ply_rom.bin`**（生長 ROM：AP 曲線`ApReq A/B/C/Max` + 自增長係數`*CoefA/B`)，正是那些與`PlayerGrowthEditor` 編輯 (解析器`PlayerKernel_File`, 經 RT0 驗證`--player-rt0`). 這 **20 個插槽**（0–6 為 PC，7 為來賓角色＝西摩，8–17 為 Aeons，18–19 未映射）源自一張 **以位元組為基礎編譯的表格**（`FfxLib/SpiraDataAtlas/PlayerGrowthData.cs`，由`tools/ffxdataparser_bridge/build_player_growth_index.ps1 -EmitCSharp` 自`.bin`)，因此在任何不包含`work/` (≠`PcAeonFineStat`，這取決於`work/pc_save_stats_catalog.csv` （而且只是快照）。名稱會在執行階段透過`Character_Enum` （單一真相來源）。**誠實（非顯而易見）：**屬性成長係數僅適用於**Aeon**——PC/訪客的係數設為**零**（PC透過**Sphere Grid**提升屬性）； 本 ROM 中 PC 的唯一成長來源是 **AP 曲線**。其軸線與`sum_grow.bin` 來自 BRASKA（自動平衡 ≠ 自訂配方）。**地區限定：**`ply_save`/`ply_rom` **並非位置不變的**（資料區段的`new_uspc` 與 jppc/inpc 不同；彙編後的表格 =`new_uspc`, 編輯者所處的區域）。遊戲內「每級AP／係數獲取量」公式 = **`RT2-pending`**（已驗證的位元組／欄位，未逆轉的執行時算術）。Value-guard =

與編輯器相同的值空間 → 編輯該欄位（原始值不一致），未知插槽／來源／欄位 → 存取器`false` → 部分徽章（鏡像 Aeon/Shop/Mix）。Gate`--spiraatlas-rt0` `21296 → 21316` (+20；皆為唯一) + **18 個新斷言**（計數 20/8/10/2；PC 係數為零； Aeon 係數不為零；區域 uspc；查表 Tidus 基礎生命值 520 / ply_rom 最大行動點數 22000 / Valefor 生命值係數 6；value-guard`9999` 隱藏；超出範圍的插槽／來源／欄位遺漏；域搜尋；BIBLE 域玩家成長）。唯讀：**無寫入器／UI／執行時／SIN**；不播放`WriteSave`/`WriteRom`,`PlayerGrowthEditor` UI、引擎`Common` ANIMA（僅消耗），亦不含 BRASKA/AURON/JECHT/RIKKU/WAKKA/VALEFOR/AURORA/SIN。Build 0 個錯誤 / 361 個警告；`--player-rt0` +`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文件：`docs/ai/ATLAS_TIDUS_PC_GROWTH_PROVIDER_RESULT_2026-06-10.md` + 球探`docs/ai/ATLAS_TIDUS_PC_GROWTH_SCOUT_RESULT_2026-06-10.md`. [上一頁：`v2.64.3`] — Jarvis-TIDUS
- **🦅`v2.64.3` — Aeon Growth 證明徽章在「自訂編輯器」中（唯讀、值受保護、編輯時隱藏）。** 請將`<common:AtlasEvidenceBadgeStrip>` 在 **“Aeon Grow / Teach”** 標籤頁中`CustomizationEditor` (「食譜編輯器」卡片)，使用已建立的存取器`SpiraDataAtlasCatalog.TryGetAeonGrowthRecipe(entryIndex, currentResultRaw, currentItemRaw)` (`v2.64.0`). 新增`AtlasEvidenceInfo? SelectedAeonEvidence` 在`CustomizationEditor_DataModel`, 在查詢條件變更時重新計算，以及當選取的資料列被觸發時`RawResult` (`AeonRecipeChanged`) → **hide-on-edit**：若編輯所傳授的技能／屬性、成本項目（原始值不一致）或超出範圍的數值，則存取器會返回`null` 而該條目被隱藏（無過期標記），是 Mix 的精確鏡像（`v2.64.1`). 這 10 項屬性配方會顯示徽章 **`partial`** (cost-semantics：編輯器會渲染`Primary× item`，但在遊戲中每次使用需消耗 1 項物品）。**不修正寫入程式或消耗量顯示**（超出範圍）。重複使用引擎`Common` 來自 ANIMA（僅供食用）。PC 繼續`blocked` （無 PC 行）與 Sphere`metadata-only` (無聯結) — 無資料可顯示。提供者／閘道未變更 (`--spiraatlas-rt0` 完好無損，`21296` 詳細資訊 / 77 Aeon)。建置 0 個錯誤 / 361 個警告；`--customization-rt0` 

+`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS。不包含 JECHT/Mix、TIDUS/PC、AURON/Sphere、RIKKU/WAKKA/VALEFOR/AURORA/SIN。文件：`docs/ai/ATLAS_BRASKA_AEON_GROWTH_BADGE_UI_RESULT_2026-06-10.md`. [上一頁：`v2.64.2`] — Jarvis-BRASKA
- **🏐`v2.64.2` — 閃電球存檔編寫器 LAB + 偏移值 SAVE-PROVED 與真實存檔（無錦標賽）的對比。** 閃電球的獎勵偏移值已從 RE 移至 **save-proved**：我找到了真實的存檔（`Documents\SQUARE ENIX\...\FINAL FANTASY X\ffx_000..006`, 7 個插槽`0x6900` =`0x40 header + 0x68C0 SaveData`) 以及`ffx_000` 解碼完全正確（聯賽 = 超級靈藥/超級藥水/速度球，錦標賽 = 靈藥/超級守門員/藥水，等等）——儲存 **純文字，無加密/壓縮** (gil/story/battle_count 均正常)，`--base 0x40` 已確認。標題為`0x40` 有簽名`"cxs"` + 遊玩時間／地點；**沒有任何欄位的校驗和與 SaveData 匹配**（可能是缺少阻塞性校驗和，但遊戲內還缺一次載入）。新的 LAB 寫入器`Tools/BlitzballSaveWrite.cs` (`--blitz-save-write <in> <field> <value> <out>`): 將 1 個 prize-index u16 寫入 **新檔案**（絕不覆寫原始檔案；拒絕就地覆寫），其中 before/after 由 Atlas 目錄解決。已在 **副本** 中驗證`ffx_006`:`tournament0 25 (Elixir) -> 50 (Saturn Crest)`, diff = 恰好 2 位元組，其餘部分位元組完全相同。`BlitzballSaveRead.Resolve` 翻了`internal ResolvePrize` （由 Writer 重新使用）。**存檔 (ffx_NNN) ≠ 遊戲檔案**：編輯存檔會改變「此」進度；變更存檔池（`takara.bin` (220..320) 是 Treasure/RIKKU。未觸及 Atlas UI/Shop/Treasure/Mix/Common/Aurora/Bahamut/SIN。建置結果：0 個錯誤 / 361 個警告。文件：`docs/ai/BLITZBALL_SAVE_RUNTIME_WRITER_SCOUT_2026-06-09.md`. [上一頁：`v2.64.1`] — Jarvis-WAKKA
- **⚗️`v2.64.1` — Mix Table Editor 中的 Atlas 證據標籤（唯讀、值保護、編輯時隱藏）。** 透過接入存取器實現 UI 唯讀功能`SpiraDataAtlasCatalog.TryGetMixCombination` (發送於`v2.63.0`) 在`MixTableEditor`：**「組合編輯器」** 卡片（詳細資訊面板）現在會顯示`<common:AtlasEvidenceBadgeStrip>` 所選 Mix 組合中的 — 每個組合一個音軌（而非每行一個；可避免 6,328 次查表及雜訊），與 Treasure/Shop 完全一致。`Mix

TableEditor_DataModel` ganhou `[ObservableProperty] AtlasEvidenceInfo? SelectedMixEvidence` + `RefreshSelectedMixEvidence()` (`TryGetMixCombination(origin.Index, result.PartnerIndex, result.RawResult) → AtlasEvidenceInfo.ForDetail`), chamado em `OnSelectedResultChanged` (cobre troca de combinação E de origin via cascata) e em `ResultChanged` quando `RawResult` muda (cobre edição do resultado via `ResultRef→SyncBack→NotifyComputedChanged` e o "Set Empty"). **Hide-on-edit:** editar o resultado p/ outro item, "Set Empty" (raw 0), célula vazia/espelho do triângulo superior, ou par fora do corpus → accessor `false`/`null` → a strip **auto-esconde** (`IsVisible=false`); ordem `(來源、合作夥伴)` irrelevante (canonicalização max/min no accessor). **REUSO** da capacidade `v2.63.0` + da infra `Common` da ANIMA (só consumida) → **PATCH** (precedente: badges UI de Shop `v2.61.2`/`v2.61.5` foram PATCH). Sem writer novo: `--mixtable-rt0` segue **byte-identical** (25108/25108). Não toca o motor `Common` (ANIMA), o provider, Treasure/Shop (RIKKU), BRASKA/WAKKA/AURORA/BAHAMUT/SIN. Revisado por workflow adversarial de **5 lentes** (hide-on-edit, writer/read-only, ANIMA-boundary, XAML-binding, honesty) + síntese → `船`, 0 defeitos. Build 0 erros / 361 warnings; `--spiraatlas-rt0` (Mix 6328) + `--mixtable-rt0` (byte-identical) + `--aicmdmeta-rt0` PASS. Doc: `docs/ai/ATLAS_JECHT_MIX_BADGE_UI_RESULT_2026-06-10.md`. [anterior: `v2.64.0`] — Jarvis-JECHT
- **🦅`v2.64.0` — Spira Data Atlas 中的 Aeon 擴充功能／自訂設定（唯讀，`proved-candidate`, Aeon 獨家，彙編版)。** 請插入`sum_grow.bin` (FFX 中 Aeon 的自訂表) 在提供者中設定為「唯讀」的詳細資料類型：新增`SpiraDataAtlasDetailKind.AeonGrowthRecipe` + 帶有值保護的存取器`SpiraDataAtlasCatalog.TryGetAeonGrowthRecipe(entryIndex, currentResultRaw, currentItemRaw)`. **Aeon-ONLY：**`sum_grow.bin` 是 636 位元組（標頭`0x14` + **77 筆資料 × 8B**，`Target` 總是`0x007F`=Aeon,`jppc`==`inpc` 字節相同) → 67 項能力配方 (結果類別 3 → 指令) + 10 項屬性配方 (結果類別 0 → 屬性選項，次要=1)。**沒有 PC 或 Sphere Grid 的資料列** (`PcAeonFineStat` 這是另一個語料庫；網格的拓撲結構存在於

`sphere.bin`/`panel.bin`). **來源非-`work/`:** 這 77 行來自一個 **以位元組為基礎彙編** 的資料表（`FfxLib/SpiraDataAtlas/SumGrowAeonRecipeData.cs`，由`build_sum_grow_aeon_fine_index.ps1 -EmitCSharp` 自`sum_grow.bin`)，因此在任何未包含`work/` (≠ Mix/Sphere/Shop，這些取決於`work/`). 名稱／標籤會在執行階段由`AeonCustomizationEntry`+編輯器自帶的字典（單一可信來源，經 RT0 驗證）`--customization-rt0`)，從未被重新設計過。**屬性配方成本 =`partial`**（編輯器會進行渲染`Primary× item`；遊戲內每次使用需消耗 1 項物品，且`Primary` （即增幅）——刊載於專欄中`evidence` (`;cost-semantics-partial`)，而不僅限於文字。Gate`--spiraatlas-rt0` `21219 → 21296` 詳細資訊（+77 永恆；皆為獨一無二）+ **13 項新斷言**（計數 77/67/10； 僅限 Aeon；無 PC；無 Sphere；查閱能力 66→Ultima/Supreme Gem；查閱屬性 67→HP+100/Power Sphere/部分消耗；數值保護`0x9999` 隱藏；超出範圍的索引；域名搜尋；BIBLE 域名 aeon-growth）。唯讀：無 writer/UI/runtime/SIN；不播放 RIKKU/WAKKA/JECHT/BAHAMUT/AURORA，引擎`Common` 徽章（ANIMA）亦非`WriteAeon`/儲存路徑。**解鎖 YUNA 待辦事項清單中的 Q1 項目**（原先是`blocked`). 已透過 Scout 上的 4-lentes 對抗性工作流程進行驗證。建置結果：0 個錯誤 / 361 個警告；`--customization-rt0` +`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文件：`docs/ai/ATLAS_BRASKA_SUM_GROW_FINE_SCOUT_RESULT_2026-06-10.md` +`docs/ai/HANDOFF_BRASKA_SUM_GROW_FINE_INDEXER_NEXT_2026-06-10.md`. [上一頁：`v2.63.0`] — Jarvis-BRASKA
- **⚗️`v2.63.0` — 在 Spira Data Atlas 中查看混合詳情類型（唯讀，`proved-candidate`, value-guarded)。** Mix 在 Atlas 上的首個誠實錨點：新`SpiraDataAtlasDetailKind.MixCombination` + 輔助器`SpiraDataAtlasCatalog.TryGetMixCombination(originIndex, partnerIndex, currentRawResult)` 載入「parser-canônico」資料集`work/step0_consolidated_v5/mix_combinations.csv` (**6,328 行 = 112×113/2，0 組重複鍵值對**) 在提供者中。該`prepare.bin` 這是一個 112×112 的 **下三角矩陣**（原點`O` 僅在合作夥伴欄位中出現非零結果`0..O`)，因此每個非順序對

已`{a,b}` 存在於單一標準細胞中，orig=max，partner=min；該金鑰`mix:0x{0x2000+max}+0x{0x2000+min}` 可根據索引重建`(origin, partner)` 編輯註：**無需猜測**。`result_hex` 這與編輯器讀取的「little-endian」一詞完全相同，即`MixResultRow.RawResult` (字節完全相同的編輯器讀取器，由`--mixtable-rt0`; 具有相同字節序的解析器) → value-guard = 在同一空間內進行整數比對：編輯結果會破壞匹配並隱藏標章（無過期）；空儲存格（原始值 0，包含整個上三角區域）會觸發短路。 **單一來源：** value-dict + detail 來自同一個 CSV 檔案。Gate`--spiraatlas-rt0` `14891 → 21219` 詳細資訊 (+6,328 種組合；皆為獨一無二) + **8 項新斷言** (計數 6328；查閱 0+0→超強藥水)`0x30AC`；教規順序`(3,1)==(1,3)`; value-guard`0x9999` 隱藏；空儲存格 raw-0 未找到；索引超出表格範圍 未找到；按網域搜尋；BIBLE 網域 mix）。唯讀：不含 writer/UI/runtime/SIN；**不觸及** Mix 編輯器（writer）、Treasure/Shop（RIKKU）以及引擎`Common` ANIMA 的徽章（僅能透過搜尋取得），亦不包含 Aurora/Bahamut/native-menu。**解鎖 YUNA 待辦清單中的 Q2 項目**（原本是`blocked`). 介面上的徽章線 = 下一次交接 (`docs/ai/HANDOFF_JECHT_MIX_ATLAS_PROVIDER_NEXT_2026-06-10.md`). 編譯 0 個錯誤 / 361 個警告；`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文件：`docs/ai/ATLAS_JECHT_MIX_DETAIL_KIND_SCOUT_RESULT_2026-06-10.md`. [上一頁：`v2.62.1.1`] — Jarvis-JECHT
- **🏐`v2.62.1.1` — Blitzball 讀取器／差異比對（唯讀），源自 prize save 的 scout RE。** 唯讀 CLI 工具（`Tools/BlitzballSaveRead.cs` + 派送編號`Program.cs`) 用於開啟一個存檔`.dat` 並解碼閃電球（Blitzball）的 4 個獎金指數（`league`/`tournament` ×`prize[3]`/`top-scorer`) 在重新驗證過的偏移量中（SaveData @`file+0x40`, BlitzballData @`+0x1984`; 聯賽獎勵 @ 存檔檔`0x1A3C`, 錦標賽`0x1A42`, 得分王`0x1A48`/`0x1A4A`)，並透過已建立的 Atlas 資料庫計算出每個獎勵值。模式：`--blitz-save-read <save>` (解碼) 以及`--blitz-save-diff <before> <after>` (save-compare：獎品 A 與 B 的比較 + 整個檔案的位元組差異，標記 BlitzballData 中的執行區段並解碼 u16)`old->new`).`--base` ov

可能有誤（磁碟上的資料庫 **尚未** 經即時確認）。資料庫`SaveData` RVA`0xD2CA90` 經 IDA 確認（`sub_785300` 返回`imagebase+0xD2CA90`) + 華氏 + MemoryMap；`sub_8B5450` (memcpy`0x68C0` 來自`SaveFile+0x40`) 驗證檔案的佈局。**100% 唯讀：保存檔／遊戲／RAM 中均未寫入任何資料。** 已通過合成煙霧測試（解碼 + 獎勵解析 + 透過差異比對定位變更）。 未觸及 Atlas UI / Shop/Treasure/Mix / Common / Aurora/Bahamut/SIN。建置結果：0 個錯誤 / 361 個警告。文件：`docs/ai/BLITZBALL_SAVE_RUNTIME_WRITER_SCOUT_2026-06-09.md`. [上一頁：`v2.62.1`] — Jarvis-WAKKA
- **🔗`v2.62.1` — 採用單一來源（FONTE ÚNICA）的 item-shop value-guard（消除漂移 + 固定操作數地雷）。** item-shop value-guard 的強化：提供者現在會讀取`slot_value_hex` 來自同一個 CSV 檔案（`item_shop_command_crosslink.csv`) 負責建構 detail`atlas:item-shop`，而非第二個檔案（`item_shop_slots.csv`) — value 和 detail 現在來自同一行，且 **不得不一致**。橋接`build_spira_atlas_step0c_crosslinks.ps1` 現在正在發放`slot_value_hex` 作為 Crosslink 的專欄，**清除一枚潛伏的地雷**：數學`slot_value + 0x2000` （寫於`slot_value_hex` （若為空／原始索引）將開始計算`0x4000` 既然解析器現在會輸出完整的編碼值（`0x2000` p/ Potion) → 結合 FALSO 與`Attack` （AI 指令）— 正是護欄的分類錯誤。`item_operand_hex` 此處依設計留空（game-index 項目 ≠ AI 運算數）。經由三視角對抗性工作流程驗證（漂移／單一來源、運算數／編碼、迴歸／齒輪）——`sound`; 已修正 2 則過時的評論。**多車道註記：** PROVIDER 的半數已被掃入`v2.62.0` (提交`2bc3d7b0`, lane WAKKA,`git add` （廣泛的競爭對手）；此提交包含使 HEAD 保持一致的 BRIDGE 的一半內容。Gear 未受影響。未涉及 writer/UI/runtime；亦未觸及 Treasure/Mix/Common/Aurora/native-menu。編譯結果：0 個錯誤 / 361 個警告；`--spiraatlas-rt0` PASS（9 項商店確認：5 件裝備 + 4 件物品）+`--aicmdmeta-rt0` PASS. 文件：`docs/ai/ATLAS_RIKKU_ITEM_SHOP_SINGLE_SOURCE_RESULT_2026-06-09.md`. [上一頁：`v2.62.0`] — Jarvis-RIKKU
- **🏐`v2.62.0` — Blitzball Prize Explorer：UI 重新設計

Atlas 的專用廣告模組。** 新增模組`Modules/BlitzballPrizeExplorer` (在 Reference/RE 群組中，標記為 **Blitzball 獎品 🏐** 的項目，無專案審核門檻)，該項目會使用已關閉的目錄`SpiraDataAtlasCatalog.BlitzballPrizeDetails` (網域`blitzball-prize`): 可搜尋的 DataGrid，包含 **prize id · takara index · reward 已解決 · kind · evidence** 等欄位，可依狀態／證據及種類進行篩選，並顯示 **規則** 的橫幅`prize 0..100 -> takara 220..320 -> reward`**（已驗證的離線候選項），以及包含來源／規則／「出現位置」／限制條件的詳細資訊面板 +`<common:AtlasEvidenceBadgeStrip>` (Atlas/BIBLE 徽章)。誠信如一：treasure =`proved-candidate` (從未 RT2)；這 64 個聯賽／錦標賽／賽事的腳本網站明確顯示為`blocked` (每項事件的獎勵為運行時間/存檔次數)；技術 =`partial`; overdrive =`metadata-only` — 除了當前的標籤外，沒有任何內容會變為綠色。新增一個微小的唯讀存取權限`SpiraDataAtlasCatalog.BlitzballPrizeDetails` (lazy, dev`work/` （僅）+ 2 個斷言未通過`--spiraatlas-rt0` (229 行 = 164 個目錄 + 64 個網站 + 1 個防護欄；網域檢查)。無 Writer，無 Runtime；無法執行 RIKKU/Shop/Treasure/Mix，引擎`Common` ANIMA（僅消耗）以及 Aurora/Bahamut/SIN。建構結果：0 個錯誤 / 361 個警告；`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文件：`docs/ai/ATLAS_WAKKA_BLITZBALL_UI_RESULT_2026-06-09.md`. [上一頁：`v2.61.5`] — Jarvis-WAKKA
- **🛍️`v2.61.5` — 物品商店中的「阿特拉斯證據徽章」（附帶價值防護） — 完成了裝備與物品的組合。** 複製了裝備商店中已驗證的價值防護（`v2.61.2`) 轉至 item-shop，既然現在`v2.61.1`+從語料庫解鎖後，該項目獲得了以位元組為基準的 1:1 原始值。新增唯讀存取器`SpiraDataAtlasCatalog.TryGetShopItemSlot(bank, slot, currentRawValue)` + 懶惰`_shopItemSlotValues` (讀作`item_shop_slots.csv`, 應`work/` only，未編譯備用方案）— 完全相同的鏡像`TryGetShopGearSlot`: 解決`atlas:item-shop:item-shop-0x{bank}-slot-{n}` **只有**當`RawValue` 該插槽的當前狀態仍與資料集相符（磁碟上的 ushort LE = 遊戲索引項目）`0x2xxx`（與編輯器位於同一空間），且 ≠ 0。`ShopExplorer_DataModel` 現在計算`Evidence` 由 shop-kind（切換裝備／道具）；o`<common:AtlasEvidenceBadgeStrip>` 在卡片上

該插槽 **先前已共享**（`v2.61.2`)，此時項目便會顯示標章，且無需修改 XAML；編輯槽位會重新建構該行並隱藏條帶（不會產生過期資料）。Gate`--spiraatlas-rt0` 獲得了 **4 項斷言**（查詢`0x2000`/魔藥，不匹配`0x9999` 隱藏、空槽位 raw 0、無實體槽位 3)，全部通過（齒輪仍為通過）。已重生`work/step0_consolidated_v5/item_shop_slots.csv` 與`slot_value_hex` (404/404，僅限開發，尚未提交)。唯讀：無寫入權限，請勿修改 Treasure/Mix/Common/Aurora/native-menu/runtime；引擎`Common` ANIMA 僅執行。Build 0 個錯誤 / 361 個警告；`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文件：`docs/ai/ATLAS_RIKKU_SHOP_ITEM_BADGE_UI_RESULT_2026-06-09.md`. [上一頁：`v2.61.4`] — Jarvis-RIKKU
- **🎮`v2.61.4` — WIRED 的 Native Menu Shell 在`ffx-hooks.dll` （已套用第 5 階段，預設為 OFF）。**第 5.1 階段的修補程式（已通過對抗性審查，無阻滯問題）已**套用**於`dllmain.cpp` （最低修補程式：僅`dllmain.cpp`, +166 行, 0 處刪除) — 連結至`NativeMenuShell.h` （內建選單，文字為「NOSSO」）至 Aurora 橋樑（`PhotoModeActions.h`) 經由泵的繞道`FFX_Menu_PerFramePump 0x8A9C50` (`int __cdecl(uint)`, IDA 已驗證, MAIN THREAD)。**預設為關閉：**`FFXHOOKS_ENABLE_NATIVE_MENU=1` 設定繞道；選單僅能透過熱鍵 **F7** 開啟。**「曙光合約」已接受並遵循：**`PhotoMode::Tick()` = **選項 A**（頂部`AuroraD3DRender`，在提前歸還之前，透過`FFXHOOKS_ENABLE_AURORA_OVERLAY=1`, hunk AURORA 所有）；FREEZE = 唯一所有者`g_pm.frozen`;`NtSuspendProcess` **禁止**；`PhotoMode::g_base=g_base` 在 init 中。該 wire **僅呼叫`PhotoMode::*`** — **無法寫入 RAM 快照 (`0xD378A0`) 亦非 RAM** 元件。Build`-WithPolyHook -Release` **PASS** (`dllmain`+`MusicHook`+`ElementHook` →`ffx-hooks.dll`). **第 6A/NPC 步驟已從**此更新中移除。**RT2-待處理：**在選單/場地中按下 F7 → 應顯示原生「拍照模式」介面（一次性儲存）。文件：`docs/ai/HANDOFF_BAHAMUT_NATIVE_MENU_WIRE_BLUEPRINT_2026-06-09.md`. [上一頁：`v2.61.3`] — Jarvis-BAHAMUT
- **📒`v2.61.3` — Atlas 服務供應商：`BlitzballPrizeRef` 標準化（唯讀）版本，取代了那段長達 76 行的原始擷取資料。** `SpiraDat` 的 prize 區段

aAtlasCatalog` deixou de varrer `bltz0200/0201` cru e passou a ler o dataset normalizado do WAKKA (`work/step0_閃電球_獎品_參考_2026-06-09`): **164 prize-index rows** (101 treasure `已通過篩選的候選人` via `prize+220 -> takara 220..320 -> reward`, fechado por 3 fontes offline — Fahrenheit `blitz_prize.cs` + `bltz0201 取得寶藏` + `bltz0200/0201 Treasure-Label` — sobre takara RT0; 60 tech `部分`; 3 overdrive `僅元資料`) + **64 script-sites `被封鎖`** (prêmio por-evento é variável de runtime/save). Guardrail reescrito: regra `已通過篩選的候選人` offline, prêmio concreto por liga/torneio `被封鎖`, nunca RT2, nunca writer. Gate `--spiraatlas-rt0` subiu de `14739` para **`14891`** detalhes (`BlitzballPrizeRef 76 → 228`) e ganhou asserts data-grounded (treasure 101 / tech 60 / overdrive 3 / sites 64; prize 0 -> takara 220 Hi-Potion; prize 100 -> takara 320 Phoenix Down; treasure `已通過篩選的候選人`-não-RT2; overdrive `僅元資料`; site `被封鎖`). Patch verificado por review adversarial de 4 agentes antes de aplicar. Sem UI, sem writer, sem SIN/runtime; não toca Shop/Treasure/Mix (RIKKU), o motor de badges `Common` (ANIMA) nem Aurora/native-menu. Build 0 erros / 361 warnings; `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS. Doc: `docs/ai/ATLAS_WAKKA_BLITZBALL_PROVIDER_INTEGRATION_RESULT_2026-06-09.md`. [anterior: `v2.61.2`] — Jarvis-WAKKA
- **🏷️`v2.61.2` — Shop Explorer 中的 Atlas 證據徽章（僅限裝備，價值受保護）。** 一個可插入的唯讀 UI，該 UI 會`TryGetShopGearSlot` （經證實於`v2.61.1`) 在`ShopExplorer`：**gear-shop** 的每個插槽會顯示`<common:AtlasEvidenceBadgeStrip>` 源自/徽章/該裝備槽「顯示位置」的獎勵——**僅限**當`RawValue` 當前的版本仍與語料庫相符。`ShopEditableSlotRow.Evidence` (`init`) 計算於`From()`:`source.Kind == Gear && TryGetShopGearSlot(entry.Index, slot.SlotIndex, slot.RawValue)`. 由於在每次變更時都會重新建構該行（下拉式選單／清空／撤銷／捨棄／儲存／重新整理 →`RebuildSelectedSlots`)，編輯該插槽會重新計算記錄並**隱藏該條目**（不會出現過期徽章）。**商店商品永遠不會獲得徽章**（守護`Kind == Gear` + 雙重檢查：該項目在語料庫中無條目）；欄位為空

o (raw 0) 發生短路。經由 3 種鏡頭的對抗性工作流程驗證（完整生命週期 / item-shop+binding / honesty）→ 全部`sound`, 0 項瑕疵。拒絕接受該設備`Common` 來自 ANIMA（不觸及引擎）；無新寫入器、無新解析器、無 SIN/runtime/Aurora/native-menu。層級`parser-corpus`+`RT0`+`read-only`，從來沒有`proved` 執行階段。Build 0 個錯誤 / 361 個警告；`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS（無閘口）`--shop*` 在`Program.cs`). 文件：`docs/ai/ATLAS_RIKKU_SHOP_GEAR_BADGE_UI_RESULT_2026-06-09.md`. [上一頁：`v2.61.1`] — Jarvis-RIKKU
- **🛒`v2.61.1` — Gear Shop 的 Atlas Value-Guard 插槽（`proved-candidate`) + 老實說，這家道具店`blocked`.** Shop 探勘的第二輪（`HANDOFF_ATLAS_RIKKU_SHOP_SLOT_VALUE_INDEXER`): 解鎖 Shop，其 value-guard 已於 Treasure 中獲得驗證。經由 8 名分析員（5 名取證分析員 + 2 名攻擊者模擬分析員 + 1 名合成分析員）的工作流程驗證：該`RawValue` 編輯器中的槽位是磁碟上未經處理的 little-endian ushort（`ShopTable_File` ≡`ReadBaselineSlotValue`)，以及`slot_value_hex` 從`gear_shop_slots.csv` (445/445 已填寫，比率為`shop_arms.bin`) 就是這個單字 — 因此該守護程序是在同一記憶體空間中進行整數比對，**沒有「偏移一」問題**（目錄`MinIndex=0`, 索引 0 = 預留的 NULL 欄位，首個可銷售檔位 = 索引 1 =`0x01`). 新的唯讀存取器`SpiraDataAtlasCatalog.TryGetShopGearSlot(bank, slot, currentRawValue)` + 懶惰`_shopGearSlotValues` (dev`work/` 僅此而已，未編譯備用方案，與 Sphere Grid 節點相同）：已解決`atlas:gear:gear-shop-0x{bank}-slot-{n}` **僅當**該插槽的當前值仍與語料庫相符（且 ≠ 0）時 → 編輯該插槽會隱藏標記（無過期狀態）。閘門`--spiraatlas-rt0` 獲得了 **5 個持久性斷言**（Tidus 正向查詢/值 1、value-guard 不匹配 999 隱藏、原始空槽位 0、無實體的銀行、邊緣`0x2E`/427)，全部為PASS。**Item-shop =`blocked`**：語料庫不會儲存原始值（`item_shop_slots.csv.slot_value_hex` 100% 空 —`ItemShopDataObject.toString()` 僅輸出名稱）；string-guard 並非假陽性安全（Potion/Phoenix Down/Antidote x47 → 過期；佔位符 + 美版與日版差異 → 假陰性）。 解鎖 = 解析器中的一行修補程式 + 重新執行（語料庫任務，不在此程式碼範圍內）

. 老實的排名：`proved read-only candidate (parser-corpus + reader-semantics + RT0)`, **絕不**`runtime`/`byte-grounded` (無`arms_shop.bin` （已在此處進行十六進位轉儲）。沒有使用者介面、沒有寫入器、沒有 SIN、沒有執行時環境，也未觸及引擎`Common` (ANIMA)。編譯過程 0 個錯誤 / 361 個警告；`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文件：`docs/ai/ATLAS_RIKKU_SHOP_SLOT_VALUE_INDEXER_RESULT_2026-06-09.md`. [上一頁：`v2.61.0`] — Jarvis-RIKKU
- **🐉`v2.61.0` — 原生選單 第 3 級：原生清單的 row-source 重新關閉 +`list-read` (probe) + 現場驗證選取讀取。** 延續原生遊戲內選單的路徑（Yojimbo→**Jarvis-BAHAMUT**），第三階段的第 1 個漏洞（「原生清單的行從何而來？」）已由 IDA 解決：清單的 **INPUT** (`FFX_Menu_List_UpdateInput 0x8B4460`) 是 **100% 通用** —— 純粹基於 152B 物件欄位的算術運算（`+40` state,`+48` count,`+50` 頂部，`+52` 目標,`+58` 頁面，`+66` 老虎機，`+69` 結果，`+70` scroll,`+72` 已選取，`+28` validator)，**不會觸及任何全域變數**，且被 **10 個不同的建構器** 重複使用；但 **所有原生繪製操作皆為項目型**：scene3 清單 (`FFX_Menu_CreateScene3ScrollableList 0x8B4FB0` → 繪製`0x8B4A00` → 行`0x8B4B20`) 讀取來自`unk_159EC30[64*i]` (64B 的結構體) +`byte_1866250[]` (類型)，其中 **項目名稱** 由`0x86C3C0(id→tabela)` 以及可選的直接標籤在`rowPtr+32` (類型 1)；載入 scene3/33/34，並依賴 Customize 的全域變數。二進位檔中**並不存在**「自由文字清單」的繪製功能——因此，需要一個包含我們自身文字的原生清單（即 Aurora 的競技場外殼／照片模式） **需要 DLL 的繪製回調**（步驟 5，《聖經》§4 中預定的路徑），並採用**已記錄的自訂解決方案**（通用輸入`0x8B4460` + 透過基本圖形元素繪製 DLL`sub_8F5F70` 視窗 /`sub_9016B0` 字串 /`sub_8C0640` 游標，正在讀取`+69`/`+72`). 今日透過 probe 提交：新動詞 **`ffxprobectl list-read [handleHex]`**（唯讀）**掃描**選單物件池**（`g_FFX_MenuObjPool 0x18408C0`, 32 個插槽 × 152B) — 會找出任何處於「活躍」狀態的原生清單／下拉選單，並透過回呼函式識別其身分 — 此外還有全域快捷鍵 (`dword_1866214`/`186A5DC`/`23CC120`). **✅ RT2 PASS（直播，2026年6月9日

):** 在 **自訂裝備** 模式下，池掃描擷取了瀏覽過的清單（slot[3]`@0x017A0A88`,`input=0x8D57E0` = 的封裝函式`0x8B4460` 通用名稱）以及`+72`/`SELECTED` **即時追蹤游標位置 (35→42)**，同時 Halyson 操作 → 步驟 3「讀取可導航原生清單中的選項」**已驗證無需輸入任何內容**。（額外資訊：`+62 = group 0x101` 重置後的物件與`FFX_MenuObj_Reset` (IDA) — 已確認的偏移量對應至記憶體。）不觸及 RAM / Aurora /`dllmain.cpp` / 儲存；IDA 唯讀（副本`_claude_ida`（參見文件中的 rename-queue）。建置`ffxprobectl` 0 個錯誤。**第 5 步（藍圖）：** 原生外殼的「可直接貼上」骨架位於`RuntimeTools/NativeMenuShell/NativeMenuShell.h` (+README) — 物件手動實作 + 繪製回呼函式 (視窗+行+游標) + 字型編碼器 + 用於 Aurora「相片模式」動作的解耦橋接器； 已確認 ABI/偏移量（經 IDA 驗證工作流程）並**經過對抗性審查**（2 種 FFX-vs-IDA 視角 + C++ → 無當機/編譯錯誤）；x86 守護條件 + 防越界鉗位 + 註解式負載不變式； **未硬連線，不觸及**`dllmain.cpp`**. **第 5.1 步（線路藍圖，尚未套用）：** 平面圖 + 修補草圖（`docs/ai/HANDOFF_BAHAMUT_NATIVE_MENU_WIRE_BLUEPRINT_2026-06-09.md` +`docs/patches/BAHAMUT_NATIVE_MENU_WIRE_DRAFT_2026-06-09.patch`) 將果皮綁在`ffx-hooks.dll` 繞道經由泵站`FFX_Menu_PerFramePump 0x8A9C50` (`int __cdecl(uint)`, IDA 已驗證, 主執行緒) — 預設為關閉 (`FFXHOOKS_ENABLE_NATIVE_MENU` + 快捷鍵 F7)，僅呼叫橋接`PhotoMode::*`; 經對抗式審查（2 位審查員）**未使用阻斷器**（編譯審查員在一個臨時樹上進行審查，`git apply --recount --check` exit 0);`dllmain.cpp` 未處理／未提交。文件：`docs/reverse/FFX_NATIVE_MENU_LIST_ROW_SOURCE_2026-06-09.md`. [上一頁：`v2.60.2`] — Jarvis-BAHAMUT
- **💰`v2.60.2` — 在「寶藏編輯器」（齒輪寶箱）中新增「阿特拉斯證據徽章」＋對「寶藏」交叉連結的誠實修正。** 偵察員`HANDOFF_ATLAS_RIKKU_TREASURE_SHOP_MIX_CROSSLINK_SCOUT` 重新開啟了「Treasure 沒有穩定密鑰」一案，該案由`v2.60.1` 並在設備箱方面**證明了相反的結論**：該`source_key` 交聯`treasure-buki-get` 它並非不透明——它是`treasure:0x{index:X4}`,

可直接從編輯器行索引進行重建。位元組級校對：`(treasure_index, buki_get_id)` 來自 crosslink ≡`(logical_index, type)` 來自`takara.bin` 針對 **82 行 Kind=0x05，0 處不匹配**。新增唯讀存取器`SpiraDataAtlasCatalog.TryGetTreasureGear(treasureIndex, expectedBukiGetRow)` 解決`atlas:gear:treasure-0x{index}` **搭配 value-guard**：由於 Treasure 是一個可編輯的模組，因此徽章僅會在`buki_get` 目前寶箱的內容仍與資料庫一致——重新標記／更換 Kind 會隱藏該條目（無過期標記）。此設定已套用至「Gear Pickup / buki_get」卡片中`TreasureEditor` 來源`AtlasEvidenceInfo.ForDetail` +`<common:AtlasEvidenceBadgeStrip>` (徽章`parser-corpus`+`RT0`+`read-only`，從來沒有`proved`). **Shop** 變成了`partial` (一個位置鍵`0x{banco}:slot:{n}` 它既穩定又可重建，但商店中僅提供`display_text` 而 gear-shop 並未提供按插槽分類的索引，因此可編輯模組中沒有乾淨的 value-guard → UI 延遲（無誤報）。**Mix** 保持`blocked` （圖譜中不存在「Mix」的詳細類型；若要建立一個，就等於憑空捏造一個錨點）。**BukiGet** = 冗餘/1:多（已由 takara 自我引用）。Gate`--spiraatlas-rt0` 獲得了 3 個持久的斷言（正向查詢 + value-guard + 非齒輪錯位），全部通過。無寫入操作、無 SIN、無執行時錯誤，且未觸及的徽章引擎`Common`. 編譯 0 個錯誤 / 361 個警告；`--spiraatlas-rt0`,`--aicmdmeta-rt0` 以及`--treasure-rt0` PASS. 文件：`docs/ai/ATLAS_RIKKU_TREASURE_SHOP_MIX_CROSSLINK_SCOUT_RESULT_2026-06-09.md`. [上一頁：`v2.60.1`] — Jarvis-RIKKU
- **🔮`v2.60.1` — 在 Sphere Grid Explorer 中顯示 Atlas 證章（第二個唯讀應用程式）。** 該證章的基礎架構`v2.60.0` 獲得了第二個家：在選取一個節點時，於`Sphere Grid Explorer`，該面板顯示證據徽章（`parser-corpus` +`RT0` +`read-only`)，節點的來源及「出現位置」，透過`AtlasEvidenceInfo.ForDetail` +`<common:AtlasEvidenceBadgeStrip>`. 新的小寫唯讀輔助方法`SpiraDataAtlasCatalog.TryGetSphereGridNode(layout, nodeIndex)` (鏡子`TryGetMonsterDetail`) 進行映射`SourceKind` (原始/標準/專家 →`OSG`/`SSG`/`ESG`) + 節點索引至`atlas:sphere-grid-node:{layout}:{index}` — id idên

若與目錄中的設定一致，則節點即可解決；在任何任務中，該條帶都會**隱藏**（無假徽章）。**交叉連結的真實性（此規則由 Halyson 強化）：**在所要求的 4 個模組中，僅有 Sphere Grid 具備穩定的交叉連結。`Treasure` (`sourceKey` 不透明、不可逆（buki_get 索引），)`Shop` (地圖集的關鍵是「銀行+插槽」，而`item_operand_hex` 對參數傳入空值；若依操作數進行映射則會發生類別錯誤）以及`Mix` （Atlas 中不存在 Mix 的 detail kind）**這些是刻意省略的** —— 若在此處強行添加徽章，將違反「若無穩定交叉連結 → 隱藏」的防護規則。 無 writer、無 SIN、無 runtime、未觸及徽章引擎。建置結果：0 個錯誤 / 361 個警告；`--spiraatlas-rt0` PASS（2493 個球網節點）以及`--aicmdmeta-rt0` PASS。經對抗性分析人員驗證：0 個缺陷。[先前：`v2.60.0`] — Jarvis-MAGIC
- **🏷️`v2.60.0` — Atlas 證據標章（唯讀、可重複使用），應用於 Monster AI Editor。** 第一層的`HANDOFF_ATLAS_READONLY_MODULE_BADGES`：一個可重複使用的證據徽章元件，能以條目形式顯示資料的來源及其可信度範圍——無需撰稿人、無需申請、無需社會保險號碼。新功能`Modules/Common/AtlasEvidenceBadgeStrip.axaml(.cs)` (具備屬性的 UserControl 即插即用元件`Evidence`) +`Modules/Common/AtlasEvidenceBadge.cs` (`AtlasEvidenceBadge` 依嚴重程度分色 +`AtlasEvidenceInfo` 包含徽章／來源／「出現位置」、工廠`ForBibleEntry`/`ForDetail`). **關鍵決策（經對抗式審查後）：** 僅有一具引擎——該`AiBibleEvidence` 已設定參數為`Derive(...)` 而這部漫畫透過……重新利用了正統設定中的徽章`entry.EvidenceBadges`，因此 Monster AI 的內嵌漫畫條與 BIBLE 的全螢幕視窗 **絕不會出現差異**；`IDA` 結構標章仍保持獨立，且**絕不會**翻轉`proved` 綠色（已在審查中發現並修正錯誤）。已新增該代幣`partial` 任務中要求的。所謂的「在遊戲中出現的位置」變成`AiBibleWhereAppears` （BIBLE 與模組之間的單一 DRY 來源）。應用於 BIBLE 的內嵌面板中`Monster AI Editor`：為選取的條目新增「徽章 + 來源 + 展開『顯示位置』」功能；**📖 開啟完整指南** 按鈕（原有功能）將開啟對應的 BIBLE。無需修改執行時、SIN、儲存路徑或提供程式

r`SpiraDataAtlasCatalog`. 編譯 0 個錯誤 / 361 個警告；`--spiraatlas-rt0` 以及`--aicmdmeta-rt0` PASS；`AiScriptLab --ai2` PASS（驗證器無誤 346/346）。[上一則：`v2.59.0`] — Jarvis-MAGIC
- **📚`v2.59.0` — BIBLE OF SPIRA / Atlas UI 2.0：多標籤證據導覽 + 篩選器 + 來源面板（唯讀）。** 該視窗`BIBLE OF SPIRA` 新增了一個基於實證的、內容嚴謹的健康導覽專區，且未增聘任何新撰稿人。`AiBibleEntry` 現在從 Atlas 載入結構化來源資料（`SourcePath`,`WriterPolicy`,`DetailKind`) 以及一個唯一的權益代幣來源（`AiBibleEvidence`) 僅源自現有欄位——絕不自行編造證據。每個條目都會顯示 **多項徽章** (`blocked`,`RT2`,`IDA`,`proved`,`RT0`,`parser-corpus`,`presence-index`,`metadata-only`,`semantic-candidate`,`RT2-pending`,`read-only`) 根據嚴重程度以不同顏色標示，並附有能保持真實性的工具提示 (`RT0` = Atlas 解析/目錄的完整性，而非執行時權威性；`parser-corpus` 結構/存在性證據，非效果證據）。新的**證據**篩選器（`Todas`,`Proved/RT0`,`Parser corpus`,`Metadata-only`,`Blocked`,`RT2 pending`) 與「類型／領域」及「搜尋」功能以級聯方式結合，並顯示計數結果。源自《Atlas》的條目會顯示**Atlas：來源與方針**面板，其中包含`Domain`,`DetailKind`,`WriterPolicy` 以及`SourcePath` （未匯出原始 CSV 檔案）。**「遊戲中出現的位置」**已按領域重新撰寫，並採用直白的措辭（`monster-presence` = 指「形成／時段」的存在，而非行為；`sin-eligibility` = 排隊，未獲授權；`gear-name-model` = 行號`w_name.bin`，非最終獎勵名稱；`blitzball-prize` = 僅元資料；Sphere`Unknown6` = 原始值／未知）。搜尋功能現已支援`metadata-only`/`blocked`/`RT2-pending`/`domain:*` 透過代幣在`SearchBlob`. 暫時性建置：0 個錯誤 / 361 個警告；`--spiraatlas-rt0` 以及`--aicmdmeta-rt0` PASS (`979/867/112`). 無需修改執行階段、SIN 寫入器或提供者`SpiraDataAtlasCatalog`：僅限閱讀／使用者體驗。[上一則：`v2.58.0`] — Jarvis-MAGIC
- **🛰`v2.58.0` — 編輯器中的 Aurora Overlay Lab：持久性設定用於`ffx-hooks.dll`.** 新增模組`Live Tools -> Aurora Overlay Lab` 用來控制 Runtim 覆蓋層

以及由`modules\config\aurora_overlay.ini`，並同步舊的標記（`aurora_overlay.flag`,`aurora_overlay_d3d11.flag`,`aurora_w2s_sniff.flag`) 並提供 GDI/D3D11 模式、W2S 掃描、D3D 嗅探、預算/冷卻時間、刷新率等控制鈕，以及`Auto-pause hits`. 該 DLL 讀取`.ini` 在開機時，將環境變數設為覆寫；`d3d_sniff_autopause_hits=3` 趁 D3D 備用陣列還處於新鮮狀態時，暫停對常量緩衝區的深度檢查。該面板將遊戲根節點正規化／`FFX.exe`/`modules`, 顯示 DLL/config/log，開啟`%TEMP%\ffx-hooks.log`，透過 Steam 推出 appid`359870`, 當`FFX.exe` vivo 位於另一個根目錄下，並在寫入設定時防止 I/O 錯誤。先前執行時測試：FFX vivo 中的 D3D11 幀內標籤；本輪測試已驗證編輯器建置版本`0 Erro(s)` /`361 Aviso(s)` 並部署 DLL。[上一頁：`v2.57.0`] — Jarvis-Codex
- **⚔`v2.57.0` — 自訂頭目生成器：適用於 Drop1/Steal/Bribe 的「進階戰利品」輕量版。** 屬性面板新增了 **「進階戰利品」** 卡片，其中包含可選的覆寫設定，用於`Drop1` 常見／罕見，`Steal` 常見／罕見，以及`Bribe`: 項目編號、數量及原始機率（如有）。若欄位為空或無效，則繼承自`Loot usado`；**預覽／差異比較** 會透過以下方式解析名稱：`Item_Dictionary` 並顯示出諸如以下等變化：`Potion x1 → Dark Matter x2`，並列出所繼承的無效欄位。複製器現在會套用`LootFile` 複製／繼承的整數，而且，更重要的是，`Gil/AP` + Drop1/Steal/Bribe light；`.bossrecipe.json` 在填寫完畢後儲存這些覆寫設定。老實說：`Drop2`, 《Overkill》的掉落物以及裝備／技能池仍保留在怪物編輯器中／下個版本將移除。建構編輯器 0 個錯誤／361 個警告。[先前：`v2.56.0`] — Jarvis-Codex
- **🧠`v2.56.0` — Monster AI 編輯器：field/stat 植入器 + 三位一體/BIBLE 的最終潤飾。**標題 **Monster AI 三位一體** 已居中對齊，使其成為流程中的真正亮點`AEON observa · BIBLE ensina · SIN cria`. Workbench 在微調區新增了 **Plantar field/stat** 選項卡：搜尋任何`btlActorProperty` 從`AiChrPropertyNames`, 選擇十進位數或`0xNN`，並儲存於`onTurn` 使用正確方式進行實機備份`PUSHII <field> · PUSHII <value> · CALLPOPA 70AB` (`setStatField(field,value)`，不含 `actorRef`

`, sem confundir com `writeChrProperty`). O default prioriza `OverdriveMax`, `過流保護`, `showOverdriveBar` e reações de hit, exatamente para casos tipo Dark Shiva/overdrive. A BIBLE inline recebeu cores de seleção/detalhe mais coesas com Spira/FFX e deixou de parecer um bloco de terminal colado. Build editor 0 erros / 361 warnings. [anterior: `v2.55.4`] — Jarvis-Codex
- **⚔`v2.55.4` — 自訂頭目創建器：`Loot usado` 成為明確的選項。** 左側欄新增了 **「已使用戰利品」** 卡片，其模式為`Herdar loot da base` 或`Copiar loot de outro m###`，自訂篩選器、資料來源清單及包含 Gil/AP、drop/steal/bribe 以及 raw 機率的技術摘要。當變更戰利品來源時，這些欄位`Gil`,`AP` 以及`AP Overkill` 會隨所選區塊一併顯示，且仍可手動覆寫。`Criar Monstro` 現在可以複製該`LootFile` 完整保留往返流程，並在該基礎上重新套用簡單的獎勵；`.bossrecipe.json` 記錄`LootSource` (`inherit-base-loot`/`copy-monster-loot`) 並將此選擇進行匯入／匯出往返處理。**預覽／差異比較** 現已顯示最終 AI、最終戰利品，並將獎勵與實際戰利品進行比較。角色建構編輯器：0 個錯誤／361 個警告。[先前：`v2.55.3`] — Jarvis-Codex
- **⚔`v2.55.3` — 自訂頭目生成器：頭目預設值，讓您無需在黑暗中手動輸入屬性數值。** 該分頁在屬性欄上方新增了 **頭目預設值** 區塊，內含五項操作：`Dark Lite`,`Tanque`,`Canhão`,`Veloz` 以及`Herdar tudo`. 預設會讀取`m###` 以基礎值為基準，並將 HP/MP/Overkill/屬性/ModelId 以及 Gil/AP/AP Overkill 填入帶有上限限制的倍率中，始終從基礎值開始計算，以避免產生連鎖乘法；`Herdar tudo` 清除數值覆寫設定，以簡化配方。點擊預設值時不會儲存任何設定：**預覽／差異** 卡片會在執行前顯示結果`Criar Monstro`. 建置編輯器 0 個錯誤 / 361 個警告。[上一頁：`v2.55.2`] — Jarvis-Codex
- **⚔`v2.55.2` — 自訂頭目創建器：建立頭目前的預覽／差異比較。** 該分頁在屬性面板中新增了 **預覽／差異比較** 卡片，當變更基礎設定、目標、名稱、AI 來源、屬性或獎勵時，該卡片會即時更新。預覽功能會將最終結果與`m###` 基礎與展示`base → novo` 僅限搬家使用

HP/MP/Overkill/屬性/ModelId/Gil/AP/AP Overkill 的實際數值；若輸入的欄位無效，在寫入前會顯示為「繼承」。同時也會摘要目標`m### → m###`，最終 AI（繼承或複製其他怪物的完整設定檔），並會在目標 ID 已存在時發出提示。無需新增寫入器：這是真實的讀取／預覽功能，旨在減少盲目建立的情況。建構編輯器：0 個錯誤／361 個警告。[先前：`v2.55.1`] — Jarvis-Codex
- **🧠`v2.55.1` — Monster AI Editor：AEON/BIBLE/SIN 三合一模組，頂端附有快速 SIN 功能。** 螢幕現在會將三合一模組視覺上區隔開來：**AEON** 變成了一條緊湊的基礎版 diff/restore 區塊，**BIBLE OF SPIRA** 則保留為 ATEL 唯讀手冊，位於摘要旁`O que este monstro faz`，而 **SIN / Spira Instinct Network** 則以「一鍵快速預設」面板的形式登場。Workbench 轉變為下方用於微調的介面（當前 AI 清單 + 新增／變更行為），技能選擇器則新增了分類`Todas` 將 Character/monmagic1/monmagic2 合併後，動作按鈕增加了對比度與圖示，而 DevKit 則在末端變成了一個單一的黑色技術展開欄。自訂狀態預設值現已包含 Shell、Regen 以及 NulBlaze/NulTide/NulShock/NulFrost，使用`writeChrProperty` 以及該的欄位`AiChrPropertyNames`; 沒有新的並行寫入器。建置編輯器：0 個錯誤 / 361 個警告。[先前：`v2.55.0`] — Jarvis-Codex
- **⚔`v2.55.0` — 自訂頭目創建器：UI 中新增頭目配方匯入／匯出／雙向同步功能。** 左側欄新增了 **配方** 卡片，並附有按鈕`Importar` 以及`Exportar` 至`.bossrecipe.json`. 「匯出」會儲存當前草稿的食譜，而不會建立`m###.bin`; 匯入 schema 並進行驗證`ffx.bossrecipe.v1`/版本 1 並重新套用基礎怪物、目標 ID、名稱、AI 模式／來源、屬性及基本獎勵 (`RewardGil`,`RewardAp`,`RewardApOverkill`) 至螢幕上的欄位中。若目標已存在，匯入功能會於狀態欄中顯示提示，並讓使用者在點擊`Criar Monstro`. 老實說：配方屬於元資料／離線編輯器；實體化頭目仍需透過「創建」按鈕，而佈局／RT2 則仍需透過「陣型編輯器」、「戰鬥沙盒」及遊戲內功能進行。建構編輯器 0 個錯誤／361 個警告。[先前：`v2.54.0`] — Jarvis-Codex
- **⚔`v2.54.0` — 《Battle Sandbox v2》：最多可對戰 8 名敵人，

 按地點規劃路線及鏡頭佈局規劃器。**「Battle Sandbox」** 標籤頁在`LiveBattleLab` 不再是垂直的 A/B/C 布局，而是改為一種緊湊的佈局，包含 8 個敵人槽位，每個槽位皆具備生命值與快速 AI。路線現在可從已確定的清單中選擇，該清單包含`btl.bin` (`map/battleId/field/group/formation`) 或手動編輯；**準備航線** 按鈕會儲存 8 個編隊槽位及位置`MonsterLive` 從`btl_*` 已解決，並已備份`.sandbox.btl.bak`，重新利用`BattleArenaAuthor`,`Battle_File.WriteWithFormationSlots()` 以及`BattleArenaPositionWriter`. 這款計畫本提供跨頁（`2 linhas compactas`（開放、首領+小怪、走廊、圓圈）並計算出能將所有怪物納入畫面的鏡頭建議；鏡頭的自動寫入功能仍維持「誠實／保存」模式，適用於 Aurora／RT2。`Force Battle` 仍要求連接 DINPUT8 探針。建置解決方案：0 個錯誤 / 361 個警告；本地螢幕截圖位於`work/screenshots/battle-sandbox-tab.png`. [上一頁：`v2.53.0`] — Jarvis-MAGIC
- **⚔`v2.53.0` — 自訂頭目創建器：在創建流程中新增「簡單獎勵」AP/吉爾選項。** 該分頁現已新增 **「簡單獎勵」** 區塊供編輯`Gil`,`AP` 以及`AP Overkill` 從`LootFile` 複製後；空值／無效的欄位將繼承自基礎怪物。複製器會保留原始的戰利品區段，並僅在這些欄位被填入時重新標記，以維持掉落物／竊取／裝備等設定供「怪物編輯器」使用。配方`.bossrecipe.json` 記錄`RewardGil`,`RewardAp` 以及`RewardApOverkill` 在使用時以及`ProofStatus` 開始引用這些覆寫。建置編輯器顯示此工作樹中有 0 個錯誤 / 361 個警告。[先前：`v2.52.0`] — Jarvis-Codex
- **⚔`v2.52.0` — 自訂頭目創建器：首款側車`.bossrecipe.json` 針對已建立的克隆體。** 在建立自訂頭目時，該模組現在會記錄`m###.bossrecipe.json` 位於與`m###.bin`，其 v1 資料結構包含 UTC 時間、來源怪物、目標怪物、名稱、AI 來源（`inherit-base-ai` 或`copy-monster-ai`)，stats/ModelId/名稱的覆寫，以及測試的真實狀態。sidecar 並不會徹底改變遊戲規則，但它使開發過程具有可重複性，並為未來奠定了第一塊基石`Boss Recipe` 可匯出／可匯入。建置編輯器 0 個錯誤／357 個警告（基準值）。[先前版本：`v2.

51.0`] — Jarvis-Codex
- **⚔`v2.51.0` — 自訂頭目創建器：`IA usada` 透過 AI Source picker 成為明確的選擇。** 該分頁`Custom Boss Creator` 不再將 AI 隱藏為隱含的遺產：現在有一張標有 **已使用 AI** 且具備模式的卡牌`Herdar IA da base` 或`Copiar IA de outro m###`, 專用濾波器、來源清單及技術摘要 (`AiFile`, 工作程序、指令、結構驗證）。在建立 boss 時，克隆體可以接收該`AiFile` 另一隻怪物的完整資料，在寫入前已由 ATEL 編解碼器／驗證器驗證過；屬性、名稱和 ModelId 仍保留在現有資料流中。 原本作為無作用欄位的「基礎怪物篩選器」，現在已能真正發揮篩選功能。誠實度：複製完整的 AI 設定檔；將工作人員／片段、戰利品／獎勵與關卡混合處理，將於後續版本中實現。建構編輯器基準值：0 個錯誤／357 個警告。[先前：`v2.50.1`] — Jarvis-Codex
- **🧠`v2.50.1` — Monster AI Editor：SPIRA 聖經 + SIN 工作台已納入主分支。** 畫面顯示`Monster AI Editor` 已根據兩個獨立的概念進行重組：**BIBLE OF SPIRA** 作為唯讀參考資料，並與`O que este monstro faz`，以及 **SIN / Spira Instinct Network** 作為兩欄式的作者名單。該清單`IA atual do monstro` 變得更高，並具備獨立捲動功能；右側面板則集中顯示所選技能、初始增益效果、快速預設以及`SIN Templates` 緊湊型車款。`Live Battle Target` 已上傳至剛編輯完的檔案附近，而「Workers/操作數/匯編語言/結構模型」已被推送到該區塊中`DevKit`. 「快速預設」現已提供 10 項實際操作，透過重新利用現有的基本元素（`Haste`,`Protect`,`Reflect`,`Defensivo`,`Agressivo`,`Enrage`,`Revezar 1/2`,`Revezar 1/3`,`Repetir cast`,`Combo 2 hits`)，且未建立平行寫入器。建置編輯器：0 個錯誤／357 個警告（基準值）。[先前：`v2.50.0`] — Jarvis-Codex
- **🎚`v2.50.0` — 難度控制模組 v2：離線模式下的「遭遇危險」與「挑戰」模式。** 此模組`Modules/DifficultyDirector` 不再僅僅是……的尺度`m###.bin`: 現在也能讀取／預覽／寫入該`Danger` 來自該群組的`btl.bin` 來源`EncounterTable_File.Write()` 附備份`.difficulty.bak`, 切換以與怪物一同套用，並預覽 5 個主要群組

受影響的項目。擴展預設：`Exploração` (危險等級 0) 以及`Caçador` （最高難度）。離線挑戰模式：`True Nightmare`,`Speed Run Assist`,`Explorer`,`Hunter` 以及`Equalizer` （根據載入的數據集平均值，將 HP/MP/屬性值進行標準化）。誠實度：`One-Hit`,`No-Overdrives`, adaptive/live scaling 和 probe 目前仍未納入此版本，需等到 IDA/runtime 階段；也就是說，writer 處於離線狀態。已嘗試建置；但因 中的既有 XAML 錯誤而受阻`MonsterAiEditor_Control.axaml` （其他通道的點擊處理程序），並非由本模組處理。[上一頁：`v2.49.0`] — Jarvis-Codex
- **⚔`v2.49.0` — Live Battle Lab 中的 Battle Sandbox：組建 A/B/C 套件，快速套用 HP/IA，並透過探測器觸發 Force Battle。** 新增 **Battle Sandbox** 分頁，位於`LiveBattleLab`: 怪物篩選器`m###`, 每個插槽可調整的生命值，AI 快速預設 (`Original`,`Agressivo`,`Defensivo`,`Enrage`) 以及用於套用包含備份的套件的按鈕`.sandbox.bak`. **強制戰鬥** 按鈕會重新使用這些欄位`field/group/formation` 以及現有的 DINPUT8/主執行緒橋接路徑；畫面明確顯示，該陣容的實際組成仍來自`btl_*` 已儲存至工作區/Formation Editor。Build 編輯器無錯誤。[上一頁：`v2.48.0`] — Jarvis-MAGIC
- **🎚`v2.48.0` — 難度總監：專為專案中所有怪物設計的 HP/MP/屬性全局滑桿。** 新增模組`Modules/DifficultyDirector` 在 Core Authoring 應用程式中，使用預設值`Fácil/Normal/Difícil/Dark Aeon`、用於 HP、MP、力量、魔法、防禦／魔法防禦及其他屬性的全局滑桿、高影響力預覽，以及透過……進行離線撰寫`Monster_File.Write()`. 每個`m###.bin` 接收備份`.difficulty.bak` 在首次寫入之前，UI 提供還原這些備份的功能。遊戲會在下次載入怪物時偵測到此變更；即時縮放功能仍不在範圍內。建構編輯器 0 個錯誤。[先前：`v2.47.1`] — Jarvis-MAGIC
- **📚`v2.47.1` — Monster AI Editor：AI 行為庫可疊加於現有預設值／自動化設定之上。** 新增 **「行為庫」** 卡片於`Monster AI Editor` 附搜尋功能與視覺化範本（`Counter-Attack`,`Cura quando HP baixo`,`Revezar habilidades`,`Enrage HP baixo`,`Buff defensivo`,`Multi-cast`). 此實作採用了現有的自動化流程與程式碼片段

卵形（`AiAutomation`,`AiSnippetLibrary`，防禦型預設、選取「⚔」動作作為範本），無需另行建立平行寫入器。HP% 條件式仍如實標記為經離線驗證的結構，RT2 遊戲內行為則需透過探針確認。建構編輯器無錯誤。[先前：`v2.47.0`] — Jarvis-MAGIC
- **📖`v2.47.0` — Monster AI Editor：BIBLE OF SPIRA，模組內建的 ATEL 情境式唯讀聖經。** 新增`FfxLib/Ai/AiBibleCatalog.cs` 建立功能條目與欄位的結構`btlActorProperty`、目標、操作碼、模式與防護措施，並使用實際的字典（`AiChrPropertyNames`,`AiTargetNames`,`AiScript_File.CallName/Mnemonic`). 該`Monster AI Editor` 透過搜尋獲得了**《SPIRA聖經》**卡片`70AB`/`Overdrive`/`PUSHII`/`Shiva` 以及簽名細節、堆疊形狀、證據與風險等資訊。現在選取 AI Assembler 中的任一行，系統便會自動調出對應的條目（例如：`CALLPOPA 70AB` →`setStatField`). 該任務文件在標題中已更名為《SPIRA聖經》，並由`setStatField/getStatField` 標準化：`setStatField(field,value)` 未收到`actorRef`; 明示的演員位於`writeChrProperty(actor,field,value)`. **沒有新的寫入器、沒有 Shiva 按鈕、沒有新的位元組** — 只有上下文／防護欄。建置編輯器 0 個錯誤；`AiScriptLab --names` PASS。[上一頁：`v2.46.1`] — Jarvis-MAGIC
- **🧠`v2.46.1` — AI 匯編器：「可讀」欄位 — 匯編器的每一行都顯示`MNEMÔNICO  gloss` 而不是單純使用原色唇彩。**`AiAsmRow.ReadableText` 搭配`AiScript_File.Mnemonic(opcode)` +`OperandGloss(opcode, operand)` 整合成一個易於閱讀的字串：`PUSHII  0xFF03  (alvo: Self)`,`CALLPOPA  Battle.performCommand`,`JMP  → jump[3]`,`ADD` （無操作數）。該欄位的`ListBox` 來自 AI Assembler（先前僅顯示光澤效果，例如：`0xFF03  (alvo: Self)`) 現在顯示完整文字；opcode 工具提示 (`OpcodeHelp`) 在懸停時保持顯示。`OnPropertyChanged(nameof(ReadableText))` 在 opcode 和 operand 的設定器中觸發，因此編輯時欄位會即時更新。RT0 不受影響（僅為檢視）。無檔案`AiOpcodeNames.cs` 已建立 —`Mnemonic()` 已經存在，且屬公開資訊。[上一則：`v2.46.0`] — Jarvis-MAGIC
- **🔍`v2.46.0` —

AEON（Assembly Evolution Observation Node）：透過綠色／紅色／黃色標示，比較修改版與原版 AI。** 新增`FfxLib/Ai/AiScript_Diff.cs` 比較兩者`AiScriptFile` 由`(worker, offset)` 並進行分類`Unchanged/Modified/Added/Removed`. 該`Monster AI Editor` 獲得了 **Diff vs Vanilla** 公開卡牌：載入透過`Path_FfxPs2Root`，顯示差異處：綠色代表新增、紅色代表刪除、黃色代表修改；當檔案大小發生變化時會發出提示，且基於偏移量的差異比對結果較為近似；並提供「還原原始版本」功能，只需點擊兩下即可確認還原 +`.prev.bak`. 缺少 Vanilla 反而變成了一則誠實的訊息，且不會當機。新閘門`AiScriptLab --diff` 密碼：`m000` 相同 = 0 個差異；`m001` 記憶體中已修改的操作數 = 1 項修改，0 項新增/移除。建置編輯器 0 個錯誤。[先前：`v2.45.0`] — Jarvis-MAGIC
- **🎵`v2.45.0` — 編輯器內建完整音樂播放器：目錄中的 89 首曲目皆可在使用者介面上進行選取。**`AudioStudio_Service` 現在顯示即時預覽 (`SetTrack`/`PreviewSelectedMusicTrack`) 並維持`SelectedTrackId` 在偏好設定中；主視窗新增了一個按鈕`▶ Preview`, 寬版下拉式選單及 **Music Player** 卡片，顯示當前曲目、狀態、音樂／音效切換開關，以及曲庫計數器。使用`Assets/Audio/Music/music_catalog.json` +`Catalog/*.wav` （89 首曲目）且目前仍僅限於 EDITOR 的播放器功能——並未承諾支援遊戲內音樂切換，此功能仍取決於 hook/IDA。Build 編輯器無錯誤。[前一版：`v2.44.0`] — Jarvis-MAGIC
- **⚔`v2.44.0` — 自訂頭目生成器：複製 + 編輯任何怪物 → 新的 m###.bin 檔案（自訂怪物流程的第一步）。** 新增模組`Modules/CustomBossCreator` +`FfxLib/Monster/MonsterCloner.cs`. 流程：選擇一個基礎怪物（m000–m346 或任何現有的 m###），設定新 ID（系統會自動建議 347+ 作為第一個可用槽位），個別編輯屬性（HP/MP/HpOverkill/力量/防禦/魔法/魔法防禦/敏捷/運氣/閃避/精準度）以及 ModelId 逐一編輯（欄位留空即繼承自基礎怪物），輸入顯示名稱，點擊 **⚔ 建立怪物**。該`MonsterCloner.Clone()` 執行 Write→Read 的往返操作以進行獨立複製，並在該處套用僅槽位覆寫（統計資料）或完整重建（名稱）`Monster_StatSheet`, es

相信`battle/mon/_m###/m###.bin` （自動建立資料夾）並將名稱記錄在`Monster_Dictionary` 在執行階段——「陣型編輯器」已能根據正確名稱識別新怪物。AI、戰利品及遊戲內名稱皆繼承自基礎設定（之後可透過「怪物 AI 編輯器」／「怪物編輯器」進行調整）。 誠實度：克隆會建立檔案；將怪物投入戰鬥的流程仍透過陣型編輯器進行（在現有的 .btl 檔案中交換插槽）。離線閘道：Monster_File 寫入器已通過驗證（往返字節完全一致）。[先前：`v2.43.1`] — Jarvis-MAGIC
- **🪝`v2.43.1` — ffx-hooks.dll 第 0 階段：C++ 引擎掛鉤層骨架（PolyHook2，x86） — DLL 可在遊戲中載入且不會當機，共用記憶體已就緒，掛鉤代碼已註解完畢，等待 IDA 分析。** 新的 C++ DLL`RuntimeTools/FfxHooksDll/` 與……並存`ffx-probe.dll` 現有（並非取代）：模組載入器（`dinput8.dll`) 同時載入兩者`modules\` 自動地。第 0 階段：`dllmain.cpp` 骨架 — 載入時，等待 2 秒（使用執行緒 + Sleep，切勿直接在 DllMain 中掛鉤），取得`FFX.exe`, 建立共用記憶體區塊`Local\FFXHooksBlock_v1` (256 位元組：magic/version,`musicOverrideTrackIndex`,`musicSeq`,`elementFlagsExt`)，並儲存至`%TEMP%\ffx-hooks.log`. **此階段尚未安裝任何實際的鉤子** — 閘門：遊戲正常開啟 + 日誌顯示為`[ffx-hooks] Fase 0 skeleton loaded`. 帶註解的存根：`hooks/MusicHook.cpp` (thiscall`FFX_FmodMusic_PlayTrackByIndex`, 第一階段 — 待定`RVA_FMOD_PLAY_TRACK` （經由 IDA），`hooks/ElementHook.cpp` （Earth/Wind/Dark 元素的內嵌掛鉤標誌位 0x20/0x40/0x80，第 2 階段）。VS2022 專案`FfxHooksDll.vcxproj` （僅限 Win32 — 遊戲為 x86 版本；vcpkg 採用 manifest 模式，並使用`polyhook2:x86-windows` +`zydis:x86-windows`). 腳本`build_hooks.ps1` 與`-Deploy` (複製到`modules\`): 簡易模式`cl.exe` 未使用 PolyHook2（第 0 階段）或`-WithPolyHook` 透過 MSBuild+vcpkg（第 1 階段+）。`shared/ffx_addresses.h` 將所有 RVA 集中整理為帶註解的佔位符（每個 RVA 對應一個 IDA 任務）。[前一頁：`v2.43.0`] — Jarvis-MAGIC
- **⚡`v2.43.0` — EncounterTable：儲存按鈕 + 可依群組編輯的 Danger + 全局 Danger（功能 1+4）。** O`EncounterTableExplorer` 已從純瀏覽者轉型為約會編輯者。`Encount

erTableGroupRow` e `EncounterTableFormationRow` agora são `可觀察物件` parciais: `危險` (por grupo, 0–255) e `重量` (por formação, 0–255) são editáveis via slider interativo; editar o `危險` reflete em `group.Danger` imediatamente (e atualiza o label `無遭遇／罕見／普通／高／最高`); editar `重量` recalcula automaticamente `group.TotalWeight`. Presets por grupo: botões `無匹配 (0) / 普通 (50) / 強 (128) / 最高 (255)`. **Salvar:** botão `💾 儲存 btl.bin` chama `EncounterTable_File.Write()` (slot-only, byte-local), cria `btl.bin.bak` na 1ª vez; `↩ 還原原版` copia o `.bak` de volta. **Danger Global:** 4 botões de preset (`⚡ 無聚會 / 一般 / 強烈 / 最高`) no card "Editar e Salvar" aplicam o valor a TODOS os grupos de TODOS os mapas de uma vez, com feedback de quantos grupos foram afetados. O `DataModel` mantém `_loadedEncounterFile` e `_encounterFilePath` para reutilizar o mesmo objeto lido sem re-parse. Build editor 0 erros. [anterior: `v2.42.0`] — Jarvis-MAGIC
- **🎥`v2.42.0` — AURORA：相機視角已在 IDA 中 100% 校準，並在 MapViewer 中拖曳了金色標記。** 任務簡報已完成`HANDOFF_CAMERA_POLAR_CALIBRATION_CODEX_2026-06-07`：處理程序`camSetPolar(0x6004)` 是透過 IDA 鑲嵌的（`0x6004 -> 0x7B9260 -> 0x7BB550 -> 0x7C4760`, 相機插槽`+12`) 例如`horizontalDeg, elevationDeg, distance`, 公式`x=refX+cos(h)*cos(e)*dist`,`y=refY+sin(e)*dist`,`z=refZ+sin(h)*cos(e)*dist`. 奧羅拉的金色標記不再顯示為「約」：`BuildCameraMarker` 使用實際公式，而「Place」模式現在允許拖曳 **金色眼睛**；編輯器會進行反向計算`horizontal/elevation/distância` 並透過以下方式儲存這 3 個浮點數：`WithFloat` (字節級本地化、僅備份一次)，同時保留共享池的警告。Gate`BattleCameraScanLab`:`camSetPolar0x6004=10944`, 獨立的目標感知變體`103854`，建立極坐標的 exato`809/855`, 可直接編輯`802/855`, **Polar Eye Round-Trip 802/802**。`camSetBtlPolar*`/`camSetChrPolar2` 這些內容確實與簡單的逆運算不同。編輯器未發現任何錯誤。[上一則：`v2.41.0`] — Jarvis-Codex/AURORA
- **🎥`v2.41.0` — AURORA：直接在 MapViewer 中拖曳鏡頭（參照/look-at）。** 針對「如何

「我該如何透過 MapViewer 移動相機？」：在 **Place mode** 下，**青色球體（ref = look-at）** 現在可以像怪物一樣拖曳了——在場景地面上拖曳，放開，並 **💾 儲存位置** 會將新位置記錄下來`refSetPos(x,y,z)` 在 chunk0 中（**字節級本地、精確**、僅備份一次）——與同一存檔中的怪物拖曳效果結合（不同區域）。Reader 揭示了該參考的浮點數池索引（`Establishing.RefX/Y/Zindex`);`ApplyCameraRefDragToDisk` 透過……發文`BattleCameraSetup_File.WithFloat`;`aurora-overlay.js` 將氰色球標記為拖曳目標 (`role=camera_ref`) 拒絕過橋`/drag`. **金色視窗（角度／距離）目前仍無法拖曳** — 請等待 IDA 中極座標系統的校準（即將完成）；暫時請透過面板上的旋鈕進行編輯。（順帶一提：我已修復了`BattleCameraScanLab` 因新的符號而斷裂的`Ai*Names` 來自另一條車道——解鎖`offline_ci`.) 編輯器 0 個錯誤，閘機通過 (float 855/855)。[上一則：`v2.40.1`] — Jarvis-AURORA
- **🪄`v2.40.1` — AI Assembler：「嘗試修復」按鈕（第 3 級，誠實自動修復）。** 關閉編輯器：在「驗證／儲存」旁設有 **🪄 嘗試修復** 按鈕。 **誠實的規則（來自擁有者本人）：** 僅在存在 **唯一正確答案** 時才進行修正；其餘情況僅提供建議，絕不亂猜。在 Assembler 模型中（該模型源自`HasOperand` （僅針對該操作碼）唯一明確的解決方案是 **恢復一條你標記為要移除、但同時是跳轉/進入點目標的指令** —— 它必須保留（重新設定跳轉目標會改變行為 = 出錯）。 該按鈕會循環重新驗證，撤銷對這些孤立目標的移除（解決案例 1「移除了某個內容導致系統崩潰」），對於沒有唯一解決方案的錯誤（無效操作碼、跳轉索引超出範圍、第 1 層堆疊為空） **報告中說明了該如何處理，但並未實際處理** ——「我不對你的意圖妄加揣測」。報告中會列出已修復的數量，以及尚待你決策的數量。`MonsterAiEditor_DataModel.Assembler.TryAutoFixAssembler` (使用`AiValidator` 已通過門閘測試；從不修改操作數／操作碼，也不會移除任何內容）。編譯器無錯誤；`--ai2`/`--ai3` PASS（RT0 位元組完全相同 — 僅還原 VM 的移除標誌，不變更位元組）。**老實說：** 根據使用者意圖進行自動修正 = 隱性錯誤，因此保留該按鈕

有目的的崇拜者。[上一則：`v2.40.0`] — Jarvis-MAGIC
- **🩹`v2.40.0` — AI Assembler：堆疊檢查器（第 1+2 級）— 當編輯操作導致堆疊清空時會發出警告，並提供修正方法。** 開發者要求一個能協助修正匯編錯誤的「迷你 AI 檢查器」。 驗證器原本就能偵測到無效指令碼／孤立跳轉／索引越界，但**無法偵測到手動編輯的第 1 號錯誤：堆疊不平衡**。現在已經可以偵測到了。**RE-grounded (FFXDataParser)：** 新增`FfxLib/Ai/AiStackModel.cs` = 按指令碼（opcode）劃分的堆疊效應（來自`OPCODE_STACKPOPS`) + **269 個函數的稀疏性**（輸入數為`ScriptFuncLib`; accessor = subject?+index+value?). 該`AiValidator` 模擬堆疊深度（在入口點／跳轉目標處重設為 0），並回報下溢錯誤。**關鍵洞見：** 解析器的元數與實際虛擬機並不完全吻合（已證實：`setSelfFloating 0x7029` 解析器顯示 2，語料庫則顯示 1) ——因此，與其採用絕對計數（這在有效程式碼中會產生錯誤），我改為比較 **原始版與編輯版** 的堆疊： 兩種情況下都存在元數雜訊，且會相互抵消，最終只剩下「您」的編輯所導致的錯誤。 該訊息（第 2 級）以葡萄牙語說明了哪裡發生了洩漏，以及 **如何修復**（「將原本作為參數的 PUSH 還原；每個語句都會先推入參數，然後才進行呼叫」）。自動跳轉至驗證面板。Gate`--ai2`: **validator clean 346/346**（語料庫中無誤報）+ **stack-break caught 1/1**（證明在移除一個 arg-push 時能偵測到）；`--ai3` PASS；RT0 位元組相同（僅分析，零位元組）。建構編輯器 0 個錯誤。**誠實：**能偵測編輯所引入的變更；部分函式的精細元數 = 公開 RE（透過語料庫校準 = 未來）。[前一項：`v2.39.2`] — Jarvis-MAGIC
- **🏷️`v2.39.2` — 專案名稱燃盡圖：原始標籤掃描器 + Monster AI 上的第一個安全別名。** 已啟動全儲存庫範圍的燃盡計畫`campo 0xNN`,`stat 0xNN`,`comando 0xNN`,`raw`,`Unknown`/`Unk` 以及通用 ID，無需進行盲目重命名。新工具`RuntimeTools/NameAuditLab` 清單`.cs`/`.axaml`/`.md`/`.ps1`, 分開`EditorUi`,`CoreDisplay`,`CoreInternal`,`LabTool`,`Documentation` 以及`Other`，且僅標記該子集`review now`; 當前結果：**2445 項檢驗結果、497 項編輯／顯示、11 項待審核**，附實驗室／

docs/offsets 根據設計保留原始十六進位數值。已套用第一個安全的別名：Monster AI 自動化清單現在顯示`writeChrProperty StatusDurationHaste (0x0038)` /`setStatField stat_round (0x00DA)` 當……時`AiChrPropertyNames` 關閉 ID；未知用戶繼續`campo 0xNNNN`. 文件：`docs/ai/MISSION_PROJECT_WIDE_NAME_BURN_DOWN_2026-06-07.md`,`docs/reverse/FFX_PROJECT_NAME_BURN_DOWN_SCAN_2026-06-07.md`；AI 位元組未變更。[先前：`v2.39.1`] — Jarvis-Codex
- **🏷️`v2.39.1` — Monster AI：利用公開解析器對 NOMES 進行審計（0 個未標註名稱的呼叫 ID；不確定的欄位將顯示為十六進位數）。** 簡報執行`docs/ai/MISSION_NAME_AUDIT_WITH_PARSERS_2026-06-07.md` 採用「一致性優先於名稱」的規則：`ScriptFuncLib` +`ScriptConstants` + 語料庫來源`AiScriptLab --names`，且未變更任何位元組。已新增詞典`AiMotionPropertyNames`,`AiMovePropertyNames` 以及`AiSaveDataVariableNames`；現在的分解是按函數對場空間進行解析（`btlActorProperty` 至`700F/7018/70AA/70AB`,`motionProperty` 至`70AC/70B2`,`moveProperty` 至`701A/7078`) 以及`saveData` 若存在，則顯示「parser-backed」名稱。已修正`0x701A` 至`readMoveProperty` 並加入那些仍以十六進位數表示的已使用呼叫識別碼（`7009`,`7029`,`7032`,`7050`,`7078`,`70A8`). 閘門`--names`: **已使用 160 個呼叫識別碼，0 個未命名；命名空間中有 285 個欄位；5 個字面值以十六進位形式保留** (`0x0156`,`0x0157`,`0xFFFB`,`0xFFEF`,`0xFFDF`) 因缺乏 parser/corpus/IDA 的關閉。`--ai2`/`--ai3` PASS；編輯器 0 個錯誤。Doc`docs/reverse/FFX_AI_NAME_AUDIT_WITH_PARSERS_2026-06-07.md`. [上一頁：`v2.39.0`] — Jarvis-Codex
- **🎥`v2.39.0` — AURORA：MapViewer 中的 3D 相機標記（可在場景渲染圖中查看相機的位置／視線方向）。**「我如何視覺化」的第 2 點：Aurora 的 3D 渲染現在會繪製 **設定相機** — **金色**球體 = 視點（相機位置），**青色**球體 = 參考點（相機精確的取景點），**視點→參考點的線段** + 地面上的支撐點。根據 chunk0 計算得出：`refSetPos(x,y,z)` （沒錯，正是該場景的同一幀畫面＝身分已證實）＋`camSetPolar(ângulo,distância)` →`olho = ref + polar`. 閱讀器`BattleCameraSetup_File.Establishing` (第 1 個 refPos + 第 1 個極性；閘極：**

編號 855/855，Polar 846/855**)，型號`AuroraCameraMarker` 在疊加層中，渲染至`aurora-overlay.js` （與錨點同組，繼承 Y-up 翻轉）。 **坦白說：** 參考點是精確的；**視點是近似值** — 極座標系統（其中「arg」代表角度與距離、仰角）目前**尚未經位元確認**， 因此標記標示為「相機（近似）」，而仰角僅為目測估算；請透過螢幕（以及探針／遊戲內）確認／調整。編輯器 0 錯誤。文件`docs/reverse/FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07.md`. [上一頁：`v2.38.1`] — Jarvis-AURORA
- **📊`v2.38.1` — Monster AI Editor：命名過的 STAT 動作（「stat 0xNN」結尾） —`setStatField` 使用的是同一張資料表。** 玩家在螢幕上指出，這些 📊 數據仍以原始格式顯示（「數據 0xDA = 8」）。**發現（透過 FFXDataParser ScriptFuncLib 交叉比對）：**`setStatField`(0x70AB)/`getStatField`(0x70AA) 使用 **相同的 indexType`btlActorProperty`** 哪個`readChrProperty`(0x700F)/`writeChrProperty`(0x7018) — 也就是說，這是完全相同的欄位表，我原先關於「以空格分隔」的假設是錯誤的。為什麼它們會以原始格式顯示：例如這類 ID：`0xDA/0xDB/0xE6` 有`name=null` 在解析器中（僅`internalName`:`stat_round`/`stat_round_return`/`stat_attack_inc_speed`)，以及第一代的`AiChrPropertyNames` 只擷取了名稱友善的項目。**修正：**我重新生成字典，當沒有英文名稱時，會將 **遊戲內的內部符號作為備用選項** 納入其中（222 → **341 個欄位**），並將其整合至偵測器的 stat 分支中。 現在「stat 0xDA = 8」會變成 **「stat_round = 8」**。`FfxLib/Ai/AiChrPropertyNames.cs` +`AiAutomation` (分支 Stat 透過`StatusFieldName`). 閘門`--ai3` PASS（偵測到 4156 項統計數據；RT0 位元組完全相同 — 僅顯示）；編輯器 0 個錯誤。**老實說：**英文名稱是 RE-pública；那些`internalName` 是 **遊戲的真實符號**（類型「未知」＝細微語義未完全對應，但該符號真實可靠，且優於十六進位表示法）。[上一頁：`v2.38.0`] — Jarvis-MAGIC
- **🎥`v2.38.0` — AURORA：在控制面板中編輯戰鬥相機的實際參數（角度 · 距離 · 位置 · 滾轉）。** 針對「那我該如何檢視／編輯這些設定？」的回應：🎥 相機卡片新增了 **「🎚 相機參數（可編輯）」**。 **RE（透過 IDA 分析 + 交叉比對`FFXDataParser`, d 的貼士

ono)：** 戰鬥鏡頭是在 chunk0 中透過腳本計算生成的 — 呼叫 Camera 命名空間 (`camSetPolar(ângulo,distância)`,`refSetPos(x,y,z)`,`camSetRoll`,`camSetScrDpt`) 將參數作為池中的 **FLOAT 常數** 使用。新的讀取器`FfxLib/BattleMap/BattleCameraSetup_File.cs` 擷取所有呼叫 + 解決浮點數問題 + 處理可編輯的**各獨立控制鈕**；`WithFloat` 編譯 **byte-local** 浮點數池（相同大小，重複使用`AiScript_File.EditFloatConst`)，同時保留其餘的區塊。控制面板列出了**按類型分組**（極坐標/參考位置/滾動/螢幕深度）的旋鈕，並具備**篩選 + 搜尋**功能（相機是一個電影級腳本，每場戰鬥約有 730 個鏡頭， 因此需透過群組/搜尋瀏覽，而非直接瀏覽原始清單），每個參數皆可編輯；「💾 儲存攝影機參數」會套用已修改的浮點數值（單次備份 + 重新載入）。Gate`BattleCameraScanLab` 擴展：**855 個帶攝影機的bin，623,981 次呼叫，浮點數往返編輯 855/855**（位元組本地化 + 可逆）。 **誠實說明：**編輯一個浮點數會改變所有共用該數值的切片；自訂角度屬於「檔案內」處理（推翻了先前「= 場景製作」的結論）；遊戲內效果 = RT2。文件`docs/reverse/FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07.md` §6. 編譯無錯誤。[前一項：`v2.37.3`] — Jarvis-AURORA
- **🎨`v2.37.3` — SPHERE GRID CANVAS：我們透過縮放功能進行縮放，並採用簡潔的向量圖示（先前圖集的裁切方式有誤）。** 開發者於 v2.37.1 版本的回饋：Explorer 的圖集（`icon_atlas.png`) **裁切細胞的方式有誤**（Lv1-4 以及許多其他醜陋的細胞），而且節點 **在縮放時會縮小**（固定螢幕大小 → 消失在空間中）。兩項修正：**(1) 半徑會隨縮放比例調整** —`CurrentNodeRadius = clamp(26×scale, 5..42px)`，因此放大 = 較大的圖示（可辨識的圖示），縮小 = 較小的圖示（概覽）；圖示與文字會同步縮放。 **(2) 向量圖示** — 我又改用 **game-icons.net (CC BY)** 的圖形了（`SphereGridIcons.cs`, SVG 路徑 →`Geometry.Parse`) 能在任何縮放比例下 **保持清晰，不會被裁切**（已排除位圖圖集）：鎖定 = 簡潔的 **"L{n}"** 徽章（nv1-4 再也不會被裁切）， 帶圖示的屬性（HP/MP/力量/防禦/魔法/敏捷/運氣/技能），其餘則為縮放後的文字徽章（ACC/EVA/MDF/WHT/BLK/SPL/SKL）。 保留按類別區分的彩色光球 + 光暈/懸停效果/標籤/反光

i-VAIDARMERDA/音效。編譯成功，無錯誤；採用 CC-BY 授權`SPHERE_GRID_ICON_CREDITS.txt`. [上一頁：`v2.37.2`] — Jarvis-MAGIC
- **🎯`v2.37.2` — Monster AI Editor：#8 真正的指定目標（自身／敵人／盟友／角色#N…）— 解析器解鎖了哨兵。** 根據「查看解析器」的提示：該`FFXDataParser/ScriptConstants.putEnum("btlActor")` 這正是 IDA 尚未交出的「哨兵目標」地圖（ATEL 解析器超時了）。 現已命名且**與語料庫一致**：**-13/0xFFF3 = Self**（已證實）、**-14/0xFFF2 = FrontlineChars**（怪物的「敵人」＝角色； 這是最常見的字面哨兵，出現 272 次），**-6/-7/-8 = 角色 #1/#2/#3**，**-15/0xFFF1 = AllMonsters**（怪物的「盟友」 ——與「白風」→治癒怪物相符），**-17 = 最後攻擊者**，**-5 = 所有角色**，**-3 = 目標角色**，**-20 = 所有永恆者**，`0x10NN = MonsterType`…（敵人／盟友是從怪物視角來看）。因此，**🎯 變更目標**（v2.33.0）不再是「例如複製」，而是變成了一個**命名目標模式的下拉選單**——這正是開發者在 #8 從一開始就希望實現的「單一／所有敵人／所有盟友」選項； 動作清單顯示「目標：FrontlineChars」；而 **反匯編／操作數編輯器** 將哨兵（0xFFE9–0xFFFF，無歧義範圍）標示為「（目標：Self/…）」。新增`FfxLib/Ai/AiTargetNames.cs` (btlActor，與編解碼器的函式／屬性映射來自同一公開來源)；在下拉選單中啟用 +`AiScript_File.OperandGloss`. 閘門`--ai2`/`--ai3` PASS（RT0 位元組完全一致且完整 — 僅有標註，零位元組未變更）；建置編輯器 0 個錯誤。 **誠實：** 已通過 Self 位元組驗證；其餘名稱來自公開的反編譯結果，且與語料庫一致（精細語義 = RT2）。[前文：`v2.37.1`] — Jarvis-MAGIC
- **🩸`v2.37.0` — Monster AI Editor：條件「若 HP 低於 X%」已驗證（IDA+語料庫）＋ 222 個已命名屬性欄位（「0xNN 欄位」結尾）。** Halyson 指示使用 IDA，並推測「這應該是個設定檔，其中每行代表一個數字」——**兩者皆正確**。RE 在`FFX_recon.i64`: 原生調度程式 ATEL =`handler = *(FuncspaceTables[funcId>>12] + 16*(funcId&0xFFF))` (slot +0 CALLPOPA / +12 CALL);`readChrProperty` (0x700F) =`0x7A4D70` → switch `field→屬性

以及` (`sub_7B2DD0`). Cruzei com o **FFXDataParser/ScriptConstants.putBattleActorProperty** (a "config" que o dono intuiu) + o corpus: **field 0x00 = HP** (stat_hp, a propriedade MAIS lida do corpus — 306×), **0x02 = maxHP** (137×), **0x119 = NearDeath** (= IDA case 281 `current<max/2`). Opcodes aritméticos provados (`* 0x16` etc.). **#11 REAL shipado:** snippet guardado **"Se HP abaixo de X% → forçar comando"** = idioma `HP*100 < maxHP*X` (fields 0/2 corpus-provados) — o enrage de chefe de verdade, não mais um chute (a versão anterior v2.35.0 era genérica porque o field de HP não estava provado; agora está). **Nomeação:** novo `FfxLib/Ai/AiChrPropertyNames.cs` (222 fields nomeados, mesma proveniência pública do mapa de funções do codec) ligado no detector de buff/stat → as ações de status agora aparecem "Haste/Protect/StatusPoison/HP/maxHP…" em vez de "campo 0xNN". Gate `--ai2`: **HP%-enrage 346/346** + conditional 346/346; `--ai3` PASS. Docs: `docs/reverse/FFX_AI_NATIVE_DISPATCH_AND_CHRPROPERTY_FIELDMAP_2026-06-07.md` (+ rename-queue pro `.i64`). **Honesto:** estrutura provada offline, efeito in-game = RT2; o gauge 0xDA/218=HP%×256 existe no IDA mas o corpus não usa (usei o caminho que a IA usa de verdade, 0/2). Build do editor red por WIP da lane Sphere Grid (alheio); meus arquivos são todos FfxLib, gate-validados. [anterior: `v2.36.0.1`] — Jarvis-MAGIC
- **🎥 AURORA — 戰鬥鏡頭表（IDA，僅文檔）的修訂說明：「shot」指代相機節點，並非位置／視野（FOV）。** 針對「能否實現 100% 自訂視角？」的回答：**無法透過浮點數表格實現。** 已解碼並重新命名的字串位於`FFX_recon.i64`:`camReq`→`FFX_Battle_Camera_RequestShot`→`CmdQueue_Push`→`BindQueuedShots`→`ShotTable_Dispatch`(@0x7985A0)→`ShotTable_Walk`(@0x797420)。該`shotIndex` 索引一個 BLOB（`[1]`=count,`[2+shot]`=選擇器、u16 偏移量表 → **節點 ID** 子表， 0xFFFF=無）並解析為一個 **相機節點**（在場景／特效中烘焙的動畫路徑）——位置／視野（FOV）來自 **追蹤該節點**，記錄中沒有浮點數。來源 = 從檔案載入的容器（`+4`=ATEL 腳本，`+8`=表格)：透過`FFX_MagicFile_LoadDllByMagicId` (`magic_NNNN.dll`); 透過 `g_CameraShotC` 進行戰鬥

hannels[8]` (kind2/id1) + `actor+0xF7C` (kind3). **Implicação:** trocar entre os ângulos existentes = operando SHOT do camReq (já no painel, v2.36.0); **ângulo custom = authoring de nó/animação de câmera na cena Phyre / effect DLL** (scene-authoring, encosta na lane MAP), NÃO um writer no per-battle bin. 13 renames + 2 comentários de layout salvos no `.i64`. Doc: `docs/reverse/FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07.md`。*(RE/IDA = 僅文件，不會更新 csproj.)* — Jarvis-AURORA
- **✨`v2.37.1` — SPHERE GRID CANVAS：真實視覺效果（透過編輯器圖集呈現的《FFX》真實圖示）＋清晰可辨的節點＋即時反VAIDARMERDA功能＋色彩／標籤／光暈／懸停效果／音效。** 業主要求「讓它看起來漂亮 + 自動提示」，並指出 v1 版本只是個沒有圖示的微小圓點。**關鍵發現：**編輯器原本就已具備 Explorer 的精美渲染器（`SphereGridPreview_Control` +`Assets/SphereGrid/icon_atlas.png`) — 於是 **我偷用了真正的圖集**（捨棄了之前放上的 game-icons.net）。現在來看看 Canvas：**(1) FFX 的正版圖示** — 彩色光球 + 角色貼圖`icon_atlas.png` 由`AppearanceType` (STR/DEF/MAG/HP/MP/白色/黑色/特殊/技能/鎖定) 或文字徽章（AGI/ACC/EVA/LCK…），與《Explorer》相同，透過`SphereGridNodeVisualInfo` 組裝自`panel.bin` （相同的邏輯`CreatePreviewVisual`/`BuildShortLabel`). **(2) 可讀性節點** — 圓球 ~12px（原先為 5.5）+ 預設縮放會以可讀等級開啟（不再將 828 個節點擠在一起）+ LOD（概覽圖中的小點）+ 視口剔除。 **(3) 即時反垃圾驗證** — 拖曳少於 40 個節點或點擊連結 → 節點變為 **紅色** + 即時顯示橫幅（無需點擊「Validate」；僅對被修改的節點/幀進行簡易檢查）。 **(4)** 依類別區分顏色 + 面板上的 **標籤**，選中項顯示 **脈動光暈**（DispatcherTimer），**懸停**時亮起，**聲音**透過`AudioStudio_Service` （內含 FFX UI SFX；因專案屬私有而釋出 — 經所有者修正）。**不含影像 AI** — 這是遊戲中原本就內建於編輯器中的真實貼圖。Build 0 無錯誤；編輯器可正常啟動且不會當機。[先前版本：`v2.37.0`] — Jarvis-MAGIC
- **🎥`v2.36.0` — AURORA：Aurora Chamber 內的「攝影機」面板（編輯剪輯片段`camReq` 戰鬥畫面：角度／鏡頭 + 目標）。** 經測試的鏡頭讀取器／鏡頭閘門（僅限文件：chun

k0 是一款 AiFile ATEL，型號為 RT0 863/863，`camReq` 100% 可編輯（位元組級），現在來看使用者介面：**「🎥 相機」** 卡片列出了剪輯片段`camReq` (`0x703F`) 選取的戰鬥片段，其中 **SHOT**（鏡頭角度，以 1 為起點）和 **TARGET**（畫面中的角色，-1 表示無）可編輯； **💾 儲存鏡頭** 會套用 **same-length byte-local** 操作數的修補檔（保留其他區塊的偏移量），執行一次備份，並重新載入。透過`FfxLib/BattleMap/BattleCameraScript_File` （與 AI 相同的編解碼器）。檔案：`Modules/AuroraChamber/{AuroraChamber_DataModel.cs (CameraShots/PopulateCameraRows/SaveCameraShots), _Control.axaml (card + lista editável), _Control.axaml.cs}` (程式碼已位於`c211a5f2`). 編譯 0 個錯誤（編輯器已開啟 =`.exe` 卡住；（在獨立輸出中進行編譯可確認）。**誠實地說：**在腳本已參考的角度／目標之間切換；100% 自訂角度（新位置／視野）= 鏡頭表中的 RE`sub_797D60` （待定，IDA）。遊戲內效果 = RT2（字節安全且可逆的邏輯門）`BattleCameraScanLab`). [上一頁：`v2.35.0`] — Jarvis-AURORA
- **🎭`v2.35.0` — Monster AI Editor：行為預設值（#10）＋已驗證的「低於 N」條件（#11）＋已記錄的邊界條件 #12/#13。** 誠實地完成「全都做」待辦清單中能完成的部分。 **#10 — 🎭 一鍵預設**（包含已驗證的自動化功能、戰鬥工作者自動選取 + 成長效果已驗證）：**🛡 防禦型**（Protect+Haste 本身），**⚔ 進攻型**（始終強制使用選取器中選定的技能），**🔥 狂暴**（選定技能 + 加速效果本身），**🎲 輪替**（每兩次選定一次）。 **#11 — 「低於 N」條件：** 已將新程式碼片段儲存至行為庫（Behavior Library）`Se propriedade do chr (self) ABAIXO de N → forçar comando` = 語料庫中**#1**的條件語言（`readChrProperty` 0x700F 驅動 **980 個分支**；比較`LT 0x0B` （經人口普查證實），其中`field`+`limiar`+`comando` 由使用者提供 — **注意：** HP 的精確 field-id 並非經過 byte 驗證（請使用經過驗證的狀態 0x38/0x31/0x32； HP = RE 邊界），因此它是通用的，並非一個會隨機觸發的「HP%」按鈕。 **#12（回合 N）** 和 **#13（實機測試）** = **文件中標示為邊界**（沒有原生的回合取得器——這是按怪物計算的私有變數計數器，且 1-in-K 的 RNG 代理已

 shipa；live 僅支援「保留長度」的編輯，且「擴充」等同於重新載入遊戲）——見 v2.33.0 版說明文件。邏輯：`AiSnippetLibrary` (片段`guard-chrprop-lt-force-cmd`) + DataModel 中的預設值 (`ApplyPreset*`，由……組成`AddAbility`/`AddSelfBuff`). 閘門`--ai2`: **條件式程式碼片段 346/346**（展開、擴展跳轉表、重新解析、驗證）；`--ai3` PASS。Build 0 錯誤。**誠實：** 離線驗證結構；readChrProperty 的效果與元數 = RT2。[先前：`v2.34.0`] — Jarvis-MAGIC
- **🩺`v2.34.0` — Battle Tracker：正常運作（可讀取即時戰鬥資料）— 自動初始讀取、狀態顯示準確 + RT2 寫入鎖定。** Battle Tracker 開啟時 **畫面為空**（兩個空白面板，「Load Ingame」處於靜止狀態）。 原因**並非出在位址上** — 已在運行中的 RAM 中驗證（FFX.exe PID 24716，戰鬥`azit03_01`) 表示整個字串是正確的：`ADDR_BATTLE_ACTIVE`(rva`0xD2A8E0`)=1,`ENEMY_LIST`/`PLAYER_LIST`(rva`0xD34460`/`0xD334CC`) 解決，stride`0xF90`, 偏移量`MemoryChr` (`Id`@0xE,`Max_hp`@0x594,`Hp`@0x5D0,`In_battle`@0xDC8) 擊中，編隊槽位`[0,4,6]` == 擁有`In_battle=1`. 後端（`Binarysharp.MSharp` x64 讀取 FFX x86）同樣可行 —`new MemorySharp` +`Read<byte>(rva, isRelative:true)` 返回正確的值。**原因在於使用者體驗（UX）：**該`DataModel` **從未觸發第一次讀數**（該`ArenaTracker` 在建構函式中讀取；Battle Tracker 則不會），且計時器僅在開啟「自動刷新」時才會讀取。**修正：** (1) 在建構函式中進行初始讀取； (2) 計時器在每個 tick 都維持 **真實狀態**，並在 **戰鬥開始時自動填入第一張照片**（無需勾選「自動刷新」），且在離開戰鬥時清空；(3)`ReadInfo` 使用 try/catch 處理錯誤，並包含守護條件（指針為 0 / 空字節 / 槽位超出範圍）；(4)`MemSharp_Service.IsAvailable()` 在「attach +」中不再會發生崩潰`IsAttached`; (5) 使用者介面新增了 **狀態橫幅**（「未找到 FFX」／「已附著，未戰鬥」／「戰鬥中：敵人名稱 · N 名敵人，M 名盟友”) 以及 **RT2 寫入鎖定**（核取方塊，預設 **關閉 = 唯讀**），並透過重新命名的「⚠ 寫入遊戲」按鈕進行控制。新驗證工具：`RuntimeTools/BattleTrackerProbe` （使用相同的 DLL 測試即時讀取路徑）。檔案：`Modules/BattleTracke

r/{BattleTracker_DataModel.cs, BattleTracker_Control.axaml}`, `Services/MemSharp_Service.cs`, `RuntimeTools/BattleTrackerProbe/*`, doc `docs/reverse/FFX_BATTLE_TRACKER_LIVE_READ_PROVEN_2026-06-07.md`. Build do módulo OK (validado em worktree HEAD limpo; o build cheio do editor está quebrado por WIP `AiTargetOption` de outra lane, alheio a esta mudança). **Honesto:** READ provado na tela/RAM; a **escrita** (Load Ingame → `WriteProcessMemory`) segue RT2 (jogo aberto + trava ligada). [anterior: `v2.33.0`] — Jarvis-MAGIC
- **🎯`v2.33.0` — Monster AI Editor：變更目標（#8）＋多目標攻擊／第二項技能（#9），基於語料庫挖掘。** 清單中再有兩項，是先使用 **RE/語料庫 完成的，沒有憑空猜測**。新的掃描器在`AiScriptLab` (`--targets`,`--cond`) 挖掘了 **1645 個命令站點** 和 **10520 個分支**（文件`docs/reverse/FFX_AI_TARGET_ENCODING_AND_CONDITION_GETTERS_2026-06-07.md`). **#8 — 🎯 變更目標：** 目標是 command-id 之前的 push 指令； **54% 為運算結果（PUSHV findMatchingChr）**，**46% 為字面哨兵值（PUSHII）** — 僅這些可替換為 1 個操作數（長度不變，即 RT2 已驗證的編輯方式）。 坦白說：只有 **self (-13/0xFFF3)** 是經過位元組驗證的；其餘的負哨兵值皆為目標模式，其確切含義屬於 RE 的邊界。 因此編輯器提供 **「自身」＋「複製此怪物其他動作的目標」**（一個在遊戲中對其已可正常運作的哨兵），卻未明確說明其語義。 **#9 — ⧉+ 多重發送：**將選取器中選定的技能插入至所選動作之後，並複製目標與模式（西摩風格的連續兩項動作；透過「重建」擴充）。純粹的邏輯`AiAutomation.{ChangeTargetInstructions,InsertSecondCommand}` +`AiDetectedAction` 贏得了`TargetPushOffset/TargetOperand/TargetIsLiteral`. 閘門`--ai3`: **變更目標 195/195**（757 個字面目標），**插入第二條指令 294/294**； 其餘所有項目（add/rng/detect/remove buff-stat/reorder/change/duplicate/toggle/self-buff/copy）均通過；`--ai2` PASS。Build 0 無錯誤。**誠實：**離線環境已驗證結構；遊戲內效果 = RT2（多重發射：確認兩者是否在同一回合解決）。將每個哨兵映射至→模式 + 每回合 HP% = 邊界（參閱文件）。[先前：`v2.32.0`] — Jarvis-MAGIC


- **🎥 AURORA — 經實戰驗證且可在 chunk0 中編輯的戰鬥攝影機 (`camReq`): 針對 863 場戰鬥進行掃描 + 閘門處理（僅限文件，未更新 csproj）。** 恢復任務（相機面板）已重新啟動。 **關鍵發現：** 戰鬥相機並不在 chunk3 中（`+0x2C` 是恆定的）——它是**腳本驅動**的，而**每個戰鬥二進位檔的 TODO chunk0 是一個純粹的 AiFile ATEL 檔案**，其中包含怪物 AI 的編解碼器（`AiScript_File`) 重新傳送 **字節完全相同的 863/863 (RT0)** — 在編解碼器從未見過的語料庫中進行了新的測試 (`declared@+0x10 == len(chunk0)`). 每道切法都是一種`camReq` (func-id`0x703F`) 該函式會彈出 2 個立即數：**SHOT**（角度，以 1 為起點；引擎使用 shot-1）和 **TARGET**（畫面中的角色，`0xFFFF`=無）。**深植於 IDA 中的語義**（`FFX_Atel_Battle_camReq @0x7A5E10` →`FFX_Battle_Camera_RequestShot @0x797BD0`): 第 1 個 pop = 緊接其前的 push = TARGET (`v3`); 第2個音符 = SHOT (`v4`); **更正先前的記載** — 該`0xFFFF` 是呼叫中硬編碼的常數 CONSTANTE，而非操作數。語料庫：**646 個二進位區間 / 3736 次呼叫，100% 的操作數是`PUSHII` 即時 → 100% 可編輯的位元組級**；SHOT 幾乎總是 1（→ 索引 0），TARGET 因情況而異（以 28 為主）。全新的純邏輯`FfxLib/BattleMap/BattleCameraScript_File.cs` (提取 chunk0 → 解碼 → 清單`camReq` 來源為 shot/target + 編輯 byte-local same-length，並保留其他區塊的偏移量）+ gate **`BattleCameraScanLab`**（在`offline_ci.ps1`): **walk 關閉 863/863 · RT0 863/863 · 編輯射擊+目標往返 646/646**（字節級本地化 + 可逆）。額外發現：戰鬥腳本使用`0x5F=POPF2`/`0x6D=PUSHF2` （有效，未列入怪物名錄）。重新命名／評論已儲存於`FFX_recon.i64`. 文件：`docs/reverse/FFX_BATTLE_CAMERA_CAMREQ_CORPUS_PROVEN_2026-06-07.md`. **合理限制：**這允許**在腳本已引用的鏡頭／目標之間切換**；100% 自訂的角度（位置／視野）則需要從鏡頭表中重新讀取（`sub_797D60`) — IDA 待處理。**接下來：** 位於此閱讀器上方的 Aurora Chamber 中的「相機」面板。*(測試/RE/實驗室 = 僅限文件，請勿更新 csproj.)* — Jarvis-AURORA
- **🟢`v2.32.0` — Monster AI Editor：列出所有動作（⚔ 指令 · 🛡 增益/狀態 · 📊 屬性），並可依類型篩選 + 重新命名指令

無名氏的 (#6 和 #7)。** 來自擁有者清單的兩項請求。 **#6 — 列出所有內容，而不僅是指令：** 「怪物行動」現在也能偵測並編輯 **增益效果／狀態（`writeChrProperty 0x7018`)** 以及 **統計數據 (`setStatField 0x70AB`)**，附有 **按類型篩選的下拉選單**（全部 / ⚔ 指令 / 🛡 增益效果 / 📊 屬性）。 每項動作皆顯示圖示 + 友善名稱（已知狀態 = "加速/防護/反射"，否則為 "0xNN 欄位"；當目標為自我反射時顯示 "（本身）"；當數值為 0 時顯示 "= 數值" 或 "移除"）。 **移動／複製／移除** 現已適用於任何類型（運行中的通用、不影響疊加數值的移除）`[pushes…][call]`); **切換／強制↔佇列** 僅適用於 **指令**（儲存 + 警告）。 **#7 — 重新命名無名稱的指令：** 當一個 ID 的`performCommand` 字典中沒有該詞條（例如：`comando 0x60AB`)，此時會出現一個名為 **✏ 重新命名** 的欄位，用以設定一個 **會被永久儲存** 的友善名稱（`%LocalAppData%\FFXProjectEditor\ai-command-labels.json`) 並在整個編輯器中適用於任何怪物。全新的純邏輯：`FfxLib/Ai/AiAutomation.DetectActions` (command+buff+stat;`DetectCommandActions` （已切換為篩選檢視） +`FfxLib/Ai/AiCommandLabels.cs` （在啟動時載入的儲存區，每次編輯後都會儲存；在閘口處為空 ⇒ 無效）。閘口`--ai3` 擴展：**偵測增益/屬性 = 4020 個增益（3698 個可移除）+ 4156 項屬性（4156）**， **移除增益/屬性 30/30**（通用移除機制會根據確切執行結果進行縮減並重新解析），**重新排序 325/325**（現在會處理任何類型的鄰接效果）； add/rng/change/duplicate/toggle/self-buff/copy 仍維持 PASS；`--ai2` PASS。Build 0 無錯誤。**誠實：** 離線驗證過結構；遊戲內效果 = RT2。僅有 3 個經位元組驗證的狀態欄位 ID 會被命名（其餘 = "欄位 0xNN"，誠實）。[先前：`v2.31.1`] — Jarvis-MAGIC
- **🧩`v2.31.1` — SPHERE GRID CANVAS：創作套件（防斷裂驗證、視覺效果、水印、連結管理器＋多選功能）。** 業主要求的四項功能，均經引擎偵測校準（鄰近節點／交叉連結會導致結構崩壞）：**(1) 防崩壞驗證** — 除了字節安全外，現在還會針對 **鄰近性**（2 個節點 < 40 單位，已證實會斷裂）及 **連結交叉**（基礎測量值 = 0，因此任何情況皆屬實際風險；段落交集測試）發出警示

以及非相鄰連結）與 **連通性**（資訊：無連結的元件／節點數量 — 說明：標準版 Expert 預設包含 25 個元件，因此此處為資訊，非錯誤）。 **(2) 視覺呈現** — **參考晶格**（在步驟 43 進行縮放時出現的小點）、**突出顯示**所選節點的連結與鄰居，以及畫布上的**類型名稱**（讀作`panel.bin`；始終選取，並透過「名稱」切換鈕 + 縮放功能填滿所有欄位）。**(3) 印章** — 按鈕 **◇ 菱形**（4 個節點 + 4 個連結）和 **— 線段**（3 個節點），可黏貼 **已間距調整（≥2×43）且相互連接** 的形狀 = 結構上符合引擎安全規範；點擊畫布即可定位。 **(4) 連結管理器 + 多重選取** — 節點面板列出其連結，附有 **✕ 移除** 按鈕及「連結至節點 #」方框； 並 **Shift+拖曳** = 選取框 → **按 Delete 鍵移除群組**（按降序執行 RemoveNode 以避免索引混亂）。關於庫中經過驗證的變體功能，Build 0 無錯誤；編輯器可順利運行且不會當機。 **坦白說：** 鄰近性／交叉警告是**經過量測**的啟發式結果（並非引擎的精確上限）；連通性僅供參考。[上一頁：`v2.31.0`] — Jarvis-MAGIC
- **🟢`v2.31.0` — 怪物 AI 編輯器：複製其他怪物的 AI · 還原原始 AI。** 清單中的另外兩項： **📋 複製 AI** — 從任何其他怪物（下拉選單中列出 294 隻具備腳本的怪物）擷取完整的 AiFile，並貼上至此處， **同時保留其屬性與掉落物**（僅 AiFile 的區域會變更，包含成長感知型拼接與驗證）；這是讓怪物快速取得另一隻已符合你期望行為的怪物的行為模式的捷徑。 **♻️ 還原原始 AI** — 從 **已萃取的參考** 中重新複製該怪物的原版 AI（`<ffx_ps2>\ffx\master\jppc\battle\mon\_mNNN\mNNN.bin`, 例如：`D:\FFX Extracted`) — 會撤銷任何 AI 編輯（即使是舊的會話，這與`.prev.bak` （第 1 級）。兩者皆保存`.prev.bak` 之前。雷烏薩`SaveNewAi` (ValidateRebuilt + grow-splice + backup + reload)。閘道`--ai3`: **copy ai 346/346**（將 AiFile 拼接至怪物 → 切回原位 → 重新解析，指令數量相同）；其餘所有操作（add/rng/detect/remove/reorder/change/duplicate/toggle/buff）均通過測試。 Build 0 錯誤。**老實說：**結構已離線驗證；遊戲內效果 = RT2。（還原需要 root 權限 ffx_ps）

已設定第 2 個參考值。）[上一頁：`v2.30.0`] — Jarvis-MAGIC
- **🟢`v2.30.0` — Monster AI Editor：更多一鍵操作（複製 · 強制↔排程 · 自身增益 · 撤銷）。** 繼續列出所需功能：**⧉ 複製（施放 2 次）** — 將選取的動作複製並緊接在該動作之後（透過重複進行多次施放；成長 + 重新解析）； **⚡ 強制↔排隊** — 在以下選項之間切換召喚：`forcePerformCommand` (force) 以及`performCommand` (佇列)，1 個保持長度的運算數；**🛡 為自己施放增益效果**（透過 加速／防護／反射）`writeChrProperty`, 使用相同的「當」——總是／有時；戰鬥工作者的自動選擇、已儲存的成長）；**↶ 撤銷（備份）** ——現在每次儲存都會記錄一個`.prev.bak` 覆寫前（一級撤銷）。新邏輯在`FfxLib/Ai/AiAutomation.cs` (`DuplicateActionInstructions`/`ToggleForceInstructions`/`AddSelfBuff` + 增益預設）；集中儲存於`WriteMonsterWithBackup`/`SaveNewAi`. 閘門`--ai3` 擴展：**複製 294/294**、**切換 294/294**、**自我增益 346/346**（新增/隨機數/偵測/移除/重新排序/變更均通過）。 Build 0 錯誤。 **說明：** 所有內容均已離線驗證（結構／長度）；遊戲內效果 = RT2。增益效果的 Field-ids（0x38／0x31／0x32）與程式碼片段中記載的相符——待挖掘更多 ID 後將提供更多狀態資訊。[先前：`v2.29.0`] — Jarvis-MAGIC
- **🐉 AURORA — 已於遊戲內驗證的怪物新增功能 (RT2)：編輯器新增的 2 隻「黑暗永恆」在戰鬥中成功載入，可正常遊玩且未發生當機（僅文件驗證，未修改 csproj）。** MARCO：Halyson 透過陣型／競技場編輯器（Aurora Chamber ➕ / 陣型編輯器）中，並由 **FFX HD 載入該戰鬥，將額外角色以「完整角色」形式生成，且 Dark Valefor 執行了 AI 並發動了 Energy Ray**（初始回合即可遊玩，FPS 30）。 關閉 chunk3/GROW 鏈（v2.27.0/51）中「誠實：未經遊戲內驗證」的骰子路徑： **引擎接受編輯後的怪物數量，並執行額外角色** — chunk2（生成、標誌`0x1000`) + chunk3 (錨點`+0x20`) 因重生迴圈而正常運作（資料完整；若為位元組損毀則無法載入）。**然而遊戲在「能量射線」關卡中當機** = **內容不匹配，並非位元組損毀**：Dark Aeon（巨型模型 +

 全螢幕超載模式＋相機／特效（會接管其專屬競技場）在未經此用途設計的辛競技場中，會導致引擎卡死。**誠實評價：** 目前是遊戲安全的（能載入＋生成怪物＋AI正常運作）； **穩定性需配合適合該競技場的內容** — 《Dark Aeon》是情況最糟的案例（請使用普通怪物或名單中的怪物以確保戰鬥穩定）。橫幅 + 文件模型 §7 已更新。文件：`docs/reverse/FFX_AURORA_GROW_INGAME_PROVEN_2026-06-07.md`. **下一項：** 模式-1 對比 模式-2；無預留間隙的戰鬥；搭配適合競技場的怪物以確保穩定性。*(測試/RT2 = 僅文件，不會更新 csproj.)* — Jarvis-AURORA
- **🔧`v2.29.0` — 怪物 AI 編輯器：移動（上移／下移）、替換及移除動作 — 怪物現在可以從頭到尾進行編輯。** 在自動化功能（v2.24.0/49）的基礎上，「怪物動作」清單新增了 3 項操作，均為 **length-preserving**（比 add/remove 更安全）：**▲ 向上 / ▼ 向下**（透過鄰近動作重新排序 —`Rebuild` 根據指令的「識別碼」重新映射跳轉點／進入點，因此流程控制會跟隨被移動的區塊；被移動的項目會保持選取狀態，以便再次點擊）以及 **✏ 替換為上方選定的技能**（僅將選定動作指令的操作數重寫為選取器中的技能——這正是 RT2-live 中已驗證的 1 位元組 Firaga→Thundaga 案例，現在適用於任何指令，包括 MonMagic2/Multi-Fira）。 純邏輯在`FfxLib/Ai/AiAutomation.cs` (`MoveActionInstructions`/`ChangeActionInstructions` +`CmdPushOffset` 在`AiDetectedAction`); 僅提供給自包含的三元組（驗證器會屏蔽其餘內容）。Gate`--ai3` 擴展：**重新排序 237/237**（向下移動、保持長度、重新解析、指令多集不變）+ **變更 294/294**（插槽變為 Firaga、保持長度、重新解析）。 add/rng/detect/remove 均通過測試。編譯無錯誤。**誠實聲明：**結構已離線驗證；移動會改變執行順序，替換會改變指令——遊戲內效果 = RT2（屬刻意設計，此為開發者之目的）。 複雜情況（非平凡目標／某些情況會偏離動作）則交由進階 AI Assembler 處理。[前文：`v2.28.1`] — Jarvis-MAGIC
- **🧩🎮`v2.28.1` — SPHERE GRID CANVAS：編輯拓撲結構（已於遊戲中實測通過，+300 HP）+ 優化（依名稱分類節點類型、對齊功能）

實際間距、還原／備份）。** **MARCO：** Halyson **在 Canvas（v2.25.0）中編輯了 Standard grid，儲存後，FFX 載入 → 瀏覽 → 啟用了一個新增的節點 (+300 HP 施加於角色)** — 警示訊息 *「遊戲內編輯的拓撲結構 = 未經引擎驗證」* **出現在螢幕上**（從「庫驗證」→「Canvas」→「儲存」→「實際引擎」的循環，在玩家手中完整閉合）。 **同時發現引擎問題：**若節點間距過近或連結相互交叉，引擎**會破壞網格**（離線位元組安全 ≠ 引擎安全）； 原版「實際尺寸」**測量值 = 基本間距 ~43un**（平均連結長度 ~77，日期 01/02/03）。 已轉化為工具功能：**(1) 對齊至43**（放置／拖曳的節點會對齊至原生網格；預設開啟，可切換）； **(2) 鄰近警告** 出現在 Validate 中（若 2 個節點 < 40un 則觸發旗標 = 可能導致結構損壞；此為建議性提示，不會阻擋 byte-safe）； **(3) 依名稱篩選的節點類型下拉選單**（讀取`panel.bin` 來源`ReadNodeTypes` → 「力量 +1」／「生命值 +200」／「1級鎖定」……而非「hex」；節點`FFh`=若未指定類型，遊戲內會渲染為 3 級鎖頭，現在可以設定正確的類型）；**(4) ♻️ 還原原始狀態**（將從專案中提取的參考資料複製為原版網格 = 撤銷導致遊戲當機的儲存檔）+ **備份`.prev.bak`** 在每次「儲存至專案」之前會自動執行。編譯 0 錯誤；編輯器可順利載入且不會當機。已記錄記憶體／間距限制的偵測結果。 **坦白說：**拓撲編輯功能現已**在遊戲中驗證完成**（載入+啟用）； 限制（鄰近性／交叉）是經過**量測**的啟發式值，而非引擎的精確上限——需透過更多測試／RE 進行優化（連結交叉偵測功能將於未來實作）。[先前：`v2.28.0`] — Jarvis-MAGIC
- **➕`v2.28.0` — AURORA：UI 中新增「新增／移除」怪物的功能（位於 Aurora Chamber 的按鈕）。** GROW（v2.27.0）新增介面：純粹的編排器`FfxLib/BattleMap/BattleArenaAuthor.cs` 該機制使 **chunk2（陣型）+ chunk3（錨點）保持同步**，並在「奧羅拉之室」中設有 2 個按鈕（**➕ 新增怪物 / ➖ 移除怪物**，位於「儲存位置」按鈕旁）。 **雙模式機制：** 若場地有空位，則「add」會使用競技場中一個**預留的錨點**（`formação-viva < MonsterPositionCount`) = 僅填滿陣列的下一格，**僅限 chunk2，不擴充**；否則 **chunk3 會擴充**（模式 2

,`BattleArenaGrowWriter`). 這個新插槽會**複製最後一隻存活的怪物**（物種 + 標記`0x1000`); 移除會清除最後一個有效的槽位。使用 backup-once 儲存 (`.aurora.bak`) +`ReloadSelectedBattle`. 閘門`BattleArenaGrowLab` 擴展（連結至作者）：**AUTHOR 新增 694/694 + 移除 302/302** (重新解碼已清理，槽位已複製/清理，動態配置 ±1) 此外還有 RT0 700/700 + ADD 696/696 + REMOVE 393/393。 編輯器編譯 0 個錯誤（exe 當機 = 編輯器開啟；輸出暫存檔中的建置結果已確認）。文件已更新`FFX_AURORA_CHUNK3_PAYLOAD_MODEL_2026-06-07.md`. **誠實：** 位元組安全離線模式；遊戲接受新計數值 = **RT2/probe**（螢幕上的橫幅）。使用者體驗：在「編隊編輯器」中調整單位類型 + 在「地圖檢視器」中拖曳位置。 — Jarvis-AURORA
- **🐉`v2.27.0` — AURORA：chunk3 的結構性 GROW（精確到字節的怪物 ADD/REMOVE）— 「chunk3」阻塞已解除。** 對`HANDOFF_AURORA_CHUNK3_RESOLVE_2026-06-07`. 先前只能**移動**錨點（v2.12.0）；現在則可以**變更**怪物的計數。 **關於封裝模型的回覆（corpus 863，已驗證）：** area-record 會以指針為單位，將這 8 個陣列以固定順序封裝起來（`origin<party<partyB<aeon<monA<monLive<monB<camera`, 863/863)；**容量 = 下一個指標 − 指標**；**`monLive`(+0x20) 是 TIGHT** (==`MonsterPositionCount@+0x06`, 856/863) 而 **`monA`(+0x1C) 保留 ~12** 和 **`monB`(+0x24) 預留區 3..78** → 預留區可在不重新調整大小的情況下容納更大的計數。那些「神秘的空隙」其實就是預留區；`+0x30..+0x5C` = 6 個面積/相機的浮點數（非指標型）。**`BattleArenaGrowWriter.GrowMonsters`** = 在末尾進行接合插入／移除`monLive` + 僅重新加蓋`monB`(+0x24)/相機(+0x2C) + 區塊表 +`+0x06`; 單區域守衛 + 緊密 + 預留 ≥ 上限（HardActorCap=8 保守估計；資料上限=15 znkd09）。閘門 **`BattleArenaGrowLab` PASS**（在`offline_ci.ps1`): **RT0 不可編輯 700/700** 位元組完全相同，**ADD +1 696/696**，**REMOVE −1 393/393**（乾淨的重新解碼）。 不符合資格者已誠實拒絕（149 個多區域 + 6 個非緊密 + 13 個異常預留 → 可透過 MOVE 繼續編輯）。變形戰鬥→場景已協調 = **IDENTIDADE**（交接 2.3）。文件`docs/reverse/FFX_AURORA_CHUNK3_PAYLOAD_MODEL_2026-06-07.md`. 編譯 0 個錯誤。**老實說：*

* 位元組安全離線模式 (RT0) ≠ 遊戲接受新計數 — **遊戲內未經證實** (RT2/探測 + 擁有者同意；重生迴圈的精確上限 = IDA 待定)。 — Jarvis-AURORA
- **🔎`v2.26.0` — Monster AI Editor：搜尋技能 + 缺失的「Monster Commands 2」（類別 MonMagic2 =`0x6000`).** 玩家在「自動化」介面中提出兩項請求：(1) **搜尋**該技能（下拉選單中有 300 多個選項），以及 (2) 「**找不到《Monster Commands 2》的技能**」（例如 Multi-Fira 等）。 原因 (2) — **RE 的發現：** 運算元的`performCommand` 是`(category<<12)|id`，而 **高位 nibble 即是資料表選擇器**（`FfxCommon_Util.GetGameCategory`/`GameCategory_Enum`):`3`=command.bin（角色），`4`=monmagic1, **`6`=monmagic2**。O`AiCommandId` 只會映射 3 和 4 → 編輯器對 **完全無法辨識`0x6xxx`** (MonMagic2)，儘管該語料庫使用了 **291 個** 該遊戲的網站（頭目／永恆者）。 證據來源：編輯器的權威清單 + 語料庫直方圖（nibbles 3=369 / 4=985 / **6=291** / 5=0；例如：`0x60AB`=Multi-Fira #171) + Firaga 之前的 RT2。**修正：**`AiCommandId` 贏得了`Monster2 = 0x6000` (`EncodeMonster2`/`DictFor`/`IsCommandOperand`/`AllOptions`) → 現已支援 **解碼、列出、新增及移除** MonMagic2 指令；解鎖 **按指令的多重傳送**（Multi-Fira 就是這樣）。自動化選取器：3 個類別，附有直觀標籤（角色／怪物 1／ **怪物 2**）+ **搜尋框**（名稱或十六進位碼，例如：「Multi」、「60AB」），可邊篩選邊保留選取項目；進階行為庫（Behavior Library）亦新增了 Monster2。Gate`--ai2` 擴展：**mon2 rt 247/247**，**MultiFira=True**；`--ai3` 現已偵測到 **1645 項動作**（原先為 1354 → +291 = 正是先前無法偵測到的 MonMagic2），移除 278/278。文件說明：`docs/reverse/FFX_AI_PERFORMCOMMAND_CATEGORY_NIBBLE_2026-06-07.md`. 編譯 0 個錯誤，檢查點通過。[上一則：`v2.25.0`] — Jarvis-MAGIC
- **🧩`v2.25.0` — SPHERE GRID CANVAS (v2 VISUAL)：在圖上編輯 Original/Standard/Expert，並拖曳／連接節點。** 這是基於該函式庫基礎上所缺失的使用者介面（FromExisting + 變數器、閘門）`--spheregrid-edit-rt0`). 新增 nav **"Sphere Grid Canvas 🧩"**（位於 Builder v1 旁）→ **custom-drawn** 控制項（`SphereGridCanvasView`:`Render` + 腳尖

r 手動操作，而非包含 800 多個圖形的 ItemsControl —— 內建的網格約有 828 個節點／848 個連結）。**開啟** 原始／標準／專家模式（透過`ReadLayout`→`FromExisting`，專案的 abmap 或作為備用方案擷取的參考）或 **新**（從零開始）； **拖曳節點** =`MoveNode`, **滾輪** = 游標縮放, **右鍵** = 平移, **+Link** 模式下點擊 2 個節點 =`AddLink`, **+節點**模式下點擊空白處 =`AddNode`, **刪除** 移除節點 (`RemoveNode`). 所選節點的側邊面板（PosX/PosY/cluster/content →`UpdateNode`). **儲存：** 副本`.dat` (版面配置 + 內容) 非破壞性，或 **儲存至專案**（abmap 中的 dat0X/dat1X，需載入專案）。 渲染：叢集 = 淡色區域，直線／曲線連結（透過二次貝塞爾曲線錨點），實心／空心節點，選取狀態 = 金色輪廓。**v1 從頭開始的版本保持完整**（自有導航系統）。建構過程零錯誤；編輯器啟動時不會當機。 **誠實聲明：** WriteLayout 具備位元組精確性（已驗證往返 RT0 無誤），但將新建立／編輯過的拓撲結構載入遊戲中的功能仍未經驗證（螢幕上會顯示誠實聲明橫幅）——請在信賴此功能前先進行遊戲內測試。[先前：`v2.24.0`] — Jarvis-MAGIC
- **🤖`v2.24.0` — Monster AI Editor：一鍵自動化（軟體中的「AI」會自動生成字節碼）。** 業主要求為非專業使用者提供按鈕，讓編輯器能自動生成 ATEL 位元組碼 **且不造成錯誤**，並在儲存前進行驗證（該編輯器雖然非常適合編輯，但從零開始建構卻相當棘手）。 模組頂端新增 **「✨ 自動化（一鍵式）」** 選項卡，附帶 **➕ 新增技能**（透過直觀的下拉式選單選擇魔法／技能）`AiCommandId` + 「何時」：總是／有時 1-in-K → AI 會自動選擇戰鬥工作節點 + 入口點，並透過以下方式擴充跳轉表：`AppendGuardedAction`, 驗證並儲存 grow-aware）以及 **➖ 移除一項動作**（列出怪物「已經」執行的指令動作，並以解碼後的名稱顯示；移除堆疊中立的三元組`[alvo][comando][CALLPOPA]` 來源`Rebuild` + 重新連結，驗證器會阻止「dangle」情況發生）。+ 切換 **「技術模式（真實名稱）」**，將清單重新標示為助記符／原始十六進位碼（供技術控使用者使用）。 自由編輯模式（AI Assembler + Behavior Library）**維持不變**，作為進階模式。純邏輯已提取至 **`FfxLib/Ai/AiAutomation.cs`**（無編輯註，與`AiCommandId`/`

AiSnippetLibrary`) → testável e gateável. Novo gate **`AiScriptLab --ai3`** prova sobre o corpus (361 m*.bin, 346 c/ script): **add-ability 346/346** + **rng-guard 346/346** (auto-pick valida + re-parseia limpo como grow), **detect 1354 ações / 255 scripts**, **remove 241/241** (Rebuild encolhe exatamente a tríade dropada, re-parseia limpo) + **14 corretamente barradas** pelo validador (algo desvia pra ação). `--ai2` segue PASS. Build 0 erros. **Honesto:** estrutura provada OFFLINE; o **comportamento in-game de uma habilidade ADICIONADA depende de QUAL entrypoint roda por turno — NÃO é byte-provado** (só a estrutura é, 692/692), por isso o auto-pick de entrypoint é heurístico (maior-span), reportado de forma transparente e marcado **experimental/RT2** (confirmar via probe DINPUT8). Multi-cast/multi-alvo/condicionais HP%-turno seguem pendentes (corpus/âncora). [anterior: `v2.23.3`] — Jarvis-MAGIC
- **🐉`v2.23.3` — 編隊編輯器：新增至空槽位的怪物現在會繼承「在戰場上存活」的標記。** 擁有者將怪物加入槽位 04-07，但它們 **未被識別為存活**（Aurora 顯示「僅有 4 隻存活怪物」）。螢幕截圖為證：原始槽位（00-03）的原始資料為`10DEh`/`10E2h` (**高位尼布爾`0x1000`**）；新增的項目會被移除`0030h`/`0136h` (**高位尼布爾`0x0000`**). 該`0x1000` 這是陣型中「怪物」處於「活躍」狀態的標記——該寫手寫道`0` 在填補一個原本是`FFFFh`. Fix (`FormationSlotRow`): 填補空閒插槽時，**會繼承來自該戰鬥中某個「兄弟」活躍插槽的高位半字節**（每場戰鬥一次，不進行淘汰；預設值`0x1000` （若編隊為 100% 空）。仍維持「僅限插槽且位元組安全」的特性（FormationSlotLab 閘值 858/858）。**額外診斷（這並非存檔錯誤）：** 存檔與讀取使用的是同一個路徑（`GetPathBattle`); 問題在於「金額」，而非立場。**老實說：** (1)`0x1000`=「存活」是基於畫面證據的假設 — **請在遊戲中測試**； (2) 奧羅拉地圖僅包含 **由競技場（chunk3）定義的怪物錨點**（例如：4）——若要新增此範圍以外的怪物，則需建立新的競技場錨點（競技場的建立不在此修正範圍內）。 Build 0 錯誤。 [先前：`v2.23.2`]
- **🧩 Sphere Grid Builder v2（基礎功能：編輯現有網格）— 包含 lib + gate，不含

 bump csproj.** v1 (`v2.22.0`) 總是從零開始建立；所讀取的模型（`SphereGridLayoutFile` + 條目）是`init`-only（不可變），鎖定「編輯 原始／標準／專家」。在`SphereGridLayoutBuilder`: **`FromExisting(grid)`** 透過**逐欄**複製每個叢集／節點／連結來建立建構器（保留`Unused*`/`Unknown6`/`RedundantContent` + 實際的標頭字元 + 內容檔案的位元組）— 無法通過`Add*` （這會將這些欄位清零）。 + 變體 **`UpdateNode`/`MoveNode`/`SetNodeContent`/`SetNodeCluster`/`UpdateCluster`/`MoveCluster`/`UpdateLink`/`RemoveLink`/`RemoveNode`**（包含索引重新映射 + 清理異常連結）**/`RemoveCluster`**. 編輯 =`FromExisting → mutar → Build → WriteLayout`，不觸及`init`-only。新閘口 **`--spheregrid-edit-rt0`** (`Tools/SphereGridLayoutEditRt0`, + 在`offline_ci.ps1`): 在 3 個實際網格（dat01/02/03）中，測試 **(1)** 不可編輯`FromExisting→Build` 在 **版面配置與內容** 中字節完全相同，**(2)**`MoveNode` 僅修改該節點的 **PosX 的 2 位元組**（零位擴散），**(3)**`SetNodeContent`/`RemoveNode` 有效的往返；+ 無語料庫的合成案例 + 正向捕獲超出範圍。3 個皆為 **PASS**（原始 828→827 個節點，在移除後）。經驗性：`RedundantContent==contentByte` 在 828/828 節中；`Unknown6` 每個非零節點（保留）。 **坦白說：**目前只有 LIB + GATE —— **缺少 UI（畫布 + 載入/編輯）**，且 **將編輯過的拓撲載入遊戲中仍未經測試**（離線安全 ≠ 引擎會接受它從未發布過的網格）。 Build 0 錯誤，3 個 gates spheregrid 通過。*(函式庫 + gate，無 UI = 僅文件；不更新 csproj — 待 UI 發布時再更新。)* — Jarvis-MAGIC
- **🔄`v2.23.2` — 奧羅拉：「重新讀取磁碟中的戰鬥資料」（反映其他模組在地圖上的存檔）。** 玩家在陣型編輯器中修改了陣型，但怪物 **並未出現在奧羅拉的地圖上**。調查結果：處理流程是 **正確的** — 奧羅拉已連結`formation slot[i] → monster-live anchor[i]` 與`MonsterId`/`Model` (`/work/phyre_chr_anim/models/mNNN/mNNN_animated.gltf`, **共有 340 個 HD 模型**，伺服器根目錄網址正確）。原因在於 **快取狀態**：該`RefreshCatalog` 僅重新載入場景清單，而非「開放戰鬥」的資料位元組——因此一個

 在「外部」進行的培訓編輯內容，在重新選取之前並未反映出來。已修正：新版本`ReloadSelectedBattle()` (重新讀取戰鬥資料 = 重新讀取磁碟中的 chunk2 陣型 + chunk3 錨點) + 「渲染」按鈕旁的 **「🔄 從磁碟重新讀取戰鬥資料」** 按鈕。 （Battle Explorer 原本已有「Refresh」功能，且會在每次導航時重新生成 — 該功能原本就已存在於其中。） 「Changed: False」與「地圖上無怪物」的**複合根本原因**在於陣型儲存未成功——已於**v2.23.1**（combo-blank）中修正。Build 0 無錯誤。[先前：`v2.23.1`]
- **🐛`v2.23.1` — 陣容編輯器：已填滿的槽位現在會顯示怪物名稱（載入時的顯示錯誤已修正）。** 開發者指出，陣容的 8 個槽位在開啟時，對於已有數值的槽位（原始值 10DEh/10E2h），下拉選單（ComboBox）會顯示為 **空白** — 只有在手動選擇後才會顯示名稱（甚至原本為 FFFFh 的空槽位也顯示為空白，而非「(空)」）。原因：Avalonia 的陷阱 — 該`SelectedItem` 在 load（物件初始化器）中設定的值，會於逐行 ComboBox 實體化之前套用`ItemsSource` （透過 RelativeSource 綁定），因此選取範圍無法解析，顯示為空白。修正方式：在填入`Slots`, 重新套用每個`SelectedMonster` (切換 null→值) 在一個`Dispatcher.UIThread.Post(..., Background)` — 此時 ComboBox 會根據已填入的 Items 重新進行比對。儲存於`slotsSyncing` 以避免 **標記為「dirty」**（在實際編輯之前，載入狀態仍維持為「Changed: false」）。Build 0 錯誤。[上一則：`v2.23.0`]
- **🔮`v2.23.0` — 魔法觀看器（PS3 Magic HD）中的「SPELL」名稱：採用盡力而為的連線方式（經所有者授權）。** 擁有者要求即使沒有經過字節驗證的加入權限，也必須顯示該名稱（「現在就是他媽的得做」，2026-06-07 — **對 no-fabricate 規則的明確覆寫**）。新`MagicSpellNameResolver` (FfxLib/Dictionaries)：magic_####（ID 0..1023，12 位元）→ 嘗試`CommandCharacter` →`CommandMonster1` →`CommandMonster2` →`Item` (所有`Dictionary<ushort,string>`)，返回`nome ~fonte` (例如：`Firaga ~char-cmd`) 或`magic_####` 若未進行映射。在 **PS3 Magic (HD)** 中出現異常（`Ps3MagicBrowser`):`Ps3MagicEntry.SpellNameDisplay` 將清單標題與詳細資訊頁面的標題翻譯，且搜尋功能可依名稱進行搜尋。**老實說：**該`~fonte` 該品牌屬於未經字節驗證的「假設」（目錄上寫著「未

 「names proved」）；系統管理員會在螢幕上進行驗證，若發現任何名稱有誤，我們便會調整偏移量／字典。建置過程零錯誤。[先前：`v2.22.0`]
- **🧩`v2.22.0` — SPHERE GRID BUILDER（v1，從零開始）：這套已通過驗證的函式庫終於在使用者介面上實作了。** 網格拓撲（叢集／節點／連結／位置）是硬性鎖定的；該`SphereGridLayoutBuilder`+`WriteLayout` (gate`--spheregrid-build-rt0` PASS）原本沒有介面。新導覽列 **「Sphere Grid Builder 🧩」** （Core Authoring，位於 Sphere Grid Explorer 旁）→ 表單式操作：**新增叢集 / 新增節點 / 新增連結** → 即時清單 → **驗證**（函式庫的範圍檢查）→ **建構與儲存**（`.dat` 來源`WriteLayout`（字節安全，儲存於專案根目錄或可執行檔目錄）。這正是「從零開始建立球形網格」這個標題下，終於能實際使用的版本。**v1 實況說明：** 沒有視覺化畫布（透過數字設定位置）；編輯現有節點的數值仍需透過「球形網格探索器」進行。 **重新確認遊戲內狀態（你的疑問）：**該`WriteLayout` 這是字節精確的（已證實往返 RT0），但 **在遊戲中載入新拓撲結構仍未經證實** — 離線安全 ≠ 引擎會接受它從未發布過的網格（螢幕上會顯示誠實的提示橫幅）。 Build 0 無錯誤。[先前：`v2.21.0`]
- **❓`v2.21.0` — 導覽列中的「???」類別：目前沒有編輯器的 3 個 Wave-1 系列模組，其瀏覽器現已設為唯讀模式。** 擁有者要求：將那些 **已驗證具備讀寫功能、位元組安全及 RT0 閘門，但完全沒有螢幕顯示** 的 Wave-1 系列模組，歸類至獨立類別中。 我已找到這 3 個（其餘所有模組都已接線完成）：**`buki_get.bin`**（武器與寶物目錄），**`albheddic.bin`**（阿爾貝德詞典），**`battle_script.bin`**（指針／腳本表）。導航末端新增卡片 **"???"**（第一波，無編輯器）→ 3 個按鈕 → 1 個通用控制項**`UnwiredCatalog_Control(family)` 該程式會解析檔案（workspace master 或已擷取的參考），並透過 FfxLib 的讀取器列出唯讀條目（`BukiGetTreasureCatalog_File`/`AlBhedDictionary_File`/`PointerScriptTable_File`, 解碼器`FfxEncoding.UsDecoder`). 坦白說：該寫入器確實存在（RT0 位元組完全相同且未編輯），但 **編輯功能超出** 此畫面之範圍。編譯無錯誤。[上一頁：`v2.20.1`]
- **🔌`v2.20.1` — 已失效的「Extras」分頁 恢復運作：source-root 會自動偵測已萃取的參照。** 擁有者指出，**Tex

tures (TM2)、PS3 Magic (HD)、PS2 Models (RSD)、PS2 Audio (.wd)、Project/Pipeline、Magic Effects 以及 Presentation Containers** 皆以「空白」狀態開啟。原因：該`Project_Service` 解決了`Path_FfxPs2Root`/`Path_Ps3DataRoot` 步行`master→ffx→ffx_ps2` — 但載入的工作區是 **Steam-mod master**（`...\data\mods\ffx_ps2\ffx\master`)，其`ffx_ps2` 只有那些`.bin` 已修改（ZERO 原始素材），且沒有`ps3data`. 已修正：解析器現在會**優先選用已知的提取根域**（`D:\FFX Extracted\FFX` →`ffx_ps2` +`ffx_data\gamedata\ps3data`，與`Directory.Exists` guard + 專為專案衍生版本設定的備用方案 + 手動覆寫「Set ffx_ps2 Root...」）。這些根目錄僅適用於唯讀瀏覽器（8 個模組）——**核心寫入模組則直接使用 ProjectPath（master）**，且保持原樣。 現在這 8 個分頁會自動填入正確的參照路徑。編譯 0 錯誤。[先前：`v2.20.0`]
- **🗺️`v2.20.0` — 內嵌於編輯器中的地圖場景編輯器（無需瀏覽器）：基於 WebView2 標準的第三個檢視器。** 業主要求（「請製作得類似『嵌入式模型檢視器』，且位於編輯器『內部』」）：新增導覽 **「地圖場景編輯器 🗺️」**（Spira Forge 卡片，位於 Aurora 旁邊）→`SetModule` 展覽`MapSceneEditorEmbedded_Control` 該平台託管著 **可編輯地圖場景實驗室**（`RuntimeTools/FFXMapViewerWeb` 來自 Lane Jarvis-MAP：**299 張地圖**、點擊選擇子網格 + 調整工具 + 材質／光源面板 + 輔助視窗`map-edits.json`) 在視窗內的 WebView2 面板中。**重新使用`WebView2Host` 共享**（Model b36 / Magic b37）— 現在這 3 個檢視器共用一套嵌入式基礎架構。新功能`MapSceneEditorLauncher` (http 8768 與 Aurora 8765/Magic 8766/Model 8767 不同 + 快取清除 + 出口處消滅 Python) +`MapSceneEditorEmbedded_Control/DataModel`. 建置 0 錯誤，編輯器重新啟動時未發生當機。**協調事項：** Jarvis-MAGIC 應所有者要求，將 Jarvis-MAP 的網頁整合至 Jarvis-MAGIC — 已於`SESSION_HANDOFF`. [上一頁：`v2.19.2`]
- **🗺️ 繪製時 HOOK 規格：自動記錄材質→每幀紋理（取代 SpecialK 手動執行的「Highlight Selected」）——僅限 RE 文件，不包含 csproj 的 bump。** RE 資料庫複製：已找到最佳掛鉤點 =`FFX_Phyre_BindNamedTextureUnit_DrawTime` @`0x67DAC0` (RVA`0x27DAC0`)，稱為 **每張貼圖每筆繪製操作呼叫 1 次*

* 由 flush 提供`FFX_Phyre_FlushTextureUnitBinds_PerDraw` (0x67E990)。探針的精確配方：`__stdcall(arg0=slot dst, arg1=descritor)`; **textureKey = ASCII 字串，格式為`[[arg1+0x94]+0x20]`** (= 標準化紋理名稱 = 檔案的基名 =`.dds`我們匯出器的 /import-path，與`Compressed_<CHK>.dds` + PNG 圖檔`tex/`); 跳過便宜的濾網`FrameBuffer`/`RealFrameBuffer`/`NoTexture`. **誠實地說：** 在引擎的綁定端（由全域狀態驅動的迴圈）中，並不存在 FileMaterialId/MeshId/SubmeshId`dword_CCC81C`, 並非基於材質物件）——精確的關聯鍵是 **紋理名稱**（`honest-limit`); 描述符指標僅用於去重；按子網格進行消歧 = 繪圖提交中的第 2 個可選掛鉤（本次執行中未找到）。已驗證的鏈：`0x642560→0x67E990→0x67DAC0→0x6A3240→0x66E680→sub_4D5910`. 資料庫中的名稱變更與註解 複製 +`idb_save`. 規格：`docs/reverse/FFX_PHYRE_DRAWTIME_BIND_HOOK_SPEC_2026-06-07.md`. *(RE/lab = 僅限文件，不會更新編輯器中的 csproj 檔案。)*
- **🗺️ 螢幕上已驗證的戰場 WARP 功能（probe/ctl — 僅文件/實驗室，不更新 csproj）：即時將玩家傳送至地圖上的任何座標。** 動詞已實作`ffxprobectl whereami/backup-pos/restore-pos/nudge/pos/warp` (`RuntimeTools/FfxDinput8Probe/ctl/Program.cs`, 附加元件、Build OK）並與 FFX.exe VIVO 進行比對（探針`hooked=1`):`whereami` 讀取播放器當前的位置（`inst+0x0C/10/14`, 確認為行走狀態 = X/Z 繼續)，以及`nudge`/`pos` **瞬間移動並「黏住」** — **Halyson 證實看到該角色在螢幕上變換位置**。場域扭曲`structural`→**已驗證**。**實際觀察結果：**每幀的回退機制並未觸發（`inst write + reseat` 僅此而已，無需 field-actor 的快取——這進一步闡明規格 §1A 中的離線理論。這是進行高保真度 RenderDoc 擷取的先決條件（導航至地圖表面）。待處理事項：跨區域`warp <sceneId>`, 表格`sceneId→área`, 解決 field-actor 問題。Specs/RE：`docs/ai/FFX_FIELD_WARP_TOOL_SPEC_2026-06-06.md` +`docs/reverse/FFX_FIELD_*_2026-06-06.md`. *(probe/ctl lab/RE = 僅供文件使用；請勿在編輯器中更新 csproj 檔案。)*
- **🐉`v2.19.2` — 嵌入修正：WebView2 會填滿面板並隨畫面調整大小而變動（適用於這兩個檢視器）。** 在螢幕上，WebView2 會...

arcado 僅在一個角落渲染（在高 DPI 螢幕上約佔 67%），周圍呈現「黑色」，且無法配合編輯器的大小調整。原因：該`SyncControllerBounds` 不斷增加`Bounds × RenderScaling` 而 Avalonia 已經針對主機 → **DPI 的雙重計數**（內容以 ~1/scale 為基準）進行了尺寸調整。已修正於`WebView2Host` （已分享，因此請一次修復 **Model Viewer v2.19.0 和 Magic Viewer v2.19.1**）：根據 **父視窗的實際 client rect** 調整 WebView 大小（`GetParent`+`GetClientRect`, 不涉及縮放運算) + **每次調整大小時重新同步** (`EffectiveViewportChanged` +`ArrangeOverride` 已批准於`DispatcherPriority.Background` （以便在 Avalonia 重新定位原生主機後執行）。Build 0 無錯誤。螢幕驗證 = 親眼確認。[上一則：`v2.19.1`]
- **🪄`v2.19.1` — 內建於編輯器的 MAGIC VIEWER（無需瀏覽器）：沿用 v2.19.0 版的 WebView2。** 直接回應原發文者（「這個構想一直都是『在』編輯器內實現；開啟瀏覽器是蠢事」）：**「Magic Viewer (Web)」** 已不再開啟外部瀏覽器 — 現在瀏覽器會`SetModule` 顯示`MagicViewerEmbedded_Control`，一個 **位於視窗內的 WebView2 面板**。**重複使用`WebView2Host` 已分享**：Model Viewer 已更新至 v2.19.0（為兩個檢視器提供單一嵌入基礎架構，避免重複）。新增功能`MagicViewerEmbedded_Control/DataModel` +`MagicViewerLauncher.EnsureServerAndGetUrl` （啟動本地 HTTP 伺服器 8766 埠 + 清除快取，並透過 WebView 瀏覽該頁面）；**重新載入** + **在瀏覽器中開啟** 按鈕（備用方案）。 **協調（同一分支中的兩個聊天室）：**我等待另一個聊天室提交`WebView2Host` (v2.19.0) 需依賴其乾淨的版本——無損壞的樹結構；其分支在`HANDOFF_CODE_AUDIT_HD_MODELS_2026-06-06.md`. **編譯 0 個錯誤，編輯器重新啟動時不會當機。** [上一則：`v2.19.0`]
- **🐉`v2.19.0` — 內建於編輯器中的模型檢視器（無需瀏覽器）：面板中的原生 WebView2。** 劇情反轉的第二階段：先前用於顯示 816 個模型的 **同一個 three.js 檢視器**，現在已能在 **編輯器視窗內** 的面板中運行 — 新增 **「模型檢視器 (內嵌) 🐉」** 按鈕，位於「額外功能」卡片中 →`SetModule` 顯示`ModelViewerEmbedded_Control` 透過以下方式託管 **Edge WebView2**：`NativeControlHost` (Win32 互通性：子 HWND + `CoreWe

bView2Controller`, bounds sincronizados em `ArrangeOverride`, HiDPI por `渲染縮放`). Usa o **runtime WebView2 Evergreen JÁ instalado** (sem bundle Chromium — nuget `Microsoft.Web.WebView2` 1.0.2592.51, ~poucos MB; **NÃO** o CEF pesado que bumparia ~100MB). O painel sobe o mesmo http server (`ModelViewerLauncher.EnsureServerAndGetUrl`, porta 8767, cache-bust) e navega o WebView pra ele; botões "Reload" + "Open in Browser" (fallback). `Program.cs`/AppBuilder **intocado**. **Build 0 erros.** Spike provado num worktree isolado (juiz: compila + 0 warnings novos) antes de trazer pro main. Fase 1 (browser, v2.18.0) segue como fallback. **Decisão do dono junto:** galeria abre no **rest pose LIMPO** (animação opt-in) — paramos o whack-a-mole de animação offline; animação real = mocap depois (fila). Doc `FFX_MODELVIEWER_EDITOR_2026-06-06.md`. [anterior: `v2.18.1`]
- **🔧`v2.18.1` — 自我審計：修正了 6 處我（Jarvis）的失誤（在對兩則聊天記錄進行對抗性審查時發現，每項發現均經第二位審核員核實）：**
  - **Ps3MagicBrowser**：每個資料夾的第一張貼圖會在 UI 執行緒中同步解碼（也就是我之前說已移除的凍結現象）**，並**在背景中再次解碼 — 現在 row[0] 會交由背景處理，`DecodeRows` 跳過已解碼的資料列（結束雙重解碼），以及`decodeGeneration` 翻了`volatile` （工作線程↔UI 的可見性）。
  - **怪物 AI 編輯器**：編輯十六進位碼（`AiEditRow`) 或 AI Assembler 中的指令碼/操作數 (`AiAsmRow`) **螢幕上的顯示內容未更新** —`AiEditRow` 現在開火`OnPropertyChanged(Meaning)` 在命令字元 E 的設定中；`AiAsmRow` 翻了`ObservableObject` 並通知 Meaning/Label/HasOperand。
  - **OpcodeHelp**：操作碼的工具提示有誤（`StartsWith("PUSHFF")` 從來都不會結婚；`PUSHF` float-const 會出現在寄存器說明文件中）— 已重新編寫，改為透過`OperandKindOf` （已驗證），並非因記憶輔助前綴不穩所致。
  - **MagicViewerLauncher**：這正是你「Waiting for catalog」錯誤的根源——即使 Python 尚未啟動，它仍會開啟瀏覽器並回傳「成功」；現在`EnsureViewerServer` 回傳 bool 值，輪詢時間上升至約 6 秒（冷啟動），失敗時顯示 **真實狀態**，對 URL 執行 **快取清除**（過期存根），並在 ProcessExit 時 **終止 Python 程序**

**（不外洩流程）。
  *（僅修正「我的」檔案。另一個聊天室的蠢事已經移至`docs/ai/HANDOFF_CODE_AUDIT_HD_MODELS_2026-06-06.md` 供他檢查+修正 — 我沒碰他的路線。）* 更新 csproj。
- **🐉`v2.18.0` — 編輯器中的「模型檢視器（HD）」：包含 816 個帶紋理與動畫的模型之 3D 圖庫。** 這個情節轉折（「這得在編輯器內運行才行」）已成為一項功能：在「額外功能」選單中新增了 **「模型檢視器 (HD) 🐉」** 按鈕 → 點擊後將開啟`RuntimeTools/FFXModelViewerWeb` (three.js + GLTFLoader) 透過 localhost HTTP 提供服務（與 Magic Viewer/Aurora 相同的、經過驗證的方法 —`python -m http.server`, 獨立埠 **8767**；必須使用 HTTP 連線至`fetch()` 來自目錄 + GLTFLoader 的`/work/...`). 此瀏覽器為 **動態圖庫**：彙整了 **816 款型號** 的統一目錄（`modelviewer-catalog.json`，由 HD 通道基準線生成（pc/sum/npc/mon/obj/wep）， **按類別篩選 + 評斷 + 搜尋**、縮圖，以及 **動畫片段播放**（AnimationMixer + 片段選擇器）+ 環繞/網格/線框/旋轉/貼合。 完全相容於 HD 系列（META 1 + 純 HD）中已烘焙的 glTF 檔案——無需重新烘焙。`ModelViewerLauncher.cs` (此為`MagicViewerLauncher`) + 按鈕在`Main_Window.axaml`/handler。**建置 0 個錯誤；已成功提供服務（目錄/index/gltf = 200）。** **更新 csproj**（實際 UI 功能）。 **第二階段已排入待辦清單（待負責人決定）：**將相同的檢視器嵌入編輯器的 WebView 面板中（無需瀏覽器）——需安裝 1 個 NuGet 套件；three.js 引擎具有主機無關性。文件：`FFX_MODELVIEWER_EDITOR_2026-06-06.md`. [上一頁：`v2.17.0`]
- **🗺️ 地圖場景編輯器 — 僅限檢視的檢視器變為可編輯的實驗室（文件／實驗室 — 無需修改 csproj）：** 該`RuntimeTools/FFXMapViewerWeb` 新增了一個獨立的編輯層（此功能隨後由已暫停開發的 SPIRA FORGE 繼承——無需啟動 Forge、無需整合控制台、也無需以 C# 重新編寫）。**(c0)** three.js **本地化供應商版本**（離線模式，無需 CDN ——`vendor/three/` 589 個 jsm 檔案，MIT 授權；importmap 指向該位置，其中 unpkg 的備用方案已註解）。**(M1)** **點擊選取子網格** (`editor/selection.js`): 從捐贈者克隆而來的射線投射器`aurora-overlay.js`, 穩態鍵方案`keyOf="meshId:submeshId"`, 處於步行模式／游標鎖定狀態（+ 防護）`isGizmoEngaged`: race giz

mo-vs-國家隊（預拖動已關閉）。**已驗證**：執行 **真實供應商版 GLTFLoader r165** 對抗`azit00` 實際：1 網格／14 基本形 → 14`THREE.Mesh`，每個都包含`geometry.userData.{submeshId,meshId,fileMaterialId}`, 14 個唯一鍵, 0 次碰撞。**(c2/M2)** **側車`map-edits.json`**（真相來源，將基於金鑰的差異比對重新套用至不可變的 glTF —— glTF 絕不會被重新序列化；`editor/mapEdits.js` baseline-once + reset + layer；**已證實的冪等性** 對比真正的three@0.165.0：執行 1 次 == 4 次，兄弟節點保持不變，localStorage 往返，輕量級冪等性) + **gizmo** MIT 的 TransformControls (`editor/gizmo.js`, 輸入 LOCAL → 房屋（Y 軸向下翻轉）) + **材質／光源面板** (`editor/materialLightPanel.js`, 寫入時複製 (clone-on-write)。**(M3)** 新的 C# 寫入器 **`PhyreDdsWriterLab`**：往返`.dds.phyre` **經實測證實為精確至位元**（5 個實際樣本，DXT1/DXT5）——與「僅解碼」提取器的結果相反；以及 **寫入方向判定**：`.phyre` **可重新寫入**，離線透過 MIT roelin 分支（不含外洩的 PhyreEngine SDK）—— 文件`FFX_PHYRE_WRITER_FEASIBILITY_2026-06-06.md`. **(M4)**`PhyreModelExportLab` 獲得了附加標記 **`nodePerObject`**（預設為 OFF，位元組識別碼與舊版相同；ON = 每個子網格批次 1 個節點／1 個網格）— 實際上限是按子網格批次計算，而非按物件計算。 **(M5)** **按物件放置的 RE 已破解（離線）**：placement =`PNode::m_localMatrix` (PMatrix4 inline, 64B, struct **+0x10** 的偏移量)；world 是透過運行時遍歷來組成的`m_parent` （已透過反射描述子驗證）`sub_5055B0` + 散步`sub_5067C0`, db 複製) + RE 來自 scene-load/material-bind 鏈 (`graphicFieldMapLoad`→綁定核心`0x65BA20`; 僅在材質中使用 texture-anim`*Mat_CTA*`). **誠實：** **本次執行中無法在螢幕上進行驗證**（專案規則：視覺真實性 = Halyson）— JS 經由`node --check` + 真實載入器的接線組 + 對手審查；C# 由`dotnet build` + 字節往返。M1/M2 = 經實證具備數據邏輯的 SCAFFOLD；耐用性 (3b) 符合實驗室標準。計畫：`docs/ai/FFX_MAP_SCENE_EDITOR_20_STEP_PLAN_2026-06-06.md`; 清倉特賣：`docs/ai/FFX_MAP_SCENE_EDITOR_BUILD_CLOSEOUT_2026-06-06.md`. *(lab/RE = 僅限文件，不會更新編輯器中的 csproj 檔案。)*
- **🐉 目標 1 已解決**

DA — Phyre 的 parent-map 處於離線狀態（doc/lab/RE — 未更新 csproj）：`m_matrixParents` (`PMesh` f44) 精確至位元組 + 約一半的回收 HD 殘餘值。** Codex 設定的目標`blocked-by-probe` (parent-map PNode) 透過 IDA 取得：Phyre 骨架的精確位元組級 parent-map 為 **`PMesh::m_matrixParents`** (`PArray<int32>`, 結構體偏移量 40 → 檔案連結 **f44**, ArrayLink`@ DataOffset+ObjectsSize+Offset`, root=−1)。摘自`.dae.phyre` == 探針的即時擷取 **6/6 逐位元組** (c001/c004/c005/n042/n054/n043) → **偽造「離線不可能」**（Codex 偵測到了錯誤的欄位：PNode→PNode，3-9%）。修正於`phyre_chr_gate` (讀作`m_matrixParents` 實際值，而非導致爆炸的約 5% 啟發式值）。 **應用於 59 個殘餘幀（重新烘焙 + Blender 品質檢查，由對立立場的審判者與懷疑論者共同進行）：16 個乾淨幀 + 13 個扭曲幀 = 29/59 可用（49%），100% 離線處理； 動作捕捉 59→30；動畫演員可用率 91%→95%。** IDA 評論已儲存於`0x490330` (副本`FFX_recon_modellane.i64` + 重新命名佇列）。**現場動作捕捉拍攝（同日）** 驗證了可遊玩「永恆者」（瓦爾福／伊弗利特／安尼瑪／夜隼／魔導士）的捕捉流程 並發現那 7 隻「損壞的永恆者」其實是 **召喚效果/道具模型**（樹木／陰影／貼圖）——而非生物；在遊戲中渲染效果良好； **6 個已重新分類為非生物 → 生物殘餘 30→24**。已驗證：`ffxprobectl spawn 0x30NN` (slot=s-id) 可在螢幕上顯示任何模型。文件：`docs/reverse/FFX_PHYRE_MATRIXPARENTS_OFFLINE_SOLVED_2026-06-06.md` +`FFX_AEON_MOCAP_SPAWN_AND_SUM_PROPS_2026-06-06.md`. **結算（PURO-HD 烘焙）：殘餘值 59→9。** 已實作靜態 PURO-HD 烘焙（Phyre 骨架，無重新定位）`.chr`): Blender 品質保證（QA）處理剩餘的 24 個模型 = **13 個已清理 + 2 個已恢復的扭轉模型**（靜態），尚餘 **9** 個（8 個單體模型 + s013，多數為非網格模型）；動畫角色 **可用率從 91% 提升至 98%**。 備註：這 15 個是靜態的（無動畫——缺少純 HD 運動路徑／動作捕捉）。文件`FFX_HD_PUREHD_STATIC_RESCUE_2026-06-06.md` + 方案`docs/ai/FFX_HD_PUREBAKE_10STEP_PLAN_2026-06-06.md`. *(RE/lab = 僅限文件，不會更新編輯器中的 csproj 檔案。)*
- **🪄`v2.17.0` — Magic Viewer 已完成（3 條平行工作流程）：編輯器中整合的網頁檢視器 + 精緻化的選單 + RE 的`root+88` 已關閉：**
  - **La

ne A — 編輯器中啟用的網頁檢視器：** o`FFXMagicViewerWeb` （由 Codex 建置的 — 法術索引、套件圖、貼圖堆疊、執行時證據、效果階段、對照表 + 6 個索引／目錄）處於 **孤立** 狀態（編輯器中沒有對應按鈕）。 新增 **「Magic Viewer (Web) 🪄」** 按鈕（位於「Extras」群組中，「PS3 Magic (HD)」旁邊）+`MagicViewerLauncher.cs` 用來……`RuntimeTools/FFXMagicViewerWeb` 來源`python -m http.server` （埠 8766，與 Aurora 8765 不同）並開啟瀏覽器——此操作方式與 Aurora/MapViewer 完全相同（必須使用 HTTP：該`app.js` 做`fetch()` 來自目錄 →`file://` 會出現 CORS-hang 錯誤）。並未使用該路徑`file://` 來自 SpiraForgeHub。
  - **Lane B — 2 組經過精修的魔法選單**（唯讀，無寫入權限）：PS2`Magic Effects` 新增了 **搜尋**（package/lane + kernel/lane）功能，以及 **誠實的空狀態**（顯示可操作訊息而非空白面板），且「Counts」卡片不再與「Summary」重複。PS3`Magic (HD)`: **在 UI 執行緒之外** 解碼縮圖（大型資料夾不再卡住 — 列會顯示「待處理」，並透過串流傳輸）`Dispatcher`（使用已過時的 generation-token 對應密碼），**按紋理名稱搜尋**，以及「開啟資料夾」/「開啟檔案」按鈕，附帶`IsEnabled` （不再出現 dead-click）。*（根據 ID 命名的法術名稱仍被封鎖 — 沒有名稱表；該聯結`magic.bin→magic_####` 這是因果關聯被阻斷了，不是我編造的。）*
  - **Lane C — RE 來自`root+88` (Pass12，僅限文件，已應用於 REAL 資料庫)`FFX_recon.i64`):** 已關閉 Pass11 的 2 個未解決問題。**(1) 誰負責填充 runtime-root：**`sub_7FD9A0` (`FFX_Magic_MaterializeRuntimeRoot`) 安裝`FFX_Magic_RuntimeRootTable[0x12A4080]` 進入 Bootstrap（bin-load）後，將其歸零`root+88`；各階段並不會更換資料表——而是重複使用相同的根節點，並就地進行變更。**(2) 最終寫入器`root+88`:**`sub_817200` = **0x21** 指令碼處理常式位於`FFX_Magic_OpcodeHandlerTable` (`0xC48EC8`); 在家庭中`0x1000` 寫道`root+84`=`root+88`=在工作副本中使用相同的游標，並在該階段結束時將變更寫回根目錄。5 次重命名 + 註解`[pass12]` 已套用並儲存至實際資料庫中。Doc`docs/reverse/FFX_MAGIC_ROOT88_WRITER_PASS12_2026-06-06.md`. *(坦白說：spell→具體的指令碼、與計時引擎精確同步，以及對寫入器的全面支援，目前仍處於「被阻擋」狀態。)*
  - 更新 csproj (

實際 UI：launch + polish）。*（C 通道為 RE/僅限文件，但仍使用同一入口。）*
- **🧠`v2.16.0` — Monster AI Editor 現已可正常使用：解碼意涵 + 技能名稱 + 篩選器 (+ 崩潰修復)：**
  - **雙重當機問題已解決：**開啟「Monster Commands 1/2」（KernelCommands）會導致編輯器關閉 — 兩個選取處理程序（`CommandList_SelectionChanged` +`MonsterLinks_SelectionChanged`) 在執行期間會存取名為 XAML 的欄位，而該欄位為 **null`EndInit`**（而且載入時間超過 300 毫秒就會觸發超時保護）。現在他們改用`sender` （始終有效）。
  - **每條指令皆顯示其含義**（Edit Operands E AI Assembler）：`CALL 7010`→`Battle.findMatchingChr`,`CALLPOPA 700B`→`Battle.performCommand`,`POPV`→`var[1]`, 跳轉→`→ jump[n]`. 輔助程式`AiScript_File.OperandGloss(opcode,operand)` +`OpcodeHelp` (依指令碼顯示的工具提示) + 說明文字。
  - **指令／技能的操作數會顯示其名稱：**`PUSHII 0x3049`→`⚔ Firaga` （來源：`AiCommandId`/`CommandCharacter_Dictionary`)，不再是「12361 [3049h]」。
  - **指令篩選器：** 🔎 搜尋框可依名稱／助記符／十六進位數篩選（輸入「Firaga」或「3049」即可找到，無需捲動約 300 行）＋「X/Y」計數器。
  - **帶有名稱的怪物清單：**`m004`→`m004 · Mafdet` (透過以下方式解決：`Monster_Dictionary`, ID 的備用方案)。
  - 修正模組描述（原先為「唯讀」，現修改為：編輯操作數 + AI 彙編器 + 行為函式庫）。更新 csproj 檔案（實際介面）。
- **🎨`v2.15.1` — 怪物指令／戰鬥指令／道具：屬性編輯器已重新設計為「Shop Explorer」標準（結束 50 欄位試算表）：** o`KernelCommands_Control` 從那個**約有 50 欄的巨型 DataGrid** 中脫身（這是老闆要求的「爛屬性」，違反了`FFX_EDITOR_UI_CONVENTIONS.md`) 採用 **卡片式詳細資訊** 標準：左側為指令清單，右側為詳細資訊面板，並按群組（身分／動畫／選單／角色鎖定／消耗／攻擊數據／元素）分組顯示卡片，**標記在 WrapPanel 中轉為核取方塊** （易於閱讀，而非 80 欄），內容較多的群組（屬性、狀態觸發機率／持續時間、特殊狀態／增益效果、額外資訊）收合於 **Expander 中**，而「使用處／怪物連結」則保留在第三欄中。 **沒有任何可編輯欄位遺失**（欄位對比）

不；僅 Name/Description 設為唯讀 — 這些是已解碼的 getter，沒有 setter）。處理常式／事件／公開方法均保持不變（Save/Undo/Discard/LoadIngame、篩選器、OpenMonsterRequested、RestoreViewState）。乾淨的建置，0 個錯誤。 *（由代理在隔離的工作樹中執行，編譯至綠色狀態，原樣套用。）* 更新 csproj（實際 UI）。
- **🖱️`v2.15.0` — Aurora 拖放定位 + 立體地圖（翻轉） + 可拖曳面板（經所有者確認已上線）：**
  - **拖放定位：** 在 MapViewer 中，選擇「Place mode」→ 將怪物（球體）拖曳至平面 → 放開 → 新座標會傳回編輯器，並點擊 **「💾 儲存位置"**（位於編輯器 **E** 內，位於疊加層中）會記錄該`.bin` **byte-safe** 版本（委派給`BattleArenaPositionWriter` 已驗證；僅 X/Y/Z 會變更，W 保持不變，備份`.aurora.bak` （自動）。已確認尚在人世：`azit03_00` 除了 chunk3 的位置陣列外，其餘部分均無差異。
  - **網頁→編輯器通道（缺失的一環）：**`AuroraDragBridge` —`TcpListener` 在 **由作業系統選擇的任意埠** 上（不`HttpListener`/固定門：那裡有成群的`python -m http.server` 佔據門口 +`HttpListener` 需要 urlacl/admin）。至少支援 HTTP/1.1（CORS +`POST /drag` +`POST /save`); 該連結將透過深度連結導向至檢視器 (`&drag=<porta>`). 新的閘門`--dragbridge-selftest`: POST→緩衝區→讀取 往返 **通過**。
  - **`Battle_File.WriteWithMonsterPositions`** (編排撰寫層級 1) — 補全缺失的位置寫入，鏡像`WriteWithFormationSlots`.
  - **倒置地圖 已修正：** Phyre 的幾何體為 Y 軸向下，而 glTF/Three.js 為 Y 軸向上 → 幾何體 **及** 錨點群在 X 軸上均旋轉 180°（同一起點 → 對齊）。 拖曳翻轉不依賴方向 (`group.worldToLocal`).
  - **介面疊加層：**「🌅 Aurora 疊加層」面板可透過標題列 **拖曳**，且每個控制項皆附有 **工具提示**。
  - 更新 csproj（Aurora 中的 UI 功能已啟用）。各階段審核點`--kernelcmd-roundtrip`/`--dragbridge-selftest` 將僅保留為文件。
- **🐛`v2.14.3` — 開啟 Monster Commands (monmagic) 時發生當機 已修復 + 工作區持久化 + Aurora 中的名稱：**
  - **當機：** 開啟「Monster Commands 1/2」會導致編輯器當機（NPE 發生在`Ability_Command.WriteList`→`WriteBytesIntoTextFile`，早在`BuildFile()` （由製造商提供）。

 **根本原因：** 該模型已更名`UnusedText1/2*`→`JapaneseOnlyText1/2*` + 贏得了`Original*Offset` (preserve-only v2.14.1)，但 **UI 封裝函式**（`KernelCommands_Wrapper`,`MonsterStatSheet_Wrapper`) 保留了舊名稱，但去除了偏移量 →`PropertyUtil.CopyProperties` **將這些欄位放入**`Wrap`/`Unwrap` → 會變成 null → 「僅保留」功能失效，轉而進入「追加重建」模式，並在 monmagic 的空 JP-only 欄位中引發 NPE。**修正：** 在兩個封裝函式中執行完整的往返處理（重新命名 +`Original*Offset`) +`FfxEncoding.WriteBytesIntoTextFile` null-safe。**新閘門**`--kernelcmd-roundtrip`** (`Tools/KernelCommandRoundtripRt0`) 驗證 GUI 的確切路徑（`ReadList→Wrap→Unwrap→WriteList`) **位元組完全相同 4/4** (command/item/monmagic1/2) — 這是`AbilityCommandLab` （直通路徑）從結構上來說是看不見的。《Wired》在`offline_ci` → **26 個閘門通過**。
  - **工作區的持久性：** 該資料夾`master` 已載入的檔案儲存於`%LocalAppData%\FFXProjectEditor\last-project.txt` 並在 **啟動時自動還原**（優先順序：CLI 參數 → 最近載入的設定 → 預設值）。載入一次，永久儲存；預設情況下不再切換至 Steam-mod。
  - **全域當機記錄器**（`%LocalAppData%\FFXProjectEditor\crash.log`，來源：`Utils/CrashLog`) + 防守端的負荷在`KernelCommands` （顯示紅色說明性錯誤訊息，而非終止應用程式）。
  - **奧羅拉之室：** 怪物錨點現在會顯示 **名稱**（`🔴 <nome>`) 而不是「monster (live)」 (`_currentLineup`→`AuroraAnchorRow`).
  - 僅限文件隨車實習：`docs/governance/FFX_EDITOR_UI_CONVENTIONS.md` (面板預設值 = Shop Explorer，而非 50 欄的 DataGrid) + 撤銷 DINPUT8 規則（免驗證）+ 檢查清單中新增多語言註解／MagicViewer。更新 csproj（UI 功能）。
- **🈶`v2.14.2` — BattleTextExplorer 新增 JP 字型（真正的漢字，不再是`<MISS>`) + 2 個新閘門：** 該`BattleTextExplorer_DataModel.ReloadSources` 現在正在載入`jppc/battle/kernel/btl_txt.bin` 與`JpDecoder` — 2 位元字節漏洞（v2.14.0）的顯著回報。**已透過新閘道進行無頭模式測試**`--btltext-jp-decode` (`Tools/BtlTextJpDecodeRt0`): JP`btl_txt.bin` = 128 筆條目 / 451 個詞彙 → **44 個漢字** 出現`<K:n>` (銀行`base.ftc`), **0

`<MISS>`**，以及 **雙向無損 451/451**（解碼→編碼==位元組）。實際情況證實了推測：**戰鬥**相關文字僅使用普通資料庫`<K:n>` (無`<FTCX>`/`F2`/`F3`/`F5` — 這些是按事件計費的）。**已修正幽靈錯誤：** 該標誌`--btltexttable-rt0` 在頁首處公告如下：`BtlTextTableRt0.cs` 但**從未在`Program.cs`** — 在背景執行時會觸發 GUI 的 fall-through 機制（WinExe，0 stdout），並「無輸出地終止」。 現在已通過測試（預設為日文，語言備用方案）：日文 **PASS** (3982/3982) + 英文 **PASS** (1910/1910)。`--wave1-rt0` 接下來的 **12/12 PASS**；`--btltext-jp-decode` wired no`offline_ci.ps1` → **25 個閘道通過**（原先是 24 個）。*（其中 2 個閘道僅供文件參考；csproj 檔案的更新是根據 Explorer 介面中的 JP 來源。）*
- **💾`v2.14.1` — MonMagic Save 已改為位元組安全（最後一個會產生偏移的寫入器，已移除）：** o`Ability_Command.WriteList` 新增了一種 **僅保留** 模式：在讀取時擷取文字池的原始偏移量，並在未編輯文字的儲存操作中，**原封不動地重新輸出原始文字池**（將每個腳本放置於其原始偏移量處 → 共享字串，例如 monmagic 中多個空欄位均位於偏移量 0 處，將被視為「共用」而非重複）。 透過重新讀取進行驗證：若編輯變更了腳本的大小／內容，則會如常進行追加。這能消除 monmagic 的漂移問題，**且不會因去重功能而導致 command/item 損壞**（先前已駁斥）。Gate`AbilityCommandLab`: **command/item RT0 4/4 + monmagic RT0 4/4**（原先為 0/4 漂移）+ 所有關卡中皆出現 1 處旗幟編輯；**monmagic 已晉升為 CERTIFIED**（漂移現在會「未能通過」閘門）。`offline_ci` PASS. bump csproj（現在將核心編輯器的儲存檔以位元組為單位傳送給 monmagic）。
- **🈶`v2.14.0` — JP 文字解碼器可讀取 2 位元組的漢字（今日破解成果）：** 無損編解碼器`FfxEncoding` 現在可識別 **2 位元組來源的潛在客戶**（`0x06`/`0x26-0x2F`，於`docs/reverse/FFX_EVENT_TEXT_ENCODING_CRACKED_2026-06-06.md`) 並顯示 **可辨識的字形參考** —`<FTCX:n>` (活動的漢字)，`<K:n>` (漢字為`base.ftc`),`<F2/F3/F5:n>` （其他銀行）— 取代`<C..>`+`<MISS>` 先前出現的亂碼。**100% 對稱編碼器**（代幣↔精確位元組）。新閘道`--jptext-rt0` 活動語料庫中的「PROVA」（第367至

檔案，**18 935 個 JP 腳本，其中 15 467 個含 2 位元組字形**）： **字形偏移 = 0** + **冪等** 編解碼器（現有字元的別名會進行 1 次規範化並穩定化 = 安全；no-edit 會直接返回原始位元組）。這直接使`BattleTextExplorer` （請使用無損格式）。`offline_ci` = **23 個閘門** 通過。**csproj 版本更新**（UI 上可見的容量）。
- **🧱 ZERO 的 Sphere Grid BUILDER + 驗證器（已通過離線驗證 — 無需更新 csproj：僅包含函式庫 + 閘門，無使用者介面）：**`SphereGridLayoutBuilder` (`AddCluster`/`AddNode`/`AddLink` →`Build()`) 在記憶體中針對該`WriteLayout` 已通過測試，附帶 **範圍驗證器**（`Validate()` 拒絕超出範圍的連結／叢集 → 絕不發送會導致遊戲當機的檔案）。新閘門`--spheregrid-build-rt0` (`Tools/SphereGridLayoutBuildRt0`) 測試：build→WriteLayout→ReadLayout **結構相同** + **第二次遍歷位元組完全相同**（冪等序列化） + 驗證器的 **正向擒獲**（拒絕索引超出範圍的網格 +`Build()` （發佈）。這是「從零開始建立球體網格」這項創作的一半（該`WriteLayout` 是序列化器的半數）。**CI：22 個門**（編輯器內建 15 個 + 實驗室 7 個）。其餘已解鎖功能的規格詳見`docs/ai/FFX_UNLOCKED_FEATURES_DESIGN_2026-06-06.md`.
- **🌐 Sphere Grid LAYOUT/TOPOLOGY 編寫工具（已通過離線測試 — 無需修改 csproj：包含函式庫與閘道，目前尚無使用者介面）：**`SphereGrid_File.WriteLayout` 將記憶體中模型的網格完整拓撲（標頭 + 叢集 + 帶有位置的節點 + 連結）重新序列化——解鎖 **「從零開始建立球面網格」**（先前僅能編輯節點值；拓撲處於硬鎖定狀態）。新增功能`--spheregrid-layout-rt0` (`Tools/SphereGridLayoutRt0`) dat01/dat02/dat03（原始／標準／專家）中的「字節身分驗證（不可編輯）」測驗 — 讀取→寫入佈局==原始。**擴充版 CI：**`offline_ci.ps1` 現在執行編輯器中的 14 個內部閘道（`--wave1-rt0`+12 +`--spheregrid-layout-rt0`) 加上 7 個實驗室 = **21 個閘位通過**。**保留位元的重構**（閘位保持不變）：輔助函式`AppendTextScript` 摘錄自（從標準中刪除重複內容，位於`Ability_Command`+`Monster_StatSheet`) + 重新命名`UnusedText1/2*`→`JapaneseOnlyText1/2*` (試題文件`FFX_REPO_ARCHAEOLOGY`; BinaryMapper 採用偏移量方式 ⇒ RT0-safe)。+ 文件說明

`docs/reverse/FFX_EVENT_OFFLINE_DECODE_PASS_2026-06-05.md` (靜態解碼器 EV01) +`PORT_STATUS`/`RUNTIME_TOOLS_INDEX` 已更新。
- **`v2.11.0` — 🧠 商品化的 AI ASSEMBLER（實用型強大 AI 編輯器）：** 編解碼器中「
  100% 自由編輯 AI」的功能已成為正式功能。該路線的最新動態`FfxLib/Ai` +`Modules/MonsterAiEditor`:
  - **行為庫** (`AiSnippetLibrary`): 可參數化的模板，其位元組結構反映
    語料庫中經過驗證的語言 — 線性（`force-cmd`/`perform-cmd`/`grant-field`/`set-stat`/`raw-call`)
    以及條件式（RNG 1-in-K 輪替、計數器／階段「若未發生事件則強制執行指令」）。
  - **起飛前驗證器** (`AiValidator`): 操作碼∈48，HasOperand 對比 0x80，**孤立分支/進入點**
    （明確指出是哪個，而非不透明的 throw），操作數範圍，RT0 自我檢查，重建模擬執行，擴展/縮減；
    `SaveAssembler` 採取了防守姿態（封阻失誤）。
  - **友善的指令選擇器**（`AiCommandId`): 操作 performCommand ↔ 名稱 透過`(cat<<12)|id`
    關於`CommandCharacter/CommandMonster1_Dictionary`; 介面中的下拉選單（不再使用原始十六進位數）。
  - **新的編解碼器基本類型**（`AiScript_File`):`GrowWorkerJumpTable` (為工作程式的跳轉表
    新增槽位 — 啟用新分支) +`AppendGuardedAction` (將儲存的動作預先新增至入口點
    並保留處理常式) +`OperandKindOf`.
  - **UI** 在`MonsterAiEditor`: 卡片行為函式庫 + 「驗證」按鈕／報告 + 指令下拉選單。
  - **Gate`AiScriptLab --ai2` PASS**（真實數據集 361）：jump-grow **898/898 個工作節點**，guarded-action
    **692/692**（第 1 個＋最後一個入口點）＋合成哨兵 1/1，驗證器無誤 346/346，AiCommandId
    620/620，正向攔截 8/8/8（透過編輯器路徑的跳出邊界攻擊）。`--` 原始 RT0 **361/361 完整**。
  - 對抗性審查（4 名審查員）發現並修正了 2 個錯誤（越界哨兵迴圈；`OperandKind`
    （已放入編輯器的儲存檔中），卡在閘門處。文件：`docs/reverse/FFX_AI_JUMPTABLE_GROW_PROVEN_2026-06-05.md`
    +`docs/ai/FFX_AI_ASSEMBLER_PRODUCTIZED_2026-06-05.md`.
  - ⚠️ 離線模式結構已通過測試；**遊戲內行為（RT2）尚待 Halyson 確認**（測試中）。範本
    「治療生命值低於 25% 的盟友」及「在 t 時進入狂暴狀態」

「N」組未發貨（缺少字節——請確認 HP 欄位／計數器）。
- **🐉 HD 模型 — 帶紋理的總體角色/NPC 陣容 + 烘焙處理 + 視覺品質保證 (僅文件，無凹凸貼圖)：** 第 7.2 節/第 7.4 節的
  `SUCESSOR_FFX_HD_MODELOS_MASTER_2026-06-05.md` 對 sum/npc 關閉。
  - **貼圖（基於清單驅動）：**`extract-texture-batch` 在`RuntimeTools/PhyreModelExportLab` 贏得了
    **`--from-manifest`** 閱讀該`g_fileNames[]` 從`<id>.ahwin32` （= 權威資產清單）並擷取
    遊戲實際載入的紋理。**305 張 PNG 圖檔**（玩家角色／非玩家角色／生物），來源地圖`texture-provenance-map.json`,
    **0 個靜默不匹配**。RE: 該`ahwin32` 這是一個易於閱讀的 C 語言標頭檔 — 解決了交叉引用 (`c906←c106`,
    `c908←c108`,`c806←c805`) 且具有多重質感（`c101+c101_01`,`n238+n238_hair`,`n356←n238_hair`) 無去程。
    額外發現：NPC 的 Rig 繼承密鑰 =`0x6NNN` 在`.chr` (映射 nXXX→kNNN，222/222 有效)。
    文件`docs/reverse/FFX_AHWIN32_ASSET_MANIFEST_2026-06-05.md`.
  - **Bake（網格＋紋理＋動畫）：** 驅動程式`work/_scratch_mgrp/bake_cast.py` 來源`phyre_chr_gate`. **靜態
    253/253**（所有角色皆已貼圖，無瑕疵）。動畫：自有動作總和，NPC 繼承`skl/<base>`.
  - **視覺品質檢查（工作流程，21 名視覺檢查人員）：** 經 F3D 篩選的 248 個動畫 — 157 個無瑕疵 / 58 個扭曲 /
    33 個爆炸。 這 33 個動畫的綁定選擇器（rest/A1）並未修復。
  - **🔧 透過 Blender 修正（2026-06-06）：F3D 在貼皮動畫中出現錯誤。** Blender 診斷（網格
    `EXPLODE_RATIO≈1.0`, 不會成長）＋忠實渲染（伊布）證明了「爆炸」的寶可夢**身體完整**，僅
    四肢／配件伸展。 重新品質檢查（8名人員針對Blender渲染結果）**修正為 175 個乾淨渲染（71%） / 59
    扭曲模型 (24%) / 14 爆炸模型 (6%)** — **20 個模型已救回**，離線烘焙的可用率始終維持在 **約 94%**。
    那14個真實案例 = **11個Aeons + 3個NPC**（非人形骨架；需進行動作捕捉／重新建立父節點映射）。規則更新：**
    以Blender畫面為準，F3D的資料不可靠**。工作流程`work/_scratch_mgrp/blender_{diagnose,render_anim,batch_render}.py`.
  - **🎯 已透過以下方式解決再行銷問題：`--retarget-delta` (2026-06-06)：175→215 已清理 (87%)。** 新增標記於
    `phyre_chr_gate` 將繼承的 motion 作為 **delta 套用

frame0 針對 NPC** 的 REST（`M=restLocal·inv(m0)·mf`),
    維持 NPC 的比例，而非套用基地的比例。RE 已證明（IDA），該重新映射`.chr@0x30` 已經
    應用了——原因在於 **retarget rest-pose**，而非 remap（文件`FFX_INHERITED_MOTION_REMAP_RUNTIME_2026-06-06.md`).
    Piloto+第73批次失敗 + Blender 重新品質檢查 + **按模型保留最佳結果**：**+40 合格，44 救回，零退化**
    （保留 1 個，因原可能退化）。 **動態 NPC = 200/222 合格 (90%)，0 個崩壞**；剩餘 **8 個 Aeons** 崩壞
    （網格免疫 → 動作捕捉）。解決了 MASTER §2.4 中的「A1-universal」問題，且無 A1 風險。
  - **🐉 完整演員陣容已於離線狀態下確定（2026-06-06）：498/643 合格（77%），90% 可用。** 已將 QA-Blender-fiel +
    retarget-delta + keep-best 擴展至其餘部分：obj/wep/pc（46 個無瑕疵/55 個，團隊資料無瑕疵）以及 **340 隻怪物**。 舊版
    怪物（bbox）的 QA 標註「0 次爆炸」＝**謊言**；Blender 忠實 QA（29 個代理）發現 **127 個實際爆炸**；
    retarget-delta 針對 66 個繼承的 → **36 個晉升**，怪物 206→**237 個乾淨**。 **總動畫數量 (643)：498 乾淨 /
    86 扭曲 / 51 爆炸 / 8 空白。** 殘餘 (9%) = 網格發散/綁定退化 → 動作捕捉/重新建模，不進行重新定位。
  - **obj/wep/pc (2026-06-06)：** 同延伸製程 — 靜態 **obj 110/110 + wep 79/79 + pc 34/49**
    （15 個 pc 錯誤 = 假插槽）`c8xx` 沒有`.chr` PS2)。**完整靜態 HD 角色陣容 = 476 個模型。** 物件/武器幾乎
    全為剛體（零散動畫 25/7）；畫面抽查：f001/w001/c004=Auron 畫面無瑕疵。
  - 圖庫`work/cast_hd_gallery.html` (模型檢視器、靜態/動畫切換、總和/NPC/物件/WEP/PC 篩選器)。所有內容皆位於
    `work/` (gitignored)：僅「指令」屬於程式碼。**不更新 csproj 版本號**（lab/RE 在 RuntimeTools 中）。
- 註冊文件`docs/ai/FFX_TOOLBOX.md` 已建立（活體登記第11條的
  `FFX_TOOLBOX_DISCOVERY_PLAYBOOK_2026-06-05.md`): **線上**掃描 + 審查
  FFX HD/PS2 外部工具的授權（VBF、Phyre、核心`.bin`, ATEL、FMOD、
  TM2、FMV）以及編輯器的 NuGets。遭否決的關鍵發現：**External File Loader
  (ffgriever, BSD-2)** 未重新打包的鬆散檔案，**Kaitai Struct** (C# MIT 執行時庫) 用於
  生成 C#+JS 讀取器，**fahrenheit** (MIT, C#) C 語言模組框架

使用 hook+DLL，以及
  確認 **FFXDataParser 為未授權版本（僅限研究用途）**。欄位`testado?`
  此外`❌` — 待處理的對照語料庫測試（oracle），相關計畫已載於文件中。僅限文件：
  **不更新 csproj**（lab/RE 僅限文件規則）。
- 2026-06-02 整合的新批次，專用於 FFX HD/PS2 的深度研究，包含
  唯讀工具及移交給 Claude/Codex 的項目：
  -`Ps3MapViewerLab` 編目`ps3data\map`/`btlmap` 並執行了首次
    區域／切片掃描；
  -`PhyreMapExportLab` 已開啟`map/azit/azit00` 作為靜態 glTF，之後
    已啟用`.dds.phyre` 作為候選的 PNG 紋理；
  -`FFXMapViewerWeb` 已轉換為具備軌道/行走/無剪裁功能的本地 Three.js 檢視器，
    包含 manifest/export/validator 面板以及預設紋理化目標；
  -`PhyreSkinnedAnimExportLab` 記錄了「出口版」的貼圖／動畫
    怪物模型，但未提供除顯而易見內容以外的素材／動畫；
  -`ReverseHarness`,`SphereGridRuntimeProbe` 以及`SphereGridRt2Lab` 建立了
    用於 PS2/Sphere Grid/執行時搜尋的唯讀閘道。
- 接下來`azit00` 現在已有一套經過驗證的紋理套件：
  -`static-debug.gltf`,`static-textured.gltf` 以及
    `static-textured-vertex-color.gltf`;
  - 14 個基本圖元、4,896 個頂點、1,632 個三角形；
  - 7 張 3D 根紋理`.dds.phyre` 解碼為 PNG 格式，並透過
    `fileMaterialId` 候選作品；
  - 帶紋理的目標物在 glTF-Validator 中顯示 0 個錯誤／0 個警告；
  - 使用 F3D 和 Three.js 作為外部載入／渲染測試。
- IDA 平面圖／Phyre 材質來自`azit00` 現在記錄這條共10個階段的路線，以
  證明`PMaterial`/`PParameterBuffer`/在呼叫
  任何「遊戲中實際材質」的綁定之前，先指定實際紋理槽位。
- 地圖解析器／匯出器現在會輸出`phyre-link-dump.json` 以及
  `phyre-string-index.json`；第一項結構性發現顯示
  `PMaterial 0..13 -> PParameterBuffer 12..25` 以及紋理插槽標記在
  `PParameterBuffer.parentFieldOffset=172`.
-`azit00` 現在也支援透過 link-table 進行比較綁定 Phyre：
  - 新增`material-slot-analysis.json`;
  - 新增`static-textured-phyre-slots.gltf` 及變體
    `static-textured-phyre-slots-vertex-color.gltf`;
  - `PMesh.parentFieldOffset=52 -> PMat

erial 7..13 ->
    PParameterBuffer 19..25 -> field172 -> sharedDataId 10..16`;
  - 顯式橋接`sharedDataId 10..16 -> root texture slot 0..6`;
  - 14/14 個由...連接的子網格
    `bound_by_pmesh_pmaterial_pparameterbuffer_field172_candidate`;
  - glTF-Validator 0/0、F3D 非空白格式及 Three.js，包含 14 個網格／14 種帶紋理的材質／4,896 個頂點；
  - 目前**尚未**是`engine_exact_material`; IDA 應在提升權限前確認字段 172 及
    著色器參數。
- 2026-06-02 的 IDA/執行時研究現已記錄在案，且未對
  遊戲二進位檔進行版本控制：
  - 索引/oracle`.mgrp` 在`docs/reverse/mgrp_oracle_2026-06-02/`;
  - 適用於 MGRP 和 Sphere Grid 的 IDA 探測腳本；
  - 推廣計畫／未知項目在`docs/reverse/WRITER_PROMOTION_GATES.md`.
- 主套件`DOSSIÊ FFX 01-06-2026` 現已與以下內容合併：
  -`58` 已打包的資料夾；
  - 每份資料夾的清單；
  - 版本控制的 Git-safe 副本，存放於`docs/history/DOSSIÊ FFX 01-06-2026/`;
  - 因 GitHub 配額限制而受阻的巨型外部二進位檔排除報告。
- 大量文件資料終於整合完成，用於`Pt2..Pt45`，內容包含：
  - 按工作坊類別分開的資料庫；
  - 整合式主圖集；
  -`KNOWLEDGE_BASE.md` 以根目錄作為唯一入口；
  - 正式的合併整合計畫；
  - 衛星伺服器附件`Pt6/Pt9`;
  - 該計畫的官方技術分支。
- 該活動`Pt50..Pt58` 現在也有正式的收購計畫了：
  -`merge em docs`
  -`Extras agora`
  -`Extras depois`
  -`research congelada`
  -`limpeza historica`
- 活動規劃現已涵蓋以下兩組原始資產樹：
  -`ps3data`
  -`ffx_ps2`
-`Pt6` 現在也獲得了正式的暫停運作方案：
  - 高層清算
  - 子項目彙編
  - 執行時/AI 地圖集
  - 繼任者的啟動方案
- 宣傳活動`Pt52..Pt58` 現在也有官方結論了：
  - 短期成熟度表
  - 結論為`Extras agora`
  - 判決書`Extras depois`
  -`research congelada`
  - 由……衍生的紙張`Pt67`
-`Pt50` 以及`Pt51` 現在也有官方的歷史清理了：
  - split`ps3data` vs`ffx_ps2`
  - 來源規則手冊
  - 篩選條件

引用義務
- 繼承人為`Pt6` 在`LiveBattleLab`:
  - 驗收合約`Pt47/Pt48` 終於能正常運行了（表面為唯讀
    來自`Ptr_script_*` + 匯出包含「自然擷取、群組/標籤」的 CSV 檔案；
  - 來源追蹤功能會在該工件中將自然擷取與「bench-replay」區分開來；
  - 申領上限 **維持不變**（`structural dispatch/VM watch candidate`);
  - 詳情請見`docs/history/LIVEBATTLE_CONTRACT_WIRING_2026-05-31.md`.

### 新增
-`RuntimeTools/Ps3MapViewerLab/` 作為讀取專用的目錄管理員，負責
  `ps3data\map`/`btlmap`.
-`RuntimeTools/PhyreMapExportLab/` 如何將獨立的 Lab 檔案匯出為地圖
  Phyre HD，包含清單檔、描述檔報告、glTF 除錯檔、帶紋理的 glTF 以及
  紋理綁定報告。
-`RuntimeTools/FFXMapViewerWeb/` 作為「Pilot」專案的靜態 Three.js 檢視器
  `map/azit/azit00`.
-`RuntimeTools/PhyreSkinnedAnimExportLab/` 作為獨立於出口的
  怪物外觀／動畫。
-`RuntimeTools/ReverseHarness/`,`RuntimeTools/SphereGridRuntimeProbe/` 以及
  `RuntimeTools/SphereGridRt2Lab/` 作為反向驗證的唯讀實驗室。
- 2026-06-02 針對 MapViewer/Phyre/PS2/runtime 的歷史紀錄文件：
  -`docs/history/FFX_PS3_MAPVIEWER_PROJECT_PLAN_2026-06-02.md`
  -`docs/history/FFX_PHYRE_MAP_EXPORT_LAB_10_STEP_PLAN_2026-06-02.md`
  -`docs/history/FFX_PHYRE_MAP_EXPORT_LAB_AZIT00_STATIC_CANDIDATE_2026-06-02.md`
  -`docs/history/FFX_PHYRE_MAP_EXPORT_LAB_AZIT00_TEXTURE_CANDIDATE_2026-06-02.md`
  -`docs/history/FFX_PHYRE_MAP_MATERIAL_IDA_PLAN_2026-06-02.md`
  -`docs/history/FFX_PHYRE_MAP_MATERIAL_LINK_DUMP_FINDINGS_2026-06-02.md`
  -`docs/history/FFX_MODELVIEWER_SKINNED_ANIM_EXPORT_2026-06-02.md`
  -`docs/history/FFX_EXE_MGRP_ORACLE_2026-06-02.md`
  -`docs/history/FFX_REVERSE_HARNESS_2026-06-02.md`
  -`docs/history/FFX_SPHEREGRID_EDITOR_V2_GATES_2026-06-02.md`
  -`docs/history/FFX_SPHEREGRID_IDA_RUNTIME_PROBE_2026-06-02.md`
  -`docs/history/FFX_PS2_*_2026-06-02.md`
-`docs/reverse/harness/` 用於輔助解碼／探測的腳本以及
  `docs/reverse/spheregrid_oracle_2026-06-02/`.
-`docs/history/CHAT_MASTER_DOSSIER_2026-06-01.md` 作為對此主要聊天室的全面重建。
-`docs/history/DOSSIÊ FFX 01-06-2026/INDEX.md` 作為文件包的主索引。
-`docs/history/DOSSIÊ FFX 01-06-2026/GIT_EXCLUSION_REPORT.md` 用來記錄僅存於完整本地套件中的唯一大型元件。
-`Pt21` 結構性讀者吸收率：
  -`important.bin`
  -`a_ability.bin`
-`ProductionSafetySmoke` 針對這兩個家族的強化措施包括：
  -`Read`
  -`No-Edit Byte Identity`
  -`Reread`
- `docs/history/PT21_PT22_R

將 `EADER_NOEDIT_GUARDS.md` 設為安全 Pt21/Pt22 區段的生產端決策日誌。
-`Pt16` `Slice 1` 吸收如下：
  - 將附加文字標記納入合約中`FFXProjectEditor/FfxLib/Text/*`
  - 純驗證／往返決策工具
  -`TextLabTools/TextContractHarness` 作為首個生產端煙霧消費者
- 針對活躍難題的前沿快照：
  -`docs/history/BATTLE_AI_FRONTIER_2026-05-31.md`
  -`docs/history/MODELVIEWER_BINDING_FRONTIER_2026-05-31.md`
-`Pt23` a`Pt34` 現已確立為歷史知識基礎：
  -`docs/history/PT23_TO_PT34_KNOWLEDGE_BASE.md`
  -`docs/history/PT23_TO_PT34_CHANGELOGS.md`
  -`docs/history/PT23_TO_PT34_BRANCH_MAP.md`
-`Pt23` a`Pt45` 現已整合為程式碼可利用的知識庫，位於：
  -`docs/history/PT23_TO_PT45_CODE_KNOWLEDGE_BASE.md`
  -`docs/history/PT23_TO_PT45_CHANGELOGS.md`
  -`docs/history/PT23_TO_PT45_BRANCH_MAP.md`
- 全新百科全書，助您瀏覽整個戰役：
  -`KNOWLEDGE_BASE.md`
  -`docs/history/PT2_TO_PT11_KNOWLEDGE_BASE.md`
  -`docs/history/PT12_TO_PT22_KNOWLEDGE_BASE.md`
  -`docs/history/PT23_TO_PT45_KNOWLEDGE_BASE.md`
  -`docs/history/PT2_TO_PT45_MASTER_KNOWLEDGE_BASE.md`
  -`docs/history/PT6_PT9_DEPENDENT_WORKSHOPS_ANNEX.md`
  -`docs/history/NON_FFX_EDITOR_THREADS_ANNEX.md`
  -`docs/history/PT_FAMILY_LINES_ANNEX.md`
  -`docs/history/OFFICIAL_MERGE_PLAN_2026-05-31.md`
- 針對資產傾倒的完整樹狀結構搜尋方案：
  -`docs/history/PS3DATA_FULL_TREE_RESEARCH_PLAN.md`
  -`docs/history/PS2_FULL_TREE_RESEARCH_PLAN.md`
- PS2/Extras 招募計畫的官方方案：
  -`docs/history/PT50_TO_PT58_ABSORPTION_PLAN.md`
- PS2/Extras 系列正式結束：
  -`docs/history/PT52_TO_PT58_CLOSEOUT_REPORT_2026-05-31.md`
- 該雙人組合的官方歷史澄清`Pt50/Pt51`:
  -`docs/history/PT50_PT51_HISTORICAL_CLEANUP_2026-05-31.md`
- 來自的全新實用凍結套件`Pt6`:
  -`docs/history/PT6_TEMPORARY_CLOSEOUT_2026-05-31.md`
  -`docs/history/PT6_CHILD_WORKSHOPS_COMPENDIUM.md`
  -`docs/history/PT6_RUNTIME_AI_DISCOVERY_ATLAS.md`
  - `docs/history/PT6_SUCCESSOR_BOO

TSTRAP.md`
- 歷史編輯版本參照：
  -`history/pt23-battleai-structure`
  -`history/pt24-exactlaunch-seam`
  -`history/pt25-selectorbank-materialization`
  -`history/pt26-battlestate-diff`
  -`history/pt27-routereplay-truth`
  -`history/pt28-battlecapacity-prep`
  -`history/pt29-keyitem-crashfix`
  -`history/pt30-autoability-crashfix`
  -`history/pt31-geometryviewport-block`
  -`history/pt32-chrcarrier-decode`
  -`history/pt33-aislice-payload`
  -`history/pt34-legacybridge-narrowing`

### 已變更
-`RuntimeTools/PhyreModelExportLab/PhyreTextureExtractor.cs` 現在展示
  通用提取`.dds.phyre -> PNG`，可針對地圖和怪物重複使用。
-`RuntimeTools/PhyreModelExportLab/DescriptorStaticGltfWriter.cs` 現在可以
  透過以下方式輸出多種紋理`fileMaterialId`,`TEXCOORD_0` 及變體
  `Color Float4 -> COLOR_0`.
-`FFXProjectEditor.sln` 現在包含`ReverseHarness` 作為實驗室專題。
-`KNOWLEDGE_BASE.md` 以及`docs/ai/SESSION_HANDOFF.md` 已更新為
  MapViewer/Phyre/IDA 前線的
  新入口點。
-`KeyItemEditor` 「公共領域」的表述已從「作者主導」的措辭重新歸類為`Guarded` 結構檢查，並保證不進行編輯。
-`AutoAbilityEditor` 「公共領域」的表述已從「作者主導」的措辭重新歸類為`Guarded` 結構檢查，並保證不進行編輯。
-`PORT_STATUS.md` and`docs/history/PRODUCTION_ABSORPTION_MATRIX.md` 現在區分`reader + no-edit guard` 出自一個真正致力於保障作家權益的專欄。
-`Pt19 / CurrentSurfaceLab` 現在反映在`main` 與`Readme.md` 針對現行 Shell 系統重新審理；
- 舊版批次檔`ReadmeAssets` 已被取代為`6` 當前版本的可追蹤截圖：
  -`CurrentWorkspaceOverview`
  -`CurrentMonsterEditor`
  -`CurrentItems`
  -`CurrentBattleExplorer`
  -`CurrentLiveBattleLab`
  -`CurrentStringExplorer`
- 文字行新增了明確的分隔符號，用以區分：
  -`EncodeSafe`
  -`DecodeOnly`
  -`RawPreserve`
  -`UnknownRisk`
- 現今可將「來回」的技術決策正式描述為：
  -`ReuseOriginalBytes`
  -`ReencodeAllowed`
  -`Blocked`
-`Pt29` 以及`Pt30` 這些不再僅僅是聊天記錄中的發現，而是作為 crashfix 和 hardening 的有據可查的歷史脈絡而存在。
- 官方吸收佇列現已明確說明如下：
  -`merge agora`
  -`merge depois`
  -`Extras/read-only`
  -`knowledge only`
- 那條線`Pt50..Pt58` 現在也明確說明如下：
  -`Pt56`,`Pt52`,`Pt54`,`Pt58` = 現在在軟體上發動攻擊
  -`Pt57` 以及部分來自`Pt53/Pt55` = 稍後再攻擊，目前仍為唯讀
  -`Pt53`,`Pt55`,`Pt57` = 積極的研究，但不過度誇大
  -`Pt50`,`Pt51` = 清除

在成為「潔淨水源」之前，其歷史沿革
- 該領域內首個被明確列為優先發展的新產品`Extras` 改為：
  -`MagicPackageViewer`
  -`BatEffPackageViewer`
  -`MagicEffectCrosswalkExplorer`
  -`never blind merge`
- 那條線`Pt6` 不再分散於「thread viva」與「packets upstreams」之間，而是統一由編輯部進行彙整，以便日後查閱。

### 已驗證
-`dotnet build RuntimeTools\PhyreMapExportLab\PhyreMapExportLab.csproj`:
  0 個錯誤 / 0 個警告。
-`map_azit_azit00.static-textured.gltf` 以及
  `map_azit_azit00.static-textured-vertex-color.gltf`:
  glTF-Validator 0 個錯誤 / 0 個警告 / 0 個資訊 / 0 個提示。
- F3D 渲染出帶有紋理的目標之非空白截圖，來自`azit00`.
-`FFXMapViewerWeb` 已在 Three.js 中載入帶有紋理的目標，且未出現主控台錯誤
  在本地 Smoke 中。
- 公開的 README 文件現已說明實際重新驗證過的 Windows 表面`main`;
- README 檔案中收錄的所有螢幕截圖均來自當前終端機，並非舊有的開發素材。
-`Pt23` a`Pt34` 現在至少需包含以下來源資訊：
  - 目的
  - 實用性
  - 合併的可能性
  - 各工作坊的簡要變更紀錄
-`Pt35` a`Pt39` 現在也以以下形式明確呈現：
  - 語言`binding truth`
  - 強烈的收窄`owner/target/parentage/commit`
  - 護欄基座，用於`Pt6` 以及`Pt23`
-`Pt44` 它不再僅僅是「新前端」，而是轉變為以下內容的唯讀交叉引用：
  -`formation 0..7`
  -`enemy actor rows 0..10`
  -`rawMonsterId -> corpus`
  -`composition truth` vs`actor-surface truth`
- 競選活動結束得太晚`Pt6` 現在也彙整了以下研究成果：
  -`Pt46 / AIBlobParityGrammarLab`
  -`Pt47 / AIRuntimeDispatchLab`
  -`Pt48 / SafeAIMicroProbeLab`
  作為 Runtime/AI 遺產的一部分，即使沒有寫入器或修補程式。
-`Pt40` a`Pt45` 這些內容均如實記錄為一項正在進行的 AI 活動，目前尚未產生具體成果，也尚未轉化為實際程式碼。
- 整個活動`Pt2..Pt45` 現在也可以分層瀏覽了：
  - 舊版基礎版`Pt2..Pt11`
  - 中間層`Pt12..Pt22`
  - 厚底`Pt23..Pt45`
  - 單一聚合 Atlas，包含記憶體／執行時／綁定／保護機制
-`Pt23..Pt45` 此外，以下項目亦明確列為附屬項目：
  - 作為`Pt6`
  - 的衛星`Pt9`
  - 生產異常`Pt29/30`
- 沒有前綴的 FFX 討論串`FFX Editor` 現在也正式被歸類為：
  - 該系列的作業層封裝`Extras / ps3data`
  - 該系列中實用的微型工作坊`Pt6 / Pt23`
  - 知識得以保存，可歸檔的討論串
- 那些偉大的

該專案的各系列現也正式確立為產品家族：
  -`Model Viewer / Binding`
  -`Battle / AI / Runtime Truth`
  -`Text Safety`
  -`Kernel / Shop`
  -`Tooling / Safety / Release`
  -`Production Crashfixes`

### 備註
-`Pt24` 按下了`exact launch seam`，但既未解決「自然擁有者」的問題，也未完成「Seam」的最終提交。
-`Pt33` 以及`Pt35` 緊了`ModelViewerLab`，但僅限於`AI Slice + .chr` 作為結構橋樑，以及`composition` 作為具有約束力的決定。
-`Pt29` 以及`Pt30` 這些是這系列工作坊的首批明確跡象，這些工作坊不僅具有直接的產出價值，且有極高的整合可能性。
-`Pt6` 由於在最近幾輪中，儘管進行了許多有用的收窄，但幾乎未帶來新的因果收益，因此已暫時暫停。

### 規劃中
- 的未來繼任者`Pt6`，但已基於新版 Bootstrap 和 Atlas 開發，並非直接使用原始程式碼；
- 可能採用窄版試行版`Pt15` 以唯讀模式執行，不進入 shell 的啟動程序；

### 待辦事項
-`Pt16` `Slice 2` 以及`Slice 3` 仍未納入此波：
  -`TextSourceCapability`
  -`Index*`
  - UI 的接線在`StringExplorer`
-`important.bin` 候選突變範圍從`Pt22` 僅剩技術待辦事項：
  -`0x10 + 0x12`
  -`0x13`
-`a_ability.bin` 以……為基準測量的綠色／黃色區域`Pt22` 僅剩技術待辦事項。
-`arms_rate.bin` 儘管 Oracle 的測試結果令人鼓舞，但孤立的 sidecar 突變僅在生產分支中仍處於待處理狀態。
-`Pt14` 這仍是一條執行時／除錯驗證線，而非生產環境框架的移植版本。

### 受阻
-`btl_txt.bin` writer 和 encode 仍處於被封鎖狀態；
-`w_name.bin` 對「公開作者」仍處於封鎖狀態；
-`Field String` 在應用程式中仍處於鎖定狀態；
-`important.bin` and`a_ability.bin` 因公眾的「變異安全寫入者」聲稱而保持封鎖狀態；
-`Pt22` Oracle 查詢結果本身並不會授權寫入者晉升；
- 任何對`runtime + memory + encounter tooling` 仍屬禁止之列。

## [v2.13.0] - 2026-06-05
### 新增功能
- **🌅 AURORA COCKPIT（Jarvis 夜間模式）— 三個連結：** (1) **MapViewer 確實會進行渲染** —`AuroraSceneRenderer` 開闢道路`file://` (瀏覽器會阻擋`fetch()` glTF/catalog → 先前在「Loading map」處會卡住）；現在可以順利載入了`http://127.0.0.1:8765/...` +`EnsureViewerServer` (向上)`python -m http.server` （單獨）。螢幕上顯示渲染已完成。（2）**EncounterTable → Aurora** — 雙擊其中一張表格`EncounterTableExplorer` 開啟`AuroraChamber` 已經開始渲染那個場景了`map` (`RequestOpenAuroraChamberForMap` +`AuroraChamber_DataModel.SelectSceneByMapKey` + 橋`Main_Window`). (3) **怪物的渲染** —`AuroraChamber` 注入`model` 由 âncora 透過陣容名單（chunk2）`Battle_File.Read().Formation`, 插槽↔錨點,`Monster_Dictionary`);`aurora-overlay.js` 載入來自`work/phyre_chr_anim/models/mNNN` 來源`GLTFLoader` +`AnimationMixer` （動畫；即時縮放滑桿）。附加效果，漸變為球體。
### 備註
- 編輯器編譯無錯誤。MapViewer 的渲染已確認；怪物渲染為加法模式（尚待所有者點擊以確認比例尺／外觀）。去重處理已記錄於`docs/ai/FFX_OVERNIGHT_2026-06-05_JARVIS.md` (Aurora/EncounterTable/FormationEditor = 標準；Field Hub/SpiraForgeHub = 停用；SaveTracker = 待退役的占位檔)。尚未推送（待 Halyson 確認）。

## [v2.12.0] - 2026-06-05
### 新增功能
- **🌅 AURORA — 陣型「位置」指令（僅值輸入，解鎖「定位怪物」功能）：** 新增
  `FfxLib/BattleMap/BattleArenaPositionWriter.cs` 將演員的 X/Y/Z 座標重新標記至 chunk3 的錨點陣列中
  (場內怪物 = 指標`+0x20`；另由 party/aeon/staging 提供`role`) **IN PLACE**，僅修改值：不觸及
  標題／指標／計數／其他區塊，原樣保留 W。 由於「battle→cena」的轉換屬於**同一性**
  （已在 IDA v2.10.0.1 中驗證），因此在「cena」中選定的座標會原樣寫入。與
  `FormationSlotWriter` (guard + backup-once`WriteLooseFile`).
### 已驗證
- **Gate RT0`RuntimeTools/BattleArenaPositionLab` — PASS (退出代碼 0)：** 在實際 btl 語料庫中 **862/862 可寫入** —
  RT0 (不可編輯 == 位元組完全相同) 862/862，僅位置 (差異僅限於陣列中`+0x20`) 862/862，重新讀取 862/862，
  + 儲存生命週期（暫存副本中執行「不編輯／編輯／還原」）通過。
- **封閉式 CI 間隙：**`RuntimeTools/offline_ci.ps1` 現在已運行 Aurora 的 3 個關卡 —
  **BiancaCatalogLab + AuroraChamberLab + BattleArenaPositionLab**（先前未包含在內）。完整 CI
  **通過 (7/7 閘門)**：ReverseHarness、AiScriptLab、FormationSlotLab、AbilityCommandLab 加上 3 個新模組。
### 延後
- **尊重遊戲內移動的位置（RT2）** = 探測 DINPUT8（已啟用）+ 開放遊戲。 寫入器在離線狀態下驗證位元組安全性；遊戲畫面為最終裁決。新增／移除怪物插槽（變更數量）= 結構性（Rebuild），下一個。

## [v2.11.1] - 2026-06-05
### 新增功能
- **📜 活動編輯器 — 關鍵字搜尋 + 語言篩選（應開發者要求）：** 該`EventExplorer` 新增了 (1) 一個
  **關鍵字搜尋** 欄位，可根據文字內容篩選台詞，以及 (2) **語言篩選器**（核取方塊
  英語／日語，**預設為英語**）——先前 JP 和 EN 會出現在同一個清單中（日語排在最前 = 日語牆）。
  重構`EventExplorer_DataModel` (`allTextRows` +`ApplyTextFilter`, 優先使用英文) + axaml (搜尋文字方塊 +
  日文／美式核取方塊)。**不涉及 Writer** (第 1 層級如下`--event-rt0` 397/397 + 編輯於 12/12)。
### 備註
- 原版僅包含 **JP（chunk 1）** + **EN（chunk 4）** 音軌 — 其中並無葡萄牙語`.ebp` (PT 指的是翻譯注入，
  這超出了 writers 的範圍)。單字搜尋僅限於所選的事件範圍內。

## [v2.10.0.1] - 2026-06-05
### 已驗證（RE / IDA，離線）
- **🌅 AURORA — 將戰鬥→場景轉換 = 身分認同，已在 IDA 中驗證（駁斥 Z 軸翻轉假說）：** 戰鬥引擎
  會將 chunk3（戰鬥區域）的座標 **原樣** 複製到角色世界節點中 — **無 Z 軸翻轉、縮放或
  旋轉**；僅 Y 軸會根據角色設定模型高度（`actor+0x534`). 由於這場戲`.dae.phyre` == 頂點幀
  Phyre 1:1，**P_cena(X,Y,Z) = P_battle(X,Y,Z)** (s=1, R=I, T=0)。已驗證的鏈：`FFX_Battle_AreaChunk_GetSetPosition`
  (`0x7AC000`; chunk3 基礎`0x112A9B0`; 逐字複製 4 個浮點數；角色 @ 的世界座標;`+0x3B0`) →
  `FFX_Battle_ResolveActorPlacement` (`0x7A9AE0`) →`FFX_Battle_GetActorByIndex` (`0x794030`, stride`0xF90` == 敵方
  RT2)。flip-Z 假設是因納入場外排（party-back Z≈-168）所產生的偽影。文檔：
  `docs/reverse/FFX_AURORA_BATTLE_TO_SCENE_TRANSFORM_IDA_PROVEN_2026-06-05.md` (+ 重命名佇列 至`.i64` （實際）。
### 已修改（極光之室 — 誠實）
- 極光之室的橫幅／疊加層：「戰鬥→世界 未校準／假設」→ **「身分（IDA 驗證）」**。 該疊加層
  將錨點直接繪製在場景座標上（預設值原本已是「身分」），而「翻轉 Z 軸」開關則變更為 **「被駁斥／比較」**；
  `coordSpace` 從`aurora-actors.json` =`scene_world_identity_ida_proven`.
### 延遲
- **即時確認（probe）：** 讀取`actor+0x3B0` 在 azit03 的「Force Battle」中確認「活體怪物」的狀況`≈ chunk3`
  (殘差 ~0) + 測量精確的 Y 項。探針已由 Halyson 釋放；僅待開放式組件就位（透過現有探針進行讀取
  ，無需新程式碼）。SPIRA FORGE 仍處於靜止狀態。

## [v2.10.0] - 2026-06-05
### 新增功能
- **📜 活動劇本撰寫者 — 第 1 級（編輯器中最後一個重大劇本撰寫漏洞，已修復）：** 該`Event_File`
  (`.ebp` / 容器 **EV01**) 已不再是唯讀狀態。**「編輯過場動畫／事件」對話框已變為按鈕。**
  - **`FfxLib/Event/Event_File.Write.cs` (新)：** 重新封裝 EV01 位元組精確容器 — 每個區塊均已重新對齊
    至`0x40`, 重新計算後的絕對偏移量表 + EOF 終止符（魔數 + 哨兵）`0xFFFFFFFF` （保留）。
    未編輯 = 保證逐字還原；編輯過的文字 = 再利用`TextTable_File.Write` (chunks JP=1/EN=4)；ATEL 腳本 (0)，
    Unknown 2 和 FTCX (3) 逐位元組完整保留。第二層鉤子`ScriptChunkOverride` （已編輯的 chunk-0 重新拼接）。
  - **`Event_File.cs`:** 擷取原始標頭 + 文字表格；允許字段字串為空指針
    （8 個檔案），並完整保留區塊內容（已記錄的可編輯邊界文件）。
  - **`TextTable_File.Write` (加法超載`includeTrailingPadding`):** 可產生不帶
    內部填充的表格+池（容器會重新填充為 0x40）。**不會導致錯誤`--textstr-rt0`**（預設值 = 舊版行為）。
  - **`Modules/EventExplorer` 已轉為對話方塊編輯器：** 可編輯的 JP/EN 字串（雙向文字方塊） + 按鈕
    **「儲存對話方塊」**，該功能會重新封裝並儲存`.ebp`.
- **📜 活動腳本撰寫者 — 第 2 級（區塊 0 = ATEL 腳本，追加/PATCH）：** 證明戰鬥用的 ATEL 編解碼器
  (`FfxLib/Ai/AiScript_File.cs`, **作為供體時設為唯讀**) 讀取／編輯事件腳本（同屬 AiFile 家族）。
  - **已證實的 PATCH 位元組級操作數** (12/12)：編輯 chunk-0 中的操作數僅會變更這些位元組；容器
    在其餘部分會重新拼接出完全相同的內容；重新讀取時會載入新的操作數。
  - GROW（AppendCode）是**已記錄的邊界**：該`AppendCode` 來自提供者的（專為 battle 設計，描述符位於
    DATA 區段）並不會重新配置事件腳本所使用的 **header-resident** 描述符（`[0x38..scriptStart)`) — 需要
    事件感知型重新定位（需與 AI Assembler 的專屬通道協調）。
### 已驗證
- **閘門`--event-rt0` (`Tools/EventRt0.cs`) — PASS：** 不可編輯 讀取→寫入 **397/397** 位元組完全相同；**編輯
  來回 12/12**（字串交換 → 重新封裝 →

重新讀取：已編輯的字串已核對無誤，塊內容保持原樣，且具備冪等性）。
- **Gate`--eventscript-rt0` (`Tools/EventScriptRt0.cs`) — PASS：** 編解碼器 chunk-0 RT0 **397/397**；容器覆寫
  **397/397**；**操作數修補 byte-local 12/12**。編輯器編譯無錯誤。
- **容器 EV01 的 RE 已驗證 (397/397)：** magic EV01，第 1 個區塊 @0x40，對齊 0x40（0 次違規），
  連續性（0 處中斷）、EOF==檔案大小、哨兵`0xFFFFFFFF`. 文件位於`docs/reverse/FFX_EVENT_*_2026-06-05.md`
  (容器，FTCX=字型表 4bpp，Unknown2=音效提示「SeSep」，ATEL 方言，填充/文字表，參考，IDA 主機)。
### 誠信 / 延遲處理
- 第 1 層 = **文字**（對話）已通過位元組安全與驗證；8 個 EN 檔案因指針條目為空而保持原樣（目前
  尚不可編輯）。 第 2 層 = 已驗證的 **修補檔**；**追加/擴充** 及結構化製作（FTCX 字形表 +
  Unknown2 提示碼 + 完整的 ATEL 事件彙編器）= 已記錄的第 3 層，尚未定案。 驗證階段優先採用
  離線字節級 RT0；經編輯的對話於遊戲內採用 RT2，建議在功能公開前先進行此處理。

## [v2.9.0] - 2026-06-05
### 新增
- **🌅 AURORA CHAMBER — 第 3 層（合一），新模組**`Modules/AuroraChamber`:** 將 🌙 BIANCA（
  btlmap 25 個場景目錄）與 MapViewer 整合，並從 chunk3 中擷取 **演員的座標**。獻給 Aurora 和 Bianca。💛
  - **場景選擇器** 會消耗`BattleMapCatalog_File`/`BattlefieldSceneResolver` (唯讀) — 按區域和地圖金鑰列出／選取場景。
  - **渲染** 負責`PhyreMapExportLab` (按需匯出 btlmap 場景的 glTF 檔案) 並開啟`FFXMapViewerWeb` 來源
    深度連結`?catalog=`/`?map=`/`?actors=` — **按場景劃分的迷你目錄**，永遠不會觸及`catalog.json` 既不會分享也不會重寫該`app.js`.
  - **座標** 透過新版閱讀器 **`FfxLib/BattleMap/BattleArenaAnchors_File.cs`**（純版／無Avalonia）：解碼
    chunk3（rec區 96B，指標`+0x10..+0x2C`，活生生的怪物`+0x20`, elem 16B XYZW Y-up)，列出
    battle-local 錨點並將 JSON 匯出至 Encounter Authoring。
- **MapViewer 的附加疊加層** (`RuntimeTools/FFXMapViewerWeb/aurora-overlay.js` + 1`<script>` 在`index.html`):
  錨點小工具由`?actors=` + 「pick」模式（在 y=0 平面上進行光線投射 → 世界座標系）。非侵入式（hooka
  `window.ffxMapViewerDebug`; 無操作（no-op）`?actors`/pick；絕不會更改該`app.js`).
### 已驗證
- **Gate RT0`RuntimeTools/AuroraChamberLab` — 通過 (退出代碼 0)：** GOLDEN 解碼 **5/5 完全正確** (azit03_00/dome00_00/
  klyt00_00/sins02_00/mihn00_00 == 文件中驗證過的座標）；資料集 **862/862** 乾淨（0 NaN/Inf，活體怪物 W==0
  活體怪物中 W==0）；確定性；BIANCA→場景→戰鬥→錨點的處理流程，**52/52** 個場景已透過錨點進行映射。
- **已驗證的 btlmap 渲染：**`PhyreMapExportLab export --area btlmap/azit/azit03_a` → 帶真實紋理的 glTF（68
  種紋理、10,804 個三角形、`gatePass: true`). 編譯器報告 **0 個錯誤**（於與 HEAD 隔離的工作樹中驗證）。
### Honesty / Deferred
- 場景橋接（EncounterTable`map` → btlmap) = **已驗證**。Transform battle→mundo = **設計假說，
  未校準**（P_場景 = R·s·P_戰鬥 + T；Z軸翻轉/偏航-180 未解決）——錨點為原始戰鬥位置，非
  引擎精確值。 透過探針進行校準 = Wave 3（需 Halyson 批准）。**SPIRA FORGE 仍處於停機狀態**

**；Aurora 僅
  使用 MapViewer + BIANCA（唯讀／附加），且不連接樞紐。

## [v2.8.0] - 2026-06-05
### 新增
- **🌙 BIANCA — Aurora Chamber 的創立（第 1 層，唯讀）：**`FfxLib/BattleMap/BattleMapCatalog_File.cs`
  （收錄 **25 個場景／56 個片段** 的 HD 內容，來自`ps3data/btlmap` —`<área>NN_<variante>` c/`mdl/d3d11/<leaf>.dae.phyre`)
  +`FfxLib/BattleMap/BattlefieldSceneResolver.cs`. Puro/Avalonia-free，可在編輯器中編譯（0 個錯誤）。
- **EncounterTable→場景的連結問題已解決且經驗證：** 關鍵在於 ** 欄位`map` (6ch = 區域+NN，例如「azit03」）**，非
  o`battlefield` u16（這是**全球競技場 ID**，可跨地圖使用 —`bf=1061` 位於 nagi/test/tori/zzzz）。文件：
  `docs/reverse/FFX_BATTLEFIELD_SCENE_BRIDGE_2026-06-05.md`.
- **已解碼的行動者座標 (RE)：** 每場戰鬥二進位檔的 chunk3 = 區域記錄 96B；**存活的怪物在
  指標中`+0x20`** (float32 X,Y,Z,W; Y-up; W=0; 步長 16; 編隊槽 ↔ 條目)。隊伍`+0x10`, aeon`+0x18`,
  相機`+0x2C`. 文件：`docs/reverse/FFX_BATTLE_FORMATION_POSITION_CHUNK3_DECODED_2026-06-05.md`.
- **已確認的 3D 處理流程（第 2 層）：**`PhyreMapExportLab` 匯出 btlmap 場景 **無需修改程式碼**
  (`-- export --ps3-root <ps3data> --area btlmap/azit/azit03_a`). 角色疊加圖層 + 透過探針進行
  座標校正 (DESIGN)：`docs/ai/FFX_AURORA_COORDINATE_SYSTEM_AND_CALIBRATION_2026-06-05.md` （僅在 Halyson 同意後才進行測試）。
### 已驗證
- **閘門 RT0`RuntimeTools/BiancaCatalogLab` — PASS（退出 0）：**完整目錄（光碟 56 == 目錄 56）+
  確定性；56/56 個場景，每個場景僅含 1 個主要模型；橋段含 **0 個無法解釋的遺漏** (22 張地圖
  HD 孤立圖 = 剪輯/僅限 PS2 版本 預期中；4 個孤立場景 bika04/grid00/nagi03/sfia00 = 頭目/劇情 預期中)。
### 延後處理
- **座標校準（探針）** 及 **在 🌅 Aurora Chamber 中的整合**（疊加層 + 拖曳寫入）：設計已完成；
  DINPUT8 探針需經 Halyson 核准，而 SPIRA FORGE 目前處於暫停狀態。

## [v2.7.1] - 2026-06-05
### 新增／驗證
- **第一波寫入完整性 — 12 組以位元組精確度觸發的閘控家族（掃描`--wave1-rt0`: RT0 12/12 通過):**
  WeaponNameTable、MacroDictionary、NameDescriptionTextTable、NameDescriptionTextPrefixTable、BtlTextTable、
  SphereGrid、ShopGearCatalog、BukiGetTreasureCatalog、AlBhedDictionary、PointerScriptTable、BattleTextTable、
  ShopTable。採用 **僅保留** 模式（複製原始檔 + 重新標記可編輯欄位；`WriteIdentity` 針對
  曾進行有損重建的玩家：WeaponName/Macro/NameDescPrefix/SphereGrid/ShopTable）。新的傳送門掃描`Tools/Wave1Rt0.cs`.
- **ShopItemCatalog**：已確認對其建立 **唯讀投影**`Ability_Command` (item.bin，已啟用) — 並非寫入間隙。
- 編輯器 **~功能上已關閉**：加上已啟用的項目，資料庫現在已大部分具備位元組安全性。

## [v2.7.0] - 2026-06-05
### 新增功能
- **解鎖 AI Assembler GROW/SHRINK 功能（結構化獨立檔案儲存）** — 新增`AiScript_File.SpliceAiFileIntoMonsterGrow`:
  將 AiFile 分區替換為大小不同的分區，對 AiFile 執行 **16-pad** 處理，**將後續區段進行位移**，並
  重新寫入 **標頭中的區段指標**（`m###.bin`)，並將 AiFile **逐字** 寫入（不覆寫
  codeLength）。 UI 中的 AI Assembler 現已支援「擴展／縮減」（grow/shrink）功能（先前僅支援「保留長度」）。已記錄的覆寫原因
  + 已依設計修正（方案 B：最小表面積，不修改`Monster_File.Write` →`--monster-rt0` 接下來的 361/361)。
- **載入器的 RE（IDA，開源）：**`docs/reverse/FFX_AIFILE_LOADER_RENAME_QUEUE_2026-06-05.md` — 載入器會根據
  **工作執行緒數量 + 每個工作執行緒的資料長度（取16進位）** 來調整虛擬機（VM）大小（而非根據區塊／DeclaredLength／codeLength），且
  **依賴檔案內的指標** → 擴充時的重新定位會被尊重，且 **尾部填充是安全的**。（黃金法則：rename-queue。）
### 已驗證
- **`--aiasm-rt0` 擴展 — PASS：** no-edit 重建 346/346、重新排版 346/346、拼接 346/346、**GROW 346/346**
  (插入 → 支援擴展的拼接 → 乾淨的重新讀取 + 尾部/標頭原樣保留 + 16 位對齊 + 冪等)，
  **SHRINK 346/346**（移除非目標指令 → 負差值 → 乾淨重新讀取 + 尾部保留）。`--monster-rt0`
  **361/361**（無迴歸）。 語料庫對齊：16/32/64/128/256，0 尾部填充。
- **螢幕上已透過點擊驗證的 UI：** 編輯器啟動（主檔自動載入）→ Monster AI Editor → **「AI Assembler
  (自由編輯)"** 已渲染，並附可編輯的指令清單（操作碼／操作數／移除）＋插入／儲存結構＋
  預覽。螢幕截圖`work/spira_forge_qa/monster_ai_assembler_v01.png`.
### 延後處理
- **grow 的遊戲內驗證 (RT2)**：需將生成的 m###.bin 寫入安裝目錄，並透過 probe DINPUT8 強制觸發戰鬥
  （共用）— 須經 Halyson 明確同意。 離線測試與重現（RE）可驗證位元組/遊戲安全性；遊戲內畫面為最終裁決依據。

## [v2.6.0] - 2026-06-05
### 新增功能
- **UI 中的 AI 組裝器** (`Modules/MonsterAiEditor`, 附加元件）——可在位元組級操作數編輯器上方對**整行指令**
  （插入／移除／修改）進行自由編輯的介面。重建後的 AiFile 源自
  `AiScript_File.Rebuild` (經 RT0 驗證：透過舊→新映射重新定位入口點與跳轉表)。可編輯清單
  （指令碼/操作數十六進位值 + 移除核取方塊），選取後插入，差異預覽。 **僅限編輯模式下儲存
  長度保留**（相同`codeLength`) → 透過以下方式進行字節安全的拼接`SpliceAiFileIntoMonster`. **GROW/SHRINK = LAB**
  （真實訊息）：儲存鬆散檔案需要支援標頭重排 + 對齊填充 + 遊戲內驗證。
- **3 個新的 RT0 無頭存取閘道**（寫入完整性）：
  -`--ctbbase-rt0` →`CtbBase_File` (**ctb_base.bin**)，僅保留。
  -`--mixtable-rt0` →`MixTable_File` (**prepare.bin**)，僅保留。
  -`--aiasm-rt0` → 驗證 **AI Assembler 的結構性儲存**（無編輯重建 + 重新佈局 + 接合字節相同）
    並測量語料庫中 AiFile→WorkerFile 的對齊狀況。
### 已驗證
- **CtbBase RT0**（255 筆記錄 / 530 B）+ **MixTable RT0**（112 個來源 / 25108 B）：位元組完全相同。
- **AI Assembler**：無編輯重建 **346/346**、重新佈局儲存 **346/346**、**接合儲存 346/346**（UI 路徑）—
  **保留長度且字節安全的編輯**。Grow=LAB（原因：標頭 0x34 的`Monster_File` 疊加`AiFile[0..4)`=codeLength
  + grow 會破壞 WorkerFile 的對齊；語料庫為 16/32/64/128/256 對齊，0 尾部填充)。
### 受阻 / LAB
- **AI Assembler GROW/SHRINK 鬆散檔案儲存** + 本次會話中未經點擊驗證的 UI 渲染（模組的標準誠實間隙）。

## [v2.4.4] - 2026-06-05
## [v2.4.4] - 2026-06-05
### 新增功能
- **FFX MapViewer 除錯切片（網頁檢視器）：** o`RuntimeTools/FFXMapViewerWeb` 現在顯示當地控制項
  `Spector.js` (`Open Spector`,`Capture Next Frame`,`Export Last Capture`) 以及首場座談會`Material Debug`
  已載入 glTF 素材的動態清單、選取器、資料方塊，以及各紋理插槽對應的卡片
  (`map`,`normalMap`,`aoMap`,`envMap`，等等）。
- **已關閉的實作文件：**`docs/history/FFX_MAPVIEWER_SPECTOR_MATERIAL_DEBUG_IMPLEMENTATION_2026-06-05.md`
  記錄哪些內容已被納入、哪些已通過驗證，以及哪些仍明確排除在驗證範圍之外。
### 已驗證
-`FFXMapViewerWeb/app.js` 已通過語法檢查。
- 透過 HTTP 進行本地驗證 + 使用 Chrome 無頭模式在`map/azit/azit00`: 檢視器已載入，地圖已渲染，新的
  控制項已出現，而面板`Material Debug` 根據載入的 glTF 進行渲染。
- 新的預覽採用了「誠實的備用方案」：當執行環境／瀏覽器無法
  可靠地提供可重複使用的像素時，檢視器會降級至`Frame preview unavailable` /`Texture preview unavailable on this source surface`
  而非偽造有效的視覺證據。

## [v2.4.4] - 2026-06-05
### 新增功能
- **交接遭遇 → 編隊** (SPIRA FORGE)：在「戰場中樞」中，「遭遇預覽」現已列出 **可選的戰場戰鬥
  **；選擇其中一項將發佈至`FieldContext.SelectedBattleId` 而 **陣型編輯器會直接跳轉至
  這場戰鬥**（載入陣型）。透過共用架構，
  實現「點擊區域並切換陣型」的總體規劃功能，無需進行外殼配置。`FieldContext` 贏得了`SelectedBattleId`/`SelectBattle`.
- **EncounterIdMapLab** (`RuntimeTools`) — 針對 id encounter↔btl_* 資料結構的唯讀查詢。
### 已驗證
- **EncounterIdMapLab:**`EncounterTable.BattleId` 與 826/863 中的 btl_* 資料夾建立 **1:1 對應**（例如：`azit03_00`);
  37 個無資料夾的 BattleIds + 37 個無對應項目的資料夾（特殊對戰／活動）— handoff 會過濾出實際存在的項目。
- 編輯器建置 0 個錯誤；`offline_ci` 4 個閘門通過；螢幕上已驗證交接（`azit03_00` 在 Hub → 戰鬥編輯器中
  直接跳轉至已載入的戰鬥（7 個區塊）。螢幕截圖`work/spira_forge_qa/handoff_encounter_to_formation_v04.png`.

## [v2.4.3.1] - 2026-06-05
### 反向分析／證據
- **HD 皮膚矩陣色盤已解碼（離線）— 腿部的線圈並非綁定。** 推翻交接假說中的第 3 項假設
  (`CONTINUE_AQUI_PERNAS_HD`): 「52」地圖`m_skeletonMatrices` → 79 個接點" **位於 Phyre 檔案中**，而非 IDA。
  - 皮膚色板是`PMatrix4[0..51]` （連結自`PMesh` 欄位 12）；`== m_skeletonMatrices` vivo **逐位元組**
    (`maxDist=0.00000`).
  - 映射 slot→node 是`int` 在每個的 **偏移量 12** 處`PSkeletonJointBounds[j]` (52 槽位 → 52 節點，一對一映射)。
  - 組合`m_defaultPose` 來源`m_matrixParents` **精確**地重現了該逆向綁定：`0/52` 節點出現分歧。
    因此`--hd-defpose+--hd-parents` **這已是遊戲中的實際綁定**。
  - 歷史線圈的根本原因：未經烘焙的`--hd-defpose/--hd-parents` 切換至備用方案`invBind = PMatrix4[52+b]`
    (原始 LOCAL 陣列) → 網格爆裂。depose+parents 的做法是解決方案，且 **已是畫廊的預設設定**。
  - 新的唯讀探測器：`work/_scratch_mgrp/phyre_palette_probe` (定位調色盤、驗證精確綁定、發出
    `node_to_slot.json`) 以及`phyre_legs_probe` (配對器；說明因「巧合對應」而陷入婚姻陷阱的情況)。
### 已驗證
- **畫面決定（F3D）：** 全隊成員的雙腿皆呈現 **結實且線條俐落** 的狀態 — c001（提達斯）、c005（瓦卡）、c007（莉庫） —
  在強制休息狀態、戰鬥中（id5_c4318 t0.0–0.9），蹲姿下有 4 個小腿角度，並採用多點剪輯（c4333/c4365/c4886）。
  數值設定：腿部關節的位置/世界座標 = 完美剛體（比例=1，細度=+1，正交 0.0000）。無 IDA。
  完整測試請見`docs/reverse/FFX_HD_SKIN_PALETTE_DECODED_LEGS_NOT_BIND_2026-06-05.md`.

## [v2.4.3] - 2026-06-05
### 新增
- **寫入完整性閘波（核心表格）** — 4 個新的 RT0 無頭閘波，用於驗證那些
  原本存在但從未經過位元組閘控的寫入器，並關閉了可編輯實體資料庫中的 4 個家族：
  -`--keyitem-rt0` (`Tools/KeyItemRt0`) →`KeyItem_File` (**important.bin**)，寫入器僅保留原始內容（複製
    原始位元組 + 僅重新標記`PrimerByte10`/`OrderingByte13`).
  -`--treasure-rt0` (`Tools/TreasureRt0`) →`Treasure_File` (**takara.bin**)，往返完整解碼（每筆記錄 4 位元組）。
  -`--customization-rt0` (`Tools/CustomizationRt0`) →`Customization_File` gear **kaizou.bin** + aeon **sum_grow.bin**
    （保留標頭的前綴／尾碼，並重新發送已解碼的條目）。
  -`--autoability-rt0` (`Tools/AutoAbilityRt0`) →`AutoAbility_File.WriteAbilities` (**a_ability.bin**，
    「資料」區段)，寫入器僅保留。 (讀取`arms_rate.bin` 純粹為了履行合約；請勿寫上「arms_rate」或收取費用
    `WriteAbilitiesAndText`/文字重新封裝。)
### 已驗證
- **RT0 位元組完全一致 4/4**，與原始檔案相比（`jppc/battle/kernel/`): important.bin（64 筆記錄，3674 B），
  takara.bin（503 筆記錄，2012 B）、kaizou.bin（125）＋ sum_grow.bin（77）、a_ability.bin（134 筆記錄，19590 B）。
  **不編輯儲存 = 位元組完全相同；編輯 = 局部位元組**（與關閉 Monster/Encounter 時相同的「僅保留」標準）。
  部分解除了歷史上的限制「important.bin/a_ability.bin 因變異安全寫入者聲索而被封鎖」：
  字段（資料區）的編輯現已通過驗證；**文字池的重新封裝仍未被聲索** （同樣
  存在 monmagic 漂移的風險 — 此問題不在本次更新範圍內）。

## [v2.4.2] - 2026-06-05
### 新增
- **陣型編輯器 — 「誰在何處作戰」**：戰鬥清單現在會顯示 **陣型標籤（怪物）**
  並以每場戰鬥為單位內嵌顯示（例如：`[m003 - Murussu, m003 - Murussu, m009 - Dingo]`). Lazy + 快取 + cap（≤90 場可見戰鬥
  ；當清單滿時會提示按區域篩選）。唯讀模式；在編輯器中實現總體規劃中的「該區域會生成
  的怪物」功能（遭遇戰↔可見佈局之整合）。

## [v2.4.1] - 2026-06-05
### 新增功能
- **`FormationSlotWriter`** (`FfxLib/Battle`) — 從訓練資料中提取的 SAVE 位元組安全路徑，用於
  **Avalonia-free** 生產輔助程式（僅儲存槽 + 僅備份一次）`.spiraforge.bak` + 寫入）。目前由 Formation
  Editor 使用（`PersistSnapshot`) **並**透過無頭 Gate 進行測試 — 邏輯去重，編輯器與測試中的程式碼完全相同。
### 已驗證
- **`FormationSlotLab` — SAVE LIFECYCLE 檢查**（在 **TEMP** 副本中建立產出路徑，不觸及工作區／資產，
  並維持唯讀狀態)：(a) 非編輯儲存 = 磁碟內容位元組完全一致 + 備份==原始檔；(b) 編輯儲存 = 僅在
  磁碟上建立槽位 + 重新讀取比對 + 備份完整保留；(c) 從備份還原 = 位元組完全一致。 **通過。** 彌補了 v0.2 的
  誠實缺口（已驗證應用程式內儲存至磁碟，且可逆）。資料集維持 **858/858**；`offline_ci` 4 個閘門通過。

## [v2.4.0] - 2026-06-05
### 新增
- **`EncounterTable_File.Rebuild`**（結構性）— 與`Write` slot-only：根據
  Entries/Groups/Formations（可變計數 + 建立表格）重新發送 chunk1，指派新的 dataOffsets，重建
  chunk0 及 chunk-table，並保留 **block-sharing** 及 padding。 Gate`--encounter-rebuild-rt0`. **從結構上
  「創造相遇」為基礎。**
### 已驗證
- 重構相遇 (`btl.bin` 96 張表 / 192 組 / 863 種編組)：**不可編輯 RT0 位元組完全相同
  (4096/4096)** + 擴充測試（新增 1 個編組，起始位址 0x1000→0x1002，2 個區塊完整無損）**有效**。
- **TextTable 字段字串寫入器 已認證** (`spcodedic.bin` 16/16 RT0) — 解鎖該家族`TextTable_File`;
  修正了 **trailing padding** 的漂移問題。誠實說明：相關記錄的`help_txt.bin` 在 StringExplorer 中，
  此次擷取中顯示為「已消失」（檔案不存在）——該寫入器已在實際字串欄位中經過驗證（`spcodedic.bin`).

## [v2.3.2] - 2026-06-05
### 新增
- **AbilityCommandLab** (`RuntimeTools/AbilityCommandLab`) — 能力寫入器的 RT0 閘口
  (`Ability_Command.ReadList`→`WriteList`)，該`KernelCommands` 雖然已經用來儲存資料，但從未經過位元檢查。
  參考編輯器的專案（依賴繁重的樹狀結構），僅呼叫 FfxLib 的靜態方法。整合於`offline_ci.ps1`.
### 已驗證
- **command.bin + item.bin (JP+US)：經認證的字節安全寫入程式** — RT0 字節完全相同 4/4 + 1 旗標版本
  定位（1 位元組）4/4。**通過。** 這是夢幻功能「新黑魔法」（位於 command.bin 中）的已驗證基礎。
### 被封鎖
- **monmagic1/2 (JP+US)：寫入器 DRIFTA** (RT0 0/4 — 文字檔案重新封裝後膨脹至 ~3–4KB，firstDiff`@0x1C`). 原因：
  monmagic 的原始版本會對文字進行 **共享／去重**，而`WriteList` 重新附加 (`FfxEncoding.WriteBytesIntoTextFile`
  只執行 append；command/item 都是純粹的 append → 相容)。**風險：** MonMagic 的 Save 在`KernelCommands` 擴充
  檔案 — 等待支援去重功能的 Writer 處理完成。稽核 + 修正目標：`docs/reverse/FFX_ABILITY_WRITER_AUDIT_2026-06-05.md`.

## [v2.3.1] - 2026-06-04
### 新增功能
- **Battle_File 讀取器的穩定性** —`Battle_File.Read` 現在開啟那 15 個 btl_*，其尾部區塊指向
  EOF 之後（`kino03_*`,`mihn05_*`,`cdsp00_02`): 將 past-EOF（及之後）的片段視為缺失，而非
  拒絕整個檔案；之前的片段（包括 @2 編組）仍保持有效。這些戰鬥現已可在
  編組編輯器中進行編輯。
### 已驗證
- Gate`FormationSlotLab`: writable 從 843 上升至 **858/858**（0 次讀取失敗）；RT0 858/858 + 僅插槽
  858/858 + 重新讀取 858/858 **通過**。 先前的 843 個仍保持完整。

## [v2.3.0] - 2026-06-04
### 新增功能
- **SPIRA FORGE v0.2 — 陣型編輯器** (`Modules/FormationEditor`): 該樞紐的首位編輯者。透過以下方式替換 btl_* 陣容中的 8
  隻怪物（16 位元組）：`Battle_File.WriteWithFormationSlots`, **字節安全且僅限插槽**。
  吞噬脊椎`FieldContext` （根據在 Hub 中選定的戰場區域預篩選對戰）。怪物選擇器
  （`Monster_Dictionary` + 空值，保留原始資料的高位半字節）。Save 會將鬆散檔案寫入工作區並進行備份
  `.spiraforge.bak` + 守護`AssertSlotOnlyDiff`，來源：`ByteSnapshotEditorSession` (撤銷/捨棄)。離線，無探針。
- **Gate RT0 無頭模式**`RuntimeTools/FormationSlotLab` （僅連結無依賴項的生產環境檔案），
  連接至`offline_ci.ps1` (暫停`-BtlRoot`). 附加的唯讀成員在`Battle_File`
  (`FormationChunkOffset`/`FormationSlotsOffset`/`FormationSlotsLength`).
### 已驗證
-`FormationSlotLab` 在語料庫中`btl`: RT0 843/843 + 僅插槽 843/843 + 重新讀取 843/843 **通過**（寫入端位元組安全）。
  （當時有 15 個 btl_* 無法被讀取器解析 — 已於 v2.3.1 修正。）

## [v2.2.0] - 2026-06-04
### 新增
- **SPIRA FORGE 第 0 階段 v0.1 — Field Hub** (`Modules/SpiraForgeHub` +`Services/FieldContext.cs`): 導覽
  欄由`field_token`. 由 CSV 橋接器驅動的欄位選擇器
  (`ps3data-map-btlmap-fieldid-bridge.csv`, 357 個欄位，**structural-candidate**)。從中選取一個已發佈的欄位
  `FieldContext` (可觀察單例) 以及 2 個唯讀消費者：**深度連結地圖**
  (`?map=map/<area>/<field>` （適用於 FFXMapViewerWeb）+ **遭遇預覽**（讀取`btl.bin` 來源`EncounterTable_File`,
  join 候選區域↔地圖)。透過 csproj 將 CSV 檔案複製到輸出位置`<Content>`. 離線；選取器在無專案的情況下仍可運作。
  無寫入器，無探測器。
### 已驗證
- 建置無錯誤；已於螢幕上驗證（欄位`azit03` → 選項器 + 深度連結 + 透過 btl.bin 中的實際資料預覽互動情境。
  螢幕截圖`work/spira_forge_qa/field_hub_v01.png`.

## [v2.1.1] - 2026-06-04
### 已驗證
- **PlayerKernel 寫入器** (`PlayerKernel_File.WriteSave`/`WriteRom`) 透過新閘門以「位元保真」方式進行測試
  `--player-rt0`:`ply_save.bin` (3098) +`ply_rom.bin` (2161) -> **不可編輯的 RT0 位元組相同**。（這些寫入器
  原本即為「僅插槽」類型；現在則被**鎖定**。）

## [v2.1.0] - 2026-06-04
### 新增
- **EncounterTable 寫入器** (`EncounterTable_File.Write`) — 唯讀 → 讀寫 **僅插槽**：保留
  `btl.bin` 逐位元組處理，並僅對可編輯欄位重新加蓋標記（table`Id`/`Unknown0C`, 群組
  `Battlefield`/`Danger`/`TotalWeight`, 培訓`Id`/`Weight`). 閘門`--encounter-rt0` 在編輯器中。
### 已驗證
-`battle/kernel/btl.bin`: 96 張表格 / 192 組 / 863 種編制 -> **不可編輯 RT0 位元組完全相同 (4096/4096)**。

## [v2.0.0] - 2026-06-04

> **新紀元 — 重大更新。** 編輯器已從「離線檔案編輯」躍升至 **即時執行時編輯
> 已實證**：在 RAM 中編輯怪物的 AI 位元組碼，並在 **螢幕上** 即時觀察行為變化，不會導致當機，
> 且可逆 — 專案的 **首要目標 #1** 已實現。 重大更新 = 新的 **功能層級**（並非
> 破壞合約／儲存檔／建置 — 我們只是新增並強化了功能）。`-beta` 因為 RT2/God-Mode 尚未
> 在具備閘門功能的 UI 中實現。**Claude Code / VSCode 結合第二個 Codex 帳戶** 的里程碑。

### 重點
- 🏆 **RT2 即時 AI 編輯 螢幕實測：** 在 RAM 中即時編輯怪物 AI 位元組碼（DINPUT8 探測），
  螢幕上的行為隨之改變 — **Flame Flan Firaga→Thundaga**，無當機，且可逆。鏈：`enemy-list`
  (`0xD34460`) →`MemoryChr.Ptr_script_chunks` (`+0xF78`) → AiFile 線上版 **===`m0NN.bin` 來自字節完全相同的磁碟**。
- 💉 **將任意能力注入任意怪物（實機）：** id 為`performCommand` =`(cat<<12)|abilityId`
  觸發全域技能——怪物無需「擁有」該技能。 證據：**斯柯爾在螢幕上吐出了伊弗利特的地獄之火**。
- 🐉 **即時敵人編輯：**將怪物轉變為 **黑暗濕婆**（ID + 實際屬性 + 110萬/400萬生命值），
  **自動掃描**、**骰子復活**（死亡標記 + KO），全部透過`MemoryChr` + 探針。

### 新增
- **AI Assembler** —`AiScript_File.AppendCode`: 附加指令並 **重新定位所有
  資料區段** 的偏移量 (+delta) → 較大且有效的 AiFile（通往「新增 IA」的路徑，超出字節本地預算）。
- **AI 控制流程編輯器**（float/int const + 跳轉目標），字節本地，位於`AiScript_File`.
- **模組`Monster AI Editor`** (Avalonia)：帶註釋的彙編程式（147 次呼叫 + 73 個欄位 + 浮點數 + 變數 +
  跳轉標籤 + 推斷出的工作執行緒類型），操作數編輯 + 儲存獨立檔案。
- **`FfxProbe_Service`** — bridge 編輯器↔probe DINPUT8（在主執行緒中進行 READ/WRITE/CALL，支援 ASLR）。
- mod/RE 文件：`FFX_AI_RT2_LIVE_EDIT_PROVEN`,`FFX_LIVE_INGAME_EDITOR_MOD_IDEA` （戰鬥之神模式），
  `FFX_MUSIC_SYSTEM_AND_MOD_IDEA` (Music Remapper)，`FFX_AI_BYTECODE_OPCODE_TABLE_PROVEN`,
  `CODEX_MAPVIEWER_WATCH_JARVIS`,`FFX_MAP_DEVELOPMENT_TOOL_MASTERPLAN` (Spira Forge)。

### 已修改／已驗證
- **`Monster_File.Write` 已修復 → 閘門`--monster-rt0`: 361/361 位元組完全相同**（原先為 0/361）：
  僅在 StatSheet/Loot 中保留資料，並保留標頭的 Signature/Padding（Padding 部分曾與`AiFile[0..3]`).
- **AI 編解碼器`AiScript_File`**: RT0 361/361 + oracle-parity 反編譯 + 離線 CI (`offline_ci.ps1`).
- VM ATEL 已寫入／儲存至 IDA（`FFX_Atel_*`,`g_FFX_Atel_VmContext`, 由演員處理、FMOD 播放器)。

### 阻塞／延遲（老實說）
- **即時 3D 模型／視覺重現** = model-viewer 通道（Codex）；標誌`MemoryChr` 不會重新渲染。
- **即時切換音樂** = FMOD API 是`__thiscall`, 探測函式僅支援 cdecl → 探測函式中需使用 op thiscall
  （在關閉遊戲的情況下重新編譯）。已找到玩家：`FFX_FmodMusic_PlayTrackByIndex` (181 軌)；PS2 的 FIFO SPU 為硬碟上的 stub。
- **載入大型能力** 若未先載入相關資源，可能會 **導致遊戲當機**（Dark Ifrit 的 Hellfire 讓遊戲當機）。
- **God Mode 模組** = 現場測試已證實有效，但尚未在帶有門檻的 UI 中正式實裝。

### 源自 Labs / 多代理
- Arco **Claude Code / VSCode**（AI 編輯器活動：ATEL 編碼 100% 解碼 → RT2 即時）結合
  **與第二個 Codex 帳戶的協作**（MapViewer 通道 / 模型-貼圖）：匯出器揭露材質角色訊號
  （TextureSampler1/normalMap/reflection/water/PhyreWaterShader），並透過外部檢視器
  （以**glTF-Sample-Viewer**作為參考標準；已證實差距源自匯出端，非殼層），並啟動總體規劃
  **Spira Forge**。多代理協調於`docs/ai/CODEX_MAPVIEWER_WATCH_JARVIS.md`.

## [v1.7.0] - 2026-06-04
### 新增功能
- **AI Assembler（100% 自由編輯 AI）** — 兩個基本元件在`AiScript_File`:
  - **`AppendCode`**：在文末附上說明 + 重新排列資料區段。
  - **`Rebuild`**：**可在**任何位置**插入／移除／編輯指令**，並自動重新定位所有
    **跳轉指令＋進入點**（連結器 old→new）以及資料區。 孤立分支（指令已移除）→ 誠實錯誤。
### 已驗證
-`m337` (Dark Shiva)：**no-edit Rebuild = 位元組完全相同 (RT0)**；插入中間 ->`codeLen +3`, walk 關閉，
  工作線程解決，**插入後的入口點已重新定位`0x2D1`→`0x2D4` 單獨**；grow-test (AppendCode) RT0。

## [v1.6.0] - 2026-06-04
### 已驗證
- **`Monster_File.Write` 已修復 -> 閘門`--monster-rt0`: 361/361 位元組完全相同**（原先為 0/361）：僅保留
  於 StatSheet/Loot 中 + 保留`Signature`/`Padding` 來自頁首（內邊距產生了重疊）`AiFile[0..3]`).

## [v1.5.0] - 2026-06-04
### 已驗證 / 已封鎖
- **RE'd 音效系統：** FMOD 播放器 **`FFX_FmodMusic_PlayTrackByIndex`**（181 首曲目）已找到；**現場
  音樂 已鎖定**（API`__thiscall`, 僅支援 cdecl 的函式)。文件`FFX_MUSIC_SYSTEM_AND_MOD_IDEA` (Music Remapper)。

## [v1.4.0] - 2026-06-04
### 已驗證（線上）
- **跨怪物能力注入已證實：**`performCommand` id =`(cat<<12)|abilityId` 觸發該能力
  全球性 — 怪物無需「擁有」。證據：**斯科爾在螢幕上吐出了伊弗利特的地獄之火**。

## [v1.3.1] - 2026-06-04
### 已修正／已驗證（正式上線）
- 透過以下方式對敵人進行實際治療：`Hp@0x5D0` (不`Current_hp`); **KO** 的清理 (`Status_suffer`); 根據資料復甦
  （精細化處理）（死亡標記）。**自動掃描**（狀態`Scan`) 已上線。

## [v1.3.0] - 2026-06-04
### 已驗證（上線）
- **將敵人轉化為暗黑濕婆** 已上線：`Id` + 實際數據來自`m337` + **1.1M/4M HP**，來源：`MemoryChr`
  (`POINTER_BATTLE_ENEMY_LIST 0xD34460`, stride`0xF90`) + probe.

## [v1.2.0] - 2026-06-04
### 新增
- **模組`Monster AI Editor`** (Avalonia)：帶註釋的反彙編器（147 次呼叫 + 73 個欄位 + 浮點數 + 變數 +
  跳轉標籤）+ 操作數編輯 + 儲存獨立檔案。
- **AI 控制流程編輯器**（常量浮點數/整數 + 跳轉目標），位元組級。
- **`FfxProbe_Service`** — bridge 編輯器<->probe DINPUT8（在主執行緒上進行 READ/WRITE/CALL，支援 ASLR）。

## [v1.1.0] - 2026-06-04
### 已驗證 (🏆 頭條 — 首要目標 #1)
- **RT2 即時 AI 編輯 螢幕上已驗證：** 怪物 AI 的字節碼在 **即時 RAM** 中進行編輯（DINPUT8 探測）→
  畫面行為發生變化（**Flame Flan Firaga→Thundaga**），無當機，且可逆。鏈接：`enemy-list
  0xD34460` -> `MemoryChr.Ptr_script_chunks +0xF78` -> AiFile vivo **=== `來自字節級精確複製磁碟的 `m0NN.bin`**。
  文件：`docs/reverse/FFX_AI_RT2_LIVE_EDIT_PROVEN_2026-06-04.md`.

## [v1.0.0] - 2026-06-01

編輯器作為真正的閱讀、驗證與知識瀏覽平台的成熟里程碑，具備`Extras` 足以證明一個`1.0` 坦率地說，即使不假裝運行時、AI 和身體播放等問題都已解決。

### 重點
- 編輯器不再僅僅是一組領域編輯器，而是同時成為一個整合式平台，用於`read-only exploration`.
- 那條線`Extras` 目前涵蓋殼牌的六大業務領域：
  -`PS2 Knowledge`
  -`Textures (TM2 + TXC/CLT/FMT/SPS2 support lane)`
  -`BIN-FTC Atlas`
  -`Project / Pipeline`
  -`Magic Effects`
  -`Presentation Containers`
  -`Battle Corpus Crosswalk`
- 該專案目前已具備足夠的閱讀資料／圖鑑／來源資訊，足以被視為`1.0` 將編輯器作為驗證平台。

### 新增
-`Pt67` 像……一樣`Extras / Magic Effects`，內容如下：
  -`MagicPackageViewer`
  -`BatEffPackageViewer`
  -`MagicEffectCrosswalkExplorer`
-`Pt57` 像……一樣`Extras / Presentation Containers` 至`.vpa/.ebp/.omd/.sps2`.
-`Pt44` 像……一樣`Extras / Battle Corpus Crosswalk` 至`formation -> actor row -> corpus`.
- 擴展`Pt52` 包含：
  -`FtcHeaderInspector`
  -`BinSidecarGraph`
  -`Signature Group` 在 shell 中
- 展開`Pt56` 包含：
  -`TxcCltPairExplorer`
  - 來自的冷元數據`fmt` 以及`sps2`
-`docs/history/PS3DATA_CHECKLIST_MASTER_2026-06-01.md` 作為樹狀結構的主檢查清單`ps3data`.
-`docs/history/EDITOR_READONLY_ABSORPTION_REPORT_2026-06-01.md` 作為一份清單，列出所有可能或不可能變成「僅讀取」介面的項目。

### 變更
- 應用程式版本已升級至`1.0.0`.
- o`PS2 Knowledge` 現在，註冊表本身便反映出`Pt44`,`Pt57` 以及`Pt67`.
- 控制措施`Extras` 在新表面上，捲軸的根部處理更為精緻，命名也更為準確。
-`PORT_STATUS.md`,`KNOWLEDGE_BASE.md` 以及`docs/history/README.md` 現在他們已正式承認「wave」`1.0`.

### 已驗證
- 建置`Release` 隨著浪潮而過`1.0.0`.
- 那條線`Extras` 接著明確指出：
  -`read-only`
  -`do not promote`
  -`no runtime proof` 在適當之處
  -`pipeline/support only` 適當時

### 註解
- 這個`1.0` 這代表該編輯平台在閱讀與驗證方面的成熟度。
- 這個`1.0` 這並不表示：
  -`magic solved`
  -`AI solved`
  -`ModelViewer playback solved`
  - writer 全面釋出

## [v0.11.0-beta.2] - 2026-06-01

產品線的實質演進`Extras` 在`main`.

### 重點
-`Extras` 在編輯器中，它不再只是平面，而是變成了一個活生生的表面。
- 殼層現在能識別伴隨的根節：
  -`master`
  -`ffx_ps2`
  -`ps3data`
- 首批唯讀版 PS2 產品現已顯示於使用者介面中：
  -`PS2 Knowledge`
  -`Textures (TM2)`
  -`BIN-FTC Atlas`
  -`Project / Pipeline`

### 新增
- 共享基礎`Extras`:
  -`ExtrasSourceResolver`
  -`ExtrasEvidenceBadgeModel`
  -`ExtrasProvenanceModel`
  -`ExtrasReadonlyBoundaryModel`
  -`ExtrasFileOpenService`
-`Extras / PS2 Knowledge` 作為 PS2 活動的唯讀樞紐。
-`Extras / Textures (TM2)` 作為該作品的第一個真實視覺呈現`Pt56`.
-`Extras / BIN-FTC Atlas` 作為的唯讀瀏覽器`Pt52`.
-`Extras / Project / Pipeline` 作為的初始表面`Pt54`，內容如下：
  -`CdIndexExplorer`
  -`ProjectDescriptorViewer`
  -`AbmapSupportGraph`
- 按工作坊／檔案類別新增指南，以`ffx_ps2`:
  -`docs/history/PT52_BIN_FTC_FILE_MEANING_GUIDE_2026-06-01.md`
  -`docs/history/PT53_BATTLE_MAGIC_FILE_MEANING_GUIDE_2026-06-01.md`
  -`docs/history/PT54_PROJECT_ABMAP_FILE_MEANING_GUIDE_2026-06-01.md`
  -`docs/history/PT56_TEXTURE_PALETTE_FILE_MEANING_GUIDE_2026-06-01.md`
  -`docs/history/PT57_PRESENTATION_CONTAINER_FILE_MEANING_GUIDE_2026-06-01.md`
  -`docs/history/PT58_FFX_PS2_OWNERSHIP_AND_LINKAGE_GUIDE_2026-06-01.md`

### 變更
- 應用程式版本已升級至`0.11.0-beta.2`.
-`Pt54` 不再只是`implementation-ready` 並以實數模數的形式進入了 shell`Extras`.
-`Pt58` 現在在軟體中，它不僅僅是一個概念，更是一個可導航的樞紐，具備徽章、來源及唯讀邊界等功能。
-`KNOWLEDGE_BASE.md` 以及`docs/history/README.md` 現在已將新的冷藏指南納入索引，該指南來自`ffx_ps2`.

### 已驗證
- 編輯器的 Release 版本已通過新模組的`Project / Pipeline`.
- 那條線`Extras` 仍維持唯讀狀態並被保存：
  - 無寫入器
  - 無重新封裝
  - 無最終解碼聲明
  - 未將冷研究與執行時證明混為一談

### 備註
-`Pt53` 依然是魔法軸線上的帥氣老大：
  -`kernel -> mag_* -> bat_eff`
-`Pt55` 仍降至附著於護欄的`Pt9`.
-`Pt57` Atlas Cold 仍屬重要版本，但尚未進行深入的解碼分析。

## [v0.10.0-beta.1] - 2026-05-31

此為整合版 Beta 版本`main` 在第一波強勁的車間收購熱潮平息之後。

### 重點
-`Shop Explorer` 透過目錄、真實圖像以及以保守風格剪輯保存的文字，正式進入主流。
-`RuntimeTools/StepBridgeLab` 以及`RuntimeTools/RuntimeInspectorLab` 作為獨立工具被導入，不會干擾 shell 的啟動過程。
-`ProductionSafetySmoke` 不再隱瞞問題家庭的情況，而是開始證明`Read`,`No-Edit Byte Identity` 以及`Reread` 至`important.bin` 以及`a_ability.bin`.
-`README` 目前公開的螢幕截圖已反映出當前的 shell`main`，並非從車廠繼承而來的舊車。

### 新增
- 吸收`Pt8 / ShopAndWeaponNameResearchLab` 在：
  -`Shop Explorer`
  -`FfxLib/Shop`
  -`Assets/Shop`
  - 由 撰寫者 儲存於`item_shop.bin` 以及`arms_shop.bin`
- 吸收`Pt12 / StepBridgeLab` 在`RuntimeTools/StepBridgeLab`;
- 吸收`Pt13 / RuntimeInspectorLab` 在`RuntimeTools/RuntimeInspectorLab`;
- 吸收`Pt17 / SaveSafetyLab` 在`ProductionAuditTools/ProductionSafetySmoke`;
- 吸收來自`Pt21 + Pt22` 在：
  -`NameDescriptionTextPrefixTable_File`
  -`reader + no-edit guard` 至`important.bin`
  -`reader + no-edit guard` 至`a_ability.bin`
-`docs/history/PT21_PT22_READER_NOEDIT_GUARDS.md` 作為此片段的生產決策記錄；
-`ReadmeAssets` 已更新至`6` 當前版本的可追蹤截圖。

### 變更
-`KeyItemEditor` 已公開重新分類為`Guarded`，重點在於結構性審閱及保證不進行編輯；
-`AutoAbilityEditor` 已公開重新分類為`Guarded`，同樣秉持保守立場；
-`PORT_STATUS.md` 以及`docs/history/PRODUCTION_ABSORPTION_MATRIX.md` 現在已明確區分`reader + no-edit guard` 來自`writer-safe`;
-`README` 針對當前的 shell，已重新聽取意見`main`;
-`CHANGELOG` 以及`changelogUS` 開始反映主線進入新的鞏固階段。

### 已驗證
-`Shop Explorer` 以及其儲存的剪圖，如今已成為該網站官方版面的組成部分`main`;
-`StepBridgeLab` 以及`RuntimeInspectorLab` 作為獨立工具被納入主樹中；
-`ProductionSafetySmoke` 開始展出`important.bin` 以及`a_ability.bin` 結構讀取正確，且字節標識未經編輯；
- 該`README` 《publico》現在描述這款經過全面升級的 Windows Surface 裝置`main`;
- 所有螢幕截圖皆儲存於`README` 來自當前的 shell，而非舊的工坊材料。

### 延遲
-`Pt16 / Slice 1` 目前仍在專屬分支中準備就緒，但尚未納入`main`;
-`Pt14` 以及`Pt15` 這些仍作為執行時／除錯／架構方面的實用功能保留，但在本次發行版中並未實際整合相關程式碼；
-`AI Probe` 以及`Pt6 / BattleStructureLab` 這些仍屬優先事項，但尚不足以作為在執行時/AI 方面提出更高版本要求的依據。

### 受阻
-`btl_txt.bin` writer 和 encode 仍處於被封鎖狀態；
-`w_name.bin` 對「公開作者」仍處於封鎖狀態；
-`Field String` 在應用程式中仍處於鎖定狀態；
-`important.bin` 以及`a_ability.bin` 對於作家公開聲稱的「突變安全」仍被封鎖；
- 區間預言機的結果為`Pt22` 不允許僅憑「writer」一詞進行宣傳；
-`Repeat Exact Encounter` 而運行時／AI 領域的重量級項目，至今仍未能真正進入廣泛推廣的階段。

## [v0.9.0-beta.1] - 2026-05-31

這是第一個真正反映編輯器及其周邊生態系統實際規模的版本。

### 主分支重點
- 正式記錄了`main` 像……一樣`v0.9.0-beta.1`;
- 保留並進行版本管理的私有 Git 基準線；
-`PORT_STATUS.md` 成為生產吸收的動態帳本；
-`docs/governance/` 整合工作流程、版本控制及下一項工作任務；
-`docs/history/` 整合登錄檔、分支地圖、時間軸及吸收矩陣。

### 主資料庫中存在的生產資料庫
-`Monster Editor`;
-`Battle Explorer`;
-`Sphere Grid Explorer`;
-`Sphere Grid Editor v1`;
-`Encounter Table Explorer`;
-`Monster AI Explorer`;
-`String Explorer` 使用安全的寫作工具來`Monster Localizations 1/2/3`;
-`Live Battle Lab`;
-`PlayerGrowthEditor`;
-`CtbBaseEditor`;
-`MixTableEditor`;
-`KeyItemEditor`;
-`AutoAbilityEditor`;
-`Shop Explorer` 附有已儲存的切片，來自`Shop`.

### 從工作坊中汲取的啟發
-`Pt3 / TextLab`
  -`TextLabTools`;
  -`ProductionAuditTools`;
  - 文字／怪物類的保守型束縛與釋放機制。
-`Pt5 / KernelTablesLab`
  -`PlayerGrowthEditor`;
  -`CtbBaseEditor`;
  -`MixTableEditor`;
  - 支撐此觀點的歷史脈絡`KeyItemEditor`.
-`Pt7 / AutoAbilityLab`
  -`AutoAbilityEditor`;
  - 保守的解析器`AutoAbility_File.cs` 以及`Arms_Rate.cs`.
-`Pt8 / ShopAndWeaponNameResearchLab`
  -`Shop Explorer`;
  -`FfxLib/Shop`;
  -`Assets/Shop`;
  - 儲存的作家來自`item_shop.bin` 以及`arms_shop.bin`.

### 治理與版本控制
-`docs/history/PT_VERSIONING_REGISTRY.md`;
-`docs/history/PT_BRANCH_MAP.md`;
- 精選版迷你版`Pt2` a`Pt20`;
- 按工作坊劃分的历史標籤；
- 針對生產環境定義的分支／提交／變更日誌政策。

### 已驗證
- 的私有基準`main` 以……名義發布`baseline-2026-05-31`;
- 音訊在`Git LFS` 在`FFXProjectEditor/Assets/Audio/**`;
- 建置`Release` 主線；
- 部分吸收`Shop` 已透過保守性切片進行技術驗證；
-`AutoAbilityEditor` 已透過保守型閘門進行驗證；
- 文字工具包及安全截取功能，用於處理已作為生產線處理的巨型字串。

### 仍被阻擋
-`btl_txt.bin` writer/serializer/encode;
-`Field String` 作家；
-`w_name.bin` 作家；
- 盲端口來自`LiveBattleLab`,`MemSharp_Service.cs` 以及`MemoryBtl.cs` 來自 labs；
-`ModelViewer v2` 作為最終觀眾；
- 推廣`Repeat Exact Encounter` 彷彿已經被證實了一樣。

### 為何這仍處於測試階段
-`Pt6 / BattleStructureLab` 仍屬強有力的觀察性證據，尚未形成明確的結論；
-`Pt9 / ModelViewerLab` 目前仍未確定最終的靜態視口；
-`Pt12` a`Pt20` 目前仍在完善工具、強化、策略與治理；
- 運行時、人工智慧與記憶體等主要領域，目前仍在實際整合中。

## 歷史語義重建

重要編輯註：

- 以下條目記錄了歷史演進歷程`v0.1.0` a`v0.8.0-beta.1` 作為該專案的整合版本；
- 它們並不對應於實際的舊版 Git 標籤；
- 它們的存在，是為了不掩蓋這樣一個事實：即該編輯器早已遠大於一個`v0.1.0` Git 剛加入時的字面值；
- 用於搭建這座梯子的依據來自`PRODUCTION_V2_HANDOFF.md`,`FFX_PRIORITY_BUILD_MANIFEST.md`,`PORT_STATUS.md`,`PROJECT_HISTORY_MASTER.md`,`WORKSHOP_TIMELINE.md`,`PRODUCTION_ABSORPTION_MATRIX.md`,`PT_VERSIONING_REGISTRY.md` 以及各工作坊的交接事項。

## [v0.8.0-beta.1] - 歷史重構（Git 官方 SemVer 之前）

此階段的生態系統已運作為一個大型、模組化的編輯器，並同時擁有多個活躍的專業分支。

### 現階段的主要介面
-`Monster Editor`;
-`Battle Explorer`;
-`Sphere Grid Explorer`;
-`Sphere Grid Editor v1`;
-`Encounter Table Explorer`;
-`Monster AI Explorer`;
-`String Explorer` 並設有安全的步道，從`Monster Localizations`;
-`Live Battle Lab`;
- 強大的核心產品線，包含`PlayerGrowthEditor`,`CtbBaseEditor` 以及`MixTableEditor`.

### 生態系統壓力
-`Pt2 + Pt9` 放置`ModelViewerLab` 已達到真正的偵察與交接的嚴肅層級；
-`Pt8` 關閉`Shop` 作為預備招式，能確實地進行防守與封鎖`w_name.bin`;
-`Pt6` 已經能駕馭關於`runtime + AI + proof`;
- 這款作品已不再只是「又一款遊戲發行商」，而是發展成一個遠超社群標準的模組生態系統。

### 仍未實現
-`ModelViewer v2` 作為最終視口；
-`Repeat Exact Encounter` 已驗證；
-`w_name.bin` 作家；
-`btl_txt.bin` 功能強大的寫入器；
- 流暢整合大型執行時工具。

## [v0.7.0] - 歷史版本重建（Git 正式 SemVer 規範實施前）

主線從「更多模組」轉變為「更多測試」的轉折點。

### 新增
-`BattleStructureLab` 成為舊版 Wave 中技術難度最高的車間；
-`BattleRuntimeProbe`, 序列監控器與選擇器／銀行的篩選成為討論的核心；
-`Force Battle / Repeat Encounter` 不再只是「一廂情願的幻想」，而是被視為一項真正的觀察性實驗。

### 變更
- 官方的優先順序轉向`runtime + AI + proof`;
- 製作方現已明確承認，重播功能目前仍存在更多`Repeat Route (Unsafe)` 比……更……`Exact Encounter`;
- 專案的風險表述趨於嚴謹。

### 尚未安全
- 盲合併自`runtime/memory`;
- 精準重播功能；
- 車間總運費`Pt6` 前往`main`.

## [v0.6.0] - 歷史重構（Git 官方 SemVer 規範實施前）

此版本標誌著核心開發線與次要系統的保守強化，已不再僅是承諾，而是成為嚴謹發行版的正式組成部分。

### 新增功能
-`AutoAbilityEditor` 以保守的閘控策略發展成獨樹一幟的路線；
-`KeyItemEditor` 進入實際吸收範圍；
- 生產已能與`Customization / Aeons` 以及其他再平衡區塊。

### 變更
- 配置策略不再是「複製自實驗室」，而是轉為「吸收經過驗證的片段」；
- 諸如`62h..67h` 將繼續保留`raw/read-only` 而非採用杜撰的語義；
- 核心分支不再屬於實驗性質，並將採用更嚴格的編輯標準。

### 仍未解決
-`Shop` 誠實的作家；
-`w_name.bin` 安全；
- 足以應對下一波浪潮的強大執行時儀器化功能。

## [v0.5.0] - 歷史重構（Git 正式版本控制之前）

強勢浪潮的里程碑`KernelTablesLab`.

### 新增
-`PlayerGrowthEditor`;
-`CtbBaseEditor`;
-`MixTableEditor`;
- 成熟的步道，長度為`KeyItemEditor`;
- 初始就緒狀態為`Auto-Abilities`,`Item Shop / Gear Shop` 以及`w_name.bin`.

### 變更
- 編輯器不再僅依賴戰場／怪物表面，而是具備了真正值得信賴的核心層；
- 模組平衡調整的重要部分，現已可在專屬使用者介面中實現；
- 製作流程奠定了基礎，未來將能更精準地整合各項功能。

### 仍未實現
- 最終驗證`Auto-Abilities` 在生產過程中；
-`Shop` 身為保守派作家；
- 可靠的語義學用於`w_name.bin`.

## [v0.4.0] - 歷史重構（Git 正式版本控制規範實施前）

此版本標誌著專案開始能夠根據實際判斷，在文字中學會說「是」與「否」。

### 新增功能
-`TextRegressionHarness` 作為回歸訓練；
- 安全的閘門通往`Name / Description`;
- 安全閘門通往`Monster Localizations 1/2/3`;
- 後續將發展為`TextLabTools` 以及`ProductionAuditTools`.

### 變更
- 先前統稱為`Unsupported` 現分為以下幾類：
  -`reader provado`;
  -`writer conservador`;
  -`blocked`;
-`Field String` 以及`btl_txt.bin` 不再被浪漫化，彷彿它們「幾乎已經完成」一般。

### Still Missing
- 廣泛的作家`Battle Text`;
- 誠實地解鎖`Field String`;
- 針對較冷門的字型家族提供「編碼安全」功能。

## [v0.3.0] - 歷史重構（Git 正式 SemVer 之前）

此版本標誌著編輯器不再僅是檔案瀏覽器，而是開始涉足 AI、執行時環境以及高遊戲性介面。

### 新增功能
-`Monster AI Explorer`;
- 最初幾層嚴肅的`Live Battle Lab`;
- 強化解析器、語料庫、指令、強制動作與「存活狀態」之間的連結；
- 針對遭遇搜尋與腳本行為提供更完善的介面。

### 變更
- AI 不再是次要議題，而是成為產品優先事項；
- 執行時驗證的概念已徹底融入編輯器的核心；
- 該專案透過提供幾乎無人能及的功能介面，與社群的區隔更加鮮明。

### 仍待完善
- 更深入的回合式驗證；
- 安全的 AI 修補機制；
- 精確的遭遇事件工具集。

## [v0.2.0] - 歷史重構（Git 正式版本控制之前）

這是編輯器為大型且可視化系統進行結構擴展的里程碑。

### 新增
-`Sphere Grid Explorer`;
-`Sphere Grid Editor v1`;
-`Encounter Table Explorer`;
- 為戰鬥結構與遭遇表提供更穩健的介面。

### 變更內容
- 編輯器已脫離「幾個強大區域」的階段，轉變為具備多個可導航大型區域的工具；
- 遊戲區域之間的導航更加連貫；
- 該專案作為模組套件的實質地位更為穩固。

### 尚待完善
-`Encounter Table Editor`;
- 更具侵略性的 Sphere Grid 拓撲結構；
- 更深入的 AI／執行時機制。

## [v0.1.0] - 歷史重構（Git 正式版本控制之前）

這是個誠實的最低基準版本，此時已具備真正的編輯器，遠遠超越了可拋棄的原型階段。

### 新增
-`Monster Editor`;
-`Battle Commands / Items / Monster Commands`;
-`Battle Explorer`;
- 具備寫入功能的介面已足夠真實，足以定義產品，而非模擬版本。

### 變更
- 該專案已成為可用的編輯器，甚至在任何嚴肅的 Git 系統出現之前便已存在；
- 主分支早已具備自身特色，無需依賴「概念驗證」來證明其存在的正當性；
- 這個歷史版本正是可以合理地說該專案`FFX Project Editor` 當時它已經是一家出版社了，儘管規模還遠不及現在。

### 仍未收錄
-`Sphere Grid` 可編輯；
- 專用開發工具；
- 深度 AI／執行時技術；
- 正式治理／版本控制；
- 專業工作坊生態系統。

## [baseline-2026-05-31] - 2026-05-31

將生產環境內容完整且如實地首次匯入 Git。

### 新增項目
- 私有儲存庫`ffx-editor-main`;
- 分支`main`;
- 標籤`baseline-2026-05-31`;
-`.gitattributes`;
-`Git LFS` 在`FFXProjectEditor/Assets/Audio/**`.

### 保留
-`_labs` 偏離了基準線；
-`publish/`,`bin/`,`obj/` 而可忽略的報告仍被忽略；
- 基準線並未偽造回溯歷史紀錄。

### 已驗證
- 基準線提交已成功發布；
-`origin/main` 以及`baseline-2026-05-31` 指向同一個初始 Git 提交；
- 在發布基準版本後，清除本地工作樹。

### 備註
- 此基線為導入用快照，並非產品的語義版本；
- 其存在目的是在進行治理、版本控制及整合之前，將產出固定在 Git 中。

## 迷你版本歷史工作坊

備註：

-`Pt1` 它沒有出現在這裡，是因為它並未成為整合式登錄檔中正式的開發分支／版本。`2026-05-31`;
- 此波的版本化歷史線從`Pt2`.

## [pt2-v0.3.0-superseded.1] - 2026-05-31

### 使命
- 開通該路線`ModelViewerLab`;
- 理解`mon`,`.ebp` 及相關家族；
- 將「recon honesta」與尚不存在的「renderer」區分開來。

### 演變
- 從`ModelViewerLab`;
- 可匯出的成果；
- 分類`PROVED / STRUCTURAL / GUESS`;
- 歷史基礎，其後正式遷移至`Pt9`.

### 主分支結果
- 無直接功能性吸收；
- 該分支被公認為該血統的起源`ModelViewer`.

### 最終狀態
- 已被以下版本取代：`Pt9`;
- 作為歷史來源仍具重要性，而非獨立的活線。

## [pt3-v0.8.0-freeze.1] - 2026-05-31

### 使命
- 審核文字格式；
- 驗證安全的讀取程式；
- 僅推廣真正保守的寫入程式。

### 演進
-`TextRegressionHarness`;
- 重新分類先前被歸類為`Unsupported`;
- 安全閘門通往`Name / Description`;
- 安全閘門通往`Monster Localizations 1/2/3`;
- 誠摯決定維持`btl_txt.bin` 以及`Field String` 不參與促銷。

### 主要分支結果
-`TextLabTools` 被吸收；
-`ProductionAuditTools` 已併入；
- 安全地從主線中截取文字／怪物並併入。

### 最終狀態
- 已凍結；
- 仍作為正式版本文字邊界的來源。

## [pt4-v0.5.0-hold.1] - 2026-05-31

### 任務
- 進行視覺層面的精修；
- 測試外殼／主題，同時避免影響執行時環境；
- 將真正可移植的資源與內部品牌元素區分開來。

### 演進
-`StudioTokens`,`StudioTheme`, dense shell、儀表板、追蹤器及資產彙整；
- 平行線`FFXMenuWorkshopConcept`;
- 視覺套件已足夠成熟，適合進行精修，但尚不適合直接合併。

### 主分支結果
- 部分共享基礎資產；
- 尚未進行完整的誠實移植。

### 最終狀態
- 暫停；
- 仍作為分塊式精煉移植的候選方案，而非整個工作坊的合併。

## [pt5-v0.9.0-final.1] - 2026-05-31

### 任務
- 整合核心的解析器與表格編輯器；
- 每當閘門關閉時，將研究成果轉化為生產模組。

### 演進歷程
-`PlayerGrowthEditor`;
-`CtbBaseEditor`;
-`MixTableEditor`;
- 支撐該論點的主線`KeyItemEditor`;
- 重新分配`Auto-Abilities` 前往`Pt7`.

### 主分支成果
- 生產環境中最大規模的實際整合浪潮之一；
- 安全核心現已成為`main`.

### 最終狀態
- 最終；
- 工作坊已結束，主要成果已由製作團隊納入。

## [pt6-v0.7.0-beta.1] - 2026-05-31

### 任務
- 驗證戰鬥的執行時真實性；
- 減少遭遇戰與序列安排中的主觀臆測；
- 為`Force Battle / Repeat Encounter`.

### 演化
-`BattleRuntimeProbe`;
- 序列監控器；
- 選取器／銀行日誌；
- 槽位選擇器的篩選機制；
- 更真實的戰鬥與拆解觀察軌跡。

### 主分支成果
- 對路線圖及生產環境的風險表述產生重大影響；
- 上述內容目前均未轉化為運行時／記憶體方面的乾淨合併。

### 最終狀態
- 處於測試階段且為優先項目；
- 處於活躍狀態，代碼量龐大，技術價值高，但若盲目移植則風險極高。

## [pt7-v0.9.0-final.1] - 2026-05-31

### 任務
- 隔離`Auto-Abilities` 來自核心開發隊列；
- 測試一款不擴充語義的保守型編輯器。

### Evolution
-`AutoAbilityEditor`;
-`AutoAbility_File.cs`;
-`Arms_Rate.cs`;
- 明示的閘門以維持`62h..67h` 像……一樣`raw/read-only`.

### 主分支成果
- 已在生產環境中實際部署並驗證；
- 這是從實驗室分支移至主分支時，在保留防護欄（guardrail）情況下最乾淨的案例之一。

### 最終狀態
- 最終版；
- 應視為已完成的历史性專案。

## [pt8-v0.7.0-freeze.1] - 2026-05-31

### 任務
- 完成「誠實最小寫入器」的收尾工作，以`Shop`;
- 若屬實，請如實回答`w_name.bin` 無論是否準備好了。

### 演化
- 撰稿人已儲存至`item_shop.bin`;
- 已儲存的 writer 為`arms_shop.bin`;
- 明示依賴`shop_arms.bin` 在齒輪側；
-`w_name.bin` 維持為「僅供研究」狀態，並對撰稿人設為「封鎖」。

### 主分支結果
- 實際部分吸收量為`Shop`:
  -`Shop Explorer`;
  -`FfxLib/Shop`;
  -`Assets/Shop`;
  - 護欄相關文件載於`docs/history/PT8_SHOP_GUARDRAILS.md`.

### 最終狀態
- 凍結／停用；
-`Shop` 進入了保守的剪輯模式；
-`w_name.bin` 仍處於停用且被封鎖的狀態。

## [pt9-v0.6.0-alpha.1] - 2026-05-31

### 任務
- 正式延續該系列`ModelViewerLab`;
- 冷凍`ModelViewer v1`;
- 重新定義實際目標為`ModelViewer v2`.

### 演化
-`PT9_CONTINUATION_PACK.md`;
-`ModelViewer v1` 被認定為「recon + clues」，而非最終觀看者；
- 音軌`mot/regmot` 以及 PS2/Chargeur/FFXDumper 橋接程式；
- 未來整合的最佳候選方案，源自於`Monster Editor`.

### 主分支成果
- 目前尚無實際應用；
- 作為研究與功能精簡的基礎架構，價值極高。

### 最終狀態
- Alpha 版本已啟用；
- 仍需驗證實際的靜態視口。

## [pt10-v0.2.0-final.1] - 2026-05-31

### 任務
- 完成審核`read-only` 來自`btl_txt.bin`;
- 組織`US vs JP`,`W0..W3`, 前綴與配對。

### 演化
- 標記／配對／前綴的文件分類法；
- 矩陣`W0..W3`;
- 重申`Battle Text` 仍維持唯讀狀態。

### 主分支結果
- 僅具文件參考價值及防護欄功能；
- 未導入任何新功能。

### 最終狀態
- 最終版／唯讀；
- 工作坊已完成文件編寫，但尚未達到可寫入狀態。

## [pt11-v0.3.0-blocked.1] - 2026-05-31

### 任務
- 嘗試驗證一個最低限度且安全的寫入器，以`btl_txt.bin`.

### 演化
- 受控變異；
- 差異審計；
- 即使在微小變異的情況下，也能證明不存在語義污染。

### 主分支結果
- 僅能整合唯讀的證據與防護措施套件；
- writer/encode 仍處於封鎖狀態。

### 最終狀態
- 阻塞凍結；
- 工作坊已透過技術證據成功扮演「說不」的角色。

## [pt12-v0.3.0-package.1] - 2026-05-31

### 使命
- 在 Ghidra 的輸出與專案所需的實用產出之間架設橋樑。

### 演進
- 具潛力的解析器；
- 綁定程式碼生成器；
- 符號目錄；
- 已準備好作為獨立工具進行整合評估的套件。

### 主分支成果
- 目前尚未被採納；
- 已為下一波採納開放專屬分支。

### 最終狀態
- 套件已準備就緒；
- 極有希望在整合完成後納入`Pt8`.

## [pt13-v0.3.0-package.1] - 2026-05-31

### 任務
- 建立用於執行階段工具的 .NET 佈局／結構檢查器。

### 演進
- 檢查工具；
- 偏移量／大小報告；
- 發現記憶體敏感型別中的實際不匹配情況。

### 主分支成果
- 目前尚未進行整合；
- 已為下一波整合開啟分支。

### 最終狀態
- 套件就緒；
- 極有可能與以下項目一同納入，或緊隨其後納入：`Pt12`.

## [pt14-v0.2.0-architecture.1] - 2026-05-31

### 任務
- 研究有紀律的擷取`printf` 以及內部除錯字串。

### 演進
- 架構與候選方案；
- 擷取防護機制；
- 目前尚無確鑿證據顯示該鉤子已準備好投入生產環境。

### 主分支結果
- 未被納入；
- 在進行任何合併前，需進行新一輪嚴格審查。

### 最終狀態
- 架構暫停；
- 此分支仍需通過最低驗證標準，否則將被列為硬性阻擋。

## [pt15-v0.2.0-architecture.1] - 2026-05-31

### 任務
- 設計執行時處理程序與事件總線的規範。

### 演進
- 生命週期架構；
- 事件合約；
- 已釐清多執行緒／再進入風險；
- 目前尚無可供生產使用的最小切片。

### 主分支成果
- 未被併入；
- 需先具備一個唯讀的最小切片，方能視為可合併。

### 最終狀態
- 架構保留（architecture-hold）；
- 僅作為方向性參考，而非可直接使用的程式碼。

## [pt16-v0.2.0-architecture.1] - 2026-05-31

### 目標
- 整理編碼架構並`index types` 不要一時衝動就解鎖新的 Writer 版本。

### 演化
- 分類法提案；
- 矩陣`decode-only / encode-safe / raw-control`;
- 目前尚未吸收任何微量添加切片。

### 主分支結果
- 無吸收；
- 仍在等待一個`Slice 1` 小巧且安全。

### 最終狀態
- 架構暫緩；
- 對未來至關重要，但目前尚無立即合併的計畫。

## [pt17-v0.3.0-guardrail.1] - 2026-05-31

### 目標
- 強化儲存安全性、往返驗證及漂移分類機制。

### 演進歷程
- 風險矩陣；
- 儲存／重新載入測試框架；
- 標示尚未解決的重要錯誤，包括`important.bin` 以及`a_ability.bin + arms_rate.bin`.

### 主分支成果
- 實際差異仍需被區隔出來，並透過誠實的聲明加以整合；
- 部分內容似乎已反映在現有工具中，但並非全部。

### 最終狀態
- guardrail-baseline；
- 仍作為強化措施具有相關性，而非新功能。

## [pt18-v0.3.0-governance.1] - 2026-05-31

### 使命
- 整理發行版本、變更紀錄、基準、標籤及編輯工作流程。

### 演變
- 政策`CHANGELOG`;
- 版本控制政策；
- 分支／合併政策；
- 整合安全發布工作坊的流程。

### 主分支成果
- 大部分內容已整合至`docs/governance/`;
- 核心價值已轉變為生產治理。

### 最終狀態
- governance-baseline;
- 更傾向於被視為遊戲規則，而非未來的變動。

## [pt19-v0.3.0-surface.1] - 2026-05-31

### 使命
- 保持一致`README`, 螢幕截圖及 Surface 內容將透過現行編輯器發布。

### 演進
- 螢幕截圖審核；
- 資產政策`README`;
- 將舊的截圖替換為最新且可追溯的圖片。

### 主分支成果
- 大部分內容似乎已反映在本地工作樹中；
- 最終的差異仍需獨立處理，避免與其他工作線混淆。

### 最終狀態
- surface-baseline；
- 此分支主要用於公開展示，不適用於執行時環境／核心。

## [pt20-v0.2.0-strategy.1] - 2026-05-31

### 任務
- 研究如何選擇性地整合外部工具，而無需導入整個框架。

### 演進
- 整合矩陣；
- 比較`STEP`, 檢查與除錯工具；
- 建議採用精準整合，而非全面複製生態系統。

### 主分支成果
- 目前尚未進行任何整合；
- 作為運作路線圖，用於`Pt12 -> Pt13`.

### 最終狀態
- 策略基準線；
- 仍維持為整合方向，而非已完成合併。


