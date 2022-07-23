#include <bits/stdc++.h>

using namespace std;
//merge sort using recursion
void mergefunction(int a[], int left, int mid, int right, int aux[])
{
    int i=left;
    int j=mid+1;
    int k=left;
    while(i<=mid && j<=right)
    {
        if(a[i]<a[j])
        {
            aux[k++]=a[i++];
        }
        else if(a[i]>a[j])
        {
            aux[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        aux[k++]=a[i++];
    }
    while(j<=right)
    {
        aux[k++]=a[j++];
    }
    for(int i=left;i<=right;i++)
    {
        a[i]= aux[i];
    }
}

void mergesort(int a[], int left, int right, int aux[])
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergesort(a,left,mid,aux);
        mergesort(a,mid+1,right,aux);
        mergefunction(a,left,mid,right,aux);
    }
}

int main()
{
    int a[]={1,5,3,4,2,0};
    int n= sizeof(a)/sizeof(a[0]);
    int left=0;
    int right=n-1;
    int aux[n];
    mergesort(a,left,right,aux);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
