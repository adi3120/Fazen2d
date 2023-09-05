#include "include/headers/Fazen.h"

int main(){
	Fazen game(100,100);
	game.console.make2DConsole(8,8,(LPCTSTR) "Your Title Here");
	float x=0;

	while(true){
		game.graphics.background(whiteB);
		float mouseX = game.mouseHandler.GetMouseX();
        float mouseY = game.mouseHandler.GetMouseY();
		game.graphics.drawCircle(mouseX,mouseY,6,blueF);
		game.graphics.display();
		if(game.keyboardHandler.CheckForUserExit()==true){
			break;
		}
	}
}