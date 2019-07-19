//嗜睡理发师管程操作解决方法 
//PC管程可以描述如下 
Monitor procducerconsumer{
	//信号量定义
	int  mutex,N,bb,cm,,sfwaiting;//记录型信号量，座椅，理发师，顾客，沙发,等待 
	public：
	void barber_do()
	{
		wait(cm); 
		waiting--; 
	}
	void get_baber()
	{
		wait(mutex);
		if(waiting<N)
		{
			waiting++;
			signal(CM);
			signal(mutex);
			wait(bb);
		}
		else
		{
			signal(mutex);			
		}
	}
{mutex=1,N=10,bb=1,cm=0,sf=0,waiting=0} 		 
}PC; 
//在利用管程解决嗜睡理发师问题时，其中的理发师和顾客可以描述为：
void barber()
{
	while(1)
	{
		PC.barber_do();
		//理发
		//睡觉 
	}
} 
void customer()
{
	while(1)
	{
		PC.get_baber();
		//被理发	
	}
} 
//主程序
void main()
{
	barber();
	customer();
} 
