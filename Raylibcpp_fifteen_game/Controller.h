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
    private:
        int inversions();
        bool check_win();
        int find16();
        void swap(int index1, int index2);
        void on_input();
        void draw_win(raylib::Font& fontbm);
    public:  
        bool is_solvable();
        void do_logic();//program update
        void do_drawing(raylib::Font& fontbm);
        void scramble();
    };
}