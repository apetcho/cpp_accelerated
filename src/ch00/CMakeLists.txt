set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(hello hello.cpp)
target_compile_options(hello PRIVATE -g)
target_compile_options(hello PRIVATE -Wextra)
