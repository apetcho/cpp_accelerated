#ifndef _GRADE_H
#define _GRADE_H

#include<vector>
#include "../ch04/student_info.hpp"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const StudentInfo&);
bool fgrade(const StudentInfo&);

#endif
