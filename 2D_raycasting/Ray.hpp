#pragma once
#include "vec2.hpp"
class Ray
{
public:
    vec2 pos;
    vec2 dir;
    Ray()
    {
        pos={0,0};
        dir={0,0};
    }
    Ray(vec2 posi,float angle)
    {
        pos = posi;
        dir = dir.fromAngle(angle);
    }

    void lookAt(float x, float y)
    {
        this->dir.x = x - pos.x;
        this->dir.y = y - pos.y;
        dir=dir.normalize();

    }
    vec2 cast(Boundary wall)
    {
        const float x1 = wall.a.x;
        const float y1 = wall.a.y;
        const float x2 = wall.b.x;
        const float y2 = wall.b.y;

        const float x3 = pos.x;
        const float y3 = pos.y;
        const float x4 = pos.x + dir.x;
        const float y4 = pos.y + dir.y;

        const float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);


        const float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
        const float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;
        if (t > 0 and t < 1 and u > 0)
        {
            vec2 pt;
            pt.x = x1 + t * (x2 - x1);
            pt.y = y1 + t * (y2 - y1);
            return pt;
        }

    }
};