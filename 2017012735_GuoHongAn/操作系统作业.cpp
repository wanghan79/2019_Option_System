#include <iostream>
#include <string>
#include <io.h>
using namespace std;
void search(string path)
{
    long hFile = 0;
    struct _finddata_t fileInfo;
    string pathName, exdName;
                // �������е�����
    if ((hFile = _findfirst(pathName.assign(path).append("\\*").c_str(), &fileInfo)) == -1) {
        return;
    }
    do
    {				//�ж����ļ��л����ļ�
        cout << fileInfo.name << (fileInfo.attrib&_A_SUBDIR ? "[folder]" : "[file]") << endl;
    } while (_findnext(hFile, &fileInfo) == 0);
    _findclose(hFile);
    return;
}
int main()
{
                //Ҫ������Ŀ¼
    cout<<"����E��Ŀ¼�µ��ļ���"<<endl;
    string idol;
    cin>>idol;
    string path = "E:\\"+idol+"\\";
    search(path);
    return 0;
}
