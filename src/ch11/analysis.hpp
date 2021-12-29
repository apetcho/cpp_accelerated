#ifndef _ANALYSIS_H
#define _ANALYSIS_H

#include<string>
#include<vector>
#include<functional>

#include "Vec.hpp"
#include "studentInfo.hpp"


using AFn = std::function<double(const Vec<StudentInfo>&)>;
using StudVec = Vec<StudentInfo>;

bool did_all_homework(const StudentInfo& info);
double average_analysis(const Vec<StudentInfo>& students);
double median_analysis(const Vec<StudentInfo>& students);
double optimistic_median_analysis(const Vec<StudentInfo>& students);
void write_analysis(std::ostream& out, const std::string& name,
    AFn fn, const StudVec& did, const StudVec& didnt);

#endif
