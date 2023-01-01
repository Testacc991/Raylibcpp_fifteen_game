#include "Controller.h"
#include "Model.h"
#include <algorithm>
#include <random>
#include "Constants.h"
#include <cmath>

int Controller::Logic::find16()
{
    int counter = 0;
    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
    {
        if (*it == 16)
        {
            return counter;
        }
        counter++;
    }
}

void Controller::Logic::scramble()
{  
    int inversions = rand() % 1000;
    for (int i = 0; i < inversions; i++)
    {
        int check = rand() % 4 + 1;
        int tile16index = find16();
        int tile16x = tile16index % Constants::boardsize;
        int tile16y = (tile16index - tile16x) / Constants::boardsize;
        if ((tile16x+1) < Constants::boardsize && check==1)
        {
            swap(tile16y * Constants::boardsize + (tile16x + 1), tile16index);
        }
        else if ((tile16x - 1) >= 0 && check == 2)
        {
            swap(tile16y * Constants::boardsize + (tile16x - 1), tile16index);
        }
        else if ((tile16y + 1) < Constants::boardsize && check == 3)
        {
            swap((tile16y + 1) * Constants::boardsize + tile16x, tile16index);
        }
        else if ((tile16y - 1) >= 0 && check == 4)
        {
            swap((tile16y - 1) * Constants::boardsize + tile16x, tile16index);
        }
    }
}


bool Controller::Logic::check_win()
{
    int temp = 0;
    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
    {
        if (*it > temp)
        {
            temp = *it;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void Controller::Logic::draw_win(raylib::Font& fontbm)
{
    if (check_win())
    {
        _view->draw_solved_text(*_gui, true, fontbm);
        _view->draw_unsolved_text(*_gui, false, fontbm);
    }
    else
    {
        _view->draw_unsolved_text(*_gui, true, fontbm);
        _view->draw_solved_text(*_gui, false, fontbm);
    }
}

void Controller::Logic::swap(int index1,int index2)
{
    int tmp = _board->cells.at(index1);
    _board->cells.at(index1) = _board->cells.at(index2);
    _board->cells.at(index2) = tmp;
}
void Controller::Logic::on_input()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        int index = find16();
        int x = GetMouseX();
        int y = GetMouseY();
        int tilex = floor((x + Constants::cellsize) / Constants::cellsize);
        int tiley = floor((y + Constants::cellsize) / Constants::cellsize);
        int tile16x = index % Constants::boardsize;
        int tile16y = (index - tile16x) / Constants::boardsize;
        if (abs((tilex-1) - tile16x) + abs((tiley-1)-tile16y) == 1)
        {
        swap((tiley - 1) * Constants::boardsize + (tilex - 1), index);
        }
    }
}

void Controller::Logic::do_logic()
{
    on_input();
}
void Controller::Logic::do_drawing(raylib::Font& fontbm)
{
    draw_win(fontbm);
    _view->draw_cells(_board->cells,fontbm);
}