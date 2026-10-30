#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobSequencing(vector<Job> jobs, int n)
{
    // Step 1: Sort jobs by decreasing profit
    sort(jobs.begin(), jobs.end(), compare);

    // Step 2: Find maximum deadline
    int maxDeadline = 0;

    for(int i = 0; i < n; i++)
    {
        if(jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Step 3: Initialize slots
    vector<bool> slot(maxDeadline, false);
    vector<char> schedule(maxDeadline, '-');

    int totalProfit = 0;

    // Step 4: Try to place each job
    for(int i = 0; i < n; i++)
    {
        for(int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--)
        {
            if(slot[j] == false)
            {
                slot[j] = true;
                schedule[j] = jobs[i].id;

                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

    // Step 5: Display result
    cout << "Job Sequence: ";

    for(int i = 0; i < maxDeadline; i++)
    {
        if(schedule[i] != '-')
        {
            cout << schedule[i] << " ";
        }
    }

    cout << endl;
    cout << "Total Profit: " << totalProfit << endl;
}

int main()
{
    int n;

    cin >> n;

    vector<Job> jobs(n);

    for(int i = 0; i < n; i++)
    {
        cin >> jobs[i].id;
        cin >> jobs[i].deadline;
        cin >> jobs[i].profit;
    }

    jobSequencing(jobs, n);

    return 0;
}