# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(GPUSim VERSION 1.0 DESCRIPTION "GPUSim project")

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Compiler options
add_compile_options(-Wall -Wextra -Werror -pedantic -O3 -g)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Source files and their dependencies
add_library(ArrayList STATIC ArrayList/ArrayList.c)
add_library(OffFile STATIC OffFile/OffFile.c)
add_library(Primitives STATIC Primitives/Primitives.c)
add_library(Transformation STATIC Transformation/Transformation.c)
add_library(Lighting STATIC Lighting/Lighting.c)
add_library(Projection STATIC Projection/Projection.c)
add_library(Rasterization STATIC Rasterization/Rasterization.c)
add_library(PGMFile STATIC PGMFile/PGMFile.c)

# Main executable
add_executable(GPUSim main.c)
target_link_libraries(GPUSim ArrayList OffFile Primitives Transformation Lighting Projection Rasterization PGMFile m)

# Specify the binaries output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Custom target for making a build directory
add_custom_target(dirs COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/bin)

# Custom command to clean up the build directory
add_custom_target(clean_all COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/bin COMMAND ${CMAKE_COMMAND} -E remove GPUSim)
