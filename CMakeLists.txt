cmake_minimum_required(VERSION 3.2)
project(snake)
set(CMAKE_CXX_STANDARD 14)
find_package(Boost 1.65 REQUIRED COMPONENTS system filesystem) 
find_package(Curses REQUIRED)

file(GLOB SOURCE_FILES "./src/*.cpp" "./src/*.h")
add_executable(snake ${SOURCE_FILES})
target_link_libraries(snake ${Boost_LIBRARIES} ${CURSES_LIBRARIES})
