#include<iostream>
#include<vector>
using namespace std;
int fibonacciTD(int x)
{
    vector <int>  memo(x+1,-1);
    if(x<=1)
    {
        return x;
    }
    if(memo[x]!=-1)
    {
        return memo[x];
    }
    memo[x]=fibonacciTD(x-1)+fibonacciTD(x-2);
    return memo[x];

}
int fibonacciBU(int x)
{
    vector<int> dp(x+1);
    if(x<=1)
    {
        return x;
    }
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=x;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[x];


}
int main()
{
    int n;
    cout<<"enter a number";
    cin>>n;
    cout<<"TOP DOWN  :"<<fibonacciTD(n)<<endl;
    cout<<"bottom up :"<<fibonacciBU(n)<<endl;
    return 0;

}