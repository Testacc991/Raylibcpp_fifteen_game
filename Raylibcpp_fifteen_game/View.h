#pragma once
#include <vector>
#include "Model.h"

namespace View //All related to interface
{
    class View
    {
       
    public:

        void draw_cells(std::vector<int>cells);

        void draw_solved_text(Mod::Gui& gui,bool visibility);

    };
}