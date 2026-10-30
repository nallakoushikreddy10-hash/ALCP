#include <iostream>
using namespace std;
int SingleNumber (int a[] , int n)
{
    int result =0;
    for (int i=0;i<n;i++)
    {
        result ^= a[i];

    }
    return result;
}
int main()
{
    int n;
    cout<<"enter no of elements ";
    cin>>n;
    int a[n];
    cout<<"enter the elments ";
    for (int i=0 ;i<n;i++)
    {
        cin>>a[i];

    }
    cout<<"single element : "<<SingleNumber(a,n)<<endl;
    return 0;
    
}