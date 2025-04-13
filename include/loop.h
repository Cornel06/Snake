#ifndef SNAKE_LOOP_H
#define SNAKE_LOOP_H
#include <raylib.h>

typedef unsigned Saiz_t;

typedef struct Food {
    Vector2 position;
}Food;
void FoodInit(Food* food, Vector2 position);
void FoodDraw(Food* food, Saiz_t Cellsize, Color color);


#endif