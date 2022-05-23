#include <bits/stdc++.h>

using namespace std;

//method 1- brute force approach O(n^2) time and O(1) space
int finddupbrute(int a[], int n)
{
    int dupliacte;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                dupliacte= a[i];
                break;
            }
        }
    }
    return dupliacte;
}

//method 2- using hashing or frequency array O(n) time and O(n) space
int findduphashing(int a[], int n)
{
    int maximum= *max_element(a,a+n);
    int hash_n= maximum+1;
    int hash_array[hash_n]={0};
    for(int i=0;i<n;i++)
    {
        hash_array[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(hash_array[i]>=2)
        {
            return i;
        }
    }
}

//method 3-  using slow and fast pointer in linked lists cycle method
int finddupllcycle(int a[], int n)
{
    int slow=a[0];
    int fast=a[0];
    do
    {
        slow=a[slow];
        fast=a[a[fast]];
    }while(slow!=fast);
    fast=a[0];
    while(slow!=fast)
    {
        slow=a[slow];
        fast=a[fast];
    }
    return slow;
}

int main()
{
   int a[]={1,3,4,2,3};
   int n= sizeof(a)/sizeof(a[0]);
   //cout<<finddupbrute(a,n);
   //cout<<findduphashing(a,n);
   cout<<finddupllcycle(a,n);
}
