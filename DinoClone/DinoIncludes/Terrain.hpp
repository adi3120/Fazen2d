#pragma once
class Terrain
{
public:
    float x, y;
    int c = rand() % 4;
    Terrain()
    {
        this->x = s_width;
        this->y = s_height / 2 - 7;
    }

    std::string cactus[4][7] = {
        {"...##...",
         "#..##..#",
         "#..##..#",
         "#######.",
         ".######.",
         "...##...",
         "...##**."},
        {"....#...",
         "#...#..#",
         "#..#...#",
         "#..##..#",
         ".######.",
         "...##...",
         "...##..."},
        {"......#.",
         "......##",
         "...##..#",
         "...##.##",
         "...####.",
         "...##...",
         "...##**."},
        {"........",
         "#.......",
         "#.......",
         ".#.##...",
         ".######.",
         "...##...",
         "**.##***"}

    };
    
    void drawCactus(Fazen2d game)
    {
        int i = c;
        for (int j = 0; j < 7; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (cactus[i][j][k] == '#')
                {
                    game.Plot(x + k, y + j, greenF);
                }
                else if(cactus[i][j][k]=='*')
                {
                    game.Plot(x + k, y + j, greenF,'.');
                    
                }
            }
        }
    }
    void move(float time)
    {
        x -= 40 * time;

        if (x + 22 < 0)
        {
            c = rand() % 4;
            x = s_width;
        }
    }
};