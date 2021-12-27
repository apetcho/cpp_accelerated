# -- describe how to build "greet" executable
add_executable(greet greet.cpp)
target_compile_options(greet PRIVATE -g)
target_compile_options(greet PRIVATE -Wextra)


# -- describe how to build "frame" executable
add_executable(frame frame.cpp)
target_compile_options(frame PRIVATE -g)
target_compile_options(frame PRIVATE -Wextra)
