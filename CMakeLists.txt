cmake_minimum_required(VERSION 3.16)
project(MyGameSFML LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED IMPORTED_TARGET sfml-all)

set(GAME_SOURCES
  src/main.cpp
  src/core/Game.cpp
  src/entities/Player.cpp
)

add_executable(MyGameSFML)
target_sources(MyGameSFML PRIVATE ${GAME_SOURCES})
target_include_directories(MyGameSFML PRIVATE include)
target_link_libraries(MyGameSFML PRIVATE PkgConfig::SFML)

# Opcional: organiza melhor os arquivos no IDE
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${GAME_SOURCES})
