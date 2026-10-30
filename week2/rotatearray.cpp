#include <iostream>
#include <vector>
using namespace std;


void reverseArray(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}


void rotateArray(vector<int> &arr, int k)
{
    int n = arr.size();

    k = k % n;

    reverseArray(arr, 0, n - 1);
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    rotateArray(arr, k);

    cout << "Rotated Array: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}