#include <iostream>
#include <algorithm>
#include <io.h>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
void getAllFilesPath(string path, vector<string>& filesName);//��ȡ�������ļ���
void getAllFilesName(string path, vector<string>& filesName);//ֻ��ȡ��Ŀ¼�µ������ļ���
void writeFilesName(const vector<string>& filesName);//���ļ��Ķ�ȡ��ʽ
void getAllFilesPath(string path, vector<string>& filesName) {
    long hFile = 0; //�ļ����
    struct _finddata_t fileinfo;//�ļ���Ϣ
    string tempFilePath;//�ļ�����ָ��
    if ((hFile = _findfirst(tempFilePath.assign(path).append("\\*").c_str(), &fileinfo)) == -1) {
        cout << "Not Find File!" << endl;
        exit(-1);
    }
    else {
        do {
            tempFilePath =  path + "\\" + fileinfo.name;
            //�Ƚ��ļ������Ƿ����ļ���
            if ((fileinfo.attrib & _A_SUBDIR)) {
                //�Ƿ���������ļ�(.,..)��etc.
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
                    filesName.push_back(tempFilePath);
                    getAllFilesPath(tempFilePath, filesName);
                }
            }
            else
                filesName.push_back(tempFilePath);
        }
        while(_findnext(hFile, &fileinfo) == 0);
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
    }
    else {
        do {
            if ((fileInfor.attrib & _A_SUBDIR)) {
                if (strcmp(fileInfor.name, ".") != 0 && strcmp(fileInfor.name, "..") != 0)
                    getAllFilesName(p.assign(path).append("\\").append(fileInfor.name), filesName);
            }
            else
                filesName.push_back(fileInfor.name);
        }
        while(_findnext(hFile, &fileInfor) == 0);
    }
    _findclose(hFile);
}
void writeFilesName(const vector<string>& filesName) {
	char* f = (char*)"E:\\myfile.txt";
    ofstream ofs(f);
    vector<string>::const_iterator iter;
    for (iter = filesName.begin(); iter != filesName.end(); ++iter) {
        ofs << *iter << endl;
    }
    ofs.close();
}
void print(const vector<string>& filesName) {
    cout << "----------------------------------------\n";
    cout << "|          ---File list---             |\n";
    cout << "|    ---count: " << filesName.size() << "---    |\n";
    cout << "----------------------------------------\n";
    vector<string>::const_iterator iter;
    for (iter = filesName.begin(); iter != filesName.end();++iter) {
        cout << *iter << endl;
    }
    cout << "----END----\n";
}
int main(int argc, char **argv)
{
    freopen("fileName.txt", "w", stdout);
    vector<string> filesName;
    string path = "E:";
    getAllFilesName(path, filesName);
    getAllFilesPath(path, filesName);
    writeFilesName(filesName);
    //�����ļ���
    print(filesName);
    return 0;
}
