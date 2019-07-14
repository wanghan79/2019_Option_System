/*
输入路径时注意使用双斜线
使用devc++编译 版本为 5.11
GCC版本为 4.9.2 64-bit 
李奇 2017012344 
*/ 
#include <io.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
void File_name( string path, vector<string>& files)  
{  
 
	long  files_hd   =   0;  
	struct _finddata_t files_name;  
	string p;  
	if((files_hd = _findfirst(p.assign(path).append("\\*").c_str(),&files_name)) !=  -1)  {  
		do {   
			if((files_name.attrib &  _A_SUBDIR)) {  
				if(strcmp(files_name.name,".") != 0  &&  strcmp(files_name.name,"..") != 0)  {
					files.push_back(p.assign(path).append("\\").append(files_name.name) );
					File_name( p.assign(path).append("\\").append(files_name.name), files ); 
				}
			}  
			else  {  
				files.push_back(p.assign(path).append("\\").append(files_name.name) );  
			} 
		}
		while(_findnext(files_hd, &files_name)  == 0);  
		_findclose(files_hd); 
	} 
} 
int main()
{
	string filePath = "C:\\python27";  
	vector<string> files;  
	File_name(filePath, files);
	int size = files.size(); 
	for (int i = 0;i<size;i++)  {  
		cout<< files[i] << endl;
	}
	return 0;
}
