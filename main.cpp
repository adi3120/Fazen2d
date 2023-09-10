#include "include/headers/Fazen.h"

int main(){
	Fazen game(100,100);
	game.graphics.background(whiteB);

	Box b(0,20,20,60,redF);
	Line l(0,0,10,10,blueF);
	Circle c(20,20,10,greenF);
	while(true){
		game.graphics.background(whiteB);
		game.graphics.draw(b);
		game.graphics.draw(l);
		game.graphics.draw(c);
		b.translate(0.01,0.01);
		l.translate(0.1,0.1);
		c.translate(0.1,0.1);
		game.graphics.display();
		if(game.keyboardHandler.CheckForUserExit()){
			break;
		}
	}
}