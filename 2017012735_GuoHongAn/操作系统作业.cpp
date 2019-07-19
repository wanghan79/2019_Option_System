#include <iostream>
#include <string>
#include <io.h>
using namespace std;
void search(string path)
{
    long hFile = 0;
    struct _finddata_t fileInfo;
    string pathName, exdName;
                // 遍历所有的类型
    if ((hFile = _findfirst(pathName.assign(path).append("\\*").c_str(), &fileInfo)) == -1) {
        return;
    }
    do
    {				//判断是文件夹还是文件
        cout << fileInfo.name << (fileInfo.attrib&_A_SUBDIR ? "[folder]" : "[file]") << endl;
    } while (_findnext(hFile, &fileInfo) == 0);
    _findclose(hFile);
    return;
}
int main()
{
                //要遍历的目录
    cout<<"给出E盘目录下的文件名"<<endl;
    string idol;
    cin>>idol;
    string path = "E:\\"+idol+"\\";
    search(path);
    return 0;
}
