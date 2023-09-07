#include "include/headers/Fazen.h"

int main(){
	Fazen game(100,100);
	while(true){
		game.graphics.background(whiteB);
		Circle c(game.mouseHandler.GetMouseX(),game.mouseHandler.GetMouseY(),10,magentaF|whiteB,'%');
		game.graphics.drawShape(c);
		game.graphics.display();
		if(game.keyboardHandler.CheckForUserExit()==true){
			break;
		}
	}
}