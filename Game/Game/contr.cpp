//
//  contr.cpp
//  Game
//
//  Created by Евгений on 28/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#include <iostream>
#include "contr.hpp"
#include "view.hpp"

Control::Control(Snake* s)
{
    sn_ = s;
}

void Control::onmove()
{}

Control_Hum::Control_Hum(Snake* s):Control(s)
{
    sn_ = s;
    View::get()->setonkey(this);
}

void Control_Hum::onkey(int key)
{
    //printf("in onkey this = :%d", this);
    switch (key) {
        case 'w':
            sn_->set_direction(UP);
            break;
        case 's':
            sn_->set_direction(DOWN);
            break;
        case 'a':
            sn_->set_direction(LEFT);
            break;
        case 'd':
            sn_->set_direction(RIGHT);
            break;
        default:
            break;
    }
}

Control_Hum::~Control_Hum()
{}

void Ai::onmove()
{
    Dir d;
    Coord my = sn_->body_.front();
    Coord way = View::get()->game_->near(my);
    
    if (way.first > my.first)
        d = LEFT;
    else
        d = RIGHT;
    
    if (way.second > my.second)
        d = UP;
    else
        d = DOWN;
    sn_->dir_ = d;
}
