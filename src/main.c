#include <stdio.h>
#include <raylib.h>
#include "../include/loop.h"
#include <raymath.h>
#include "../include/deque.h"

#define CellSize 30
#define CellCount 25
#define FPS 60
#define IMAGE "graphics/food.png"

Color SnakeColor = {43, 51, 24, 255};
Color ArenaColor = {172, 226, 63, 255};


int main() {
    InitWindow(CellCount*CellSize, CellCount*CellSize, "Snake");
    SetTargetFPS(FPS);
    
    Food apple;
    Snake snake;
    Vector2 pos = RandomPosition(CellCount);  //!!!!!!!! NEED TO CHANGE ONCE I AM DONE WITH TRIGGERING, IT SPAWNS ONLY ONCE!!!!

    Image image = LoadImage(IMAGE);
    ImageResize(&image, 30, 30);    

    FoodInit(&apple, pos, image);
    UnloadImage(image);
    
    SnakeInit(&snake, SnakeColor);

    while(WindowShouldClose() == false) {
        BeginDrawing();
        
        ClearBackground(ArenaColor);
        FoodDraw(&apple, CellSize);
        SnakeDraw(&snake, CellSize);
        
        EndDrawing();
    }
    
    
    UnloadTexture(apple.texture);
    CloseWindow();
    return 0;
}
