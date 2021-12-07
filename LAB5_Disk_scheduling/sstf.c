#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void gethead();   // Function to get the starting position of the read/write head from the user.
void getnumber(); // Function to get the number of requests from the user.
void getdata();   // Function to get the array of actual requests from the user.
void set_zero();  // Sets the completion of each request to zero initially. Initializing the completion_array.
void sstf();      // Function to calculate and display the total seek time using SSTF algorithm.
void mark_visited(int);
int getnearest(int);

int n;                 // n           = number of requests coming to the disk.
int head;              // head        = The starting position of the reader head of the disk
int upper_limit = 199; // upper_limit = Upper limit of number of sectors in disk.
int lower_limit = 0;   // lower_limit = Lower Limit of number of sectors in disk.
int *request_array;    // Array containing the requests in order.
int *visited_array;    // Array containing a flag corresponding to each request. denoting whether completed or not.
int nearest_position;
// Main function starts here
int main()
{

    gethead();
    getnumber();
    getdata();
    set_zero();
    sstf();

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

void set_zero()
{
    visited_array = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        visited_array[i] = 0;
    }
}

void sstf()
{
    int temp, nearest, head_position, total = 0;
    head_position = head;

    nearest = getnearest(head_position);
    while (nearest != -1)
    {
        total += abs(nearest - head_position);
        mark_visited(nearest_position);
        head_position = nearest;
        nearest = getnearest(head_position);
    }

    printf("%d", total);
}

void mark_visited(int position)
{
    visited_array[position] = 1;
}
print_array()

{
    for(int i=0; i<n; i++)
    {
        printf("%d\n", request_array[i]);
    }
    for(int i=0; i<n; i++)
    {
        printf("%d");
    }
}
int getnearest(int head_pos)
{
    int temp = -1, position_of_min = -1, current_min_distance = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (visited_array[i] == 0)
        {
            if ((abs(request_array[i] - head_pos)) < current_min_distance)
            {
                temp = request_array[i];
                position_of_min = i;
            }
        }
    }

    if (temp != -1)
    {
        printf("\n\nNext nearest is: %d", temp);
        printf("\nPosition of next nearest is: %d", position_of_min);

        mark_visited(position_of_min);
    }

    return temp;
}
