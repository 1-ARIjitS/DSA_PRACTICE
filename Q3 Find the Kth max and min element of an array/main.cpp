#include <bits/stdc++.h>

using namespace std;
// using set
int ksmallset(int arr[], int n, int k)
{
    set<int>s(arr,arr+n);
    auto it= s.begin();
    advance(it,k-1);
    return *it;
}

//using min heap
void minheapify(int arr[],int i)
{
    int minchild=min(arr[2*i+1],arr[2*i+2]);
    if((arr[2*i+1]>10 || arr[2*i+1]<0) && (arr[2*i+2]>10 || arr[2*i+2]<0))
    {
        return;
    }
    if(arr[i]>minchild && arr[2*i+1]==minchild)
    {
        swap(arr[i],arr[2*i+1]);
        i=2*i+1;
    }
    else if(arr[i]>minchild && arr[2*i+2]==minchild)
    {
        swap(arr[i],arr[2*i+2]);
        i=2*i+2;
    }
    minheapify(arr,i);
}

void buildminheap(int arr[],int n)
{
    for(int i=(n-1)/2;i>=0;i--)
    {
       minheapify(arr,i);
    }
}

int extractmin(int arr[],int n)
{
    int temp=arr[0];
    arr[0]= arr[n-1];
    minheapify(arr,0);
    n--;
    return temp;
}

int ksamllminheap(int arr[],int n, int k)
{
    buildminheap(arr,n);
    for(int i=0;i<k-1;i++)
    {
        extractmin(arr,n);
    }
    return arr[0];
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int k=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<ksamllminheap(arr,n,k);
}
