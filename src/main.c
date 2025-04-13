#include <stdio.h>
#include <raylib.h>
#include "../include/loop.h"

//gcc main.c -o main -lraylib -lm -ldl -lpthread -lGL -lrt -lX11

#define CellSize 30
#define CellCount 25

Color SnakeColor = {43, 51, 24, 255};
Color ArenaColor = {173, 204, 96, 255};


int main() {
    InitWindow(CellCount*CellSize, CellCount*CellSize, "Snake");
    SetTargetFPS(60);
    
    Food apple;
    Vector2 pos={5, 6};
    FoodInit(&apple, pos);
    while(WindowShouldClose() == false) {
        BeginDrawing();
        //Drawing
        ClearBackground(ArenaColor);
        FoodDraw(&apple, CellSize, SnakeColor);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
