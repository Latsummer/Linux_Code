#include "Slist.h"


SListNode* CreatNode(SLTDataType data)
{
  SListNode* Node = (SListNode*)malloc(sizeof(SListNode));
  Node->_data = data;
  Node->_next = NULL;
  
  return Node;
}
void Print(SList* p)
{
  SListNode* cur = p->_head;
  while(cur)
  {
    printf("%d ", cur->_data);
    cur = cur->_next;
  }
  printf("\n");
}
void PushBack(SList* p, SLTDataType data)
{
  SListNode* Node = CreatNode(data);
  if(!p->_head)
  {
    p->_head = Node;
    return;
  }
  SListNode* cur = p->_head;
  while(cur->_next)
    cur = cur->_next;
  cur->_next = Node;
}
void PopBack(SList* p)
{
  SListNode* cur = p->_head;
  SListNode* prev = NULL;
  if(!cur || !cur->_next)
  {
    free(cur);
    p->_head = NULL;
    return;
  }
  while(cur->_next)
  {
    prev = cur;
    cur = cur->_next;
  }
  free(cur);
  cur = NULL;
  prev->_next = NULL;
}
void PushFront(SList* p, SLTDataType data)
{
  SListNode* Node = CreatNode(data);
  Node->_next = p->_head;
  p->_head = Node;
  
}
void PopFront(SList*p)
{
  SListNode* cur = p->_head;
  if(!cur || !cur->_next)
  {
    free(cur);
    p->_head = NULL;
    return;
  }
  p->_head = cur->_next;
  free(cur);
}
SListNode* Find(SList* p, SLTDataType data)
{
  SListNode* cur = p->_head;
  while(cur)
  {
    if(cur->_data == data)
      return cur;
    cur = cur->_next;
  }
  return NULL;
}
void SlistInsert_After(SListNode* pos, SLTDataType data)
{
  if(!pos)
    return;
  SListNode* Node = CreatNode(data);
  SListNode* next = pos->_next;
  pos->_next = Node;
  Node->_next = next;
}
void SlistErase_After(SListNode* pos)
{
  if(!pos)
    return;
  SListNode* del = pos->_next;
  SListNode* del_next = del->_next;

  pos->_next = del_next;
  free(del);
  
}
void DesTory(SList* p)
{
  SListNode* cur = p->_head;
  if(!cur)
    return;
  while(cur)
  {
    SListNode* next = cur->_next;
    free(cur);
    cur = next;
  }
  p->_head = NULL;
}
