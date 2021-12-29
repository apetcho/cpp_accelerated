#include<algorithm>
#include<iostream>
#include<cctype>
#include<string>

#include "Vec.hpp"
#include "urls.hpp"


// --- MAIN DRIVER ---
int main(){
    std::string text;
    while(std::getline(std::cin, text)){
        Vec<std::string> vec = find_urls(text);
        for(const auto& url: vec){
            std::cout << url << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
