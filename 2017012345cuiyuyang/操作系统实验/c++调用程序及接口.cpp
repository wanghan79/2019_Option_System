?#include <iostream>
#include <string>
#include <iostream>
using namespace std;
void d(string path)
{
    long hF = 0;
    struct _finddata_t fileInfo;
    string pname;
    // \\* ����Ҫ�������е�����
    if ((hF = _findfirst(pname.assign(path).append("\\*").c_str(), &fileInfo)) == -1)
    {
    return��
    }
    do
    {
        //�ж����ļ��л����ļ�
        cout << fileInfo.name << (fileInfo.attrib&_A_SUBDIR ? "[folder]" : "[file]") << endl;
    } while (_findnext(hF, &fileInfo) == 0);
    _findclose(hF);
    return;
}
int main()
{
    //Ҫ������Ŀ¼
    cout<<"please give a folder name in disk C:"<<endl;
    string i;
    cin>>i;
    string path="C:\\"+i+"\\";
    d(path);
    system("pause");
}
