//
//  exception.cpp
//  MyException
//
//  Created by Евгений on 30/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#include "exception.hpp"

MyExc::MyExc(MyExc* prev, const char* comment):
errcode_(0),
previus_(nullptr)
{
    if (prev == nullptr)
    {
        MyExc* T;
    }
};

MyExc::MyExc(MyExc& that)
{
    
};
