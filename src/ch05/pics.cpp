#include<algorithm>
#include<string>
#include<vector>

#include "pics.hpp"

std::string::size_type width(const std::vector<std::string>& vec){
    std::string::size_type maxlen = 0;

    for(std::vector<std::string>::size_type i=0; i != vec.size(); ++i){
        maxlen = std::max(maxlen, vec[i].size());
    }

    return maxlen;
}

//
std::vector<std::string> frame(const std::vector<std::string>& vec){
    std::vector<std::string> ret;
    std::string::size_type maxlen = width(vec);
    std::string border(maxlen+4, '*');

    // write the top border
    ret.push_back(border);

    // write each interior row, bordered by an asterisk ans space
    for(std::vector<std::string>::size_type i=0; i != vec.size(); ++i){
        ret.push_back(
            "* " + vec[i] + std::string(maxlen - vec[i].size(), ' ') + " *"
        );
    }

    // write the bottom border
    ret.push_back(border);

    return ret;
}

//
std::vector<std::string> vcat(
    const std::vector<std::string>& top,
    const std::vector<std::string>& bottom
){
    // copy the `top' picture
    std::vector<std::string> ret = top;

    // copy entry `bottom' picture
    using iterator = std::vector<std::string>::const_iterator;
    for(iterator iter = bottom.begin(); iter != bottom.end(); ++iter){
        ret.push_back(*iter);
    }

    return ret;
}

//
std::vector<std::string>
hcat(
    const std::vector<std::string>& left,
    const std::vector<std::string>& right)
{
    
    std::vector<std::string> ret;
    // add 1 to leave a space between pictures
    std::string::size_type width1 = width(left) + 1;

    using psize_type = std::vector<std::string>::size_type;

    // indices to look at elements from `left' and `right' respectively
    psize_type i = 0;
    psize_type j = 0;

    // continue untile we've seen all rows from both pictures
    while(i != left.size() || j != right.size()){
        // construct new `string' to hold characters from both pictures
        std::string s;

        // copy a row from the left-hand side, if there is one
        if( i != left.size()){
            s = left[i++];
        }
        // pad to full width
        s += std::string(width1 - s.size(), ' ');

        // copy a row from the right-hand side, if there is one
        if(j != right.size()){
            s += right[j++];
        }
        ret.push_back(s);
    }

    return ret;
}
