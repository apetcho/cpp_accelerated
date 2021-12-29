#include<algorithm>
#include<cctype>
#include<string>
#include<vector>

#include "../ch05/split.hpp"

/** true if the argument is a whitespace, false otherwise */
bool space(char c){
    return isspace(c);
}

/** true if the argument is not a whitespace, false otherwise */
bool not_space(char c){
    return !isspace(c);
}

std::vector<std::string> split(const std::string& mystr){
    /* Use alias to name type to make the code more expressive */
    using Iter_t = std::string::const_iterator;
    using Text_t = std::vector<std::string>;

    Text_t result;

    Iter_t iter1 = mystr.begin();
    while(iter1 != mystr.end()){
        // ignore leading blanks
        // use lambda expressions for the callable argument of find_if
        // instead of the functions defined earlier
        iter1 = std::find_if(iter1, mystr.end(), 
            [](char c) -> bool {
                return !isspace(c);
            }
        );

        // find end of the next word
        Iter_t iter2 = std::find_if(iter1, mystr.end(),
            [](char c) -> bool{
                return isspace(c);
            }
        );

        // copy the word delimited by iter1 and iter2
        if(iter1 != iter2){
            result.push_back(std::string(iter1, iter2));
        }
        iter1 = iter2;
    }

    return result;
}
