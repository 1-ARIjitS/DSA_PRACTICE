#include <bits/stdc++.h>

using namespace std;

int getmindiff(int a[], int n, int k)
{
    sort(a,a+n);
    int mindiff= a[n-1]-a[0];
    int smallest= a[0]+k;
    int largest= a[n-1]-k;
    int minimum;
    int maximum;
    int diff=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=k)
        {
            minimum=min(smallest,a[i]-k);
            maximum=max(largest,a[i-1]+k);
            diff=maximum-minimum;
            if(diff<mindiff)
            {
                mindiff=diff;
            }
        }
    }
    return mindiff;
}

int main()
{
    int a[]={1,5,8,10};
    int n= sizeof(a)/sizeof(a[0]);
    int k=2;
    cout<<getmindiff(a,n,k);
}
