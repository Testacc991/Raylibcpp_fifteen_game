#pragma once
#include "Vec2.h"
#include <vector>
#include "Model.h"

namespace View //All related to interface
{
    class UI
    {
       
    public:

        void drawcell(Mod::Cell& cell);

        /*void drawendgame(bool visibility, int& screenWidth, int& screenHeight);

        void drawrepeat(bool visibility, int& screenWidth, int& screenHeight);*/
    };
}