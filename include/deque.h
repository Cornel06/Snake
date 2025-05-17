#ifndef DEQUE_H
#define DEQUE_H
#include <raylib.h>

typedef Vector2 Element_t;

typedef struct Node_t
{
    Element_t data;
    struct Node_t* next;
    struct Node_t* prev;
}Node_t;

typedef struct Deque_t
{
    Node_t* first;
    Node_t* last;
    int size;
}Deque_t;

Deque_t* MakeDeque();
Node_t* MakeNode();
int IsEmpty(Deque_t*);

void PushFront(Deque_t*, Node_t*);
void PushRear(Deque_t*, Node_t*);

Element_t PopFront();
Element_t PopRear();

#endif