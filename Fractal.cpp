#define s_width 150
#define s_height 90
#include "include/Fazen.hpp"

void branch(Fazen2d game, float startx, float starty, float len, float angle, float delang)
{
    short col;
    if (angle == 90 and startx == 0)
    {
        col = 0x0005 & 0x0006;
    }
    else
    {
        col = greenF;
    }
    float anglerad = angle * pi / 180;
    float endx = startx - len * cos(anglerad);
    float endy = starty - len * sin(anglerad);
    game.drawLine(startx, starty, endx, endy, col);

    if (len > 3)
    {
        branch(game, endx, endy, len * 0.7, angle + delang, delang);
        branch(game, endx, endy, len * 0.7, angle - delang, delang);
    }
}
int main()
{
    Fazen2d game;
    game.make2DConsole(8, 8, "Fractal Trees");
    TIMEVARS
    float centerx = s_width / 2;
    float centery = s_height;
    float len = 1;
    float angle = 90;
    float delang = 0;
    int d=1;
    int ad=40;
    while (1)
    {

        TIMER

        game.background();
        if(len>37)
        {
            d=0;
            ad=0;
        }
        delang += ad * felapsedTime;
        game.translate(centerx + 1, centery);
        branch(game, 0, 0, len, angle, delang);
        game.display();
        len += d * felapsedTime;
    }
}
