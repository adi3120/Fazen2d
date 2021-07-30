#include "vec2.hpp"

class Particle
{
public:
    vec2 pos;
    std::vector<Ray> rays;

    void look(std::vector<Boundary> walls, Fazen2d game)
    {

        for (Ray r : rays)
        {
            vec2 closest;
            float record = 500;

            for (Boundary wall : walls)
            {
                vec2 pt = r.cast(wall);
                const float d = vec2::dist(this->pos, pt);

                if (d < record)
                {
                    record = d;
                    closest = pt;
                }
            }
            if (closest.x>1 and closest.y>1 and closest.x<s_width-1 and closest.y<s_height-1)
            {
                float x1 = pos.x;
                float y1 = pos.y;
                float x2 = closest.x;
                float y2 = closest.y;
                game.drawLine(x2, y2, x1, y1, greenF);
            }
        }
    }
    void update(float x, float y)
    {

        pos.x = x;
        pos.y = y;
        rays.clear();
        for (int i = 0; i < 360; i +=3)
        {
            rays.push_back(Ray(pos, pi * i / 180));
        }
    }
};