cmake_minimum_required(VERSION 3.0.0)
project(tower_defence VERSION 0.1.0)

#include(CTest)
#enable_testing()

add_executable(tower_defence src/main.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

target_link_libraries(tower_defence SDL2main SDL2 SDL2_image) 