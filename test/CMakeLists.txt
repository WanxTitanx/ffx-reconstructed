# test/CMakeLists.txt
# Harness de testes com Google Test via FetchContent.
# Build: cmake --build build --config Release; ctest --test-dir build -C Release

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/googletest ${CMAKE_BINARY_DIR}/googletest-build EXCLUDE_FROM_ALL)

add_executable(ffx_tests
    test_save_crc.cpp
    test_phyre_pclass_descriptor.cpp
    test_battle_hp_compute.cpp
    test_rdata_dump.cpp
    test_stubs.cpp
)

target_include_directories(ffx_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}/stubs
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/data
)

target_link_libraries(ffx_tests PRIVATE gtest gtest_main)

target_compile_options(ffx_tests PRIVATE /EHsc /MD)
set_target_properties(ffx_tests PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")

include(GoogleTest)
gtest_discover_tests(ffx_tests DISCOVERY_MODE PRE_TEST)
