#include "vec2.hpp"

class Particle
{
public:
    vec2 pos;
    short col=yellowF;
    std::vector<Ray> rays;
    float numOfrays=10;
    short c='.';
    void FillRays()
    {
        rays.clear();
        for (float i = 0; i < 360; i +=3)
        {
            rays.push_back(Ray(pos, pi * i / 180));
        }
    }
    void look(std::vector<Boundary> walls, Fazen2d game)
    {

        for (Ray r : rays)
        {
            vec2 closest;
            float record = 100000;

            for (Boundary wall : walls)
            {
                vec2 pt = r.cast(wall);
                if (pt.x > 1 and pt.y > 1)
                {
                    float ray_dx = r.pos.x - pt.x;
                    float ray_dy = r.pos.y - pt.y;
                    float d = sqrt(pow(ray_dx, 2) + pow(ray_dy, 2));
                    if (d < record)
                    {
                        record = d;
                        closest = pt;
                    }
                }
            }
            if (closest.x > 1 and closest.y > 1)
            {
                         //game.drawLine(pos.x, pos.y, closest.x, closest.y, col,c);
                
                
                if (pos.y > closest.y)
                {
                    if (pos.x > closest.x)
                        game.drawLine(pos.x, pos.y, closest.x + 1, closest.y + 1, col,c);
                    if (pos.x < closest.x)
                        game.drawLine(pos.x, pos.y, closest.x - 1, closest.y + 1, col,c);
                }
                if (pos.y < closest.y)
                {
                    if (pos.x > closest.x)
                        game.drawLine(pos.x, pos.y, closest.x + 1, closest.y - 1, col,c);
                    if (pos.x < closest.x)
                        game.drawLine(pos.x, pos.y, closest.x - 1, closest.y - 1, col,c);
                }
            }
        }
    }
    void update(float x, float y)
    {

        pos.x = x;
        pos.y = y;
    }
};