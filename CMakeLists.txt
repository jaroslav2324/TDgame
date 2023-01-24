cmake_minimum_required(VERSION 3.22.1)

project(TowerDefence)

 set( SDL_STATIC ON CACHE BOOL "" FORCE )
 set( SDL_SHARED OFF CACHE BOOL "" FORCE )
# 'libs/SDL' should point at a SDL
# repo clone or extracted release tarball
 add_subdirectory( libs/SDL)

 add_subdirectory(src/engine)
 add_subdirectory(src/game)
 add_subdirectory(src/maths)

 set(SOURCES)
 foreach(source ${ENGINE_SOURCES})
    # //TODO change
        list(APPEND SOURCES src/engine/${source})
        # message("../${source}")
 endforeach()

 foreach(source ${GAME_SOURCES})
 # //TODO change
     list(APPEND SOURCES src/game/${source})
endforeach()

foreach(source ${MATHS_SOURCES})
# //TODO change
    list(APPEND SOURCES src/maths/${source})
endforeach()
 

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} src/main.cpp)

#target_include_directories(TowerDefence ${SDL2_INCLUDE_DIR})
target_link_libraries( ${CMAKE_PROJECT_NAME} SDL2main SDL2-static SDL2_image SDL2_ttf SDL2_mixer)
