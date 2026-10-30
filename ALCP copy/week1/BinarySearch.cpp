#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x)
{
    if(low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if(arr[mid] == x)
    {
        return mid;  
    }
    if(x > arr[mid])
    {
        return binarySearch(arr, mid + 1, high, x);
    }
    else
    {
        return binarySearch(arr, low, mid - 1, x);
    }
}

int main()
{
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to search: ";
    cin >> x;
    int result = binarySearch(arr, 0, n - 1, x);
    if(result != -1)
    {
        cout << "Element found at index " << result;
    }
    else
    {
        cout << "Not Found";
    }
}