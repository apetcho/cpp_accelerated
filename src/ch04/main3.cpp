#include<algorithm>
#include<iomanip>
#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>

#include "student_info.hpp"
#include "median.hpp"
#include "grade.hpp"


// -----------------------
//  M A I N   D R I V E R
// -----------------------
int main(){
    std::vector<StudentInfo> students;
    StudentInfo record;

    std::string::size_type maxlen = 0; // the length of the longest name

    std::cout << "\nReading all the students' data ..." << std::endl;
    while(read_student_info(std::cin, record)){
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
    }
    
    // sort students records in alphabetical order
    std::sort(students.begin(), students.end(), compare_student_info);

    using vsize_type = std::vector<StudentInfo>::size_type;
    std::cout << "Computing the final grade of each students ..."
        << std::endl;
    for(vsize_type i=0; i != students.size(); ++i){
        std::cout << students[i].name
            << std::string(maxlen + 1 - students[i].name.size(), ' ');

        try{
            double final_grade = grade(students[i]);
            std::streamsize prec = std::cout.precision();
            std::cout << " final grade is "
                << std::setprecision(3) << final_grade
                << std::setprecision(prec);
        }catch(std::domain_error err){
            std::cout << err.what();
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
