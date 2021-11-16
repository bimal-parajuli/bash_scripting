#include <stdio.h>
#include <conio.h>

int main()
{

    int i, n, sum = 0, count = 0, y, time_quantum, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    printf(" Total number of process in the system: ");
    scanf("%d", &n);
    y = n;

    for (i = 0; i < n; i++)
    {
        printf("\n\n\n For Process %d ::\n", i + 1);

        printf("Arrival time ??  ");
        scanf("%d", &at[i]);

        printf("Burst Time ?? ");
        scanf("%d", &bt[i]);
        
        temp[i] = bt[i];
    }

    printf("Enter the time Quantum for scheduling processes :: \t");
    scanf("%d", &time_quantum);

    printf("\nProcess ID    Burst Time   TurnaroundTime    Waiting Time ");
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= time_quantum && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - time_quantum;
            sum = sum + time_quantum;
        }
        if (temp[i] == 0 && count == 1)
        {
            y--;
            printf("\n%d  \t\t %d\t\t %d\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    avg_wt = wt * 1.0 / n;
    avg_tat = tat * 1.0 / n;
    printf("\n\n\n Average Turn Around Time is :: \t%f", avg_wt);
    printf("\n Average Waiting Time is :: \t%f", avg_tat);

    return 0;
}