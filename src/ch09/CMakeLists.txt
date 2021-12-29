# --- studentInfo
add_library(studentInfo
    studentInfo.cpp grade.cpp studentInfo.hpp grade.hpp median.hpp)

add_executable(gradingMain gradingMain.cpp)
target_link_libraries(gradingMain PRIVATE studentInfo)
