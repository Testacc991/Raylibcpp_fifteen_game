#include "raylib-cpp.hpp"
#include "View.h"
#include "Vec2.h"
#include <iostream>

void View::UI::drawcell(Mod::Cell &cell)
{
		cell.rec.DrawLines(BLACK);
		cell.numtext.Draw({ cell.position.x + 20,cell.position.y + 15 });
}
//
//void View::UI::drawendgame(bool visibility,int &screenWidth, int& screenHeight)
//{
//	if (visibility)
//	{
//		DrawText("Game over", screenWidth / 2, screenHeight / 2, 70, BLACK);
//	}
//}
//
//void View::UI::drawrepeat(bool visibility, int& screenWidth, int& screenHeight)
//{
//	if (visibility)
//	{
//		DrawText("Repeat", screenWidth / 2, screenHeight / 2, 70, BLACK);
//	}
//}
