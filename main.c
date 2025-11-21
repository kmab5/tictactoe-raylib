
#include "raylib.h"

void update(); // Update and draw one frame

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        update();
    }

    CloseWindow();

    return 0;
}

// Update and draw game frame
void update()
{
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("This is a raylib example", 10, 40, 20, DARKGRAY);
        DrawFPS(10, 10);
    EndDrawing();
}
