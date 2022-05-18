#include <bits/stdc++.h>

using namespace std;
//method 1- using quick sort partition
void moveposneg_qspartition(int a[],int n)
{
    int p=0;
    int q=n-1;
    int pivot= a[p];
    int i=p;
    for(int j=2;j<n;j++)
    {
        if(a[j]<0)
        {
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[p],a[i]);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

//method 2- 2 pointer approach
void moveposneg_2pointer(int a[],int n)
{
    int l=0;
    int h=n-1;
    while(l<=h)
    {
       if(a[l]>0 && a[h]<0)
       {
           swap(a[l],a[h]);
           l++;h--;
       }
       else if(a[l]<0 && a[h]<0)
       {
           l++;
       }
       else if(a[l]>0 && a[h]>0)
       {
           h--;
       }
       else if(a[l]<0 && a[h]>0)
       {
           l++;h--;
       }
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

//method 3- modification of dutch nation flag algorithm

void moveposneg_dnf(int a[],int n)
{
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        if(a[l]<0)
        {
            l++;
        }
        else if(a[h]>0)
        {
            h--;
        }
        else
        {
            swap(a[l],a[h]);
        }
    }

      for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int a[]={-1,3,-10,4,5,-70,6};
    int n= sizeof(a)/sizeof(a[0]);
    //moveposneg_qspartition(a,n);
    //moveposneg_2pointer(a,n);
    moveposneg_dnf(a,n);
}
