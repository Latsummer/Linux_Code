#include "My_ls.h"

typedef struct Node{
  char* _name;
  struct Node* _next;

}Node;

Node* Creat(char* dname)
{

  Node* pnode = (Node*)malloc(sizeof(Node));
  pnode->_name = (char*)malloc(strlen(dname) + 1);
  memset(pnode->_name, 0x00, strlen(dname) + 1);
  strcpy(pnode->_name, dname);
  pnode->_next = NULL;

  return pnode;
}

void insert_list(Node** head, char* dname)
{
  if(head == NULL)
    return;
  Node* new_pnode = Creat(dname);
  if(*head == NULL)
    *head = new_pnode;
  else
  {
    //来的新目录名字比原来链表的第一个目录名字还小
    if(strcasecmp((*head)->_name, new_pnode->_name) >= 0)
    {
      new_pnode->_next = *head;
      *head = new_pnode;
      return;
    }
    //此时来的目录名字大于原链表的第一个名字
    Node* cur = *head;
    Node* next = cur->_next;
    while(next != NULL)
    {
      if(strcasecmp(next->_name, new_pnode->_name) >= 0)
        break;
      cur = next;
      next = cur->_next;
    }
    new_pnode->_next = next;
    cur->_next = new_pnode;
  }
  
}

int main()
{
  struct dirent *pidrent = NULL;
  DIR *pdir = opendir(".");
  Node* head = NULL;

  while( (pidrent = readdir(pdir)) != NULL)
  {
    if(pidrent->d_name[0] == '.')
      continue;
    insert_list(&head, pidrent->d_name);
  }
  Node* cur = head;
  while(cur != NULL)
  {
    //printf("%s  ", cur->_name);
    my_ls(cur->_name);
    cur = cur->_next;
  }

  printf("\n");
  closedir(pdir);
  return 0;
}
