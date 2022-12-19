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
        
    public:  
        void do_logic();//program update
        void do_drawing();
    };
}