#include "My_ls.h"

void file_type(mode_t mode)
{
  char buf[11] = "?---------";
  switch( mode & S_IFMT )
  {
    case S_IFSOCK: buf[0] = 's'; break;
    case S_IFLNK: buf[0] = 'l'; break;
    case S_IFREG: buf[0] = '-'; break;
    case S_IFBLK: buf[0] = 'b'; break;
    case S_IFDIR: buf[0] = 'd'; break;
    case S_IFCHR: buf[0] = 'c'; break;
    case S_IFIFO: buf[0] = 'p'; break;
  }
  if( mode & S_IRUSR ) buf[1] = 'r';
  if( mode & S_IWUSR ) buf[2] = 'w';
  if( mode & S_IXUSR ) buf[3] = 'x';

  if( mode & S_IRGRP ) buf[4] = 'r';
  if( mode & S_IWGRP ) buf[5] = 'w';
  if( mode & S_IXGRP ) buf[6] = 'x';

  if( mode & S_IROTH ) buf[7] = 'r';
  if( mode & S_IWOTH ) buf[8] = 'w';
  if( mode & S_IXOTH ) buf[9] = 'x';

  printf("%s. ", buf);
}

void my_ls(char* argv)
{

  struct stat buf;
  if ( lstat(argv, &buf) == -1)
    perror("stat"), exit(1);

  file_type(buf.st_mode); //权限
  printf("%ld ", buf.st_nlink);//硬链接
  struct passwd* pw = getpwuid(buf.st_uid);
  printf("%s ", pw->pw_name);//创建者
  struct group* gp = getgrgid(buf.st_gid);
  printf("%s ", gp->gr_name);//组名
  printf("%ld ", buf.st_size);//文件大小
  struct tm* ptm = localtime(&buf.st_mtime);
  printf("%04d-%02d-%02d %02d:%02d:%02d ", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday
                                        , ptm->tm_hour, ptm->tm_min, ptm->tm_sec);//最后一次修改时间
  printf("%s", argv);//文件名
  if( S_ISLNK(buf.st_mode) ){
    char tmp[256];
    readlink(argv, tmp, 256);
    printf(" -> %s", tmp);
  }

  printf("\n");
}
