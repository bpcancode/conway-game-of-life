#include <raylib.h>
#include "game.h"

int main() 
{
    const Color darkGreen = {20, 160, 133, 255};

    constexpr int screenWidth = 800;
    constexpr int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);
    Game game;

    
    
    while (!WindowShouldClose())
    {
        game.UpdateState();
        game.Update();
        BeginDrawing();
            ClearBackground(darkGreen);
            game.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}