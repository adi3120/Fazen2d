#define s_width 80
#define s_height 80
#include "../include/Fazen.hpp"
#include "boundary.hpp"
#include "Ray.hpp"
#include "Particle.hpp"
void drawLineAsBoundary(Fazen2d game, std::vector<Boundary> &walls)
{
    float x1 = game.Mouse_X();
    float y1 = game.Mouse_Y();
    float x2 = x1+4+rand()%20;
    float y2 = y1;
    walls.push_back(Boundary(x1, y1, x2, y2, magentaF));

    Sleep(800);
}
void drawBlocksAsBoundary(Fazen2d game, std::vector<Boundary> &walls)
{
    int size = 3 + rand() % 11;
    std::vector<std::pair<int, int>> xcoords{{0, size}, {0, size}, {0, 0}, {size, size}};
    std::vector<std::pair<int, int>> ycoords{{0, 0}, {size, size}, {0, size}, {0, size}};
    for (int i = 0; i < 4; i++)
    {
        walls.push_back(Boundary(game.Mouse_X() + xcoords[i].first, game.Mouse_Y() + ycoords[i].first, game.Mouse_X() + xcoords[i].second, game.Mouse_Y() + ycoords[i].second, greenF));
    }
    Sleep(800);
}
int main()
{
    Fazen2d game;
    game.make2DConsole(8, 8, "ASCII RayCaster Engine");
    Particle p;
    std::vector<Boundary> walls;
    srand(time(nullptr));
    bool button = 0;
    game.background();
    game.Text(s_width / 2 - 20, s_height / 2, L"Press SPACEBAR to TOGGLE the light", whiteF | FOREGROUND_INTENSITY);
    game.Text(s_width / 2 - 20, s_height / 2 + 2, L"Left Click to Add a Line Boundary", whiteF | FOREGROUND_INTENSITY);
    game.Text(s_width / 2 - 20, s_height / 2 + 4, L"Press 'B' Button to Add a Block Boundary", whiteF | FOREGROUND_INTENSITY);
    game.Text(s_width / 2 - 20, s_height / 2 + 6, L"Press ENTER Key to Clear The Window", whiteF | FOREGROUND_INTENSITY);
    game.Text(s_width / 2 - 20, s_height / 2 + 8, L"Press ESC Key To Close the Window", whiteF | FOREGROUND_INTENSITY);
    game.Text(s_width / 2 - 20, s_height / 2 + 11, L"Press Any Key to Continue", whiteF | FOREGROUND_INTENSITY);
    game.display();
    system("PAUSE");
    while (1)
    {

        game.background();
        p.FillRays();
        if (GetAsyncKeyState(VK_SPACE))
        {
            button = !button;
            Sleep(800);
        }
        p.update(game.Mouse_X(), game.Mouse_Y());

        if (GetAsyncKeyState(VK_RETURN))
        {
            walls.clear();
            std::vector<std::pair<int, int>> xcoords{{3, s_width - 3}, {3, s_width - 3}, {3, 3}, {s_width - 3, s_width - 3}};
            std::vector<std::pair<int, int>> ycoords{{2, 2}, {s_height - 3, s_height - 3}, {2, s_height - 3}, {2, s_height - 3}};
            for (int i = 0; i < 4; i++)
            {
                walls.push_back(Boundary(xcoords[i].first, ycoords[i].first, xcoords[i].second, ycoords[i].second, redF));
            }
            Sleep(800);
        }
        if (GetAsyncKeyState((VK_LBUTTON)))
        {
            drawLineAsBoundary(game, walls);
        }
        if (GetAsyncKeyState(0x42))
        {
            drawBlocksAsBoundary(game, walls);
        }
        for (Boundary wall : walls)
        {
            wall.show(game);
        }
        if (button)
            p.look(walls, game);

        game.display();

        CHECK_USER_EXIT
    }
}
