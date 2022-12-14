#pragma once
#include "View.h"
#include "Model.h"

namespace Controller//All related to logic
{
    class Logic
    {
        
    private:
        View::UI* _ui;
        Mod::Board* _board;
        //Check if there pressed cell
        bool is_cell_pressed(raylib::Vector2 pointer, Mod::Cell& cell);
        
        void check();
        //Check can cell be moved
        bool is_cell16_near();
        
        void drawboard();
        void updatepointer();
        
    public:
        Logic(View::UI* ui, Mod::Board* board)
        {
            _ui = ui;
            _board = board;
        }
        
        void fillBoard();
        void doLogic();//program update
        void doDrawing();
    };
}