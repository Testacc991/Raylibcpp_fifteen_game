#include "raylib-cpp.hpp"
#include "View.h"
#include "Vec2.h"
#include <iostream>
void View::UI::return_pressed_cell()
{
	raylib::Vector2 ballPosition = GetMousePosition();
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		
	}
}
void View::UI::drawcell(Mod::Cell &cell)
{
		cell.rect.DrawLines(BLACK);
		cell.numtext.Draw({ cell.position.x + 10,cell.position.y + 10 });
}

void View::UI::drawendgame(bool visibility,int &screenWidth, int& screenHeight)
{
	if (visibility)
	{
		DrawText("Game over", screenWidth / 2, screenHeight / 2, 70, BLACK);
	}
}

void View::UI::drawrepeat(bool visibility, int& screenWidth, int& screenHeight)
{
	if (visibility)
	{
		DrawText("Repeat", screenWidth / 2, screenHeight / 2, 70, BLACK);
	}
}
