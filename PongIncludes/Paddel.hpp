#pragma once
struct Paddel
{
    float x;
    float y=s_width/2;
    float w=2;
    float h=20;
    int score=0;
    Paddel(float xs)
    {   
        x=xs;
    }
    void clipY()
    {
        if(y+h>s_height-3)
        {
            y=s_height-3-h;
        }
        else if(y<1)
        {
            y=1;
        }
    }

};