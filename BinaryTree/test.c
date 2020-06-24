#include "binaryTree.h"

void test1()
{
  //char arr[] = "ABD##E#H##CF##G##";
  char arr[] = "ABD##E##CF##G##";
  int pi = 0;
  BTNode* root = BinaryTreeCreat(arr, sizeof(arr) / sizeof(arr[0]) - 1, &pi);
  BinaryTree_PrevOrder(root);
  printf("\n");
  BinaryTree_InOrder(root);
  printf("\n");
  BinaryTree_PostOrder(root);
  printf("\n\n");
  BinaryTree_PrevOrder_NoR(root);
  BinaryTree_InOrder_NoR(root);
  BinaryTree_PostOrder_NoR(root);
  BinaryTree_LeveOrder(root);

  printf("%d \n", BinaryTree_Complete(root));
}

int main()
{
  test1();
  return 0;
}
