#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
  int fd = open("test.txt", O_RDWR);
  pid_t pid = fork();
  if(pid == 0){
    write(fd, "XXXX", 4);
    close(fd);
  }else{
    char buf[10] = {};
    sleep(1);
    read(fd, buf, 5);
    printf("buf = [%s]\n", buf);
    close(fd);
  }
  return 0;
}
