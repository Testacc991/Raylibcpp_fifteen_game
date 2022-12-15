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
        void check_pressed();
        //------------------------------------------------------------------
        //Functions to swap
        Mod::Cell& find_16cell();
        void try_swap_cell16_near();
        void swap(Mod::Cell& cell1, Mod::Cell& cell2);
        //------------------------------------------------------------------
        void draw_board();
        void update_pointer();
        
    public:
        Logic(View::UI* ui, Mod::Board* board)
        {
            _ui = ui;
            _board = board;
        }
        
        void fill_board();
        void doLogic();//program update
        void doDrawing();
    };
}