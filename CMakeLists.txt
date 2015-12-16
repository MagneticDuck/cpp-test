cmake_minimum_required(VERSION 3.2)
project(snake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(source)
set(SOURCE_FILES source/main.cpp)
set(SOURCE_FILES ${SOURCE_FILES} source/snake/snake.h                   source/snake/snake.cpp)
set(SOURCE_FILES ${SOURCE_FILES} source/snake/control/control.h         source/snake/control/control.cpp)
set(SOURCE_FILES ${SOURCE_FILES} source/snake/control/control_ncurses.h source/snake/control/control_ncurses.cpp)
set(SOURCE_FILES ${SOURCE_FILES} source/snake/control/control_sfml.h     source/snake/control/control_sfml.cpp)
set(SOURCE_FILES ${SOURCE_FILES} source/snake/engine/engine.h           source/snake/engine/engine.cpp)
set(SOURCE_FILES ${SOURCE_FILES} source/snake/engine/options.h          source/snake/engine/options.cpp)
set(SOURCE_FILES ${SOURCE_FILES} source/snake/util/util.h               source/snake/util/util.cpp)
add_executable(snake ${SOURCE_FILES})

# hack for nixos, sorry
include_directories(/home/magneticduck/.nix-profile/include/)
target_link_libraries(snake /home/magneticduck/.nix-profile/lib/libncurses.so)
target_link_libraries(snake /home/magneticduck/.nix-profile/lib/libsfml-system.so)
target_link_libraries(snake /home/magneticduck/.nix-profile/lib/libsfml-graphics.so)
target_link_libraries(snake /home/magneticduck/.nix-profile/lib/libsfml-window.so)
