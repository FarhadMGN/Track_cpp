//
//  exception.hpp
//  MyException
//
//  Created by Евгений on 30/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#ifndef exception_hpp
#define exception_hpp

#include <stdio.h>
#include <iostream>
#include <exception>

#define BUF_SIZE 1024


class MyExc:public std::exception
{
private:
    int             errcode_;
    MyExc*          previus_;
    static char     mem_[BUF_SIZE];
public:
    virtual const char* what() const noexcept override;
    MyExc();
    MyExc(MyExc& that);
    MyExc(MyExc* prev, const char* what);
    ~MyExc() = default;
    int errcode();
};



#endif /* exception_hpp */
