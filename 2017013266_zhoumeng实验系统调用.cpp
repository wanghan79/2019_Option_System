
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream> 
#include <string>  
#include <vector>  
#include <map>  
#include <unistd.h>

#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h> 
#include <sstream>
using namespace std;
/**
*int转为string型
*/
string int_to_string(int num){
  ostringstream oss;
  string c = "";
  oss << num;
  c =oss.str();
  return c;
}

/**
@line_size:每1行有多少字母
@line:要读多少行
@count_thread:第几个进程
*/
int get_line_size(int line_size,int line,int count_thread){
	if(count_thread == 0){
		return 0;
	}else{
		return (line_size + 1) * (line * count_thread - 1) ;
	}
}

/*
对每行读取的记录进行系统调用，来统计该记录在文件中出现的行号,参数内容参见test方法
*/
void test_grep(const char* in_file,const char* out_file,string filename,int thread_num,int line_size,int read_line_num,int is_end){
	fstream fout;
	fout.open(out_file,ios::out);
	
	ifstream fin;
	fin.open(in_file,ios::in);
	int count_read =0;
	fin.seekg(get_line_size(line_size,read_line_num,thread_num),std::ios::cur); 
	while(!fin.eof()){
		count_read++;
		string str_temp = "";
		getline(fin,str_temp);
		char tmp[1000];
		if(is_end == 0 && count_read > read_line_num){
				break;    //用于不是最后一块文件的跳出	
		}else if(str_temp.size() <= 2){
				break;	 //用于最后1快文件的跳出
		}else{
			fout<<str_temp<<endl;
			string sql = "grep -n \""+str_temp+"\" "+filename;
			cout<<count_read<<endl;
			FILE *fp = popen(sql.c_str(), "r");   //通过popen函数来实现系统调用，返回1个字符数组，保存的系统调用的命令的结果
   			while (fscanf(fp, "%s", tmp) != EOF){
				for(int i = 0;i < 18;i++){
					if(tmp[i] != ':')fout<<tmp[i];
					else{
						fout<<endl;
						break;
					}
				}
			}
        			//puts(tmp);
			//fout<<tmp<<endl;
   			pclose(fp);
		}
	}

}


void test(const char* in_file,const char* out_file,int thread_num,int line_size,int read_line_num,int is_end){
	fstream fout;
	fout.open(out_file,ios::out);
	
	ifstream fin;
	fin.open(in_file,ios::in);
	int count_read =0;
	fin.seekg(get_line_size(line_size,read_line_num,thread_num),std::ios::cur); 
	while(!fin.eof()){
		count_read++;
		string str_temp = "";
		getline(fin,str_temp);
		if(is_end == 0 && count_read > read_line_num){
				break;
				
		}else if(str_temp.size() <= 2){
				break;
		}else{
			//cout<<count_read<<endl;
			fout<<str_temp<<endl;
		}
	}
}

int main(int argc,char *args[])
{
	char* file_1 = "/export/home/liaolanjie/xxq/hhh/BACKUP_RAW_DATA/carp_sequencing/female/assemblyreads/allfc/rightFc.txt";
	string file_name = "/export/home/liaolanjie/xxq/hhh/BACKUP_RAW_DATA/carp_sequencing/female/assemblyreads/carp-F-PCRfree_Round110_Lane8_1.fastq.raw_seq"; //要修改

	int  max_thread = 6;
	//file_1:右端特征码文件，不修改
	//file_name:rz文件
	//max_thread:要跑的进程数
	for(int i = 0;i <  max_thread;i++){
		if ( fork() == 0 ) {  
			/* 子进程程序 */
 			//printf("This is child process  %d\n",i);
			int is_end = 0;    //判断是否是文件最后1块，0表示不是，1表示是
			string out_file = "/export/home/liaolanjie/xxq/hhh/yc/Multi_Thread_linux/data/newtest/Round151_Lane1_1_" + int_to_string(i);     //out_file:生成记录保存的位置   ---要修改,还要修改MAKE文件，共3处地方修改
			if(i ==  max_thread -1)is_end = 1;
			//test(file_1,out_file.c_str(),i,76,4100000,is_end);
			test_grep(file_1,out_file.c_str(),file_name,i,30,100000,is_end);
			exit(0);   //用于进程的退出
		}
		else {
		
 			printf("This is process process\n");
		} 
	}
	return 0;
}

