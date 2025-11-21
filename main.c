#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#define WIDTH 810

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
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            int x = GetMouseX() - 10;
            int y = GetMouseY() - 70;
            if(!(x < 0 || x > WIDTH || y < 0 || y > WIDTH)) {
                x /= (WIDTH / 3);
                y /= (WIDTH / 3);
                if(game[x][y] == 0) {
                    game[x][y] = turn;
                    if(turn == 1) turn = 2;
                    else if(turn == 2) turn = 1;
                    check_game();
                }
            }
        }
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
        // Draw grid
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(game[i][j] == 0) continue;
                if(game[i][j] == 1) {
                    DrawText("X", i * (WIDTH / 3) + 40, j * (WIDTH / 3) + 80, (WIDTH / 3) - 10, BLUE);
                }
                if(game[i][j] == 2) {
                    DrawText("O", i * (WIDTH / 3) + 40, j * (WIDTH / 3) + 80, (WIDTH / 3) - 10, RED);
                }
            }
        }
    EndDrawing();
}

void game_check() {

}
