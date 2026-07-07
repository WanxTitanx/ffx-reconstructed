# ============================================================================
# FFX.EXE — Reconstructed Build
# Target: Visual Studio 2012 (VC11), /MD, /LTCG
# ============================================================================
cmake_minimum_required(VERSION 3.5)
project(FFX_Reconstructed C CXX)

set(CMAKE_CXX_FLAGS "/MD /O2 /GL /GS-")
set(CMAKE_EXE_LINKER_FLAGS "/LTCG /SUBSYSTEM:WINDOWS")

# ============================================================================
# Sources
# ============================================================================
set(FFX_SOURCES
    src/ffx/main.cpp
    src/ffx/ffx_battle.cpp
    src/ffx/ffx_field.cpp
    src/ffx/ffx_menu.cpp
    src/ffx/ffx_save.cpp
    src/ffx/ffx_debug.cpp
    src/ffx/ffx_renderer.cpp
    src/ffx/ffx_input.cpp
    src/ffx/ffx_renderqueue.cpp
    src/ffx/ffx_texture.cpp
)

set(PHYRE_SOURCES
    src/phyre/phyre_input.cpp
    src/phyre/phyre_audio.cpp
    src/phyre/phyre_scripting.cpp
    src/phyre/phyre_render.cpp
    src/phyre/phyre_animation.cpp
    src/phyre/phyre_postprocess.cpp
    src/phyre/phyre_pclass.cpp
    src/phyre/phyre_pinputs.cpp
    src/phyre/phyre_stubs.cpp
)

set(LUA_SOURCES
    src/lua-real/lapi.c
    src/lua-real/lauxlib.c
    src/lua-real/lbaselib.c
    src/lua-real/lbitlib.c
    src/lua-real/lcode.c
    src/lua-real/lcorolib.c
    src/lua-real/lctype.c
    src/lua-real/ldblib.c
    src/lua-real/ldebug.c
    src/lua-real/ldo.c
    src/lua-real/ldump.c
    src/lua-real/lfunc.c
    src/lua-real/lgc.c
    src/lua-real/linit.c
    src/lua-real/liolib.c
    src/lua-real/llex.c
    src/lua-real/lmathlib.c
    src/lua-real/lmem.c
    src/lua-real/loadlib.c
    src/lua-real/lobject.c
    src/lua-real/lopcodes.c
    src/lua-real/loslib.c
    src/lua-real/lparser.c
    src/lua-real/lstate.c
    src/lua-real/lstring.c
    src/lua-real/lstrlib.c
    src/lua-real/ltable.c
    src/lua-real/ltablib.c
    src/lua-real/ltm.c
    src/lua-real/lundump.c
    src/lua-real/lvm.c
    src/lua-real/lzio.c
)

set(BULLET_SOURCES
    src/bullet/bullet_stubs.cpp
)

# ============================================================================
# Includes
# ============================================================================
set(INCLUDES
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/bullet
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}/stubs
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/lua-real
)

# Ativa compatibilidade com Lua 5.1 (unpack, loadstring, module, etc.)
add_compile_definitions(LUA_COMPAT_ALL)

# ============================================================================
# Stubs for external dependencies
# ============================================================================
set(STUB_LIBS
    stubs/stub_steam.cpp
    stubs/stub_fmod.cpp
    stubs/stub_iggy.cpp
    stubs/stub_win32.cpp
    stubs/stub_d3d11.cpp
)

# ============================================================================
# Executable
# ============================================================================
add_executable(FFX_Reconstructed
    ${FFX_SOURCES}
    ${PHYRE_SOURCES}
    ${LUA_SOURCES}
    ${BULLET_SOURCES}
    ${STUB_LIBS}
)

target_include_directories(FFX_Reconstructed PRIVATE ${INCLUDES})

# ============================================================================
# External Libraries
# ============================================================================
target_link_libraries(FFX_Reconstructed
    d3d11.lib
    dxgi.lib
    dinput8.lib
    xinput.lib
    winmm.lib
    advapi32.lib
)
