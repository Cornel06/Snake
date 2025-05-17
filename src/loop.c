#include "../include/loop.h"
#include "../include/deque.h"
#include <stdio.h>
//FOOD:
void FoodInit(Food* food, Vector2 position, Image image) {
    food->position = position;
    food->texture = LoadTextureFromImage(image);
}
void FoodDraw(Food* food, Saiz_t CellSize){
    DrawTexture(food->texture, food->position.x * CellSize, food->position.y * CellSize, WHITE);
}
Vector2 RandomPosition(Saiz_t CellCount) {
    Saiz_t x = GetRandomValue(0, CellCount - 1);
    Saiz_t y = GetRandomValue(0, CellCount - 1);
    Vector2 Coords = {x, y};
    return Coords;
}

//SNAKE:
void SnakeInit(Snake* snake, Color color){
    snake->position = MakeDeque();
    Vector2 v1={6.0f, 9.0f};
    Vector2 v2={5.0f, 9.0f};
    Vector2 v3={4.0f, 9.0f};
    PushRear(snake->position, MakeNode(v1));
    PushRear(snake->position, MakeNode(v2));
    PushRear(snake->position, MakeNode(v3));
    snake->color = color;
}
void SnakeDraw(Snake* snake, Saiz_t CellSize){
    Node_t* curr = snake->position->first;
    while(curr != NULL){
        DrawRectangle(curr->data.x*CellSize, curr->data.y*CellSize, CellSize, CellSize, snake->color);
        curr = curr->next;
    }
}
