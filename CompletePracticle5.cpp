#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void FCFS(int n, string p[], int AT[], int BT[])
{
    int WT[n];
    int CT[n];
    int TAT[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - (i + 1); j++)
        {
            if (AT[j] > AT[j + 1])
            {
                int temp = AT[j];
                AT[j] = AT[j + 1];
                AT[j + 1] = temp;

                temp = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = temp;

                string temp1 = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp1;
            }
        }
    }

    cout<<"Gantt Chart"<<endl;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            CT[i] = AT[i] + BT[i];
        }
        else
        {
            if (AT[i] > CT[i - 1])
            {
                CT[i] = AT[i] + BT[i];
            }
            else
            {
                CT[i] = BT[i] + CT[i - 1];
            }
        }
        cout<<p[i]<<" "<<CT[i]<<" ";
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }
    cout<<"\n\n";

    cout << "Process\tAT\tBT\tWT\tTAT\tCT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << "\t" << AT[i] << "\t" << BT[i] << "\t" << WT[i] << "\t" << TAT[i] << "\t" << CT[i] << endl;
    }
}

void SJF(int n, string p[], int AT[], int BT[])
{
    int WT[n];
    int CT[n];
    int TAT[n];
    int Burst[n];
    int completed[n];
    memset(completed, 0, sizeof(completed));

    int total = 0, pointer = 0, x = n;

    for (int i = 0; i < n; i++)
    {
        Burst[i] = BT[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (AT[i] < AT[j])
            {
                int temp = AT[j];
                AT[j] = AT[i];
                AT[i] = temp;

                temp = BT[j];
                BT[j] = BT[i];
                BT[i] = temp;

                temp = Burst[j];
                Burst[j] = Burst[i];
                Burst[i] = temp;

                string temp1 = p[j];
                p[j] = p[i];
                p[i] = temp1;
            }
        }
    }
    cout << "Gantt Chart" << endl;
    while (true)
    {
        int min = 99, c = n;
        if (total == n)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            if ((completed[i] == 0) && (AT[i] <= pointer) && (BT[i] < min))
            {
                min = BT[i];
                c = i;
            }
        }
        if (c == n)
        {
            pointer++;
        }
        else
        {
            if (x != c)
            {
                cout << pointer << " ";
                cout << p[c] << " ";
                x = c;
            }
            BT[c]--;
            pointer++;
            if (BT[c] == 0)
            {
                completed[c] = 1;
                CT[c] = pointer;
                total++;
            }
        }
    }
    cout << pointer << "\n\n";
    for (int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - Burst[i];
    }

    cout << "Process\tAT\tBT\tWT\tTAT\tCT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << "\t" << AT[i] << "\t" << Burst[i] << "\t" << WT[i] << "\t" << TAT[i] << "\t" << CT[i] << endl;
    }
}

void Priority(int n, string p[], int AT[], int BT[], int prio[])
{
    int WT[n];
    int CT[n];
    int TAT[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((prio[i] < prio[j]) || (prio[i] == prio[j] && AT[j] < AT[i]))
            {
                string temp1 = p[i];
                p[i] = p[j];
                p[j] = temp1;

                int temp = AT[j];
                AT[j] = AT[i];
                AT[i] = temp;

                temp = prio[j];
                prio[j] = prio[i];
                prio[i] = temp;

                temp = BT[j];
                BT[j] = BT[i];
                BT[i] = temp;
            }
        }
        if(i==0){
            CT[i]=BT[i];
        }
        else{
            CT[i]=CT[i-1]+BT[i];
        }
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        cout << p[i] << " "<<CT[i]<<" ";
    }
    cout << endl;
    cout << "Process\tAT\tBT\tpriority\tWT\tTAT\tCT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << "\t" << AT[i] << "\t" << BT[i] << "\t" << prio[i] << "\t" <<  WT[i] << "\t" << TAT[i] << "\t" << CT[i] << endl;
    }
}

void RR(int n, string p[], int AT[], int BT[])
{
    int WT[n];
    int CT[n];
    int TAT[n];
    int Burst[n];
    int QT, total = 0;

    cout << "Enter Quantum time : ";
    cin >> QT;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (AT[i] > AT[j])
            {
                string temp1 = p[i];
                p[i] = p[j];
                p[j] = temp1;

                int temp = AT[j];
                AT[j] = AT[i];
                AT[i] = temp;

                temp = BT[j];
                BT[j] = BT[i];
                BT[i] = temp;
            }
        }
        Burst[i] = BT[i];
    }
    cout << endl;
    while (1)
    {
        bool complete = true;
        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= total && Burst[i] > 0)
            {
                complete = false;
                if (Burst[i] > QT)
                {
                    total += QT;
                    CT[i] = total;
                    Burst[i] -= QT;
                }
                else
                {
                    total += Burst[i];
                    CT[i] = total;
                    Burst[i] = 0;
                }
                cout << p[i] << " " << CT[i] << " ";
            }
        }
        if (complete == true)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }
    cout << endl;
    cout << "Process\tAT\tBT\tWT\tTAT\tCT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << "\t" << AT[i] << "\t" << BT[i] << "\t" << WT[i] << "\t" << TAT[i] << "\t" << CT[i] << endl;
    }
}

int main()
{
    int n;
    cout << "Enter no of process : ";
    cin >> n;
    string proc[n];
    int AT[n];
    int BT[n];
    int prio[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter process name for " << i + 1 << " process : ";
        cin >> proc[i];
        cout << "Enter arrival time for " << proc[i] << " process : ";
        cin >> AT[i];
        cout << "Enter burst time for " << proc[i] << " process : ";
        cin >> BT[i];
        cout << "Enter priority for " << proc[i] << " process : ";
        cin >> prio[i];
        cout << endl;
    }

    FCFS(n, proc, AT, BT);
    SJF(n, proc, AT, BT);
    Priority(n, proc, AT, BT, prio);
    RR(n, proc, AT, BT);
    return 0;
}
