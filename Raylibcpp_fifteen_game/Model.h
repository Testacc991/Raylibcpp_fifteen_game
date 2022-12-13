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
        bool selected;
        bool exists;

        raylib::Text numtext;
        raylib::Rectangle rect;

        Vector2 cellsize;
        Vector2 position;

        Cell(Vector2 position, Vector2 cellsize, bool selected, bool exists, int number) :
            position(position),
            cellsize(cellsize),

            selected(selected),
            exists(exists),
            number(number),

            numtext(std::to_string(number), 80, BLACK),
            rect(position, cellsize)
        {
            //empty
        }

    };

    class Board
    {
    public:
        
        
        std::vector <Cell> cells;
        
        Vector2 boardposition;
        Vector2 boardsize;
        Vector2 cellsize;
        Board(Vector2 boardposition, Vector2 boardsize, Vector2 cellsize) :
            
            boardposition(boardposition),
            boardsize(boardsize),
            cellsize(cellsize)
        {
            //empty
        };
        void return_cells();
        void record_cells();
    };

}