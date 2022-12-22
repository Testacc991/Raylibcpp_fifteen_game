#include "Controller.h"
#include "Model.h"
#include <algorithm>
#include <random>
#include "Constants.h"
#include <cmath>
int Controller::Logic::inversions()
{
    int inv = 0;
    for (int i = 0; i<_board->cells.size(); i++)
    {
        for (int j = i+1; j< _board->cells.size(); j++)
        {
            if (_board->cells.at(i) > _board->cells.at(j) && _board->cells.at(j) != 16)
            {
                inv++;
            }
        }
    }
    return inv;
}
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
bool Controller::Logic::is_solvable()
{
    int index = find16();
    int tile16x = index % Constants::boardsize;
    int tile16y = (index - tile16x) / Constants::boardsize;
        if(tile16y % 2 != 0 && inversions() % 2 == 0 )
        {
            return true;
        }    
        if(tile16y % 2 == 0 && inversions() % 2 != 0)
        {
            return true;
        }
    return false;
}

void Controller::Logic::scramble()
{   
    std::default_random_engine engine(std::random_device{}());

    std::shuffle(begin(_board->cells), end(_board->cells), engine);
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