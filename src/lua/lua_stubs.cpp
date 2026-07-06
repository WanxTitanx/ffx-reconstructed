// ============================================================================
// Lua 5.2.1 — Stubs para reconstrução do FFX.EXE
// Todas as funções aqui foram mapeadas via RE no binário original.
// Cobre: Core VM (LuaV), Parser (luaY), CodeGen (luaK), Debug (luaG),
//        API pública (lua_*), AuxLib (luaL_*), Libs (luaopen_*),
//        PhyreScripting bridge, GC, Table, String, I/O, OS.
// ============================================================================
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <csetjmp>
#include <cstdarg>

// ============================================================================
// Tipos simulados (structs opacas — preenchidas durante a port progressiva)
// ============================================================================
struct lua_State;
struct TValue;
struct Table;
struct Proto;
struct GCheader;
struct UpVal;
struct CallInfo;

typedef double lua_Number;
typedef ptrdiff_t lua_KContext;
typedef int (*lua_CFunction)(lua_State *L);
typedef const char *(*lua_Reader)(lua_State *L, void *data, size_t *size);
typedef int (*lua_Writer)(lua_State *L, const void *p, size_t sz, void *ud);
typedef void *(*lua_Alloc)(void *ud, void *ptr, size_t osize, size_t nsize);

#define LUA_OK          0
#define LUA_YIELD       1
#define LUA_ERRRUN      2
#define LUA_ERRSYNTAX   3
#define LUA_ERRMEM      4
#define LUA_ERRGCMM     5
#define LUA_ERRERR      6
#define LUA_MULTRET     (-1)

#define LUA_TNONE           (-1)
#define LUA_TNIL            0
#define LUA_TBOOLEAN        1
#define LUA_TLIGHTUSERDATA  2
#define LUA_TNUMBER         3
#define LUA_TSTRING         4
#define LUA_TTABLE          5
#define LUA_TFUNCTION       6
#define LUA_TUSERDATA       7
#define LUA_TTHREAD         8

#define LUA_MINSTACK        20
#define LUAI_MAXSTACK       1000000
#define LUA_REGISTRYINDEX   (-LUAI_MAXSTACK - 1000)

// ============================================================================
// LuaV_* — Core VM (~30 functions)
// ============================================================================

// luaV_execute (0x95xxxx) — Core VM bytecode executor (39 opcodes)
int luaV_execute(lua_State *L, int nexeccalls) {
    // Stub: dispatch loop for MOVE, LOADK, GETTABLE, SETTABLE, ADD, SUB,
    //       MUL, DIV, MOD, POW, UNM, NOT, LEN, CONCAT, JMP, EQ, LT, LE,
    //       TEST, TESTSET, CALL, TAILCALL, RETURN, FORLOOP, FORPREP,
    //       TFORLOOP, SETLIST, CLOSURE, CLOSE, VARARG, EXTRAARG
    return 0;
}

// luaV_gettable (0x95xxxx) — "loop in gettable"
void luaV_gettable(lua_State *L, const TValue *t, TValue *key, TValue *val) {
    // Stub
}

// luaV_settable (0x95xxxx) — "loop in settable"
void luaV_settable(lua_State *L, const TValue *t, TValue *key, TValue *val) {
    // Stub
}

// luaV_equal (0x95xxxx) — EqualDispatch, EqualMeta (__eq metamethod)
int luaV_equal(lua_State *L, const TValue *t1, const TValue *t2) {
    return 0; // Stub
}

// luaV_lessthan (0x95xxxx) — CompareLE/LT (float/string), strcoll
int luaV_lessthan(lua_State *L, const TValue *l, const TValue *r) {
    return 0; // Stub
}

// luaV_tonumber (0x95xxxx) — Convert string to number
int luaV_tonumber(const TValue *obj, TValue *result) {
    return 0; // Stub
}

// luaV_forlist_check (0x95xxxx) — For list iteration check
int luaV_forlist_check(lua_State *L, TValue *t) {
    return 0; // Stub
}

// luaV_concat (0x95xxxx) — "string length overflow"
void luaV_concat(lua_State *L, int total) {
    // Stub
}

// luaV_mod (0x95xxxx) — Modulo operation with float fixup
lua_Number luaV_mod(lua_Number x, lua_Number y) {
    return 0.0; // Stub
}

// luaV_div (0x95xxxx) — Floating-point division
lua_Number luaV_div(lua_Number x, lua_Number y) {
    return 0.0; // Stub
}

// luaV_executeArithFallback (0x95xxxx) — Fallback for arithmetic metamethods
int luaV_executeArithFallback(lua_State *L, int op) {
    return 0; // Stub
}

// ============================================================================
// LuaParser_* / luaY_* — Parser system (~10 functions)
// ============================================================================

// luaY_parser (0x95xxxx) — Main parser entry point
void *luaY_parser(lua_State *L, lua_Reader reader, void *data,
                  const char *name, int firstchar) {
    return nullptr; // Stub
}

// LuaParser_statement (0x95xxxx) — 227-case switch, central dispatcher
void LuaParser_statement(lua_State *L, void *lexstate) {
    // Stub: parses if/while/repeat/for/function/local/return/break/do/block
}

// LuaParser_expression (0x95xxxx) — Expression parser (prefix/infix)
void LuaParser_expression(lua_State *L, void *lexstate, void *expdesc) {
    // Stub
}

// LuaParser_forInClause (0x95xxxx) — For-in clause parser
void LuaParser_forInClause(lua_State *L, void *lexstate, void *expdesc) {
    // Stub
}

// LuaParser_prefix (0x95xxxx) — Prefix expression (name, number, string, parens)
void LuaParser_prefix(lua_State *L, void *lexstate, void *expdesc) {
    // Stub
}

// LuaParser_infix (0x95xxxx) — Infix operator (binary ops)
void LuaParser_infix(lua_State *L, void *lexstate, void *expdesc) {
    // Stub
}

// LuaParser_body (0x95xxxx) — Function body parser
void LuaParser_body(lua_State *L, void *lexstate, void *expdesc, int ismethod) {
    // Stub
}

// LuaParser_funcargs (0x95xxxx) — Function arguments (() or {} or string literal)
void LuaParser_funcargs(lua_State *L, void *lexstate, void *expdesc) {
    // Stub
}

// LuaParser_primaryexp (0x95xxxx) — Primary expression with chained calls
void LuaParser_primaryexp(lua_State *L, void *lexstate, void *expdesc) {
    // Stub
}

// LuaParser_explist (0x95xxxx) — Expression list (comma-separated)
int LuaParser_explist(lua_State *L, void *lexstate, void *expdesc) {
    return 0; // Stub
}

// LuaParser_singlevar (0x95xxxx) — Single variable lookup
void LuaParser_singlevar(lua_State *L, void *lexstate, void *expdesc) {
    // Stub
}

// ============================================================================
// LuaCodeGen_* / luaK_* — Code generation (~10 functions)
// ============================================================================

// luaK_codeABC (0x95xxxx) — Emit instruction in ABC format
int luaK_codeABC(void *funcstate, int op, int A, int B, int C) {
    return 0; // Stub
}

// luaK_codeABx (0x95xxxx) — Emit instruction in ABx format
int luaK_codeABx(void *funcstate, int op, int A, unsigned int Bx) {
    return 0; // Stub
}

// luaK_exp2reg (0x95xxxx) — Expression to register
void luaK_exp2reg(void *funcstate, void *expdesc, int reg) {
    // Stub
}

// luaK_exp2nextreg (0x95xxxx) — Expression to next available register
void luaK_exp2nextreg(void *funcstate, void *expdesc) {
    // Stub
}

// luaK_emitOpcode (0x95xxxx) — Emit opcode
void luaK_emitOpcode(void *funcstate, int op) {
    // Stub
}

// luaK_emitBinaryOp (0x95xxxx) — Emit binary operation
void luaK_emitBinaryOp(void *funcstate, int op, int reg, int target) {
    // Stub
}

// luaK_emitUnaryOp (0x95xxxx) — Emit unary operation
void luaK_emitUnaryOp(void *funcstate, int op, int reg, int target) {
    // Stub
}

// luaK_emitMove (0x95xxxx) — Emit MOVE instruction
void luaK_emitMove(void *funcstate, int dst, int src) {
    // Stub
}

// luaK_emitLoad (0x95xxxx) — Emit LOADK instruction
void luaK_emitLoad(void *funcstate, int reg, int k) {
    // Stub
}

// luaK_emitReturn (0x95xxxx) — Emit RETURN instruction
void luaK_emitReturn(void *funcstate, int first, int nret) {
    // Stub
}

// luaK_emitJMP (0x95xxxx) — Emit JMP instruction
void luaK_emitJMP(void *funcstate, int pc) {
    // Stub
}

// luaK_checkstack (0x95xxxx) — Check and grow function stack
void luaK_checkstack(void *funcstate, int n) {
    // Stub
}

// luaK_stringK (0x95xxxx) — Add string constant to function's constant table
int luaK_stringK(void *funcstate, const char *s, size_t len) {
    return 0; // Stub
}

// luaK_numberK (0x95xxxx) — Add number constant to function's constant table
int luaK_numberK(void *funcstate, lua_Number r) {
    return 0; // Stub
}

// luaK_setreturns (0x95xxxx) — Mark expression as having multiple returns
void luaK_setreturns(void *funcstate, void *expdesc, int nresults) {
    // Stub
}

// luaK_setoneret (0x95xxxx) — Force expression to single return
void luaK_setoneret(void *funcstate, void *expdesc) {
    // Stub
}

// ============================================================================
// LuaDebug_* / luaG_* — Debug support (~8 functions)
// ============================================================================

// luaG_typeerror (0x95xxxx) — "attempt to %s a %s value"
int luaG_typeerror(lua_State *L, const TValue *o, const char *op) {
    return 0; // Stub
}

// luaG_concaterror (0x95xxxx) — Concatenation type error
void luaG_concaterror(lua_State *L, const TValue *p1, const TValue *p2) {
    // Stub
}

// luaG_runerror (0x95xxxx) — Runtime error with formatted message
int luaG_runerror(lua_State *L, const char *fmt, ...) {
    return 0; // Stub
}

// luaG_aritherror (0x95xxxx) — Arithmetic operation type error
void luaG_aritherror(lua_State *L, const TValue *p1, const TValue *p2) {
    // Stub
}

// luaG_ordererror (0x95xxxx) — Order comparison type error
void luaG_ordererror(lua_State *L, const TValue *p1, const TValue *p2) {
    // Stub
}

// LuaDebug_REPL (0x95xxxx) — Interactive "lua_debug>" prompt
void LuaDebug_REPL(lua_State *L) {
    // Stub: interactive read-eval-print loop
}

// LuaDebug_getinfo (0x95xxxx) — Get debug information
int LuaDebug_getinfo(lua_State *L, const char *what, void *ar) {
    return 0; // Stub
}

// LuaDebug_traceback (0x95xxxx) — Generate traceback string
void LuaDebug_traceback(lua_State *L) {
    // Stub
}

// LuaDebug_getlocal (0x95xxxx) — Get local variable info
const char *LuaDebug_getlocal(lua_State *L, void *ar, int n) {
    return nullptr; // Stub
}

// LuaDebug_setlocal (0x95xxxx) — Set local variable value
const char *LuaDebug_setlocal(lua_State *L, void *ar, int n) {
    return nullptr; // Stub
}

// LuaDebug_getupvalue (0x95xxxx) — Get upvalue info
const char *LuaDebug_getupvalue(lua_State *L, int func, int n) {
    return nullptr; // Stub
}

// LuaDebug_setupvalue (0x95xxxx) — Set upvalue value
const char *LuaDebug_setupvalue(lua_State *L, int func, int n) {
    return nullptr; // Stub
}

// LuaDebug_sethook (0x95xxxx) — Set debug hook
int LuaDebug_sethook(lua_State *L, void *func, int mask, int count) {
    return 0; // Stub
}

// LuaDebug_gethook (0x95xxxx) — Get current hook settings
void *LuaDebug_gethook(lua_State *L) {
    return nullptr; // Stub
}

// LuaDebug_gethookcount (0x95xxxx) — Get hook count
int LuaDebug_gethookcount(lua_State *L) {
    return 0; // Stub
}

// LuaDebug_gethookmask (0x95xxxx) — Get hook mask
int LuaDebug_gethookmask(lua_State *L) {
    return 0; // Stub
}

// LuaDebug_getstack (0x95xxxx) — Get stack level info
int LuaDebug_getstack(lua_State *L, int level, void *ar) {
    return 0; // Stub
}

// ============================================================================
// Lua API — lua_* (~25 functions)
// ============================================================================

// lua_newstate (0x95xxxx) — Create new Lua state
lua_State *lua_newstate(lua_Alloc f, void *ud) {
    return nullptr; // Stub
}

// lua_close (0x95xxxx) — Close Lua state, free all resources
void lua_close(lua_State *L) {
    // Stub
}

// lua_pcall (0x95xxxx) — Protected call (used by PhyreScripting bridge)
int lua_pcall(lua_State *L, int nargs, int nresults, int errfunc) {
    return LUA_OK; // Stub
}

// lua_load (0x95xxxx) — Load a Lua chunk
int lua_load(lua_State *L, lua_Reader reader, void *data,
             const char *chunkname, const char *mode) {
    return LUA_OK; // Stub
}

// lua_newthread (0x95xxxx) — Create new thread (coroutine)
lua_State *lua_newthread(lua_State *L) {
    return nullptr; // Stub
}

// lua_resume (0x95xxxx) — Resume a coroutine
int lua_resume(lua_State *L, lua_State *from, int narg) {
    return LUA_OK; // Stub
}

// lua_yield (0x95xxxx) — Yield from a coroutine
int lua_yield(lua_State *L, int nresults) {
    return LUA_YIELD; // Stub
}

// lua_status (0x95xxxx) — Get thread status
int lua_status(lua_State *L) {
    return LUA_OK; // Stub
}

// lua_pushnil (0x95xxxx) — Push nil
void lua_pushnil(lua_State *L) {
    // Stub
}

// lua_pushboolean (0x95xxxx) — Push boolean
void lua_pushboolean(lua_State *L, int b) {
    // Stub
}

// lua_pushnumber (0x95xxxx) — Push number
void lua_pushnumber(lua_State *L, lua_Number n) {
    // Stub
}

// lua_pushinteger (0x95xxxx) — Push integer
void lua_pushinteger(lua_State *L, int n) {
    // Stub
}

// lua_pushlstring (0x95xxxx) — Push counted string
void lua_pushlstring(lua_State *L, const char *s, size_t len) {
    // Stub
}

// lua_pushstring (0x95xxxx) — Push null-terminated string
void lua_pushstring(lua_State *L, const char *s) {
    // Stub
}

// lua_pushcfunction (0x95xxxx) — Push C function
void lua_pushcfunction(lua_State *L, lua_CFunction f) {
    // Stub
}

// lua_pushlightuserdata (0x95xxxx) — Push light userdata
void lua_pushlightuserdata(lua_State *L, void *p) {
    // Stub
}

// lua_pushvalue (0x95xxxx) — Push copy of stack value
void lua_pushvalue(lua_State *L, int idx) {
    // Stub
}

// lua_tonumber (0x95xxxx) — Get number at index
lua_Number lua_tonumber(lua_State *L, int idx) {
    return 0.0; // Stub
}

// lua_tointeger (0x95xxxx) — Get integer at index
int lua_tointeger(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_toboolean (0x95xxxx) — Get boolean at index
int lua_toboolean(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_tolstring (0x95xxxx) — Get string at index (with length)
const char *lua_tolstring(lua_State *L, int idx, size_t *len) {
    return nullptr; // Stub
}

// lua_tocfunction (0x95xxxx) — Get C function at index
lua_CFunction lua_tocfunction(lua_State *L, int idx) {
    return nullptr; // Stub
}

// lua_touserdata (0x95xxxx) — Get userdata at index
void *lua_touserdata(lua_State *L, int idx) {
    return nullptr; // Stub
}

// lua_tothread (0x95xxxx) — Get thread at index
lua_State *lua_tothread(lua_State *L, int idx) {
    return nullptr; // Stub
}

// lua_topointer (0x95xxxx) — Get raw pointer at index
const void *lua_topointer(lua_State *L, int idx) {
    return nullptr; // Stub
}

// lua_type (0x95xxxx) — Get type of value at index
int lua_type(lua_State *L, int idx) {
    return LUA_TNIL; // Stub
}

// lua_typename (0x95xxxx) — Get type name
const char *lua_typename(lua_State *L, int tp) {
    return "nil"; // Stub
}

// lua_isfunction (0x95xxxx) — Check if value is function
int lua_isfunction(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_isstring (0x95xxxx) — Check if value is string
int lua_isstring(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_istable (0x95xxxx) — Check if value is table
int lua_istable(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_isnumber (0x95xxxx) — Check if value is number
int lua_isnumber(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_isnil (0x95xxxx) — Check if value is nil
int lua_isnil(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_isboolean (0x95xxxx) — Check if value is boolean
int lua_isboolean(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_isnone (0x95xxxx) — Check if index is valid
int lua_isnone(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_isnoneornil (0x95xxxx) — Check if index is invalid or nil
int lua_isnoneornil(lua_State *L, int idx) {
    return 1; // Stub
}

// lua_settable (0x95xxxx) — Set table[key] = value (pop key & value)
void lua_settable(lua_State *L, int idx) {
    // Stub
}

// lua_gettable (0x95xxxx) — Get table[key], push value
void lua_gettable(lua_State *L, int idx) {
    // Stub
}

// lua_setfield (0x95xxxx) — Set table.field = value
void lua_setfield(lua_State *L, int idx, const char *k) {
    // Stub
}

// lua_getfield (0x95xxxx) — Get table.field, push value
void lua_getfield(lua_State *L, int idx, const char *k) {
    // Stub
}

// lua_setglobal (0x95xxxx) — Set global variable
void lua_setglobal(lua_State *L, const char *name) {
    // Stub
}

// lua_getglobal (0x95xxxx) — Get global variable
void lua_getglobal(lua_State *L, const char *name) {
    // Stub
}

// lua_rawget (0x95xxxx) — Raw get (no metamethods)
int lua_rawget(lua_State *L, int idx) {
    return LUA_TNIL; // Stub
}

// lua_rawset (0x95xxxx) — Raw set (no metamethods)
void lua_rawset(lua_State *L, int idx) {
    // Stub
}

// lua_rawgeti (0x95xxxx) — Raw get by integer index
int lua_rawgeti(lua_State *L, int idx, int n) {
    return LUA_TNIL; // Stub
}

// lua_rawseti (0x95xxxx) — Raw set by integer index
void lua_rawseti(lua_State *L, int idx, int n) {
    // Stub
}

// lua_settop (0x95xxxx) — Set stack top
void lua_settop(lua_State *L, int idx) {
    // Stub
}

// lua_gettop (0x95xxxx) — Get stack top index
int lua_gettop(lua_State *L) {
    return 0; // Stub
}

// lua_remove (0x95xxxx) — Remove element at index
void lua_remove(lua_State *L, int idx) {
    // Stub
}

// lua_insert (0x95xxxx) — Insert element at index
void lua_insert(lua_State *L, int idx) {
    // Stub
}

// lua_replace (0x95xxxx) — Replace element at index
void lua_replace(lua_State *L, int idx) {
    // Stub
}

// lua_pop (0x95xxxx) — Pop n elements
void lua_pop(lua_State *L, int n) {
    // Stub
}

// lua_newtable (0x95xxxx) — Create new table
void lua_newtable(lua_State *L) {
    // Stub
}

// lua_createtable (0x95xxxx) — Create table with preallocated slots
void lua_createtable(lua_State *L, int narr, int nrec) {
    // Stub
}

// lua_call (0x95xxxx) — Call function (unprotected)
void lua_call(lua_State *L, int nargs, int nresults) {
    // Stub
}

// lua_callk (0x95xxxx) — Call with continuation (yield-aware)
void lua_callk(lua_State *L, int nargs, int nresults, lua_KContext ctx,
               void *k) {
    // Stub
}

// lua_pcallk (0x95xxxx) — Protected call with continuation
int lua_pcallk(lua_State *L, int nargs, int nresults, int errfunc,
               lua_KContext ctx, void *k) {
    return LUA_OK; // Stub
}

// lua_error (0x95xxxx) — Raise Lua error
int lua_error(lua_State *L) {
    return LUA_ERRRUN; // Stub
}

// lua_next (0x95xxxx) — "invalid key to 'next'"
int lua_next(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_len (0x95xxxx) — Get length (# operator)
void lua_len(lua_State *L, int idx) {
    // Stub
}

// lua_concat (0x95xxxx) — Concatenate n values
void lua_concat(lua_State *L, int n) {
    // Stub
}

// lua_arith (0x95xxxx) — Arithmetic operation on stack values
void lua_arith(lua_State *L, int op) {
    // Stub
}

// lua_compare (0x95xxxx) — Compare two values
int lua_compare(lua_State *L, int idx1, int idx2, int op) {
    return 0; // Stub
}

// ============================================================================
// Lua AuxLib — luaL_* (~15 functions)
// ============================================================================

// luaL_newstate (0x95xxxx) — Create new state with default allocator
lua_State *luaL_newstate(void) {
    return nullptr; // Stub
}

// luaL_openlibs (0x95xxxx) — Open all standard libraries
void luaL_openlibs(lua_State *L) {
    // Stub
}

// luaL_checktype (0x95xxxx) — Check type, raise error on mismatch
void luaL_checktype(lua_State *L, int arg, int t) {
    // Stub
}

// luaL_checkinteger (0x95xxxx) — Get argument as integer
int luaL_checkinteger(lua_State *L, int arg) {
    return 0; // Stub
}

// luaL_checknumber (0x95xxxx) — Get argument as number
lua_Number luaL_checknumber(lua_State *L, int arg) {
    return 0.0; // Stub
}

// luaL_checklstring (0x95xxxx) — Get argument as string
const char *luaL_checklstring(lua_State *L, int arg, size_t *len) {
    return nullptr; // Stub
}

// luaL_optinteger (0x95xxxx) — Get optional integer argument
int luaL_optinteger(lua_State *L, int arg, int def) {
    return def; // Stub
}

// luaL_optnumber (0x95xxxx) — Get optional number argument
lua_Number luaL_optnumber(lua_State *L, int arg, lua_Number def) {
    return def; // Stub
}

// luaL_optlstring (0x95xxxx) — Get optional string argument
const char *luaL_optlstring(lua_State *L, int arg, const char *def, size_t *len) {
    return def; // Stub
}

// luaL_argerror (0x95xxxx) — Bad argument error
int luaL_argerror(lua_State *L, int numarg, const char *extramsg) {
    return 0; // Stub
}

// luaL_error (0x95xxxx) — Raise error with format
int luaL_error(lua_State *L, const char *fmt, ...) {
    return LUA_ERRRUN; // Stub
}

// luaL_loadstring (0x95xxxx) — Load a string as a Lua chunk
int luaL_loadstring(lua_State *L, const char *s) {
    return LUA_OK; // Stub
}

// luaL_loadfile (0x95xxxx) — Load a file as a Lua chunk
int luaL_loadfile(lua_State *L, const char *filename) {
    return LUA_OK; // Stub
}

// luaL_dofile (0x95xxxx) — Load and execute a file
int luaL_dofile(lua_State *L, const char *filename) {
    return LUA_OK; // Stub
}

// luaL_dostring (0x95xxxx) — Load and execute a string
int luaL_dostring(lua_State *L, const char *s) {
    return LUA_OK; // Stub
}

// luaL_ref (0x95xxxx) — Create reference in table
int luaL_ref(lua_State *L, int t) {
    return 0; // Stub
}

// luaL_unref (0x95xxxx) — Release reference
void luaL_unref(lua_State *L, int t, int ref) {
    // Stub
}

// luaL_newmetatable (0x95xxxx) — Create new metatable
int luaL_newmetatable(lua_State *L, const char *tname) {
    return 0; // Stub
}

// luaL_setmetatable (0x95xxxx) — Set metatable from registry
void luaL_setmetatable(lua_State *L, const char *tname) {
    // Stub
}

// luaL_getmetatable (0x95xxxx) — Get metatable from registry
void luaL_getmetatable(lua_State *L, const char *tname) {
    // Stub
}

// ============================================================================
// Lua Standard Libraries — luaopen_* (~8 functions)
// ============================================================================

// luaopen_base (0x95xxxx) — Open base library (print, type, pairs, etc.)
int luaopen_base(lua_State *L) {
    return 0; // Stub
}

// luaopen_table (0x95xxxx) — Open table library (concat, insert, remove, sort)
int luaopen_table(lua_State *L) {
    return 0; // Stub
}

// luaopen_string (0x95xxxx) — Open string library (sub, format, find, match, gsub)
int luaopen_string(lua_State *L) {
    return 0; // Stub
}

// luaopen_math (0x95xxxx) — Open math library (abs, sin, cos, sqrt, random, etc.)
int luaopen_math(lua_State *L) {
    return 0; // Stub
}

// luaopen_io (0x95xxxx) — Open I/O library (file operations)
int luaopen_io(lua_State *L) {
    return 0; // Stub
}

// luaopen_os (0x95xxxx) — Open OS library (clock, date, exit, execute)
int luaopen_os(lua_State *L) {
    return 0; // Stub
}

// luaopen_debug (0x95xxxx) — Open debug library
int luaopen_debug(lua_State *L) {
    return 0; // Stub
}

// luaopen_coroutine (0x95xxxx) — Open coroutine library
int luaopen_coroutine(lua_State *L) {
    return 0; // Stub
}

// ============================================================================
// Lua Internal — GC, Table, String (~10 functions)
// ============================================================================

// luaM_realloc_ (0x95xxxx) — Memory reallocation (lua_Alloc wrapper)
void *luaM_realloc_(lua_State *L, void *block, size_t osize, size_t nsize) {
    return nullptr; // Stub
}

// luaM_toobig (0x95xxxx) — "object too large" error
void luaM_toobig(lua_State *L) {
    // Stub
}

// luaS_newlstr (0x95xxxx) — Create short string (interning, hash Bob Jenkins)
void *luaS_newlstr(lua_State *L, const char *str, size_t l) {
    return nullptr; // Stub
}

// luaS_new (0x95xxxx) — Create string from null-terminated
void *luaS_new(lua_State *L, const char *str) {
    return nullptr; // Stub
}

// luaS_hash (0x95xxxx) — Bob Jenkins one-at-a-time hash
unsigned int luaS_hash(const char *str, size_t l, unsigned int seed) {
    return 0; // Stub
}

// luaH_new (0x95xxxx) — Create new table
Table *luaH_new(lua_State *L) {
    return nullptr; // Stub
}

// luaH_get (0x95xxxx) — Get value from table by key
const TValue *luaH_get(Table *t, const TValue *key) {
    return nullptr; // Stub
}

// luaH_set (0x95xxxx) — Set value in table
TValue *luaH_set(lua_State *L, Table *t, const TValue *key) {
    return nullptr; // Stub
}

// luaH_getint (0x95xxxx) — Get value by integer key (binary search)
const TValue *luaH_getint(Table *t, int key) {
    return nullptr; // Stub
}

// luaH_setint (0x95xxxx) — Set value by integer key
void luaH_setint(lua_State *L, Table *t, int key, TValue *value) {
    // Stub
}

// luaH_next (0x95xxxx) — Table traversal (next)
int luaH_next(lua_State *L, Table *t, TValue *key) {
    return 0; // Stub
}

// luaH_resizearray (0x95xxxx) — Resize array part of table
void luaH_resizearray(lua_State *L, Table *t, unsigned int size) {
    // Stub
}

// luaC_step (0x95xxxx) — Incremental GC step
void luaC_step(lua_State *L) {
    // Stub
}

// luaC_fullgc (0x95xxxx) — Run full GC cycle
void luaC_fullgc(lua_State *L) {
    // Stub
}

// luaC_barrier_ (0x95xxxx) — GC write barrier
void luaC_barrier_(lua_State *L, void *o, void *v) {
    // Stub
}

// luaC_barrierback_ (0x95xxxx) — GC back barrier
void luaC_barrierback_(lua_State *L, void *o) {
    // Stub
}

// luaC_checkGC (0x95xxxx) — Check and trigger GC if needed
void luaC_checkGC(lua_State *L) {
    // Stub
}

// ============================================================================
// Lua I/O — LuaIO_* (~5 functions)
// ============================================================================

// LuaIO_openStandardFiles (0x95xxxx) — Open stdin/stdout/stderr
void LuaIO_openStandardFiles(lua_State *L) {
    // Stub
}

// LuaIO_input (0x95xxxx) — Set/get input file
int LuaIO_input(lua_State *L) {
    return 0; // Stub
}

// LuaIO_output (0x95xxxx) — Set/get output file
int LuaIO_output(lua_State *L) {
    return 0; // Stub
}

// LuaIO_open (0x95xxxx) — Open file (fopen wrapper)
int LuaIO_open(lua_State *L) {
    return 0; // Stub
}

// LuaIO_close (0x95xxxx) — Close file
int LuaIO_close(lua_State *L) {
    return 0; // Stub
}

// LuaIO_read (0x95xxxx) — Read from file
int LuaIO_read(lua_State *L) {
    return 0; // Stub
}

// LuaIO_write (0x95xxxx) — Write to file
int LuaIO_write(lua_State *L) {
    return 0; // Stub
}

// LuaIO_seek (0x95xxxx) — Seek in file
int LuaIO_seek(lua_State *L) {
    return 0; // Stub
}

// ============================================================================
// Lua OS — LuaOS_* (~5 functions)
// ============================================================================

// LuaOS_clock (0x95xxxx) — os.clock()
int LuaOS_clock(lua_State *L) {
    return 0; // Stub
}

// LuaOS_exit (0x95xxxx) — os.exit()
int LuaOS_exit(lua_State *L) {
    return 0; // Stub
}

// LuaOS_execute (0x95xxxx) — os.execute()
int LuaOS_execute(lua_State *L) {
    return 0; // Stub
}

// LuaOS_date (0x95xxxx) — os.date()
int LuaOS_date(lua_State *L) {
    return 0; // Stub
}

// LuaOS_time (0x95xxxx) — os.time()
int LuaOS_time(lua_State *L) {
    return 0; // Stub
}

// LuaOS_difftime (0x95xxxx) — os.difftime()
int LuaOS_difftime(lua_State *L) {
    return 0; // Stub
}

// ============================================================================
// PhyreScripting Bridge — Phyre Lua integration (~10 functions)
// ============================================================================

// PushPhyreObject (0x95xxxx) — Push Phyre object onto Lua stack (3866 callers!)
void PushPhyreObject(lua_State *L, void *obj, void *typeDesc) {
    // Stub
}

// PushPhyrePropertyType (0x95xxxx) — Push typed property value
void PushPhyrePropertyType(lua_State *L, void *prop, void *ctx) {
    // Stub
}

// PushSlot (0x95xxxx) — Push value to stack slot (1664 callers)
void PushSlot(lua_State *L, int slot) {
    // Stub
}

// ReserveSlots (0x95xxxx) — Reserve N stack slots (1825 callers)
void ReserveSlots(lua_State *L, int n) {
    // Stub
}

// ResolveValue (0x95xxxx) — Resolve Lua value reference
void ResolveValue(lua_State *L, void *val) {
    // Stub
}

// ReadFloat (0x95xxxx) — Read float from Lua stack
float ReadFloat(lua_State *L, int idx) {
    return 0.0f; // Stub
}

// PScriptContext_SwapVar (0x95xxxx) — Swap variables in script context
void PScriptContext_SwapVar(lua_State *L, int a, int b) {
    // Stub
}

// PScriptContext_ThrowError (0x95xxxx) — Throw script error
void PScriptContext_ThrowError(lua_State *L, const char *msg) {
    // Stub
}

// PScriptContext_Control (0x95xxxx) — Script control flow
int PScriptContext_Control(lua_State *L, int op) {
    return 0; // Stub
}

// Type_IsNumeric (0x95xxxx) — Check if type is numeric
int Type_IsNumeric(int type) {
    return 0; // Stub
}

// Type_IsCallable (0x95xxxx) — Check if type is callable
int Type_IsCallable(int type) {
    return 0; // Stub
}

// PScriptContext_GetScriptObjectOfType (0x95xxxx) — Get script object by type
void *PScriptContext_GetScriptObjectOfType(lua_State *L, void *typeDesc) {
    return nullptr; // Stub
}

// PScriptContext_GetScriptObjectPointer (0x95xxxx) — Get raw pointer from script
void *PScriptContext_GetScriptObjectPointer(lua_State *L, int idx) {
    return nullptr; // Stub
}

// RegisterScriptingRuntime (0x95xxxx) — Register runtime with scripting system
void RegisterScriptingRuntime(lua_State *L, void *runtime) {
    // Stub
}

// RegisterPObjectAccessors (0x95xxxx) — Register PObject accessors for Lua
void RegisterPObjectAccessors(lua_State *L) {
    // Stub
}

// ============================================================================
// API Core — Stack Manipulation (stubs expandidos)
// ============================================================================

// lua_checkstack (0x95xxxx) — Ensure at least n extra slots
int lua_checkstack(lua_State *L, int n) {
    return 1; // Stub (success)
}

// lua_absindex (0x95xxxx) — Convert pseudo-index to absolute index
int lua_absindex(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_rotate (0x95xxxx) — Rotate stack elements between idx1 and idx2
void lua_rotate(lua_State *L, int idx, int n) {
    // Stub
}

// lua_copy (0x95xxxx) — Copy value at fromidx to toidx (replaces)
void lua_copy(lua_State *L, int fromidx, int toidx) {
    // Stub
}

// ============================================================================
// API Core — Tipo/Conversão (stubs expandidos)
// ============================================================================

// lua_tointegerx (0x95xxxx) — Get integer with isnum flag
int lua_tointegerx(lua_State *L, int idx, int *isnum) {
    if (isnum) *isnum = 0;
    return 0; // Stub
}

// lua_tonumberx (0x95xxxx) — Get number with isnum flag
lua_Number lua_tonumberx(lua_State *L, int idx, int *isnum) {
    if (isnum) *isnum = 0;
    return 0.0; // Stub
}

// lua_isinteger (0x95xxxx) — Check if value is integer
int lua_isinteger(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_rawequal (0x95xxxx) — Raw equality test (no metamethods)
int lua_rawequal(lua_State *L, int idx1, int idx2) {
    return 0; // Stub
}

// lua_lessthan (0x95xxxx) — Less-than comparison
int lua_lessthan(lua_State *L, int idx1, int idx2) {
    return 0; // Stub
}

// lua_equal (0x95xxxx) — Equality comparison
int lua_equal(lua_State *L, int idx1, int idx2) {
    return 0; // Stub
}

// lua_stringtonumber (0x95xxxx) — Convert string to number, push it
size_t lua_stringtonumber(lua_State *L, const char *s) {
    return 0; // Stub
}

// lua_iscfunction (0x95xxxx) — Check if value is C function
int lua_iscfunction(lua_State *L, int idx) {
    return 0; // Stub
}

// lua_islightuserdata (0x95xxxx) — Check if value is light userdata
int lua_islightuserdata(lua_State *L, int idx) {
    return 0; // Stub
}

// ============================================================================
// API Core — Push (stubs expandidos)
// ============================================================================

// lua_pushfstring (0x95xxxx) — Push formatted string (vararg)
const char *lua_pushfstring(lua_State *L, const char *fmt, ...) {
    return nullptr; // Stub
}

// lua_pushvfstring (0x95xxxx) — Push formatted string (va_list)
const char *lua_pushvfstring(lua_State *L, const char *fmt, va_list argp) {
    return nullptr; // Stub
}

// lua_pushcclosure (0x95xxxx) — Push C closure with upvalues
void lua_pushcclosure(lua_State *L, lua_CFunction fn, int n) {
    // Stub
}

// lua_pushglobaltable (0x95xxxx) — Push global table
void lua_pushglobaltable(lua_State *L) {
    // Stub
}

// ============================================================================
// API Core — Raw Access (stubs expandidos)
// ============================================================================

// lua_rawgetp (0x95xxxx) — Raw get by pointer key
int lua_rawgetp(lua_State *L, int idx, const void *p) {
    return LUA_TNIL; // Stub
}

// lua_rawsetp (0x95xxxx) — Raw set by pointer key
void lua_rawsetp(lua_State *L, int idx, const void *p) {
    // Stub
}

// lua_geti (0x95xxxx) — Get t[n], push value
int lua_geti(lua_State *L, int idx, int n) {
    return LUA_TNIL; // Stub
}

// lua_seti (0x95xxxx) — Set t[n] = value (pop value)
void lua_seti(lua_State *L, int idx, int n) {
    // Stub
}

// ============================================================================
// API Core — Funções (stubs expandidos)
// ============================================================================

// lua_cpcall (0x95xxxx) — Protected call with C function
int lua_cpcall(lua_State *L, lua_CFunction func, void *ud) {
    return LUA_OK; // Stub
}

// lua_dump (0x95xxxx) — Dump function to writer
int lua_dump(lua_State *L, lua_Writer writer, void *data) {
    return LUA_OK; // Stub
}

// ============================================================================
// API Core — Corrotina (stubs expandidos)
// ============================================================================

// lua_yieldk (0x95xxxx) — Yield with continuation
int lua_yieldk(lua_State *L, int nresults, lua_KContext ctx, void *k) {
    return LUA_YIELD; // Stub
}

// lua_isyieldable (0x95xxxx) — Check if current thread can yield
int lua_isyieldable(lua_State *L) {
    return 0; // Stub
}

// lua_costatus (0x95xxxx) — Get coroutine status
int lua_costatus(lua_State *L, lua_State *co) {
    return LUA_OK; // Stub
}

// ============================================================================
// API Core — Tabela de Referência (stubs expandidos)
// ============================================================================

// lua_ref (0x95xxxx) — Create reference (LUA_REGISTRYINDEX)
int lua_ref(lua_State *L, int lock) {
    return 0; // Stub
}

// lua_unref (0x95xxxx) — Release reference
void lua_unref(lua_State *L, int ref) {
    // Stub
}

// lua_getref (0x95xxxx) — Push referenced value
void lua_getref(lua_State *L, int ref) {
    // Stub
}

// ============================================================================
// API Core — Utilitários (stubs expandidos)
// ============================================================================

// lua_gc (0x95xxxx) — GC control (what, data)
int lua_gc(lua_State *L, int what, int data) {
    return 0; // Stub
}

// lua_getallocf (0x95xxxx) — Get allocator function
lua_Alloc lua_getallocf(lua_State *L, void **ud) {
    return nullptr; // Stub
}

// lua_setallocf (0x95xxxx) — Set allocator function
void lua_setallocf(lua_State *L, lua_Alloc f, void *ud) {
    // Stub
}

// lua_atpanic (0x95xxxx) — Set panic function
lua_CFunction lua_atpanic(lua_State *L, lua_CFunction panicf) {
    return nullptr; // Stub
}

// lua_version (0x95xxxx) — Return version number
int lua_version(lua_State *L) {
    return 502; // Stub (Lua 5.2.1)
}

// lua_upvalueindex (0x95xxxx) — Pseudo-index for upvalue i
int lua_upvalueindex(int i) {
    return -10000 - i; // Stub
}

// ============================================================================
// AuxLib — luaL_* (stubs expandidos)
// ============================================================================

// luaL_getmetafield (0x95xxxx) — Get metatable field
int luaL_getmetafield(lua_State *L, int obj, const char *e) {
    return 0; // Stub
}

// luaL_callmeta (0x95xxxx) — Call metatable metamethod
int luaL_callmeta(lua_State *L, int obj, const char *e) {
    return 0; // Stub
}

// luaL_loadfilex (0x95xxxx) — Load file with mode
int luaL_loadfilex(lua_State *L, const char *filename, const char *mode) {
    return LUA_OK; // Stub
}

// luaL_loadbufferx (0x95xxxx) — Load buffer with mode
int luaL_loadbufferx(lua_State *L, const char *buff, size_t sz,
                     const char *name, const char *mode) {
    return LUA_OK; // Stub
}

// luaL_checkudata (0x95xxxx) — Check userdata type
void *luaL_checkudata(lua_State *L, int arg, const char *tname) {
    return nullptr; // Stub
}

// luaL_checkstack (0x95xxxx) — Check/expand stack in AuxLib
void luaL_checkstack(lua_State *L, int sz, const char *msg) {
    // Stub
}

// luaL_argcheck (0x95xxxx) — Check condition, raise arg error
void luaL_argcheck(lua_State *L, int cond, int arg, const char *extramsg) {
    if (!cond) { /* would raise error */ }
}

// luaL_fileresult (0x95xxxx) — File operation result (status + errno)
int luaL_fileresult(lua_State *L, int stat, const char *fname) {
    return stat; // Stub
}

// luaL_execresult (0x95xxxx) — Execute result (exit code → status)
int luaL_execresult(lua_State *L, int stat) {
    return 0; // Stub
}

// luaL_checkoption (0x95xxxx) — Check option argument
int luaL_checkoption(lua_State *L, int arg, const char *def, const char *const lst[]) {
    return 0; // Stub
}

// luaL_checkany (0x95xxxx) — Check that arg is not nil/none
void luaL_checkany(lua_State *L, int arg) {
    // Stub
}

// luaL_setfuncs (0x95xxxx) — Set table functions from array
void luaL_setfuncs(lua_State *L, const void *lreg, int nup) {
    // Stub
}

// luaL_newlib (0x95xxxx) — Create table and register functions
void luaL_newlib(lua_State *L, const void *lreg) {
    // Stub
}

// luaL_testudata (0x95xxxx) — Test userdata type (no error)
void *luaL_testudata(lua_State *L, int arg, const char *tname) {
    return nullptr; // Stub
}

// luaL_traceback (0x95xxxx) — Build traceback string
void luaL_traceback(lua_State *L, lua_State *L1, const char *msg, int level) {
    // Stub
}

// luaL_where (0x95xxxx) — Push location string (file:line:)
void luaL_where(lua_State *L, int level) {
    // Stub
}

// luaL_len (0x95xxxx) — Get length (raises on error)
int luaL_len(lua_State *L, int idx) {
    return 0; // Stub
}

// luaL_getsubtable (0x95xxxx) — Get/create subtable in table
int luaL_getsubtable(lua_State *L, int idx, const char *fname) {
    return 0; // Stub
}

// luaL_requiref (0x95xxxx) — Load module with C function
void luaL_requiref(lua_State *L, const char *modname,
                   lua_CFunction openf, int glb) {
    // Stub
}

// ============================================================================
// AuxLib — Buffer system (stubs expandidos)
// ============================================================================

struct luaL_Buffer {
    lua_State *L;
    char *b;
    size_t size;
    size_t n;
};

// luaL_buffinit (0x95xxxx) — Initialize string buffer
void luaL_buffinit(lua_State *L, luaL_Buffer *B) {
    // Stub
}

// luaL_prepbuffsize (0x95xxxx) — Prepare buffer for size bytes
char *luaL_prepbuffsize(luaL_Buffer *B, size_t sz) {
    return nullptr; // Stub
}

// luaL_addlstring (0x95xxxx) — Add counted string to buffer
void luaL_addlstring(luaL_Buffer *B, const char *s, size_t l) {
    // Stub
}

// luaL_addstring (0x95xxxx) — Add null-terminated string to buffer
void luaL_addstring(luaL_Buffer *B, const char *s) {
    // Stub
}

// luaL_addvalue (0x95xxxx) — Add top-of-stack value to buffer
void luaL_addvalue(luaL_Buffer *B) {
    // Stub
}

// luaL_pushresult (0x95xxxx) — Finalize buffer and push result
void luaL_pushresult(luaL_Buffer *B) {
    // Stub
}

// luaL_buffinitsize (0x95xxxx) — Init buffer with prealloc size
void luaL_buffinitsize(lua_State *L, luaL_Buffer *B, size_t sz) {
    // Stub
}

// ============================================================================
// Lua Internals — Table (stubs expandidos)
// ============================================================================

// luaH_getstr (0x95xxxx) — Get string key from table
const TValue *luaH_getstr(Table *t, void *key) {
    return nullptr; // Stub
}

// luaH_setstr (0x95xxxx) — Set string key in table
TValue *luaH_setstr(lua_State *L, Table *t, void *key) {
    return nullptr; // Stub
}

// luaH_getn (0x95xxxx) — Get table length (#t)
int luaH_getn(Table *t) {
    return 0; // Stub
}

// luaH_pack (0x95xxxx) — Pack array part of table
void luaH_pack(lua_State *L, Table *t) {
    // Stub
}

// luaH_unpack (0x95xxxx) — Unpack array part of table
int luaH_unpack(lua_State *L, Table *t, int n) {
    return 0; // Stub
}

// luaH_real (0x95xxxx) — Get real array size (last non-nil)
unsigned int luaH_real(Table *t) {
    return 0; // Stub
}

// ============================================================================
// Lua Internals — String (stubs expandidos)
// ============================================================================

// luaS_newliteral (0x95xxxx) — Create string from literal (macro)
void *luaS_newliteral(lua_State *L, const char *s) {
    return nullptr; // Stub
}

// luaS_newudata (0x95xxxx) — Create new userdata (with gc)
void *luaS_newudata(lua_State *L, size_t size) {
    return nullptr; // Stub
}

// luaS_resize (0x95xxxx) — Resize string hash table
void luaS_resize(lua_State *L, int newsize) {
    // Stub
}

// luaS_remove (0x95xxxx) — Remove dead string from hash
void luaS_remove(lua_State *L, void *str) {
    // Stub
}

// ============================================================================
// Lua Internals — Memory (stubs expandidos)
// ============================================================================

// luaM_new (0x95xxxx) — Allocate new typed object (macro stub)
void *luaM_new(lua_State *L, size_t size) {
    return nullptr; // Stub
}

// luaM_newvector (0x95xxxx) — Allocate new typed vector
void *luaM_newvector(lua_State *L, int n, size_t elemsize) {
    return nullptr; // Stub
}

// luaM_growvector (0x95xxxx) — Grow typed vector
void *luaM_growvector(lua_State *L, void *v, int *nelems, int max,
                      size_t elemsize, const char *errormsg) {
    return nullptr; // Stub
}

// luaM_freearray (0x95xxxx) — Free typed array
void luaM_freearray(lua_State *L, void *v, size_t size) {
    // Stub
}

// luaM_reallocvector (0x95xxxx) — Realloc typed vector (macro stub)
void *luaM_reallocvector(lua_State *L, void *v, size_t oldn, size_t newn,
                         size_t elemsize) {
    return nullptr; // Stub
}

// ============================================================================
// Lua Internals — Debug (stubs expandidos)
// ============================================================================

// luaG_addinfo (0x95xxxx) — Add source line info to error message
const char *luaG_addinfo(lua_State *L, const char *msg, const char *src, int line) {
    return msg; // Stub
}

// luaG_errormsg (0x95xxxx) — Process and send error message
int luaG_errormsg(lua_State *L) {
    return LUA_ERRRUN; // Stub
}

// luaG_checkopenop (0x95xxxx) — Check open operation at PC
void luaG_checkopenop(lua_State *L, int pc) {
    // Stub
}

// ============================================================================
// Lua Internals — Call/Dispatch (stubs expandidos)
// ============================================================================

// luaD_call (0x95xxxx) — Call a function (internal, no try)
void luaD_call(lua_State *L, void *func, int nresults) {
    // Stub
}

// luaD_pcall (0x95xxxx) — Protected call (internal)
int luaD_pcall(lua_State *L, void *func, void *ud,
               ptrdiff_t old_top, ptrdiff_t ef) {
    return LUA_OK; // Stub
}

// luaD_protectedparser (0x95xxxx) — Protected parse
int luaD_protectedparser(lua_State *L, void *z, const char *name) {
    return LUA_OK; // Stub
}

// luaD_rawrunprotected (0x95xxxx) — Run function with raw protection
int luaD_rawrunprotected(lua_State *L, void *f, void *ud) {
    return LUA_OK; // Stub
}

// luaD_throw (0x95xxxx) — Throw Lua error (longjmp)
void luaD_throw(lua_State *L, int errcode) {
    // Stub (longjmp equivalent)
}

// ============================================================================
// Lua Internals — Function Proto/Closure (stubs expandidos)
// ============================================================================

// luaF_newproto (0x95xxxx) — Create new function prototype
Proto *luaF_newproto(lua_State *L) {
    return nullptr; // Stub
}

// luaF_newLclosure (0x95xxxx) — Create new Lua closure
void *luaF_newLclosure(lua_State *L, int nelems) {
    return nullptr; // Stub
}

// luaF_newCclosure (0x95xxxx) — Create new C closure
void *luaF_newCclosure(lua_State *L, int nelems) {
    return nullptr; // Stub
}

// luaF_findupval (0x95xxxx) — Find or create upvalue
UpVal *luaF_findupval(lua_State *L, void *level) {
    return nullptr; // Stub
}

// luaF_close (0x95xxxx) — Close upvalues for open slots
void luaF_close(lua_State *L, void *level) {
    // Stub
}

// luaF_freeupvals (0x95xxxx) — Free upvalue list
void luaF_freeupvals(lua_State *L, UpVal *uv) {
    // Stub
}

// luaF_getlocalname (0x95xxxx) — Get local variable name
const char *luaF_getlocalname(const Proto *p, int local, int pc) {
    return nullptr; // Stub
}

// luaF_initlocalvars (0x95xxxx) — Initialize local variables in proto
void luaF_initlocalvars(lua_State *L, Proto *p) {
    // Stub
}

// luaF_fixup (0x95xxxx) — Fix upvalue references after proto is closed
void luaF_fixup(lua_State *L, Proto *p) {
    // Stub
}

// ============================================================================
// Extra: CodeGen + Parser stubs complementares
// ============================================================================

// luaK_dischargevars (0x95xxxx) — Discharge variables to registers
void luaK_dischargevars(void *funcstate, void *expdesc) {
    // Stub
}

// luaK_indexed (0x95xxxx) — Indexed expression (t[k])
void luaK_indexed(void *funcstate, void *t, void *k) {
    // Stub
}

// luaK_self (0x95xxxx) — Emit SELF instruction (obj:method)
void luaK_self(void *funcstate, void *e, void *key) {
    // Stub
}

// luaK_storevar (0x95xxxx) — Store value to variable
void luaK_storevar(void *funcstate, void *var, void *exp) {
    // Stub
}

// luaK_goiftrue (0x95xxxx) — Emit jump-if-true
void luaK_goiftrue(void *funcstate, void *e) {
    // Stub
}

// luaK_goiffalse (0x95xxxx) — Emit jump-if-false
void luaK_goiffalse(void *funcstate, void *e) {
    // Stub
}

// luaK_jump (0x95xxxx) — Emit unconditional jump, return patch pc
int luaK_jump(void *funcstate) {
    return 0; // Stub
}

// luaK_label (0x95xxxx) — Define label at current position
void luaK_label(void *funcstate, int pc) {
    // Stub
}

// luaK_fixline (0x95xxxx) — Associate line number with last instruction
void luaK_fixline(void *funcstate, int line) {
    // Stub
}

// luaK_setlist (0x95xxxx) — Emit SETLIST instruction
void luaK_setlist(void *funcstate, int base, int nelems, int tostore) {
    // Stub
}

// luaK_infix (0x95xxxx) — Prepare left operand for binary op
void luaK_infix(void *funcstate, int op, void *e) {
    // Stub
}

// luaK_posfix (0x95xxxx) — Emit code for binary op with both operands
void luaK_posfix(void *funcstate, int op, void *e1, void *e2) {
    // Stub
}

// luaK_prefix (0x95xxxx) — Emit code for unary op
void luaK_prefix(void *funcstate, int op, void *e) {
    // Stub
}

// ============================================================================
// Extra: CodeGen constant management (stubs complementares)
// ============================================================================

// luaK_const (0x95xxxx) — Add constant to function, return index
int luaK_const(void *funcstate, const void *value) {
    return 0; // Stub
}

// luaK_isKint (0x95xxxx) — Check if expression is constant integer
int luaK_isKint(void *expdesc) {
    return 0; // Stub
}

// ============================================================================
// Extra: Parser utilities (stubs complementares)
// ============================================================================

// luaY_checklimit (0x95xxxx) — Check parser limit
void luaY_checklimit(void *fs, int v, int l, const char *what) {
    // Stub
}

// luaY_pushlocal (0x95xxxx) — Push local variable
void luaY_pushlocal(lua_State *L, void *lexstate, const char *name, int pc) {
    // Stub
}

// luaY_findlocal (0x95xxxx) — Find register for local variable
int luaY_findlocal(void *lexstate, const char *name) {
    return -1; // Stub
}

// ============================================================================
// Extra: Lexer (luaX_*) — Token scanning (stubs complementares)
// ============================================================================

// luaX_newlexstate (0x95xxxx) — Create new lexer state
void *luaX_newlexstate(lua_State *L, lua_Reader reader, void *data) {
    return nullptr; // Stub
}

// luaX_next (0x95xxxx) — Advance to next token
void luaX_next(void *lexstate) {
    // Stub
}

// luaX_lookahead (0x95xxxx) — Peek at next token
int luaX_lookahead(void *lexstate) {
    return 0; // Stub
}

// luaX_token2str (0x95xxxx) — Convert token to string
const char *luaX_token2str(void *lexstate, int token) {
    return "unknown"; // Stub
}

// luaX_lexerror (0x95xxxx) — Lexical error
void luaX_lexerror(void *lexstate, const char *msg, int token) {
    // Stub
}

// luaX_syntaxerror (0x95xxxx) — Syntax error
void luaX_syntaxerror(void *lexstate, const char *msg) {
    // Stub
}

// luaX_setinput (0x95xxxx) — Set lexer input source
void luaX_setinput(lua_State *L, void *lexstate, lua_Reader reader,
                   void *data, const char *name) {
    // Stub
}

// ============================================================================
// Extra: Undump / Loader (luaU_*) (stubs complementares)
// ============================================================================

// luaU_undump (0x95xxxx) — Undump (load) precompiled bytecode
Proto *luaU_undump(lua_State *L, void *z, const char *name) {
    return nullptr; // Stub
}

// luaU_dump (0x95xxxx) — Dump (save) precompiled bytecode
int luaU_dump(lua_State *L, const Proto *f, lua_Writer w, void *data,
              int strip) {
    return LUA_OK; // Stub
}

// ============================================================================
// Extra: ZIO — Buffered I/O for loader (stubs complementares)
// ============================================================================

struct ZIO;

// luaZ_fill (0x95xxxx) — Fill read buffer
int luaZ_fill(void *z) {
    return 0; // Stub
}

// luaZ_init (0x95xxxx) — Initialize ZIO state
void luaZ_init(lua_State *L, void *z, lua_Reader reader, void *data) {
    // Stub
}

// luaZ_read (0x95xxxx) — Read n bytes from ZIO
size_t luaZ_read(void *z, void *b, size_t n) {
    return 0; // Stub
}

// ============================================================================
// Extra: Math library stubs complementares
// ============================================================================

// math_abs (0x95xxxx) — math.abs()
int math_abs(lua_State *L) { return 0; }

// math_sin (0x95xxxx) — math.sin()
int math_sin(lua_State *L) { return 0; }

// math_cos (0x95xxxx) — math.cos()
int math_cos(lua_State *L) { return 0; }

// math_sqrt (0x95xxxx) — math.sqrt()
int math_sqrt(lua_State *L) { return 0; }

// math_floor (0x95xxxx) — math.floor()
int math_floor(lua_State *L) { return 0; }

// math_ceil (0x95xxxx) — math.ceil()
int math_ceil(lua_State *L) { return 0; }

// math_pow (0x95xxxx) — math.pow()
int math_pow(lua_State *L) { return 0; }

// math_random (0x95xxxx) — math.random()
int math_random(lua_State *L) { return 0; }

// math_randomseed (0x95xxxx) — math.randomseed()
int math_randomseed(lua_State *L) { return 0; }

// math_min (0x95xxxx) — math.min()
int math_min(lua_State *L) { return 0; }

// math_max (0x95xxxx) — math.max()
int math_max(lua_State *L) { return 0; }

// math_log (0x95xxxx) — math.log()
int math_log(lua_State *L) { return 0; }

// math_exp (0x95xxxx) — math.exp()
int math_exp(lua_State *L) { return 0; }

// math_deg (0x95xxxx) — math.deg()
int math_deg(lua_State *L) { return 0; }

// math_rad (0x95xxxx) — math.rad()
int math_rad(lua_State *L) { return 0; }

// ============================================================================
// Extra: String library stubs complementares
// ============================================================================

// string_len (0x95xxxx) — string.len()
int string_len(lua_State *L) { return 0; }

// string_sub (0x95xxxx) — string.sub()
int string_sub(lua_State *L) { return 0; }

// string_rep (0x95xxxx) — string.rep()
int string_rep(lua_State *L) { return 0; }

// string_reverse (0x95xxxx) — string.reverse()
int string_reverse(lua_State *L) { return 0; }

// string_lower (0x95xxxx) — string.lower()
int string_lower(lua_State *L) { return 0; }

// string_upper (0x95xxxx) — string.upper()
int string_upper(lua_State *L) { return 0; }

// string_byte (0x95xxxx) — string.byte()
int string_byte(lua_State *L) { return 0; }

// string_char (0x95xxxx) — string.char()
int string_char(lua_State *L) { return 0; }

// string_format (0x95xxxx) — string.format()
int string_format(lua_State *L) { return 0; }

// string_find (0x95xxxx) — string.find()
int string_find(lua_State *L) { return 0; }

// string_match (0x95xxxx) — string.match()
int string_match(lua_State *L) { return 0; }

// string_gsub (0x95xxxx) — string.gsub()
int string_gsub(lua_State *L) { return 0; }

// string_gmatch (0x95xxxx) — string.gmatch()
int string_gmatch(lua_State *L) { return 0; }

// ============================================================================
// Extra: Table library stubs complementares
// ============================================================================

// table_concat (0x95xxxx) — table.concat()
int table_concat(lua_State *L) { return 0; }

// table_insert (0x95xxxx) — table.insert()
int table_insert(lua_State *L) { return 0; }

// table_remove (0x95xxxx) — table.remove()
int table_remove(lua_State *L) { return 0; }

// table_sort (0x95xxxx) — table.sort()
int table_sort(lua_State *L) { return 0; }

// table_pack (0x95xxxx) — table.pack()
int table_pack(lua_State *L) { return 0; }

// table_unpack (0x95xxxx) — table.unpack()
int table_unpack(lua_State *L) { return 0; }

// ============================================================================
// Extra: Coroutine library stubs complementares
// ============================================================================

// coroutine_create (0x95xxxx) — coroutine.create()
int coroutine_create(lua_State *L) { return 0; }

// coroutine_resume (0x95xxxx) — coroutine.resume()
int coroutine_resume(lua_State *L) { return 0; }

// coroutine_yield (0x95xxxx) — coroutine.yield()
int coroutine_yield(lua_State *L) { return 0; }

// coroutine_status (0x95xxxx) — coroutine.status()
int coroutine_status(lua_State *L) { return 0; }

// coroutine_wrap (0x95xxxx) — coroutine.wrap()
int coroutine_wrap(lua_State *L) { return 0; }

// coroutine_running (0x95xxxx) — coroutine.running()
int coroutine_running(lua_State *L) { return 0; }

// ============================================================================
// Extra: Base library stubs complementares
// ============================================================================

// base_print (0x95xxxx) — Standard print()
int base_print(lua_State *L) { return 0; }

// base_type (0x95xxxx) — Standard type()
int base_type(lua_State *L) { return 0; }

// base_pairs (0x95xxxx) — Standard pairs()
int base_pairs(lua_State *L) { return 0; }

// base_ipairs (0x95xxxx) — Standard ipairs()
int base_ipairs(lua_State *L) { return 0; }

// base_next (0x95xxxx) — Standard next()
int base_next(lua_State *L) { return 0; }

// base_assert (0x95xxxx) — Standard assert()
int base_assert(lua_State *L) { return 0; }

// base_select (0x95xxxx) — Standard select()
int base_select(lua_State *L) { return 0; }

// base_tostring (0x95xxxx) — Standard tostring()
int base_tostring(lua_State *L) { return 0; }

// base_tonumber (0x95xxxx) — Standard tonumber()
int base_tonumber(lua_State *L) { return 0; }

// base_error (0x95xxxx) — Standard error()
int base_error(lua_State *L) { return 0; }

// base_pcall (0x95xxxx) — Standard pcall()
int base_pcall(lua_State *L) { return 0; }

// base_xpcall (0x95xxxx) — Standard xpcall()
int base_xpcall(lua_State *L) { return 0; }

// base_rawget (0x95xxxx) — Standard rawget()
int base_rawget(lua_State *L) { return 0; }

// base_rawset (0x95xxxx) — Standard rawset()
int base_rawset(lua_State *L) { return 0; }

// base_rawlen (0x95xxxx) — Standard rawlen()
int base_rawlen(lua_State *L) { return 0; }

// base_rawequal (0x95xxxx) — Standard rawequal()
int base_rawequal(lua_State *L) { return 0; }

// base_setmetatable (0x95xxxx) — Standard setmetatable()
int base_setmetatable(lua_State *L) { return 0; }

// base_getmetatable (0x95xxxx) — Standard getmetatable()
int base_getmetatable(lua_State *L) { return 0; }

// base_collectgarbage (0x95xxxx) — Standard collectgarbage()
int base_collectgarbage(lua_State *L) { return 0; }

// base_load (0x95xxxx) — Standard load()
int base_load(lua_State *L) { return 0; }

// base_dofile (0x95xxxx) — Standard dofile()
int base_dofile(lua_State *L) { return 0; }

// base_pcall_x (0x95xxxx) — Extended pcall variant
int base_pcall_x(lua_State *L) { return 0; }

// ============================================================================
// Extra: Debug library stubs complementares
// ============================================================================

// debug_debug (0x95xxxx) — debug.debug()
int debug_debug(lua_State *L) { return 0; }

// debug_getuservalue (0x95xxxx) — debug.getuservalue()
int debug_getuservalue(lua_State *L) { return 0; }

// debug_setuservalue (0x95xxxx) — debug.setuservalue()
int debug_setuservalue(lua_State *L) { return 0; }

// debug_getregistry (0x95xxxx) — debug.getregistry()
int debug_getregistry(lua_State *L) { return 0; }

// debug_getmetatable (0x95xxxx) — debug.getmetatable()
int debug_getmetatable(lua_State *L) { return 0; }

// debug_setmetatable (0x95xxxx) — debug.setmetatable()
int debug_setmetatable(lua_State *L) { return 0; }

// debug_getinfo (0x95xxxx) — debug.getinfo()
int debug_getinfo(lua_State *L) { return 0; }

// debug_getlocal (0x95xxxx) — debug.getlocal()
int debug_getlocal(lua_State *L) { return 0; }

// debug_setlocal (0x95xxxx) — debug.setlocal()
int debug_setlocal(lua_State *L) { return 0; }

// debug_getupvalue (0x95xxxx) — debug.getupvalue()
int debug_getupvalue(lua_State *L) { return 0; }

// debug_setupvalue (0x95xxxx) — debug.setupvalue()
int debug_setupvalue(lua_State *L) { return 0; }

// debug_upvalueid (0x95xxxx) — debug.upvalueid()
int debug_upvalueid(lua_State *L) { return 0; }

// debug_upvaluejoin (0x95xxxx) — debug.upvaluejoin()
int debug_upvaluejoin(lua_State *L) { return 0; }

// debug_sethook (0x95xxxx) — debug.sethook()
int debug_sethook(lua_State *L) { return 0; }

// debug_gethook (0x95xxxx) — debug.gethook()
int debug_gethook(lua_State *L) { return 0; }

// debug_getfenv (0x95xxxx) — debug.getfenv()
int debug_getfenv(lua_State *L) { return 0; }

// debug_setfenv (0x95xxxx) — debug.setfenv()
int debug_setfenv(lua_State *L) { return 0; }

// debug_traceback (0x95xxxx) — debug.traceback()
int debug_traceback(lua_State *L) { return 0; }

// ============================================================================
// Extra: I/O library stubs complementares
// ============================================================================

// io_open (0x95xxxx) — io.open()
int io_open(lua_State *L) { return 0; }

// io_popen (0x95xxxx) — io.popen() (may be disabled in sandbox)
int io_popen(lua_State *L) { return 0; }

// io_tmpfile (0x95xxxx) — io.tmpfile()
int io_tmpfile(lua_State *L) { return 0; }

// io_close (0x95xxxx) — io.close()
int io_close(lua_State *L) { return 0; }

// io_read (0x95xxxx) — io.read()
int io_read(lua_State *L) { return 0; }

// io_write (0x95xxxx) — io.write()
int io_write(lua_State *L) { return 0; }

// io_lines (0x95xxxx) — io.lines()
int io_lines(lua_State *L) { return 0; }

// io_input (0x95xxxx) — io.input()
int io_input(lua_State *L) { return 0; }

// io_output (0x95xxxx) — io.output()
int io_output(lua_State *L) { return 0; }

// io_type (0x95xxxx) — io.type()
int io_type(lua_State *L) { return 0; }

// io_flush (0x95xxxx) — io.flush()
int io_flush(lua_State *L) { return 0; }

// ============================================================================
// Extra: OS library stubs complementares
// ============================================================================

// os_clock (0x95xxxx) — os.clock()
int os_clock(lua_State *L) { return 0; }

// os_date (0x95xxxx) — os.date()
int os_date(lua_State *L) { return 0; }

// os_time (0x95xxxx) — os.time()
int os_time(lua_State *L) { return 0; }

// os_difftime (0x95xxxx) — os.difftime()
int os_difftime(lua_State *L) { return 0; }

// os_exit (0x95xxxx) — os.exit()
int os_exit(lua_State *L) { return 0; }

// os_execute (0x95xxxx) — os.execute()
int os_execute(lua_State *L) { return 0; }

// os_tmpname (0x95xxxx) — os.tmpname()
int os_tmpname(lua_State *L) { return 0; }

// os_rename (0x95xxxx) — os.rename()
int os_rename(lua_State *L) { return 0; }

// os_remove (0x95xxxx) — os.remove()
int os_remove(lua_State *L) { return 0; }

// os_setlocale (0x95xxxx) — os.setlocale()
int os_setlocale(lua_State *L) { return 0; }

// ============================================================================
// Extra: PhyreScripting bridge stubs complementares
// ============================================================================

// PhyreScript_pcall (0x95xxxx) — Phyre wrapped pcall
int PhyreScript_pcall(lua_State *L, int nargs, int nresults) {
    return LUA_OK; // Stub
}

// PhyreScript_load (0x95xxxx) — Load Phyre script bundle
int PhyreScript_load(lua_State *L, const char *script) {
    return LUA_OK; // Stub
}

// PhyreScript_collect (0x95xxxx) — Force Phyre-side GC collection
void PhyreScript_collect(lua_State *L) {
    // Stub
}

// PhyreScript_trace (0x95xxxx) — Enable/disable tracing
void PhyreScript_trace(lua_State *L, int enable) {
    // Stub
}

// GetObjectType (0x95xxxx) — Get Phyre object type name
const char *GetObjectType(void *obj) {
    return "PhyreObject"; // Stub
}

// ResolveProperty (0x95xxxx) — Resolve property by name
void *ResolveProperty(lua_State *L, void *obj, const char *prop) {
    return nullptr; // Stub
}

// EnumerateProperties (0x95xxxx) — Enumerate object properties
int EnumerateProperties(lua_State *L, void *obj) {
    return 0; // Stub
}

// CallMethod (0x95xxxx) — Call method on Phyre object
int CallMethod(lua_State *L, void *obj, const char *method) {
    return 0; // Stub
}

// BindScriptObject (0x95xxxx) — Bind Lua table to Phyre object
void BindScriptObject(lua_State *L, void *obj) {
    // Stub
}

// UnbindScriptObject (0x95xxxx) — Unbind Lua table from Phyre object
void UnbindScriptObject(lua_State *L, void *obj) {
    // Stub
}

// ============================================================================
// Extra: GC auxiliar — collect step variants (stubs complementares)
// ============================================================================

// luaC_step_count (0x95xxxx) — GC step with counter
void luaC_step_count(lua_State *L, int count) {
    // Stub
}

// luaC_barriert (0x95xxxx) — GC barrier for table
void luaC_barriert(lua_State *L, Table *t, void *v) {
    // Stub
}

// luaC_barrierf (0x95xxxx) — GC barrier for fixed object
void luaC_barrierf(lua_State *L, void *o, void *v) {
    // Stub
}

// luaC_upvalbarrier (0x95xxxx) — GC barrier for upvalue
void luaC_upvalbarrier(lua_State *L, UpVal *uv) {
    // Stub
}

// luaC_separateudata (0x95xxxx) — Separate userdata for GC finalization
void luaC_separateudata(lua_State *L) {
    // Stub
}

// ============================================================================
// Extra: CallInfo / Stack management (stubs complementares)
// ============================================================================

// luaD_reallocCI (0x95xxxx) — Reallocate CallInfo array
void luaD_reallocCI(lua_State *L, int newsize) {
    // Stub
}

// luaD_growstack (0x95xxxx) — Grow stack to n
void luaD_growstack(lua_State *L, int n) {
    // Stub
}

// luaD_reallocstack (0x95xxxx) — Reallocate stack
void luaD_reallocstack(lua_State *L, int newsize) {
    // Stub
}

// luaD_seterrorobj (0x95xxxx) — Set error object on stack
void luaD_seterrorobj(lua_State *L, int errcode, void *old_top) {
    // Stub
}

// ============================================================================
// Extra: String formatting / vsprintf wrapper (stubs complementares)
// ============================================================================

// luaO_pushfstring (0x95xxxx) — Format and push string (vararg)
const char *luaO_pushfstring(lua_State *L, const char *fmt, ...) {
    return nullptr; // Stub
}

// luaO_pushvfstring (0x95xxxx) — Format and push string (va_list)
const char *luaO_pushvfstring(lua_State *L, const char *fmt, va_list argp) {
    return nullptr; // Stub
}

// luaO_str2d (0x95xxxx) — Convert string to double
int luaO_str2d(const char *s, size_t len, lua_Number *result) {
    return 0; // Stub
}

// luaO_arith (0x95xxxx) — Perform arithmetic on two values
int luaO_arith(lua_State *L, int op, const void *v1, const void *v2) {
    return 0; // Stub
}

// luaO_hexavalue (0x95xxxx) — Convert hex char to value
int luaO_hexavalue(int c) {
    return 0; // Stub
}

// ============================================================================
// Extra: Opcode / Instruction constants (stubs complementares)
// ============================================================================

// luaO_str2unsigned (0x95xxxx) — Convert string to unsigned (size_t)
int luaO_str2unsigned(const char *s, size_t *result) {
    return 0; // Stub
}

// luaO_ceillog2 (0x95xxxx) — Ceiling log base 2
int luaO_ceillog2(unsigned int x) {
    return 0; // Stub
}

// ============================================================================
// Extra: Template / Factory pattern (stubs complementares)
// ============================================================================

// CreateLuaStateWithPhyre (0x95xxxx) — Create Lua state pre-configured for Phyre
lua_State *CreateLuaStateWithPhyre(void) {
    return nullptr; // Stub
}

// CreateLuaStateWithStandardLibs (0x95xxxx) — Create Lua state with all std libs
lua_State *CreateLuaStateWithStandardLibs(void) {
    return nullptr; // Stub
}

// RegisterPhyreTypeToLua (0x95xxxx) — Register a Phyre type to Lua
void RegisterPhyreTypeToLua(lua_State *L, const char *typeName, void *typeDesc) {
    // Stub
}

// IsPhyreType (0x95xxxx) — Check if Lua value is a Phyre type
int IsPhyreType(lua_State *L, int idx) {
    return 0; // Stub
}

// ============================================================================
// Lua API — Push stubs com __stdcall (expansao para reconstrucao FFX.EXE)
// ============================================================================

// lua_pushnil (0x95xxxx) — Push nil value onto stack
void __stdcall lua_pushnil(lua_State *L) { }

// lua_pushnumber (0x95xxxx) — Push number (lua_Number = double) onto stack
void __stdcall lua_pushnumber(lua_State *L, lua_Number n) { }

// lua_pushinteger (0x95xxxx) — Push integer onto stack
void __stdcall lua_pushinteger(lua_State *L, int n) { }

// lua_pushboolean (0x95xxxx) — Push boolean onto stack
void __stdcall lua_pushboolean(lua_State *L, int b) { }

// lua_pushstring (0x95xxxx) — Push null-terminated string onto stack
void __stdcall lua_pushstring(lua_State *L, const char *s) { }

// lua_pushliteral (0x95xxxx) — Push string literal (macro wrapper)
void __stdcall lua_pushliteral(lua_State *L, const char *s) { }

// lua_pushcfunction (0x95xxxx) — Push C function onto stack
void __stdcall lua_pushcfunction(lua_State *L, lua_CFunction f) { }

// lua_pushlightuserdata (0x95xxxx) — Push light userdata pointer onto stack
void __stdcall lua_pushlightuserdata(lua_State *L, void *p) { }
