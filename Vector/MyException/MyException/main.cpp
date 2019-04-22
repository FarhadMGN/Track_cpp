//
//  main.cpp
//  MyException
//
//  Created by Евгений on 30/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    try {
        Vector v;
        incr (v);
    }
    catch (const char* err)
    {
        std::cout << "error is " << err << std::endl;
    }
    catch (...)
    return 0;
    std::cout << "Hello, World!\n";
    return 0;
}
