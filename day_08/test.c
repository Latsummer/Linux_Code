#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

//usage : ./mycpy src dst

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    fprintf(stderr, "usage : %s src_file dst_file\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  int fd_src = open(argv[1], O_RDONLY);
  if(fd_src == -1)
  {
    fprintf(stderr, "open(%s) : %s\n", argv[1], strerror(errno));
    exit(EXIT_FAILURE);
  }

  int fd_dst = open(argv[2], O_WRONLY | O_CREAT, 0644);
  if(fd_dst == -1)
  {
    close(fd_src);
    fprintf(stderr, "open(%s) : %s\n", argv[2], strerror(errno));
    exit(EXIT_FAILURE);
  }

  char buf[1024];
  while(1)
  {
    memset(buf, 0x00, sizeof(buf));
    int ret = read(fd_src, buf, 1024);
    if(ret == -1)
    {
      fprintf(stderr, "read(%s) : %s\n", argv[1], strerror(errno));
      break;
    }else if(ret == 0)
    {
      break;
    }

    if(write(fd_dst, buf, ret) == -1)
    {
      fprintf(stderr, "write(%s) : %s\n", argv[2], strerror(errno));
      break;
    }
  }


  close(fd_dst);
  close(fd_src);
}


