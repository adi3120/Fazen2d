#include "include/headers/Fazen.h"

int main(){
	Fazen game(100,100);
	game.graphics.background(whiteB);
	while(true){
		float mouseX=game.mouseHandler.GetMouseX();
		float mouseY=game.mouseHandler.GetMouseY();
		game.mouseHandler.UpdateMouseState();
		if (game.mouseHandler.IsLeftMousePressed())
		{
			Point p(mouseX,mouseY,0);
			game.graphics.draw(p);
		}
		game.graphics.display();

		if(game.keyboardHandler.CheckForUserExit()==true){
			break;
		}
	}
}