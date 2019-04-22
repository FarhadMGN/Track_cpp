//
//  vec.hpp
//  Vector
//
//  Created by Евгений on 29/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#ifndef vec_hpp
#define vec_hpp

#include <stdio.h>

#define logs                                        \
do                                              \
{                                               \
fprintf(stderr, "%s started\n", __func__);  \
fflush(stderr);                             \
}while (0)

#define loge                                        \
do                                              \
{                                               \
fprintf(stderr, "%s finished\n", __func__); \
fflush(stderr);                             \
}while (0)

#define SIZEOFNAME 8

typedef int type_t;

template <typename data_T, int cap>
class Vector
{
private:
    data_T* data_;
    int     capacity_;
    int     size_;
public:
    Vector  ();
    ~Vector ();
    
    template <int tcap>
    Vector              (const Vector<data_T, tcap>& that);
    
    Vector<data_T, cap>& operator=   (const Vector& that);

    Vector<data_T, cap>              (Vector<data_T,cap>&& that);
    Vector<data_T, cap>& operator=   (Vector<data_T, cap>&& that);
    
    int     resize           (int ncap);
    data_T& operator[]       (const int index);
    friend Vector<data_T, cap>  operator+ (const Vector<data_T, cap>& v1, const Vector<data_T, cap>& v2);
    Vector<data_T, cap>& operator+=       (const Vector<data_T, cap>& that);
    
    void    dump             (const char path[SIZEOFNAME]);
    
};

template <typename data_T, int cap>
Vector<data_T, cap>::Vector (Vector<data_T, cap>&& that):
data_(nullptr),
capacity_(0),
size_(0)
{
    logs;
    data_       = that.data_;
    capacity_  = that.capacity_;
    size_       = that.size_;
    
    that.data_      = nullptr;
    that.capacity_  = 0;
    that.size_      = 0;
    loge;
}

template <typename data_T, int cap>
Vector<data_T, cap>& Vector<data_T, cap>::operator= (Vector<data_T, cap>&& that)
{
    logs;
    data_       = that.data_;
    capacity_   = that.capacity_;
    size_       = that.size_;
    
    that.data_      = nullptr;
    that.capacity_  = 0;
    that.size_      = 0;
    loge;
    return *this;
}

template <typename data_T, int size>
Vector<data_T, size>::Vector(const Vector<data_T, size>& that):
data_ (nullptr),
size_(0),
capacity_(0)
{
    logs;
    data_T* data_ = (new data_T[that.capacity_]{});
    /*if (!data_)
     exit(1);*/
    for (int i = 0; i != that.capacity_; i++)
        data_[i] = that.data_[i];
    capacity_   = that.capacity_;
    size_       = that.size_;
    loge;
}

template <typename data_T, int cap>
Vector<data_T, cap>::Vector():
data_       (nullptr),
size_       (0),
capacity_   (cap)
{
    logs;
    data_T* data = new data_T[cap]{0};
    /*if (!data)
     exit(1);*/
    data_ = data;
    loge;
}

template <typename data_T, int size>
Vector<data_T, size>::~Vector ()
{
    logs;
    delete[] data_;
    capacity_   = 0;
    size_       = 0;
    loge;
}

template <typename data_T, int size>
int Vector<data_T, size>::resize  (int cap)
{
    logs;
    int old_cap = capacity_;
    data_T* data_new    =   (new data_T[cap]{});
    memcpy                  (data_new, data_, capacity_);
    delete[] data_;
    data_               =   data_new;
    capacity_           =   cap;
    size_               =   0;
    loge;
    return old_cap;
}

template <typename data_T, int size>
data_T& Vector<data_T, size>::operator[] (const int index)
{
    logs;
    if (index > capacity_ or index < 0) {
        printf("bad diapason\n");
        loge;}
    loge;
    return (data_[index]);
}

template <typename data_T, int size>
Vector<data_T, size>& Vector<data_T, size>::operator= (const Vector<data_T, size>& that)
{
    logs;
    if (capacity_ != that.capacity_)
        this->resize(that.capacity_);
    for (int i = 0; i != that.capacity_; i++)
        data_[i] = that.data_[i];
    loge;
    return *this;
}

template <typename data_T, int size>
Vector<data_T, size> operator+ (const Vector<data_T, size>& v1, const Vector<data_T, size>& v2)
{
    logs;
    //if (v1.capacity_ != v2.capacity_)
    // throw "size of vectors aren't equal";
    
    Vector<data_T, size> result(v1);
    for (int i = 0; i != v1.capacity_; i++)
        result.data_[i] = result.data_[i] + v2.data_[i];
    loge;
    return result;
}

template <typename data_T, int size>
Vector<data_T, size>& Vector<data_T, size>::operator+=  (const Vector<data_T, size>& that)
{
    logs;
    if (capacity_ != that.capacity_)
        this->resize(that.capacity_);
    for (int i = 0; i != capacity_; i++)
        data_[i] = data_[i] + that.data_[i];
    loge;
    return *this;
}

template <typename data_T, int size>
void Vector<data_T, size>::dump (const char path[SIZEOFNAME])
{
    logs;
    printf("dump of __%s__\n", path);
    printf("capacity_ = %d\n", capacity_);
    printf("size_     = %d\n", size_);
    if (data_ != nullptr) {
        for (int i = 0; i != capacity_; i++)
            printf("    data_[%d] = %d\n", i, data_[i]); }
    else
        printf("__NULLPTR__\n");
    loge;
}

#endif /* vec_hpp */
