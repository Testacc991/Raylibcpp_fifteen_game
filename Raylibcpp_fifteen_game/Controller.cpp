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
void Controller::Logic::check()
{
    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
    {
        if (is_cell_pressed(_board->pointer, *it))
        {
            
        }
    }
}

void Controller::Logic::fillBoard()
{
    int counter = 1;
    for (float y = 0.0; y < _board->boardsize.y; y += _board->cellsize.y)
    {
        for (float x = 0.0; x < _board->boardsize.x; x += _board->cellsize.x)
        {
            _board->cells.push_back(
                Mod::Cell({ x,y },
                { _board->cellsize.x,_board->cellsize.y },
                true,
                counter));
                counter++;
        }
    }
}

void Controller::Logic::drawboard()
{
    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
    {
        if (it->exists)
        {
            _ui->drawcell(*it);
        }
    }
}
void Controller::Logic::updatepointer()
{
    _board->pointer.x = GetMouseX();
    _board->pointer.y = GetMouseY();
}

void Controller::Logic::doLogic()
{
    updatepointer();
    check();
}
void Controller::Logic::doDrawing()
{
    drawboard();
}
