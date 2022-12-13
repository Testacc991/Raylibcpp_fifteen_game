#include "raylib-cpp.hpp"
#include "View.h"
#include "Vec2.h"
#include <iostream>
bool View::UI::return_pressed_cell(raylib::Rectangle pointer, Mod::Cell &cell)
{

	raylib::Vector2 ballPosition = GetMousePosition();
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (pointer.CheckCollision(cell.rec))
		{
			return true;
		}

	}
}
void View::UI::drawcell(Mod::Cell &cell)
{
		cell.rec.DrawLines(BLACK);
		cell.numtext.Draw({ cell.position.x + 10,cell.position.y + 10 });
}

void View::UI::drawpointer(Mod::Board& board)
{
	board.pointer.Draw(BLACK);
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
