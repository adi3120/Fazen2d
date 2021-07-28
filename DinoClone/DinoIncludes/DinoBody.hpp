#include "Terrain.hpp"
class Dino
{

    float gravity = 200;

public:
    float x = 4;
    int score = 0;
    bool button = true;
    bool button2 = false;
    float y = s_height / 2;
    float vely = 0;
    short eyecolor = greenF;
    short bodycolor = whiteF;
    void drawDino3(Fazen2d game)
    {
        std::string dino3[10] =

            {
                ".....#####",
                "....##$###",
                "....####..",
                "#...#####.",
                "#..####...",
                "#######...",
                "#######...",
                ".#####....",
                "..#.#.....",
                "....##...."};
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (dino3[i][j] == '#')
                {
                    game.Plot(x + j, y + i, bodycolor);
                }
                if (dino3[i][j] == '$')
                {
                    game.Plot(x + j, y + i, eyecolor);
                }
            }
        }
    }
    void drawDino2(Fazen2d game)
    {
        std::string dino2[10] = {
            ".....#####",
            "....##$###",
            "....####..",
            "#...#####.",
            "#..####...",
            "#######...",
            "#######...",
            ".#####....",
            "..#.#.....",
            "..##......"};
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (dino2[i][j] == '#')
                {
                    game.Plot(x + j, y + i, bodycolor);
                }
                if (dino2[i][j] == '$')
                {
                    game.Plot(x + j, y + i, eyecolor);
                }
            }
        }
    }
    void drawDino1(Fazen2d game)
    {

        std::string dino1[10] =
            {
                ".....#####",
                "....##$###",
                "....####..",
                "#...#####.",
                "#..####...",
                "#######...",
                "#######...",
                ".#####....",
                "..###.....",
                "..#.#....."};

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (dino1[i][j] == '#')
                {
                    game.Plot(x + j, y + i, bodycolor);
                }
                if (dino1[i][j] == '$')
                {
                    game.Plot(x + j, y + i, eyecolor);
                }
            }
        }
    }
    void jump()
    {
        if (button)
        {
            vely = -80;
            button2 = true;
        }
    }
    void move(float time)
    {
        y += vely * (time);
        vely += gravity * time;
        if (y + 10 >= s_height / 2)
        {
            button = true;
            y = s_height / 2 - 10;
        }
        else if (y < 2)
        {
            y = 2;
        }
    }
    void jumpsOver(Terrain t)
    {
        if (t.x > 5)
        {
            if (x + 8 > t.x && y + 8 < t.y && button2)
            {
                score += 1;
                button2 = false;
            }
        }
    }
    bool hits(Terrain t)
    {
        if (t.x > 5)
        {
            if (x + 7 > t.x && y + 8 > t.y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};