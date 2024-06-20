
#PROJECT_BINARY_DIR

include_directories(
    "${PROJECT_SOURCE_DIR}/examples/ffmpeg_player_example/include"
    )

#将所有的源文件列为一个集合，集合名字叫做SRC_LISTS
set(EXAMPLES_SOURCES                   
    ./src/main.cpp
    ./src/VideoRenderer.cpp
    ./src/FFmpegPlayer.cpp
)


add_executable(ffmpeg_player_example ${EXAMPLES_SOURCES})

target_link_libraries(ffmpeg_player_example  SDL2 SDL2_image)

# copy data to build directory

add_custom_command(TARGET ffmpeg_player_example PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_CURRENT_LIST_DIR}/data $<TARGET_FILE_DIR:ffmpeg_player_example>/data)