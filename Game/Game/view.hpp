//
//  view.hpp
//  Game
//
//  Created by Евгений on 28/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#ifndef view_hpp
#define view_hpp

#include <stdio.h>
#include "contr.hpp"
#include "game.hpp"

using lol = std::function<void()>;
using par_time = pair<int, lol>;

class View
{
    public:
    Keypressable* onkey_delegate;
    void setonkey(Keypressable* k);
    
    static View* get ();
    static View* inst;
    
    Game* game_;
    void set_model(Game* g);
    
    par_time par_;
    void setontimer(int , lol);
    
    //virtual void gotoxy(float x, float y);
    
    virtual void SnakePainter(Coord c, Dir d) = 0;
    virtual void draw() = 0;
    virtual void run() = 0;
    virtual ~View() = 0;
};

#endif /* view_hpp */
