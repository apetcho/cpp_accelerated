#include<iostream>


int main(){
    int x = 5;

    // `p' points to `x'
    int* p = &x;
    std::cout << "x = " << x << std::endl;
    // change the value of `x' through `p'
    *p = 6;
    std::cout << "x = " << x << std::endl;

    return EXIT_SUCCESS;
}
