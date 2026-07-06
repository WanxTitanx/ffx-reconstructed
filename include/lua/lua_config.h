// ============================================================================
// Lua 5.2.1 -- Configuracoes de compilacao para FFX.EXE
// ============================================================================
// Este arquivo e incluido por include/lua/lua.hpp antes dos headers do Lua.
// O luaconf.h original ja detecta Windows automaticamente via _WIN32,
// entao LUA_USE_WINDOWS nao e estritamente necessario -- mantemos como
// documentacao de que este e um build Windows.
// ============================================================================
#ifndef lua_config_h
#define lua_config_h

// --- Plataforma ---
// Sinaliza que este e um build Windows. O luaconf.h original usa _WIN32
// para definir LUA_WIN, que ativa LUA_DL_DLL e LUA_USE_AFORMAT.
#define LUA_USE_WINDOWS 1

// --- Compatibilidade com Lua 5.1 ---
// Ativa: unpack, loaders, log10, loadstring, maxn, module
#define LUA_COMPAT_ALL 1

#endif // lua_config_h
