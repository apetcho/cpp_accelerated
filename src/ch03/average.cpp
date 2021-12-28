/**
 * @file average.cpp
 * @brief Computing student grades
 * @version 0.1
 * @date 2021-12-28
 * 
 * Write a program that compute the final grade of a student in a course.
 * The final grade is the sum of 40% of the student's final exam, 20% of the
 * midterm exam and 40% of the average of homework grades.
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iomanip>
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::streamsize;


int main(){
    /* ask for and read the student's name */
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    /* ask for and read the midterm and final grades */
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    /* ask for the homework grades */
    cout << "Enter all your homework grades, followed end-of-file: ";

    /* the number and sum of grades read so far */
    int count = 0;
    double sum = 0.0;

    /* a variable into which to read */
    double x;

    /**
     * Invariant:
     *      we have read `count' grade so far, and `sum' is the sum of the
     *      sum of the first `count' grades
     */
    while(cin >> x){
        ++count;
        sum += x;
    }

    /* write the result */
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4*sum / count
         << setprecision(prec) << endl;


    return EXIT_SUCCESS;
}
