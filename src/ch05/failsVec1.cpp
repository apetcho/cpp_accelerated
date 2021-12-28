#include<vector>
// #include "../ch04/student_info.hpp"
#include "extractFails.hpp"

#include "grade.hpp"

/** separate passing and failing student records: first try */
std::vector<StudentInfo> extract_fails(std::vector<StudentInfo>& students){
    std::vector<StudentInfo> pass;
    std::vector<StudentInfo> fail;
    // original version
    /*
    using vsize_type = std::vector<StudentInfo>::size_type;
    for(vsize_type i=0; i != students.size(); ++i){
        if(fgrade(students[i])){
            fail.push_back(students[i]);
        }else{
            pass.push_back(students[i]);
        }
    }
    */
    
    // C++11 and later version add `auto'
    for(auto& student: students){
        if(fgrade(student)){
            fail.push_back(student);
        }else{
            pass.push_back(student);
        }
    }

    students = pass;
    return fail;
}
