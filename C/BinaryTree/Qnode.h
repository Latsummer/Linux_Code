#include<stdio.h>
#include<stdlib.h>
#include "binaryTree.h"

typedef BTNode* QDataType;
typedef struct QListNode
{
  QDataType _data;
  struct QListNode* _next;
}QNode;

typedef struct Queue{
  size_t _size;
  QNode* _front;
  QNode* _rear;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
QNode* CreatNode(QDataType data);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDertory(Queue* q);
