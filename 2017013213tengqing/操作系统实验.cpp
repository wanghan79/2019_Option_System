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
    struct _finddata_t file; //����ṹ�����
    long handle;
    int iRetVal = 0;
    FILE *pf = NULL;
    char cFileAddr[300];
    strcpy(cFileAddr, FileAddr);
    _chdir(FileAddr);
    strcat(cFileAddr, "*.*");
    handle = _findfirst(cFileAddr, &file);//���������ļ�


    if (handle == -1)//���handleΪ��1, ��ʾ��ǰĿ¼Ϊ��, ��������Ҷ��������handleΪ��1, ��ʾ��ǰĿ¼Ϊ��, ��������Ҷ�����
        return;
    else
    {
        if (file.attrib &_A_SUBDIR) //��Ŀ¼
        {

            if (file.name[0] != '.') //�ļ�������'.'��'..'ʱ
            {
                memset(cFileAddr, 0, sizeof(cFileAddr));
                _chdir(file.name); //�����Ŀ¼
                printf("%s\n",file.name);//
                fprintf(fp,"%s\n" ,file.name);

                _chdir("..");//��������֮��, ������һ��Ŀ¼�����֮��, ���ء�����������������������������������һ��Ŀ¼

            }
        }
        while (!(_findnext(handle, &file)))
        {
            if (file.attrib &_A_SUBDIR) //��Ŀ¼
            {
                if (file.name[0] != '.') //�ļ�������'.'��'..'ʱ
                {
                    memset(cFileAddr, 0, sizeof(cFileAddr));
                    _chdir(file.name); //�����Ŀ¼
                    printf("%s\n",file.name);//               add---
                    fprintf(fp,"%s\n" ,file.name);

                    _chdir("..");//��������֮��, ������һ��Ŀ¼�����֮��, ���ء�����������������������������������һ��Ŀ¼

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
time_t start,end;/*����time_t���ͱ���start��end*/
printf("please input file path:\n");
scanf("%s", FileAddr);
puts(FileAddr);
fp = fopen("aa.txt", "w");
if(fp ==NULL)
printf("���ļ�aa.txtʧ��\n");


start=time(NULL);/*����ǰʱ�丳��start*/
view(FileAddr);
end=time(NULL);/*���жϺ�ĵ�ǰʱ�丳��end*/
printf("runtime is:%f(s)\n",difftime(end,start));/*����difftime��������start��end˵������ʱ��*/
fclose(fp);
_getch();
}
