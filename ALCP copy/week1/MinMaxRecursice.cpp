#include<iostream>
using namespace std;

int a[100];

void MinMax(int i, int j, int &max, int &min)
{
    int mid, max1, min1;

    if(i == j)
    {
        max = min = a[i];
    }
    else if(i == j-1)
    {
        if(a[i] < a[j])
        {
            max = a[j];
            min = a[i];
        }
        else
        {
            max = a[i];
            min = a[j];
        }
    }
    else
    {
        mid = (i + j) / 2;

        MinMax(i, mid, max, min);
        MinMax(mid + 1, j, max1, min1);

        if(max < max1)
        {
            max = max1;
        }

        if(min > min1)
        {
            min = min1;
        }
    }
}

int main()
{
    int n, max, min;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    MinMax(0, n-1, max, min);

    cout << "Max and Min elements are = "
         << max << " " << min << endl;

    return 0;
}