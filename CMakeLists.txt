cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0072 NEW)

project(CozeeFarm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set source files
file(GLOB_RECURSE SOURCES 
    src/*.cpp
    external/stb/*.cpp
)
file(GLOB_RECURSE HEADERS include/*.h)

# Include dirs
include_directories(include)
include_directories(include external/stb)


# Find OpenGL, GLFW, GLEW
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GLEW REQUIRED glew)

include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})

# Executable
add_executable(CozeeFarm ${SOURCES} ${HEADERS})

# Copy in assets
add_custom_command(
    TARGET CozeeFarm POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:CozeeFarm>/assets
)

# Link libraries
target_link_libraries(CozeeFarm ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})