#include "raylib-cpp.hpp"
#include "Controller.h"
int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "15 game");
    
    View::UI ui;
    Mod::Board board({ 10,10 }, { 400,400 },{100,100});
    Controller::Logic logic(&ui, &board);
    logic.fillBoard();
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    

    // Main game loop
    while (!window.ShouldClose()) {   // Detect window close button or ESC key
        // Logic
        //----------------------------------------------------------------------------------
    
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
            //textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);
            logic.doLogic();
            ui.return_pressed_cell();
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
