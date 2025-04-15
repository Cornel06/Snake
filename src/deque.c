#include "../include/deque.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
    void* arr;
    Node_t* next;
    Node_t* prev;
}Node_t;

typedef struct Deque_t
{
    Node_t* first;
    Node_t* last;
}Deque_t;

Deque_t* MakeDeque() {
    Deque_t* deque=malloc(sizeof(Deque_t));
    if(!deque) {
        perror("Problem allocating memory for the deque\n");
        exit(-1);
    }
    deque->first=NULL;
    deque->last=NULL;
    return deque;
}

Element_t IsEmpty(Deque_t* deque){
    if(deque->first==NULL || deque->last==NULL)
        return 0;
    else return 1;
}

void PushFront();

void PushtRear();

Element_t PopFront();

Element_t PopRear();