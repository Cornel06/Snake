#ifndef SNAKE_LOOP_H
#define SNAKE_LOOP_H
#include <raylib.h>

typedef unsigned Saiz_t;

//FOOD:
typedef struct Food {
    Vector2 position;
    Texture2D texture;
}Food;
void FoodInit(Food* food, Vector2 position, Image image);
void FoodDraw(Food* food, Saiz_t Cellsize, Color color);
Vector2 RandomPosition(Saiz_t CellCount);

//SNAKE:
typedef struct Snake
{

}Snake;

#endif