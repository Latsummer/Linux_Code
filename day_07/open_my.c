#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main()
{
  int fd = open("My_shell.c", O_RDONLY);
  if(fd == -1) perror("open"), exit(1);
  printf("Open OK !\n");

  while(1)
  {
    char buf[10 + 1];
    memset(buf, 0x00, sizeof(buf));
    int r = read(fd, buf, 10);
    if(r == 0)
    {
      printf("end of file\n");
      break;
    }
    if(r == -1) perror("read"), exit(1);
    printf("%s", buf);
    sleep(1);
    fflush(stdout);
  }
  

  if((close(fd) == -1))perror("close"), exit(1);
}
