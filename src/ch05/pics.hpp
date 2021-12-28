#ifndef _PICS_H
#define _PICS_H

#include<string>
#include<vector>

std::string::size_type width(const std::vector<std::string>& vec);
std::vector<std::string> frame(const std::vector<std::string>& vec);

//
std::vector<std::string> vcat(
    const std::vector<std::string>& top,
    const std::vector<std::string>& bottom
);

//
std::vector<std::string> hcat(
    const std::vector<std::string>& left,
    const std::vector<std::string>& right
);

#endif
