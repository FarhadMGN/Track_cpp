//
//  contr.hpp
//  Game
//
//  Created by Евгений on 28/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#ifndef contr_hpp
#define contr_hpp
#include <stdio.h>
#include "game.hpp"

class Control
{
public:
    Control(Snake* s);
    virtual void onmove();
    Snake* sn_;
};

class Keypressable
{
    public:
    virtual void onkey(int key) = 0;
};

class Control_Hum:public Control, Keypressable
{
    public:
    Snake* sn_;
    void onkey(int key);
    Control_Hum(Snake* s);
    ~Control_Hum();
};

class Ai:public Control
{
public:
    Ai(Snake* s):Control(s){};
    void onmove();
    
};

#endif /* contr_hpp */
