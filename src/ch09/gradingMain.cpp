#include<algorithm>
#include<stdexcept>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

#include "studentInfo.hpp"
#include "median.hpp"
#include "grade.hpp"


// --------------------------
//   M A I N   D R I V E R
// --------------------------
int main(){
    std::vector<StudentInfo> students;
    StudentInfo record;
    std::string::size_type maxlen = 0;

    // read and store the data
    while(record.read(std::cin)){
        maxlen = std::max(maxlen, record.name().size());
        students.push_back(record);
    }

    // sort record by student's name
    std::sort(students.begin(), students.end(), compare);

    for(auto item: students){
        std::cout << item.name()
            << std::string(maxlen + 1 - item.name().size(), ' ');
        try{
            double final_grade = item.grade();
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << final_grade
                << std::setprecision(prec) << std::endl;
        }catch(std::domain_error err){
            std::cout << err.what() << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
