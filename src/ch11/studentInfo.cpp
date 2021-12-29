#include "studentInfo.hpp"

// ---
bool compare(const StudentInfo& x, const StudentInfo& y){
    return x.name < y.name;
}

// ---
std::istream& read(std::istream& stream, StudentInfo& info){
    // read and store the student's name and midterm and final exam grades
    stream >> info.name >> info.midterm >> info.final;
    // read and store all the student's homeword grades
    read_hw(stream, info.homework);

    return stream;
}


// -----
// read homework grades from an input stream into a `Vec<double>'
// -----
std::istream& read_hw(std::istream& stream, Vec<double>& homework){
    if(stream){
        // get rid of previous contents
        homework.clear();
        // read homework grades
        double x;
        while(stream >> x){ homework.push_back(x); }

        // clear the stream so that input will work for the next student
        stream.clear();
    }

    return stream;
}
