#include "raylib-cpp.hpp"
#include "View.h"
#include <iostream>

void View::View::draw_cells(std::vector<int>cells)
{
    int height = 4;
    int width = 4;
    for (int y = 0; y < height;y++)
    {
        for (int x = 0; x < width; x++)
        {
            std::string currentNum = std::to_string(cells[y * width + x]);
            raylib::Color rec;
            rec.DrawRectangleLines(x * 100, y * 100, 100, 100);
            if (currentNum != "16")
            {
                raylib::Text text(currentNum, 100, BLACK);
                text.Draw(x * 100 + 10, y * 100 + 10);
            }
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

