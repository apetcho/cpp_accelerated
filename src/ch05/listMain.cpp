#include<algorithm>
#include<list>
#include<string>
#include<iostream>

#include "extractFails.hpp"
#include "grade.hpp"
#include "../ch04/student_info.hpp"

bool operator<(const StudentInfo& x, const StudentInfo& y){
    return compare_student_info(x, y);
}

// --- MAIN DRIVER ---
int main(){
    std::list<StudentInfo> students;
    StudentInfo student;
    std::string::size_type maxlen = 0;

    while(read_student_info(std::cin, student)){
        maxlen = std::max(maxlen, student.name.size());
        students.push_back(student);
    }
    students.sort();    // FIXME
    /*
    std::sort(students.begin(), students.end(), 
        [](StudentInfo x, StudentInfo y)->bool{
            return x.name < y.name;
        }
    );
    */

    std::list<StudentInfo> fails = extract_fails(students);

    std::list<StudentInfo>::iterator iter;
    for(iter = fails.begin(); iter != fails.end(); ++iter){
        std::cout << iter->name << " " << grade(*iter) << std::endl;
    }

    return EXIT_SUCCESS;
}
