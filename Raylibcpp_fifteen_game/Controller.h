#pragma once
#include "View.h"
#include "Model.h"

namespace Controller//All related to logic
{
    class Logic
    {
    //Fields
    private:
        View::View* _view;
        Mod::Board* _board;
        Mod::Gui* _gui;
    public:
        Logic(View::View* view, Mod::Board* board, Mod::Gui* gui)
        {
            _view = view;
            _board = board;
            _gui = gui;

        }
    //Methods
    private:
        
        //Functions to check pressed cell

        bool is_cell_pressed(raylib::Vector2 pointer, Mod::Cell& cell);
        void check_pressed();

        //Functions to swap

        int& find_16cell();
        void swap();

        //Function to scramble
        int inversions(std::vector<Mod::Cell>& cells);
        
        //Function to check win
        
        bool check_win(std::vector<int>& cells);

        //Functions to update
        void draw_win();
        void draw_board();
        void update_pointer();
    
    public:  
        bool is_solvable();
        void scramble();
        void fill_board();
        void do_logic();//program update
        void do_drawing();
    };
}