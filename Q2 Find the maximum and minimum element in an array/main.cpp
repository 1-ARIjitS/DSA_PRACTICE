#include <bits/stdc++.h>

using namespace std;

class pairs
{
public:
    int min;
    int max;
};
//method 1 using normal linear search
pairs getminmax(int a[], int n)
{
    pairs minmax;

    if(n==1)
    {
        minmax.min=a[0];
        minmax.max=a[0];
    }
    else
    {
        if(a[0]<a[1])
        {
            minmax.min=a[0];
            minmax.max=a[1];
        }
        else
        {
            minmax.min=a[1];
            minmax.max=a[0];
        }
        for(int i=2;i<n;i++)
        {
            if(a[i]>minmax.max)
            {
                minmax.max=a[i];
            }
            else if(a[i]<minmax.min)
            {
                minmax.min=a[i];
            }
        }
    }

    return minmax;
}
// method 2 using tournament method
pairs tournamentminmax(int a[], int l, int r, int n)
{
    pairs minmax;
    if(l==r)
    {
        minmax.min=a[l];
        minmax.max=a[r];
    }
    else if(r==l+1)
    {
       if(a[l]>a[r])
       {
           minmax.min=a[r];
           minmax.max=a[l];
       }
       else
       {
           minmax.min=a[l];
           minmax.max=a[r];
       }
    }
    else
    {
        int m=(l+r)/2;
        pairs leftpair= tournamentminmax(a,l,m,n);
        pairs rightpair= tournamentminmax(a,m+1,r,n);
        if(leftpair.min>rightpair.min)
        {
           minmax.min= rightpair.min;
        }
        else
        {
            minmax.min= leftpair.min;
        }
        if(leftpair.max>rightpair.max)
        {
           minmax.max= leftpair.max;
        }
        else
        {
            minmax.max= rightpair.max;
        }
    }
    return minmax;
}

int main()
{
   int a[]={1,2,3,4,5,6,78,9};
   int n= sizeof(a)/sizeof(a[0]);
   int l=0;
   int r=n-1;
   pairs minmaxpair= tournamentminmax(a,l,r,n);
   cout<<minmaxpair.min<<" "<<minmaxpair.max;
}
