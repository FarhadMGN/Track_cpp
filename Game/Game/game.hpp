//
//  game.hpp
//  Game
//
//  Created by Евгений on 29/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

//#include "contr.hpp"
#include <stdio.h>
#include <utility>
#include <list>
#include <functional>
#include "math.h"

using namespace std;
//using Coord     = pair<int,int>;
//using Rabbit    = Coord;

class Coord:public std::pair<float, float>
{
public:
    using Base = std::pair<float, float>;
    float   distance(const Coord& coord) const;
    using Base::Base;
    
};


using Rabbit    = Coord;

enum Dir
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    BODY
};

using SnakePainter = function<void(Coord,Dir)>;


class Snake
{
public:
    Snake(int type);
    ~Snake();
    int type_ctrl_;
    void move();
    void set_direction(Dir d);
    list<Coord> body_;
    Dir dir_;
};

class Control;

class Game
{
    list<Snake*>snakes_;
    list<Rabbit>rabits_;
public:
    list<Control*>ctr_;
public:
    Game();
    ~Game()=default;
    int is_free(Coord plc);
    void random();
    Coord near(Coord my);
    void add(Snake* p);
    void paint(SnakePainter p);//patern visiter
    void move();
    void collide();
};

#endif /* game_hpp */
