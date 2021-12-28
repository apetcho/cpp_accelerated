#include<algorithm>     // to get the declaration of `sort'
#include<stdexcept>     // to get the declaration of `domain_error'
#include<vector>        // to get the declaration of `vector'

#include "median.hpp"


/** Compute the median of a `vector<double>' */
double median(std::vector<double> vec){
    using vec_size = std::vector<double>::size_type;

    vec_size size = vec.size();
    if(size == 0){
        throw std::domain_error("median of an empty vector");
    }

    std::sort(vec.begin(), vec.end());
    vec_size mid = size / 2;

    auto result = size % 2 == 0 ?
        (vec[mid] + vec[mid-1])/2 :
        vec[mid];

    return result;
}
