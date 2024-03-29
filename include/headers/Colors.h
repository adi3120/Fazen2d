#ifndef COLORS_H
#define COLORS_H

#include<windows.h>

enum ConsoleColor {
	redF = FOREGROUND_RED | FOREGROUND_INTENSITY,
	redB = BACKGROUND_RED | BACKGROUND_INTENSITY,
	blueF = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	blueB = BACKGROUND_BLUE | BACKGROUND_INTENSITY,
	greenF = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	greenB = BACKGROUND_GREEN | BACKGROUND_INTENSITY,
	dmagentaF = 0x0005,
	magentaF = 0x000D,
	yellowF = 0x000E,
	dyellowF = 0x0006,
	dredF = 0x0004,
	greyF = 0x0008,
	dgreenF = 0x0002,
	whiteF = 0x000F,
	whiteB = BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
};

class Color{
	private:
		short fgColor;
		short bgColor;
		short value;
	public:
		Color(short fgColor=0,short bgColor=whiteB);
		void setFgColor(short fgColor);
		void setBgColor(short bgColor);
		void setValue(short value);
		short getFgColor();
		short getBgColor();
		short getValue();

};	

#endif