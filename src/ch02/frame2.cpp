/**
 * @file frame.cpp
 * @brief Learning about some looping techniques 
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include<string>

int main(){
    /* Ask for the person's name */
    std::cout << "Please enter your first name: ";

    /* read the name */
    std::string name;
    std::cin >> name;

    /* build the message that we intend to write */
    const std::string greeting = "Hello, " + name + "!";

    /* the number of blanks surrounding the greeing */
    const int pad = 1;

    /* the number of rows and columns to write */
    const int rows = pad * 2 + 3;
    const std::string::size_type cols = greeting.size() + pad * 2 + 2;

    /* write a blank line to separate the output from the input */
    std::cout << std::endl;

    /* write `rows` rows of output */
    for(int row=0; row != rows; ++row){
        std::string::size_type col = 0;
        while(col != cols){
            /* is it time to write the greetings? */
            if(row == pad + 1 && col == pad + 1){
                std::cout << greeting;
                col += greeting.size();
            }else{
                /* are we on the border? */
                if(row == 0 || row == rows -1 || col == 0 || col == cols - 1){
                    std::cout << "*";
                }else{
                    std::cout << " ";
                }
                ++col;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
