#pragma once
#include "View.h"
#include "Model.h"

namespace Controller//All related to logic
{
    class Logic
    {
        View::UI* _ui;
        Mod::Board* _board;
        //Check if there pressed cell
        int check();
        //Change configuration
        void changeConf();
        //Revord configuration 
        void recordConf();
        //Check if configuration is correct
        void checkConf();
        //Reset configuration
        void drawboard();
    public:
        Logic(View::UI* ui, Mod::Board* board)
        {
            _ui = ui;
            _board = board;
        }
        void fillBoard();
        void doLogic();
    };
}