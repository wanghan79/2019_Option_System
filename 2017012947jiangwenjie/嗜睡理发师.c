Monitor producerconsumer
{
    int bb,cm,N,mutex,SFoccupied;//理发师，顾客，沙发，互斥信号量，被占用沙发
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
            //坐在沙发上等待;
            signal(cm);
            wait(bb);
        }
        else
        {
            signal(mutex);
            //离开;
        }
    }
    {bb=1,cm=0,N=10,mutex=1,SFoccupied=0}
}PC;

void barber()
{
    while(1)
    {
        PC.work();
        //理发;
        //睡觉;
    }
}
void customer()
{
    while(1)
    {
        PC.guest();
        //释放座椅;
        //被理发;
    }
}
void main()
{
    barber();
    customer();
}
