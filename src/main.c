#include <stdio.h>
#include <raylib.h>
#include "../include/loop.h"

//gcc main.c -o main -lraylib -lm -ldl -lpthread -lGL -lrt -lX11

#define CellSize 30
#define CellCount 25
#define FPS 60
#define IMAGE "graphics/food.png"

Color SnakeColor = {43, 51, 24, 255};
Color ArenaColor = {173, 204, 96, 255};


int main() {
    InitWindow(CellCount*CellSize, CellCount*CellSize, "Snake");
    SetTargetFPS(FPS);
    
    Food apple;
    Vector2 pos = RandomPosition(CellCount);  //!!!!!!!! NEED TO CHANGE ONCE I AM DONE WITH TRIGGERING, IT SPAWNS ONLY ONCE!!!!

    Image image = LoadImage(IMAGE);
    ImageResize(&image, 30, 30);    
    
    FoodInit(&apple, pos, image);
    UnloadImage(image);
    
    while(WindowShouldClose() == false) {
        BeginDrawing();
        
        ClearBackground(ArenaColor);
        FoodDraw(&apple, CellSize, SnakeColor);
        
        EndDrawing();
    }
    
    
    UnloadTexture(apple.texture);
    CloseWindow();
    return 0;
}
