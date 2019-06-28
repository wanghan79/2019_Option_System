Swait(S1,t1,d1,......Sn,tn,dn)
{
    while(true)
    {
        if (Si>=t1&&...&&Sn>=tn)
        for(i=1;i<n;i++)
            Si=Si-di;
        break;
        else
        {
        Place the ececuting process in the waiting queue associated with the first Si with Si<ti ,
        and set the program countof the process to the beginning of the Swait Operation;
        }
    }
}
Ssignal(S1,d1,......Sn,dn)
{
    while(true)
    {
        for(i=1;i<n;i++)
        {
            Si=Si+di;
            Remove all the process waiting in the queue
            associated with Si into the ready queue;
        }
    }
}

