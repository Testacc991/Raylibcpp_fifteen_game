#pragma once
#include "Vec2.h"
#include <vector>
#include "Model.h"

namespace View //All related to interface
{
    class UI
    {
    public:
        
        bool return_pressed_cell(raylib::Rectangle pointer, Mod::Cell& cell);

        bool return_repeat_is_pressed();

        void drawcell(Mod::Cell& cell);

        void drawpointer(Mod::Board& board);

        void drawendgame(bool visibility, int& screenWidth, int& screenHeight);

        void drawrepeat(bool visibility, int& screenWidth, int& screenHeight);
    };
}