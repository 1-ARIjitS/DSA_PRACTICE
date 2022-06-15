#include <bits/stdc++.h>

using namespace std;
//method 1-using simple single pass in O(n) time and O(1) space
int maxprofitsingle(int a[], int n)
{
    int maxprofit=0;
    int buy1=INT_MAX,buy2=INT_MAX;
    int profit1=0,profit2=0;
    for(int i=0;i<n;i++)
    {
        buy1=min(buy1,a[i]);
        profit1=max(profit1,a[i]-buy1);
        buy2=min(buy2,a[i]-profit1);
        profit2=max(profit2,a[i]-buy2);
        maxprofit=profit2;
    }
    return maxprofit;
}

//method 2- using dynamic programming in O(n) time and O(n) space
int maxprofitdp(int a[], int n)
{
    int maxprofit=0;
    int dp[n]={0};
    //minimum buying price of stock
    int minn=a[0];
    //maximum selling price of stock
    int maxx=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        maxx=max(maxx,a[i+1]);
        dp[i]=max(dp[i+1],maxx-a[i]);
    }
    for(int i=1;i<n;i++)
    {
        minn=min(minn,a[i-1]);
        dp[i]=max(dp[i-1],dp[i]+(a[i]-minn));
    }
    return dp[n-1];
}

int main()
{
    //int a[]={10, 22, 5, 75, 65, 80};
    int a[]={2, 30, 15, 10, 8, 25, 80};
    int n= sizeof(a)/sizeof(a[0]);
    //cout<<maxprofitsingle(a,n);
    cout<<maxprofitdp(a,n);
}
