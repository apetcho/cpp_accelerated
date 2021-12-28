add_executable(main1 main1.cpp)
target_compile_options(main1 PRIVATE -g)
target_compile_options(main1 PRIVATE -Wextra)

add_executable(main2 main2.cpp)
target_compile_options(main2 PRIVATE -g)
target_compile_options(main2 PRIVATE -Wextra)
