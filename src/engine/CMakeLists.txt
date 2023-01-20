
add_subdirectory(HID)
add_subdirectory(rendering)
add_subdirectory(sound)

foreach(source ${HID_SOURCES})
    # //TODO change
    list(APPEND ENGINE_SOURCES HID/${source})
    # message("../${source}")
endforeach()

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

list(APPEND ENGINE_SOURCES Engine.cpp)

set(ENGINE_SOURCES ${ENGINE_SOURCES} PARENT_SCOPE)