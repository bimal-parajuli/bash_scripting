#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
using namespace std;

void get_bt_at(int b_t[], int p_id[], int a_t[], int n);
void bt_sort(int a_t[], int p_id[], int b_t[], int n);
void at_sort(int a_t[], int p_id[], int b_t[], int n);
void calc_sjf(int a_t[], int w_t[], int b_t[], int ta_t[], int end_t[], int n);
void display(int p_id[], int b_t[], int w_t[], int ta_t[], int a_t[], int n);
void display_avg(int ta_t[], int w_t[],  int n);

int main()
{
    int n;
    cout << "Enter the total number of processes to be scheduled.: ";
    cin >> n;
    
    int p_id[n];
    int b_t[n];
    int w_t[n];
    int end_t[n];
    int ta_t[n];
    int a_t[n];

    get_bt_at(b_t, p_id, a_t, n);

    at_sort(a_t, p_id, b_t, n);

    bt_sort(a_t, p_id, b_t, n);

    calc_sjf(a_t, w_t, b_t, ta_t, end_t, n);

    display(p_id, b_t, w_t, ta_t, a_t, n);

    display_avg(ta_t, w_t, n);


    return 0;
}







void get_bt_at(int b_t[], int p_id[], int a_t[], int n)
{
    cout << "Enter Burst and arrival of all processes :: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\n For process" << i+1 << endl;
        p_id[i] = i;

        cout << "Enter brusttime (b_t) :: ";
        cin >> b_t[i];
        cout << "Enter arrivaltime (a_t) :: ";
        cin >> a_t[i];
    }
}

void bt_sort(int a_t[], int p_id[], int b_t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a_t[i] == a_t[j])
            {
                if (b_t[i] > b_t[j])
                {
                    swap(p_id[i], p_id[j]);
                    swap(a_t[i], a_t[j]);
                    swap(b_t[i], b_t[j]);
                }
            }
        }
    }
}


void at_sort(int a_t[], int p_id[], int b_t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a_t[i] > a_t[j])
            {
                swap(p_id[i], p_id[j]);
                swap(a_t[i], a_t[j]);
                swap(b_t[i], b_t[j]);
            }
        }
    }
}



void calc_sjf(int a_t[], int w_t[], int b_t[], int ta_t[], int end_t[], int n)
{
    int temp;
    int value;


    for(int i=0; i<n; i++)
    {
        w_t[i] = 0;
        ta_t[i] = 0;
        end_t[i] = 0;
    }

    end_t[0] = a_t[0] + b_t[0];
    ta_t[0] = end_t[0] - a_t[0];
    w_t[0] = ta_t[0] - b_t[0];

    for (int i = 1; i < n; i++)
    {
        temp = end_t[i - 1];
        int low = b_t[i];
        for (int j = i; j < n; j++)
        {
            if (temp >= a_t[j] && low >= b_t[j])
            {
                low = b_t[j];
                value = j;
            }
        }
        end_t[value] = temp + b_t[value];
        ta_t[value] = end_t[value] - a_t[value];
        w_t[value] = ta_t[value] - b_t[value];
    }
}

void display(int p_id[], int b_t[], int w_t[], int ta_t[], int a_t[], int n)
{
    cout << endl
         << endl;

    cout << "Process ID"
         << " \t"
         << "Arrival Time"
         << " \t"
         << "Burst Time"
         << " \t"
         << "Waiting Time"
         << " \t"
         << "Turn Around Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p_id[i] << "\t\t" << a_t[i] << "\t\t" << b_t[i] << "\t\t" << w_t[i] << "\t\t" << ta_t[i] << endl;
    }

    cout << endl
         << endl;
}


void display_avg(int ta_t[], int w_t[],  int n)
{
    float av_tat = 0.0;
    float av_wt = 0.0;
    for(int i=0; i<n; i++)
    {
        av_tat += 1.0 * ta_t[i];
        av_wt += 1.0 * w_t[i];
    }

    av_tat = av_tat/n*1.0;
    av_wt = av_wt/n*1.0;

    cout << "The average turn-around-time is :: " << av_tat << endl;
    cout << "The average waiting-time is :: " << av_wt << endl;

}
