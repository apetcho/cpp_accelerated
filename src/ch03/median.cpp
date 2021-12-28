/**
 * @file median.cpp
 * @brief Computing student grades
 * @version 0.1
 * @date 2021-12-28
 * 
 * Write a program that compute the median and final grade of a student in a
 * course. The final grade is the sum of 40% of the student's final exam, 20% 
 * of the midterm exam and 40% of the average of homework grades.
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<algorithm>
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>

int main(){
    /* ask for and read the student's name */
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;

    /* ask for and read the midterm and final grades */
    std::cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    std::cin >> midterm >> final;

    /* ask for and read the homework grades */
    std::cout << "Enter all your homework grade followed by end-of-file: ";
    std::vector<double> homework;
    double x;
    while(std::cin >> x){
        homework.push_back(x);
    }
    using vec_size = std::vector<double>::size_type;
    vec_size size = homework.size();
    if(size == 0){
        std::cout << std::endl
            << "You must enter your grades. Please try again. " << std::endl;
        return EXIT_FAILURE;
    }

    /** sort the grades */
    std::sort(homework.begin(), homework.end());

    /** compute the median homeword grade */
    vec_size mid = size / 2;
    double median;
    median = size % 2 == 0 ? 
        (homework[mid] + homework[mid-1])/2 :
        homework[mid];
    
    /** compute and write the final grade */
    std::streamsize prec = std::cout.precision();
    std::cout << "Your final grade is " << std::setprecision(3)
        << 0.2 * midterm + 0.4*final + 0.4 * median
        << std::setprecision(prec) << std::endl;

    return EXIT_SUCCESS;
}
