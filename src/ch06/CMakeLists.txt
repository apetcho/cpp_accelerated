# set(SPLIT_SRC_LIST )
# list(APPEND ${SPLIT_SRC_LIST}
#     ../ch05/splitMain.cpp
#     split.cpp
#     ../ch05/split.hpp
# )

# function(makeExampleExec exename exesrclist)
#     add_executable(${exename} ${exesrclist})
#     target_compile_options(${exename} PRIVATE -g)
#     target_compile_options(${exename} PRIVATE -Wextra)
# endfunction()


# makeExampleExec(split ${SPLIT_SRC_LIST})

add_executable(mySplit 
    ../ch05/splitMain.cpp
    split.cpp
    ../ch05/split.hpp
)

add_executable(Palindrome palindrome.cpp)
add_executable(URLExe urlsMain.cpp urls.cpp urls.hpp)

# ----
add_library(ganalysis
    analysis.cpp grade.cpp gradeCheck.cpp
    ../ch04/student_info.cpp ../ch04/median.cpp
    ../ch04/median.hpp ../ch04/student_info.hpp
    grade.hpp analysis.hpp)
add_executable(gradeAnalysis gradeAnalysis.cpp)
target_link_libraries(gradeAnalysis PRIVATE ganalysis)
