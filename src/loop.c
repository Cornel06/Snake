//for the game loop
#include "../include/loop.h"

void FoodInit(Food* food, Vector2 position) {
    food->position = position;
}
void FoodDraw(Food* food, Saiz_t CellSize, Color color){
    DrawRectangle(food->position.x * CellSize, food->position.y * CellSize, CellSize, CellSize, color);
}

