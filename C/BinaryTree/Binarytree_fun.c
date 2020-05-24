#include "stack.h"
#include "Qnode.h"
#include "binaryTree.h"

BTNode* BinaryTreeCreat(BTDataType* arr, int n, int* pi)
{
  if(arr[*pi] != '#' && *pi < n)
  {
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->_data = arr[*pi];
    (*pi)++;
    root->_left = BinaryTreeCreat(arr, n, pi);
    (*pi)++;
    root->_right = BinaryTreeCreat(arr, n, pi);
    return root;
  }
  return NULL;
}
void BinaryTreeDestory(BTNode** root)
{
  BTNode* cur = *root;
  if(cur)
  {
    BinaryTreeDestory(&cur->_left);
    BinaryTreeDestory(&cur->_right);
    free(cur);
    *root = NULL;
  }
}
 int BinaryTreeSize(BTNode* root)
{
  if(!root)
    return 0;
  return BinaryTreeSize(root->_left)
    + BinaryTreeSize(root->_right)
    + 1;
}
 int BinaryTree_LeafSize(BTNode* root)
{
  if(!root)
    return 0;
  if(!root->_left && !root->_right)
    return 1;
  return BinaryTree_LeafSize(root->_left)
    + BinaryTree_LeafSize(root->_right);
}
 int BinaryTree_Leve_K_Szie(BTNode* root, int k)
{
  if(!root)
    return 0;
  if(k == 1)
    return 1;
  return BinaryTree_Leve_K_Szie(root->_left, k - 1)
    + BinaryTree_Leve_K_Szie(root->_right, k - 1);
}
 BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
  BTNode* ret = NULL;
  if(!root)
    return NULL;
  if( root->_data == x )
    return root;
  ret = BinaryTreeFind(root->_left, x);
  if(ret)
    return ret;
  return BinaryTreeFind(root->_right, x);
}
 
void BinaryTree_PrevOrder(BTNode* root)
{
  if(root)
  {
    printf("%c ", root->_data);
    BinaryTree_PrevOrder(root->_left);
    BinaryTree_PrevOrder(root->_right);
  }
}
 void BinaryTree_PrevOrder_NoR(BTNode* root)
{
  Stack st;
  StackInit(&st);
  BTNode* cur = root;
  BTNode* top = NULL;
  while(cur || !StackEmpty(&st))
  {
    while(cur)
    {
      printf("%c ", cur->_data);
      StackPush(&st, cur);
      cur = cur->_left;
    }
    top = StackTop(&st);
    StackPop(&st);
    cur = top->_right;
  }
  printf("\n");
}
 
 void BinaryTree_InOrder(BTNode* root)
{
  if(root)
  {
    BinaryTree_InOrder(root->_left);
    printf("%c ", root->_data);
    BinaryTree_InOrder(root->_right);
  }
}
 void BinaryTree_InOrder_NoR(BTNode* root)
{
  Stack st;
  StackInit(&st);
  BTNode* cur = root;
  BTNode* top = NULL;
  while(cur || !StackEmpty(&st))
  {
    while(cur)
    {
      StackPush(&st, cur);
      cur = cur->_left;
    }
    top = StackTop(&st);
    StackPop(&st);
    printf("%c ",top->_data);
    cur = top->_right;
  }
  printf("\n");
}

 void BinaryTree_PostOrder(BTNode* root)
{
  if(root)
  {
    BinaryTree_PostOrder(root->_left);
    BinaryTree_PostOrder(root->_right);
    printf("%c ", root->_data);
  }
}
 void BinaryTree_PostOrder_NoR(BTNode* root)
{
  Stack st;
  StackInit(&st);
  BTNode* cur = root;
  BTNode* top = NULL;
  BTNode* prev = NULL;
  while(cur || !StackEmpty(&st))
  {
    while(cur)
    {
      StackPush(&st, cur);
      cur = cur->_left;
    }
    top = StackTop(&st);
    if(!top->_right || top->_right == prev)
    {
      printf("%c ", top->_data);
      StackPop(&st);
      prev = top;
    }
    else
      cur = top->_right;
  }
  printf("\n");
}
 
 void BinaryTree_LeveOrder(BTNode* root)
{
  Queue q;
  QueueInit(&q);
  if(root)
    QueuePush(&q, root);
  while(!QueueEmpty(&q))
  {
    BTNode* front = QueueFront(&q);
    QueuePop(&q);
    printf("%c ", front->_data);
    if(front->_left)
      QueuePush(&q, front->_left);
    if(front->_right)
      QueuePush(&q, front->_right);
  }
  printf("\n");
}
 int BinaryTree_Complete(BTNode* root)
{
  Queue q;
  QueueInit(&q);
  if(root)
    QueuePush(&q, root);
  while(!QueueEmpty(&q))
  {
    BTNode* front = QueueFront(&q);
    QueuePop(&q);
    if(front)
    {
      QueuePush(&q, front->_left);
      QueuePush(&q, front->_right);
    }
    else
      break;
  }
  while(!QueueEmpty(&q))
  {
    BTNode* front = QueueFront(&q);
    QueuePop(&q);
    if(front)
      return 0;
  }
  return 1;
}

 
