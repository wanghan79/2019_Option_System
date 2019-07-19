#include <stdio.h>
#include <windows.h>
using namespace std;
char** GetFileList(const char *path, int *cnt)
{
    HANDLE hRes;
    WIN32_FIND_DATA data;
    LPCSTR IpFileName;	int count = 0;
    char tmpDir[MAX_PATH] = "";	char ** fileList;
    int i = 0; 	strcat(tmpDir,path);
    strcat(tmpDir,"\\*");
    IpFileName = tmpDir;
    hRes = FindFirstFileEx(IpFileName,FindExInfoStandard,&data,FindExSearchNameMatch,NULL,0);
    while(FindNextFile(hRes,&data))
    {
        if(strcmp(data.cFileName,".") ==0 || strcmp(data.cFileName,"..") == 0)
            continue;
        count++;
    }
    fileList = (char**)malloc(sizeof(char*)*count);
    hRes = FindFirstFileEx(IpFileName,FindExInfoStandard,&data,FindExSearchNameMatch,NULL,0);
    while(FindNextFile(hRes,&data))
    {
        if(strcmp(data.cFileName,".") ==0 || strcmp(data.cFileName,"..") == 0)
            continue;
        fileList[i] = (char*)malloc(strlen(data.cFileName)+1);
        memset(fileList[i],0,strlen(data.cFileName)+1);
        strcpy(fileList[i],data.cFileName);
        i++;
    }
    *cnt = i;
    return fileList;
}

int main(){
    char *path=(char *)malloc(10*sizeof(char));;
    scanf("%s",path);
    int res,i;
    char **fileList;
    fileList = GetFileList(path,&res);
    for(i = 0; i < res; i++)
    {
        printf("%s\n",fileList[i]);
    }
    return 0;
}
