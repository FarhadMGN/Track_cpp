//
//  game.cpp
//  Game
//
//  Created by Евгений on 29/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#include "game.hpp"
#include "contr.hpp"
#include "view.hpp"
#include "tuI.hpp"
#include <functional>

float Coord::distance(const Coord& coord) const
{
    if (abs(this->first - coord.first) > abs(this->second  - coord.second))
        return abs(this->first - coord.first);
    else
        return abs(this->second  - coord.second);
}

Game::Game()
{
    View::get()->setontimer (100, std::bind (&Game::move, this));
}

void Snake::set_direction(Dir d)
{
    dir_ = d;
}

void Snake::move()
{
    auto a  = body_.front();
    switch (dir_) {
        case UP:
            a.second--;
            break;
        case DOWN:
            a.second++;
            break;
        case LEFT:
            a.first--;
            break;
        case RIGHT:
            a.first++;
            break;
        default:
            break;
    }
    body_.push_front(a);
    body_.pop_back();
}

void Game::move()
{
    random();
    for(const auto cont: ctr_)
        cont->onmove();
    for(const auto s: snakes_)
        s->move();
    View::get()->draw();
}

void Game::paint (SnakePainter p)
{
    int i = 0;
    for (const auto s : snakes_)
    {
        for (const auto &c: s->body_)
        {
            if (i == 0)
            {
                p(c, s->dir_);
                i++;
            }
            else
                p(c, BODY);
        }
    }
    for (const auto &c: rabits_)
    {
        //printf("______i'm here!_________\n");
        //View::get()->gotoxy(c.first, c.second);
        
        //printf("i was been pushed!\nWith param x = %f y = %f", c.first, c.second);
        printf("\e[%f;%fH", 20, 20);
        printf("@");
    }
    
}

void Game::add(Snake* sn)
{
    snakes_.push_back(sn);
}

Snake::Snake(int type)
{
    type_ctrl_ = type;
    body_.push_back(Coord(10,10));
    body_.push_back(Coord(10,11));
    body_.push_back(Coord(10,12));
    body_.push_back(Coord(10,13));
    dir_ = RIGHT;
}

Snake::~Snake()
{}

int Game::is_free(Coord plc)
{
    for (const auto s : snakes_)
    {
        for (const auto &c: s->body_)
        {
            if (plc.first == c.first && plc.second == c.second)
                return 0;
        }
    }
    
        for (const auto &c: rabits_)
        {
            if (plc.first == c.first && plc.second == c.second)
                return 0;
        }
    return 1;
}

void Game::random()
{
    Coord rab;
    rab.first = rand() % 100 + 15;
    rab.second = rand() % 35 + 10;
    if (is_free(rab) != 0)
        rabits_.push_back(rab);
    else
        random();
}

Coord Game::near(Coord my)
{
    Coord min = Coord(0,0);
    for (const auto &c: rabits_)
    {
        if (min == Coord(0,0) || my.distance(c) < my.distance(min))
            min = c;
    }
    return min;
}
