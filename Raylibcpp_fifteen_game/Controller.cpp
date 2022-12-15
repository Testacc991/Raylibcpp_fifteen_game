#include "Controller.h"
#include "Model.h"
#include <algorithm>
#include <random>
bool Controller::Logic::is_cell_pressed(raylib::Vector2 pointer, Mod::Cell& cell)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        if (cell.rec.CheckCollision(pointer))
        {
            return true;
        }
    }
}
void Controller::Logic::check_pressed()//in doLogic
{
    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
    {
        if (is_cell_pressed(_board->pointer, *it))
        {
            it->pressed = true;
            try_swap_cell16_near();
        }
    }
}
Mod::Cell& Controller::Logic::find_16cell()
{
    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
    {
        if (!it->exists) { return *it; }
    }
}
void Controller::Logic::try_swap_cell16_near()
{
    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
    {
       Mod::Cell& empty = find_16cell();
       //if (abs(empty.position.x - it->position.x) + abs(empty.position.y - it->position.y)==_board->cellsize.x)
       //{
            if (it->pressed)
            {
                it->pressed = false;
                swap(empty,*it);
            }
       //}
    }
}

void Controller::Logic::swap(Mod::Cell& cell1, Mod::Cell& cell2)
{
    Mod::Cell temp(cell1);
    cell1 = cell2;
    cell2 = temp;
    
}

void Controller::Logic::fill_board()
{
    int counter = 1;
    for (float y = 0.0; y < _board->boardsize.y; y += _board->cellsize.y)
    {
        for (float x = 0.0; x < _board->boardsize.x; x += _board->cellsize.x)
        {
            if (counter != 16)
            {
                _board->cells.push_back(
                    Mod::Cell({ x,y },
                        { _board->cellsize.x,_board->cellsize.y },
                        true,
                        false,
                        counter));
                counter++;
            }
            else
            {
                _board->cells.push_back(
                    Mod::Cell({ x,y },
                        { _board->cellsize.x,_board->cellsize.y },
                        false,
                        false,
                        counter));
                counter++;
            }
            
        }
    }
}

void Controller::Logic::draw_board()
{
    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
    {
        if (it->exists)
        {
            _ui->drawcell(*it);
        }
    }
}
void Controller::Logic::update_pointer()
{
    _board->pointer.x = GetMouseX();
    _board->pointer.y = GetMouseY();
}

void Controller::Logic::doLogic()
{
    update_pointer();
    check_pressed();
}
void Controller::Logic::doDrawing()
{
    draw_board();
}
