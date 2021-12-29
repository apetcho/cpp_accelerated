#include<algorithm>
#include<functional>
#include<iostream>
#include<iterator>
#include<numeric>
#include<stdexcept>
#include<vector>

#include "../ch04/student_info.hpp"
#include "grade.hpp"
#include "../ch04/median.hpp"
#include "analysis.hpp"

// --- make this auxilary function local to this file
// static double grade_aux(const StudentInfo& info){
//     try{
//         return grade(info);
//     }catch(std::domain_error){
//         return grade(info.midterm, info.final, 0);
//     }
// }

// ---
double median_analysis(const StudVec& students){
    std::vector<double> grades;

    // std::transform(students.begin(), students.end(),
    //     std::back_inserter(grades), grade_aux);

    // using generic lambda instead of traditional way (see above)
    std::transform(students.begin(), students.end(),
        std::back_inserter(grades), [](auto&& info) -> double{
            try{
                return grade(info);
            }catch(std::domain_error){
                return grade(info.midterm, info.final, 0);
            }
        });

    return median(grades);
}

// ---
void write_analysis(std::ostream& out, const std::string& name,
    AFn aFn, const StudVec& did, const StudVec& didnt)
{
    out << name << ": median(did) = " << aFn(did)
        << ", median(didnt) = " << aFn(didnt) << std::endl;
}

static double average(const std::vector<double>& vec){
    return std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}

static double average_grade(const StudentInfo& info){
    return grade(info.midterm, info.final,
        /* use lambda and catch value by reference */
        [&hw=info.homework]() -> double{
            return std::accumulate(
                hw.begin(), hw.end(), 0.0)/hw.size();   
        }());
}

//
double average_analysis(const StudVec& students){
    std::vector<double> grades;

    std::transform(students.begin(), students.end(),
        std::back_inserter(grades),
        [](const StudentInfo& info)->double{
            return grade(info.midterm, info.final, average(info.homework));
        }
    );

    return median(grades);
}

// --
// median of the nonzero element of `info.homework', or `0' if no such
// elements exist
// --
static double optimistic_median(const StudentInfo& info){
    std::vector<double> nonzero;

    std::remove_copy(info.homework.begin(), info.homework.end(),
        std::back_inserter(nonzero), 0);

    if(nonzero.empty()){
        return grade(info.midterm, info.final, 0);
    }
    else{
        return grade(info.midterm, info.final, median(nonzero));
    }
}


// ---
double optimistic_median_analysis(const StudVec& students){
    std::vector<double> grades;

    std::transform(students.begin(), students.end(),
        std::back_inserter(grades), optimistic_median);

    return median(grades);
}
