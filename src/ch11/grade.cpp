#include<stdexcept>
#include "Vec.hpp"
#include "grade.hpp"
#include "median.hpp"
#include "studentInfo.hpp"

// ---
double grade(double midterm, double final, double homework){
    return 0.2*midterm + 0.4*final + 0.4*homework;
}

// ---
double grade(double midterm, double final, const Vec<double>& hw){
    if(hw.size() == 0){
        throw std::domain_error("student has done no homework");
    }

    return grade(midterm, final, median(hw));
}

// ---
double grade(const StudentInfo& info){
    return grade(info.midterm, info.final, info.homework);
}
