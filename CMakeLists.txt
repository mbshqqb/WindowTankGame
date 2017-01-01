cmake_minimum_required(VERSION 3.6)
project(TankGame)

set(CMAKE_CXX_STANDARD  11)

set(SOURCE_FILES Utils.h Utils.cpp DEFINE.h Bullet.h Tank.h Bullet.cpp Tank.cpp main.cpp TankGame.h TankGame.cpp Elements.h Elements.cpp test.cpp)
#set(SOURCE_FILES Utils.h Utils.cpp)
#set(SOURCE_FILES test.cpp)
add_executable(TankGame ${SOURCE_FILES})
target_link_libraries(TankGame ncurses)