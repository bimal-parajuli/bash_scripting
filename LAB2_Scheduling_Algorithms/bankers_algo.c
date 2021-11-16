#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct request_data
{
    int size, resource_types, id[50], req_time[50], request[5][50];
} request_data;

typedef struct data_of_processes
{
    int process_id, size;
    int allocation[50];
    int max[50];
    int need[50];
} data_of_processes;

typedef struct resource_data
{
    char id[50];
    int size;
    int total_instance[50];

    int available[50];
} resource_data;
request_data no_req = {0, 0, 0, 0, 0};


void add_array(int *arr1, int *arr2, int *arr3, int n);
void subtract_array(int *arr1, int *arr2, int *arr3, int n);
bool operation_less_than(int *arr1, int *arr2, int n);
bool safety_algorithm(data_of_processes *Process, resource_data Resources, request_data req, int n, int m);
void resource_request_algorithm(data_of_processes *Process, resource_data Resources, int n, int m);

int main()
{

    int n, m;
    char id = 'A';
    bool system_state;

    printf("Enter the number of resources : ");
    scanf("%d", &m);

    printf("\nEnter the number of processes : ");
    scanf("%d", &n);

    data_of_processes processes[n];
    resource_data resource_types;
    resource_types.size = m;

    int allocated_instances[m];
    memset(allocated_instances, 0, m * sizeof(int));

    printf("Enter information on resources.\n");

    for (int i = 0; i < m; i++)
    {
        resource_types.id[i] = id;
        printf("Enter max instances for resource %c = ", id);
        id++;

        scanf("%d", &resource_types.total_instance[i]);
    }

    printf("Enter information on Processes.\n");

    for (int i = 0; i < n; i++)
    {
        printf("For Process%d\n", i + 1);
        printf("Enter %d Maximum resource needed for completion :: \n ", m);

        for (int j = 0; j < m; j++)
        {
            scanf("%d", &processes[i].max[j]);
        }

        printf("\nEnter %d Allocated resource for each resource :: \n", m);

        for (int j = 0; j < m; j++)
        {
            scanf("%d", &processes[i].allocation[j]);

            allocated_instances[j] += processes[i].allocation[j];
        }

        subtract_array(processes[i].need, processes[i].max, processes[i].allocation, m);
    }

    subtract_array(resource_types.available, resource_types.total_instance, allocated_instances, m);

    system_state = safety_algorithm(processes, resource_types, no_req, n, m);

    if (!system_state)
    {
        printf("System is in unsafe state.\n");
    }
    else
    {
        printf("System is in safe state, \n");
    }

    printf("\n");

    resource_request_algorithm(processes, resource_types, n, m);

    return 0;
}

void add_array(int *arr1, int *arr2, int *arr3, int n)
{

    for (int i = 0; i < n; i++)
        arr1[i] = arr2[i] + arr3[i];
}

void subtract_array(int *arr1, int *arr2, int *arr3, int n)
{

    for (int i = 0; i < n; i++)
        arr1[i] = arr2[i] - arr3[i];
}

bool operation_less_than(int *arr1, int *arr2, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (arr1[i] > arr2[i])
            return false;
    }

    return true;
}


bool safety_algorithm(data_of_processes *Process, resource_data Resources, request_data req, int n, int m)
{

    int running_time = 0;
    int rc = 0;

    int work[m];
    int need[n][m];
    int allocation[n][m];

    bool finished[n];
    memset(finished, 0, n * sizeof(finished));

    int safe_sequence[n];
    int counter = 0;
    int i = 0;

    bool one_task_completed = false;
    bool request_granted;
    int completed = 0;

    memcpy(work, Resources.available, m * sizeof(int));

    for (int k = 0; k < n; k++)
    {
        memcpy(need[k], Process[k].need, m * sizeof(int));
        memcpy(allocation[k], Process[k].allocation, m * sizeof(int));
    }

    while (completed < n)
    {

        if (rc < req.size)
        {
            if (req.req_time[rc] == running_time)
            {
                int process_id = req.id[rc];

                bool req_lt_need = operation_less_than(req.request[rc], need[process_id], m);

                bool req_lte_work = operation_less_than(req.request[rc], work, m);

                if (req_lt_need && req_lte_work)
                {
                    subtract_array(work, work, req.request[rc], m);

                    add_array(allocation[process_id], allocation[process_id], req.request[rc], m);

                    subtract_array(need[process_id], need[process_id], req.request[rc], m);
                }

                rc++;
            }
        }

        if (!finished[i] && operation_less_than(need[i], work, m))
        {

            finished[i] = true;

            add_array(work, work, allocation[i], m);

            completed++;
            safe_sequence[counter] = i;
            counter++;
            one_task_completed = true;
        }

        running_time++;

        if (i == n - 1)
        {

            if (!one_task_completed)
            {
                printf("Process cannot be completed. No safe sequence can be found.\n");
                return false;
            }

            one_task_completed = false;
            i = 0;
        }
        else
        {
            i++;
        }
    }

    // display  the safe sequence

    printf("\nSafe sequence is  ::\n");

    for (i = 0; i < counter - 1; i++)
    {
        printf("P%d ->  ", safe_sequence[i]);
    }

    printf("P%d \n", safe_sequence[i]);

    return true;
}

void resource_request_algorithm(data_of_processes *Process, resource_data Resources, int n, int m)
{

    int no_of_requests;
    int sub_req;
    bool system_state;
    int k;

    printf("\n\nEnter number of requests to be sent = ");
    scanf("%d", &no_of_requests);

    request_data req[no_of_requests];

    for (int i = 0; i < no_of_requests; i++)
    {
        printf("\n\nEnter number of requests for Request %d = ", i + 1);
        scanf("%d", &sub_req);

        req[i].size = sub_req;
        req[i].resource_types = m;

        for (int j = 0; j < sub_req; j++)
        {

            printf("\n\nEnter details about request.\nProcess id = ");
            scanf("%d", &req[i].id[j]);

            printf("Time of request = ");
            scanf("%d", &req[i].req_time[j]);

            printf("Enter %d space separated reqource instances for request = ", m);

            for (k = 0; k < m; k++)
            {
                scanf("%d", &req[i].request[j][k]);
            }
        }
    }

    for (int i = 0; i < no_of_requests; i++)
    {

        printf("\n-------------------------------\n\n---------For request made by :: \n");

        for (int j = 0; j < req[i].size; j++)
        {
            printf("Process %d, time=%d, resources (", req[i].id[j], req[i].req_time[j]);

            for (k = 0; k < m - 1; k++)
            {
                printf("%d, ", req[i].request[j][k]);
            }
            printf("%d)\n", req[i].request[j][k]);
        }

        system_state = safety_algorithm(Process, Resources, req[i], n, m);

        if (!system_state)
        {
            printf("System is in unsafe state.\n");
        }
        else
        {
            printf("System is in safe state, since there exists a safe sequence, \n");
        }
    }
}
