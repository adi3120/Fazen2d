#define s_width 300
#define s_height 100
#include "../include/Fazen.hpp"
#include "boundary.hpp"
#include "Ray.hpp"
#include "Particle.hpp"
int main()
{
    Fazen2d game;
    game.make2DConsole(4, 6);
    Particle p;
    std::vector<Boundary> walls;
    srand(time(nullptr));
    bool button = 0;

    while (1)
    {
        game.background();
        if (GetAsyncKeyState(VK_SPACE))
        {
            
            button = !button;
            Sleep(100);
        }
        p.update(game.Mouse_X(), game.Mouse_Y());
        if (button)
            p.look(walls, game);
        if (GetAsyncKeyState(VK_RETURN))
        {
            walls.clear();
        }
        if (GetAsyncKeyState((VK_LBUTTON)))
        {
            walls.push_back(Boundary(game.Mouse_X(), game.Mouse_Y(), game.Mouse_X() + 20, game.Mouse_Y()));
            walls.push_back(Boundary(game.Mouse_X(), game.Mouse_Y() + 20, game.Mouse_X() + 20, game.Mouse_Y() + 20));
            walls.push_back(Boundary(game.Mouse_X(), game.Mouse_Y(), game.Mouse_X(), game.Mouse_Y() + 20));
            walls.push_back(Boundary(game.Mouse_X() + 20, game.Mouse_Y(), game.Mouse_X() + 20, game.Mouse_Y() + 20));
        }
        for (Boundary wall : walls)
        {
            wall.show(game);
        }
        game.display();

        CHECK_USER_EXIT
    }
}
