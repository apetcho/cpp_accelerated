#include<stdexcept>
#include<vector>
#include "grade.hpp"
#include "../ch04/median.hpp"
#include "../ch04/student_info.hpp"

// ---
double grade(double midterm, double final, double homework){
    return 0.2*midterm + 0.4*final + 0.4*homework;
}

// ---
double grade(double midterm, double final, const std::vector<double>& homework){
    if(homework.size() == 0){
        throw std::domain_error("student has done no homework");
    }
    return grade(midterm, final, median(homework));
}

// ---
double grade(const StudentInfo& info){
    return grade(info.midterm, info.final, info.homework);
}

// ---
bool fgrade(const StudentInfo& info){
    return grade(info) < 60;
}

// ---
bool pgrade(const StudentInfo& info){
    return !fgrade(info);
}
