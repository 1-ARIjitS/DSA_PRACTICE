#include <bits/stdc++.h>

using namespace std;
//method 1- using brute force
int countinversionbrute(int a[], int n)
{
    int countinv=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j] && i<j)
            {
                countinv++;
            }
        }
    }
    return countinv;
}

//method 2- using merge sort's merge function
int mergefunction(int a[], int temp[], int left, int mid, int right)
{
    int i=left;
    int j=mid+1;
    int k=left;
    int invcount=0;
    while(i<=mid && j<=right)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
            invcount+=(mid+1-i);
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=right)
    {
        temp[k++]=a[j++];
    }
    for(int m=left;m<=right;m++)
    {
        a[m]=temp[m];
    }
    return invcount;
}

int countinversionmerge(int a[], int temp[], int left, int right)
{
    int invcount=0;
    if(left<right)
    {
       int mid=(left+right)/2;

       invcount+= countinversionmerge(a,temp,left,mid);
       invcount+= countinversionmerge(a,temp,mid+1,right);
       invcount+= mergefunction(a,temp,left,mid,right);
    }
    return invcount;
}

int main()
{
    int a[]={3,5,2,1,8,6,4,9};
    //int a[]={8,4,2,1}'
    //int a[]={3,1,2};
    int n= sizeof(a)/sizeof(a[0]);
    int left=0;
    int right=n-1;
    int temp[n];
    //cout<<countinversionbrute(a,n);
    cout<<countinversionmerge(a,temp,left,right);
}
