#ifndef _EXTRACT_FAILS_H
#define _EXTRACT_FAILS_H

#include<vector>
#include<list>
#include "../ch04/student_info.hpp"

std::vector<StudentInfo> extract_fails(std::vector<StudentInfo>& vec);
std::list<StudentInfo> extract_fails(std::list<StudentInfo>& students);

#endif
