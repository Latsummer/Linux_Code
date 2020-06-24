#include "ListNode.h"

 void Init(ListNode* pHead)
{
  pHead->_data = 0;
  pHead->_next = pHead;
  pHead->_prev = pHead;
}

 // 创建返回链表的头结点.
 ListNode* ListCreate(LTDataType x)
{
  ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
  Node->_data = x;
  Node->_next = NULL;
  Node->_prev = NULL;

  return Node;
}
 // 双向链表销毁
 void ListDestory(ListNode* pHead)
{
  ListNode* cur = pHead->_next;
  while(cur != pHead)
  {
    ListNode* next = cur->_next;
    free(cur);
    cur = next;
  }
  pHead = NULL;
}
 // 双向链表打印
 void ListPrint(ListNode* pHead)
{
  ListNode* cur = pHead->_next;
  while(cur != pHead)
  {
    printf("%d ",cur->_data);
    cur = cur->_next;
  }
  printf("\n");
}
 // 双向链表尾插
 void ListPushBack(ListNode* pHead, LTDataType x)
{
  ListNode* prev = pHead->_prev;
  ListNode* Node = ListCreate(x);
  Node->_next = pHead;
  pHead->_prev = Node;

  prev->_next = Node;
  Node->_prev = prev;
}
 // 双向链表尾删
 void ListPopBack(ListNode* pHead)
{
  ListNode* del = pHead->_prev;
  del->_prev->_next = pHead;
  pHead->_prev = del->_prev;

  free(del);
}
 // 双向链表头插
 void ListPushFront(ListNode* pHead, LTDataType x)
{
  ListNode* Node = ListCreate(x);
  ListNode* Front = pHead->_next;

  Node->_next = Front;
  Node->_prev = pHead;

  pHead->_next = Node;
  Front->_prev = Node;
}
 // 双向链表头删
 void ListPopFront(ListNode* pHead)
{
  ListNode* Front = pHead->_next;
  pHead->_next = Front->_next;
  Front->_next->_prev = pHead;

  free(Front);

}
 // 双向链表查找
 ListNode* ListFind(ListNode* pHead, LTDataType x)
{
  ListNode* cur = pHead->_next;
  while(cur != pHead)
  {
    if(cur->_data == x)
      return cur;
    cur = cur->_next;
  }
  return NULL;
}
 // 双向链表在pos的前面进行插入
 void ListInsert(ListNode* pos, LTDataType x)
{
  ListNode* node = ListCreate(x);

  node->_prev = pos->_prev;
  node->_next = pos;

  pos->_prev->_next = node;
  pos->_prev = node;
}
 // 双向链表删除pos位置的节点
 void ListErase(ListNode* pos)
{
  pos->_prev->_next = pos->_next;
  pos->_next->_prev = pos->_prev;

  free(pos);
}
