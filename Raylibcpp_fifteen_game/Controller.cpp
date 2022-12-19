#include "Controller.h"
#include "Model.h"
#include <algorithm>
#include <random>
#include "Constants.h"
#include <cmath>
//
//void Controller::Logic::check_pressed()//in doLogic
//{
//    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
//    {
//        if (is_cell_pressed(_gui->pointer, *it))
//        {
//            
//
//        }
//    }
//}
//
//void Controller::Logic::find_16cell()
//{
//    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
//    {
//        if (*it==16) { return it; }
//    }
//}
//
//
//
//void Controller::Logic::swap(Mod::int& cell1, Mod::int& cell2)
//{
//     
//}
//
//int Controller::Logic::inversions(std::vector<Mod::Cell>& cells)
//{
//    int inv = 0;
//    for (int i = 0; i<_board->cells.size(); i++)
//    {
//        for (int j = i+1; j< _board->cells.size(); j++)
//        {
//            if (cells.at(i).number > cells.at(j).number && cells.at(j).number != 16)
//            {
//                inv++;
//            }
//        }
//    }
//    return inv;
//}
//
//bool Controller::Logic::is_solvable()
//{
//    
//}
//
//void Controller::Logic::scramble()
//{   
//    std::default_random_engine engine(std::random_device{}());
//
//    std::shuffle(begin(_board->cells), end(_board->cells), engine);
//}
//
//void Controller::Logic::fill_board()
//{
//    
//}
//
//bool Controller::Logic::check_win(std::vector<int>&cells)
//{
//    int temp = 0;
//    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
//    {
//        if (*it > temp)
//        {
//            temp = *it;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//void Controller::Logic::draw_win()
//{
//    if (check_win(_board->cells))
//    {
//        _view->draw_solved_text(*_gui, true);
//    }
//    else
//    {
//        _view->draw_solved_text(*_gui, false);
//    }
//}
//
//void Controller::Logic::draw_board()
//{
//    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
//    {
//        if (*it!=16)
//        {
//            _view->draw_cell(it);
//        }
//    }
//}
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
        int x = GetMouseX();
        int y = GetMouseY();
        int tilex = floor((x + 100) / 100); 
        int tiley = floor((y + 100) / 100);
        int tile16x = find16() % 4;
        int tile16y = (find16() - tile16x) / 4;
        if (abs((tilex-1) - tile16x) + abs((tiley-1)-tile16y) == 1)
        {
        swap((tiley - 1) * 4 + (tilex - 1), find16());
        }
    }
}

void Controller::Logic::do_logic()
{
    on_input();
    //check_pressed();
}
void Controller::Logic::do_drawing()
{
    //draw_board();
    _view->draw_cells(_board->cells);
}
