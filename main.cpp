#include "include/headers/Fazen.h"

int main(){
	Fazen game(100,100);
	game.console.make2DConsole(8,8,(LPCTSTR) "Your Title Here");
	float x=0;

	while(true){
		game.graphics.background(whiteB);
		game.graphics.drawCircle(50,50,10,blueF);
		game.graphics.display();
		if(game.keyboardHandler.CheckForUserExit()){
			break;
		}
	}
}