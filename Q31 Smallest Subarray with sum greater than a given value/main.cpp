#include <bits/stdc++.h>

using namespace std;

//method 1- using brute force in O(n^2) time and O(1) space
int minlensubbrute(int a[], int n, int x)
{
    int minlensub=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            if(sum>x)
            {
                int lensub=(j-i)+1;
                minlensub=min(minlensub,lensub);
            }
        }
    }
    return minlensub;
}

//method 2- using 2 pointer in O(n) time and O(1) space
int minlensub2pointer(int a[], int n, int x)
{
    int i=0;
    int j=0;
    int sum=0;
    int minlensub=INT_MAX;
    while(i<=j && j<n)
    {
        while(sum<=x &&j<n)
        {
            sum+=a[j];
            j++;
        }
        while(sum>x && i<j)
        {
            minlensub=min(minlensub,j-i);
            sum-=a[i];
            i++;
        }
    }
    return minlensub;
}

int main()
{
    int a[]={1, 4, 45, 6, 0, 19};
    int x=51;
    int n=sizeof(a)/sizeof(a[0]);
    //cout<<minlensubbrute(a,n,x);
    cout<<minlensub2pointer(a,n,x);
}
