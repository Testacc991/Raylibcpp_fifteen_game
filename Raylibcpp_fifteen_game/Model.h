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

        raylib::Text numtext;
        raylib::Rectangle rec;

        Vector2 cellsize;
        Vector2 position;

        Cell(Vector2 position, Vector2 cellsize, bool exists, int number) :
            position(position),
            cellsize(cellsize),

            exists(exists),
            number(number),

            //Text and cell rectangle initialization
            numtext(std::to_string(number), 80, BLACK),
            rec(position, cellsize)
        {
            //empty
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
        void return_cells();
        void record_cells();
    };

}