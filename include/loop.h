#ifndef SNAKE_LOOP_H
#define SNAKE_LOOP_H
#include <raylib.h>
#include "deque.h"

typedef unsigned Saiz_t;

//FOOD:
typedef struct Food {
    Vector2 position;
    Texture2D texture;
}Food;

void FoodInit(Food* food, Vector2 position, Image image);
void FoodDraw(Food* food, Saiz_t Cellsize);
Vector2 RandomPosition(Saiz_t CellCount);

//SNAKE:
typedef struct Snake{
    Deque_t* position;
    Color color;
}Snake;

void SnakeInit(Snake* snake, Color color);
void SnakeDraw(Snake* snake, Saiz_t CellSize);

#endif