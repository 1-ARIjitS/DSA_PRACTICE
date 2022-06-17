#include <bits/stdc++.h>

using namespace std;
void selectionsort(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        int jmin=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[jmin])
            {
                jmin=j;
            }
        }
        if(jmin!=i)
        {
            swap(a[i],a[jmin]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
//method 1- brute force in O(n^3) time and O(1) space
int tripletsumbrute(int a[], int n, int x)
{
    int tripletsum=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                tripletsum=a[i]+a[j]+a[k];
                if(tripletsum==x)
                {
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag=1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//method 2- using sorting in O(n^2+n*Lgn) time and O(1) space
int tripletsumsort(int a[], int n, int x)
{
    sort(a,a+n);
    int flag=0;
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            int remtripletsum=x-a[i];
            int twosum=a[j]+a[k];
            if(twosum<remtripletsum)
            {
                j++;
            }
            else if(twosum>remtripletsum)
            {
                k--;
            }
            else if(twosum==remtripletsum)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//method 3- using hash maps in O(n^2) time and O(n) space
int tripletsummap(int a[], int n, int x)
{
    unordered_map<int,int>m;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
       for(int j=i+1;j<n;j++)
       {
           int sum=a[i]+a[j];
           if(sum<x)
           {
               int rem=x-sum;
               if(m[rem]==1)
               {
                   flag=1;
                   break;
               }
           }
       }
    }
    if(flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    //int a[]={1,4,45,6,10,8};
    int a[]={1,2,4,3,6};
    int n=sizeof(a)/sizeof(a[0]);
    //int x= 13;
    int x=10;
    //cout<<tripletsumbrute(a,n,x);
    //cout<<tripletsummap(a,n,x);
    cout<<tripletsumsort(a,n,x);
}
