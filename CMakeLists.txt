cmake_minimum_required(VERSION 3.28)
project(RaylibTemplate CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# The minimum version of raylib to search for
set(RAYLIB_VERSION "5.0")

file(GLOB_RECURSE SOURCES
    "src/**.cpp"
)

include_directories("src/")
add_executable(${PROJECT_NAME} ${SOURCES})

# Set this to the minimal version you want to support
find_package(raylib ${RAYLIB_VERSION} QUIET) # Let CMake search for a raylib-config.cmake

# This part downloads raylib and builds it if it's not installed on your system
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)

  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/master.tar.gz
  )

  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

    # build raylib
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
