#include "student_info.hpp"

// compare two student by name
bool compare_student_info(const StudentInfo& x, const StudentInfo& y){
    return x.name < y.name;
}

/** read and store the student's name and midterm and final exam grades */

