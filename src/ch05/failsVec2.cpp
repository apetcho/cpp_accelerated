#include<vector>

#include "../ch04/student_info.hpp"
#include "extractFails.hpp"
#include "grade.hpp"

/** second try: correct but potentially slow */
std::vector<StudentInfo> extract_fails(std::vector<StudentInfo>& students){
    std::vector<StudentInfo> fails;
    std::vector<StudentInfo>::size_type i = 0;
    while(i != students.size()){
        if(fgrade(students[i])){
            fails.push_back(students[i]);
            students.erase(students.begin() + i);
        }else{ ++i; }
    }

    return fails;
}
