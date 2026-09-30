# Lua 5.2.1 — byte-identical reconstruction (verified)

Source: PhyreEngine SDK `External/lua/src` (Lua 5.2.1, `LUA_VERSION_NUM 502`).
Recipe: `cl /nologo /c /GS- /O2 /MD /Oy- /Oi <file>.c`, then LTCG link in the original build
(LTCG only affects padding-sensitive functions; objects already match for most).

**403 of the binary's 565 Lua functions are byte-identical** (36,009 of 92,035 Lua code bytes).

Verification method (no guessing):
1. compile each `l*.c` with the recipe above;
2. parse `dumpbin /DISASM` per object into per-label byte runs;
3. for each candidate, search every IDB function boundary with **exactly the same size**;
4. require full-length equality with relocation dwords masked (VA dwords and `E8/E9` rel32 displacements);
5. count only candidates that match **exactly one** boundary (`confirmed.json`), so no ambiguous winners inflate the number.

| IDA name | source function | VA | size |
|---|---|---|---|
| `LuaB_table_sort_core` | `auxsort` | `0x00955450` | 1032 |
| `LuaS_newlstr` | `internshrstr` | `0x00958540` | 339 |
| `LuaG_gcStepGC` | `callallpendingfinalizers` | `0x0094e2d0` | 310 |
| `LuaSys_packageOpen` | `luaopen_package` | `0x00961710` | 307 |
| `LuaParser_resolveScopeGotos` | `movegotosout` | `0x009641d0` | 300 |
| `LuaC_tagmethod` | `DumpConstants` | `0x00959b00` | 286 |
| `LuaG_gcStep` | `GCTM` | `0x0094e040` | 273 |
| `LuaSys_cmoduleSearcher` | `searcher_Croot` | `0x00960ff0` | 270 |
| `Lua_str_format_replace` | `add_s` | `0x00951b80` | 259 |
| `Lua_coroutine_resume_core` | `auxresume` | `0x00950ca0` | 232 |
| `Lua_str_gsub_replacer` | `add_value` | `0x00951c90` | 228 |
| `LuaCodeGen_emitConcat` | `luaK_self` | `0x00967d30` | 225 |
| `LuaB_string_byte` | `str_byte` | `0x00951260` | 223 |
| `PhyreTable_LookupKey` | `findfield` | `0x0094c480` | 221 |
| `LuaV_lessEqual` | `luaV_lessequal` | `0x0095be00` | 221 |
| `LuaV_compareHelper` | `call_binTM` | `0x0095a2d0` | 213 |
| `LuaB_loadfile` | `luaB_load` | `0x00954920` | 210 |
| `Lua_str_scanformat` | `scanformat` | `0x00952d00` | 208 |
| `LuaParser_closeScopeBlock` | `leaveblock` | `0x00963d90` | 202 |
| `LuaSys_moduleLoader` | `ll_require` | `0x00961160` | 200 |
| `LuaD_callFunctionWithArgs` | `callTM` | `0x0095a200` | 199 |
| `Lua_str_pushcaptures` | `push_captures` | `0x00952ba0` | 194 |
| `LuaH_get` | `luaH_get` | `0x00958cf0` | 193 |
| `LuaB_require_core` | `luaL_requiref` | `0x0094d870` | 187 |
| `LuaSys_dynlibLoadCore` | `ll_loadfunc` | `0x00961590` | 185 |
| `LuaIO_fileOpenInput` | `io_lines` | `0x0095df10` | 183 |
| `Lua_str_memfind` | `lmemfind` | `0x009521d0` | 180 |
| `LuaB_xpcall` | `luaB_xpcall` | `0x00954be0` | 177 |
| `LuaH_next` | `findindex` | `0x00958b20` | 176 |
| `Lua_debug_varname` | `findlocal` | `0x00956670` | 175 |
| `LuaD_resume` | `lua_resume` | `0x00957c80` | 172 |
| `LuaB_table_insert` | `tinsert` | `0x00954fc0` | 172 |
| `LuaB_string_sub` | `str_sub` | `0x00950e60` | 170 |
| `Lua_codegen_emitFormat` | `lua_getinfo` | `0x00956f50` | 167 |
| `LuaCodeGen_emitSetList` | `luaK_nil` | `0x00967860` | 166 |
| `LuaSys_resolveSearchPath` | `setpath` | `0x00961b10` | 166 |
| `LuaCodeGen_emitNewTable` | `luaK_setlist` | `0x00967e20` | 165 |
| `LuaG_gcMarkGray` | `luaC_checkfinalizer` | `0x0094ebd0` | 164 |
| `LuaParser_patchAssignment` | `luaK_setreturns` | `0x00967f30` | 162 |
| `Lua_str_matchcap` | `match_capture` | `0x009525b0` | 162 |

The remaining Lua functions need the exact per-file flags or LTCG inlining state; they are tracked in
`recon/lua/match_report.json` (all anchored candidates with measured diffs).
