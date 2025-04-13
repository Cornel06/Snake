#ifndef DEQUE_H
#define DEQUE_H

typedef unsigned Element_t;

typedef struct Deque_t Deque_t;


void MakeDeque();
void InsertFront();
void InsertRear();
Element_t DeleteFront();
Element_t DeleteRear();
Element_t Empty();
Element_t Full();




#endif