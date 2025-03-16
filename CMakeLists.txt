cmake_minimum_required(VERSION 3.28)
project(RaylibTemplate CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES
    "src/**.cpp"
)

include_directories("src/")
add_executable(${PROJECT_NAME} ${SOURCES})

find_package(Raylib)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
