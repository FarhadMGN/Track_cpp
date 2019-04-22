//
//  main.cpp
//  Game
//
//  Created by Евгений on 28/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include "game.hpp"
#include "view.hpp"
#include "contr.hpp"
#include "tuI.hpp"

int main(int argc, const char * argv[])
{
    View* v = View::get();
    Game a;
    //par_time_ t;
    Snake snake1(0);
    Snake snakeAI(1);
    v->set_model(&a);
    Control_Hum h(&snake1);
    Ai h_ai(&snakeAI);
    a.add(&snake1);
    a.add(&snakeAI);
    v->draw();
    v->run();
    delete v;
    return 0;
}

