#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
    List* new = malloc(sizeof(List));
    if (new == NULL) return NULL;
  
    new-> head= NULL;
    new-> tail= NULL;
    new-> current = NULL;
    return new;
 
}

void * firstList(List * list) 
{
  if (list->head == NULL) return NULL;
  
  list->current = list->head;
  return list->current->data;
}

void * nextList(List * list) 
{
  if(list->current == list->tail || list->current == NULL || list->head == NULL || list->head->next == NULL) return NULL;
  
  list->current = list->current->next;
  
  return list->current->data;
}

void * lastList(List * list) 
{
  if (list->tail == NULL) return NULL; 
  
  void *data = list->tail->data; 
  list->current = list->tail; 
  
  return data;
}

void * prevList(List * list) 
{
  if(list->current == NULL || list->current == list->head) return NULL;
  Node *prev = list->head;
  while (prev != NULL && prev->next != list->current) 
  {
    prev = prev->next; 
  }
  list->current = prev;
  return prev->data;
}

void pushFront(List * list, void * data) 
{
  Node * nNode = createNode(data);
  if (list->head == NULL) 
  {
    list->head = nNode;
    list->tail = nNode;
    list->current = nNode;
  } 
  else 
  {
    nNode->next = list->head;
    list->head->prev = nNode;
    list->head = nNode;
  }
}

void pushBack(List * list, void * data) 
{
  
  list->current = list->tail;
  pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
  Node *nNode = createNode(data);
  if(list->current == NULL) return;

  nNode->prev = list-> current;
  nNode->next = list-> tail;
  if (list->current == list->tail)
  {
    list->tail = nNode;
  }
  else
  {
    list->current->next = nNode;
  }
}

void * popFront(List * list) 
{
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}