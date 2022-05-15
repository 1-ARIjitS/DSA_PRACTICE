#include <bits/stdc++.h>

using namespace std;

void reverse_array(int a[],int n)
{
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        swap(a[i],a[j]);
    }
}

void reverse_array(int a[],int start, int end)
{
    while(start<end)
    {
        swap(a[start],a[end]);
        start++;
        end--;
    }
}

void recursive_reverse_array(int a[],int start, int end)
{
    if(start>end)
        return;
    swap(a[start],a[end]);
    recursive_reverse_array(a,start+1,end-1);
}


void print_array(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8};
    int n= sizeof(a)/sizeof(a[0]);
    //reverse_array(a,n);
    //reverse_array(a,0,n-1);
    recursive_reverse_array(a,0,n-1);
    print_array(a,n);
}
