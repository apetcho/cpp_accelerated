#include<algorithm>
#include<iostream>
#include<iterator>
#include<string>
#include<vector>

#include "pics.hpp"


// --- MAIN DRIVER ---
int main(){
    using Picture_t = std::vector<std::string>;
    Picture_t picture;
    picture.push_back("this is an");
    picture.push_back("example");
    picture.push_back("to");
    picture.push_back("illustrate");
    picture.push_back("framing");

    std::ostream_iterator<std::string> ofile(std::cout, "\n");
    std::copy(picture.begin(), picture.end(), ofile);
    std::cout << std::endl;

    Picture_t framed = frame(picture);
    std::copy(framed.begin(), framed.end(), ofile);
    std::cout << std::endl;

    Picture_t hjoined = hcat(frame(picture), picture);
    std::copy(hjoined.begin(), hjoined.end(), ofile);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
