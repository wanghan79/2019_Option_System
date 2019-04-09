# 2019_Option_System
For the course of Option System of 2019
Swait(S1,t1,d1,...Sn,tn,dn);
{
  while(TRUE)
   {
     if(Si >= ti && Sn >= tn){
     for(i = 1; i <= n; i++) Si--;
     break;
     }
     else
     {
     place the process in the waiting queue associated with the first Si found with Si < ti,and set the program count of this process
     to the beginning of Swait operation
     }
     }
     }
     Ssignal(S1, d1, ..., Sn, dn);
     {
     while(TRUE){
     for(i = 1; i <= n; i++){
     Si++;
     ti++;
     Remove all the process waiting in the queue associated with Si into the ready queue
     }
     }
     }
     
