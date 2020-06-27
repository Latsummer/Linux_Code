#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

typedef struct 
{
  int id;
  char name[32];
}stu_t;

void input(int n)
{
  int fd = open("stu.dat", O_RDWR | O_CREAT | O_TRUNC, 0644);
  if(fd == -1)perror("open"), exit(1);
  int i = 1;

  do{
    stu_t s;
    s.id = i++;
    printf("name: ");
    scanf("%s", s.name);
    if(write(fd, &s, sizeof(stu_t)) != sizeof(stu_t))perror("write"), exit(1);
  }while(--n > 0);

  close(fd);
}

void output(int n)
{
  int fd = open("stu.dat", O_RDONLY);
  if(fd == -1)perror("open"), exit(1);

  stu_t buf;
  int r = lseek(fd, (n - 1) * sizeof(stu_t), SEEK_SET);
  printf("r == %d", r);
  if(read(fd, &buf, sizeof(buf)) == -1)perror("read"), exit(1);
  printf("id = %d, name = %s\n", buf.id, buf.name);

  close(fd);
}

int main()
{
  int n;
  printf("要输入几个学生信息？");
  scanf("%d", &n);
  input(n);

  while(1)
  {
    printf("要显示几号学生信息（-1：exit）：");
    int n;
    scanf("%d", &n);
    if(n == -1)break;
    output(n);
  }

  return 0;
}
