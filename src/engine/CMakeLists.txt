
add_subdirectory(rendering)
add_subdirectory(sound)

foreach(source ${RENDERING_SOURCES})
    # //TODO change
    list(APPEND ENGINE_SOURCES rendering/${source})
    # message("../${source}")
endforeach()

foreach(source ${SOUND_SOURCES})
    # //TODO change
    list(APPEND ENGINE_SOURCES sound/${source})
    # message("../${source}")
endforeach()

set(ENGINE_SOURCES ${ENGINE_SOURCES} PARENT_SCOPE)