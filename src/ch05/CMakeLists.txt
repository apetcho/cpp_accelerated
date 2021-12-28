set(STUDENT_INFO_DIR ../ch04)
set(CH05_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# ---
function(make_failExec name)
    add_executable(${name} 
    ${CH05_DIR}/extMain.cpp
    ${CH05_DIR}/grade.cpp
    ${CH05_DIR}/${name}.cpp
    ${STUDENT_INFO_DIR}/median.cpp
    ${STUDENT_INFO_DIR}/student_info.cpp
    ${STUDENT_INFO_DIR}/median.hpp
    ${STUDENT_INFO_DIR}/student_info.hpp
    ${CH05_DIR}/grade.hpp
    ${CH05_DIR}/extractFails.hpp)

    add_compile_options(${name} PRIVATE -g)
    add_compile_options(${name} PRIVATE -Wextra)

endfunction(make_failExec name)

macro(build_failExec name)
    add_executable(${name} 
    ${CH05_DIR}/listMain.cpp
    ${CH05_DIR}/grade.cpp
    ${CH05_DIR}/${name}.cpp
    ${STUDENT_INFO_DIR}/median.cpp
    ${STUDENT_INFO_DIR}/student_info.cpp
    ${STUDENT_INFO_DIR}/median.hpp
    ${STUDENT_INFO_DIR}/student_info.hpp
    ${CH05_DIR}/grade.hpp
    ${CH05_DIR}/extractFails.hpp)

    add_compile_options(${name} PRIVATE -g)
    add_compile_options(${name} PRIVATE -Wextra)

endmacro(build_failExec name)

function(makeExampleExec name)
    add_executable(${name}
        ${CH05_DIR}/${name}Main.cpp
        ${CH05_DIR}/${name}.cpp
        ${CH05_DIR}/${name}.hpp)
    add_compile_options(${name} PRIVATE -g)
    add_compile_options(${name} PRIVATE -Wextra)
endfunction(makeExampleExec name)
    

# ----

#make_failExec(failsVec1)
#make_failExec(failsVec2)
# make_failExec(failsIters)
#build_failExec(failsList)
#makeExampleExec(pics)
#makeExampleExec(split)

add_executable(splitMain2 ${CH05_DIR}/splitMain2.cpp)

