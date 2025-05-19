#ifndef SNAKE_LOOP_H
#define SNAKE_LOOP_H
#include <raylib.h>
#include "deque.h"

typedef unsigned Saiz_t;

//BORDER:
void BorderInit(Rectangle* param, Saiz_t Offset, Saiz_t CellCount, Saiz_t CellSize);

//FOOD:
typedef struct Food {
    Vector2 position;
    Texture2D texture;
}Food;

void FoodInit(Food* food, Vector2 position, Image image);
void FoodDraw(Food* food, Saiz_t Cellsize, Saiz_t Offset);
Vector2 GenerateRandomCoord(Saiz_t CellCount);
Vector2 RandomPosition(Saiz_t CellCount, Deque_t* body);

//SNAKE:
typedef struct Snake{
    Deque_t* position;
    Color color;
    Vector2 direction;
    bool ate;
}Snake;

void SnakeInit(Snake* snake, Color color, Vector2 direction);
void SnakeDraw(Snake* snake, Saiz_t CellSize, Saiz_t Offset);

//MOVEMENT:
void UpdatePosition(Snake* snake, Vector2 direction);
int EventTrigger(double* LastUpdateTime, double interval);

//COLLISION:
void FoodCollision(Snake* snake, Food* food, Saiz_t CellCount, Saiz_t* score);
int ElementInSnake(Vector2 Coords, Deque_t* body);
void EdgeCollision(Snake* snake, Color color, Vector2 direction, Food* food, Saiz_t CellSize, Saiz_t CellCount, bool* pause, Saiz_t* score);
void TailCollision(Snake* snake, Color color, Vector2 direction, Food* food, Saiz_t CellSize, Saiz_t CellCount, bool* pause, Saiz_t* score);

//END OF GAME:
void Reset(Snake* snake);
void GameOver(Snake* snake, Color color, Vector2 direction, Food* food, Saiz_t CellSize, Saiz_t CellCount, bool* pause, Saiz_t* score);

#endif