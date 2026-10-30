#include<iostream>
using namespace std;
void interchange(int &x ,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}
int partition(int a[],int low,int high)
{
    int pivot=a[low];
    int i=low;
    int j=high+1;
    while(i<j)
    {
        do
        {
            i++;
        } while (i<=high&&a[i]<pivot);
        do
        {
            j++;
        } while (a[j]>pivot);
        if(i>=j)
        {
            break;
        }
        interchange(a[low],a[j]);
    }
    interchange(a[low],a[j]);
    return j;
}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int main()
{
    int n;
    cout<<"enter number of elements";
    cin>>n;
    int a[n];
    cout<<"enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    cout<<"sorted array";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"";
    }
    return 0;
}