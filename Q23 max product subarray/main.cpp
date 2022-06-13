#include <iostream>

using namespace std;
//method 1- brute force approach O(n^2) time and O(1) space
int maxpdtbrute(int a[], int n)
{
    int maxpdt=0;
    for(int i=0;i<n;i++)
    {
        int pdt=1;
        for(int j=i;j<n;j++)
        {
            pdt=pdt*a[j];
            maxpdt=max(pdt,maxpdt);
        }
    }
    return maxpdt;
}

//method 2- using single pass and maintaining 4 vars. max,min,current,result in O(n) time and O(1) space
int maxpdtsubarray(int a[], int n)
{
    int maxx=a[0];
    int minn=a[0];
    int maxpdt=a[0];
    for(int i=1;i<n;i++)
    {
        int current=a[i];
        if(a[i]==0)
        {
            maxx=1;
            minn=1;
            continue;
        }
        int currentmax=maxx*current;
        int currentmin=minn*current;
        maxx=max(currentmax,currentmin);
        maxx=max(current,maxx);
        minn=min(currentmax,currentmin);
        minn=max(current,minn);
        maxpdt=max(maxpdt,maxx);
    }
    return maxpdt;
}

int main()
{
    //int a[]={6, -3, -10, 0, 2};
    //int a[]={2,3,4,5,-1,0};
    int a[]={-2,3,0,-2,-4};
    int n= sizeof(a)/sizeof(a[0]);
    //cout<<maxpdtbrute(a,n);
    cout<<maxpdtsubarray(a,n);
}
