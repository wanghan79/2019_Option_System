#include<iostream>    
#include<string>    
#include<io.h>  
#include<fstream> 
using namespace std;  
void visit(string path,int layer)    
{    
    struct _finddata_t  filefind;    
    string  curr=path+"\\*.*"; 
    long handle;
    int i;   
    if((handle=_findfirst(curr.c_str(),&filefind))==-1)return;      
    while(_findnext(handle,&filefind) == 0)    
    {        
        if(!strcmp(filefind.name,"..")){ 
            continue;
        }
        for(i=1;i<layer;i++) cout<<"    ";                  
        if(_A_SUBDIR==filefind.attrib) 
        {            
            curr=path+"\\"+filefind.name;  
            visit(curr,layer+1);
        }    
        else      
        {    
            cout<<path+"\\"+filefind.name<<endl;   
        }    
    }            
    _findclose(handle);                
} 
void openandwrite()
{
	char i;
	ofstream ofile; 
    ofile.open("d:\\liuyh.txt");//û�л��Զ������� 
    ofile<<"����ϵͳʵ����ҵ"<<endl;
	ofile.close();
} 
int main()    
{            
    string path;  
    cout<<"������Ŀ¼��";    
    cin>>path; 
    visit(path,1);   
    openandwrite();
    return 0;      
} 
