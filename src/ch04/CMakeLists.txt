add_executable(main1 main1.cpp)
target_compile_options(main1 PRIVATE -g)
target_compile_options(main1 PRIVATE -Wextra)

add_executable(main2 main2.cpp)
target_compile_options(main2 PRIVATE -g)
target_compile_options(main2 PRIVATE -Wextra)

# -- main3 --
set(MAIN3_SOURCE ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(main3 
    ${MAIN3_SOURCE}/main3.cpp
    ${MAIN3_SOURCE}/median.cpp
    ${MAIN3_SOURCE}/student_info.cpp
    ${MAIN3_SOURCE}/grade.cpp
    ${MAIN3_SOURCE}/median.hpp
    ${MAIN3_SOURCE}/student_info.hpp
    ${MAIN3_SOURCE}/grade.hpp)
