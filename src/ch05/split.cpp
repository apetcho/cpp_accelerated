#include<cctype>
#include<string>
#include<vector>

#include "split.hpp"

//
std::vector<std::string> split(const std::string& s){
    std::vector<std::string> ret;

    using string_size = std::string::size_type;
    string_size i = 0;
    while(i != s.size()){
        // ignore space leading blanks
        while(i != s.size() && isspace(s[i])){
            ++i;
        }
        string_size j= i;
        while(j != s.size() && !isspace(s[j])){
            ++j;
        }
        // if we found some non-whitespace characters
        if(i != j){
            ret.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return ret;
}
