//��˯��ʦ�̲ܳ���������� 
//PC�ܳ̿����������� 
Monitor procducerconsumer{
	//�ź�������
	int  mutex,N,bb,cm,,sfwaiting;//��¼���ź��������Σ���ʦ���˿ͣ�ɳ��,�ȴ� 
	public��
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
//�����ùܳ̽����˯��ʦ����ʱ�����е���ʦ�͹˿Ϳ�������Ϊ��
void barber()
{
	while(1)
	{
		PC.barber_do();
		//��
		//˯�� 
	}
} 
void customer()
{
	while(1)
	{
		PC.get_baber();
		//����	
	}
} 
//������
void main()
{
	barber();
	customer();
} 
