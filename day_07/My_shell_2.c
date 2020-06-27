#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<ctype.h>
#include<string.h>

int get_input(char* buf)
{
    memset(buf, 0x00, sizeof(512));
    if(scanf("%[^\n]%*c", buf) != 1)
    {
      int c;
      do
        c = getchar();
      while(c!= '\n');
    }
    return strlen(buf);
}

void do_action(int argc, char* argv[])
{
  pid_t pid;
  switch( pid = fork() )
  {
    case -1:
      printf("当前shell出现故障，正在维护中......\n");
      break;
    case 0:{
             if(strcmp(argv[1], "<") == 0 || strcmp(argv[1], ">") == 0)
             {
                
             }
      int ret = execvp( argv[0], argv );
      printf("%s : 未找到命令\n", argv[0]);
      exit(1);
          }
      break;
    default:{
              int status;
              waitpid(pid, &status, 0 );
            }
            break;
  }
}

void do_parse(char* buf)
{
  int argc = 0;
  char* argv[10] = {};
#define  OUT 0
#define  IN 1
  int flag = OUT;
  int i = 0;

  while(buf[i] != '\0')
  {
    if(flag == OUT && !isspace(buf[i]))
    {
      argv[argc++] = buf + i;
      flag = IN;
    }
    else if(isspace(buf[i]))
    {
      flag = OUT;
      buf[i] = '\0';
    }
    i++;
  }

  argv[argc] = NULL;
  do_action(argc, argv);
}

int main()
{
  char buf[512];
  while(1)
  {
    printf("[Morgan Shell] #");
    if( get_input(buf) == 0 )
      continue;
    do_parse(buf);
  }
}
