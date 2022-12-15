#pragma once
#include "raylib-cpp.hpp"
#include "Vec2.h"
#include <vector>
#include <string>
namespace Mod//Everything related to data
{
    class Cell
    {
    public:
        int number;
        bool exists;
        bool pressed;

        raylib::Text numtext;
        raylib::Rectangle rec;

        Vector2 cellsize;
        Vector2 position;
        
        Cell(Vector2 position, Vector2 cellsize, bool exists,bool pressed, int number) :
            position(position),
            cellsize(cellsize),
            pressed(pressed),
            exists(exists),
            number(number),

            //Text and cell rectangle initialization
            numtext(std::to_string(number), 80, BLACK),
            rec(position, cellsize)
        {
            //empty
        }
        Cell(const Cell& cell) noexcept
        {
            this->number = cell.number;
            this->exists = cell.exists;
            this->pressed = cell.pressed;
            this->cellsize = cell.cellsize;
            this->position = cell.position;
            this->numtext = cell.numtext;
            this->rec = cell.rec;
        }
        
        Cell& operator=(const Cell& other) {
            if (this == &other) {
                return *this;
            }
            this->number = other.number;
            //this->exists = other.exists;
            this->pressed = other.pressed;
            this->cellsize = other.cellsize;
            this->position = other.position;
            this->rec.x = other.rec.x;
            this->rec.y = other.rec.y;
            return *this;
        }
    };

    class Board
    {
    public:
        std::vector <Cell> cells;
        raylib::Vector2 pointer;
        Vector2 boardposition;
        Vector2 boardsize;
        Vector2 cellsize;
        Board(raylib::Vector2 boardposition, raylib::Vector2 boardsize, raylib::Vector2 cellsize) :
            boardposition(boardposition),
            boardsize(boardsize),
            cellsize(cellsize),
            //Pointer initialization
            pointer({0,0})
        {
            //empty
        };
    };

}