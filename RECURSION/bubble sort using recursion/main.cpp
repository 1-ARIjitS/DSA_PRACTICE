#include <bits/stdc++.h>

using namespace std;
//simple bubble sort using loops
void bubblesortsimple(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}

//bubble sort using recursion
void bubblesortrec(int a[], int n)
{
    if(n==0 || n==1)
    {
        return;
    }
    else
    {
       for(int i=0;i<n;i++)
       {
           if(a[i+1]<a[i])
           {
               swap(a[i],a[i+1]);
           }
       }
       bubblesortrec(a,n-1);
    }
}

int main()
{
    int a[]={1,5,6,7,3,4,2,0,8,9};
    int n= sizeof(a)/sizeof(a[0]);
    bubblesortrec(a,n);
    //bubblesortsimple(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
