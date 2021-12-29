#include<vector>
#include<iostream>

#include "analysis.hpp"
#include "../ch04/student_info.hpp"

int main(){
    std::vector<StudentInfo> did;
    std::vector<StudentInfo> didnt;

    // read the student records and partition them
    StudentInfo student;
    while(read_student_info(std::cin, student)){
        if(did_all_homework(student)){
            did.push_back(student);
        }else{
            didnt.push_back(student);
        }
    }

    // verify that the analyses will show us something
    if(did.empty()){
        std::cout << "No student did all the homework!" << std::endl;
        return 1;
    }
    if(didnt.empty()){
        std::cout << "Every student did all the homework!" << std::endl;
        return 1;
    }

    // do the analysis
    write_analysis(std::cout, "median", median_analysis, did, didnt);
    write_analysis(std::cout, "average", average_analysis, did, didnt);
    write_analysis(std::cout, "median of homework turned in",
        optimistic_median_analysis, did, didnt);

    return EXIT_SUCCESS;
}
