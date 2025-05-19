#include "../include/loop.h"
#include "../include/deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <raymath.h>

//BORDER:
void BorderInit(Rectangle* param, Saiz_t Offset, Saiz_t CellCount, Saiz_t CellSize){
    param->x = (float)Offset - 5;
    param->y = (float)Offset - 5;
    param->width = (float)CellSize * CellCount + 10;
    param->height = (float)CellSize * CellCount +10;
}

//FOOD:
void FoodInit(Food* food, Vector2 position, Image image) {
    food->position = position;
    food->texture = LoadTextureFromImage(image);
}
void FoodDraw(Food* food, Saiz_t CellSize, Saiz_t Offset){
    DrawTexture(food->texture, food->position.x * CellSize + Offset, food->position.y * CellSize + Offset, WHITE);
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
void SnakeDraw(Snake* snake, Saiz_t CellSize, Saiz_t Offset){
    Node_t* curr = snake->position->first;
    while(curr != NULL){
        Rectangle body;
        body.x = curr->data.x*(float)CellSize + Offset;
        body.y = curr->data.y*(float)CellSize + Offset;
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
void FoodCollision(Snake* snake, Food* food, Saiz_t CellCount, Saiz_t* score){
    if(Vector2Equals(snake->position->first->data, food->position)){
        food->position = RandomPosition(CellCount, snake->position);
        snake->ate = true;
        *score+=100;
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
void EdgeCollision(Snake* snake, Color color, Vector2 direction, Food* food, Saiz_t CellSize, Saiz_t CellCount, bool* pause, Saiz_t* score){
    if(snake->position->first->data.x == CellCount || snake->position->first->data.x == -1){
        GameOver(snake, color, direction, food, CellSize, CellCount, pause, score);
    }
    if(snake->position->first->data.y == CellCount || snake->position->first->data.y == -1){
        GameOver(snake, color, direction, food, CellSize, CellCount, pause, score);
    }
}
void TailCollision(Snake* snake, Color color, Vector2 direction, Food* food, Saiz_t CellSize, Saiz_t CellCount, bool* pause, Saiz_t* score){
    Node_t* head = snake->position->first;
    Node_t* curr = head->next;
    while(curr != NULL){
        if(Vector2Equals(head->data, curr->data)){
            GameOver(snake, color, direction, food, CellSize, CellCount, pause, score);
            break;
        }
        curr = curr->next;
    }
}

//END OF GAME:
void Reset(Snake* snake){
    while(!IsEmpty(snake->position)){
        PopFront(snake->position);
    }
}
void GameOver(Snake* snake, Color color, Vector2 direction, Food* food, Saiz_t CellSize, Saiz_t CellCount, bool* pause, Saiz_t* score){
    Reset(snake);
    SnakeInit(snake, color, snake->direction);
    food->position = RandomPosition(CellCount, snake->position);
    *pause = true;
    *score = 0;
}