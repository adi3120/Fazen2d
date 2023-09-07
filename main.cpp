#include "include/headers/Fazen.h"

int main(){
	Fazen game(100,100);
	while(true){
		game.graphics.background(whiteB);
		Circle c(game.mouseHandler.GetMouseX(),game.mouseHandler.GetMouseY(),10,magentaF|whiteB,'%');
		game.graphics.draw(c);
		Line l(game.mouseHandler.GetMouseY(),game.mouseHandler.GetMouseX(),game.mouseHandler.GetMouseX(),game.mouseHandler.GetMouseY(),redB,'#');
		game.graphics.draw(l);
		Text t(50,50,L"Aditya",redB);
		game.graphics.draw(t);
		game.graphics.display();
		if(game.keyboardHandler.CheckForUserExit()==true){
			break;
		}
	}
}