#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int fd = open("test.txt", O_RDWR);
  close(1);//关闭标准输出
  dup(fd);
  printf("this is 截胡\n");
  return 0;
}
