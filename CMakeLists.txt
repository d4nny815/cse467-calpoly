cmake_minimum_required(VERSION 3.10)
project(GPUSim VERSION 1.0 DESCRIPTION "GPU Simulation Project" LANGUAGES C)

# Compiler options
add_compile_options(-Wall -Wextra -Werror -std=c99 -pedantic -g)

# Include math library
link_libraries(m)

# Specify the executable name and its source file
add_executable(main main.c)

# Add directories for include files if any
include_directories(ArrayList Primitives OffFile Transformation Lighting Projection Rasterization PGMFile)

# Add each module as a library and link it to the executable
add_library(ArrayList STATIC ArrayList/ArrayList.c)
add_library(OffFile STATIC OffFile/OffFile.c)
add_library(Primitives STATIC Primitives/Primitives.c)
add_library(Transformation STATIC Transformation/Transformation.c)
add_library(Lighting STATIC Lighting/Lighting.c)
add_library(Projection STATIC Projection/Projection.c)
add_library(Rasterization STATIC Rasterization/Rasterization.c)
add_library(PGMFile STATIC PGMFile/PGMFile.c)

# Linking the libraries to the main executable
target_link_libraries(main ArrayList OffFile Primitives Transformation Lighting Projection Rasterization PGMFile)

# Custom target for making a build directory (if needed)
add_custom_target(make_build_dir ALL COMMAND ${CMAKE_COMMAND} -E make_directory build)

# Custom command for cleaning up the build (optional)
add_custom_target(clean_custom COMMAND ${CMAKE_COMMAND} -E remove_directory build COMMAND ${CMAKE_COMMAND} -E remove main)
