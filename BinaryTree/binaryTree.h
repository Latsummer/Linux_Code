#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode{
  BTDataType _data;
  struct BinaryTreeNode* _left;
  struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreat(BTDataType* arr, int n, int* pi);
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTree_LeafSize(BTNode* root);
int BinaryTree_Leve_K_Szie(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

void BinaryTree_PrevOrder(BTNode* root);
void BinaryTree_PrevOrder_NoR(BTNode* root);

void BinaryTree_InOrder(BTNode* root);
void BinaryTree_InOrder_NoR(BTNode* root);

void BinaryTree_PostOrder(BTNode* root);
void BinaryTree_PostOrder_NoR(BTNode* root);

void BinaryTree_LeveOrder(BTNode* root);
int BinaryTree_Complete(BTNode* root);
