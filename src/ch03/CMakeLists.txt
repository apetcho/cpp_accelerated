# -- describe how to build "frame" executable
add_executable(average average.cpp)
target_compile_options(average PRIVATE -g)
target_compile_options(average PRIVATE -Wextra)
