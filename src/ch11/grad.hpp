#ifndef _GRADE_H
#define _GRADE_H

#include "Vec.hpp"
#include "studentInfo.hpp"


double grade(double, double, double);
double grade(double, double, const Vec<double>&);
double grade(const StudentInfo&);

#endif
