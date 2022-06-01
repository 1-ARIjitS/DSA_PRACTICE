#include <bits/stdc++.h>

using namespace std;
//method 1- brute force approach in O(n^2) time and O(1) space
int maxprofitbrute(int a[], int n)
{
    int profit=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int diff=(a[j]-a[i]);
            if(diff>profit)
            {
                profit=diff;
            }
        }
    }
    return profit;
}

//method 2- using auxiliary maximum array in O(n) time and O(n) space
int maxprofitauxmaxarray(int a[], int n)
{
    int profit=0;
    int auxmax[n];
    auxmax[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        auxmax[i]=max(auxmax[i+1],a[i]);
    }
    for(int i=0;i<n;i++)
    {
        int diff=auxmax[i]-a[i];
        if(diff>profit)
        {
            profit=diff;
        }
    }
    return profit;
}

//method 3- using no extra space
int maxprofitwithoutextraspace(int a[], int n)
{
    int profit=0;
    int minn=a[0];
    for(int i=0;i<n;i++)
    {
        minn=min(minn,a[i]);
        int diff= a[i]-minn;
        profit=max(profit,diff);
    }
    return profit;
}

int main()
{
    int a[]={7,1,5,3,6,4};
    //int a[]={7,6,4,3,1};
    int n=sizeof(a)/sizeof(a[0]);
    //cout<<maxprofitbrute(a,n);
    //cout<<maxprofitauxmaxarray(a,n);
    cout<<maxprofitwithoutextraspace(a,n);
}
