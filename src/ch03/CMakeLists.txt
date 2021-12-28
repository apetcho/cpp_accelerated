# -- describe how to build "average" executable
add_executable(average average.cpp)
target_compile_options(average PRIVATE -g)
target_compile_options(average PRIVATE -Wextra)


# -- describe how to build "median" executable
add_executable(median median.cpp)
target_compile_options(median PRIVATE -g)
target_compile_options(median PRIVATE -Wextra)
