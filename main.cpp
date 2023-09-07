#include "include/headers/Fazen.h"

int main(){
	Fazen game(100,100);
	while(true){
		float mouseX=game.mouseHandler.GetMouseX();
		float mouseY=game.mouseHandler.GetMouseY();
		Color c1(magentaF,whiteB);
		Color c2(greenF,whiteB);
		game.graphics.background(whiteB);

		Circle c(mouseX,mouseY,10,c1.getValue());
		game.graphics.draw(c);
		Line l(mouseY,mouseX,mouseX,mouseY,redB);
		game.graphics.draw(l);
		Text t(50,50,100,c2.getValue());
		game.graphics.draw(t);
		Box b(mouseY,mouseX,10,20,c1.getValue());
		game.graphics.draw(b);
		game.graphics.display();

		if(game.keyboardHandler.CheckForUserExit()==true){
			break;
		}
	}
}