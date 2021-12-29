#include<stdexcept>
#include<vector>

#include "grade.hpp"
#include "median.hpp"

// ---
double grade(double midterm, double final, double homework){
    return 0.2*midterm + 0.4*final + 0.4*homework;
}

// ---
double grade(double midterm, double final, const std::vector<double>& hwvec){
    if(hwvec.size() == 0){
        throw std::domain_error("student has done no homework");
    }

    return grade(midterm, final, median(hwvec));
}
