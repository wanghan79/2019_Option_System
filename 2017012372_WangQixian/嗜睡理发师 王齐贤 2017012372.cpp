//PC�ܳ����� 
Monitor PC{
	int waiting; //�˿���
	int chairs; //������
	semaphore customers,barbers,mutex;
	customers = 0;
	barbers = 0;
	waiting = 0;
	mutex = 1;
	
	barber()//��ʦ���� 
	{
		while(true)
		{
			wait(customers); //���޹˿ͣ���ʦ˯��
			wait(mutex); //����
			waiting--; //�ȴ��˿ͼ���1 
			signal(barbers);//��ʦΪһ���˿ͼ���
			signal(mutex);//�뿪�ٽ���
			Cut_hair(); 
		}
	}
	Customer(int i)//�˿ͽ��� 
	{
		wait(mutex);//���̻���
		if(waiting<chairs){
			waiting++;//�ȴ��˿�+1
			signal(customers);//������ʦ
			signal(mutex);//�����ٽ���
			wait(barbers);//�ȴ���ʦ
			Get_haircut();//�� 
		} 
		else 
			signal(mutex);//���� 
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
