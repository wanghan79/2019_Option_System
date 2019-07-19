#include<time.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include <io.h>

FILE *fp = NULL;
void view(char *FileAddr)
{
    struct _finddata_t file; //定义结构体变量
    long handle;
    int iRetVal = 0;
    FILE *pf = NULL;
    char cFileAddr[300];
    strcpy(cFileAddr, FileAddr);
    _chdir(FileAddr);
    strcat(cFileAddr, "*.*");
    handle = _findfirst(cFileAddr, &file);//查找所有文件


    if (handle == -1)//如果handle为－1, 表示当前目录为空, 则结束查找而返回如果handle为－1, 表示当前目录为空, 则结束查找而返回
        return;
    else
    {
        if (file.attrib &_A_SUBDIR) //是目录
        {

            if (file.name[0] != '.') //文件名不是'.'或'..'时
            {
                memset(cFileAddr, 0, sizeof(cFileAddr));
                _chdir(file.name); //进入该目录
                printf("%s\n",file.name);//
                fprintf(fp,"%s\n" ,file.name);

                _chdir("..");//查查找完毕之后, 返回上一级目录找完毕之后, 返回　　　　　　　　　　　　　　　　　上一级目录

            }
        }
        while (!(_findnext(handle, &file)))
        {
            if (file.attrib &_A_SUBDIR) //是目录
            {
                if (file.name[0] != '.') //文件名不是'.'或'..'时
                {
                    memset(cFileAddr, 0, sizeof(cFileAddr));
                    _chdir(file.name); //进入该目录
                    printf("%s\n",file.name);//               add---
                    fprintf(fp,"%s\n" ,file.name);

                    _chdir("..");//查查找完毕之后, 返回上一级目录找完毕之后, 返回　　　　　　　　　　　　　　　　　上一级目录

                }
            }
        }
        _findclose(handle);
    }

    return;
}

main()
{
int i=0;
char FileAddr[50];
time_t start,end;/*定义time_t类型变量start，end*/
printf("please input file path:\n");
scanf("%s", FileAddr);
puts(FileAddr);
fp = fopen("aa.txt", "w");
if(fp ==NULL)
printf("打开文件aa.txt失败\n");


start=time(NULL);/*将当前时间赋给start*/
view(FileAddr);
end=time(NULL);/*将中断后的当前时间赋给end*/
printf("runtime is:%f(s)\n",difftime(end,start));/*调用difftime函数，从start到end说经过的时间*/
fclose(fp);
_getch();
}
