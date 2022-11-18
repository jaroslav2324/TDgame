cmake_minimum_required(VERSION 3.24.1)

project(TowerDefence)

set( SDL_STATIC ON CACHE BOOL "" FORCE )
set( SDL_SHARED OFF CACHE BOOL "" FORCE )
# 'external/sdl' should point at a SDL
# repo clone or extracted release tarball
add_subdirectory( libs/SDL )

add_executable(TowerDefence src/main.cpp src/Timers.cpp src/EnemiesWay.cpp src/Base.cpp src/approximateComparison.cpp 
src/abstractClasses/Enemy.cpp src/enemies/BasicEnemy.cpp src/abstractClasses/Tower.cpp src/towers/BasicTower.cpp
src/entityManagers/EnemyManager.cpp src/abstractClasses/Projectile.cpp)

target_link_libraries( ${CMAKE_PROJECT_NAME} SDL2main SDL2-static )
