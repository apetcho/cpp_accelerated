#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

//#include "../ch04/student_info.hpp"
#include "extractFails.hpp"
#include "grade.hpp"

// ---------------
//   MAIN DRIVER
// ---------------
int main(){
    std::vector<StudentInfo> studentsVec;
    StudentInfo student;
    std::string::size_type maxlen = 0;
    while(read_student_info(std::cin, student)){
        maxlen = std::max(maxlen, student.name.size());
        studentsVec.push_back(student);
    }

    // using lambda instead of compare_student_info()
    std::sort(studentsVec.begin(), studentsVec.end(), 
        [](auto &x, auto &y) -> bool{
            return x.name < y.name;
        }
    );

    std::vector<StudentInfo> fails = extract_fails(studentsVec);

    // traditional way
    /*
    for(int i=0; i < fails.size(); ++i){
        std::cout << fails[i].name << " " << grade(fails[i]) << std::endl;
    }*/

    // using generic for loop with auto
    for(auto& fail: fails){
        std::cout << fail.name << " " << grade(fail) << std::endl;
    }

    return EXIT_SUCCESS;
}
