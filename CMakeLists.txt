cmake_minimum_required(VERSION 3.22.1)

project(TowerDefence)

 set( SDL_STATIC ON CACHE BOOL "" FORCE )
 set( SDL_SHARED OFF CACHE BOOL "" FORCE )
# 'libs/SDL' should point at a SDL
# repo clone or extracted release tarball
 add_subdirectory( libs/SDL)


add_executable(${CMAKE_PROJECT_NAME} 
                ${SOURCES}

                # maths folder
                src/maths/Coords.cpp
                src/maths/Vector.cpp
                src/maths/Line.cpp
                src/maths/approximateComparison.cpp
                src/main.cpp

                # game folder
                src/game/Application.cpp 
                src/game/GameLevel.cpp 
                src/game/Wave.cpp

                # abstractClasses folder
                src/game/abstractClasses/Enemy.cpp 
                src/game/abstractClasses/Interface.cpp 
                src/game/abstractClasses/LaserTower.cpp 
                src/game/abstractClasses/Projectile.cpp 
                src/game/abstractClasses/ProjectileTower.cpp 
                src/game/abstractClasses/SplashwaveTower.cpp 
                src/game/abstractClasses/Tower.cpp

                # entityManagers folder
                src/game/entityManagers/EnemyManager.cpp 
                src/game/entityManagers/TowerManager.cpp

                # grid folder
                src/game/grid/Base.cpp 
                src/game/grid/EnemiesWay.cpp 
                src/game/grid/Grid.cpp 
                src/game/grid/GridTile.cpp 
                src/game/grid/Portal.cpp

                # towers folder
                src/game/towers/BasicTower.cpp 
                src/game/towers/FireTower.cpp 
                src/game/towers/IceTower.cpp

                # UI folder
                src/game/UI/HUDInterface.cpp 
                src/game/UI/Button.cpp 
                src/game/UI/LevelsMenu.cpp 
                src/game/UI/MainMenu.cpp 
                src/game/UI/OptionsMenu.cpp 
                src/game/UI/Slider.cpp

                # Engine
                src/engine/Engine.cpp

                # HID folder
                src/engine/HID/SystemEventsHandler.cpp 
                src/engine/HID/GameEvents.cpp

                # rendering folder
                src/engine/rendering/TexturesEnum.cpp 
                src/engine/rendering/Renderer.cpp

                # sound folder 
                src/engine/sound/SoundPlayer.cpp 
                src/engine/sound/SoundsEnumeration.cpp

                # utility folder
                src/engine/utility/Timers.cpp 
                src/engine/utility/CoutTextColors.cpp

                
                )

#target_include_directories(TowerDefence ${SDL2_INCLUDE_DIR})
target_link_libraries( ${CMAKE_PROJECT_NAME} SDL2main SDL2-static SDL2_image SDL2_ttf SDL2_mixer)
