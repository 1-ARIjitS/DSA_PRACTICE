#include <bits/stdc++.h>

using namespace std;
//method 1- using merge sort in O(n*lgn) time and O(n) space
void mergefunc(int a[], int temp[], int left, int mid, int right)
{
    int i=left;
    int j=mid+1;
    int k=left;
    while(i<=mid && j<=right)
    {
      if(a[i]<=a[j])
      {
          temp[k++]=a[i++];
      }
      else if(a[i]>a[j])
      {
          temp[k++]=a[j++];
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
    for(int l=left;l<=right;l++)
    {
        a[l]=temp[l];
    }
}

void mergesort(int a[], int temp[], int left, int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergesort(a,temp,left,mid);
        mergesort(a,temp,mid+1,right);
        mergefunc(a,temp,left,mid,right);
    }
}

int longestsubsequencesort(int a[], int temp[], int n, int left, int right)
{
    mergesort(a,temp,left,right);
    //sort(a,a+n);
    int countsubseq=1;
    int longestsubseq=0;
    for(int i=0;i<n;i++)
    {
        if(a[i+1]-a[i]==1)
        {
            countsubseq++;
        }
        else if(a[i+1]-a[i]==0)
        {
            continue;
        }
        else
        {
            countsubseq=1;
        }
        longestsubseq=max(longestsubseq,countsubseq);
    }
    return longestsubseq;
}

//method 2- using same sort but removing duplicates using set in O(n*lgn) time and O(1) space
int longestsubsequencesetsort(int a[], int n)
{
    set<int>s;
    int countsubseq=1;
    int longestsubseq=0;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    vector<int>v;
    for(auto it:s)
    {
        v.push_back(it);
    }
    for(int i=0;i<n;i++)
    {
        if(v[i+1]-v[i]==1)
        {
            countsubseq++;
        }
        else
        {
            countsubseq=1;
        }
        longestsubseq=max(longestsubseq,countsubseq);
    }
    return longestsubseq;
}

//method 3- using set in O(n) time and O(1) space
int longestsubsequenceset(int a[], int n)
{
    set<int>s;
    int longestsubseq=0;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(s.find(a[i]-1)==s.end())//this is the smallest element of the subsequence
        {
            int next=a[i]+1;
            while(s.find(next)!=s.end())
            {
                next++;
            }
            longestsubseq=max(longestsubseq,next-a[i]);
        }
    }
    return longestsubseq;
}

int main()
{
   int a[]={1,9,3,10,4,20,2,10,10,10,11,11,11,11,11,12,13,14,15,15,16,17,18,19};
   //int a[]={2,6,1,9,4,5,3};
   //int a[]={1,9,3,10,4,20,2};
   int n= sizeof(a)/sizeof(a[0]);
   int left=0;
   int right=n-1;
   int temp[n];
   //cout<<longestsubsequencesort(a,temp,n,left,right);
   //cout<<longestsubsequencesetsort(a,n);
   cout<<longestsubsequenceset(a,n);
}
