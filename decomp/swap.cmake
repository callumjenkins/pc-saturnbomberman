# The decompiled kernel functions, built into the recompiled game in place of their generated bodies
# (the [[replace]] entries in game.toml): -DSATURN_EXTRA={root}/decomp/swap.cmake
enable_language(C)
target_sources(recomp PRIVATE ${CMAKE_CURRENT_LIST_DIR}/krnl.c ${CMAKE_CURRENT_LIST_DIR}/swap.cpp)
set_source_files_properties(${CMAKE_CURRENT_LIST_DIR}/krnl.c PROPERTIES
    COMPILE_DEFINITIONS DECOMP_HOST COMPILE_OPTIONS -std=gnu11)
