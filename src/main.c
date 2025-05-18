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
    
    //Vector2 pos = RandomPosition(CellCount);  //!!!!!!!! NEED TO CHANGE ONCE I AM DONE WITH TRIGGERING, IT SPAWNS ONLY ONCE!!!!

    Image image = LoadImage(IMAGE);
    ImageResize(&image, 30, 30);
    
    Vector2 direction = {1, 0};
    SnakeInit(&snake, SnakeColor, direction);

    FoodInit(&apple, RandomPosition(CellCount, snake.position), image);  //!!!!
    UnloadImage(image);

    double LastUpdateTime = GetTime();

    while(WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(ArenaColor);
       
        FoodDraw(&apple, CellSize);
        SnakeDraw(&snake, CellSize);
        
        
        if(EventTrigger(&LastUpdateTime, 0.12)==1){
            UpdatePosition(&snake, snake.direction);
            FoodCollision(&snake, &apple, CellCount);
        }
        if(IsKeyPressed(KEY_W) && snake.direction.y != 1){
            Vector2 vector = {0, -1};
            snake.direction = vector;
        }
         if(IsKeyPressed(KEY_S) && snake.direction.y != -1){
            Vector2 vector = {0, 1};
            snake.direction = vector;
        }
         if(IsKeyPressed(KEY_A) && snake.direction.x != 1){
            Vector2 vector = {-1, 0};
            snake.direction = vector;
        }
         if(IsKeyPressed(KEY_D) && snake.direction.x != -1){
            Vector2 vector = {1, 0};
            snake.direction = vector;
        }
        EndDrawing();
    }
    
    
    UnloadTexture(apple.texture);
    CloseWindow();
    return 0;
}
