#include <bits/stdc++.h>

using namespace std;
//method 1- using sorting and 2 pointer approach O(nlgn) time and O(1) space
int mindiffsort2pointer(int a[], int n, int m)
{
    sort(a,a+n);
    int mindiff=INT_MAX;
    int i=0;
    int j=m-1;
    while(i<n && j<n)
    {
        int diff=a[j]-a[i];
        mindiff=min(mindiff,diff);
        i++;
        j++;
    }
    return mindiff;
}

int main()
{
    //int a[]={3, 4, 1, 9, 56, 7, 9, 12};
    //int m=5;
    int a[]={7, 3, 2, 4, 9, 12, 56};
    int m=3;
    int n=sizeof(a)/sizeof(a[0]);
    cout<<mindiffsort2pointer(a,n,m);
}
