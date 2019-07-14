#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#define FILENAME "test.txt"
int main(void)
{
   struct stat statbuf;
   FILE *stream;
   if ((stream = fopen(FILENAME, "r")) == NULL)
   {
      fprintf(stderr, "Cannot open output file.\n");
      return(1);
   }
   /* 获取文件信息*/
   stat(FILENAME, &statbuf);
   fclose(stream);
   /* 显示文件信息 */
   if (statbuf.st_mode & S_IFCHR)
      printf("Handle refers to a device.\n");
   if (statbuf.st_mode & S_IFREG)
      printf("Handle refers to an ordinary file.\n");
   if (statbuf.st_mode & S_IREAD)
      printf("User has read permission on file.\n");
   if (statbuf.st_mode & S_IWRITE)
      printf("User has write permission on file.\n");
   printf("Drive letter of file: %c\n", 'A'+statbuf.st_dev);
   printf("Size of file in bytes: %ld\n", statbuf.st_size);
   printf("Time file last opened: %s\n", ctime(&statbuf.st_ctime));
   return 0;
}
