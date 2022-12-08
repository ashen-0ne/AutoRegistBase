cmake_minimum_required(VERSION 3.0)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src src_lists)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (UNIX AND NOT APPLE)
    MESSAGE(STATUS "unix")
elseif (WIN32)
    MESSAGE(STATUS "windows")
else ()
    MESSAGE(STATUS "other platform")
endif ()

add_library(AutoRegister ${src_lists})
