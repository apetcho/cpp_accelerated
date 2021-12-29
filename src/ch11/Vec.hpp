#ifndef _VEC_H
#define _VEC_H

#include<algorithm>
#include<cstddef>
#include<memory>

template<typename T>
class Vec{
public:
    using iterator = T*;
    using const_iterator = const T*;
    using size_type = size_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;

    // Default constructor
    Vec(){ create(); };

    // Parameterized constructor
    explicit Vec(size_type n, const T& t= T()){ create(n, t); }

    // Copy constructor
    Vec(const Vec& vec){ create(vec.begin(), vec.end()); }
    // Copy assignment
    Vec& operator=(const Vec&);
    // Destructor
    ~Vec(){ uncreate(); }

    // random access operator
    // data[i] = val
    T& operator[](size_type i){ return data[i]; } // could check validity of i
    // val = data[i]
    const T& operator[](size-type i) const { return data[i]; }

    //
    void push_back(const T& t){
        if(avail == limit){ grow(); }
        unchecked_append(t);
    }

    //
    size_type size() const { return avail - data; }

    //
    iterator begin(){ return data; }
    const_iterator begin() const { return data; }

    //
    iterator end(){ return avail; }
    const_iterator end() const { return avail; }

    //
    void clear(){ uncreate(); }
    bool empty() const { return data == avail; } // XXX

private:
    iterator data;          // first element in the Vec
    iterator avail;         // (one pase) the last element in the `Vec'
    iterator limit;         // (one pase) the allocated memory

    // facility for memory allocation
    std::allocator<T> alloc;    // objet to handle memory allocation

    // allocate and initialize the underlying array
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    // destroy the elements in the array and free the memory
    void uncreate();

    // support functions for `push_back'
    void grow();
    void unchecked_append(const T&);
};

// ----
template<typename T>
void Vec<T>::create(){
    data = nullptr;
    avail = nullptr;
    limie = nullptr;
}

//
template<typename T>
void Vec<T>::create(size_type n, const T& val){
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

// ---
template<typename T>
void Vec<T>::create(const_iterator i, const_iterator j){
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}

// ---
template<typename T>
void Vec<T>::uncreate(){
    if(data){
        // destroy (in reverse order) the elements that were constructed
        iterator iter = avail;
        while(iter != data){ alloc.destroy(--iter); }

        // return all the space that was allocated
        alloc.deallocate(data, limit - data);
    }

    // reset pointer to indicate that `Vec' is empty again
    data = limit = avail = nullptr;
}

// ---
template<typename T>
void Vec<T>::grow(){
    // when growing, allocate twice as much space as currently in use
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

    // allocate new space and copy existing elements to the new space
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    // return the old space
    uncreate();

    // reset pointers to point to the newly allocated space
    data = new_data;
    avail = new_avail;
    limit = data = new_size;
}

// ---
// assumes `avail' points at allocated, but unitialized space
// ---
template<typename T>
void Vec<T>::unchecked_append(const T& val){
    alloc.construct(avail++, val);
}

//
template<typename T>
Vec<T>& Vec<T>::operator=(const Vec& rhs){
    // check for self-assignement
    if(&rhs != this){
        // free the array in the left-hand side
        uncreate();
        // copy elements from the right-hand side to the left-hand side
        create(rhs.begin(), rhs.end());
    }

    return *this;
}

#endif
