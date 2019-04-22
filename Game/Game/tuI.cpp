//
//  tuI.cpp
//  Game
//
//  Created by Евгений on 28/03/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//
#include <stdio.h>
#include <cstdlib>
#include <termios.h>
#include <sys/ioctl.h>
#include <poll.h>

#include <unistd.h>


#include "game.hpp"
#include "tuI.hpp"

struct termios old;

Tui::Tui():
x_(0),
y_(0)
{
    struct winsize ws;
    ioctl (1, TIOCGWINSZ, &ws);
    col_ = ws.ws_col;
    row_ = ws.ws_row;
    
    /*struct termios a;
    tcgetattr(0, &a);//получ данные о терминале
    old = a;
    cfmakeraw(&a);
    tcsetattr(0, TCSAFLUSH, &a);*/
    //old = a;
}


Tui::~Tui()
{
    //tcgetattr(TCSAFLUSH, &old);
    system("clear");
    printf("bye\n");
}

void Tui::SnakePainter(Coord c, Dir d)
{
    gotoxy(c.first, c.second);
    putchar("^v<>o"[d]);
}

void Tui::gotoxy (int x, int y)
{
    printf("\e[%d;%dH", y, x);
}

void Tui::yline (int x, int y)
{
    for (int i = 0; i != row_; i++)
    {
        gotoxy (x,y);
        printf ("#");
        y++;
    }
}

void Tui::xline (int x, int y)
{
    for (int i = 0; i != col_; i++)
    {
        gotoxy (x,y);
        printf ("#");
        x++;
    }
}

using namespace std::placeholders;

void Tui::draw()
{
    system("clear");
    yline(0, 0);
    xline(0, 0);
    yline(col_, 0);
    xline(0, row_);
    
    auto f = std::bind(&View::SnakePainter, this, _1, _2);
    game_->paint(f);
}

void Tui::run()
{
    struct pollfd fds;
    fds.fd = 0;
    fds.events = POLLIN;
    int timeout = par_.first;
    while (1) {
        int n = poll(&fds, 1, timeout);
        if (n == 1)
        {
            int key = getchar();
            if (key == 'q')
                break;
            if (key != -1){
                if(onkey_delegate != nullptr)
                    onkey_delegate->onkey(key);
            }
        }
        if (n == 0)
        {
            par_.second();
        }
    }
}
