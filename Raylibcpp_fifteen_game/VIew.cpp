#include "raylib-cpp.hpp"
#include "View.h"
#include <iostream>

void View::View::draw_cells(std::vector<int>cells)
{
    int height = 4;
    int width = 4;
    for (int y = 0; y<height;y++)
    {
        for (int x = 0; x <width; x++)
        {
            int currentNum = cells[y * width + x];
            DrawText(std::to_string(currentNum), x * width, y * width, 50);
        }
    }
}

void View::View::draw_solved_text(Mod::Gui& gui, bool visibility)
{
	if (visibility)
	{
		gui.youwintext.Draw({Constants::screenWidth/2-180,Constants::screenHeight/2-50});
	}
}
//
//void View::UI::drawrepeat(bool visibility, int& screenWidth, int& screenHeight)
//{
//	if (visibility)
//	{
//		DrawText("Repeat", screenWidth / 2, screenHeight / 2, 70, BLACK);
//	}
//}
