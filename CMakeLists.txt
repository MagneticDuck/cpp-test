cmake_minimum_required(VERSION 3.2)
project(snake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
set(SOURCE_FILES ${SOURCE_FILES} src/game.h src/game.cpp)
set(SOURCE_FILES ${SOURCE_FILES} src/snake.h src/snake.cpp)
add_executable(snake ${SOURCE_FILES})

# hack for my nixos system, sorry
include_directories(/home/magneticduck/.nix-profile/include/ncurses/)
target_link_libraries(snake /home/magneticduck/.nix-profile/lib/libncurses.so)