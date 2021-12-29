#include<algorithm>

#include "studentInfo.hpp"

bool did_all_homework(const StudentInfo& info){
    return ((std::find(
        info.homework.begin(), info.homework.end(), 0))==info.homework.end());
}
