#ifndef _GRADE6_H
#define _GRADE6_H

#include<vector>
#include "../ch04/student_info.hpp"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const StudentInfo&);

bool pgrade(const StudentInfo&);
bool fgrade(const StudentInfo&);


#endif
