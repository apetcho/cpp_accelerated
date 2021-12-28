#include<stdexcept>
#include<vector>

#include "grade.hpp"
#include "../ch04/median.hpp"
#include "../ch04/student_info.hpp"

/** Compute a student's overall finall grade from median and final exam grades
 * and homework grade */
double grade(double midterm, double final, double homework){
    return 0.2*midterm + 0.4*final + 0.4*homework;
}

/** Compute a student grade's overall grade from midterm and final exam grades
 * and vector of home work grades.
 * 
 * This function does not copy its arguments, because `median' does so for us.*/
double grade(double midterm, double final, const std::vector<double>& homework){
    if(homework.size() == 0){
        throw std::domain_error("student has done no homework");
    }
    return grade(midterm, final, median(homework));
}

/***/
double grade(const StudentInfo& info){
    return grade(info.midterm, info.final, info.homework);
}

// predicate to determine whether a student failed
bool fgrade(const StudentInfo& info){
    return grade(info) < 60;
}
