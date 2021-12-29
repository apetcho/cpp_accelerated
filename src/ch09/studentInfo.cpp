#include<iostream>
#include<vector>

#include "grade.hpp"
#include "studentInfo.hpp"

// ---
double StudentInfo::grade() const {
    return ::grade(midterm, final, homework);
}

// ---
bool compare(const StudentInfo&x, const StudentInfo& y){
    return x.name() < y.name();
}

// ---
StudentInfo::StudentInfo(): midterm(0), final(0) {}

// ---
StudentInfo::StudentInfo(std::istream& stream){ read(stream); }

// ---
// read homework grades from an input stream into a `vector<double>'
// ---
static std::istream&
read_homework(std::istream& stream, std::vector<double>& homework){
    if(stream){
        // get rid of previous contents
        homework.clear();
        // read homework grades
        double x;
        while(stream >> x){
            homework.push_back(x);
        }
        // clear the stream so that input will work for the next student
        stream.clear();
    }

    return stream;
}

// ---
std::istream& StudentInfo::read(std::istream& stream){
    stream >> name_ >> midterm >> final;
    read_homework(stream, homework);
    return stream;
}
