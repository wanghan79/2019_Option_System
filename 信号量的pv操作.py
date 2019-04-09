Swait(S1,t1,d1,.......Sn,tn,dn)#P操作
    while(TRUE)
        if(S1>=t1&&...&&Sn>=t1)
            for i range(1,n+1):
                Si-=di;
            break;
        else:
            将进程放在等待队列，直到有ti个资源才给Si分配

Ssignal(S1,d1,....,Sn,dn)#V操作
    while(TURE)
        for i range(1,n+1):
            Si+=di;
            将进程移入就绪队列
            
    
 