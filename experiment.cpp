#include<io.h>
#include<fstream>
#include<string.h> 
void getFilesAll( string path, vector<string>& files) 
 { 
   //文件句柄 
   long  hFile  =  0; 
   //文件信息 
   struct _finddata_t fileinfo; 
   string p; 
   if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) != -1) 
   { 
     do
     {  
       if((fileinfo.attrib & _A_SUBDIR)) 
       { 
         if(strcmp(fileinfo.name,".") != 0 && strcmp(fileinfo.name,"..") != 0) 
         {
           //files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
           getFilesA( p.assign(path).append("\\").append(fileinfo.name), files ); 
         }
       } 
       else
       { 
         files.push_back(p.assign(path).append("\\").append(fileinfo.name) ); 
       } 
     }while(_findnext(hFile, &fileinfo) == 0); 
     _findclose(hFile); 
   } 
 }
int main(int argc, char** argv)
{
vector<string> files; 
getFilesall(filePath, files);
int size = files.size(); 
for (int i = 0;i<size;i++) 
{ 
  cout<<files[i]<<endl; 
}
  return 0;
}
