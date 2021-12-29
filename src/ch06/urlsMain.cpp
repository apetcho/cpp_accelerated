#include<algorithm>
#include<cctype>
#include<iostream>
#include<string>
#include<vector>

#include "urls.hpp"


int main(){
    std::string word;
    while(std::getline(std::cin, word)){
        std::vector<std::string> vec = find_urls(word);

        for(auto elem: vec){
            std::cout << elem << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
