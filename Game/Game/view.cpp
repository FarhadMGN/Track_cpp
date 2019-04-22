//
//  view.cpp
//  Game
//
//  Created by Евгений on 28/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#include "view.hpp"
#include "tuI.hpp"
#include "contr.hpp"

View::~View()
{
    inst = nullptr;
}

View* View::inst = nullptr;

View* View::get()
{
    if (inst != nullptr)
        return inst;
    inst = new Tui();
    return inst;
}

void View::setonkey(Keypressable* key)
{
    onkey_delegate = key;
}

void View::setontimer(int a, lol fn)
{
    par_.first = a;
    par_.second = fn;
}

void View::set_model(Game* g)
{
    game_ = g;
}
