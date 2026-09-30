---
日付: 2026-06-29
タグ:
  - 変更履歴
  - バージョン管理
  - プロジェクトエディタ
  - モンスターAI
  - フェーズローテーション
  - スピラレフォージ
別名:
  - 変更履歴
  - バージョン履歴
  - バージョン記録
---
# 変更履歴

このファイルは、`FFX Project Editor` およびワークショップのエコシステム`Pt`.

これには3つの履歴レベルが含まれます：

- のリリースおよびベースライン`main`;
- から再構築された意味論的マイルストーン`main` Gitが公式に採用される前の時期；
- ワークショップの編集版ミニバージョンおよびナレッジ・スナップショット`Pt2` a`Pt45`.

この変更履歴のルール：

- **現行のルール（2026年6月4日より適用、参照`docs/governance/VERSIONING.md` 第4節）：** **shippavel** な追加項目（ライター、モジュール、テスト、容量、登録ドキュメント）はすべて、以下の4つのフィールドにバンプとして入力されます。`FFXProjectEditor.csproj` + ここ **と** ここ`changelogUS.md` + 行を`VERSIONING.md`;
- 各エントリを **MINOR** / **PATCH** / **REVISION** のいずれかに分類してください；lane を署名として記載してください (`Jarvis-ARENA`,`Jarvis-MAGIC`、など）マルチチャットの場合；
- スレッドを維持する`[anterior: vX.Y.Z.W]` リニア — バージョン番号を飛ばさない；
- **バンプなし**：些細な変更（タイプミス、空白の修正、内部リネーム、修正を伴わないバイト単位で同一のリファクタリング）に限定；
- マイルストーン、吸収、フリーズ、ブロック、ハンドオフも記録する；
- かつて存在しなかった古いGit履歴を偽装しない；
- 古いセマンティックバージョンが編集的に再構築された場合は、次のようにマークする`historical reconstruction`;
- 整備工場が設計を大幅に変更したにもかかわらず、`main`, ここではエコシステムの変更として記載されており、すでに実装済みの機能としては記載されていません。

## [未リリース]

### MINOR
- **`v2.192.0.0` (2026-07-15, MINOR) — 有用なPPP挙動の変異：初のT4による視覚的証明。** Lane **Jarvis-MAGIC-DLL**。[前回：`v2.191.0.0`]
  -`pppSclMove` パワーブレイク中にMMFバウンデッドキャプチャでT1/T2を通過：9/9のコールバック`magic_0021` Blobランタイムに割り当てられたもの；テクスチャローダーが識別した`magic_0021` から`magic_0326`.
  - リバーシブルなT4 PASS：コールバック内の16バイトのウィンドウ`.data+0x1C1B0` 均一なスケールで描かれた`0.948116` ～へ`3.0`; Power Breakのコンポーネントの1つが、クラッシュすることなく明らかに大きくなった。Restoreが復帰した`magic_0021.dll` vanillaとバイト単位で同一。
  -`pppSclAccele` そして`pppAngMove` source-linkedおよびT3 copy-onlyの候補を受け入れました。これらは次期ランタイムファミリーとなります。`pppColor` 依然として日和見的であり、批判的な立場からは外れている。
  -`ffx-magic-re v0.4.0` サニタイズされたベクトルセレクタ／スイッチおよび合成フィクスチャを含む状態で公開。テスト222件中222件すべてが成功し、ガードに違反はなかった。

- **`v2.190.0.0` (2026-07-11, MINOR) — Sphere Grid Canvas v3: UIのリデザイン + コンテンツの修正 + デプロイポリシー + IDA RE.** **MINOR**. Lane **Jarvis/Sisyphus**. [前回:`v2.189.0.0`]
  - **UIのリデザイン（Kimi K2.7）：** SphereGridCanvas_Control.axamlを再構築：3行のコンパクトなツールバー（グループラベルは大文字＋垂直セパレーター）、340pxのサイドパネル（ヘッダーを強調＋空の状態（◎））、ノードを大きくしたCanvasView（30個）、背景色をクールな色調に、リンクを太く、ラベルを11pxに。
  - **コンテンツインデックスの修正：**`FindOrAddNodeTypeOption` 修正済み — これで、panel option が`Index == contentIndex` まず、あり得たコマンドオプションを優先するのではなく、`Index` 異なる（ドロップダウンでHP→Lock Nv3のバグが発生していた）。
  - **デプロイポリシー：**`SphereGridDeployPolicy` 追加 — ブロック`SaveToProject` そして`SaveSquareToProject` カウントが変更された際、実行時に問題が発生することが確認された。Banner、README、およびTopologySafetySummaryに記載されていた「no hook required」という誤った主張を撤回した。
  - **削除されたフックアーティファクト：** True New Node LAB（プロパティ、ロジック、マニフェスト、フラグ）、true_new_node.flag、true_new_node_manifest.csv、READMEのフックテキスト — これらすべてがエディタおよびSquarePackageWriterから削除されました。
  - **IDA RE (0xA45570):**`FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells` parse/cell バケットに対して nodeCount-driven が確認されました。ヘッダーマジック 0x31、Unknown6 =`(PosX+2560)/256 + 20*((PosY+2336)/256)`. **exitパイプラインの安全性を検証しません。**
  - **IDA RE (0x681DB0):**`FFX_Menu2D_InitBatchBuffers_NoTextureFallback` ケース3は、pos=0xA170（41328=861×48）、color=0xD740（55104）、uv=0x6BA0、index=0x285Cを割り当てます。 履歴「41252」は誤りでした。
  - **IDA RE (0xA51340):**`FFX_Abmap_DrawRuntimePanelNodes` 使用する`n861 = NodeCount - iter + 860` (860 がハードコーディングされている)。
  - **IDA RE (0x7F4900):**`FFX_Menu2D_DrawQuadIndexedBatch` ある`if(n861 >= 861)` (861がハードコーディングされている)。負のパスにより、861ノードでカラーバッファがオーバーフローする。
  - **IDA RE (0xA54860):**`FFX_Abmap_RecomputePartyStatsAndLearnedMoves` これは統計データのみであり、GPUプロデューサーではありません（過去の推論を修正）。
  - **RT2 確認済み：** Standard 98/861/882 では Sphere Grid が起動しますが、終了時に即座にクラッシュします。 バニラオーバーレイが復元されました。アーティファクトは `work/evidence/spheregrid-exit-cras` に保存されています。

h-20260711/`.
  - **ステータス: SGM 861`bloqueado / research only`. 次のステップ：インターセプトするためのインプロセス・フック（DINPUT8ブリッジ）`DrawQuadIndexedBatch` また、860以上のスロットをより大きなバッファにリダイレクトする。**

### PATCH
- **`v2.190.3.0` (2026-07-12、パッチ) — Battle Commandsのマスターサイドバーの幅に関する修正 + MonsterMagicGrowWriterのコンパイルに関する修正。** **パッチ**。Lane **Jarvis-UI**。[以前：`v2.190.2.0`]
  - **サイドバーの幅に関する修正：**`ModuleMasterDetail_Shell.axaml` — パネルが 140px から 260px に拡大されました。以前の幅では、コマンド名が省略記号で切り詰められていました（`Fros...`,`Shor...`,`Mist...`) スキル名をすべて読み取ることができなかったためです。260pxでは、次のような名前が`Froststrike`,`Short Charge`,`Counter March` ほとんどの場合、トリミングなしで収まります。折りたたまれたレールは26pxのままです。
  - **コンパイルの修正（ビルドブロッカー）：**`MonsterMagicGrowWriter.cs` 4つのリンク切れを修正しました：`FlagTargetSelf` →`FlagTargetSelfOnly`; 削除済み`StatusDuration.Confuse = 3` (クラス`StatusDurationByteList` フィールドがありません`Confuse` — この形式には「confuse」の持続時間という概念は存在しない）。`BreakArmor`/`BreakPower` すでに正しい名前になっていました。ビルドのエラー数が0に戻りました。
  - **互換性：** シェルを使用する他のタブ／モジュール（Mix Tables、Monster Editor、Items）も、展開されたパネルで260pxの幅を確保できるようになりました。これにより、アイテムやモンスターが表示される際に文字が切り詰められることなく、十分なスペースが確保されます。

- **`v2.190.2.0` (2026-07-11, PATCH) — バトルコマンドのマスターサイドバーのスリム化 + 共有シェル切り替え機能のリファクタリング。** **PATCH**。レーン **Jarvis-UI**。[以前：`v2.190.1.0`]
  - **Master sidebar slim (Kimi K2.7 + GLM-5.2):**`ModuleMasterDetail_Shell.axaml` に取って代わった`Expander` アヴァロニア出身のデザイナーによるレイアウト`Grid` +`Button` custom。Expanderのテンプレートには`ExpandDirection="Left"` パディング／余白／最小値が設定されており、これにより約50～60px未満での折りたたみが妨げられていた。
  - **新しいサイズ：** 展開時 = 140pxの密集したパネル + 26pxのトグルレール（合計約166px）；折りたたみ時 = 26pxの細いレールにシェブロンが1つだけ。
  - **バトルコマンドのデフォルト展開状態：** 削除`IsMasterExpanded="False"` から`KernelCommands_Control.axaml` — ユーザーはコマンド一覧が表示された状態で操作を開始し、詳細画面に完全に集中したい場合はレールをクリックして折りたたむことができます。
  - **バトルコマンドUIの改良 (Kimi K2.7):**`KernelCommands_Control.axaml` ヒーロー統計チップ（Scope/Total/Filtered/WRITABLE）を獲得し、アクションカラー付きのセッションバー（`primaryAction accentGold`,`dangerAction`,`accentRefresh`), スリム行形式のマスターリスト、`HorizontalAlignment="Stretch"` 「Detail」のカード内、およびコマンドが選択されていない場合の空の状態。`KernelCommands_DataModel.cs` 計算プロパティを追加しました`CommandScope`,`TotalCount`,`FilteredCount`,`HasSelectedCommand`.
  - **互換性：** シェルのすべてのパブリックプロパティ（`MasterHeader`,`MasterList`,`Detail`,`MasterHeaderLabel`,`IsMasterExpanded`) は変更不要です。シェルを使用するその他のモジュール（Mix Tables、Monster Editor、Itemsなど）についても、変更の必要はありません。
  - **Writers/save bytes/handlers/converters/FfxLib は変更なし。** ビジュアルコンテナのみ。ビルド **エラー0件**（既存の警告427件）。

- **`v2.190.1.0` (2026-07-11、パッチ) — ミックステーブルのUI再設計の仕上げ：ストレッチレイアウト + 埋まっている／空いている状態を示すチップ + パートナーアイテムの統一グリッド。** **パッチ**。レーン **Jarvis-UI**。[以前：`v2.190.0.0`]
  - **ストレッチレイアウト（Kimi K2.7）：**`MixTableEditor_Control.axaml` Detailの垂直方向の崩れを修正しました —`HorizontalAlignment="Stretch"` ScrollViewer + StackPanel + 5つの内部ボーダーを追加しました。右側の巨大な余白が消えました。
  - **Partner Itemsの均一グリッド：**`ItemsPanel` Partner ItemのListBoxが、`StackPanel` 垂直に`UniformGrid Columns="3"`. リストは、112個の項目を1つの縦列に積み重ねるのではなく、レスポンシブな3列レイアウトになります。
  - **ステータスチップ（filled/empty）：** パートナー行のチップは、現在`<Grid>` 2で`<Border>` 重なり合う —`IsVisible="{Binding !IsEmpty}"` → 「filled」（ティールグリーン）と`IsVisible="{Binding IsEmpty}"` →「empty」（くすんだグレー）。これに取って代わったのは`<Run Text="{Binding ResultLabel}"/>` が示していた`<empty>` 空のセルにはリテラルが、値が入力されたセルには項目の名前（セマンティックノイズ）が表示される――項目の正しいラベルは、下の「Combination Editor」の「Current Result」カードにすでに表示されている。
  - **ツールチップ：** 両方のチップに`ToolTip.Tip` 112×112のマトリックスの各セルが、アイテムを生成するか否かを説明します。
  - **DataModel:**`MixResultRow.IsEmpty` ～に由来する`RawResult == 0`; 通知日：`NotifyComputedChanged` ～とともに`ResultLabel`/`ResultCode`/`Formula`.
  - **ヒーローのステータス：**`OriginCount`,`TotalNonEmptyResults`,`CoveragePercent` （すでに計算済みプロパティとして存在する）ものが、ヒーロー上にチップとして表示される。
  - **Writers/save bytes/handlers/converters/FfxLib は変更なし。** ビジュアルコンテナのみ。ビルド **エラー0件**（既存の警告422件）。

### 修正
- **`v2.189.0.0` (2026-07-10, 改訂) — PPP C2 Wave 1 + SOL 監査 + ハンドラテーブルのレイアウト。** **改訂**。レーン **Jarvis-MAGIC-DLL / SOL**。
  - **C2 Wave 1 (GLM-5.2):** 193/193 のユニークなハンドラーが、IDA MCP を使用して正規の IDB から逆コンパイルされた`ffxoficial_post_vtable_struct_20260710_110730.i64`. 特定された10のカテゴリ（Nullsub、Euler Matrix、Rand/Pattern、Transform/Matrix、Menu2D/Projection、FieldMap/Scene、Draw/VFX、Push/Copy Node、Animation State、Misc）。`PPP_HANDLER_ENCODING_SPEC.md` 呼び出し規約、スロットレイアウト、ノード構造体、5つのアクセスパターンについて記述されている。`SOL_PACKAGE_V2.md` ハンドオフに向けた統合。22個のDLLからなるフィクスチャ（6,650以上のスロット）。カバレッジレポートを作成。68/68のテストを維持。
  - **SOL Audit (GPT-5.6):** 標準IDBに対するV2パッケージの敵対的監査。ハンドラテーブルのレイアウトが証明された：40B（0x28）のエントリで`name_ptr@+0x00`, モードポインタ`@+0x04/+0x08/+0x0C`, パディング`@+0x10..+0x27`.`0x730050` ～のインテリアとして確認された`ApplyTransformPattern_F` （エントリポイントではない）。`0x75B320` ～として確認された`UpdateAnimationState` （内部ヘルパー、ディスパッチテーブルからのクロス参照なし）。`pppRandUpFV` string ptr が確認されました`0xB50E0C`. 通訳者`0x7170F0` デコンパイル済み：読み取り専用`+4` (direct_handler) がパス上に存在する場合；カスケード`+8/+C` 証明されていない。
  - **証拠による中断：** ディスパッチテーブルから再現可能な抽出子が得られるまでC2/C3がブロックされる + ハンドラによって具体化された証拠 + 意味論`+4/+8/+C` 証明された。`SOL_PACKAGE_V2.md` また、「193/193 のハンドラーが逆コンパイルされた」という、実現されていない主張が含まれている（逆コンパイル結果は個別のファイルには保存されていない）。`HANDLER_TABLE_LAYOUT.md` そして`OPEN_QUESTIONS.md` ワーキングツリー内に作成されました。
  - **シェーダーリード（非ブロッキング）：** 797個のPhyre D3D11ファイルが`work/vanilla_bins/ffx_data/gamedata/ps3data/shaders`; ドローと素材の相関を示す二次的な手がかりであり、PPPのエンコーディングを直接示す証拠ではない。
  - **ステータス: C2/C3`bloqueadas por evidência incompleta`. レイヤーA/B/C1はゲートを有効な状態に維持する。**

### ハイライト
- **`v2.189.0.0` (2026-07-10) — Magic DLL / PPP アセンブラ・レーン：レイヤー A + B + C1 + フェーズ 2 + 詳細分析。** **マイナー**。レーン **Jarvis-MAGIC-DLL**。[前回：`v2.188.0.0`]
  - **レイヤー A — WD3 構造化シリアライザ** (`wd3_writer.py`): 224バイトのプレフィックス（ヘッダー、ポインタテーブル、ギャップ、5つのストリームヘッダー）をコピーせずに再構築する`raw_bytes`. センチネルの保護`end_offset=0`, 予約済みフィールドおよび不変項`total_size/count_entries`.
  - **レイヤーB — WD3物理ペイロードモデル** (`payload_map.py` +`wd3_blob_writer.py`): 110,272バイトのBLOBを、型付きプレフィックス（224B）に分割し、`post_prefix_gap` 不透明（5.296B）および`body` 不透明（104.752B）。1～5人の論理所有者を持つ9つの標準的な物理スパン。テンプレートなしのラウンドトリップ積分`.data`.
  - **レイヤー C1 — PPP 再配置可能スロットコーデック** (`layer_c_slot.py` +`layer_c_resource.py`): PPPリソースブロブからWD3を分離し、ルートを検出し、セクション／プログラムを走査して、16Bのディスク上のスロットを再発行する。 Steam **353/353 PASS** (355個のルート、1,623個のセクション、24,888個のプログラム、274,732個のスロット); フィクスチャ **16/16 PASS** (4,450個のスロット)。
  - **PPP オペコードカタログ**：274個のオペコードをカタログ化、222個のディスパッチエントリ、約50個のハンドラを逆コンパイル。
  - **フェーズ2のミューテーション実験**：ゲーム内でテクスチャパスの入れ替えを確認；ゲーム内で.dataの入れ替えを確認；float4/BGRAの個別パッチについて、可視色が変化しないことを確認（5回の試行）。
  - **詳細分析**：Blizzara/Watera/Thunderを分析；シェーダーシステムFamily Aのマッピング（PPP→DXBC）；ターゲットごとのアニメーションの根本原因を特定；11件のドキュメントでHOST_CONTEXT_MAPを修正；`magic_0383` 偽陽性として再分類された。
  - **エビデンス**：68/68 テスト PASS；レイヤー A/B Steam 6/6 ＋フィクスチャ 16/16；C1 Steam 353/353 ＋フィクスチャ 16/16；診断エラーゼロ。
  - **ステータス：レイヤーA/BおよびC1**`validadas`; Layer C2+（ペイロード、リサイズ、新エフェクト）`research only`.**
- **`v2.189.0.0` (2026-07-10) — UNI-003 低HPラッシュ + クロスバリデーションRE完了 + HPゲート修正。** **マイナー**。レーン **Jarvis-AI/RE**。[以前：`v2.188.0.0`]
  - **HPゲートの修正（NearDeath）：** 根本原因の確定 — フィールド 0x0000/0x0002 は CTB ゲージ/ターン数であり、HP/最大HP ではない。 フィールド 0x0119（NearDeath ブール値、読み取り）に修正`[edi+594h]` maxHpStat 対`[edi+5D0h]` curre

ntHp）。Skoll m014のゲーム内でRT2が検証済み：HPが50%を下回ると、HPゲートが正しく発動する。
  - **UNI-003「Low HP Rush」：** エディターにワンクリックで適用できるプリセットとして実装されました。HPが50%未満（NearDeath）の場合、自身に「Haste」を付与し、さらに前線の生存しているランダムなターゲットに「Slow」を付与します。`findMatchingChr(FrontlineChars, isAlive, 0, Any)`、プライベート変数によるワンショット。複合ガード：`var==0 && NearDeath` (LAnd)。ユーザーが手動で修正したバイナリ m014 により RT2-proven となった。
  - **新しい IR レコード：**`PerformCommandOnRandomFrontlineChr` no`SinChainRecipe` — 実行時に計算されたターゲットを、以下の方法でモデル化します`findMatchingChr`.
  - **汎用プランナー：**`SinDryRunPlanner.PlanGuarded` アクションのコンボが可能になりました（以前は1つだけでした）；`LowerLinearAction` 対応しています`PerformCommandOnRandomFrontlineChr`.
  - **REレーンの完全なクロスバリデーション：** SUPERMD（2115行、バイナリに対して150以上の仮定を検証）。87件が確認され、20件の実際のバグが修正され、120件の新しい関数IDが登録された。 346件のケースがマッピングされたスイッチの書き込み側（0x7B4B80） — 0x7018 = WriteChrProperty を確認。
  - **修正された重大なバグ：** 0x7050→0x705A (ForcePerformCommand)、0xB6→0xD8 (CALLPOPA)、UNI-007 70%→50% (NearDeath閾値)、 0xFFF1ラベル（AllAeons）、0x7078→0x706C（ReadMovePropertyForActor）、センチネルラベル（0xFFEC/0xFFEB/0xFFE9）。
  - **再生されたファイル：**`SinChainRecipe.cs`,`SinPresetRecipeResolver.cs`,`SinDryRunPlanner.cs`,`MonsterAiEditor_DataModel.Sin.cs`,`SinScaleInject/Program.cs`,`SinPresetRecipeResolverTests.cs`,`AiChrPropertyNames.cs`,`AiScript_File.cs`,`AiTargetNames.cs`,`universal.csv`,`PORT_STATUS.md`,`SESSION_HANDOFF.md`.
  - **ビルド:** エラー0件。 **テスト:** 1/1 GREEN (SinPresetRecipeResolverTests)。 **RT2:** Skoll m014において、HPゲートおよびPhaseRotationがゲーム内で確認されました。
  - **ステータス:`Precisa Testar`** — UI（.axaml.cs）内のUNI-003ボタンおよびワンクリックボタンのRT2の配線が不足しています。
- **`v2.188.0.0` (2026-07-07) — Wave E：6つのファミリー固有のナローライター＋6つのRT0ゲートが検証済み。** **MINOR**。レーン **Jarvis-WAVE-E**。[前回：`v2.187.0.0`]
  - 6つのファミリー固有のナローライターが実装されている`FFXProjectEditor/FfxLib/Ai/`、それぞれについて、RT0ゲートが`AiScriptLab` (ベースライン → パッチ → 検証 → スプライス

 round-trip → restore → byte-identity):
    - **`AiRoundScriptedBossWriter`** (m238 Zu) — ラウンド5ビート（ランディング／クロール／ソニック／イオーン・パニッシュ／フィニッシャー）、コマンドホワイトリスト 0x4019/401A/4016/4097/40AB/40DF、ゲート`--round-scripted-boss-writer-rt0` **PASS**。
    - **`AiAnimaOdThresholdWriter`** (m125 Anima) — シェイプ付きゲートOD`OverdriveMax / divisor [* numerador]`, 検出、ルーズ・フォールバック、ゲート`--anima-od-threshold-writer-rt0` **PASS**。
    - **`AiOmnisClusterWriter`** (m131 Omnis) — エレメンタル・クラスター 0x3045-0x304C、ホワイトリスト（ナロー）、ゲート`--omnis-cluster-writer-rt0` **PASS**。
    - **`AiMortibodySupportAccumulatorWriter`** (m127 Mortibody) — 4つの蓄電器 priv0010/0014/0018/001C、ゲート`--support-accumulator-writer-rt0` **PASS**。
    - **`AiMortiorchisCompanionWriter`** (m143 Mortiorchis) — ハンドオフ/吸収 0x608C/0x60A9、ゲート`--mortiorchis-writer-rt0` **PASS**。
    - **`AiReactiveSensorWriter`** (m106/m118/m150/m154 リアクティブ) — センサー`usedCommand 0x7019 → readMoveProperty 0x701A → PUSHII state`, ゲート`--reactive-sensor-mortiphasm-writer-rt0` **PASS**（モンスター4体）。
  - 各ライターは、以下のパターンに従います。`AiFluxNativeThresholdWriter`: 記述子 → パッチ要求 → バイト変更ガード → 編集結果 → 失敗時のロールバック。パッチは許可されたバイト（immediates PUSHII）のみに影響を与えます。ホワイトリスト外の差分がある場合は、ロールバックにより処理が中止されます。
  -`AiScriptLab.csproj` 6つの新しいインクルードファイルが追加されました；`RuntimeTools/AiScriptLab/Program.cs` RT0ゲートが6つ追加されました。
  - **ビルド**:`dotnet build FFXProjectEditor` エラー0件、`dotnet build AiScriptLab` エラー0件、**6/6ゲート RT0 PASS**。
  - **ステータス：`Precisa Testar`** — UI統合（DataModel Advanced*のポップアップ）が不足しているほか、ゲームプレイやオーサリングに関する詳細な文言を確定する前に、エディタでの手動テストおよびゲーム内でのRT2テストが必要。
- **`v2.187.0.0` (2026-07-01) — Treasure Master + BukiGet Writer + Lightning Dodgeエディター。** **MINOR**。レーン **Jarvis-BAUS**。[前回：`v2.186.1.0`]
  - **buki_get.binのライター**：ByteSnapshotEditorSessionを介して編集可能なギアの項目が86件（Owner、GearType、Formula、Power、Crit、Slots、4つの自動アビリティ、Flags、Unk03）。 Items Hub内のTabMode.Writer。
  - **Lightning Dodgeエディタ**：kami0000.ebp内の11個のしきい値を読み書きし、

 kami0300.ebp（ATELのバイトコードパッチ経由）。プリセット：バニラ／中／イージー／エクストリーム。「Extras」内のモジュール。
  - **REの発見**：thresholds（5/10/20/50/100/150/200 連続 + 30/80 合計）が命令として検出されました`AE XX 00 29 06` .ebp ファイル内 — EXE、カーネルバイナリ、マジック DLL には含まない。ffx_addresses.h は 0x400000 オフセット。並列エージェント 5 つ（IDA MCP 3 つ + 検索 2 つ）。
  - **マスタードキュメント**: FFX_TREASURE_MASTER_2026-07-01.md (631行、15セクション)。 498個の宝物がカタログ化され、33のエリアがマッピングされ、86個のbuki_getエントリが文書化されました。CSVをエクスポートしました。
  - **ビルド**：コンパイルエラー0件。
- **`v2.186.0.0` (2026-06-30) — フェイズ・マネージャー：IDUエディター + ルートカード。** **マイナー**。レーン **ジャービス-MAGIC**。[前回：`v2.185.18.0`]
- **`v2.185.18.0` (2026-06-30) — シーモア・オープナーのプルーフが、Bible/Atlas + ガードレール・インアプリに昇格。** **パッチ**。レーン **Jarvis-RE / Jarvis-MAGIC**。このオープニング`Shell/Protect antes da party agir` 外部フックなしで閉じられた：`mcyt06_00 ?StartEndHooks2::HookStart` する`AllMonsters.FirstStrike = true`,`AllMonsters.CurrentTurnDelay = 0`,`Monster#01.CurrentTurnDelay = 1` そして、パーティー／予約を`+2`; 実際の編成で`slot0=m141`,`slot1=m124`,`slot2=m141`,`slot3=m125`、これは、オープナーがエンカウンターの本来のセットアップから生まれるものであり、その場限りの小細工から生まれるものではないことを証明している。`performCommand` シーモアによるもの。この発見は、耐久性のあるドキュメントに反映された（`ATEL Bible`,`Monster AI Corpus Atlas`) および`BIBLE OF SPIRA` アプリ内経由で`AiBibleCatalog`、製品ごとに明確な境界を設定して：`Battle Corpus Crosswalk` /`Aurora` これを読み取り専用モードで表示することはできますが、`HookStart` / CTBの初期シードはまだパブリックライターではありません。ネイティブのSeymourドキュメントは統合され、バージョン管理されています。[以前：`v2.185.17.0`]
- **`v2.185.17.0` (2026-06-30) — Monster AI フェーズ回転 P1+P2 + Seymour RE 第2層 + IDU 編集可能性に関する提案。** **PATCH**。レーン **Jarvis-MAGIC / Jarvis-RE**。ブランチ依存型リーダー P1+P2 を実装：`AiDetectedBranchAction` 今、読み込み中`TargetProvenance`/`CommandProvenance` ウォーカーによってローカルパスが保持されているもの（PUSHV/POPV、findMatchingChr）。UIの`Monster AI Editor` cmd/target/labels をソースとする、読み取り専用の複数行ブロックを表示します。ビルドエラー 0 件、PASS n

RT0。Seymour m124：REの第2レイヤーが完了 — オペコード 0x6051 （SetupWaitTimer）がCTBのカウントダウンにより特定、0x604D（MenuAnimationKind）がマッピング済み、0x604B（BattleEventString）は内部マシンコードを含む文字列テーブルとして構成されている。 CTBセットアップフローを調査：バトル開始イベント 0x01→0x704A（エンジンのQtMG/スクリプティング層）、純粋なATELではない。 Indirect Dispatch Unit (IDU)：調査完了 — 57個の間接テーブル、147回のディスパッチ操作、ビジュアルエディタの提案。 Home (Gundappo)：azit03によるフォーメーションがコミットされた。ナレッジベース＋FastEntrypoints＋セッションハンドオフが同期化された。[前回：`v2.185.16.0`]
- **`v2.185.16.0` (2026-06-29) — モンスターのステータス・ギル・APの再調整：マカラニア、ビカネル、カルム・ランズ、および7つのODデザイン。** **パッチ**。レーン **ジャービス**。イギオン（m026）とマフデット（m004）が、トカゲ系／アーマード系の基準に従って強化されました。 カクタール（m208）が強化（HP 800→1500、AGI 24→40、MDEF 255は維持）。 Calm Lands：10体のモンスターのAGIおよびステータスが強化されました。3つのエリア（マカラニア、ビカネル、Calm Lands）で、ODボーナス付きでギル/APが増加しました。APovkは2×に統一されました。 計画中のOD：ムシュッス（サンドブレス）、ズー（ソニックストーム）、カクタール（10,000ニードルズ）、クール（ブラスターキャノン）、キメラブレイン（マイティガード＋サイキックストーム）、オーガ（オーガスマッシュ）。 4ターゲットの同期（repo/steam/extract/clean-bins）がプロジェクトルールとして文書化された。[以前：`v2.185.15.0`]
- **`v2.185.15.0` (2026-06-29) — Obsidian Vault + ドキュメントのフロントマター + ツールインフラ。** **PATCH**。レーン **Jarvis-INFRA**。 プロジェクトのルートにObsidian Vaultを設定：フォルダ/タグごとに11色のグループ分けがされたgraph.json、グラフのグロー効果と鮮やかな色使いを施したCSSスニペット（colorful-graph、colorful-folders）。 docs/obsidian-vault/ には、30件以上の相互リンクされたノート（ハブ、REノート、Battle AI、Spira Reforge、セッション、参考文献）に加え、4つのMermaidダイアグラム（SinScaleInjectアーキテクチャ、Phase Rotationフロー、ATEL VM、Monster Worker構造）が含まれています。 Organizer DeepSeekは、グラフビューを充実させるために、フロントマター（タグ、エイリアス、日付）を含む約1900個の.mdファイルを処理しました。 AGENTS.mdでの自動ルーティング機能を備えた、5つのFFX専門スキル（monster-ai-specialist、runtime-hooks-engineer、wpf-module-architect、re-ida-analyst、data-diff-patch-engineer）が作成されました。GitHub MC

Pは環境変数と.bashrcを介してトークンが設定済み。.gitignoreが更新済み（.mcp.jsonを含む）。AGENTS.mdには標準化されたフロントマターが記載されている。[以前：`v2.185.14.0`]
- **`v2.185.14.0` (2026-06-29) — Monster AI フェーズ・ローテーション：`AfterAnyValidTurn` CTBエッジでの実際のディスパッチ実行時間。** **PATCH**。レーン **Jarvis-MAGIC**。O`PhaseTurnEdgeHook` 単なるオブザーバーではなくなりました。ランタイムのコールバックは、エッジのアクターを解決し、`m###`, このモンスターと互換性のあるサイドカーのすべてのエントリーをスキャンし、構造ブリッジを介してアクションを並べる（`resolveTargetMask -> queue script command`) CTB edgeと同じコンテキストで。ランタイムは状態を保持する`onlyOnce` 著：`entry x actorSlot`、戦闘の署名が変わった際にこの状態をリセットし、ディスパッチの成功／失敗をログに記録するようになりました。エディタでは、sidecarの`AfterAnyValidTurn` 現在は、以下の国・地域にも輸出されています`modules\config` ゲームの、その`GameInstallRoot` 解決可能であり、警告やUIは、あたかも～であるかのように装わないよう厳格化された。`guardVar` シフト外でも実行可能：runtime v1 = 即時コマンド、ワンショットとして最適。`RuntimeTools/PhaseTurnEdgeLab` 実際のログに合わせて調整されました（`n6`/`a2`). **ステータス：`Precisa Testar` ゲーム内** — オフラインでのビルドは問題なし、RT2はまだ未確定。[前回：`v2.185.13.0`]
- **`v2.185.13.0` (2026-06-28) — Monster AI Phase Rotation：バトル開始時のAIが無効化されました。honestトリガーがruntime/CTB edge pendingに変更されました。** **パッチ**。レーン **Jarvis-MAGIC**。O`Gerenciador de Fases` ～ふりをやめた`Assim que a batalha começar` これは、ゲーム内における確実なゲームプレイのトリガーであり、`AiFile`. ライターは現在、applyを拒否しています。`BattleStart`, UIはこのパスを`Init do CombatHandler (LAB desabilitado)`、そして警告は正しい道筋を示している：CTBのエッジにおけるランタイムフックは、「有効なターンがすべて終了した後」という動作に対応するものだ。`RuntimeTools/AiScriptLab --phase-rotation-rt0` 100%のレシピに戻りました`onTurn` そして**PASS**が続く；その`m020.bin` テスト環境は、リポジトリ外のクリーンなベースライン状態に復元されました。[以前：`v2.185.12.0`]
- **`v2.185.12.0` (2026-06-28) — Monster AI Phase Rotation：実際のトップでのバトル開始 + 往復の`forcePerformCommand`.** **PATCH**. Lane **Jarvis-MAGIC**. O`Gerenciador de Fases` 現在はフェーズを扱っています

 トリガー付き`Assim que a batalha começar` コードの末尾に新しいブロックを単に連結するのではなく、エントリポイントの先頭に物理的に挿入する形です。これにより、オープナーが文字通り従来のハンドラ本体の直上に配置され、以下のケースが発生するリスクを低減します`m020`、そこでは即座の行動が、他の行動に先んじてそのターンを消費してしまう可能性があった。ドラフトの読者もまた、次のように認識するようになった`forcePerformCommand (0x705A)`, そのため、開始レシピを再開／再適用すると、これらのブロックが無視されなくなります。`RuntimeTools/AiScriptLab --phase-rotation-rt0` **PASS** が続きます`319/319`** そして、エディタのリリースビルドは **エラー0件** で完了しました。 **ステータス：`Precisa Testar` ゲーム内**、とりわけ`m020 - Teste Não Funcional 2.bin` オープニングでの3つのキャストの実際の順番通り。[前：`v2.185.11.0`]
- **`v2.185.11.0` (2026-06-28) — Monster AI Phase Rotation：移植可能なオーサーID + 既存の変数を上書きせずにマテリアライズ。** **パッチ**。Lane **Jarvis-MAGIC**。O`Gerenciador de Fases` さあ、分けよう`ID real` から`ID autoral/template` 監査対象の各変数について：UIは両方を表示し、優先されるIDをローカルメタデータに保存した上で、レシピにリクエストを行わせる`var[N]` エイリアスを実際のオペランドと混同することなく、より高いレベルで。applyでは、エディタは必要に応じて、既存の変数を上書きすることなく、同じストレージ／スロットのエイリアスを使用して追加の記述子を生成します。もし`ID` リクエストがすでに別のvarによって占有されている場合、リソースは次の空きインデックスに割り当てられます。フェーズのガードも、マテリアライズされたインデックスに再マッピングされます。`RuntimeTools/AiScriptLab --var-grow` **PASS** が続きます`185/185`** および`--phase-rotation-rt0` **PASS** が続きます`319/319`**; エディタのReleaseビルドが **エラー0件** で完了しました。 **ステータス：`Precisa Testar` ゲーム内**、とりわけ異なる変数テーブルを持つモンスター間のインポート／エクスポート。[前：`v2.185.10.0`]
- **`v2.185.10.0` (2026-06-28) — Monster AI Phase Rotation：varのIDが安定 + 戦闘開始直後の即時展開。** **パッチ**。レーン **Jarvis-MAGIC**。O`Gerenciador de Fases` テキスト解析への依存をやめた`IndexLabel` 知るために`var[N]`:`AiPhaseVariableAuditRow` 今、読み込み中`VariableIndex` 数値は安定しており、UIには次のように表示されます`ID###` 直接指定するため、「変数のIDを編集する」という表現における、テキストかエイリアスかという曖昧さが解消されます。gを含むフェーズ

アティリョ`Assim que a batalha começar` 現在、発行している`forcePerformCommand (0x705A)` ～の代わりに`performCommand (0x700B)`、オープニングのセットアップで通常の順番待ちに頼らなくて済むように。`RuntimeTools/AiScriptLab --phase-rotation-rt0` 「オープナー・バトルスタート」の特集を飾り、**PASS**へと進む`319/319`**; エディタのReleaseビルドが **エラー0件** で完了しました。 **ステータス：`Precisa Testar` ゲーム内**、主にオープニングの順序・アニメーションと、実際の事例として`m020`. [前へ：`v2.185.9.0`]
- **`v2.185.9.0` (2026-06-28) — SinScaleInjectのクリーンなデプロイを`modules\tools`.** **PATCH**. Lane **Jarvis-SIN**. 新しいスクリプト`RuntimeTools/SinScaleInject/deploy-sinscaleinject.ps1` 公開する`SinScaleInject` 新しいファイルに貼り付け、置き換える`modules\tools\SinScaleInject\` コンパクトなスタンドアロン型ペイロードによって（`SinScaleInject*`,`SinCoreLib.dll`,`Xe.BinaryMapper.dll`), ドラッグ効果を排除して`FFXProjectEditor.exe`/ゲームデータのAvalonia。`Program.cs` 現在、これを検出し`GameRoot` ～から`AppContext.BaseDirectory` ～の中で実行されるとき`modules\tools\SinScaleInject`、そうすればハードコーディングに頼らなくて済む`D:\SteamLibrary\...` ゲームのパス用。ローカルで検証済み：Releaseビルド`0 erros / 0 warnings`、クリーンなパブリッシュを行い、ゲームのパスに実際にデプロイする。 **ステータス：`Precisa Testar` ゲーム内**; リポジトリのパス (`clean-base` /`roster-dir`) は、設計上、マシンローカルのままです。[前へ：`v2.185.8.0`]
- **`v2.185.8.0` (2026-06-28) — SINパッチレビューのフォローアップ：CLIのセキュリティ強化 + ビルドフックの健全性チェック。** **PATCH**。Lane **Jarvis-SIN**。`SinScaleInject`:`--restore-area` IDの入力が必須になりました；`--seed`,`--t` そして`--intensity` 無効なものは早い段階で失敗し、明確なメッセージが示される；`--t` 不適合として却下；`--intensity` ～に限定される`0..100`;`MonsterStatSheetStruct.StatSheet` 無効化に関する警告を解除するために初期化されました。`build_hooks.ps1`: 維持する`version.res` 組み込み型 via`cl.exe` そして、もし……の場合、PolyHookのビルドを拒否する`ffx-hooks.dll` 最終的なサイズが小さくなりすぎないようにし、アーティファクトの「サイレントリグレッション」を防ぐ。レビューおよびフォローアップは以下に記録されている。`docs/ai/SIN_PATCH_REVIEW_2026-06-28.md`. [前へ：`v2.185.7.0`]
- **`v2.185.7.0` (2026-06-28) — UIの改良：柔らかな色調のカラーパレット + 選択範囲の可視化。** **パッチ**。Lane **Jarvis-UI**。StudioTokens.ax

aml: アクセント`#5DD0B4` →`#2A9D8F` （淡いティール色）、ネオン調の派手さのない、柔らかな色調で統一された塗りつぶし／枠線。StudioTheme.axaml：ListBoxItemの選択`#15323B` →`#1A3040` 1pxの枠線が表示される。選択トークン、タブ、エクスパンダー、ステータスが更新された。ビルドリリース、エラー0件。[前回：`v2.185.6.0`]
- **`v2.185.0.0` (2026-06-27) — オーバードライブ：LABの表記を削除 + フィニッシャーの各段階ごとのターゲット選択。** **マイナー**。Lane **Jarvis**。オーバードライブのオリジナルブロック内のすべての表示テキストから「LAB」を削除。 フィニッシャーシーケンスの各段階に、それぞれ独自のターゲット用コンボボックス（生存中のランダム / HPが最も低い）が追加されました。`AddOverdriveFinisherSequence` パラメータが失われた`template` そして`fallbackTarget` — 各コマンドには、すでにターゲットが指定されています。`OverdriveFinisherStep` VMクラス。ビルドエラーなし。RT0ゲート 330/330 PASS。[前回：`v2.184.1.0`]
- **`v2.185.6.0` (2026-06-27) — Sin Lab v2.1: コードレビュー + バグ修正 + 脅威の同期。** **パッチ**。Lane **Jarvis-SIN**。SinScaleInject: カーネル名は、各実行前のクリーン操作後に復元されるようになった`--area` (ProcessArea、SaveClean、RestoreAll)。SaveClean および RestoreAll は、kernel/monster*.bin にも対応するようになりました。C++ に合わせた RNG：`seed = seed ^ (seed << 16)`. g_sinPreset[93] を削除（デッドコード）。seed から time(nullptr) を削除（決定論的 RNG）。 kAreaTable (C++) および AREA_T (C#) を脅威上限の CSV と同期：14 個の値を修正、tMin=0 を常に設定、地域を追加（zanarkand、postgame、thunder_plains_cross、macalania_bosses）。[以前：`v2.185.5.0`]
- **`v2.185.5.0` (2026-06-27) — Sin Curse Lab v2: SinScaleInjectが動作するようになった + フックが簡素化された。** **パッチ**。Lane **Jarvis-SIN**。SinCurseHook.cpp：MonsterLoad、SetScaleAxis、AiQueryProperty、LaunchRestoreを削除。 btlmapフィルター。CREATE_NO_WINDOW。SinScaleInject v2はMonster_StatSheet.ReadSingle/WriteSingleを使用。リポジトリからクリーンなbinファイルを再生成。62個のDLLを管理。[以前：`v2.185.4.0`]
- **`v2.185.4.0` (2026-06-27) — Sin Curse Lab v2: AiQueryProperty を削除、SinScaleInject v2 CLI、ドキュメント。** **パッチ**。Lane **Jarvis-SIN**。AiQueryPropertyフック（RVA 0x3B2DD0）を削除 — これはFFX_Battle_AggregateActorPropertyであり、迂回処理によりメニューがクラッシュしていた。F7 Zoneサブメニューを元に戻した。 独自のVAR g_sinPreset[93] を維持。SinScaleInject v2 CLI: --ar

ea、--seed、--intensity、--save-clean (361 ビン)、--restore、--dry-run、XorShift32 RNG、HP/ステータススケーリング。ATEL インジェクションは無効化（保留中）。 ドキュメント：SIN_CURSE_LAB_SESSION_2026-06-27.md、SIN_CURSE_V2_BIN_FIRST_PLAN_2026-06-27.md。[前回：`v2.185.3.0`]
- **`v2.185.1.0` (2026-06-26) — Arena+ クロスマップの遅延復元：ランダムエンカウントのビンを破損させない。** **パッチ**。レーン **Jarvis-ARENA**。追加`ArenaPlus_ArmDeferredFileRestore` +`ArenaPlus_TickDeferredFileRestore` dllmain.cpp 内。cross-map 781D60 の起動が成功した後、約 30 秒（1800 フレーム）のタイマーを設定する。タイマーが切れると、元に戻る`.spiraforge.bak` コンパイルされたbinについて。ルート：cross-map deploy（例：Macalania Forest）は、Dark Aeonsを`mcfr00_00.bin`、これもランダムエンカウントの生成であり、ランダムエンカウントではフィエンドの代わりにダーク・イオーンが出現していた。DLLのビルドとデプロイ。[前：`v2.185.0.0`]
- **`v2.184.1.0` (2026-06-26) — Aurora Chamber: btlmap スタブのフォールバック、--portable、πフリップの削除、モンスターのTポーズ。** **マイナー**。Lane **Jarvis**。btlmap スタブ → 対応するマップへのフォールバック。 DataModel: IsMapOnlyVirtual がレンダリングをブロックしなくなりました。ExportSceneGeometry:`--portable` PNodeへの変換を適用（ジオメトリを正しい位置に配置）。ビューア：πフリップを削除（glTFはすでにY軸上向き）。モンスター：aurora-overlay.jsでTポーズ（フレーム0、アニメーションなし）。`ResolvedAreaArg` ビューアーの正しいURLへ。[前へ：`v2.176.8.0`]
- **`v2.184.1.0` (2026-06-26) — SIN UNI プリセット v2 パッチ — CounterAttack、Haste enrage、Ward Stack+、Frontline。** **パッチ**。レーン **Jarvis-SIN**。[前回：`v2.184.0.0`]
- **`v2.184.0.0` (2026-06-26) — マッシュルーム・ロックの座標の変動 + ドキュメント + 付録 D/E。** **マイナー**。レーン **ジャービス-FORM**。 マッシュルーム・ロック・ロードの遭遇地点における座標の変更。別紙D（サンダー・プレインズ）およびE（マカラニア）が`PROMPT_JARVIS_FORM_ENCOUNTERS.md`. BFによるカメラ設定のドキュメント。[前へ：`v2.183.9.0`]
- **`v2.183.9.0` (2026-06-26) — ユーザー座標 Mi'ihen + BF カメラドキュメント。** **パッチ**。レーン **Jarvis-FORM**。ユーザー手動座標を含む 8 つの mihn04 G0 フォーメーション。 FFX_ENCOUNTER_BATTLE_KNOWLEDGE.md: BFテーブル3つ (1031/1033/1034)。[以前:`v2.183.8.0`]
- **`v2.183.8.0` (2026-06-26) — mihn04 G0 ニューロード・ノース

拡張。** **PATCH**。レーン **Jarvis-FORM**。8つのフォーメーション (00-07) BF=1033、3～5体のモブ。[前回：`v2.183.7.0`]
- **`v2.183.7.0` (2026-06-26) — ユーザーによるミイヘン座標の手動編集。** **パッチ**。レーン **Jarvis-FORM**。ユーザーによる手動調整済みの16個のビン：BF=1031（後方2つ／前方3つ）、BF=1034（対角線）、BF=1033（ワイド）。[以前：`v2.183.6.0`]
- **`v2.183.5.0` (2026-06-26) — カメラ対応座標スプレッド。** **修正済み**。レーン **Jarvis-FORM**。 フロントパターン（BF=1031-1039）およびサイドパターン（BF=1040-1042）。[以前：`v2.183.3.0`]
- **`v2.183.3.0` (2026-06-26) — 全66のフォーメーションにおけるフル・ファンアウトVスプレッド。** **修正済み**。レーン **ジャービス-FORM**。[以前：`v2.183.2.0`]
- **`v2.183.2.0` (2026-06-26) — monLiveの座標が拡散。** **修正済み**。レーン **Jarvis-FORM**。[以前：`v2.183.1.0`]
- **`v2.183.1.0` (2026-06-26) — monLiveカウントおよび座標を修正。** **修正済み**。レーン **Jarvis-FORM**。monLiveカウントと66ビンのフォーメーションスロットとの同期。[以前：`v2.183.0.0`]
- **`v2.183.0.0` (2026-06-26) — サンダー・プレインズが拡張（7ビン）。** **マイナー**。 レーン **Jarvis-FORM**。kami00 South（4フォーマット）、kami03 North（3フォーマット）。プール：Aerouge、Melusine、Buer、Kusariqqu、GoldElm、IronGiant、Larva。[前回：`v2.182.2.0`]
- **`v2.182.2.0` (2026-06-25) — ムーンフローの調整。** **パッチ**。レーン **Jarvis-FORM**。genk00_01/+Garm、genk00_02/+BiteBug、genk00_03/+2Bunyip。Steamに59個のビンをデプロイ。[前回：`v2.182.1.0`]
- **`v2.182.1.0` (2026-06-25) — Moonflowの拡張 + 付録C.** **MINOR**. レーン **Jarvis-FORM**。genk00 (6 fmts)、genk16 (5 fmts、Treasure Chestの模倣)。[前回：`v2.182.0.0`]
- **`v2.182.0.0` (2026-06-25) — Djose Highroadが拡張されました。** **MINOR**。レーン **Jarvis-FORM**。kino04 G0 Shade (5フォーマット) + G1 Sunlight (8フォーマット)。+SnowFlan 25/26。[前回：`v2.181.1.0`]
- **`v2.182.1.3` — 最終同期：MonsterMagicGrowWriter、SinCurseHook、Arena+ エンカウンター・ピン・キューのG/Fリーク修正。** **パッチ**。レーン **Jarvis-SYNC**。MonsterMagicGrowWriter：12個のODレシピ。SinCurseHook：ランタイムC++の改善。 **Arena+ dllmain：ピンが解除された後にRVA_BATTLE_QUEUE_GROUP/FORMATIONをクリアし、キャリアのG/Fが同じフィールド内のランダムエンカウントに漏れ出るのを防止 （例：マカラニア湖 フィールド=340 + キャリア mcyt00_22 フィールド=340

 （通常のフィエンドの代わりにダーク・イオーンを生成していた）。** a_ability.bin にパッチを適用。monmagic1.bin を同期。DLLのビルドとデプロイ。[以前：`v2.182.1.2`]
- **`v2.182.1.2` — Sync: ユーザーの monmagic2 + 正しい OD ビン。** **PATCH**。レーン **Jarvis-SYNC**。ユーザーのオーバードライブ・ビンを同期します。[前:`v2.182.1.1`]
- **`v2.182.1.1` — モンスター・オーバードライブのスキル + バックアップテキストプールの修正。** **パッチ**。 レーン **Jarvis-MONMAGIC**。ODスキル15個（0x60F7..0x6105）、バックアップテキストプールの修正、モッドスキル12+3個、エリア6つ。[以前：`v2.182.1.0`]
- **`v2.182.1.0` — モンスターのリバランス + a_ability + monmagic2 OD + SinCurseHook。** **マイナー**。レーン **Jarvis-MONSTER**。 約60体のモンスターのバランス調整。a_ability.bin AU1-AU7。monmagic2：4つのODスキル。SinCurseHook C++ランタイム。[以前：`v2.182.0.0`]
- **`v2.181.1.0`/`v2.179.0.0` — ランダムエンカウント拡張（ミイヘン、マッシュルームロック、ジョゼ・ハイロード）。** **マイナー**。レーン **ジャービス-FORM**。ランダムエンカウントのパターン48種が、敵2～3体から4～5体に拡張されました。 ルカ戦後のミイヘン：16個のビン（mihn07/mihn04/mihn05）。 マッシュルームロック：19個のビン（kino00/kino01/kino05/kino07）。 ジョゼ・ハイロード：13個のビン（kino04 G0=Shade G1=Sunlight）。 ドキュメント：`docs/ai/PROMPT_JARVIS_FORM_ENCOUNTERS.md` （別紙A／B／C）、`FFX_ENCOUNTER_BATTLE_KNOWLEDGE.md`. [前へ：`v2.181.1.0` /`v2.179.0.0`]
- **`v2.181.0.1` — Arena+ MusicHook：戦闘から逃げても音楽が止まらない問題を修正。** **パッチ**。レーン **Jarvis-ARENA**。`ConsumeArenaBattleMusicPending()` 曲の切り替えを行う3つのshim（PlayTrack、SwitchCrossfade、PlayTrackWithPreload）に追加しました。ルート：`g_arenaBattleMusicPending` オーバーライドを適用した後は決して再生されなかったため、フックから抜け出すとフィールド音楽が再びボステーマに戻ってしまう。DLLのビルドとデプロイ。[前：`v2.181.0.0`]
- **`v2.179.0.3` — マッシュルームロックのモンスターバフ + monmagic2のODスキル（スナイプ、フェザーストーム）。** **パッチ**。レーン **ジャービス**。 ラプター／ガルーダ／ガンダレワ／ラマシュトゥ／レッドエレメント／フングアール：HP、STR、MAG、AGI、AP、ギルのブースト。monmagic2.bin：スナイプ（0x60FE）＋フェザーストーム（0x60FF）。 レガシーMODの361個のbinファイルを同期。[以前：`v2.179.0.2`]
- **`v2.179.0.2` — 旧MOD（D:\FFX Mods\）** **PATCH** 内の361個のモンスタービンをすべて同期。レーン・**ジャービス**。旧MODからm000～m360をすべてコピー（20

24) リポジトリ向け。これには、すでに適用済みのステータスのリバランスがすべて含まれます。[以前：`v2.179.0.1`]
- **`v2.179.0.1` — シンスポーン・グイ フェーズ2 (m118): STR 20→28, MAG 20→26, AGI 10→16, ACC 30→80.** **パッチ**。レーン **ジャービス**。[以前：`v2.179.0.0`]
- **`v2.179.0.0` — ロード・オチュ + シンスポーン・グイのバランス調整：HP、AP、ドロップ率の向上。** **パッチ**。レーン **ジャービス**。 ロード・オチュ (m153)：HP 9999→15000、AGI 8→14、AP 120→300、APO 300→900。 グイ F1 (m117)：AP 400→1200、APO 600→1800、ドロップ量2倍。 グイ F2 (m118): HP 6000→9000、AP 0→300、APO 0→450、ギル 0→500、ドロップ＋オーバーキルが追加されました。[以前:`v2.178.0.0`]
- **`v2.178.0.0` — monmagic2 ODスキル + モンスター再調整ドキュメント。** **マイナー**。レーン **Jarvis**。monmagic2.bin: Gore Charge (0x60FC)、Fang Strike (0x60FD)。 MonsterMagicGrowWriter: AppendGoreCharge、AppendFangStrike、AppendSnipe、AppendFeatherStorm。MONSTER_REBALANCE_SUMMARY.md: 完全な比較表（バニラ→MOD、約60体のモンスター）。 VANILLA_VS_MOD_MONSTER_STATS.md: 完全な比較表。[以前:`v2.175.1.0`]
- **`v2.176.8.0` — AGSデコーダー：textureanimation.ags.phyreパーサー + 生データスキャン（11フレーム）。** **マイナー**。Lane **Jarvis**。`PhyreTextureAnimationDecoder.cs`: PTextureAtlasInfo、PSubTextureInfo、PSpriteAnimationInfo を含む RYHPT PBinary ファイルをデコードします。テクスチャアトラスからアニメーションフレームを抽出します。エクスポートパイプラインに統合されています。PTexture2D レイアウトの RE 待ちの PNG アトラス。[前:`v2.176.6.0`]
- **`v2.176.6.0` — ComposeWorldMatrix のネイキッドフック + ApplyQueued の修正 + ヘビーフックの安定化。** **パッチ**。Lane **Jarvis**。ComposeWorldMatrix をヘビーフックから削除（毎フレーム呼び出され、値はゼロ）。 SetupSceneNodeがBindMaterialTextureSamplerであることが確認された（IDA）。ApplyQueuedはワーカースレッドで即座に実行される（遅延なし）。ヘビーフック（WireInstance + CommitInstanceMappings）はクラッシュすることなく安定している。[以前：`v2.176.4.0`]
- **`v2.176.4.0` — field172 ノーマルマップ + スペシャルレーンスキャナー + 復元されたMOD。** **パッチ**。レーン **Jarvis**。field172 が追加の PAssetReference リンクをキャプチャ。スペシャルレーンスキャナー：`ScanSpecialLaneTextureRefs` tex/用の .dae.phyre を読み込む<name>.dds COLLADA のソースパス。Mods Spira Reforge + FFX_Data + ffx_ps2 を復元。[以前：`v2.176.2.0`]
- **`v2.176.2.0` — バーテックス社

優先度 + インフラの法線マップ + バインディング。** **パッチ**。レーン **ジャービス**。頂点カラー：テクスチャのないサブメッシュは、頂点ごとのカラースストリームを使用します。法線マップ：`DescriptorGltfMaterialTexture` com`NormalMapPngPath`, writer は発行する`normalTexture` glTF内。PParameterBufferへの追加のDDSインポートによるバインディング。[以前：`v2.176.1.0`]
- **`v2.176.1.0` — glTFからKHR_materials_unlitを削除（PBRシェーディング有効）。** **パッチ**。Lane **Jarvis**。すべてのマテリアルで`KHR_materials_unlit` — 照明なし。現在は、Three.jsのネイティブPBRにHemisphereLightとDirectionalLightを組み合わせて使用しています。flipVを修正しました。[以前：`v2.176.0.0`]
- **`v2.176.0.0` — MinHook の移行 + WireInstanceToSceneNodes + C1-C3 のバグ修正。** **マイナー**。 Lane **Jarvis**。PolyHook → MinHook (MH_CreateHook + MH_ApplyQueued、スレッドセーフ)。WireInstanceToSceneNodes (0x65B0F0)：PMeshInstance↔PNodeのマッピングエントリ447件。 CommitInstanceMappings (0x65A850): 条件付きフック。C1: デトール間のシャットダウンチェック。C2: g_currentArea/Fieldのアトミック読み取り。C3: トレーススレッドでのタイムアウト＋リトライ。RVAを修正。[以前:`v2.175.1.0`]
- **`v2.175.1.0` — a_ability.bin マスターテーブルパッチ + SinCurseHook + OD スプレッドシート。** **マイナー**。Lane **Jarvis**。a_ability.bin：AU1～AU7（inflict、resist、elemental、auto-status、customize、compatibility）でパッチ適用済み。 SinCurseHook: SINの呪いフィールド遷移用のランタイムC++フック。SinCompatibilityMatrix + SinCurseSidecarIO。monster-od-master-spreadsheet.csv: 12体のモンスターによるODパイロット。マカラニアのSIN名簿。[以前:`v2.174.2.1`]
- **`v2.174.2.0` — カスタムミックス：ラベル「Remiem Temple」→「Mushroom Rock Road」（C++メニュー）。** **パッチ**。レーン **Jarvis-ARENA**。 ゲームのメニュー（x3/x4/x5）に表示されるラベル名を、C++フックで「Remiem Temple」から「Mushroom Rock Road」に変更します（`ArenaPlusComposePick.cpp`) およびログ (`dllmain.cpp`). 技術的な鍵`remiem` 変更はありません。C# (`BattleComposeRunner.cs`) すでに正しいラベルが付けられ、behind-partyカメラが適用されていました。DLLのビルドとデプロイが完了しました。[前回：`v2.174.1.0`]
- **`v2.174.1.0` — カスタムミックス×3：シナリオ「Remiem」（kino00_00）の配置。** **PATCH**。レーン **Jarvis-ARENA**。シナリオにおける不整合を修正`remiem` ～することに決めた`kino00_70` C++では（エラーを引き起こし）

（Custom Mix x3）で割り当て/拡張が拒否されました）および`kino00_00` C#で。これで正しく`kino00_00` (Mushroom Rock Road) 両方に。[前へ：`v2.174.0.0`]
- **`v2.174.0.0` — キマハリのランセット・デュアル・グラント・フック（ロンソ OD → ブルーメイジ MP）。** **マイナー**。レーン **ジャービス-MAGIC**。`KimahriLancetDualGrantHook` +`kimahri_lancet_dual_grant.flag`: ランセット「Learn-on-Use」104–115、グランタ・クローン 323–334 + メニュー`#322`; GridTeach経由のサイドカー。Demita/Lancet+はグリッド上にのみ残る。[前へ:`v2.173.0.2`]
- **`v2.173.0.2` — キマハリ・ブルーマジック：ドナー #276 スペシャル（#282 ロンソではない）、サブ=14 (+232)。** **パッチ**。 レーン **ジャービス-MAGIC**。RT2：オープナーがロンソ・レイジを複製していたため、メニューを開くとODが発動していた；フックが+296で104–115を再注入しなくなる。[以前：`v2.173.0.1`]
- **`v2.173.0.1` — カスタムミックス x4 ビカネル：絶対スプレッド ×2.65 (Jarvis-ARENA)。** **PATCH**。RT2 aeons Dark はカメラはOKなのにまだくっついている — 合成グリッド + パーティーの向きがX/Z方向に圧縮されている。Composeは現在、monLive vanillaのスケールに合わせている`nagi05_24` 重心（フォールバック・レシピ・カルテット）を起点として、絶対座標を`bika02_01`、ボスからのナッジなし；xSpan ~185 (±93)。F7 → **ビルド + 起動**。[前：`v2.173.0.0`]
- **`v2.173.0.0` — GridTeach extMenu フック：キマハリのブルーマジック（#322）＋ユナのホワイトマジック+（#366）。** **MINOR**。レーン **Jarvis-MAGIC**。`GridTeachHook` v4.5 以降`BuildActorCommandMenu`: リング間のアクター横断スクラブ（+296 ケース4 + その他のバケット） + オープナー／学習済み子ノードの挿入；定数`#322/#366` で`ffx_addresses.h`. リビルド`ffx-hooks.dll` +`grid_teach.flag`. RT2 保留中。[前回：`v2.172.0.7`]
- **`v2.172.0.7` — Lulu Multi-*: ランダムなターゲットに3回命中（Allではない）、MP180。** **パッチ**。レーン **Jarvis-MAGIC**。`#337–340` `SetRandomEnemyHits` （Fury仕様）；`MultiGaMpCost=180`; RT0`RandTgt`. [前へ：`v2.172.0.6`]
- **`v2.172.0.6` — ワッカキット：引退したツインリール；ジンクスボール P16/MP200；クワッドファウルポイズン＋MP180。** **パッチ**。レーン **ジャービス-MAGIC**。`#351` 未使用；`#352` ジンクス・ボールの寄付者`#13` スキルリング P16 MP200;`#350` クワッド・ファウルの説明 + ポイズン 3ターン MP180；サイドカー ワッカ＝`350,352`. RT0 PASS 367行。[前：`v2.172.0.5`]
- **`v2.172.0.5` — ティダス・キット：ブレードストームのみ`#358` (P16、MP180、3ヒット・シングル)。** **PATCH**。レーン *

*Jarvis-MAGIC**.`#356`/`#357` リタイア（未使用）；ドナー・ディレイ・アタック`#6` (Quick Hitなし); サイドカー・ティダス=`358`. [前へ：`v2.172.0.4`]
- **`v2.172.0.0` — Yuna White Magic+ メニューオープナー (#366) — Blue Magic標準、スペシャル外。** **MINOR**。レーン **Jarvis-MAGIC**。Append`#366` メインリング上の「White Magic+」（ドナー`#278`,`MainMenu+OpenCommandMenu`); 娘たち`#343–347` から移行する`sub=14` (Special) 向け`sub=4` (+296、アクターごとのバッファー — キマハリのロンソとは独立)。GridTeach bound`367` 行。Sidecar Yunaには以下が含まれます`#366`. RT2 保留中。[前回：`v2.171.0.16`]
- **`v2.171.0.16` — カスタムミックス×4：Anima-safe（Jarvis-ARENA）を適用。** **PATCH**。Animaを搭載したRT2 Bikanelクワッドがクラッシュした — ナッジ`x*=0.50` 中心方向へ引っ張る；グリッド ±68 / Z 128–186、アニマのみ +Z 深部。F7 → **ビルド + 起動**。[前：`v2.171.0.15`]
- **`v2.171.0.15` — Spira Reforge command.bin 作成者：Biora Lulu、MPリバランス、ティダスの自己バフ、ワード無効化。** **パッチ**。レーン **Jarvis-MAGIC**。`#348` ビオラ → ルル（ポイズン＋フィラガ級のダメージ）；`#349` Sleepraが無効化されています；`#350` クワッド・ファウル＋ポイズン MP56；ドレイン／オズモス-ga／ユナ *ga／オーロン マス MP↑；`#356–358` `FlagTargetSelfOnly` (RT2 保留中);`#320–321`/`#359` 未使用；サイドカー`Lulu=337..342+348`,`Wakka=350..352`,`Tidus=356..358`. RT0 PASS 366行。[前：`v2.171.0.14`]
- **`v2.171.0.14` — カスタムミックス×4：より広くて深いスプレッド（Jarvis-ARENA）。** **PATCH**。RT2 バイチャンネルカメラ OK；aeons はパーティー内および互いに密着。chunk3 monLive：翼 ±58 / Z +20、内列 ±30、中心 Z 142；Valefor/Yojimbo/Ixion/Shiva の位置を微調整し、オーバーラップを軽減。 F7 → **ビルド + ローンチ**。[前回：`v2.171.0.13`]
- **`v2.171.0.10` — GridTeach v4.4：フィールドで「ステータス」を開いた際のステータスリセットを修正。** **パッチ**。レーン **Jarvis-MAGIC**。`786BC0` (`PrepareSaveCommandState` =`InitPlySaveMenuPanel`) テンプレートを再読み込み中`ply_save` +`A53DE0` 「ステータス/装備」メニューでは、HP/Strがベース値に戻っていた（S.Lvはそのまま）。v4.3ではこの迂回処理が削除されていた（バニラ版は引き続き動作していた）。修正：迂回処理を**戦闘時のみ**に限定（`sub_7817D0` return-addr ゲート) + skip`A53DE0` FullGridCompilerにおいて、すでにデータが入力済みのグリッドを保存する際；guard`786BC0` FullGridでGridTeachをオフに。**RT2 PASS** (Halyson)。[前：`v2.171.0.9`]
-

**`v2.171.0.13` — Mod docs: 無効化 ≠ command.bin から削除。** **REVISION**。Lane **Jarvis-MAGIC**。366 行を引き継ぎ；`#320–321`/`#359` 無効化されても、行は残ります。[前へ：`v2.171.0.12`]
- **`v2.171.0.9` — スパイラ・リフォージ・エクステンデッド：物理マルチヒット、低P／高MP。** **パッチ**。レーン **ジャービス-MAGIC**。ツイン・リール／ジンクス・ボール、ムグラ／ムガ、ティダス`#356–358`. [前へ：`v2.171.0.8`]
- **`v2.171.0.8` — Multi-* Lulu：数式`SpecialMagic` (15) 代わりに`IgnoreMagicDefense`.** **パッチ**. レーン **Jarvis-MAGIC**. RT2後のロック・ハリソン（Fire Breath BMはDark Aeonに対して有効）。`#337–340` P62/MP80/3ヒットのままだ。[前回：`v2.171.0.7`]
- **`v2.171.0.7` — Spira Reforge extended: Multi-* P62/MP80/3ヒット；物理マルチヒットの微調整。** **パッチ**。レーン **Jarvis-MAGIC**。`#337–340` MP 64→80；ヒット数 6→3；明示的なP 62。ティダ／リク／ワッカのマルチヒット：パワー／ヒット数が減少。RT0 PASS。[前回：`v2.171.0.6`]
- **`v2.171.0.6` — Yuna *ga：サブメニュー「Special」（ホワイトリング 24/24 満タン）。** **PATCH**。レーン **Jarvis-MAGIC**。`#343–347` `sub 2→14` (+232、32スロット); ライター`SetPartySpecialSubMenu`. [前へ：`v2.171.0.5`]
- **`v2.171.0.5` — ティダスの拡張スキル：サブメニュー「スキル」（オーバードライブではない）。** **パッチ**。レーン **ジャービス-MAGIC**。ドナー OD`#96/97/99` 受け継いでいた`SubMenu=4` (+296 ODリング);`#356–359` 今`sub=3` Skill. Bin へ`work/`, mod`jppc`+`new_uspc`, Steam。[前へ：`v2.171.0.4`]
- **`v2.171.0.5` — スパイラ・リフォージ：ワッカのリワークにより、ツインリール＋ジンクスボールがロックされる；スリープラ候補。** **改訂**。レーン **ジャービス-MAGIC**。`EXTENDED_COMMANDS_REWORK_QUEUE_2026-06-23.md` — Silencegaは却下されました；#349 A/B/C。[前回：`v2.171.0.4`]
- **`v2.171.0.4` — Spira Reforge：キューのリワークに関する拡張コマンド（RT2 Halysonからのフィードバック）。** **改訂**。レーン **Jarvis-MAGIC**。ドキュメント`mods/Spira Reforge/EXTENDED_COMMANDS_REWORK_QUEUE_2026-06-23.md` — ルル：マルチ3ヒット＋MP吸収；ワッカ／ティダ／オーロン／ユウナのチューニング；敵へのバフ発動バグ（ティダ）。 [前回：`v2.171.0.3`]
- **`v2.171.0.3` — GridTeach v4.2 + 拡張パック：CharacterUserフィルター + 正しいサブメニュー。** **パッチ**。Lane **Jarvis-MAGIC**。`HasCommandBit` 尊重する`CharacterUser` カーネル内（party bank + shadow 352+）；ライター`SetOwned` 無理に押さないで`MainMenu` nas skills (so #322 m

enu opener）。[前へ：`v2.171.0.2`]
- **`v2.171.0.2` — GridTeach v4.1：攻撃／切り替えの不具合を修正（別名 actor+0x690）。** **パッチ**。レーン **Jarvis-MAGIC**。アクターのシャドウシードを削除；detour経由でID 352以上`HasCommandBit`. [前へ：`v2.171.0.1`]
- **`v2.171.0.1` — カスタムミックス Bikanel：カメラ chunk0`nagi05_24` + スプレッド・パーティー・ロウ（Jarvis-ARENA）。** **パッチ**。RT2の砂漠はOKだが、カメラの位置がランダム`bika02_01` 表示されていたのは1つのイオーンだけだった；ワイド・ポーラー・ノー・ロータ・フレーミング。マカラニア・オープンと同じパターン：ドナー・クワッドのATELからチャンク0をグラフトし、パーティー列に基づいてチャンク3をスプレッドした。`nagi05_24`; ステージは続く`bika02_01`. F7 → **ビルド + 実行** が必須です。[前へ：`v2.171.0.0`]
- **`v2.171.0.0` — GridTeach v4: 拡張コマンド RT2 grant (#322–365)。** **マイナー**。レーン **Jarvis-MAGIC**。`GridTeachHook` メニュー・バウンド366、迂回路`BuildActorCommandMenu`, サイドカー 18語（シャドウID 352以上）、スクリプト`RuntimeTools/SpiraReforgeRt2/set-grid-teach-sidecar.ps1`. Doc`FFX_GRID_TEACH_EXTENDED_BANK_WIDEN_2026-06-23.md`. [前へ：`v2.170.0.17`]
- **`v2.170.0.17` — カスタムミックス・ビカネル：781D60 トークン・ビカ`0x01600001` (Jarvis-ARENA)。** **PATCH**。RT2ログ：`MsBattleEncountExe` ret=-1 だが`n2` 2を見たことがない — 戦闘が始まらない；ただ`781D60` 列に並ぶ。Bikanel cross-map: deploy`bika02_01` +`781D60(0x01600001)` + pin（FGFではない、nagiトークンではない）。[前回：`v2.170.0.16`]
- **`v2.170.0.16` — カスタムミックス：FGF deferred + Remiem コンポーズ修正 (Jarvis-ARENA)。** **パッチ**。 即時FGFのBikanelは戦闘を開始しなかった（ティック前にforce-gateがオフになっていた）；SetBattleFlags+pinによる遅延起動。Remiem x3：`kino00_00` (grow OK) の代わりに`kino00_70` マルチエリア。[前へ：`v2.170.0.15`]
- **`v2.170.0.15` — Spira Reforge：キャラクターごとのRT2グラント拡張コマンドガイド。** **改訂版**。レーン **Jarvis-MAGIC**。Doc`mods/Spira Reforge/EXTENDED_COMMANDS_RT2_GRANT_GUIDE.md` — 地図`#322–365`, ブルーマジック・キマリ（メニュー`#322` + サブメニュー 14）、GridTeach サイドカー（パック単位）。[前へ：`v2.170.0.14`]
- **`v2.170.0.14` — カスタムミックス Bikanel：ネイティブ FGF のリリース（nagi トークンではない）（Jarvis-ARENA）。** **パッチ**。ログで実証済み`781D60(0x01AE0017)` 常にナギの洞窟への列を書き換える (`fieldHi=63`); backdrop/pin nagiのハックは失敗していた。Bikanel: d

eploy`bika02_01.bin` +`MsBattleEncountExe(47/0/1)` + ピン；洞窟は続く`nagi05_23`+token。[前へ：`v2.170.0.13`]
- **`v2.170.0.13` — スパイラ・リフォージ：キマハリ・ランセット・デュアル・グラント §10.17（デザインロック）。** **改訂**。レーン **ジャービス-MAGIC**。ランセット +`RonsoRageId` モンスターから → OD + ブルーメイジのMPを合わせて；フックTODO。Doc`FFX_KIMAHRI_LANCET_DUAL_GRANT_RESEARCH_2026-06-23.md`. [前へ：`v2.170.0.12`]
- **`v2.170.0.12` — カスタムミックス・ビカネル：ビジュアルバックドロップ（Jarvis-ARENA）前のロスター。** **PATCH**。RT2ログ：ティックで`field=47` ロード中に再解決していた`bika02_01` (アルキオネなど) 複合語「bin」を無視。現在のクロスマップ：ピン`nagi05_23` + G/F ～60フレームはビジュアルパッチなし；ティック後にのみ`field=47 bf=1049` メッシュ・デセルトへ。[前へ：`v2.170.0.11`]
- **`v2.170.0.11` — Spira Reforge：ダブル／トリプルドロップの自動能力 §10.16 + フックドキュメント** **改訂**。レーン **Jarvis-MAGIC**。 新しいAA ID 129–130（アイテム数量×2/×3）；フック`DoubleTripleDropHook` coded; 窃盗／強盗／賄賂　未定。 [前回：`v2.170.0.10`]
- **`v2.170.0.10` — スピラ・リフォージ：オメガ遺跡のエンドゲーム周回 §15.** **改訂版**. レーン **Jarvis-MAGIC**. 場所 = 難易度の高いファーム；戦利品/ギル/AP/宝箱 ↑；超強力なボス；隔離されたロスター（共有プレイヤーは削除済み）；1体目のボス → 撃破後にランダムで弱体化。スペック`OMEGA_RUINS_ENDGAME_FARM_SPEC.md`. [前へ：`v2.170.0.9`]
- **`v2.170.0.9` — カスタムミックス・ビカネル：ピン`nagi05_23` + ビジュアル背景 47/1049 (Jarvis-ARENA)。** **PATCH**。RT2ログで実証済み`781D60` キューを書き換えて`fieldHi=63 formation=3` (caverna vanilla); bf-onlyではシナリオもロスターも変更されない。キャリアのG/Fを回復し、ピン`g_FFX_Battle_EncounterName`, 視覚的なチェックマーク`field=47 bf=1049`. [前へ：`v2.170.0.8`]
- **`v2.170.0.8` — スパイラ・リフォージ：SINスキル（SIN発動時のみ）＋ルカ後のOD（§13.2）。** **改訂**。 レーン **Jarvis-MAGIC**。SINの効果下でのみ発動する**新たな**モンスタースキル（VFXの色変更）；ルカ後のオーバードライブはエリアあたり約1～2回、SINとは**無関係**で、その大半が**新たな**スキルとなる。[以前：`v2.170.0.7`]
- **`v2.170.0.7` — 『Spira Reforge』：第13節 — フォーメーション対`m###` （ボス戦は編集済み、追加要素なし）。** **改訂**。レーン **Jarvis-MAGIC**。§13.1の明確化：v0.1ではすでにボスのバランス調整が行われており、`m###`/AI; §13は**試合の登録メンバー**のみを制限する（セイモウは対象外）

r + 4 回追加）；5 = **randoms** に展開。[前回：`v2.170.0.6`]
- **`v2.170.0.6` — カスタムミックス Bikanel：BF専用デザート + カメラワイド（グラフトなし）（Jarvis-ARENA）。** **パッチ**。
- **`v2.170.0.5` — Spira Reforge：戦闘範囲 — ランダムエンカウントを編集済み、ボスはSINモードのみ。** **改訂**。レーン **Jarvis-MAGIC**。 §13.1：**ランダムエンカウント**（最大5体の敵）に特化した恒久的なフォーメーション/bin；**ストーリーのボス**のbinは変更なし；ボスレイヤーは**SIN**トグルのみ（§5.6）。[以前：`v2.170.0.4`]
- **`v2.170.0.4` — 『Spira Reforge』：対戦相手が最大5体まで拡大（デザイン確定）。** **改訂**。レーン **Jarvis-MAGIC**。
- **`v2.170.0.3` — カスタムミックス・ビカネル：エイオン・ワイド・グラフトカメラ`nagi05_24` (Jarvis-ARENA)。** **PATCH**。砂漠のステージ`bika02_01` バックドロップ／パーティーアンカーを維持；chunk0 ATEL（バトルカメラ）はドナー・クワッドから供給される`nagi05_24` 経由`BattleChunk0GraftWriter` — 4体の巨大なダーク・エオン相手では、ランダムエンカウンター・カメラは通用しなかった。F7 → 展開後は「ビルド」＋「発射」が必須。[以前：`v2.170.0.2`]
- **`v2.170.0.2` — カスタムミックス・ビカネル：テンプレート`bika02_01` FGF 47/0/1 (Jarvis-ARENA)。** **PATCH**。RT2 バトルスナップショット Halyson：desert random =`bika02_01` @ idx **47** bf **1049**、いいえ`bika03_03` @ 48/0/3 (サンドワーム)。コンポーズ + メタデータが整合済み；ドキュメント`FFX_ARENA_PLUS_BIKANEL_BIKA02_RT2_2026-06-23.md`. [前へ：`v2.170.0.1`]
- **`v2.170.0.1` — カスタムミックス：シナリオのランタイムパッチ（Jarvis-ARENA）を無効化。** **PATCH**。RT2ログ：ティックで`field_idx=36` (マカラニアの森) バニラテーブルを再解決 → キメラ。Composeはすでにシナリオのテンプレートをキャリアのbinに書き込んでおり、launchはトークンをキューに入れるだけ`781D60`. パッチ`@0xD2C254` 現在はオプトイン（`arena_plus_scenario_backdrop.flag`). [前へ：`v2.170.0.0`]
- **`v2.170.0.0` — Field Tier C1: PMeshInstance マップ + glTF インスタンスグループ + FieldPack ファクトリ (Jarvis-FIELD-RE)。** **マイナー**。`ParseInstanceMap()` →`{assetId}.phyre-instance-map.json`;`DescriptorStaticGltfWriter` flag`--instance-group`; PNode 親チェーン・ワールドのオフライン合成;`RuntimeTools/FieldPackFactory/` (`build-field-pack.ps1`,`mount-work-for-mapviewer.ps1`,`build-fieldpack-chr-subset.ps1`); MapViewer`window.__fieldExplorerReady`;`ffx_addresses.h` 修正する`0x6F6D40` + RVA

 `0x65B0F0`. [前へ：`v2.169.0.2`]
- **`v2.169.0.2` — Spira Reforge: ステータスグリッド補償パッケージB（インプレースパネル）。** **改訂**。レーン **Jarvis-MAGIC**。 §12.1.1のロック：STR–LCKティアを+1引き上げ；HP 200→250 / 300→400；MP 標準値 = +20/+40（49+7ノード）→ +25 / **+60**（`up_value` 8→12 in`0x24`); ルートAのみ`panel.bin`. [前へ：`v2.169.0.1`]
- **`v2.169.0.1` — カスタムミックス Bikanel：BF専用クロスマップ + 音楽 Arena+ (Jarvis-ARENA)。** **パッチ**。RT2のログにより、再パッチが`field_idx=48` ロード中に解決していた`bika03_03` （サンドワーム）を、コンポジットの代わりに`nagi05_23`. クロスマップ（Bikanel/Remiem）は現在、パッチのみ`battlefield_id` (LOWORD @`0xD2C254`); キャリア`field_idx` 変更なし；chunk0/cameraはcomposeのテンプレートに既に含まれている。 MusicHook: 45秒待機、Prep/Play/SwitchCrossfadeをインターセプト（フィールドトラック21を除く）、1回目のヒットでは消費しない — オーバーライド145後のvanilla 138を回避。[以前:`v2.169.0.0`]
- **`v2.169.0.0` — Field Explorer CHR モデル + PNode オフラインデコード (Jarvis-FIELD-RE)。** **マイナー**。MapViewer が glTF ベイク済みデータを読み込もうとする (`/work/*_anim`) CHRピン；より大きなピン＋ラベル；PhyreMapExportLabは以下を出力します`phyre-scene-graph-report.json` + フラグ`--node-per-object`. [前へ：`v2.168.0.0`]
- **`v2.168.0.0` — Field Explorer：シーンノード + 店舗／小屋のプロキシ (Jarvis-FIELD-RE)。** **マイナー**。WalkManifest が読み込み`sceneNodesPlaced`; MapViewerのオーバーレイが、Phyreレイヤーとプロップ用の3Dプロキシを描画する`f###`; Field Scoutがフックを再有効化`ComposeWorldMatrix`/`SetupSceneNode` 戦闘中にスキップ。[前へ：`v2.167.0.6`]
- **`v2.167.0.6` — カスタムミックス：スプレッドに「Magus (+3)」を組み込んだフィックスコンポーズ（Jarvis-ARENA）。** **パッチ**。`AssignSpreadPositions` ピックのカウント（3）と5人のアクターからなるグリッドを使用していた → クラッシュ`role grid mismatch` (exit 3762504530)。これで、スプレッド上のMagusが3スロット分拡大される。[以前：`v2.167.0.5`]
- **`v2.167.0.5` — カスタムミックス Bikanel/Remiem：クロスマップの背景 + キャリアピン（Jarvis-ARENA）。** **PATCH**。トークン`nagi05_23` compose を使用しても、フィールド 63（Cavern）が強制されていた`bika03_03`. Cross-map、パッチが適用されました`field+bf` 背景＋ピン`g_FFX_Battle_EncounterName` 複合キャリア内（無傷のダーク・イオーン）。[前：`v2.167.0.4`]
- **`v2.167.0.4` — F7 Arena+：Enterキーのデバウンス（メニュー＋com

ポーズ) (Jarvis-ARENA)。** **パッチ**。 サブメニュー/戦闘開始時のクールダウン（ハブ10f、コンポーズ24f）；Aeonのトグルを高速化（7f）；Launch/Relaunchを遅く（28f）。Edge-latchにより、Enterキーを長押しした際に誤った行に入力されるのを防止。[以前：`v2.167.0.3`]
- **`v2.167.0.3` — Spira Reforge: grid wire — ステータス値のみ再利用（バニラ状態のスキルはそのまま）。** Lane **Jarvis-MAGIC**。**REVISION**。Halyson: ステータス値約44がスキルの教えに変わった`#322–365`; バニラのスキルノードは**変更されません**；バンプで調整してください`IncreaseAmount` 残りの統計（未定）。Doc`VISION_AND_ROADMAP.md` §12.1. [以前：`v2.167.0.2`]
- **`v2.167.0.2` — カスタムミックス x4 Bikanel：fix Sand Worm vanilla hijack (Jarvis-ARENA)。** **パッチ**。ランタイムパッチ`field_idx=48` 再解決していた`bika03_03` （サンドワーム）がトークンの上にいる`nagi05_23`. クロスマップ（Bikanel/Remiem）→ bin compose でのシーン（`bika03_03` chunk0); field=63（Cavern）の場合にのみFGFをパッチ適用。[前回：`v2.167.0.1`]
- **`v2.167.0.1` — カスタムミックス x4/x5：バックドロップ Bikanel/Cavern/Remiem ＋ カメラ aeon-wide (Jarvis-ARENA)。** **PATCH**。`ScenarioBattlefieldIdForKey` マカラニアしかいなかった → ミックス×4 ビカネルはバニラに落ちていた`bika03_03` （砂漠の機械）。現在、bf=1049/1080/1035 + ビジュアルのみのパッチ；lab x4/x5ではキャリアの広角カメラを使用（`nagi05_24`/`_50`) ダーク・イオーンズに有利なオッズ。[前回：`v2.167.0.0`]
- **`v2.167.0.0` — Monster AI Editor: ATEL scaleOwnSize（Jarvis-MAGIC）を適用。** **MINOR**。カード「YUNALESCA」が適用される`scaleOwnSize` (0x7028) DeathAnimation終了後のinsert経由、または既存のfloatプールを乗算；ショートカット +10%/+80%；スクリプトの現在の均一スケーリングを読み取る。[以前：`v2.166.0.16`]
- **`v2.166.0.16` — カスタムミックス x4/x5：空のシナリオ行を削除（Jarvis-ARENA）。** **PATCH**。メニューには4つの固定スロットが確保されていたが、シナリオが3つのティアでは、ボス戦の前に空白のバーが表示されていた。動的なレイアウトによる`g_scenarioCount`. [前へ：`v2.166.0.15`]
- **`v2.166.0.14` — カスタムミックス・フォレスト：ポストトークン・バックドロップのキューパッチ（Jarvis-ARENA）。** **PATCH**。`781D60` 運んでいた`mcyt00_22` FGF 36/mcfrを無視していた；DLLの再パッチ適用`dword_112C254` + シナリオがデフォルトでない場合、トークンの前後にバトル名を追加する。[以前：`v2.166.0.13`]
- **`v2.166.0.13` — フィールドスカウト：pr

ep/finish walk one-shot + auto-ingest (Jarvis-FIELD-RE).** **PATCH**.`prepare-field-scout-walk.ps1` (ULTRAビルド、検疫フラグ、NativeMenuオフ) +`finish-field-scout-walk.ps1`; エディター「Publicar Scout」は新しいセッションを自動的に読み込みます。[前へ：`v2.166.0.12`]
- **`v2.166.0.12` — カスタムミックス「マカラニアの森」：mcfr00 + tableIndex FGF (Jarvis-ARENA)。** **PATCH**。RT2 Live Battle Lab：Forest =`36/0/0` +`mcfr00_00` (nao mcyt/id 340); Open = idx 42. [前:`v2.166.0.11`]
- **`v2.166.0.11` — バトルトラッカー：BTLスナップショット + レスポンシブレイアウト（Jarvis-MAGIC）。** **パッチ**。「バトルスナップショット」カード（フィールド、グループ、フォーメーション、フロントライン、ルートカーソルなど — Live Battle Labと同じデコード）＋4列グリッドの代わりに「味方／敵」タブ。Chrエディタは変更なし。[以前：`v2.166.0.10`]
- **`v2.166.0.10` — インジェクションDLL：緑／赤のネオン表示の切り替え機能が復元されました（Jarvis-MAGIC）。** **パッチ**。ピルの「オン」／「オフ」表示が再び緑色に戻りました`#00E87A` と赤`#FF2A4D` 強いグロー効果；フォールバックがもはや青みがかった灰色にはならない。[以前：`v2.166.0.9`]
- **`v2.166.0.9` — Battle Tracker：レイアウトの不具合 + リストのコントラスト（Jarvis-MAGIC）。** **パッチ**。ネストされたグリッド`*,*`/`2*,3*` 詳細パネルを折りたたんでいた（中央が空白）；4つの固定列に戻す`150,*,300,*` com`MinWidth` ScrollViewer内。編成外の味方は`TextMutedBrush` ～の代わりに`DarkRed`. 読み込み時に最初の味方／敵を自動選択します。[前へ：`v2.166.0.8`]
- **`v2.166.0.8` — F7メニュー：アニメーションするネオンバーを削除 + ガラスの不透明度を向上（Jarvis-ARENA）。** **パッチ**。アーケード風の外枠とスイープ効果を削除；滑らかな縁取りの静的なガラスパネル。[以前：`v2.166.0.7`]
- **`v2.166.0.7` — F7メニュー：ガラスパネル＋EN文字列＋明るい背景（Jarvis-ARENA）。** **PATCH**。ネオン色の縁取り付き透明なヘッダー／フッター；ハブのテキストは英語（i18nは後ほど）。[前：`v2.166.0.6`]
- **`v2.166.0.6` — F7メニュー：レスポンシブレイアウト Menu2D (Jarvis-ARENA)。** **パッチ**。`MenuPhysW/H` + 分数`NX/NY/NW/NH`; バッファの物理座標上に、均一な厚さのネオングリーンの枠線（`MenuBorderPx`); 1080p/2K/720pのハードコーディングを廃止する。[以前：`v2.166.0.5`]
- **`v2.166.0.5` — F7メニュー：ネオングリーンの枠線 + 左揃え

非対称（Jarvis-ARENA）。** **PATCH**。ゴールドをネオングリーンに変更（`#50FF90`); デザイン空間における対称マージン; 「Arena+」および「Custom Mix」のサブメニューに表示される緑色の選択線。[前へ:`v2.166.0.4`]
- **`v2.166.0.4` — カスタムミックス×3：マカラニアのシナリオ4つ＋ピッカーのローンチルート（ジャービス・アリーナ）。** **パッチ**。ピッカー内のフォレスト／オープン／オープン2／レミエム；ローンチ時にルートが適用される。[前回：`v2.166.0.3`]
- **`v2.166.0.3` — F7メニュー：スピラの地図が復活（スクリム＋適度な不透明度）（Jarvis-ARENA）。** **パッチ**。暗いスクリム＋`worldmap` アトラス 11948 +`ffx_bg` 繊細＋ヴィネット；v2.166.0.1のHDRオーバーフローを回避。[以前：`v2.166.0.2`]
- **`v2.166.0.2` — カスタムミックス：マカラニアのシナリオを修正 + マニフェストの起動ルート（Jarvis-ARENA）。** **パッチ**。フォレスト =`mcyt00_01`; Open =`mcyt00_21`; レミエム =`kino00_70` + フィールド 220。[前：`v2.166.0.1`]
- **`v2.166.0.1` — F7メニュー：オーバーレイ世界地図のフルスクリーン表示を解除（はみ出し／白画面の修正）（Jarvis-ARENA）。** **パッチ**。ゲームシーンがきれいに表示されるようになり、グリッド／フィールドの上に白い四角が表示されなくなった。[以前：`v2.166.0.0`]
- **`v2.166.0.0` — カスタムミックス：シナリオピッカー（ミックスのみ；固定プリセット）（Jarvis-ARENA）。** **MINOR**。F7ピッカーでティアごとに3つのシナリオ；ラボ`--scenario`; manifest`scenario_key`. 『Gauntlet』／『Dark Rematch』は変更なし。[前回：`v2.165.0.1`]
- **`v2.165.0.1` — F7メニュー：青色のウォッシュを削除；背景＝クリーンなスピラマップ（Jarvis-ARENA）。** **パッチ**。削除`ffx_bg` + 青いヴィネット + 単色のオーバーレイ；不透明度を高く設定したworldmap atlas 11948。[前：`v2.165.0.0`]
- **`v2.165.0.0` — Arena+ Gilの経済性：Dark Aeon 1つあたりのコスト + プリセット／ミックスでの合計（Jarvis-ARENA）。** **MINOR**。フラグ`arena_plus_charge_gil.flag`; データ表 §13.1 (Valefor/Ifrit 100k … Penance 500k); プリセット = ボスの合計; カスタムミックス = ピックの合計 (Magus 300k); ギル不足の場合はブロック; 展開にはフラグが含まれる。 [前へ：`v2.164.0.5`]
- **`v2.164.0.5` — スパイラ・リフォージ：ダーク・イオーン（ヨジンボを除く）のAPを大幅に引き上げる案。**レーン** ジャービス-MAGIC**。 **修正**。Halyson：Arena+のラダーにおけるDark Aeonの勝利によるAPを**大幅に**増加させる；**Dark Yojimboは**この調整の対象外とする。Docs：`VISION_AND_ROADMAP.md` §5.2.1,`FFX_SPIRA_REFORGE_DARK_AEON_REBALANCE_RESEARCH_2026-06-15.md`. 数値は未定；オーサリング `m###

.bin` loot AP. [anterior: `v2.164.0.4`]
- **`v2.164.0.4` — Arena+ コンポーズ x4/x5：ドナー・プリセット・ワイド + ウィング・ソート (Jarvis-ARENA)。** **PATCH**。x4 ドナー`nagi05_24`; ドナー×5`nagi05_50`; 中央で最大; 文書スキャン [前：`v2.164.0.3`]
- **`v2.164.0.3` — Arena+ コンポーズ x4：スプレッドをさらに奥に（Jarvis-ARENA）。** **PATCH**。グリッドZ +18；ヴァレフォールの翼幅を狭く。[以前：`v2.164.0.2`]
- **`v2.164.0.2` — Arena+ hub：壮大な字幕＋小さなフォント（Jarvis-ARENA）。** **パッチ**。タイトルはそのまま；説明`DrawStringSub` 別個に。[前へ：`v2.164.0.1`]
- **`v2.164.0.1` — Arena+メニュー：確認画面でのみダブルクリック防止（Jarvis-ARENA）。** **パッチ**。デフォルトのクールダウンを12フレーム→3フレームに変更；「Dark Aeon」のサブメニューを開くと、UP/DOWNキーで即座にナビゲート可能。[以前：`v2.164.0.0`]
- **`v2.164.0.0` — Arena+ F7 サブメニュー + カメラ/chunk0 バイブル (Jarvis-ARENA)。** **マイナー**。ハブ：**Dark Aeon Rematch** / **Aeon Gauntlet** / **Custom Mix**；ドキュメント [`FFX_ARENA_PLUS_COMPOSE_CAMERA_CHUNK0_TEMPLATE_2026-06-23.md`](docs/reverse/FFX_ARENA_PLUS_COMPOSE_CAMERA_CHUNK0_TEMPLATE_2026-06-23.md) (chunk0 提供元`mcyt00_21`, スロットスワップ、ODバー ≠ HPバグ、オーロラの再利用）。DLL`ArenaPlusMenuKind`. [前へ：`v2.163.0.4`]
- **`v2.163.0.4` — Field Explorer：UI上でScoutを公開（Jarvis-FIELD-RE）。** **PATCH**。「Scoutを公開」／「マーカーを更新」／「公開＋フィールドを開く」ボタン；プロセス内でリフレッシュ（2つ目のエディタを起動せずに）；PS1`-SkipOverlayRefresh` UIから呼び出されたとき。[前へ：`v2.163.0.3`]
- **`v2.163.0.3` — Arena+ 設定：パーティへのスプレッド表示（キャラクターの背後からカメラ） (Jarvis-ARENA)。** **PATCH**。`BattleComposeRunner`: バニラ版キャリアのパーティのZ軸重心を取り、エオンを反対側に配置する（`mcyt00_22` party Z≈+2 → モンスター Z 負); lab + Steam を再構成。音楽はそのまま。[前回：`v2.163.0.2`]
- **`v2.163.0.2` — Arena+ 構成：Dark Anima/YojimboのスロットIDを入れ替え、Steam（Jarvis-ARENA）を再展開。** **パッチ**。`BattleComposeRunner`:`0x1153`=アニマ、`0x1154`=『用心棒』（関連項目：`battle-model-catalog.json` / REファイル); スプレッドが3倍に拡大; ラボ再公開 +`mcyt00_22.bin` 再構成された (`ixion,shiva,yojimbo` → スロット`0x1150,0x1151,0x1154`). 楽曲は**変更なし**。[前：`v2.163.0.1`]
- **`v2.

163.0.1` — Field Explorer P0: CHR honest overlay + dedupe (Jarvis-FIELD-RE).** **PATCH**. `EncounterOverlayCompiler` + `ChrClassifier`: dedupe por ator (n/c/m/f), `field-encounters.json` v2 (`entities[]`, `chrCounts`, `鮮度`), MapViewer layer toggles + labels honestos, publish C1 (`break`→`続きを読む`) + `Resolve-FieldKey` com limite de proximidade, `chr_spawn` com `領域／フィールド` no hook, ingest `登録フィールド` para chr. RT2 Field Actor ainda pendente. [anterior: `v2.163.0.0`]
- **`v2.163.0.0` — SGM 861 F1 インラインストアリダイレクトフック v1.75 (Jarvis-MAGIC-SGM)。** **マイナー**。`SphereGridFullGridCompilerHook v1.75`: 内部の5バイトのスタブパッチ`7F4900` @`0x3F4C0F` (NEGライター準備)、`0x3F5208` (NEG pos store)、`0x3F57E6` (POS pos store); flag`sg_f1_inline.flag` SKIP860をリフトし、vanilla draw860を可能にする`STORE-INLINE` remap stale 41252→41328. RE:`docs/reverse/FFX_SPHEREGRID_861_F1_INLINE_STORE_2026-06-23.md`,`work/reverse/ida/f1_inline_patch_sites_2026-06-23.json`, F2チェーン`docs/reverse/FFX_SPHEREGRID_861_F2_ANIM_CAPTURE_STORE_RE_2026-06-23.md`. ゲーム内でのDLL + RT2のビルド **テストが必要**。[前へ：`v2.162.9.4`]
- **`v2.162.9.4` — Arena+ 構成：完全なデプロイラボ + Enterキーのデバウンス (Jarvis-ARENA)。** **PATCH**。終了`2147516570` =`ArenaMultiBossLab.dll` 欠落 — デプロイ時にフォルダ全体をコピーして`modules\tools\ArenaMultiBossLab\`. ピッカー：Confirmでの立ち上がりエッジ + トグル後のクールダウン20f（Enterキーを押すと選択が解除される不具合を修正）。[以前：`v2.162.9.3`]
- **`v2.162.9.2` — Spira Reforge: handoff RT2 テストハーネス（グリッドの前にスキルを付与）。** Lane **Jarvis-MAGIC**。**REVISION**。Doc`docs/ai/PROMPT_SPIRA_REFORGE_COMMAND_RT2_TEST_HARNESS_2026-06-18.md` — 並行チャットへの貼り付け：最小限のデプロイ`command.bin`,`GridTeach` + サイドカー`grid_teach_learned.bin`, grant via`ffxprobectl call 385D10`, パックごとの煙量（マニフェスト）、テスト終了時のチェックリスト **デフォルト設定に戻す**。[以前：`v2.162.9.1`]
- **`v2.162.9.1` — スパイラ・リフォージ：デザインロック — オーバードライブ→APアウト + ティアTの報酬。**レーン** ジャービス-MAGIC**。 **修正**。Halyson：Overdrive→APを削除（APファームが面倒）；代替案は未定。SINモード：ティア**T**のモブも基本ステータスが↑し、ドロップ量が増加（数値は未記載）

（このドキュメント）。ドキュメント：`FFX_SPIRA_REFORGE_VANILLA_OFFENSIVE_REBALANCE_2026-06-16.md`,`SIN_DIFFICULTY_MODE_SPEC.md` §3.4. [前項：`v2.162.9.0`]
- **`v2.162.9.0` — 修正：MonsterAiEditorのバグ`{StaticResource Spacing*}` + ネオン色のアクセントが復元されました（Jarvis-UI）。** Lane **Jarvis-UI**。**PATCH**。Halyson から報告された 2 つの問題：(1) **バグ：**`MonsterAiEditor_Control.axaml` 4件の事例がありました`Padding="{StaticResource SpacingLg/Md}"` 起動時に解決されなかった問題（ホットフィックスと同じクラス）`v2.159.6.1` — トークン`Spacing*` ～に住んでいる`Application.Resources` ～の後`StyleInclude`、それなら`StaticResource` 失敗；F3スイープが使用された`{DynamicResource}` しかし、この4行は手動パイロットの`v2.159.6.0` （逃げ出した者たち）。これを`{DynamicResource Spacing*}` — バグを修正する。(2) **「ネオン色ではない、見栄えの悪い色」：** その`v2.159.6.0` 15を標準化した`Accent*FillBrush` (Shell/Protect/Regen/Gold/Cycle/Forbidden/Crimson/Undo/Refresh/Move/Haste/Reflect/NulAll/Builder/Reaction) 非常に暗い色調で (`#21506A`/`#1E5E45`/etc.)、ネオンの縁の輝きを覆い隠してしまっていた。**より彩度が高く鮮やかな**色調に復元された（例：Shell`#21506A`→`#1A6E8C`, Protect`#1E5E45`→`#1E8050`, ゴールド`#4A4226`→`#6E5E2A`, サイクル`#3D4F78`→`#3A5BB0`) — ダークなフィルとネオンの縁取りの中間色で、ネオン一色になることなく存在感を放つ。ネオンの縁取り／前景（`#66D8F0`/`#6FE3B7`/`#AAB4FF`/etc.) **そのまま**（もともと綺麗だった）。消費するすべてのモジュールに影響する`Accent*` (MonsterAiが最大)。対象範囲：ビジュアルコンテナのみ — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし。リリースビルド **エラー0件**（既存の警告403件）。[前回：`v2.162.8.0`]
- **`v2.162.8.0` — 修正：SGM 861 OOB スロット 860 フック v1.30 (Jarvis-MAGIC-SGM)。** **パッチ**。`SphereGridFullGridCompilerHook v1.30`: ブートバンプ`942B60` 41252→41328、SKIPの拡張 (-861/-862)、F858パッチ（ライターのみ +0/+4）、ALLOC-TRACE、プロデューサーウォッチ、バッファ861の準備完了時にdraw860を再有効化。RE:`docs/reverse/FFX_SPHEREGRID_861_PRODUCER_RE_2026-06-20.md`. DLLのビルドは成功；RT2ゲーム内 **テストが必要**。[前：`v2.162.7.0`]
- **`v2.162.6.0` — 修正：コマンドパレット`Ctrl+K` + 引き出し（幅狭）`Ctrl+B` (ポップアップ`IsOpen`, tunnel KeyDown) (Jarvis-UI).** Lane **Ja

rvis-UI**. **PATCH**（フェーズDから修正が約束されていたものの、オーバーレイが表示されなかったショートカットを修正）。Avalonia 11`Popup` **が必要**`IsOpen`** — そのコードでは`IsVisible` (no-op)。**tunnel** ハンドラーに移行されたショートカット (`KeyDownEvent`) TextBoxや子エディタに焦点を当てて動作するようにするため。`PlacementTarget` +`Topmost` ポップアップ内。ビルドリリース **エラー0件**。[前回：`v2.162.5.0`]
- **`v2.162.5.0` — i18n: 移行`ModuleRegistry` (41モジュール × 5フィールド) + ダッシュボードの文字列 + §16–§17 完了 (Jarvis-UI)。** Lane **Jarvis-UI**。 **PATCH** (F4 i18n基盤の再利用；新たな製品機能なし)。プロンプト後`PROMPT_GLM_PHASE_E_HARD_AND_F`: **205キー**`Mod_{id}_{Title|Description|Mode|Notes|Scope}` で`Strings.resx` +`Strings.pt.resx` (発電機`work/_gen_module_i18n_20260622.ps1`);`Strings.Get`/`Strings.Module` 動的ルックアップ;`ModuleCatalogEntry.Localized*` (ダッシュボード、パレット、レールツールチップ、バナー via`SetModule` オーバーレイはいつ`_currentModuleId` レジストリを更新する）。**+11 キー** ダッシュボード（ヒーローの読み込み済み／空、ラベル：Workspace／Modules／Hook）。`MainDashboard_Control` ビンダ`LocalizedTitle/Description/Mode` +`{x:Static res:Strings.*}`.`docs/specs/EDITOR_UI_OVERHAUL_PLAN.md` §16～§17に「**DONE**」とマークされている（`v2.160.0.0`).`PORT_STATUS.md` 調整済み (`v2.162.4.0`→`v2.162.5.0`). **誠実さ：** レジストリがすでにポルトガル語（PT）だった箇所については完全なポルトガル語の説明文を記載し、衛星版で翻訳された英語のタイトル、および68の内部文字列`SetModule` リテラルがバックログに残っている。Smoke RT1 + Halysonによるマージが保留中。適用範囲はコンテナのみ。ビルドリリース **エラー0件**。[前回：`v2.162.4.0`]
- **`v2.162.4.0` — フェーズ F §F4: i18n foundation (`.resx`) (Jarvis-UI)。** Lane **Jarvis-UI**。**PATCH** (foundation; デフォルトでは目立った動作の変更なし — デフォルトのロケールは引き続き en)。**フェーズ F** の4つ目にして最後のコミット (`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F4). 適用範囲：**ビジュアルコンテナのみ** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし。国際化のためのインフラストラクチャを構築する：**このコミット以前、リポジトリには0があった**`.resx`**; 至る所にハードコーディングされた文字列。 **作成日:**`Resources/Strings.resx` (neutral = en、約17個のキーが負荷を担う：ヒーローの称号、レールのラベル、パレットのプレースホルダー)

（古いもの、アクションラベル、モードピル） +`Resources/Strings.pt.resx` (PT-BR衛星) +`Resources/Strings.cs` (静的アクセサ via`ResourceManager`, キーごとに1つの静的プロパティ — XAMLでは次のようにバインド可能`{x:Static res:Strings.Xxx}`) +`Strings.ApplyUiCulture()` (読む`FFX_UI_LANG=pt|en`; default = neutral/en; 矢印`DefaultThreadCurrentUICulture` （XAMLバインディングを行う前に）。**配線：**`App.axaml.cs Initialize()` 炎`Strings.ApplyUiCulture()` ～の前に`AvaloniaXamlLoader.Load`. それらの`.resx` は`EmbeddedResource` glob SDKによって暗黙的に定義されている（`Resources/**/*.resx`) — 衛星が確認された`pt\FFXProjectEditor.resources.dll` が表示される。**2点荷重支持のバインディングのデモ：** MainDashboard の CTA「Open workspace folder」（`{x:Static res:Strings.DashboardCtaOpenWorkspace}` + a11y name) + コマンドパレットのプレースホルダー (`Watermark="{x:Static res:Strings.RailSearchPlaceholder}"`). **率直に言えば：** 完全なi18nは終わりのない作業です（doc §4.F4）。 このコミットは基盤を確立し、パターンを示すものである。約50件のModuleRegistryのタイトル／説明文および数百件の内部文字列の移行は、今後のバックログとして残される（2つのresxファイルにキーを追加し、Strings.csにプロパティを追加し、リテラルを`{x:Static}`). 本日、ポルトガル語以外のユーザーは確認されていないため、`FFX_UI_LANG` UIには表示されない（環境変数のみ）。ハンドラー／バインディング／ライター／保存バイト／フックは変更なし。リリースビルド **エラー0件**（既存の警告403件）。 **フェーズF全体が完了**（F1～F4）。[前回：`v2.162.3.0`]
- **`v2.162.3.0` — フェーズ F §F3: トークンのスイープ — 均一なパディング →`Spacing*` (67ファイルに518個のリテラル); CornerRadiusは**トークン化されていない** (正直に言うと) (Jarvis-UI)。** Lane **Jarvis-UI**。 **PATCH**（デザインシステムの磨き上げ；新機能なし）。**フェーズF**の3回目のコミット（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F3 — 「高いチャーン率、低い増分価値」）。対象範囲：**ビジュアルコンテナのみ** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし。 **パディングスイープ：** 518個のリテラル`Padding="N"` （N ∈ {4,8,12,16,20}）の制服が移行された`{DynamicResource SpacingXs/Sm/Md/Lg/Xl}` **67個のファイル**`.axaml`** から`Modules/` 保守的なスクリプト経由 (`work/_padding_sweep_20260622.ps1`)

` — só substitui valores que batem **exato** com um token; deixou intactos os ~340 Paddings assimétricos/não-token como `Padding="10,6"`/`Padding="14"`). `MonsterAiEditor2_Control.axaml` **não** migrado (discontinued). **CornerRadius sweep (§F3b) = NO-OP honesto:** os valores `CornerRadius` ativos nos módulos são majoritariamente 5/6/7/14 — **nenhum** bate com os tokens `RadiusSm=8`/`Md=10`/`Lg=12`/`Pill=999`. Forçar o valor mais próximo seria **mudança visual**, não tokenização. O doc citava "158 CornerRadius" mas esse count incluía `MonsterAiEditor2_Control.axaml` (discontinued, ~34 ocorrências de 8/10). Decisão documentada: deixar CornerRadius literal onde não há match exato. Pós-commit: 518 `Padding="{DynamicResource Spacing*}"` em 67 arquivos; 0 `Padding="16"` restantes. Handlers/bindings/writers intocados. Build Release **0 erros** (403 warnings preexistentes). [anterior: `v2.162.2.0`]
- **`v2.162.2.0` — フェーズF §F2：`AutomationProperties.Name` 約98個のアクションボタン（a11y）に関するグローバルな変更（Jarvis-UI）。** Lane **Jarvis-UI**。**PATCH**（アクセシビリティの修正；新機能なし）。**フェーズF**の2回目のコミット（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F2). 適用範囲：**ビジュアルコンテナのみ** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし。アクションボタンのアクセシビリティ：このコミット以前は、F2モジュール内のボタンはわずか約8個しか`AutomationProperties.Name` （スクリーンリーダーがアイコンのみのボタンを読み上げられなかった）。**98個のボタンを追加**：**うち87個はスクリプト経由**`work/_a11y_name_sweep_20260622.ps1` （ボタンの表示テキストから名前を導出する；UTF-8として読み込む；非ASCIIテキストや◀/▶/…などの非ASCIIテキストやアイコングリフを含むボタンは、文字化けを防ぐためにスキップ）が、12のCore Authoring + SaveEditorHub + (Customization/Shop/MixTable/KernelCommands)に存在し、さらにKernelCommands内に**4つの明示的なもの**（◀/▶ 「Previous/Next FSB sample」、「Import fsbankcl」、「Import custom WAV」）、+ **MainDashboard内の2つ**（Open Workspace + QuickTile`{Binding Title}` — アイコンのみ、アクセシビリティ（a11y）を最優先）、+ **Main_Window内の5箇所**（Music/Settings/Workspace path/Back/Forwardのレールアイコン）。コミット後：**164箇所**の`AutomationProperties.Name` 18個のファイルのうち`Modules/` （以前のF2スコープでは約8）。ハンド

lers/bindings/writers は変更なし。リリースビルド **エラー0件**（既存の警告403件）。[前回：`v2.162.1.0`]
- **`v2.162.1.0` — フェーズ F §F1: ユーティリティアイコン（新規13個）＋スウィープ絵文字（8ファイル）`.axaml`) (Jarvis-UI)。** Lane **Jarvis-UI**。**PATCH**（ビジュアルの修正：アイコン；新機能なし）。**フェーズF**の最初のコミット（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §4.F1). 対象範囲：**ビジュアルコンテナのみ** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし。**13個の新しいユーティリティアイコン**が`Styles/StudioIcons.axaml` (`IconSearch`/`IconAdd`/`IconRemove`/`IconWarning`/`IconUndo`/`IconRedo`/`IconFilter`/`IconOpen`/`IconClose`/`IconChevronDown`/`IconChevronRight`/`IconCheck`/`IconX` — Lucide-like、viewBox 24×24、`<StreamGeometry>`). **8つのファイルに含まれる絵文字**`.axaml` リストされたもの：🏐/💾/🌅/🗺️ タイトルから削除`sectionLabel`/`cardTitle` および「保存」ボタン。「保存」ボタン（`💾 Salvar`) が勝利した`<PathIcon Data="{DynamicResource IconSave}"/>` + テキスト（MonsterAiEditor ×2、EncounterTableExplorer ×1、AuroraChamber ×3）。絵文字を含むタイトル（`🌅`/`🗺️`/`🏐`) から絵文字が削除されました（TextBlock内のPathIconをインライン化するクリーナー）。`SphereGridCanvas_Control.axaml` すでにきれいになっていた（絵文字を削除しました）`v2.159.5.0` OPT-A6）。**「8」以外のボーナス：** 2タイトル`SetModule` user-visible (`"Save Editor 💾"`,`"Sphere Grid 🧩"` で`Main_Window.axaml.cs`) ヘッダーの視覚的な統一感のため、これらも削除しました。`.cs` （コメント＋ステータス文字列）**変更なし**（対象外）。リリースビルド **エラー0件**（既存の警告403件）。[前回：`v2.162.0.0`]
- **`v2.162.0.0` — フェーズE完了：`ModuleMasterDetail_Shell` 12のCore Authoringモジュール（E1～E12）（Jarvis-UI）すべてにおいて。** Lane **Jarvis-UI**。**MINOR**（フェーズ終了マイルストーン — 5つのPATCHの統合）`v2.161.1.0`→`v2.161.5.0`). **Eフェーズ全体**の`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` （§2 標準仕様 + §3 E9-E12 + §4）が納品されました：**12のCore Authoringモジュール**が、独自開発版から移行されました`Auto,*` /`2*,5*` /`3*,6*,3*` グリッド（ボーダーカード`Padding=16` （inchado + ScrollViewer）から標準のシェルへ（`ModuleMasterDetail_Shell` 折りたたみ式エクスパンダー付き、`Padding=8`, 濃厚)

. モジュール：**E1 CtbBase、E2 PlayerGrowth、E3 Formation、E4 Treasure、E5 KeyItem、E6 AutoAbility、E7 BukiGetTreasureCatalog、E8 MonEditorSelector** (`v2.161.1.0`) + **E9 CustomizationEditor**（Gear/Aeonの2つのシェルを備えたTabControl、`v2.161.2.0`) + **E10 ShopExplorer** (3列カスケード、ヘックス→トークン、`v2.161.3.0`) + **E11 MixTableEditor** (112×112の行列、`v2.161.4.0`) + **E12 KernelCommands**（このリポジトリで最も詳細な部分、977行、16進数→トークン、`v2.161.5.0`). **ハードアーキテクチャ上の決定事項（E9-E12）：** カスタマイズにおいて外部のTabControlが維持される（2つのシェル）； ShopのMasterHeaderではソースピッカーがComboBoxに変更；MixTableのDetail内ではパートナー軸がExpanderに変更；セッションバーはシェルの上部に維持され、KernelCommandsのDetail内では「Where Used」がExpanderに変更。各モジュールには`rsp:Responsive.Breakpoints="True"` + スタイル`UserControl.narrow` マスターを崩壊させる`<760px`. DataContext/bindings/handlers/converters/`AutoSaveIndicator_Control`/`AtlasEvidenceBadgeStrip`/`IRestorableModule`/`x:Name`すべてにおいて変更なし。Writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は手つかずのまま。リリースビルド **エラー0件**（既存の警告403件 — Jarvis-UIのベースライン）。 次：**フェーズ F** (F1 アイコン+絵文字、F2 a11y、F3 トークンスウィープ、F4 i18n)。 [前：`v2.161.5.0`]
- **`v2.161.5.0` — フェーズE §E12：`KernelCommands` →`ModuleMasterDetail_Shell` (リポジトリの詳細、3色＋セッションバー＋16進数) (Jarvis-UI)。** Lane **Jarvis-UI**。 **パッチ**（表面的な修正：レイアウトの移行；新機能なし）。**フェーズE**の最後のコミット（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E12 — プランの中で**最もリスクが高い**もの）。 適用範囲：**ビジュアルコンテナのみ** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし；DataContext/bindings/handlers/converters/IRestorableModule は変更なし。`KernelCommands_Control.axaml` (977 → 約970行) 3列レイアウトに移行 (`3*,6*,3*` コマンド一覧 | 詳細エディタ | 「使用箇所」）＋ 標準的なプロシェル用セッションバー。**アーキテクチャ上の決定：** outer`RowDefinitions="Auto,*"` 変更なし — **TOP SESSION BAR** はシェルの**上**に表示されます（行 0、変更なし）。行 1 のシェルには`MasterList` = command ListBox (era Col0,`DisplayedCommands`/`Selec

tedCommand` + `FilterText` + botões Clonar/Apagar/Adicionar), `詳細` = editor (era Col1, ~840 linhas de campos densos preservados byte-a-byte: Identity/Animations/Battle SFX 3 tiers/Menu/Characters/Costs/Attack Data/Element/Properties/Status/Status Special/Extra); a **3ª coluna "Where Used"** (era Col2) vira um **Expander colapsável dentro do Detail** (default colapsado, label "Where Used — monster links"). `x:Name`s preservados (`ThisControl`, `CommandList`, `MonsterLinksList`) — o code-behind referencia `MonsterLinksList.SelectedItem` em `OpenReferenceMonster`. `AutoSaveIndicator_Control` e os 3 converters (`キャラクター`/`DamageFormula`/`HitCalcType`) preservados. **Hex → tokens no mesmo commit:** `#FF6B6B` (LoadError foreground) → `DangerBrush`; `#1A2A3A` (Spira Ward note bg) → `PanelDeepBrush`; `#3A6EA5` (Spira Ward note border) → `PanelStrokeBrush`; `#7EC8FF`/`#B8D4E8` (Spira Ward note foreground) → `AccentCoolBrush` (token exato já existe). Ganhou `rsp:Responsive.Breakpoints="True"` + style `UserControl.narrow` que colapsa o master em `<760px`. **Fecha a Fase E** (E1-E12 completa). Build Release **0 erros** (403 warnings preexistentes). [anterior: `v2.161.4.0`]
- **`v2.161.4.0` — フェーズE §E11：`MixTableEditor` →`ModuleMasterDetail_Shell` (112×112の行列、3列) (Jarvis-UI)。** Lane **Jarvis-UI**。 **PATCH**（表面的な修正：レイアウトの移行；新機能なし）。**フェーズE**の継続（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E11). 適用範囲：**ビジュアルコンテナのみ** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし；DataContext/bindings/handlers/IRestorableModule は変更なし。O`MixTableEditor_Control.axaml` (176 → 約200行) 手作りのグリッドを移行する`3*,3*,5*` (112×112のマトリックス：origin ListBox | partner ListBox | result detail) 標準的なシェル向け。 **アーキテクチャ上の決定：** このマトリックスには2つの連鎖した選択（origin → partner → result）が必要であり、標準的なマスター・ディテール形式には直接収まりません。Origin（Col0）は`MasterList` (プライマリ軸専用のシェル、`OriginFilterText`/`DisplayedOrigins`/`SelectedOrigin`); partner (Col1) は、**折りたたみ可能なエクスパンダー内の Detail 内のセレクター** になります（デフォルトでは展開済み —`ResultFilterText`/`D

isplayedResults`/`SelectedResult`, label "Partner Item"); result detail (Col2) vira o topo do Detail (hero `heroBlue` preservado + session + Combination Editor). `AutoSaveIndicator_Control`, `GameIndex_Template` e `AtlasEvidenceBadgeStrip` preservados. Ganhou `rsp:Responsive.Breakpoints="True"` + style `UserControl.narrow` que colapsa o master em `<760px`. **Falta E12** (KernelCommands — maior detail do repo, maior risco). Build Release **0 erros** (403 warnings preexistentes). [anterior: `v2.161.3.0`]
- **`v2.161.3.0` — フェーズE §E10：`ShopExplorer` →`ModuleMasterDetail_Shell` (3列カスケード) (Jarvis-UI)。** Lane **Jarvis-UI**。**PATCH** (表面的な修正：レイアウトの移行；新機能なし)。**フェーズE**の継続 (`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E10). 適用範囲：**ビジュアルコンテナのみ** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし；DataContext/bindings/handlers/IRestorableModule は変更なし。O`ShopExplorer_Control.axaml` (361 → 約360行) 手作りのグリッドを移行する`Auto,Auto,*` (3列カスケード：ソースListBox | ショップ行ListBox | スロットスライスエディタ) 標準的なプロシェル。**アーキテクチャ上の決定：** ソースピッカー（Col0）は、**MasterHeader内のコンパクトなComboBox** となる（`LoadedSources`/`SelectedSource` +`LoadSummary` + Refresh); ショップの行（Col1）は`MasterList` (`FilterText` +`DisplayedShops`/`SelectedShop` + フィルターのフィードバック）；スライスエディタのスロット（Col2）は`Detail` (カードが密集したWrapPanel)`SelectedSlots` （Image/ComboBox および「詳細情報」のエクスパンダーが保持された状態で）。`AutoSaveIndicator_Control` そして`AtlasEvidenceBadgeStrip` 保存された。**Hex → トークン：** スロットのビジュアルバッジには`#0D1621` (背景) および`#274760` (border) inline →`{DynamicResource PanelDeepBrush}` /`{DynamicResource PanelStrokeBrush}`. 勝った`rsp:Responsive.Breakpoints="True"` + スタイル`UserControl.narrow` マスターを崩壊させる`<760px`. **E11-E12が未解決** (MixTable/KernelCommands)。リリースビルド **エラー0件** (既存の警告403件)。 [前回:`v2.161.2.0`]
- **`v2.161.2.0` — フェーズE §E9：`CustomizationEditor` →`ModuleMasterDetail_Shell` (TabControl内の2つのシェル) (Jarvis-UI)。** Lane **Jarvis-UI**。 **PATCH** (po

表面処理：レイアウトの移行；新規生産能力の追加なし）。**フェーズE**の継続（`docs/ai/PROMPT_GLM_PHASE_E_HARD_AND_F_2026-06-22.md` §3.E9). 適用範囲：**ビジュアルコンテナのみ** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし；DataContext/bindings/handlers/IRestorableModule は変更なし。O`CustomizationEditor_Control.axaml` (396 → 約340行) 手作りのグリッドを移行する`3*,7*` (国境通過カード`Padding=16` （インチ + ScrollViewer）を**それぞれ**`TabItem` 標準的なプロシェル — o`<TabControl>` 外部（Gear / Aeon）は**保持**される；各`TabItem` 現在、その組織独自の`ModuleMasterDetail_Shell` （シェル2つ、ヘッダーラベル「Gear Recipes」／「Aeon Recipes」）。2組のバインディング（`GearFilterText`/`DisplayedGearRecipes`/`SelectedGearRecipe`/`GearEditSession` vs`AeonFilterText`/`DisplayedAeonRecipes`/`SelectedAeonRecipe`/`AeonEditSession`) は、シェル内で**隔離**され、混在することはありません。`AutoSaveIndicator_Control` (Gear/Aeon) および`AtlasEvidenceBadgeStrip` (Aeon) が保持される。適用密度：ListBox 項目`Padding=12`→`10`,`Margin=0,0,0,10`→`6`, 出典`16`→`14`,`sectionLabel`/`muted` 勝ち取った`FontSize=11`. 勝った`rsp:Responsive.Breakpoints="True"` + スタイル`UserControl.narrow` 両方のマスターを以下に統合する`<760px`. **E10～E12が未解決** (Shop/MixTable/KernelCommands)。ビルドリリース **エラー0件** (既存の警告403件)。 [前回：`v2.161.1.0`]
- **`v2.161.1.0` — フェーズE（一部）（E1～E8）：`ModuleMasterDetail_Shell` 8つのCore Authoring（Jarvis-UI）モジュール。** Lane **Jarvis-UI**。**PATCH**（表面的な修正：レイアウトの移行；新機能なし）。**フェーズE**の最初の8つのコミット（`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §4）。 適用範囲：**ビジュアルコンテナのみ** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし；DataContext/bindings/handlers/IRestorableModule は変更なし。**8つのモジュール**がハンドロール版から移行済み`Auto,*` /`2*,5*` グリッド（ボーダーカード`Padding=16` （インフレート＋ScrollViewer）から標準的なシェル（折りたたみ可能なExpander、`Padding=8`, 詳細): **E1 CtbBase**, **E2 PlayerGrowth**, **E3 Formation** (フィールドコンテキストカードがMasterHeaderに変更された), **E4 Treasure** (カードの種類固有の情報はDetailに保持されている)

), **E5 KeyItem** (`2*,5*` →`Auto,*`), **E6 AutoAbility** (詳細が保存されたカード8枚), **E7 BukiGetTreasureCatalog** (ルート`Margin=18` 削除済み + hex`#C9A227` →`WarningBrush`), **E8 MonEditorSelector**（以前は手動のExpanderがあったが、シェルに置き換えられた；詳細の切り替えは`ContentControl Name="ContentFrame"` （「Detail」スロットに保持）。各モジュールは`rsp:Responsive.Breakpoints="True"` + スタイル`UserControl.narrow` マスターを崩壊させる`<760px`. **E9～E12が未対応**（Customization/Shop/MixTable/KernelCommands — 3列/マトリックスレイアウト、リスクが高い）。リリースビルド **エラー0件**（既存の警告403件）。[前回：`v2.161.0.0`]
- **`v2.161.0.0` — フェーズD 完了：コマンドパレット`Ctrl+K` (Jarvis-UI)。** Lane **Jarvis-UI**。**マイナー**（新機能：ファジー検索対応のコマンドパレット）。**フェーズD全体を完了**するコミット`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` (D1+D2+D3+D4 + このD5)。対象範囲：**新しいクイックナビゲーション画面** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし。**新規`Modules/Main/CommandPalette_Popup.axaml(.cs)`**: 独自のUserControl（コンテナ専用、ハンドラを認識しない）で、`TextBox` (プレースホルダー「モジュールを検索…」) +`ItemsControl` data-bound への`ModuleRegistry.All` 「…で絞り込み」`Title.Contains`/`Description.Contains`/`Id.Contains` (IgnoreCase)。各検索結果にはアイコンが表示されます（via`IconKeyToGeometryConverter.ResolveGeometry`) + タイトル + 説明（2行）。Enterキーを押すと最初の検索結果が開きます（デフォルトで選択済み）。行をクリックするとIDに基づいて開きます。Escキーで閉じます。**Wiringの`Main_Window`:** 新規`<Popup Name="CommandPalette" PlacementMode="Center" IsLightDismissEnabled="True">` (XAMLでは空 — 余分なXAML名前空間を避けるため、コードビハインドでインスタンス化されたコンテンツ);`ToggleCommandPalette()` インスタンスをキャッシュし、起動する`DispatchRequested`/`CloseRequested` (イベント) を呼び出し`Reset()` 開く前に。`OnKeyDown` 獲得する`if (ctrl && e.Key == Key.K) ToggleCommandPalette()`.`Palette_DispatchRequested(id)` ポップアップを閉じる +`Dispatch(id)`. **保存：** Ctrl+Kを押して中央のパレットを開き、「save」と入力 → 「Save Editor」が表示されるので、Enterキーを押して開きます。 **フェーズD全体を5つのコミットに分けて提出** (`v2.160.1.0` →`v2.160.4.0` パッチ + このマイナーアップデート):

**約72個のすべてのコントロール**において、back/forwardの復元が可能（via）`IRestorableModule` （8つのエディタ + 状態が明示されている9つのハブ；残りはデフォルトのインターフェースメソッドを介してステートレス） + 41のモジュールに対するコマンドパレット（Ctrl+K）。リリースビルド **エラー0件**（既存の警告403件）。[前回：`v2.160.4.0`]
- **`v2.160.4.0` — フェーズD4：`IRestorableModule` 残りのすべてのコントロールについては、デフォルトのインターフェースメソッド（Jarvis-UI）を介して処理されます。** Lane **Jarvis-UI**。**PATCH**。**フェーズD**の4回目のコミット（`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D4). 適用範囲：**すべての`*_Control` 残りの** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし。`IRestorableModule.cs` **デフォルトのインターフェースメソッド**が追加されます：`CaptureState() => null` そして`RestoreState(state) { }` （デフォルトではstateless/no-op）。したがって、実質的な状態を持たないコントロール（読み取り専用エクスプローラー、ハブ、ランタイムラボ、デバッグ、トラッカー、16のエクストラ、Wave-1、サブコントロール）は、単に`, IRestorableModule` 署名欄 — o`Main_Window` これでできるようになりました`ContentFrame.Content is IRestorableModule` タイプを問わず、**任意の**モジュールで。**自動スイープ**は以下を通じて`work/_irestable_stateless_sweep_20260620.ps1`: **変更されたコントロール：65個**（追加`using FFXProjectEditor.Modules.Common;` +`: UserControl, IRestorableModule`), **9つスキップ**（D1/D2/D3ですでに実装済みの8つ +`MonsterAiEditor2_Control` 販売終了）。**正直に言うと：** フィルタ機能を備えた3つのブラウザ（MagicDllBrowser/RuntimeDllManager/Ps3MagicBrowser）は、その`FilterText` これらは非公開のDataModels内に存在し、コントロール上には公開されていない――フィルターの実際のキャプチャは、より小さなバックログとして残される。D1+D2+D3+D4により、**約72個のコントロールすべて**が現在、以下のように宣言している`IRestorableModule`; これまで参加していたもの（8つのエディター＋9つのハブ）は明示的なオーバーライドを行っており、それ以外はステートレスである。ビルドリリース **エラー0件**（既存の警告402件）。[前回：`v2.160.3.0`]
- **`v2.160.3.0` — フェーズD3：`IRestorableModule` no`SubTabHub_Control` （9つのハブに対応）（Jarvis-UI）。** Lane **Jarvis-UI**。**PATCH**。**フェーズD**の3回目のコミット（`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D3). 適用範囲：**すべてのベースハブにおいて、戻る／進む機能の復元が可能**

で`SubTabHub`** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし。`SubTabHub_Control.axaml.cs` 実装する`IRestorableModule`: 新しいフィールド`int _activeTabIndex` 追跡された日時：`SelectTab(index)`;`CaptureState()` 戻る`{["activeTab"] = _activeTabIndex}`;`RestoreState(state)` 炎`SelectTab(idx)` （通常は re-apilla pill/active/hosted-content を使用します）。**9つのハブの自動対応：** BattleCommandsHub、ItemsHub、SphereGridHub、TextHub、EnemyDesignHub、CustomizationsHub、StatsHub、EncountersHub、Blitzball — これらすべてが`SubTabHub_Control` 経由`AddTab(...)`, そうすれば、たった1回の変更で全員がアクティブなサブタブの復元機能を無料で利用できるようになります。**正直に言うと：** 各サブタブ内のコンテンツ（ホストされたエディタのフィルター／選択機能）については、ホストされたコントロールが責任を負います — もしそれが`IRestorableModule` （D2はTreasure/KeyItem/etc.を網羅した）、その`Main_Window` その直後にrestoreを実行します。ビルドリリース **エラー0件**（既存の警告402件）。[前回：`v2.160.2.0`]
- **`v2.160.2.0` — フェーズD2：`IRestorableModule` 7つの簡単なエディタ（Jarvis-UI）。** Lane **Jarvis-UI**。**PATCH**。**フェーズD**の2番目のコミット（`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D2). 適用範囲：**7つのCore Authoringエディタで「戻る/進む」機能を復元可能** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGEは変更なし。実装`IRestorableModule` （D1で定義されたもの）を**7つの対照群**において：`TreasureEditor_Control`,`AutoAbilityEditor_Control`,`PlayerGrowthEditor_Control`,`CtbBaseEditor_Control`,`KeyItemEditor_Control`,`FormationEditor_Control`,`BukiGetTreasureCatalog_Control`. それぞれ`CaptureState()` キャプチャ`filterText` (文字列) +`selectedIndex` (int? コレクション内で選択された項目から派生した値`Displayed*`);`RestoreState(state)` フィルターを再適用する（これにより、`ApplyFilter` 経由`OnFilterTextChanged`) を行い、インデックスに基づいて行を再選択します。**エディタによるマッピング：** Treasure (`SelectedTreasure`/`DisplayedTreasures`), AutoAbility (`SelectedAbility`/`DisplayedAbilities`), PlayerGrowth (`SelectedCharacter`/`DisplayedCharacters`), CtbBase (`SelectedRow`/`DisplayedRows`), KeyItem (`SelectedItem`/`DisplayedItems`), 形成 (`SelectedBattle`/`Battles` — `Displayed*` なし

`), BukiGetTreasureCatalog (`SelectedRow`/`表示行数`). **Honestidade:** agora Monster Editor + os 7 editores acima são plenamente restorable via back/forward (voltam pra seleção/filtro exatos). KernelCommands + os hubs (BattleCommands/Items/etc.) viram em D3 (SubTabHub). Build Release **0 erros** (402 warnings preexistentes). [anterior: `v2.160.1.0`]
- **`v2.160.1.0` — フェーズD1完了：インターフェース`IRestorableModule` + リファクタリング`NavigationSnapshot` (Jarvis-UI)。** Lane **Jarvis-UI**。**PATCH**。**フェーズD**の最初のコミット (`docs/ai/PROMPT_GLM_PHASE_D_TO_F_2026-06-20.md` §3.D1). 対象範囲：**ナビゲーションアーキテクチャ（復元可能な「戻る」「進む」）** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE は変更なし。**新規契約**`FFXProjectEditor/Modules/Common/IRestorableModule.cs`:`CaptureState()` →`Dictionary<string,object?>?` (null = ステートレス) および`RestoreState(state)` （冪等、null でも安全）。D1 以前では、`Main_Window` 具体的な型に対してパターンマッチを行っていた（`MonEditorSelector_Control`/`KernelCommands_Control`) 状態の取得用 — ~38モジュールまで拡張できない。現在、`Main_Window` コントロールに、それがそうかどうかを尋ねる`IRestorableModule`. **リファクタリング`NavigationSnapshot`:** 回る`record struct (string ModuleId, Dictionary<string,object?>? State)`; enum`NavigationSurfaceKind` **削除**されます。新しいフィールド`private string _currentModuleId = "home"` の冒頭で設定された`Dispatch(string moduleId)`.`CaptureCurrentNavigationSnapshot()` ジェネリック医薬品（オンライン購入）`ContentFrame.Content is IRestorableModule`;`IsSameNavigationSurface()` 比べてみて`ModuleId`;`RestoreNavigationSnapshot()` する`Dispatch(snapshot.ModuleId)` +`restorable.RestoreState(snapshot.State)`. **3件のリンク切れを修正**（依然として`NavigationSurfaceKind`):`MenuItem_MonsterMagic1/2` (L560/568) →`_currentModuleId = "battle-commands-hub"` +`new NavigationSnapshot("battle-commands-hub")` （以下のものと同じ形式の`MenuItem_Commands`/`MenuItem_Items` （すでに移行済み）；`NavigateToMonsterEditor` (L1549) →`new NavigationSnapshot("monster-editor")`. **正直なところ：** 3つのオリジナル（Home/Monster/KernelCommands）では「戻る」「進む」機能が引き続き動作しますが、Monster/KernelCommandsのみが**完全に**復元可能となります

le がその制御を実装したとき`IRestorableModule` (D2/D4)。それまでは、スナップショットは作成されますが、`State` 来る`null` （モジュールに戻る。サブ選択は復元されない）。ビルドリリース **エラー0件**（既存の警告402件）。[前回：`v2.160.0.0`]
- **`v2.160.0.0` — フェーズ A–C：ModuleRegistry + Workspace Ready（§17） + フライアウトなしのIcon Rail（§16）（Jarvis-UI）。** Lane **Jarvis-UI**。**MINOR**。フェーズ A–C の納品`docs/specs/EDITOR_UI_OVERHAUL_PLAN.md` §16–§17（Halyson 2026年6月20日の決定）に基づき、`docs/ai/PROMPT_UI_GLM_REMAINING_BACKLOG_2026-06-20.md`. 対象範囲：**ナビゲーションアーキテクチャ + データ駆動型カタログ + アイコン** — writers/save bytes/hooks/FfxLib/RT0/RT2/SGM/SPIRA FORGE **未変更**；68個のハンドラー`MenuItem_*` **リファクタリングされていない**（呼び出されているのみ）。**フェーズA — ModuleRegistry（単一ソース）：**`ModuleCatalogPolicy.cs` ドキュメントのスタブから権威あるカタログへと発展 — 新規`public static class ModuleRegistry` com`IReadOnlyList<ModuleCatalogEntry> All` **41エントリ**（Home + 10 Core Authoring + 5 Maps + 7 Live + 16 Extras + 2 Wave-1）が登録されており、各モジュールにつき1つずつがレール上でルーティングされています。`ModuleCatalogEntry` 獲得する`Mode`/`Notes`/`Scope`/`Cluster` (enum`ModuleCluster`) さらに`Id`/`Title`/`Description`/`IconKey`/`RequiresProject` 原文。各リテラルの忠実な複製`SetModule(...)` で`Main_Window.axaml.cs` （再発明されたものではない）。doc-commentポリシー：新規`MenuItem_*` ルーティング済み = レジストリへの追加 (**レビュー・ブロッカー**)。 **フェーズA — アイコングラフィックス：**`StudioIcons.axaml` **14 → 54 個のアイコン** に拡張されました (`<StreamGeometry>` Lucide風、viewBox 24×24） — モジュールごとに1つのメタファー（剣＋角＝モンスター、フロッピーディスク＝セーブ、頭蓋骨＝敵のデザイン、六角格子＝球面グリッドなど）。 整合性チェック（スクリプト）により、41個すべてが`IconKey`レジストリのsは、以下に解決されます`StudioIcons`. **フェーズB — §17 Workspace Ready：**`MainDashboard_Control.axaml` 6つのハードコードされたタイルがなくなり、代わりに`ItemsControl ItemsSource="{Binding Modules}"` com`DataTemplate` （アイコン + タイトル + 詳細説明 + モードのピル）。`Main_DataModel` 獲得する`public IReadOnlyList<ModuleCatalogEntry> Modules => ModuleRegistry.All`. 新品のコンバーター2台が`FFXProjectEditor/Converters/`: `IconKeyToGeo

metryConverter` (resolve string IconKey → Geometry percorrendo `リソース` + `統合辞書` via `TryGetResource(key, ActualThemeVariant, out _)` — necessário porque binding `{DynamicResource {Binding IconKey}}` não funciona para `PathIcon.Data` em Avalonia) e `RequiresProjectEnabledConverter` (`IMultiValueConverter` RequiresProject × IsProjectLoaded → `IsEnabled`). Hero + empty-state CTA + card de Workspace status preservados (§17.4). **Fase C — §16 Icon Rail sem flyouts:** removidos os 5 `Button.Flyout`/`メニューフライアウト` do `IconRailCol` (XAML L156–239) — substituídos por `<StackPanel Name="RailStack">` populado em code-behind por `BuildIconRail()` (1 botão `railIcon` por entry, agrupado por cluster com `ボーダー` 1px como separador). `Popup#RailDrawer` (narrow) troca a lista textual de `Button Classes="nav"` por `<WrapPanel Name="RailDrawerGrid">` (grid de ícones). Handler único `Button_RailModule_Click(sender, e)` lê `タグ=ID` → `Dispatch(id)`. `RefreshRailProjectGates()` re-aplica o gate `RequiresProject` quando `Project_Service.IsProjectLoaded` muda. **Fase C — Dispatch genérico:** `OnQuickLaunchRequested` (6 keys hardcoded: monster/kernel/sphere/save/extras/home) substituído por `Dispatch(string moduleId)` com switch de **todos os 41 Ids** → handler `MenuItem_*` existente. Rail, drawer e dashboard passam pelo mesmo caminho. **Aceite:** build Release **0 erros** (402 warnings preexistentes); 0 `メニューフライアウト` no `IconRailCol`; 0 tile hardcoded no dashboard; 41 ícones renderizando no rail + 41 cards no home com ícone dedicado + descrição completa; cards desabilitados quando `RequiresProject && !IsProjectLoaded`. **Bug visual corrigido:** os ícones não renderizavam inicialmente porque `Application.Current.Resources.TryGetValue()` em Avalonia 11 não percorre `統合辞書` — fix via `ResolveGeometry()` helper compartilhado que itera os merged dicts com `TryGetResource`. [anterior: `v2.159.6.1`]
- **`v2.159.6.1` — ブート修正：ModuleMasterDetail_Shell（Jarvis-UI）のトークン P1-7（半径／モーション）およびバインディング。** Lane **Jarvis-UI**。**PATCH**。リリース後のホットフィックス`v2.159.6.0`. **StudioTheme:** 参照 P1-7 (`RadiusLg/Md/Sm`,`DurationNormal/Fast`) では `{StaticResource ...

}` mas os tokens estão em `Application.Resources` (`StudioTokens.axaml`) **depois** do `StyleInclude` do tema → `KeyNotFoundException: 静的リソース「RadiusLg」が見つかりません` no boot (processo morria sem janela). Fix: `{DynamicResource ...}`. **ModuleMasterDetail_Shell:** `MasterHeader`/`マスターリスト`/`詳細`/`MasterHeaderLabel`/`IsMasterExpanded` agora usam `RelativeSource AncestorType=ModuleMasterDetail_Shell` (antes bindavam o DataModel do módulo → lista/botões/detail vazios no Magic DLL Browser e Runtime DLL Manager). Escopo: UI container only — writers/save/hooks intocados. Build Release **0 erros**. [anterior: `v2.159.6.0`]
- **`v2.159.6.0` — フロントエンド P0/P1 のビジュアル調整：heroGradient sweep + MonsterAi ヘックストークン + ドローワー（ナロー） + P1-7 デザイントークン（Jarvis-UI）。** Lane **Jarvis-UI**。**PATCH**。P0/P1 のバックログの実行`docs/ai/FRONTEND_AUDIT_P0_P1_2026-06-19.md` 承認された計画に従って。範囲：**UI／デザインシステムの磨き上げ** — writers/save bytes/hooks/FfxLib/RT0/RT2 **は変更なし**；`MonsterAiEditor2_*` (販売終了) **変更なし**。**P0-1 (heroGradient sweep):** 25個のファイルに収録された26のインライングラデーション`Modules/` 移住者 — 18人のカノニクス（`#163245/#0F1821/#214F69`) 見た`Classes="heroGradient"`; 8つのアイデンティティのバリエーションが、新しい名前付きトークンとして保持されている（`heroPurple`/`heroGreen`/`heroBrown`/`heroTeal`/`heroBlue` で`StudioTheme.axaml` +`Color` トークン`HeroXxxA/B/CColor` で`StudioTokens.axaml`) — 「Aurora」は紫のまま、「AutoAbility/Formation/Customization」は緑のまま、「KeyItem」は茶色のまま、「AlBhed/CtbBase/PlayerGrowth」はティール色のまま、「MixTable」は青のまま。`Main_Window.axaml` ヘッダー（パレット`PanelDeepColor` （自身の）意図的に保持されたもの。**P0-2 (MonsterAi hex → トークン)：** MonsterAiEditor クラスターから移行された 4 つのアクティブなファイル — **261 個の 16 進リテラル**（Background/BorderBrush/Foreground）が以下に集約された`{DynamicResource ...}` ファミリーごと（Shell/Protect/Regen/Gold/Forbidden/Cycle + Panel/Stroke）に、ファミリー内のドリフトを正規化（~20個のティール色の塗りつぶしが1個に）`AccentShellFillBrush`). 作成数 **14**`AccentXxxForegroundBrush`** 新規（以前はゴールドのみ） + **ファミリー`Border.accentXxx`** (15 スタイル + セレクタ`> TextBlock`) において`StudioTheme`, `Button.accen`と並行して

tXxx` existente. `MonsterAiEditor2_Control.axaml` retém seus 71 hex (discontinued). **P0-4 (drawer narrow):** o bug onde em `Window.narrow` o botão "≡" e `Ctrl+B` não faziam nada visível (estilo `Window.narrow Border#IconRailCol → IsVisible=False` vencia o toggle) foi resolvido — novo `<Popup Name="RailDrawer">` flutuante em `Main_Window.axaml` com os 6 grupos de navegação como botões de texto verticais (mais escaneáveis que ícones 22px em tela pequena), `IsLightDismissEnabled=True`; `ToggleIconRail()` agora branch narrow→Popup / wide→Border. Reusa os MESMOS `MenuItem_*` handlers (zero mudança em handlers). **P1-7 (design tokens estruturais):** novas famílias em `StudioTokens.axaml` — **Spacing** (`SpacingXs/Sm/Md/Lg/Xl` Thickness + `StackGapSm/Md/Lg` doubles), **Radius** (`RadiusSm=8/Md=10/Lg=12/Pill=999` CornerRadius), **Motion** (`再生速度：高速／通常／低速` `sys:TimeSpan`), **Elevation** (`Border.elevation1/2/3` BoxShadow). Adoção piloto: `StudioTheme.axaml` consome `RadiusLg/Md/Sm` em `Border.card`/`cardSoft`/`Button.primaryAction`/`secondaryAction`/`railIcon`/`tabPill`, e `所要時間：通常／高速` nas 3 transições de microinteração (antes literais `0:0:0.12`/`0:0:0.10`); `MonsterAiEditor_Control.axaml` demonstra `SpacingLg/Md` + combo `カード・アクセント・シェル` em 4 cards piloto. **Divergências do audit registradas:** P0-3 (Ctrl+B) já estava implementado na working tree (não era mais "comentário mentiroso"); P1-8 (shell) já tinha 2 consumidores; P1-5/P1-6 (arquitetura nav) fora do escopo por alto merge-risk. Build Release **0 erros** (401 warnings preexistentes, nenhum novo). Artefatos de sweep: `work/_hero_gradient_sweep_20260620.ps1`, `work/_monster_ai_hex_sweep_20260620.ps1`. [anterior: `v2.159.5.0`]
- **`v2.159.5.0` — UI オプションマスター：1つのPATCHで完了したオプションのバックログ28件（Jarvis-UI）。**レーン**Jarvis-UI**。**PATCH**。完全な実行`docs/ai/PROMPT_UI_OPTIONALS_MASTER_2026-06-20.md` 第5節 — 未処理の28個のIDをすべて実装（OPT-F2はすでに`v2.159.4.0`, 再実装なし）。範囲：UIの磨き上げ **コンテナのみ**（トークン、レスポンシブ、アクセシビリティ、空の状態、ピル、絵文字） — writers/save bytes/hooks/FfxLib/RT0/RT2 **変更なし**。**Spri

nt B（再利用可能なSubTabHub）：** OPT-B1/B2 —`AutomationProperties.Name` すべてのボタンで`tabPill` 生成された`AddTab()`、～と`tabA11yName` オプション（デフォルトはラベル「タブ X」に基づきます）； OPT-B3 —`BlitzballSubTabHubFactory.Create()` staticは、5つのタブの構造を`MenuItem_Blitzball` (5行以下); OPT-B4 — プレースホルダーのコピー`requiresProject` ハブごとに設定可能になりました（`RequiresProjectMessage`), 従来のデフォルト設定（PT）を維持。 **スプリント F（Magic DLL Browser の残存）：** OPT-F1 — ヘッダーカード`heroGradient`; OPT-F3 — **2行固定**のアクションボタン（Open/View \| Author/Patch、以前は単一のWrapPanel）； OPT-F4 —`IsMasterExpanded` DataModel に永続化（シェルでは TwoWay）；OPT-F5 — 詳細画面のヒーロー`heroGradient`; OPT-F6 — マスター空`!HasDllList` 標準仕様`Border#EmptyState` (アイコン + コピー、詳細が空の場合と同様); OPT-F7 —`StatusSeverity` (なし/情報/警告/危険) 由来：`StatusText` + 新規`StatusSeverityBrushConverter` エラー／警告を表示する`DangerBrush`/`WarningBrush`; OPT-F8 —`AutomationProperties.Name` 検索テキストボックス内； OPT-F9 — ピル`WRITER LAB · native magicFiles DLL · RT2 pending` ヘッダー内。**スプリント A + C (Save Editor)：** OPT-A1 — レスポンシブ対応（ヘッダーが縦方向のStackPanelになり、アクションがナローに積み重なる）； OPT-A2 — ヘッダー`heroGradient`; OPT-A3 — 錠剤`READ-ONLY · FFXED port · RT2 via CLI` ヘッダー内；OPT-A4 — 完全なSHA256ハッシュのクリック時コピー（クリップボード経由`TopLevel.Clipboard`, 新しい`IconCopy`); OPT-C1 —`StatusSeverity` no`StatusSummary` （コンバーターの再利用）；OPT-C2–C5 — 「Character」「Equipment」「Items」「Blitzball」の各サブタブのマスターリストが`Expander` 折りたたみ式 (`ExpandDirection="Left"`, 展開済みデフォルト)。**スプリント A5/A6/D (スフィアグリッド + ブリッツボール)：** OPT-A5 — 絵文字`🏐` から削除されました`SetModule` ブリッツボールのタイトルと`sectionLabel` ロスターから；OPT-A6 —`♻️ Restaurar` →「元に戻す」、`✕` リンク内 → 「Remove」 + a11y; OPT-D1 — v1 レスポンシブフォーム (3列グリッド →`WrapPanel` （narrowに積み重ねる）；OPT-D2 —`ActiveToolMode` DataModel 内の enum ＋ ビュークラス`toolActive` アクティブなモードボタン（以下に反映される）`PropertyChanged` （コードビハインド内）； OPT-D3 —`AutomationProperties.Name` Load/Save/Validate の CTA において。**スプリント E (Runtim

（残存eDll）：** OPT-E2 — バナーの「Refresh」ボタン`IsGameClosed`; OPT-E3 — C#のトグルボタンの16進数 (`ToggleBrush`/`ToggleBorderBrush`/`ToggleForeground`/`ToggleGlow`/`RuntimeBrush`) トークン化された`RuntimeToggle*`/`RuntimeRuntime*` no`StudioTokens` (以下で解決)`Resources.TryGetValue`, モジュールにヘックスなし); OPT-E1 — **スキップ** (DLLの切り替えは同期方式で`File.Move`/`File.Copy`、300msを超える目立った非同期処理はない（第7節に記載）。リリースビルド **エラー0件**（既存の警告401件、変更されたファイルには警告なし）；ゼロ`#RRGGBB` 新しいリテラルが`.axaml` 再生されたもの。[前へ：`v2.159.4.0`]
- **`v2.159.4.0` — Magic DLL Browser: 9 ヘックス → トークン + ModuleMasterDetail_Shell（2番目のコンシューマー） + 空の状態 + レスポンシブ + アクセシビリティ。** Lane **Jarvis-UI**。**PATCH**。 **Magic DLL Browser** におけるモジュールごとの UI 監査を継続中 (`Modules/Extras/`)、以下の通り`docs/ai/PROMPT_UI_MAGICDLLBROWSER_2026-06-20.md`. (P0) 11`#RRGGBB` Chrome（Wave4編集ガイドライン）`#E8A040`, Value Workbench ファミリーに関する警告`#E8A040`、および3つのRT2インラインバッジ — 動作停止中`#3B1A1A`/`#E85050`/`#F0A0A0`, プロヴェッド`#3B2719`/`#E8A040`/`#F0C070`, リスク`#2A2A1A`/`#C0A040`/`#E8D080`) は、既存のトークン／クラスから`StudioTheme`:`WarningBrush` ガイダンス／家族向け警告のテキスト内；バッジ **rt2-dead** →`Classes="pillDanger"`; バッジ **rt2-timing PROVED** →`Classes="pillWriter"`; バッジ **rt2-timing RISK** → 背景`PanelAltBrush` +`WarningBrush` (border/foreground)。 (P1) **2番目の利用者** のレポ`ModuleMasterDetail_Shell` (1番目 = RuntimeDllManager)：本体`ColumnDefinitions="330,*"` hand-rolledは、シェルを`MasterHeaderLabel="Magic DLLs"` — master = ソースルートの概要 + 検索 + リストボックス`magic_*.dll`; 詳細 = アクションヒーロー + Wave4 Attribution + Direct Patch Builder + 高密度TabControl（セクション／エクスポート／インポート／サウンド（SeSep）／オーバーレイスロット／ロール候補／ファミリーコンパレータ／論理デコンパイル／文字列／警告）。`MinWidth` master ~260 はシェルから来ている。(P2)`Border#EmptyState` 詳細については、いつ`!HasSelectedDll` （タイトル「*No DLL selected*」＋DLLの選択／設定を行うよう案内するサブタイトル）`magicFiles\FFX` root); マスターの空の状態は、次の場合に`!HasDllList` (新しいフラグが計算された`Dlls.Count > 0`, notif

所在地：`ApplyFilter` （RefreshおよびSearchをカバーするため）；`rsp:Responsive.Breakpoints` no root + style`UserControl.narrow` <760px ではマスターが折りたたまれる（アクションの WrapPanel が、Extract や Repack といった重要なボタンを切り取らない）。(P3)`AutomationProperties.Name` detail画面の約16個のアクションボタン（Open DLL/Extract/Logical Decompile/Repack/Patch Plan/C/ASM Project/Semantic RE Report/Magic Viewer/Phyre Package I/O/Clone/バイトパッチの適用/ASCIIパッチの適用/ステージング＋値パッチの適用/ステージング＋ホストオフセットパッチの適用/ps3dataクローンのデプロイ/PS3 Magicおよびフォルダのオープン）。ヘッダーカードはそのまま維持され、`card` 一般（決定：`heroGradient` セカンダリコンテキストのヘッダーでは重くなるだろう（実際のヒーローは、DLLが選択されている場合にインスペクションパネルに表示される）。**スコープが尊重される：** PEオーバーレイ、Direct Patch Builder、Value Workbench、論理デコンパイル、`MagicDllBrowser_DataModel` デコンパイル／再パッケージ／パッチ適用ロジックとイベント`OpenPs3MagicRequested`/`OpenMagicViewerRequested` + 配線番号`Main_Window` まったく変更されていない――変更されたのはビジュアルコンテナのみ（UI専用のプロパティが1つ）`HasDllList` 追加）。ビルドリリース **エラー0件**（既存の警告401件）；ゼロ`#RRGGBB` 文字通りの`.axaml` モジュールの。[前へ：`v2.159.3.0`]
- **`v2.159.3.0` — Save Editor Hub フェーズ 2：チップダーティ + SHA256 ペイロード + セッション保護。** Lane **Jarvis-UI**。**PATCH**。**Save Editor Hub** における UI のモジュールごとの監査を継続中（`Modules/SaveEditor/`)、以下の通り`docs/ai/PROMPT_UI_SAVEEDITOR_HUB_PHASE2_2026-06-20.md`. (P0) クラスを使用したヘッダーカード上の **未保存の変更** チップ`autosaveChip`/`autosaveOrb`/`autosaveLabel` 既存の`StudioTheme`, リンク先：`IsDirty` — ユーザーがキャラクター／ギル／装備などを編集した際に表示され、「保存」または「名前を付けて保存」を実行すると消える（DataModelはすでにリセットされている）`IsDirty`). (P1) **ペイロード SHA256**（最初の12文字＋「…」）経由`FfxSaveHash.Sha256Hex(session.Core.Data)` ヘッダーに、完全なハッシュ（64文字）を表示するツールチップ付き。ロード／保存／MC切り替え時に再計算される — **再計算されない**のは`TouchDirty` (ハッシュ = メモリ内のブロブのフィンガープリント；Apply+mutateが行われるまでは、dirty ≠ ハッシュの変更)。新しいプロパティ`PayloadHashShort`/`PayloadHashFull` および方法`RefreshPayloadHash()` DataModel 内。(P2) **セッションの置換前の確認**：新規

ヘルパー`AvaloniaDialog_Util.ConfirmYesNoAsync` （新しいアセットを使用しないYes/Noモーダル）は、Load（ツールバー＋空の状態のCTA）の前に、またMCのスロットを切り替える前に呼び出されます。`IsDirty`; MCスロットのコンボは、直接のTwoWayバインディングを使用せず、代わりに`SelectionChanged` 確認ガード付き＋手動同期コンボ↔DataModel。**スコープは遵守：** FFXEDサブタブ、オフセット、`FfxSaveFile` ライター、バッチタグ、CLI`--ffx-save-rt2` まったく変更なし — ハブシェルとDataModelにのみ新しいプロパティが追加された。ビルドリリース **エラー0件**。[前回：`v2.159.2.0`]
- **`v2.159.2.0` — Blitzball Hub：重複しているシェルから`SubTabHub` 再利用可能。** Lane **Jarvis-UI**。**PATCH**。O`BlitzballHub_Control` (`Modules/BlitzballHub/`) は、その`SubTabHub_Control` もう—サブタブのセクション`tabPill`,`tabPillActive`、遅延読み込み＋タブごとのキャッシュ、Writer/Read-onlyピル、オーディオ`PlayAlternative()` クリックすると。その`MenuItem_Blitzball` さあ、一つ作ってみよう`SubTabHub_Control` com`AddTab` 5つのタブ（Writer 4つ＋Prize Atlas Read-only 1つ）に対応しており、同じピルテキストと`requiresProject: false` すべてにおいて（4つのテキストエディタは、それぞれ独自のプロジェクトの「空の状態」を維持している。Atlasはプロジェクトなしで起動する）。その`BlitzballHub_Control` (`.axaml` +`.axaml.cs`) は **削除** されます —`grep` もう見つからない`new BlitzballHub_Control()` 開発中。 **スコープは遵守済み：**`FfxLib/Blitzball/*`, RT0/RT2,`ByteSnapshotEditorSession` そして、5つのサブエディタの内部コンテンツは一切変更されておらず、変更されたのは視覚的なコンテナのみです。これは、将来の移行に向けたテンプレートとなります。`SaveEditorHub` （7つのタブがハードコードされている）。ビルドリリース **エラー0件**（既存の警告401件）。[前回：`v2.159.1.0`]
- **`v2.159.1.0` — Runtime DLL Manager: ModuleMasterDetail_Shell パイロット版 + heroGradient + レスポンシブ + オフライン／デタッチド時のバナー + 空の状態 + アクセシビリティ。** Lane **Jarvis-UI**。**PATCH**。 **Runtime DLL Manager** におけるモジュールごとの UI 監査を継続中 (`Modules/RuntimeDllManager/`)、以下の通り`PROMPT_UI_RUNTIMEDLL_2026-06-20.md`. (P0) インラインのヒーロー`#183444/#111C24/#3B4B2D` →`Classes="heroGradient"`; Chromeの16進数`#20303B` から削除されました`.axaml` (usa`RailHoverBrush`/`PanelStrokeBrush`). (P1) **1番目に消費されたもの**

r** のリポジトリから`ModuleMasterDetail_Shell`: master = ステータスカード3枚（Game root / FFX open / Hooks）；detail = ヒーロー + DLLリスト。（P1）`rsp:Responsive.Breakpoints` + スタイル`UserControl.narrow` マスターがクラッシュする。（P2）バナー`WarningBrush`/`DangerBrush` いつ`IsGameClosed` （ゲーム終了 — トグルはディスクをセットするだけ）および`IsRuntimeDetached` （プローブ／フックなしでFFXを開いた状態 — ライブステータスは信頼できない）。空の状態`Border#EmptyState` いつ`!GameRootReady`. (P3)`AutomationProperties.Name` ステータスのチェックボックスやアクションボタンにおいて；`ToggleA11yName` 項目ごと。**範囲は遵守：** デプロイ／トグル／DLL／フック／プローブのロジックには手を加えておらず、ビジュアルコンテナのみ。[以前：`v2.159.0.0`]
- **`v2.159.0.0` — Save Editorの「Character」タブ：FFXEDとの互換性（アビリティ、パーティ、ODモード、オーバードライブ）。** Lane **Jarvis-UI**。**MINOR**。「Character」タブは、ステータスとバッチボタンのみから進化しました：新機能`SaveEditor_CharacterBindings` +`FfxSaveCharacterFieldCatalog` FFXED v0.749のパネルを再現 — コンボ、アクティベーション／オーバードライブモード、パーティ（7スロット @15768）、 約95の能力（ビットフィールド @22090）、カウンター付き20種類のオーバードライブモード、オーバードライブおよび特殊能力、最大値付きスフィアレベル／ODゲージ（22088／22086）。`FfxSaveCore.ReadSaveBit/WriteSaveBit` >7のビットを修正（FFXEDのセマンティクス）`offset + bit/8`). FFXEDと同様に、UIが3列構成に再編成されました。ビルドリリース **エラー0**。[前回：`v2.158.2.0`]
- **`v2.158.2.0` — Sphere Grid Builder：ヘックス → トークン + サイドパネルの空の状態 + 行単位のツールバー。** Lane **Jarvis-UI**。**PATCH**。**Sphere Grid Builder** における UI のモジュールごとの監査を継続中（`Modules/SphereGridBuilder/`, v1 form + v2 canvas)、以下のように`PROMPT_UI_SPHEREGRID_BUILDER_2026-06-20.md`. (P0) UIのChromeの16進リテラルはトークンに変換される：`#C9A227` (警告文) →`{DynamicResource WarningBrush}` で`TopologySafetySummary`,`StatusSummary` そして`SaveSummary` (v1);`#F23A3A` (ライブリスク) →`{DynamicResource DangerBrush}` で`LiveRiskWarning`;`#22FFFFFF`/`#33FFFFFF` (区切り記号) →`{DynamicResource PanelStrokeBrush}` +`Opacity="0.4"`. (P1) キャンバスのサイドパネルが`Border#EmptyState` （すでに存在するスタイル）`StudioTheme`) タイトル *「選択されたノードはありません」* ＋ 「選択」モードの操作方法を示すサブタイトル ＋

`ModeLabel` いつ`!HasSelection`; 既存の編集ブロックは置き換えられます`IsEnabled` 著：`IsVisible="{Binding HasSelection}"`. (P1) 過密なツールバー（約20個のコントロールを含む単一のWrapPanel）を、ボタンを削除したりハンドラを変更したりすることなく、3つの固定行 — **開く** / **モード** / **検証・保存** — に再編成した。 **スコープの遵守：**`SphereGridLayoutBuilder`、セーブバイト、Square/TrueNewNodeのロジック、およびレンダリングカラーを`SphereGridCanvasView.cs` まったく変更なし — ビジュアルコンテナのみが変更された。ビルドリリース **エラー0**；ゼロ`#RRGGBB` 文字通り、私たちに`.axaml` モジュール内（コメントを除く）。[前へ：`v2.158.1.0`]
- **`v2.158.1.0` — 保存エディタ：空の状態 + 折りたたみ可能なナビゲーション + アクティブなタブ。** Lane **Jarvis-UI**。**PATCH**。モジュールごとのUI監査を継続中。現在は**保存エディタ**（FFXEDポート）を監査中。(P0) とき`HasSession == false`, その`TabHost` は、次のものに置き換えられます`Border#EmptyState` （すでに存在するスタイル：`StudioTheme`) アイコン、タイトル *「No save loaded」*、対応フォーマット（.psu / 25848 バイト / .ffx PC / .ps2 MC）を列挙したサブタイトル、および同じハンドラーを指すプライマリCTA **Load…** が付いている`Button_Load` — 逆バインディングを好む（`IsVisible="{Binding !HasSession}"`) コードビハインドにおけるロジックについて。(P1-A) 「Equipment/Items/Blitzball/Sphere Grid/Minigame/Misc」をクリックすると、アクティブなボタンがハイライトされるようになりました：削除された`tabPillActive` Characterにしか存在しなかった静的要素、そして`SelectTab(int)` 7つのボタンにクラスを適用／クリアする（`SubTabHub_Control`). (P1-B) 幅約220pxの固定サイドナビゲーションカラムが`Expander` 左側に折りたたみ可能（`ExpandDirection="Left"`, 保存された状態は`IsSectionsExpanded` DataModel では、デフォルトで展開済み） — すでに`MonsterAiEditor` オーバーホールのレイヤー4にて。（P3 軽度）`AutomationProperties.Name` ツールバーの「Load」「Save」「Save As」「FFXED」ボタン。 **適用範囲：** FFXED ロジック /`FfxSaveFile` / バッチタグ / MCマルチスロット / セーブ形式 / CLI`--ffx-save-rt2` まったく変更なし — ハブのビジュアルコンテナのみが変更されました。ビルドリリース **エラー0**。[前回：`v2.158.0.0`]
- **`v2.158.0.0` — UI監査のフォローアップ：アクセント付きトークン、ダッシュボードのクイック起動、グローバルショートカット。** Lane **Jarvis-UI**。**軽微**。所要時間：約100時間

「」の文字列`MonsterAiEditor` トークン用`Accent*Fill/BorderBrush` + スタイル`Button.accent*` で`StudioTokens`/`StudioTheme`. データ駆動型のダッシュボード・ホーム (`MainDashboard_Control`): ワークスペースの状態を持つヒーロー、レスポンシブなグリッドクイックローンチ、およびイベント`QuickLaunchRequested` ルーティング先：`Main_Window`. アプリの最初のグローバルショートカット：`Ctrl+B` (IconRailの切り替え)、`Alt+Left`/`Alt+Right` (戻る/進む)。フッター／ステータスバーおよびサイドバーのメニューをすっきりさせた（絵文字を削除；`PathIcon` （ワークスペースのバッジ内）。[前へ：`v2.157.0.0`]
- **`v2.157.0.0` — SGMネイティブノード：セーブデータの861番目のノードの読み取り／書き込み + オフセット検証ツール + RE セッション3。** Lane **Jarvis-MAGIC-SGM Native**。**MINOR**。RE検証（セッション3、`FFX_SPHEREGRID_SAVE_ORCHESTRATOR_RE_2026-06-19.md`) は次のように述べている。`A5BB70`/`A49590` これらはNodeCount駆動型（860のクランプなし）であり、ノード860は`state[1720/1721]` = **save+10404/10405**（インデックス1279までの空き領域）、バルク経由でネイティブに永続化`memcpy` — **サイドカーなし**でノードが1つ追加。新しいライブラリ`FfxSaveSphereGridRuntimeTable` (ネイティブマップ`save+8684+2*idx`, オフセットの分類） + CLI`--spheregrid-extra-node-rt0` （ノード860の往復通信で、SGリージョンのバイト識別子を使用）および`--spheregrid-save-diff` （ゲーム内でのオフセットの実証テストツール）。`SphereGridFullGridCompilerHook v1.2` に読み取り専用迂回路が追加されます`A45570` そのロゴ`menu+2/+4` (NodeCount/LinkCount) ロード後 + レコード 858..862 (FFFF=ゴースト)、空のグリッドの原因を特定中（アセット Square / マジックチェック）および L3 ゲートは`A49590`. Gates SGM-RT0-08/09 PASS（マトリックス 9/9）。ゲーム内レンダリング（参加／退出）およびネイティブ RT2 ラウンドトリップは、**Halyson 保留中**のまま。[前回：`v2.156.2.0`]
- **`v2.156.2.0` — SGM RT2 リカバリー：ランチャー／フックの強化 + RT2-03 FAIL の改ざん可能性。** Lane **Jarvis-MAGIC-SGM-RT2**。**PATCH**。`sgm_rt2_launch.ps1` vanillaとSquare identityを区別し、TrueNewNodeを環境変数に基づいてクリアする`0`, オーバーレイのハッシュを検証し、エクスポートする`FFXHOOKS_SG_ASSET_NODES/LINKS`、Squareのオーバーレイをvanilla observeに移動し、RT2-03b用の検証済みサイドカーシードを作成する。`SphereGridFullGridCompilerHook` env/manifest/sidecarごとに信頼できるカウントを使用し、seedを適用します`A53DE0`/`A54860` いつ`WRITE=1`、そしてロゴ`live/trusted/sidecar/effective`. RT2-02 バニル

la observe **PASS**; RT2-03 Square 861は、**FAIL**（グリッドが空／L3）のままです。たとえ`node=860 00/00 -> 09/00` + パッチメニューにログイン済み；RT2-04がロックされています。[前回：`v2.156.1.1`]
- **`v2.156.1.1` — SGM プロンプト監査：レーン A～E が「SUPERSEDED」とマークされ、RT2 プロンプトが更新されました。** レーン **Jarvis-MAGIC**。**REVISION**。パック`PARALLEL_LANES_SGM_MASTER` およびプロンプト`PROMPT_SGM_LANE_A/B/C/D/E_*` 現在、**SUPERSEDED**というバナーが表示されており、再度貼り付けられないようになっています；新規`PROMPT_SGM_CURRENT_RT2_PROOF_2026-06-19.md` 現在のRT2テスト用の唯一のスクリプトが改ざん可能になった。ランタイムコードの変更は不要。[以前：`v2.156.1.0`]
- **`v2.156.1.0` — SGM監査 + フルグリッドコンパイラのサイドカーライターの堅牢化。** Lane **Jarvis-MAGIC**。**PATCH**。新しいドキュメント`FFX_SPHEREGRID_SAVE_MIGRATION_AUDIT_AND_NEXT_ACTIONS_2026-06-19.md`; playbook RT2 は、単に`scripts/sgm/*`; スクリプト`scripts/sgm` 絶対パスで動作します；`SphereGridFullGridCompilerHook` さあ、記入してください`profile_key` + ハッシュ`save/layout/contents` sidecarを記述する前にenvを経由し、完全なIDがない場合の書き込みを拒否することで、最初のRT2-04における無効なJSONを回避。ステータスは引き続き**offline-valid / lab-rt2**。RT2のゲーム内実装は保留中。[前回：`v2.156.0.0`]
- **`v2.156.0.0` — SGM Lane E 完成（オフライン RT0/RT2 ハーネス）。** Lane **Jarvis-MAGIC-SGM-E**。**MINOR**。バージョン管理されたスクリプト`scripts/sgm/*` (RT0 7/7、RT2 起動、オペレーター、フィクスチャのブートストラップ); CLI`--sgm-fixtures-bootstrap`; オフライン判定 + レーン状況のドキュメント;`work/sgm_*.ps1` ラッパーを確認しました。RT0 **オフライン有効**；RT2 ゲーム内 **Halyson 保留中**（RT2-06/08 ブロック済み）。[前回：`v2.155.0.3`]
- **`v2.155.0.3` — Sphere Grid save orchestrator RE セッション 2 (レーン A)。** レーン **Jarvis-MAGIC-SGM-A**。 **REVISION**。 セーブ→ランタイムの終了 @ 8748/11308（バルクエイリアスモデル、ローダーなし）；マップはギャップを介して書き込み`A5BB70`; チャンクのロード／書き込みオーケストレーターを逆アセンブル; A47210オーバーレイを無効化。[前:`v2.155.0.2`]
- **`v2.155.0.2` — スフィアグリッド セーブ形式破綻ラボ フェーズ1（決定文書、レーンD）。** レーン **Jarvis-MAGIC-SGM-D**。 **改訂版**。 文書`FFX_SPHEREGRID_SAVE_FORMAT_BREAK_LAB_STATUS_2026-06-19.md`: ダウンストリーム・オフセット 10467 のマトリックス、判定はオプション A **ABANDON**、B **DEFER**（レーン A のギャップ）、C **ABANDON**

**; キル基準 + デザインラボの切り替え フェーズ2 ゲート付き。コードなし — 通常のエディタでバイト単位で同一。製品 = サイドカー + フック。[前回:`v2.155.0.1`]
- **`v2.155.0.1` — スフィアグリッド・セーブ・オーケストレーター IDA RE（レーン A の一部）。** レーン **Jarvis-MAGIC-SGM-A**。**改訂**。ドキュメント`FFX_SPHEREGRID_SAVE_ORCHESTRATOR_RE_2026-06-19.md`: それが証明している`A5BB70` runtime table（save bufferを除く）のみを書き込み、オーケストレーターのI/Oバルクマップ、A/Bギャップの仮説、IDAのrename-queue。Appendを`FFX_SPHEREGRID_SAVE_MIGRATION_GAPS_AND_PIPELINE`. [前へ：`v2.155.0.0`]
- **`v2.155.0.0` — Sphere Grid フルグリッドコンパイラフック（ラボ用 DLL、デフォルトでは観測専用）。** Lane **Jarvis-MAGIC-SGM-C**。**MINOR**。新規`SphereGridFullGridCompilerHook` で`FfxHooksDll` — 5つの迂回路 (`A53DE0`/`A47210`/`A49590`/`A5BB70`/`A54860`), 最小限のJSONパーサー・サイドカー、split persistスタブ、env`FFXHOOKS_ENABLE_SG_FULL_GRID_COMPILER=1` (デフォルトはOFF)。Doc`FFX_SPHEREGRID_FULL_GRID_COMPILER_HOOK_IMPL_2026-06-19.md`. **lab-rt2** — RT2なし。 [前：`v2.154.0.0`]
- **`v2.154.0.0` — Sphere Grid Save Migration: sidecar C# 読み書きライブラリ + RT0 CLI。** Lane **Jarvis-MAGIC-SGM-B**。**MINOR**。新しいライブラリ`FfxSaveSphereGridExtraStateSidecar` +`FfxSaveSphereGridExtraStateSidecarIO` (アトミックな読み込み／保存、検証、`Matches`,`BuildEmptyFromAnalyzer`, merge helpers); CLI`--spheregrid-sidecar-validate/create/info`; サンプル`work/_samples/sgm/sidecar_v1_minimal.json`; パス規則`mods/Spira Reforge/save-sidecars/<profile>/<prefix>.sphere-grid-extra.json`. Gates SGM-RT0-05/06 オフライン。[前：`v2.153.0.0`]
- **`v2.153.0.0` — Sphere Grid セーブデータの移行：アナライザー + サイドカースキーマ + フルグリッドコンパイラ仕様。** Lane **Jarvis-MAGIC**。**MINOR**。新しい読み取り専用 CLI`--spheregrid-save-migration-analyze <save> <dat0X> <dat1X> [--json]` FFXEDのセーブデータ（25,848バイト）とSquareのアセットを比較し、容量・差分・ポリシーについて報告する；スキーマ`sphere-grid-extra-state.schema.json` ノード/リンク 860+ に対するサイドカーの永続性を定義；ドキュメントではギャップマップ、フルグリッドコンパイラのフック仕様、セーブフォーマットのブレークラボ、および RT0/RT2 マトリックスに関する記述を完了。[前回：`v2.152.1.0`]
- **`v2.152.1.0` — タスク報酬インスペクター FROZEN：エディタからUIが削除されました。** Lane **Jarv

is-MAGIC**. **PATCH**. 製品のROIが低いため、フロントエンドが読み取り専用で凍結されています：**Task Rewards 🏁** メニューおよびモジュール`Modules/TaskRewardInspector/*` 削除済み；CLI`--task-reward-inspect` 「FROZEN（研究用のみ）」のバナーが表示されたままです。Doc`FFX_TASK_REWARD_INSPECTOR_FROZEN_2026-06-18.md`. 実際のオーサリング作業は、「Kernel Commands」「Treasure」「Blitzball」「Mon Editor」で引き続き行われています。[前へ：`v2.152.0.0`]
- **`v2.152.0.0` — スフィアグリッド・スクエアモード フェーズ1：セーブスクエア + dat0X+dat1Xの完全なパッケージのエクスポート。** Lane **Jarvis-MAGIC**。 **マイナー**。Canvas v2に**Square Mode**の切り替え機能、**Save Square** / **Export Square Package**ボタンが追加されました。`SphereGridSquarePackageWriter` (`square_grid_manifest.json` + レポート + README デプロイ）、保存後のベースライン更新は以下経由で`FromExisting`, manifest delta bridge を使用して`square_mode=1`. RT2フックがR27でフリーズ；結果＝Squareとして再認証がオフライン。計画：`FFX_SPHEREGRID_SQUARE_MODE_FULL_REAUTHOR_PLAN_2026-06-18.md`. [前へ：`v2.151.0.0`]
- **`v2.151.0.0` — タスク・リワードのゲームファイルの欠落：grantAbility、Ronso mon.bin、Tidus counter、corpus mode。** Lane **Jarvis-MAGIC**。**MINOR**。`TaskRewardGameFileLoader` さあ、ATELをスキャンしてください`0x01FC`/`0x01FD` （権限の付与／取り消し）、クロスリンク`mon.bin` RonsoRageId (0..999)、バトルゲート・ティダ @15852、およびモード`--all-treasure-grants` / コーパス「obtainTreasure」全体のチェックボックスUI（未加工データとフィルタリング済みデータのカウンター）。スナップショットの保存により、以下が明らかになる`TidusOverdriveUseCount`. [前へ：`v2.150.0.0`]
- **`v2.150.0.0` — タスク・リワード・インスペクター：ゲームファイルの読み込み（カーネル + ATEL）。** Lane **Jarvis-MAGIC**。**MINOR**。新規`TaskRewardGameFileLoader` 読む`command.bin`,`takara.bin`,`important.bin` そして、スキャンを行い、`.ebp` FFXプロジェクトが読み込まれた際の(obtainTreasure/hasKeyItem)。UIに「Game files」パネルと「Load」ボタンが追加されました。CLI`--game-files [--project]`. Doc`FFX_TASK_REWARD_GAME_FILE_RE_2026-06-18.md`. [前へ：`v2.149.1.0`]
- **`v2.149.1.0` — タスク報酬インスペクター：レジストリの指定フラグ（保存なし）＋実現可能性に関するドキュメント。** Lane **Jarvis-MAGIC**。**PATCH**。タブ`Task Rewards 🏁` ここで、の報酬ビットの一覧を`ffxed_registry` （シューティングスター、アタックリール、ジェクトのスフィアなど）セーブデータの読み込みを必要とせず；「Live」欄にはオプションのセーブデータのみを入力します。新しいドキュメント `doc

s/reverse/FFX_TASK_REWARD_AUTHORING_VIABILITY_2026-06-18.md` mapeia caminhos save-side / ATEL / hook com gates. [anterior: `v2.149.0.0`]
- **`v2.149.0.0` — エディタ内のタスク・リワード・インスペクタ：タスク／リワード用の読み取り専用タブ。** Lane **Jarvis-MAGIC**。**MINOR**。CLI`--task-reward-inspect` IconRailに「Avalonia」のスキンが追加されました（`Task Rewards 🏁`): キャラクター/報酬ごとにフィルタリング可能なインベントリ、選択したクエストの詳細、セーブ/データ地域のマップ、オーサリングパス、およびODモード/ゲージ/キル数/ビットのスナップショット用セーブRAWデータ（25848バイト）とブリッツボールの報酬のオプション読み込み。 ライター機能なし。オーサリング前にdiff/ATELのガードレールを維持します。[以前：`v2.148.0.0`]
- **`v2.148.0.0` — UIエディタの全面的な刷新（計画のレイヤー4～12）。** Lane **Jarvis-UI**。**MINOR**。完了`EDITOR_UI_OVERHAUL_PLAN.md`: 重いモジュール内で再表示されていた内部サイドバーを削除した（`MonsterAiEditor`,`MonsterEditor`) — 回転する`Expander` 折りたたみ式 (`Padding="8"`、アイテムごとのcardSoftなし）；密度（半径 18→12、パディング 16→12、`Button.nav` 14.12→12.8）；タイポグラフィ（`h1`/`h2`/`h3`/`label`/`body`/`muted`); 1行のヘッダー（約40px）（ワークスペースバッジ＋アイコン）；`Button.dangerAction` +`Border.pillDanger` +`:focus-visible` +`Border#EmptyState`; フッター → 1行のステータスバー; リテラルカラーをトークンに変換 (`PanelDeepColor`,`HeroAccentColor`,`RailHoverBrush`...); 実際の図像（`PathIcon` +`StudioIcons.axaml`) IconRailおよびヘッダーで；ポインタオーバー時の遷移は120ms。ビルド **エラー0件**。[前回：`v2.142.0.1`]
- **`v2.142.0.1` — Sphere Grid True New Node hook v5.2: exit probes 8E27E0/8E27B0/A54720.** Lane **Jarvis-MAGIC**. **PATCH**. RT2 R3a により、バニラ版でのクラッシュが確認されました。`A54860`; v5.2 では、UI の無効化 + コールバック slot-19 + SEH および exit-snapshot による GPU テアダウンが回避されます。RT2 R4a が必須です。[以前:`v2.142.0.0`]
- **`v2.142.0.0` — Task Reward Inspector：タスク、報酬、セーブ領域の読み取り専用インベントリ。** Lane **Jarvis-MAGIC**。**MINOR**。新しいCLI`--task-reward-inspect [--save <raw-25848-save>] [--json]` 報酬が得られるバニラゲート（ティダ／オーロン／ワッカ／キマリ／ルル／リク／ユウナ／ODモード）を一覧化し、既知のセーブエリアを明記する（`15788..15852`,

 `22090..24606`、ODモード、ブリッツボール、キー／ミニゲームフラグ、スフィアグリッド）を処理し、オーサリングの安全な道筋を提示する。ライターなしの場合：ブリッツボールのオーバードライブ賞品は、特定の賞品について引き続きメタデータのみ／ブロックされた状態となり、ATELイベント／キーフラグはREの次の課題として残る。[前回：`v2.141.0.1`]
- **`v2.141.0.1` — Sphere Grid True New Node hook v5.1: 終了パスの読み取り専用化 + A54860 後の修正。** Lane **Jarvis-MAGIC**。**PATCH**。Hookによるバグ修正`after-A5BB70` manifestを再適用していた`g_writeApply=1` にもかかわらず`g_writeSave=0`; パス`before-A54860` 「観察のみ」の状態になります；トランポリンでのSEH`A54860`/`A5BB70`. REはvanillaのexitをマッピングした`A56060 → A5BB70 → A54860 → 8E27E0`; 調査後の容疑者：`FFX_Abmap_DeactivateAndReturnToFieldUI` およびテアダウン・レンダリング`A54560/A54660`. ドキュメント：`FFX_SPHEREGRID_EXIT_POST_A54860_RE_2026-06-18.md`. RT2 R3は必須。[前へ：`v2.141.0.0`]
- **`v2.140.0.8` — Sphere Grid True New Node：アロケーターの反証、静的ABMAPバッファの証明。** Lane **Jarvis-MAGIC**。**REVISION**。スプリント A.5 IDA がゲートングの不明点を解消：`dword_2305834`/`g_FFX_AbmapMenuStatePtr` ヒープの容量不足が原因ではない；`FFX_Abmap_InitStaticMenuStateBuffers` (`0xA572E0`) はポインタを`word_133F76C+0x36E104` そしてリセット`0x12FC0` バイト。Nodeレコードは`1024 * 0x28`、つまりノード860はバッファ内にある。仮説「A5BB70がOOBを読み込むのは、アロケーターが860だから」**反証**。新たな容疑者：クラッシュ後`A54860`/メニューの脆弱なウィンドウ、またはフックの書き換え`after-A5BB70`; 今後のゲートでは、SEH/正確なフェーズを実装し、アロケーターにパッチを適用してはならない。[以前：`v2.140.0.7`]
- **`v2.140.0.7` — スフィアグリッド・トゥルー・ニュー・ノード RT2 R2 クラッシュ RE ＋ セーブレイアウトの整合。** Lane **Jarvis-MAGIC**。**REVISION**。RT2 R2（フック v5 搭載）で **CRASH** が発生`after-A54860`; 6つのサブエージェント（BG-A～F）が一致した：仮説A54860 OOB **反証**（ループ1024は読み取り専用）；エンジン**ヘッダー駆動型**（save/loadにおいてNodeCountはハードコーディングされていない）； クラッシュの候補 = OOB 読み取りで`A5BB70` se menu blob`dword_2305834` undersized; セーブSGの空き容量が約1.2 KBであることが実証的に確認された（9回のセーブ）。ドキュメント：`FFX_SPHEREGRID_TRUENEWNODE_RT2_R2_VERDICT_2026-06-18.md`,`FFX_SAVE_SPHEREGRID_ADDRESS_MAP_2026-06-18.md`, `FFX_SAVE_FORMAT_AND_SPHEREGRID_LAYOUT_2026-06

-18.md`, `FFX_SPHEREGRID_TRUENEWNODE_HOOK_V6_DRAFT_2026-06-18.md`; handoff `docs/ai/SESSION_HANDOFF_Jarvis-MAGIC_2026-06-18_0154.md`. **Próximo gate:** Sprint A.5 — IDA allocator `dword_2305834` (`sub_A44D30`/`sub_A44EF0`). [anterior: `v2.140.0.6`]
- **`v2.140.0.6` — スフィアグリッド・スクエアモード：オフライン再認証（ハンドオフ）の完全な計画。** Lane **Jarvis-MAGIC**。**REVISION**。Doc`docs/reverse/FFX_SPHEREGRID_SQUARE_MODE_FULL_REAUTHOR_PLAN_2026-06-18.md`: Squareスタイルのフロー（Saveごとにdat0X+dat1Xのペアを完全処理）、True New Nodeの達成、次のエージェントに向けたエディタ／フック／RT2／デプロイのフェーズ。[前回：`v2.140.0.5`]
- **`v2.140.0.5` — Sphere Grid TRUE NEW NODE hook v5：ライブポインタによるメニュー状態。** Lane **Jarvis-MAGIC**。**PATCH**。v4はパッチを適用していた`g_AbmapMenuState` 静的 (`0x6A3704`, IDA 内の xref は 0 個); v5 は参照を解除する`dword_2305834` (`0x2305834`) のように、exeが`A49590/A5BB70`. RT2 への進入・退出が必須。[前へ：`v2.140.0.4`]
- **`v2.140.0.4` — Sphere Grid TRUE NEW NODE hook v4: 非アクティブな新規ノードのメニューレコードをパッチ適用。** Lane **Jarvis-MAGIC**. **PATCH**.`A49590` ノードのメニューレコードが ≠ の場合にのみ state を適用する`0xFFFF`; hook v4 を初期化`g_FFX_AbmapMenuState+0x808` apply/save/recomputeを実行する前に新しいスロット用に；manifestには以下を記述`link state=0` （ゲーム内で有効化するまでは無効）。**オフ**の状態のノードでのRT2の進入／退出は依然として必須。[以前：`v2.140.0.3`]
- **`v2.140.0.3` — Sphere Grid TRUE NEW NODE hook v3: 完全なパイプライン + ダブル適用。** Lane **Jarvis-MAGIC**。**PATCH**。`SphereGridTrueNewNodeHook` 今、そらして`A45570` (レイアウト)、`A47210` (デフォルト状態のマージ)、`A5B140` (隣接性)、`A54860` （再計算）に加え、`A53DE0/A49590/A5BB70`; 新規スロットのシード値（`>= seeded count`), double-apply を`A49590`, manifest には`link state=1` そして「LAB」のバナー。RT2の進入・退出は依然として必須。[前へ：`v2.140.0.2`]
- **`v2.140.0.1` — スフィアグリッド：欠落しているフック + Unknown6ガード + スフィアパネル + カーネルクローンのリロード。** Lane **Jarvis-MAGIC**。**PATCH**。納品`SphereGridTrueNewNodeHook` +`GridTeachHook` （欠落していた出典 vs`v2.139.0.0`),`Unknown6` ABMAPのバケット再計算／検証 + Safe Transplant 対 True New Node LAB、`SphereGridNodeSphereRequirement` 

+ 「Panel」タブ、`Ability_Command.CloneDeep` + clone/delete コマンドでのグラフの再読み込み；ドキュメント RE Unknown6/L3/ランタイム状態テーブル。RT2 True 新規ノード **未処理**。[前回：`v2.140.0.0`]
- **`v2.140.0.0` — Arena+ カスタムミックス フェーズ2：チェックリスト F7 + ゲーム内での作成。**レーン**Jarvis-ARENA**。**MINOR**。カスタムミックス x3/x4/x5 でネイティブピッカーを開く（8ティック、Magus +3）→ サブプロセス`ArenaMultiBossLab.exe --compose` → キャリアを起動する；`--compose` CLI + 専用キャリア`mcyt00_22`/`nagi05_23`/`nagi05_22`; Duo–Specialsのプリセットはそのまま。設定`arena_plus_compose_vanilla_btl.txt`. ドキュメント`FFX_ARENA_PLUS_COMPOSE_PHASE1/2_2026-06-16.md`. [前へ：`v2.139.1.1`]
- **`v2.139.1.1` — Field Explorer：walk、publish、refresh 機能に加え、ドラッグ可能なオーバーレイ、MapViewer での NPC のマージ機能。** Lane **Jarvis-FIELD-RE**。**PATCH**。`--field-explorer-refresh-walk` +`publish-scout-to-editor.ps1` 再生する`field-encounters.json` btl.bin グループを削除しない；Field Explorer パネルをドラッグ可能に；WalkManifest のシャード処理をより堅牢に；Field Scout をバトル中に安全に動作させる（クワイエット化 + 重いフックの遅延実行）。50 フィールドのウォークバンドル（セッション 2026-06-17）。[前回：`v2.139.1.0`]
- **`v2.139.1.0` — SIN ポゼスト・オープナー：1ターン目のガード＋フック・イニシエート（デフォルト）（RT2 m019）。**レーン** **ジャービス-MAGIC**。**パッチ**。`BuildFirstTurnGuard` (TurnsTaken&lt;2); entry`0` usa guard always-true; デフォルトのパイロット`--clear-forced-action` + hook init;`--on-turn`/`--battle-start`. [前へ：`v2.139.0.0`]
- **`v2.139.0.0` — Sphere Grid TRUE NEW NODE LAB：マニフェストエディタ + ランタイム状態コンパイラフック。** Lane **Jarvis-MAGIC**。**MINOR**。Builder に、シード済みグリッドへの追加を行うためのオプトイン機能 **TRUE NEW NODE LAB** が追加され、保存される`dat02/dat10` +`modules/config/true_new_node_manifest.csv` +`true_new_node.flag`;`FfxHooksDll` 獲得する`SphereGridTrueNewNodeHook` マニフェストを読み、それを守り続ける`g_FFX_SphereGridRuntimeStateTable` (`word_112EC7C`) 新しいノード／リンクに対する一貫性のある処理。**必須のRT2：**「Safe Product」に昇格する前に、クラッシュすることなくSphere Gridへの参加／離脱を行うこと。[前回：`v2.138.4.2`]
- **`v2.138.4.2` — SIN Possessedのオープナー：ガード TurnsTaken + RET（バニラ版のBlizzaraのフォールスルーを回避）。** レーン **Jarvis-MAGIC**。** パッチ **。`performCommand` m166;`stopAfterAction`; p

RT2 m019の調査記録。[前へ：`v2.138.4.1`]
- **`v2.138.4.1` — SIN Possessedのオープナー：grow後のエントリポイントのリポイント修正（onTurnで実際にブロックが実行される）。** Lane **Jarvis-MAGIC**。**PATCH**。[以前：`v2.138.4.0`]
- **`v2.138.4.0` — SIN 『Possessed』のオープナー：「Possessed by Yu Yevon!」を1ターン目に発動（ベイク＋パイロットCLI）。**レーン** ジャービス-MAGIC**。**マイナー**。`SinPossessedOpener` (monmagic2`0x60E7`–`0x60EE`, 規格 m166`performCommand` Self);`--sin-possessed-scan` /`--sin-possessed-pilot`; 焼く`--possessed-opener`; gate mod を無視する`payload-candidate` オーサリングにおいて。[前へ：`v2.138.3.0`]
- **`v2.138.3.0` — Monster AI: SINギャラリー v2（実機8台；UIから汎用プロトタイプ100個を削除）。** Lane **Jarvis-MAGIC**。**PATCH**。`AiSinPresetCatalog` これ読んでみて`universal.csv`/`boss-presets.csv`; CSVを出力にコピーしました；Monster AIギャラリーを更新しました。[前回：`v2.138.2.0`]
- **`v2.138.2.0` — SIN UNI-005..008：マカラニアのプリセット（デュアル・アイス／ウォーター、フロント・ウォーターア、キュア、ホワイト・ウィンド）。**レーン**ジャービス-MAGIC**。**マイナー**。[前：`v2.138.1.0`]
- **`v2.138.0.0` — SINカタログv2をゼロから作成：CSV + boss-bindings；ベイク準備完了のコア4つ。** Lane **Jarvis-MAGIC**。**MINOR**。[前回：`v2.137.1.0`]
- **`v2.137.0.1` — Field Scout MAX：Opusのコードレビュー（P0/P1/P2 ＋ RE監査は`.i64`).** Lane **Jarvis-FIELD-RE**. **REVISION** (登録ドキュメント；ライター／動作なし)。`docs/ai/REVIEW_RESULT_FIELD_SCOUT_MAX_v2.137.0.0_Jarvis-FIELD-RE.md`: 判定：条件付きOK（lab/read-only）；**1 P0**（ロックなしの重複排除ストア → race/TOCTOU によるヒープオーバーフローが`FieldScoutHook.cpp:1055-1074`); P1 (UAFの分解;`max_warp` 広すぎる via`sub_870AC0` 任意のアクターの位置を再設定する）；P2（タカラがプレイヤーの座標を記録し、上書きする`RecordMaxZoneSlot`, ゲート`groupByte>0` ゾーン0を除外、PS`+=` O(n²))； **RE監査：** 4つのMAX関数が逆コンパイルされた (`sub_798FE0`/`sub_870AC0`/`sub_875BA0`/`sub_85A740`) — RVAs/ABIsは**バイト単位で確認済み**で、誤りはなし；RT2のギャップ（coords golden field、obtainTreasureのカバレッジ、shift17↔btlグループ）により、出力が停止する`lab` no`PORT_STATUS`. [前へ：`v2.137.0.0`]
- **`v2.137.0.0` — フィールドスカウトMAXモード：フックRE（タカラ／ワープ／ゾーン）＋NPC／トリガーオーバーレイ＋REアトラス。** Lan

および **Jarvis-FIELD-RE**。 **MINOR**。`field_scout_max.flag` (gate: heavy+ultra+max); scout v8: hooks`sub_798FE0` takara,`FFX_Field_WarpActorToPosition`,`FFX_Field_SampleEncounterZoneSlot`;`sceneGroup` @ scene+0x10; 取り込み`max-events.json`; WalkManifest`npcSpawns`/`triggerSpawns`; MapViewer の青／シアン色のマーカー。ドキュメント`docs/ai/FIELD_SCOUT_MAX_MODE.md`, **`docs/reverse/FFX_FIELD_SCOUT_RE_ADDRESS_ATLAS_2026-06-17.md`** (RVA／出典／数式)、Opusのレビュープロンプト。[前回：`v2.136.0.0`]
- **`v2.136.0.0` — フィールドスカウト ULTRA HEAVY：カテゴリ別の詳細なフラグ（マスター＋ヘビーゲート）。**レーン**Jarvis-FIELD-RE**。**マイナー**。`field_scout_ultra.flag` + 5つのサブフラグ (`field_logic`,`collision`,`encounters`,`scene_env`,`pipeline`); scout v7:`npc_spawn`,`trigger_spawn`,`ultra_*` 正直なサンプル／スタブ；2Mの重複排除；`deploy-field-scout.ps1 -Ultra`. Doc`docs/ai/FIELD_SCOUT_ULTRA_HEAVY_MODE.md`. [前へ：`v2.135.0.0`]
- **`v2.135.0.0` — Field Scout + Aurora：宝箱（bauro/chest）の取得とマップ上のオーバーレイ表示。**レーン**Jarvis-FIELD-RE**。**MINOR**。Field Scout v6 (`chest_spawn` via scene node/CHR`bauro*` +`area`/`field` （マニフェスト内）；ingest`chest-spawns.json`; WalkManifestのシャード; Aurora Field Explorer + MapViewerは、デンジャーゾーンの近くに金色のマーカーを表示する（mapout.vpa）。 [前へ：`v2.134.5.0`]
- **`v2.134.5.0` — Field Scout 公開パイプライン: lab work/ → WalkManifest エディタ (リリースバンドル)。** Lane **Jarvis-FIELD-RE**。**PATCH**。`publish-scout-to-editor.ps1`;`WalkManifest/` + 「踏みつけられた」状態のField Explorerバッジ；`work/`/`fields/`/`public/maps/` gitignored; csproj CopyToOutputDirectory. [前:`v2.134.4.0`]
- **`v2.134.4.0` — Field Scout HEAVY v5: Phyreのメッシュのワールド位置 + CHRのスポーン地点。**レーン**Jarvis-FIELD-RE**。**パッチ**。`scene_node_placed` (wx/wy/wz via`Phyre_PSceneNode_composeWorldMatrix` + ノードフックの設定)、`chr_spawn` (ActiveChrInstance スキャン +`SetWorldPosition`); 摂取`scene-nodes-world.json` +`chr-spawns.json`. [前へ：`v2.134.3.0`]
- **`v2.134.3.0` — Field Scout HEAVY：アグレッシブなキャプチャ + オフラインのtexconvパイプライン。** Lane **Jarvis-FIELD-RE**。**PATCH**。`field_scout_heavy.flag`: 重複排除 **1M**、スレッド player-trace 1.5秒、polyMeta/sh

textures内のift17、encounter/zoneのフック、すべてのシーンノード、個別のJSONLトレース；`install-field-scout-tools.ps1` (texconv),`extract-scout-textures.ps1`, デフォルトのヘビーを展開する。[前:`v2.134.2.0`]
- **`v2.134.2.0` — Field Scout v3 world_walk：完全なウォークスルーを実現するための最大キャプチャ。** Lane **Jarvis-FIELD-RE**。**PATCH**。ヒープの重複排除 **250k**；追加のフック`GetInstanceNameByIndex` →`scene_node`;`LoadAndActivateDriver` PS3Dataのすべてを出力する；`field_load` 合成パックを発行する (`geometry_inferred`); パスが緩んでいる`map/area/field`; 摂取`walk-field-catalog.json` +`deploy-field-scout.ps1`. [前へ：`v2.134.1.0`]
- **`v2.134.1.0` — Field Scout v2: 3Dジオメトリのフック（フィールドロード + .dae.phyre）。** Lane **Jarvis-FIELD-RE**。**PATCH**。`graphicFieldMapLoad` +`LoadAndActivateDriver` → manifest`field_load` /`geometry` player anchor付き；インジェストスクリプトを更新しました。[以前：`v2.134.0.0`]
- **`v2.134.0.0` — フィールドスカウト：移動中のJSONLマニフェスト（テクスチャ＋プレイヤーのアンカー＋発見されたフィールド）。**レーン**Jarvis-FIELD-RE**。**MINOR**。`FieldScoutHook` で`ffx-hooks.dll` (`field_scout.flag`): 最大65kのアセットを重複排除し、保存する`modules/field-scout/session-*.jsonl` path/cat/field/tile/px/py/pz/sceneId を含む; 取り込み`RuntimeTools/FieldScoutLab/process-scout-session.ps1` → レポート + キュー PhyreMapExportLab. Doc`docs/reverse/FFX_FIELD_SCOUT_WALK_MANIFEST_2026-06-17.md`. [前へ：`v2.133.0.0`]
- **`v2.133.0.0` — スフィアグリッドパネル + エクスプローラー：「必要なスフィア」のドロップダウンが固定される`NodeEffectBitfield` +`AppearanceType`.** Lane **Jarvis-MAGIC**. **MINOR**. パワー／マナ／スピード／アビリティ／キーのLv1～4（＋カスタム）プリセット via`SphereGridNodeSphereRequirement`;`WriteNodeTypes` 両方のフィールドが維持される（以前は常にオリジナルから継承されていた）。**Panel**タブと**Explorer → Node Types**にコンボボックスが追加され、Panelのリストには推論されたスフィアが表示される。オーサリングの「Key NV3」とスキルティーチングの修正（`0x0400`). **RT2 保留中：** レベル96以上のクローンに「アビリティ・スフィア」を記録し、ゲーム内でのコストを確認する。ファイル：`FfxLib/SphereGrid/SphereGridNodeSphereRequirement.cs`,`SphereGrid_File.Write.cs`,`Modules/SphereGridPanel/*`,`Modules/SphereGridExplorer/*`. [前へ：`v2.132.0.0`]
- **`v2.132.0.0` — スフィアグリッドビルダー：キャラクターを配置する

r`panel.bin` ～から`command.bin` + スキルピッカー + CLI キマリ・ロンソの解析。**レーン** ジャービス-MAGIC**。**MINOR**。`SphereGridPanelGrowWriter` appenda ノードタイプを`panel.bin` (jp+us) スキルテンプレートのクローン作成 (`LearnedMove = 0x3000|id`); Builderに**command.bin**のドロップダウン、**Popular panel (≥96)**ボタン、**適用**時の自動拡大機能が追加されました；JPエンコーダーを修正（ASCIIにならないように）`"Learn …"` （日本語版）。CLI`--kimahri-ronso-parse [command.bin]` OD Ronsoの統計データ（104–115、Lancet、オープナー282）。**RT2未確定：**ゲーム内でクローンスキル96以上を習得できる。ファイル：`FfxLib/SphereGrid/SphereGridPanelGrowWriter.cs`,`SphereGrid_File.Write.cs`,`Modules/SphereGridBuilder/*`,`Tools/KimahriRonsoParseRt0.cs`,`Program.cs`. [前へ：`v2.131.0.0`]
- **`v2.131.0.0` — カーネルコマンド：行の複製／削除／追加、および組み込みテキストプールでの名前／説明の編集が可能。** Lane **Jarvis-MAGIC**。**MINOR**。`KernelCommandListMutator` (append/clone/delete を`command.bin` +`monmagic*.bin`); リスト内の****クローン / 削除 / 追加**ボタン（Monster Commands 1/2との互換性）；**Name**と**Description**を編集可能な**Identity**パネル（`DisplayName`/`DisplayDescription` →`NameScriptBytes`/`DescriptionScriptBytes`, **Save**での往復（経由）`Ability_Command.WriteList`). エディタで「Path 4」の編集制限を解除（例：クローン **#320** の名前を、16進数表記なしで **Blue Magic** に変更）。**RT2 保留中：** ゲーム内でのセーブ＋ロード、および戦闘メニューでの名前・説明の確認。ファイル：`FfxLib/Ability/KernelCommandListMutator.cs` (新規)、`Modules/BattleKernel/Commands/KernelCommands_*.{axaml,cs}`,`FFXProjectEditor.csproj`, 変更履歴。[前：`v2.130.3.8`]
- **`v2.130.3.8` — Spira Reforge：第1パス「Vanilla Offensive Rebalance」確定 — 16スキルの攻撃力バフ + オートアビリティの整理 + MPスフィアの強化。**レーン**Jarvis-MAGIC**。 **リビジョン**（デザインのみ／Halysonによる決定事項のみ；今回のパスではライターや挙動に関する変更なし）。Halysonが開始しました`FFX_PLAYER_COMMAND_CATALOG_0_TO_95_2026-06-16.md` そしてこう断言した。「*魔法は役割を果たしているし、回復もできる。でも、それ以外は？ 情けない。フルブレイク？ ふざけるなよ。当たることもまずない上に、MP99を消費して与えるダメージが馬鹿げている。*」 率直な評価：`Pow`付きのノーマルな攻撃スキル20個

er = 16` (= multiplier 1.0× = Attack base) ou `電力 < 16` (= **pior que Attack**); Auron Full Break Power 16 / Acc 36 / MP 99 = crime contra o jogador. **Pacote final cravado (3 frentes em 1 pass):** **(1) Damage buff de 16 skills (Extracts removed):** Wakka 8 status-riders (Sleep/Silence/Dark Attack P16→20 Acc 50→60, Zombie Attack P16→24 Acc 50→60, Busters P16→26 Acc 100, Triple Foul P16→32 Acc 100→90 MP 24→28), Auron 4 Breaks (Power/Magic Break P16→22 Acc 50→80 MP 8→10, Armor/Mental Break P16→24 Acc 36→70 MP 12→14), **Full Break P16→48 (3× damage cravado Halyson) Acc 36→90 MP 99→75**, Tidus 2 Delays (Delay Attack P12→18 MP 5→6, Delay Buster P14→22 MP 10→12), Rikku Mug P16→20. Filosofia: Power ≥ 18 sempre quando skill paga MP; premium MP ⇒ premium Power; Breaks Acc 36-50% sobem 65-90%. **(2) Auto-Ability cleanup:** Slot 12 Half MP Cost **MANTÉM** (justificativa Halyson: Lulu Magic Booster + custos altos = ainda paga Ether/Elixir = balance natural). Slot 13 (ex-One MP Cost, cheese de 1 MP universal) **REMOVIDO → vira Mana Spring** (+5 MP/turno em batalha; regen tick passivo; substitui economia sem virar cheese — em battle de 10 turnos = +50 MP cumulativo). Slot 23 (ex-Break HP Limit) **vira "Break Limits"** (bits `0x0200 | 0x0400` OR em `ability_flags_64`, HP cap + MP cap juntos via engine vanilla; byte-edit puro, zero hook); §10.8 do VISION cravado. Slot 24 (ex-Break MP Limit) **vira "Devil's Bargain"** (+50% dano dado / +50% dano recebido — glass cannon switch simétrico; 2-pass: Pass 1 placeholder funcional agora com bit reassignment, Pass 2 hook damage calc depois com RT2). **(3) MP Sphere node bump (escopo B cravado Halyson "B simplesmente B"):** Standard Grid MP +40 → +60, Expert Grid MP +20 → +30 (escala proporcional 1.5× cross-grid). Edit trivial via `SphereGridNodeTypeEntry.IncreaseAmount` (offset 0x14, ushort) em `SphereGrid_File.cs:519`. **このセッションで決定された一連の事項：** (a) Halysonがカタログを開き、問題を特定した； (b) 20のスキル＋4つの自動能力カテゴリのバフ表を提案した； (c) Halysonは「Extracts」を削除し、「Full Break」を3回設定した；(d) 「One MP」を削除し、「Mana Shield」は設定しない（新たなメタを構築）と決定した；(e) §10.8を確認し、スロット23を反転させてBrに変更した

eak Limitsとスロット24がrepurpose（「xereca」）に変わった；(f) Devil's Bargainをスロット24に設定し、2-passの注意点も理解した；(g) Mana Springをスロット13に調整し、Spell Springのバックログを整理した。 **分類された技術的な注意点：** Devil's Bargainには、hookによるダメージ計算とREアドレスの追加が必要`FFX_DamageCalc_*` 保留中；Mana Springにはターン・ティック・フックが必要＋空きビットを特定する`ability_flags_64`; ヒットによる命中率 vs ステータス・ライダーによる命中率 — RT2で調整中; トリプルファウルによる命中率 100→90 — 調整中（「トリプル保証」が有効な場合、破綻しない）； ゲーム終盤でのフルブレイクMPスケーリングはOK（ハーフMPでは75は依然として非常に高すぎる）；オートアビリティビットの再割り当てスロット24は、空きフラグをスキャンする必要がある`AutoAbilityHardcodedFlagCatalog.cs`. **技術計画 フェーズ1（純粋なバイト編集`v2.131.x` PATCH):** 1.1`command.bin` 16 スキル攻撃力バフ、1.2 スロット23「ブレイク・リミッツ」、1.3 スロット13「マナ・スプリング」（仮）、1.4 スロット24「デビルズ・バーゲン」（仮）、1.5`panel.bin` MPノード、1.6 テキストプール、1.7 RT0/RT1 ゲートバイト識別子、1.8 RT2 パイロット。**フェーズ2（フック LAB`v2.133.x+`):** 2.1 REのダメージ計算、2.2 マナ・スプリングのターンティック・フック、2.3 デビルズ・バーゲンのダメージ・フック、2.4 RT2のフック。 **VISIONとのシナジー：** §10.4 QHの弱体化（補足 — スキルの強化＋QHの弱体化＝攻撃の多様化）、§10.5 魔法（変更なし、次回のアップデート）、§10.6 ODルルのフューリー（次回のアップデート）、§10.8 ブレイク時のHP+MP融合（今回のパス1.2で確定）、§10.9 オーロンの隠しスキル（強化 — ブレイク・リミッツ＋デビルズ・バーゲン＋ブレイクバフ＝「不死身のリスクテイカー、オーロン」）、§10.10 魔法速度（Spell Springのバックログ）、§10.11/§10.13（次パス）、パス4 ブラックマジック・エクステンデッド（間接的 — ベースラインのバニラが96以上の呪文の文脈を構築）。 **未解決事項のバックログ：** Spell Springは次の空きスロットを待機中（犠牲候補：スロット18 Double AP、19 Triple AP、21 Pickpocket、22 Master Thief — 進行/戦利品獲得のチート）；次のキャラクターごとのアイデンティティに向けたステータス/Break Sharpness §10。9. **対象外：** ライター／フック／プローブ／DLL／csproj（ライター側）。ファイル：`FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.7` →`v2.130.3.8`);`docs/reverse/FFX_SPIRA_REFORGE_VANILLA_OFFENSIVE_REBALANCE_2026-06-16.md` (新規、約280行、7つのセクション：§0 短い真実、§1 ヴァニラ・カーニバルの診断、§2 統合パッケージ c

（表16のスキル＋自動能力の整理＋MPスフィア、§3 技術的な注意点（6項目）、§4 実施計画（フェーズ1+2）、§5 未解決の問題、§6 納品版、§7 関連文献）；）`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md` +`mods/Spira Reforge/VISION_AND_ROADMAP.md` (次のページ)。[前のページ：`v2.130.3.7` [参照カタログ]
- **`v2.130.3.7` — 参考資料：96のキャラクタースキル統合カタログ（ID：`0..95`) と`Power`/`MP`/`Formula`/`Acc`/`Hits`/要素/効果 + AbiMapアーキテクチャ × パーティー全体向けバンク。** Lane **Jarvis-MAGIC**。 **REVISION** (登録ドキュメント / 参照カタログ；ライター/挙動/RT2なし；既に分散している知識を1つのドキュメントに統合するのみ`FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` +`FFX_SPELL_LEARN_ABIMAP_INFERNO_2026-06-15.md` +`FFX_BATTLE_COMMAND_MENU_INFERNO_2026-06-15.md` +`CommandCharacter_Dictionary.cs` +`Ability_Command.cs`). Halysonは、MODの運用上の参考資料として、MDの96のスキル一覧を要求した。新しいドキュメント`docs/reverse/FFX_PLAYER_COMMAND_CATALOG_0_TO_95_2026-06-16.md` （8つのセクション、約250行）：§0 TL;DR：95で限界を突き詰める（物理96ビットのAbiMap）＋REによる交差検証；§1 エンジンがメニューを決定する方法（`FFX_Btl_IsCommandAvailable @ 0x39BB70` per-char 対 party-wide を使用`CharacterUser` filter); §2 エンコーディング`LearnedMove = 0x3000 | id` の`panel.bin` (参照`SphereGridExplorer_DataModel.cs:30-31`); §3 0～95までの全カタログを9つのグループに分類（Core/Menu 0-5、Skill 6-21、Special 22-25、Cheer 26-31、Kimahri/Def/Social 32-42、 **ホワイトマジック 43-64**、**ブラックマジック 65-83**、エーオンメニュー 84-87、リク・エンドゲーム 88-95）で、FFX HDリマスター（US/JP）の公式値 — MP/パワー/フォーミュラ/命中率/ヒット数/属性/効果； §4 「魔法とは何か」を決定づけるシナリオ（3つのフラグによる）（`DamageFlags` +`DamageFormula_Enum` +`PreviewFlags`) テーブル「Cura/Revive/Cleanse/Phys/Magic/Status/Buff/Gravity/Drain」を含む； §5 グリッドでは習得できない11個のID（`missing=[0,1,2,3,4,5,33,84,85,86,87]` 全10地域 — system/Defend/Aeon/Yojimbo）； §6 96以上のIDにおけるパーティ全体への影響（オーバードライブ、エオン、モルト、ミックス、疑似AI）と、分離の設計理由3つ； §7 スピラ・リフォージが「道」と結びつくことによる影響

第4項の`v2.130.3.6`; §8 相互参照。 **対象外：** writer/hook/probe/DLL/gate。ファイル：`FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.6` →`v2.130.3.7`),`docs/reverse/FFX_PLAYER_COMMAND_CATALOG_0_TO_95_2026-06-16.md` (新規)、`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md`. [前へ：`v2.130.3.6`]
- **`v2.130.3.6` — Spira Reforge: REALITY CHECK + 3回のリバース — ルート4 (`CharacterUser` （ネイティブ）固定 + スフィアグリッド経由の習得可能。ハリソンは、私が見落としていたものを見抜いた。**レーン **ジャービス-MAGIC**。**REVISION**（2026年6月16日（木）の続き、`v2.130.3.3`; ライター／挙動なし）。本セッションにおけるアーキテクチャの反復手順：**(1) v2.130.3.2 pivot：** RE D01を発見し、ids`0..95` おそらくネイティブのものだと思います。「フック0＋空きスロット62」と記入しました。**(2) Halysonがスレッドを立てました`FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` そして「どういうこと？」と尋ねた：** 2026年6月12日の監査ですでに証明されている`0/96` 空きスロット — 96個のIDすべてがvanillaで埋まっています。私の「62個残っている」という説明は**誤り**でした。**(3) v2.130.3.4 方法3：** appendを提案しました`≥96` + キャラクターごとのフック・ホワイトリスト（Nul Wardスタイルの汎用版）、Halysonが承認。 **(4) Halysonが「方法4」を提案：** *「CommandBinで、単に『CHARACTER USE（例：TIDUS）』とスキルを選択するだけで、問題は解決するのでは？ フックなんて一切必要ないはずだ」*。 **私はそのネイティブフィールドに気づいていませんでした`[Data] public Character_Enum CharacterUser` で`Ability_Command.cs:29`** — 符号付きバイト数`command.bin` 各コマンドの使用者を制限するものです。バイト単位で正確なテスト：`FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` 86行目には、Yojimbo Dismiss（ID 87）が引用されており、そこには`CharacterUser=0x0E` (14=Yojimbo) — 標準のエンジンは、このフィールドに基づいてメニューを自動的にフィルタリングします。既存のUI (`KernelCommands_Control.axaml:434` ComboBox）。**方法4は1/2/3に代わる** — append`≥96` com`CharacterUser` UIエディタから直接設定されたキャラクターごとに。メニューフィルタへのフックはゼロ。**(5) Halysonは次のように明言した：「スキルはスフィアグリッドを通じて習得可能になる」** — これにより、Nul Ward §HのIDに関する注意点が再浮上する`≥96` （パーティー全体の「reload-by-init」が「grant grid」を上書きする）。解決策：`NulWardTe` を拡張する **1つの汎用フック**。

achHook.cpp` (já provado em `v2.130.2.0`) — (a) detour `PrepareSaveCommandState` re-asserta bits ≥96 lendo sidecar; (b) detour panel_teach escreve sidecar quando node ativa. Net hook count: 1 (generalização, não hook novo). Sidecar JSON extends `spira-reforge-flags.schema.json` do Capture Cascade. **Plano técnico atualizado (15 bloqueios honestos catalogados):** Fase 0 ✅ → Fase A append `command.bin` ≥96 com `CharacterUser` (A.1-A.7 por pool char) → Fase B sidecar schema → Fase C Sphere Grid editor scope expansion (`LearnedMove = 0x3000 | id≥96`) → Fase D hook generalizado → Fase E RT0/RT1 writer LAB → Fase F RT2 in-game piloto → Fase G Lulu Fury rows → Fase H `-ja` backlog v0.7+. **Bloqueios pequenos pendentes (spikes):** addr panel_teach runtime, sidecar JSON schema design, side-effects `CharacterUser` filter (Trio of 9999, Doublecast cross-char), Multi-Firaga random-hit field, steal-per-hit Mugra/Mugga, Wakka status-rider per hit, Tidus self-buff stacking, Auron Sentinel++ party-wide buff. **Vantagens Caminho 4 vs alternativas:** (a) zero sacrifício vanilla (coexistência total Firaga + Multi-Firaga, Demi + Demita, Mug + Mugra/Mugga, Sentinel + Sentinel++); (b) net 1 hook (vs 0 do pivot falso, vs 2-3 do Caminho 3); (c) infra ALREADY EXISTING (NulWardTeach hook + sidecar Capture Cascade + editor UI ComboBox); (d) identity vanilla intocada. **Lição honesta documentada:** "sempre que sentir 'zero hook' soando bom demais, abrir os audits existentes antes de propagar a narrativa". **Doc atualizado:** §0 verdade curta (3 reversões + 4ª decisão grid), §1 ownership model (Caminho 4 + grid teach), §7.2 plano técnico (Fases 0-H), §7.3 15 bloqueios honestos, §10 entries `v2.130.3.5` e `v2.130.3.6`. **Não toca:** writer/hook/probe/DLL. Arquivos: `FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.3` → `v2.130.3.6`, pulou `.4`/`.5` por terem sido reversões dentro da mesma sessão de design), `docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` (§0/§1/§7.2/§7.3/§10 reescritos), `CHANGELOG.md` + `changelogUS.md` + `docs/governance/VERSIONING.md` + `docs/ai/SESSION_HANDOFF.md`. [anterior: `v2.130.3.3`]
- **`v2.130.3.3` — スパイラ・リフォージ：フェーズ0 完了

A — ハリソンは、キャラクターごとのTBDプールをすべて、たった1回のプレイでクリアした（デミタ→キマリ、ワッカ 5つの呪文、オーロン MAXパック 6つの呪文、ティダ マルチヒット＋自己バフ、リク 新しい「シーフ」スキル＋1）。** レーン **ジャービス-MAGIC**。 **REVISION**（2026年6月16日の3回目のプレイ、直後の続き）`v2.130.3.2`; ライター／挙動なし）。 **決定事項がさらに4つ追加（9 → 13）：** (1) **オーナーを解任 = キマハリ**（「奇妙なモンスター」ギミック + ブルーメイジテーマ；ルルを解放してエレメンタルバーストに集中させる）； (2) **ワッカのスキルプール＝A＋Bの組み合わせ、5つの呪文** — ビオラ（範囲毒＋ダメージ）＋スリープラ （範囲睡眠）＋クワッド・ファウル（範囲トリプル・ファウル＋毒＝4ステータス）＋ダブル・バスター（2ヒット単体、2ステータスコンボRNG）＋タイド・スラッシュ（2ヒット物理） — 「ステータスマスター＋ダブルヒット＋奇抜な技」； (3) **オーロン・プール = MAXパック、6つの呪文** — マス・パワーブレイク + マス・アーマーブレイク + マス・マジックブレイク + マス・メンタルブレイク + **センチネル++**（センチネル + 物理・魔法防御ブロック + パーティー全体1ターン） + **プロヴォークジャ** (プロヴォーク＋自動センチネル＋全敵への挑発) — *「オーロンは、このゲームの最強タンクだ」*； (4) **ティダの方向性 = マルチヒット + 自己バフ、4～5つの呪文** — スパイラルスラッシュ（3ヒット単体、+5 STR／キャスト上限25） + タイダルコンボ（4ヒット範囲攻撃、 +5 AGI/キャスト上限20) + ブレードストーム (5ヒット・ランダム、+自身へのハステ1ターン) + アウロックス・ラッシュ (シグネチャー、+AGI固定 + ハステ3ターン) + オプションのチア・ストライク (2ヒット + 自身へのチア)。 *「ティダは昔から素早いキャラだった。『クイックヒット』はナーフされる予定なので、自身のステータスを上げるバフを与えるマルチヒットスキルが必要だ」* — クイックヒットナーフに対する直接的な補償 §10.6； (5) **リク +1 新規シーフスキル** — ハリソンがスキルプールを充実させるために「独自に考案されたシーフスキル」を要望；ジャービスの提案：**Sleight of Hand**（洗練されたMug）、**Pickpocket** （ターンコストなしのスティール；デフォルトはジャービス）、**スティッキー・フィンガーズ**（キャストごとに+25％スタック）、**バックスタブ**（物理防御無視）、**キャッシュ**（スティールプールを直接補充）、**スモークボム**（パーティのCTBをスキップ）。 **最終的な配分（フェーズ0）：** ルル 6 + ユウナ 5 + ワッカ 5 + リク 4 + キマハリ 3 + ティダ 4-5 + オーロン 6 = **96スロット中33-34の呪文 = 約35%の予算**（残り62+は`-ja` バックログ v0.7+ + ホワイトマジック・エクストラ）。**キャラクター間のコンボ：** オーロン「マス・メンタルブレイク」＋ ルル「マルチ・フィラガ」（MDEFなしのウェーブバースト）； オーロン「センチネル++」＋ ユウナ「P」

rotectga/Shellga（2ターン間、ほぼ完全な無敵状態）；オーロンの「プロヴォーク」＋ワッカの「クワッド・ファウル」（タンク＋集団ステータス異常）；ティダスの「ブレードストーム」＋オーロンの「マス・アーマーブレイク」（ティダのバースト＋DEFゼロのターゲット）。 **ティダスの自己バフによる追加リスク：** STR/AGIの無限スタック＝QHのようなデジェネレーション；スタック上限（STR 5 / AGI 4）による緩和＋戦闘終了ごとのデケイ（戦闘間で持続しない）。 **§9.2に残る11の未解決問題** — これらはすべて細かいサブ決定（リククの「シーフ」スキルの最終名称、ティダスの呪文を4つにするか5つにするか）か、**技術的な問題**（マルチ・フィラガのランダムヒットなど）である。`command.bin` フィールド、ヒットごとのスティール（ムグラ／ムガ）、ヒットごとのステータスライダー（ワッカ）、ティダスの自己バフのスタック、オーロンのセンチネル++（パーティー全体へのバフ）、キマハリのランセット+（持続効果） — **全体的なデザインを妨げるものではない**が、オーサリングの特定の段階を妨げる。ドナー監査`0..95` (§9.2 q18) に具体的な範囲が設定されました：約33～34スロットが必要となります。 **ドキュメント更新：** §3.1.4 デミタを§3.5.1 キマハリへ移動； §3.3 ワッカの呪文5つを確定； §3.4 リクにシーフスキルを+1追加（6つの提案あり）； §3.5 キマハリのフルプール（デミタ＋ブルーメイジ拡張2～3）；§3.6 ティダスのプール：4～5のマルチヒット＋自己バフ、QHに対するコンボによるナーフ対策；§3.7 オーロンのMAXパック：6つの呪文、キャラクター間のコンボ＋リスク／軽減； §3.8 総まとめ：33～34の呪文＝予算の35％； §9.1 13の決定事項； §9.2 11のサブ決定事項／スパイク； §10 エントリ`v2.130.3.3`. **VISION §12 更新：** キャラクターごとの最終配分表 + 出現コンボ。 **対象外：** writer/hook/probe/DLL/gate。 ファイル：`FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.2` →`v2.130.3.3`),`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` （§3.1.4 を移動 + §3.3/§3.4/§3.5/§3.6/§3.7/§3.8/§9/§10 を更新）、`mods/Spira Reforge/VISION_AND_ROADMAP.md` (§12 ビリヤード台の最終ステージ＋コンボ)、`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md`. [前へ：`v2.130.3.2`]
- **`v2.130.3.2` — Spira Reforge: アーキテクチャの転換 — 「拡張ブラックマジック」を「拡張キャラクター別コマンド」に改称（RE D01 検証済み + 適用対象を7キャラクターに拡大）。** レーン **Jarvis-MAGIC**。 **改訂**（直後の続き`v2.130.3.1`; ライター／挙動なし）。ハリソンは次のように提案した。「もし、これらのスキーの代わりに

「『誰でも』入手できるようにするなら、『特定のキャラクター限定』にはしないほうがいいんじゃない？」* — 既存のREと照らし合わせてみたところ、**vanillaのエンジンはすでにIDごとのキャラクター別所有権をネイティブでサポートしていることがわかった`0..95`**. **重要な発見（RE D01 —`FFX_SPELL_LEARN_ABIMAP_INFERNO_2026-06-15.md`):**`FFX_GrantCommandToCharacter @ 0x785D10` **SPLIT AT INDEX 96** があります：ids`< 96` ちょっと銀行に行ってくるよ`word_11307FC[74*char+3151+(id&0xFFF)/16]` (74語 =`ply_save` キャラクターごと); ids`>= 96` FLATのパーティー全体用のバンク（ストライドなし）に格納される。⇒ **キャラクターごとに学習可能な領域は正確に96ビットで、IDは0～95**。IDが96以上のものは、キャラクターごとに学習することはできない。**意味するところ：** IDの再利用`0..95` = バニラエンジンは、**フックを一切使用せずに**、各呪文を「誰」が見るかをフィルタリングする。従来の方法（IDが96以上 + Nul Ward式の迂回による制限）は採用されなかった。 **拡大された配分（Halysonによる決定 2026-06-16、引用文は原文のまま）：** **ルル**（6スペル、バーストキャスター＋HP吸収） — マルチ・フィラガ系 × 4 ＋ ドレインガ ＋ **オズモーズガ（ユナからルルへ移動）**、場合によってはデミタ； **ユナ**（5つの呪文、ホワイト／バフ範囲攻撃） — リフレクトガ + **プロテクトガ** + **シェルガ** + エスナガ + **ディスペルガ**（「リフレクトガ、プロテクトガ、シェルガ、エスナガ、ディスペルガはユナ担当」）； **リク**（魔法3つ、スティールマスター） — **コピーキャットが彼女専用になる** + **ムグラ**（2ヒット単体、2回スティール） + **ムガ**（範囲2ヒット、低ダメージ、「最大6回スティール可能!!!!」）； **ワッカ**（未定、「さらに多くのステータススキルや、もっとクレイジーなもの」）； **キマハリ**（未定、「ブルーメイジ。 モンスターのスキルや、自身のオーバードライバーさえも、マナを使って習得・使用可能になる」 — ロンソ・マナレーン担当）；**ティダ**（未定、「アイデアゼロ、でもマルチヒットスキルがあるかも」）； **オーロン**（「このゲームのクソッタレなタンク。センチネルの進化形、おそらくより強力な範囲ブレイク」）。**推定合計：96スロットのうち28～31の呪文＝予算の約30％**、残り65以上のスロットは`-ja` バックログ v0.7+ + 将来計画。**ドキュメントの§9.1で確定した決定事項が9件、§9.2**（オーナーの解任、ワッカ／ティダ／オーロンのプール、リク・コピーキャットの代替案、スフィアグリッドのワイヤー、ドナー0..95の監査、マルチ・フィラガのランダムヒットフィールド、ヒットごとのスティールを持つムグラ／ムガ、キマハリのブルーメイジの座標、ロンソのレーン）。 **このモデルの利点：** (a)

 ゼロフック・カスタム — ネイティブのバニラエンジン；(b) スフィアグリッドのツリーに真の意味が生まれる（別のツリーへ移動＝実質的なトレードオフ）；(c) ルル・フューリーが大幅に簡素化される — フューリープールはキャラクターごとのバニラ仕様となり、「フューリーからMulti-*を除外する」という問題は解消される； (d) キャプチャー・カスケード §11 および SINモード §10.13 が、キャラクターごとに異なる戦術的反応を示すようになる。**技術計画 (§7.2)：** フェーズ0：プールの確定（未定） → フェーズA：ドナー監査（開始をブロック） → フェーズB：キャラクターごとの作成（B ルル・パイロット、B.1 ユウナ・ホワイトAoE、B.2 リク・マグファミリー（ヒットごとのスティール付き）、B.3 プール（未定）） → フェーズC/D：RT0/RT1/RT2 → フェーズE：スフィアグリッド・ワイヤー（スピラグリッドエディタの拡張） → フェーズF：ルルのフューリー・ロウ → フェーズG：キマハリのブルーメイジ（ロンソ・レーンに依存） → フェーズH：-jaバックログ v0.7+。 **VISION_AND_ROADMAP.md §12を書き直し：** 「拡張ブラックマジック」 → 「拡張キャラクター別コマンド」 + キャラクター別配分表 + ブロック + ロードマップを更新。 **ドキュメント名を概念的に変更**（履歴のためファイルパスは維持）：`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` — 第11節、§1 キャラクターごとの所有権モデル（デコンパイル用RE D01バイト検証機能搭載）、§3 キャラクター別配分（3.1 ルル、3.2 ユウナ、3.3 ワッカ 未定、 3.4 リク、3.5 キマハリの調整、3.6 ティダ（未定）、3.7 オーロン（未定）、3.8 まとめ）。**対象外：** writer/hook/probe/DLL/gate。設計およびロードマップへの統合のみ。ファイル：`FFXProjectEditor/FFXProjectEditor.csproj` (`v2.130.3.1` →`v2.130.3.2`),`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` （大幅な改訂：新しい§1 RE D01、§3の配分を7文字に拡大、§5/§7/§8/§9/§10/§11の番号を付け直し、内容を更新）、`mods/Spira Reforge/VISION_AND_ROADMAP.md` （§12を改訂）、`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md`. [前へ：`v2.130.3.1`]
- **`v2.130.3.1` — スパイラ・リフォージ：拡張ブラックマジック — ハリソンによる4つの決定（マルチ・フィラガ オプションB、ターゲットごとのドレイン上限の最大化、デミタとデミの共存、ニュアンスを盛り込んだオールインクルーシブなフューリー）。**レーン** ジャービス-MAGIC**。 **REVISION** ポスト・カスケード`v2.130.3.0` （別の並行するJarvis-MAGICによるRonso Manaのマイナーなホットフィックス）。以下のデザインドキュメントの直後の続きとして`v2.130.2.1`: Hとのブレインストーミング

アリソンが、未決定だった最後の4つの選択肢を決定した。**(1) マルチ・フィラガのメカニクス — オプションB（ランダム配分）＋MP 基本値の3～5倍：** ハリソン：*「オプションBだが、『マルチ・フィラガ』、『マルチ・フォダセ』は、その威力を補うために基本スキルのMPの3～5倍を消費する。とんでもない破壊力だ」*。 メカニクス＝1回の詠唱→Nヒット（5～7）、各ヒットはランダムな敵を攻撃する（Holy/Comet/Doublecastの計算式に基づくエンジンネイティブ）。敵はRNGに応じて、同じ「マルチ・フィラガ」から1、2、3回以上のヒットを受ける可能性がある。 MPコスト＝デフォルトの4倍（マルチ・フィラガ＝64 MP）、マルチ・アルティマ＝200 MP。ジャービスの提案：最初はMPの4倍＋6ヒットから始め、RT2で調整。**スケーラブルなファミリー**（段階的な展開）：v0.5 Multi-Firaga + Multi-Blizzaga、v0.6 + Multi-Thundaga + Multi-Waterga、v0.7 + Multi-Ultima（Darkness §10.11以降）、v0.8+ バックログ Multi-Flare/Multi-Holy。 **(2) ドレインの上限 — ターゲット1体あたり9999/ターゲット（マルチ上限）：** ハリソンはその影響を十分に認識した上で実装した。生存敵4体＝1回の詠唱で最大39,996 HP回復＝究極の「攻撃型ヒーラー」。 ⚠ 長時間のアリーナ戦を崩壊させる可能性がある — 意図的な仕様であり、HalysonのMOD、エンドゲームのファンタジー要素。代償：すべてを破壊した場合、RT2以降でMPコストが最大約30まで上昇する可能性がある。**(3) デミタ vs デミ・バニラ — 共存可能：** 両方を維持する。 シングル用デミ（16 MP、ボスキラー）＋マルチ用デミタ（24 MP、ウェーブクリア）。プレイヤーがツールを選択。 コスト：IDスロットが1つ追加。**(4) ルルのフューリーはニュアンスを伴いながらすべてを含む（§4の決定事項を更新）：** バイオラ16回＝OK（ポイズンウェーブ）； ドレインガ 16× = フューリー限定上限 9999/ピック（フューリー中はターゲットごとではなく、そうでなければ最大639,936 HP回復 — 「理にかなわなくなる」）； オズモーズ・ガ 16× = OK（MP上限 9999 = ハードウォール）；デミタ 16× = OK（デミタは死亡したターゲットには命中しなくなる）； **マルチ・フィラガ 16回 = 潜在ヒット数96 ⇒ フューリーのマルチ*は hit_count=1 を使用（フューリーではシングルキャストに戻る）** または、フューリープールからマルチ*を除外（「すべてを含む」に対する唯一の例外）。最終決定によりRT2を調整。 **ドキュメントの§8で更新された未解決事項：** §8.1は決定済み（4件確定）； §8.2は未解決（スフィアグリッドのワイヤー、ホワイトマジックのAoE範囲、エレメント吸収の混乱、**ドナーのティア**）`0..95` フェーズA**をブロック、マルチ*ランダム分布`command.bin` field via spike）。**ドキュメントの更新：**`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` §2.2 ドラインガ（ターゲットごとのキャップが固定）、§2.4 解雇（c

（固定あり）、§2。5 マルチ・フィラガ（オプションB + MP 3～5×固定 + 完全なエレメンタル表）、§4 フューリー（呪文ごとのニュアンス）、§8 未解決事項（4件は決定済み、5件は未解決）、§9 提出版の更新。 **次の確実なステップ：** フェーズAの呪文IDドナー監査と`FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` — Halysonは、今すぐ導入するか、v0.5のリリースが近づくまで保留にするかを決定する。**対象外：** writer/hook/probe/DLL/gate。ファイル：`FFXProjectEditor/FFXProjectEditor.csproj` (カスケード`v2.130.3.0` →`v2.130.3.1`),`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` （§2.2／§2.4／§2.5／§4／§8／§9を更新）、`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md`. [前へ：`v2.130.3.0`]
- **`v2.130.3.0` — Ronso Mana CRASH HOTFIX (`hudSafe=26`): Blobへの書き込みがノードを蹴らなくなった（以前は`via=rich>=1 subIdx=0x01` → クラッシュ）；現在は OPT-IN 方式 + 安全なノードのみ + SEH による保護された読み取りとなっています。** Lane **Jarvis-MAGIC**。**PATCH**（によって引き起こされた動作上のクラッシュを修正）`hudSafe=25` から`v2.130.1.0` DLLが再構築／展開された際、`v2.130.2.0` （Nul Wardレーン）。**根本原因（ログ RT2`%TEMP%\ffx-hooks.log`):**`RonsoMana BLOB-PATCH2 #1 treeId=43 set subIdx=0x01 via=rich>=1 nodeOff=0x1B4 ec=24 (was 0xFF)` — 私の **(3) 「最もリッチなノード」** というフォールバック`hudSafe=25` **「CHUTADO」というノードのインデックスを作成しました** (`0x01`,`ec=24`) において`blob[2+43]`. それが`Resolve(2,1,43)` **「成功する」**というノードが **ODリングではない**場合 →`finishMenuTree` 偽のコンテンツを読み込んだ／表示した → ゲームが**クラッシュ**した。（O`0x00` かつての`hudSafe<=24` 単に−1を返すだけだったので、クラッシュはしなかった：呼び出されることはなかった`finishMenuTree`.) 私の試みが、「動作は不安定だが安全だった状態」を「クラッシュ状態」に変えてしまった。**このホットフィックス（`hudSafe=26`):** (1) **blobへの書き込みは現在OPT-IN方式となっています** — 書き込みが行われるのは`blob[2+treeId]` **送信時**`FFXHOOKS_RONSO_OD_BLOBWRITE=1`** が設定されています； **デフォルト = 何も書き込まない** （クラッシュ耐性のあるビルド、純粋に診断用として`ODBLOB`); (2) **オプトインの場合でも、**PRINCIPIADOノードのみを記録する** — (a) エントリにエンコードされたODコマンドを含むノード`0x311A`、または (b) ゲームがすでに記録済みのsibling party-OD 41..47；**決して** cを自動記録しない

hute 「最もリッチなノード」（これはログにのみ記録され、ダンプを読み取った後にハードコードされる場合がある）； (3) **ノードのすべての読み取り（`OdBlobNode`/`OdBlobEntry`) および a2=0 のブロック`DumpOdBlobStructureOnce` 現在はSEHによる保護が施されており（`__try/__except`)** — オフセットが範囲外（OOB）によるアクセス違反は、クラッシュではなく「無効なノード」として処理される； (4)`mainPtr` a2=0 の場合、サニティチェックに合格する (`> 0x10000`). ログには現在、次のように表示されます`BLOB-PATCH2 #n ... write=0|1 safe=0xXX(how) risky=0xXX(how,ec=..)` （書くことを除けば何をするかを示す）そして、オプトイン＋安全なノードの場合、`BLOB-PATCH2 WROTE ...`. バナー`hudSafe=25`→`26`. **リバーシビリティ：** envがなければ、動作は安全なバニラ版と同じ（ODが非表示、クラッシュなし）。**ビルド・デプロイは行っていない**（他のJarvis-MAGICレーンと共有のDLL）— **次回の再ビルドでは`ffx-hooks.dll` （どのレーンでも）すでにホットフィックス**が適用されています；`ReadLints` clean。ファイル：`RuntimeTools/FfxHooksDll/hooks/RonsoManaHook.cpp`. ドキュメント：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §14. [以前：`v2.130.2.1`]
- **`v2.130.2.1` — スパイラ・リフォージ：拡張された黒魔術 — デザイン・ロックダウン（マルチスキル・ファミリー > -ja ティア；`-ja` ニッチなバックログになる；Lulu Furyはすべてを含む）。** Lane **Jarvis-MAGIC**。 **REVISION**（設計文書＋VISIONへの統合；今回のパスではライター／挙動／RT2は対象外）。Halysonが新しいBlack Magicの作成に関するブレインストーミングを開始した。私は2つのアプローチを比較した：(a) **`-ja` tier**（フィラジャ／ブリザジャ／サンダジャ／ウォータージャ＝「-ga」に「+Power」を付与したクローン、フューリーを除く）対（b）**マルチスキル**（**対応する**AoE版が存在しない、バニラの単体対象呪文のAoE版）。 **決定（Halyson）：** マルチスキルがメインの選択肢として採用される；`-ja` ニッチなバックログとして保留中（要素ごとに1つ、MP消費が激しすぎる～80～120、セレスティアル以降、おまけとして――バフとは競合しない`-ga` で`VISION §10.5`); ルル・フューリー **すべてが含まれている**（「フューリー・ドレイン16×は美しいカオス、OD級のファンタジー」）。**マルチスキルが勝る理由：** (1)`TargetFlags.Multi` すでに**エンジンにネイティブに組み込まれている**（`FfxLib/Ability/Ability_Command.cs:125`) — シングル → マルチ = **コマンド行の1ビット**; (2) スペルは**バニラの実際のギャップ**（AoEポイズン、AoEドレイン、AoEオズモシスなし）を埋め、独自性を与える; (3)`-ja` 「plano」と重複しています`VISION §10.5` もうバフがかかる`-ga` 「Ignore MD」付き

EF / パワースケーリング（「再錬されたフィラガ」であり、「フィラジャ」ではない）； (4)`VISION §10.11` すでにHolyra/Holyga/Wildraについては、同じ理由（独自性のないインフレプール）から「面白いけど、たぶん使わない」と分類済み；(5) Drainga/Osmose-gaは他の戦線（Capture Cascade T7の長期戦、SINモードの呪い、モブのODマルチキャスト）を支えている。 **技術的に検証済みの第1弾呪文（v0.5+）：** **ビオラ**（AoE毒＋ダメージ、クローン・バイオ＋マルチ）、**ドレインガ**（AoE HPドレイン、上限9999/キャスト）、 **オズモーズ・ガ**（AoE MPドレイン、上限99/キャスト）、**デミタ**（AoE 50% HP、上限9999/ターゲット）、 **マルチ・フィラガ・ファミリー**（3×フィラガ AoE 連続発動、MP消費3倍 — Halysonによる直接的なアイデア：*「例えばマルチ・フィラガ>>>>>>」* — マルチ・ブリザガ／サンダガ／ウォーターガ／アルティマへと拡張可能なサブファミリー）。 **第2弾（v0.6+）：** スロウガ、リフレクトガ、デミ・フォール（「ディメンショナル・クラッシュ」75% HP 単体、MP消費大）、クォーターガ（25% HP AoE、MP消費小）。 **記録済みの正当なブロック：** (a) スペルIDスロット`0..95` — クロスチェック`FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md` 寄付者を特定するため；（b）ルル・フューリーの漕ぎ`#12408–#12422` ダンプ未完了； (c) RT2に依存するキャップバランス（キャップなし＝攻撃による回復、キャップが逼迫＝呪文が使い物にならない）； (d) マルチ・フィラガ`hit_count` player-cast RE スパイク未実装； (e) VFXはシングル版と同一（v0.5では問題なし、v0.6以降ではFlan Floodエンジンを介した色変更が既に検証済み）`v2.114.0.0`); (f) スフィアグリッドの配線については別途決定。**段階的な技術計画（ドキュメント第6.2項）：** フェーズA：ドナーIDの監査（コードなし、本ドキュメント）、フェーズB：オフラインでのオーサリング（行のクローン作成＋マルチフリップ＋パワー／MPの調整＋テキスト入力）、フェーズC：ライターLAB、フェーズD：RT2のゲーム内実装、フェーズE：フューリーの統合、フェーズF`-ja` backlog niche (v0.7+)。**MODとの連携：** 補完機能`§10.5` ブラックバフの魔法、エネルギーを供給する`§10.6` ルル・フューリー、守れ`§10.11` パズル・エレメンタル、答えて`§10.13` Drainga/Osmose-ga 対応の mob OD マルチキャスト、対応`§11` Cascade T7の戦闘を記録する。 **VISION_AND_ROADMAP.md を更新：** 新しい§12「拡張ブラックマジック — マルチスキル・ファミリー」（デザイン決定 + 第1弾・第2弾の呪文 + ロードマップとの連携 + 完全版ドキュメント）；参照番号を§13に再番号付け。 **継続的なブレインストーミングのための未解決事項：** マルチ・フィラガのメカニクス A/B/C（ダブルキャストの固定配分 vs ランダム配分 vs ハイブリッド型など）

ement — 推奨事項 A)、ターゲットごと vs キャストごとのドレイン上限、スフィアグリッドの配線、デミタ vs デミ・バニラの共存、ホワイトマジックのAoE（エスナガ？）、ドナーのティア。 **対象外：** ライター、フック、プローブ、DLL、オフライン/RT2ゲートは一切対象外。ドキュメントおよびロードマップの統合のみ。新規ドキュメント：`docs/reverse/FFX_SPIRA_REFORGE_BLACK_MAGIC_EXTENDED_RESEARCH_2026-06-16.md` （10セクション、約300行）。再生されたファイル：`FFXProjectEditor/FFXProjectEditor.csproj` (bump 4-tuple)、`mods/Spira Reforge/VISION_AND_ROADMAP.md` （新規第12項＋「参考文献」の第13項への改番）、`CHANGELOG.md` +`changelogUS.md` +`docs/governance/VERSIONING.md` +`docs/ai/SESSION_HANDOFF.md`. [前へ：`v2.130.2.0`]
- **`v2.130.2.0` — ヌル・ワード：「ホワイトマジックのメニューに何も表示されなかった」の根本原因 発見＋修正 — パーティー全体のバンクは、`party_data` 戦闘開始のたびに、騎乗メニューが表示される前にグラントを消去する。** Lane **Jarvis-MAGIC**。**PATCH**（Nul Wardのサーフェシングを妨げていた動作上のバグを修正 — 同じfeature/labの`v2.123.4.0`/`v2.124.0.2`; 決定的なREが証明された`.i64` real + re-assertの新たな迂回ルートが`NulWardTeachHook`; Halyson によって**公開**された DLL（再ビルドおよびデプロイ済み）。**症状：** menu-bound のマルチサイト対応修正後も（`v2.124.0.2`) + 読み込み時のグラント (ログ`NulWardTeach grant ch=0..6 radiant=1 umbral=1`)、戦闘中の白魔法では、ワードは**表示されなかった**。**閉鎖されたRE（idalib MCP、バイト単位で検証済み via`disasm`):**`sub_7817D0` ("`* BTL INIT`") を呼び出す`FFX_Btl_PrepareSaveCommandState`@`0x786BC0` ("`-- SAVE RAM CLEAR -- Preparing save game data`") **戦闘開始のたびに**；で`0x786CA3` 彼女は～する`mov ecx,21h; mov edi,offset dst__0; rep movsd` — コピー`0x84`カーネルの(132)バイト`party_data` (テーブルID 4) へ`dst__0=0x11307D8`, トラック`[0x11307D8,0x113085C)` **全体をカバーする**`g_PartyWideCommandBank`@`0x11307FC` (オフセット`+0x24` コピー内；データベース = 16 ワード、ID 96..351）。⇒ **パーティー全体のデータベース全体が上書きされる`party_data` あらゆる戦い**、そして`party_data` ワードビットがない → word14=0 →`IsCommandAvailable(320/321)=0` → 配置ループがワードをスキップ → 「何も表示されなかった」。**容疑者：** `FFX_Btl_InitPartyWi

deCommandBank`@`0x784960` só dá `OR` em bits 0..130 e é **debug-gated** (`if(unk_112A905){ DebugMaxAll(); Init(); }` — não roda em jogo normal); `sub_78F0B0` (Lancet/blue) e o grant só mexem bit individual. **Correção mental do §H:** `PrepareSaveCommandState` não é só "persistência" — é o **reload ATIVO por-batalha** do banco a partir do `party_data`; qualquer grant de id≥96 ausente do `party_data` (sphere-grid teach incluído) reseta toda batalha. **Categorização corrigida (empírica):** dump do `command.bin` deployado mostra os doadores Nul (NulShock id48, NulTide id49) **e** as wards (320/321) todos com `SubMenuCategorization (バイト +24) = 0x02` — wards são templatadas dos doadores, então caem na **mesma** categoria de magia branca dos Nul que já aparecem (categorização correta-por-construção; faltava só o bit de disponibilidade vivo). **O FIX (lab `teach_grant`, deployado):** `NulWardTeachHook` agora instala um `PLH::x86Detour` no `FFX_Btl_PrepareSaveCommandState`; o shim chama o original (deixa recarregar o banco do `party_data`) e **re-afirma** `g_PartyWideCommandBank[word14] |= 0x3` (Radiant bit0 + Umbral bit1) no retorno — ou seja, logo após o wipe e antes do `FFX_Btl_BuildActorCommandMenu` semear o ator. Escrita direta no banco (não chamada de grant) pra não re-entrar no menu builder de dentro do init. Log diag (4 primeiros disparos): `NulWardTeachが#nのpost-PrepareSaveCmdStateを再設定：バンク word14 0xPRE→0xPOST`. Grant one-shot mantido pros menus de field/pré-batalha. **Consequência de design (produção):** como `party_data` é a fonte por-batalha pra ids≥96, o caminho limpo pra uma ward sempre-disponível é adicionar o bit no próprio kernel `party_data` (innata, party-wide), não no sphere grid — um id≥96 ensinado no grid não persiste pós-init sem (a) o bit do `party_data` ou (b) re-assert em runtime como esse detour de lab. **Build/deploy:** `build_hooks.ps1 -WithPolyHook -Release` PASS (12/12 cpp), deploy `install_to_modules.ps1 -EnableApply -EnableTeach` (backup `ffx-hooks.dll.backup-nul-ward-20260616-081633`, novo SHA-prefix `0DE302BDF13D5B14`). Gate `--nul-ward-static` **VERDICT: PASS** (sem regressão; command.bin/exe/flags intactos). `.i64` real: コメント

～における`0x786BC0` +`0x786CA3` （黄金律）。2つの新しいRVAが`shared/ffx_addresses.h` (`RVA_FFX_BTL_PREPARE_SAVE_COMMAND_STATE`,`RVA_FFX_PARTY_WIDE_COMMAND_BANK`). **RT2 ゲーム内：** 戦闘を開始し、ホワイトマジックでラディアント／アンブラル・ワードを確認 + ログを確認`reassert ... word14 0x0000->0x0003`. 開口部の幅：`ply_save` pro bit 224/225 (§H) — ロードのたびにlabが再適用される。ファイル：`RuntimeTools/FfxHooksDll/hooks/NulWardTeachHook.cpp`,`shared/ffx_addresses.h`. ドキュメント：`docs/reverse/FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16.md` §I. [以前：`v2.130.1.0`]
- **`v2.130.1.0` — ロンソ・マナ（先週の7日）：読んだのは`DIAG`/`BLOB-PATCH` RT2より`hudSafe=24` 私がスキップしていた → ブロブのパッチには「無効なノード」と表示されていた (`subIdx=0x00`); 有効なノードを選択するように書き換え +`ODBLOB` deep dump。** Lane **Jarvis-MAGIC**。**PATCH**（破損していたヒューリスティクスを修正する`PatchCase2BlobForKimahri` + すでにリリース済みのフック/RT2への新しい読み取り専用実装；**コードは完成済み、次のDLLリリースでビルド・デプロイ予定** — 別のチームでも使用中）。**発見（行数`DIAG`/`BLOB-PATCH` の`%TEMP%\ffx-hooks.log` 今まで読んだことがなかった――ただざっと目を通すだけだった`B0 resolve`):**`BLOB-PATCH #1 treeId=43 set entry=0x00 (was 0xFF)` +`DIAG G0-ring-post blob2=0x1B5C8D70 hdr=[03 8A] maxE=138 treeId=43 entry=0x00 slots41/42/43=[FF FF 00] OK` — つまり、その`PatchCase2BlobForKimahri` **すでに存在しており、動作していた**（setou`blob[45]` から`0xFF`→`0x00`) しかし、その`Resolve(2,1,43)` **引き続き −1**。⇒ 以前のフォールバック（`maxUsed`→ほとんどいつも`0x00`) は、treeId 43 を **構造的に無効なノード** を指していた：プライマリゲートを通過する`WalkMenuBlobIndex` (`idx!=0xFF`,`43<count`) しかし、**セカンダリセレクタ`ringKind` estoura** (`v4>=node.entryCount` または`entry[v4]==0xFFFF`) →`*a3=−1`. **同じログからの追加の証拠：**`count=138` (43は範囲内 → 「カウントが小さい」ケースではない/`43>=count`);`slots 41/42 = 0xFF` (**このブロブには登録されたパーティのODがない** a2=1 → 兄弟ドナーは存在しない);`DIAG G0-finalize slot=2 od=3065 3064 3066 311A` (**リングバッファ層-A TEM**)`311A`=cmd282 Ronso Rage** — ゲートがメニューツリーのレイヤーBの解決策であり、コンテンツそのものではないことを確認）。**修正（コード、`hudSafe=25`):** (1) **`PatchCas

e2BlobForKimahri` reescrito** — agora decodifica o nó no formato EXATO do `WalkMenuBlobIndex` (`v6=(count+1)/2+2*subIdx`; `nodeOff=*(i16)(blob+2*v6+4)`; `entryCount=*(u16)(blob+nodeOff)`; `entry[k]=*(u16)(blob+nodeOff+2+2*k)`, tudo bounds-clamped) e escolhe `blob[2+43]` por prioridade: **(a)** nó que **contém `0x311A`** (assinatura exata do OD) e suporta `ringKind=1`; **(b)** sibling party-OD 41..47 já registrado com nó selector-capaz; **(c)** nó mais rico que suporta `ringKind=1` (de preferência também 12). Se NADA qualifica, **deixa `0xFF`** (a2=1 não tem nó OD usável → é fix-C/redirect pro a2=0) e loga `NO 有効なノード`, em vez de escrever lixo `0x00` como antes. (2) **novo `DumpOdBlobStructureOnce`** (read-only, dispara 1× mesmo em log-only) — dumpa os índices party-OD 41..47 do a2=1, o `entryCount`+primeiras entradas dos nós 0..23 (marcando o que tem `<<OD311A>>`), e os índices 41..47/109..115 do a2=0 (MainRing) → **1 RT2 crava o `subIdx` certo OU revela que é redirect pro a2=0**. Helpers novos (todos `static`, bounds-clamped, sem dep de PolyHook): `OdBlobNode`/`OdBlobEntry`/`OdNodeSupportsSelector`/`OdNodeContainsEncodedOd`/`ReadMainRingBlobPtr` (a2=0 = `_BASE` `0xD2A994`). Banner `hudSafe=24`→`25` (confirma DLL nova no log). **NÃO buildei/deployei** (DLL em uso por outra sala — respeitado); `ReadLints` clean; código pronto pro `build_hooks.ps1 -WithPolyHook -Release`. Arquivo tocado: `RuntimeTools/FfxHooksDll/hooks/RonsoManaHook.cpp`. Doc: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §13. [anterior: `v2.130.0.0`]
- **`v2.130.0.0` — Arena+ Multi Dark Aeon ティアロックレポート CLI (`--print-tier-lock`) + サイドカー・スキーマ v1.** Lane **Jarvis-ARENA**. **MINOR**（新機能：カタログ v2 とサイドカーの進捗状況を照合した初のオフラインレポート；スナップショットの新しい標準スキーマ LOCKED/READY/CLEARED）。**新機能`RuntimeTools/ArenaMultiBossLab/TierLockReport.cs` + 4 フラグが`Program.cs`:**`--print-tier-lock`,`--progress <path>`,`--out <json>`,`--json`. 標準モードでは、ゲート理由別にティアごとにグループ化されたヒューマンレポートを出力します（`← needs: arena.dark.valefor, ...` （rows LOCKED）およびフォールバック`rt2:<status>  risk:<...>  token:<mode>` rows では `prove` ではない

d`. Modo `--out` ou `--json` emite JSON estrito que casa com o novo schema `mods/Spira Reforge/arena/spira-arena-tier-lock-state.schema.json` v1 (`フォーマット`, `format_version`, `generated_utc`, `summary{total,cleared,ready,locked}`, `rows[]` com `state` enum `ロック済み|準備完了|クリア済み` + `unlock_requires/missing_requires`). **Regras de gating ja documentadas no schema** (sao as mesmas que o futuro hook de menu F7 vai aplicar). **Run atual contra catalog + sidecar vazio:** 13 rows total -> 9 READY (solos) + 4 LOCKED (duo/trio/quartet/penta gateados pelos solos), 0 CLEARED. **README de `mods/Spira Reforge/arena/` reescrito** com tabela completa dos 5 sidecars + comandos `--print-tier-lock` e `--validate` exemplificados. Lints clean. Build PASS. [anterior: `v2.129.0.0`]
- **`v2.129.0.0` — Arena+ Multi Dark Aeon BattleEndHook スキャフォールド（レーン 3）＋バトル終了処理パイプラインのRE。**レーン** Jarvis-ARENA**。 **MINOR**（DLLの新機能：バトルクリーンアップに関する新しい読み取り専用フック「PolyHook2」、およびバトル終了パイプラインの未公開RE）。**IDA + MCP idalib によるRE** — 関数の名前変更およびコメント追加は`work/reverse/ida/FFX_recon.i64` （適用された「黄金律」）：`FFX_Battle_EndCleanupDispatcher @ 0x79E650` (かつては`sub_79E650`),`FFX_Battle_EffectFreeAtEnd @ 0x7FB090` (かつては`sub_7FB090`, リテラルログ「(op)\top_et_battle_effect_free( battle end )」を出力し、`FFX_Battle_GetNextEncounterToken @ 0x7C5EE0` (かつては`sub_7C5EE0`). 発見された連鎖：`FFX_Btl_MainBattleTick @ 0x790C60` 以下の場合にcleanupを呼び出します`sub_888CE0(0,0,0)` 0x20ビットがオンになっている、その前に`FFX_Battle_InitEncounterFromBtlbin` 再接続するか、フィールドに戻る。 **新しいファイル：**`RuntimeTools/FfxHooksDll/hooks/BattleEndHook.{h,cpp}` （完全なスキャフォールド：迂回、登録可能なコールバック、ハンドルごとのデバウンス、`BattleEndEvent` struct com`effectHandle`/`nextEncounterTok`/`result`/`sequenceNo`). **5つの新しいRVAが`shared/ffx_addresses.h`:**`RVA_FFX_BATTLE_END_CLEANUP_DISPATCHER`,`RVA_FFX_BATTLE_EFFECT_FREE_AT_END`,`RVA_FFX_BATTLE_GET_NEXT_ENCOUNTER_TOKEN`,`RVA_FFX_BATTLE_MAIN_TICK`,`RVA_FFX_BATTLE_END_EFFECT_HANDLE` (=`dword_1134564[1743]` @`0x11360A0`). **ゲート：**`arena_plus_victory_hook.flag` (env `FFXHOOKS_ENABL

E_ARENA_PLUS_VICTORY_HOOK=1`); default OFF. **Callback default `ArenaPlus_OnBattleEnd` em `dllmain.cpp`** apenas LOGA — NAO grava no `spira-arena-progress.json` ainda. **2 TODOs explicitos para RT2 spike** com Halyson: (a) distinguir vitoria/derrota/fuga via bitmask de `sub_888CE0`; (b) mapear `effectHandle` -> `progress_flag` via correlacao com ultimo `ResolverLogHook` match. Linha de plug-in `ArenaProgress_RecordCleared` deixada comentada e explicada no codigo. Build PolyHook PASS 12/12 cpp. Doc completa em `docs/reverse/FFX_ARENA_PLUS_BATTLE_END_HOOK_RE_2026-06-16.md`. **Reversibilidade:** remover flag = vanilla instantaneo; hook nao toca memoria/return. [anterior: `v2.128.0.1`]
- **`v2.128.0.1` — ロンソ・マナ（先週のRE第6回）：ランタイム終了 — o`−1` キマハリのODは、`WalkMenuBlobIndex(blob2,43)==0`; gauge/OD-ready は完全に除外（RT2のログより）`hudSafe=24` テスト）。** Lane **Jarvis-MAGIC**。**REVISION** (RE/doc + コメント`.i64` 実際；**一切**の動作変更はなく、**DLLも変更なし** — もう一方の部屋では引き続き使用中）。**RT2のログを読んだところ、`hudSafe=24` (`%TEMP%\ffx-hooks.log`) その迂回路そのものが`B0-resolve` すでに捕捉済み — バグ#1の因果関係を完結させる。** 根拠：`B0 resolve a1=2 a2=1 treeId=43 a4=1 ->-1` (で`ringKind=1` **E**`ringKind=12`) と`P0 dispatch charge=100 max=100 590=0x0D` (OD-ready FORÇADO: このフックはすでに0x590のビットを設定しており、`79AF70` 1を返す、`6C8`、そしてピナ`max:=charge`) — **そしてODは隠れたままだった。** ⇒ **OD-ready/charge==max はゲートではない**（hudSafe 17–24の締めくくり）。さらに：`blob2=0x1B5C8D70` = **HEAP VIVO** のポインタ（`system_00` （オフラインの空）→ ゲートは、実行時に与えられるブロブの**インデックス**である。**構造的ブレークスルー（記号演算、実行時なし）：**`dword_1134564[N] ≡ unk_C8F8D0[N+1217317]` (`(0x1134564−0xC8F8D0)/4=1217317` （その通り） ⇒`dword_1134564[0]` (countが`Resolve` （読む）**それは**、その`PushMenuTreeEntry(797B80)` 増加し、そして`dword_1134564[2*v8+1537]` **これは**プッシュされた入力 → **このプッシュは、node-defのループに正確にデータを供給する`ResolveMenuTreeNode(797D60)`**;`case 2 subtype=1` →`unk_112A994[8]=0x112A9B4=blob2`. **すぐに`−1` を削減する`WalkMenuBlobIndex(blob2,43)==0`** ⇒`blob2[2+43]==0xFF` (t

reeId 43（未登録） **または**`43>=blob2[1]` (count≤43)。kind=1（sel=1）およびkind=12（sel=12）の両方が−1となったため、これは**一次ゲート**（二次セレクタではない）である。**`79BB70` (`BuildActorCommandMenu`) デコンパイルされ、ゲートのライターとして**除外**された：これは**リングバッファ層-A**のみを構築する（`ringBase+1144*slot+catOffset`、ルーティング`byte24` 1→+120/2→+72/3→+168/4→+296/0xE→+232; ヘッダー`dword28` &0x1000→+40/&0x800→+56/それ以外→+0)、**解決用**のblobも書き込まない`actor+0xF7C`. **測定が1回不足しています** (`blob2[1]` count +`blob2[2+43]` idx) — **DIAGターンキーパッチ（6行以下、読み取り専用）**を、shimに貼り付ける準備ができた`B0-resolve` ドキュメントの§12.4において、3人の候補者のフィックスが調整済み（B=記述）`blob2[2+43]`, C=パスへのリダイレクト`a2=0` （Aeonsのように、A＝ノードを合成すること）は、**1 RT2**でのダンプによって決定された。**コメント`.i64` (黄金律、ただし):**`0x797D60`/`0x797B80`/`0x797420`/`0x7985A0`/`0x112A9B4`. ドキュメント：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §12. [前項：`v2.128.0.0`]
- **`v2.128.0.0` — Arena+ Multi Dark Aeon カスタムトークンリゾルバー REDIRECT（スパイクのオプションA）。**レーン**Jarvis-ARENA**。**MINOR**（DLLの新機能：読み取り専用のスパイクに、ドキュメントに記載されているリダイレクトパスが追加されました）`FFX_ARENA_PLUS_CUSTOM_TOKEN_RESOLVER_HOOK_SPIKE.md`). **フック`ResolverLogHook` 現在、2つのモードがあります：** (a) LOGGER — 従来の動作、デフォルト； (b) REDIRECT — 以下の方法によるオプトイン`arena_plus_custom_token_resolver.flag` (env:`FFXHOOKS_ENABLE_ARENA_PLUS_CUSTOM_TOKEN_RESOLVER`). リダイレクトモードでは、vanillaのトランポリンを呼び出す前に、shimはテーブルを参照する`customToken -> aliasToken` (必須の範囲 HIWORD`0xA001..0xAFFF`); 一致した場合、そのトークンは「vanilla」というエイリアスに置き換えられ、リゾルバーは`row` 正当なもの。ダウンストリームでは通常のトークンと区別されない；元に戻すには、フラグまたはDLLを削除する。**ヘッダー内の新しいAPI**`hooks/ResolverLogHook.h`:**`SetCustomTokenRedirects(table, count)` (第32章、範囲の有効性)、`SetCustomTokenRedirectEnabled(bool)`,`IsCustomTokenRedirectEnabled()`,`ResolverRedirectHitCount()`. **新型サイドカー`mods/Spira Reforge/arena/spira-arena-custom-tokens.{json,schema.json}`** 4件のエントリが格納されています（デュオ `0xA0010

046->0x00DC0046`, trio `0xA0020046→0x00DC0046`, quartet `0xA0030046→0x01AE0046`, penta `0xA0040046→0x01AE0046`). **Carregamento no boot via `ArenaPlus_LoadCustomTokenRedirects()` em `dllmain.cpp`** — busca em `$FFXHOOKS_ARENAPLUS_CUSTOM_TOKENS_PATH` -> `<DllDir>/mods/Spira Reforge/arena/spira-arena-custom-tokens.json` -> `<DllDir>/spira-arena-custom-tokens.json`; falha em I/O ou parse mantem o hook em modo logger (zero regressao). Build PolyHook PASS 11/11 cpp. RT2 in-game **Precisa Testar** (espera ate o launcher gerar token custom; ainda nao foi conectado em UI). [anterior: `v2.127.0.0`]
- **`v2.127.0.0` — キャプチャー・カスケード Cap-1 フェーズ C：1 バイトのライター`capturable` (`MonsterCaptureFlagWriter`) + ゲート`--monster-capture-bit-rt0` vanillaコーパスにおけるPASS 361/361。**レーン**Jarvis-CAPCAS-WRITE**。**MINOR**（新機能：この機能の最初のライター）`Capture Cascade` /`Yoke of Spira`; ライブラリ + ゲート、UIはまだ未実装）。Cap-1計画のフェーズCを実装（フェーズB`v2.123.3.1` そのバイトを特定した；フェーズCがそのバイトに書き込みを行う）。**Writer (`FFXProjectEditor/FfxLib/Monster/MonsterCaptureFlagWriter.cs`):** バイトレベル（なし`Monster_File.Read(...).Write()` full struct）は、直接`bytes[StatSheetPointer + 0x78]` com`StatSheetPointer = uint32_le(bytes[0x0C])`. API：`TryGetStatSheetPointer`,`GetCaptureFlagFileOffset`,`ReadCaptureFlag`,`ReadPaddingByte`,`WriteCaptureFlag(monBin, newSlot)` (配列を複製し、バイトを反転させ、パディングを維持する`0x00`, パディングがゼロでないモンスターを「未知の亜種」として拒否する); ヘルパー`IsUncapturable`/`IsVanillaArenaSlot`/`IsSidecarArenaSlot`. 定数`Uncapturable = 0xFF`,`VanillaArenaSlotMin/Max = 0x00..0x67`,`SidecarArenaSlotMin/Max = 0x68..0xFE` (vanilla MA = 104スロット、sidecar = ベストイアリーと衝突しないキャプチャー・カスケード・リージョン)。**ゲート (`FFXProjectEditor/Tools/MonsterCaptureFlagRt0.cs`):** 経由で呼び出す`FFXProjectEditor.exe --monster-capture-bit-rt0 [monsterRoot]`、モンスターごとに3つの特性を証明する：(1) **同一値のバイト同一性** —`WriteCaptureFlag(bin, current)` ==`bin` (newSlot==current のときは writer は no-op となる); (2) **slot-only diff** —`WriteCaptureFlag(bin, target)` ～とは異なる`bin` **正確に1バイト**の `[StatSheetPointer +

 0x78]`, com padding `0x00`, todos os outros bytes byte-identical; (3) **flip-and-restore RT0** — `WriteCaptureFlag(WriteCaptureFlag(bin, target), original)` == `bin` (idempotência completa). Target é escolhido fora-da-banda por categoria: uncap (0xFF) → flip pra 0x68 (sidecar), vanilla MA → flip pra 0xFF, etc. **Resultado contra `D:\FFX Extracted\...\jppc\battle\mon` (vanilla):** **VERDICT PASS — 361/361 monstros**, 251 uncap (0xFF), 110 vanilla MA slot, 0 sidecar, 0 padding non-zero, header parse 361/361, same-value RT0 361/361, slot-only diff 361/361, flip-and-restore RT0 361/361. **Excede 6× as 58 amostras do spike Phase B.** Plugado no `RuntimeTools/offline_ci.ps1` `$editorGates` (entre `モンスター` e `出会い`) — fica como gate interno permanente. Arquivos novos: `FfxLib/Monster/MonsterCaptureFlagWriter.cs`, `Tools/MonsterCaptureFlagRt0.cs`. Tocados: `Program.cs` (wire `--monster-capture-bit-rt0`), `RuntimeTools/offline_ci.ps1` (`$editorGates`). **NÃO toca:** `m###.bin` (gate read-only — só lê arquivos vanilla, nunca escreve no disco), DLL, runtime, save, hook. Build C# Release PASS (0 erros, 384 warnings baseline). UI Phase C **não** pluggada nesta entrega — ainda biblioteca + gate, sem botão público. **Próximo passo seguro:** Phase D (UI checkbox `キャプチャ可能` no `MonEditor` + bulk writer pra Dark Aeons + Penance) ou RT2 in-game manual (Halyson edita 1 monstro descartável `0xFF→0x68` em `m###.bin` real, salva, abre o jogo, captura o monstro pra ver se o engine aceita slot fora do range vanilla 0x00..0x67). Doc: `docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_RESULT_2026-06-16.md` §5.1. [anterior: `v2.126.0.0`]
- **`v2.126.0.0` — Arena+ Multi Dark Aeon カタログバリデータ CLI (`--validate`).** レーン **ジャービス＝アリーナ**。 **マイナー**（新収容人数は`RuntimeTools/ArenaMultiBossLab`: カタログv2初のオフラインバリデータ）。新機能`RuntimeTools/ArenaMultiBossLab/CatalogValidator.cs` + フラグ`--validate [--catalog <path>] [--vanilla-root <btlRoot>]` no`Program.cs`. 以下の5つの観点から確認してください：(1)`format/format_version`; (2) 行ごとの必須項目 (`token_mode`,`battle_token`,`base_template`,`battle_id`,`raw_monster_ids`,`gil_cost`,`progress_flag`, `

rt2_status`, `リスク`, `証拠`); (3) consistencia de `unlock_requires` (cada flag deve aparecer como `progress_flag` em outra row, incluindo tier-level `unlock.requires`); (4) regex `0xXXXXXXXX` em `battle_token`, `0xXXXX` per slot em `raw_monster_ids` + anti-gap (slot vazio antes de slot ocupado = ERRO); (5) `レシピ` aponta pra arquivo existente. **Sweep opcional de recipes** via subprocess do mesmo CLI com `--dry-run` quando `--vanilla-root` for fornecido (re-roda todas as recipes em `./レシピ` automaticamente). Exit codes: 0 OK, 4 catalog inconsistente, 5 recipe dry-run failou. Run atual contra `spira-arena-catalog.json`: **PASS 0 erros / 0 warnings em 13 rows / 13 flags distintas**. [anterior: `v2.125.1.1`]
- **`v2.125.1.1` — オーロラ 弾道処理 フェーズ9 完了：計画の10フェーズ間のステータス照合（RT2 キュー完了、オフライン 100% 完了）。**レーン** ジャービス-AURORA**。 **REVISION** (ドキュメントのみ / 完了:`PORT_STATUS.md` +`docs/ai/SESSION_HANDOFF.md` +`KNOWLEDGE_BASE.md` 調整済み。動作上の変更はなく、今回の作業ではwriter/probe/DLLには一切手を加えていない）。計画のサイクルが完了した。`.cursor/plans/aurora_balistica.plan.md` （10フェーズ、Halysonにより承認されたA+Bの範囲）。**本プロジェクトで完了したフェーズ（Jarvis-AURORA、2026年6月16日）：** F0 ドキュメントの整合（REVISION`v2.123.5.1`), F1プローブ`aurora-calib-v2` MINOR (`v2.125.0.0`), F3 ドラッグによるプレビューの差分表示（オフライン）PATCH (`v2.125.1.0`). **先行作業ですでにカバー済みのフェーズ（クローズアウトの際に判明したもので、この一連の作業において新たな遅延は生じない）：** F5ゲート`camera-chunk0-edit-rt0` オフラインについてはすでに`BattleCameraScanLab` (`offline_ci.ps1` C08`BattleCameraScanLab` すでに含まれています`polar eye round-trip` +`setup FLOAT edit round-trip` +`edit byte-local + reversible` chunk0のすべてのビン（カメラ設定あり）において）。F6 PhotoModeの配線は`FfxHooksDll` すでに満席です (`PhotoMode::Tick()` Presentフックでのアクターの更新後に呼び出される`dllmain.cpp:4622`,`PhotoMode::g_base/g_pm` 定義された`dllmain.cpp:6060`, ブリッジ`NativeMenu_OnEdge`/`NativeMenu_OnHeldEnter` 登録日：`StartNativeMenuIfEnabled` `dllmain.cpp:8884`,`PhotoMode::Exit()` no`StopNativeMenu` `dllmain.cpp:8910` — ゲーム内ではRT2のみが欠けている）。F7 スパイクID

W2Sは3ドキュメント分の深さで集約されています（`FFX_AURORA_W2S_MATRIX_OWNER_IDA_DEEP_2026-06-15.md`,`FFX_AURORA_W2S_MATRIX_IDA_CHAIN_2026-06-15.md`,`FFX_W2S_D3D11_INFERNO_2026-06-15.md`) 受け入れ基準とロギング仕様が明確に定められている；ギャップ＝の読み取り専用フック`selected target id/index` メインUI（RVAが保留中、このセッションのMCP idalibへのローカルIDAデータベースのロックが解除されていない）。F8スパイクのIDAバリアントセレクターが3つのドキュメントに統合された（`FFX_AURORA_ARENA_VARIANT_IDA_DEEP_2026-06-15.md`,`FFX_AURORA_ARENA_VARIANT_SELECTION_RE_2026-06-15.md`,`FFX_ARENA_VARIANT_RUNTIME_INFERNO_2026-06-15.md`); バッジ`runtime selector UNVERIFIED` のUIに配置された`AuroraChamber` F0において。**人間でロックされているフェーズ（Halyson、RT2 ゲーム内）：** F2 RT2 calib-v2、4回のゴールデンバトル（`425/0/0`,`azit03_00`,`bsil`,`klyt00_00`) + 面積／高さごとの残留物Yの分析 — 完全なレシピは`docs/reverse/FFX_AURORA_FORCE_BATTLE_CALIBRATION_PROTOCOL_2026-06-15.md`; F3 (RT2) ドラッグ位置のみ — §B のレシピ`FFX_AURORA_MASTER_RT2_CHECKLIST_2026-06-15.md`; F4 RT2 通常成長・非ダーク・イオーン（スポーン＋AI＋戦闘終了＋クリーンアップ）；F5 RT2 極性編集；F6 RT2 フォトモード最小。**サーガ終了後のステータス（PORT_STATUS 調整済み）：** オーロラ・チェンバー`parcial → parcial+++` (X/Zの同一性がIDAで証明済み、Yの残差RT2は未処理、バリアントに「UNVERIFIED」バッジが付与されている)、`aurora-calib-v2` `validado offline / RT2 pendente`, ドラッグオーバーレイ`validado offline / RT2 pendente`, BattleCameraScanLab`validado offline (gate C08 = 1 dos 29)`, PhotoModeの配線`validado offline / RT2 pendente`, W2Sのオーナー`partial / blocked / acceptance criteria definidos`, バリアントセレクタの実行時`partial / inferred / blocked sem IDA db destravado`. **対象外：** writers、probes、DLL、build、package — 作業全体はドキュメント作成が中心で、さらに2つの小さな機能追加（probe ctl + overlay UX）があり、これらはすでにそれぞれのREVISIONSでリリース済みです。 **次の確実なステップ（Halysonへの引き継ぎ）：** 事前にセットアップ済みのRT2キューを実行する（アクティブなRT2が5つ＋ロック解除済みのIDAスパイクが1つ） — まずF2 calib-v2から（`ffxprobectl aurora-calib-v2 --route 425 0 0` （バトルロイヤル）、その後、体力の状態に応じてF3/F4/F5/F6を押す。[前へ：`v2.125.1.0`]
- **`v2.125.1.0` — オーロラ 弾道計算 フェーズ3（オフライン）：ドラッグ予測

オーバーレイでの差分表示（旧／新／Δ）。** Lane **Jarvis-AURORA**。**PATCH**（既存のドラッグモードにおけるUXの改良）`aurora-overlay.js`; 新しい機能や新しいライターは追加されず、ドラッグ位置のみのRT2前の読み出しが改善されたのみ）。 「オーロラ」計画のフェーズ3の**オフライン**部分を実装――RT2（実戦での小型モンスターの移動、保存、強制戦闘、スクリーンショット、復元）は引き続き**人間モードでロックされた状態**（Halyson）。**3つの変更点：`RuntimeTools/FFXMapViewerWeb/aurora-overlay.js`:** (1)`onPointerDown` 現在、の「ORIGINAL」座標を取得します`rawAnchors` ドラッグを開始する際（交差しながら`userData.role/index`), 保存先を`overlayState.dragging.original = {x,y,z}`. (2)`onPointerMove` setReadoutは`place role[i]:  X 12.34  Y 5.67  Z 8.90` 3部構成の新しい形式へ：`(orig) → (new) Δ=(+1.23, +0.00, -2.45)` — 明示的な合図（`+`/`-`) これにより、ドラッグの方向が明確になる。(3)`onPointerUp` 今すぐ電話して`setAnchorInfo` 持続的な要約付き` ${role}[${i}]: Δ=... (orig) → (new)` 次のイベントまで表示され続ける — 以前は、カーソルがパネルから外れると表示が消えてしまっていた。**HalysonのRT2における利点：** オペレーターは、保存する前に各モンスターをどれだけ移動させたかを正確に確認できる（`💾 Salvar posicoes`) — RT2のテストログで「X方向に1.2u、Y方向に0u、Z方向に-3.5u」を簡単に指定できるようにします。**対象外：** writer (`AuroraDragBridge`/`BattleArenaPositionWriter`), オフラインゲート、FfxHooksDll、プローブ ctl。 **Lints:**`ReadLints` clean。**次のフェーズ：** フェーズ4（RT2 grow normal non-Dark Aeon）およびフェーズ5（gate camera-chunk0-edit-rt0 offline + RT2 polar）がキューに続いています。 RT2 フェーズ3 = ヒューマン（Halyson）でブロック中。[前回：`v2.125.0.0`]
- **`v2.125.0.0` — オーロラ 弾道試験 第1フェーズ：試験`aurora-calib-v2` (CSV/JSON、residual identity/flipZ/yaw180 + height_0x534)。** Lane **Jarvis-AURORA**。**MINOR** (新機能：新しいモードの`ffxprobectl` 残差の新しいスキーマを用いたCSV+JSON形式のデータを出力する；ペアリングするのは今回が初めて`chunk3.monLive` ×`actor+0x3B0` ×`actor+0x534` （構造化されたプローブ）。オーロラ計画の**フェーズ1**の実施（`.cursor/plans/aurora_balistica.plan.md`). **適用された仕様：**`docs/reverse/FFX_AURORA_CALIBRATION_PROBE_SPEC_2026-06-15.md` (XZの同一性が証明された 2

026-06-05 IDA；残差Yは依然としてRT2未処理）。**モード：**`ffxprobectl aurora-calib-v2 [--route <field> <group> <formation>] [--battle <id>] [--out <json>] [--csv <csv>] [--max-slots <N>]` (読み取り専用、ウィンドウ以外のMMFによる計測なし)`Arm(1, ...)` （既存の）。**各スロットについて`monLive` まで`min(monCount, max-slots=16)`:** le`chunk3.monLive[s]` で`g_FFX_Battle_AreaChunk + ptr@+0x20 + 16*s` (XYZW)、解決する`actor[s] = *0x11334CC + 0xF90*s`, le`actor+0x3B0` (world XYZW)、`actor+0x3C0` (XYZWキャッシュは任意)、`actor+0x534` (height float)。3つの残差を計算します：`identity = actor - chunk`,`flipz = actor - (cx,cy,-cz)`,`yaw180 = actor - (-cx,cy,-cz)` 構成部品付き`dx/dy/dz` + RMS（フル + XZ限定）。**承認（A01に一致）：**`identity_rms_xz < 0.5` E`identity_rms * 5 < flipz_rms` E`identity_rms * 5 < yaw180_rms` ->`winner=identity`; 代替案が成立するのは、rms_alternativa<1.0 の場合のみ（IDA-proof ではあり得ない — 「UNEXPECTED — investigate」という警告を表示する）；actor_array が無効、またはワールドが非有限（despawn/アニメーション）の場合はスロットがブロックされる — その場合`blocked-runtime-state`, いいえ`fail`. **出力：** JSON (`work/actor_overlay/aurora_calib_<battle_id>_<utcstamp>.json` (デフォルト) と`verdict` 連結（`identity-confirmed-live` /`ALERT-non-identity-winner` /`blocked-runtime-state` /`partial`) + 配列`rows`; 36列の並列CSV（qpc、battle_id、route field/group/formation、area_chunk_va、actor_array_va、slot、dict_id、chunk_xyzw、actor_xyzw、actor_cache_xyz、 height_0x534, identity/flipz/yaw180_dx/dy/dz/rms, identity_rms_xz, winner, reason）。**ビルド：**`dotnet build RuntimeTools/FfxDinput8Probe/ctl/Ctl.csproj -c Release` PASS（エラー0件、既存の警告CS8632/CS0219のみ）。**実行しない：** probe DLL (`ffx-probe.dll`), ゲートオフライン、FfxHooksDll。**次の段階：** RT2 calib-v2 を使用し、Halyson と共にゴールデンバトルを4回（`azit03_00`,`bsil05`,`klyt00_00` + 以下のようなコントローラー`425/0/0`) — レシピは`docs/reverse/FFX_AURORA_FORCE_BATTLE_CALIBRATION_PROTOCOL_2026-06-15.md`. RT2 フェーズ1 = 該当なし（プローブビルドのみ）；RT2 フェーズ2 = ヒト（Halyson）でブロック中。[以前：`v2.124.0.2`]
- **`v2.124.0.2` — Build+deploy の`ffx-hooks.dll` (DLLが解放された): の固定メニューバウンドを具現化する

 Nul Ward + Nul Ward用フラグおよびRT2用アイテムスタック上限；オフライン事前チェック GREEN。**レーン**Jarvis-MAGIC**。 **REVISION**（運用：バージョン管理済みのコードの再ビルド＋デプロイ＋フラグの作成；今回のパスでは新しいソースコードの動作はなし — menu-boundの修正は`v2.123.4.0`（エディタの「LearnedMove」エンコーディングは、そのエントリ独自のものです）。HalysonがDLLを公開しました（Ronso Manaがその使用を終えました）。アクション：(1)`build_hooks.ps1 -WithPolyHook -Release` → 10/10 のフックがコンパイルされました。**以下を含む`NulWardTeachHook.cpp`** マルチサイト用フィックス（`cmp r32,140h`/`cmp eax,140h`→322、PLACEMENTのループを含むすべてのサイトをパッチ適用する`81 FF`=edi) 以前はコード化されていたもの； (2) デプロイは`install_to_modules.ps1 -EnableApply -EnableTeach` — 以前のDLLのバックアップ (`ffx-hooks.dll.backup-nul-ward-20260616-071450`), 新しいSHAプレフィックス`95E1D56A8B9269F7`, フラグ`nul_ward.flag`+`nul_ward_apply.flag`+`nul_ward_teach.flag`+`nul_ward_teach_grant.flag`; (3) **他のレーンからの要請により**、作成された`modules/item_stack_cap_255.flag` (空) → 装填する`ItemStackCapHook` (スタック上限 99→255；他レーンによるフック、共有DLLに既にコンパイル済み、デフォルト)`FFX_ITEM_STACK_CAP_EXTENDED`=255）。ゲート`--nul-ward-static` 現在 **判定：合格** (exeバイト数 + 322行 +`engine_lookup_resolves` Radiant@`0x7814`/Umbral@`0x7874` inRange + DLL文字列 + デプロイフラグ + 新しいクリア）。**RT2 ゲーム内実装済み**（Nul Ward：320/321の非攻撃型キャストはオフラインで既に検証済み、ホワイトメニューでの表示＋グリッド経由の指導＋パーシストが未実装； アイテムスタック上限：ドキュメント§8の6つのシナリオ — ポーション100個のスタック、Steal/Drop/Mix/Shop/Treasure、回帰テストフラグオフ）。ドキュメント：`FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16`,`FFX_ITEM_STACK_CAP_99_RESEARCH_2026-06-16` §8. [前：`v2.124.0.1`]
- **`v2.124.0.1` — ロンソ・マナ（先週の第5回RE）：「バー満タン」説は完全に否定された — 真のゲートはメニューツリーのノード解決である（`ResolveMenuTreeNode`), ゲージは使用しないでください。** Lane **Jarvis-MAGIC**。**REVISION** (RE/doc + ファイル名の変更/コメントの追加`.i64` 実際；**一切**の動作変更はなく、**DLLも変更なし** — 他のルームでも使用可能）。**RT2の`hudSafe=24` (v2.123.4.1) 失敗し、ログにはゲージの行全体（hudSafe 23/24）が誤っていた理由が示されています：** `

P0 ディスパッチ #1..#48 負荷=100 最大=100` em **TODOS os 48 frames** (o pino persistente funcionou, a barra ficou genuinamente cheia todo frame) + bits `0x590=0x0D` + `IsOdReady ->1` (até `vanilla=1`) + `311A` no anel — **e o OD continuou oculto / "esquerda" bloqueada**. ⇒ **`charge==max` NÃO é o gate.** (Bônus: o log inunda `警告：コマンド 0～49 に OD リングヘッダーが見つかりません` — `ScanForOdRingHeader` procura no range errado; o header de OD é cmd**282**.) **O gate REAL (provado por decompile idalib):** `FFX_Btl_UI_BuildCommandRing@0x7ACEC0` constrói o anel **principal** (Attack/Skill/Special) via `FFX_Btl_UI_BuildMainCommandRingTree@0x7A07D0` **só quando `kind<=8`**; o anel **Overdrive é `kind=12`** → **PULA `7A07D0`** e depende 100% de `ResolveMenuTreeNode(2,1,slot+41) ≥ 0` (só então `sub_7979E0` finaliza). Para Kimahri (slot 2) = `Resolve(2,1,43)`, que retorna **−1**. A causa exata está em `FFX_Btl_UI_WalkMenuBlobIndex@0x797420`: `idx=blob[2+treeId]; cnt=blob[1]; if(idx==0xFF || treeId>=cnt) return 0` → `LookupMenuBlob=0` → `解＝−1` → anel OD nunca exibe. **Mapeamento das duas vias:** principal=`Resolve(2,**0**,slot+109)` no blob `g_FFX_MenuTreeBlob_MainRing` (`*0x112A994`) — resolve OK (user vê); OD=`Resolve(2,**1**,slot+41)` no blob `g_FFX_MenuTreeBlob_OdRing` (`*0x112A9B4`) — Kimahri testa `blob[45]`. **Ambos blobs são DADO ESTÁTICO do recurso `system_01`** (via `FFX_Btl_UI_InitMenuBlobPointers@0x783ED0`: `blob = base + *(base+N)`), idênticos com/sem OD → `blob[2+treeId]` é **índice de nó, não bool** (por isso o `hudSafe=19` errou a semântica). **Nada disso lê `0x5BC`/`0x5BD` (charge/max).** **Renames+comentários `.i64` aplicados e salvos (REGRA DE OURO):** `0x112A9B4`→`g_FFX_MenuTreeBlob_OdRing`, `0x112A994`→`g_FFX_MenuTreeBlob_MainRing`, `0x112A9A8`→`g_FFX_MenuBlobBase_system01` + comentários em `0x797420`(fórmula do gate), `0x7985A0`, `0x7ACEC0`, `0x7A07D0`, `0x783ED0`. **EXPERIMENTO DECISIVO (próximo, precisa de 1 sessão DLL):** DIAG no detour de `ResolveMenuTreeNode` quando `a1==2&&a2==1` logando `treeId`, `blobPtr=*0x112A9B4`, `cnt=blob[1]`, ``idx=blob[2+treeId]`、vanillaの結果 — **2つのシナリオ**（ODが満杯であることが確認されたsave-edit対当社の強制）および**d

iffar the`idx`/`cnt`** → フィックスの正確な値を表示（入力`blob[45]` 有効にするか、treeIdをリダイレクトするか、あるいは`case 3` オペレーターごと`actor+0xF7C`). **推奨事項：** のゲージピンを元に戻す／無効化する`hudSafe=24` （それは道ではない）、ただ`gateMin/drainCost` （消費量はすでに確定済み）。資料：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §11. [前項：`v2.124.0.0`]
- **`v2.124.0.0` — アイテムのスタック上限 99→255：新規`ItemStackCapHook` no`FfxHooksDll` （新機能、フラグによるゲート制御）。** Lane **Jarvis-MAGIC**。**MINOR**（新機能：ランタイムでの新しいフック＋vanillaの制限を超えてスタックの上限を解除するライター風のパッチ；初めて実装した）`FFX_Inventory_AddItem`). **この発見（idalib MCP を通じて証明されたもの）は、`FFX_recon.i64` (2026-06-16):** スロットあたり99アイテムの上限と、**中央**のクランプが、ある関数において`FFX.exe` —`FFX_Inventory_AddItem`@`0x003905A0` (IDAフラット`0x7905A0`) — **2つ**`push 63h`** 汎用ヘルパーへのデータ渡し **`FFX_Math_ClampInt(v, 0, 99)`@`0x0039A0D0`. 14個のコーラー（steal/drop/mix/shop/treasure/event/menu）は**すべて**この単一の関数を通じて処理されます。他のパスへのclampのコピー＆ペーストは行われません。**ロード時のノーマライゼーションなし**（以下で実証済み）`FFX_Btl_PrepareSaveCommandState`@`0x786BC0`: 空のスロットのみを初期化し、既存のカウントについてはエラーを出さない）。ストレージ（1バイトの`QuantityBase+slot` セーブ +`byte[112]` RAM上の`0xD30B5C`) は、再割り当てなしで 0～255 をすでにサポートしています。**選択した戦略：** バイトナローパッチでは 255 まで対応できません（push imm8`6A FF` （-1 に対して符号拡張されるはず）→ **トランポリン＋スタブを用いた 5 バイトの迂回**（テンプレートと同様）`NovaSuperDamageHook`). 各スタブ：`push imm32 <cap>` に置き換える`push 63h`, 2～3バイト分オフセットしたデータを再生し、経由して戻る`jmp rel32` ～のために`0x00390622`/`0x00390652`. 設定可能なキャップ（設定方法：）`FFXHOOKS_ITEM_STACK_CAP` env（デフォルト 255、1～255 にクリップ）。**ゲーティング：**`item_stack_cap_255.flag` （デフォルトではオフ = 標準の挙動を維持、自然な回帰テスト）。**パッチ適用前に検証されたセンチネルバイト数：**`kExpectedNew[5] = {6A 63 6A 00 53}` (サイト #1 / 新規スロット) および`kExpectedExist[5] = {6A 63 8D 04 1E}` (サイト #2 / 既存のスロット)。2回目の書き込みが失敗した場合は自動的にロールバックされる

 （中途半端な状態で残さない）。PolyHookのビルドに成功（11/11 cpp、新しいものを含む`ItemStackCapHook.cpp`), デプロイされたリリース版DLL (`932352→935936 bytes`, 新しいフックの+3584）。リネーム＋コメント`.i64` 適用されるもの（IDAの黄金律）：`0x7905A0`→`FFX_Inventory_AddItem`,`0x79A0D0`→`FFX_Math_ClampInt`,`0x790500`→`FFX_Inventory_GetItemCount`,`0x784A90`→`FFX_Inventory_DebugMaxAll`,`g_CmdAggregateAvailArrays`→`g_FFX_InventoryAggregate`、コメントは`0x79061D`/`0x79064D` （トランポリンのレシピを使ったクランプサイト）。**UIの評価（スパイクによる）：**`safe-above-99-provavel` (ゲッターはリクランプなしの生のバイトを返す；視覚的なリスク＝2桁のレイアウトでは「100」以上でオーバーフローする可能性があるが、フォーマッタは`%d` （3桁の入力でもクラッシュしない）。**Phase 3 UIパッチは事前適用されていない** — RT2で確認済み。 **Phase 4 RT2の6つのシナリオのレシピ**（save-edit Quantity=200、steal/drop、shop buy、mix、Potionの使用、UIレンダリング）は`docs/reverse/FFX_ITEM_STACK_CAP_99_RESEARCH_2026-06-16.md` §8. RT2 ゲーム内 **テストが必要** (Halyson)。ドキュメント：`docs/reverse/FFX_ITEM_STACK_CAP_99_RESEARCH_2026-06-16.md`. 新規ファイル：`RuntimeTools/FfxHooksDll/hooks/ItemStackCapHook.{h,cpp}`. 再生されたファイル：`shared/ffx_addresses.h` (10個の新しいRVA＋定数)、`dllmain.cpp` (include + フラグ有効化機能 + InstallItemStackCapHook を`InstallHooks` + RemoveItemStackCapHook),`FfxHooksDll.vcxproj`,`build_hooks.ps1`. [前へ：`v2.123.5.1`]
- **`v2.123.5.1` — Aurora 弾道解析の完了：フェーズ0のキックオフ（ドキュメントの整合 + レガシーコメント + UNVERIFIEDバッジのバリエーション）。** Lane **Jarvis-AURORA**。 **レビュー**（ドキュメント＋RE/誠実性に関する注釈；新機能なし；構造的な動作の変更なし）。統合された計画は`.cursor/plans/aurora_balistica.plan.md` (10フェーズ、Halysonにより確認された範囲A+B：アクティブなRT2が5つ + IDA W2Sスパイク + IDAバリアントセレクタースパイク)。**このREVISIONではフェーズ0のみをリリースします**（プローブの実装前のドキュメントの整合確認）。 **4つの変更点：** (1)`PORT_STATUS.md` 「Aurora Chamber」シリーズ — **「正直さ」**という記述を修正：正しくは`transform battle→mundo e DESIGN/UNCALIBRATED (...) flip-Z e hipotese`, 現在は2026年6月5日付のIDA-proofを反映しています (`X/Z = identity`,`Y residual RT2 pendente`, ref `FFX_AURORA_BATTLE_

TO_SCENE_TRANSFORM_IDA_PROVEN_2026-06-05.md` + `FFX_AURORA_MASTER_RT2_CHECKLIST_2026-06-15.md` A01/A04/A10). (2) `PORT_STATUS.md` topo — novo bloco `2026年6月16日更新（オーロラ、弾道計算完了）` resumindo estado real Aurora reconciliado contra A15 + ordem RT2 confirmada (`azit03_00 → klyt00_00 → drag → grow → camera → photo`, depois spike IDA). (3) `RuntimeTools/FFXMapViewerWeb/aurora-overlay.js` — comentario JSDoc do header (linhas 9-10) corrigido: era `RAW バトル・ローカル — デザイン専用／未校正`, agora `X/Z方向におけるIDA検証済みIDENTITY；面積／モデル高さごとのY残差（actor+0x534）RT2保留中；flip-Zは比較／デバッグ用としてのみ維持`. (4) `FFXProjectEditor/Modules/AuroraChamber/AuroraChamber_DataModel.cs` — `variantNote` (mostrado em `SceneDetail` quando `_resolver.ResolveScenes(MapKey)` retorna mais de 1 variante) agora exibe `・ランタイムセレクタ UNVERIFIED` ao lado dos `_a/_b/_c`, pra deixar claro que o Chamber renderiza qualquer variante que o catalogo escolha enquanto o selector real (story-flag → variante) ainda nao foi provado por RE — ver A04 `FFX_AURORA_ARENA_VARIANT_SELECTION_RE_2026-06-15.md`. **Nao toca:** probe, writers, gates offline, FfxHooksDll. **Proximo (Fase 1):** implementar `aurora-calib-v2` no `RuntimeTools/FfxDinput8Probe/ctl/Program.cs` com saida CSV/JSON (residual `identity_dx/dy/dz/rms`, `flipz_*`, `yaw180_*`, `winner` enum, `height_0x534`, route + battle id) — spec em `docs/reverse/FFX_AURORA_CALIBRATION_PROBE_SPEC_2026-06-15.md`. RT2 da Fase 0: nao se aplica (doc-only + UI string). [anterior: `v2.123.5.0`]
- **`v2.123.5.0` — ヌル・ワード・グリッド・ティーチ：範囲は`command.bin` 検証済み（exeパッチなし）＋エディタでのLearnedMoveエンコーディングの修正＋オフライン検証ツール。**レーン**Jarvis-MAGIC**。**パッチ**（SphereGridExplorerエディタでの動作バグを修正＋新しいオフライン検証ツール＋RE）。 **DLLは未改変**（Ronso Manaのレーンがこれを使用中） — C#/エディタ/IDAのみ。 **RT2 #1のリスクがオフラインで解消：** REにより証明された`FFX_Kernel_LoadFileToTable`@`0x781E00` (ケース 0`"command"`) は`command.bin` **verbatim** をグローバルポインタに（`g_CommandKernelTable`@`0x112A92C`,`memcpy` （ファイル全体） — **範囲の要約なし**。 `FFX_Table_GetEntryBy

IdRange`@`0x7AB890` lê o header de range **direto dos bytes do arquivo**, mapeando exatamente no `EntryListFile`: `numRanges=int16@0`(=Signature=1), `lo=PreviousFileCount@8`(=0), `hi=(EntryCount-1)@10`, `stride=EntrySize@12`(0x60), `base=EntryTableFileOffset@16`(0x14); `record = file + 0x14 + id*0x60`. Como o `command.bin` crescido grava `EntryCount-1=321`, ids 320/321 ∈ [0,321] → resolvem **exatamente** pras linhas Radiant/Umbral appendadas. **Sem patch de exe/DLL.** **Novo `CommandKernelLookupVerifier` (FfxLib/Ability)** replica a matemática exata do engine contra os bytes crescidos e foi ligado no gate `--nul-ward-static` (check `engine_lookup_resolves`: prova offline que GetCommandEntryById(320/321) NÃO cai no fallback cmd0). **FIX no editor (SphereGridExplorer):** o dropdown LearnedMove gravava o id **cru** (`0x0140`), mas o on-disk é o id **encodado** (`0x3000|id`) — provado empiricamente pelo `SphereGridRt2Lab` (Armor Break em `panel.bin` = `0x3012`) e exigido pelo gate `(cmd & 0xFFFFF000) == 0x3000` do grant. Agora o dropdown emite `0x3000|id` (Radiant→`0x3140`, Umbral→`0x3141`) e resolve nomes mascarando `& 0xFFF`, então **o usuário pode pôr as wards no sphere grid e elas REALMENTE ensinam** (antes gravava 0x0140 e o grant rejeitava). Renames `.i64`: `0x781E00`→`FFX_Kernel_LoadFileToTable`, `g_CommandKernelTable`/`g_KernelFileSizes`/`g_AAbilityKernelTable`/`g_ItemKernelTable` + comentários provados em `0x781E00`/`0x7AB890`/`0x790AE0` (salvos via `idalib_save`). Builds C# PASS (0 erros). Doc: `docs/reverse/FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16.md` §F/§G. [anterior: `v2.123.4.1`]
- **`v2.123.4.1` — Ronso Mana hudSafe=24: gauge-fullのPINO PERSISTENTE (`max:=charge`) — 「ゲージが満タンでない限り、オーバードライブ中に左へ移動できない」という不具合を修正。** Lane **Jarvis-MAGIC**。 **PATCH**（ランタイムフックおよびREにおける動作のバグを修正）。**発見事項（ログおよび逆コンパイルにより確認済み）：** FFXは「使用可能なオーバードライブ」を**ゲージが満タン**の状態に紐付けている（`charge==max`) そして、HUD/メニューのレンダラーで **フレームごとにこれを再確認** してください — **当社のフックの外側で**。一時的なスプーフィングは`hudSafe=23` setava`max:=charge` 各トランポリンの周囲で、**修復されていた`max=255` その直後** (`EndK

imahriMaxSpoof`), então o frame em que o anel é desenhado via `max=255` (barra não-cheia) → Overdrive escondido / LEFT bloqueado. **Evidência no log RT2 (`hudSafe=23`):** `G0 メニュー charge=100 max=100` (o spoof FUNCIONOU no build) mas o OD continuou sem aparecer; `IsOdReady ... vanilla=1 ->1` (os bits 0x590 estavam setados, até pelo vanilla) e mesmo assim bloqueado. **RE desta passada (idalib MCP):** `79AF70 = (actor[0x590]>>2)&1`, `79AEE0 = (actor[0x590]>>3)&1` — **ambos forçados e =1, NÃO são o gate**; `792AB0` (`FFX_Btl_BattleMenuInputDispatch`) **constrói o anel OD `kind=12`** quando `79AF70` (logo o anel OD existe); `799AD0`/`799D60`/`7996E0`/`799830` são **resolvedores de máscara de alvo**, não o gate de OD-cheio. Conclusão: o gate vivo é a comparação `charge==max` por-frame no render — fora do alcance de um spoof transiente. **Fix:** `ApplyKimahriRuntimePoolMax` agora **fixa `max := charge` de forma PERSISTENTE** enquanto `charge>=gateMin` (a barra lê 100% cheia pra toda checagem por-frame com o menu de comando aberto; o ATB/CTB fica **pausado** durante o input de comando, então **nenhum ganho de OD é perdido**); abaixo do limiar devolve o pool real (255) pra barra reencher rumo a 0–255. O spoof transiente `開始／終了` foi **aposentado** (no-ops); o dispatch shim agora chama o pino persistente. **Tradeoff conhecido (RT2):** a barra lê cheia enquanto o OD está usável; o ganho de OD pode pausar enquanto a carga estiver na faixa usável (revisitar se o RT2 mostrar stall de ganho — escopar o pino só pro menu). Build PolyHook PASS (10/10), deploy apply mode (SHA `B092B4C6`). RT2 **Precisa Testar** (ir pra esquerda + usar Ronso Rage com carga parcial). Doc: `docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §10. [anterior: `v2.123.4.0`]
- **`v2.123.4.0` — Nul Ward：teach/menu-surface の再判定 + menu-bound フックの修正（以前は`cmp 320` （誤り）。** Lane **Jarvis-MAGIC**。**PATCH**（動作上のバグを修正）`NulWardTeachHook` + REが承認された`.i64` 実; PATCH バージョンアップ → リビジョンをリセット; 以前の HEAD`v2.123.3.1` （並行レーンのREVISIONでした）。REの完全な検索（idalib MCPで`FFX_recon.i64` （実数）で、Radiant(320)を教えるかどうか答える

/Umbral(321) via sphere grid +`command.bin` 成長したものはエンドツーエンドで機能する。**実証済みのチェーン：** (1)`FFX_GrantCommandToCharacter`@`0x785D10` id≥96のルートテーブルをパーティー全体用のバンクに設定する`g_PartyWideCommandBank`@`0x11307FC` — 16ワード/256ビット = ID 96～351；ラディアント＝ワード14のビット0、アンブラル＝ワード14のビット1； (2)`FFX_Btl_BuildActorCommandMenu`@`0x79BB70` SEEDを実行するには、データベース全体をactor+0x670にコピーします（ループは`g_CmdAggregateAvailArrays`@`0x113081C` → ベンチ = 16 語); (3)`FFX_Btl_IsCommandAvailable`@`0x79AD40` 「actor」という単語を読み上げる`818+id/16` (id320→バイト 0x68C ビット0) — 一貫性あり; (4)`FFX_SphereGrid_NodeActivateStateMachine`@`0x8CC300` case21 は grant(char, node.LearnedMove, 1) を呼び出し → 以下のノードが返される`LearnedMove=0x3140/0x3141` 教える；(5) 継続する via`FFX_IsCommandLearnedPersistent`@`0x7850E0` 同じビットを読み取ります。 **バグを発見し、修正しました：**`BuildActorCommandMenu` **3**つあります`cmp r32,140h` (2`81 FE`=esi 集計ループ内では、1つの`81 FF`=PLACEMENTのループ内で、ホワイトマジックのサブメニューにIDを挿入する部分）。メニューに320/321が表示されるかどうかは、PLACEMENTの部分だけで制御されており、`NulWardTeachHook` 以前は**最初の**試合をパッチしていた（`81 FE`（サーフェシング用のノーオペ）。修正：これで**すべての**`cmp r32,140h`→`0x142` (PolyHook PASSの再構築)。**RT2の既知のリスク：** (a)`FFX_Kernel_GetCommandEntryById`@`0x790AE0`→`FFX_Table_GetEntryByIdRange`@`0x7AB890` これは、**cmd 0 へのフォールバック**を備えたレンジテーブルです —`command.bin` 成長したユニットは、320/321をカバーする範囲を広げる必要がある（そうしないと、Radiantがcmd 0になってしまう）；(b) 持続性は、マップの幅（limit/special）に依存する`ply_save` ビット224/225（ワード14）をカバーする。**設計：** id≥96 = パーティ全体（全員が習得）、キャラクター固有ではない（上限96ビット）。リネーム＋コメントは`.i64` 実（`FFX_Btl_IsCommandAvailable`,`FFX_Btl_InitPartyWideCommandBank`,`FFX_Btl_PrepareSaveCommandState`,`FFX_Btl_BuildAggregateChildList`,`g_PartyWideCommandBank`,`g_PerCharCmdMenuState`、など）。Doc：`docs/reverse/FFX_NUL_WARD_TEACH_SURFACE_RE_VERDICT_2026-06-16.md`. [前へ：`v2.123.3.1`]
- **`v2.123.3.1` — Spira Reforge: Capture Cascade Cap-1 — bit`capturable` で`m###.bin` LOCALIZADO（Phase B spike RE doc-only）。**レーン**Jarvis-CAPTURE-RE**。**REVISION**（RE/doc、変更なし）

および行動；チェーンされた`v2.123.3.0` 別の並行レーンのマイナー — このリビジョンは純粋にドキュメント/RE用であり、あのマイナーとは競合しない）。Spike Phase Bの`Capture Cascade` doc-onlyモードで送信：制御用のバイト`capturable=true|false` それぞれ`m###.bin` バイト単位で特定され、**58個のサンプル**を用いて検証されました。**判定：** 位置 =`bytes[StatSheetPointer + 0x78]` (どこで`StatSheetPointer = uint32_le(bytes[0x0C])`); 意味論 =`0xFF` (`sbyte -1`) 捉えがたい、`0x00..0x67` capturable（バニラ版モンスターアリーナの104番テーブルのスロット）；padding`bytes[StatSheetPointer + 0x79]` いつも`0x00`. 証拠チェーンが（a）レガシーエディター v1.4 とクロスした`FFXmon4.ini` (「Capture index」ラベルを16ビットの16進数で、`00FF` = uncap), (b) struct C#`FfxLib/Monster/Monster_StatSheet.cs` 49行目～50行目（`[Data] public sbyte ArenaId` +`[Data] public byte ArenaIdPadding`), (c) 現在のUIバインディング`MonEditor_Control.axaml` 466行目（「Capture index (Arena)」）、(d) 完全な構造レイアウト（ヘッダー`MonsterHeaderFile` 0x40バイト + StatSheetセクション +`Monster_StatSheet` ArenaIdがオフセットにあるStatBlock`+0x64` 以下から始まるStatBlockに関して`section + 0x14` → ファイル相対`+0x78`). 検証結果：21/21が期待スロットで捕獲可能（以下の条件と完全に一致するケースを含む：`FFXmon4.ini` ～へ`m044=0x28`/`m045=0x29`/`m046=0x2A`/`m193=0x55`/`m194=0x56`), 16/16 ボス・アンキャップ in`0xFF`, 10/10 『Dark Aeons』（`m334..m343`) において`0xFF`, 3/3 ペナンス (`m344..m346`) において`0xFF`. **重要な運用上の修正：** 従来の前提「DAは`m106..m113`「それは間違っていた――正しいのは」`m334..m343` （試飲した場所：`FfxLib/Dictionaries/Monster_Dictionary.cs` 343行目～356行目）、Magus Sistersは3つの別々の項目として（`m341/m342/m343`). DOC-ONLY: ここに何も記述されていません`m###.bin`/DLL/runtime/save/hook このセッションでは。実行されなかった：ゲートキーパーのIDAによる確認`CanCapture()` （PLANのステップ3：オプション）；vanillaツリーを用いた交差検証`D:\FFX Extracted\` （推奨されるが必須ではない — 58/58の改造版は、FFXmon4.ini経由でバニラ版の期待値とすでに一致している）。アーティファクト：`docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_RESULT_2026-06-16.md` (Phase Cのライターによる収益を含む完全なRESULTドキュメント)、`work/_capture_re_2026-06-16/parse

_capture_offset.ps1` (parser CLI), `work/_capture_re_2026-06-16/dump_arena_id_evidence.ps1` (bulk dump), `work/_capture_re_2026-06-16/capture_re_evidence_summary.json` (58 rows), `work/_capture_re_2026-06-16/capture_re_evidence_hexdump.txt`. PLAN doc original ganhou banner BLOQUEIO RESOLVIDO + IDs DA corrigidos. `PORT_STATUS.md` ganhou row "Capture Cascade Cap-1 — bit `キャプチャ可能` localizado" como `ゲーム内でのテストが必要（Phase Cライター）`. Cap-1 writer (Phase C, próxima sessão) escreve **1 byte** por monstro mantendo byte-identity dos 8 fields adjacentes. [anterior: `v2.123.3.0`（並行ブランチ；リリース時の変更履歴への記載）]
- **`v2.123.2.0` — Ronso Mana: コマンドリングの根本的な修正 — リングバッファのベースが参照されていなかった（バグ #1）。** Lane **Jarvis-MAGIC**。 **PATCH**（ランタイムフックおよびREにおける動作上のバグを修正）。**発見事項：**コマンドリングのバッファは**ランタイムに割り当てられる**。その絶対ポインタはBSSセクター内のセルに存在し（`*(u32*)0x2310CD8`). O`7AEFC0`/`79BB70` する`mov edi,[célula]` (**DEREF**) インデックス作成前`+20592` (ソート用のスクラッチ) /`+1144*slot` （ポル・アトル・リング）。O`RonsoManaHook.cpp` 使っていた`RVA_FFX_BATTLE_COMMAND_RING_BSS_BASE=0x1F0FCD8` **生データ、derefなし、さらに0x1000オフセット** — つまり、リングへの**すべての**書き込み（テンプレート、スロットごとのヘッダー`+0`, OD行`+296`) の`hudSafe 11..21` 静的なBSSに落ち込んでしまい、**表示されていたアクティブなバッファとは決して一致しなかった**。これが、BSSリングへのインジェクションが一度も表示されなかった理由、そして`CopyMenuTemplate_Shim` (迂回路：`7AEFC0`) はいつも早期返却（`delta = slotPtr - ringBase` （1144の倍数ではなかった）。**修正：** 新規`RVA_FFX_BATTLE_COMMAND_RING_BASE_PTR=0x1F10CD8` （実際のポインタセル。命令のimm32から抽出されたもの）`mov edi,[..]@0x7AEFC8`) +`BattleCommandRingUiBase()` 次に、そのセルを**参照解除**します（`*(u32*)(g_base+RVA)`（割り当てられていない場合はnullチェック）。これにより、`PatchKimahriCommandRingUi` (+0 ヘッダー)、`PatchKimahriMainMenuOverdriveRow` (+296 OD) および`CopyMenuTemplate_Shim` (+296 ポストソート) が**リアル**リングに初めて書き込みました。**RE 承認済み (IDA)：**`7AD980` = 1つの配列を優先度順にソートする (`key=*(u8*)(GetCommandEntryById+92)`, scratch=`ring+20592`);`7AEFC0`

 8回呼び出し（カテゴリごとに1回ずつ）し、リングをスロット順に並べ替える。名前を変更する`.i64`:`7AEFC0`→`FFX_Btl_UI_SortCommandRingSlot`,`7AD980`→`FFX_Btl_UI_SortCmdRingArrayByPrio` + ポインタセルへのコメント`0x2310CD8`. **DIAG (hudSafe=22):**`DumpKimahriRingState` したがって、のリードバックは`+0`/`+296` レアルで`G0-finalize` エンコードされたOD（0x311A）が正常に送信されるか確認するため。PolyHookビルド PASS（10/10）、デプロイは適用モード。RT2 **テストが必要**（バグ#1：中央のリングにODが表示されない）。ドキュメント：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §9. [前：`v2.123.1.2`]
- **`v2.123.1.2` — Spira Reforge: Capture Cascade の命名規則（内部コードネーム + プレイヤー向け名称）のデュアル仕様。** Lane **Jarvis-MAGIC**。 **REVISION**（設計/ドキュメント、コードなし）。Halysonが2026-06-16に確定：この機能は、異なる役割を持つ**2つの名前**を維持する。 **内部**（技術文書、変更履歴、スキーマフィールド、ID、プロンプト、レーン署名）では引き続き **Capture Cascade** （Cap-1/2/3、`dark_aeons.captured.<id>`,`capture_cascade.patrol_kills`,`arena.dark.<id>`). **プレイヤー向け**（ポップアップ、MODのREADME、MODページ）＝**スピラの軛**（PT）／ **Yoke of Spira** (EN) — イェヴォン／聖書（マタイによる福音書 11:30）を彷彿とさせる響きは、FFX オリジナル版の神権政治的なテーマを反映している。 **F7タブ「実績」** = **O Jugo** (PT) / **The Yoke** (EN)。 標準ポップアップ文字列が更新されました：PT「ベサイドはダーク・ヴァレフォールの**くびき**の下にある」／EN「Besaid is now under the **yoke** of Dark Valefor」；捕獲時のバトルテキスト PT「ダーク・ヴァレフォールは制圧された。 スピラが震えている。」／EN「Dark Valefor has been tamed. Spira trembles." Doc Capture Cascade に §0 が追加されました（命名規則テーブル + Microsoft Threshold/Redstone との類推に基づく）。VISION_AND_ROADMAP §11 に、相互リンク付きの 3 つのコンテキストのテーブルが追加されました。[以前：`v2.123.1.1`]
- **`v2.123.1.1` — Spira Reforge：Capture Cascade Phase B のハンドオフプロンプト（RE スパイク`capturable` bit）。** Lane **Jarvis-MAGIC**。**REVISION**（引き継ぎ文書、コードなし）。新規`docs/ai/PROMPT_JARVIS_CAPTURE_BIT_M_HEADER_RE_SPIKE_2026-06-16.md` — 「Capture Cascade」フェーズBの専用チャットを開くための完全なプロンプト。レーンのID：**Jarvis-CAPTURE-RE**。ミッション：オフセットとビットの位置を特定する`capturable` のヘッダーで`m###.bin` hex diff 経由（Sinscale ↔ Dark Valefor + 2 サンプル）

（検証用）＋オプションのIDA`CanCapture` クロスチェック。成果物：サンプル4件以上の表 + RESULTドキュメント + 計画書の更新 + Cap Cascadeマスタードキュメントの更新 + PORT_STATUS + 自身のREVISION番号の更新。 明示されていない要件（ライターを実装しない、ランタイムには触れない、ゲーム内でのキャプチャは行わない）。正直な見積もり：1.5～2時間。Cap-1（Phase C、v0.5）のロックを解除。[前回：`v2.123.1.0`]
- **`v2.123.1.0` — ロンソ・マナ：オーバードライブの再武装の修正（バグ #2）＋コマンドリングの2回目の修正。**レーン** ジャービス-MAGIC**。 **パッチ**（ランタイムフックの挙動に関するバグを修正 + RE/ドキュメント）。 **バグ #2（「Ronso Rage を使用後、左に移動しても解放されない」）：**`RonsoManaHook.cpp` ODの表示ゲートを`gateMin=100` (バニラ「フルバー」) 対 **40** (=`kRonsoSkillCosts[0]`（オーバードライブ・ジャンプのコスト）。ゲートを100に設定した場合、1回の部分使用後（ドレイン40 → チャージ60 < 100）、**すべての**フォーシング機能が`return` そして、ODは100まで補充されるまで消えてしまう――これは0～255の部分プールという仕様そのものと矛盾している。行ごとのグレーアウト（`G3`) は依然として高コストのスキル（コスト＞現在のチャージ量）をブロックし続けているため、ゲートを下げるのは安全だ。インストールバナーが修正された`hudSafe=19`→`hudSafe=21` （ログに誤ったバージョンが表示されており、診断の妨げになっていた）。**先週のRE（RT2の後）`hudSafe=20` FAIL）：** の完全な逆コンパイル`79BB70`/`79B500`/`7B6BD0`/`79AD40`/`7A07D0`/`797D60` + **オフライン**のダンプ`command.bin` 証明：(a) 実行時のコマンド行 = **0x14のヘッダー + ファイル構造体** (アンカー`byte[25]`=CharacterUser=file+5)、したがって`byte[22]`=MenuFlgs など； (b) **cmd282 (Ronso Rage) これはリングの OD ヘッダーである** (`MenuFlgs=0x11`→ヘッダー、`MainMenu=True`,`ODCat=19`,`MenuLeft`) — 以前の表記「282→cat4シート +296」は**誤り**でした； (c) のループ-2において`79BB70`, ヘッダーに`Misc2 MenuLeft (0x10)` →`dword[28]&0x1000` → BSS配列の**+40**の位置にあり、+0の位置（ヘッダーが表示される場所）ではない — そのため、282の表示を強制しても、その途中には表示されない；(d)`resolve=-1` これは**レッド・ヘリング**である（-1であってもメインリングは表示される）；（e）`797D60 case 3` **por-ator** の blob を読み込む (`actor+0xF7C`); (f)`79B500` する`actor[0x590]=save[+16]` **早朝** — 私たちの攻勢は`RefreshMenu_Shim` (トランポリンの前に準備する) は、この代入によって **上書き／消去** される → 例

save-editの複製に失敗した理由について。名前の変更`.i64`:`7B6BD0`→`FFX_Btl_UI_BuildOverdriveTargetList`,`79B500`→`FFX_Btl_RefreshActorMenuState` (+ コメントは`79BB70`/`797D60`/`79B500`). ドキュメント：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md` §8. 次のステップ（バグ #1）：正確なデルタを比較するために、「save-edited」と「forced」のキャプチャ実験。修正 #2 の RT2 **テストが必要**。[前：`v2.123.0.2`]
- **`v2.123.0.2` — Spira Reforge: Capture Cascade Phase A ロックダウン — 8つの決定事項確定 + 3つのアーティファクト準備完了** Lane **Jarvis-MAGIC**。 **改訂**（設計／ドキュメント／スキーマ、コードなし）。2026年6月16日のHalyson計画会議において、「Capture Cascade」ドキュメントの§7に記載されていた8つの未決定事項が確定した（`v2.122.0.1`): D1 マグス・シスターズ → **Mushroom Rock Road**（ガガゼットではない — ミイヘン作戦の歪んだノスタルジア＋3体の悲劇的なフェイス、序盤～中盤のコンテンツがT7エンドゲームへと変貌）； D2 ベストアイアリー F7 → **専用タブ + 戦闘後のポップアップ**、捕獲した**DAが生成したアート（GPT画像）**用のスロット付き； D3 **逃れられない**パトロール； D4 ドロップ = **1×シャード + 1×レア消費アイテム**； D5 捕獲は**キル++としてカウント**（1v1バニラおよびSINラダーを解放）； D6 **確認プロンプトなし**；D7 セーフゾーン **T7のモブおよびDAパトロールによって尊重される**；D8 バフの告知は **捕獲後の最初の入場時のみ**。 フェーズAでは3つのアーティファクトを入手：(a) **サイドカーの設計図**`mods/Spira Reforge/save-schemas/spira-reforge-flags.schema.json` v1 (DAキャプチャ +`sin_mode.region_overrides` +`conquistas_seen` +`capture_cascade.patrol_kills`/`first_entry_seen` — **サイドカーとの干渉を解消**`spira-arena-progress.json` ジャービス・アリーナ`v2.123.0.0` （アリーナ・ロウ・クリアを維持するもの）；（b）**リージョンマップ**`mods/Spira Reforge/arena/dark-aeon-region-map.json` (8 DA → カノニカルエリア + patrol_subzones + safe_zones + narrative notes); (c) **RE スパイク計画 フェーズ B**`docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_PLAN_2026-06-16.md` （ビットの位置を特定するための手順：所要時間1～2時間）`capturable` で`m###` ヘッダー（hex diff 経由 + オプションで IDA）。Cap Cascade マスタードキュメントを更新：§7（ロックダウン）+ §4（最終マップ）+ §13（アーティファクトのリファレンス）。 VISION_AND_ROADMAP §11に「Phase Aのアーティファクト」ブロックが追加されました。4段階の計画が定義されました（A=ロックダウン完了、B=REスパイクチャットを別途実施、C=Cap-1ライターv0.5

, D=RT2 パイロット）。[前：`v2.123.0.1`]
- **`v2.123.0.1` — Arena+ Multi Dark Aeon: ペンタ・ストレッチ・レシピ + ドライラン PASS。** レーン **Jarvis-ARENA**。 **REVISION** (レシピ/ドキュメント、出荷時の動作に変更なし)。計画のフェーズ7 (ストレッチ)。新規`RuntimeTools/ArenaMultiBossLab/recipes/dark_penta_elemental_five.json` + レシピ文書`mods/Spira Reforge/arena/recipes/dark_penta_elemental_five.md` 覆いながら`Dark Valefor + Dark Ifrit + Dark Ixion + Dark Shiva + Dark Bahamut` で`nagi05_70` （別名：Dark Yojimbo、vanillaのmonPos 6つのうち5つ、スロット5にアクターなし）。パイプライン`ArenaMultiBossLab --recipe dark_penta_elemental_five --dry-run` PASS対`nagi05_70.bin.spiraforge.bak`: chunk2 = 5 actors @ 0x18A4 (16 バイト)、chunk3 = 6 monLive @ 0x1B04 (96 バイト、位置情報のみ)、再読み込みによりスロットが確認される。カタログ行`dark-penta-elemental-five` 更新：IDを改名、`token_mode` `blocked->alias` （別名、そして技術的には正当な）、`evidence` dry-run PASS を使用して、`rt2_status` 残る`blocked` （ゲーム内での検証なし）— RT0のバイトセーフティのみが証明されている。**機能として採用されない**：RT2 PASSのクワルテットが達成されるまで継続し、ゲーム内での試行が以下のように記録されている`_RT2_CHECKLIST.md`. MDレシピにおける4つのケース（PASS / カメラによる遮断 / AIによる遮断 / クラッシュによる遮断）を含むプロモーション計画。[前：`v2.123.0.0`]
- **`v2.123.0.0` — Arena+ Multi Dark Aeonの進行状況：FfxHooksDll内のサイドカー + リーダー/ライター。**レーン**Jarvis-ARENA**。**マイナー**：(a) 新しいサイドカー`mods/Spira Reforge/arena/progress/spira-arena-progress.{json,schema.json}` （第15節の書類のスキーマv1）と`flags{}` cleared/first_clear_utc/last_clear_utc/clear_count/evidence +`tier_lock_state{}` オプション（LOCKED/READY/CLEARED）；キーによる`progress_flag` カタログより (`arena.dark.<slug>`); 利用規則およびcatalog<->sidecarのマッピングを記載したREADME。(b) 新しいモジュール`RuntimeTools/FfxHooksDll/hooks/ArenaProgressSidecar.{h,cpp}` — ベストエフォート型のJSON読み書き機能（依存関係なし）、`ArenaProgress_Initialize/IsRowCleared/RecordCleared` gated by`arena_plus_progress.flag` (デフォルトはオフ)、検索対象`$FFXHOOKS_ARENAPLUS_PROGRESS_PATH` ->`<DllDir>/mods/Spira Reforge/arena/progress/...` -> フォールバック`<DllDir>/spira-arena-progress.json`. `.tmp` によるアトミックな永続化

+ MoveFileEx`. Env `FFXHOOKS_ARENAPLUS_FAKE_CLEAR=flag1,flag2` permite seed manual para teste de UI. (c) `dllmain.cpp` chama `ArenaProgress_Initialize` no `InstallHooks` apos catalog overlay. (d) **Victory detection real ainda nao plugada** — fica como TODO documentado; a Fase 6 do plano admite essa separacao e a API publica `ArenaProgress_RecordCleared(flag, note)` ja esta pronta para receber o consumer quando o hook `battleEnd` existir. Build PolyHook PASS 10/10 cpp. RT2 in-game **Precisa Testar** (via `FFXHOOKS_ARENAPLUS_FAKE_CLEAR`). [anterior: `v2.122.0.1`]
- **`v2.122.0.1` — Spira Reforge: Capture Cascade — ダーク・イオーンを捕獲すると、その地域が覚醒する（設計文書＋ロードマップ）。** Lane **Jarvis-MAGIC**。**REVISION**（設計／文書、コードなし）。 Halysonによるアイデア 2026-06-16：DAを倒すだけで、Arena+ F7でDAが解放される；**キャプチャー**武器（vanilla）でDAを**キャプチャー**（flag66 bit Capture）し、とどめを刺すと、DAの正史上の地域が覚醒する。 確定した決定事項：トリガー＝標準のキャプチャー、遭遇頻度＝チャイム付きで稀（約5～10％）、可逆性＝セーブ時の片方向；ベストアイアリー「実績」F7、高ティアのドロップ、逃走不可、標準ベストアイアリーのMAには加算されない。 **Cap-1**への分解（ポップアップ + サイドカーフラグ + ラダー SIN · DARK AEONS 経由`unlock_requires: ["dark_aeon.captured.<id>"]` — すでにリリース済みのカタログv2に適合しています`v2.122.0.0`; v0.5)、**第2章** (`sin_tier_override=7` SINランタイムモードのカノニカル・ピギーバック領域；v0.6）、**Cap-3**（DAパトロール`m###` T7のモンスター1～3体を含むカスタム編成ではHPが約30～40％減少（エンカウンターエディタREに依存；v0.7+）。マップDA→標準エリア（8つの入口）＋軽減効果のある7つの障害＋各層につき最低RT2。ドキュメント：`docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_CASCADE_RESEARCH_2026-06-16.md`; ロードマップ §11 + §6 v0.5/v0.6/v0.7 における`mods/Spira Reforge/VISION_AND_ROADMAP.md`. [前へ：`v2.122.0.0`]
- **`v2.122.0.0` — Arena+ Multi Dark Aeon カタログ v2 + DLL リーダー + カスタムトークンリゾルバー spike.** Lane **Jarvis-ARENA**. **MINOR**: (a)`mods/Spira Reforge/arena/spira-arena-catalog.schema.json` v1からv2へと進化し、`token_mode`/`base_template`/`raw_monster_ids`/`unlock_requires`/`rt2_status`/`risk`/`recipe` 行ごと； (b)`spira-arena-catalog.json` 5つのティアで構成されています（ソロ9 ヴァニラ + デュオ + トリオ + カルテット +

 ペンタ・ストレッチ）；（c）`FfxHooksDll/dllmain.cpp` 獲得した`ArenaPlus_LoadCatalogOverlay()` +`ArenaPlus_GetRoute(int)` accessor: いつ`arena_plus_catalog.flag` アクティブ + JSON が見つかりました、スロットごとのオーバーライド`battleToken`/`battleId`/label (フォールバックとしてハードコーディングされた`kArenaPlusBossRoutes[9]` （常に失敗時に勝利する）；（d）新しいフック`RuntimeTools/FfxHooksDll/hooks/ResolverLogHook.{h,cpp}` — 読み取り専用のPolyHookデトールは`FFX_Field_ResolveEncounterToken@0x7828B0` （token、result、outField、outGroup、outEntry）が、以下の条件によって制限される`arena_plus_resolver_log.flag`; (e) RE doc`docs/reverse/FFX_ARENA_PLUS_CUSTOM_TOKEN_RESOLVER_HOOK_SPIKE.md` 注釈付きデコンパイル（HIWORD = フィールドキー、下位バイトのLOWORD = エントリキー、中間バイト = 0）、4つの呼び出し元、テーブルのレイアウト`g_EncounterFieldTable@0x112A9C8` +`g_EncounterGroupBlobBase@0x112A9CC`, 仕様範囲のカスタムトークン`0xA001..0xAFFF`, プラン「オプションA」（リダイレクトの事前解決）； (f) 適用されたリネームおよびコメント`.i64` 実（`work/reverse/ida/FFX_recon.i64`) — sub_79D1B0/D1E0/D190/D230 が変更された`FFX_Field_*EncounterField*/Group*` （黄金律）。PolyHook PASS 9/9 cppをビルド。[前回：`v2.121.0.1`]
- **`v2.121.0.1` — Ronso Mana：コマンドリングのパイプラインのREを修正（hudSafe 17/19が失敗した理由）。** Lane **Jarvis-MAGIC**。 **REVISION**（RE/doc、動作変更なし）。リングのIDA再解析：**表示されている** Attack/Skill/Special リングは`FFX_Btl_UI_BuildMainCommandRingTree@0x7A07D0` (treeId=`slot+109`、ただ`kind<=8`), ではなく`treeId=slot+41` — だから`resolve(2,1,43)→-1` それでもリングは現れた。**Overdrive**リングは`kind=12` (>8)の場合、`7A07D0` そして、それは100％～に依存する`resolve(2,1,slot+41)`, これはblobが`unk_112A9B4` ある`blob[2+treeId]==0xFF`. **`blob[2+treeId]` これはノード定義のインデックスであり、ブール値**ではありません → パッチの`hudSafe=19` 数値は合っていたが、その値の意味を誤解していた。バグ「Ronso Rageが解放されない」：gate`79AF70` 要求する`charge>=100`; ドレイン（100→60）の後、ODが消える → 最適な選択肢は、スキルコストを最小限に抑えるためにゲートを下げる（~40）こと。リネーム`.i64`:`7A07D0`/`79AF00`(IsAeonMenuSlot 20-27)/`7986B0`/`783ED0` + コメント（blobの形式は`797420`, 配列`X` シェアされた日時：`7985A0` xref経由`0x798672`, drサイト

ain/transfer`0x78F1E5`). ドキュメント：`docs/reverse/FFX_RONSO_MANA_COMMAND_RING_PIPELINE_RE_2026-06-16.md`. （注：`hudSafe=20` — ODリングヘッダーのスキャン + ヘッダー配列への書き込み — 引き続き**デプロイ済み、テストが必要**。） [前へ：`v2.121.0.0`]
- **`v2.121.0.0` — Arena+ Multi Dark Aeon オーサリングレーン（ArenaMultiBossLab + マルチエイリアスレシピ）。** レーン **Jarvis-ARENA**。 **MINOR**：新しいCLI`RuntimeTools/ArenaMultiBossLab` JSONレシピを決定論的に適用する —`chunk2` 経由`FormationSlotWriter` (スロット専用 RT0) +`chunk3` 経由`BattleArenaPositionWriter` (位置指定のみ RT0) または`BattleArenaGrowWriter` (monLive grow cap 8 actors)、リリードガードおよびルーズファイルのデプロイ付き`.spiraforge.bak`. アクティブなレシピ：`dark_duo_valefor_ifrit` (別名`kino00_70`/token`0x00DC0046`). レシピドキュメント + RT2テンプレートのチェックリスト + マルチエイリアスのREADMEが`mods/Spira Reforge/arena/recipes/`. 戦略：B（マルチエイリアス）＋C（REフックの並列解決）＋コンテンツファースト（カタログv2/DLLリーダーの前にデュオ→トリオ→カルテット）。基本資料：`docs/reverse/FFX_ARENA_PLUS_MULTI_DARK_AEON_AUTHORING_DOSSIER_2026-06-16.md`. 計画：`.cursor/plans/arena_plus_multi_dark_aeon_*.plan.md`. オフラインで生成されたDuo deploy RT0 PASS（7780バイト、chunk2の16バイトおよびchunk3の48バイトを除く部分はバイト単位で同一、monLive）； **RT2 ゲーム内 テストが必要** 以下の条件で`_RT2_CHECKLIST.md`. [前へ：`v2.120.7.0`]
- **`v2.120.7.0` — Ronso Mana hudSafe=19: レイヤー B UI ツリー (797B80/797D60)。** レーン **Jarvis-MAGIC**。**PATCH**: 迂回`FFX_Btl_UI_PushMenuTreeEntry` +`FFX_Btl_UI_ResolveMenuTreeNode`; ダイレクトインジェクション`Push(2,1,treeId,1+12)` +`Resolve` +`7979E0` で`G0-finalize`; log blob ケース4`0xD35DF0` + スタックの深さ;`ForceKimahri` shim経由。RT2 **テストが必要**。[前へ：`v2.120.6.0`]
- **`v2.120.6.0` — オリジナルのFSBを修正（seIdの低バイト、IDAで確認済み）。** Lane **Jarvis-MAGIC**。**PATCH**:`FFX_FmodSfx_ResolveSequence@0x70FB60` →`sub_710370` 切り詰め`seId` ～へ`u8` でのルックアップの前に`9999_common.txt` (例：`9066`→key`106`→FSB`#9`, いいえ`#85`); フォールバック`seId-9000` 最下位バイトが存在しない場合のみ；UIはSeSepのライブデータを`magic_####.dll`; バンドルされたマップを再生成しました (824/1165)。[前回：`v2.120.5.1`]
- **`v2.120.5.1` — Ronso Mana hudSafe=17: ho

OK P0`792AB0` (ミドルリング OD)。**レーン** ジャービス-MAGIC**。**PATCH**：迂回路`FFX_Btl_BattleMenuInputDispatch` — クリア`+0xDF7`,`+0x590|=0x0C`, force`7ACEC0(1+12)` スタックした場合、すべてをログに記録する`ringKind`; デプロイラボ`-EnableApply`. RT2 **テストが必要**. [前へ：`v2.120.5.0`]
- **`v2.120.5.0` — オリジナルのPlayのFSBが間違っている（seId−9000、magicIdではない）。** Lane **Jarvis-MAGIC**。**PATCH**: FEVイベントキーのマップ`seId-9000` →`9999_common.txt` → FSBサブソング；ヒューリスティックを削除`magicId` （「SIMが撃たれた」のようなランダムな音が鳴っていた）；◀▶ボタンでサブソングを閲覧；バンドルされたマップが再生成された。[前回：`v2.120.4.0`]
- **`v2.120.3.0` — Battle Audio Toolsエディタの完全な統合。** Lane **Jarvis-MAGIC**。**PATCH**：ヘルスプローブ + **Verify Audio Tools** UI；`FfxFsbBankCl_Service` fsbankexcl 経由で実数値を追加；fsbankexcl バンドルをインポート；gate`--audio-tools-health`; CWD/DLL対応のCLI。[前:`v2.120.2.0`]
- **`v2.120.2.0` — fsbankcl バンドル版 (FMOD FSBankEx 4.44.64)。** Lane **Jarvis-MAGIC**。**PATCH**:`tools/fsbankcl/` com`fsbankexcl`+DLL；別名`fsbankcl.exe`; locator が受け入れられる`fsbankexcl.exe`. [前へ：`v2.120.1.0`]
- **`v2.120.1.0` — fsbankcl バンドルパス（インポート + SDK 検出）。** Lane **Jarvis-MAGIC**。**PATCH**:`tools/fsbankcl/` no build; UI **fsbankclのインポート** / **fsbankclの検出 (FMOD SDK)**; ブートストラップ`-InstallFsbankCl`; locator SDK スキャン。バイナリは自動ダウンロードされません — FMOD インストール後に 1 回インポートしてください。[前回：`v2.120.0.0`]
- **`v2.120.0.0` — バトルSFXオーディオツールが同梱・バージョン別。** Lane **Jarvis-MAGIC**。 **MINOR**:`vgmstream` +`fsbext` で`tools/` Git上で；の横にコピーされた`.exe` ビルドには含まない；UIの**オーディオツールの修復**は、不足している場合のみ表示する；`tools/AUDIO_TOOLS_LICENSES.md`. [前へ：`v2.119.0.0`]
- **`v2.119.0.0` — カスタムバトルSFX フェーズ2：上書きなしの新しいseId。**レーン**Jarvis-MAGIC**。**MINOR**：`FsbDumpDatAppender` +`Fsb9999SampleAppendWriter` (FSB subsong +1 via dump.dat);`FevLegacySequenceWriter` + サイドカー`9999_common.txt` row;`CommandSoundPackService.NewSeIdAudio` FEV+FSB+common+DLLのトリプルデプロイ；UIカーネルコマンド **新しいseIdスロット**；ゲート`--fsb9999-append-lab`,`--fev9999-sequence-clone-wave9`,`--command-sound-new-seid-pack`; I36 RE doc;`work/.../wav/` レイアウト

+`cleanup_fsb_audio_scratch.ps1`. RT2 ゲーム内 **保留中**。[前回：`v2.118.0.0`]
- **`v2.118.0.0` — Nul Ward マスタープラン（エポック 1～7 のラボスタック）。** Lane **Jarvis-MAGIC**。**MINOR**：ネイティブスロット`+0x613/+0x614`, P16 プレチェック・デトール,`NulWardTeachHook` (I20 メニューバインド)、RT2 判定パーサー、ATEL 行差分、`NulWardLab` gate; ドキュメント R01/P14/RT2 マトリックス。RT2 ゲーム内 **保留中**。[前回：`v2.117.0.2`]
- **`v2.117.0.2` — ロンソ・メニュー RE: AbilityCommandLab`--dump-cmds`.** Lane **Jarvis-MAGIC**. **PATCH**: 行ダンプ用のオフラインCLI`command.bin` (ODCat、CostOD、メニューフラグ); カタログ「inferno」を補完する (`8f6ac031`,`v2.116.0.3`). 次のROIフック：`792AB0`. [前へ：`v2.117.0.1`]
- **`v2.117.0.1` — Flan Flood LAB + MagicDllRt2VerdictCatalog（実装未完了）。** Lane **Jarvis-MAGIC**。 **PATCH**：納品`--flameflan-flood-pack` /`--flameflan-flood-recolor`,`MagicDllRt2VerdictCatalog`,`MonsterMagicGrowWriter` 行 #249`0x60F9`, ファイア・マグマ／コーラル,`FlanFloodDllPossibleTimingPatch`; ドキュメント：ledger RT2（32回の試行）、タイミング：Family D、プレイブック：Flan Flood。すでに以下で言及されているゲート／UIを完了する`v2.114`–`v2.117`. [前へ：`v2.117.0.0`]
- **`v2.116.0.3` — ロンソ・メニュー・インフェルノ RE + AbilityCommandLab`--dump-cmds`.** Lane **Jarvis-MAGIC**. **PATCH**: カタログ`FFX_RONSO_MANA_MENU_DISPLAY_INFERNO` +`FFX_RONSO_MANA_KNOWN_VS_NEW` (レイヤーA/B、バグ`+0xDF7`, ビット`79AEE0`,`command.bin` ODCat 19/35）；CLI`--dump-cmds` 行のオフラインダンプ用`command.bin`; ドリフトの注記`Camera_*` vs メニュー UI。次の ROI フック：`792AB0`. [前へ：`v2.116.0.2`]
- **`v2.116.0.2` — セマンティック・ドリフト 第2段階：PARTIALの適用 +`ffx_addresses.h`.** Lane **Jarvis-MAGIC**. **PATCH**: IDAの名称変更を4件追加 (`7985A0/797420` UIのblob、`794030` GetActorRecord,`78C330` precheck_structural); Ronso/UIのRVAメニューにある`ffx_addresses.h`; W2S`593440/5936A0` ドキュメントがロックされています。合計 **12/12** の名前変更ドリフトが`.i64`. [前へ：`v2.116.0.1`]
- **`v2.116.0.1` — IDA + BIBLE fix.** Lane **Jarvis-MAGIC** に適用された Semantic Drift Audit S01–S12。**REVISION**: パッケージ`FFX_RE_SEMANTIC_DRIFT_AUDIT` (12/12、67文字); **8件の名称変更**が`FFX_recon.i64` (UIメニュー`797B80/797D60`,`7B2DD0` aggregate, `78

28B0` token, `g_BattlePlayerList`); `AiBibleCatalog` separa `7078` vs `0x7B2DD0`. [anterior: `v2.116.0.0`]
- **`v2.116.0.0` — 能力SFXティア1：パック展開 + UI編集可能 + FEVウェーブ7。**レーン**Jarvis-MAGIC**。**マイナー**：`CommandSoundPackService` +`--command-sound-pack` (stage/deploy/restore、RT2 Fire→Firaga デモ); カーネルコマンド **バトルSFX** 編集可能 (ドナーピッカー、プレビュー/stage/deploy/restore);`MagicDllSoundWriter` バックアップ／ドナーパッチ；Magic DLL Browserの**Sound (SeSep)**タブ；`--fev9999-corpus-wave7`;`--command-sound-custom-wizard`; I31 IDAの名称変更を適用済み; I33 FEVのRT2ドキュメント（ゲーム内）**未完了**。[前回：`v2.115.0.1`]
- **`v2.115.0.1` — Magic DLLs：blue vec4 = タイミングリスク（RT2 Flan Flood 0718 確認済み）。** Lane **Jarvis-MAGIC**。**PATCH**：`Extras → Magic DLLs (FFX)` Value Workbenchは、青が優勢なvec3/vec4を次のように分類します。`possible timing (cast→hit)` バッジ付き`timing-risk` およびFamily C/Dに関する通知；Wave4編集ガイダンスの整合；ドキュメント`FFX_FLAN_FLOOD_DLL_TIMING_RT2_FAIL`,`FFX_MAGIC_DLL_POSSIBLE_TIMING_VEC4_FAMILY_D`. ビジュアルカラー = phyre PS3、ヒューリスティックDLLパッチなし。[前回：`v2.115.0.0`]
- **`v2.115.0.0` — Ability SFX inferno: FMODパイプライン + wave6コーパス + hook lab + Commands UI。** Lane **Jarvis-MAGIC**。**MINOR**: I31/I32 RE (`FFX_ABILITY_SFX_FMOD_STREAMING_INFERNO`,`FFX_MAGIC_DLL_ABILITY_SFX_CORPUS_INFERNO`);`--magicdll-sound-corpus-wave6` (587個のDLL、510個のSeSep);`MagicDllSoundWriter` +`--command-sound-rt0`;`AbilitySfxHook` 読み取り専用ラボ；カーネルコマンド **バトルSFX** 読み取り専用パネル；`AbilitySfxLab` 判定。RT2 ゲーム内 **保留中**。[前回：`v2.114.0.3`]
- **`v2.114.0.3` — Spira Reforge: Possessed by ?????????? (Sin-infected opener)。**レーン**Jarvis-HD**。**改訂**：ネタバレなしのバニラ版クローン；スキル限定のカペトン式パッケージ。[以前：`v2.114.0.2`]
- **`v2.114.0.2` — Spira Reforge：スキルの色変更 ≠ モンスターモデル。** レーン **Jarvis-HD**。**修正**：VFXのみであることを明確化；モンスターモデル＝バックログ。[以前：`v2.114.0.1`]
- **`v2.114.0.1` — 『Spira Reforge：シンに感染したモンスターのスキルに関するドキュメント』** Lane **Jarvis-HD**。**改訂**：`SIN_INFECTED_MONSTER_SKILLS.md` — 新しいmonmagic + リカラー；POC Flan Flood オレンジ色；Sinのスキル列。[

前へ：`v2.114.0.0`]
- **`v2.114.0.0` — フラン・フラッド：ウォーターガ・クローン LAB（フレイムフラン・マグマ）。** レーン **ジャービス-MAGIC**。 **MINOR**：`--flameflan-flood-pack` /`--flameflan-flood-recolor` — 行番号 #249`0x60F9`, クローン`magic_0718/0719` から`0096/0097`, phyre magma/coral、**FFX.exeパッチなし**；UI Monster Commands 2 のインストール／展開。[前：`v2.113.0.3`]
- **`v2.113.0.3` — INFERNOの配信 + IDAによる意味的なリネーム + BIBLEの更新。** Lane **Jarvis-MAGIC**。**REVISION**: パッケージ`FFX_RE_DEEP_INFERNO_DELIVERY_BUNDLE`; 45件のセマンティックなリネームが`FFX_recon.i64` (160個のプレースホルダー`FFX_I##_` （無視されたもの）；`AiBibleCatalog` +`btlGetCalcResult`/`readMovePropertyForActor`; 監査プロンプト ドリフト`FFX_RE_SEMANTIC_DRIFT_AUDIT`. rename によって **ブロックされない** Hooks/editor。[以前：`v2.113.0.2`]
- **`v2.113.0.2` — ヌル・ワード24計画統合マトリックス（ATEL 56/57）。**レーン**・ジャービス-MAGIC**。**改訂**：`FFX_NUL_WARD_INTEGRATION_MATRIX` — IDAのスロット試験`+0x613/+0x614` (オペコード 56/57)、VALIDATED/CUT ステータスを持つ 24 の armar/consume/UI ルート。[前：`v2.113.0.1`]
- **`v2.113.0.1` — ヌル・ワード 12 プラン RE（RT2 以前）（IDA デコンパイル）。** レーン **ジャービス-MAGIC**。 **改訂**：`FFX_NUL_WARD_RESEARCH_PLANS` — 12の計画には、実証済みの基盤が含まれている（`sub_7B2DD0` メーター`+0x60E`, teach id≥96 party bank, Scan`0x3032`, フェーズBのライトバック）。[前へ：`v2.113.0.0`]
- **`v2.113.0.0` — Nul Wardのオフラインプリフライト + フックの修正 + カーネルUI。** Lane **Jarvis-MAGIC**。 **MINOR**:`--nul-ward-static` FFX.exe（PE RVA）、command.bin 320/321、DLL/フラグを検証；IDAはaction+0x08の位置にエンコードされたcmdを検出；`NulWardHook` 修正済み；hook-aware パック（Tide/Shock inflict なし）；Kernel ID 320/321 のパネル；`preflight.ps1`. [前へ：`v2.112.0.25`]
- **`v2.112.0.25` — Ronso Mana hudSafe=16: デプロイの修正 + フック`7ACEC0`.** Lane **Jarvis-MAGIC**. **PATCH**:`install_to_modules.ps1` バンドル内の古いDLLをコピーしていた；フック`3ACEC0` força ring kind=12; 維持`79AF70`. RT2 保留中。[前回：`v2.112.0.24`]
- **`v2.112.0.24` — ロンソ・マナ hudSafe=15：ミドルリングのゲート`79AF70`.** Lane **Jarvis-MAGIC**. **PATCH**: hook`39AF70` +`actor+0x590|=4` + word`+0x6C8=0` Kimahriの負荷が100以上の場合；hudSafe=14のテンプレートを維持。RT2は保留中。[以前：`v2.112.0

.23`]
- **`v2.112.0.23` — RE Deep INFERNO GPTプロンプト（I01–I20 悪魔のマラソン）。**レーン**Jarvis-MAGIC**。**REVISION**：`FFX_RE_DEEP_INFERNO_PROMPT_GPT55` — ATEL VM、ダメージパイプライン、AIリロード、31個のハードコーディングされたAA、エンカウンターFSM、Magic VM、メニュー／AbiMap；ボーナスI21～I30。[前回：`v2.112.0.22`]
- **`v2.112.0.22` — RE Deep Wave 3 GPTプロンプト（R01–R04 IDAマラソン）。**
- **`v2.112.0.21` — Ronso Mana hudSafe=14: テンプレート 7AEFC0 + menuCtx.**
- **`v2.112.0.20` — Spira Reforge 運用チートシート（Halyson 1ページ）。** Lane **Jarvis-HD**。 **改訂**：`docs/ai/FFX_SPIRA_REFORGE_HALYSON_CHEATSHEET_2026-06-15.md` — RT2 v0.2 キュー、MEGA/MODS インデックスリンク、Auto-Abilities セクション（#114–#134、#24 Break、CLI ゲート）。[前へ：`v2.112.0.19`]
- **`v2.112.0.19` — MODSマラソン M01–M30 完了：ドキュメント29件 + 目次 + Spira Reforgeによる監査。** Lane **Jarvis-MODS-MEGA**。 **REVISION**：`FFX_MODS_MEGA_RESEARCH_INDEX` + M01–M29（操作概要：約37～142行/ドキュメント）；Spira Patch/Arena/SIN/QH/Darkのブロックは維持；RT2トップ #134/id129/Break Limits。研究専用。[前回：`v2.112.0.18`]
- **`v2.112.0.18` — Ronso Mana hudSafe=10: プール 255、ODは100以上のみ。** レーン **Jarvis-MAGIC**。 **PATCH**:`gateMin=101` デフォルト；最大255、永続的；スキルごとのグレーアウトにより、コストは40～255の範囲に維持される。RT2は保留中。[前回：`v2.112.0.17`]
- **`v2.112.0.17` — Ronso Mana hudSafe=9: プール最大255に対するスプーフィングを修正。** Lane **Jarvis-MAGIC**。**PATCH**: 引退`BeginKimahriMaxSpoof` (解きほぐしていた`max=255` （ビルド内）；drain は`ApplyKimahriRuntimePoolMax`; log`G0 poolMax`. RT2 保留中。[前回：`v2.112.0.16`]
- **`v2.112.0.16` — Ronso Mana hudSafe=8：パリティセーブ（最大値=255）＋ネイティブメニュー。** Lane **Jarvis-MAGIC**。**PATCH**：RVAレイアウトを修正`01F0FCD8`;`actor+0x5BD=255` キマハリ限定；注入`0x311A` で`+0x71A`/`+0x6CB`; hook`7850E0` save-bank cmd 282; G2 drain および G0'/G1'/G3' を維持。RT2 は保留中。[前:`v2.112.0.15`]
- **`v2.112.0.15` — MODS MGによるGPT 5.5の調査：Spira Reforge M01–M30。** Lane **Jarvis-HD**。**REVISION**：プロンプト`FFX_MODS_MEGA_RESEARCH_PROMPT` (Spira Patch、Arena+、SINモード、パーティーメタ、Forbidden Rite、IDEAs);`KNOWLEDGE_BASE` +`mods/README`. RT2なし。[前：`v2.112.0.14`]
- *

*`v2.112.0.14` — Ronso Mana hudSafe=6: メインメニュー（Attack/Skill/Special）のオーバードライブ。** Lane **Jarvis-MAGIC**。**PATCH**: G0' @`39AD40` (`HasCommandBit` cmd 282 キマハリ + 部分積載）；G0 ビット 282 の前／後`79BB70`/`79B500`; ドレイン後のビット再接続。RT2が保留中。[前回：`v2.112.0.13`]
- **`v2.112.0.13` — Ronso Mana hudSafe=5: 部分読み込みでODサブメニューを再表示。** Lane **Jarvis-MAGIC**。 **PATCH**:`RonsoManaHook` — G1' @`392170` (ODの破断強度) +`49BA80` (open spoof) + G0 リフレッシュ`39B500` + bit cmd 282 @`39C090`; 固定`IsKimahriActorPtr` ただ`Id==2`; G2ドレイン + G3' グレーアウトを維持; HUD/GetMaxの迂回なし。RT2は保留中。[前回:`v2.112.0.12`]
- **`v2.112.0.12` — MEGA deep follow-up D01–D07 が完了（IDA + コーパス + ブロック）。** Lane **Jarvis-MEGA-DEEP**。**REVISION**: 7 ドキュメント分（約260～390行） +`FFX_MEGA_RESEARCH_DEEP_INDEX`; exports IDA`work/reverse/ida/exports/mega_deep/` 参照されたもの；W2S オーナー／キャップスポーン／バリアントセレクター／ハンドラー`0x707A` ブロック済み；chunk3、stride`0xF90`, FSMカメラ、Y著の検証済み。研究用のみ。[前：`v2.112.0.11`]
- **`v2.112.0.11` — Ronso Mana hudSafe=4: G0 メニュー + G3' リフレッシュ + G2 ドレイン。** レーン **Jarvis-MAGIC**。**PATCH**:`RonsoManaHook` — G0 @`39BB70` (キマハリの気温`max=charge`), G3' @`492040` （グレーアウトされた行）、回り道なし`897F80`/GetMax. [前へ:`v2.112.0.10`]
- **`v2.112.0.3` — Spira Reforge：完全版 + アリーナ F7（NPC wontfix）。** レーン **Jarvis-HD**。 **改訂**：`mods/Spira Reforge/VISION_AND_ROADMAP.md` — アンチメタ「Ribbon/Celestial」、ロードマップ v0.2–v0.5、ラダー「Dark Aeons」＋SINバリエーション、アリーナ・スキーマのカタログ、F7キーのみの決定メニュー。[前回：`v2.112.0.2`]
- **`v2.112.0.2` — Spira パッチ形式仕様（一括エクスポート／インポート草案）。** Lane **Jarvis-HD**。**改訂版**：`docs/specs/SPIRA_PATCH_FORMAT_2026-06-15.md` — モンスター、戦利品、自動スキル用のJSON/CSVスキーマ、および`arms_rate`; 例は`mods/Spira Reforge/patches/`. エディタへの実装はまだ行われていません。[前：`v2.112.0.1`]
- **`v2.112.0.1` — Ronsoのフラグコメント + バージョン管理 MonEditor Modelsのエントリを修正。** Lane **Jarvis-MAGIC**。**PATCH**:`kimahri_ronso_mana.flag` log/apply コマンドの説明。[前へ：`v2.112.0.0`]
- **`v2.112.0.0` 

— MonEditor：バトルモデルカタログ（FFXmon）＋プレビュー Model1/Model2。** Lane **Jarvis-MAGIC**。**MINOR**：取り込み`battle-model-catalog.json`; 名前が表示されるピッカー; ブリッジ`BattleModelCatalogBridge` → モデルビューア (`m###`/`c###`/`s###`); プレビュー dual id1+id2; ボタン MAIN MODEL pair. Doc`FFX_BATTLE_MODEL_CATALOG_MONEDITOR`. [前へ：`v2.111.0.0`]
- **`v2.111.0.0` — Ronso Mana hook wired (`FfxHooksDll` キマハリ（OD LABの一部）。**レーン** ジャービス-MAGIC**。**MINOR**：`RonsoManaHook` G1ゲート + G3グレイアウト (PolyHook) + G2ドレイン @ PE`0x38F1E5`; フラグ`kimahri_ronso_mana.flag` /`kimahri_ronso_mana_apply.flag`; デプロイラボ`ronso-mana-lab-v2.111.0.0`. RT2 ゲームプレイの一部（ドレインPASS）。[前：`v2.110.1.2`]
- **`v2.110.1.2` — MEGAリサーチマラソン：Auroraのドキュメント23件＋監査＋詳細なフォローアップ（D01～D07）。** Lane **Jarvis-MAGIC**。**REVISION**：目次`FFX_MEGA_RESEARCH_INDEX` + A01–A15/C01–C08;`FFX_MEGA_RESEARCH_AUDIT` （要約 vs 実証）；プロンプト`FFX_MEGA_RESEARCH_DEEP_FOLLOWUP` IDAの2回目のマラソンに向けて；`PORT_STATUS` gates 21→29 を照合済み。RT2 なし。[前回：`v2.110.1.1`]
- **`v2.110.1.1` — NovaClamp: ゲート・クローバーリングによるEFLAGSの改ざん（グローバルバイパス）。** Lane **Jarvis-MAGIC**。**PATCH**: スタブが再実行されていた`cmp eax,ebx` バニラ・ルート —`jle` ～のフラグを使用していた`cmp [ebp+0x1C]` (ほぼすべてのcmd &lt;`0x3073` clampをスキップ); deploy`ffx-hooks.dll`. RT2：ティダスの再認定 ≤99k + ノヴァ &gt;99k。[前回：`v2.110.1.0`]
- **`v2.110.1.0` — Event JPのリード + PPPDRAWの廃止 + NovaClampのスタブ修正。** Lane **Jarvis-MAGIC**。**PATCH**:`--event-rt0` JP回帰`0x06`/`0x26..0x2F` (`13/13`);`FFXPROBE_PPPDRAW_RETIRED` no probe/lab; ログ記録前の新しいスタブ書き込み。[以前:`v2.110.0.3`]
- **`v2.110.0.3` — 研究 H01–H15：ヘビー・パッケージ + インデックス + ロンソ・マナ。** レーン **Jarvis-HEAVY** + **Jarvis-MAGIC**。**改訂**：16 件のドキュメント (`FFX_RESEARCH_CHAT_GENERATED_FILES` + H01–H15);`KNOWLEDGE_BASE` ONDA H；Ronso G1/G3 IDA。RT2なし。[前：`v2.110.0.2`]
- **`v2.110.0.2` — RE: IDA flat 対 PE RVA（バトルセクション）`+0x400000`).** Lane **Jarvis-MAGIC**. **REVISION**: doc`FFX_IDA_FLAT_VS_PE_RVA_BATTLE_SECTION_2026-06-15.md`; spec/brief/handoff と RVAs`0x38xxxx`. [前へ：`v2.110.0.1`]
- **`v2

.110.0.1` — NovaClamp: fix PE RVAs (0x38EDD5, não 0x78EDD5).** Lane **Jarvis-MAGIC**. **PATCH**: hook falhava silencioso — IDA flat = PE RVA + 0x400000 na seção battle; bytes `7E 02` no build Steam. [anterior: `v2.110.0.0`]
- **`v2.110.0.0` — 新しいスーパーダメージキャップバイパスLAB (`FfxHooksDll`).** Lane **Jarvis-MAGIC**. **MINOR**: hook inline @`FFX.exe+0x38EDD5` — スキップクランプ`mov eax,ebx` いつ`[ebp+0x1C]==0x3073` (Nova #115); 式による変動ダメージ; フラグ`nova_super_damage.flag` /`nova_super_damage_log.flag`; REクランプのドキュメントおよびRT2の仕様書は、ゲーム内での実装が保留中。[前回：`v2.109.4.1`]
- **`v2.109.4.1` — Arena+: NPCフックラボ — RT2が失敗、軽減措置＋REで解決。**レーン**Jarvis-ARENAPLUS**。**パッチ**：フックの強化`013B` (バンプなし)`maxIndex` パッチなし；defer 30f；`sub_86BEC0` @`0x86BEC0`); **RT2 NPCが失敗** — 6番目の選択肢が表示されない；**F7は引き続き有効**。Doc`FFX_ARENA_PLUS_NPC_NOWWHAT_HOOK_2026-06-15.md` 更新済み。[以前：`v2.109.4.0`]
- **`v2.109.4.0` — Arena+: NPCオプション「Now what?」→ Arena+ (lab)。**レーン**Jarvis-ARENAPLUS**。**MINOR**: hook`Common.displayFieldChoice [013B]` 文字列`0x4A`;`arena_plus_npc.flag`. RT2 NPC **合格しなかった** — 参照`v2.109.4.1`. [前へ：`v2.109.3.0`]
- **`v2.109.3.0` — ThundaFira: hook PPPDRAW インライン EXE を無効化 (`sub_71B980`).** Lane **Jarvis-MAGIC**. **PATCH**:`FFXPROBE_PPPDRAW_RETIRED`; オペコード 14～16 はエラーを返す; lab`--pppdraw-tint-capture` ブロック済み；`DEAD_ENDS_INDEX` H7–H9。[前：`v2.109.2.0`]
- **`v2.109.2.0` — ThundaFira: PPPのドローフック爆発後のクラッシュを修正。** Lane **Jarvis-MAGIC**。**PATCH**:`PPPDRAW_STOP` hook mid-VFXはアンインストールしないでください。アンインストールは`DLL_PROCESS_DETACH`; キャプチャは、最後のヒットから3秒間待機する。Doc`FFX_THUNDAFIRA_PPPDRAW_HOOK_CRASH_2026-06-15.md`. [前へ：`v2.109.1.0`]
- **`v2.109.1.0` — ThundaFira: PPP ドロー・フック・リターゲット`sub_71B980`.** Lane **Jarvis-MAGIC**. **PATCH**:`ffx-probe` PPPDRAWは次の場所にインストールされます`0x71B980` (14 B プロローグ); tint struct`a3+4`; doc`FFX_THUNDAFIRA_SUB_71B980_IDA_2026-06-15.md`. [前へ：`v2.109.0.2`]
- **`v2.109.0.2` — Research queue troxa：REパッケージがオフライン（21件のドキュメント）。**レーン**Jarvis-RESEARCH-TROUXA**。**REVISION**：インデックス `FFX_RESEARCH_QUEUE_TROUXA_IN

DEX_2026-06-15.md` + dossiers ThundaFira/Magic/Arena+/AutoAbility/FPS/offline-ci/event-text/spheregrid; `KNOWLEDGE_BASE` + `PORT_STATUS` atualizados. Sem mudança de comportamento do produto. [anterior: `v2.109.0.1`]
- **`v2.109.0.1` — Arena+：ディスク内のFFXEDフラグ + OST 145 マルチボス RT2。**レーン**Jarvis-ARENAPLUS**。**パッチ**：PCでのマッチセーブ (`gil@0x3D88`, アリーナ`@0x424C`, FFXED`@3273` bit7) OR 実行時`0x18F4`; F7での「8 Dark Aeons」COST; 複数のボスに対するOSTチャレンジ（P4のディレイ開放）。 [前：`v2.109.0.0`]
- **`v2.109.0.0` — セーブエディタ：MCマルチスロット + アイテムドロップダウン + RT2.** Lane **Jarvis-SAVE**. **MINOR**：ハブ内のスロットピッカー`.ps2`; アイテムのコンボ（FFXEDカタログ）；`--ffx-save-rt2` (raw/.ffx/.ps2 マルチスロット); 修正`SaveSlot` 別のパスに保存する。[前へ：`v2.108.0.0`]
- **`v2.108.0.0` — セーブエディタ：キャラクターごとの武器コンボ + C0008i バッチファイル一式。** Lane **Jarvis-SAVE**。 **MINOR**：ドロップダウン付き装備（T[0–6] ティダ→リク、外観、オート、ダメージ計算式）；`weaponCatalogByCharacter` レジストリ内で；`FfxSaveBatchActions` アクションスロット 9–59（スフィア／ミニゲーム／ブリッツ／インポートドナー）；「キャラクター」「スフィア」「ミニゲーム」「ブリッツボール」タブ内のバッチボタン。[前へ：`v2.107.0.0`]
- **`v2.107.0.0` — セーブエディタ：FFXED完全版（装備→インポート + .ps2 MC）。** Lane **Jarvis-SAVE**。 **マイナー**：ネイティブタブ「Equipment」（200スロット＋自動設定）、「Items/Gil/key items」、「Blitzball」（60選手）、「Sphere Grid」（ノード＋バッチ）、「Minigame」（レジストリフィールド）、「Misc/Import」（ドナー地域）；`ffxed_registry.json` +`scripts/ffxed_extract_registry.py`; 読み込み／保存`.ps2` 8MB; バッチ C0008i のレビュー; フォールバック FFXED.jar。[前:`v2.106.0.1`]
- **`v2.106.0.1` — Arena+：FFXEDに準拠したDark Aeonのフラグ（bit7 @ save+3273）。** レーン **Jarvis-ARENAPLUS**。 **パッチ**：F7メニューで誤った配列が読み込まれていた`0x18F4`; 現在はFFXEDの「Misc→Optional Bosses」の要素を使用しています (`0xD2D759..`, ビット7）。[前：`v2.106.0.0`]
- **`v2.105.0.0` — ThundaFira: ppp_dataA 対 PE アナライザーのライブ実行 + ダンプ・ティント領域。** Lane **Jarvis-MAGIC**。**MINOR**: ランタイム・ラボ`LiveVsPeAnalyzer` +`--live-vs-pe`; ダンプカーの撮影`tint_vec4_canonical` @`0x37710` そして`dataA_cyan_strip`; ランタイムの判定結果≠PE (2758 B の差)。[以前: `v2.104.0.6

`]
- **`v2.104.0.6` — Arena+ OST: レシピラボ（オーバーライド + soundcmd トリガー 4）。** Lane **Jarvis-ARENAPLUS**。**PATCH**: 非同期処理における直接スワップ 16→145 を廃止；使用`musicOverride` +`soundcmd 23/4/0` +`SwitchCrossfade` （ラボメニューで実証済み）。[前へ：`v2.104.0.5`]
- **`v2.104.0.3` — Arena+ OST hook v5 (FSM case-8)`PlayTrackWithPreload`).** Lane **Jarvis-ARENAPLUS**. **PATCH**:`InstallMusicHookArenaBattle` 傍受する`PrepBattleTrack` +`PlayTrackWithPreload` (RVA`0x486940`/`0x486980`) ハードコーディングされた 16→145 を変更し、非同期キュー 26/39 はそのまま維持；ドキュメント RE P0–P3。[以前：`v2.104.0.2`]
- **`v2.104.0.2` — ThundaFira: PPP ドローフックのクラッシュ修正（プローブは安全）。** Lane **Jarvis-MAGIC**。**PATCH**: 無効なフォールバック EXE を削除；vtable のみをインストール`host+2856` プロローグ付き`55 8B EC`; STOP はバイトを復元します;`--force-tint` RT2のクラッシュ後にロックされた。[前：`v2.104.0.1`]
- **`v2.104.0.1` — ThundaFira: PPP ドローフックの修正 (vtable host+2856)。** Lane **Jarvis-MAGIC**。**PATCH**: 実行時に bind fn を解決 (`off_C64CE8+2856`); cdecl thunk; force tint em +0/+4. RT2− em`0x31B590` (0件)。[前へ：`v2.104.0.0`]
- **`v2.104.0.0` — ThundaFira: プローブ・フック・ティント・PPP・ドロー (`FFX+0x31B590`).** レーン **ジャービス-MAGIC**. **MINOR**:`ffx-probe` オペコード PPPDRAW 14–16; lab`--pppdraw-tint-capture`. [前へ：`v2.103.0.0`]
- **`v2.103.0.0` — ThundaFira: KeThResのマップ再配置 + フックアタッチバッファ (`sub_72C570`).** レーン **ジャービス-MAGIC**. **MINOR**:`MagicDllKeThResRelocAnalyzer` +`--thundafira-kethres-reloc`; ゲートパッチを修正（`dataA+0x58C..0x620`, 2× vec4);`ffx-probe` KETHRESのオペコード 10–12; lab`--kethres-attach-capture`. [前へ：`v2.102.0.1`]
- **`v2.102.0.1` — ThundaFira: gate KeThRes PPP パッチ（RT2のソフトロック後）。**レーン**Jarvis-MAGIC**。**パッチ**:`MagicDllKeThResPppPatch` blob/offset-tableへのパッチ適用をやめて、ただ`float_vec4` シアン帯で`dataA`. Doc RT2− softlock. [前へ：`v2.102.0.0`]
- **`v2.102.0.0` — ThundaFira: KeThRes PPP オフラインパッチ (`--thundafira-kethres-patch`).** レーン **ジャービス-MAGIC**. **MINOR**:`MagicDllKeThResPppPatch` — 分析する`ppp_dataA` + ディスク上のblob、オレンジ色を適用（スコープ`ppp-only`); 出力`magic_0716_kethres_orange.dll`. RT2のゲーム内処理が保留中。[前回：

`v2.101.0.1`]
- **`v2.101.0.1` — ThundaFira: KeThResの静的ダンプ (`--thundafira-kethres-dump`).** Lane **Jarvis-MAGIC**. **PATCH**:`MagicDllKeThResDumper` — PEからblob/handle/PPPカタログを抽出する`0094` + manifest/hex MD。[前：`v2.101.0.0`]
- **`v2.101.0.0` — ThundaFira: KeThRes PPP パーサー (`--thundafira-kethres-parse`).** レーン **ジャービス-MAGIC**. **MINOR**:`MagicDllKeThResParser` — PPP オペコードカタログ`0x55D4456F`,`pppKeThRes32x4` + score phyre PS3; IDA draw-path ドキュメント。[前:`v2.100.0.3`]
- **`v2.100.0.3` — ThundaFira フェーズ1：RT2 デュオ vec4 地上（`--offset2`).** Lane **Jarvis-MAGIC**. **PATCH**:`--thundafira-ppp-color-test` 承諾する`--offset` +`--offset2` （最大2）および`--rt2-tag` RT2のB枝を二等分するために。[前：`v2.100.0.2`]
- **`v2.100.0.2` — ThundaFira フェーズ1：RT2 FAILにより、PPPランタイムサイトが停止。** Lane **Jarvis-MAGIC**。**PATCH**：RT2 Halyson —`full_phase1` 光線に色がない、アニメーションが速く・平坦（タイミングと色の見間違い）；ゲート`--thundafira-ppp-runtime-color` ただ`--restore`. Doc`FFX_THUNDAFIRA_PHASE1_RUNTIME_PATCH_RT2_FAIL_2026-06-14.md`. [前へ：`v2.100.0.1`]
- **`v2.100.0.0` — ThundaFira フェーズ1：PPPカラーランタイムパッチ拡張版（デフォルトブランチ＋ボルトスポーン）。**レーン**Jarvis-MAGIC**。**MINOR**：`--thundafira-ppp-runtime-color --site full_phase1` — IDAは、モンスターのキャストが**default**のブランチを使用していることを証明した`Thundaga_EgoTaskSetup_0094` (LABEL_9 プレイヤー ID を除く); ホスト+1072 および RGBA スポーンの両方のブランチにパッチを適用する`Thundaga_EgoTaskTick_0094`. Doc`FFX_THUNDAFIRA_PHASE1_RUNTIME_PATCH_2026-06-14.md`. ヒトRT2は保留中。[前：`v2.99.0.0`]
- **`v2.99.0.0` — ThundaFira: PPP カラーランタイムパッチ (IDA ホスト+1072)。** Lane **Jarvis-MAGIC**。**MINOR**: ゲート`--thundafira-ppp-runtime-color` — パッチ即時実行`.text` で`sub_10006B50` (`magic_0716.dll`); scan`.data` RT2終了後にvec4が廃止されました。Doc`FFX_THUNDAFIRA_PPP_RUNTIME_COLOR_IDA_2026-06-14.md`. [前へ：`v2.98.1.0`]
- **`v2.98.1.0` — ThundaFira: phyre RT2 分類器 (128_128 ≠ レイ)。** Lane **Jarvis-MAGIC**。**PATCH**:`ThundagaPhyreClassifier` — RT2 ハリソンが証明した`_128_128` で`0716` = 地面への衝撃の閃光／爆発、**雷**ではない；`--bolts-orange` 「comport」に名称変更

主にWARNを使用したグラウンドフラッシュ用。Doc`FFX_THUNDAFIRA_PHYRE_SHEET_RT2_2026-06-14.md`. [前へ：`v2.98.0.0`]
- **`v2.98.0.0` — テキスト：2バイトグリフのデコード／エンコード（FTCX/FONTk）＋EncounterTableの名称変更`MapNamePadding`.** レーン **ジャービス-MAGIC**. **MINOR**:`FfxEncoding.glyph.cs` — バイト`0x06` そして`0x26..0x2F` もはや～ではなくなる`<C6>`/`<C38..>` そしてトークンになった`<FTCX:n>`/`<FONTk:n>` バイト単位の往復（`TextBinary_Util.TryMatchGlyphToken`、非ブロック型検査）。**PATCH**（外観上の修正）：`Unknown0C` →`MapNamePadding` で`EncounterTable_File` (IDA-proved: map-name の文字列の終端)。Worktrees Claude`851-1/2/3/4` 選別済み：持ち込まれた有用なもののみ；残りは廃棄。[前：`v2.97.0.0`]
- **`v2.97.0.0` — ThundaFira: Family D PPP プローブ + 修正済みリカラー RT2。**レーン** Jarvis-MAGIC**。**マイナー**: ゲート`--thundafira-ppp-probe` (候補者`pppColMove`/`pppKeThRes` で`magic_0094`),`--thundafira-ppp-color-test` （外科用パッチ 1 オフセット）、`--thundafira-recolor --phyre-anim1`; デフォルトの分割パック`716/717` ドナー付き`0095`;`MagicDllPppColorCandidateScanner`; vec4 のヒューリスティックな`0716.dll` **退職** (RT2:`0x31640` = PPP行列、2D半径）。ドキュメント：`FFX_THUNDAFIRA_HANDOFF_CONTINUE_2026-06-14.md`. [前へ：`v2.96.0.0`]
- **`v2.96.0.0` — Kernel monmagic live sync + アル・ベド辞書エディタ。** Lane **Jarvis-MAGIC** + テキスト。 **MINOR**:`KernelMonsterMagicLiveSync` 読む`monmagic1.bin`/`monmagic2.bin` プロジェクトの読み込み／保存時に、名前とオペランドを反映する`0x4xxx`/`0x6xxx` 新しいものへ`CommandMonster*`,`AiCommandId`,`AiCommandMetadataCatalog` およびMonster AIピッカー（spell LABによる手動パッチなし）；**Al Bhed Dictionary**モジュール（`albheddic.bin` US Latin + JP かな）を、Rail上のバイトセーフなライターで処理`???`. RT2 ThundaFira のゲーム内処理が保留中。[前回：`v2.95.0.0`]
- **`v2.95.0.0` — ThundaFira：LABの魔法「Thundaga」＋「Multi-Fira」＋エディタ上のUI。**レーン**：Jarvis-MAGIC**。**MINOR**：ゲート`--thundafira-pack` (grow monmagic2 #248、クローン`magic_0716`/`0717`, テクスチャ thunder+fire);`--prism-flare-recolor` (濃い紫色に塗り直す)`magic_0715`); **Monster Commands 2** → 「Install/Deploy visuals」ボタン。[前へ:`v2.94.0.0`]
- **`v2.94.0.0` — Magic DLLs：UI上のwave4のクレジット表示 + p

Magic Viewer / Phyre Package I/O.** Lane **Jarvis-MAGIC**. **MINOR**:`MagicDllWave4CatalogLoader` オフラインの分類体系（カテゴリ、ファミリー、カーネル参照、オーバーレイ署名、編集ガイダンス）を`Extras → Magic DLLs (FFX)`; リスト内のバッジ; **Wave4 Attribution** カード; **Magic Viewer** ボタン (`?magic=####`) および **Phyre Package I/O**（第1`.dds.phyre` （PS3用）；`scripts/magic_viewer_merge_wave4_catalog.py` wave4を`magic-viewer-catalog.json`; ビューアのHUDにW4のバッジが表示されている。[前：`v2.93.0.0`]
- **`v2.93.0.0` — Magic DLLs：wave3 分類 + wave4 ディープコーパス + オーファンアトリビューションカタログ + Hex-Rays 後処理。** Lane **Jarvis-MAGIC**。**MINOR**：gates`--magicdll-classify-wave3`,`--magicdll-deep-corpus-wave4`,`--magicdll-orphan-catalog`;`MagicDllMoveAnimParser` 修正する`moveAnim=magic_XXXX/None` (+44 呪文リンク); 複数ソースによる分類 (463`catalog_and_kernel`, 109`engine_overlay_carrier`, 9つのツイン、2つのクローン); スクリプト`magic_dll_hexrays_postprocess_host.py`,`magic_dll_hexrays_host_profile.py`,`magic_dll_wave4_rt2_queue.py`; Hex-Raysのセカンダリバッチ処理 + 自動後処理。wave3/wave4/orphanカタログのドキュメント。RT2のゲーム内実装は保留中。[前回：`v2.92.0.0`]
- **`v2.92.0.0` — Magic DLLs: Hex-Rays ALL tier (1829/1829) + idalibによる並列バッチ処理 + RT2ビジュアルプレップゲート。** Lane **Jarvis-MAGIC**。 **MINOR**:`scripts/magic_dll_hexrays_batch.py` (`--tier all|pinned|shared`,`--workers N`,`--remaining-only`, 隔離されたステージング環境`w0..wN`); wave2 コーパス **534 DLL / 1829 スロット** Hex-Rays にて`work/magic_dll_logical_decompile_wave2/hexrays_output/` （6人のワーカーで約16分）；ゲート`--magicdll-rt2-visual-prep` DLLを生成する`magic_0084`/`magic_0098` + パッチプランをオフラインで。ドキュメント：`FFX_MAGIC_DLL_HEXRAYS_ALL_COMPLETE_2026-06-14.md`,`FFX_MAGIC_DLL_HEXRAYS_PINNED_PROGRESS_2026-06-14.md`、RT2 チェックリスト 0084/0098 を更新。正確性：C言語の逆コンパイル ≠ 視覚的意味論；RT2 ゲーム内（Prism + ラボ用 DLL）は未処理；コーパス内のコードスロットがない DLL が約49個、キューに待機中。[前回：`v2.91.1.0`]
- **`v2.91.1.0` — Arena+: OST battle-entry hook v4 + briefs Opus + オフセット調整済みのDark Aeon。**レーン**Jarvis-ARENAPLUS**。**パッチ**:`MusicHook` デュアルインターセプト`PlayTrack(16)` 経由`soundcmd 23` (prob

e) 標準のフォールバック付き；`SwitchCrossfade(16)` argの交換；削除`SwitchCrossfade` シムに直接当たっていた（音がしなくなっていた）。`dllmain` 「arma pending」の前に`781D60`; フォールバックスレッドは、インターセプトされたが消費されなかった場合のみ。設定ラボ`RuntimeTools/FfxHooksDll/config/arena_plus_music_*.txt`.`MemoryMap.ADDR_DARK_AEON_FLAGS=0xD2E384`;`ffxprobectl arena-flags` RVAを修正しました。ドキュメント：`OPUS_BRIEF_ARENA_PLUS_MUSIC_2026-06-14.md`,`OPUS_BRIEF_ARENAPLUS_RESEARCH_QUEUE_2026-06-14.md`; Arena+の資料におけるオフセット補正のバナー。RT2 OSTはまだ未処理。[前：`v2.91.0.0`]
- **`v2.91.0.0` — Magic DLLs：論理デコンパイル・ウェーブ 1/2 ＋ ブラウザ UI（ファミリー・コンパレータ、PS3 ブリッジ、論理デコンパイルタブ）。** Lane **Jarvis-MAGIC**。 **MINOR**：`MagicDllLogicalDecompiler` (静的ホストオフセットフィンガープリント + 擬似コード／スロットクラスタリング)、ゲート`--magicdll-logical-decompile-wave1` （サンプルDLL 119個）および`--magicdll-logical-decompile-wave2` (583/583 コーパス + Hex-Rays の pinned/shared/all キュー);`MagicDllFamilyComparator` +`MagicEffectClonePipeline` (deploy ps3data clone); **Logical Decompile** タブで`Extras → Magic DLLs (FFX)` スロットごとの表／擬似コード、Value WorkbenchでのFamily C/Dの警告、PS3 Magic／extract／modsへのショートカット、およびブリッジ`Open PS3 Magic (HD)`. ドキュメント：`FFX_MAGIC_DLL_LOGICAL_DECOMPILE_WAVE1_2026-06-14.md`,`FFX_MAGIC_DLL_LOGICAL_DECOMPILE_WAVE2_2026-06-14.md`. ビルド リリース 0 エラー。[前回：`v2.90.1.0`]
- **`v2.90.1.0` — Prism Flare v2 パック（ゲームプレイ + prism DLL リカラー + デプロイ）。**レーン**Jarvis-MAGIC**。**MINOR**: gate`--prism-flare-v2-pack` — 行 #247 パワー 42、炎・雷・水、スロー 65%/4ターン；カラー変更`magic_0714/0715` (各16個のvec4パッチ、パープルプリズム)。[前：`v2.90.0.3`]
- **`v2.90.0.3` — Magic VM：パス 2+3 クラスター（MISC→0）＋RT2 ビジュアル 0084/0098。**レーン** **Jarvis-MAGIC**。**リビジョン**：パス 2`analyze_batch` (66 MISC) + 残りの10件についてHex-Raysのデコンパイルを3回実行 →`cluster_assignments_pass3.csv` (119/119、行動クラスターあり)。資料：`FFX_MAGIC_VM_MISC_PASS3_DECOMPILES_2026-06-14.md`,`FFX_MAGIC_RT2_VISUAL_0084_0098_2026-06-14.md`. [前へ：`v2.90.0.2`]
- **`v2.90.0.2` — Magic VM：自動化されたクラスターパス1（119/119コアオペレーション）。**レーン**Jarvis-MAGIC**。**リビジョン**：`f

unc_query` IDA + `work/magic_vm_cluster/cluster_from_func_query.py` → `cluster_assignments.csv` (9 clusters; 66 MISC aguardam pass 2 callees). Doc clusters atualizado com fila decompile top-3/cluster. [anterior: `v2.90.0.1`]
- **`v2.90.0.1` — マジックエンジン：統合ハブ + VMクラスター + A/C編集ガイド。** Lane **Jarvis-MAGIC**。**REVISION**：VM EXEを連携させるREドキュメント、581個のDLLの分類、および実践的な編集。`FFX_MAGIC_ENGINE_MASTER_2026-06-14.md` (ハブ)、`FFX_MAGIC_VM_OPCODE_CLUSTERS_2026-06-14.md` (7つのクラスター、IDAサンプル)、`FFX_MAGIC_FAMILY_AC_EDITING_GUIDE_2026-06-14.md` （色／速度：Value Workbenchによる、A/Cファミリー）。[前：`v2.90.0.0`]
- **`v2.90.0.0` — Magic DLLs：ブラウザのスロット0に対するバイトスキャンによるA/B/C/Dファミリーの分類。** Lane **Jarvis-MAGIC**。 **MINOR**：`MagicDllFamilyClassifier` ドア`scripts/scan_ab.py` C# 向け — 事前分類（基準：）`slot_kind_signature` + スロット0のRVAにある2048バイトのPEスキャン (`0xB2C/0xB30` → B、`0xB1C/0xB18` → C). 組み込まれている`MagicDllSemanticAnalyzer.DetectFamily` そして、その`InspectionSummary` Magic DLL Browserによる。IDAによる検証：バケット404に潜入したFamily Cの13個のDLLのうち3つのサンプル（`magic_0183`,`magic_0244`,`magic_0700`) が確認している`host+2844/2840` なし`host+2860`. ドキュメント：`docs/reverse/FFX_MAGIC_DLL_INFILTRATED_C_VALIDATION_2026-06-14.md`. ゲート・バイトスキャン 13/13 via`work/validate_infiltrated_c/validate.py`. [前へ：`v2.89.0.0`]
- **`v2.88.1.5` — Magic DLLs：実際の逆コンパイル（Hex-Rays）により、2つのエフェクトアーキテクチャと、実証済みのホストフィールドが明らかになった。**Lane **Jarvis-MAGIC**。**REVISION**について`v2.88.1.4`: リポジトリにREが残っている（デコンパイル＋ファイル名の変更／コメントアウト）`.i64`)、製品の挙動に変化はない。「位置による命名」（ヒューリスティック）から離れ、`MagicDllSemanticAnalyzer`) そして実際にデコンパイルした`magic_0084` そして`magic_0148` IDAにおいて。主な発見：コーパスには、スロット・カインドのシグネチャでは区別できない**2つ以上の異なるアーキテクチャ**が存在する（いずれも`code` すべてのスロットにおいて）：**「自己完結型粒子」**（`magic_0084`: 1023個のパーティクルからなるローカルプール + 256パケットのリング、ルートなし`dat_et`; slot1は描画ティックです；slot4は**オーバーレイテーブル自体を上書き**してフェーズを進めます — `magi`でも確認済み

c_0688`) e **família B "root/record-interpreter"** (`magic_0148`: aloca o root de 1.024.000 bytes via host+3212, materializa via host+2860, e chama host+2864=`sub_80CD60` e host+2884=`sub_80BEA0` diretamente). Promovi ~20 host fields de `候補者` para **provado por chamada decompilada cross-DLL** (host+672 actor, +884/+888 timer, +900/+904/+908 phase/start/progress, +2860 materialize, +2864 interpreter, +2872/+2876 Ego obj, +2908 make-packet) e descobri o par novo **host+3216 (free)** de host+3212. Doc: `docs/reverse/FFX_MAGIC_DLL_DECOMPILED_FAMILIES_2026-06-13.md`. Bump do editor para `2.88.1.5`. Guardrail: ainda é RE de bytes, nomes descrevem papel (não símbolo original); slot-kind signature é proxy fraco — o classificador real de família é "slot 0 chama host+2860?". Validação: 2 `.i64` salvos no `magicFiles\FFX` com rename+comment; renames `17/17` (0084) e `10/10` (0148) OK. [anterior: `v2.88.1.4`] — Jarvis-MAGIC
- **`v2.88.1.4` — 詳細な調査：ゲームプレイは60fps、カットシーン／FMVは30fps。** Lane **Jarvis-FPS**。**REVISION**について`v2.88.1.3`: リポジトリに保存された調査/RE。製品の動作に変更はありません。資料`docs/reverse/FFX_GAMEPLAY_60FPS_DEEP_RESEARCH_2026-06-13.md` ユーザーの新たな要望に応える：カットシーンは30fpsのまま維持可能だが、重点はゲームプレイにある。 結論：これによりオーディオビジュアルの範囲は縮小されるが、問題が単純なキャプチャ処理に変わるわけではない。ゲームプレイでは、フィールド、バトル、MSEQ、カメラ、CTB、魔法／VFX、メニュー、ロード、ミニゲームを依然として個別に処理する必要がある。調査では、以下の4つのアプローチについて詳しく説明している：`visual 60` フレーム生成／補間、フレームペーシング／VRR／Present Doctor、30fpsのシミュレーションと内蔵補間機能を用いた60fpsのレンダリング、および`engine-exact 60fps` Scoutが分離可能なクロックを実証するまでは、ムーンショットとして扱う。次の技術的なステップ：`fps-scout` read-only、CSV/summary 形式の`Present`、heartbeat/tick、ゲームモード、MSEQカーソル、およびUnX/SpecialKとの互換性を、パッチを適用する前に確認してください。エディタのバンプは`2.88.1.4`. 検証：文書上のアンカーを介して`Test-Path`/`rg`; ビルド`work\_build_gameplay60_research_28814` エラー 0 件 / 警告 366 件（ベースライン）。[前回：`v2.88.1.3`] — Jarvis-FPS
- **`v2.88.1.3` — 60fps 調査 / FPS アンロック：フレーム生成、フレームペーシング、およびエンジン・エクサクトの分離。*

* Lane **Jarvis-FPS**。**REVISION** について`v2.88.1.2`: リポジトリに保存された調査/RE。製品の動作に変更はありません。資料`docs/reverse/FFX_60FPS_UNLOCK_FEASIBILITY_RESEARCH_2026-06-13.md` 単純な30→60のキャップが確実であるという証拠はないと結論づけ、正直なルートは次のように分かれる。`visual 60` フレーム生成／外部補間により、30fpsではフレームペーシングが向上し、30fpsのシミュレーションと内部補間を用いて60fpsでレンダリングし、そして`engine-exact 60fps` moonshot/research-only として。裏付けとなる証拠：UnXは乗算によってスピードハックを行っている`FFX_GameTick` 通常モードのロックを解除する代わりに、Special K/UnXは、30の外部キャップがロードに影響を与える可能性があり、一部のメニューは60で動作することに注意を促している。リポジトリにはすでにDINPUT8/main-thread、Present hook、MSEQが含まれている。`frameRate=7680 (30fps*256)`、しかし、magic/battle/cutsceneではまだフレーム単位の正確なタイミングが実現されていません。次の確実なステップ：`fps-scout` read-only での`FfxHooksDll`/`FfxDinput8Probe` パッチを適用する前に、Present、tick、MSEQカーソル、およびゲームモードを測定します。エディタのバンプを`2.88.1.3`. 検証：文書上のアンカー経由で`Test-Path`/`rg`; ビルド`work\_build_fps_research_28813` エラー 0 件 / 警告 366 件（ベースライン）。[前回：`v2.88.1.2`] — Jarvis-FPS
- **`v2.88.1.2` — マジックDLL：類似した魔法のパターンを調査し、試行錯誤を減らして色や速度を特定する。** Lane **Jarvis-MAGIC**。**REVISION** について`v2.88.1.1`: リポジトリに保存された調査/RE。製品の動作に変更はない。クロスチェック`AiCommandMetadataCatalog.Generated.cs` (`979` 行、`689` com`moveAnim`), CSVオーバーレイ (`581` rows）およびDLL`magicFiles\FFX\magic_####.dll` 単なる名称ではなく、実際の外観に基づいて分類するため。主な知見：`Power`/hits/status はコマンド行に表示され、ビジュアルは`moveAnim`; 基本の「火」「雷」「水」は単純な系統に従う`nz9/u5`、Ice/curas/Flare-likeはより幅広いPPPファミリーを使用している；Cure/PotionおよびいくつかのMixesはビジュアルを再利用している；`Death` 同じ名前でも異なるDLLを指す可能性があることを示している；`Death` 一般的な`magic_0098` そして`Mega Death` `magic_0351` オーバーレイ／スロット／テクスチャサイズを共有するが、ハッシュ／ペイロードは共有しない；クローン`0714/0715` Fira/Thundaraのバニラ版に影響を与えることなく、Prism Flareへの正しい道を歩み続けている。ガードレール：`pppColor`/`pppColMove`/`pppAccele`, floa

tsとpushesは、RT2/probeが色、速度、またはタイミングを証明するまで候補を追跡し続けます。編集者によるバンプは`2.88.1.2`. 検証：資料に基づく根拠 via`Test-Path`/`rg`; ビルド`work\_build_magic_patterns_28812` エラー 0 件 / 警告 366 件（ベースライン）。[前回：`v2.88.1.1`] — Jarvis-MAGIC
- **`v2.88.1.1` — Arena+ pre-RT2：DLL経由でNPCに追加された新オプションに対応したバージョン管理された調査パッケージ。** Lane **Jarvis-ARENA+**。**REVISION**について`v2.88.1`: リポジトリに保存された調査/RE。製品の動作に変更はありません。Monster Arena/Arena+のファイルセットをバージョンアップ：新しいタブ/作成機能、DLL経由の挿入、実際の敗北によるDark Aeon/Penanceフラグ、NPCオプション、最終スカウト、およびファイル`nagi0700` pre-RT2。主な所見：アリーナのオーナーはイベントに没頭している`nagi0700`;`w0E::f05` メニューを表示する`Now what?` 経由`Common.displayFieldChoice [013B]` 文字列`[4A]`,`w0E::f07` セレクターを開くには`SgEvent.showModularMenu [401D]`、～をめぐる闘いを開始する`Battle.launchBattle [7002]` そして、敗れた「Creations」ブランド`0x0300..0x0322` 著：`Common.setMonsterArenaUnlocked [0210]`. 編集者からのバンプ：`2.88.1.1`. ガードレール：`research-only/pre-RT2`; 展開しない`ArenaUnlocks[35+]`, 編集しない`nagi0700.ebp` また、本番環境でのトレースの前に「row vanilla」を挿入しないこと。検証：`Test-Path` +`rg` ドシエ、KB、ハンドオフのアンカー；ビルド`dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_versioning_28811 --no-restore` エラー 0 件 / 警告 366 件（ベースライン）。[前回：`v2.88.1`] — ジャービス
- **`v2.88.1` — Magic Viewer Web：メインステージでのランタイムシミュレーション候補。** Lane **Jarvis-MAGIC**。**PATCH**について`v2.88.0`: ビューアーに新モードが追加されました`Simulate`、これはテクスチャのスライドショーを、逆順の構造チェーンに基づいて連続ループする形式に変更する（`sub_800530/590/950`,`sub_80CD60`,`sub_817200`,`root+84/root+88`、オーバーレイスロット、およびPhyreペイロード）。のテクスチャは`ps3data\magic` これらは、時計やフレームリストとしてではなく、エフェクトのビジュアル素材として表示されるようになりました。HUDには、フェーズ、ルートカーソル、コールバックのコード／データ、およびDLLの重複エイリアスが表示されます。ガードレール：これは`Runtime Simulation Candidate`、～より偽りではない`Cycle Surface`、ただし、フレーム精度のタイミング、完全なオペコードインタプリタ、RT2による相関処理はまだ実装されていない

ゲーム内のcallbacks/frame。エディタからのバンプで`2.88.1.0`. 検証：`node --check RuntimeTools\FFXMagicViewerWeb\app.js`; HTTP`http://127.0.0.1:8766/index.html?magic=0688` 200; Chromiumのヘッドレスモードでクリックされました`Simulate` デスクトップおよびモバイルで390px、ページエラーやコンソールエラーがなく、モバイルで横方向のオーバーフローがないこと、スクリーンショット`work/magic_viewer_runtime_simulation_0688.png` そして`work/magic_viewer_runtime_simulation_0688_mobile.png`; ビルド`dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_magic_runtime_sim_2881 --no-restore` エラー 0 件 / 警告 366 件（ベースライン）。[前回：`v2.88.0`] — Jarvis-MAGIC
- **`v2.88.0` — Magic DLLs (FFX)：色、速度、タイマー、および候補ベクトル用のValue Workbench。** Lane **Jarvis-MAGIC**。**MINOR**について`v2.87.1`: タブ`Extras -> Magic DLLs (FFX) / Role Candidates` 今、一つある`Candidate Value Workbench` 選択したDLLをスキャンして、以下のものを検索する編集可能なツール`float32`,`vec3f/vec4f` そして`push imm8/imm32`、候補をalpha/cor/scale/speed/timer/flag/countとして分類し、decimal/float/comma-vector形式で新しい値を入力したり、`Stage Patch` または、出力DLLを以下のように生成する`Apply To Output`. ブロック`Host Context / InitMagicPRX Fields` これもサポート対象になりました：ホストフィールドを選択し、DLL内の実際のu32の出現箇所を一覧表示し、具体的なオフセット参照の変更を可能にします。Guardrail：名称は候補に従い、変更のたびにRT2テストを実施して、視覚的・ゲームプレイ上の意味合いを確認する必要があります。エディタのバンプを`2.88.0.0`. 検証：`dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_magicdll_value_workbench_probe --no-restore` エラー 0 件 / 警告 366 件（ベースライン）。[前回：`v2.87.1`] — Jarvis-MAGIC
- **`v2.87.1` — 組み込みのMagic Viewer：WebView2の404エラーに対するホットフィックス。** Lane **Jarvis-MAGIC**。**PATCH**について`v2.87.0`: ドアが`8766` すでに一つが占められていた`http.server` 古くから深く根付いている`RuntimeTools/FFXMagicViewerWeb`; ランチャーはポートがアクティブであることを検知し、`/RuntimeTools/FFXMagicViewerWeb/index.html`、その404のサーバーで。`MagicViewerLauncher` ここで「repo-root」というURLをテストし、応答がない場合は自動的に「/index」にリダイレクトされます。

html`, mantendo o viewer embutido funcional sem depender de matar o servidor manualmente. Bump do editor para `2.87.1.0`. Validacao: HTTP atual provou `/RuntimeTools/FFXMagicViewerWeb/index.html -> 404` e `/index.html -> 200`; build `work\_build_magicviewer_url_hotfix` com 0 erros / 366 avisos baseline. [anterior: `v2.87.0`] — Jarvis-MAGIC
- **`v2.87.0` — Magic DLLs (FFX)：メニュー内に「Direct Patch Builder」があります。** Lane **Jarvis-MAGIC**。**MINOR**について`v2.86.2`: 面積`Extras -> Magic DLLs (FFX)` 現在、直接作成したパネルを表示し、そこからバイトパッチまたはASCIIパッチを含む出力DLLを生成します。`file offset` または`RVA`、既存のコンパイラ／パッチプランを再利用し、ユーザーに外部JSONファイルを作成させる必要をなくします。選択されたオリジナルファイルは上書きされません。ボタンでは常に出力用DLLの入力を求められます。ガードレールは維持されます：`Role Candidates` そして`Host Context / InitMagicPRX Fields` 証拠や候補名が引き続き存在します。実際の動作を再現するには、特定のアドレスにあるバイト／文字列／ASMにパッチを当てる必要があり、手動でのC／ASMまたはRT2を使用します。エディタのバージョンを`2.87.0.0`. 検証：`dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_magicdll_direct_patch_2870 --no-restore` エラー 0 件 / 警告 366 件（ベースライン）。[前回：`v2.86.2`] — Jarvis-MAGIC
- **`v2.86.2` — Magic Viewer Webは、メインステージで本格的なDLL/ランタイムリーダーへと進化しました。**Lane **Jarvis-MAGIC**。**PATCH**について`v2.86.1`: o`MagicCorpusIndexer` 今すぐ直接読む`magicFiles\FFX\magic_####.dll` そして証拠を生み出す`runtimeDll` カタログ（`runtime-dll-index.json`): CSVから候補ロールとともに保持されたPEの種類/マシン/タイムスタンプ、SHA-256、セクション、エクスポート/インポート、文字列/ファミリー、およびオーバーレイスロット。組み込みのビューアは以下で開きます：`Runtime Map` メインのビューポートで、どのテクスチャよりも先に表示される：DLL、PE、エクスポート／インポート、セクション、文字列ファミリー、ペイロードリンク、および実際のコールバック／データスロットを表示する；`Cycle Surface` そして`Stack Surface` Phyre/textureペイロードの二次的な検査方法となりました。エディタのバンプを`2.86.2.0`. 検証：`MagicCorpusIndexer` ビルドエラーなし；ビルドエディタは`work\_build_magic_runtime_reader_2862` エラー 0 件 / 警告 366 件（ベースライン）；ローカルカタログが再生成されました`587 entries`,

 `580 ps3 magic`,`583 runtime DLLs`,`581 overlay rows`; HTTP 200; Edge headless による検証`magic=0688` そして`magic=0003` com`Runtime Map` アクティブ、`slotCount=16`、ページエラーなし、スクリーンショット付き`work/magic_viewer_runtime_map_0688.png` そして`work/magic_viewer_runtime_map_0003.png`; モバイル版は390pxで、水平方向のオーバーフローなし。正直なところ：Carrier Runtime/Phyreの実際のプレーヤー；まだフレーム単位の正確な再生には至っておらず、タイムライン/コンパイラもRT2も同様。[前：`v2.86.1`] — Jarvis-MAGIC
- **🔮`v2.86.1` — バトルコマンドのブリッジ → PS3 Magic + Magic Viewer Webのロック解除。**レーン**Jarvis-MAGIC**。**パッチ**について`v2.86.0`: すでにリリース済みの機能に関する再利用・利便性、およびブート／カタログの固定。各フィールド`Anim 1 Id` /`Anim 2 Id` で`Battle Commands / Monster Commands` 現在、の概要が表示されています`magic_####`, ボタン`View Anim 1/2` 開くには`Extras / PS3 Magic (HD)` エフェクトで既にフィルタ処理済み、およびボタン`Open Folder` そのフォルダが`ps3data\magic`. また、組み込みのMagic Viewer Webを修正し、以下を使用するようにします`three`/`OrbitControls` 相対インポートを介してローカルに読み込み、画面がフリーズしてしまう可能性のある依存関係を排除し、`Loading catalog`; WebGLが失敗した場合、カタログを黙って終了させるのではなく、エラーが表示されるようになる。エディターからのバンプ：`2.86.1.0`. 検証：`dotnet build FFXProjectEditor\FFXProjectEditor.csproj -c Release -o work\_build_versioning_2861` エラー0件；HTML/vendor/catalogはHTTP 200で配信済み；CDP/Chromeで確認済み`585 entries`,`583` 項目および`exceptions=[]`; スクリーンショットは`work/magic_viewer_web_smoke_fixed.png`. 正確性：HDプレビューは近似的なテクスチャ／コンポジットであり、タイムライン／コールバックエンジンはDLL／ランタイムレベルで正確であり、最終的なゲームプレイにはRT2の検証が必要となる。[前：`v2.86.0`] — Jarvis-MAGIC
- **🔮`v2.86.0` — New Content Authoring Labs.** Lane **Jarvis-MAGIC**. **MINOR** について`v2.85.2`: コミットに追加された新しいコンテンツのラボパッケージを正式にバージョン管理する`ac2f5ebe`. AutoAbility writer AU1～AU7、Monster Magic/Prism Flare ツール、Magic DLL（FFX）、VBF Extract（抽出専用）、PS3 Magic テクスチャ I/O、および Phyre Package I/O が含まれます。エディタのバージョンを`2.86.0.0`. 正直なところ、魔法・エフェクト・テクスチャのラボは、RT0／オフライン、テクスチャI/Oの同一形状、および

RT2マニュアル；タイムライン／コールバックエンジン・アキュレート・コンティニュア DLL／ランタイム。[前：`v2.85.2`] — Jarvis-MAGIC
- **🧠`v2.85.2` — Monster AI Editor：公開された「Forbidden Rite」＋フェイズマネージャーの状態の読み取り。** Lane **Jarvis-MAGIC**。**PATCH**について`v2.85.1`: 公印を削除する`LAB` Forbidden Rite/var priv/writer のローテーションは、すでに著作者フローとして実証済み；削除`Sequência / Multi-*` 偽物のMulti-*が販売されるのを防ぐため、フローを迅速化し、ウィンドウ内で意図した順序を維持する`Ação composta`; フェイズごとに「Forbidden Rite」を追加し、フェイズマネージャーに追加HPを保存する；ビルダーを修正する`Condição multivar livre` ～を再開するために`ConditionGuard` 再起動／再監査後に選択されたフェーズの、シェイプスタック／RPNのデコード（`cond1 cond2 E/OU`) そして、解釈する前に「ランダムな要素」を取り除く。編集者からのバンプで`2.85.2.0`. 検証：隔離環境でのビルド、エラー0件、`phase-rotation-rt0` 319/319 うち`var1 store when present` 300/300、そして`multivar-guard-rt0` 300/300。ゲーム内でのRT2は、最終的なゲームプレイにおいて引き続き必須です。[前回：`v2.85.1`] — Jarvis-MAGIC
- **🧠`v2.85.1` — Monster AI Editor：位相回転マネージャーの安定性。** Lane **Jarvis-MAGIC**。**PATCH**について`v2.85.0`: フィルター／ピッカーが再構築された際に、ステージカードのスキルが失われる不具合を修正しました`PhaseAbilityOptions`、を使用して`SelectedPhaseAbility` 安定した予測として、かつ無視して`null` ComboBoxのトランジティブ；LAB v1のリードバックを再構築する`guard -> performCommand -> mutação de var -> RET/JMP`; 以前行っていた自動ピンを削除します`Fluxo de Raio`/`Fluxo de Fogo` トップへ移動し、視覚的な選択を解除する；条件／ガードを保持する`AliasKey`、UIが最初の状態に戻るのを防ぐ。エディタのBumpを`2.85.1.0`. 検証：ビルドエラー0件、`phase-rotation-rt0` 319/319 うち`var1 store when present` 300/300、そして`multivar-guard-rt0` 300/300。[前：`v2.85.0`] — Jarvis-MAGIC
- **🧠`v2.85.0` — Monster AI Editor：フェイズローテーションマネージャー、マルチ変数条件、シーモア式複合アクション。** Lane **Jarvis-MAGIC**。 **MINOR**（Monster AI Editorの新機能。同チャット内で複数のバグ修正をまとめて反映）。以下を追加します。`PhaseRotationRecipe` LAB v1: `AppendGu` によるフェーズ

ardedAction`, condição própria por fase ou fallback, alvo/chance por fase, mutações de var por fase (`+最小値..+最大値` e reset), `ここで止まってください`/RET e gravação com backup em monstro de teste. A janela de rotação agora audita vars, permite apelidos por monstro, cria var `priv` livre em LAB, monta condições multivar livres e preserva draft por contador/var. Também entra a janela de `複合アクション · シーモア`, para montar sequências explícitas de habilidades com alvo entendido e Forbidden Rite planejado entre passos. Corrige bugs de estado do builder: avanço/reset escrevem a var explicitamente escolhida, a condição da fase não sobrescreve outras fases, reauditar preserva a var ativa, e o filtro de habilidade não apaga Thunder/Water/etc já usados no draft. AiScriptLab ganhou gates `--var-grow`, `--var-flow`, `--multivar-guard-rt0` e `--phase-rotation-rt0`; validação usada: build 0 erros, `phase-rotation-rt0` 319/319 com `var1：存在する場合に保存` 300/300, e `multivar-guard-rt0` 300/300. Honestidade: writer LAB/offline; RT2 em jogo ainda obrigatório antes de chamar rotação de fase de comportamento final. [anterior: `v2.84.25`] — Jarvis-MAGIC
- **🧠`v2.84.25` — Monster AI Editor：Yunalescaがクリーンなプリセットとなり、条件はメインの執筆フローに移されました。** Lane **Jarvis-MAGIC**。**累積パッチ +5** について`v2.84.20`: 同一ブロック内に「クイック儀式」「状態」「詳細編集」が混在していた画面のUX/仕様を修正しました。YUNALESCAは現在、ステータスや祝福のプリセット専用エリアとなっており、戦闘用儀式は含まれておらず、`Revezar 1/2`, なし`Revezar 1/3`, なし`Duplicar cast` また、冗長な条件の事前定義も不要です。条件コンストラクタは`Adicionar / trocar comportamento`、同出版社を代表する作品：`onTurn`,`Início`,`Sempre`,`onHit`,`Qualquer Hit`,`HP < %` そして`Talvez 1 em K` 次の作成・変更される動作の準備を始めます。メインバーは、選択されたアクションのみにフォーカスが当たっています（`Trocar habilidade`,`Duplicar ação`,`Subir/Descer`,`Modo: fila/agora`,`Tirar ação`,`Desfazer backup`). バックエンドには、ガードを明示的に指定してスキルを作成したり、アクションのテンプレートをコピーしたり、マウント状態の条件下で「Forbidden Rite」をリンクさせたりするための手段が追加され、カードを売却する必要がなくなった

これはMonster AI Editor以外の新機能です。『Forbidden Rite』の説明文は、事実を反映するように修正されました。具体的には、指定されたポイントで行動が作成・変更された直後に「Anti-Ribbon」が適用されるという内容です。また、次のような誤った警告文は削除されました：`Multi-*` 必ずしもエラーになるわけではない。別々の出力でビルドしたところ、エラーは0件だった。[以前：`v2.84.20.1`] — Jarvis-MAGIC
- **📚`v2.84.20.1` — 調査：新しいオートアビリティ（武器／防具のスキル）の実装可能性 — すべてのルート + レシピ集（byte-recipe）。** Lane **Jarvis-MAGIC**。 **REVISION**（4桁目：doc/RE/リポジトリに追加される調査で、**動作は変更されません** — ライター／モジュール／バインディングには一切手を加えていません）。 マルチエージェント調査（3つのワークフローでファインダーを並列実行＋敵対的検証）により、FFX HD PC版で新しいオートアビリティを作成できるかどうか、またその方法を検証。 **結論：** はい。ただし、「新しい」には3つの意味があり、**データ駆動型 vs IDによるハードコーディング**という明確な区分がある。 (1) **フラグの組み合わせによる効果**はデータ駆動型であり、**IDAでのオフセット検証により実証済み**（`sub_79C610`/`sub_7861B0` OR-レコードのフィールドを累積する`0x6C` 俳優の**なし**`switch` ID**) → バイトを設定するだけで、どのスロットでもその効果を継承する； **完全なバイトクックブック** をデコードし、diff 処理して`a_ability.bin` shipado（要素`0x11-0x15` Fire`01`/Ice`02`/Thunder`04`/水`08`/Holy`10`; status touch=`0x16+slot=50`/strike=100; stat%`0x55`+`0x56`; 自動車/SOS`0x5A`+`0x10`; リボン`0x3C+slot=255`+`0x60`). (2) **実際に空いているスロット5つ 129–133 (`0x81-0x85`)** (全ゼロの日付) → テーブルを拡張せずに再利用。(3) **Grow >0x86:** 意外なことに、**エンジンは** 135番目のエントリを**受け入れる** (`sub_7AB890` **ファイルのヘッダー**からcount/rangeを読み込み、リテラルは使用しない`0x86`; ファイルサイズに合わせてサイズが調整されたバッファ); C#のガード3つ＋RT2＋バイトサイズの制限によってのみロックされる`0x25800` + 2つ目の装備メニュー構造`0xC8=200`. **ハードリミット：** ~31の能力はIDごとにハードコーディングされている（1ビットが`0x62/0x64/0x66`、C言語のハンドラー — センサー／ファーストストライク／カウンター／ピアシング／ブレイクリミッツ／キャプチャー／など）→ **バイト単位での再現不可**；新しいKINDの効果（ライフスティール／リフレクト％）は**DLLフック**経由でのみ（インフラ`DINPUT8` probe +`FfxHooksDll` PolyHook2 **検証済み**）またはexeパッチ。**ability-as-script (ATEL)** はフックフリー方式として否定された p

プレイヤー装備可能（バインディングギャップ）。3つの独立したストリームによるクロス検証済み＋**fahrenheit**オープンソースの構造体（バイト単位）。 **正直に言うと：** スロットの実際のゲームプレイを編集しており、すべてランタイム/フックによるもの = **RT2/LAB 保留中**；`a_ability.bin` 続く`reader+no-edit guard` 生産中（出荷承認なし）。ドキュメント：`docs/reverse/FFX_AUTOABILITIES_NOVAS_MASTER_2026-06-11.md` (目次／結論) +`FFX_NEW_AUTO_ABILITY_FEASIBILITY_2026-06-11.md` (静的) +`FFX_AUTO_ABILITY_NEW_VIA_HOOK_DLL_RUNTIME_FEASIBILITY_2026-06-11.md` (ランタイム/DLL) +`FFX_AUTOABILITIES_NOVAS_VIAS_E_FORMULAS_COOKBOOK_2026-06-11.md` （12の方法＋クックブック）。[前へ：`v2.84.20`] — Jarvis-MAGIC
- **`v2.84.20` — Monster AI Editor：『Forbidden Rite/Anti-Ribbon』および行動のヒューマンリーディングに関するバグ修正パッチをさらに10個追加。** Lane **Jarvis-MAGIC**。**累積パッチ**について`v2.84.10`: 表面を修正する`Forbidden Rite LAB` それは、実際の標準のほんの一部に過ぎなかった`writeChrProperty(target, field, value)` すでにサポートされていました。Anti-Ribbonのドロップダウンには、負の直接フィールドが一覧表示されるようになりました：`Poison`,`Petrify`,`Power Break`,`Magic Break`,`Armor Break`,`Mental Break`,`Berserk`,`Sleep(255)`,`Slow(255)`、さらに高度な技術に加え`Provoke`/`Threaten`、維持しつつ`Zombie`,`Confuse`,`Silence(255)`,`Darkness(255)`,`Curse`,`Doom` そして『Doom』のカウンター。`Zombie`/`Confuse`/`Silence`/`Darkness` 現在の基準では、これらは明示的に「RT2/インゲーム検証済み」としてマークされます。また、この拡張機能については、オペレーターが同じ直接ルートでインゲーム検証を行ったことが記録されます。`Death/KO` は、マップが`btlActorProperty` 説明する`isAlive`、ではなく`StatusDeath` クリーン；これには別のレシピ／ゲートが必要です。「BIBLE」と「SIN／Anti-Ribbon」プランが更新され、次のエージェントがすでに解決済みのブロックを再開できないようになりました。また、以下の最近のメモについてもバージョン管理が行われています。`Multi-*` vs`Sequencial-*`、ダイナミックサイクル、Dark Flan、Seymour Natusといった、未来のデザインに関する知見。**正直に言うと：**これは既存のMonster AI Editorのバグ修正・強化であり、`Forbidden Rite LAB`. [前へ：`v2.84.10`] — Jarvis-MAGIC
- **🧠`v2.84.10` — Monster AI Editor：10個のパッチの統合

バグ・UX・ガードレールに関する小さな修正のみで、新機能はなし。** Lane **Jarvis-MAGIC**。**累積パッチ**について`v2.84.0`: RT2/実運用での試行により、Monster AIのヒューマンインターフェースには、タブを追加するのではなく、契約内容の修正が必要であることが判明した。この変更により、サブタブが削除される`Monster AI Editor 2` ナビゲーションから、著作者を`Monster AI Editor` メインページ；大きなブロックを折りたたみ可能に；AEON/YUNALESCA/BIBLE/Live/アクションを人間が読みやすい位置に再配置；修正`Talvez` エントリポイント全体を再読み込みしないようにする場所；以下を追加する`Pare aqui` com`RET` 制御済み；ネイティブの証拠がない場合は、フェイクコンボを解除してストレートコンボに切り替える；バッジの取得を阻止する`forçada` 偶然に生まれる；YUNALESCAの状態のリークを解消；交換`NulAll` 現実の魔法に対して；魔法の詠唱を阻止する`Início` ランタイムがアクションをキューに入れなかった場合；コンディション／ワーカーのラベルを改善；ターゲットのバインド／最初のスキル／同一ターゲットを修正；Shredスタイルの計算済みターゲット＋HP減少のレシピを追加；ゲートを強化`AiScriptLab --ai3` local chance、linked rite、target recipe、computed target、stop-after については、実際のロックを維持し、`Multi-*` natural + Forbidden Rite、RT2は保留中。**正直に言うと：**これは既存のMonster AI Editorに対するバグ修正／セキュリティ強化であり、スコープ外の新しいライターを追加するものではない。[以前：`v2.84.0`] — Jarvis-MAGIC
- **🧩`v2.84.0` — UIの完全なレスポンシブ対応：スムーズなフレーム + すべてのウィンドウにおける「強制サイズ」のアプリ全体にわたるスキャン + 再利用可能なブレークポイントのインフラ。** **Jarvis-UI** レーン（横断的なスキャン — ほぼすべてのモジュール（MAGIC/MAP/HD）の UI に影響）。 オーナーの指示に応える：*「固定サイズはもう終わり。すべてレスポンシブで自動リサイズ可能に。パフォーマンスより見た目を優先し、処理負荷はユーザーのPCに任せる」*。**新しいインフラ：**`Styles/Responsive.cs` — 付随的性質`Responsive.Breakpoints` クラスを使ってルートにマークを付ける`narrow`/`medium`/`wide` 実際にレンダリングされた幅に基づいて、次のように行う`Style Selector` CSSの「メディアクエリ」として機能する。**Frame (`Main_Window`):** 固定幅290/320pxのサイドバー → カラム`Auto` com`MinWidth`/`MaxWidth`; 右側の検査官は（列`Auto`→0) ウィンドウの幅が狭い場合は、ワイド画面でのみ3列表示にする；

`MinWidth` 1280→1000; トップバー付き`ComboBox` 固定幅 →`MinWidth`; 有効なブレークポイント。 **アプリ全体のスキャン (71件中65件)`.axaml` マルチエージェント・オーケストレーションによって調整済み — ファイルごとに1つのエージェント、レイアウトのみの「外科的」編集）：**`ColumnDefinitions` ピクセル単位で 137→59 (−78);`StackPanel Orientation="Horizontal"` →`WrapPanel` (×26; ボタン／入力欄の列が切り取られるのではなく、分割されるようにするため、合計252個)；`ScrollViewer` ルートが破裂する可能性のある安全装置；`Viewbox` no`SphereGridCanvas`; WebViewのホスト (`*Embedded`) 伸ばした状態で；`TextWrapping` 欠けていた箇所；`Width`/`Height` 固定値 231→211 および 35→27（残りは固有のもの：アイコン、数値フィールド、列の`DataGrid` および、以下の範囲内のアライメント幅`WrapPanel` すでに引き潮になっているもの — カットしない）。**MINOR**（レスポンシブ対応の新機能＋UIの横断的な機能）。**正直に言うと：** 75画面すべてがコンパイルに成功（リリースビルド **エラー0**；エスケープ処理の`&` /`<` /`>` （グリーンビルドによって保証されている）および **なし`{Binding}`/`Click`/`x:Name` 変更されました**（レイアウトのみの修正）— ただし、**小さなウィンドウでの画面ごとの視覚的QAは、まだ手作業による確認が未完了です**（75種類の画面でアプリを実行していません。構造・コンパイルは確認済みですが、外観は未確認です）。 ロジック／保存／AI／ランタイム／RT2／Spira Forgeには影響しません。ファイル：`Styles/Responsive.cs` (新規) +`Modules/Main/Main_Window.axaml` + 65`.axaml` モジュール／コントロール／テンプレート。[前へ：`v2.83.0`] — Jarvis-UI
- **🧠`v2.83.0` — Monster AI Editor 2：独自のタブとして実装されたヒューマンモード。動作サーフェス、マルチセレクト、保守的なドラッグ＆ドロップ、圧縮感の少ないリサイズ、ヒューマンAEON、およびSIN/HP%ゲートの整合化が実現。** Lane **Jarvis-MAGIC**（Monster AI Editor / AI ツール）。オーナーからの要望に応える大きな転換を実現：Editor 2は単なる技術的なクローンから脱却し、実際のエンジン上に構築された「ヒューマン」ウィンドウへと進化しました。新しいサブタブ`Monster AI Editor 2` 開く`MonsterAiEditor2_Control`; エディタ 1 は DevKit/レガシーとして維持されます。画面 2 では、`Normal / Avançado / DevKit`: オペコードをダンプせずに動作を記録するカード、パネル`Editar esta ação`, YUNALESCA/BIBLE/SIN/AEON/Live/DevKit を人間の理解に基づいて再配置、AEON の人間の差分、セキュリティ／コンテキストのバッジ (`ramo condicional`,`outro worker`, `安全に動作する`

唯一の`), combo visual, seleção em lote, limpar lote, comandos batch-aware, drag/drop por alça para grupo consecutivo/autocontido, e layout responsivo que empilha áreas em vez de espremer a janela. Backend novo: `MonsterAiEditor_DataModel.HumanMode.cs`, `.Behavior.cs`, `.HumanDiff.cs`, `.InlineEdit.cs`, `MonsterAiEditor_ActionDrag.cs`, `MonsterAiEditor2_Control.axaml(.cs)` e reuso direto de `AiAutomation`/`AiValidator`/`AiScript_Diff`/`AppendGuardedAction`. Também corrige contratos antigos de HP%: `0x17=MUL`, `0x16=DIV`; SIN-010 deixa de ser bloqueado pelo bug velho e continua honestamente preso a payload/jump-slots/RT2/operator gates. Docs/protótipos versionados: plano de superfície total, pesquisa de acessibilidade humana, protótipo HTML e handoffs de agentes. **MINOR** (nova aba/capacidade de edição humana real). **Honestidade:** RT0/build/gates cobrem estrutura; efeito in-game e patches loose-file como o Skoll `m014` seguem prova RT2/manual. [anterior: `v2.82.0`] — Jarvis-MAGIC
- **🧠`v2.82.0` — Monster AI Editor：リスト上で直接行えるハイレベルなアクション編集（アセンブリを使わずに、バフやステータスの状態や値をその場で変更可能）＋上部に配置された定番のセッションボタン（保存／元に戻す／復元／更新）。** Lane **Jarvis-MAGIC** (Monster AI Editor)。所有者からの「*現在のAIは実際の知性を反映していない*」および「*上部に定番のボタンがない*」という不満を解決。 **正しい再定義（所有者からのフィードバックを受けて）：** **認識されたアクションのリストこそが、重要な「知能」そのもの**である — バフ（🛡）、ステータス（📊）、コマンド（⚔）； その利点は、**その場で編集可能**にすることであり、オペコードを表示することではありません（ワーカーごとに逆アセンブリを出力する最初のバージョンは、DevViewにより**冗長であるとして却下**されました）。 **インラインエディタ（新機能）：** バフ／ステータスを選択 → **ステータス／フィールド**（ドロップダウン）と**値**（入力欄）を変更 → **💾 適用** により、2つのオペランドを**バイト単位で**編集します`PUSHII` 既存のステートメントの(field + value)を保存し、`monster_*.bin` com`.prev.bak` （「保存」と同じパス）。ステートメントの場所：field instr in`CmdPushOffset`, value instr の直前の`CALLPOPA`; 両方が満たされている場合にのみ有効になります`PUSHII` リテラル（固定値、計算されない値）。 **セッションごとのChrome（card no t

opo):** 💾 保存 (`HasPendingEdits`) · ↶ 取り消し (`.prev.bak`/`CanUndoBackup`) · ♻ バニラ状態に戻す（2ステップ） · ⟳ 更新 — 既存のメソッドを基に（バーだけが欠けていた；その`Save` （アセンブラセクションに埋もれていた）。**MINOR**（新機能：リスト内でのインラインアクションの初回実装）。**適用範囲／正確性：** **バイトローカル**な編集（オペランド、同一サイズ、RT0対応）； **挿入/削除/並べ替え、およびワーカー間のアクションの移動は構造化されたまま（次回のカット）** — ワーカーのタイプ（MotionHandler/CombatHandler）はコードから推論され、固定されたラベルではない。 SINには触れない（パブリック書き込み用にBLOCKEDのまま）／runtime／RT2／Aurora／native-menu／Blitzball／Shop／Mix／Sphere／`Common`(ANIMA)/その他のレーン。ビルドリリース **エラー0**。ファイル：`Modules/MonsterAiEditor/MonsterAiEditor_DataModel.InlineEdit.cs` (新規) +`MonsterAiEditor_DataModel.cs` +`MonsterAiEditor_DataModel.Automations.cs` (1行) +`MonsterAiEditor_Control.axaml(.cs)`. [前へ：`v2.81.0`] — Jarvis-MAGIC
- **🔌`v2.81.0` — SIN Gate 6 LIVE glue：ステージオペレーター制御＋パイロットSIN-006のRAM読み取り専用検証 — 戦闘中にどのイメージが読み込まれているかを検証；実際のスワップは引き続き手動；SINはパブリック書き込みに対してBLOCKED状態を維持。** レーン **Jarvis-YU-YEVON** (MAGIC/SIN)。 RAM調査で実証された公正な分業に基づき、**SIN→probe**のグルーを構築：**SIN-006はスクリプトを拡張（+15命令、+2ジャンプスロット）し、拡張されたスクリプトはライブ領域にインプレースで注入できない** — モンスターのバッファはファイルの正確なサイズで割り当てられ（WorkerFileはAiFileの直後に配置される）、VMの構造体は元のカウントに基づいて事前にサイズ設定されている（`FFX_Atel_ComputeScriptChunksSize @0x86A220` /`ComputeScriptDataSize @0x86C050`); その後、拡大された画像は**RELOADパス**（オペレーターによるファイルの手動スワップ、ランブック C1-C6）を経由して取り込まれ、コラーが実行時に実際に行うのは**検証**のみで、書き込みは一切行わない。**`FfxLib/Ai/Sin`**: **`SinRt2LiveProbe`** (読み取り専用:`Status` liveness ゲーム/RAM/probe/バトル;`LocateMonster` RT2で実証済みのチェーンを再利用`MonsterAiEditor` —`ADDR_BATTLE_ACTIVE 0xD2A8E0` →`POINTER_BATTLE_ENEMY_LIST 0xD34460` → ストライド`0xF90` →`Id-0x1000` → `Ptr_script_chunks +0xF

78`; `ClassifyLiveAi` compara byte-exato o AiFile live contra as fatias ORIGINAL e EDITADA → `MatchesOriginal`/`試合（編集済み）`/`異なる`/`読めない`) e **`SinRt2LiveSession`** (`ステージ` operator-gated: re-roda elegibilidade RT2 + round-trip sandbox provado e persiste em `work/sin_rt2_live/` os artefatos `*.original.bin`/`*.sin006.bin`/`MANIFEST.txt` com SHA-256s + aim + efeito-de-tela; `VerifyLive` read-only com skip honesto sem jogo/batalha; guard de stage endurecido com separador — só sob `work/`). `SinSandboxApplyResult` ganha **`EditedMonsterBytes`** (contrato previsto no handoff do PENANCE: o RT2 reusa os MESMOS bytes provados, sem re-emitir). 3 flags novos: **`--sin-pilot-rt2-live-rt0`** (self-test headless: stage prova artefatos+SHAs+`+15`+parse-clean; recusas sem permissão/SIN-009/SIN-010 deixam ZERO arquivos; verify sem jogo → not-ready honesto sem throw; guarda de filesystem + cleanup), **`--sin-pilot-rt2-stage`** (comando do operador, mantém os artefatos) e **`--sin-pilot-rt2-verify`** (comando do operador, read-only: qual imagem está na RAM da batalha — `試合（編集済み）` prova só o LOAD estrutural; o efeito na tela continua veredito humano). **MINOR** (capacidade NOVA executável: camada LIVE glue + 3 flags). **Escopo/honestidade:** nenhum caminho de escrita em arquivo real/jogo/RAM existe nesta camada; staging não é apply; SIN **continua BLOCKED para escrita pública**; SIN-009/010 continuam fora; `0x16/0x17` intocado. Build 0 erros; `--sin-pilot-rt2-live-rt0` + os 8 gates anteriores todos **PASS**. [anterior: `v2.80.0`] — Jarvis-YU-YEVON
- **🕹️`v2.80.0` — SIN Chain Builder Gate 6: RT2 ゲーム内パイロット PREFLIGHT オペレーターゲート — SIN-006 パイロットをシミュレート、RT2 は実行されません；実際のステータス = RT2-pending；SIN はパブリック書き込みに対して BLOCKED のままです。** レーン **Jarvis-YU-YEVON** (MAGIC/SIN)。SIN Chain Builderの**Gate 6**を開く：実証、 **ヘッドレスかつグリーンライイングなし**で、サンドボックス（Gate 5/PENANCE）ですでに検証済みのカットアウト SIN-006 が、**オペレーター主導の RT2 パイロットで実行可能**であることを証明する — 実行中のゲームには一切触れることなく、`dinput8 probe` あるいは実際のアーカイブにおいて、**ゲーム内での効果については言及しない**。*「最小ケース SIN-006 は操縦可能な状態です R」*と回答する。

「T2の安全性について、オペレーターはどのような点に注意すべきか？」* — 画面上の確認作業は依然として**人的な工程**である（そのため、結果は**RT2-pending**となり、自動でPASSとなることはない）。**`FfxLib/Ai/Sin`**: **`SinRt2PilotGate`** (`SinRt2Eligibility` — RT2の適格基準は、サンドボックスよりも**厳格**である：(1) 許可`AllowRt2InGamePilot` 明示的であり、かつ**区別された**`AllowSandboxApply`; (2) **allowlist RT2** 内の ID = 今日は **のみ`SIN-006`**; (3) **本質的な形状** ベルトとサスペンダーの組み合わせによる誤表示の防止：単一の結び目、`Trigger=OnTurn` 解決済みであることが証明され、`Condition=Always` (**HP%なし/`0x16`-`0x17`**)、すべて`Action` =`GrantChrProperty` **Self 0xFFF3**（**コマンドペイロードなし**））、**`SinRt2PilotSession`**（**preflight**のオーケストレーター：RT2の適格性チェックを実行し、**検証済みのサンドボックスのラウンドトリップを再利用**）`SinSandboxApplySession` （コピー → バックアップ → 発行 → 保守的な差分 → バイト単位で同一の復元）は、対象（ワーカー／エントリポイント）と確認すべき画面上の効果を再現し、**その後** — ライブでの適用と監視はオペレーターの作業であり、 **ここでは実装されていない**）、そして **`SinRt2PilotResult`** (`SinRt2Outcome` `Blocked`/`Skipped`/`SandboxProofFailed`/`PreflightReady` +`SinRt2OperatorVerdict` デフォルト **`Pending`** + テンプレート;`RealApplyDone`/`Rt2Confirmed`/`PublicApplyAllowed` = **設計上NO**）。**適用範囲（SIN-006のみ）：** SIN-006 +`AllowRt2InGamePilot=true` + コーパス → **PREFLIGHT-READY** (`m201`, OnTurn ワーカー 0/ep 2, 差分 **+15 ~0 -0**, **バイト単位で同一の復元**, コーパス/コピーの SHA は変更なし`B4C0FB90…012F`, 判定 **保留中**, RT2/RealApply/PublicApply **NO**); **許可なし**の場合、SIN-006までは **BLOCKED** となる（オペレーター制御、RT2の許可はサンドボックスとは別扱い）； **SIN-009**（コマンドペイロード候補）および **SIN-010**（HP% /`0x16`-`0x17`) = **RT2対象外**（allowlist + shapeによりブロック）。新しいゲート **`--sin-pilot-rt2-rt0`**: 4つのケースを実行し、RT2-pendingの不変条件を検証し、**ファイルシステムの保護**（`work/`, なし`.prev.bak`/`monster_*.bin` 出力ディレクトリでは、すべての実際のフィクスチャが読み取り専用でハッシュも変更されておらず、終了時にはパイロットディレクトリがクリーンな状態になる）また、**本番環境への適用パスは存在しない**（`SinRt2PilotSession` 実際のファイルには書き込みを行わず、prも実行しない

obe）。**MINOR**（実行可能なNOVA機能：RT2プリフライト層＋ゲート）。 **適用範囲／正確性：** SIN **は引き続き公開書き込みがBLOCKED** — *Gate 6のプリフライトは、管理されたRT2パイロットを検証するものであり、テンプレートギャラリーを検証するものではない*； **RT2検証済みではなく、公開ボタンでもない**；`Rt2Confirmed=NO`/`RealApplyDone=NO`/`PublicApplyAllowed=NO`. **修正しない**`0x16/0x17`、**SIN-009/010**には**手を加えない**でください。また、**writer/save/batch/UI/ボタン**については`MonsterAiEditor`; **再生しない**`monster_*.bin` real/game/probe/Aurora/native-menu/Blitzball/Shop/Mix/Sphere/`Common`(ANIMA); Gate 2-5の検証済みスタックを再利用。ビルドエラーなし；`--sin-pilot-rt2-rt0` +`--sin-sandbox-rt0` (5番ゲート) +`--sin-aeon-preview-rt0` (4番ゲート) +`--sin-validate-rt0` (ゲート3) +`--sin-dryrun-rt0` (ゲート2) +`--aicmdmeta-rt0` +`--spiraatlas-rt0` +`--aiasm-rt0` すべて **PASS**。ドキュメント：`docs/ai/SIN_YU_YEVON_RT2_INGAME_PILOT_RESULT_2026-06-10.md` +`docs/ai/SIN_YU_YEVON_RT2_OPERATOR_RUNBOOK_2026-06-10.md` +`docs/ai/HANDOFF_YU_YEVON_SIN_AUTHORING_PROMOTION_NEXT_2026-06-10.md`. [前へ：`v2.79.0`] — Jarvis-YU-YEVON
- **🛡️`v2.79.0` — SIN Chain Builder Gate 5: バックアップ／適用 SANDBOX オペレーターゲート — 使い捨てのコピーに適用し、バイト単位で同一のものを元に戻す；SINはパブリック書き込みのためにBLOCKED状態を維持する。** Lane **Jarvis-PENANCE** (MAGIC/SIN)。 SIN Chain Builderの**Gate 5**を開く：ある`SinApplyPlan` （Gate 3/NEMESIS）で検証され、AEON（Gate 4/OMEGA）によってレビューされたものは、**サンドボックス／管理されたコピー上で適用および元に戻す**ことができます。ゲーム本体やユーザーの実際のファイルには一切触れることなく、 **RT2も公開ボタンも使用せずに**。*サンドボックスのバックアップ／適用は、公開オーサリングではありません。* **サンドボックス限定の新しいクラスは**`FfxLib/Ai/Sin`**: **`SinSandboxApplyGate`** (`SinSandboxEligibility` — 8つの読み取り専用条件：構造的に有効 ·`ApplyAcceptable` false · 許可`AllowSandboxApply` 明示的かつ独立した · AEON ADDED-only · **スキャフォールディング外でクリア可能なクリティカル・ブロッカーなし**、ゲート5が解決するブロッカーを区別するルール（`plan-blocker`/`rung-ladder`) レアル（ペイロード候補／ブロック済み、`divmul-integrity`,`jump-slots`, step-blocker)), **`SinSandboxApplySession`** (オーケストレーター：コピー → 書き込み前のバックアップ → 再発行)

l コピーのみ → 実際の差分 → 変更されていないオリジナルを確認 → 復元 → バイト単位で同一)、**`SinSandboxBackup`** (`.prev.bak` コピーの + プレイメージのハッシュ +`Restore`), **`SinSandboxRestoreVerifier`** (SHA-256 + バイト比較) および **`SinSandboxApplyResult`**（検証可能な結果 + 出力テンプレート）。**実データを用いた検証済みコーデックによる適用：**対象となるレシピについては、**実データの**使い捨てコピー**（コーパスの読み取り専用版 →`work/`), **を介して直線状の構造を組み立てる`AppendGuardedAction`(永遠の真実を守る`PUSHII 1`)** — コードの末尾に**追加する**（既存のオフセットは変更されない）唯一のクリーンで自己再配置可能なメソッドであり、`SpliceAiFileIntoMonsterGrow`, 再読み込み（クリーンな再解析 = rung`offline-emittable`), 実行 **`AiScript_Diff.Compare(original, edited)` REAL**（対象となる**ADDED**ブロックのみ、**0 modified / 0 removed** = ラング）`AEON-reviewed`（ドリフトなし） +`AiValidator.ValidateRebuilt` (rung`AiScriptLab-clean`), そしてその後に初めて **コピーに記入する**（`.prev.bak` = rung`backup-ready`). **3つのパイロットレシピ（正直な判断、グリーンフォースなし）：** **SIN-006**（ベヴェルのベール、1ターン目の自己バフ；ターゲットは自己検証済み、**コマンドペイロードなし**、0x16/0x17なし）＝**唯一の適格なケース** → サンドボックスで実際に適用（`m201`, OnTurnは以下を通じて解決されました`AiWorkerMapping.TryResolveCombatOnTurn`, diff **+15 ~0 -0**, **バイト単位で同一の復元**, オリジナル／コーパスのハッシュ値は変更なし); **SIN-009**（メイスターの指令；ペイロード **candidate**）＝ **BLOCKED**（保守的判断）（使い捨てのコピーであることは、不正なペイロードを作成する言い訳にはならない；決定は文書化済み）； **SIN-010** (ファープレーン・トール、HP%) = **BLOCKED** により **`0x16` DIV 対 目標HP%乗算** (`divmul-integrity`) — *0x16/0x17は別のレーン専用のPATCHであり、ここでは決して修正されない*。さらなる証拠：**許可がない限り`AllowSandboxApply`、SIN-006まではBLOCKED**（オペレーター・ゲート）となる；**予期せぬdiff（改ざん）は、同じ保守的な述語によって**拒否される**（`+0 ~1 -0 → conservative=False`); **原文は決して書かれていない** (`AppliedToOriginal=NO`, コーパス内の参照コピーおよび実際のソースのハッシュによる検証）。新しいゲート **`--sin-sandbox-rt0`**: 3つのレシピを実行し、バックアップ／復元／分離のテストを行い、**ファイルシステムの保存**（外部への書き込みなし）

から`work/`, なし`.prev.bak`/`monster_*.bin` 出力ディレクトリ内では、すべての実際のフィクスチャが読み取り専用でハッシュ値も変更されておらず、終了時にはサンドボックスディレクトリがクリーンな状態になる（残留物なし、コミットは一切行われない）。 **MINOR**（NOVAの実行機能：サンドボックス適用レイヤー＋ゲート；1つのコピー内で「オフライン発行可能」「AiScriptLabクリーン」「AEONレビュー済み」「バックアップ準備完了」の各段階を通過）。 **適用範囲／正確性：** SIN **は引き続き公開書き込みに対してBLOCKED** — ゲート5はサンドボックス／コピーにのみ適用され、**RT2ではなく、公開ボタンでもない**；`PublicApplyAllowed=NO`/`Rt2=NO` 仕様上。public/save/runtime/RT2/UI/ボタンにはwriterを配置しないでください。`MonsterAiEditor`; 触らないでください`monster_*.bin` real/Aurora/native-menu/ブリッツボール/ショップ/ミックス/スフィア/`Common`(ANIMA); 再利用`SinDryRunPlanner`/`SinPlanValidator`/`SinAeonDiffPlanner` +`AiScript_File.AppendGuardedAction`/`SpliceAiFileIntoMonsterGrow`/`AiScript_Diff`/`AiValidator` （往復運賃はすでに345/345と確認済み、`--aiasm-rt0`). ビルドエラーなし;`--sin-sandbox-rt0` +`--sin-aeon-preview-rt0` (4番ゲート) +`--sin-validate-rt0` (ゲート3) +`--sin-dryrun-rt0` (ゲート2) +`--aicmdmeta-rt0` +`--spiraatlas-rt0` +`--aiasm-rt0` すべて **PASS**。ドキュメント：`docs/ai/SIN_PENANCE_BACKUP_APPLY_SANDBOX_RESULT_2026-06-10.md` +`docs/ai/HANDOFF_PENANCE_SIN_RT2_PILOT_NEXT_2026-06-10.md`. [前へ：`v2.78.1`] — Jarvis-PENANCE
- **🎨`v2.78.1` — UIの磨き上げ：一貫した配色（Fluentの「茶色」を排除）＋Monster Editor／ナビゲーション／Prize Tableの洗練。** Lane **Jarvis-RIN**（UIの磨き上げ）。**色：** Fluentのクローム部分を塗り直す（`Expander`/`ListBox`/`ListBoxItem`/`TabItem`) ＋ 4つの共有フィールド用ControlTemplates（`Property`/`PropertyBool`/`GameIndex`/`Loot`) + スタジオのクールカラーパレット用のオートセーブトークン — **アプリ全体**のデフォルトの温かみのあるグレー／「茶色」と枠線を削除する`AliceBlue` （FluentのThemeDictionaryではリソースのオーバーライドが無視されていたが、グローバルスタイルではこれが改善された）。**Monster Editor：** スタイル`Label`/`Separator` スコープ、ヘッダー`cardTitle` (ステータス+戦利品)、均一なタイルに整列されたステータスボックスのグリッド、戦利品のヘッダーは太字20ポイント →`cardTitle`. **ナビゲーション：** 新しいハブ **「エンカウンター＆フォーメーション」**（読み取り専用エンカウンターテーブル＋書き込み可能なフォーメーションエディタ、サブタブ）； **「Spira Forge」→「マップ＆シーン」**（ナビゲーション外のフィールドハブ、

 （コード内に残す）；テキスト／参照＋ブリッツボールをCore Authoringに移動し、カード**「Next Wave」を削除**（`&` 「マップ＆シーン」というタイトルのバグ（**すべてのレーンのリリースビルドを破壊していた**もの）。**賞品表：** 3段階のツリー`Expander` achatada (Draw inline; 「抽選N」は、drawが1回以上の場合にのみ via`ShowLabel`)、枠のないプライズ行にファミリーストライプ＋ホバー効果、コンペティションはデフォルトでフィルターなしで開く、オッズは`ScrollViewer` 本体 (MaxHeight 400) + チップ`pillWriter` 「プレミアムなし」の琥珀、`Detail` 短縮版、チェーン／誠実さが移動したスリムなヒーロー`Expander` 「About」が折りたたまれています。**Prize Atlasの整合が完了：**オッズに関する記述には、「別ファミリー／1:1でペアリングされない／賞金に対するパーセンテージなし」という注記が付いています。 **PATCH**（既にリリース済みの機能に関するビジュアルの微調整；疑問解消→PATCH）。 **プレゼンテーション専用：** ライター／パーサー／バインディングには一切触れない（`Value` TwoWay、`IsPrize`,`EditSession.*` など（逐語的に）；ツリー＝それらに関するビュー`PrizeStructRow` (DTOなし)。ビルドエラーなし；`--blitzball-prizestruct-rt0` +`--spiraatlas-rt0` **PASS**。[前：`v2.78.0`] — Jarvis-RIN
- **🌌`v2.78.0` — SIN Chain Builder Gate 4: AEON diff プレビュー`SinApplyPlan` 検証済み（読み取り専用） — 差分を表示するのみで、適用は行わない；SINは書き込みに対してBLOCKED状態のままである。** Lane **Jarvis-OMEGA** (MAGIC/SIN)。SIN Chain Builderの**Gate 4**を開く：`SinApplyPlan` (Gate 2/SHINRYU) はすでに`SinPlanValidator` (Gate 3/NEMESIS) を行い、**もしそのプランが実際のスクリプトまたは制御されたスクリプトに対して発行された場合にAEONが示すであろうdiff**を生成する――**モンスターをロードせず、実際のワーカーをdiffせず、`Rebuild`/`Splice`/`AiScript_Diff`、バックアップもディスクもなく、何も適用しない状態で**。ただ一つの質問に答えるだけだ：*「この検証済みのプランが発行された場合、AEONにはどのような差分が表示されるか？」*。**内の新しいクラス`FfxLib/Ai/Sin`**: **`SinAeonDiffPreview`**/**`SinAeonDiffPreviewStep`**/**`SinAeonDiffPreviewRow`**（～の語彙を反映している）`AiScript_Diff`:`Added`/`Modified`/`Removed`/`Unchanged`, +`Context` マーカー線用`;` リスト内 — 表示されているが、カウントには含まれていない）、**`SinAeonDiffPlanner`** (`Plan(SinApplyPlan, SinPlanValidationResult)` →`SinAeonDiffPreview`; プランと検証結果のみを読み込む（どちらもread）

-only; 便宜上のオーバーロード`Plan(SinChainRecipe)` チェーン全体を回す）と **`SinAeonPreviewFormatter`**（決定論的テキスト）。**正直なモデル：**ロード済みのモンスターが存在しないため、実際のbefore-imageは存在しない → 計画されたすべての命令は、**`synthetic/control fixture`** (`vanilla/current: <none at planned insertion point>`); **MODIFIED == 0** および **REMOVED == 0** は設計上決まっている（これを解決するには、実際のワーカー＝Gate 5 の適用／バックアップが必要となる）。Gate 4 は **Gate 3 を順守する**：`StructurallyValid` バリデータから、`ApplyAllowed` これは**false hard-wired**であるため、どの候補もauthoring-readyにはならず、**DIV/MULの検出結果（`0x16`/`0x17`) は読み込まれますが、修正はされません** — HP% レシート (SIN-010) はブロックを文字通りそのまま印刷します`Blocked/warning: unresolved 0x16 DIV vs intended HP% multiply semantics. / No public apply. / No RT2 proof.` そして、ゲート3は引き続きブロッカーをロードし続けている`divmul-integrity`. **3つのパイロット：** SIN-006（リニア、12 ADDED）および SIN-009（リニア、3 ADDED）＝ *構造的に有効、適用ブロック*； SIN-010 (GuardedAction, 16 ADDED) = 同上 **+ 必須のHP%ブロック**。新しい読み取り専用ゲート **`--sin-aeon-preview-rt0`**: 3人のパイロットを配置し、プレビューを生成して、確認する`ApplyAllowed=false`, 合成diff-target、ADDED≥1/MODIFIED=0/REMOVED=0、候補なし→authoring-ready、決定論的プレビュー、SIN-010にDIV/MULブロックが存在 + **ファイルシステムのバックアップ** （出力ディレクトリの「前」と「後」のスナップショット → **新規ファイルなし、`.prev.bak`, なし`monster_*.bin`**). **MINOR**（実行可能な新機能：AEON diffプレビュー + gate）。 **適用範囲／正確性：** SIN **は書き込みに対して引き続きBLOCKEDの状態** — *Gate 4はdiffプレビューを表示するが、diffは適用しない*； *「Clean for DESIGNはWRITINGに対してアンロックされていない」* — また、クリーンなdiffプレビューであっても書き込みのロックは解除されない。 writer/saveは実行しない/`Rebuild`/`Splice`/AEON-real/backup/RT2/ボタン/UI; タップしない`monster_*.bin`/runtime/Aurora/native-menu/Blitzball/Shop/Mix/Sphere/`Common`(ANIMA) も、`MonsterAiEditor`; 読み取り専用`FfxLib/Ai/Sin/*`. ビルドエラーなし;`--sin-aeon-preview-rt0` +`--sin-validate-rt0` (ゲート3) +`--sin-dryrun-rt0` (ゲート2) +`--aicmdmeta-rt0` +`--spiraatlas-rt0` +`--aiasm-rt0` (AiScriptLab) すべて **PASS**。ドキュメント: `docs/ai/SIN_OMEGA_AEON_DIFF

_PREVIEW_RESULT_2026-06-10.md` + `docs/ai/HANDOFF_OMEGA_SIN_BACKUP_APPLY_GATE_NEXT_2026-06-10.md`. [anterior: `v2.77.0`] — Jarvis-OMEGA
- **🔱`v2.77.0` — SIN Chain Builder Gate 3：AiScriptLabのバリデーションブリッジ`SinApplyPlan` (読み取り専用) — プランを検証するが、適用は行わない。SINは書き込み不可（BLOCKED）のまま。** Lane **Jarvis-NEMESIS** (MAGIC/SIN)。SIN Chain Builderの**Gate 3**を開く：`SinApplyPlan` SHINRYU（Gate 2）のプレビュー版をAiScriptLabに対応した形でチェックしています**/`AiValidator`**、まだ**モンスターを召喚しておらず、`Rebuild`/`Splice`、AEON diffなし、ディスクなし、何も適用しない**。 ただ一つの質問に答えてください：*「このプレビュー限定のプランは構造的に許容可能か（生成されるバイトコードはウェルフォームである）、そして、これを『apply』から阻む正当なブロック要因・警告・エラーは何か？」*。新しいクラスは**`FfxLib/Ai/Sin`**: **`SinPlanValidator`** (`Validate(SinApplyPlan) → SinPlanValidationResult`, は、の静的テーブルのみを読み込みます`AiScript_File` +`AiStackModel` + プラン）、**`SinPlanValidationResult`**（の語彙を反映している）`AiValidationReport` 計画レベルでは：`Errors`/`Blockers`/`Warnings`/`Infos`,`StructurallyValid` = エラーなし、`ApplyAcceptable` = **Gate 3ではデフォルトでfalse**）および **`SinAiScriptLabBridge`**（単一のストリームに対する低レベルの検証については、`AiInstruction`, なし`AiScriptFile`). **検証（オフラインのSÓLIDOサブセット、`AiValidator` （米国）：** (1) すべてのオペコード ∈ 検証済みの48個（`AiScript_File.IsKnownOpcode`); (2)`HasOperand` サイズ規定に合致する`0x80` (`IsOperandBearing`) — そうでなければ`Emit()` ずれる； (3) 命令ごとのRT0 (`Emit()` 同じオペコード＋オペランドに対して再デコードする）；（4）ステートメントごとのスタックバランス調整を`AiStackModel` （線形ボディはnet 0で終了する；ガードがD7/POPXNCJMP用に**正確に1つのbool**を残す）。 **3つのパイロットレシピの判定：** すべて **構造的には有効だが、apply-BLOCKED**（プレビューのみ） — SIN-006/SIN-009（リニア）はスタックがネット0； SIN-010（HP-guard）は、ガードが**正確に1つのbool**を残し、アクションがnet 0にある。 **SHINRYUのDIV/MULに関する発見について明示的に対処（NEMESISの決定＝期待されるBLOCKERとして維持、修正しない）：** 方向性は証明済み（`0x16=DIV`/`0x17=MUL

` por censo de 345 monstros + IDA `FFX_Atel_InterpretWorkerOpcodes@0x864180` + FFXDataParser), então o `MUL` do `AiSnippetLibrary` ligado a `0x16` é bug confirmado — mas a **reconciliação completa** (corrigir a constante + re-validar TODO consumidor: `MonsterAiEditor`, `AiAutomation`, `--aiasm-rt0`/`--ai2`/`--ai3` + re-provar RT0/RT2) é um **PATCH dedicado fora de uma gate de validação read-only** (e RT2 é proibido pro Gate 3). Insight estrutural que prova por que tem de ser BLOCKER e não Error: `AiStackModel` dá **net -1 pra DIV E pra MUL** → a pilha balanceia idêntico, o byte re-parseia, e **só o RT2 pega a aritmética errada**. O validador surfa isso como **Warning + Blocker** com a evidência toda, e o gate confirma que a receita HP% **continua blocked** e que **NÃO foi corrigida silenciosamente** (o planner ainda emite `0x16`, `AiSnippetLibrary` intocado). **Extensão aditiva (não-quebra):** `SinPlannedStep` ganhou `GuardOps`/`BodyOps` (as `AiInstruction` cruas que o planner já calculava) pra o validador inspecionar **exatamente** o que o planner produziu (fonte única; default vazio → toda construção do Gate 2 segue compilando e o `--sin-dryrun-rt0` continua PASS). Novo gate read-only **`--sin-validate-rt0`**: valida os 3 pilotos e assere estruturalmente-válido + apply-NÃO-aceitável + blockers honestos + escada de promoção insatisfeita + nenhum candidate→authoring-ready + (SIN-010) blocker DIV/MUL presente e não-corrigido; validação determinística. **MINOR** (capacidade NOVA executável: validador + gate). **Escopo/honestidade:** SIN **continua BLOCKED para escrita** — *Gate 3 valida planos, não aplica planos*; *"Clean for DESIGN não é unlocked for WRITING"* — e estrutura-limpa também não destrava escrita. NÃO faz writer/save/`リビルド`/`Splice`/AEON diff/backup/RT2/botão/UI; NÃO toca `monster_*.bin`/runtime/Aurora/native-menu/Blitzball/Shop/Mix/Sphere/`Common`(ANIMA) nem o `MonsterAiEditor`. Build 0 erros; `--sin-validate-rt0` + `--sin-dryrun-rt0` (Gate 2, sem regressão) + `--aicmdmeta-rt0` + `--spiraatlas-rt0` + `--aiasm-rt0` (AiScriptLab, 346/346 RT0 no corpus real) todos **PASS**. Docs: `docs/ai/SIN_NEMESIS_AISCRIPTLAB_VALIDATION_RESULT_2026-06-10.md` + `doc

s/ai/HANDOFF_NEMESIS_SIN_AEON_DIFF_GATE_NEXT_2026-06-10.md`. [anterior: `v2.76.0`] — Jarvis-NEMESIS
- **🐉`v2.76.0` — SIN Chain Builder Gate 2: ドライラン／プレビュープランナー (`SinApplyPlan`) — プレビュー専用、SINは書き込み不可のまま。** Lane **Jarvis-SHINRYU** (MAGIC/SIN)。 SIN Chain Builderの**Gate 2**を開き、YEVONの仕様（Gate 1、設計）を**実行可能なプレビューレイヤー**に変換します： ユーザーはAIの意図を構築し、プランナーは**生成される結果を正確に表示**します — 適用、保存、モンスターへのバイトコード書き込み、またはパブリックボタンの作成は行われません。新しいネームスペース **`FfxLib/Ai/Sin`**:`SinChainRecipe` (具体的なIR：トリガー／条件／アクション／コンボ／ペイロード／ターゲット)、`SinApplyPlan` （閲覧可能な読み取り専用プラン：計画された手順、指示、分岐／スタック形状、証拠、ブロック要因、昇格ラダーのゲート、`ApplyAllowed=false` ハードワイヤード),`SinDryRunPlanner` (**読み取り専用**の解除：検証済みのスニペットを選択します。`AiSnippetLibrary` そして **テンプレートをメモリ上で展開** する — 呼び出さない`Rebuild`/`AppendGuardedAction`/splice、モンスターを召喚しない、動作しない`AiValidator`、電話はかけないでください`AiAutomation`),`SinDryRunPreview` （決定論的テキストの連続化）および`SinPilotRecipes` （必須の3つのパイロットレシピ：SIN-006 ベヴェルのベール＝ターン1の自己バフ；SIN-009 メイスターの指令＝強制／実行コマンド；SIN-010 ファープレイン・トール＝HP<50%時のガードアクション）。 **ペイロードの正直な評価** (`SinDryRunPlanner.ClassifyPayload`, 経由`AiCommandMetadataCatalog.IsKnownAiPerformOperandCategory`): アイテム/GATTA (`0x2xxx`) および非AI = **blocked**; AI実行コマンド = **candidate** (決して「proved」とはならない — Firagaでさえも`0x3049`、そのRT2はオペランドスワップであり、SINが承認したブロックではない）。**発見（ドライランですぐに判明）：** 検証済みのスニペット`guard-hp-below-pct-force-cmd` **オペコードを発行する**`0x16` （証明済みの表によるDIV**）`0x16=DIV`/`0x17=MUL`) ここで、HP% 言語は **MULTIPLY** を意図している — 潜在的な不一致が`AiSnippetLibrary` (定数`MUL` は～に関連している`0x16`); **プレビューで警告/ブロッカーとしてフラグが立てられており、ここでは修正されていません**（エミッターの修正はプレビュー限定の範囲外であり、スニペットのRT0/RT2再検証が必要です）。新しい読み取り専用ゲート **`--sin-dryrun-rt0`**: 3人のパイロットを配置し、生成する

 決定論的なプレビューを行い、何も保存／書き込みが行われていないことを確認し、`ApplyAllowed=false`, rung=preview-only、正当なブロック要因が存在、昇格の段階が100%未達成、かつ**authoring-readyに昇格した候補者はいない**。 **MINOR**（実行可能な新機能：planner dry-run + gate；YEVONからの引き継ぎに基づき、実行可能な機能を持つという理由だけでREVISIONから除外）。 **スコープ／整合性：** SIN **は書き込みに対して引き続きBLOCKED** — ゲート2はプレビュー／ドライランであり、オーサリングではない； *「Clean for DESIGNはunlocked for WRITINGではない。」* writer/parser/runtime/Aurora/native-menu/Blitzball/Shop/Mix/Sphere/には一切触れない。`Common`(ANIMA)/save でも`MonsterAiEditor` (UI Preview = Gate 3+); 読み取り専用`FfxLib/Ai/*`. ビルドエラーなし;`--sin-dryrun-rt0` +`--aicmdmeta-rt0` +`--spiraatlas-rt0` +`--aiasm-rt0` (AiScriptLab) すべて **PASS**。ドキュメント：`docs/ai/SIN_SHINRYU_DRY_RUN_EMITTER_RESULT_2026-06-10.md` +`docs/ai/HANDOFF_SHINRYU_SIN_AISCRIPTLAB_GATE_NEXT_2026-06-10.md`. [前へ：`v2.75.0`] — ジャービス・シンリュウ
- **🏐`v2.75.0` — ブリッツボールの賞品表がツリー形式に：リーグ／トーナメント → 1位／2位／3位／得点王 → 抽選 → 賞品（＋抽選検出機能が再承認済み）。** Lane **Jarvis-NIMROOK**（賞品管理）。Prize Table（459の賞品インデックス + 390のオッズが`bltz0200.ebp`) カテゴリごとの平面的なアコーディオン形式ではなくなり、**3階層のRE検証済みツリー**となります： **Competition** (リーグ/トーナメント) → **Award** (1位/2位/3位 + **Top Scorer** — 順位に関係なく、最多得点者を擁するチームに贈られる賞) → **抽選N** (1つの`switch GetRandomInRange`) → 編集可能な賞品バケット。パーサーの新機能`BlitzballPrizeStructure_File.FindRollSwitchStarts`/`DrawStartFor` (読み取り専用、バイトセーフ)：各抽選の上限は「call」です`GetRandomInRange` (オペコード`B5 A6 00`) — **68回の抽選結果**が`bltz0200.ebp` 実収（459の賞金サイトすべてが割り当て済み；第1ロール前の孤児1件）、ゲート`--blitzball-prizestruct-rt0` モデルを検証するために拡張した。**正直に言うと：**オッズは依然として独立したグループ（賞金と紐づいていない）となっている。なぜなら、抽選において、賞金の数 ≠ ロール区間の数 だからである（データ検証済み、67/68） — 「この賞にはX％の確率がある」と主張することは、証拠をでっち上げることになる。＋ **タブ名の変更`Atlas`→`Pr

ize Atlas`** + **reconciliação do `ブロックされた`**: o Prize Atlas (read-only) dizia "liga/torneio/artilheiro = blocked (runtime/save)"; o texto agora explica que isso vale **só pro prêmio que caiu no save** — a atribuição + odds são game-file editáveis (aba Prize Table, RT0 provado) e o reward = aba Prize Pool (takara). + legenda de cadeia (Prize Table escolhe o índice → Prize Pool diz o reward) nas abas de prêmio. **MINOR** (capacidade NOVA: API de estrutura de sorteio RE-provada no parser + 1ª árvore hierárquica de prêmio). Escopo: writer/`EditSession`/`SetPrizeIndexAt`/`SetThresholdAt` **intocados** (só leitura nova + apresentação); não toca save/runtime/SIN/`Common`/provider Atlas nem o código de outras lanes (em cima do baseline commitado do RIN v2.74.x). Build 0 erros; `--blitzball-prizestruct-rt0` (68 draws) + `--spiraatlas-rt0` + roster/recruit/treasure RT0 todos PASS. Doc: `docs/ai/HANDOFF_NIMROOK_BLITZBALL_PRIZE_UI_DIAGNOSIS_2026-06-10.md`. [anterior: `v2.74.1`] — Jarvis-NIMROOK
- **🪗`v2.74.1` — サイドバーのセクションを折りたたみ可能に + セッション間で状態を保持。** Lane **Jarvis-RIN** (UX)。 サイドバーの各セクションカード（Core Authoring · Spira Forge · Live Tools · Next Wave · Extras · ???）は、**クリック可能なヘッダー**になりました（カードの見た目は維持されています：`sectionLabel` +`cardTitle` + シェブロン）で、ボタングループを**折りたたんだり展開したり**できます。各セクションの折りたたみ状態は、新しい機能を通じて**保存され、セッション間で保持されます**。`Services/SidebarState_Service` (`LocalAppData/FFXProjectEditor/sidebar-state.json`、の慣例に倣って、`last-project.txt`) — セクションを編集しない場合は、そのセクションを閉じることができます。エディタを再起動しても、そのセクションは閉じたままになります。コンストラクタで適用されます (`ApplySidebarState`) であり、トグルに記録されている (`SidebarSection_Toggle`). **加法**クラスにおける`StudioTheme.axaml` (`Button.sectionHeader` 透明／タイトルにホバー時にティール色のカーソル（手形）が表示される +`TextBlock.sectionChevron`); シェブロン ▾（開いた状態） / ▸（閉じた状態）。**表示のみ：** の6枚のカードを再構成します。`Main_Window` (ヘッダー +`StackPanel` （折りたたみ可能と指定）＋ 1 つの利便性のための永続化サービス（障害＝サイレント、展開状態で開く）。writer/parser/runtime/save/provider/その他のレーンには影響しない。**PATCH**（利便性／UX；

 確認のため→PATCH）。ビルド結果：**エラー0件／警告361件**；v2.74.1.0でエディタを再起動。[前回：`v2.74.0`] — Jarvis-RIN
- **🗂️`v2.74.0` — 統合されたナビゲーション：4つの新しい集約ハブ（バトルコマンド、アイテム、スフィアグリッド、テキスト／リファレンス）＋コンポーネント`SubTabHub` 再利用可能 + シンプルなサイドバー。** レーンAIの第2弾 **Jarvis-RIN**（Halysonによる大量のメモ）。新しい汎用コンポーネント **`SubTabHub_Control`** (`Modules/SubTabHub`): FFX風のサブタブ（再利用`tabPill`/（ブリッツボール・モードのピル）コードによって構築された`AddTab(label, factory, modo, pílula, requiresProject)`, **lazy-load**（各サブタブは、最初の選択時にのみコントロールを生成し、キャッシュする）および **guard`requiresProject`**（設計が必要なタブは、クラッシュする代わりにプレースホルダーを表示する）。その上に、**4つのハブ**（それぞれが既存のコントロールをホストし、その内部には手を加えない）：**(1) バトルコマンド** →`Comandos/Magias de Personagem` (command.bin) ·`Monster Commands 1` (monmagic1) ·`Monster Commands 2` (monmagic2); **(2) アイテム** →`Items` (item.bin) ·`Key Items` (important.bin, guard) ·`Shop` (スロットペイロードを保存) — ショップとキーアイテムは、ここからは個別の画面から表示されるようになった； **(3) スフィアグリッド** →`Explorer (DB)` ·`Builder` ·`Canvas` (3が1に変わった；Explorerはプロジェクトを要求するが、Builder/Canvasはプロジェクトなしで開く)；**(4) テキスト／参照** →`String Explorer` ·`Macro Explorer` ·`Weapon Names` ·`Battle Text` ·`Event Explorer` (5つが1つに統合されました)。各サブタブには、実際のファイル／スコープに応じた適切なモード（書き込み可能：琥珀色／読み取り専用：青緑色）が設定されています。 **サイドバー：** コアオーサリングのボタン数が 23 → 15 に減少； **オートアビリティは「カスタマイズ／エイオン」に統合**； **モンスター AI エクスプローラーがメニューから削除**（ハンドラー／コードは保持、ナビゲーションオプションのみ削除）。 **スコープ（RIN）：** ナビゲーション／ホスティングのみ — 4つの新しいハンドラーは`Main_Window` 建設する`SubTabHub` 工場経由で (`CreateKernelCommandsControl(...)` カーネルテーブル用；`new XxxControl()` （その他）そして、従来のハンドラはコード内に残ります（`ShowKernelCommands`/`CreateKernelCommandsControl` （back/forward および nav-restore は引き続き機能します）。**writer/parser/runtime/save/SIN/provider およびそれらの内部構造には一切手を加えません**。

別のレーンのモジュール（MAGIC/Sphere）；nav行のみを編集します。`Main_Window` (共有ファイル) + 追加`Modules/SubTabHub`. 「Battle Commands」で未実装の機能（ユニバーサル検索、サブタブ検索、**マルチ編集**）は、今後のアップデートに持ち越されました（コマンドエディタのロジックに変更が必要＝lane MAGIC）。 **マイナー**（4つの新しいタブ／ナビゲーションモジュール + 新しい再利用可能なコンポーネント）。ビルドは**エラー0件／警告361件**でコンパイル完了；エディタはv2.74.0.0で再開されました。[前回：`v2.73.0`] — Jarvis-RIN
- **🏐`v2.73.0` — ブリッツボール・ハブ：5つの独立した画面を、サブタブ付きの「ブリッツボール」タブ1つに統合し、モード表示バーを明確化し、5つのウィンドウのビジュアルを洗練させた。** ナビゲーションとUXの統合（担当：**Jarvis-RIN**）。 サイドバーには**5つの独立したボタン**があり（`Blitzball Prizes`/`Roster`/`Recruits`/`Prizes (Edit)`/`Prize Table`) 名前が競合していたもの（3つが「prize」と表示されていた）；現在は**1つのボタン**`Blitzball 🏐`** 新しいモジュールが開きます **`BlitzballHub_Control`** (`Modules/BlitzballHub`) FFX風の帯に**5つのサブタブ**（ピル`tabPill`, **ティール色**の下線が引かれたアクティブなタブ): **ロスター · 新人選手 · 賞金総額 · 賞金配分表 · アトラス**。各サブタブには、帯のすぐ下に**率直なモードのピル**が表示されています —`WRITER LAB · <arquivo> · RT0 proven · RT2 pending` （琥珀色）の4つの文字で、`READ-ONLY · Spira Data Atlas` (ティール) アトラスでは — ハブの外部「モード」バッジがニュートラルになったため (`Atlas + Writer Lab`) であり、もはや単一のモードを指定することはできない。タブの**lazy-load**（各UserControlは最初の選択時にのみ生成され、キャッシュされる）→ ハブは**決して4つを保持しない**`ByteSnapshotEditorSession` 同時に**。**5つのウィンドウのビジュアル調整**（表示のみ — ライター／パーサー／バインディング／データモデルには一切手を加えていない）：新しいクラスを使用した小さなヒーロー`heroGradient` （コピーされた3つのリテラルグラデーションを削除しました）、`Save` 現在、`primaryAction` (ティール色) 4つの入力欄（以前は各画面に表示されていたスタイリッシュな「マイナス」ボタン）、8つのボックスからなる**Roster**`cardSoft` **表**（ヘッダーは中央揃え、a/b/c/typeは右揃え）として表示される、**Prize Table** **カテゴリー別にアコーディオン形式でグループ化**（5つの折りたたみ可能なグループ — リーグ／トーナメント順位、リーグ／トーナメント得点王、ロール閾値／オッズ — デフォルトでは折りたたまれており、同系色の丸いアイコンとカウント数が表示されています）

ites; テキストフィルターは一致するグループを自動展開し、約849の選択肢を整理するため、 **ファミリーごとの色帯**を1行ごとに（ティール＝賞金指数、アンバー＝オッズ）＋要約テキスト＋標準化されたパディング、**賞金総額**には数量／原型がグループ化され、`cardSoft` およびスリム化されたQuantity列、オフセット付きの**Recruits**`@0x` サブタイトルとプレーヤーのコンボをメイン要素として配置し、グリッド上に**Atlas**と**色分けされた証拠ピル**（proved-candidate=ティール / partial=アンバー / metadata-only=ブルー / blocked=危険）を配置し、リテラルカラー（`#9AD7E2`/`#9EB0C2`) をトークンと交換する。**追加**される新しいクラスは、`StudioTheme.axaml` (`tabPill`/`tabPillActive`,`heroGradient`,`pillWriter`/`pillReadonly`,`numField`) — 存在しなかったセレクター → 他の画面では**回帰がゼロ**（グローバルテーマには手を加えていない）`TabControl`（まさに、tab cruを使用している8つの画面に影響を与えないようにするためです）。新しいプレゼンテーション用コンバーター2台（`PrizeFamilyBrushConverter`,`EvidenceStatusBrushConverter`). **MINOR**（新しいナビゲーションモジュール／AI ＋ 再利用可能なサブタブの第1グループ；ポリッシュ単体ではPATCHとなるが、新しいモジュールに便乗する）。 **以下には**手を加えません：writer/parser/runtime/save/SIN/Atlasプロバイダー/その他のレーン；これら5つ`*_Control.axaml.cs` また、DataModelsは変更されませんでした。ビルドの結果、**エラー0件／警告361件**でした（`.exe` （単にエディタが開いていたからといってコピーされたわけではない――コードとは無関係）。[前へ：`v2.72.0`] — Jarvis-RIN
- **🏐`v2.72.0` — ブリッツボール賞金表：ODDS（抽選の390のしきい値）も編集可能に — 「すべてを編集」。** タブの拡張`Blitzball Prize Table 🏐` (`v2.71.0`): 459のプライズインデックスに加え、現在は確率を定義する**390の即時スレッショルド**、すなわちバウンドを算出している`case >= N` /`case <= M` について`GetRandomInRange(100)` (バイトコード`29 AE <thr> 0E/0F D7/D6` =`DUP·PUSHII·GE/LE·jump`). 取得されたバケット`roll >= lo` そして`roll <= hi` ～がある`(hi-lo+1)%` 確率；バケットを広げる＝その賞が当たる確率が高くなる。新規`BlitzballPrizeStructure_File.FindRollThresholds`/`SetThresholdAt` （**ある賞品サイトから≤768Bでスキャンしたもの**、無関係なスイッチには決して触れないように）— 同じ2バイトのライターを使用している（`Event_File.PatchScriptUInt16`). 統一されたUI：フィルターに**「Roll Thr」**が追加されました

eshold (odds)**、各行はインライン編集が可能（prize rowsにはリアルタイムで算出された報酬が表示され、threshold rowsにはバケットの境界値が表示される）。Gate`--blitzball-prizestruct-rt0` 拡張版および**PASS**の`bltz0200.ebp` 実数：459 賞金 + **390 のしきい値** (195`<=` / 195`>=` = 完全なペア）、編集なしのバイト同一、プライズインデックスの編集 **および** スレッショルドの編集、いずれも **2バイト単位で分離** （`<=10 → <=50` @0xC108)、再読み込みで両方が確認されました。**MINOR**（新機能：オッズの編集）。save/runtime/SIN/その他のレーンには影響しません。ビルド：エラー 0 件／警告 361 件；`--blitzball-prizestruct-rt0` **PASS**。ドキュメント：`docs/reverse/FFX_BLITZBALL_PRIZE_STRUCTURE_RE_2026-06-10.md`. [前へ：`v2.71.0`] — Jarvis-CHAPPU
- **🏐`v2.71.0` — ブリッツボールの賞品一覧：各順位・抽選でどのような賞品がもらえるかを編集する（459個の即時賞品が`bltz0200.ebp`) — 「blocked」という表示を否定している。** 読み取り専用エクスプローラー (`v2.62.0`) は記していた`BlitzballLeague/TournamentPrizeIndex`/`TopScorer` **のように`blocked` (実行時/保存)** — **あまりにも保守的**：彼は**読み取り/表示**側の側面しか見ていなかった`bltz0201` (`PrizeIndex + 220 → Treasure Label`). その**役割**は`bltz0200.ebp` ATELにおける**459件の即時定数**として：`Set Blitzball*PrizeIndex[slot] = <prize-index>` スイッチをオンにして`GetRandomInRange(100)` （賞品のランダムな配分）。編集可能なゲームファイル。リクルートと同様（ただし、255を超えるため、**2バイト**の即時処理となる）。新しいモジュール／タブ **`Blitzball Prize Table 🏐`** (`Modules/BlitzballPrizeStructEditor`): 459のサイトの一覧（変数／報酬／インデックスでフィルタリング可能）。各サイトには、prize-indexのインライン編集機能に加え、**リアルタイムで算出される報酬**が掲載されています（takara`prize+220`、あるいはMacroDict#8（100以上用）。新しいプリミティブ`Event_File.PatchScriptUInt16`/`ReadScriptUInt16` (2バイトの即時パッチ、length-preserving via`ScriptChunkOverride`) +`FfxLib/Blitzball/BlitzballPrizeStructure_File.cs` (スキャン/`SetPrizeIndexAt`) + ゲート`Tools/BlitzballPrizeStructRt0.cs` (`--blitzball-prizestruct-rt0`). **実証済み**`bltz0200.ebp` 実データ (222.464 B): **459サイト** （リーグ141＋トーナメント188＋リーグ-TS 65＋トーナメント-TS 65＝コーパスのカウントを上回る）、編集なしのバイト同一、1つの賞金インデックスの編集が**2バイトに限定**（リーグ1位`0x0001→0x0099` @0xC0A2), re

-read が確認します。**RE の結果：** ATEL の var-ids は **ファイル単位** です（`0x28` bltz0201 対`0x30` no bltz0200); ids bltz0200 (`0x30`/`0x31`/`0x32`/`0x33`) switch/Setによって実証済み。**正直に言うと：**各順位がどのプライズインデックスをもたらすかを編集（ゲームファイル、RT0の隔離は実証済み、RT2は保留中）；各インデックスが与える報酬＝takara（aba`Blitzball Prizes (Edit)`); オッズ（ロールの閾値）は、まだ公開されていない別の即時変数のセットである。**MINOR**（NOVOモジュール + 新しい2バイトライター）。save/runtime/SIN/その他のレーンには影響しない。ビルド：エラー0件／警告361件；`--blitzball-prizestruct-rt0` **PASS**。ドキュメント：`docs/reverse/FFX_BLITZBALL_PRIZE_STRUCTURE_RE_2026-06-10.md`. [前へ：`v2.70.0`] — Jarvis-CHAPPU
- **🏐`v2.70.0` — ブリッツボールの賞品エディタ：ゲームデータ（takara.bin 220..320）内の101種類のブリッツボールの賞品を編集するためのUI。** 新しいモジュール／タブ **`Blitzball Prizes (Edit) 🏐`** (`Modules/BlitzballPrizesEditor`) ブリッツボールの賞品プール（prize 0..100 → takara row 220+k → reward）を管理しており、proved-candidateルールは`v2.62.0`): 101の報酬を掲載したマスター・ディテール形式。各報酬には、**項目のドロップダウン**（名前／IDによるフィルタリング）＋**数量**＋Raw Type／Kind／rewardが明示されている。**内部で以下を再利用している`TreasureEditor_DataModel` 検証済み**（項目辞書、名前解決、`ByteSnapshotEditorSession`, テーブル全体のライター）で220行目～320行目にフィルタリング → **save は「Treasures」タブのライターと同じ**であり、書き込みを行います`takara.bin` 編集された賞を除き、498件のエントリをバイト単位でそのまま保持しています。登録先：`Main_Window` (nav +`SetModule`). **Honestidade:** **「Writable (Lab)」**バッジ — POOL（各賞品インデックスがどの報酬を与えるか）を編集します。リーグ／トーナメント／イベントごとにどの賞品を獲得するか（＝実行時／セーブ時）を編集するものではありません； ギアやキーアイテムの賞品、あるいはKindの詳細な制御については、「Treasures」タブを使用してください。これは、読み取り専用のエクスプローラーを補完するものです。`Blitzball Prizes 🏐` (`v2.62.0`) 実際の版との比較。**MINOR**（新しいモジュール／タブ）。Reusa`TreasureEditor_DataModel`/`Treasure_File`/`Item_Dictionary`; **新しい**ライターを作成せず、save-do-jogador/runtime/SIN/その他のレーンにも影響を与えません。ビルドエラー 0件 / 警告 361件。[前回：`v2.69.0`] — Jarvis-CHAPPU
- **🏐`v2.69.0` — ブリッツボール・リクルート エディター：誰をリクルートするかを切り替えるためのUI

 各場所（ゲームファイル；ライター`v2.67.0` （確認済み）。** 新しいモジュール／タブ **`Blitzball Recruits 🏐`** (`Modules/BlitzballRecruitEditor`) ゲームのデータファイル内でフリーエージェントのスカウトを直接編集する機能：**~34のスカウトフィールドイベント**（ルカ／キリカ／グアドサラム／カルム・ランズ／エアシップ／ベサイド／…、コーパスから署名に基づいて抽出されたもの）を一覧表示する`AE 28 00 14 AE <id> 00 A3`)、イベントごとに各**リクルートサイト**に**60人のプレイヤーが並ぶドロップダウンメニュー**（名前が解決された`macrodic.dcp` 経由`BlitzballPlayerNames`) そこで採用された人物を再指定するため。すでに検証済みのライターを使用する`BlitzballRecruit_File`/`Event_File.PatchScriptByte` (ゲート`--blitzball-recruit-rt0`) 経由で`ByteSnapshotEditorSession` **イベントごと**（保存／取り消し／元の状態に戻す／自動保存、MacroExplorerのマルチソース機能と同様）。登録先：`Main_Window` (nav +`SetModule`). **誠実さ：** **「Writable (Lab)」** バッジ — 新入プレイヤーのプレイヤーIDのみを再設定（ゲームファイル、**EXEパッチなし**；RT0の隔離は確認済み、ゲーム内RT2は未確認）； 各プレイヤーには通常 **2つのサイト**（2つのコードブランチ）があります → 両方を変更して完全に再設定してください；リクルートの利用可能性／ゲートはイベントのロジックに従います；プレイヤーのステータス = 「Blitzball Roster」タブ、名前 = 「Macro Explorer」。 **MINOR**（新規モジュール／タブ；前例：Blitzball Roster Editor`v2.68.0` = MINOR）。Reusa writer/`Event_File`/`MacroDictionary_File`/`BlitzballPlayerNames`/`ByteSnapshotEditorSession` 既存のものを使用します。**新しい**ライターを作成したり、save/runtime/SIN/その他のレーンにアクセスしたりは**しません**。ビルドエラー 0件 / 警告 361件；`--blitzball-recruit-rt0` PASS。[前：`v2.68.0`] — Jarvis-CHAPPU
- **🏐`v2.68.0` — ブリッツボール・ロースターエディタ：60人の選手のステータス・成長値を視覚的に表示するUI（ゲームファイル；ライター`v2.66.0` （確認済み）。** 新しいモジュール／タブ **`Blitzball Roster 🏐`** (`Modules/BlitzballRosterEditor`) ファイル内の60人のプレイヤーのstat-growth曲線を視覚的に編集する`bltz0002.ebp`: プレイヤー一覧（**名前は読み取り専用**で解決済み）`macrodic.dcp` 経由`BlitzballPlayerNames`) + 8つのステータス（HP/SP/AT/EN/PA/SH/BL/CA）のエディタ。各ステータスには4つの浮動小数点値が設定されています`a/b/c/growthType` 編集可能、**Lv 1/50/99での値のリアルタイムプレビュー**、および計算式。実績のあるライターを活用`BlitzballRoster_File` (gate `--

blitzball-roster-rt0`) via `ByteSnapshotEditorSession` (save/undo/restore-original/auto-save, espelho exato do `TreasureEditor`). Registrado no `Main_Window` (nav + `SetModule`). **Honestidade:** badge **"Writable (Lab)"** — escreve só os stats/growth (RT0 byte-identity provado, in-game RT2 pendente); **nomes são read-only aqui** (editar no Macro Explorer); techs/level/EXP/custo = save-side; match-engine/efeitos de técnica = EXE-native (ver address map). **MINOR** (módulo/aba NOVO; precedente: Blitzball Prize Explorer `v2.62.0` = MINOR). Reusa writer/`Event_File`/`MacroDictionary_File`/`ブリッツボールの選手名` existentes; **não** cria writer novo nem toca outras lanes/runtime/save/SIN. Build 0 erros / 361 warnings; `--blitzball-roster-rt0` PASS. [anterior: `v2.67.0`] — Jarvis-CHAPPU
- **🏉`v2.67.0` — ブリッツボール：ゲームデータ内の「リクルート」情報を編集可能 — すぐに適用できるパッチは ATEL の`.ebp` (RT0 検証済み)。** 各場所でリクルートされるのは、フィールドイベントの ATEL バイトコード内の **1 バイトのイミディエート** である：署名`AE 28 00 14 AE <playerId> 00 A3` (`PUSHII 40 · ADD · PUSHII <playerId> · write-array`) 自分のチームにappendを行います (`BlitzballTeamPlayers[count+40]`). 新しいプリミティブ`Event_File.PatchScriptByte` (ATELチャンクへの1バイトのパッチ、**長さを維持**して via`ScriptChunkOverride`) +`FfxLib/Blitzball/BlitzballRecruit_File.cs` (`FindSites`/`SetRecruit`/`SetRecruitAt`) + ゲート`Tools/BlitzballRecruitRt0.cs` (`--blitzball-recruit-rt0`). **実証済み**`guad0000.ebp`: 6つのサイト (Giera`0x1F`/Auda`0x22`/Nav`0x21` × 2 ブランチ）、編集不可の読み取り→書き込み（バイト単位で同一）（189,696 B）、Giera→Wakka への再参照（`0x1F`→`0x33`) **2バイト単位で分離**されたものを所定のオフセットで読み込み、再読み込みにより新入隊員を確認。署名の検証結果：vs`guad0000`/`lchb0000`/`hiku0500` （アル・ベド・サイキーズ完全版）。**正直に言うと：** 誰をどこでリクルートするかを変更します（ゲームファイル、**EXEパッチなし**）；リクルートの利用可能条件／ゲートはイベントのロジックに従います。 **マイナー**（新規の募集ライター；この種のツールとしては初）。ファイルの追加とディスパッチ1回のみ`Program.cs`; save/runtime/SIN/その他のレーンは処理しません。ビルドエラー 0件 / 警告 361件;`--blitzball-recruit-rt0` **PASS**。ドキュメント：`docs/reverse/FFX_BLITZBALL_ENGINE_IDA_SCOUT_2

026-06-10.md` (Recrutamento). [anterior: `v2.66.0.1`] — Jarvis-CHAPPU
- **🏉`v2.66.0.1` — ブリッツボール：プレイヤーの名前が編集可能であることが確認された（macrodic chunk 7）＋レーン内アクセサ。** **修正**（コードは入力されるが動作は変更なし — アクセサはまだ消費されていない；RE/prep）。以下をデコードした`new_uspc/menu/macrodic.dcp` 実際に確認し、60人のプレイヤーの名前がマクロであることを証明した`0x700+idx` = **チャンク 7** (文字セット FFX`byte−0x0F`; 101件）：`0x702`=Datto,`0x703`=レティ、`0x704`=ジャス、`0x705`=ボッタ、`0x706`=Keepa,`0x707`=ビクソン…；`0x700`/`0x701` = **名前変更可能な**キャラクター（ティダ／ワッカ）について。→ モジュール内で**本日より編集可能**`MacroExplorer` (読み書き`macrodic.dcp` （SafeWriter/元に戻す/検証/ラウンドトリップ）。新しい読み取り専用アクセサ`FfxLib/Blitzball/BlitzballPlayerNames.cs` (インデックス↔マクロ`0x700+idx`,`TryGetName`) 未来形の**prep**として`BlitzballRosterEditor` UIで名前をインライン表示・編集する。`MacroExplorer` （テキストレーン）やその他のレーンには何も追加せず、ファイル1つとドキュメントのみを追加します。ビルド結果：エラー0件／警告361件。ドキュメント：`docs/reverse/FFX_BLITZBALL_ROSTER_BASE_RE_2026-06-10.md §3` +`docs/ai/BLITZBALL_100PCT_EDITOR_CHECKLIST_2026-06-10.md`. [前へ：`v2.66.0`] — Jarvis-CHAPPU
- **🏉`v2.66.0` — ブリッツボールのロースター（60人の選手のステータス・成長値）が、ゲームデータ内で編集可能になりました — ライター`.ebp` Atel-variable PROVADO（RT0バイト同一＋変異隔離）。** **GAME FILE内のブリッツボールのベースデータを編集する最初のライターであり、セーブデータ内ではない。** 60人のプレイヤーの基本ステータス＋成長曲線は、`bltz0002.ebp` Atel変数として`0x126..0x12E` (8つの統計値 × 60人の選手 × 4つの浮動小数点数`a,b,c,growthType`; 成長の公式を解き明かす：`gt -1`→1,`0`→a+b・Lv,`1`→a+b·Lv^c,`2`→a+b・Lv−c・Lv²、`3`→a+b・Lv+c・Lv²）。新しい原始関数`Event_File.PatchEventDataElement(varId, idx, bytes)` (`FfxLib/Event/Event_File.AtelVar.cs`): AtelのeventData変数に対するインプレースパッチャー。フックを介して**長さを保持**`ScriptChunkOverride` すでに存在する →`Write()` 編集されたスライスを除き、バイト単位で同一のデータを再パッケージ化。新しいファイルクラスの読み取り／書き込み`FfxLib/Blitzball/BlitzballRoster_File.cs` (60×8のグロースをデコード／編集) + ゲート`Tools/BlitzballRosterRt0.cs` (`--blitzball-roster-rt0`). **実証済み：** 朗読：

te-exato 対 FFXDataParser のダンプ（プレイヤー0のHP =`70 + 30·Lv + 0.711·Lv²`); no-edit 読み取り→書き込み **バイト単位で同一** (5,445,248 B); **有効な growthType 480/480**; 1 つの float パッチが **対象要素の 4 バイトに限定** され、想定されたオフセットに配置 (`@0x491680`). **RE（欠けていた部分）：** 変数の値ベース =`worker0_header + 0x30` （堅牢な解決策、ハードコーディングなし）。**正直に言うと：** ファイルから取得されるのはstats/growthのみです。名前は文字列マクロです。`0x700+idx` (ライターは存在するが、接続が必要)、**ポジション/技術定義/スターター = EXE (IDA未対応)**、 習得した技術/コスト/契約/レベル/EXP = **save** (game-fileの範囲外)。 **UIはまだ実装されていません** (次のステップ =`BlitzballRosterEditor`). **MINOR**（新機能：ゲームファイル内のブリッツボール・ロスターのライターとして初めて実装）。セーブデータ（CHAPPU/チェックサム）、ランタイム、SIN、その他のレーンには一切触れない。単に新しいファイルを追加し、`Program.cs`. ビルドエラー 0件 / 警告 361件;`--blitzball-roster-rt0` **PASS**（編集不可、バイト同一かつ変異が隔離されている）。ドキュメント：`docs/reverse/FFX_BLITZBALL_ROSTER_BASE_RE_2026-06-10.md` +`docs/ai/BLITZBALL_100PCT_EDITOR_CHECKLIST_2026-06-10.md`. [前へ：`v2.65.3`] — Jarvis-CHAPPU
- **🗺 Spira Data Atlas / FFXDataParser ブリッジ — 巨大パーサーのフロントエンドが完成。** ゲーム全体の調査・カタログ化を担当するフロントエンドに、バージョン管理された運用環境が整備されました：ローカルブリッジは`tools/ffxdataparser_bridge` は、以下に基づく読み取り専用再カタログ化を再現するために強化されました。`FFXDataParser`、Step0/v5、追加のv6 P0、v7 ATEL granular、v8 ATEL semanticの各レイヤーで構成されています。データの出所を明確にするため、出所および引き継ぎに関するドキュメントが追加されました（`HANDOFF_SPIRA_DATA_ATLAS_PARSERS_GIGANTES_2026-06-09.md`,`SPIRA_DATA_ATLAS_PARSERS_GIGANTES_PROVENANCE_MAP_2026-06-09.md`), PRE1/PRE2 向け`takara.bin`/`buki_get.bin`、command/magic ロケールスキーマ、ロケール対応パーサー層、unknown/evidence ヘルス、および Step0-C クロスリンク。この結果から、何が`proved`,`partial`,`read-only`,`metadata-only`,`blocked` そして`RT2-pending`: parser-corpus は構造や存在を確認するものであり、実行時の動作やライターの権限は確認しません。
- **📚 Spira Data Atlas / BIBLE OF SPIRA — プロバイダーの読み取り専用データが 14,739 件に拡大

彼らに。** プロバイダー`SpiraDataAtlasCatalog` そして、BIBLEは現在、アトラスを実際に調査可能な文脈として捉えている：`74` アトラスの項目、`54` マスターレイヤー、`1601` 解析済みの生データ、`615` call-shapes,`89` branch-shapes,`202` field-shapes,`3283` workers および`656` コマンドサイトの概要。最終的なパッケージにより、Step0-Cの「6つのギャップ」が解消されました：`1604` monster-presence rows 編成/スロットごと、`979` SINの適格基準 経由`AiCommandMetadata`,`1190` 名前／モデルの行`w_name.bin`,`312` ブリッツボールのイベント審判の皆様、`76` ブリッツボールの賞品審判は、以下に由来する`bltz0200/0201`,`20` PC/Aeon fine rows e`2493` Sphere Gridノード。組み込みのCSVリーダーが、複数行のレコードとゲートに対応するようになりました。`--spiraatlas-rt0` /`--aicmdmeta-rt0` 完了しました。新しいライターは導入されませんでした：Treasure/Shop/Sphere/Monster AI/SINは、まずこれをコンテキスト、バッジ、監査として活用します。SIN Chain Builderは引き続き、AiScriptLab、AEON diff、バックアップ、RT2に依存しています。
- **🧠 Monster AI Editor — SIN Threatのナビゲーションを洗練。** **Spira Instinct Network**の読み取り専用ギャラリーに、正確な脅威フィルターが追加されました`T1`..`T10`、帯域フィルターを維持しつつ（`T1-T3`,`T4-T6`,`T7-T8`,`T9-T10`) および、オプションで`SIN-001 -> SIN-100`,`Threat 1 -> 10`,`Threat 10 -> 1` または検索の関連性。選択した「罪」のプレビューには、脅威の範囲が明示されるようになりました（`baixo`,`medio`,`alto`,`dark`,`proibido`) および具体化の方針（`materializavel primeiro`,`espera chain builder`,`somente lab`, など）。新しいライターも使わず、ランタイムやゲーム本体をいじらずに：将来のチェーンビルダーが登場する前に、100個のプリセットを閲覧できるオフラインのUX／カタログ。一時的なビルドでエラー0／警告0。 — Jarvis-Codex
- **🧠 BattleTracker / SIN — オフラインマッピングのステータス固定。** ライブゲームには手を加えずに、Forbidden Riteのフロントエンドにドキュメントが追加されました`docs/ai/SIN_STICKY_STATUS_OFFLINE_MAPPING_2026-06-08.md`:`AiChrPropertyNames` 341個のフィールドがあります (`0x0000..0x0159`) であり、さらさない`status_full_auto_*`/`status_innate_auto_*` ATELフィールドとして知られている；当面はstickyがランタイムのまま`MemoryChr` (`0x62A..0x634`) または将来のライブ/DINPUT8であり、純粋なMonster AIではない。BattleTrackerには現在、読み取り専用のトラック **Forbidden Rite / Sticky Bytes** が表示されており、`Suffer`,`Durations`,

 `Extra`,`Doom`,`Full auto`,`Innate auto` 簡潔な要約。次期RT2ではPowerShellへの依存度を低減。ビルドエディタ：エラー0件／警告361件。 — Jarvis-Codex
- **🧠 Monster AI Editor — Forbidden Rite スティッキー・アンチリムーバル RT2 LAB。** アンチリボン・パッケージの後に`m034 -> Tidus`、実機テストによって、単なるバイパスに過ぎないものと、取り除けないものが区別された：スティッキーなし、`Eye Drops` ミスになって、去っていった`Darkness=255`、でも「Holy Water/除去」で消えた`Zombie/Confuse/Curse`、残りは`Silence/Darkness/Doom`. 続いて、LABランタイムスクリプトが次のように記録した`status_full_auto=0102/0806/4400` そして`status_innate_auto=0102/0806/4400` ～のそばで`suffer=0102`,`sil/dark=255/255`,`extra=4400`,`doom=5/5`; 150秒間、除去アイテムや呪文はパッケージを解放せず、ドゥームのダメージが蓄積した`5 -> 4 -> 5`. Guardrail：これはランタイムテストです`MemoryChr`, nao writer ATEL/SINボタンがマッピングされるまで`full_auto/innate_auto` フィールドとして扱うか、live/DINPUT8のルートを採用するか。 — Jarvis-Codex
- **🧠 Monster AI Editor — Forbidden Rite RT2：ティダで検証済みのアンチ・リボン・パック。** 初の直接経由のパック`writeChrProperty(Character#1, field, value)` リボンを、バトルロイヤルで`m034`: ティダスは受け取った`Zombie`,`Confuse`,`Silence(255)`,`Darkness(255)`,`Curse` そして`Doom(cur=4/init=5)`. 実行時の読み取り：`suffer=0x0102`,`turns[sleep/sil/dark]=0/255/255`,`extra=0x4400`. O`m034` labは、以下の内容で再構成されました`HP=1.000.000`,`Agility=100` そして`Accuracy=255` 生き残り、より迅速に行動するために。**Forbidden Rite LAB**のUIには、Zombie/Confuse/Silence/Darkness/Curse/DoomおよびDoomカウンターが、正しいデフォルト設定で一覧表示されるようになりました。 まだ公開用のSINプリセットではありません：広範囲のターゲット、敵対的な回復、ターンごとのペナルティには独自のRT2が必要です。ビルドエディタのエラー0件／警告361件。 — Jarvis-Codex
- **🧠 モンスターAIエディタ — Forbidden Rite LAB アンチ・リボン。** Workbenchには、**リボン**を持つキャラクターに対して直接ステータス効果をテストするための、初の狭域向けLABライターが追加されました。カード**Forbidden Rite LAB**は単一のターゲットを選択します（`Character#1/#2/#3`,`FrontlineChars`,`TargetActors`,`LastAttacker`), 選択してください`Zombie`/`Curse`/`Doom`, 金額`1`, そしてそれを`CombatHandler.onTurn` バックアップ機能付きのリアル版`writeChrProperty(target, field, value)` (`PUSHII<target> -> PUSHII<field>

 -> PUSHII<value> -> CALLPOPA 7018`). A rota fica separada de `setStatField(70AB)` — 署名を混同しないように。これは公開されているSINプリセットではなく、Ribbon + AEONを装備したダミーがRT2までバイパスを宣言しない限り、バイパスは宣言されない。ビルドエディタ：エラー0件／警告361件。 — Jarvis-Codex
- **🧠 モンスターAIエディタ — SIN 100プリセット + 脅威フィルター。** **Spira Instinct Network**のギャラリーに、読み取り専用の**100プリセット**が追加されました。今回の新追加分には`Tribunal of Yevon`,`Fayth Erosion`,`Guado Excommunication`,`Spectral Keeper Wheel`,`Penance Arm Doctrine`,`Omega Scripture`,`Anima Pain Engine`,`Bevelle Inquisition`,`Yu Pagoda Spiral` そして`Sin Eternal Return`. UIでは現在、以下でフィルタリングされます`Threat` (`T1-T3`,`T4-T6`,`T7-T8`,`T9-T10`,`T10`) ティア／ステータスに加え、リストを数値順に並べ替えます`SIN-001` ->`SIN-100`;`Tier` 技術的なリスクが依然として存在し、`Threat` ゲーム内での脅威は続いている。新しいライターはいない：`T10` これは「禁断のレシピ」のショーケース／ラボであり、公開用ボタンではありません。 — Jarvis-Codex
- **🧠 Monster AI Editor — SIN Lethal Expansion + アンチ・リボン対策プラン。** SINカタログは58から**80のプリセット**（読み取り専用）に増え、レタル／アンチ・メタ・パックが追加されました：`Yunalesca's Mercy`,`Ribbon Funeral`,`Rotting Benediction`,`Maester's Noose`,`Penance Clock`,`Anti-Phoenix Liturgy`,`Seymour's Verdict`,`Faythless Prayer`,`All-Life Reversal`,`Yu Yevon's Hunger`,`Omega Pattern` など。BIBLEにはガードレールが設置され、`Ribbon bypass nao e magia normal` そして`Status direto no battle actor`、さらに以下のフィールドのほかに`StatusCurse`,`StatusDoom`,`DoomCounter`,`StatusResistanceZombie` および部分的な免除。新たな計画：`docs/ai/SIN_LETHAL_EXPANSION_AND_RIBBON_BYPASS_PLAN_2026-06-08.md`. カタログでは現在、以下のように分類されています`Tier A/B/C/LAB` 技術的リスクとして、および`Threat 1-10` ゲーム内の脅威として、T10は『ファイナルファンタジーX』の禁止されたレシピに割り当てられている。新しいライターもおらず、バイパスが実証されたという主張もない：次のゲートは、リボンを装備したキャラクターに対するRT2であり、通常のコマンドと`writeChrProperty(target, StatusZombie/Curse/Doom, 1)`. ビルドエディタ：エラー 0件 / 警告 361件。 — Jarvis-Codex
- **🧠 モンスターAIエディタ — UI上でSINギャラリーの読み取り専用モードが有効化されています。** **Spira Instinct Network*の4枚のカードのモック

* 58のプリセットを閲覧できる体系的なカタログとなり（`False Calm`,`Cycle of Ruin`,`Yevon's Maw`,`Unsent Choir`,`Diamante de Shiva`（など）、テキスト／プリミティブ検索、フィルタ`Todos`/`Tier A`/`Tier B`/`Tier C / LAB`/`A-now`、選択可能なカードと、動作、プリミティブ、リスク、次のゲートを表示するプレビュー。新しいライターはまだ実装されていません：パネルはショーケース／作成機能として計画されています。プリセットを実際のボタンに変換するには、依然としてBIBLEエントリ、AiValidator、AEON diff、バックアップ、RT2が必要です。 ビルドエディタ：エラー0件／警告361件。 — Jarvis-Codex
- **🧠 BIBLE/SIN研究ツール — モンスターAIの完全な調査データ + コマンドのグリモワール + 58のSIN候補。** O`RuntimeTools/AiScriptLab` 2つの読み取り専用モードが追加されました：`--sin-census`、これはワーカー、検出されたアクション、コマンド、フィールド、ターゲット、およびパターンフラグを用いて、モンスターごとのアトラスを生成するものであり；そして`--sin-grimoire`、これには以下の方法で実行可能な867個のコマンドが記載されており、`AiCommandId` また、著作者を特定するためのヒューリスティックな役割に基づいて分類する。実際のコーパスでテスト済み：AiFiles 361件、スクリプト 346件、330件`CombatHandler.onTurn` 解決済み、使用されたコマンド470件、読み込まれたフィールド67件、書き込まれたフィールド171件、ターゲット37件。新しいドキュメント：`BIBLE_OF_SPIRA_MONSTER_AI_CORPUS_ATLAS_2026-06-08.md`,`SIN_COMMAND_GRIMOIRE_2026-06-08.md` そして`SIN_PRESET_CANDIDATES_2026-06-08.md` 58の候補プリセット（`False Calm`,`Cycle of Ruin`,`Yevon's Maw`,`Unsent Choir` など）が`A-now`/`B-chain`/`C-frontier`/`LAB-only`. 新しいライターも、新しいパブリックボタンもない。これは、将来のSIN Chain Builderに向けた、監査可能な基盤である。 — Jarvis-Codex
- **🔎`v2.65.3` — SEYMOUR監査：124のATEL`unknown-call-shape` アトラスのデータを、信頼性の高いクラス（読み取り専用、バイト単位で検証済み）に分類した。** **ATEL Call-Shape Audit（SIN以前）。** これらの`124` v8のセマンティックパースでは分類されなかったフィールド書き込み（`field-write-unknown-call-shape`) は、コーパス全体（FFXDataParser target/text、346スクリプト）について**バイトコード**レベルで検証され、**完全に**2つの実証済みのクラスに分類され、**残りは0**であった。**(1)`0x70A8 btlSetMotionData` — 116行 (100%)：** 均一な形状`PUSHII actor · PUSHII field · (PUSHII|PUSHF) value · CALLPOPA` =`(actor, field, value)` **motionProperty** ネームスペース内（フィールド`0x00..0x09`, これらはすべて `AiMotion` で指定されています

PropertyNames`); actor é ref REAL (113× Self `0xFFF3` + Monster#01/#02/#03 `15時／16時／17時`), em 25 monstros → classe **`set-motion-data-actor-field-value`** (irmão explicit-actor do `0x70B2 setMotionField`; **NÃO** é `setStatField`). **(2) `0x7032 setActorFacingAngle` — 8 rows:** NÃO é field-write — é `(俳優、アングル)` 2-push **sem field-id**; vazaram pro catálogo por **falso-positivo de regex** (só ângulos FLOAT renderizam `.facingAngle = 90.0 [42B40000h]` e o regex v7 pegou o `.0 [16進数]` do decimal; os 63 sites-irmãos com ângulo inteiro `= 90 [5Ah]` não vazaram) → classe **`not-field-write`**. **Mudanças:** bridge `tools/ffxdataparser_bridge/build_atel_semantic_catalog.ps1` (`Get-FieldWriteSemanticKind` + risk notes) reclassifica os dois call-ids; o v8 regenera com `0` unknown (116+8 nas classes novas); a contagem de `AtelFieldWriteShape` fica **`202`** (relabel preserva a cardinalidade da chave `callId|fieldHex|fieldName|semanticKind|fieldCategory`, provado before/after); o pass `unknown-health` cai de `199 → 75` (os 124 ATEL saem do bucket "blocked-until-audited"); narrativas do `SpiraDataAtlasCatalog` (`atlas:フィールド呼び出し形状` + guardrail + `atlas:unknown-health`) atualizadas; asserts `--spiraatlas-rt0` movidos (`詳細エントリ 21316→21192`, `不明な健康関連の行 199→75`) + **2 asserts-trava novos** (`0` unknown call-shapes remanescentes + `0x70A8` motion-data presente). **Honestidade:** classificar ≠ autorizar writer — todo `AtelFieldWriteShape` segue `read-only;not-writer-authority`, `70A8` continua sem botão/escrita, nada promovido pro SIN. **Achado de fidelidade (read-only):** o decoder do EDITOR (`AiScript_File.cs`) **não** glossa `70A8` (ausente de `FieldArgBack`/`関数用のフィールド名`) e o `AiStackModel` não tem a aridade dele → gap de display handoff p/ a lane MAGIC (`docs/ai/HANDOFF_SEYMOUR_ATEL_DECODER_GLOSS_GAP_2026-06-10.md`), sem efeito de gameplay. **PATCH** (refina/classifica catálogo read-only existente, resolve um data-blocker do SIN; precedente `v2.61.3`/`v2.62.1`; 疑問の解消→PATCH）。新しいライターなし；runtime/AURORA/VALEFOR/native-menu/SIN-chain-builder/CHAPPU/saveには影響しない。敵対的ワークフローによる検証済み（3つの反証者＋完全性基準）

ic）。ビルドエラー 0 件／警告 361 件；`--spiraatlas-rt0` +`--aicmdmeta-rt0` +`AiScriptLab --ai2` (346/346) PASS. 文書：`docs/ai/ATLAS_SEYMOUR_ATEL_CALL_SHAPE_AUDIT_RESULT_2026-06-10.md`. [前へ：`v2.65.2`] — ジャービス・セイモア
- **🔧`v2.65.2` — スフィアグリッド：空のノードの冗長コンテンツが保持されている (0xFFFF) ＋ アトラスの出現箇所の修正。** **アトラスの修正 / エビデンスの整理 (Jarvis-BARTHELLO)。** **(A) スフィアグリッドの強化 (バイト単位の正確性):** なし`SphereGrid_File.Builder.cs` (writer LAYOUT v2、ゲート処理：`--spheregrid-layout-rt0`)、執筆・編集のプロセス`AddNode`/`NodeWith` 録音していた`RedundantContent = (ushort)(contentIndex & 0xFF)` → **空**のノード（content`0xFF`) それによって生み出されていた`0x00FF`、出荷時のデータとは異なる。コーパス（scout Jarvis-AURON、**3,444/3,444 ノード**：低位バイト == ContentIndex、高位バイトはExpertの空ノード23個でのみ設定）は、空ノード = **`0xFFFF`**, 満杯 =`0x00<content>`. 新しいプライベートヘルパー`RedundantContentFor(contentIndex)` 「シッパ」という慣習を反映している（empty→`0xFFFF`, filled→`0x00NN`).`FromExisting`/`Clone` コピーを続けてください`RedundantContent` **verbatim** → 編集なしの往復 **バイト単位で同一**（変更なし、ゲートによる再検証済み）。新しいアサートが`--spheregrid-edit-rt0` (合成 + コーパスの3つのグリッド)：`SetNodeContent(idx, 0xFF)` → レイアウトを保存`0xFFFF` node+0x06 + コンテンツバイト`0xFF` + 再読み込みは空。ゲームプレイのリスクが低い（冗長なフィールド；ゲームはコンテンツを`dat09/10/11` + reach-lists — AURON により IDA 検証済み（2 つのバイナリ）、ただし、すでにリリース済みのライターにおける忠実度の不一致である。**(B)**`AiBibleWhereAppears.For` polish (読み取り専用):** ケースを追加しました`aeon-growth` (Atlasドメインは`v2.64.0` （空のフォールバックに陥っていたもの）に、「表示される場所／マッピング」という率直なテキストを追加；更新済み`sphere-grid-node` （以前の記述：「Unknown6 は『未処理／不明』のまま」とされていた）AURONのバーンダウンを反映するため —`Node.Unknown6` **ゲームプレイには影響しない（2つのバイナリでIDA検証済み）**であり、残存する可能性のある要素はメニューのレイアウト／ビジュアル（メタデータのみ）であり、架空のゲームプレイのセマンティクスは含まれていない。 **PATCH**（すでにリリース済みのライターにおける潜在的な忠実度に関するバグを修正 — 「消費者が恩恵を受ける」→ はい、バイト単位の忠実度 — ＋テキストの読み取り専用ポリッシュ；

疑問解消→PATCH）。新しいライターも、新しいUIも、プロバイダーやゲートのカウントの変更もありません（`--spiraatlas-rt0` （無傷）、エンジン`Common` (ANIMA)、runtime/AURORA/VALEFOR/native-menu/SIN、CHAPPU/save、実際のグリッドトポロジー（ノードの作成・移動・再接続は境界に従う）。ビルドエラー 0 件／警告 361 件；`--spheregrid-edit-rt0` +`--spheregrid-layout-rt0` +`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文書：`docs/ai/ATLAS_BARTHELLO_POLISH_RESULT_2026-06-10.md`. [前へ：`v2.65.1`] — ジャービス・バーテッロ
- **🧪`v2.65.1` — PlayerGrowthEditor に Atlas エビデンスバッジを追加 + ラベル「Sphere None/Passive」（読み取り専用、値保護、編集時に非表示）。** **Atlas UI Sweep。** (1) **PlayerGrowthEditor:** 新規`<common:AtlasEvidenceBadgeStrip>` 「Growth Curves」カード（ply_rom.bin）で、すでに作成済みのアクセサを使用する`SpiraDataAtlasCatalog.TryGetPlayerGrowthStat(source, characterIndex, field, currentRawValue)` (`v2.65.0`, TIDUS）。新着`AtlasEvidenceInfo? SelectedCharacterEvidence` no`PlayerGrowthEditor_DataModel`、スロットの入れ替え時に再計算され、`CharacterRowChanged` (編集) → **hide-on-edit**: このバッジは、2つのファイル／カードを網羅する、Growth Gateで実証済みの3つの値に基づいています（`ply_save` HPベース +`ply_rom` AP max + HP coef A — これと同じルックアップが`--spiraatlas-rt0` テスト：520 / 22000 / 6）、そしていずれかのアンカーがバイトベースのコーパスから逸脱した場合、そのストリップは非表示になる（Mixバッジのアンカーと同じ深さ`v2.64.1`/Aeon`v2.64.3`). (2) **Labels Sphere（正直なところ、`partial`):**`sphere.bin ActionValue=0x0000` 現在は **"None / Passive"** と表示され、`RangeValue=0x00` 「Unknown」の代わりに **"None"** と表示される — その`0x00` これはコーパスにおける3番目に妥当な値であり（タッチ効果のない球体の約40％、スカウト：Jarvis-AURON）、決して珍しいものではない。ドロップダウンに「None」という選択肢を追加し、ラベルのフォールバックを修正した。(3) **`AiBibleWhereAppears.For`:** 読み取り専用ケース`player-growth` そして`mix` （「どこに表示されるか」という率直な記述であり、実行時の効果をもたらさないもの；`sphere-grid-node` （すでに存在していた）。**PATCH**（既存機能の再利用：アクセサとエンジンを消費するUI`Common` ANIMAの既存作品＋レーベルの仕上げ；直前の作品：Mixバッジ`v2.64.1`/Aeon`v2.64.3`/ショップ`v2.61.2` PATCHでした；疑問解消→PATCH）。writer novなし

o: SphereGridExplorerのバッジは以前から存在していた（`v2.60.1`), プレイヤーの成長およびスフィアのトポロジーに関するwriter/saveは**変更なし**。provider/gateには手を加えない（`--spiraatlas-rt0` （無傷）、エンジン`Common` （消費のみ）、runtime/Aurora/native-menu/SIN、TIDUS/BRASKA/JECHT/RIKKU/WAKKA/VALEFOR/AURORAも同様。ビルドエラー 0件／警告 361件；`--spiraatlas-rt0` +`--player-rt0` +`--spheregrid-layout-rt0` +`--aicmdmeta-rt0` PASS. 文書：`docs/ai/ATLAS_LULU_PLAYER_GROWTH_SPHERE_BADGE_UI_RESULT_2026-06-10.md`. [前へ：`v2.65.0`] — Jarvis-LULU
- **🧬`v2.65.0` — Spira Data Atlas の「PC/Player Growth」（読み取り専用、`proved-candidate`, バイト単位、作業／独立型）。** プロバイダーにPCの成長／統計の「真の」情報源を追加：新規`SpiraDataAtlasDetailKind.PlayerGrowthStat` + アクセサの値ガード付き`SpiraDataAtlasCatalog.TryGetPlayerGrowthStat(source, characterIndex, field, currentRawValue)`. 出典 = **`ply_save.bin`**（基本／現在の統計）＋**`ply_rom.bin`** (成長ROM：AP曲線`ApReq A/B/C/Max` + 自己成長係数`*CoefA/B`)、まさにその`PlayerGrowthEditor` edita (パーサー`PlayerKernel_File`, RT0による検証済み`--player-rt0`). **20個のスロット**（0–6：PC、7：ゲスト＝シーモア、8–17：エオン、18–19：未割り当て）は、**バイト単位でまとめられたテーブル**（`FfxLib/SpiraDataAtlas/PlayerGrowthData.cs`、生成元：`tools/ffxdataparser_bridge/build_player_growth_index.ps1 -EmitCSharp` 以下の`.bin`)、したがって、これがない「いかなる」ビルドにも存在します`work/` (≠`PcAeonFineStat`、これは～に依存する`work/pc_save_stats_catalog.csv` （スナップショットのみ）。名前は実行時に以下を通じて解決されます`Character_Enum` （単一の真実の源）。**正直さ（一見してわからない点）：**ステータス成長係数は**Aeon限定**である――PC/ゲストの係数はゼロに設定されている（PCは**Sphere Grid**を介してステータスを成長させる）； このROMにおけるPCの成長は、**APカーブ**のみです。軸は`sum_grow.bin` BRASKAによる（オートレベル ≠ カスタマイズレシピ）。**地域限定：**`ply_save`/`ply_rom` **位置不変ではない**（データセクションの`new_uspc` jppc/inpcとは異なります；コンパイルされたテーブル =`new_uspc`（編集者が設定している地域）。ゲーム内の「レベルごとのAP／係数ごとの獲得量」の計算式 = **`RT2-pending`**（検証済みのバイト／フィールド、ランタイム算術演算は逆算されていない）。Value-guard =

エディタの同じ値空間 → フィールドを編集（rawが異なる場合）、不明なスロット/ソース/フィールド → アクセサ`false` → バッジ・サム（ミラー：Aeon/Shop/Mix）。ゲート`--spiraatlas-rt0` `21296 → 21316` (+20; すべて一意) + **18個の新規アサート** (カウント 20/8/10/2; PC係数ゼロ; Aeonの係数はゼロ以外；uspc領域；ルックアップ Tidus BaseHp 520 / ply_rom AP max 22000 / Valefor HpCoef 6；value-guard`9999` 隠す；範囲外スロット／ソース／フィールドミス；ドメイン検索；BIBLEドメインプレイヤー成長）。読み取り専用：**ライター／UI／ランタイム／SINなし**；再生しない`WriteSave`/`WriteRom`,`PlayerGrowthEditor` UI、エンジン`Common` ANIMA（消費のみ）も、BRASKA/AURON/JECHT/RIKKU/WAKKA/VALEFOR/AURORA/SINも。ビルド：エラー0件／警告361件；`--player-rt0` +`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. ドキュメント：`docs/ai/ATLAS_TIDUS_PC_GROWTH_PROVIDER_RESULT_2026-06-10.md` + スカウト`docs/ai/ATLAS_TIDUS_PC_GROWTH_SCOUT_RESULT_2026-06-10.md`. [前へ：`v2.64.3`] — Jarvis-TIDUS
- **🦅`v2.64.3` — カスタマイズエディタ内の「Aeon Growth」エビデンスバッジ（読み取り専用、値保護、編集時に非表示）。** これを`<common:AtlasEvidenceBadgeStrip>` の**「Aeon Grow / Teach」**タブで`CustomizationEditor` (「Recipe Editor」カード)、すでに作成済みのアクセサを使用する`SpiraDataAtlasCatalog.TryGetAeonGrowthRecipe(entryIndex, currentResultRaw, currentItemRaw)` (`v2.64.0`). 新規`AtlasEvidenceInfo? SelectedAeonEvidence` no`CustomizationEditor_DataModel`、選択の切り替え時および選択された行がトリガーされた際に再計算される`RawResult` (`AeonRecipeChanged`) → **hide-on-edit**: 習得したスキル／ステータス、あるいはコストとなるアイテム（値が一致しない場合）、または範囲外のインデックスを編集すると、アクセサが例外を返す`null` そして、そのストリップは（ステールバッジなしで）隠れており、Mixの完全なミラー（`v2.64.1`). 10のスタットレシピにはバッジが表示されています **`partial`** (cost-semantics: エディタは以下のようにレンダリングする`Primary× item`、ただしゲーム内ではコストは1アイテム/使用回です）。**Writerやコスト表示の修正は行わない**（対象外）。エンジンを再利用`Common` ANIMA社製（消費のみ）。PCは継続`blocked` （PCの行なし）およびSphere`metadata-only` (joinなし) — 表示するデータなし。プロバイダー／ゲートに変更なし (`--spiraatlas-rt0` 無傷の、`21296` 詳細 / 77 Aeon）。ビルドエラー 0 件 / 警告 361 件；`--customization-rt0` 

+`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS。JECHT/Mix、TIDUS/PC、AURON/Sphere、RIKKU/WAKKA/VALEFOR/AURORA/SINは再生されません。Doc：`docs/ai/ATLAS_BRASKA_AEON_GROWTH_BADGE_UI_RESULT_2026-06-10.md`. [前へ：`v2.64.2`] — Jarvis-BRASKA
- **🏐`v2.64.2` — ブリッツボールのセーブライター LAB ＋ オフセット SAVE-PROVED と実際のセーブデータ（トーナメントなし）の比較。** ブリッツボールの賞品に関するオフセットは、RE から **save-proved** へと変更されました：実際のセーブデータを見つけました（`Documents\SQUARE ENIX\...\FINAL FANTASY X\ffx_000..006`、7つのスロット`0x6900` =`0x40 header + 0x68C0 SaveData`) および`ffx_000` 正確にデコードされました（「liga」＝メガエリクサー／メガポーション／スピードスフィア、「torneio」＝エリクサー／スーパーゴーリー／ポーションなど）— **暗号化・圧縮なしのプレーンテキスト**を保存 (gil/story/battle_count は正常)、`--base 0x40` 確認済み。ヘッダーの`0x40` 署名がある`"cxs"` + プレイ時間/場所；**どのフィールドもSaveDataのチェックサムと一致しない**（ロック用のチェックサムがない可能性が高いが、ゲーム内でのロードが1回不足している）。新しいライターLAB`Tools/BlitzballSaveWrite.cs` (`--blitz-save-write <in> <field> <value> <out>`): **新しいファイル**に 1 つの prize-index u16 を書き込みます（ソースを上書きすることは決してありません。その場での上書きは拒否します）。before/after は Atlas カタログによって解決されます。のコピーで検証済み`ffx_006`:`tournament0 25 (Elixir) -> 50 (Saturn Crest)`, diff = 正確に 2 バイト、残りはバイト単位で同一。`BlitzballSaveRead.Resolve` ひっくり返った`internal ResolvePrize` （ライターによる再利用）。**セーブデータ (ffx_NNN) ≠ ゲームファイル**：セーブデータを編集すると、この進行状況が変更されます。プールを変更すると（`takara.bin` 220..320) は Treasure/RIKKU です。Atlas UI/Shop/Treasure/Mix/Common/Aurora/Bahamut/SIN には手を加えません。ビルド：エラー 0 件 / 警告 361 件。ドキュメント：`docs/ai/BLITZBALL_SAVE_RUNTIME_WRITER_SCOUT_2026-06-09.md`. [前へ：`v2.64.1`] — Jarvis-WAKKA
- **⚗️`v2.64.1` — Mix Table Editor における Atlas エビデンスバッジ（読み取り専用、値保護、編集時に非表示）。** アクセサを接続した読み取り専用 UI`SpiraDataAtlasCatalog.TryGetMixCombination` (送信日時:`v2.63.0`) の`MixTableEditor`: **「Combination Editor」**カード（詳細パネル）には、現在`<common:AtlasEvidenceBadgeStrip>` 選択された「Mix」の組み合わせについて — 組み合わせごとに1つのストリップ（行ごとではなく；これにより6,328回のルックアップとノイズを回避）、Treasure/Shopと完全に同一。`Mix

TableEditor_DataModel` ganhou `[ObservableProperty] AtlasEvidenceInfo? SelectedMixEvidence` + `RefreshSelectedMixEvidence()` (`TryGetMixCombination(origin.Index, result.PartnerIndex, result.RawResult) → AtlasEvidenceInfo.ForDetail`), chamado em `OnSelectedResultChanged` (cobre troca de combinação E de origin via cascata) e em `ResultChanged` quando `RawResult` muda (cobre edição do resultado via `ResultRef→SyncBack→NotifyComputedChanged` e o "Set Empty"). **Hide-on-edit:** editar o resultado p/ outro item, "Set Empty" (raw 0), célula vazia/espelho do triângulo superior, ou par fora do corpus → accessor `false`/`null` → a strip **auto-esconde** (`IsVisible=false`); ordem `(origin,partner)` irrelevante (canonicalização max/min no accessor). **REUSO** da capacidade `v2.63.0` + da infra `Common` da ANIMA (só consumida) → **PATCH** (precedente: badges UI de Shop `v2.61.2`/`v2.61.5` foram PATCH). Sem writer novo: `--mixtable-rt0` segue **byte-identical** (25108/25108). Não toca o motor `Common` (ANIMA), o provider, Treasure/Shop (RIKKU), BRASKA/WAKKA/AURORA/BAHAMUT/SIN. Revisado por workflow adversarial de **5 lentes** (hide-on-edit, writer/read-only, ANIMA-boundary, XAML-binding, honesty) + síntese → `船`, 0 defeitos. Build 0 erros / 361 warnings; `--spiraatlas-rt0` (Mix 6328) + `--mixtable-rt0` (byte-identical) + `--aicmdmeta-rt0` PASS. Doc: `docs/ai/ATLAS_JECHT_MIX_BADGE_UI_RESULT_2026-06-10.md`. [anterior: `v2.64.0`] — Jarvis-JECHT
- **🦅`v2.64.0` — Spira Data Atlas における Aeon の拡張・カスタマイズ（読み取り専用、`proved-candidate`, イオン限定、コンピレーション）。** プラグを`sum_grow.bin` （FFXの「Aeon」カスタマイズテーブル）プロバイダー上で、詳細種別「読み取り専用」として：新規`SpiraDataAtlasDetailKind.AeonGrowthRecipe` + アクセサの値ガード付き`SpiraDataAtlasCatalog.TryGetAeonGrowthRecipe(entryIndex, currentResultRaw, currentItemRaw)`. **Aeon-ONLY:**`sum_grow.bin` 636バイトです（ヘッダー`0x14` + **77件 × 8B**,`Target` いつも`0x007F`=Aeon,`jppc`==`inpc` バイト同一) → 67 つの ability-recipes (結果カテゴリ 3 → Commands) + 10 つの stat-recipes (結果カテゴリ 0 → StatOptions、Secondary=1)。**PC や Sphere Grid の行は存在しません** (`PcAeonFineStat` これは別のコーパスです。グリッドのトポロジーは

`sphere.bin`/`panel.bin`). **出典なし**`work/`:** 77行は、**バイト単位でコンパイルされた**テーブルから取得されています（`FfxLib/SpiraDataAtlas/SumGrowAeonRecipeData.cs`、生成元：`build_sum_grow_aeon_fine_index.ps1 -EmitCSharp` ～から`sum_grow.bin`)、したがって、これがないビルドであればどれでも`work/` (≠ Mix/Sphere/Shop。これらは`work/`). 名前／ラベルは、実行時に`AeonCustomizationEntry`+出版社独自の辞書（単一の信頼できる情報源、RT0による検証済み）`--customization-rt0`), 決して再発明されることはない。**ステータス・レシピのコスト =`partial`**（エディタがレンダリングします）`Primary× item`; ゲーム内では、1回の使用につき1アイテムのコストがかかり、`Primary` （増加分） — コラムで取り上げられた`evidence` (`;cost-semantics-partial`)、テキストだけにとどまらない。Gate`--spiraatlas-rt0` `21219 → 21296` 詳細（+77 イオーン；すべてユニーク） + **13の新規アサート**（カウント 77/67/10； Aeon限定；PCなし；スフィアなし；ルックアップ能力 66→アルティマ／シュプリーム・ジェム；ルックアップステータス 67→HP+100／パワー・スフィア／コスト・パーシャル；バリューガード`0x9999` 非表示；範囲外のインデックスミス；ドメイン検索；BIBLEドメインaeon-growth）。読み取り専用：writer/UI/runtime/SINなし；RIKKU/WAKKA/JECHT/BAHAMUT/AURORAには影響せず、エンジン`Common` バッジ（ANIMA）も`WriteAeon`/保存パス。**YUNAのバックログのQ1キューのロックを解除**（以前は`blocked`). Scoutにおける4つのレンズを用いた敵対的ワークフローにより検証済み。ビルド：エラー0件／警告361件；`--customization-rt0` +`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. ドキュメント：`docs/ai/ATLAS_BRASKA_SUM_GROW_FINE_SCOUT_RESULT_2026-06-10.md` +`docs/ai/HANDOFF_BRASKA_SUM_GROW_FINE_INDEXER_NEXT_2026-06-10.md`. [前へ：`v2.63.0`] — Jarvis-BRASKA
- **⚗️`v2.63.0` — Spira Data Atlas におけるミックス詳細の種類（読み取り専用、`proved-candidate`, value-guarded)。** 『アトラス』におけるMixの最初の「正直なアンカー」：新作`SpiraDataAtlasDetailKind.MixCombination` + アクセサ`SpiraDataAtlasCatalog.TryGetMixCombination(originIndex, partnerIndex, currentRawResult)` 「parser-canônico」データセットを接続する`work/step0_consolidated_v5/mix_combinations.csv` (**6,328行 = 112×113/2、重複キー0件**) プロバイダーで。その`prepare.bin` これは112×112の**下三角**行列です（原点`O` パートナーのスロットでのみゼロ以外の結果が出る`0..O`)、したがって、各非順序対

ado`{a,b}` 単一の標準セルに存在し、origin=max、partner=min；キー`mix:0x{0x2000+max}+0x{0x2000+min}` 指標から再構築可能である`(origin, partner)` 編集者より **当てずっぽうではなく**。`result_hex` これは、エディタが次のように読み取るのと同じ「little-endian」という単語です。`MixResultRow.RawResult` (エディタのバイト単位で同一のリーダー by`--mixtable-rt0`; 同じエンディアンを持つパーサー） → value-guard = 同一空間での整数比較：結果を編集するとマッチが破られ、バッジが非表示になる（staleなし）；空のセル（raw 0、上部の三角形のミラー全体を含む）はショートカットされる。 **単一ソース：** value-dict + detail は同じ CSV から出力される。Gate`--spiraatlas-rt0` `14891 → 21219` 詳細 (+6,328 ミックス；すべてユニーク） + **8つの新規アサート** (カウント 6328；ルックアップ 0+0→ウルトラポーション)`0x30AC`; 教会法上の順位`(3,1)==(1,3)`; バリューガード`0x9999` 非表示；空のセル raw-0 欠落；テーブル外のインデックス 欠落；ドメイン検索；BIBLE ドメイン mix）。読み取り専用：writer/UI/runtime/SINなし；Mixエディタ（writer）、Treasure/Shop（RIKKU）、エンジンには**影響なし**`Common` ANIMAのバッジ（検索経由でのみ消費される）も、Aurora/Bahamut/native-menuも対象外。**YUNAのバックログのQ2キューのロックを解除**（以前は`blocked`). UI上のバッジのワイヤー = 次のハンドオフ (`docs/ai/HANDOFF_JECHT_MIX_ATLAS_PROVIDER_NEXT_2026-06-10.md`). ビルドエラー 0件 / 警告 361件;`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文書：`docs/ai/ATLAS_JECHT_MIX_DETAIL_KIND_SCOUT_RESULT_2026-06-10.md`. [前へ：`v2.62.1.1`] — ジャービス＝イェクト
- **🏐`v2.62.1.1` — Blitzball セーブデータリーダー／差分表示（読み取り専用）（prize save のスカウト RE）。** 読み取り専用の CLI ツール（`Tools/BlitzballSaveRead.cs` + ディスパッチ番号`Program.cs`) セーブデータを開く`.dat` そして、ブリッツボールの4つのプライズインデックスをデコードし（`league`/`tournament` ×`prize[3]`/`top-scorer`) 再検証済みのオフセット (SaveData @`file+0x40`, BlitzballData @`+0x1984`; リーグ賞 @ セーブデータ`0x1A3C`, トーナメント`0x1A42`, 得点王`0x1A48`/`0x1A4A`)、すでに確定済みのAtlasカタログを用いて各報酬値を算出する。モード：`--blitz-save-read <save>` (decode) および`--blitz-save-diff <before> <after>` (save-compare: 賞品A対B + ファイル全体のバイト差分、BlitzballData内のランをマークし、u16をデコード)`old->new`).`--base` ov

erridable（ディスク上のベースはライブ確認**されていません**）。ベース`SaveData` RVA`0xD2CA90` IDAにより確認された（`sub_785300` 戻る`imagebase+0xD2CA90`) + Fahrenheit + MemoryMap;`sub_8B5450` (memcpy`0x68C0` から`SaveFile+0x40`) ファイルのレイアウトを確認します。**100% 読み取り専用：save/game/RAM への書き込みは一切ありません。** 合成スモークテスト（デコード + リワードの解決 + 変更箇所の特定）で検証済み。 Atlas UI / Shop/Treasure/Mix / Common / Aurora/Bahamut/SINには手を加えていません。ビルドエラー0件 / 警告361件。ドキュメント：`docs/ai/BLITZBALL_SAVE_RUNTIME_WRITER_SCOUT_2026-06-09.md`. [前へ：`v2.62.1`] — Jarvis-WAKKA
- **🔗`v2.62.1` — アイテムショップのバリューガード（単一ソース）（ドリフトの除去＋オペランドのランドマインの固定）。** アイテムショップのバリューガードの強化：プロバイダーは`slot_value_hex` 同じCSVファイルの（`item_shop_command_crosslink.csv`) これが詳細を構成する`atlas:item-shop`、2つ目のファイルの代わりに（`item_shop_slots.csv`) — value と detail は現在、同じ行に表示され、**値が一致しないことは許されない**。ブリッジ`build_spira_atlas_step0c_crosslinks.ps1` 現在、送信中`slot_value_hex` crosslinkのコラムとして、**潜伏している地雷を取り除く**：数学`slot_value + 0x2000` （書かれたのは……の時）`slot_value_hex` （空／生指数）は、以下のように計算されるようになる`0x4000` パーサーがエンコード済みの値全体を出力するようになったので（`0x2000` (p/ Potion) → FALSO と結合`Attack` （AIコマンド） — まさにガードレールのカテゴリのエラーだ。`item_operand_hex` 設計上、空のままとなっている（game-index 項目 ≠ AIのオペランド）。3つの視点（ドリフト／シングルソース、オペランド／エンコーディング、回帰／ギア）による敵対的ワークフローにより検証済み —`sound`; 2件のコメントが修正されました。**マルチレーンに関する注記：** PROVIDERの半分が`v2.62.0` (コミット`2bc3d7b0`, lane WAKKA,`git add` （主要な競合相手）；このコミットには、HEADの一貫性を確保するためのBRIDGEの半分が含まれています。Gearには手を加えていません。writer/UI/runtimeは対象外で、Treasure/Mix/Common/Aurora/native-menuにも変更はありません。ビルド結果：エラー0件／警告361件；`--spiraatlas-rt0` PASS（ショップでのアサート数：ギア5個＋アイテム4個）＋`--aicmdmeta-rt0` PASS. 文書：`docs/ai/ATLAS_RIKKU_ITEM_SHOP_SINGLE_SOURCE_RESULT_2026-06-09.md`. [前へ：`v2.62.0`] — Jarvis-RIKKU
- **🏐`v2.62.0` — ブリッツボール・プライズ・エクスプローラー：UIの再設計

Atlas専用の広告専用モジュール。** 新しいモジュール`Modules/BlitzballPrizeExplorer` （Reference/RE グループ内の **Blitzball Prizes 🏐** タブ、プロジェクトゲートなし）で、すでにクローズされたカタログを参照するもの`SpiraDataAtlasCatalog.BlitzballPrizeDetails` (ドメイン`blitzball-prize`): **prize id · takara index · reward resolved · kind · evidence** の列を持つ検索可能な DataGrid、ステータス／証拠および種類によるフィルタ、**ルール** を表示するバナー`prize 0..100 -> takara 220..320 -> reward`**（オフラインの検証済み候補）、およびソース／ルール／「表示される場所」／制限事項を含む詳細パネル +`<common:AtlasEvidenceBadgeStrip>` (Atlas/BIBLEのバッジ)。誠実さを保つ：treasure =`proved-candidate` (RT2は決してない); リーグ・トーナメント・イベントの64のスクリプトサイトは、明示的に次のように表示される`blocked` (イベントごとの報酬はランタイム/セーブ); tech =`partial`; オーバードライブ =`metadata-only` — 現在のラベル以外は何も緑色にはなりません。新しい読み取り専用アクセサ（小文字）`SpiraDataAtlasCatalog.BlitzballPrizeDetails` (lazy, dev`work/` (only) + ゲート内のアサート2つ`--spiraatlas-rt0` (229行 = カタログ164件 + サイト64件 + ガードレール1件；ドメインチェック)。ライターなし、ランタイムなし；RIKKU/Shop/Treasure/Mixは動作せず、エンジン`Common` ANIMA（消費のみ）も、Aurora/Bahamut/SINも。ビルド：エラー0件／警告361件；`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文書：`docs/ai/ATLAS_WAKKA_BLITZBALL_UI_RESULT_2026-06-09.md`. [前へ：`v2.61.5`] — Jarvis-WAKKA
- **🛍️`v2.61.5` — アイテムショップの「アトラス・エビデンス・バッジ」（バリューガード付き） — ギアとアイテムの組み合わせを完成させる。** ギアショップで実証済みのバリューガードを複製する（`v2.61.2`) アイテムショップへ、さて、`v2.61.1`+コーパスのロック解除により、アイテムにバイト単位で1:1の生の値が割り当てられました。新しい読み取り専用アクセサ`SpiraDataAtlasCatalog.TryGetShopItemSlot(bank, slot, currentRawValue)` + lazy`_shopItemSlotValues` (読む`item_shop_slots.csv`, dev`work/` only、コンパイル済みフォールバックなし） — の完全なミラー`TryGetShopGearSlot`: 解決する`atlas:item-shop:item-shop-0x{bank}-slot-{n}` **ただ**、その`RawValue` スロットの現在の値は、コーパスとまだ一致している（ディスク上のushort LE = game-index Items`0x2xxx`（エディタの同じ場所）であり、かつ ≠ 0 である。`ShopExplorer_DataModel` 現在、計算中`Evidence` shop-kind（スイッチ・ギア／アイテム）による；o`<common:AtlasEvidenceBadgeStrip>` カード上

**すでに共有されていた**スロット（`v2.61.2`)、これにより、XAMLを変更することなくアイテムにバッジが表示されるようになりました。スロットを編集すると、行が再構築され、ストリップが非表示になります（ステール状態にはなりません）。Gate`--spiraatlas-rt0` **4つのアイテムアサート**を獲得しました（ルックアップ`0x2000`/ポーション、ミスマッチ`0x9999` 隠し、空のスロット raw 0、no-corpus スロット 3）、すべて PASS（ギアは引き続き PASS）。再生成`work/step0_consolidated_v5/item_shop_slots.csv` com`slot_value_hex` (404/404、開発者専用、コミット未実施)。読み取り専用：ライターなし、Treasure/Mix/Common/Aurora/native-menu/runtimeには手を加えない；エンジン`Common` ANIMAのものはすべて消費済み。ビルド：エラー0件／警告361件；`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文書：`docs/ai/ATLAS_RIKKU_SHOP_ITEM_BADGE_UI_RESULT_2026-06-09.md`. [前へ：`v2.61.4`] — Jarvis-RIKKU
- **🎮`v2.61.4` — WIREDのネイティブメニューシェル`ffx-hooks.dll` （ステップ5を適用、デフォルトではOFF）。** ステップ5.1のパッチ（敵対的レビュー済み、ブロッカーなし）が **適用** されました。`dllmain.cpp` （最小パッチ：のみ`dllmain.cpp`, +166行, 0件の削除) — を有効にする`NativeMenuShell.h` （「NOSSO」というテキストが表示されたネイティブメニュー）からオーロラのブリッジへ（`PhotoModeActions.h`) ポンプを経由する迂回路`FFX_Menu_PerFramePump 0x8A9C50` (`int __cdecl(uint)`, IDA検証済み、メインスレッド）。**デフォルトではOFF：**`FFXHOOKS_ENABLE_NATIVE_MENU=1` 迂回ルートを設定します。メニューはホットキー **F7** でのみ開きます。**「オーロラ契約」は承諾し、遵守します：**`PhotoMode::Tick()` = **選択肢A**（上部`AuroraD3DRender`、早期返却の前に、`FFXHOOKS_ENABLE_AURORA_OVERLAY=1`, hunk AURORA-owned); FREEZE = 唯一の所有者`g_pm.frozen`;`NtSuspendProcess` **禁止**；`PhotoMode::g_base=g_base` init では、wire は **単に呼び出すだけ**です`PhotoMode::*`** — **RAMカメラとは書かない（`0xD378A0`) も、RAM**も使用しません。ビルド`-WithPolyHook -Release` **PASS** (`dllmain`+`MusicHook`+`ElementHook` →`ffx-hooks.dll`). **ステップ 6A/NPC は**、このパッチでは**除外されました**。**RT2-保留中：** メニュー内またはフィールド内で F7 キーを押すと、ネイティブの「フォトモード」ポップアップが表示されるはず（一時保存）。ドキュメント：`docs/ai/HANDOFF_BAHAMUT_NATIVE_MENU_WIRE_BLUEPRINT_2026-06-09.md`. [前へ：`v2.61.3`] — ジャービス・バハムート
- **📒`v2.61.3` — Atlasプロバイダー：`BlitzballPrizeRef` 76行にわたる生のスクレイプデータの代わりに、正規化された（読み取り専用）データを使用します。** `SpiraDat`のprizeセクション

aAtlasCatalog` deixou de varrer `bltz0200/0201` cru e passou a ler o dataset normalizado do WAKKA (`work/step0_blitzball_prize_ref_2026-06-09`): **164 prize-index rows** (101 treasure `合格候補者` via `prize+220 -> takara 220..320 -> reward`, fechado por 3 fontes offline — Fahrenheit `blitz_prize.cs` + `bltz0201 obtainTreasure` + `bltz0200/0201 Treasure-Label` — sobre takara RT0; 60 tech `partial`; 3 overdrive `メタデータのみ`) + **64 script-sites `ブロックされた`** (prêmio por-evento é variável de runtime/save). Guardrail reescrito: regra `合格候補者` offline, prêmio concreto por liga/torneio `ブロックされた`, nunca RT2, nunca writer. Gate `--spiraatlas-rt0` subiu de `14739` para **`14891`** detalhes (`BlitzballPrizeRef 76 → 228`) e ganhou asserts data-grounded (treasure 101 / tech 60 / overdrive 3 / sites 64; prize 0 -> takara 220 Hi-Potion; prize 100 -> takara 320 Phoenix Down; treasure `合格候補者`-não-RT2; overdrive `メタデータのみ`; site `ブロックされた`). Patch verificado por review adversarial de 4 agentes antes de aplicar. Sem UI, sem writer, sem SIN/runtime; não toca Shop/Treasure/Mix (RIKKU), o motor de badges `Common` (ANIMA) nem Aurora/native-menu. Build 0 erros / 361 warnings; `--spiraatlas-rt0` + `--aicmdmeta-rt0` PASS. Doc: `docs/ai/ATLAS_WAKKA_BLITZBALL_PROVIDER_INTEGRATION_RESULT_2026-06-09.md`. [anterior: `v2.61.2`] — Jarvis-WAKKA
- **🏷️`v2.61.2` — Shop Explorer の Atlas エビデンスバッジ（ギア専用、バリューガード付き）。** 以下の機能と連携する読み取り専用 UI`TryGetShopGearSlot` （～で実証済み）`v2.61.1`) の`ShopExplorer`: **gear-shop**の各スロットには、以下が表示されます`<common:AtlasEvidenceBadgeStrip>` そのスロットの装備報酬の「出現場所」/バッジ — **その間のみ**`RawValue` 現在のものは依然としてコーパスと一致している。`ShopEditableSlotRow.Evidence` (`init`) は、`From()`:`source.Kind == Gear && TryGetShopGearSlot(entry.Index, slot.SlotIndex, slot.RawValue)`. 行は、あらゆる変更（ComboBox／空に設定／元に戻す／破棄／保存／更新）のたびに再構築されるため →`RebuildSelectedSlots`)、スロットを編集するとエビデンスが再計算され、**ストリップが非表示になる**（ステールバッジなし）。**アイテムショップにはバッジが付与されない**（ガード`Kind == Gear` + ダブルガード：コーパスに当該項目のエントリがない）；スロットが空

o (raw 0) がショートする。3つのレンズを用いた敵対的ワークフロー（網羅的なライフサイクル／item-shop+binding／honesty）により検証済み → すべて`sound`, 欠陥0件。インフラの再利用`Common` ANIMA（エンジンには手を加えない）；新しいライターなし、新しいパーサーなし、SIN/runtime/Aurora/native-menuなし。Tier`parser-corpus`+`RT0`+`read-only`、決して`proved` 実行時。ビルド 0、エラー 0 件／警告 361 件；`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS（ゲートなし）`--shop*` no`Program.cs`). ドキュメント：`docs/ai/ATLAS_RIKKU_SHOP_GEAR_BADGE_UI_RESULT_2026-06-09.md`. [前へ：`v2.61.1`] — Jarvis-RIKKU
- **🛒`v2.61.1` — ギアショップの「アトラス・バリューガード」スロット（`proved-candidate`) + アイテムショップ（正直に言うと）`blocked`.** ショップのスカウト第2ラウンド (`HANDOFF_ATLAS_RIKKU_SHOP_SLOT_VALUE_INDEXER`): 「Treasure」で実証済みの「value-guard」を「Shop」でも有効化する。8名のエージェント（フォレンジック5名＋アダーサリアル2名＋合成1名）によるワークフローで確認済み：`RawValue` エディタ上のスロットは、ディスク上の生のリトルエンディアン形式のushortです（`ShopTable_File` ≡`ReadBaselineSlotValue`), そして`slot_value_hex` の`gear_shop_slots.csv` (445/445 居住者、指数`shop_arms.bin`) まさにその単語そのものです — つまり、guard は同じ領域内での整数比較であり、**オフ・バイ・ワン** はありません（カタログ`MinIndex=0`, インデックス 0 = NULL 入力用（予約済み）、最初の販売可能ギア = インデックス 1 =`0x01`). 新しい読み取り専用アクセサ`SpiraDataAtlasCatalog.TryGetShopGearSlot(bank, slot, currentRawValue)` + lazy`_shopGearSlotValues` (dev`work/` only、コンパイル済みのフォールバックなし、Sphere Gridノードと同様）：解決済み`atlas:gear:gear-shop-0x{bank}-slot-{n}` **のみ**、スロットの現在の値がコーパスと一致している場合（かつ ≠ 0）→ スロットを編集するとバッジが非表示になる（ステールなし）。ゲート`--spiraatlas-rt0` **5つの耐久性のあるアサート**を獲得した（ティダスのルックアップ成功／値 1、バリューガードの不一致 999 が隠れる、空のスロット raw 0、コーパスのないバンク、エッジ`0x2E`/427)、すべてPASS。**Item-shop =`blocked`**: コーパスには生データは保存されません（`item_shop_slots.csv.slot_value_hex` 100% 空 —`ItemShopDataObject.toString()` （名前のみを出力する）；string-guard はフェイクセーフではない（ポーション／フェニックスダウン／解毒剤 x47 → ステール；プレースホルダー＋米国版対日本版 → 偽陰性）。 Unlock = パーサーへの1行のパッチ適用 + 再実行（コーパス処理タスク、このコードの範囲外）

. 正直な評価：`proved read-only candidate (parser-corpus + reader-semantics + RT0)`, **決して**`runtime`/`byte-grounded` (なし`arms_shop.bin` （ここでヘックスダンプされました）。UIも、ライターも、SINも、ランタイムもなし。エンジンには一切手を加えずに`Common` (ANIMA)。ビルド：エラー 0 件 / 警告 361 件；`--spiraatlas-rt0` +`--aicmdmeta-rt0` PASS. 文書：`docs/ai/ATLAS_RIKKU_SHOP_SLOT_VALUE_INDEXER_RESULT_2026-06-09.md`. [前へ：`v2.61.0`] — Jarvis-RIKKU
- **🐉`v2.61.0` — ネイティブメニュー ステップ3：ネイティブリストのrow-sourceを再閉じ +`list-read` (probe) + ライブでの選択読み取りの検証。** ネイティブのゲーム内メニューのレーン（Yojimbo→**Jarvis-BAHAMUT**）の調査を継続し、ステージ3のギャップ#1（「ネイティブリストの行はどこから来るのか？」）がIDAによって解消されました。リストの**INPUT** (`FFX_Menu_List_UpdateInput 0x8B4460`)は**100%汎用**である — 152Bのオブジェクトフィールドの純粋な算術演算（`+40` state,`+48` count,`+50` トップ,`+52` target,`+58` ページ、`+66` スロット、`+69` 結果、`+70` スクロール、`+72` selected,`+28` validator)は、**グローバル変数には一切触れない**上、**10個の異なるビルダー**によって再利用される。しかし、**すべてのネイティブdrawはitem-shapedである**：scene3リスト（`FFX_Menu_CreateScene3ScrollableList 0x8B4FB0` → 描く`0x8B4A00` → 行`0x8B4B20`) は、`unk_159EC30[64*i]` (64Bの構造体) +`byte_1866250[]` (タイプ)、**項目名**は以下によって決定される`0x86C3C0(id→tabela)` およびオプションのラベルを直接`rowPtr+32` (タイプ1)；scene3/33/34を読み込み、Customizeのグローバル変数に依存する。バイナリには「フリーテキストリスト」の描画機能は**存在しない**――つまり、我々が作成したテキストを含むネイティブリスト（アリーナのシェル／Auroraのフォトモード） **DLLからのドローコールバックが必要**（ステップ5、『バイブル』§4で想定されている手順）であり、**文書化された独自実装**（汎用入力）`0x8B4460` + プリミティブを用いたDLLの描画`sub_8F5F70` ウィンドウ /`sub_9016B0` 文字列 /`sub_8C0640` カーソル、読み込み中`+69`/`+72`). 本日、プローブ経由で配信：新しい動詞 **`ffxprobectl list-read [handleHex]`**（読み取り専用）で、**メニューオブジェクトのPOOLを**スキャンする**（`g_FFX_MenuObjPool 0x18408C0`, 32 スロット × 152B) — アクティブなネイティブのリストやポップアップを「すべて」検出し、コールバックによってそれらを識別します — ショートカットのグローバル変数に加えて (`dword_1866214`/`186A5DC`/`23CC120`). **✅ RT2 PASS（ライブ、2026年6月9日

):** **装備のカスタマイズ**画面で、プールスキャンがナビゲートされたリストを取得しました（slot[3]`@0x017A0A88`,`input=0x8D57E0` = のラッパー`0x8B4460` （汎用）および`+72`/`SELECTED` **カーソルの動きをリアルタイムで追跡（35→42）** しながら、Halysonが操作 → ステップ3「ナビゲーション可能なネイティブリストから選択項目を読み取る」を **何も入力せずに実証**。（おまけ：`+62 = group 0x101` リセットされたオブジェクトの値が一致する`FFX_MenuObj_Reset` (IDA) — メモリに対するオフセットが確認されました。）カメラのRAMには触れない / Aurora /`dllmain.cpp` / 保存；IDA 読み取り専用（コピー`_claude_ida`（ドキュメントの「rename-queue」参照）。ビルドの`ffxprobectl` エラー0件。**ステップ5（ブループリント）：** ネイティブシェルの貼り付け可能なスケルトンを`RuntimeTools/NativeMenuShell/NativeMenuShell.h` (+README) — オブジェクトの手動実装 + 描画コールバック（ウィンドウ＋行＋カーソル） + フォントエンコーダー + Auroraのフォトモード機能向けに分離されたブリッジ； ABI/オフセットが確認済み（IDAによる検証ワークフロー）かつ**敵対的検証済み**（FFX-vs-IDAの2つの視点＋C++ → クラッシュ・コンパイルエラーなし）；x86ガード＋OOB防止クランプ＋注釈付きロードベアリング不変条件； **ワイヤードではない、触れない`dllmain.cpp`**. **ステップ 5.1（ワイヤーブループリント、適用なし）：** 平面図 + パッチ草案（`docs/ai/HANDOFF_BAHAMUT_NATIVE_MENU_WIRE_BLUEPRINT_2026-06-09.md` +`docs/patches/BAHAMUT_NATIVE_MENU_WIRE_DRAFT_2026-06-09.patch`) 皮を`ffx-hooks.dll` ポンプ経由の迂回路`FFX_Menu_PerFramePump 0x8A9C50` (`int __cdecl(uint)`, IDA検証済み、メインスレッド) — デフォルトではOFF (`FFXHOOKS_ENABLE_NATIVE_MENU` + ホットキー F7）、bridge は呼び出すだけ`PhotoMode::*`; 対立的レビュー済み（2つのレンズ）**ブロッカーなし**（コンパイルレビュアーがスクラッチツリーに適用し、`git apply --recount --check` exit 0);`dllmain.cpp` 未処理／未コミット。ドキュメント：`docs/reverse/FFX_NATIVE_MENU_LIST_ROW_SOURCE_2026-06-09.md`. [前へ：`v2.60.2`] — ジャービス・バハムート
- **💰`v2.60.2` — Treasure Editorにおけるアトラス・エビデンス・バッジ（ギアチェスト）＋Treasureのクロスリンクの適切な修正。** スカウト`HANDOFF_ATLAS_RIKKU_TREASURE_SHOP_MIX_CROSSLINK_SCOUT` 「Treasureには安定した鍵がない」という件について、`v2.60.1` そして、装備用トランクについては**その反対を証明した**：その`source_key` クロスリンクの`treasure-buki-get` 不透明ではない――それは`treasure:0x{index:X4}`,

エディタの行インデックスから直接再構築可能。バイト単位の照合：`(treasure_index, buki_get_id)` クロスリンク ≡`(logical_index, type)` から`takara.bin` **82行のKind=0x05、0件の不一致**について。新しい読み取り専用アクセサ`SpiraDataAtlasCatalog.TryGetTreasureGear(treasureIndex, expectedBukiGetRow)` 解決する`atlas:gear:treasure-0x{index}` **value-guard を使用する場合**：Treasure は編集可能なモジュールであるため、バッジは`buki_get` 現在の宝箱は依然としてコーパスと一致している――Kindを再配置／交換すると、ストリップが非表示になる（ステールバッジなし）。「Gear Pickup / buki_get」カードに適用され、`TreasureEditor` 経由`AtlasEvidenceInfo.ForDetail` +`<common:AtlasEvidenceBadgeStrip>` (バッジ`parser-corpus`+`RT0`+`read-only`、決して`proved`). **Shop**は`partial` (位置指定キー`0x{banco}:slot:{n}` 安定していて再構築も可能ですが、アイテムショップでは入手できません`display_text` また、gear-shopにはスロットごとのインデックスがないため、編集可能なモジュールには明確なvalue-guardが存在しない（→ 誤検知のないUIの実装が延期された）。**Mix**は`blocked` （アトラスには「Mix」という詳細種が存在しない。作成すれば、アンカーを新たに作り出すことになる）。**BukiGet** = 冗長／1対多（すでにtakaraを自己参照している）。Gate`--spiraatlas-rt0` 3つの耐久性のあるアサート（ルックアップ成功＋バリューガード＋ノンギアミス）を獲得し、すべてPASSとなった。ライターもSINもランタイムも使用せず、バッジエンジンの`Common`. ビルドエラー 0 件 / 警告 361 件;`--spiraatlas-rt0`,`--aicmdmeta-rt0` そして`--treasure-rt0` PASS. 文書：`docs/ai/ATLAS_RIKKU_TREASURE_SHOP_MIX_CROSSLINK_SCOUT_RESULT_2026-06-09.md`. [前へ：`v2.60.1`] — Jarvis-RIKKU
- **🔮`v2.60.1` — スフィアグリッドエクスプローラー上のアトラス・エビデンス・バッジ（2つ目の読み取り専用アプリケーション）。** バッジのインフラストラクチャは`v2.60.0` 2つ目のホームを獲得しました：でノードを選択すると`Sphere Grid Explorer`、パネルにはエビデンスのバッジが表示されています（`parser-corpus` +`RT0` +`read-only`), ノードの起源および「出現場所」、via`AtlasEvidenceInfo.ForDetail` +`<common:AtlasEvidenceBadgeStrip>`. 新しい読み取り専用アクセサ（小文字）`SpiraDataAtlasCatalog.TryGetSphereGridNode(layout, nodeIndex)` (鏡`TryGetMonsterDetail`) マッピングする`SourceKind` (オリジナル／スタンダード／エキスパート →`OSG`/`SSG`/`ESG`) + ノードのインデックスを`atlas:sphere-grid-node:{layout}:{index}` — id idên

カタログの仕様と一致すれば、ノードは正常に機能する。いずれのミッションにおいても、ストリップは（偽のバッジなしで）**隠れる**。**クロスリンクの整合性（Halysonによって強化されたルール）：**要求された4つのモジュールのうち、安定したクロスリンクを持つのはSphere Gridのみである。`Treasure` (`sourceKey` 不透明で、buki_getインデックスの値は元に戻せない）、`Shop` (アトラスのキーは「バンク＋スロット」で、その`item_operand_hex` アイテムには空の値が渡される（オペランドによるマッピングを行うとカテゴリエラーとなる））および`Mix` （アトラスには「Mix」の詳細種別が存在しない）**意図的に除外された** — そこでバッジを強制すると、「安定したクロスリンクがない → 非表示」というガードレールに違反してしまう。 ライターなし、SINなし、ランタイムなし、バッジエンジンには手を加えずに。ビルド結果：エラー0件／警告361件；`--spiraatlas-rt0` PASS（2493個のスフィアグリッドノード）および`--aicmdmeta-rt0` PASS。敵対的エージェントによる検証：不具合0件。[前回：`v2.60.0`] — Jarvis-MAGIC
- **🏷️`v2.60.0` — Monster AI Editorに適用された、再利用可能な読み取り専用「Atlas evidence badges」。** 第1層の`HANDOFF_ATLAS_READONLY_MODULE_BADGES`: 再利用可能なエビデンスバッジのコンポーネントで、各項目ごとにデータの出所と信頼できる範囲を表示します。ライターも、適用も、SINも不要です。新機能`Modules/Common/AtlasEvidenceBadgeStrip.axaml(.cs)` (プロパティを持つドロップイン UserControl`Evidence`) +`Modules/Common/AtlasEvidenceBadge.cs` (`AtlasEvidenceBadge` 重症度による色分け +`AtlasEvidenceInfo` バッジ/出典/「表示される場所」、ファクトリー`ForBibleEntry`/`ForDetail`). **重要な決定（対立的レビューの後）：** エンジンは1つだけ――その`AiBibleEvidence` は、以下のように設定されました。`Derive(...)` また、このストリップは、以下の方法を通じて公式のバッジを再利用しています`entry.EvidenceBadges`, したがって、Monster AIのインラインストリップとBIBLEのフルウィンドウは**決して一致しない**；`IDA` 構造的なバッジは引き続き独立したままであり、**決して**反転することはない`proved` 緑（レビューで不具合を発見し、修正済み）。トークンを追加しました`partial` ミッションで求められたもの。「ゲーム内のどこに表示されるか」は`AiBibleWhereAppears` （BIBLEとモジュール間のDRY単一ソース）。BIBLEのインラインパネルに適用され、`Monster AI Editor`: 選択した項目に対して、バッジ + 出典 + 「表示場所」の展開機能；（以前から存在していた）**📖 完全ガイドを開く** ボタンをクリックすると、その項目に焦点を当てたBIBLEが開きます。ランタイム、SIN、保存パス、またはprovideには一切触れません

r`SpiraDataAtlasCatalog`. ビルドエラー 0 件 / 警告 361 件;`--spiraatlas-rt0` そして`--aicmdmeta-rt0` PASS;`AiScriptLab --ai2` PASS（バリデータ クリーン 346/346）。[前回：`v2.59.0`] — Jarvis-MAGIC
- **📚`v2.59.0` — BIBLE OF SPIRA / Atlas UI 2.0：マルチバッジによるエビデンスのナビゲーション + フィルター + ソースパネル（読み取り専用）。** ウィンドウ`BIBLE OF SPIRA` 新たな執筆者を一切起用することなく、エビデンスに基づく健康情報ナビゲーションの充実したコンテンツが追加された。`AiBibleEntry` 現在、Atlasからの構造化された出所情報を読み込んでいます（`SourcePath`,`WriterPolicy`,`DetailKind`) および唯一のエビデンス・トークンの発行元（`AiBibleEvidence`) 既存の分野のみに基づいて導き出されたものであり、決して証拠をでっち上げることはありません。各項目には**マルチバッジ**が表示されています（`blocked`,`RT2`,`IDA`,`proved`,`RT0`,`parser-corpus`,`presence-index`,`metadata-only`,`semantic-candidate`,`RT2-pending`,`read-only`) 重症度に応じた色分けと、正確性を保つツールチップ（`RT0` = Atlasのパース／カタログの整合性であり、実行時の権限ではない；`parser-corpus` （構造／存在の証明、効果ではない）。新しい**証拠**フィルター（`Todas`,`Proved/RT0`,`Parser corpus`,`Metadata-only`,`Blocked`,`RT2 pending`) は、「タイプ／ドメイン」および検索結果（件数付き）と連鎖的に連携しています。『アトラス』に由来する項目には、**「アトラス：由来と方針」**というパネルが設けられており、`Domain`,`DetailKind`,`WriterPolicy` そして`SourcePath` （生のCSVデータは出力しない）。**「ゲーム内の出現場所」**は、ドメインごとに適切な言葉で書き直されました（`monster-presence` = トレーニングの参加状況／枠の有無であり、行動ではない；`sin-eligibility` = 待ち行列、未承認；`gear-name-model` = 行の`w_name.bin`、報酬の最終名称ではない；`blitzball-prize` = メタデータのみ; Sphere`Unknown6` = 未加工／不明）。検索では、以下の形式も受け入れられるようになった`metadata-only`/`blocked`/`RT2-pending`/`domain:*` トークンを介して`SearchBlob`. 一時ビルド：エラー 0 件 / 警告 361 件；`--spiraatlas-rt0` そして`--aicmdmeta-rt0` PASS (`979/867/112`). ランタイム、SINライター、またはプロバイダーには一切触れない`SpiraDataAtlasCatalog`: 閲覧・UXのみ。[前へ:`v2.58.0`] — Jarvis-MAGIC
- **🛰`v2.58.0` — エディタ内のAurora Overlay Lab：永続的な設定`ffx-hooks.dll`.** 新しいモジュール`Live Tools -> Aurora Overlay Lab` ランタイムオーバーレイを制御するために

そして、……によって`modules\config\aurora_overlay.ini`、古いフラグを同期させながら（`aurora_overlay.flag`,`aurora_overlay_d3d11.flag`,`aurora_w2s_sniff.flag`) および、GDI/D3D11モード、W2Sスキャン、D3Dスニフ、予算/クールダウン、リフレッシュなどのノブを表示し、`Auto-pause hits`. DLLは`.ini` 起動時に、環境変数をオーバーライドとして保持し、`d3d_sniff_autopause_hits=3` D3Dフォールバックのマトリックスがまだ有効なうちに、コンスタントバッファの徹底的な検査を一時停止する。パネルはゲームルートを正規化し、`FFX.exe`/`modules`, DLL/config/log を表示し、開く`%TEMP%\ffx-hooks.log`, Steam appid を通じてリリース`359870`, が`FFX.exe` vivoは別のルートにあり、設定の書き込み時のI/Oエラーから保護しています。前回のランタイムテスト：FFX vivoにおけるD3D11のインフレームラベル。今回のテストでエディタビルドの有効性が確認されました。`0 Erro(s)` /`361 Aviso(s)` およびDLLのデプロイ。[前へ：`v2.57.0`] — ジャービス・コーデックス
- **⚔`v2.57.0` — カスタムボスクリエーター：ドロップ1/スティール/賄賂用の「アドバンスト・ルート（light）」。** ステータスパネルに、オプションのオーバーライド機能を備えた **「アドバンスト・ルート」** カードが追加されました。`Drop1` 一般的／まれ、`Steal` 一般的／まれ、および`Bribe`: アイテムID、数量、および存在する場合のraw確率。空欄または無効なフィールドは、`Loot usado`; **プレビュー / 差分**では、名前は以下を通じて解決されます`Item_Dictionary` そして、次のような変化が見られます。`Potion x1 → Dark Matter x2`、さらに継承される無効なフィールドを一覧表示します。クローン機能は現在、以下を適用します`LootFile` コピー／継承された全体、さらにその上に、`Gil/AP` + ドロップ1／スティール／軽微な賄賂；`.bossrecipe.json` これらのオーバーライドは、入力されると保存されます。正直なところ：`Drop2`、オーバーキルのドロップやギア／アビリティプールは、モンスターエディタ／次回のカットでも引き続き実装されます。ビルドエディタ：エラー0件／警告361件。[前回：`v2.56.0`] — ジャービス・コーデックス
- **🧠`v2.56.0` — Monster AI Editor：フィールド／ステータスの設定 + 「トリニティ／BIBLE」の最終調整。**「MONSTER AIのトリニティ」**という見出しを中央揃えにし、ワークフローの目立つ見出しとした。`AEON observa · BIBLE ensina · SIN cria`. Workbenchの微調整エリアに**Plantar field/stat**カードが追加されました：任意の`btlActorProperty` の`AiChrPropertyNames`、小数点以下の桁数を選択するか、`0xNN`, そして`onTurn` 正しい方法でバックアップを行う`PUSHII <field> · PUSHII <value> · CALLPOPA 70AB` (`setStatField(field,value)`, `actorRef`なし

`, sem confundir com `writeChrProperty`). O default prioriza `OverdriveMax`, `オーバードライブ電流`, `showOverdriveBar` e reações de hit, exatamente para casos tipo Dark Shiva/overdrive. A BIBLE inline recebeu cores de seleção/detalhe mais coesas com Spira/FFX e deixou de parecer um bloco de terminal colado. Build editor 0 erros / 361 warnings. [anterior: `v2.55.4`] — Jarvis-Codex
- **⚔`v2.55.4` — カスタムボスクリエーター：`Loot usado` 明示的な選択肢となる。** 左側の列には、モード付きの**「使用済み戦利品」**カードが追加された。`Herdar loot da base` または`Copiar loot de outro m###`、独自のフィルター、ソース一覧、およびGil/AP、ドロップ/スティール/賄賂、Raw確率を含む技術概要。戦利品のソースを変更すると、各フィールドは`Gil`,`AP` そして`AP Overkill` 選択したブロックに追従し、さらに手動で上書きすることも可能です。`Criar Monstro` これで、`LootFile` 往復で保持された整数を、その上に単純な報酬を再適用する；`.bossrecipe.json` 記録する`LootSource` (`inherit-base-loot`/`copy-monster-loot`) そして、その選択をインポート／エクスポートで往復処理します。**プレビュー／差分**では、最終的なIA、最終的な戦利品が表示されるようになり、報酬と実際の戦利品を比較できるようになりました。ビルドエディタ：エラー0件／警告361件。[以前：`v2.55.3`] — ジャービス・コーデックス
- **⚔`v2.55.3` — カスタムボスクリエーター：闇雲にステータスを入力する手間を省くためのボスプリセット。** タブには、ステータスの上に **ボスプリセット** ブロックが追加され、5つのアクションが用意されています：`Dark Lite`,`Tanque`,`Canhão`,`Veloz` そして`Herdar tudo`. プリセットは`m###` ベース値を基に、HP/MP/オーバーキル/ステータス/ModelId、およびギル/AP/APオーバーキルを、クランプ付きの乗数で計算します。この際、乗算の連鎖を防ぐため、常にベース値から計算を開始します。`Herdar tudo` 数値のオーバーライドをクリアして、レシピを軽量化します。プリセットをクリックしても何も保存されません。**Preview / Diff** カードには、実行前の結果が表示されます。`Criar Monstro`. ビルドエディタ：エラー 0件／警告 361件。[前回：`v2.55.2`] — ジャービス・コーデックス
- **⚔`v2.55.2` — カスタムボスクリエーター：ボス作成前のプレビュー／差分表示。** ステータスパネルに「**プレビュー／差分**」タブが追加され、ベース、ターゲット、名前、AIソース、ステータス、報酬を変更すると自動的に更新されます。プレビューでは、最終結果と`m###` ベースと表示`base → novo` 引越し専用

HP/MP/オーバーキル/ステータス/ModelId/ギル/AP/APオーバーキルの実際の値。入力されたフィールドが無効な場合、書き込みの前に「継承」と表示されます。また、宛先も要約されます。`m### → m###`、最終的なAI（他のモンスターのプロフィールを継承または丸ごとコピー）であり、ターゲットIDがすでに存在する場合に警告を表示します。新しいライターは使用せず、盲目的な作成を減らすための正直な読み取り／プレビュー機能です。ビルドエディタのエラー数：0、警告数：361。[以前：`v2.55.1`] — ジャービス・コーデックス
- **🧠`v2.55.1` — Monster AI Editor：AEON/BIBLE/SINのトリニティ＋上部にクイックSIN。** 画面では、モジュール内のトリニティが視覚的に分離されるようになりました。**AEON**はコンパクトなvanillaのdiff/restore帯となり、**BIBLE OF SPIRA**は要約の横にある読み取り専用のATELマニュアルとして残っています。`O que este monstro faz`、そして**SIN / Spira Instinct Network**が、ワンクリックで素早くプリセットを切り替えられるパネルとして追加されました。Workbenchは下部の微調整機能（現在のAIリスト＋挙動の追加・変更）となり、スキルピッカーにはカテゴリが追加されました`Todas` Character/monmagic1/monmagic2を統合した結果、アクションボタンにはコントラストとアイコンが追加され、DevKitは最後尾に単一の黒いテクニカル・エキスパンダーとして配置されました。独自のステータスプリセットには、Shell、Regen、およびNulBlaze/NulTide/NulShock/NulFrostが以下を使用して含まれるようになりました。`writeChrProperty` およびのフィールド`AiChrPropertyNames`; 新しい並列ライターなし。ビルドエディタ：エラー0件／警告361件。[前回：`v2.55.0`] — ジャービス・コーデックス
- **⚔`v2.55.0` — カスタムボスクリエーター：UI上でのボスレシピのインポート／エクスポート／往復処理。** 左側の列に、ボタン付きの「**レシピ**」カードが追加されました。**`Importar` そして`Exportar` ～へ`.bossrecipe.json`. 「エクスポート」をクリックすると、現在の下書きのレシピが保存され、新規作成は行われません`m###.bin`; スキーマのインポートと検証`ffx.bossrecipe.v1`/バージョン1、および基本モンスター、ターゲットID、名前、モード／AIソース、ステータス、およびシンプルな報酬を再適用（`RewardGil`,`RewardAp`,`RewardApOverkill`) を画面の各フィールドに入力します。ターゲットがすでに存在する場合、インポート機能はステータスでその旨を通知し、ユーザーが`Criar Monstro`. 正直なところ：レシピはメタデータ／オフラインエディタです。ボスの生成は依然として作成ボタンで行われ、配置／RT2は引き続きフォーメーションエディタ／バトルサンドボックス／ゲーム内で行われます。ビルドエディタのエラー数：0、警告数：361。[前回：`v2.54.0`] — ジャービス・コーデックス
- **⚔`v2.54.0` — Battle Sandbox v2：最大8体の敵、

 場所ごとのルートと、スプレッド／カメラのプランナー。** **Battle Sandbox** タブは`LiveBattleLab` 従来の縦型のA/B/C配置から、8つの敵スロットを備えたコンパクトなレイアウトへと変更され、各スロットごとにHPと高速なAIが設定されるようになった。ルートは、事前に決定されたリストから選択できるようになり、`btl.bin` (`map/battleId/field/group/formation`) または手動で編集できます。**ルート設定**ボタンをクリックすると、8つのフォーメーションスロットと位置情報が保存されます`MonsterLive` の`btl_*` 解決済み、バックアップあり`.sandbox.btl.bak`、再利用して`BattleArenaAuthor`,`Battle_File.WriteWithFormationSlots()` そして`BattleArenaPositionWriter`. このプランナーにはスプレッドが収録されています（`2 linhas compactas`（オープン、ボス＋追加敵、通路、円）に基づき、すべてのモンスターをフレーム内に収めるためのカメラ設定の推奨値を算出する。カメラの自動書き込みは、Aurora／RT2向けに引き続き「正直／保存」モードのままとする。`Force Battle` DINPUT8が接続されていることを引き続き要求しています。ソリューションのビルド結果：エラー 0件／警告 361件；ローカルのスクリーンショットは`work/screenshots/battle-sandbox-tab.png`. [前へ：`v2.53.0`] — Jarvis-MAGIC
- **⚔`v2.53.0` — カスタムボスクリエーター：作成フローにおけるAP/ギルの「シンプル報酬」。** このタブに、編集用の **シンプル報酬** ブロックが追加されました。`Gil`,`AP` そして`AP Overkill` の`LootFile` クローン化；空欄または無効なフィールドはベースモンスターから継承されます。クローナーは元の戦利品セクションを保持し、これらのフィールドが入力された場合にのみ再設定を行うため、モンスターエディタ向けのドロップ・スティール・装備情報は維持されます。レシピ`.bossrecipe.json` 記録する`RewardGil`,`RewardAp` そして`RewardApOverkill` 使用時には、および`ProofStatus` これらのオーバーライドを参照するようになりました。ビルドエディタ：このワークツリーでエラー0件／警告361件。[前回：`v2.52.0`] — ジャービス・コーデックス
- **⚔`v2.52.0` — カスタム・ボス・クリエイター：最初のサイドカー`.bossrecipe.json` 作成されたクローンに対して。** カスタムボスを作成する際、モジュールは現在、`m###.bossrecipe.json` の同じディレクトリ内に`m###.bin`, schema v1にはUTC日時、ソースモンスター、ターゲットモンスター、名前、AIソース（`inherit-base-ai` または`copy-monster-ai`)、stats/ModelId/name のオーバーライド、およびテストの正直なステータス。サイドカーはゲームを変えるものではないが、作成プロセスを再現可能にし、未来への第一歩を築く`Boss Recipe` エクスポート可能／インポート可能。ビルドエディタ：エラー 0 件／警告 357 件（ベースライン）。[前回：`v2.

51.0`] — ジャービス・コーデックス
- **⚔`v2.51.0` — カスタムボスクリエーター：`IA usada` AI Source picker を使用すると、明示的な選択が可能になります。** [タブ]`Custom Boss Creator` AIを暗黙の遺産として隠すことはなくなりました。現在では、モード付きの**「使用済みAI」**カードが存在します`Herdar IA da base` または`Copiar IA de outro m###`、独自のフィルター、ソース一覧、技術概要（`AiFile`、ワーカー、指示、構造的検証）。ボスを作成する際、クローンは`AiFile` 別のモンスターの全体データ。書き込み前にATELコーデック／バリデータによって検証済み。ステータス、名前、ModelIdは既存の流れのまま維持される。 以前はアクションのないフィールドとして存在していたベースモンスターフィルターが、実際にフィルタリングを行うようになりました。正直に言うと：AIのプロファイル全体をコピーしています。ワーカー／セグメント、戦利品／報酬、およびステージの統合については、今後のリリースで対応予定です。ビルドエディタのエラー数：0、警告数：357（ベースライン）。[以前：`v2.50.1`] — ジャービス・コーデックス
- **🧠`v2.50.1` — Monster AI Editor：BIBLE OF SPIRA + SIN workbenchがメインストリームに。** 画面は`Monster AI Editor` 2つの別々のコンセプトを中心に再編成されました。**BIBLE OF SPIRA**は読み取り専用のリファレンスとして、それに加えて`O que este monstro faz`、および**SIN / Spira Instinct Network**を2列の著者パネルとして。リスト`IA atual do monstro` 高くなり、独自のスクロール機能が追加されました。右側のパネルには、選択したスキル、初期バフ、クイックプリセットなどがまとめられており、`SIN Templates` コンパクト。`Live Battle Target` 編集したばかりの箇所付近までスクロールし、「Workers/オペランド/アセンブラ/構造モデル」がブロック内に移動された`DevKit`. 「クイックプリセット」では、既存のプリミティブを再利用して10種類の実際のアクションが実行できるようになりました（`Haste`,`Protect`,`Reflect`,`Defensivo`,`Agressivo`,`Enrage`,`Revezar 1/2`,`Revezar 1/3`,`Repetir cast`,`Combo 2 hits`)、並列のwriterを作成せずに。ビルドエディタ：エラー0件／警告357件（ベースライン）。[前回：`v2.50.0`] — ジャービス・コーデックス
- **🎚`v2.50.0` — Difficulty Director v2：オフラインでの「Encounter Danger」および「Challenge」モード。** このモジュール`Modules/DifficultyDirector` もはや単なる～の段階ではなくなった`m###.bin`: これで、以下のファイルの読み込み・プレビュー・書き込みも可能になりました`Danger` のグループのうち`btl.bin` 経由`EncounterTable_File.Write()` バックアップ付き`.difficulty.bak`, モンスターと一緒に適用するためのトグルと、5つのグループのプレビュー

影響を受けるもの。拡張プリセット：`Exploração` (危険度 0) および`Caçador` （最高難易度）。オフラインのチャレンジモード：`True Nightmare`,`Speed Run Assist`,`Explorer`,`Hunter` そして`Equalizer` （読み込んだデータセットの平均値に基づいてHP/MP/ステータスを正規化します）。正直さ：`One-Hit`,`No-Overdrives`、adaptive/live scaling および probe は、IDA/runtime までは引き続きこの対象外となります。つまり、ライターはオフライン状態です。ビルドを試みましたが、既存の XAML エラーによりブロックされました。`MonsterAiEditor_Control.axaml` （他のレーンのクリックハンドラ）、このモジュールによるものではない。[前へ：`v2.49.0`] — ジャービス・コーデックス
- **⚔`v2.49.0` — Live Battle LabのBattle Sandbox：パッケージA/B/Cを組み立て、HP/IAを素早く適用し、プローブ経由でForce Battleを発動させる。** **Battle Sandbox**という新しいタブが`LiveBattleLab`: モンスターピッカー`m###`, スロットごとに編集可能なHP、AIのクイックプリセット（`Original`,`Agressivo`,`Defensivo`,`Enrage`) およびバックアップを含むパッケージを適用するためのボタン`.sandbox.bak`. **Force Battle** ボタンは、フィールドを再利用します`field/group/formation` および既存のDINPUT8/main-threadブリッジのルート。画面には、編成の実際の構成が依然として`btl_*` workspace/Formation Editor を除く。Build Editor でエラーは0件。[前回：`v2.48.0`] — Jarvis-MAGIC
- **🎚`v2.48.0` — 難易度ディレクター：プロジェクト内のすべてのモンスターのHP/MP/ステータスを調整するグローバルスライダー。** 新しいモジュール`Modules/DifficultyDirector` Core Authoring ナビゲーションで、プリセットを使用`Fácil/Normal/Difícil/Dark Aeon`、HP、MP、力、魔法、防御／魔法防御、その他のステータス用のグローバルスライダー、トップインパクトのプレビュー、およびオフラインライター機能（以下経由）`Monster_File.Write()`. それぞれ`m###.bin` バックアップを受信する`.difficulty.bak` 最初の書き込み前、UIではこれらのバックアップからの復元が可能です。ゲームは次のモンスターの読み込み時に変更を認識します。ライブスケーリングは引き続き対象外です。ビルドエディタのエラーは0件。[以前：`v2.47.1`] — Jarvis-MAGIC
- **📚`v2.47.1` — Monster AI Editor：既存のプリセットやオートメーションの上に表示されるビジュアルなAIビヘイビアライブラリ。** 新しいカード **「Behavior Library」** が`Monster AI Editor` 検索機能とビジュアルテンプレートを搭載（`Counter-Attack`,`Cura quando HP baixo`,`Revezar habilidades`,`Enrage HP baixo`,`Buff defensivo`,`Multi-cast`). この実装では、すでに用意されている自動化機能やスニペットを活用しています。

卵子（`AiAutomation`,`AiSnippetLibrary`、（防御用プリセット、アクション⚔をテンプレートとして選択）、並列ライターを作成することなく。HP%の条件分岐は、検証済みのオフライン構造として正しくマークされており、RT2のゲーム内動作についてはプローブによる確認待ち。ビルドエディタのエラーは0件。[前回：`v2.47.0`] — Jarvis-MAGIC
- **📖`v2.47.0` — Monster AI Editor: BIBLE OF SPIRA、モジュール内のコンテキストに応じた読み取り専用ATELバイブル。** 新機能`FfxLib/Ai/AiBibleCatalog.cs` 関数やフィールドの項目を構成する`btlActorProperty`、ターゲット、オペコード、パターン、およびガードレールについて、実際の辞書を用いて（`AiChrPropertyNames`,`AiTargetNames`,`AiScript_File.CallName/Mnemonic`). O`Monster AI Editor` 検索により、**BIBLE OF SPIRA**カードを獲得しました`70AB`/`Overdrive`/`PUSHII`/`Shiva` および署名、スタック形状、証拠、リスクに関する詳細。AI Assemblerの行を選択すると、対応する項目が自動的に読み込まれます（例：`CALLPOPA 70AB` →`setStatField`). このミッション・ドキュメントのタイトルは『BIBLE OF SPIRA』に変更され、以下の署名が入った。`setStatField/getStatField` 正規化：`setStatField(field,value)` 受け取らない`actorRef`; 明示的なアクターは`writeChrProperty(actor,field,value)`. **新しいライターなし、シヴァボタンなし、新しいバイトなし** — コンテキスト／ガードレールのみ。ビルドエディタのエラーは0件；`AiScriptLab --names` PASS。[前：`v2.46.1`] — Jarvis-MAGIC
- **🧠`v2.46.1` — AIアセンブラ：「可読」列 — アセンブラの各行には以下のように表示されます`MNEMÔNICO  gloss` 単なるグロスだけじゃなく。**`AiAsmRow.ReadableText` 合う`AiScript_File.Mnemonic(opcode)` +`OperandGloss(opcode, operand)` 1つの読みやすい文字列にまとめる：`PUSHII  0xFF03  (alvo: Self)`,`CALLPOPA  Battle.performCommand`,`JMP  → jump[3]`,`ADD` （オペランドなし）。の列`ListBox` AI Assemblerの（以前はグロス表示のみでした。例：`0xFF03  (alvo: Self)`) これで全文が表示されるようになりました；オペコードのツールチップ（`OpcodeHelp`) はホバー時に表示されたままになります。`OnPropertyChanged(nameof(ReadableText))` opcodeおよびオペランドのセッターでトリガーされるため、編集時に列がリアルタイムで更新されます。RT0には影響なし（ビューのみ）。ファイルなし`AiOpcodeNames.cs` 作成 —`Mnemonic()` すでに存在しており、公開されています。[前へ：`v2.46.0`] — Jarvis-MAGIC
- **🔍`v2.46.0` —

AEON (Assembly Evolution Observation Node)：編集済みAIとバニラ版を、緑・赤・黄色のハイライトで比較。** 新規`FfxLib/Ai/AiScript_Diff.cs` 2つを比較する`AiScriptFile` 著：`(worker, offset)` そして分類する`Unchanged/Modified/Added/Removed`. O`Monster AI Editor` **Diff vs Vanilla**のオープンカードを獲得：以下から抽出された参照を読み込み`Path_FfxPs2Root`、デルタを緑＝追加、赤＝削除、黄色＝変更として表示し、サイズが変化した際に通知し、オフセットによる差分表示が概算値となるほか、2クリックでの確認による「vanilla」状態への復元機能も提供します +`.prev.bak`. バニラが欠けていると、クラッシュすることなく率直なメッセージが表示される。新しいゲート`AiScriptLab --diff` PASS：`m000` 同一 = デルタが0；`m001` メモリ内のオペランドが変更されました = 1 が変更され、0 が追加／削除されました。ビルドエディタでエラーは0件でした。[前回：`v2.45.0`] — Jarvis-MAGIC
- **🎵`v2.45.0` — エディタに本格的な音楽プレーヤーを搭載：カタログ内の89曲すべてがUI上で選択可能になります。**`AudioStudio_Service` 現在、即時プレビューを表示しています（`SetTrack`/`PreviewSelectedMusicTrack`) 維持しつつ`SelectedTrackId` 設定で；メインウィンドウにボタンが追加されました`▶ Preview`、幅広のコンボボックスと、現在再生中の曲、ステータス、Music/FXの切り替え、カタログのカウンターを表示する**Music Player**カード。使用するのは`Assets/Audio/Music/music_catalog.json` +`Catalog/*.wav` （89トラック）であり、引き続きEDITORのプレイヤーのみである――ゲーム内での音楽切り替え機能は保証されておらず、引き続きフック／IDAに依存する。ビルドエディタのエラーは0件。[前回：`v2.44.0`] — Jarvis-MAGIC
- **⚔`v2.44.0` — カスタムボスクリエーター：任意のモンスターを複製・編集 → 新しい m###.bin （カスタムモンスター作成パイプラインの第一段階）。** 新しいモジュール`Modules/CustomBossCreator` +`FfxLib/Monster/MonsterCloner.cs`. フロー：ベースとなるモンスターを選択し（m000～m346、または既存のm###）、新しいIDを設定し（最初の空きスロットとして347+が自動的に提案されます）、ステータス（HP/MP/HpOverkill/力/防御/魔法/魔法防御/敏捷/運/回避/命中）およびModelIdを個別に編集（空欄＝ベースから継承）、表示名を入力し、**⚔ モンスター作成**をクリックします。`MonsterCloner.Clone()` 独立したコピーを行うためにWrite→Readの往復処理を行い、スロット限定のオーバーレイ（stats）または完全な再構築（名前）を`Monster_StatSheet`, es

～を信じる`battle/mon/_m###/m###.bin` （自動的にフォルダを作成し）、その名前を`Monster_Dictionary` 実行時 — フォーメーションエディタは、新しいモンスターを正しい名前で認識します。AI、戦利品、ゲーム内での名称はベースから継承されます（後でモンスターAIエディタ／モンスターエディタで調整可能です）。 正確性：クローンがファイルを作成します。モンスターを戦闘に投入する作業は、引き続きフォーメーションエディタで行います（既存の.btlファイルでのスロットスワップ）。オフラインゲート：Monster_Fileライターの動作確認済み（ラウンドトリップでバイト単位で同一）。[以前：`v2.43.1`] — Jarvis-MAGIC
- **🪝`v2.43.1` — ffx-hooks.dll フェーズ0：C++エンジンフックレイヤーの骨格（PolyHook2、x86） — DLLはクラッシュせずにゲームに読み込まれ、共有メモリの準備も整っており、IDAでの解析を待つためにフックはコメントアウトされている。** 新しいC++ DLL`RuntimeTools/FfxHooksDll/` と共存している`ffx-probe.dll` 既存の（置き換えるものではありません）：モジュールローダー（`dinput8.dll`) は両方を`modules\` 自動的に。フェーズ0：`dllmain.cpp` スケルトン — 読み込み時に2秒待機し（スレッド＋Sleep、決してDllMainを直接フックしない）、ベースを`FFX.exe`, 共有メモリブロックを作成する`Local\FFXHooksBlock_v1` (256バイト：マジック値/バージョン、`musicOverrideTrackIndex`,`musicSeq`,`elementFlagsExt`), そして以下に保存します`%TEMP%\ffx-hooks.log`. **この段階では実際のフックはインストールされていない** — gate: ゲームは通常通り起動し、ログに以下が表示される`[ffx-hooks] Fase 0 skeleton loaded`. コメント付きスタブ：`hooks/MusicHook.cpp` (thiscall`FFX_FmodMusic_PlayTrackByIndex`, フェーズ1 — 待機中`RVA_FMOD_PLAY_TRACK` （IDA経由）、`hooks/ElementHook.cpp` （Earth/Wind/Dark要素のインラインフックフラグのビット 0x20/0x40/0x80、フェーズ2）。VS2022プロジェクト`FfxHooksDll.vcxproj` （Win32のみ — ゲームはx86です；vcpkgのマニフェストモードで`polyhook2:x86-windows` +`zydis:x86-windows`). スクリプト`build_hooks.ps1` com`-Deploy` (コピーして`modules\`): シンプルモード`cl.exe` PolyHook2なし（フェーズ0）または`-WithPolyHook` MSBuild+vcpkg 経由（フェーズ 1+）。`shared/ffx_addresses.h` すべてのRVAを、コメント付きのプレースホルダーとして一元化します（RVAごとのIDAタスク）。[以前：`v2.43.0`] — Jarvis-MAGIC
- **⚡`v2.43.0` — EncounterTable：保存ボタン + グループごとに編集可能なDanger + グローバルなDanger（機能1+4）。** O`EncounterTableExplorer` 単なる閲覧者から、出会いの編集者へと変貌を遂げた。`Encount

erTableGroupRow` e `EncounterTableFormationRow` agora são `ObservableObject` parciais: `危険` (por grupo, 0–255) e `重量` (por formação, 0–255) são editáveis via slider interativo; editar o `危険` reflete em `group.Danger` imediatamente (e atualiza o label `発生なし／まれ／普通／高い／最高`); editar `重量` recalcula automaticamente `group.TotalWeight`. Presets por grupo: botões `マッチなし (0) / 通常 (50) / 強 (128) / 最大 (255)`. **Salvar:** botão `💾 btl.bin を保存` chama `EncounterTable_File.Write()` (slot-only, byte-local), cria `btl.bin.bak` na 1ª vez; `↩ バニラ状態に戻す` copia o `.bak` de volta. **Danger Global:** 4 botões de preset (`⚡ なし / 通常 / 強 / 最大`) no card "Editar e Salvar" aplicam o valor a TODOS os grupos de TODOS os mapas de uma vez, com feedback de quantos grupos foram afetados. O `DataModel` mantém `_loadedEncounterFile` e `_encounterFilePath` para reutilizar o mesmo objeto lido sem re-parse. Build editor 0 erros. [anterior: `v2.42.0`] — Jarvis-MAGIC
- **🎥`v2.42.0` — AURORA：IDAでカメラの視点を100%キャリブレーション済み + MapViewerで金色の目のドラッグ操作。** ブリーフ完了`HANDOFF_CAMERA_POLAR_CALIBRATION_CODEX_2026-06-07`: ハンドラー`camSetPolar(0x6004)` IDA経由で記録された（`0x6004 -> 0x7B9260 -> 0x7BB550 -> 0x7C4760`, カメラスロット`+12`) として`horizontalDeg, elevationDeg, distance`, 数式`x=refX+cos(h)*cos(e)*dist`,`y=refY+sin(e)*dist`,`z=refZ+sin(h)*cos(e)*dist`. オーロラの金色のマーカーは「約」ではなくなりました：`BuildCameraMarker` 実際の数式を使用し、Placeモードでは**金色の目**をドラッグできるようになりました。エディタが自動的に再計算を行います。`horizontal/elevation/distância` そして、3つのfloat型を以下のように記録する`WithFloat` (byte-local、backup-once)とし、共有プールに関する警告はそのまま残す。Gate`BattleCameraScanLab`:`camSetPolar0x6004=10944`、個別のターゲット対応バリアント`103854`, 極座標のexatoを定義する`809/855`, 目で編集可能`802/855`, **polar eye round-trip 802/802**。`camSetBtlPolar*`/`camSetChrPolar2` 単純な逆転とは一線を画しています。エディターによる誤りは0件。[前へ：`v2.41.0`] — Jarvis-Codex/AURORA
- **🎥`v2.41.0` — AURORA：MapViewer上で直接カメラをドラッグ（ref/look-at）する。** 「どのように」という質問への回答

「MapViewerでカメラを操作するには？」：**Placeモード**では、**シアン色の球体（ref = look-at）**がモンスターと同じようにドラッグできるようになりました。シーンの床上でドラッグして放すと、**💾 位置の保存**で新しい位置が記録されます`refSetPos(x,y,z)` chunk0（**バイトローカル、正確**、バックアップ1回） — 同じセーブデータ内のモンスターのドラッグと組み合わせる（異なる地域）。Readerは、refのfloat-poolのインデックスを公開する（`Establishing.RefX/Y/Zindex`);`ApplyCameraRefDragToDisk` via を通じて投稿する`BattleCameraSetup_File.WithFloat`;`aurora-overlay.js` シアノ色の球体をドラッグのターゲットとしてタグ付けする (`role=camera_ref`) 橋を渡り直して`/drag`. **「ゴールデンアイ」（角度／距離）はまだドラッグされません** — IDAでの極座標系キャリブレーション（近日中）を待ってください。それまでは、パネルのノブで調整してください。（ついでに：のビルドを修正しました）`BattleCameraScanLab` 新しい記号によって壊されていた`Ai*Names` 別のレーンから — ロックを解除する`offline_ci`.) エディタ エラー 0、ゲート PASS (float 855/855)。[前:`v2.40.1`] — Jarvis-AURORA
- **🪄`v2.40.1` — AIアセンブラ：「修復を試みる」ボタン（レベル3、正直な自動修正）。** ブローカーを閉じる：**「Validate/Save」の横にある **🪄 修復を試みる** ボタン。 **正直なルール（所有者自身のもの）：** **唯一の正しい答え**がある場合にのみ修正を適用します。それ以外は推測ではなく、提案にとどめます。アセンブラのモデル（これは派生したもので`HasOperand` （opcode単体の場合）唯一の明確な修正策は、**削除対象としてマークしたものの、ジャンプ／エントリポイントのターゲットとなっている命令を復元すること**です。この命令は残さなければなりません（分岐先を変更すると動作が変わってしまうため＝推測）。 このボタンはループで再検証を行い、これらの孤立したターゲットを復元し（ケース1「何かを削除して壊れた」を解決）、唯一の解決策がないエラー（無効なオペコード、OOBジャンプインデックス、レベル1のスタックが空）については **レポートで対処法を説明しているが、実際には手を加えない** — 「あなたの意図を推測して修正はしない」。修正した件数と、あなたの判断待ちの残件数を報告する。`MonsterAiEditor_DataModel.Assembler.TryAutoFixAssembler` (を使用する`AiValidator` ゲートテスト済み（オペランドやオペコードを編集したり、何かを削除したりすることは一切ありません）。ビルドエディタでエラーは0件；`--ai2`/`--ai3` PASS（RT0バイトと同一 — VMの削除フラグのみを復元し、バイトは変更しない）。**正直なところ：** 意図を推測する自動修正 = サイレントバグとなるため、ボタンはそのまま残す

意図的な崇拝。[前へ：`v2.40.0`] — Jarvis-MAGIC
- **🩹`v2.40.0` — AIアセンブラ：スタックチェッカー（レベル1+2） — 編集によってスタックが空になった際に警告し、修正方法を提示します。** 依頼主は、アセンブリのエラー修正を支援する「ミニAIチェッカー」を求めていました。 バリデータはすでに無効なオペコード／孤立したジャンプ／インデックスの範囲外（OOB）を検出できていましたが、**手動編集におけるエラーNo.1である「スタックの不均衡」**は検出できませんでした。現在は検出可能です。 **RE-grounded (FFXDataParser)：** 新規`FfxLib/Ai/AiStackModel.cs` = オペコードごとのスタック効果（出典：`OPCODE_STACKPOPS`) + **269個の関数の数**（入力数の`ScriptFuncLib`; accessor = subject?+index+value?). O`AiValidator` スタックの深さをシミュレートし（エントリポイント／ジャンプ先で0にリセット）、アンダーフローを報告する。**重要なポイント：**パーサーの引数個数は、実際のVMと100%一致しない（証明済み：`setSelfFloating 0x7029` パーサーは「2」と表示し、コーパスは「1」を返す）――そこで、絶対的なカウント数（有効なコードでは誤った結果となる）の代わりに、**オリジナルと編集後の**スタックを比較する： 両方にアーリティのノイズが存在し、互いに相殺されるため、残るのは「あなたの編集」によって壊れた部分だけになります。 メッセージ（レベル2）は、ポルトガル語で、どこが空になったか＋**修正方法**（「引数だったPUSHを元に戻してください。すべてのステートメントは引数をプッシュしてから呼び出します」）を示しています。検証パネルで自動的に移動します。ゲート`--ai2`: **validator clean 346/346**（コーパス内で誤検知はゼロ） + **stack-break caught 1/1**（arg-push を削除した際に検出されることが証明されている）；`--ai3` PASS；RT0 バイト同一（解析のみ、ゼロバイト）。ビルドエディタ 0 エラー。**正直なところ：**編集による変更点を検出する；一部の関数の引数個数の微調整＝公開RE（コーパスによる調整＝将来）。[前：`v2.39.2`] — Jarvis-MAGIC
- **🏷️`v2.39.2` — プロジェクトのバーンダウン名：生ラベルスキャナー + Monster AI における最初の安全なエイリアス。** リポジトリ全体でのバーンダウン計画を開始`campo 0xNN`,`stat 0xNN`,`comando 0xNN`,`raw`,`Unknown`/`Unk` 無差別なリネームを行わずに、汎用IDを割り当てる。新しいツール`RuntimeTools/NameAuditLab` 目録`.cs`/`.axaml`/`.md`/`.ps1`, 区切る`EditorUi`,`CoreDisplay`,`CoreInternal`,`LabTool`,`Documentation` そして`Other`, かつその部分集合のみをマークする`review now`; 現在の結果：**2445件の所見、497件の編集・表示、11件の即時レビュー**、検査室/

docs/offsets では、設計上、生の16進数を維持しています。最初の安全なエイリアスが適用されました：Monster AIの自動化部品表には、現在次のように表示されます`writeChrProperty StatusDurationHaste (0x0038)` /`setStatField stat_round (0x00DA)` いつ`AiChrPropertyNames` IDを閉じる；不明な項目は続く`campo 0xNNNN`. ドキュメント：`docs/ai/MISSION_PROJECT_WIDE_NAME_BURN_DOWN_2026-06-07.md`,`docs/reverse/FFX_PROJECT_NAME_BURN_DOWN_SCAN_2026-06-07.md`; AIのバイトは変更なし。[以前：`v2.39.1`] — ジャービス・コーデックス
- **🏷️`v2.39.1` — Monster AI：公開パーサーを用いた「名前」の監査（名前が指定されていないコールIDは0件；不明確なフィールドは16進数で表示）。** ブリーフの実行`docs/ai/MISSION_NAME_AUDIT_WITH_PARSERS_2026-06-07.md` 「一貫性を優先する」というルールに基づき：`ScriptFuncLib` +`ScriptConstants` + コーパス経由`AiScriptLab --names`、バイトを変更せずに。辞書が追加されました`AiMotionPropertyNames`,`AiMovePropertyNames` そして`AiSaveDataVariableNames`; 現在の分解は、関数ごとのフィールド空間を記述している（`btlActorProperty` ～へ`700F/7018/70AA/70AB`,`motionProperty` ～へ`70AC/70B2`,`moveProperty` ～へ`701A/7078`) および`saveData` 「parser-backed」という名前が表示される場合がある。修正済み`0x701A` ～へ`readMoveProperty` また、16進数で表される使用済みのコールIDを追加した（`7009`,`7029`,`7032`,`7050`,`7078`,`70A8`). ゲート`--names`: **使用されたコールIDは160個、名前のないものは0個；名前付きスペース内のフィールドは285個；16進数で保持されたリテラルは5個** (`0x0156`,`0x0157`,`0xFFFB`,`0xFFEF`,`0xFFDF`) parser/corpus/IDA の閉じ忘れのため。`--ai2`/`--ai3` PASS；エディタ エラー0件。Doc`docs/reverse/FFX_AI_NAME_AUDIT_WITH_PARSERS_2026-06-07.md`. [前へ：`v2.39.0`] — ジャービス・コーデックス
- **🎥`v2.39.0` — AURORA：MapViewer上のカメラの3Dマーカー（シーンのレンダリングで、カメラの位置や向きを確認できます）。**「表示方法」の#2：Auroraの3Dレンダリングでは、**カメラの位置**が以下のように表示されるようになりました — **金色の球体 = 視点**（カメラの位置）、**シアン色の球体 = 参照点**（カメラが正確に捉えているポイント）、**視点→参照点**の線 + 地面上のステム。chunk0から算出：`refSetPos(x,y,z)` （その通り、シーンのフレームが同じ＝同一性が証明された）＋`camSetPolar(ângulo,distância)` →`olho = ref + polar`. Reader`BattleCameraSetup_File.Establishing` (1番目のrefPos + 1番目のpolar; ゲート: **

ref 855/855、polar 846/855**）、モデル`AuroraCameraMarker` オーバーレイで、以下でレンダリングする`aurora-overlay.js` （アンカーと同じグループで、Y-upフリップを継承する）。 **正直なところ：** 参照値は正確ですが、**視線は概算**です — 極座標の定義（どの引数が角度か、距離か、仰角か）は**まだバイト単位で確定していません**。 そのため、マーカーには「カメラ（概算）」とラベルが付けられており、仰角は目測による推定値です。画面上（およびプローブやゲーム内）で確認・微調整してください。エディタのエラーは0件。ドキュメント`docs/reverse/FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07.md`. [前へ：`v2.38.1`] — Jarvis-AURORA
- **📊`v2.38.1` — Monster AI Editor：STATの名称付きアクション（「stat 0xNN」の末尾） —`setStatField` 同じテーブルを使用している。** オーナーは画面上で、📊 ステータスがまだ未処理の状態（「stat 0xDA = 8」）で表示されていることを指摘した。**発見（FFXDataParser ScriptFuncLib のクロスチェック）：**`setStatField`(0x70AB)/`getStatField`(0x70AA) は **同じ indexType** を使用しています`btlActorProperty`** が`readChrProperty`(0x700F)/`writeChrProperty`(0x7018) — つまり、フィールドのテーブルは「同じ」ものであり、私の「区切り文字」という前提は間違っていた。なぜ生のままだったのか：IDは次のような形式で`0xDA/0xDB/0xE6` 持っている`name=null` パーサー内（のみ`internalName`:`stat_round`/`stat_round_return`/`stat_attack_inc_speed`)、および第1世代の`AiChrPropertyNames` 親しみやすい名前のものだけを取得していました。**修正：** 英語名がない場合の**フォールバックとしてゲーム内の内部シンボル**を含めるように辞書を再生成し（222 → **341フィールド**）、検出器のstatブランチにマージしました。 これで「stat 0xDA = 8」が **「stat_round = 8」** になります。`FfxLib/Ai/AiChrPropertyNames.cs` +`AiAutomation` (branch Stat via`StatusFieldName`). ゲート`--ai3` PASS（4156件の統計情報を検出；RT0はバイト単位で同一 — 表示のみ）；エディタのエラーは0件。**正直なところ：** 英語の名称は「RE-pública」であり、`internalName` これらは**ゲームの真のシンボル**です（タイプ「unknown」＝詳細な意味付けが100％対応しているわけではありませんが、このシンボルは正確であり、16進数表記よりも優れています）。[前へ：`v2.38.0`] — Jarvis-MAGIC
- **🎥`v2.38.0` — AURORA：パネル上で戦闘用カメラの実際のパラメータ（角度・距離・位置・ロール）を編集できます。** 「それをどうやって表示・編集するの？」という質問への回答：🎥 カメラカードに **「🎚 カメラパラメータ（編集可能）」** が追加されました。 **RE（IDA経由＋クロスチェックによる`FFXDataParser`, dからのヒント

ono):** 戦闘用カメラはchunk0でスクリプト処理される — Camera-namespaceを呼び出す (`camSetPolar(ângulo,distância)`,`refSetPos(x,y,z)`,`camSetRoll`,`camSetScrDpt`) パラメータをプールの**FLOAT定数**として指定します。新しいリーダー`FfxLib/BattleMap/BattleCameraSetup_File.cs` すべての呼び出しを抽出 + 浮動小数点を解決 + 編集可能な**個別のノブ**；`WithFloat` **byte-local** フロートプールを編集する（同じサイズ、再利用`AiScript_File.EditFloatConst`）、他のチャンクは保持したまま。パネルには、**タイプ別**（polar/refPos/roll/screenDepth）にグループ化されたノブが一覧表示され、**フィルタ＋検索**機能（カメラは1バトルあたり約730カットのシネマティックスクリプトであるため、 そのため、グループ別／検索によるナビゲーションが可能で、単純なリスト表示ではありません）、それぞれ編集可能です。「💾 カメラパラメータを保存」は変更されたfloat値を適用します（1回限りのバックアップ＋リロード）。Gate`BattleCameraScanLab` 詳細：**カメラ付き855ビン、623,981コール、フロート編集の往復855/855**（バイトローカル＋可逆）。 **正直なところ：** floatを編集すると、それを共有するすべてのカットが変更されます。カスタムアングルはインファイルです（以前の結論「＝シーンオーサリング」を覆しました）。インゲームエフェクト＝RT2。ドキュメント`docs/reverse/FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07.md` §6. ビルドエラーなし。[前：`v2.37.3`] — Jarvis-AURORA
- **🎨`v2.37.3` — SPHERE GRID CANVAS：ズームに合わせて拡大縮小され、すっきりとしたベクターアイコンが使用されています（アトラスの切り抜きが不正確でした）。** v2.37.1における開発者からのフィードバック：Explorerのアトラス（`icon_atlas.png`) **セルが正しく切り取られていなかった**（Lv1-4やその他多くの見苦しい箇所）うえ、**ズームするとノードが縮小してしまう**（画面サイズが固定されているため→画面から消えてしまう）。2つの修正点：**(1) 半径がズームに合わせて拡大・縮小される** —`CurrentNodeRadius = clamp(26×scale, 5..42px)`、つまり、ズームイン＝オーブが大きくなる（アイコンが読みやすい）、ズームアウト＝小さくなる（全体像）；アイコンとテキストは一緒に拡大・縮小される。 **(2) ベクターアイコン** — **game-icons.net (CC BY)** のグリフに戻しました (`SphereGridIcons.cs`, SVGパス →`Geometry.Parse`) **ズームレベルに関係なく、切り取られることなく**スケーリングされる（ビットマップアトラスは除外）：ロック = シンプルなバッジ **"L{n}"**（nv1-4は二度と切り取られない）、 アイコン付きステータス（HP/MP/力/防御/魔法/敏捷/運/スキル）、その他はスケーリングされたテキストバッジ（ACC/EVA/MDF/WHT/BLK/SPL/SKL）。 カテゴリーごとの色付きオーブを維持 + グロー/ホバー/キャプション/アンチ

i-VAIDARMERDA/sound。ビルドエラー0件；CC-BYライセンス`SPHERE_GRID_ICON_CREDITS.txt`. [前へ：`v2.37.2`] — Jarvis-MAGIC
- **🎯`v2.37.2` — Monster AI Editor: #8 実際に指定されたターゲット（自分／敵／味方／キャラクター#N…） — パーサーがセンチネルを解除した。** 「パーサーに注目」に続き：`FFXDataParser/ScriptConstants.putEnum("btlActor")` これはまさに、IDAが提供していなかったターゲットのセンチネルマップそのものです（ATELの解決処理がタイムアウトしました）。 これで名前が付けられ、**コーパスと整合性が取れた**：**-13/0xFFF3 = Self**（実証済み）、**-14/0xFFF2 = FrontlineChars**（モンスターの「敵」＝キャラクターたち； 最も一般的なリテラル・センチネルで、272回出現）、**-6/-7/-8 = キャラクター #1/#2/#3**、**-15/0xFFF1 = AllMonsters**（モンスターの「味方」 — White Wind→モンスターを回復と一致する）、**-17 = LastAttacker**、**-5 = AllActors**、**-3 = TargetActors**、**-20 = AllAeons**、`0x10NN = MonsterType`…（敵／味方はモンスターの視点による）。これにより、**🎯 ターゲット変更**（v2.33.0）は、「例をコピー」という形式から、**名前付きターゲットモードのドロップダウン**へと変更されました。これは、投稿者#8が当初から求めていた「1体/すべての敵/すべての味方」というものです。 アクションリストには「ターゲット：FrontlineChars」と表示され、**オペランドの分解／エディタ**では、センチネル（0xFFE9–0xFFFF、一意の範囲）が「（ターゲット：Self／…）」として扱われます。新機能`FfxLib/Ai/AiTargetNames.cs` (btlActor、コーデックの関数／プロパティマップと同じ公開元); ドロップダウンで有効化 +`AiScript_File.OperandGloss`. ゲート`--ai2`/`--ai3` PASS（RT0のバイト同一性が維持されている — グロス（gloss）のみ、変更されたバイトはゼロ）；ビルドエディタでエラー0件。 **正直に言うと：** Selfはバイト単位で検証済み；その他の名前は公開REに由来し、コーパスと整合している（詳細な意味論 = RT2）。[前：`v2.37.1`] — Jarvis-MAGIC
- **🩸`v2.37.0` — Monster AI Editor：「HPがX%未満の場合」という条件が確認された（IDA+コーパス）＋ 222個の命名済みプロパティフィールド（「フィールド0xNN」の終わり）。** HalysonはIDAを使うよう指示し、「行が数値である設定ファイルだろう」と推測した — **両者とも的中**。REで`FFX_recon.i64`: ネイティブのディスパッチ ATEL =`handler = *(FuncspaceTables[funcId>>12] + 16*(funcId&0xFFF))` (slot +0 CALLPOPA / +12 CALL);`readChrProperty` (0x700F) =`0x7A4D70` → switch `field→プロパティ

そして` (`sub_7B2DD0`). Cruzei com o **FFXDataParser/ScriptConstants.putBattleActorProperty** (a "config" que o dono intuiu) + o corpus: **field 0x00 = HP** (stat_hp, a propriedade MAIS lida do corpus — 306×), **0x02 = maxHP** (137×), **0x119 = NearDeath** (= IDA case 281 `current < max/2`). Opcodes aritméticos provados (`* 0x16` etc.). **#11 REAL shipado:** snippet guardado **"Se HP abaixo de X% → forçar comando"** = idioma `HP*100 < maxHP*X` (fields 0/2 corpus-provados) — o enrage de chefe de verdade, não mais um chute (a versão anterior v2.35.0 era genérica porque o field de HP não estava provado; agora está). **Nomeação:** novo `FfxLib/Ai/AiChrPropertyNames.cs` (222 fields nomeados, mesma proveniência pública do mapa de funções do codec) ligado no detector de buff/stat → as ações de status agora aparecem "Haste/Protect/StatusPoison/HP/maxHP…" em vez de "campo 0xNN". Gate `--ai2`: **HP%-enrage 346/346** + conditional 346/346; `--ai3` PASS. Docs: `docs/reverse/FFX_AI_NATIVE_DISPATCH_AND_CHRPROPERTY_FIELDMAP_2026-06-07.md` (+ rename-queue pro `.i64`). **Honesto:** estrutura provada offline, efeito in-game = RT2; o gauge 0xDA/218=HP%×256 existe no IDA mas o corpus não usa (usei o caminho que a IA usa de verdade, 0/2). Build do editor red por WIP da lane Sphere Grid (alheio); meus arquivos são todos FfxLib, gate-validados. [anterior: `v2.36.0.1`] — Jarvis-MAGIC
- **🎥 AURORA — バトルカメラのショットテーブルに関するRE（IDA、ドキュメントのみ）：「shot」はカメラノードへの参照であり、位置やFOVではない。** 「100% カスタムなアングルにできるか？」という質問への回答：**float テーブルでは不可能です。** デコードおよびリネームされたチェーンは`FFX_recon.i64`:`camReq`→`FFX_Battle_Camera_RequestShot`→`CmdQueue_Push`→`BindQueuedShots`→`ShotTable_Dispatch`(@0x7985A0)→`ShotTable_Walk`(@0x797420)。その`shotIndex` BLOB をインデックス化します (`[1]`=count,`[2+shot]`=セレクタ、u16オフセットテーブル → **ノードID**のサブテーブル、 0xFFFF=なし）として、**カメラノード**（シーン／エフェクトにベイクされたアニメーションパス）に解決されます。位置／FOVは**ノードを追跡**することで得られ、レコード内にはfloat型データは含まれません。ソース = ファイルから読み込まれたコンテナ（`+4`=ATELスクリプト、`+8`=表）：経由による効果`FFX_MagicFile_LoadDllByMagicId` (`magic_NNNN.dll`); `g_CameraShotC` による戦闘

channels[8]` (kind2/id1) + `actor+0xF7C` (kind3). **Implicação:** trocar entre os ângulos existentes = operando SHOT do camReq (já no painel, v2.36.0); **ângulo custom = authoring de nó/animação de câmera na cena Phyre / effect DLL** (scene-authoring, encosta na lane MAP), NÃO um writer no per-battle bin. 13 renames + 2 comentários de layout salvos no `.i64`. Doc: `docs/reverse/FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07.md`。*(RE/IDA = ドキュメントのみ、csprojは更新しない。)* — Jarvis-AURORA
- **✨`v2.37.1` — SPHERE GRID CANVAS：本物そっくりのビジュアル（エディタの Atlas 経由で FFX の実際のアイコンを使用）＋見やすいノード＋リアルタイムの「クソみたいな VAIDAR」対策＋色／キャプション／グロー／ホバー／サウンド。** 依頼主は「見栄えを良くして＋自動通知」を要望し、v1はアイコンのない小さな丸だったと指摘した。**重要な発見：**エディタにはすでにExplorerの美しいレンダラーが搭載されていた（`SphereGridPreview_Control` +`Assets/SphereGrid/icon_atlas.png`) — そこで**本物のアトラスを盗んできた**（以前載せていたgame-icons.netのものは削除した）。さて、Canvasについて：**(1) FFXの正規のアイコン** — カラフルなオーブ＋スプライトの`icon_atlas.png` 著：`AppearanceType` (STR/DEF/MAG/HP/MP/white/black/special/skill/lock) またはテキストバッジ (AGI/ACC/EVA/LCK…)、エクスプローラーと同様に、経由して`SphereGridNodeVisualInfo` 組み立てられた`panel.bin` （同じ理屈で`CreatePreviewVisual`/`BuildShortLabel`). **(2) 読み取り可能なノード** — オーブ ~12px（以前は5.5） + デフォルトのズームで読み取り可能なレベルで表示される（828個のノードがぎっしり詰まることはなくなった） + LOD（概要画面のドット） + ビューポートのカリング。 **(3) リアルタイムの「クソ検証」対策** — ノードを40単位未満ドラッグするか、リンクをクロスすると → ノードが**赤**になり、即座にバナーが表示される（「Validate」をクリックせず、変更されたノード/フレームのみを簡易チェック）。 **(4)** カテゴリ別色分け + パネル上の**キャプション**、選択中のノードに**点滅するグロー**（DispatcherTimer）、**ホバー**で点灯、**サウンド**経由で`AudioStudio_Service` (FFX UI SFXが同梱されています。プロジェクトが非公開であるため公開されました — 所有者による訂正)。**画像AIは含まれていません** — これはエディタに元々含まれていたゲームの実際のスプライトです。ビルドにエラーはなく、エディタはクラッシュすることなく起動します。[以前：`v2.37.0`] — Jarvis-MAGIC
- **🎥`v2.36.0` — AURORA：オーロラ・チェンバー内のカメラパネル（カットを編集する`camReq` 戦闘シーン：アングル／ショット＋ターゲット）。** 検証済みのカメラリーダー／ゲートの上（ドキュメント限定：chun

k0はAiFile ATEL、RT0 863/863であり、`camReq` （100% バイト単位で編集可能）、次に UI：**「🎥 カメラ」**カードにはカット一覧が表示されます`camReq` (`0x703F`) 選択したバトルの、編集可能な**SHOT**（アングル、1ベース）および**TARGET**（フレーム内の俳優、-1=なし）； **💾 カメラの保存** は、**same-length byte-local** オペランドのパッチを適用し（他のチャンクのオフセットは保持）、一度だけバックアップを行い、再読み込みします。読み取り/書き込みは以下を介して行われます：`FfxLib/BattleMap/BattleCameraScript_File` （AIと同じコーデック）。ファイル：`Modules/AuroraChamber/{AuroraChamber_DataModel.cs (CameraShots/PopulateCameraRows/SaveCameraShots), _Control.axaml (card + lista editável), _Control.axaml.cs}` (コードはすでに`c211a5f2`). ビルドエラーなし（エディタが開いている =`.exe` フリーズ；別ファイルへのビルドで確認済み）。**正直なところ：**スクリプトがすでに参照しているアングル／ターゲット間の切り替え；100％カスタムのアングル（新しい位置／FOV）＝ショットテーブルのRE`sub_797D60` （保留中、IDA）。ゲーム内での効果 = RT2（バイトセーフかつ可逆なゲート`BattleCameraScanLab`). [前へ：`v2.35.0`] — Jarvis-AURORA
- **🎭`v2.35.0` — Monster AI Editor：行動プリセット（#10）＋「N未満」という条件の検証済み（#11）＋境界条件 #12/#13 のドキュメント化。**「これを全部やって」というバックログのうち、正直に片づけられるものは片づける。 **#10 — 🎭 ワンクリックプリセット**（すでに検証済みの自動化機能で構成、戦闘ワーカーの自動選択＋成長の検証済み）： **🛡 防御的**（Protect+Haste自体）、 **⚔ 攻撃的**（ピッカーで選択されたスキルを常に強制）、**🔥 エンレイジ**（選択されたスキル＋Haste自体）、**🎲 ローテーション**（2回に1回の割合で選択）。 **#11 — 「N未満」という条件：** Behavior Libraryに保存された新しいスニペット`Se propriedade do chr (self) ABAIXO de N → forçar comando` = **#1のコーパス**の条件言語（`readChrProperty` 0x700Fは**980の分岐**を供給する；比較`LT 0x0B` （国勢調査で確認済み）、および`field`+`limiar`+`comando` ユーザーから提供された情報 — **注意：** HPの正確なfield-idはバイト単位で検証済みではありません（検証済みのステータス 0x38/0x31/0x32 を使用してください； HP = REの境界）であるため、これは汎用的なものであり、単純に「HP%」と割り当てるボタンではありません。 **#12（ターンN）**および**#13（ライブテスト）** = **境界として文書化済み**（ターン用のネイティブゲッターは存在せず、モンスターごとのpriv-varカウンターであり、1-in-KのRNGプロキシはすでに

 shipa; live は長さを維持する編集のみに対応し、grow = ゲームの再読み込み）v2.33.0 のドキュメントに記載。ロジック：`AiSnippetLibrary` (抜粋`guard-chrprop-lt-force-cmd`) + DataModel のプリセット (`ApplyPreset*`、で構成される`AddAbility`/`AddSelfBuff`). ゲート`--ai2`: **条件付きスニペット 346/346**（展開、ジャンプテーブルの拡大、再解析、検証）；`--ai3` PASS。ビルドエラーなし。**正直なところ：** オフラインで検証済み；readChrProperty の効果および引数個数 = RT2。[以前：`v2.34.0`] — Jarvis-MAGIC
- **🩺`v2.34.0` — Battle Tracker：動作確認済み（ライブバトルを読み込み） — 自動初期読み込み、正確なステータス表示 + RT2書き込みロック。** Battle Trackerが開くと**空の状態**（2つのパネルが空白で、「Load Ingame」が反応しない）。 原因は**アドレスではありませんでした** — 実行中のRAMで確認済み（FFX.exe PID 24716、バトル中`azit03_01`) チェーン全体が正しいことを示す：`ADDR_BATTLE_ACTIVE`(rva`0xD2A8E0`)=1,`ENEMY_LIST`/`PLAYER_LIST`(rva`0xD34460`/`0xD334CC`) 解決する、ストライド`0xF90`, のオフセット`MemoryChr` (`Id`@0xE,`Max_hp`@0x594,`Hp`@0x5D0,`In_battle`@0xDC8) ヒット、フォーメーションスロット`[0,4,6]` == 以下の3人のプレイヤー`In_battle=1`. バックエンド（`Binarysharp.MSharp` x64でFFX（x86版）を読み込むことも可能です —`new MemorySharp` +`Read<byte>(rva, isRelative:true)` 正しい値を返す。**原因はUXだった：**その`DataModel` **1回目の読み取りでは決して発射しなかった**（その`ArenaTracker` コンストラクタで読み込む（Battle Trackerは読み込まない）、またタイマーは「自動更新」がオンになっている場合のみ読み込んでいた。**修正：** (1) コンストラクタでの初期読み込み； (2) タイマーは毎ティック**正確なステータス**を維持し、**戦闘開始時に最初の写真を自動で表示**（「自動更新」をオンにする必要なし）し、戦闘終了時にクリアする； (3)`ReadInfo` try/catch を使ってエラーを処理し、さらにガード（ポインタが 0 / ヌルバイト / 範囲外のスロット）を追加する； (4)`MemSharp_Service.IsAvailable()` attach + で表示されなくなりました`IsAttached`; (5) UIに**ステータスバナー**（「FFXが見つかりません」／「同行中、戦闘なし」／「戦闘中：敵名・ N体の敵、M体の味方」）と、**RT2書き込みロック**（チェックボックス、デフォルト**OFF = 読み取り専用**）が追加され、「⚠ ゲームに保存」と名称変更されたボタンで制御されるようになりました。新しい検証ツール：`RuntimeTools/BattleTrackerProbe` （同じDLLを使用して、ライブ読み取りの動作を確認してください）。ファイル：`Modules/BattleTracke

r/{BattleTracker_DataModel.cs, BattleTracker_Control.axaml}`, `Services/MemSharp_Service.cs`, `RuntimeTools/BattleTrackerProbe/*`, doc `docs/reverse/FFX_BATTLE_TRACKER_LIVE_READ_PROVEN_2026-06-07.md`. Build do módulo OK (validado em worktree HEAD limpo; o build cheio do editor está quebrado por WIP `AiTargetOption` de outra lane, alheio a esta mudança). **Honesto:** READ provado na tela/RAM; a **escrita** (Load Ingame → `WriteProcessMemory`) segue RT2 (jogo aberto + trava ligada). [anterior: `v2.33.0`] — Jarvis-MAGIC
- **🎯`v2.33.0` — Monster AI Editor：ターゲット変更（#8）＋マルチキャスト／2番目のスキル（#9）、コーパスマイニングに基づく。** リストからさらに2つ、**RE/コーパス**を優先して、推測なしで作成**。新しいスキャナーは`AiScriptLab` (`--targets`,`--cond`) **1645カ所のコマンドサイト**と**10520のブランチ**をマイニングした（doc`docs/reverse/FFX_AI_TARGET_ENCODING_AND_CONDITION_GETTERS_2026-06-07.md`). **#8 — 🎯 ターゲットの変更：** ターゲットは command-id の直前の push です； **54%は計算される（PUSHV findMatchingChr）**、**46%はリテラル・センチネル（PUSHII）** — これらのみが1つのオペランドに置き換え可能（長さを保持、= RT2で証明された編集）。 正直なところ、**self (-13/0xFFF3)** だけがバイト単位で証明済みであり、その他の負のセンチネルは、その正確な意味がREの境界となるターゲットモードである。 したがって、エディタは**「自分自身」＋「このモンスターの別のアクションのターゲットをコピー」**（ゲーム内ですでに機能しているセンチネル）を提供しているが、その意味論については明言していない。 **#9 — ⧉+ マルチキャスト：** 選択したアクションの直後に、ピッカーで選択したスキルを挿入し、ターゲットとモードを複製する（シーモア式：2つのアクションを連続して実行；Rebuildによる成長）。純粋なロジック`AiAutomation.{ChangeTargetInstructions,InsertSecondCommand}` +`AiDetectedAction` 獲得した`TargetPushOffset/TargetOperand/TargetIsLiteral`. ゲート`--ai3`: **ターゲットの変更 195/195** (リテラルターゲット 757個)、**2番目のコマンドの挿入 294/294**; その他すべて（add/rng/detect/remove buff-stat/reorder/change/duplicate/toggle/self-buff/copy）はPASSのまま；`--ai2` PASS。ビルド0、エラーなし。**正直なところ：**オフラインで検証済みの構造；ゲーム内での効果＝RT2（マルチキャスト：両方が同じターンに解決されるか確認）。各センチネルをマッピング→モード＋HP％／ターン＝境界（ドキュメント参照）。[前回：`v2.32.0`] — ジャービス・MAGIC


- **🎥 AURORA — 実戦実績あり、chunk0で編集可能なバトルカメラ (`camReq`): 863回の戦闘に対するスキャン＋ゲート処理（ドキュメントのみ、csprojのバンプなし）。** リカバリータスクの再開（カメラパネル）。 **重要な発見：** 戦闘用カメラはchunk3には存在しない（`+0x2C` は一定）— **スクリプト駆動型**であり、**各バトル用TODOビンのchunk0は純粋なAiFile ATEL**であり、モンスターのAIコーデック（`AiScript_File`) **バイト同一の863/863 (RT0)**を再送信する — コーデックがこれまで見たことのないコーパスにおける新たな証拠（`declared@+0x10 == len(chunk0)`). それぞれのカットは、`camReq` (func-id`0x703F`) は、2つの即値オペランドを取り出します：**SHOT**（角度、1ベース；エンジンは shot-1 を使用）と **TARGET**（フレーム内のアクター、`0xFFFF`=なし）。**IDAに深く根ざした意味論**（`FFX_Atel_Battle_camReq @0x7A5E10` →`FFX_Battle_Camera_RequestShot @0x797BD0`): 1番目のポップ = その直前のプッシュ = TARGET (`v3`); 2番目のポップ = SHOT (`v4`); **以前の記述を訂正** — その`0xFFFF` call 内でハードコーディングされていたのは CONSTANTE であり、オペランドではありませんでした。コーパス：**646 ビン / 3736 呼び出し、オペランドの 100% が`PUSHII` 即時 → 100% バイト単位で編集可能**；SHOT はほぼ常に 1（→ インデックス 0）、TARGET は様々（28 が主流）。新しい純粋なロジック`FfxLib/BattleMap/BattleCameraScript_File.cs` (chunk0を抽出 → デコード → リスト`camReq` （ショット／ターゲット由来 + バイト単位のローカル編集（同一長）、他のチャンクのオフセットを維持） + ゲート **`BattleCameraScanLab`** (no`offline_ci.ps1`): **walk 863/863 · RT0 863/863 · edit shot+target round-trip 646/646** (バイトローカル + 可逆)。追加の発見：戦闘スクリプトでは`0x5F=POPF2`/`0x6D=PUSHF2` （有効、モンスター調査に未記載）。リネーム／コメントは`FFX_recon.i64`. ドキュメント：`docs/reverse/FFX_BATTLE_CAMERA_CAMREQ_CORPUS_PROVEN_2026-06-07.md`. **公正な境界線：**これにより、**スクリプトがすでに参照しているショット／ターゲット間での切り替え**が可能になります。100% カスタムなアングル（位置／FOV）については、ショットテーブルの RE が必要です（`sub_797D60`) — IDAは保留中。**次：** このリーダーの上にあるAurora Chamberの「カメラ」パネル。*(テスト/RE/lab = ドキュメントのみ、csprojには反映しない。)* — Jarvis-AURORA
- **🟢`v2.32.0` — Monster AI Editor：すべてのアクション（⚔ コマンド · 🛡 バフ/ステータス · 📊 ステータス）を一覧表示し、タイプ別にフィルタリング可能＋コマンド名の変更

名前のないもの（#6 および #7）。** 所有者のリストからの2つの要望。 **#6 — コマンドだけでなく、すべてを一覧表示する：** 「モンスターのアクション」は、**バフ／ステータス（`writeChrProperty 0x7018`)** および **stats (`setStatField 0x70AB`)**、**タイプ別フィルターのドロップダウン**（すべて / ⚔ コマンド / 🛡 バフ / 📊 ステータス）付き。 各アクションにはアイコンとフレンドリーネームが表示されます（既知のステータス = 「Haste/Protect/Reflect」、それ以外は「フィールド 0xNN」；ターゲットが自己反射の場合は「(自身)」；0の場合は「= 値」または「除去」）。 **移動 / 複製 / 解除**は、あらゆるタイプに対して有効になりました（実行時のスタック非依存の汎用的な解除）。`[pushes…][call]`); **切り替え / 強制↔キュー** は **コマンド専用** です（保存 + 警告）。 **#7 — 名前のないコマンドの名前変更：** IDが`performCommand` 辞書には見当たらない（例：`comando 0x60AB`)、**✏ 名前を変更** というフィールドが表示され、**永続化**されるわかりやすい名前を付けることができます（`%LocalAppData%\FFXProjectEditor\ai-command-labels.json`) であり、エディタ全体で、どのモンスターに対しても使用できます。まったく新しい純粋なロジック：`FfxLib/Ai/AiAutomation.DetectActions` (command+buff+stat;`DetectCommandActions` （フィルタリングされたビューに切り替わった） +`FfxLib/Ai/AiCommandLabels.cs` （起動時に読み込まれ、編集のたびに保存される；ゲートでは空 ⇒ 効果なし）。ゲート`--ai3` 拡張：**バフ／ステータスの検出 = 4020個のバフ（3698個が除去可能）＋ 4156個のステータス（4156）**、 **バフ/ステータスの解除 30/30**（一般的な解除は正確な実行によって縮小され、再解析される）、**再順序付け 325/325**（現在はあらゆるタイプの隣接対象を通過する）； add/rng/change/duplicate/toggle/self-buff/copy は引き続きPASS；`--ai2` PASS。ビルド0、エラーなし。**正直に言うと：**オフラインで検証済みの構造体；ゲーム内での効果＝RT2。バイト単位で検証済みのステータスフィールドIDのうち3つだけが名前が付与される（残りは「フィールド0xNN」、正直に言うと）。[前回：`v2.31.1`] — Jarvis-MAGIC
- **🧩`v2.31.1` — SPHERE GRID CANVAS：オーサリングパッケージ（破損防止検証、ビジュアル、スタンプ、リンクマネージャー＋複数選択）。** 所有者から要望のあった4つの機能は、すべてエンジンによる検出（近接ノード／リンクの交差による破損）に基づいて調整されています：**(1) 破損防止検証** — バイトセーフに加え、**近接**（2ノード < 40un、破損が確認済み）および**リンクの交差**（測定されたバニラ値 = 0、したがっていずれも現実的なリスクあり；セグメントの交差テストなど）について警告する。

および非隣接リンク）と**接続性**（情報：リンクのないコンポーネント／ノードの数 — 補足：Expertのデフォルト設定では25個のコンポーネントが表示されるため、これは「情報」であり、エラーではない）。 **(2) ビジュアル** — **参照ラティス**（ステップ43でズームインした際の点々）、選択したノードのリンクおよび近傍ノードの**ハイライト**、およびキャンバス上の**型名**（読み取り`panel.bin`; 常に選択され、「名前」トグルで全項目が選択され、ズーム表示）。**(3) スタンプ** — **◇ ダイヤモンド**（4ノード＋4リンク）および **— ライン**（3ノード）は、**すでに間隔が空いており（≥2×43）、接続された**形状を貼り付けます = 設計上エンジンセーフです。キャンバスをクリックして配置します。 **(4) リンクマネージャー + 複数選択** — ノードパネルにはそのリンクが一覧表示され、**✕ 削除** ボタンと「ノード # にリンク」ボックスがあります； **Shiftキーを押しながらドラッグ** = 選択ボックス → **Deleteでグループを削除**（インデックスを乱さないよう、降順でRemoveNodeを実行）。ライブラリの検証済みミューテーターに関するすべて。ビルドエラー0件；エディタはクラッシュせずに起動。 **正直に言うと：** 近接／交差の警告は**目安**となるヒューリスティック（エンジンの正確な上限値ではない）；接続性は参考情報です。[前：`v2.31.0`] — Jarvis-MAGIC
- **🟢`v2.31.0` — モンスターAIエディタ：他のモンスターのAIをコピー · 元のAIを復元。** リストからさらに2つ： **📋 AIのコピー** — 任意の他のモンスター（スクリプトを持つ294体のドロップダウンリストから）のAiFile全体を取得し、これに貼り付け、 **このモンスターのステータスやドロップアイテムは維持されたまま**（AiFileの領域のみが変更され、grow-awareスプライス＋検証が行われます）。これで、すでに希望通りの動作をする別のモンスターの挙動を、手っ取り早くこのモンスターに適用できます。 **♻️ オリジナルのAIを復元** — **抽出された参照**のモンスターのバニラAIを再コピーします（`<ffx_ps2>\ffx\master\jppc\battle\mon\_mNNN\mNNN.bin`、例：`D:\FFX Extracted`) — AIによる編集をすべて元に戻します（過去のセッションであっても、`.prev.bak` （1レベル）。両者とも`.prev.bak` 以前。レウサ`SaveNewAi` (ValidateRebuilt + grow-splice + backup + reload)。ゲート`--ai3`: **copy ai 346/346**（モンスターにAiFileをスプライス → スライスして元に戻す → 再解析、命令数は同じ）；その他すべて（add/rng/detect/remove/reorder/change/duplicate/toggle/buff）はPASS。 ビルドエラー0。**正直なところ：** オフラインで構造は検証済み；ゲーム内での効果＝RT2。（復元にはffx_psのroot権限が必要）

（参照番号2の設定済み。） [前へ：`v2.30.0`] — Jarvis-MAGIC
- **🟢`v2.30.0` — Monster AI Editor：1クリック操作の追加（複製・強制↔キュー・自身へのバフ・取り消し）。** 要望されている機能のリストを続けます：**⧉ 複製（2回キャスト）** — 選択したアクションの直後にそのアクションの3連発をコピーします（繰り返しによるマルチキャスト；grow + 再解析）； **⚡ 強制↔キュー** — 呼び出しを切り替えます`forcePerformCommand` (force) および`performCommand` (列)、1つのオペランド（長さを保持）； **🛡 自分にバフをかける**（Haste/Protect/Reflect via`writeChrProperty`, 「いつ」は「常に／時々」と同じ用法；戦闘ワーカーの自動選択、セーブされたgrow）； **↶ 取り消し（バックアップ）** — すべてのセーブで、現在は`.prev.bak` 上書きする前（1段階の取り消し）。新しいロジックは`FfxLib/Ai/AiAutomation.cs` (`DuplicateActionInstructions`/`ToggleForceInstructions`/`AddSelfBuff` + バフのプリセット）；保存データは以下に一元管理されています`WriteMonsterWithBackup`/`SaveNewAi`. ゲート`--ai3` 拡張：**duplicate 294/294**、**toggle 294/294**、**self-buff 346/346**（add/rng/detect/remove/reorder/change はすべてPASS）。 ビルドエラー0件。 **正直なところ：** すべてオフラインで検証済み（構造/長さ）；ゲーム内の効果は RT2 と同じ。バフのフィールド ID（0x38/0x31/0x32）はスニペットに記載されたものと同じ — さらに多くの ID をマイニングしたら、ステータスを追加する。[以前：`v2.29.0`] — Jarvis-MAGIC
- **🐉 AURORA — ゲーム内で検証済みのモンスター追加 (RT2): エディターで追加された2体のダーク・エオンがバトルに読み込まれ、クラッシュすることなくプレイ可能でした（ドキュメントのみ、csprojの更新なし）。** MARCO：Halysonがフォーメーション／アリーナ（Aurora Chamber ➕ / フォーメーションエディタ）により、**FFX HDがバトルを読み込み、追加アクターを完全なアクターとしてスポーンさせ、ダーク・ヴァレフォールがAIを実行してエナジーレイを発動**した（初期ターンでプレイ可能、FPS 30）。 chunk3/GROW（v2.27.0/51）チェーンの「正直なところ：ゲーム内では未検証」というダイスパスに関する記述を閉じる： **エンジンは編集されたモンスター数を認識し、追加アクターを実行する** — chunk2（編成、フラグ`0x1000`) + chunk3 (アンカー`+0x20`) スポーンループによって正常に処理された（データは完全；破損したデータは読み込まれない）。**しかし、Energy Ray でゲームがクラッシュした** = **コンテンツの不一致、バイト単位の破損ではない**：Dark Aeon（巨大モデル +

 フルスクリーンオーバードライブ＋独自のアリーナを占有するカメラ／エフェクト）を、その用途向けに設計されていないシン（Sin）のアリーナで実行すると、エンジンが固まってしまう。**率直な評価：** ゲーム自体は安全（読み込み＋スポーン＋AIが動作する）； **安定性を確保するには、アリーナに適したコンテンツが必要** — ダーク・イオーンは最悪のケース（安定した戦闘を行うには、通常のモンスターやロスターのモンスターを使用すること）。バナー＋ドキュメント・モデル §7 を更新。ドキュメント：`docs/reverse/FFX_AURORA_GROW_INGAME_PROVEN_2026-06-07.md`. **次：** レジーム-1 対 レジーム-2；予備枠なしのバトル；アリーナに適したモンスターによる安定性。 *(テスト/RT2 = ドキュメントのみ、csproj を更新しない。)* — Jarvis-AURORA
- **🔧`v2.29.0` — Monster AI Editor：移動（上/下）、入れ替え、アクションの削除 — モンスターを端から端まで編集できるようになりました。** 自動化機能（v2.24.0/49）に加え、「モンスターのアクション」リストに3つの新しい操作が追加されました。これらはすべて**length-preserving**（add/removeよりもさらに安全）です：**▲ 上に移動 / ▼ 下に移動**（隣接するアクションをスキップしてアクションの順序を変更します —`Rebuild` （命令の「ID」に基づいてジャンプ／エントリポイントを再マッピングするため、制御フローは移動したブロックに従います。移動した項目は、再度クリックするために選択されたままになります）および **✏ 上記で選択したスキルに置き換える**（選択したアクションのコマンドのオペランドのみを、ピッカーのスキルに書き換えます。これは、RT2-liveで実証済みの1バイトのFiraga→Thundagaと全く同じ仕組みで、MonMagic2やMulti-Firaを含むあらゆるコマンドに対応しています）。 純粋なロジックは`FfxLib/Ai/AiAutomation.cs` (`MoveActionInstructions`/`ChangeActionInstructions` +`CmdPushOffset` no`AiDetectedAction`); 自己完結型の3つ組にのみ提供されます（それ以外はバリデータによってブロックされます）。Gate`--ai3` 拡張：**reorder 237/237**（下へ移動、長さ保持、再解析、コマンドのマルチセットは同一）＋**change 294/294**（スロットがFiragaに変化、長さ保持、再解析）。 add/rng/detect/removeは引き続きPASS。ビルドエラー0。**正直なところ：** オフラインで構造が検証済み；移動すると実行順序が変わり、入れ替えるとコマンドが変わる — ゲーム内での効果 = RT2（意図的、開発者の目的通り）。 複雑なケース（非自明なターゲット／何らかの要因でアクションが逸脱する場合）は、高度なAIアセンブラの範疇となる。[前回：`v2.28.1`] — Jarvis-MAGIC
- **🧩🎮`v2.28.1` — SPHERE GRID CANVAS：トポロジーの編集（ゲーム内での動作確認済み）（+300 HP）＋調整（ノード名の種類別、スナップ

実際の間隔、復元／バックアップ）。** **MARCO：** Halysonが**Canvas（v2.25.0）でStandardグリッドを編集し、保存したところ、FFXが読み込み → 移動 → 追加されたノードを有効化 （キャラクターに+300 HPが適用）** — *「ゲーム内で編集されたトポロジー＝未検証」*という注意書きが**画面に表示された**（lib検証済み→Canvas→保存→実際のエンジンというサイクルが、所有者の手元で完結した）。 **エンジンに関する発見：** ノードが近すぎたり、リンクが交差したりすると、エンジンは**グリッドを破壊する**（オフライン・バイトセーフ ≠ エンジンセーフ）； バニラの「実際のサイズ」**測定値 = 基本間隔 ~43un**（平均リンク長 ~77、日付01/02/03）。 ツール化：**(1) snap-to-43**（配置・ドラッグしたノードがvanillaグリッドにスナップ；デフォルトでオン、トグルあり）； **(2) 近接警告** Validateにて（2つのノードが40un未満の場合、フラグが立ち、破損のリスクあり；アドバイザリーであり、byte-safeをブロックしない）； **(3) 名前別ノードタイプのドロップダウン**（読み取り`panel.bin` 経由`ReadNodeTypes` →「Strength +1」／「HP +200」／「Lv.1 Lock」…ヘックスの代わりに；ノード`FFh`=型を指定しないとゲーム内ではLv.3の鍵としてレンダリングされていたが、これで正しい型を設定できるようになった）； **(4) ♻️ オリジナルを復元**（プロジェクトに抽出された参照元のバニラグリッドをコピーする＝ゲームをクラッシュさせたセーブデータを元に戻す） + **バックアップ`.prev.bak`**「プロジェクトに保存」を行うたびに自動的に実行されます。ビルドエラーは0件。エディタはクラッシュせずに起動します。メモリ／間隔制約の検出が記録されました。 **正直に言うと：** トポロジーの編集は現在、**ゲーム内で検証済み**（読み込み＋有効化）です； 制限（近接／交差）は、エンジンの正確な上限ではなく、**測定された**ヒューリスティック値です — さらなるテストやREで微調整が必要です（リンクの交差検出は今後の課題）。[以前：`v2.28.0`] — Jarvis-MAGIC
- **➕`v2.28.0` — AURORA：UI上のモンスターの追加・削除（Aurora Chamber内のボタン）。** GROW（v2.27.0）にインターフェースが追加されました：純粋なオーケストレーター`FfxLib/BattleMap/BattleArenaAuthor.cs` **chunk2（編成）＋ chunk3（アンカー）をロックステップで同期**させ、さらにオーロラ・チェンバーには「位置を保存」の横に2つのボタン（**➕ モンスターを追加 / ➖ モンスターを削除**）が配置されています。 **2つのモードモデル：** 「add」は、余裕がある場合にアリーナの**予約済みアンカー**を使用します（`formação-viva < MonsterPositionCount`) = 編成の次のスロットのみを埋める、**chunk2のみ、growなし**；そうでない場合は **chunk3が拡大** する（モード2

,`BattleArenaGrowWriter`). この新しいスロットは、**最後に生存していたモンスターを複製する**（種族＋フラグ`0x1000`); remove は、最後に残っているスロットを削除します。backup-once を使用して保存します (`.aurora.bak`) +`ReloadSelectedBattle`. ゲート`BattleArenaGrowLab` 拡張（著者をリンク）：**AUTHOR add 694/694 + remove 302/302** （再デコード完了、スロットの複製・クリーンアップ、ライブ編成 ±1）に加え、RT0 700/700 + ADD 696/696 + REMOVE 393/393。 エディタはエラー0でコンパイル（exeがフリーズ＝エディタが開いている状態；出力一時ファイルでのビルドで確認済み）。ドキュメントを更新`FFX_AURORA_CHUNK3_PAYLOAD_MODEL_2026-06-07.md`. **正直なところ：** バイトセーフなオフラインモード；ゲームは新しいカウント = **RT2/probe**（画面上のバナー）を受け入れる。UX：フォーメーションエディタで種族を設定し、マップビューアで位置をドラッグして調整。 — Jarvis-AURORA
- **🐉`v2.27.0` — AURORA: chunk3の構造的GROW（バイト単位でのモンスターの追加/削除） — 「chunk3」のロックが解除されました。** 回答：`HANDOFF_AURORA_CHUNK3_RESOLVE_2026-06-07`. 以前はアンカーを**移動**することしかできませんでしたが（v2.12.0）、現在はモンスターの**カウントを変更**できるようになりました。 **パッキングモデルの修正（コーパス863、検証済み）：** area-recordは、8つの配列をポインタ順の固定順序でパッキングします（`origin<party<partyB<aeon<monA<monLive<monB<camera`, 863/863); **容量 = 次ポインタ − ポインタ**; **`monLive`(+0x20) は TIGHT** (==`MonsterPositionCount@+0x06`, 856/863) 一方で **`monA`(+0x1C) 予約 ~12** および **`monB`(+0x24) 予約領域 3..78** → 予約領域は、サイズ変更なしでより大きなカウントを吸収する。「謎のギャップ」は予約領域だった；`+0x30..+0x5C` = エリア／カメラあたり6つのfloat（ポインタ型ではない）。 **`BattleArenaGrowWriter.GrowMonsters`** = 末尾でのスプライス挿入／削除`monLive` + 再スタンプは`monB`(+0x24)/カメラ(+0x2C) + チャンクテーブル +`+0x06`; ガード：単一エリア + タイト + 予備 ≥ 上限 (HardActorCap=8 保守的; データ上限=15 znkd09)。ゲート **`BattleArenaGrowLab` PASS** (no`offline_ci.ps1`): **RT0 no-edit 700/700** バイト同一、**ADD +1 696/696**、**REMOVE −1 393/393**（クリーンな再デコード）。 対象外で拒否されたもの（149のマルチエリア + 6の非タイト + 13の異常なリザーブ → MOVE経由で引き続き編集可能）。トランスフォームバトル→シーンの調整済み = **IDENTIDADE**（ハンドオフ 2.3）。Doc`docs/reverse/FFX_AURORA_CHUNK3_PAYLOAD_MODEL_2026-06-07.md`. ビルドエラーなし。 **正直に言うと：*

* バイトセーフ・オフライン (RT0) ≠ ゲームが新しいカウントを受け入れる — **ゲーム内では未確認** (RT2/プローブ + 所有者の承認；スポーンループの正確な上限 = IDA 保留中)。 — Jarvis-AURORA
- **🔎`v2.26.0` — Monster AI Editor：スキル検索 + 欠けていた「Monster Commands 2」（カテゴリ MonMagic2 =`0x6000`).** 「オートメーション」画面におけるオーナーからの2つの要望：(1) スキルの**検索**（ドロップダウンには300以上の項目があった）および (2) 「**Monster Commands 2のスキルが見つからない**」（Multi-Firaなど）。 (2)の原因 — **REの発見：** 演算子の`performCommand` です`(category<<12)|id`, そして **大文字のnibbleはテーブルセレクタ** です (`FfxCommon_Util.GetGameCategory`/`GameCategory_Enum`):`3`=command.bin (キャラクター)、`4`=monmagic1, **`6`=monmagic2**. O`AiCommandId` 3と4しかマッピングしていなかった → エディタは**それを見落としていた**`0x6xxx`** (MonMagic2)、コーパスではその**291サイト**（ボス／エオン）が使用されているにもかかわらず。 根拠：エディタの公式リスト + コーパスのヒストグラム（ニブル 3=369 / 4=985 / **6=291** / 5=0；例：`0x60AB`=Multi-Fira #171) + 以前のFiragaのRT2。 **修正：**`AiCommandId` 獲得した`Monster2 = 0x6000` (`EncodeMonster2`/`DictFor`/`IsCommandOperand`/`AllOptions`) → これで、MonMagic2のコマンドを**デコード、一覧表示、追加・削除**できるようになりました。また、**コマンドごとのマルチキャスト**（Multi-Fira、これです）の制限が解除されました。オートメーションピッカー：わかりやすいラベルが付いた3つのカテゴリ（キャラクター／モンスター1／ **モンスター2**）＋ **検索ボックス**（名前または16進数、例：「Multi」、「60AB」）により、選択状態を維持したままフィルタリングが可能。高度なBehavior LibraryにもMonster2が追加されました。Gate`--ai2` 拡張：**mon2 rt 247/247**、**MultiFira=True**;`--ai3` **1645件のアクション**を検出するようになった（以前は1354件 → +291 = 以前は検出されていなかったMonMagic2が正確にこれだけの数）、278/278件を削除。Doc RE:`docs/reverse/FFX_AI_PERFORMCOMMAND_CATEGORY_NIBBLE_2026-06-07.md`. ビルドエラーなし、ゲート通過。[前回：`v2.25.0`] — Jarvis-MAGIC
- **🧩`v2.25.0` — SPHERE GRID CANVAS (v2 VISUAL)：グラフ上で「Original」「Standard」「Expert」を編集 + ノードのドラッグ＆接続。** ライブラリの基盤に欠けていたUI（FromExisting + ミュテーター、ゲート`--spheregrid-edit-rt0`). 新しいナビゲーション **「Sphere Grid Canvas 🧩」**（Builder v1の横） → **custom-drawn** コントロール（`SphereGridCanvasView`:`Render` + ポワント

手動で、800以上のシェイプを含むItemsControlではない（出荷時のグリッドには約828ノード／848リンクが含まれている）。**開く** オリジナル／スタンダード／エキスパート（経由`ReadLayout`→`FromExisting`、プロジェクトのabmap、またはフォールバックとして抽出された参照）または **新規**（ゼロから）； **ノードのドラッグ** =`MoveNode`, **ホイール** = カーソルのズーム、**右クリック** = パン、**+Link** モードでノードを2つクリック =`AddLink`, **+ノード**モードで、空白をクリック =`AddNode`, **Delete** でノードを削除します (`RemoveNode`). 選択したノードのサイドパネル (PosX/PosY/cluster/content →`UpdateNode`). **保存：** コピー`.dat` (レイアウト + コンテンツ) 非破壊編集、または **プロジェクトに保存** (abmap内のdat0X/dat1X、プロジェクトの読み込みが必要)。 レンダリング：クラスター＝淡い領域、直線／曲線のリンク（2次ベジェ曲線によるアンカー）、ノードの有無、選択状態＝金色の輪郭。**v1のゼロからの構築はそのまま維持**（独自のナビゲーション）。ビルドエラー0件；エディタはクラッシュせずに起動。 **正直なところ：** WriteLayoutはバイト単位で正確（ラウンドトリップRT0は実証済み）ですが、ゲーム内で新規／編集済みのトポロジーを読み込むことは依然として未検証です（画面に正直なバナーが表示されます）— 信頼する前にゲーム内でテストしてください。[以前：`v2.24.0`] — Jarvis-MAGIC
- **🤖`v2.24.0` — Monster AI Editor：ワンクリック自動化（ソフトウェアの「AI」がバイトコードを生成します）。** オーナーからの要望により、初心者ユーザー向けのボタンが追加されました。このボタンを押すと、エディタが自動的にATELのバイトコードを**エラーなく**生成し、保存前に検証を行います（このエディタは編集には優れていましたが、ゼロから作成するのは非常に困難でした）。 モジュール上部に新しいカード **「✨ 自動化（ワンクリック）」** が追加され、**➕ スキルの追加**（魔法／スキルを選択できる使いやすいドロップダウンメニュー経由で`AiCommandId` + 「いつ」：常に／時々 1-in-K → AIが戦闘ワーカーとエントリポイントを自動選択し、ジャンプテーブルを拡張する`AppendGuardedAction`, grow-aware を検証して保存する）および **➖ アクションを削除する**（モンスターがすでに実行しているコマンドアクションを、名前でデコードして一覧表示する；スタック中立のトライアドを削除する`[alvo][comando][CALLPOPA]` 経由`Rebuild` + relink（バリデータがダングルケースをブロックする）。+ **「テクニカルモード（実名）」**の切り替えにより、リストがニーモニック／生ヘックスで再表示される（オタクユーザー向け）。 フリー編集（AIアセンブラ＋ビヘイビアライブラリ）は、**そのまま**「上級モード」として残ります。抽出された純粋なロジックは**`FfxLib/Ai/AiAutomation.cs`**（編集者による注記なし、そのまま）`AiCommandId`/`

AiSnippetLibrary`) → testável e gateável. Novo gate **`AiScriptLab --ai3`** prova sobre o corpus (361 m*.bin, 346 c/ script): **add-ability 346/346** + **rng-guard 346/346** (auto-pick valida + re-parseia limpo como grow), **detect 1354 ações / 255 scripts**, **remove 241/241** (Rebuild encolhe exatamente a tríade dropada, re-parseia limpo) + **14 corretamente barradas** pelo validador (algo desvia pra ação). `--ai2` segue PASS. Build 0 erros. **Honesto:** estrutura provada OFFLINE; o **comportamento in-game de uma habilidade ADICIONADA depende de QUAL entrypoint roda por turno — NÃO é byte-provado** (só a estrutura é, 692/692), por isso o auto-pick de entrypoint é heurístico (maior-span), reportado de forma transparente e marcado **experimental/RT2** (confirmar via probe DINPUT8). Multi-cast/multi-alvo/condicionais HP%-turno seguem pendentes (corpus/âncora). [anterior: `v2.23.3`] — Jarvis-MAGIC
- **🐉`v2.23.3` — フォーメーションエディタ：空いているスロットに追加されたモンスターは、現在「フィールド上で生存中」のフラグを継承する。** 所有者がスロット04～07にモンスターを追加しましたが、それらは**「生存中」として認識されませんでした**（オーロラ「生存中のモンスターは4体のみ」）。画面上の証拠：元のスロット（00～03）にはraw`10DEh`/`10E2h` (**ニブル高`0x1000`**); 追加されたものは削除されていた`0030h`/`0136h` (**ニブル高`0x0000`**). O`0x1000` フォーメーション内の「アクティブ」なモンスターのフラグだ――ライターはこう書いていた`0` かつては……だった枠を埋めることで`FFFFh`. フィックス (`FormationSlotRow`): 空いているスロットを埋める際、**そのバトル自体の「兄弟」であるアクティブなスロットの上位ニブルを継承する**（バトルごとに適用、キックなし；デフォルト`0x1000` （フォーメーションが100%空だった場合）。引き続きスロット専用かつバイトセーフである（ゲート FormationSlotLab 858/858）。**追加の診断情報（セーブに関するバグではありません）：** セーブと読み込みは同じパスを使用しています（`GetPathBattle`); 問題は「金額」であり、どちらの側かではなかった。**正直に言うと：** (1)`0x1000`=「生きている」というのは、画面上の証拠に基づく仮説である — **ゲーム内でテスト**； (2) オーロラのマップには、**ARENA（chunk3）で定義されたモンスターのアンカー**のみが存在する（例：4） — これ以外のモンスターを追加するには、新しいアリーナのアンカーが必要となる（アリーナの作成は、今回の修正の範囲外）。 ビルド0のエラー。[以前：`v2.23.2`]
- **🧩 Sphere Grid Builder v2（基本機能：既存のグリッドを編集） — lib + gate、なし

 bump csproj.** v1 (`v2.22.0`) はゼロから作り上げていた；読み込んだモデル（`SphereGridLayoutFile` + エントリ）は`init`-only（変更不可）、「オリジナル／スタンダード／エキスパート」の編集をロックします。新しい基盤を`SphereGridLayoutBuilder`: **`FromExisting(grid)`** ビルダーは、各クラスター／ノード／リンクを**フィールドごとに**クローンして展開します（保持されます`Unused*`/`Unknown6`/`RedundantContent` + 実際のヘッダー文字列 + コンテンツファイルのバイト数） — 以下の処理を通過しない`Add*` （これらのフィールドを空にするもの）。 + 変更子 **`UpdateNode`/`MoveNode`/`SetNodeContent`/`SetNodeCluster`/`UpdateCluster`/`MoveCluster`/`UpdateLink`/`RemoveLink`/`RemoveNode`**（インデックスの再マッピング＋重複リンクの削除）**/`RemoveCluster`**. 編集 =`FromExisting → mutar → Build → WriteLayout`、～には触れずに`init`-only。新しいゲート **`--spheregrid-edit-rt0`** (`Tools/SphereGridLayoutEditRt0`, + で`offline_ci.ps1`): 3つの実際のグリッド（dat01/02/03）において、**(1)**のno-editを検証`FromExisting→Build` **レイアウトおよびコンテンツ**においてバイト単位で同一、**(2)**`MoveNode` そのノードの**PosXの2バイトのみ**を変更する（ゼロ・フィールド・ブリード）、**(3)**`SetNodeContent`/`RemoveNode` 有効な往復；＋コーパスなしの合成ケース＋範囲外のポジティブキャッチ。3つすべてで**PASS**（元828→削除により827ノード）。経験的：`RedundantContent==contentByte` 828/828 ノット；`Unknown6` ゼロ以外のノードごと（保持）。 **実情：** LIB + GATE のみ — **UI（キャンバス + 読み込み/編集）が欠落**しており、**編集済みのトポロジーをゲーム内に読み込むことは依然として未検証**（オフライン対応 ≠ エンジンが、これまで出荷されたことのないグリッドを受け入れること）。 ビルドエラー0件、3つのゲートでspheregridがPASS。*(ライブラリ＋ゲート、UIなし＝ドキュメント専用；csprojのバージョンは上げない — UIがリリースされた時点で上げる。)* — Jarvis-MAGIC
- **🔄`v2.23.2` — オーロラ：「ディスクのバトルを再読み込み」（マップ上に他のモジュールのセーブデータを反映）。** 所有者がフォーメーションエディタで編成を編集したところ、モンスターが **オーロラのマップ上に表示されなかった**。調査の結果、パイプラインは **正常** である — オーロラはバインドされている`formation slot[i] → monster-live anchor[i]` com`MonsterId`/`Model` (`/work/phyre_chr_anim/models/mNNN/mNNN_animated.gltf`, **340個のHDモデルが存在する**、サーバールートのURLが正しい）。原因は**キャッシュ状態**だった：その`RefreshCatalog` シーンのリストのみを再読み込みし、開いているバトルのバイトデータは再読み込みしない――つまり、

 外部で作成されたトレーニング版は、再選択するまで反映されませんでした。修正済み：新規`ReloadSelectedBattle()` (バトルの読み込みを再実行 = ディスク上のchunk2のフォーメーションとchunk3のアンカーを再読み込み) + 「レンダリング」の横にある**「🔄 ディスクからバトルを再読み込み」**ボタン。 （Battle Explorerにはすでに「Refresh」があり、ナビゲーションごとに新たに生成される — これはすでにそこにあった。） 「Changed: False」＋「マップ上にモンスターなし」の**複合的な根本原因**は、フォーメーションの保存が反映されていなかったことでした — **v2.23.1**で修正済み（combo-blank）。ビルド0エラー。[以前：`v2.23.1`]
- **🐛`v2.23.1` — フォーメーションエディタ：すでに埋まっているスロットに、モンスターの名前が表示されるようになりました（ロード時の表示不具合を修正）。** 報告者によると、フォーメーションの8つのスロットのうち、すでに値（raw 10DEh/10E2h）が設定されているスロットでも、ComboBoxが**空**の状態で開いてしまうという問題がありました。 — 手動で選択した「後」になって初めて名前が表示される（空のスロット（FFFFh）でさえ、「(空)」ではなく空白のままだった）。原因：Avaloniaの落とし穴 — 当該`SelectedItem` load（オブジェクト初期化子）で設定された値は、各行のComboBoxが`ItemsSource` (RelativeSource 経由でバインドする場合)、選択が反映されず、空白のままになります。修正：`Slots`, それぞれを再適用する`SelectedMonster` (null→値) を切り替える`Dispatcher.UIThread.Post(..., Background)` — そこで、ComboBoxは、すでにデータが入力済みのItemsに対して再解決を行います。保存元：`slotsSyncing` **ダーティフラグを立てない**ため（実際の編集が行われるまで、loadは「Changed: false」のままとなる）。ビルドエラー0件。[前回：`v2.23.0`]
- **🔮`v2.23.0` — 魔法ビューアー（PS3 Magic HD）における「SPELL」の名前：ベストエフォートでの参加（所有者が許可）。** 所有者は、バイト検証済みのjoinがなくても名前を表示するよう指示した（「今こそやるべきだ」、2026-06-07 — **no-fabricate** ルールに対する**明示的なオーバーライド**）。新規`MagicSpellNameResolver` (FfxLib/Dictionaries): magic_#### (ID 0～1023、12ビット) → 試みる`CommandCharacter` →`CommandMonster1` →`CommandMonster2` →`Item` (すべて`Dictionary<ushort,string>`), 戻る`nome ~fonte` （例：`Firaga ~char-cmd`) または`magic_####` マッピングされない場合。**PS3 Magic (HD)** で動作しない (`Ps3MagicBrowser`):`Ps3MagicEntry.SpellNameDisplay` リストのタイトルと詳細ページのヘッダーが入れ替わり、検索は名前で行われます。**正直なところ：**その`~fonte` 「仮説」であり、バイト単位で検証されていないブランド（カタログには「no」と記載されている）

 「names proved」); 所有者が画面上で検証を行い、名前が間違っているものがあれば、オフセットや辞書を修正します。ビルドエラーは0件。[前回：`v2.22.0`]
- **🧩`v2.22.0` — SPHERE GRID BUILDER (v1、ゼロからの開発)：このライブラリがようやくUI上で実証された。** グリッドのトポロジー（クラスター／ノード／リンク／位置）はHARD-LOCKEDだった；その`SphereGridLayoutBuilder`+`WriteLayout` (ゲート`--spheregrid-build-rt0` PASS）は画面なしの状態で存在していました。新しいナビゲーション **「Sphere Grid Builder 🧩」** （Core Authoring、Sphere Grid Explorerの横）→ フォームベース：**Add Cluster / Add Node / Add Link** → リアルタイムリスト → **Validate**（ライブラリによる範囲チェック）→ **Build & Save**（`.dat` 経由`WriteLayout`（バイトセーフ、プロジェクトルートまたはexeディレクトリに保存）。「ゼロからスフィアグリッドを作成」という見出しの通り、ようやく実用可能な状態になりました。**v1の正直なところ：** 視覚的なキャンバスはなく（位置は数値で指定）、既存ノードの値を編集するには引き続き「Sphere Grid Explorer」を使用します。 **ゲーム内ステータスの再確認（あなたの疑問）：**`WriteLayout` バイト単位で正確である（ラウンドトリップ RT0 が実証済み）が、**ゲーム内に新しいトポロジーを読み込むことについては依然として実証されていない** — オフライン対応 ≠ エンジンが、これまで配信したことのないグリッドを受け入れること（画面上に正直なバナーが表示される）。 ビルド0のエラー。[前回：`v2.21.0`]
- **❓`v2.21.0` — ナビゲーションの「???」カテゴリ：エディタのない3つのWave-1ファミリーは、現在ブラウザが読み取り専用となっています。**所有者からの依頼：**「**リーダー＋ライター、バイトセーフ、ゲートRT0が実証済みだが、画面がゼロ**」なWave-1ファミリーを、専用のカテゴリに分類してください。 3つ見つかりました（他のモジュールはすべてすでに配線済みでした）：**`buki_get.bin`**（武器・宝物カタログ）、**`albheddic.bin`**（アル・ベド辞典）、**`battle_script.bin`** (ポインター/スクリプトテーブル)。ナビゲーションの最後に新しいカード **"???"** が追加（Wave-1、エディタなし） → ボタン3つ → 汎用コントロール1つ`UnwiredCatalog_Control(family)` ファイル（ワークスペースマスターまたは抽出された参照）を解決し、FfxLibのリーダーを介して読み取り専用エントリを一覧表示する（`BukiGetTreasureCatalog_File`/`AlBhedDictionary_File`/`PointerScriptTable_File`, デコーダー`FfxEncoding.UsDecoder`). 正直なところ、ライターは存在します（RT0はバイト単位で同一の未編集状態）が、**編集機能はこの画面の範囲外**です。ビルドエラーなし。[前：`v2.20.1`]
- **🔌`v2.20.1` — 無効になっていた「Extras」タブが復活：source-root が抽出された参照を自動検出します。** 所有者は次のように指摘しました **Tex

tures (TM2)、PS3 Magic (HD)、PS2 Models (RSD)、PS2 Audio (.wd)、Project/Pipeline、Magic Effects、および Presentation Containers** が開くと中身が空になっていた。原因：`Project_Service` 解決していた`Path_FfxPs2Root`/`Path_Ps3DataRoot` 歩きながら`master→ffx→ffx_ps2` — しかし、読み込まれたワークスペースは **Steam-mod master** です (`...\data\mods\ffx_ps2\ffx\master`), その`ffx_ps2` あるのは`.bin` モディファイド（ZEROソースアセット）であり、`ps3data`. 修正：リゾルバーは、**既知の抽出ルート**を優先するようになりました（`D:\FFX Extracted\FFX` →`ffx_ps2` +`ffx_data\gamedata\ps3data`、～と`Directory.Exists` guard + プロジェクト派生版へのフォールバック + 手動オーバーライド「Set ffx_ps2 Root...」）。これらのルートは、読み取り専用ブラウザ（8つのモジュール）専用です。**カーネルライターは、変更されていないProjectPath（master）**を使用します。 これで、8つのタブに正しい参照が自動的に設定されます。ビルドエラーは0件。[以前：`v2.20.0`]
- **🗺️`v2.20.0` — エディタに組み込まれたマップシーンエディタ（ブラウザ不要）：WebView2標準の3番目のビューア。** オーナーからの要望（「エディタ『内部』で、Model Viewer Embeddedと同様の機能を実現してほしい」）：新しいナビゲーション **「Map Scene Editor 🗺️」**（Spira Forgeのカード、Auroraの隣） →`SetModule` 展示会`MapSceneEditorEmbedded_Control` **編集可能なマップシーンのラボ**をホストしている（`RuntimeTools/FFXMapViewerWeb` Jarvis-MAP レーン：**299 マップ**、クリックによるサブメッシュの選択 + ギズモ + マテリアル／ライトパネル + サイドカー`map-edits.json`) ウィンドウ内のWebView2パネルで。**再利用`WebView2Host` 共有**（Model b36 / Magic b37）— 3つのビューアーが1つの埋め込みインフラを共有するようになりました。新機能`MapSceneEditorLauncher` (http 8768：Aurora 8765/Magic 8766/Model 8767とは異なる + キャッシュバスター + 出口でPythonを倒す) +`MapSceneEditorEmbedded_Control/DataModel`. ビルド0でエラーなし、エディタはクラッシュせずに再起動する。**調整：** Jarvis-MAGICが、所有者の依頼によりJarvis-MAPのレーンからWebを組み込んでいる — 通知は`SESSION_HANDOFF`. [前へ：`v2.19.2`]
- **🗺️ 描画時 HOOK SPEC: 描画ごとにマテリアル→テクスチャを自動ログ（SpecialKの「Highlight Selected」機能に代わるもの） — RE ドキュメントのみ、csprojへのバンプなし。** DBのREコピー：最適なフックポイントが見つかりました =`FFX_Phyre_BindNamedTextureUnit_DrawTime` @`0x67DAC0` (RVA`0x27DAC0`)、**1回の描画につきテクスチャ単位あたり1回**と呼ばれる

* フラッシュによる`FFX_Phyre_FlushTextureUnitBinds_PerDraw` (0x67E990)。プローブ用の正確なレシピ：`__stdcall(arg0=slot dst, arg1=descritor)`; **textureKey = ASCII文字列`[[arg1+0x94]+0x20]`** (= 標準化されたテクスチャ名 = ベースネームの`.dds`当社のエクスポーターの/import-pathは、1対1で`Compressed_<CHK>.dds` + PNG画像`tex/`); 安価なフィルターをスキップ`FrameBuffer`/`RealFrameBuffer`/`NoTexture`. **正直に言うと：** エンジン内のバインドサイト（グローバルステートによって制御されるループ）には、FileMaterialId/MeshId/SubmeshId といったものは存在しません`dword_CCC81C`（素材のオブジェクトではない）— 正確な結合キーは**テクスチャ名**である（`honest-limit`); 記述子のポインタは重複排除のみに使用される；サブメッシュごとの曖昧性解消 = 描画送信時の2番目のオプションフック（今回の実行では未検出）。検証済みのチェーン：`0x642560→0x67E990→0x67DAC0→0x6A3240→0x66E680→sub_4D5910`. データベース内の名前変更＋コメント コピー＋`idb_save`. 仕様：`docs/reverse/FFX_PHYRE_DRAWTIME_BIND_HOOK_SPEC_2026-06-07.md`. *(RE/lab = ドキュメントのみ、エディタの csproj を更新しません。)*
- **🗺️ 画面上で実証済みのフィールドWARP（probe/ctl — doc/lab、csprojの更新なし）：プレイヤーをマップ上の任意の座標へリアルタイムでテレポートさせる。** 動詞を実装しました`ffxprobectl whereami/backup-pos/restore-pos/nudge/pos/warp` (`RuntimeTools/FfxDinput8Probe/ctl/Program.cs`, アドオン、ビルド OK）を、稼働中の FFX.exe に対して実行（プローブ`hooked=1`):`whereami` プレーヤーの現在の位置を読み取る（`inst+0x0C/10/14`, 歩行が確認された場合 = X/Zが続く）、および`nudge`/`pos` **テレポートしてくっつく** — **ハリソンは、画面上でキャラクターの位置が変化するのを見たと確認した**。フィールドワープ`structural`→**確認済み**。**発見事項：** フレームごとのリバートがトリガーされない（`inst write + reseat` field-actorのキャッシュがなくても十分である（spec §1Aのオフライン理論を精緻化する）。これは、忠実度の高いRenderDocキャプチャ（マップの表面まで移動すること）の前提条件である。未解決の課題：クロスエリア`warp <sceneId>`, 表`sceneId→área`, field-actorの解決。仕様/RE:`docs/ai/FFX_FIELD_WARP_TOOL_SPEC_2026-06-06.md` +`docs/reverse/FFX_FIELD_*_2026-06-06.md`. *(probe/ctl lab/RE = ドキュメント専用；エディタのcsprojを更新しない。)*
- **🐉`v2.19.2` — 埋め込みの修正：WebView2はパネル全体を埋め尽くし、リサイズにも追従します（両方のビューアに適用されます）。** 画面上では、WebView2は…

arcadoは画面の一角（hiDPIディスプレイでは約67%）にのみ表示され、周囲が「黒」で囲まれており、エディタのサイズに合わせて表示されませんでした。原因：`SyncControllerBounds` 増え続けていた`Bounds × RenderScaling` また、Avaloniaはすでにホストウィンドウのサイズを、**DPIの二重カウント**（コンテンツが~1/scale）に合わせて調整しています。修正済み`WebView2Host` （共有されたため、**Model Viewer v2.19.0 と Magic Viewer v2.19.1 を一度に修正**）：**親ウィンドウの実際のクライアント矩形**に基づいて WebView のサイズを調整します（`GetParent`+`GetClientRect`, スケール計算なし） + **リサイズ時の再同期** (`EffectiveViewportChanged` +`ArrangeOverride` 承認された日付：`DispatcherPriority.Background` （Avaloniaの後に実行するには、ネイティブホストの位置を再設定する必要があります）。ビルド0エラー。画面上の確認＝所有者の目。[前：`v2.19.1`]
- **🪄`v2.19.1` — エディタに組み込まれたMAGIC VIEWER（ブラウザ不要）：v2.19.0のWebView2を再利用しています。** 投稿者への直接の回答（「当初からエディタ『内』での表示がコンセプトだった。ブラウザを開くのは馬鹿げている」）：**「Magic Viewer (Web)」**は外部ブラウザを開かなくなりました。現在はナビゲーションが`SetModule` …を示して`MagicViewerEmbedded_Control`、**ウィンドウ内のWebView2パネル**。**再利用します`WebView2Host` 【共有】**Model Viewerがv2.19.0にアップデートされました（2つのビューアに共通の埋め込みインフラを採用し、重複を排除）。新機能`MagicViewerEmbedded_Control/DataModel` +`MagicViewerLauncher.EnsureServerAndGetUrl` (ローカルHTTPサーバー8766番ポートを起動し、キャッシュバスターを有効にして、WebViewからそのサーバーにアクセスする)；**Reload**ボタンと**Open in Browser**ボタン（フォールバック）。 **連携（同じブランチ上の2つのチャット）：** もう一方のチャットがコミットするのを待ち、`WebView2Host` (v2.19.0) これには、破損したツリーがない「クリーンな」状態が前提となります。彼のレーンにおけるコード監査の結果は`HANDOFF_CODE_AUDIT_HD_MODELS_2026-06-06.md`. **ビルドエラー0、エディタはクラッシュせずに再起動する。** [前回：`v2.19.0`]
- **🐉`v2.19.0` — エディタに組み込まれたモデルビューア（ブラウザ不要）：パネル内のネイティブWebView2。** プロット・ツイストの第2段階：816個のモデルで使用されていたのと同じ three.js ビューアーが、**エディターウィンドウ内**のパネルで動作するようになりました — 「Extras」カードに新しいボタン **「Model Viewer (Embedded) 🐉」** が追加されました →`SetModule` …を表示します`ModelViewerEmbedded_Control` **Edge WebView2** をホストしている`NativeControlHost` (interop win32: 子 HWND + `CoreWe

bView2Controller`, bounds sincronizados em `ArrangeOverride`, HiDPI por `RenderScaling`). Usa o **runtime WebView2 Evergreen JÁ instalado** (sem bundle Chromium — nuget `Microsoft.Web.WebView2` 1.0.2592.51, ~poucos MB; **NÃO** o CEF pesado que bumparia ~100MB). O painel sobe o mesmo http server (`ModelViewerLauncher.EnsureServerAndGetUrl`, porta 8767, cache-bust) e navega o WebView pra ele; botões "Reload" + "Open in Browser" (fallback). `Program.cs`/AppBuilder **intocado**. **Build 0 erros.** Spike provado num worktree isolado (juiz: compila + 0 warnings novos) antes de trazer pro main. Fase 1 (browser, v2.18.0) segue como fallback. **Decisão do dono junto:** galeria abre no **rest pose LIMPO** (animação opt-in) — paramos o whack-a-mole de animação offline; animação real = mocap depois (fila). Doc `FFX_MODELVIEWER_EDITOR_2026-06-06.md`. [anterior: `v2.18.1`]
- **🔧`v2.18.1` — 自己監査：私（Jarvis）のミス6件を修正（2つのチャットの対立的レビューで発見され、各発見事項は別の担当者が確認）：**
  - **Ps3MagicBrowser**：各フォルダの最初のテクスチャがUIスレッドで同期的にデコードされていた（私が修正したと述べたフリーズの原因）**かつ**バックグラウンドでも再度デコードされていた — 現在はrow[0]がバックグラウンドで処理されるようになり、`DecodeRows` すでにデコード済みの行をスキップし（ダブルデコードの終了）、そして`decodeGeneration` ひっくり返った`volatile` （ワーカー↔UIの可視性）。
  - **モンスターAIエディタ**：ヘックスを編集（`AiEditRow`) または AI アセンブラにおけるオペコード／オペランド (`AiAsmRow`) **画面上の意味が更新されなかった** —`AiEditRow` さあ、発射だ`OnPropertyChanged(Meaning)` コマンドの16進数Eのセッターで；`AiAsmRow` ひっくり返った`ObservableObject` および Meaning/Label/HasOperand を通知する。
  - **OpcodeHelp**: オペコードのツールチップに誤りがある (`StartsWith("PUSHFF")` 結婚することは決してなかった；`PUSHF` float-const がレジスタのヘルプでエラーになっていた） — 以下で処理されるよう書き直した`OperandKindOf` （実証済み）、不安定なニーモニックの接頭辞によるものではない。
  - **MagicViewerLauncher**：これが「Waiting for catalog」の原因だった――ブラウザを開くと、Pythonが起動していなくても「成功」と返されていた；現在は`EnsureViewerServer` boolを返す、pollの処理時間が約6秒に増加（コールドスタート）、失敗時は**正直なステータス**を返す、URLで**キャッシュバスター**（スタブが古くなっている場合）、**ProcessExitでPythonを終了させる**

**（プロセスはリークしない）。
  *（修正は「私の」ファイルのみ。もう一方のチャットでの失敗は`docs/ai/HANDOFF_CODE_AUDIT_HD_MODELS_2026-06-06.md` 彼に確認・修正してもらうため — 彼のレーンには手を出していない。）* csproj を更新。
- **🐉`v2.18.0` — エディタ内の「MODEL VIEWER (HD)」：テクスチャ付き＋アニメーション付きの816個のモデルの3Dギャラリー。** 「これはエディタ内で動作させる必要がある」という予想外の展開が機能として実現：[Extras]カードに新しいボタン**「Model Viewer (HD) 🐉」**が追加され、クリックすると`RuntimeTools/FFXModelViewerWeb` (three.js + GLTFLoader) を localhost の HTTP 経由で配信（Magic Viewer/Aurora で実証済みの同じ手法 —`python -m http.server`, 別個のポート **8767**; HTTPは必須`fetch()` カタログ + GLTFLoader の`/work/...`). このビューアーは**アニメーションギャラリー**であり、**816モデル**を網羅した統合カタログです（`modelviewer-catalog.json`, HDレーンのベースラインから生成されたもの — pc/sum/npc/mon/obj/wep), **カテゴリ別フィルタ + 判定 + 検索**、サムネイル、および **アニメーションクリップの再生**（AnimationMixer + クリップセレクター） + オービット／グリッド／ワイヤー／スピン／フィット。 HDシリーズ（META 1 + ピュアHD）でベイクされたglTFをそのまま使用 — 再ベイクは不要。`ModelViewerLauncher.cs` (のクローン)`MagicViewerLauncher`) + ボタン`Main_Window.axaml`/handler。**ビルドエラーなし；配信テスト済み（catalog/index/gltf = 200）。** **csprojを更新**（実際のUI機能）。 **フェーズ2の計画（オーナーの決定）：** 同じビューアをエディタのWebViewパネル（ブラウザなし）に組み込む — 1つのNuGetパッケージが必要；three.jsエンジンはホストに依存しない。ドキュメント：`FFX_MODELVIEWER_EDITOR_2026-06-06.md`. [前へ：`v2.17.0`]
- **🗺️ マップシーンエディタ — 閲覧専用だったビューアが編集可能なラボに（doc/lab — csprojのバンプなし）：** o`RuntimeTools/FFXMapViewerWeb` スタンドアロン編集レイヤーが追加された（これは、後にSPIRA FORGEが引き継ぐものとなる――Forgeを起動せず、統合されたコックピットも使わず、C#での書き換えも不要）。**(c0)** three.js **ローカルでベンダー化**（オフライン、CDNなし――`vendor/three/` 589個のjsmファイル、MIT；importmapは、unpkgのフォールバックがコメントアウトされた場所を指している）。**(M1)** **クリックによるサブメッシュの選択** (`editor/selection.js`): ドナーからクローン化されたレイキャスター`aurora-overlay.js`, 安定した鍵方式`keyOf="meshId:submeshId"`, ウォークモード／ポインターロックでセーフ (+ ガード`isGizmoEngaged`: レース・ギズ

mo-vs-代表チーム（プレドラグ終了）。**検証済み**：**実際のベンダー化済みGLTFLoader r165**を`azit00` 実数：1 メッシュ／14 プリミティブ → 14`THREE.Mesh`、それぞれ`geometry.userData.{submeshId,meshId,fileMaterialId}`, 14個のユニークな鍵, 0回の衝突。 **(c2/M2)** **サイドカー`map-edits.json`**（真実のソース、不変のglTFに対してキーごとの差分処理を再適用 — glTFは決して再シリアル化されない；`editor/mapEdits.js` baseline-once + reset + layer; **証明済みの冪等性** 対 実際のthree@0.165.0：1回の適用==4回、兄弟要素はそのまま、localStorageのラウンドトリップ、冪等なlight） + **gizmo** MITのTransformControls (`editor/gizmo.js`, 「LOCAL」→「家」と入力し、Yキーで下方向へスクロール） + **素材・照明パネル** (`editor/materialLightPanel.js`, クローン・オン・ライト)。**(M3)** 新しい C# ライター **`PhyreDdsWriterLab`**: 往復`.dds.phyre` 5つの実サンプル（DXT1/DXT5）で**バイト単位の正確性が実証済み** — 「デコード専用」エクストラクタの逆操作；および**書き込み方向に関する結論**：`.phyre` **書き換え可能**です。オフラインで、MIT roelin 系統（リークされた PhyreEngine SDK なし）を介して — ドキュメント`FFX_PHYRE_WRITER_FEASIBILITY_2026-06-06.md`. **(M4)**`PhyreModelExportLab` 追加フラグを獲得 **`nodePerObject`**（デフォルトはOFF、バイト単位ではレガシー仕様と同一；ON = サブメッシュ・バッチごとに1ノード/1メッシュ）— 上限値はオブジェクトごとではなく、サブメッシュ・バッチごとです。 **(M5)** **オブジェクトごとの配置に関するRE CRACKED (オフライン)**: placement =`PNode::m_localMatrix` (PMatrix4 inline, 64B, struct **+0x10** のオフセット); world は実行時に順次生成される`m_parent` （リフレクション記述子による検証済み）`sub_5055B0` + 歩く`sub_5067C0`, db コピー) + scene-load/material-bind チェーンの RE (`graphicFieldMapLoad`→bind core`0x65BA20`; texture-anim はマテリアルでのみ使用可能`*Mat_CTA*`). **正直に言うと：** **この実行では画面上の検証は利用不可**（プロジェクトのルール：視覚的な真実＝Halyson） — JSの検証は`node --check` + 実際のローダーのハーネス + 競合するレビュー；C# による`dotnet build` + バイト単位の往復通信。M1/M2 = データロジックが実証済みのSCAFFOLD；耐久性あり（3b）はラボに準拠。計画：`docs/ai/FFX_MAP_SCENE_EDITOR_20_STEP_PLAN_2026-06-06.md`; クリアランスセール:`docs/ai/FFX_MAP_SCENE_EDITOR_BUILD_CLOSEOUT_2026-06-06.md`. *(lab/RE = ドキュメント専用、エディタのcsprojを更新しません。)*
- **🐉 目標1 解決済み

DA — Phyreのparent-mapがオフラインです（doc/lab/RE — csprojの更新なし）：`m_matrixParents` (`PMesh` f44) バイト単位の正確さ + 回収されたHDの残りの約半分。** コーデックスが設定した目標`blocked-by-probe` (parent-map PNode) が IDA 経由で検出されました：Phyre スケルトンのバイト単位で正確な parent-map は ** です`PMesh::m_matrixParents`** (`PArray<int32>`, struct offset 40 → file-link **f44**, ArrayLink`@ DataOffset+ObjectsSize+Offset`, root=−1)。出典：`.dae.phyre` == プローブの**6/6 バイト単位**のライブキャプチャ (c001/c004/c005/n042/n054/n043) → **「オフラインでは不可能」という条件を偽装**（Codexは誤ったフィールドを捕捉した：PNode→PNode、3～9％）。修正済み`phyre_chr_gate` (「」と読む)`m_matrixParents` （爆発を引き起こしていた約5％のヒューリスティックに代わる、確実な手法）。 **残りの59フレームに適用（リベイク＋Blender QA：審査員＋懐疑的な対立者によるチェック）：クリーン16＋トーション13＝29/59が使用可能（49%）、100%オフライン； モーションキャプチャー 59→30；アニメーション済みキャスト 91%→95% 使用可能。** IDAコメントは以下に保存済み`0x490330` (コピー`FFX_recon_modellane.i64` + rename-queue）。**ライブモーションキャプチャセッション（同日）**により、プレイ可能な「エオン」（ヴァレフォール／イフリート／アニマ／ヨジンボ／マグス）におけるキャプチャパイプラインの有効性が実証された その結果、7体の「破損したエオン」は、**召喚時のエフェクト／プロップモデル**（木／影／デカール）であり、クリーチャーではないことが判明した。ゲーム内では正常にレンダリングされる。 **6つが再分類され除外 → クリーチャーの残数 30→24**。検証済み：`ffxprobectl spawn 0x30NN` (slot=s-id) は、任意のモデルを画面に表示します。ドキュメント：`docs/reverse/FFX_PHYRE_MATRIXPARENTS_OFFLINE_SOLVED_2026-06-06.md` +`FFX_AEON_MOCAP_SPAWN_AND_SUM_PROPS_2026-06-06.md`. **クローズ（PURO-HDベイク）：残留値 59→9。** 静的PURO-HDベイクを実装（Phyreスケルトン、リターゲットなし）`.chr`): BlenderのQAで、残りの24個のうち = **13個がクリーン、2個が復元されたトーション**（静的）、**9**個が残っている（8つのモノとs013、その大半がノメッシュ）；アニメーション付きキャラクターは **91%→98% が使用可能**。 注：15体はスタティック（アニメーションなし — ピュアHDモーションパス／モーションキャプチャが不足）。Doc`FFX_HD_PUREHD_STATIC_RESCUE_2026-06-06.md` + プラン`docs/ai/FFX_HD_PUREBAKE_10STEP_PLAN_2026-06-06.md`. *(RE/lab = ドキュメント専用、エディタのcsprojは更新されません。)*
- **🪄`v2.17.0` — Magic Viewer 完了（3レーンの並列ワークフロー）：エディタに統合されたWebビューア + 洗練されたメニュー + REの`root+88` 閉鎖中：**
  - **ラ

ne A — エディタに組み込まれたWebビューア：** o`FFXMagicViewerWeb` （Codexが構築したもの — Spell Index、Package Graph、Texture Stack、Runtime Evidence、Effect Stage、Crosswalk ＋ 6つのインデックス／カタログ）は**孤立**していた（エディタ上にボタンが一切なかった）。 新しいボタン **「Magic Viewer (Web) 🪄」**（「Extras」グループ、「PS3 Magic (HD)」の隣） +`MagicViewerLauncher.cs` ～に役立つ`RuntimeTools/FFXMagicViewerWeb` 経由`python -m http.server` (ポート 8766、Aurora 8765 とは異なります) を開き、ブラウザを起動します — Aurora/MapViewer と同じ手順です（HTTP が必須：`app.js` する`fetch()` カタログから →`file://` （CORS-hangになる）。パスを使用しなかった`file://` SpiraForgeHubより。
  - **レーンB — 洗練された魔法メニュー2つ**（読み取り専用、書き込み不可）：PS2`Magic Effects` **検索**（package/lane + kernel/lane）と**適切な空状態**（空のパネルではなく、アクション可能なメッセージ）が追加され、「Counts」カードが「Summary」と重複しなくなりました。PS3`Magic (HD)`: **UIスレッド外**でのサムネイルのデコード（容量の大きいフォルダでもフリーズしなくなった — 行には「pending」と表示され、ストリーミングされる）`Dispatcher`（旧式のパスワードに対するgeneration-tokenを使用）、**テクスチャ名による検索**、および「フォルダを開く」「ファイルを開く」ボタンには`IsEnabled` （dead-clickはなくなりました）。*（IDによるスペルの名前は引き続きBLOCKEDのままです — name-tableは存在せず、join`magic.bin→magic_####` 「因果関係が遮断されているだけで、私が作り出したわけではない。」*
  - **レーンC — REの`root+88` (Pass12、ドキュメント専用、実データベースに適用済み)`FFX_recon.i64`):** Pass11の2つのオープンタスクを閉じました。**(1) runtime-rootにデータを格納するのは誰か：**`sub_7FD9A0` (`FFX_Magic_MaterializeRuntimeRoot`) インストールする`FFX_Magic_RuntimeRootTable[0x12A4080]` ブートストラップ（bin-load）で一度実行し、リセットする`root+88`; 各フェーズではテーブルが置き換えられることはなく、同じルートを再利用し、その場で変更を加えます。**(2) 最終的なライターは`root+88`:**`sub_817200` = **0x21** オペコードのハンドラが`FFX_Magic_OpcodeHandlerTable` (`0xC48EC8`); 家族の中で`0x1000` 書く`root+84`=`root+88`=ワークコピーでも同じカーソルを使用し、フェーズ終了時にルートへ書き戻す。5つのリネーム＋コメント`[pass12]` 適用され、本番データベースに保存されました。Doc`docs/reverse/FFX_MAGIC_ROOT88_WRITER_PASS12_2026-06-06.md`. *(正直なところ：spell→具体的なオペコード、エンジン精度のタイミング、およびライターの完全なカバレッジは、依然としてBLOCKEDのままです。)*
  - csproj を更新 (

実際のUI：launch + polish）。*（レーンCはRE/doc-onlyですが、同じエントリに入ります。）*
- **🧠`v2.16.0` — Monster AI Editorが使えるようになりました：意味の解読＋スキル名＋フィルター（＋クラッシュの修正）：**
  - **二重クラッシュが解消：**「Monster Commands 1/2」（KernelCommands）を開くとエディタが終了していた問題 — 2つの選択ハンドラ（`CommandList_SelectionChanged` +`MonsterLinks_SelectionChanged`) は、**null** である指定された XAML フィールドを、`EndInit`**（そして、ロード時間が300msを超えるとタイムアウトが発生していた）。現在は`sender` （常に有効）。
  - **各命令の意味**（Edit Operands E AI Assembler）：`CALL 7010`→`Battle.findMatchingChr`,`CALLPOPA 700B`→`Battle.performCommand`,`POPV`→`var[1]`, jumps→`→ jump[n]`. ヘルパー`AiScript_File.OperandGloss(opcode,operand)` +`OpcodeHelp` (オペコードごとのツールチップ) + キャプション。
  - **コマンド／スキルのオペランドには「名前」が表示されます：**`PUSHII 0x3049`→`⚔ Firaga` (出典：`AiCommandId`/`CommandCharacter_Dictionary`）、もはや「12361 [3049h]」ではありません。
  - **コマンドフィルター：** 名前／ニーモニック／16進数で絞り込める検索ボックス🔎（「Firaga」や「3049」と入力すれば、約300行をスクロールする手間が省ける）＋「X/Y」カウンター。
  - **名前付きモンスター一覧：**`m004`→`m004 · Mafdet` (以下で解決)`Monster_Dictionary`, IDのフォールバック)。
  - モジュールの説明を修正（以前は「read-only」だったが、編集：Edit Operands + AI Assembler + Behavior Library）。csprojを更新（実際のUI）。
- **🎨`v2.15.1` — モンスターコマンド／バトルコマンド／アイテム：プロパティエディタをShop Explorerの標準仕様に合わせて刷新（50列のスプレッドシートは廃止）：** o`KernelCommands_Control` **約50列もある巨大なDataGrid**（オーナーが要求した「クソみたいなプロパティ」であり、`FFX_EDITOR_UI_CONVENTIONS.md`) **カード形式の詳細表示**の標準レイアウト：左側にコマンド一覧、右側にグループごとのカード（Identity/Animations/Menu/Characters-Targeting/Costs/Attack Data/Element）が表示された詳細パネル、**フラグはWrapPanel内のチェックボックスに変更** （80列ではなく、読みやすい表示）、容量の大きいグループ（Properties、Status chance/duration、Status Special/Buffs、Extra）は**折りたたまれたExpander**にまとめられ、「Where Used / Monster Links」は3列目に維持されています。 **編集可能なフィールドは一切失われていない**（列ごとのdiff）

na; Name/Descriptionのみが読み取り専用になります（セッターのないデコード済みゲッターです）。ハンドラー／イベント／パブリックメソッドは変更なし（Save/Undo/Discard/LoadIngame、フィルター、OpenMonsterRequested、RestoreViewState）。クリーンなビルド、エラー0件。 *（エージェントが隔離されたワークツリーで作成、グリーンまでビルド、そのまま適用。）* csproj を更新（実際の UI）。
- **🖱️`v2.15.0` — Aurora DRAG-TO-PLACE + 縦向きマップ（フリップ） + ドラッグ可能なパネル（開発者により稼働中と確認済み）：**
  - **ドラッグ・トゥ・プレイス：** MapViewerで、「Place mode」を選択 → モンスター（球体）を平面上にドラッグ → ドロップ → 新しい座標がエディタに戻り、**「💾 位置を保存」**ボタン（オーバーレイ内のエディタ**E**内）が位置を保存します。`.bin` **byte-safe** バトル（**に委譲する**）`BattleArenaPositionWriter` 検証済み；X/Y/Zのみが変更され、Wは維持、バックアップ`.aurora.bak` （自動）。生存が確認された：`azit03_00` ただし、chunk3の位置配列でのみdiffが発生します。
  - **Web→エディタチャネル（欠けていた部分）：**`AuroraDragBridge` —`TcpListener` **OSが選択した任意のポート**（NO`HttpListener`/固定ドア：そこには群れが`python -m http.server` ドアを踏みつけ +`HttpListener` urlacl/admin が必要）。HTTP/1.1 以上（CORS +`POST /drag` +`POST /save`); ドアはディープリンクでビューアーに遷移します (`&drag=<porta>`). 新しいゲート`--dragbridge-selftest`: POST→バッファ→読み取りの往復 **PASS**。
  - **`Battle_File.WriteWithMonsterPositions`** (フォーメーション・オーサリング・ティア1) — 欠落していたポジションの入力、ミラーリング`WriteWithFormationSlots`.
  - **逆さまのマップ 修正済み：** PhyreのジオメトリはY軸が下向きであるのに対し、glTF/Three.jsはY軸が上向きである → ジオメトリ **および** アンカーグループにおいてX軸を180°回転させた（原点が同じ → 位置が揃う）。 ドラッグによる反転の対応（`group.worldToLocal`).
  - **Overlay UX：** タイトルバーから**ドラッグ可能**な「🌅 Aurora overlay」パネル + 各コントロールに**ツールチップ**。
  - csprojの更新（Auroraで動作するUI機能）。ゲート`--kernelcmd-roundtrip`/`--dragbridge-selftest` ドキュメント専用となります。
- **🐛`v2.14.3` — 「Monster Commands (monmagic)」を開いた際のクラッシュ（エディタが強制終了）＋ワークスペースの永続化＋Auroraでの名称表示：**
  - **クラッシュ：**「Monster Commands 1/2」を開くとエディタが強制終了した（NPEが発生）`Ability_Command.WriteList`→`WriteBytesIntoTextFile`, すでに`BuildFile()` （建設業者による）。

 **根本原因：** モデルの名称が変更された`UnusedText1/2*`→`JapaneseOnlyText1/2*` + 以下の賞を受賞した`Original*Offset` (preserve-only v2.14.1)ですが、**UIのラッパー**（`KernelCommands_Wrapper`,`MonsterStatSheet_Wrapper`) 旧名称のまま、オフセットは削除された →`PropertyUtil.CopyProperties` **これらのフィールドを**`Wrap`/`Unwrap` → null になっていた → preserve-only が失敗し、append-rebuild に切り替わり、monmagic の空の JP-only フィールドで NPE が発生していた。**修正:** 2 つのラッパーで完全なラウンドトリップを実行（rename +`Original*Offset`) +`FfxEncoding.WriteBytesIntoTextFile` null-safe。 **新しいゲート**`--kernelcmd-roundtrip`** (`Tools/KernelCommandRoundtripRt0`) GUIの正確なパスを指定します（`ReadList→Wrap→Unwrap→WriteList`) **バイト同一 4/4** (command/item/monmagic1/2) — これは`AbilityCommandLab` （近道）構造的には見当がつかなかった。Wired誌の`offline_ci` → **26ゲート PASS**。
  - **ワークスペースの永続化：** フォルダ`master` 読み込まれたデータは、以下の場所に保存されます`%LocalAppData%\FFXProjectEditor\last-project.txt` そして**起動時に自動復元**されます（優先順位：CLI引数 → 最後に読み込まれたもの → デフォルト）。1回読み込めば、永久に記憶されます。デフォルトでは、もうSteam-modに落ちなくなります。
  - **グローバルなクラッシュロガー**（`%LocalAppData%\FFXProjectEditor\crash.log`, 経由`Utils/CrashLog`) + 守備的な負荷が`KernelCommands` （アプリを強制終了させるのではなく、説明付きの赤いエラーが表示される）。
  - **オーロラ・チェンバー：** モンスターのアンカーに**名前**が表示されるようになった（`🔴 <nome>`) ではなく「monster (live)」 (`_currentLineup`→`AuroraAnchorRow`).
  - ドキュメントのみの同乗：`docs/governance/FFX_EDITOR_UI_CONVENTIONS.md` （パネルテンプレート＝Shop Explorer、50列のDataGridではない）＋DINPUT8ルールが廃止（プローブなし）＋チェックリストに多言語ノート／MagicViewerを追加。csprojを更新（UI機能）。
- **🈶`v2.14.2` — BattleTextExplorerにJPフォントが追加されました（本物の漢字です。もう`<MISS>`) + 新しいゲート2つ：** o`BattleTextExplorer_DataModel.ReloadSources` 今、読み込み中`jppc/battle/kernel/btl_txt.bin` ～とともに`JpDecoder` — 2バイトクラックの目に見える成果（v2.14.0）。新しいゲートによる**ヘッドレスでの検証済み**`--btltext-jp-decode` (`Tools/BtlTextJpDecodeRt0`): JP`btl_txt.bin` = 128件 / 451語 → **44の漢字** が表示されました`<K:n>` (銀行`base.ftc`), **0

`<MISS>`**、および **往復ロスレス 451/451**（デコード→エンコード==バイト数）。現実が推測を裏付けた：**戦闘**のテキストでは共通のデータベースのみが使用されている`<K:n>` (なし`<FTCX>`/`F2`/`F3`/`F5` — これらはイベントごとのものです）。**「ゴーストバグ」の修正：** フラグ`--btltexttable-rt0` は、ヘッダーに表示されていました`BtlTextTableRt0.cs` しかし、**nunca foi wired no`Program.cs`** — バックグラウンドで実行すると、GUI（WinExe、stdout 0）へのフォールスルーが発生し、「出力なしで終了」していた。 現在の結果（デフォルトはJP、言語のフォールバック）：JP **PASS** (3982/3982) + US **PASS** (1910/1910)。`--wave1-rt0` **12/12 PASS** が続きます；`--btltext-jp-decode` wired no`offline_ci.ps1` → **25 ゲート PASS**（以前は 24）。*（2 つのゲートはドキュメント専用となる予定だった。csproj のバンプは、エクスプローラーの UI 上の JP ソースによるものである。）*
- **💾`v2.14.1` — MonMagic Saveがバイトセーフになりました（ドリフトしていた最後のライターが削除されました）：** o`Ability_Command.WriteList` **preserve-only** モードが追加されました：読み込み時にテキストプールの元のオフセットを取得し、テキスト編集を行わない保存時には、**元のプールをそのまま再出力**します（各スクリプトを元のオフセットに配置 → 文字列が共有されます。例： monmagicの空のフィールドはすべてオフセット0にあり、重複することなく共有される）。 再読み込みによる検証：編集によってスクリプトのサイズや内容が変更された場合は、通常通りappend処理が行われます。これにより、**command/itemを破損させていた重複排除処理**（前述で反論済み）を行わずに、monmagicのドリフトを解消できます。Gate`AbilityCommandLab`: **command/item RT0 4/4 + monmagic RT0 4/4**（以前は 0/4 drift だった）＋全箇所で 1-flag-edit が検出された；**monmagic が CERTIFIED に昇格**（drift は現在、ゲートを通過できなくなった）。`offline_ci` PASS. bump csproj（カーネルエディタの保存が、monmagic向けにバイト単位で正確になった）。
- **🈶`v2.14.0` — JPテキストデコーダーは2バイトの漢字を読み取ります（今日のクラックの成果）：** ロスレスコーデック`FfxEncoding` **2バイトのソースリード**を認識するようになりました（`0x06`/`0x26-0x2F`、で実証された`docs/reverse/FFX_EVENT_TEXT_ENCODING_CRACKED_2026-06-06.md`) そして、**判読可能なグリフの参照**を表示します —`<FTCX:n>` （イベントの漢字）、`<K:n>` (漢字は`base.ftc`),`<F2/F3/F5:n>` （その他の銀行） — の代わりに`<C..>`+`<MISS>` 先ほどの文字化け。**100%対称エンコーダー**（トークン↔バイトが完全に一致）。新しいゲート`--jptext-rt0` イベントコーパス内のテスト（367～

ファイル、**18,935個のJPスクリプト、15,467個が2バイトグリフ**）： **グリフドリフト = 0** ＋ **冪等**なコーデック（既存の文字エイリアスは1回正規化され安定化される＝安全；no-editは元のバイトをそのまま返す）。これは直接的に`BattleTextExplorer` （ロスレスを使用する）。`offline_ci` = **23ゲート** 合格。**csprojのバンプ**（UI上で容量を確認可能）。
- **🧱 Sphere Grid BUILDER do ZERO + バリデータ（オフライン検証済み — csprojの更新なし：ライブラリ＋ゲート、UIなし）：**`SphereGridLayoutBuilder` (`AddCluster`/`AddNode`/`AddLink` →`Build()`) は、メモリ上にグリッド全体を構築し、その上に`WriteLayout` 検証済み、**範囲検証機能**付き（`Validate()` 範囲外のリンク/クラスターを拒否 → ゲームをクラッシュさせるファイルは決して送信しない）。新しいゲート`--spheregrid-build-rt0` (`Tools/SphereGridLayoutBuildRt0`) テスト：build→WriteLayout→ReadLayout **構造が同一** + **2回目のパスでバイトが同一**（イデポテンツなシリアライズ） + バリデータによる**positive-catch**（範囲外のインデックスを持つグリッドを拒否 +`Build()` （投げる）。これは「ゼロからスフィアグリッドを作成する」という作業の半分にあたる（その`WriteLayout` （シリアライザの半分でした）。**CI：22ゲート**（エディタの内部15＋ラボ7）。その他の機能の仕様は以下で公開されています`docs/ai/FFX_UNLOCKED_FEATURES_DESIGN_2026-06-06.md`.
- **🌐 Sphere Grid LAYOUT/TOPOLOGY ライター（オフラインでの動作確認済み — csprojのバンプなし：ライブラリ＋ゲート、UIはまだ未実装）：**`SphereGrid_File.WriteLayout` メモリ内のモデルのグリッドのトポロジー全体（ヘッダー＋クラスター＋位置情報付きノード＋リンク）を再シリアライズする――これにより、**「ゼロからスフィアグリッドを作成する」**ことが可能になる（以前はノードの値のみ編集可能で、トポロジーはハードロックされていた）。新機能`--spheregrid-layout-rt0` (`Tools/SphereGridLayoutRt0`) dat01/dat02/dat03（オリジナル／スタンダード／エキスパート）におけるバイト同一性テスト（編集不可） — read→WriteLayout==original。**拡張CI：**`offline_ci.ps1` 現在、エディタの14個の内部ゲートが動作しています（`--wave1-rt0`+12 +`--spheregrid-layout-rt0`) 7つのラボに加えて = **21ゲート PASS**。**バイト保持リファクタリング**（ゲートはそのまま）：ヘルパー`AppendTextScript` 抽出（`Ability_Command`+`Monster_StatSheet`) + 名前変更`UnusedText1/2*`→`JapaneseOnlyText1/2*` (試験問題`FFX_REPO_ARCHAEOLOGY`; BinaryMapper はオフセット指定型 ⇒ RT0-safe）。 + ドキュメント

`docs/reverse/FFX_EVENT_OFFLINE_DECODE_PASS_2026-06-05.md` (静的デコード EV01) +`PORT_STATUS`/`RUNTIME_TOOLS_INDEX` 更新済み。
- **`v2.11.0` — 🧠 プロダクト化されたAIアセンブラ（実用的な超強力なAIエディタ）：** コーデックの「
  100%自由なAI編集」機能が正式な機能となりました。レーンでの新機能`FfxLib/Ai` +`Modules/MonsterAiEditor`:
  - **挙動ライブラリ** (`AiSnippetLibrary`): パラメータ設定可能なテンプレートで、そのバイト配列は
    コーパスに含まれる検証済みの言語を反映している — 線形（`force-cmd`/`perform-cmd`/`grant-field`/`set-stat`/`raw-call`)
    および条件付き（RNG 1-in-K ローテーション、カウンター／フェーズ「イベントなしでもコマンドを実行」）。
  - **プレフライト・バリデータ** (`AiValidator`): オペコード∈48、HasOperand vs 0x80、**孤立した分岐/エントリポイント**
    （不透明なthrowの代わりに具体的にどのものかを示す）、オペランドの範囲、RT0自己チェック、リビルドのドライラン、拡大/縮小；
    `SaveAssembler` 守備的になった（ブロックミス）。
  - **使いやすいコマンドセレクター** (`AiCommandId`): performCommand ↔ 名前 経由`(cat<<12)|id`
    について`CommandCharacter/CommandMonster1_Dictionary`; UI上のドロップダウン（生の16進数表示は廃止）。
  - **新しいコーデックプリミティブ**（`AiScript_File`):`GrowWorkerJumpTable` (ワーカーのジャンプテーブルにスロットを追加
    — 新しい分岐を有効化) +`AppendGuardedAction` (保存済みのアクションをエントリポイントに事前追加し、
    ハンドラを維持する) +`OperandKindOf`.
  - **UI** の`MonsterAiEditor`: カード動作ライブラリ + 「Validate」ボタン／レポート + コマンドドロップダウン。
  - **Gate`AiScriptLab --ai2` PASS**（実データセット 361）：jump-grow **898/898 ワーカー**、guarded-action
    **692/692**（1番目＋最後のエントリポイント）＋合成センチネル 1/1、バリデータクリーン 346/346、AiCommandId
    620/620、positive-catch 8/8/8（エディタのパスによるjumpOOB）。`--` オリジナルのRT0 **361/361 完全無傷**。
  - 敵対的レビュー（4名のエージェント）により、2つのバグ（endの1つ先のセンチネルによるループ；`OperandKind`
    （エディタのセーブデータにドロップされた）、ゲートでロックされている。ドキュメント：`docs/reverse/FFX_AI_JUMPTABLE_GROW_PROVEN_2026-06-05.md`
    +`docs/ai/FFX_AI_ASSEMBLER_PRODUCTIZED_2026-06-05.md`.
  - ⚠️ オフラインでの動作確認済み；**ゲーム内での動作（RT2）はHalysonの承認待ち**（テスト中）。テンプレート
    「HPが25%未満の味方を回復」および「tでエンレイジ」

「N」のデータは未出荷（バイト不足—HPフィールド／カウンターの確認が必要）。
- **🐉 HDモデルレーン — テクスチャ化済み＋ベイク済み＋視覚QA済みのサマ/NPC（ドキュメントのみ、バンプなし）：** §7.2/§7.4の
  `SUCESSOR_FFX_HD_MODELOS_MASTER_2026-06-05.md` sum/npc用に非公開。
  - **テクスチャ（マニフェスト駆動型）：**`extract-texture-batch` で`RuntimeTools/PhyreModelExportLab` 獲得した
    **`--from-manifest`** これを読む`g_fileNames[]` の`<id>.ahwin32` (= 権威あるアセットマニフェスト) から、
    ゲームが読み込む正確なテクスチャを抽出します。**305個のPNGファイル**（PC/NPC/SUM）、出所マップ`texture-provenance-map.json`,
    **0件のサイレントミスマッチ**。RE: o`ahwin32` これは読みやすいC言語のヘッダーです — 相互参照を解決します (`c906←c106`,
    `c908←c108`,`c806←c805`) そして、多彩な質感（`c101+c101_01`,`n238+n238_hair`,`n356←n238_hair`) 行きなし。
    ボーナス発見：NPCのリグの継承キー =`0x6NNN` no`.chr` (マップ nXXX→kNNN、222/222 有効)。
    Doc`docs/reverse/FFX_AHWIN32_ASSET_MANIFEST_2026-06-05.md`.
  - **Bake (メッシュ+テクスチャ+アニメーション):** ドライバー`work/_scratch_mgrp/bake_cast.py` 経由`phyre_chr_gate`. **静的
    253/253**（テクスチャ化済み、クリーンな全キャスト）。アニメーション：独自の動き、NPCが継承`skl/<base>`.
  - **視覚的QA（ワークフロー、視覚担当エージェント21名）：** F3Dによって選別されたアニメーション248点 — クリーン157点／トーション58点／
    エクスプロード33点。 33個のバインドピッカー（rest/A1）は修正されなかった。
  - **🔧 Blenderによる修正（2026-06-06）：F3Dはスキンアニメーションにおいて誤った情報を返していた。** Blenderによる診断（メッシュ
    `EXPLODE_RATIO≈1.0`, 成長しない）＋忠実なレンダリング（イーブイ）により、「爆発した」キャラクターは**体は無傷**であり、
    手足やアクセサリーだけが伸びているだけであることが証明された。 再QA（Blenderのレンダリングに関する8名のエージェント）**により、175クリーン（71%） / 59
    トーション（24%）／14 エクスプロード（6%）** — **20モデルが救出**、オフラインベイクは常に**約94%が利用可能**だった。
    14体の真正なモデル = **11体のAeon + 3体のNPC**（非ヒューマノイドのリグ；モーションキャプチャー／REの親マップが必要）。ルールの更新：**
    Blenderの画面が決定権を持ち、F3Dは誤り**。パイプライン`work/_scratch_mgrp/blender_{diagnose,render_anim,batch_render}.py`.
  - **🎯 リターゲティングの問題は以下により解決されました`--retarget-delta` (2026-06-06): 175→215 clean (87%)。** 新しいフラグが
    `phyre_chr_gate` 継承されたモーションを**delta**として適用する

frame0のNPC**のRESTについて (`M=restLocal·inv(m0)·mf`),
    ベースの比率を強制するのではなく、NPCの比率を維持する。REは（IDA）、リマップが`.chr@0x30` すでに
    適用されていた――原因は**rest-poseのリターゲティング**であり、リマップではなかった（ドキュメント`FFX_INHERITED_MOTION_REMAP_RUNTIME_2026-06-06.md`).
    パイロット＋バッチ73件の失敗＋Blenderによる再QA＋**モデルごとのベスト保持**：**+40件のクリーン、44件の救出、リグレッションゼロ**
    （1件はリグレッションの恐れがあったため保持）。 **アニメーション付きNPC = 200/222 クリーン (90%)、0 破損**；残りの **8 Aeons** が破損
    （メッシュは影響なし → モーションキャプチャー）。A1のリスクなしに、MASTER §2.4の「A1-universal」を解決する。
  - **🐉 キャスト全員のオフライン収録完了（2026-06-06）：498/643 クリーン（77%）、90%が使用可能。** 残りのオブジェクト（obj/wep/pc）（46クリーン/55、パーティはクリーン）および**340体のモンスター**に対して、Blender準拠のQA +
    リターゲット・デルタ + キープベストを適用。 以前の
    モンスター（bbox）のQAでは「0爆発」とされていたが、**嘘**だった；Blender忠実QA（29エージェント）により**127の実際の不具合**が発見された；
    継承された66体に対するretarget-delta → **36体が昇格**、モンスター206体→**237クリーン**。 **アニメーション対象合計（643）：498 clean /
    86 トーション / 51 爆発 / 8 ブランク。** 残存分（9%）＝メッシュの不整合／バインドの劣化 → モーションキャプチャー／RE-メッシュ処理、リターゲットは行わない。
  - **obj/wep/pc (2026-06-06):** 同じ拡張パイプライン — スタティック **obj 110/110 + wep 79/79 + pc 34/49**
    (15件のpcエラー = ダミースロット)`c8xx` なし`.chr` PS2）。**HDフルキャスト（静的）＝476モデル。** obj/wepはほぼ
    すべてリジッド（アニメーションは散在：25/7）；画面のスポットチェック：f001/w001/c004＝オーロンは問題なし。
  - ギャラリー`work/cast_hd_gallery.html` (モデルビューア、静止画／アニメーションの切り替え、sum／NPC／obj／wep／pcフィルター)。すべて
    `work/` (gitignored): コマンドのみがコードです。**csprojのバージョンアップなし** (RuntimeToolsのlab/RE)。
- 登録ドキュメント`docs/ai/FFX_TOOLBOX.md` 作成（生体登録 §11の
  `FFX_TOOLBOX_DISCOVERY_PLAYBOOK_2026-06-05.md`): **オンライン**スキャン +
  FFX HD/PS2用外部ツールのライセンス検証 (VBF、Phyre、カーネル`.bin`、ATEL、FMOD、
  TM2、FMV）およびエディタのNuGets。却下された主な発見事項：**External File Loader
  (ffgriever, BSD-2)** 再パッケージ不要のルーズファイル、**Kaitai Struct** (C# MIT ランタイム) による
  C#+JS リーダーの生成、**fahrenheit** (MIT, C#) C言語用MODフレームワーク

hook+DLL、および
  **FFXDataParserがライセンスなし（研究用のみ）**であることの確認。列`testado?`
  まだ`❌` — コーパス対照テスト（オラクル）は保留中。計画はドキュメント内に記載済み。ドキュメント限定：
  **csprojのバージョンアップなし**（lab/REのドキュメント限定ルール）。
- 2026-06-02の新しいバッチを、FFX HD/PS2の集中的な調査向けに統合。
  ツールは読み取り専用とし、Claude/Codexへの引き継ぎを実施：
  -`Ps3MapViewerLab` カタログ化する`ps3data\map`/`btlmap` そして、最初の
    エリア／スライスのローカルスキャンを生成した；
  -`PhyreMapExportLab` 開いた`map/azit/azit00` 静的なglTFとして、その後
    リンクした`.dds.phyre` PNGテクスチャの候補として；
  -`FFXMapViewerWeb` ローカルの Three.js ビューアに、orbit/walk/no-clip 機能を追加し、
    manifest/export/validator パネルとデフォルトのテクスチャ付きターゲットを実装しました；
  -`PhyreSkinnedAnimExportLab` 「スキン付き／アニメーション付き」のモンスターのエクスポート用フロントを登録した
    が、明らかなもの以外の素材やアニメーションは追加していない；
  -`ReverseHarness`,`SphereGridRuntimeProbe` そして`SphereGridRt2Lab` PS2/Sphere Grid/ランタイムの検索用に、
    読み取り専用のゲートを作成しました。
- 続き`azit00` 現在、検証済みのテクスチャ付きパッケージがあります：
  -`static-debug.gltf`,`static-textured.gltf` そして
    `static-textured-vertex-color.gltf`;
  - プリミティブ14個、頂点4,896個、三角形1,632個；
  - 3Dルートテクスチャ7個`.dds.phyre` PNG形式に変換され、以下によって結合された
    `fileMaterialId` 候補；
  - テクスチャ付きターゲットにおいて、glTF-Validatorのエラー0件／警告0件；
  - 読み込み／レンダリングの外部検証としてF3DおよびThree.jsを使用。
- IDAの平面／Phyreのマテリアル`azit00` 現在、以下の10段階のプロセスを記録し、
  証明している`PMaterial`/`PParameterBuffer`/「実際のゲーム素材」のバインディングを呼び出す前に、
  実際のテクスチャスロット。
- マップパーサー／エクスポーターは現在、`phyre-link-dump.json` そして
  `phyre-string-index.json`; 最初の構造的所見は、次のように示している
  `PMaterial 0..13 -> PParameterBuffer 12..25` およびテクスチャスロットのマークが
  `PParameterBuffer.parentFieldOffset=172`.
-`azit00` Phyreのlink-tableによる比較バインディングも追加されました：
  - 新規`material-slot-analysis.json`;
  - 新規`static-textured-phyre-slots.gltf` およびその変種
    `static-textured-phyre-slots-vertex-color.gltf`;
  - `PMesh.parentFieldOffset=52 -> PMat

erial 7..13 ->
    PParameterBuffer 19..25 -> field172 -> sharedDataId 10..16`;
  - 明示的なブリッジ`sharedDataId 10..16 -> root texture slot 0..6`;
  - 14/14 のサブメッシュが
    `bound_by_pmesh_pmaterial_pparameterbuffer_field172_candidate`;
  - glTF-Validator 0/0、F3D nonblank、および14個のメッシュ／14個のテクスチャ付きマテリアル／4,896個の頂点を含むThree.js
    ;
  - まだ**ではない**`engine_exact_material`; IDAは、プロモーションの前にフィールド172および
    シェーダーパラメータを確認する必要があります。
- 2026年6月2日のIDA/ランタイムに関する調査結果が、ゲームのバイナリにバージョン情報を付加せずに
  文書化されました：
  - インデックス/オラクル`.mgrp` で`docs/reverse/mgrp_oracle_2026-06-02/`;
  - MGRPおよびSphere Grid用のIDAプローブスクリプト；
  - プロモーション計画／不明点については`docs/reverse/WRITER_PROMOTION_GATES.md`.
- マスターパッケージ`DOSSIÊ FFX 01-06-2026` 現在は以下と統合されています：
  -`58` パッケージ化されたフォルダ；
  - フォルダごとのマニフェスト；
  - バージョン管理されたGit-safeのコピー（保存先：`docs/history/DOSSIÊ FFX 01-06-2026/`;
  - GitHubの制限によりブロックされた巨大な外部バイナリに関する除外レポート。
- ドキュメントの大規模な更新がようやく完了し、`Pt2..Pt45`、以下の内容を含む：
  - ワークショップの分野ごとに分類されたデータベース；
  - 統合されたマスターアトラス；
  -`KNOWLEDGE_BASE.md` ルートが唯一の入り口として機能すること；
  - 統合された公式マージ計画；
  - サテライトの添付資料`Pt6/Pt9`;
  - プロジェクトの公式技術ファミリー。
- キャンペーン`Pt50..Pt58` 現在、正式な吸収計画も策定されています：
  -`merge em docs`
  -`Extras agora`
  -`Extras depois`
  -`research congelada`
  -`limpeza historica`
- キャンペーンの計画では、現在、以下の2つのアセットのラフツリーも対象となっています：
  -`ps3data`
  -`ffx_ps2`
-`Pt6` 今回、一時休止のための正式なパッケージも追加されました：
  - エグゼクティブ・クローズアウト
  - 子会社の概要
  - ランタイム／AIアトラス
  - 後継システムのブートストラップ
- キャンペーン`Pt52..Pt58` 正式な締め切りも発表されました：
  - 短期の満期表
  - 判定`Extras agora`
  - 判決`Extras depois`
  -`research congelada`
  - 由来する紙`Pt67`
-`Pt50` そして`Pt51` 公式の履歴消去機能も追加されました：
  - split`ps3data` vs`ffx_ps2`
  - 出所に関するルールブック
  - ファセット

引用義務
- の後継者`Pt6` で、実際のコードの最初のステップを踏み出した`LiveBattleLab`:
  - 受諾契約`Pt47/Pt48` ようやく動作するようになった（surface read-only
    de`Ptr_script_*` + 自然キャプチャのCSVエクスポート（コホート／ティック／ラベル付き）；
  - オリジントラッキングにより、自然キャプチャとベンチリプレイをアーティファクト内で区別；
  - クレームの上限は**変更なし**（`structural dispatch/VM watch candidate`);
  - 詳細は`docs/history/LIVEBATTLE_CONTRACT_WIRING_2026-05-31.md`.

### 追加
-`RuntimeTools/Ps3MapViewerLab/` の読み取り専用カタログ作成者として
  `ps3data\map`/`btlmap`.
-`RuntimeTools/PhyreMapExportLab/` マップ用に個別のLabファイルをエクスポートする方法
  Phyre HD、マニフェスト、ディスクリプタレポート、glTFデバッグ、テクスチャ付きglTF、および
  テクスチャのバインディングレポートを含む。
-`RuntimeTools/FFXMapViewerWeb/` パイロット用の静的なThree.jsビューアとして
  `map/azit/azit00`.
-`RuntimeTools/PhyreSkinnedAnimExportLab/` エクスポート用の独立したフロントとして
  モンスターのスキン／アニメーション。
-`RuntimeTools/ReverseHarness/`,`RuntimeTools/SphereGridRuntimeProbe/` そして
  `RuntimeTools/SphereGridRt2Lab/` 逆検証用の読み取り専用ラボとして。
- MapViewer/Phyre/PS2/runtime に関する履歴ドキュメント（2026-06-02）：
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
-`docs/reverse/harness/` 補助的なデコード／プローブ用のスクリプトおよび
  `docs/reverse/spheregrid_oracle_2026-06-02/`.
-`docs/history/CHAT_MASTER_DOSSIER_2026-06-01.md` このメインチャットの全面的な再構築として。
-`docs/history/DOSSIÊ FFX 01-06-2026/INDEX.md` 書類一式の目次として。
-`docs/history/DOSSIÊ FFX 01-06-2026/GIT_EXCLUSION_REPORT.md` ローカルパッケージ全体にのみ含まれる唯一の大きなアーティファクトを登録するため。
-`Pt21` 以下の項目に関する構造的読解の理解度：
  -`important.bin`
  -`a_ability.bin`
-`ProductionSafetySmoke` これら2つのファミリーに対する強化措置として：
  -`Read`
  -`No-Edit Byte Identity`
  -`Reread`
- `docs/history/PT21_PT22_R

「EADER_NOEDIT_GUARDS.md」を、安全なPt21/Pt22スライス向けの本番環境向け決定ログとして使用します。
-`Pt16` `Slice 1` 吸収として：
  - 契約に追加のテキストトークンを組み込む`FFXProjectEditor/FfxLib/Text/*`
  - 純粋な妥当性検証／往復判定ユーティリティ
  -`TextLabTools/TextContractHarness` 生産サイド初のスモークコンシューマーとして
- 解決が困難なアクティブな問題に対するフロンティア・スナップショット：
  -`docs/history/BATTLE_AI_FRONTIER_2026-05-31.md`
  -`docs/history/MODELVIEWER_BINDING_FRONTIER_2026-05-31.md`
-`Pt23` a`Pt34` 現在では、以下の分野における歴史的知識の基盤として定着している：
  -`docs/history/PT23_TO_PT34_KNOWLEDGE_BASE.md`
  -`docs/history/PT23_TO_PT34_CHANGELOGS.md`
  -`docs/history/PT23_TO_PT34_BRANCH_MAP.md`
-`Pt23` a`Pt45` 現在では、以下のコードでも活用可能な知識ベースとして定着しています：
  -`docs/history/PT23_TO_PT45_CODE_KNOWLEDGE_BASE.md`
  -`docs/history/PT23_TO_PT45_CHANGELOGS.md`
  -`docs/history/PT23_TO_PT45_BRANCH_MAP.md`
- キャンペーン全体を閲覧できる新しい百科事典：
  -`KNOWLEDGE_BASE.md`
  -`docs/history/PT2_TO_PT11_KNOWLEDGE_BASE.md`
  -`docs/history/PT12_TO_PT22_KNOWLEDGE_BASE.md`
  -`docs/history/PT23_TO_PT45_KNOWLEDGE_BASE.md`
  -`docs/history/PT2_TO_PT45_MASTER_KNOWLEDGE_BASE.md`
  -`docs/history/PT6_PT9_DEPENDENT_WORKSHOPS_ANNEX.md`
  -`docs/history/NON_FFX_EDITOR_THREADS_ANNEX.md`
  -`docs/history/PT_FAMILY_LINES_ANNEX.md`
  -`docs/history/OFFICIAL_MERGE_PLAN_2026-05-31.md`
- アセットダンプに対する完全木探索計画：
  -`docs/history/PS3DATA_FULL_TREE_RESEARCH_PLAN.md`
  -`docs/history/PS2_FULL_TREE_RESEARCH_PLAN.md`
- PS2/Extrasの引き受けに関する公式計画：
  -`docs/history/PT50_TO_PT58_ABSORPTION_PLAN.md`
- PS2/Extrasシリーズの正式な終了：
  -`docs/history/PT52_TO_PT58_CLOSEOUT_REPORT_2026-05-31.md`
- このデュオの公式な経歴の整理`Pt50/Pt51`:
  -`docs/history/PT50_PT51_HISTORICAL_CLEANUP_2026-05-31.md`
- 便利な新しい凍結パッケージ`Pt6`:
  -`docs/history/PT6_TEMPORARY_CLOSEOUT_2026-05-31.md`
  -`docs/history/PT6_CHILD_WORKSHOPS_COMPENDIUM.md`
  -`docs/history/PT6_RUNTIME_AI_DISCOVERY_ATLAS.md`
  - `docs/history/PT6_SUCCESSOR_BOO

TSTRAP.md`
- 編集履歴の参照先：
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

### 変更点
-`RuntimeTools/PhyreModelExportLab/PhyreTextureExtractor.cs` 現在表示中
  一般的な抽出`.dds.phyre -> PNG`、マップやモンスターごとに再利用可能。
-`RuntimeTools/PhyreModelExportLab/DescriptorStaticGltfWriter.cs` これで
  複数のテクスチャを`fileMaterialId`,`TEXCOORD_0` およびその変種
  `Color Float4 -> COLOR_0`.
-`FFXProjectEditor.sln` 現在、以下が含まれています`ReverseHarness` 実験課題として
-`KNOWLEDGE_BASE.md` そして`docs/ai/SESSION_HANDOFF.md` MapViewer/Phyre/IDAの
  新たな前線進入地点に合わせて更新されました。
-`KeyItemEditor` public surfaceは、writer-forwardの表現から再分類され、`Guarded` 構造検査に加え、編集不可の保証。
-`AutoAbilityEditor` public surfaceは、writer-forwardの表現から再分類され、`Guarded` 構造検査に加え、編集不可の保証。
-`PORT_STATUS.md` and`docs/history/PRODUCTION_ABSORPTION_MATRIX.md` now distinguish`reader + no-edit guard` 真に作家にとって安心できる分野から。
-`Pt19 / CurrentSurfaceLab` それが今、反映されているのは`main` com`Readme.md` 現在のシェルに対して再オーディション；
- レガシーのバッチ`ReadmeAssets` は、次のように置き換えられました`6` 現在のビルドの追跡可能なキャプチャ：
  -`CurrentWorkspaceOverview`
  -`CurrentMonsterEditor`
  -`CurrentItems`
  -`CurrentBattleExplorer`
  -`CurrentLiveBattleLab`
  -`CurrentStringExplorer`
- テキスト行には、以下を区別するための明示的な区切りが追加されました：
  -`EncodeSafe`
  -`DecodeOnly`
  -`RawPreserve`
  -`UnknownRisk`
- ラウンドトリップに関する技術的な決定は、現在、次のように形式的に記述できる：
  -`ReuseOriginalBytes`
  -`ReencodeAllowed`
  -`Blocked`
-`Pt29` そして`Pt30` これらは単なるチャットでの発見にとどまらず、クラッシュ修正やセキュリティ強化に関する文書化された歴史的な記録として存在することになります。
- 公式の吸収キューは、現在次のように明示されています：
  -`merge agora`
  -`merge depois`
  -`Extras/read-only`
  -`knowledge only`
- 線`Pt50..Pt58` また、次のように明示されるようになりました：
  -`Pt56`,`Pt52`,`Pt54`,`Pt58` = ソフトウェアで今すぐ攻撃する
  -`Pt57` および以下の部分`Pt53/Pt55` = 後で実行、まだ読み取り専用
  -`Pt53`,`Pt55`,`Pt57` = 過大な主張を伴わない積極的な研究
  -`Pt50`,`Pt51` = 消去

「za historica」が「fonte limpa」に変わる前の
- において、明確に優先された最初の新製品は`Extras` 次のように変更されます：
  -`MagicPackageViewer`
  -`BatEffPackageViewer`
  -`MagicEffectCrosswalkExplorer`
  -`never blind merge`
- 線`Pt6` 「viva」スレッドや「upstreams」パケットの間に散らばった状態ではなくなり、将来参照できるよう、単一の編集上のまとめが設けられる。

### 検証済み
-`dotnet build RuntimeTools\PhyreMapExportLab\PhyreMapExportLab.csproj`:
  エラー 0 件 / 警告 0 件。
-`map_azit_azit00.static-textured.gltf` そして
  `map_azit_azit00.static-textured-vertex-color.gltf`:
  glTF-Validator エラー 0件 / 警告 0件 / 情報 0件 / ヒント 0件。
- F3Dは、テクスチャが適用されたターゲットの空白ではないスクリーンショットをレンダリングしました。`azit00`.
-`FFXMapViewerWeb` Three.jsでテクスチャ付きターゲットを読み込み、コンソールエラーは発生しなかった
  ローカルのsmokeでは。
- 公開されているREADMEには、実際に再検証されたWindowsのサーフェスについて`main`;
- READMEに掲載されているスクリーンショットはすべて、現在のシェルから取得したものであり、過去の作業資料からのものではありません。
-`Pt23` a`Pt34` 現在、以下の項目について最低限の由来情報が記載されています：
  - 目的
  - 有用性
  - マージの可能性
  - ワークショップごとの簡易変更履歴
-`Pt35` a`Pt39` これらは現在、次のように明確に定義されています：
  - 言語`binding truth`
  - フォーテの狭窄`owner/target/parentage/commit`
  - ガードレールの土台として`Pt6` そして`Pt23`
-`Pt44` もはや単なる「新しいフロント」ではなく、以下のクロスウォークの読み取り専用版として存在することになります：
  -`formation 0..7`
  -`enemy actor rows 0..10`
  -`rawMonsterId -> corpus`
  -`composition truth` vs`actor-surface truth`
- 選挙運動の締め切りが遅れたこと`Pt6` 現在では、以下の研究成果もまとめられています：
  -`Pt46 / AIBlobParityGrammarLab`
  -`Pt47 / AIRuntimeDispatchLab`
  -`Pt48 / SafeAIMicroProbeLab`
  ランタイム／AIの遺産の一部として、ライターやパッチャーがなくても。
-`Pt40` a`Pt45` これらは、AIによる進行中のキャンペーンとして正直に記録されていますが、コードとして実現されるような具体的な成果はまだ得られていません。
- キャンペーン全体`Pt2..Pt45` これでレイヤー単位での閲覧も可能になりました：
  - 旧ベース`Pt2..Pt11`
  - 中間基盤`Pt12..Pt22`
  - ヘビーベース`Pt23..Pt45`
  - メモリ/ランタイム/バインディング/ガードを統合した単一のアトラス
-`Pt23..Pt45` また、以下のように明示的に付属しています：
  - の衛星`Pt6`
  - の衛星`Pt9`
  - 生産上の例外`Pt29/30`
- プレフィックスのないFFXのスレッド`FFX Editor` これらは現在、正式には次のように分類されるようになりました：
  - ラインのオペレーショナル・ラッパー`Extras / ps3data`
  - シリーズの実用的なミニワークショップ`Pt6 / Pt23`
  - 知識が保存され、スレッドをアーカイブ可能
- 大手

プロジェクトのラインも、これをもってファミリーとして正式に認定されました：
  -`Model Viewer / Binding`
  -`Battle / AI / Runtime Truth`
  -`Text Safety`
  -`Kernel / Shop`
  -`Tooling / Safety / Release`
  -`Production Crashfixes`

### 注記
-`Pt24` を押し、`exact launch seam`、しかし「owner natural」も「commit seam final」も解決されなかった。
-`Pt33` そして`Pt35` 締め付けた`ModelViewerLab`、でもそれまでは`AI Slice + .chr` 構造用ブリッジとして、および`composition` 拘束力のある決定として。
-`Pt29` そして`Pt30` これらは、生産に直接的な価値をもたらし、統合の可能性が高いこの一連のワークショップの、最初の明確な兆候である。
-`Pt6` ここ数ラウンドでは、非常に有用なナローイングが行われたものの、新たな因果的ゲインがほとんど得られなかったため、一時的に中断されました。

### 計画
- の将来の後継として`Pt6`、ただし、新しいBootstrapとAtlasを基盤として構築されており、生のスレッドは提供されません；
- 場合によっては、狭いパイロットが`Pt15` 読み取り専用モードで、シェルの起動画面には進まずに；

### バックログ
-`Pt16` `Slice 2` そして`Slice 3` この波には依然として含まれていないもの：
  -`TextSourceCapability`
  -`Index*`
  - UIの配線は`StringExplorer`
-`important.bin` 候補となる変異の範囲は`Pt22` 技術的なバックログのみが残る：
  -`0x10 + 0x12`
  -`0x13`
-`a_ability.bin` green/yellow zones measured by`Pt22` 技術的なバックログのみが残っている。
-`arms_rate.bin` 孤立したサイドカー変異は、オラクルによる有望な結果が出ているにもかかわらず、プロダクションブランチでのみ未処理のまま残っている。
-`Pt14` これは依然として実行時／デバッグ用のテスト用ラインであり、本番環境向けフレームワークの移植版ではない。

### ブロック中
-`btl_txt.bin` writer および encode については引き続きブロックされています；
-`w_name.bin` 一般のライターには引き続きアクセスが制限されています；
-`Field String` アプリでは引き続きロックされた状態です；
-`important.bin` and`a_ability.bin` パブリックなmutation-safeライターのクレームに対してはブロックされたままとなる；
-`Pt22` Oracleの検索結果だけでは、ライターの昇格は承認されません。
- どのようなブラインドポートであっても、`runtime + memory + encounter tooling` 引き続き禁止されている。

## [v2.13.0] - 2026-06-05
### 追加
- **🌅 AURORA COCKPIT（Jarvisナイト） — 3つの接続：** (1) **MapViewerが実際にレンダリング** —`AuroraSceneRenderer` ルートを開く`file://` （ブラウザがブロックする`fetch()` glTF/catalog → 「Loading map」でフリーズしていた）が、現在は正常に読み込まれるようになった`http://127.0.0.1:8765/...` +`EnsureViewerServer` (上に`python -m http.server` （単独）。画面上でレンダリングが確認されました。(2) **EncounterTable → Aurora** — テーブルをダブルクリックして`EncounterTableExplorer` を開く`AuroraChamber` すでにあのシーンのレンダリングを始めていて`map` (`RequestOpenAuroraChamberForMap` +`AuroraChamber_DataModel.SelectSceneByMapKey` + ブリッジ`Main_Window`). (3) **モンスターのレンダリング** —`AuroraChamber` を注入する`model` アンカー経由でフォーメーションのラインナップを確認（chunk2`Battle_File.Read().Formation`, スロット↔アンカー,`Monster_Dictionary`);`aurora-overlay.js` 実際のglTFファイルを`work/phyre_chr_anim/models/mNNN` 経由`GLTFLoader` +`AnimationMixer` （アニメーションあり；リアルタイムのスケールスライダー）。加算モードで、球体へとグラデーションする。
### 備考
- エディタはエラー0でコンパイルされました。MapViewerのレンダリングは確認済み。モンスターのレンダリングは加算処理（スケールや外観を確認するには所有者のクリックが必要です）。重複排除については以下に記載されています。`docs/ai/FFX_OVERNIGHT_2026-06-05_JARVIS.md` (Aurora/EncounterTable/FormationEditor = 標準; Field Hub/SpiraForgeHub = 休止中; SaveTracker = 廃止予定のスタブ)。プッシュなし（Halysonからの承認待ち）。

## [v2.12.0] - 2026-06-05
### 追加
- **🌅 AURORA — フォーメーションの「ポジション」ライター（値のみ、「モブを配置」のロック解除）：** 新規
  `FfxLib/BattleMap/BattleArenaPositionWriter.cs` chunk3のアンカー配列に、アクターのX/Y/Z座標を再設定する
  (フィールド上のモンスター = ポインタ`+0x20`; また、party/aeon/staging による`role`) **IN PLACE**、value-only：
  ヘッダー／ポインタ／カウント／その他のチャンクには手を加えず、Wをそのまま保持する。 「battle」→「cena」の変換は**同一**であるため
  （IDA v2.10.0.1で実証済み）、cenaで選択された座標はそのまま書き込まれます。
  `FormationSlotWriter` (guard + backup-once`WriteLooseFile`).
### 検証済み
- **Gate RT0`RuntimeTools/BattleArenaPositionLab` — PASS (exit 0):** 実際のbtlコーパス **862/862 書き込み可能** —
  RT0 (no-edit == バイト同一) 862/862, POSITION-ONLY (差分は配列内に限定)`+0x20`) 862/862、RE-READ 862/862、
  + SAVE LIFECYCLE（一時コピーでのno-edit/edit/restore）PASS。
- **CIの空き枠が閉じられました：**`RuntimeTools/offline_ci.ps1` 現在、Auroraの3つのゲートが稼働中 —
  **BiancaCatalogLab + AuroraChamberLab + BattleArenaPositionLab**（以前は対象外だった）。CI完了
  **PASS (7/7ゲート)**: ReverseHarness、AiScriptLab、FormationSlotLab、AbilityCommandLab ＋ 3つの新規ゲート。
### 延期
- **ゲーム内での位置変更を反映（RT2）** = DINPUT8のプローブ（解放済み）＋ゲーム開始。 ライターはオフラインでバイトセーフティを検証
  。ゲーム内の画面が最終判断となる。モンスタースロットの追加／削除（カウントの変更）＝構造的（Rebuild）、次へ。

## [v2.11.1] - 2026-06-05
### 追加
- **📜 イベントエディタ — キーワード検索 + 言語の区別（開発者からの要望）：** o`EventExplorer` (1) テキストの内容に基づいてセリフを絞り込む**キーワード検索**フィールドと、(2) **言語フィルター**（チェックボックス
  英語／日本語、**デフォルトは英語**）が追加されました。以前はJPとENが同じリストに表示されていました（日本語が先頭＝日本語の壁）。
  リファクタリング済み`EventExplorer_DataModel` (`allTextRows` +`ApplyTextFilter`, 英語優先) + axaml (検索用TextBox +
  JP/US版チェックボックス)。**Writerには触れない** (Tier 1は引き続き`--event-rt0` 397/397 + 編集 12/12）。
### 備考
- バニラ版には **JP (chunk 1)** および **EN (chunk 4)** のトラックしか含まれていません。ポルトガル語のトラックは`.ebp` (PTは翻訳の挿入であり、
  writersの範囲外です)。単語検索は、選択されたイベント内で行われます。

## [v2.10.0.1] - 2026-06-05
### 検証済み (RE / IDA、オフライン)
- **🌅 AURORA — バトル→シーンの変換 = 同一性、IDAで検証済み (Z軸反転仮説を否定):** バトルエンジンは
  は、chunk3（battle-local）の座標をアクターの世界ノードへ**文字通り**コピーする — **Z軸反転、スケール、
  回転なし**；Y軸のみがアクターごとのモデル高さを取得する（`actor+0x534`). そのシーンは`.dae.phyre` == 頂点フレーム
  Phyre 1:1、**P_cena(X,Y,Z) = P_battle(X,Y,Z)** (s=1, R=I, T=0)。証明済みチェーン：`FFX_Battle_AreaChunk_GetSetPosition`
  (`0x7AC000`; chunk3 ベース`0x112A9B0`; 4つのfloatをそのままコピー; アクター @ のworld-pos;`+0x3B0`) →
  `FFX_Battle_ResolveActorPlacement` (`0x7A9AE0`) →`FFX_Battle_GetActorByIndex` (`0x794030`, stride`0xF90` == enemy
  RT2）。フリップZ仮説は、オフフィールドの列（パーティーバック Z≈-168）を含めたことによるアーチファクトであった。Doc:
  `docs/reverse/FFX_AURORA_BATTLE_TO_SCENE_TRANSFORM_IDA_PROVEN_2026-06-05.md` (+ rename-queue p/ a`.i64` （実）。
### 変更点（オーロラ・チェンバー — 誠実さ）
- オーロラ・チェンバーのバナー／オーバーレイ：「battle→世界 UNCALIBRATED/仮説」 → **「アイデンティティ（IDA-proven）」**。 このオーバーレイは
  アンカーをシーン座標に直接プロットし（デフォルトはすでに「アイデンティティ」でした）、Z軸反転のトグルは**「反証済み／比較」**に変更されます；
  `coordSpace` の`aurora-actors.json` =`scene_world_identity_ida_proven`.
### Deferred
- **ライブ確認（プローブ）：** 読み取り`actor+0x3B0` azit03の「Force Battle」に登場する生き物たちを確認する`≈ chunk3`
  (残留値 ~0) + 正確なY温度を測定。Halysonによるプローブの解放済み；未解決なのはオープンゲームのみ（既存のプローブ経由でREAD
  、新規コード不要）。SPIRA FORGEは停止したままである。

## [v2.10.0] - 2026-06-05
### 追加
- **📜 イベントスクリプトライター — ティア1（エディターにおけるライター機能の最後の大穴が解消されました）：** o`Event_File`
  (`.ebp` / コンテナ **EV01**) が読み取り専用ではなくなりました。**カットシーン／イベントの編集ダイアログがボタンになりました。**
  - **`FfxLib/Event/Event_File.Write.cs` (新規)：** EV01コンテナをバイト単位で再パッケージ化 — 各チャンクを再配置
    a`0x40`, 再計算された絶対オフセットのテーブル + EOF ターミネータ（マジック値 + センチネル）`0xFFFFFFFF` （そのまま保持）。
    編集なし = 逐語的再現が保証される；編集済みテキスト = 再利用`TextTable_File.Write` (chunks JP=1/EN=4); ATELスクリプト (0)、
    Unknown 2 および FTCX (3) はバイト単位で保持。Tier 2 フック`ScriptChunkOverride` （chunk-0の編集内容を再結合）。
  - **`Event_File.cs`:** 生のヘッダー + テキストテーブルの取得；NULLポインタを含むフィールド文字列エントリを許容
    （8ファイル）チャンクをそのまま保持（編集可能なフロンティアテキストとして文書化済み）。
  - **`TextTable_File.Write` (加算的な過負荷`includeTrailingPadding`):** 内部のパディングなしでテーブル+プールを生成できます
    （コンテナが0x40に再パディングします）。 **破損しません`--textstr-rt0`**（デフォルト＝従来の動作）。
  - **`Modules/EventExplorer` ダイアログエディタになりました：** 編集可能なJP/EN文字列（TextBox TwoWay） + ボタン
    **「Save dialogue」** をクリックすると、再パッケージ化して保存されます`.ebp`.
- **📜 イベントスクリプトライター — Tier 2 (chunk 0 = ATELスクリプト、append/PATCH):** 戦闘用ATELコーデックが
  (`FfxLib/Ai/AiScript_File.cs`, **ドナーとして読み取り専用**で使用される）は、イベントスクリプト（同じAiFileファミリー）を読み込み／編集します。
  - **バイト単位のPATCHオペランドが実証済み** (12/12)：chunk-0のオペランドを編集しても、それらのバイトのみが変更される。コンテナは
    残りの部分を同一のまま再結合し、再読み込み時に新しいオペランドが読み込まれる。
  - GROW (AppendCode) は**文書化された境界**です：`AppendCode` ドナー側（battle用に作成されたもの、
    DATAセクションのディスクリプタ）は、イベントスクリプトが使用する**ヘッダー常駐**のディスクリプタを再配置しません（`[0x38..scriptStart)`) — 以下の対応が必要
    イベント対応の再配置（AI Assemblerのレーンと調整する）。
### 検証済み
- **ゲート`--event-rt0` (`Tools/EventRt0.cs`) — PASS:** no-edit 読み取り→書き込み **397/397** バイト同一; **編集
  ラウンドトリップ 12/12** (文字列の交換 → 再パッケージ →

再読：編集された文字列は一致し、チャンクはそのままの状態で、冪等性がある）。
- **Gate`--eventscript-rt0` (`Tools/EventScriptRt0.cs`) — PASS:** コーデック chunk-0 RT0 **397/397**; コンテナオーバーライド
  **397/397**; **オペランドパッチ byte-local 12/12**。エディタはエラー0でコンパイル完了。
- **コンテナ EV01 の RE 検証済み (397/397):** マジック EV01、1番目のチャンク @0x40、アラインメント 0x40 (違反 0)、
  連続性（0回の断絶）、EOF==ファイルサイズ、センチネル`0xFFFFFFFF`. Docsの`docs/reverse/FFX_EVENT_*_2026-06-05.md`
  (コンテナ、FTCX=フォントシート 4bpp、Unknown2=音声キュー「SeSep」、ATEL方言、パディング/テキストテーブル、参照、IDAホスト)。
### Honesty / Deferred
- Tier 1 = **テキスト**（ダイアログ）はバイトセーフかつ検証済み；ポインタエントリがヌルの8つのENファイルはそのままの状態で保持される（現時点では
  テキスト編集不可）。 Tier 2 = 検証済みの**パッチ**；**追加/拡張**および構造的オーサリング（FTCXグリフシート +
  Unknown2キュー + 完全なイベントのATELアセンブラ）= 文書化済みだが未確定のTier 3。 検証では
  オフラインのバイト-RT0を優先した。編集済みダイアログのゲーム内RT2は、一般公開前の機能として推奨される。

## [v2.9.0] - 2026-06-05
### 追加
- **🌅 AURORA CHAMBER — レイヤー3（融合）、新モジュール`Modules/AuroraChamber`:** 🌙 BIANCA（btlmapの
  25シーンのカタログ）をMapViewerに連携させ、chunk3から**出演者の座標**を抽出します。オーロラとビアンカに捧ぐ。💛
  - **Scene Picker** は`BattleMapCatalog_File`/`BattlefieldSceneResolver` (読み取り専用) — エリアおよびマップキーごとにシーンを一覧表示・選択します。
  - **Render** は`PhyreMapExportLab` (btlmapシーンのglTFをオンデマンドでエクスポート) し、`FFXMapViewerWeb` via
    deep-link`?catalog=`/`?map=`/`?actors=` — **シーンごとのミニカタログ**、決して`catalog.json` 共有も上書きもせず、`app.js`.
  - **座標**（新しいリーダー経由）**`FfxLib/BattleMap/BattleArenaAnchors_File.cs`** (純粋/Avaloniaフリー):
    chunk3 (rec領域 96B、ポインタ`+0x10..+0x2C`、生きた怪物たち`+0x20`, elem 16B XYZW Y-up)、アンカー
    battle-local を一覧表示し、JSON を Encounter Authoring にエクスポートします。
- **MapViewer の追加オーバーレイ** (`RuntimeTools/FFXMapViewerWeb/aurora-overlay.js` + 1`<script>` no`index.html`):
  アンカー用ギズモ by`?actors=` + 「ピック」モード（y=0平面でのレイキャスト → ワールド座標）。非侵襲的（hooka
  `window.ffxMapViewerDebug`; no-op なし`?actors`/pick; は決して`app.js`).
### 検証済み
- **Gate RT0`RuntimeTools/AuroraChamberLab` — PASS (exit 0):** GOLDEN デコード **5/5 正確** (azit03_00/dome00_00/
  klyt00_00/sins02_00/mihn00_00 == ドキュメントで検証済みの座標); コーパス **862/862** クリーン (0 NaN/Inf、生きているモンスターでは W==0
  ）；決定論的；パイプライン BIANCA→シーン→バトル→アンカー **52/52** シーンがアンカーでマッピング済み。
- **btlmapのレンダリングが検証済み：**`PhyreMapExportLab export --area btlmap/azit/azit03_a` → リアルなテクスチャ付きglTF（68
  テクスチャ、10,804個の三角形、`gatePass: true`). コンパイラは **0 エラー** を検出しました（HEAD から切り離されたワークツリーで確認済み）。
### Honesty / Deferred
- シーンブリッジ (EncounterTable`map` → btlmap) = **実証済み**。Transform battle→mundo = **設計仮説、
  未キャリブレーション**（P_cena = R·s·P_battle + T；Z軸反転／ヨー角180度の未解決）— アンカーはバトルロケーションの生データであり、
  エンジン精度は保証されない。 プローブによるキャリブレーション = Wave 3（Halysonの承認が必要）。**SPIRA FORGEは停止状態のまま**

**; Auroraは、
  MapViewer + BIANCA（読み取り専用／追加機能）のみを使用し、ハブは接続しません。

## [v2.8.0] - 2026-06-05
### 追加
- **🌙 BIANCA — オーロラ商工会議所の設立（レイヤー1、読み取り専用）：**`FfxLib/BattleMap/BattleMapCatalog_File.cs`
  （**25のエリア／56のシーン**のHD映像を収録）`ps3data/btlmap` —`<área>NN_<variante>` c/`mdl/d3d11/<leaf>.dae.phyre`)
  +`FfxLib/BattleMap/BattlefieldSceneResolver.cs`. Puro/Avalonia-free、エディタでコンパイル可能（エラー0）。
- **EncounterTable→シーンへの橋渡し：解決済み＋検証済み：** 鍵となるのは**フィールド**です。`map` (6ch = エリア+NN、例：「azit03」）**、NO
  o`battlefield` u16（これは**グローバルアリーナID**であり、マップをまたぐ――`bf=1061` （nagi/test/tori/zzzz内）。Doc:
  `docs/reverse/FFX_BATTLEFIELD_SCENE_BRIDGE_2026-06-05.md`.
- **DECODADAS（RE）のアクター座標：** バトルごとのbinのchunk3 = エリアレコード 96B； **生存しているモンスターの
  ポインタ`+0x20`** (float32 X,Y,Z,W; Y-up; W=0; ストライド 16; 編成スロット ↔ エントリ)。パーティ`+0x10`, aeon`+0x18`,
  カメラ`+0x2C`. ドキュメント：`docs/reverse/FFX_BATTLE_FORMATION_POSITION_CHUNK3_DECODED_2026-06-05.md`.
- **3Dパイプラインが確定（レイヤー2）：**`PhyreMapExportLab` btlmapシーンをエクスポート **コードの変更なし**
  (`-- export --ps3-root <ps3data> --area btlmap/azit/azit03_a`). アクターのオーバーレイ計画 + プローブによる
  座標のキャリブレーション（DESIGN）：`docs/ai/FFX_AURORA_COORDINATE_SYSTEM_AND_CALIBRATION_2026-06-05.md` （Halysonの承認を得た場合のみ試行）。
### 検証済み
- **ゲート RT0`RuntimeTools/BiancaCatalogLab` — PASS (exit 0):** 完全なカタログ (ディスク 56 == カタログ 56) +
  決定論的；56/56 シーンで、それぞれ正確に 1 つのプライマリモデル；**0 件の説明不能な欠落** を含むブリッジ (22枚のマップ
  HD孤立マップ = カット/PS2専用 EXPECTED；4つの孤立シーン bika04/grid00/nagi03/sfia00 = ボス/ストーリー EXPECTED)。
### 延期
- **座標のキャリブレーション（プローブ）** および **🌅 オーロラ・チェンバーでの統合**（オーバーレイ + ドラッグ・トゥ・ライト）：設計完了；
  プローブ DINPUT8 は Halyson の承認を必要とし、SPIRA FORGE は一時停止中。

## [v2.7.1] - 2026-06-05
### 追加／検証済み
- **WAVE 1 WRITER-COMPLETENESS — 12 ファミリーのバイト忠実なゲート処理（スイープ）`--wave1-rt0`: RT0 12/12 PASS):**
  WeaponNameTable、MacroDictionary、NameDescriptionTextTable、NameDescriptionTextPrefixTable、BtlTextTable、
  SphereGrid、ShopGearCatalog、BukiGetTreasureCatalog、AlBhedDictionary、PointerScriptTable、BattleTextTable、
  ShopTable。**preserve-only** パターン（オリジナルを複製し、編集可能なフィールドを再設定；`WriteIdentity` ロス有りのリビルドを行っていた方へ
  （WeaponName/Macro/NameDescPrefix/SphereGrid/ShopTable）。新しいゲートスイープ`Tools/Wave1Rt0.cs`.
- **ShopItemCatalog**：**読み取り専用プロジェクション**が確認されました`Ability_Command` (item.bin、すでにゲート済み) — ライターギャップではありません。
- エディタ **~機能的には完了**：すでにゲート済みのものに加え、データベースは現在、大部分がバイトセーフとなっています。

## [v2.7.0] - 2026-06-05
### 追加
- **AIアセンブラーのGROW/SHRINKのロック解除（構造的なルーズファイル保存）** — 新規`AiScript_File.SpliceAiFileIntoMonsterGrow`:
  AiFileのパーティションを異なるサイズのパーティションに置き換え、AiFileを**16-pad**にし、**後続のセクションをシフト**し、
  **ヘッダーのセクションポインタ**を書き換える（`m###.bin`), AiFileを**文字通り**（
  codeLengthを上書きせずに）保存します。 UI上のAIアセンブラは、grow/shrinkを保存するようになりました（以前はlength-preservingのみ）。上書きの原因が文書化され
  + 設計上修正されました（オプションB：最小表面積、`Monster_File.Write` →`--monster-rt0` （続き 361/361）。
- **ローダーのRE（IDA、フリー版）：**`docs/reverse/FFX_AIFILE_LOADER_RENAME_QUEUE_2026-06-05.md` — ローダーは、
  VMのサイズを **ワーカー数 + ワーカーあたりのデータ長（16で丸め）** に基づいて決定します（パーティション／DeclaredLength／codeLength に基づくものではありません）。また
  **ファイル内のポインタを信頼する** → 成長時の再配置は正しく行われ、**トレーリングパッドは安全**である。（黄金律：リネームキュー。）
### 検証済み
- **`--aiasm-rt0` 拡張 — PASS:** no-edit リビルド 346/346、再レイアウト 346/346、スプライス 346/346、**GROW 346/346**
  (挿入 → グロウ対応スプライス → クリーンな再読み込み + テール/ヘッダーを逐語的に保持 + 16アラインメント + 冪等性)、
  **SHRINK 346/346** (対象外の命令を削除 → 負のデルタ → クリーンな再読み込み + テールが保持される)。`--monster-rt0`
  **361/361**（回帰なし）。 コーパスのアライメント：16/32/64/128/256、末尾パディング0。
- **画面上のUIクリック確認：** エディタの起動（マスターの自動読み込み）→ Monster AI Editor → **「AI Assembler
  (free-edit)」**が、編集可能な命令リスト（オペコード／オペランド／削除）とともにレンダリングされ、Insert/Save Structural 機能および
  プレビューが表示される。スクリーンショット`work/spira_forge_qa/monster_ai_assembler_v01.png`.
### Deferred
- **growのゲーム内検証（RT2）**：installにgrowされたm###.binを書き込む必要があり、さらにDINPUT8プローブを介して戦闘を強制する必要がある
  （共有） — Halysonからの明示的な承認を得ている。 オフラインおよびREによるバイト単位の検証およびゲーム内安全性の確認；ゲーム画面が最終的な判定基準となる。

## [v2.6.0] - 2026-06-05
### 追加
- **UI上のAIアセンブラー** (`Modules/MonsterAiEditor`, アドオン） — **命令全体**のフリー編集機能
  （挿入／削除／変更）を、バイト単位のオペランドエディタの上に重ねて実装。再構築されたAiFileは、
  `AiScript_File.Rebuild` (RT0-proven: エントリポイントとジャンプテーブルをold→newマップ経由で再配置)。編集可能なリスト
  （オペコード／オペランドの16進数＋削除チェックボックス）、選択後の挿入、差分のプレビュー。 **編集時のみ保存可能
  長さを保持**（同じ`codeLength`) → バイトセーフなスプライス via`SpliceAiFileIntoMonster`. **GROW/SHRINK = LAB**
  （正直なところ）：ルーズファイルの保存には、ヘッダーを意識した再レイアウト＋アラインメント用のパディング＋ゲーム内での検証が必要。
- **3つの新しいRT0ヘッドレスゲート** (ライター完全性):
  -`--ctbbase-rt0` →`CtbBase_File` (**ctb_base.bin**)、保存専用。
  -`--mixtable-rt0` →`MixTable_File` (**prepare.bin**)、保存専用。
  -`--aiasm-rt0` → **AI Assemblerによる構造的保存**（編集なしのリビルド＋リレイアウト＋バイト同一のスプライス）を検証し、
    コーパスのAiFile→WorkerFile間のアライメントを測定する。
### 検証済み
- **CtbBase RT0** (255エントリ / 530 B) + **MixTable RT0** (112ソース / 25108 B)：バイト単位で同一。
- **AI Assembler**：編集なしリビルド **346/346**、リレイアウト保存 **346/346**、**スプライス保存 346/346**（UIパス） —
  **長さを保持するバイトセーフ編集**。Grow=LAB（原因：ヘッダー 0x34 の`Monster_File` 重なる`AiFile[0..4)`=codeLength
  + grow により WorkerFile のアライメントが崩れる（コーパス 16/32/64/128/256-aligned、0 トレーリングパッド）。
### ブロック済み / LAB
- **AI Assembler GROW/SHRINK ルーズファイル保存** + 本セッションではUIレンダリングのクリック検証が行われていない（モジュールの標準的な許容範囲内のギャップ）。

## [v2.4.4] - 2026年6月5日
## [v2.5.0] - 2026-06-05
### 追加
- **FFX MapViewer デバッグスライス (Webビューア):** o`RuntimeTools/FFXMapViewerWeb` 現在、ローカルコントロールを公開しています
  `Spector.js` (`Open Spector`,`Capture Next Frame`,`Export Last Capture`) および最初のパネル`Material Debug`
  glTF素材のライブインベントリが読み込まれており、セレクター、ファクトチップ、およびテクスチャスロットごとのカード
  (`map`,`normalMap`,`aoMap`,`envMap`、など）。
- **実装ドキュメント（非公開）：**`docs/history/FFX_MAPVIEWER_SPECTOR_MATERIAL_DEBUG_IMPLEMENTATION_2026-06-05.md`
  入力された内容、検証済みの内容、および明示的に検証対象外となっている内容を記録します。
### 検証済み
-`FFXMapViewerWeb/app.js` 構文チェックに合格しました。
- HTTP によるローカル検証 + Chrome ヘッドレス環境での検証`map/azit/azit00`: ビューアが読み込まれ、地図がレンダリングされ、新しい
  コントロールが表示され、パネルが`Material Debug` 読み込まれた glTF に基づいて生成されました。
- 新しいプレビューには「正直なフォールバック」が採用されました。つまり、ランタイムやブラウザが再利用可能なピクセルを
  確実に提供できない場合、ビューアは`Frame preview unavailable` /`Texture preview unavailable on this source surface`
  有効な視覚的証拠を装うのではなく。

## [v2.4.4] - 2026-06-05
### 追加
- **Handoff エンカウンター → 編成** (SPIRA FORGE): Field Hub において、エンカウンターのプレビューに **選択可能なフィールドバトル
  **が表示されるようになりました。選択すると、`FieldContext.SelectedBattleId` そして、**フォーメーションエディタは直接
  このバトル**（フォーメーションを読み込み）に遷移します。シェルの配管処理を必要とせず、共有スパインを介して
  マスタープランの「ゾーンをクリックしてフォーメーションを変更する」機能を実現します。`FieldContext` 獲得した`SelectedBattleId`/`SelectBattle`.
- **EncounterIdMapLab** (`RuntimeTools`) — id encounter↔btl_* スキーマの読み取り専用調査。
### 検証済み
- **EncounterIdMapLab:**`EncounterTable.BattleId` **826/863にあるbtl_*フォルダと1:1で対応**（例：`azit03_00`);
  フォルダのないBattleIdが37件 + 対象のないフォルダが37件（スペシャルバトル／イベント） — handoffが実際に存在するものに絞り込みます。
- エディターのビルドでエラーは0件；`offline_ci` 4ゲートがPASS；画面上でハンドオフが確認された（`azit03_00` Hub → Formation Editor
  ロード済みのバトル画面に遷移（7チャンク）。スクリーンショット`work/spira_forge_qa/handoff_encounter_to_formation_v04.png`.

## [v2.4.3.1] - 2026-06-05
### リバース / プルーフ
- **HDスキンマトリックス・パレットのデコード（オフライン） — 脚のコイルはバインドされていなかった。** ハンドオフの仮説§3を否定する
  (`CONTINUE_AQUI_PERNAS_HD`): 「52」の地図`m_skeletonMatrices` → 79 joints" **はPhyreアーカイブ**にあり、IDAにはありません。
  - スキンのパレットは`PMatrix4[0..51]` （リンク元：`PMesh` フィールド12);`== m_skeletonMatrices` vivo **バイト単位**
    (`maxDist=0.00000`).
  - map slot→node は`int` 各**オフセット12**で`PSkeletonJointBounds[j]` (52スロット → 52ノード、全単射)。
  - 合成`m_defaultPose` 経由`m_matrixParents` **正確に**、著者が指定したinverse-bindを再現します：`0/52` ノードが異なる。
    したがって`--hd-defpose+--hd-parents` **これはすでにゲーム内の実際のバインドです**。
  - 履歴コイルの根本的な原因：ベイクなし`--hd-defpose/--hd-parents` フォールバックに切り替わる`invBind = PMatrix4[52+b]`
    (生のLOCALマトリックス) → メッシュが破裂する。defpose+parentsという手法が解決策であり、**すでにギャラリーのデフォルト設定となっている**。
  - 新しい読み取り専用プローブ：`work/_scratch_mgrp/phyre_palette_probe` (パレットを検索し、正確なバインドを確認し、出力する
    `node_to_slot.json`) および`phyre_legs_probe` (マッチャー；一致する置換による結婚の落とし穴を例示している)。
### 検証済み
- **画面が決定（F3D）：** パーティー全員の脚が **しっかりとしていてすっきりしている** — c001（ティダ）、c005（ワッカ）、c007（リク） —
  強制レスト時、戦闘時（id5_c4318 t0.0–0.9）、しゃがみ姿勢での脛の4つの角度、およびマルチクリップ（c4333/c4365/c4886）。
  数値設定：脚のジョイントの位置／ワールド座標 = 完全な剛体（スケール=1、デタイル=+1、直交座標 0.0000）。IDAなし。
  完全なテストは`docs/reverse/FFX_HD_SKIN_PALETTE_DECODED_LEGS_NOT_BIND_2026-06-05.md`.

## [v2.4.3] - 2026-06-05
### 追加
- **ライター完全性ゲート波（カーネルテーブル）** — 4つの新しいRT0ヘッドレスゲート。これらは、
  存在していたもののバイトゲート処理が一度も行われていなかったライターを検証し、編集可能なコンクリートベースの4つのファミリーを閉じます：
  -`--keyitem-rt0` (`Tools/KeyItemRt0`) →`KeyItem_File` (**important.bin**)、ライターは保存のみ（元の
    バイトを複製し、その上にのみ書き込みを行う）`PrimerByte10`/`OrderingByte13`).
  -`--treasure-rt0` (`Tools/TreasureRt0`) →`Treasure_File` (**takara.bin**)、往復完全デコード（4バイト/エントリ）。
  -`--customization-rt0` (`Tools/CustomizationRt0`) →`Customization_File` gear **kaizou.bin** + aeon **sum_grow.bin**
    （ヘッダーのプレフィックス／サフィックスを保持し、デコードされたエントリを再送信する）。
  -`--autoability-rt0` (`Tools/AutoAbilityRt0`) →`AutoAbility_File.WriteAbilities` (**a_ability.bin**、
    「データ」セクション)、ライターは保存専用。（読み取り`arms_rate.bin` 契約上の義務を果たすためだけ。arms_rateと記入したり、請求したりはしない
    `WriteAbilitiesAndText`/テキストの再パッケージ化。）
### 検証済み
- **RT0 バイト単位で同一 4/4**（実際のファイルとの比較）（`jppc/battle/kernel/`): important.bin (64 エントリ、3674 B)、
  takara.bin (503エントリ、2012 B)、kaizou.bin (125) + sum_grow.bin (77)、a_ability.bin (134エントリ、19590 B)。
  **編集なしの保存 = バイト同一；編集 = バイトローカル**（Monster/Encounterを締めくくったのと同じ「保存のみ」のパターン）。
  「important.bin/a_ability.bin blocked for mutation-safe writer claims」という歴史的な問題の一部を解消：
  フィールド（データセクション）の編集は現在、検証済みです；**テキストプールの再パッケージ化は依然として未検証** （monmagicと同様の
  ドリフトリスク — このゲート外）。

## [v2.4.2] - 2026-06-05
### 追加
- **フォーメーションエディタ — 「何がどこで戦うか」**：バトルリストに、**フォーメーション（モンスター）のラベル**が
  バトルごとにインラインで表示されるようになりました（例：`[m003 - Murussu, m003 - Murussu, m009 - Dingo]`). Lazy + キャッシュ + cap (表示されるバトルは90件以下
  。リストが満杯になると、エリアでフィルタリングするよう求められる)。読み取り専用。エディタ上で、マスタープランの「その場所にスポーンするモンスターがいるゾーン
  」を実装する（エンカウンターと表示形式の統合）。

## [v2.4.1] - 2026-06-05
### 追加
- **`FormationSlotWriter`** (`FfxLib/Battle`) — 形成時のバイトセーフなSAVEパスを、
  **Avaloniaフリー**の本番用ヘルパーに抽出（スロットのみの保存 + 1回限りのバックアップ）`.spiraforge.bak` + write）。現在、Formation
  Editor で使用されています（`PersistSnapshot`) **E** ヘッドレスゲートによるテスト済み — ロジックの重複排除、エディタとテストで同じコード。
### 検証済み
- **`FormationSlotLab` — SAVE LIFECYCLE チェック**（**TEMP** コピーへの出力パス、ワークスペース／アセットには手を加えず、
  読み取り専用を遵守）：(a) 編集なしの保存 = ディスク上のバイト単位で同一 + バックアップ==オリジナル；(b) 編集後の保存 = ディスク上のスロットのみ
  + 再読み込みによる一致 + バックアップの保持；(c) バックアップからの復元 = バイト単位で同一。 **PASS.** v0.2の
  正直なギャップを埋める（ディスク上でのアプリ内保存が実証済み、元に戻せる）。コーパスは **858/858** のまま；`offline_ci` 4ゲート PASS。

## [v2.4.0] - 2026-06-05
### 追加
- **`EncounterTable_File.Rebuild`**（構造的）— とは異なり、`Write` slot-only: chunk1を
  Entries/Groups/Formations（可変カウント＋テーブル作成）から再発行し、新しいdataOffsetsを割り当て、
  chunk0とchunk-tableを再構築し、**block-sharing**とパディングを維持する。 Gate`--encounter-rebuild-rt0`. **「出会いを生み出す」という
  構造的な基盤。**
### 検証済み
- 出会いの再構築 (`btl.bin` 96 テーブル / 192 グループ / 863 フォーメーション）：**編集不可 RT0 バイト同一
  (4096/4096)** + 拡張テスト（1つのフォーメーションを追加、末尾 0x1000→0x1002、2つのチャンクは完全） **有効**。
- **TextTable フィールド文字列ライター 認証済み** (`spcodedic.bin` 16/16 RT0) — ファミリーのロックを解除する`TextTable_File`;
  **trailing padding**のドリフトを修正。率直な指摘：`help_txt.bin` StringExplorer には
  この抽出では「MORTOS」（ファイルが存在しない） — ライターは実際のフィールド文字列で検証される（`spcodedic.bin`).

## [v2.3.2] - 2026-06-05
### 追加
- **AbilityCommandLab** (`RuntimeTools/AbilityCommandLab`) — アビリティ・ライターのゲート RT0
  (`Ability_Command.ReadList`→`WriteList`), それによると、`KernelCommands` すでに保存には使用しているが、バイトゲート処理されたことはない。
  エディタのプロジェクト（重いデバッグツリー）を参照しており、FfxLibの静的メソッドのみを呼び出している。以下に組み込まれている。`offline_ci.ps1`.
### 検証済み
- **command.bin + item.bin (JP+US): バイトセーフな認証済みライター** — RT0とバイト単位で同一 4/4 + 1フラグ版
  （1バイト）4/4。**PASS。** これは、ドリーム機能「新しいブラックマジック」（command.bin内に存在）の証明された基盤である。
### ブロック済み
- **monmagic1/2 (JP+US): ライターがドリフト** (RT0 0/4 — テキストファイルの再パッケージで ~3–4KB 肥大化、firstDiff`@0x1C`). 原因：
  monmagicのオリジナル版はテキストを**共有／重複排除**しており、`WriteList` 再添付 (`FfxEncoding.WriteBytesIntoTextFile`
  appendのみを行う；command/itemは純粋なappend → 互換性あり）。**リスク：** MonMagicのセーブデータが`KernelCommands` ファイルが
  肥大化する — dedup-aware 対応のライターが通過するまで試行錯誤する。監査 + 修正対象:`docs/reverse/FFX_ABILITY_WRITER_AUDIT_2026-06-05.md`.

## [v2.3.1] - 2026-06-04
### 追加
- **Battle_Fileリーダーの堅牢性** —`Battle_File.Read` 次に、末尾のチャンクが
  EOFの先を指している15個のbtl_*を開きます（`kino03_*`,`mihn05_*`,`cdsp00_02`): past-EOF（およびそれ以降）のチャンクを、ファイル全体を
  却下するのではなく、存在しないものとして扱います。それ以前のチャンク（@2のフォーメーションを含む）は有効なままです。これらのバトルは、
  フォーメーションエディタで編集可能になりました。
### 検証済み
- ゲート`FormationSlotLab`: writable が 843 → **858/858** に増加（読み取り失敗 0 回）；RT0 858/858 + スロットのみ
  858/858 + 再読み取り 858/858 **PASS**。 以前の843はそのまま。

## [v2.3.0] - 2026-06-04
### 追加
- **SPIRA FORGE v0.2 — フォーメーションエディタ** (`Modules/FormationEditor`): ハブの最初のEDITOR。btl_*のフォーメーションに含まれる8体の
  モンスター（16バイト）を、以下の方法で変更します。`Battle_File.WriteWithFormationSlots`, **バイトセーフ・スロット専用**。
  棘を消費する`FieldContext` （ハブで選択したフィールドエリアに基づいてバトルを絞り込みます）。モンスターピッカー
  (`Monster_Dictionary` + Empty（rawの上位ニブルを保持）。Saveはバックアップ付きでワークスペースにルーズファイルを保存します
  `.spiraforge.bak` + 保存`AssertSlotOnlyDiff`, 経由`ByteSnapshotEditorSession` (元に戻す/破棄)。オフライン、プローブなし。
- **Gate RT0 ヘッドレス**`RuntimeTools/FormationSlotLab` （依存関係のない本番用ファイルのみをリンクし）、
  以下に接続して`offline_ci.ps1` (停止`-BtlRoot`). 追加の読み取り専用メンバーが`Battle_File`
  (`FormationChunkOffset`/`FormationSlotsOffset`/`FormationSlotsLength`).
### 検証済み
-`FormationSlotLab` コーパス内`btl`: RT0 843/843 + スロット専用 843/843 + 再読み取り 843/843 **PASS** (ライターはバイトセーフ)。
  (当時、reader では 15 個の btl_* が解析不能だった — v2.3.1 で修正済み。)

## [v2.2.0] - 2026-06-04
### 追加
- **SPIRA FORGE フェーズ 0 v0.1 — Field Hub** (`Modules/SpiraForgeHub` +`Services/FieldContext.cs`): ナビゲーションの
  キーは`field_token`. CSVブリッジからデータを取得するフィールドピッカー
  (`ps3data-map-btlmap-fieldid-bridge.csv`, 357 フィールド, **structural-candidate**)。公開されているフィールドを
  `FieldContext` (オブザーバブル・シングルトン) と、2つの読み取り専用コンシューマーが反応する：**map deep-link**
  (`?map=map/<area>/<field>` pro FFXMapViewerWeb) + **エンカウントプレビュー** (読み込み`btl.bin` 経由`EncounterTable_File`,
  join 候補 エリア↔マップ). csproj 経由で出力にコピーされた CSV`<Content>`. オフライン；ピッカーはプロジェクトなしで動作する。
  ライターもプローブもない。
### 検証済み
- ビルドエラー0件；画面上で検証済み（フィールド`azit03` → ピッカー + ディープリンク + エンカウンター・ピーク（btl.bin の実際のデータを使用）。
  スクリーンショット`work/spira_forge_qa/field_hub_v01.png`.

## [v2.1.1] - 2026-06-04
### 検証済み
- **PlayerKernel ライター** (`PlayerKernel_File.WriteSave`/`WriteRom`) 新しいゲートを通じてバイト単位で忠実に検証された
  `--player-rt0`:`ply_save.bin` (3098) +`ply_rom.bin` (2161) -> **no-edit RT0 バイト同一**。（ライターは
  以前からスロット専用として存在していましたが、現在は**ゲート制御**されています。）

## [v2.1.0] - 2026-06-04
### 追加
- **EncounterTable ライター** (`EncounterTable_File.Write`) — 読み取り専用 → 読み書き可能 **スロットのみ**：以下の内容を保持する
  `btl.bin` バイト単位で処理し、編集可能なフィールドのみを再スタンプする（table`Id`/`Unknown0C`, グループ
  `Battlefield`/`Danger`/`TotalWeight`, 研修`Id`/`Weight`). ゲート`--encounter-rt0` エディタ内で。
### 検証済み
-`battle/kernel/btl.bin`: 96 テーブル / 192 グループ / 863 フォーメーション -> **編集不可 RT0 バイト同一 (4096/4096)**。

## [v2.0.0] - 2026-06-04

> **新時代 — メジャーアップデート。** エディタは「ファイルのオフライン編集」から、**リアルタイムのランタイム編集
> 実証済み**へと進化しました：RAM上のモンスターAIのバイトコードを編集し、クラッシュすることなく**画面上で**挙動の変化を確認でき、
> 元に戻すことも可能です — プロジェクトの**最優先目標 #1**が実現しました。 MAJOR = 新しい**機能クラス**（
> 契約/セーブ/ビルドの破綻ではありません — 単に機能を追加し、堅牢化しただけです）。`-beta` RT2/God-Modeがまだ
> ゲート付きのUIとして製品化されていないため。**Claude Code / VSCode + 2つ目のCodexアカウントとの連携**という流れの節目。

### ハイライト
- 🏆 **画面上で実証されたRT2ライブAI編集：** 実行中のRAM上でモンスターのAIバイトコードを編集（DINPUT8プローブ）、
  画面上の挙動が変化 — **Flame Flan Firaga→Thundaga**、クラッシュなし、元に戻せる。チェーン：`enemy-list`
  (`0xD34460`) →`MemoryChr.Ptr_script_chunks` (`+0xF78`) → AiFile vivo **===`m0NN.bin` バイト単位で同一のディスク**。
- 💉 **任意のモンスターに任意の能力を注入（ライブ）：** IDは`performCommand` =`(cat<<12)|abilityId`
  グローバルアビリティを発動する――モンスターが「持っている」必要はない。 証拠：**スクールがイフリートのヘルファイアを画面上に吐き出した**。
- 🐉 **敵のリアルタイム編集：** モンスターを**ダーク・シヴァ**（ID + 実際のステータス + 1.1M/4M HP）に変える、
  **オートスキャン**、**ダイスによる復活**（死亡フラグ＋KO）、すべては`MemoryChr` + プローブ。

### 追加
- **AIアセンブラ** —`AiScript_File.AppendCode`: 指示を添付し、**データセクションのすべてのオフセットを
  再配置** (+delta) → より大きく有効なAiFile（「AIを追加」へのパス、バイトローカル予算に加えて）。
- **AIの制御フローエディタ**（float/int const + jump-target）、バイトローカル、no`AiScript_File`.
- **モジュール`Monster AI Editor`** (Avalonia): グロス付きディスアセンブラ (147回の呼び出し + 73個のフィールド + 浮動小数点数 + 変数 +
  ジャンプラベル + 推論されたワーカータイプ)、オペランドの編集 + ルーズファイルの保存。
- **`FfxProbe_Service`** — bridge editor↔probe DINPUT8（メインスレッドでのREAD/WRITE/CALL、ASLR対応）。
- mod/REのドキュメント：`FFX_AI_RT2_LIVE_EDIT_PROVEN`,`FFX_LIVE_INGAME_EDITOR_MOD_IDEA` （バトル・ゴッドモード）、
  `FFX_MUSIC_SYSTEM_AND_MOD_IDEA` (Music Remapper)、`FFX_AI_BYTECODE_OPCODE_TABLE_PROVEN`,
  `CODEX_MAPVIEWER_WATCH_JARVIS`,`FFX_MAP_DEVELOPMENT_TOOL_MASTERPLAN` (Spira Forge)。

### 変更／検証済み
- **`Monster_File.Write` 修理済み → ゲート`--monster-rt0`: 361/361 バイト同一**（以前は 0/361）：
  StatSheet/Loot では「preserve-only」を適用 + ヘッダーの署名/パディングを保持（パディングが重複していた`AiFile[0..3]`).
- **AIコーデック`AiScript_File`**: RT0 361/361 + oracle-parity の逆アセンブル + オフライン CI (`offline_ci.ps1`).
- IDAに保存されたVM ATEL (`FFX_Atel_*`,`g_FFX_Atel_VmContext`, アクターの解決、FMODプレイヤー）。

### ブロック済み / 延期済み（正直なところ）
- **ライブ3Dモデル / ビジュアルリライブ** = モデルビューアーのレーン（Codex）；フラグ`MemoryChr` レンダリングが再構築されません。
- **ライブで音楽を切り替える** = FMOD APIは`__thiscall`, プローブはcdecl専用 → プローブにop thiscallが必要
  （ゲームを閉じた状態で再ビルド）。見つかったプレイヤー：`FFX_FmodMusic_PlayTrackByIndex` (181トラック); PS2のFIFO SPUはHD上のスタブである。
- アセットが読み込まれていない状態で**重いアビリティを発動**すると、**クラッシュ**する可能性がある（ダークイフリートの「ヘルファイア」でゲームがフリーズした）。
- **God Modeモジュール** = ライブテスト済みですが、ゲート付きUIにはまだ実装されていません。

### Labsからの取り込み / マルチエージェント
- Arco **Claude Code / VSCode**（AIエディタのキャンペーン：ATELコーデックを100%デコード → RT2ライブ）に加え、
  **2つ目のCodexアカウントとの連携**（MapViewerレーン／モデル・テクスチャ）：エクスポーターがマテリアル・ロールのシグナルを公開
  （TextureSampler1／normalMap／reflection／water／PhyreWaterShader）、外部ビューアー
  （**glTF-Sample-Viewer**をオラクルとして；エクスポーター側のギャップが証明され、シェル側ではない）、およびマスタープラン
  **Spira Forge**のキックオフ。マルチエージェント連携による`docs/ai/CODEX_MAPVIEWER_WATCH_JARVIS.md`.

## [v1.7.0] - 2026-06-04
### 追加
- **AI Assembler（AIを100%自由に編集可能）** — 2つのプリミティブが`AiScript_File`:
  - **`AppendCode`**: 末尾に説明を追加 + データセクションの位置を変更。
  - **`Rebuild`**: **任意の場所で命令を挿入／削除／編集** + すべての
    **ジャンプ + エントリポイント**（リンカー：旧→新） + データセクションを自動的に再配置。 孤立した分岐（命令が削除された）→ 正当なエラー。
### 検証済み
-`m337` (Dark Shiva): **no-edit Rebuild = バイト単位で同一 (RT0)**; 途中に挿入 ->`codeLen +3`, walkが終了し、
  ワーカーが処理を完了し、**挿入後のエントリポイントが再配置された`0x2D1`→`0x2D4` 単独**; grow-test (AppendCode) RT0.

## [v1.6.0] - 2026-06-04
### 検証済み
- **`Monster_File.Write` 修理済み -> ゲート`--monster-rt0`: 361/361 バイト同一**（以前は 0/361）：StatSheet/Loot での「preserve-only」
  ＋ 保持`Signature`/`Padding` ヘッダーの（パディングが重なっていた`AiFile[0..3]`).

## [v1.5.0] - 2026-06-04
### 検証済み / ブロック済み
- **サウンドシステム RE'd:** FMOD プレイヤー **`FFX_FmodMusic_PlayTrackByIndex`** (181曲) 見つかりました； **ライブ
  楽曲はブロックされています** (API`__thiscall`, cdecl専用プローブ）。ドキュメント`FFX_MUSIC_SYSTEM_AND_MOD_IDEA` (Music Remapper)。

## [v1.4.0] - 2026-06-04
### 検証済み（ライブ）
- **モンスターを跨ぐアビリティの注入が実証済み：**`performCommand` id =`(cat<<12)|abilityId` アビリティを発動する
  GLOBAL — モンスターが「持っている」必要はない。証拠：**スコールが画面上でイフリートのヘルファイアを吐き出した**。

## [v1.3.1] - 2026-06-04
### 修正／検証済み（本番環境）
- 敵の実際の回復量について`Hp@0x5D0` (いいえ`Current_hp`); **KO**の清掃 (`Status_suffer`); データからの復活
  （死亡フラグ）。**オートスキャン**（ステータス`Scan`) ライブ配信中。

## [v1.3.0] - 2026-06-04
### 検証済み（ライブ）
- **敵をダーク・シヴァに変える**（ライブ）：`Id` + 実際の統計データ`m337` + **1.1M/4M HP**、出典：`MemoryChr`
  (`POINTER_BATTLE_ENEMY_LIST 0xD34460`, stride`0xF90`) + プローブ。

## [v1.2.0] - 2026-06-04
### 追加
- **モジュール`Monster AI Editor`** (Avalonia)：注釈付き逆アセンブラ (147 回の呼び出し + 73 個のフィールド + 浮動小数点数 + 変数 +
  ジャンプラベル) + オペランドの編集 + ルーズファイルの保存。
- **AIの制御フローエディタ**（float/int const + jump-target）、バイト単位。
- **`FfxProbe_Service`** — bridge editor<->probe DINPUT8（メインスレッドでのREAD/WRITE/CALL、ASLR対応）。

## [v1.1.0] - 2026-06-04
### 検証済み (🏆 HEADLINE — 最重要目標 #1)
- **RT2 ライブ AI 編集が画面上で実証済み:** **ライブ RAM** 上で編集されたモンスターの AI バイトコード (DINPUT8 プローブ) ->
  画面上の挙動が変化（**Flame Flan Firaga→Thundaga**）、クラッシュなし、元に戻せる。チェーン：`enemy-list
  0xD34460` -> `MemoryChr.Ptr_script_chunks +0xF78` -> AiFile vivo **=== `バイト単位で同一のディスク上の`m0NN.bin`**。
  ドキュメント：`docs/reverse/FFX_AI_RT2_LIVE_EDIT_PROVEN_2026-06-04.md`.

## [v1.0.0] - 2026-06-01

エディタが、知識の閲覧、検証、探索を行う真のプラットフォームとして成熟した段階に達し、`Extras` ～を正当化するのに十分な`1.0` ランタイム、AI、身体表現の再生といった課題が解決されたかのように装うことなく、率直に言えば。

### ハイライト
- エディターは、単なるドメイン別エディターの集合体ではなく、統合プラットフォームとしても機能するようになり、`read-only exploration`.
- 線`Extras` 現在、シェルでは6つの実際の分野をカバーしている：
  -`PS2 Knowledge`
  -`Textures (TM2 + TXC/CLT/FMT/SPS2 support lane)`
  -`BIN-FTC Atlas`
  -`Project / Pipeline`
  -`Magic Effects`
  -`Presentation Containers`
  -`Battle Corpus Crosswalk`
- このプロジェクトには、現在、読み物・地図・来歴に関する十分な資料が揃っており、以下として扱われるようになった`1.0` 検証プラットフォームとしてのエディタ。

### 追加
-`Pt67` どのように`Extras / Magic Effects`、内容は以下の通り：
  -`MagicPackageViewer`
  -`BatEffPackageViewer`
  -`MagicEffectCrosswalkExplorer`
-`Pt57` どのように`Extras / Presentation Containers` ～へ`.vpa/.ebp/.omd/.sps2`.
-`Pt44` どのように`Extras / Battle Corpus Crosswalk` ～へ`formation -> actor row -> corpus`.
- の拡大`Pt52` com:
  -`FtcHeaderInspector`
  -`BinSidecarGraph`
  -`Signature Group` シェル内で
- の展開`Pt56` com:
  -`TxcCltPairExplorer`
  - メタデータ（冷）`fmt` そして`sps2`
-`docs/history/PS3DATA_CHECKLIST_MASTER_2026-06-01.md` ツリーのマスターチェックリストとして`ps3data`.
-`docs/history/EDITOR_READONLY_ABSORPTION_REPORT_2026-06-01.md` 「surface read-only」になる可能性のあるもの、あるいはならない可能性のあるものすべてを示すマップとして。

### 変更点
- アプリのバージョンを`1.0.0`.
- o`PS2 Knowledge` 今や、レジストリそのものに、その生きた存在が反映されている`Pt44`,`Pt57` そして`Pt67`.
- 制御`Extras` 新しいサーフェスでは、スクロールの根元が改善され、ネーミングも以前より自然になった。
-`PORT_STATUS.md`,`KNOWLEDGE_BASE.md` そして`docs/history/README.md` 今や、彼らは「ウェーブ」を正式に認めている`1.0`.

### 検証済み
- ビルド`Release` 波に乗って通り過ぎた`1.0.0`.
- 線`Extras` さらに次のように明示されている：
  -`read-only`
  -`do not promote`
  -`no runtime proof` 適宜
  -`pipeline/support only` 適切な場所に

### 注記
- これ`1.0` これは、編集者が読書と検証のプラットフォームとして成熟していることを意味する。
- これ`1.0` 次のことを意味するわけではない：
  -`magic solved`
  -`AI solved`
  -`ModelViewer playback solved`
  - writer amplo がリリースされました

## [v0.11.0-beta.2] - 2026-06-01

シリーズの本格的な進化`Extras` na`main`.

### 注目ポイント
-`Extras` エディタ上で、単なる平面ではなく、生き生きとした表面へと変化しました。
- シェルは、関連するルートも認識するようになりました：
  -`master`
  -`ffx_ps2`
  -`ps3data`
- PS2の読み取り専用製品の第一弾が、UI上に表示されるようになりました：
  -`PS2 Knowledge`
  -`Textures (TM2)`
  -`BIN-FTC Atlas`
  -`Project / Pipeline`

### 追加
- 共同設立`Extras`:
  -`ExtrasSourceResolver`
  -`ExtrasEvidenceBadgeModel`
  -`ExtrasProvenanceModel`
  -`ExtrasReadonlyBoundaryModel`
  -`ExtrasFileOpenService`
-`Extras / PS2 Knowledge` PS2キャンペーンの読み取り専用ハブとして。
-`Extras / Textures (TM2)` の、最初の率直な視覚的表現として`Pt56`.
-`Extras / BIN-FTC Atlas` の読み取り専用ブラウザとして`Pt52`.
-`Extras / Project / Pipeline` の初期表面として`Pt54`、内容は以下の通り：
  -`CdIndexExplorer`
  -`ProjectDescriptorViewer`
  -`AbmapSupportGraph`
- ワークショップ／ファイルファミリーごとの新しいガイド`ffx_ps2`:
  -`docs/history/PT52_BIN_FTC_FILE_MEANING_GUIDE_2026-06-01.md`
  -`docs/history/PT53_BATTLE_MAGIC_FILE_MEANING_GUIDE_2026-06-01.md`
  -`docs/history/PT54_PROJECT_ABMAP_FILE_MEANING_GUIDE_2026-06-01.md`
  -`docs/history/PT56_TEXTURE_PALETTE_FILE_MEANING_GUIDE_2026-06-01.md`
  -`docs/history/PT57_PRESENTATION_CONTAINER_FILE_MEANING_GUIDE_2026-06-01.md`
  -`docs/history/PT58_FFX_PS2_OWNERSHIP_AND_LINKAGE_GUIDE_2026-06-01.md`

### 変更点
- アプリのバージョンが`0.11.0-beta.2`.
-`Pt54` もはや～ではなくなった`implementation-ready` そして、実数モジュールとしてシェルにログインし、`Extras`.
-`Pt58` 現在、このソフトウェアでは、単なる概念としてだけでなく、バッジ、プロヴェナンス、読み取り専用の境界を備えた、操作可能なハブとして表示されるようになっています。
-`KNOWLEDGE_BASE.md` そして`docs/history/README.md` 現在、新しい冷蔵ガイドが`ffx_ps2`.

### 検証済み
- エディタのReleaseビルドが、新しいモジュールによる`Project / Pipeline`.
- 線`Extras` 読み取り専用で保存されたまま：
  - ライターなし
  - リパックなし
  - 最終デコードのクレームなし
  - コールドリサーチとランタイムプルーフを混在させない

### 備考
-`Pt53` 依然として「魔法軸」のトップを走り続けている：
  -`kernel -> mag_* -> bat_eff`
-`Pt55` 引き続き、以下に取り付けられたガードレールに対して低位置に保たれている`Pt9`.
-`Pt57` 重要なアトラス・フリオは続いているが、依然として詳細な解析は進んでいない。

## [v0.10.0-beta.1] - 2026-05-31

統合ベータ版`main` ワークショップによる最初の強力な吸収の波が収まった後。

### ハイライト
-`Shop Explorer` カタログ、実際の図版、そして保守的な切り抜きとして保存された文章を携えて、主流の分野に参入した。
-`RuntimeTools/StepBridgeLab` そして`RuntimeTools/RuntimeInspectorLab` スタンドアロンのツールとして導入され、シェルの起動に影響を与えることはありませんでした。
-`ProductionSafetySmoke` 問題を抱えた家族を隠すのをやめ、証明するようになった`Read`,`No-Edit Byte Identity` そして`Reread` ～へ`important.bin` そして`a_ability.bin`.
-`README` また、公開されているスクリーンショットは、現在のシェルを反映するようになりました。`main`、古い作業場の遺産ではない。

### 追加
- 吸収`Pt8 / ShopAndWeaponNameResearchLab` で：
  -`Shop Explorer`
  -`FfxLib/Shop`
  -`Assets/Shop`
  - 保存されたライター`item_shop.bin` そして`arms_shop.bin`
- 吸収`Pt12 / StepBridgeLab` で`RuntimeTools/StepBridgeLab`;
- 吸収`Pt13 / RuntimeInspectorLab` で`RuntimeTools/RuntimeInspectorLab`;
- 吸収`Pt17 / SaveSafetyLab` で`ProductionAuditTools/ProductionSafetySmoke`;
- 確実なスライスの吸収`Pt21 + Pt22` で：
  -`NameDescriptionTextPrefixTable_File`
  -`reader + no-edit guard` ～へ`important.bin`
  -`reader + no-edit guard` ～へ`a_ability.bin`
-`docs/history/PT21_PT22_READER_NOEDIT_GUARDS.md` この切り出しに対する生産決定ログとして；
-`ReadmeAssets` 以下で更新されました`6` 現在のビルドの追跡可能なキャプチャ。

### 変更点
-`KeyItemEditor` 公に再分類され、`Guarded`、構造的な読み込みと「編集なし」の保証に重点を置いて；
-`AutoAbilityEditor` 公に再分類され、`Guarded`、同じ保守的な視点で；
-`PORT_STATUS.md` そして`docs/history/PRODUCTION_ABSORPTION_MATRIX.md` 今でははっきりと区別されている`reader + no-edit guard` から`writer-safe`;
-`README` 現在のシェルに対して再聴取が行われた`main`;
-`CHANGELOG` そして`changelogUS` これらは、本線の新たな定着段階を反映するようになった。

### 検証済み
-`Shop Explorer` そして、その保存された切り抜きは、公式の表面を構成するようになった。`main`;
-`StepBridgeLab` そして`RuntimeInspectorLab` 独立したツールとしてメインツリーに追加された；
-`ProductionSafetySmoke` 展示を開始した`important.bin` そして`a_ability.bin` 構造が正しく読み取られ、バイト識別子が編集されていないもの；
- o`README` publicoは現在、実際に再評価されたWindows Surfaceについて次のように報じている。`main`;
- すべてのスクリーンショットは`README` 現在のシェルからのものであり、古いワークショップの資料からのものではありません。

### Deferred
-`Pt16 / Slice 1` 独自のブランチでは準備が整っているが、まだ`main`;
-`Pt14` そして`Pt15` ランタイム／デバッグ／アーキテクチャに関する有用な機能として残されていますが、今回のリリースでは実際にコードが組み込まれることはありません；
-`AI Probe` そして`Pt6 / BattleStructureLab` 引き続き優先事項ではあるが、実行時／AIにおけるより大きなリソース割り当てを正当化するほどではない。

### 保留中
-`btl_txt.bin` writer および encode については引き続きブロックされています；
-`w_name.bin` 一般のライターには引き続きアクセスが制限されています；
-`Field String` アプリでは引き続きロックされた状態です；
-`important.bin` そして`a_ability.bin` 「mutation-safe」というタグの公開クレームについては、引き続きブロックされたままです。
- 範囲オラクルの結果：`Pt22` それだけではライターの昇格は認められない；
-`Repeat Exact Encounter` また、ランタイム／AI関連の主要な分野は、依然として本格的な普及段階には至っていない。

## [v0.9.0-beta.1] - 2026-05-31

エディタとその周辺のエコシステムの実際の規模を正直に反映した最初のバージョン。

### メインブランチのハイライト
- 公式登録`main` どのように`v0.9.0-beta.1`;
- プライベートなGitのベースラインが保持され、バージョン管理されている；
-`PORT_STATUS.md` 生産吸収の「ライブ・レジャー」となる；
-`docs/governance/` ワークフロー、バージョン管理、および次の作業順序を統合する；
-`docs/history/` レジストリ、ブランチマップ、タイムライン、および吸収マトリックスを統合する。

### メインに存在するプロダクション・サーフェス
-`Monster Editor`;
-`Battle Explorer`;
-`Sphere Grid Explorer`;
-`Sphere Grid Editor v1`;
-`Encounter Table Explorer`;
-`Monster AI Explorer`;
-`String Explorer` 安全なライターを使って`Monster Localizations 1/2/3`;
-`Live Battle Lab`;
-`PlayerGrowthEditor`;
-`CtbBaseEditor`;
-`MixTableEditor`;
-`KeyItemEditor`;
-`AutoAbilityEditor`;
-`Shop Explorer` 保存済みのスライスから`Shop`.

### ワークショップから得た知見
-`Pt3 / TextLab`
  -`TextLabTools`;
  -`ProductionAuditTools`;
  - テキスト／モンスター用のハーネスおよびリリース（保守仕様）。
-`Pt5 / KernelTablesLab`
  -`PlayerGrowthEditor`;
  -`CtbBaseEditor`;
  -`MixTableEditor`;
  - その根拠となる歴史的経緯`KeyItemEditor`.
-`Pt7 / AutoAbilityLab`
  -`AutoAbilityEditor`;
  - 保守的なパーサー`AutoAbility_File.cs` そして`Arms_Rate.cs`.
-`Pt8 / ShopAndWeaponNameResearchLab`
  -`Shop Explorer`;
  -`FfxLib/Shop`;
  -`Assets/Shop`;
  - 保存されたライター`item_shop.bin` そして`arms_shop.bin`.

### ガバナンスとバージョン管理
-`docs/history/PT_VERSIONING_REGISTRY.md`;
-`docs/history/PT_BRANCH_MAP.md`;
- 編集版ミニバージョン：`Pt2` a`Pt20`;
- ワークショップごとの履歴タグ；
- 本番環境向けに定義されたブランチ／コミット／変更履歴の方針。

### 検証済み
- のプライベート・ベースライン`main` 「～として公開」`baseline-2026-05-31`;
- 音声は以下`Git LFS` で`FFXProjectEditor/Assets/Audio/**`;
- ビルド`Release` 本線から；
- の部分的な吸収`Shop` 保守的な切り出しにおいて技術的に検証済み；
-`AutoAbilityEditor` 保守的なゲートによる検証済み；
- テキスト用ツールキットおよび、すでに生産ラインとして扱われているモンスターストリングの安全な切り出し。

### 依然としてブロック中
-`btl_txt.bin` writer/serializer/encode;
-`Field String` writer;
-`w_name.bin` writer;
- ブラインドポートの`LiveBattleLab`,`MemSharp_Service.cs` そして`MemoryBtl.cs` labsからの情報；
-`ModelViewer v2` 最終視聴者として；
- プロモーション`Repeat Exact Encounter` まるで既に証明されているかのように。

### なぜまだベータ版なのか
-`Pt6 / BattleStructureLab` 依然として観察的証拠が重く、明確な統合には至っていない；
-`Pt9 / ModelViewerLab` 依然として、確定した静的ビューポートは存在しない；
-`Pt12` a`Pt20` 現在も、ツールング、ハードニング、戦略、ガバナンスの策定が進められている。
- ランタイム、AI、メモリの各分野では、依然として実質的な統合が進められている。

## 歴史的意味の再構築

重要な編集上の注記：

- 以下の記述は、歴史的な変遷を記録したものである`v0.1.0` a`v0.8.0-beta.1` このプロジェクトの統合された読み方として；
- これらは実際の古いGitタグには対応していない；
- これらは、エディタがすでに単なる`v0.1.0` Gitが導入された時点でのリテラル；
- この「はしご」を構築するために使用された根拠は、`PRODUCTION_V2_HANDOFF.md`,`FFX_PRIORITY_BUILD_MANIFEST.md`,`PORT_STATUS.md`,`PROJECT_HISTORY_MASTER.md`,`WORKSHOP_TIMELINE.md`,`PRODUCTION_ABSORPTION_MATRIX.md`,`PT_VERSIONING_REGISTRY.md` およびワークショップの引き継ぎについて。

## [v0.8.0-beta.1] - 歴史的再構築（Git公式SemVer以前）

エコシステムが、大規模かつモジュール化されたエディターとして機能し、複数の専門分野が同時に活発に活動している段階。

### この段階におけるメイン画面
-`Monster Editor`;
-`Battle Explorer`;
-`Sphere Grid Explorer`;
-`Sphere Grid Editor v1`;
-`Encounter Table Explorer`;
-`Monster AI Explorer`;
-`String Explorer` 安全なルートで`Monster Localizations`;
-`Live Battle Lab`;
- 堅牢なカーネルラインアップと`PlayerGrowthEditor`,`CtbBaseEditor` そして`MixTableEditor`.

### 生態系への負荷
-`Pt2 + Pt9` 置く`ModelViewerLab` 本格的な偵察と実際のハンドオフの段階において；
-`Pt8` 閉じる`Shop` スライスとして保存され、確実にブロックする`w_name.bin`;
-`Pt6` すでにその話題を独占している`runtime + AI + proof`;
- その制作物はもはや「ありふれたエディター」という印象ではなく、コミュニティの標準をはるかに上回るモッディングのエコシステムへと変貌を遂げている。

### 依然として不足している点
-`ModelViewer v2` 最終的なビューポートとして；
-`Repeat Exact Encounter` 確認済み；
-`w_name.bin` writer;
-`btl_txt.bin` 幅広いライター；
- 重いランタイムツールのシームレスな統合。

## [v0.7.0] - 履歴の再構築（Git導入前の公式SemVer）

メインのラインが「モジュールの追加」から「試験の追加」へと切り替わる時点。

### 追加
-`BattleStructureLab` 旧Waveシリーズの中で、技術的に最も高度なモデルとなる；
-`BattleRuntimeProbe`, シーケンシング・ウォッチャーやセレクター／バンクの絞り込みが議論の中心となる；
-`Force Battle / Repeat Encounter` 単なる「希望的観測」ではなく、実際の観察実験として扱われるようになる。

### 変更点
- 公式の優先順位が`runtime + AI + proof`;
- 制作側は、リプレイ機能について、依然としてさらに`Repeat Route (Unsafe)` よりも`Exact Encounter`;
- プロジェクトのリスク評価が厳しくなる。

### まだ安全ではない
- ブラインドマージ`runtime/memory`;
- 完全なリプレイの推進；
- 工場の総重量`Pt6` ～へ`main`.

## [v0.6.0] - 歴史的再構築（Git導入前の公式SemVer）

カーネル系およびセカンダリシステムの保守的な強化が、単なる約束の段階から、本格的なエディタの一部へと移行したマイルストーン。

### 追加
-`AutoAbilityEditor` 保守的なゲートを持つ独自の路線として成熟していく；
-`KeyItemEditor` 実際の吸収範囲内に入る；
- 生産はすでに、より円滑に連携している`Customization / Aeons` およびその他のリバランスブロック。

### 変更点
- ポート戦略が「ラボからコピーする」から「実証済みの切り出しを取り入れる」に変更されました；
- 以下のような不明瞭なバイト列`62h..67h` 引き続き維持されることになる`raw/read-only` でっち上げのセマンティクスを追加する代わりに；
- kernelブランチは実験的な段階を脱し、より厳しい編集基準が適用されるようになる。

### 依然として未実装
-`Shop` 誠実な作家；
-`w_name.bin` 安全；
- 次の波に対応できるほど強力なランタイム・インストルメンテーション。

## [v0.5.0] - 履歴の再構築（Git導入前の公式SemVer）

大きな波の始まり`KernelTablesLab`.

### 追加
-`PlayerGrowthEditor`;
-`CtbBaseEditor`;
-`MixTableEditor`;
- 成熟したトレイル`KeyItemEditor`;
- 初期の準備状況`Auto-Abilities`,`Item Shop / Gear Shop` そして`w_name.bin`.

### 変更点
- エディタは、もはや戦闘面やモンスター面だけに依存するものではなく、本格的なカーネル層を備えるようになった。
- モッディングにおけるリバランス作業の重要な部分が、独自のUI上で実行可能になった。
- 制作プロセスは、将来的により洗練された統合を行うための基盤を得た。

### まだ未実装
- 最終的な検証`Auto-Abilities` 生産において；
-`Shop` 保守的なライターとして；
- 信頼性の高いセマンティクス`w_name.bin`.

## [v0.4.0] - 歴史的再構築（Git導入前の公式SemVer）

プロジェクトが、実際の判断基準に基づいてテキスト内の「はい」と「いいえ」を識別できるようになるマイルストーン。

### 追加
-`TextRegressionHarness` 回帰療法の一環として；
- 安全なゲートとして`Name / Description`;
- 安全なゲートへ`Monster Localizations 1/2/3`;
- 後に～へとつながることになるツール`TextLabTools` そして`ProductionAuditTools`.

### 変更点
- 以前は総称して「`Unsupported` 以下のように分類される：
  -`reader provado`;
  -`writer conservador`;
  -`blocked`;
-`Field String` そして`btl_txt.bin` 「もうすぐ完成」であるかのようにロマンチックに描かれることはなくなる。

### Still Missing
- 作家：`Battle Text`;
- 正当なアンロック`Field String`;
- あまり知られていないファミリー向けのエンコードセーフ機能。

## [v0.3.0] - 歴史的再構築（Git導入前の公式SemVer）

エディタが単なるファイルブラウザから脱却し、AI、ランタイム、そしてゲームプレイ価値の高いインターフェースを取り入れ始めた節目。

### 追加
-`Monster AI Explorer`;
- 本格的な最初の層は`Live Battle Lab`;
- パーサー・コーパス、コマンド、強制アクション、および「生存状態」間の連携が強化されました；
- エンカウンターおよびスクリプト動作の検索機能が向上しました。

### 変更点
- AIは周辺的なテーマから脱却し、製品の優先事項となる；
- ランタイム検証の概念が、エディタのDNAに完全に組み込まれる；
- 他のコミュニティとは一線を画し、他ではほとんど提供されていない機能を提供するようになる。

### まだ実装されていない機能
- より詳細なターンごとの検証；
- AIの安全なパッチ適用；
- 正確なエンカウンターツール。

## [v0.2.0] - 歴史的再構築（Git導入前の公式SemVer）

大規模かつ視覚的なシステムに向けた、エディタの構造的拡張の節目。

### 追加
-`Sphere Grid Explorer`;
-`Sphere Grid Editor v1`;
-`Encounter Table Explorer`;
- 戦闘システムおよびエンカウント表の構造をより堅牢なものに。

### 変更点
- エディタは「いくつかの強力なドメイン」という段階から脱却し、複数の広大なエリアを移動できるツールへと進化しました；
- ゲームドメイン間の移動がより一貫性のあるものになりました；
- このプロジェクトは、モッディングスイートとして本格的な存在感を増しました。

### まだ未実装
-`Encounter Table Editor`;
- Sphere Gridの攻撃的なトポロジー；
- より洗練されたAI／ランタイム。

## [v0.1.0] - 歴史的再構築（Git導入前の公式バージョン番号）

使い捨てのプロトタイプをはるかに超え、本格的なエディタがすでに存在していた、最小限の正直なマイルストーン。

### 追加
-`Monster Editor`;
-`Battle Commands / Items / Monster Commands`;
-`Battle Explorer`;
- 製品を特徴づけるのに十分なほど現実的な書き込み可能なインターフェースであり、単なるモックではない。

### 変更点
- このプロジェクトは、本格的なGitが導入される前から、実用的なエディタとして存在していた；
- メインブランチはすでに独自のアイデンティティを持っており、その存在を正当化するために「概念実証」に依存していなかった；
- この歴史的なバージョンこそが、`FFX Project Editor` 当時はすでに編集者でしたが、現在の規模にはまだほど遠かったのです。

### まだ見つからない
-`Sphere Grid` 編集可能；
- 専用のエンカウンター・ツール；
- 高度なAI／ランタイム；
- 正式なガバナンス／バージョン管理；
- 専門的なワークショップのエコシステム。

## [baseline-2026-05-31] - 2026-05-31

本番環境からGitへの初期の正確なインポート。

### 追加
- プライベートリポジトリ`ffx-editor-main`;
- ブランチ`main`;
- タグ`baseline-2026-05-31`;
-`.gitattributes`;
-`Git LFS` で`FFXProjectEditor/Assets/Audio/**`.

### 保存済み
-`_labs` ベースラインから外れてしまった；
-`publish/`,`bin/`,`obj/` そして、破棄可能なレポートは引き続き無視された；
- ベースラインは遡及的な履歴を装わなかった。

### 検証済み
- ベースラインのコミットが正常に公開された；
-`origin/main` そして`baseline-2026-05-31` Gitの同じ初期コミットを指している；
- ベースラインの公開後、ローカルのワーキングツリーがクリーンな状態になる。

### 注記
- これはインポート用のベースラインおよびスナップショットであり、製品のセマンティックリリースではありません。
- ガバナンス、バージョン管理、および取り込みのプロセスが始まる前に、Git上にビルドを固定するために存在します。

## ミニ・バージョン履歴ワークショップ

注記：

-`Pt1` ここには表示されないのは、それが統合レジストリにおいて正式なワークショップ／バージョン管理ラインになっていないためである。`2026-05-31`;
- この波のバージョン管理された履歴は、`Pt2`.

## [pt2-v0.3.0-superseded.1] - 2026-05-31

### ミッション
- 路線を開設する`ModelViewerLab`;
- 理解する`mon`,`.ebp` および関連するファミリー；
- 現時点ではまだ存在しないレンダラーと、HonestaのReconを区別する。

### 進化
- 隔離されたシェルから`ModelViewerLab`;
- エクスポート可能なアーティファクト;
- 分類`PROVED / STRUCTURAL / GUESS`;
- 歴史的基盤であり、その後正式に移行された`Pt9`.

### メインブランチの結果
- 直接的な機能的な吸収はない；
- レガシーが系統の起源として認められている`ModelViewer`.

### 最終ステータス
- 以下のものに置き換えられました`Pt9`;
- 独立した「生きた系譜」としてではなく、歴史的な起源としては依然として重要である。

## [pt3-v0.8.0-freeze.1] - 2026-05-31

### ミッション
- テキスト形式の監査を行う；
- 安全なリーダーを検証する；
- 真に保守的なライターのみを推奨する。

### 進化
-`TextRegressionHarness`;
- 以前は次のように扱われていた世帯の再分類`Unsupported`;
- 安全なゲートへ`Name / Description`;
- 安全なゲートへ`Monster Localizations 1/2/3`;
- 維持するという誠実な決断`btl_txt.bin` そして`Field String` セール対象外。

### 主要支店の結果
-`TextLabTools` 吸収された；
-`ProductionAuditTools` 吸収済み；
- メイン行のテキスト／モンスターの安全な切り取り。

### 最終ステータス
- 凍結中；
- 制作におけるテキスト境界の基準として引き続き有効。

## [pt4-v0.5.0-hold.1] - 2026-05-31

### ミッション
- ビジュアルの仕上げを行う；
- ランタイムに影響を与えずにシェル／テーマを試験的に導入する；
- 実際に移植可能なアセットと、社内ブランディング用アセットを分離する。

### 進化
-`StudioTokens`,`StudioTheme`、dense shell、ダッシュボード、トラッカー、およびアセットのハーベスト；
- 並行ライン`FFXMenuWorkshopConcept`;
- ビジュアルパッケージは、熟成版としては十分に完成度が高いが、そのままマージするにはまだ不十分である。

### メインブランチの結果
- アセットベースの部分的な共有；
- パッケージ全体の適切な移植は行われていない。

### 最終ステータス
- 保留；
- ワークショップ全体をマージするのではなく、ブロック単位での移植候補として継続。

## [pt5-v0.9.0-final.1] - 2026-05-31

### ミッション
- カーネル用パーサーおよびテーブルエディタを統合する；
- ゲートが閉じるたびに、研究成果を本番用モジュールへと転換する。

### 経緯
-`PlayerGrowthEditor`;
-`CtbBaseEditor`;
-`MixTableEditor`;
- 根拠となった一節`KeyItemEditor`;
- 再配分`Auto-Abilities` ～へ`Pt7`.

### メインブランチの結果
- 生産環境における実態的な吸収の最大規模の波の一つ；
- セキュアカーネルが、`main`.

### 最終状況
- 完了；
- ワークショップは終了し、主な成果はすでに制作チームによって取り入れられた。

## [pt6-v0.7.0-beta.1] - 2026-05-31

### ミッション
- 戦闘のランタイム・トゥルースを実証する；
- エンカウンターおよびシーケンスにおける推測を削減する；
- 現実的な基盤を提供する`Force Battle / Repeat Encounter`.

### エボリューション
-`BattleRuntimeProbe`;
- シーケンシング・ウォッチャー；
- セレクター／バンクのログ；
- スロット・チョーサーの絞り込み；
- バトルおよびティアダウンのより正確な観測トレイル。

### メインブランチの結果
- ロードマップおよび本番環境のリスク表現に大きな影響を与えた；
- これらはいずれも、ランタイム／メモリに関するクリーンなマージにはまだ至っていない。

### 最終ステータス
- ベータ版かつ優先度高；
- アクティブ、負荷が高く、技術的価値は高いが、ブラインド移植にはリスクが高い。

## [pt7-v0.9.0-final.1] - 2026-05-31

### ミッション
- 隔離`Auto-Abilities` カーネル・キューから；
- セマンティクスを膨らませることなく、保守的なエディタを検証する。

### 進化
-`AutoAbilityEditor`;
-`AutoAbility_File.cs`;
-`Arms_Rate.cs`;
- 維持するための明示的なゲート`62h..67h` どのように`raw/read-only`.

### メインブランチの結果
- 本番環境で実際に検証済み；
- ガードレールを維持したままラボからメインブランチへ移行した、最もクリーンな事例の一つ。

### 最終ステータス
- 完了；
- 完了した歴史的ワークショップとして扱うこと。

## [pt8-v0.7.0-freeze.1] - 2026-05-31

### ミッション
- 最小限かつ妥当なライターをクローズし、`Shop`;
- 以下の質問に正直に答えてください`w_name.bin` 準備ができていたか、いなかったか。

### エボリューション
- ライターは以下に保存されました`item_shop.bin`;
- 保存されたライター`arms_shop.bin`;
- 明示的な依存関係`shop_arms.bin` ギアの側で；
-`w_name.bin` 「research-only」に維持され、「writer」にはブロックされています。

### メインブランチの結果
- 実際の部分的な吸収`Shop`:
  -`Shop Explorer`;
  -`FfxLib/Shop`;
  -`Assets/Shop`;
  - ガードレールに関する資料は以下に記載されています`docs/history/PT8_SHOP_GUARDRAILS.md`.

### 最終ステータス
- 凍結／無効化；
-`Shop` 保守的な切り取りに入った；
-`w_name.bin` 引き続き利用不可で、ブロックされた状態です。

## [pt9-v0.6.0-alpha.1] - 2026-05-31

### ミッション
- 正式に以下の路線を継続する`ModelViewerLab`;
- 凍結する`ModelViewer v1`;
- の真の目標を再定義する`ModelViewer v2`.

### エボリューション
-`PT9_CONTINUATION_PACK.md`;
-`ModelViewer v1` 「recon + clues」として認識され、最終ビューアではない；
- サウンドトラック`mot/regmot` および PS2/Chargeur/FFXDumper ブリッジ；
- 今後、以下からの統合に向けた最有力候補として`Monster Editor`.

### メインブランチの結果
- 現時点では機能的な取り込みはなし；
- リサーチおよび絞り込みのスタックとして高い価値がある。

### 最終ステータス
- アルファ版が稼働中；
- 実際の静的ビューポートの実証がまだ必要。

## [pt10-v0.2.0-final.1] - 2026-05-31

### ミッション
- パス処理を行う`read-only` から`btl_txt.bin`;
- 整理する`US vs JP`,`W0..W3`, prefix および pair。

### 進化
- marker/pair/prefix の文書分類法；
- マトリックス`W0..W3`;
- 改めて強調すると、`Battle Text` 引き続き読み取り専用でした。

### メインブランチの結果
- ドキュメントおよびガードレールとしての価値のみ；
- 実装された機能なし。
- 機能は導入されませんでした。

### 最終ステータス
- 最終版／読み取り専用；
- ワークショップは、ライター対応の準備としてではなく、ドキュメントとして完了しました。

## [pt11-v0.3.0-blocked.1] - 2026-05-31

### ミッション
- 最小限かつ安全なライターを検証すること`btl_txt.bin`.

### 進化
- 制御された変更；
- 差分監査；
- わずかな変更であっても、意味的な汚染がないことが証明される。

### メインブランチの結果
- 証拠とガードレールに関する読み取り専用パッケージのみが取り込まれた；
- writer/encodeは引き続きブロックされたままである。

### 最終ステータス
- ブロックド・フリーズ；
- ワークショップは、技術的な根拠に基づいて「ノー」と言う役割を果たした。

## [pt12-v0.3.0-package.1] - 2026-05-31

### ミッション
- Ghidraのエクスポート出力と、プロジェクトで有用なアーティファクトとの間に橋渡しを構築する。

### 開発の経緯
- 有望なパーサー；
- バインディングのコードジェネレータ；
- シンボルカタログ；
- スタンドアロンツールとして取り込みの検討が可能な状態のパッケージ。

### メインブランチの成果
- 現時点では取り込み実績なし；
- 次のフェーズに向けた取り込み用ブランチを開設。

### 最終ステータス
- パッケージ化済み；
- 以下の統合後に採用される有力候補`Pt8`.

## [pt13-v0.3.0-package.1] - 2026-05-31

### ミッション
- ランタイム・ツールング用の .NET レイアウト／構造体インスペクタを作成する。

### 開発経緯
- インスペクション機能；
- オフセット／サイズのレポート；
- メモリに敏感な型における実際の不一致の検出。

### メインブランチの成果
- 現時点ではマージなし；
- 次のリリースに向けたマージ用ブランチを開設。

### 最終ステータス
- パッケージ化準備完了；
- 以下のリリースに併せて、またはその直後に組み込まれる有力候補`Pt12`.

## [pt14-v0.2.0-architecture.1] - 2026-05-31

### ミッション
- 規律あるキャプチャについて研究する`printf` および内部デバッグ文字列。

### 進化
- アーキテクチャおよびエントリー候補；
- キャプチャのガードレール；
- 本番環境向けのフックが完成したという確固たる証拠はまだない。

### メインブランチの結果
- 取り込みなし；
- マージを行う前に、新たな絞り込み作業が必要。

### 最終ステータス
- architecture-hold；
- このブランチは、まだ最小限の検証を完了するか、ハードブロックとなる必要がある。

## [pt15-v0.2.0-architecture.1] - 2026-05-31

### ミッション
- ランタイムのハンドルおよびイベントバスの仕様を設計する。

### 進捗
- ライフサイクルアーキテクチャ；
- イベント契約；
- スレッディング／再入リスクのマッピング済み；
- 本番環境向けの最小スライスはまだ完成していない。

### メインブランチの結果
- 取り込みなし；
- マージ可能と見なされるには、読み取り専用の最小スライスが用意される必要がある。

### 最終ステータス
- architecture-hold；
- 完成したコードとしてではなく、方向性として有用。

## [pt16-v0.2.0-architecture.1] - 2026-05-31

### ミッション
- エンコーディングアーキテクチャを整理し、`index types` 衝動的に新しいWriterをアンロックしない。

### エボリューション
- 分類法の提案；
- マトリックス`decode-only / encode-safe / raw-control`;
- まだ吸収された小さな付加スライスがない。

### メインブランチの結果
- 吸収なし；
- 引き続き待機中`Slice 1` 小規模で安全。

### 最終ステータス
- architecture-hold;
- 将来的に重要なブランチだが、現時点では直ちにマージされる予定はない。

## [pt17-v0.3.0-guardrail.1] - 2026-05-31

### ミッション
- セーブ安全性、ラウンドトリップ、およびドリフトの分類を強化する。

### 進化
- リスクマトリックス；
- セーブ／リロード用ハーネス；
- まだ解決されていない重要な障害の通知、以下を含む`important.bin` そして`a_ability.bin + arms_rate.bin`.

### メインブランチの結果
- 実際のデルタについては、まだ特定し、正当な根拠に基づいて取り込む必要がある。
- 機能の一部は既存のツールにすでに反映されているようだが、すべてではない。

### 最終ステータス
- guardrail-baseline；
- 新機能としてではなく、セキュリティ強化策として引き続き重要である。

## [pt18-v0.3.0-governance.1] - 2026-05-31

### ミッション
- リリース、変更履歴、ベースライン、タグ、および編集ワークフローを整理する。

### 経緯
- ポリシー`CHANGELOG`;
- バージョン管理ポリシー；
- ブランチ／マージポリシー；
- ワークショップ公開のための安全な手順の統合。

### メインブランチの成果
- 大部分はすでに`docs/governance/`;
- 主要な価値は生産ガバナンスへと移行した。

### 最終ステータス
- governance-baseline;
- 将来の変革というよりは、ゲームのルールとして定着しつつある。

## [pt19-v0.3.0-surface.1] - 2026-05-31

### ミッション
- 整合を図る`README`、スクリーンショット、およびSurfaceは現在のエディターで公開されます。

### 進化
- スクリーンショットの監査；
- アセットに関するポリシー`README`;
- 古いスクリーンショットを、最新かつ追跡可能な画像に置き換える。

### メインブランチの成果
- 大部分はすでにローカルワークツリーに反映されているようだ；
- 最終的なデルタは、他の作業項目と混同しないよう、まだ分離する必要がある。

### 最終ステータス
- surface-baseline；
- 公開プレゼンテーション向けの重要なブランチであり、ランタイム／コア向けではない。

## [pt20-v0.2.0-strategy.1] - 2026-05-31

### ミッション
- フレームワーク全体をインポートすることなく、外部ツールを選択的に取り込む方法を検討する。

### 進捗
- 統合マトリックス；
- 比較`STEP`、インスペクターおよびデバッグツール；
- エコシステムの全面的な複製ではなく、外科的統合を推奨。

### メインブランチの結果
- 現時点では吸収は行われていない；
- 以下のための運用ロードマップとして機能する`Pt12 -> Pt13`.

### 最終ステータス
- strategy-baseline;
- 統合の方向性として継続され、マージ完了として扱われない。


