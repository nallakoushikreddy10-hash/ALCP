#include<iostream>
using namespace std;

int PowerTwo(int n)
{
    return n>0 && (n&(n-1))==0;
}
int main()
{
    int n;
    cout<<"enter an element"<<endl;
    cin>>n;
   if(PowerTwo(n))
   {
        cout<<"it is a power of two"<<endl;
   }
   return 0;
}