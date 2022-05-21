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
        pre_sum[i]=pre_sum[i-1]+a[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=(pre_sum[j]-pre_sum[i-1]);
            if(sum>max)
            {
                max=sum;
            }
        }
    }
    return max;
}

//method 3- without using prefix sum in O(n^2) time
int sumlargestvar(int a[], int n)
{
    int max= INT_MIN;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            if(sum>max)
            {
                max=sum;
            }
        }
    }
    return max;
}

//method 4- kadane's algorithm for O(n) time and O(1) space
int sumlargestkadane(int a[], int n)
{
   int max=INT_MIN;
   int max_till=0;
   for(int i=0;i<n;i++)
   {
       max_till+=a[i];
       if(max_till>max)
       {
           max=max_till;
       }
        if(max_till<0)
       {
           max_till=0;
       }
   }
   return max;
}

int main()
{
   int a[]={-2, -3, 4, -1, -2, 1, 5, -3};
   int n= sizeof(a)/sizeof(a[0]);
   //O(n^3) time and O(1) space
   //cout<<sumlargestbrute(a,n);
   //O(n^2) time and O(1) space
   //cout<<sumlargestprefixsum(a,n);
   //O(n^2) time and O(n) space
   //cout<<sumlargestvar(a,n);
   //O(n) time and O(1) space
   cout<<sumlargestkadane(a,n);
}
