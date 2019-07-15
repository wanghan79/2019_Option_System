#include <iostream>
#include <cstring>        
#include <io.h>
#include<bits/stdc++.h> 

using namespace std;

void listFiles(const char * dir);

int main()
{
    char dir[200];
    cout << "Enter a directory (ends with \'\\\'): ";
    cin.getline(dir, 200);
    strcat(dir, "*.*");
    listFiles(dir);
    return 0;
}

void listFiles(const char * dir)
{
    intptr_t handle;
    _finddata_t findData;
    handle = _findfirst(dir, &findData);
    if (handle == -1)
    {
        cout << "Failed to find first file!\n";
        return;
    }
    do
    {
        if (findData.attrib & _A_SUBDIR
            && strcmp(findData.name, ".") == 0
            && strcmp(findData.name, "..") == 0
            )
            cout << findData.name << "\t<dir>\n";
        else
            cout << findData.name << "\t" <<"文件大小："<< findData.size <<"\t"<< endl;
    } while (_findnext(handle, &findData) == 0)
    cout << "Done!\n";
    _findclose(handle);
}
