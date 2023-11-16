#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void first_fit(int block_size[], int m, int process_size[], int n)
{
    int block[n];
    int flag[m];
    memset(block, -1, sizeof(block));
    memset(flag, 0, sizeof(flag));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (block_size[j] >= process_size[i] && flag[j] == 0)
            {
                block[i] = j + 1;
                flag[j] = 1;
                break;
            }
        }
    }

    cout << "\nProcess no\tProcess size\tBlock no\tBlock size" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << process_size[i] << "\t\t";

        if (block[i] != -1)
        {
            cout << block[i] << "\t\t" << block_size[block[i] - 1];
        }
        else
        {
            cout << "Not allocated"
                 << "\t"
                 << "-";
        }
        cout << endl;
    }
}

void best_fit(int block_size[], int m, int process_size[], int n)
{
    int block[n];
    int flag[m];
    memset(block, -1, sizeof(block));
    memset(flag, 0, sizeof(flag));

    for (int i = 0; i < n; i++)
    {
        int best_indx = -1;
        for (int j = 0; j < m; j++)
        {
            if (block_size[j] >= process_size[i] && flag[j] == 0)
            {
                if (best_indx == -1)
                {
                    best_indx = j;
                }
                else if (block_size[best_indx] > block_size[j])
                {
                    best_indx = j;
                }
            }
        }
      if (best_indx != -1)
        {
            block[i] = best_indx + 1;
            flag[best_indx] = 1;
        }
    }
    cout << "\nProcess no\tProcess size\tBlock no\tBlock size" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << process_size[i] << "\t\t";

        if (block[i] != -1)
        {
            cout << block[i] << "\t\t" << block_size[block[i] - 1];
        }
        else
        {
            cout << "Not allocated";
        }
        cout << endl;
    }
}

void worst_fit(int block_size[], int m, int process_size[], int n)
{
    int block[n];
    int flag[m];
    memset(flag, 0, sizeof(flag));
    memset(block, -1, sizeof(block));

    for (int i = 0; i < n; i++)
    {
        int wrst_indx = -1;
        for (int j = 0; j < m; j++)
        {
            if (block_size[j] >= process_size[i] && flag[j] == 0)
            {
                if (wrst_indx == -1)
                {
                    wrst_indx = j;
                }
                else if (block_size[wrst_indx] < block_size[j])
                {
                    wrst_indx = j;
                }
            }
        }

        if (wrst_indx != -1)
        {
            block[i] = wrst_indx + 1;
            flag[wrst_indx] = 1;
        }
    }

    cout << "\nProcess No\tProcess size\tBlock no\tBlock size" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << process_size[i] << "\t\t";

        if (block[i] != -1)
        {
            cout << block[i] << "\t\t" << block_size[block[i] - 1];
        }
        else
        {
            cout << "Not allocated "
                 << "\t-";
        }
        cout << endl;
    }
}

void next_fit(int block_size[], int m, int process_size[], int n)
{
    int block[n];
    int flag[m];
    int j = 0, t = m - 1;
    memset(block, -1, sizeof(block));
    memset(flag, 0, sizeof(flag));

    for (int i = 0; i < n; i++)
    {
        while (j < m)
        {
            if (block_size[j] >= process_size[i] && flag[j] == 0)
            {
                block[i] = j + 1;
                flag[j] = 1;
                t = (j - 1) % m;
                break;
            }
            else if (t == j)
            {
                t = (j - 1) % m;
                break;
            }
            j = (j + 1) % m;
        }
    }
    cout << "\nProcess no\tProcess size\tBlock no\tBlock size" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << process_size[i] << "\t\t";

        if (block[i] != -1)
        {
            cout << block[i] << "\t\t" << block_size[block[i] - 1];
        }
        else
        {
            cout << "Not allocated"
                 << "\t-";
        }
        cout << endl;
    }
}

int main()
{
    int block_size[] = {100, 500, 200, 300, 600};
    int process_size[] = {212, 417, 112, 426};
    int m = sizeof(block_size) / sizeof(block_size[0]);
    int n = sizeof(process_size) / sizeof(process_size[0]);

    int ch;
    char ch1;

    do
    {
        cout << "1)First Fit\n2)Best Fit\n3)Worst Fit\n4)Next Fit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            first_fit(block_size, m, process_size, n);
            break;
        case 2:
            best_fit(block_size, m, process_size, n);
            break;
        case 3:
            worst_fit(block_size, m, process_size, n);
            break;
        case 4:
            next_fit(block_size, m, process_size, n);
            break;
        default:
            cout << "Invalid option..." << endl;
            break;
        }
        cout << "\nDo you want to continue (y/n) : ";
        cin >> ch1;
    } while (ch1 == 'y' || ch1 == 'Y');

    return 0;
}


