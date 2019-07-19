?#include <iostream>
#include <string>
#include <iostream>
using namespace std;
void d(string path)
{
    long hF = 0;
    struct _finddata_t fileInfo;
    string pname;
    // \\* 代表要遍历所有的类型
    if ((hF = _findfirst(pname.assign(path).append("\\*").c_str(), &fileInfo)) == -1)
    {
    return；
    }
    do
    {
        //判断是文件夹还是文件
        cout << fileInfo.name << (fileInfo.attrib&_A_SUBDIR ? "[folder]" : "[file]") << endl;
    } while (_findnext(hF, &fileInfo) == 0);
    _findclose(hF);
    return;
}
int main()
{
    //要遍历的目录
    cout<<"please give a folder name in disk C:"<<endl;
    string i;
    cin>>i;
    string path="C:\\"+i+"\\";
    d(path);
    system("pause");
}
