#include <iostream>
#include <io.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void getAllFiles(string path, vector<string>& files) {
	long hFile = 0;
	struct _finddata_t fileinfo;
	string p;  
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) != -1) {
		do {
			if ((fileinfo.attrib & _A_SUBDIR)) { 
				if (strcmp(fileinfo.name,".") != 0 && strcmp(fileinfo.name,"..") != 0) {
					files.push_back(p.assign(path).append("\\").append(fileinfo.name));
					getAllFiles(p.assign(path).append("\\").append(fileinfo.name), files);
				}
			}
			else {
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} 
		while (_findnext(hFile, &fileinfo) == 0); 
		_findclose(hFile);
	}
}

int main(){
	char* filePath = "D:\\setup";
	vector<string> files;
	char* distAll = "AllFiles.txt";
	getAllFiles(filePath, files);
	ofstream ofn(distAll);
	int size = files.size();
	ofn<<"numbers : "<<size<<endl;
	for (int i = 0; i < size; i++) {
	    ofn<<files[i]<<endl;
	}
	ofn.close();
}
