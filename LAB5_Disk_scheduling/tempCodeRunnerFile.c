#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void gethead();   // Function to get the starting position of the read/write head from the user.
void getnumber(); // Function to get the number of requests from the user.
void getdata();   // Function to get the array of actual requests from the user.
void fcfs();      // Function to calculate and display the total seek time using FCFS algorithm.

int n;                 // n           = number of requests coming to the disk.
int head;              // head        = The starting position of the reader head of the disk
int upper_limit = 199; // upper_limit = Upper limit of number of sectors in disk.
int lower_limit = 0;   // lower_limit = Lower Limit of number of sectors in disk.
int *request_array;    // Array containing the requests in order.

// Main function starts here
int main()
{
    gethead();
    getnumber();
    getdata();
    fcfs();

    return 0;
}

// Definition of above declared functions:
void gethead()
{
    scanf(" %d", &head);
}

void getnumber()
{
    scanf(" %d", &n);
}

void getdata()
{
    request_array = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &request_array[i]);
    }
}

void fcfs()
{
    int temp, total_seek, head_position, past_position;
    head_position = head;

    total_seek = 0;
    past_position = head_position;
    for (int i = 0; i < n; i++)
    {
        total_seek += abs(request_array[i] - past_position);
        past_position = request_array[i];
    }
    printf("%d", total_seek);

    return 0;
}
