//
//  main.cpp
//  Vector
//
//  Created by Евгений on 29/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

//#include <iostream>
#include "vec.hpp"
#include <stdlib.h>

/**/

//void*   operator new     (size_t size);
//void    operator delete  (void* ptr);

int main(int argc, const char * argv[])
{
    logs;
    Vector<char, 15> v1;
    Vector<int, 10> v2;
    v1.dump("v1");
    v2.dump("v2");
    loge;
    return 0;
}
/*void* operator new (size_t size)
{
    logs;
    try {
    void* data = (type_t*)calloc (size, sizeof(type_t));
    if (data == nullptr)
        throw "nullptr";
    printf ("memory allocated for pointer %d\n", data);
    return data;
    }
    catch (const char* str)
    {
        printf ("error! calloc is bad\n");
    }
    return nullptr;
}

void   operator delete (void* ptr)
{
    logs;
    try {
    if (ptr == nullptr)
        throw "Bad value";
    free(ptr);
    printf ("memory deleted for pointer %d\n", ptr);
    }
    catch (const char* str)
    {
        printf ("error! free is bad\n");
    }
    loge;
    
    return;
}*/

