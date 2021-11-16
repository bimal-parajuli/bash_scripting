#include<stdio.h>

struct process
{
    char processname[5];
    int arrivaltime;
    int bursttime;
    
    int waitingtime;
    int turnaroundtime;
    
    int starttime;
    int endtime;
};



int main()
{
    int n;
    float averagewaiting, averageturnaround;
    printf("Enter the total number of processes:");
    scanf("%d", &n);
    
    struct process allprocess[n], temp;
    
    
    for(int i=0; i<n; i++)
    {
        allprocess[i].processname[0]='P';
        allprocess[i].processname[1]= (char)(i+1 + '0');         //creating process names for all processes.
        allprocess[i].processname[2]='\0';
    }
    printf("Enter the CPU brust time for all processes:\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d:  ", i+1);
        scanf("%d", &allprocess[i].bursttime);                   //getting the burst times.
        
    }
    
    
    printf("Enter the Arrival times of each processes:\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d:  ", i+1);
        scanf("%d", &allprocess[i].arrivaltime);                 //getting arrivaltimes.
    }
    
    
    
    for(int i=(n-1); i>=0; i--)
    {
        for(int j=1; j<=i; j++)
        if(allprocess[j].arrivaltime < allprocess[j-1].arrivaltime)
        {
            temp = allprocess[j];
            allprocess[j] = allprocess[j-1];                           //sorting processes by arrivaltime.
            allprocess[j-1] = temp;
        }
        
    }
    
    // printf("After sorting by arrivaltime, ");
    
    
    int time = allprocess[0].arrivaltime;
    
    int total_turnaroundtime=0, total_waitingtime=0;
    for(int i=0; i<n;  i++)
    {
        allprocess[i].waitingtime = time - allprocess[i].arrivaltime;
        allprocess[i].turnaroundtime = allprocess[i].waitingtime + allprocess[i].bursttime;
        
        allprocess[i].starttime = time;
        
        time += allprocess[i].bursttime;                 //calculating the total waitingtime, turnaroundtime, etc.
        
        allprocess[i].endtime = time;
        
        
        total_turnaroundtime += allprocess[i].turnaroundtime;
        total_waitingtime += allprocess[i].waitingtime;
    }
    
    
    
    // printf("----------------------------------------------\n");
        printf("Process | BurstTime | ArrivalTime | TurnaroundTime | WaitingTime\n");       //constructing the table of informations.
    // printf("----------------------------------------------\n");
    
    for(int i=0; i<n; i++)
    {
        printf("  %s           %d           %d             %d              %d\n", allprocess[i].processname, allprocess[i].bursttime, allprocess[i].arrivaltime, allprocess[i].turnaroundtime, allprocess[i].waitingtime);   
        printf("                                           \n");
        // printf("----------------------------------------------\n");
    }


    
    printf("\n\n\n\nThe Gantt Chart of FCFS Algorithm based scheduling for given information is as follows:\n");
    int t=n; 
    while(t--){printf("-----------");}
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("|    %s    ",  allprocess[i].processname );         //Gantt Chart construction.
    } 
    printf("|\n");
    
    t=n;
    while(t--){printf("-----------");}
    printf("\n");

    for(int i=0; i<n; i++)
    {
        printf("%d          ", allprocess[i].starttime);
    }
    printf("%d\n", allprocess[n-1].endtime);
    printf("\n\n\n\n");
    
    // for(int i=0; i<n; i++)
    // {
    //     printf("TAT: %d   WAIT: %d\n", allprocess[i].waitingtime, allprocess[i].turnaroundtime);
    // }

    averagewaiting = ((float)total_waitingtime) / n;
    averageturnaround = ((float)total_turnaroundtime) / n;
    printf("The average waiting time is: %f\n", averagewaiting);
    printf("The average turnaround time is: %f\n", averageturnaround);   //Displaying the result.
    return 0;


    
}


