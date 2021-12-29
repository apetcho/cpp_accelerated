#ifndef _STUDENT_INFO_H
#define _STUDENT_INFO_H

#include<iostream>
#include<string>
#include "Vec.hpp"

//
struct StudentInfo {
    std::string name;
    double midterm;
    double final;
    Vec<double> homework;
};

bool compare(const StudentInfo&, const StudentInfo&);
std::istream& read(std::istream&, StudentInfo&);
std::istream& read_hw(std::istream&, Vec<double>&);

#endif
