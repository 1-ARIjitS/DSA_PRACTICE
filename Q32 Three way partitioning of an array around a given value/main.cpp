#include <bits/stdc++.h>

using namespace std;
//method 1- simply sort in O(nlgn) time and O(1) space
void partitionsort(int a[], int n, int x, int y)
{
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

//method 2- using space in O(n) time and O(n) space
void partitionspace(int a[], int n, int x, int y)
{
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(a[i]<x)
        {
            v.push_back(a[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>=x && a[i]<=y)
        {
            v.push_back(a[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>y)
        {
            v.push_back(a[i]);
        }
    }
    for(auto it:v)
    {
        cout<<it<<" ";
    }
}

//method 3- using single pass in O(n) time and O(1) space
void partitionsinglepass(int a[], int n, int x, int y)
{
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<x)
        {
            swap(a[k++],a[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>=x && a[i]<=y)
        {
            swap(a[k++],a[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>y)
        {
            swap(a[k++],a[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int a[]={5,7,1,4,6,3};
    int x=2;
    int y=4;
    int n=sizeof(a)/sizeof(a[0]);
    //partitionsort(a,n,x,y);
    //partitionspace(a,n,x,y);
    partitionsinglepass(a,n,x,y);
}
