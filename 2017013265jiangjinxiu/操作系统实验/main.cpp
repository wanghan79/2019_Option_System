#include <iostream>
#include <string>
#include <io.h>
using namespace std;
void dir(string path)
{
    long hFile = 0;
    struct _finddata_t fileInfo;
    string pathName, exdName;
                // \\* ����Ҫ�������е�����,��ĳ�\\*.jpg��ʾ����jpg�����ļ�
    if ((hFile = _findfirst(pathName.assign(path).append("\\*").c_str(), &fileInfo)) == -1) {
        return;
    }
    do
    {
                //�ж��ļ����������ļ��л����ļ�
        cout << fileInfo.name << (fileInfo.attrib&_A_SUBDIR ? "[folder]" : "[file]") << endl;
    } while (_findnext(hFile, &fileInfo) == 0);
    _findclose(hFile);
    return;
}
int main()
{
                //Ҫ������Ŀ¼
    cout<<"please give a folder name in disk E"<<endl;
    string idol;
    cin>>idol;
    string path = "E:\\"+idol+"\\";
    dir(path);
    //system("pause");
    return 0;
}
