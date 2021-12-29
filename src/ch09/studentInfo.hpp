#ifndef _STUDENT_INFO_H
#define _STUDENT_INFO_H

#include<string>
#include<vector>

class StudentInfo{
public:
    StudentInfo();                  // Default constructor
    StudentInfo(std::istream&);     // Construct one by reading a stream

    //
    std::string name() const { return name_; }

    //
    bool valid() const { return !homework.empty(); }

    //
    std::istream& read(std::istream&);
    double grade() const;

private:
    std::string name_;
    double midterm;
    double final;
    std::vector<double> homework;
};

bool compare(const StudentInfo&, const StudentInfo&);

#endif
