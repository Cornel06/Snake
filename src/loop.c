#include "../include/loop.h"
#include "../include/deque.h"
#include <stdio.h>
#include <raymath.h>
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
        Rectangle body;
        body.x = curr->data.x*(float)CellSize;
        body.y = curr->data.y*(float)CellSize;
        body.width = (float)CellSize;
        body.height = (float)CellSize;
        DrawRectangleRounded(body, 0.5, 6, snake->color);
        curr = curr->next;
    }
}
void UpdatePosition(Deque_t* body, Vector2 direction){
    PopRear(body);
    Vector2 head = body->first->data;
    Vector2 newHead = Vector2Add(head, direction);
    PushFront(body, MakeNode(newHead)); 
}
int EventTrigger(double* LastUpdateTime, double interval){
    double CurrTime = GetTime();
    if(CurrTime - *LastUpdateTime >= interval){
        *LastUpdateTime = CurrTime;
        return 1;
    }
    return 0;
}
