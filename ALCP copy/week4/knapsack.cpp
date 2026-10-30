#include<iostream>
#include<vector>
using namespace std;

vector<double> greedy(vector<int> w, vector<int> p, int M)
{
    vector<double> x;
    vector<double> ratio;

    for(int i = 0; i < w.size(); i++)
    {
        x.push_back(0);
        ratio.push_back((double)p[i] / w[i]);
    }

    int weight = 0;

    while(weight < M)
    {
        int index = -1;
        double max = 0;

        for(int i = 0; i < w.size(); i++)
        {
            if(ratio[i] > max)
            {
                max = ratio[i];
                index = i;
            }
        }

        if(index == -1)
            break;

        if(weight + w[index] <= M)
        {
            x[index] = 1;
            weight = weight + w[index];
            ratio[index] = -1;   // mark item as selected
        }
        else
        {
            x[index] = (double)(M - weight) / w[index];
            weight = M;
        }
    }

    return x;
}

int main()
{
    vector<int> profit = {10, 5, 15, 7, 6, 18, 3};
    vector<int> weight = {2, 3, 5, 7, 1, 4, 1};

    int M = 10;

    vector<double> result = greedy(weight, profit, M);

    double totalProfit = 0;

    cout << "Weight\tProfit\tX\n";

    for(int i = 0; i < weight.size(); i++)
    {
        cout << weight[i] << "\t"
             << profit[i] << "\t"
             << result[i] << endl;

        totalProfit += profit[i] * result[i];
    }

    cout << "\nTotal Profit = " << totalProfit << endl;

    return 0;
}