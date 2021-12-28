#ifndef _GRADE_H
#define _GRADE_H

#include<vector>
#include "student_info.hpp"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const StudentInfo&);


#endif
