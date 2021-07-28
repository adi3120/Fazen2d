#define s_width 80
#define s_height 80
#include "../include/Fazen.hpp"
#include "DinoIncludes/DinoBody.hpp"
#include "DinoIncludes/Terrain.hpp"
#include "DinoIncludes/Clouds.hpp"
#include "DinoIncludes/Ground.hpp"
#include <iostream>
int main()
{
    Fazen2d game;
    game.make2DConsole(8, 8, "Bhaag DK Bose");
    Dino d;
    srand(time(nullptr));
    std::vector<Terrain> t;
    std::vector<cloud> c;
    std::vector<ground> g;
    TIMEVARS
    bool run = true;
    bool button1 = 1;
    bool button2 = 0;
    int i = 0;
    while (run)
    {

        c.resize(3);

        if (i / 50 == 1)
        {
            button1 = !button1;
            button2 = !button2;
            i = 0;
        }

        if (rand() % 10000 < 1)
        {
            t.push_back(Terrain());
        }
        if (rand() % 100000 < 10)
        {
            c.push_back(cloud());
        }
        if (rand() % 1000 < 1)
        {
            g.push_back(ground());
        }
        TIMER
        game.background();
        game.drawLine(0, s_height / 2 - 3, s_width, s_height / 2 - 3);
        for (int i = 0; i < c.size(); i++)
        {
            c[i].drawClouds(game);
            c[i].move(felapsedTime);
        }
        for (int i = 0; i < g.size(); i++)
        {
            g[i].show(game);
            g[i].move(felapsedTime);
        }
        if (button1)
            d.drawDino2(game);
        d.move(felapsedTime);
        if (button2)
            d.drawDino3(game);
        if (GetAsyncKeyState(VK_SPACE))
        {
            d.jump();
            d.button = false;
        }

        for (int i = 0; i < t.size(); i++)
        {
            t[i].drawCactus(game);
            t[i].move(felapsedTime);
            d.jumpsOver(t[i]);
            if (d.hits(t[i]))
            {
                d.bodycolor = redF;
                d.drawDino1(game);
                run = false;
            }
        }
        game.drawTextFromInt(10, 10, L"Score : ", d.score);
        game.Plot(d.x, d.y, redF);
        game.display();
        i += 370 * felapsedTime;
        if (t.size() >= 4)
        {
            t.resize(4);
        }
        if (g.size() >= 10)
        {
            g.resize(10);
        }
    }
    game.display();
    getchar();
}