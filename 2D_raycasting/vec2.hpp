#pragma once
class vec2
{
public:
    float x;
    float y;
    vec2()
    {
        x = 0;
        y = 0;
    }
    vec2(float a, float b)
    {
        x = a;
        y = b;
    }

    friend vec2 operator+(vec2 a, vec2 b)
    {
        return {a.x + b.x, a.y + b.y};
    }
    friend vec2 operator-(vec2 a, vec2 b)
    {
        return {a.x - b.x, a.y - b.y};
    }
    friend vec2 operator*(vec2 a, vec2 b)
    {
        return {a.x * b.x, a.y * b.y};
    }
    friend vec2 operator/(vec2 a, vec2 b)
    {
        return {a.x / b.x, a.y / b.y};
    }
    vec2 normalize()
    {
        float mag = x * x + y * y;
        if (mag != 0)
        {
            x = x / mag;
            y = y / mag;
        }
        return {x, y};
    }
    vec2 fromAngle(float angle)
    {
        return {cosf(angle),sinf(angle)};
    }


};
