#include "raylib-cpp.hpp"
#include "Controller.h"
#include "Constants.h"
int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = Constants::screenWidth;
    int screenHeight = Constants::screenHeight;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "15 game");
    
    View::View draw;
    Mod::Board board;
    Mod::Gui gui;
    Controller::Logic logic(&draw, &board, &gui);
    /*logic.scramble();
    while (!logic.is_solvable())
    {
       logic.scramble();
    }*/
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    

    // Main game loop
    while (!window.ShouldClose()) {   // Detect window close button or ESC key
        // Logic
        //----------------------------------------------------------------------------------
        
        logic.do_logic();
       
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
            //textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);
            logic.do_drawing();
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
