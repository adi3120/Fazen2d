#define s_width 80
#define s_height 80
#include "include\Fazen.hpp"
#include "PongIncludes\Ball.hpp"
#include "PongIncludes\Paddel.hpp"

void showScores(Fazen2d game,Paddel p1,Paddel p2)
{
    game.drawTextFromInt(10,10,L"PLAYER 1 SCORE : ",p1.score);
    game.drawTextFromInt(s_width-30,10,L"PLAYER 2 SCORE : ",p2.score);
}
int main()
{
    Fazen2d game;
    game.make2DConsole(8,8,"Pong");
    TIMEVARS
    Ball b;
    Paddel p1(10);
    Paddel p2(s_width-10);
    while(1)
    {
        TIMER
        game.background();
        game.drawRectangle(p1.x,p1.y,p1.w,p1.h,0,redF);
        game.drawRectangle(p2.x,p2.y,p2.w,p2.h,0,blueF);
        game.drawRectangle(b.x,b.y,2,2,0,greenF);
        b.update(felapsedTime);
        b.edges(p1.score,p2.score);
        b.checkCollide(p1,p2);
        p1.clipY();
        p2.clipY();
        if(GetAsyncKeyState(VK_UP))
        {
            p2.y-=70*felapsedTime;
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            p2.y+=70*felapsedTime;
        }
        if(GetAsyncKeyState(0x57))
        {
            p1.y-=70*felapsedTime;
        }
        if(GetAsyncKeyState(0x53))
        {
            p1.y+=70*felapsedTime;
        }
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            if(p1.score>p2.score)
            {
                game.Text(30,30,L"Player 1 Wins");
            }
            else
            {
                game.Text(30,30,L"Player 2 Wins");
            }
            game.display();
            break;
        }
        showScores(game,p1,p2);
        game.display();

    }
}