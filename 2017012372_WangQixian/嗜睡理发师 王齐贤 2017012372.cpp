//PC管程描述 
Monitor PC{
	int waiting; //顾客数
	int chairs; //椅子数
	semaphore customers,barbers,mutex;
	customers = 0;
	barbers = 0;
	waiting = 0;
	mutex = 1;
	
	barber()//理发师进程 
	{
		while(true)
		{
			wait(customers); //若无顾客，理发师睡眠
			wait(mutex); //互斥
			waiting--; //等待顾客减少1 
			signal(barbers);//理发师为一个顾客剪发
			signal(mutex);//离开临界区
			Cut_hair(); 
		}
	}
	Customer(int i)//顾客进程 
	{
		wait(mutex);//进程互斥
		if(waiting<chairs){
			waiting++;//等待顾客+1
			signal(customers);//唤醒理发师
			signal(mutex);//开放临界区
			wait(barbers);//等待理发师
			Get_haircut();//理发 
		} 
		else 
			signal(mutex);//人满 
	}
}PC; 
int main(void)
{
	while(true)
	{
		PC.barber();
		PC.Customer();
	}
}
