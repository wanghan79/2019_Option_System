//2017012344 李奇 操作系统第一次作业 
Swait(S1,ti,d1,...,Sn,tn,dn)
{
	while(TRUE)
	{
		if(S1>=t1 && ... && Sn>=tn)
		{
			for(i=1;i<=n;i++)
			{
				Si:=Si-di;
			}
			break;
		}
		else
		{
			place the process in the waiting queue associated of 
			the first Si found with Si<ti and set the program count 
			of this process to the begining of the Swait operation. 
		}
	}	
} 
Ssingal(S1,ti,d1,...,Sn,tn,dn)
{
	while(TRUE)
	{
		for(i=1;i<=n;i++)
		{
			Si:=Si-di;	
			Remove all the process waiting in the queue 
			associated with Si into the ready queue. 
		}	
	} 
} 
