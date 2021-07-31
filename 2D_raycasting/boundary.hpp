#include "vec2.hpp"
class Boundary
{
public:
   vec2 a, b;
   short col=blueF;
   short c='*';
    Boundary(float x1, float y1, float x2, float y2,short color=blueF)
    {
        a=vec2(x1,y1);
        b=vec2(x2,y2);
        col=color;
    }

    void show(Fazen2d game)
    {
        game.drawLine(a.x, a.y, b.x, b.y,col,c);
    }
};