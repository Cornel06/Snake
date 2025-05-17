#include "../include/deque.h"
#include <stdio.h>
#include <stdlib.h>

#define EMPTY_VECTOR (Vector2){-1.0f, -1.0f}

Deque_t* MakeDeque() {
    Deque_t* deque = malloc(sizeof(Deque_t));
    if(!deque) {
        perror("Problem allocating memory for the deque\n");
        exit(-1);
    }
    deque->first = NULL;
    deque->last = NULL;
    deque->size = 0;
    return deque;
}

Node_t* MakeNode(Element_t elem){
    Node_t* newnode = malloc(sizeof(Node_t));
    if(!newnode) {
        perror("Problem allocating memory for the node");
        exit(-1);
    }
    newnode->data = elem;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

int IsEmpty(Deque_t* deque){
    if(deque->size == 0)
        return 1;
    else return 0;
}

void PushFront(Deque_t* deque, Node_t* newnode){
    newnode->next = deque->first;
    if(IsEmpty(deque)){
        deque->last=newnode;
    }
    else{
        deque->first->prev = newnode;
    }
    deque->first = newnode;
    deque->size++;
}

void PushRear(Deque_t* deque, Node_t* newnode){
    newnode->prev = deque->last;
    if(IsEmpty(deque)){
        deque->first=newnode;
    }
    else{
        deque->last->next = newnode;
    }
    deque->last = newnode;
    deque->size++;
}

Element_t PopFront(Deque_t* deque){
    if(IsEmpty(deque)){
        return EMPTY_VECTOR;
    }
    Element_t poppedItem;
    Node_t* tmp = deque->first;
    poppedItem = tmp->data;
    if(deque->first == deque->last){
        deque->first=NULL;
        deque->last=NULL;
    }
    else{
        deque->first = tmp->next;
        deque->first->prev = NULL;
    }
    free(tmp);
    deque->size--;
    return poppedItem;
}

Element_t PopRear(Deque_t* deque){
    if(IsEmpty(deque)){
        return EMPTY_VECTOR;
    }
    Element_t poppedItem;
    Node_t* tmp = deque->last;
    poppedItem = tmp->data;
    if(deque->first == deque->last){
        deque->first=NULL;
        deque->last=NULL;
    }
    else{
        deque->last = tmp->prev;
        deque->last->next = NULL;
    }
    free(tmp);
    deque->size--;
    return poppedItem;
}