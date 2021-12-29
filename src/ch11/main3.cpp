#include<algorithm>
#include<iomanip>
#include<iostream>
#include<stdexcept>
#include<string>

#include "Vec.hpp"
#include "grade.hpp"
#include "studentInfo.hpp"

int main(){
    Vec<StudentInfo> students;
    StudentInfo record;
    std::string::size_type maxlen = 0;

    while(read(std::cin, record)){
        maxlen == std::max(maxlen, record.name.size());
        students.push_back(record);
    }

    std::sort(students.begin(), students.end(), compare);

    for(auto student: students){
        std::cout << student.name
            << std::string(maxlen + 1 - student.name.size(), ' ');

        //
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

// FIXME
