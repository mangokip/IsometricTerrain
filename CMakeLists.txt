cmake_minimum_required(VERSION 3.30)
project(IsometricTileSim)

set(CMAKE_CXX_STANDARD 20)


find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(IsometricTileSim main.cpp Tile.cpp TileMap.cpp Block.cpp BlockMap.cpp)

target_link_libraries(IsometricTileSim sfml-system sfml-window sfml-graphics)
