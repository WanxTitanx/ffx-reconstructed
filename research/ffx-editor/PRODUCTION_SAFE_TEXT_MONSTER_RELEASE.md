---
date: 2026-06-29
tags:
  - production-safe
  - monster-localization
  - string-explorer
  - text-release
  - smoke-test
aliases:
  - Safe Text Monster Release
  - Production Safe Text Release
---
# Production Safe Text/Monster Release

## 1. O que entrou e está validado

- `StringExplorer` agora expõe badges/cards/classificação para os formatos.
- A família `Name/Description` salva e persiste após `save + refresh`.
- `Monster Localizations 1/2/3` salva e persiste somente nos campos `Name`, `Sensor` e `Scan`.
- `Monster Editor` permite editar e persistir `English Name`, `English Sensor` e `English Scan`.
- `Linked Monster` navega de `Monster Localizations` para `Monster Editor`.
- `Legacy MenuMain (US)` deve cair em `Different Format` quando o shape divergir do formato suportado.

## 2. O que continua bloqueado

- `Battle Text`
- `Field String`
- `Al Bhed Dictionary`
- `Pointer Script Table`
- `Legacy MenuMain` como writer

## 3. Smoke manual curto

1. Abrir um projeto com `new_uspc` e `jppc`.
2. No `StringExplorer`, confirmar badges/cards/classificação e verificar que `Legacy MenuMain (US)` divergente aparece como `Different Format`.
3. Editar um arquivo `Name/Description`, salvar, atualizar/reabrir e confirmar persistência.
4. Editar `Monster Localizations 1/2/3` em `Name`, `Sensor` e `Scan`, salvar, atualizar e confirmar persistência.
5. A partir de `Linked Monster`, abrir o `Monster Editor` e validar edição/persistência de `English Name`, `English Sensor` e `English Scan`.
6. Confirmar que conteúdo Japanese segue read-only.

## 4. Smoke automatizado disponível

- O recorte passou em build.
- Existe smoke/regressão via `TextLabTools/TextRegressionHarness`.
- Último relatório disponível: `TextLabTools/Reports/text-regression-last.md` com `36` sources, `36` pass e `0` fail.
- O harness cobre writer-safe para `Name/Description` e para `Monster Localizations` somente em `Name/Sensor/Scan`.
- `Battle Text` continua read-only; `Field String` aparece só como diagnóstico de serializer em lab; `Al Bhed Dictionary`, `Pointer Script Table` e `Legacy MenuMain` seguem reader-only no smoke automatizado.

## 5. Nota sobre Japanese

Japanese continua read-only neste recorte. Não houve liberação de writer para fluxo Japanese; a validação aqui é de leitura/navegação segura, não de edição.

## 6. Nota sobre Legacy MenuMain (US)

`Legacy MenuMain (US)` não deve ser comunicado como texto writer-safe. Quando o shape divergir, a classificação honesta é `Different Format`; e mesmo quando houver leitura/classificação de legacy menumain no harness, isso continua sendo cobertura reader-only, não writer.

## Arquivo alterado

- `C:\Users\wande\Documents\Codex\2026-05-26\mano-seguinte-aprende-tudo-que-eu\FFXProjectEditor-main\PRODUCTION_SAFE_TEXT_MONSTER_RELEASE.md`
