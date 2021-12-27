/**
 * @file greet.cpp
 * @brief Ask for person's name, and greet the person 
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include<string>


int main(){
    /*ask for the person's name */
    std::cout << "Please enter your first name: ";

    /* read the name */
    std::string name;       // define `name`
    std::cin >> name;       // read into `name`

    /* write a greeting */
    std::cout << "Hello, " << name << "!" << std::endl;

    return 0;
}
