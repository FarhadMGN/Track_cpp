//
//  tuI.hpp
//  Game
//
//  Created by Евгений on 28/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#ifndef tuI_hpp
#define tuI_hpp

#include <stdio.h>
#include "view.hpp"
#include "game.hpp"

class Tui:public View
{
private:
    int     row_, col_;
    int     x_,   y_;
public:
    
    Tui();
    ~Tui();
    virtual void draw() override;
    virtual void run()  override;
    virtual void SnakePainter(Coord c, Dir d) override;
    void xline   (int x, int y);
    void yline   (int x, int y);
    void gotoxy  (int x, int y);
};

#endif /* tuI_hpp */
