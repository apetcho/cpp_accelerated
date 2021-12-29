#include<algorithm>
#include "../ch04/student_info.hpp"

bool did_all_homework(const StudentInfo& info){
    return ((find(info.homework.begin(), info.homework.end(), 0))
        == info.homework.end());
}
