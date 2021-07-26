#include "Paddel.hpp"
struct Ball
{
public:
    float x = s_width / 2;
    float y = s_height / 2;
    float velx = 30;
    float vely = 30;
    void update(float time)
    {
        x += velx * time;
        y += vely * time;
    }
    void reset()
    {
        x = s_width / 2;
        y = s_height / 2;
        velx *= -1;
    }
    void edges(int &P1score, int &P2score)
    {
        if (y < 3 || y+3 > s_height -3)
        {
            vely *= -1;
        }
        if (x < 9)
        {
            reset();
            P2score += 1;
        }
        if (x > s_width - 9)
        {
            reset();
            P1score += 1;
        }
    }
    void checkCollide(Paddel Left, Paddel Right)
    {
        if (x + 2 > Right.x && (y + 2 > Right.y && y < Right.y + Right.h ))
        {
            velx *= -1;
        }
        else if (x < Left.x+Left.w && (y + 2 > Left.y && y < Left.y + Left.h))
        {
            velx *= -1;
        }
    }
};