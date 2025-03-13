cmake_minimum_required(VERSION 3.30)
project(IsometricTileSim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")


add_executable(IsometricTileSim ${SOURCES})

target_include_directories(IsometricTileSim PUBLIC ${PROJECT_SOURCE_DIR}/include)


target_link_libraries(IsometricTileSim sfml-system sfml-window sfml-graphics)
