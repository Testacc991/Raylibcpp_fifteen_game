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
        raylib::Text yousolve;
        raylib::Vector2 pointer;

        Gui() : 
            pointer({ 0,0 }),
            youwintext("You solve the puzzle", 45, GREEN),
            yousolve("Solving",45,GRAY)        
        {
            //empty
        };
    };
    class Board
    {
    public:
        std::vector <int> cells = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    };

}