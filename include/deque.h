#ifndef DEQUE_H
#define DEQUE_H

typedef unsigned Element_t;

typedef struct Node_t Node_t;
typedef struct Deque_t Deque_t;

Deque_t MakeDeque();
void PushFront();
void PushtRear();
Element_t PopFront();
Element_t PopRear();
Element_t IsEmpty();




#endif