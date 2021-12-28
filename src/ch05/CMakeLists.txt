set(STUDENT_INFO_DIR ../ch04)
set(CH05_DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(failsVec1 
    ${CH05_DIR}/extMain.cpp
    ${CH05_DIR}/grade.cpp
    ${CH05_DIR}/failsVec1.cpp
    ${STUDENT_INFO_DIR}/median.cpp
    ${STUDENT_INFO_DIR}/student_info.cpp
    ${STUDENT_INFO_DIR}/median.hpp
    ${STUDENT_INFO_DIR}/student_info.hpp
    ${CH05_DIR}/grade.hpp
    ${CH05_DIR}/extractFails.hpp)

add_compile_options(target PRIVATE -g)
add_compile_options(target PRIVATE -Wextra)
