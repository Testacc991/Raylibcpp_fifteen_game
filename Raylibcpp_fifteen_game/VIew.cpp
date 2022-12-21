#include "raylib-cpp.hpp"
#include "View.h"
#include <iostream>

void View::View::draw_cells(std::vector<int>cells)
{
    int height = Constants::boardsize;
    int width = Constants::boardsize;
    for (int y = 0; y < height;y++)
    {
        for (int x = 0; x < width; x++)
        {
            std::string currentNum = std::to_string(cells[y * width + x]);
            
            if (currentNum != "16")
            {
                raylib::Color rec;
                rec.DrawRectangleLines(
                    x * Constants::cellsize + Constants::movex,
                    y * Constants::cellsize + Constants::movey,
                    Constants::cellsize,
                    Constants::cellsize
                );
                raylib::Text text(currentNum, 90, BLACK);
                text.Draw(x * Constants::cellsize + 15 + Constants::movex,
                    y * Constants::cellsize + 10 + Constants::movey);
            }
        }
    }
}

void View::View::draw_solved_text(Mod::Gui& gui, bool visibility)
{
	if (visibility)
	{
		gui.youwintext.Draw({Constants::screenWidth/2-200,400});
	}
}
void View::View::draw_unsolved_text(Mod::Gui& gui, bool visibility)
{
    if (visibility)
    {
        gui.yousolve.Draw({ Constants::screenWidth / 2 - 70,400});
    }
}

