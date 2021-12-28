#include<list>

#include "extractFails.hpp"
#include "../ch04/student_info.hpp"
#include "grade.hpp"

/** version 4: use `list' instead of vector */
std::list<StudentInfo> extract_fails(std::list<StudentInfo>& students){
    std::list<StudentInfo> fails;
    std::list<StudentInfo>::iterator iter = students.begin();

    while(iter != students.end()){
        if(fgrade(*iter)){
            fails.push_back(*iter);
            iter = students.erase(iter);
        }else{
            ++iter;
        }
    }

    return fails;
}
