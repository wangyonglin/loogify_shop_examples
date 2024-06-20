
#PROJECT_BINARY_DIR

include_directories(
    "${PROJECT_SOURCE_DIR}/modules/spine/include"
    "${PROJECT_SOURCE_DIR}/examples/spine_example/include"
    )

#将所有的源文件列为一个集合，集合名字叫做SRC_LISTS
set(EXAMPLES_SOURCES                   
    ./src/main.cpp
    ./src/spine-sdl-cpp.cpp
)


add_executable(spine_example ${EXAMPLES_SOURCES})

target_link_libraries(spine_example spine SDL2)

# copy data to build directory

add_custom_command(TARGET spine_example PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_CURRENT_LIST_DIR}/data $<TARGET_FILE_DIR:spine_example>/data)