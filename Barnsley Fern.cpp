#define s_width 80
#define s_height 80
#include "include/Fazen.hpp"
float x = 0;
float y = 0;
void nextPoint()
{
    float p = rand() % 100;
    p -= 1.2;
    float nextX = 0;
    float nextY = 0;
    if (p < 1)
    {
        nextX = 0;
        nextY = 0.16 * y;
    }
    else if (p < 86)
    {
        nextX = 0.85 * x + 0.04 * y;
        nextY = -0.04 * x + 0.85 * y + 1.60;
    }
    else if (p < 93)
    {
        nextX = 0.20 * x - 0.26 * y;
        nextY = 0.23 * x + 0.22 * y + 1.60;
    }
    else
    {
        nextX = -0.15 * x + 0.28 * y;
        nextY = 0.26 * x + 0.24 * y + 0.44;
    }
    x = nextX;
    y = nextY;
}
void DrawPoint(Fazen2d game)
{
    float px;
    float py;
    px = game.mapBounds(x, 0, s_width, -2.1820, 2.6558);
    py = game.mapBounds(y, 0, s_height, 0, 9.9983);
    game.Plot(px, s_height-py, 0x002);
}
int main()
{
    Fazen2d game;
    game.make2DConsole(4, 1, "Barnsley Fern");
    srand(time(nullptr));
    game.background(whiteB);
    while (1)
    {
        for (int i = 0; i < 100; ++i)
        {
            nextPoint();
            DrawPoint(game);
            game.display();
        }
    }
}
