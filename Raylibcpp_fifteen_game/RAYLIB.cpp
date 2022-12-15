#include "raylib-cpp.hpp"
#include "Controller.h"
int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 400;
    int screenHeight = 400;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "15 game");
    
    View::UI ui;
    Mod::Board board({ 10,10 }, { 400,400 },{100,100});
    Controller::Logic logic(&ui, &board);
    logic.fill_board();
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    

    // Main game loop
    while (!window.ShouldClose()) {   // Detect window close button or ESC key
        // Logic
        //----------------------------------------------------------------------------------
        
        logic.doLogic();
       
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
            //textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);
            logic.doDrawing();
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
