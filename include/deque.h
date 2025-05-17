#ifndef DEQUE_H
#define DEQUE_H

typedef unsigned Element_t;

typedef struct Node_t Node_t;
typedef struct Deque_t Deque_t;

Deque_t* MakeDeque();
Node_t* MakeNode();
Element_t IsEmpty(Deque_t*);

void PushFront(Deque_t*, Node_t*);
void PushRear(Deque_t*, Node_t*);

Element_t PopFront();
Element_t PopRear();

#endif