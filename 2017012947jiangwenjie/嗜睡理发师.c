Monitor producerconsumer
{
    int bb,cm,N,mutex,SFoccupied;//��ʦ���˿ͣ�ɳ���������ź�������ռ��ɳ��
public:
    void work()
    {
        wait(cm);
        SFoccupied--;
    }
    void guest()
    {
        wait(mutex);
        if(SFoccupied<N)
        {
            SFoccupied++;
            signal(mutex);
            //����ɳ���ϵȴ�;
            signal(cm);
            wait(bb);
        }
        else
        {
            signal(mutex);
            //�뿪;
        }
    }
    {bb=1,cm=0,N=10,mutex=1,SFoccupied=0}
}PC;

void barber()
{
    while(1)
    {
        PC.work();
        //��;
        //˯��;
    }
}
void customer()
{
    while(1)
    {
        PC.guest();
        //�ͷ�����;
        //����;
    }
}
void main()
{
    barber();
    customer();
}
