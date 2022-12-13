#include "Controller.h"
#include "Model.h"
int Controller::Logic::check()
{
    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
    {
        if (it->selected == true)
        {
            return it->number;
        }
    }
    return 0;
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
                false,
                true,
                counter));
            counter++;
        }
    }
}

void Controller::Logic::updateboard()
{
    for (auto it = _board->cells.begin(); it != _board->cells.end(); ++it)
    {
        _ui->drawcell(*it);
    }
}
void Controller::Logic::updatepointer()
{
    _board->pointer.x = GetMouseX() - _board->pointer.width / 2;
    _board->pointer.y = GetMouseY() - _board->pointer.width / 2;
    _ui->drawpointer(*_board);
}

void Controller::Logic::doLogic()
{
    updateboard();
    updatepointer();
}

