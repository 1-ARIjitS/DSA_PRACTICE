#include <bits/stdc++.h>

using namespace std;
//method 1- simple approach
void cyclicrotate_simple(int a[], int n)
{
    int temp=a[n-1];
    for(int i=n-2;i>=0;i--)
        a[i+1]=a[i];
    a[0]=temp;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

//method 2- 2 pointer approach
void cyclicrotate_2pointer(int a[], int n)
{
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        swap(a[i],a[j]);
        i++;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int n= sizeof(a)/sizeof(a[0]);
    //cyclicrotate_simple(a,n);
    cyclicrotate_2pointer(a,n);
}
