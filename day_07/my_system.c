#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>

int  my_system(const char* cmd)
{
  pid_t pid;
  if((pid = fork()) == -1)
    exit(127);
  if(pid == 0)
  {
    if(execlp("/bin/sh", "/bin/sh", "-c", cmd, NULL) == -1)
      exit(1);
  }
  int status;
  while(waitpid(pid, &status, WNOHANG) != pid)
    ;
  if(WIFEXITED(status))
  {
    return WEXITSTATUS(status);
  }
  return -1;
}

int main()
{
  printf("before my_system\n");
  my_system("ls -l");
  printf("after\n");
}
