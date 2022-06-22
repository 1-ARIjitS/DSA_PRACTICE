#include <bits/stdc++.h>

using namespace std;
//method 1- using sliding window approach in O(n^2) time and O(1) space
int minswapsslidingwindow(int a[], int n, int k)
{
    int fav=0;
    int nonfav=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=k)
        {
            fav++;
        }
    }
    for(int i=0;i<fav;i++)
    {
        if(a[i]>k)
        {
            nonfav++;
        }
    }
    int minswaps=INT_MAX;
    int l=0;
    int r=fav-1;
    while(l<n && r<n)
    {
        minswaps=min(minswaps,nonfav);
        r++;
        if(a[r]>k)
        {
            nonfav++;
        }
        if(a[l]>k)
        {
            nonfav--;
        }
        l++;
    }
    return minswaps;
}

int main()
{
    int a[]={2, 1, 5, 6, 3};
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;
    //cout<<minswapsbrute(a,n);
    cout<<minswapsslidingwindow(a,n,k);
}
