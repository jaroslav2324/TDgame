

set(GAME_SOURCES)

add_subdirectory(abstractClasses)
add_subdirectory(entityManagers)
add_subdirectory(enemies)
add_subdirectory(towers)
add_subdirectory(projectiles)
add_subdirectory(grid)
add_subdirectory(UI)

# order important
set(subds abstractClasses entityManagers enemies towers projectiles grid UI)
set(SUBDS_SOURCES ABSTRACT_CLASSES_SOURCES ENTITY_MANAGERS_SOURCES ENEMIES_SOURCES TOWERS_SOURCES PROJECTILES_SOURCES GRID_SOURCES UI_SOURCES)

set(subds_amount)
list(LENGTH subds subds_amount)
MATH(EXPR stop_val "${subds_amount} - 1")


foreach(index RANGE 0 ${stop_val})
    set(sources)
    set(source_dirname)
    list(GET SUBDS_SOURCES ${index} sources)
    list(GET subds ${index} source_dirname)

    foreach(source ${${sources}})
        # message(${source})
        list(APPEND GAME_SOURCES ${source_dirname}/${source})
    endforeach(source)
    
endforeach(index)


list(APPEND GAME_SOURCES Application.cpp GameLevel.cpp Wave.cpp)

set (GAME_SOURCES ${GAME_SOURCES} PARENT_SCOPE)
