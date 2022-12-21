cmake_minimum_required(VERSION 3.24.1)

project(TowerDefence)

set( SDL_STATIC ON CACHE BOOL "" FORCE )
set( SDL_SHARED OFF CACHE BOOL "" FORCE )
# 'libs/SDL' should point at a SDL
# repo clone or extracted release tarball
add_subdirectory( libs/SDL )
# add_subdirectory( libs/SDL_image-release-2.6.2 )

#find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
#find_library(SDL2_LIBRARY NAME SDL2)

add_executable(${CMAKE_PROJECT_NAME} src/game/Base.cpp src/main.cpp src/game/Game.cpp src/Timers.cpp src/game/EnemiesWay.cpp  src/approximateComparison.cpp 
src/abstractClasses/Enemy.cpp src/enemies/BasicEnemy.cpp src/abstractClasses/Tower.cpp src/towers/BasicTower.cpp src/game/Grid.cpp
src/entityManagers/EnemyManager.cpp src/abstractClasses/Projectile.cpp src/game/GridTile.cpp src/entityManagers/TowerManager.cpp
src/UI/BasicInterface.cpp src/UI/Button.cpp src/game/Portal.cpp src/Coords.cpp src/game/Wave.cpp src/UI/MainMenu.cpp src/Application.cpp 
src/projectiles/BasicProjectile.cpp src/towers/IceTower.cpp src/towers/FireTower.cpp src/Renderer.cpp src/TexturesEnum.cpp src/abstractClasses/Interface.cpp
)

#target_include_directories(TowerDefence ${SDL2_INCLUDE_DIR})
target_link_libraries( ${CMAKE_PROJECT_NAME} SDL2main SDL2-static SDL2_image)
