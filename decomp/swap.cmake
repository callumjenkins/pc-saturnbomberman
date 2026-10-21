# The decompiled kernel functions, built into the recompiled game in place of their generated bodies
# (the [[replace]] entries in game.toml): -DSATURN_EXTRA={root}/decomp/swap.cmake
enable_language(C)
file(GLOB DECOMP_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/src/*.c)
target_sources(recomp PRIVATE ${DECOMP_SOURCES} ${CMAKE_CURRENT_LIST_DIR}/divide.c ${CMAKE_CURRENT_LIST_DIR}/swap.cpp)
target_include_directories(recomp PRIVATE ${CMAKE_CURRENT_LIST_DIR})
set_source_files_properties(${DECOMP_SOURCES} PROPERTIES
    COMPILE_DEFINITIONS DECOMP_HOST COMPILE_OPTIONS "-std=gnu11;-fwrapv")
