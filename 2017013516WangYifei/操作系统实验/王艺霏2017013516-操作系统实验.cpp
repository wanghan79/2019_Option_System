/*
    *�γ̣�����ϵͳʵ�� 
    *��ҵ��C++����ϵͳ�ӿ�ʵ�ָ���Ŀ¼�ļ���Ϣ��ȡ 
    *������������ 
    *ѧ�ţ�2017013516
*/
#include <iostream>
#include <algorithm>
#include <io.h>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
void getAllFilesPath(string path, vector<string>& filesName)
{
    long hFile = 0;
    struct _finddata_t fileinfo;
    string tempFilePath;
    if ((hFile = _findfirst(tempFilePath.assign(path).append("\\*").c_str(), &fileinfo)) == -1)
	{
        cout << "Not Find File!" << endl;
        exit(-1);
    }
	else
	{
        do{
            tempFilePath =  path + "\\" + fileinfo.name;
            if ((fileinfo.attrib & _A_SUBDIR))
			{
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
                    filesName.push_back(tempFilePath);
                    getAllFilesPath(tempFilePath, filesName);
                }
            } 
		    else
			{
                filesName.push_back(tempFilePath);
            }
        }while(_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}
void getAllFilesName(string path, vector<string>& filesName)
{
    long hFile = 0;
    struct _finddata_t fileInfor;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileInfor)) == -1)
	{
        cout <<"Not Find File!" << endl;
        exit(-1);
    } 
	else
	{
        do{
            if((fileInfor.attrib & _A_SUBDIR))
			{
                if (strcmp(fileInfor.name, ".") != 0 && strcmp(fileInfor.name, "..") != 0)
                    getAllFilesName(p.assign(path).append("\\").append(fileInfor.name), filesName);
            } 
			else
			{
                filesName.push_back(fileInfor.name);
            }
        }while(_findnext(hFile, &fileInfor) == 0);
    }
    _findclose(hFile);
}
void print(const vector<string>& filesName)
{ 
    cout << "-----------------------------------------\n";
    cout << "|                                       |\n";
    cout << "|   ---Directory��F:\\����ϵͳʵ��---    |\n";
    cout << "|           ---File list---             |\n";
    cout << "|            ---Count: " << filesName.size() << "---             |\n";
    cout << "|                                       |\n";
    cout << "-----------------------------------------\n";
    vector<string>::const_iterator iter;
    for (iter = filesName.begin(); iter != filesName.end();++iter)
	{
        cout << *iter << endl;
    }
    cout << "-------------------END-------------------\n";
}
void writeFilesName(const vector<string>& filesName)
{
    char *f = "fileName.txt";
    ofstream ofs(f);
    vector<string>::const_iterator iter;
    for (iter = filesName.begin(); iter != filesName.end(); ++iter) 
	{
        ofs << *iter << endl;
    }
    ofs.close();
}
int main(int argc, char **argv)
{
    vector<string> filesName;
    string path = "F:\\����ϵͳʵ��";
    getAllFilesPath(path, filesName);
    writeFilesName(filesName);
    print(filesName);

    return 0;
}
