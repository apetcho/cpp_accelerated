#include<iostream>
#include<string>
#include<map>


int main(){
    std::string word;
    std::map<std::string, int> counters{};

    /** read the input, keeping track of each word and how often we use it */
    while(std::cin >> word){
        ++counters[word];
    }

    for(auto [key, val]: counters){
        std::cout << key << "\t" << val << std::endl;
    }

    return EXIT_SUCCESS;
}
