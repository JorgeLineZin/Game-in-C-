cmake_minimum_required(VERSION 3.10)
project(MyGameSFML)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-all)

add_executable(MyGameSFML src/main.cpp src/Game.cpp src/Player.cpp)

target_include_directories(MyGameSFML PRIVATE include ${SFML_INCLUDE_DIRS})
target_link_libraries(MyGameSFML ${SFML_LIBRARIES})

target_link_directories(MyGameSFML PRIVATE ${SFML_LIBRARY_DIRS})
