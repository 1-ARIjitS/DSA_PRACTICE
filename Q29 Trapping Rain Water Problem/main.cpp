#include <bits/stdc++.h>

using namespace std;
//method 1- using brute force leftmax and rightmax in O(n^2) time and O(n^2) space
int trapwaterbrute(int a[], int n)
{
    int trapwatersum=0;
    for(int i=0;i<n;i++)
    {
        //calculating leftmax
        int leftmax=a[i];
        int j=i-1;
        while(j>=0)
        {
            if(a[j]>leftmax)
            {
                leftmax=a[j];
            }
            j--;
        }
        //calculating rightmax
        int rightmax=a[i];
        int k=i+1;
        while(k<n)
        {
            if(a[k]>rightmax)
            {
                rightmax=a[k];
            }
            k++;
        }
        trapwatersum+=(min(leftmax,rightmax)-a[i]);
    }
    return trapwatersum;
}

//methos 2- using leftmax and rightmax auxillary arrays in O(n) time and O(n) space
int trapwateraux(int a[], int n)
{
    int trapwatersum=0;
    int lefttmaxaux[n];
    int rightmaxaux[n];
    //leftmax auxillary array
    lefttmaxaux[0]=a[0];
    for(int i=1;i<n;i++)
    {
        lefttmaxaux[i]=max(lefttmaxaux[i-1],a[i]);
    }
    //rightmax auxillary array
    rightmaxaux[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rightmaxaux[i]=max(rightmaxaux[i+1],a[i]);
    }
    for(int i=0;i<n;i++)
    {
        trapwatersum+=(min(lefttmaxaux[i],rightmaxaux[i])-a[i]);
    }
    return trapwatersum;
}

//metgod 3- using 2 pointer approach in O(n) time and O(n) space
int trapwater2pointer(int a[], int n)
{
    int lo=0;
    int hi=n-1;
    int leftmax=0;
    int rightmax=0;
    int trapwatersum=0;
    while(lo<hi)
    {
        if(a[lo]<a[hi])
        {
            if(a[lo]>leftmax)
            {
                leftmax=a[lo];
            }
            else
            {
                trapwatersum+=(leftmax-a[lo]);
            }
            lo++;
        }
        else
        {
            if(a[hi]>rightmax)
            {
                rightmax=a[hi];
            }
            else
            {
                trapwatersum+=(rightmax-a[hi]);
            }
            hi--;
        }
    }
    return trapwatersum;
}

int main()
{
  int a[]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  //int a[]={2,0,2};
  //int a[]={3,0,2,0,4};
  int n= sizeof(a)/sizeof(a[0]);
  //cout<<trapwaterbrute(a,n);
  //cout<<trapwateraux(a,n);
  cout<<trapwater2pointer(a,n);
}
