#ifndef _MEDIAN_H
#define _MEDIAN_H

#include<algorithm>
#include<stdexcept>

#include "Vec.hpp"

template<typename T>
T median(Vec<T> vec){
    using vec_size = size_t;

    vec_size size = vec.size();
    if(size == 0){
        throw std::domain_error("median of an empty Vec");
    }

    std::sort(vec.begin(), vec.end());

    vec_size mid = size/2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}


#endif
