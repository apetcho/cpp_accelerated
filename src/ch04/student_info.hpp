#ifndef _STUDENT_INFO_H
#define _STUDENT_INFO_H

#include<iostream>
#include<string>
#include<vector>

struct StudentInfo{
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
};

bool compare_student_info(const StudentInfo&, const StudentInfo&);
std::istream& read_student_info(std::istream&, StudentInfo&);
std::istream& read_homework(std::istream&, std::vector<double>&);

#endif
