#include "raylib.h"
#include <stdlib.h>
#define WIDTH 800

// Function inits
void update(); // Update and draw one frame
void check_game(); // Check game state

// Game variables
int game[3][3] = {0}; // 0 - empty, 1 - X, 2 - O
int gameState = 0; // 0 - not playing, 1 - playing, 2 - tie, 3 - X won, 4 - O won
int turn = 1; // 1 - X, 2 - 0

int main() {
    const int screenWidth = WIDTH + 20;
    const int screenHeight = WIDTH + 80;

    InitWindow(screenWidth, screenHeight, "tic tac toe");

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
void update() {
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Tic Tac Toe", 10, 10, 30, DARKGRAY);
        if(gameState == 0) DrawText("X to start. Click to make your move.", 10, 40, 20, DARKGRAY);
        else if(gameState == 1) DrawText((turn == 1 ? "X's turn" : "O's turn"), 10, 40, 20, DARKGRAY);
        else if(gameState == 2) DrawText("It's a tie!", 10, 40, 20, ORANGE);
        else if(gameState == 3) DrawText("X won! Click anywhere to play again.", 10, 40, 20, GREEN);
        else if(gameState == 3) DrawText("O won! Click anywhere to play again.", 10, 40, 20, GREEN);
        DrawFPS(WIDTH - 65, 10);
        DrawRectangle(10, 70, WIDTH, WIDTH, LIGHTGRAY); // Background
        DrawRectangle(10 + WIDTH / 3, 70, 5, WIDTH, DARKGRAY); // vertical bar 1
        DrawRectangle(10 + (WIDTH * 2) / 3, 70, 5, WIDTH, DARKGRAY); // vertical bar 2
        DrawRectangle(10, 70 + WIDTH / 3, WIDTH, 5, DARKGRAY); // horizontal bar 1
        DrawRectangle(10, 70 + (WIDTH * 2) / 3, WIDTH, 5, DARKGRAY); // horizontal bar 2
    EndDrawing();
}

void game_check() {

}
