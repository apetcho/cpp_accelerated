#ifndef _GENERIC_MEDIAN_H
#define _GENERIC_MEDIAN_H

#include<algorithm>
#include<stdexcept>
#include<vector>

template<typename T>
T median(std::vector<T> vec){
    using vecsize_t = std::vector<T>::size_type;
    vecsize_t size = vec.size();
    if(size == 0){
        throw std::domain_error("median of an empty vector");
    }

    std::sort(vec.begin(), vec.end());
    
    vecsize_t mid = size/2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}

#endif
