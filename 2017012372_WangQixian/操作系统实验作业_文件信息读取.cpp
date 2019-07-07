#include <iostream>
#include <algorithm>
#include <io.h>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//获取完整的文件名
void getAllFilesPath(string path, vector<string>& filesName);

//只获取在目录下的所有文件名
void getAllFilesName(string path, vector<string>& filesName);

//用文件的读取方式
void writeFilesName(const vector<string>& filesName);

void getAllFilesPath(string path, vector<string>& filesName) {
    //文件句柄
    long hFile = 0;

    //文件信息
    struct _finddata_t fileinfo;

    //文件搜索指针
    string tempFilePath;

    //可以对要查找的目录或者文件名进行限制查找。
    //比如，只要后缀是.txt的文件名，则可以这样设置
    //tempFilePath.assign(path).append("\\*.txt").c_str()
    //当然，其查找到的结果只能是当前目录下的所有.txt文件。
    if ((hFile = _findfirst(tempFilePath.assign(path).append("\\*").c_str(), &fileinfo)) == -1) {
        cout << "Not Find File!" << endl;
        exit(-1);
    } else {
        do {
            tempFilePath =  path + "\\" + fileinfo.name;
            //比较文件类型是否是文件夹
            if ((fileinfo.attrib & _A_SUBDIR)) {
                //是否是特殊的文件(.,..)，etc.
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
                    filesName.push_back(tempFilePath);
                    getAllFilesPath(tempFilePath, filesName);
                }
            } else {
                filesName.push_back(tempFilePath);
            }

        }while(_findnext(hFile, &fileinfo) == 0);

        _findclose(hFile);
    }

}

void getAllFilesName(string path, vector<string>& filesName){
    long hFile = 0;
    struct _finddata_t fileInfor;

    string p;

    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileInfor)) == -1) {
        cout <<"Not Find File!" << endl;
        exit(-1);
    } else {
        do {
            if ((fileInfor.attrib & _A_SUBDIR)) {
                if (strcmp(fileInfor.name, ".") != 0 && strcmp(fileInfor.name, "..") != 0)
                    getAllFilesName(p.assign(path).append("\\").append(fileInfor.name), filesName);
            } else {
                filesName.push_back(fileInfor.name);
            }
        }while(_findnext(hFile, &fileInfor) == 0);
    }
    _findclose(hFile);
}

void print(const vector<string>& filesName) {
    cout << "----------------------------------------\n";
    cout << "|                                      |\n";
    cout << "|          ---File list---             |\n";
    cout << "|          ---count: " << filesName.size() << "---             |\n";
    cout << "----------------------------------------\n";
    vector<string>::const_iterator iter;
    for (iter = filesName.begin(); iter != filesName.end();++iter) {
        cout << *iter << endl;
    }
    cout << "-----------------END--------------------\n";
}

void writeFilesName(const vector<string>& filesName) {
//    char *f = "fileName.txt"; 这种写法不通过 
	char* f = (char*)"E:\\myfile.txt";
    ofstream ofs(f);

    vector<string>::const_iterator iter;
    for (iter = filesName.begin(); iter != filesName.end(); ++iter) {
        ofs << *iter << endl;
    }
    ofs.close();
}

int main(int argc, char **argv)
{
    //将查找的结果写入fileName.txt
    freopen("fileName.txt", "w", stdout);

    vector<string> filesName;
    string path = "E:\\acm\\ggg";

    getAllFilesName(path, filesName);
    getAllFilesPath(path, filesName);

    writeFilesName(filesName);
    //输入文件名
    print(filesName);

    return 0;
}

