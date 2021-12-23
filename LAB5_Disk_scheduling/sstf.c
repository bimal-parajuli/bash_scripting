#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

void gethead();    //Function to get the starting position of the read/write head from the user.
void getnumber();  //Function to get the number of requests from the user.
void getdata();    //Function to get the array of actual requests from the user.
void sstf();       //Function to calculate and display the total seek time using SSTF algorithm.

int n;                  // n           = number of requests coming to the disk.
int head;               // head        = The starting position of the reader head of the disk
int upper_limit=199;    // upper_limit = Upper limit of number of sectors in disk.
int lower_limit = 0;    // lower_limit = Lower Limit of number of sectors in disk.
int *request_array;     // Array containing the requests in order.


//Main function starts here
int main()
{
    gethead();
    getnumber();
    getdata();
    sstf();

    return 0;
}

//Definition of above declared functions:
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

void sstf()
{
    int counter=0, min, min_index, diff, lowest, highest, head_position=head, total=0;
    
    while(counter != n)
    {
        min = INT_MAX;
        for(int i=0; i<n; i++)
        {
            diff = abs(request_array[i] - head_position);
            
            if(diff < min)
            {
                min=diff;
                min_index=i;
            }
        }
        total += min;
        head_position = request_array[min_index];
        
        request_array[min_index]=INT_MAX;
        counter += 1;
    }
    
    printf("%d", total);
}


