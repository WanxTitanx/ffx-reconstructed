// ============================================================================
// Lua 5.2.1 -- C++ wrapper header para FFX.EXE
// ============================================================================
// Inclui lua_config.h primeiro (overrides de configuracao),
// depois os headers C do Lua dentro de extern "C".
//
// Os headers reais estao em src/lua-real/ e sao encontrados via
// o include path que inclui essa pasta.
// ============================================================================
#ifndef lua_hpp
#define lua_hpp

#include "lua_config.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#endif // lua_hpp
