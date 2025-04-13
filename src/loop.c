#include "../include/loop.h"

//FOOD:
void FoodInit(Food* food, Vector2 position, Image image) {
    food->position = position;
    food->texture = LoadTextureFromImage(image);
}
void FoodDraw(Food* food, Saiz_t CellSize, Color color){
    DrawTexture(food->texture, food->position.x * CellSize, food->position.y * CellSize, WHITE);
}
Vector2 RandomPosition(Saiz_t CellCount) {
    Saiz_t x = GetRandomValue(0, CellCount - 1);
    Saiz_t y = GetRandomValue(0, CellCount - 1);
    Vector2 Coords = {x, y};
    return Coords;
}

//SNAKE: