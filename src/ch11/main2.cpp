#include<algorithm>
#include<stdexcept>
#include<iostream>
#include<iomanip>
#include<string>

#include "Vec.hpp"

struct StudentInfo {
    std::string name;
    double midterm;
    double final;
    Vec<double> homework;
};

// compute the median
double median(Vec<double> vec){
    using size_type = Vec<double>::size_type;

    size_type size = vec.size();
    if(size == 0){
        throw std::domain_error("median of an empty Vec");
    }

    std::sort(vec.begin(), vec.end());

    size_type mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}

// ---
double grade(double midterm, double final, double homework){
    return 0.2 * midterm + 0.4*final + 0.4*homework;
}

// ---
double grade(double midterm, double final, const Vec<double>& homework){
    if(homework.size() == 0){
        throw std::domain_error("student has done no homework");
    }

    return grade(midterm, final, median(homework));
}

// ----
double grade(const StudentInfo& info){
    return grade(info.midterm, info.final, info.homework);
}

// ----
std::istream& read_hw(std::istream& stream, Vec<double>& homework){
    if(stream){
        // get rid of previous contents
        homework.clear();
        // read homework grades
        double x;
        while(stream >> x){
            homework.push_back(x);
        }

        stream.clear();
    }

    return stream;
}

//
std::istream& read(std::istream& stream, StudentInfo& info){
    // read and store the student's name and midterm and final exam grades
    stream >> info.name >> info.midterm >> info.final;
    // read and store all the student's homework
    read_hw(stream, info.homework);

    return stream;
}


bool compare(const StudentInfo& x, const StudentInfo& y){
    return x.name < y.name;
}

// ------------
// MAIN DRIVER
// ------------
int main(){
    Vec<StudentInfo> students;
    StudentInfo record;
    std::string::size_type maxlen = 0;

    // read and store all records, and find the length of the longest name
    while(read(std::cin, record)){
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
    }

    // sort the students by name
    std::sort(students.begin(), students.end(), compare);

    for(auto student: students){
        std::cout << student.name
            << std::string(maxlen + 1 - student.name.size(), ' ');

        // compute and write the grade
        try{
            double final_grade = grade(student);
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << final_grade
                << std::setprecision(prec);
        }catch(std::domain_error err){
            std::cout << err.what();
        }

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
