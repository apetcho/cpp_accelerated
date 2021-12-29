# --- urlsMain ---
add_executable(urlsMain
    urlsMain.cpp urls.cpp urls.hpp Vec.hpp)

# --- gradingMain2 ----
add_executable(gradingMain2 main2.cpp Vec.hpp)

# --- analysis ---
add_library(analysis 
    grade.cpp studentInfo.cpp analysis.cpp gradeCheck.cpp
    analysis.hpp grade.hpp studentInfo.hpp median.hpp Vec.hpp
)

add_executable(GradeAnalyis gradeAnalysis.cpp
    Vec.hpp analysis.hpp studentInfo.hpp)

target_link_libraries(GradeAnalyis PRIVATE analysis)
