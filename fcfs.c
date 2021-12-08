#include <stdio.h>

int main()
{
    int a;
    int TotalWaitingTime = 0;
    printf("How many process : ");
    scanf("%d", &a);  
    int burstTime[a];
    int arrivalTime[a];
    
    for(int j = 1; j <= a; j++){
        printf("Enter Burst Time For Process No.#%d : ", j);
        scanf("%d", &burstTime[j]);
    } 
    
    for(int k = 0; k < a; k++){
        printf("Enter Arrival Time For Process No.#%d : ", k+1);
        scanf("%d", &arrivalTime[k]);
    }
    
    burstTime[0] = arrivalTime[0];
    for(int i = 1; i<a; i++){
        int waitingTime = burstTime[i-1] + burstTime[i];
        TotalWaitingTime = TotalWaitingTime+waitingTime;
    }
    printf("Averrage Waiting Time : %.1f", (float)TotalWaitingTime/a);
    return 0;
}