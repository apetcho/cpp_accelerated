#ifndef _ANALYSIS_H
#define _ANALYSIS_H

#include<string>
#include<vector>
#include<functional>

#include "../ch04/student_info.hpp"

using AFn = std::function<double(const std::vector<StudentInfo>&)>;
using StudVec = std::vector<StudentInfo>;

bool did_all_homework(const StudentInfo& info);
double average_analysis(const std::vector<StudentInfo>& students);
double median_analysis(const std::vector<StudentInfo>& students);
double optimistic_median_analysis(const std::vector<StudentInfo>& students);
void write_analysis(std::ostream& out, const std::string& name,
    AFn fn, const StudVec& did, const StudVec& didnt);

#endif
