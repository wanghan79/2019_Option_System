#include<bits/stdc++.h>
#include<io.h>
using namespace std;
void dir(string path)
{
    long hFile;
    struct _finddata_t fileInfo;
    string pathName, exdName;
    hFile = 0;
                // ��\\*���������Ҫ�������е�����,��������\\*���ĳɡ�\\*.jpg����ʾ����jpg�����ļ�
    if ((hFile = _findfirst(pathName.assign(path).append("\\*").c_str(), &fileInfo)) == -1) {
        return;
    }
    do
    {
        cout << fileInfo.name << (fileInfo.attrib&_A_SUBDIR ? "[folder]" : "[file]") << endl;//�ж��ļ����������ļ��л����ļ�
    } while (_findnext(hFile, &fileInfo) == 0);
    _findclose(hFile);
    return;
}
int main()
{
    cout<<"please give a folder name in disk D"<<endl;
    string idol;
    cin>>idol;
    string path = "D:\\"+idol+"\\";
    dir(path);
    system("pause");
    return 0;
}
