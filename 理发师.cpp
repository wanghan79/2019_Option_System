struct cut_hair{
	int customes=0;
	int barber=0;
	int murtex=1;
	int chairs=N;
	int waiting=0;
	void work(int customers){
		wait(customers);
		wait(murtex);
		waiting=waiting-1;
		signal(barber);
		signal(murtex);
		cuthair;
	}
	void cut(int waiting){
		wait(murtex);
		if(waiting<chairs)
		{
			waiting=wating+1;
			signal(customers);
			signal(murtex);
			wait(barber);
			get cut;
		}
		else
			signal(murtex);
	}
}ch; 
void barbers(void){
	waite;
	while(true){
		ch.work(customers);
	}
}
void custom(void){
	waite;
	while(true)
	{
		ch.cut(waiting);
	}
}
int main()
{
	barber();
	custom();
}
