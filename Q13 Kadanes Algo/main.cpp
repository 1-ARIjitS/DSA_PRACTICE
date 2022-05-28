#include <bits/stdc++.h>

using namespace std;

int kadane_max_sum_contiguos_subarray(int a[], int n)
{
    int max_sum=INT_MIN;
    int max_th=0;
    bool ispositive=false;
    for(int i=0;i<n;i++)
    {
       if(a[i]>0)
       {
           ispositive=true;
           break;
       }
    }
    if(ispositive)
    {
        for(int i=0;i<n;i++)
        {
            max_th+=a[i];
            if(max_th>max_sum)
            {
                max_sum=max_th;
            }
            if(max_th<0)
            {
                max_th=0;
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]>max_sum)
            {
                max_sum=a[i];
            }
        }
    }
    return max_sum;
}

int main()
{
    int a[]={-2,-1,-3,-4};
    int n= sizeof(a)/sizeof(a[0]);
    cout<<kadane_max_sum_contiguos_subarray(a,n);
}
