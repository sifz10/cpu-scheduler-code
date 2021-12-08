#include<stdio.h>
int main()
{
    int i,j,n,total=0,pos,temp;
    float avg_wt;
    printf("Enter number of process:");
    scanf("%d",&n);
    int burstTime[n],process[n],waitingTime[n];
    
    
    for(i=0;i<n;i++)
    {
        printf("Enter Burst Time For The Process No. #%d:",i+1);
        scanf("%d",&burstTime[i]);
        process[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burstTime[j]<burstTime[pos])
                pos=j;
        }
        // swapping
        temp=burstTime[i];
        burstTime[i]=burstTime[pos];
        burstTime[pos]=temp;
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
    
    waitingTime[0]=0;            
    for(i=1;i<n;i++)
    {
        waitingTime[i]=0;
        for(j=0;j<i;j++)
            waitingTime[i]+=burstTime[j];
        total+=waitingTime[i];
    }
    avg_wt=(float)total/n;      
    total=0; 
    printf("\nProcess\t    Burst Time    \tWaiting Time");
    for(i=0;i<n;i++)
    {
      printf("\nP-ID #%d\t\t  %d\t\t    %d",process[i],burstTime[i],waitingTime[i]);
    }
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    
    return 0;
}
