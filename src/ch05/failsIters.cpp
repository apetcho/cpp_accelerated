#include<vector>
#include "../ch04/student_info.hpp"
#include "extractFails.hpp"
#include "grade.hpp"

/** version 3: iterators but no indexing; still potential slow */
std::vector<StudentInfo> extract_fails(std::vector<StudentInfo>& students){
    std::vector<StudentInfo> fails;
    std::vector<StudentInfo>::iterator iter = students.begin();

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
