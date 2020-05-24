#include "Qnode.h"

void QueueInit(Queue* q)
{
  q->_size = 0;
  q->_front = NULL;
  q->_rear = NULL;
}
QNode* CreatNode(QDataType data)
{
  QNode* Node = (QNode*)malloc(sizeof(QNode));
  Node->_data = data;
  Node->_next = NULL;

  return Node;
}
void QueuePush(Queue* q, QDataType data)
{
  QNode* Node = CreatNode(data);
  if(!q->_rear)
  {
    q->_front = Node;
    q->_rear = Node;
  }
  else
  {
    q->_rear->_next = Node;
    q->_rear = Node;
  }
  q->_size++;
}
void QueuePop(Queue* q)
{
  if(q->_front)
  {
    QNode* next = q->_front->_next;
    free(q->_front);
    q->_front = next;
    if(!q->_front)
      q->_rear = NULL;
    q->_size--;
  }
}
int QueueEmpty(Queue* q)
{
  if(!q->_front)
    return 1;
  else
    return 0;
}
QDataType QueueFront(Queue* q)
{
  return q->_front->_data;
}
QDataType QueueBack(Queue* q)
{
  return q->_rear->_data;
}
int QueueSize(Queue* q)
{
  return q->_size;
}
void QueueDertory(Queue* q)
{
  QNode* cur = q->_front;
  while(cur)
  {
    QNode* next = cur->_next;
    free(cur);
    cur = next;
  }
  q->_front = NULL;
  q->_rear = NULL;
  q->_size = 0;
}
