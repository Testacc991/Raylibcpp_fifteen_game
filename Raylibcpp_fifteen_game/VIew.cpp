#include "raylib-cpp.hpp"
#include "View.h"
#include <iostream>

void View::View::draw_cells(std::vector<int>cells,raylib::Font& fontbm)
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
                fontbm.DrawText(
                    currentNum,
                    { (float)x * Constants::cellsize +6+ Constants::movex,
                    (float)y * Constants::cellsize +5+ Constants::movey },
                    90,
                    2,
                    BLACK
                );
            }
        }
    }
}

void View::View::draw_solved_text(Mod::Gui& gui, bool visibility, raylib::Font& fontbm)
{
    if (visibility)
    {
        fontbm.DrawText(
            "You solved the puzzle",
            { Constants::screenWidth / 2 - 180,400 },
            38,
            2,
            GREEN);
	}
}
void View::View::draw_unsolved_text(Mod::Gui& gui, bool visibility, raylib::Font& fontbm)
{
    if (visibility)
    {
        fontbm.DrawText(
            "Solving",
            { Constants::screenWidth / 2 - 70,400 },
            45,
            2,
            GRAY);
    }
}

