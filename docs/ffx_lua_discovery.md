# FFX.exe Lua 5.2.1 Discovery

**Date:** 2026-07-28
**Database:** ffxoficial_COPY.i64 (session 9993ee7e)

## Key Finding

FFX.exe has **Lua 5.2.1** statically compiled into the binary. This is a major discovery for RE.

## Evidence

### Strings Found
- `"Lua 5.2.1"` @ 0xb6c468 — version string
- `"multiple Lua VMs detected"` @ 0xb6c6d8 — confirms multiple VM instances
- `"lua_pcall failed"` — multiple locations
- `"lua_debug>"` @ 0xb6e3e4 — Lua debugger prompt
- `"LUA_PATH_5_2"` @ 0xb6e610 — Lua 5.2 path config
- `"LUA_CPATH_5_2"` @ 0xb6e64c — Lua 5.2 C path config
- `"luaopen_%s"` @ 0xb6e50c — module loader pattern

### Functions Found
- `LuaG_open_verify` @ 0x94cc90 (181 bytes) — debug/verify module
- `LuaB_open_base` @ 0x954e60 (96 bytes) — base library opener

### Implications

1. **ATEL VMs may be Lua-based** — The 5 ATEL VMs (Movie/Battle/Map/Field/Script) might be Lua bytecode interpreters, not custom VMs.

2. **Lua scripts in game data** — The `.sbin`, `.rbin`, `.sc` files might contain Lua bytecode.

3. **Modding opportunity** — If we can load custom Lua scripts, we can mod game behavior without C++ patching.

4. **Lua 5.2 vs PhyreEngine SDK** — The SDK has Lua 5.1.4, but FFX uses 5.2.1. This suggests Square Enix upgraded Lua independently.

## Next Steps

1. Find all Lua-related functions (search for `lua` prefix in IDA)
2. Identify the Lua state initialization
3. Map which ATEL VM channels use Lua
4. Check if `.sbin`/`.rbin` files contain Lua bytecode
5. Create a Lua bytecode parser for FFX scripts
