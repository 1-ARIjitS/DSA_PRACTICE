#include <bits/stdc++.h>

using namespace std;
//method 1- brute force O(n^2) time and O(1) space
int pairsumcountbrute(int a[], int n, int k)
{
    int pairsumcount=0;
    for (int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==k)
                pairsumcount++;
        }
    }
    return pairsumcount;
}

//method 2- using sorting in O(n*lgn) time and O(1) space
int pairsumcountsort(int a[], int n, int k)
{
    sort(a,a+n);
    int pairsumcount=0;
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        int sum=a[j]+a[i];
        if(sum>k)
        {
            j--;
        }
        else if(sum<k)
        {
            i++;
        }
        else
        {
            pairsumcount++;
            i++;
        }
    }
    return pairsumcount;
}

//method 3- using hash array in O(n) time and O(n) space
int pairsumcounthash(int a[], int n, int k)
{
    int hash_n=*max_element(a,a+n)+1;
    int hasharray[hash_n]={0};
    int pairsumcount=0;
    for(int i=0;i<n;i++)
    {
        hasharray[a[i]]++;
    }
    int visited[hash_n]={0};
    for(int i=0;i<hash_n;i++)
    {
        if(i<k && visited[i]!=1)
        {
            int remainingsum=k-i;
            pairsumcount+=max(hasharray[i],hasharray[k-i]);
            visited[i]=1;
            visited[k-i]=1;
        }
    }
    return pairsumcount;
}
int main()
{
   int a[]={1, 5, 7, 1};
   int n= sizeof(a)/sizeof(a[0]);
   int k=6;
   //cout<<pairsumcountbrute(a,n,k);
   //cout<<pairsumcountsort(a,n,k);
   cout<<pairsumcounthash(a,n,k);
}
