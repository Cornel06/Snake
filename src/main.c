#include <stdio.h>
#include <raylib.h>
#include "../include/loop.h"
#include <raymath.h>
#include "../include/deque.h"
#include <stdlib.h>

#define CellSize 30
#define CellCount 25
#define Offset 75
#define FPS 60
#define IMAGE "graphics/food.png"

Color SnakeColor = {43, 51, 24, 255};
Color ArenaColor = {172, 226, 63, 255};
Color BorderColor = {0, 153, 153, 255};
Color FontColor = {255, 255, 255, 255};

int main() {
    InitWindow(2*Offset+CellCount*CellSize, 2*Offset+CellCount*CellSize, "Snake");
    SetTargetFPS(FPS);
    bool pause = false;
    
    Rectangle param;
    BorderInit(&param, Offset, CellCount, CellSize);

    Saiz_t score = 0;
    Food apple;
    Snake snake;
    
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

        DrawRectangleLinesEx(param, 5, BorderColor);
        DrawText("Snake", Offset-5, 20, 40, FontColor);
        DrawText(TextFormat("Score: %u", score), Offset-5, Offset + CellSize * CellCount + 10, 40, FontColor);
       
        FoodDraw(&apple, CellSize, Offset);
        SnakeDraw(&snake, CellSize, Offset);        
        
        if(!pause && EventTrigger(&LastUpdateTime, 0.12)==1){
            UpdatePosition(&snake, snake.direction);
            FoodCollision(&snake, &apple, CellCount, &score);
            EdgeCollision(&snake, SnakeColor, direction, &apple, CellSize, CellCount, &pause, &score);
            TailCollision(&snake, SnakeColor, direction, &apple, CellSize, CellCount, &pause, &score);
        }

        if(IsKeyPressed(KEY_W) && snake.direction.y != 1){
            Vector2 vector = {0, -1};
            snake.direction = vector;
            pause = false;
        }
         if(IsKeyPressed(KEY_S) && snake.direction.y != -1){
            Vector2 vector = {0, 1};
            snake.direction = vector;
            pause = false;
        }
         if(IsKeyPressed(KEY_A) && snake.direction.x != 1){
            Vector2 vector = {-1, 0};
            snake.direction = vector;
            pause = false;
        }
         if(IsKeyPressed(KEY_D) && snake.direction.x != -1){
            Vector2 vector = {1, 0};
            snake.direction = vector;
            pause = false;
        }
        EndDrawing();
    }
    
    
    UnloadTexture(apple.texture);
    CloseWindow();
    return 0;
}



//PROBLEMS: snake always on pause