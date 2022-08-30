cmake_minimum_required(VERSION 3.24.1)

#include(CTest)
#enable_testing()

project(TowerDefence)

#set(SOURCE src/)

add_executable(TowerDefence src/main.cpp src/Timers.cpp src/EnemiesWay.cpp src/Base.cpp src/approximateComparison.cpp 
src/abstractClasses/Enemy.cpp src/enemies/BasicEnemy.cpp src/abstractClasses/Tower.cpp src/towers/BasicTower.cpp
src/entityManagers/EnemyManager.cpp src/abstractClasses/Projectile.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

target_link_libraries(TowerDefence SDL2main SDL2 SDL2_image) 
