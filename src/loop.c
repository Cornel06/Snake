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
Vector2 GenerateRandomCoord(Saiz_t CellCount){
    int x = GetRandomValue(0, CellCount - 1);
    int y = GetRandomValue(0, CellCount - 1);
    Vector2 Coords = {x, y};
    return Coords;
}
Vector2 RandomPosition(Saiz_t CellCount, Deque_t* body) {
    Vector2 Coords = GenerateRandomCoord(CellCount);
    while(ElementInSnake(Coords, body)){
        Coords = GenerateRandomCoord(CellCount);
    }
    return Coords;
}
//SNAKE:
void SnakeInit(Snake* snake, Color color, Vector2 direction){
    snake->position = MakeDeque();
    Vector2 v1={6.0f, 9.0f};
    Vector2 v2={5.0f, 9.0f};
    Vector2 v3={4.0f, 9.0f};
    PushRear(snake->position, MakeNode(v1));
    PushRear(snake->position, MakeNode(v2));
    PushRear(snake->position, MakeNode(v3));
    snake->color = color;
    snake->direction = direction;
    snake->ate = false;
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

//MOVEMENT:
void UpdatePosition(Snake* snake, Vector2 direction){
    PushFront(snake->position, MakeNode(Vector2Add(snake->position->first->data, direction)));
    if(snake->ate==true){
        snake->ate = false;
    }
    else{
        PopRear(snake->position);
    }
}
int EventTrigger(double* LastUpdateTime, double interval){
    double CurrTime = GetTime();
    if(CurrTime - *LastUpdateTime >= interval){
        *LastUpdateTime = CurrTime;
        return 1;
    }
    return 0;
}

//COLLISION:
void FoodCollision(Snake* snake, Food* food, Saiz_t CellCount){
    if(Vector2Equals(snake->position->first->data, food->position)){
        food->position = RandomPosition(CellCount, snake->position);
        snake->ate = true;
    }
}
int ElementInSnake(Vector2 Coords, Deque_t* body){
    Node_t* curr = body->first;;
    while(curr != NULL){
        if(Vector2Equals(Coords, curr->data)){
            return 1;
        }
        curr = curr->next;
    }
    return 0;
} 