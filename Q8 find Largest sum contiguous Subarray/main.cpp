#include <bits/stdc++.h>

using namespace std;

//method-1 brute force O(n^3) approach
int sumlargestbrute(int a[], int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=a[k];
            }
            if(sum>max)
            {
                max=sum;
            }
        }
    }
    return max;
}

//method-2 using prefix sum O(n^2) time approach
int sumlargestprefixsum(int a[], int n)
{
    int pre_sum[n+1];
    pre_sum[0]=0;
    int max=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        pre_sum[i]=pre_sum[i-1]+a[i-1];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            sum+=(pre_sum[j+1]-pre_sum[i]);
            if(sum>max)
                max=sum;
        }
    }
    return max;
}

int main()
{
   int a[]={-2, -3, 4, -1, -2, 1, 5, -3};
   int n= sizeof(a)/sizeof(a[0]);
   cout<<sumlargestprefixsum(a,n);
}
