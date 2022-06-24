#include <bits/stdc++.h>

using namespace std;
int median(int a[], int n)
{
    sort(a,a+n);
    if(n%2==0)//even number of elements
    {
        return (a[n/2]+a[n/2-1])/2;
    }
    else//odd no. of elements
    {
        return a[n/2];
    }
}

int main()
{
    //int a[]={90,100,78,89,67};
    int a[]={56,67,30,79};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<median(a,n);
}
