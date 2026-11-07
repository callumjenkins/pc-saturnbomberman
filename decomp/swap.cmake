# The decompiled functions, built into the recompiled game in place of their generated bodies
# (the [[replace]] entries in game.toml): -DSATURN_EXTRA={root}/decomp/swap.cmake
# KRNL's C is in src/. Another module's is in src/<module>/, where names.h (decomp/gen.py writes it) gives its
# functions the module's prefix, since modules load at addresses KRNL uses too.
enable_language(C)
file(GLOB DECOMP_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/src/*.c)
set(MODULE_SOURCES_ALL)
foreach(module boot ip fld)
    file(GLOB MODULE_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/src/${module}/*.c)
    if(MODULE_SOURCES)
        set_property(SOURCE ${MODULE_SOURCES} APPEND PROPERTY COMPILE_OPTIONS
            -include ${CMAKE_CURRENT_LIST_DIR}/src/${module}/names.h)
        list(APPEND MODULE_SOURCES_ALL ${MODULE_SOURCES})
    endif()
endforeach()
list(APPEND DECOMP_SOURCES ${MODULE_SOURCES_ALL})
target_sources(recomp PRIVATE ${DECOMP_SOURCES} ${CMAKE_CURRENT_LIST_DIR}/swap.cpp)
target_include_directories(recomp PRIVATE ${CMAKE_CURRENT_LIST_DIR})
set_property(SOURCE ${DECOMP_SOURCES} APPEND PROPERTY COMPILE_DEFINITIONS DECOMP_HOST)
set_property(SOURCE ${DECOMP_SOURCES} APPEND PROPERTY COMPILE_OPTIONS -std=gnu11 -fwrapv)
