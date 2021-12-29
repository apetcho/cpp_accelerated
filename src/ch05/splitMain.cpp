#include<cctype>
#include<iostream>
#include<string>
#include<vector>

#include "./split.hpp"

// --- MAIN DRIVER ---
int main(){
    std::string text;

    // read and split each line of input
    //using tsize_type = std::vector<std::string>::size_type;
    while(std::getline(std::cin, text)){
        std::vector<std::string> vtext = split(text);

        for(auto item: vtext){
            std::cout << item << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
