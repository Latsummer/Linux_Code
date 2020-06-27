#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
  int fd = open("test.txt", O_RDWR);
  printf("fd = %d\n", fd);
  int newfd = dup(fd);
  
  printf("before close(fd)\n");
  getchar();
  close(fd);
  printf("after close(fd)\n");
  getchar();

  printf("newfd = %d\n", newfd);

  write(newfd, "ZZ", 2);
  return 0;
}
