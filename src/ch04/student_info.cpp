#include "student_info.hpp"

// compare two student by name
bool compare_student_info(const StudentInfo& x, const StudentInfo& y){
    return x.name < y.name;
}

/** read and store the student's name and midterm and final exam grades */
std::istream& read_student_info(std::istream& stream, StudentInfo& info){
    stream >> info.name >> info.midterm >> info.final;
    /* read and store all the student's homework grades */
    read_homework(stream, info.homework);
    return stream;
}
