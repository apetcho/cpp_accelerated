#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<map>

#include "../ch05/split.hpp"

using XRef_t = std::map<std::string, std::vector<int>>;
using WordVec_t = std::vector<std::string>;

/** find all the lines that refer to each word in the input */
XRef_t xref(
    std::istream& stream,
    WordVec_t find_words(const std::string&) = split)
{
    std::string line;
    int lineno = 0;
    XRef_t result;

    // read the next line
    while(std::getline(stream, line)){
        ++lineno;
        // break the input line into words
        WordVec_t words = find_words(line);
        for(WordVec_t::iterator iter = words.begin();
            iter != words.end(); ++iter)
        {
            result[*iter].push_back(lineno);
        }
    }

    return result;
}


// --- MAIN DRIVER ---
int main(){
    // call `xref' using `split' by default
    XRef_t retVal = xref(std::cin);
    for(auto [word, lineno]: retVal){
        std::cout << "[" << std::setw(25) << word << "] - occurs on line(s): ";
        for(auto num: lineno){
            std::cout << num << "  ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
