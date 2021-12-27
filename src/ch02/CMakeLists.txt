# -- describe how to build "frame" executable
add_executable(frame2 frame2.cpp)
target_compile_options(frame PRIVATE -g)
target_compile_options(frame PRIVATE -Wextra)
