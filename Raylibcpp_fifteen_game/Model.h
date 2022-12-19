#pragma once
#include "raylib-cpp.hpp"
#include <vector>
#include <string>
#include "Constants.h"
namespace Mod//Everything related to data
{
    class Gui
    {
    public:
        raylib::Text youwintext;
        raylib::Vector2 pointer;

        Gui() : 
            pointer({ 0,0 }),
            youwintext("You solve puzzle", 50, RED)
            
        {
            //empty
        };
    };
    class Cell
    {
    public:
        int number;
        bool pressed;

        raylib::Text numtext;
        raylib::Rectangle rec;

        Vector2 position;
        
        Cell(Vector2 position,bool pressed, int number) :
            //Text and cell rectangle initialization
            numtext(std::to_string(number), 80, BLACK),
            rec(position, Constants::cellsize)
        {
            this->position = position;
            this->pressed = pressed;
            this->number = number;
            this->position = position;
        }
    };

    class Board
    {
    public:
        std::vector <int> cells;
    };

}