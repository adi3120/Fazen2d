#include "vec2.hpp"
class Boundary
{
public:
   vec2 a, b;
   short col=blueF;
   Boundary()
   {
       a.x=10;
       a.y=10;
       b.x=10;
       b.y=10;
   }
    Boundary(float x1, float y1, float x2, float y2)
    {
        a=vec2(x1,y1);
        b=vec2(x2,y2);
    }

    void show(Fazen2d game)
    {
        game.drawLine(a.x, a.y, b.x, b.y,col);
    }
};