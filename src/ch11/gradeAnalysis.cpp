#include<iostream>
#include "Vec.hpp"
#include "analysis.hpp"
#include "studentInfo.hpp"



// ---- MAIn DRIVER ----
int main(){
    // students who did and didn't do all their homework
    Vec<StudentInfo> did;
    Vec<StudentInfo> didnt;

    // read the student records and partitions them
    StudentInfo student;
    while(read(std::cin, student)){
        if(did_all_homework(student)){ did.push_back(student); }
        else{ didnt.push_back(student); }
    }

    // verify that the analyses witll show us something
    if(did.empty()){
        std::cout << "No student did all the homeword!" << std::endl;
        return 1;
    }
    if(didnt.empty()){
        std::cout << "Every student did all the homework!" << std::endl;
        return 1;
    }

    // do the analyses
    write_analysis(std::cout, "median", median_analysis, did, didnt);
    write_analysis(std::cout, "average", average_analysis, did, didnt);
    write_analysis(std::cout, "median of homework turned in",
        optimistic_median_analysis, did, didnt);

    return EXIT_SUCCESS;
}
