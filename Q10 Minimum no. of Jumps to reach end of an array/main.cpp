#include <iostream>

using namespace std;
//method 1- recursive approach
int minjumpsrecursive(int a[], int n)
{
   int minjumps=INT_MAX;
   if(n==1)
   {
       return 0;
   }
   for(int i=n-2;i>=0;i--)
   {
       if(i+a[i]>=n-1)
       {
          int sub_minjumps=minjumpsrecursive(a,i+1);
          if(sub_minjumps<minjumps)
          {
              minjumps=sub_minjumps+1;
          }
       }
   }
   return minjumps;
}

//method 2- in O(n) time and O(1) space most optimized approach
int minjumpsoptimized(int a[], int n)
{
    int minjumps=0;
    int halt=0;
    int maximum=0;
    if(a[0]=0)
    {
        return -1;
    }
    for(int i=0;i<n-1;i++)
    {
        maximum=max(maximum,a[i]+i);
        if(maximum>=n-1)
        {
            minjumps++;
            return minjumps;
        }
        if(i==halt)
        {
            halt=maximum;
            minjumps++;
        }

    }
    if(halt>=n-1)
        return minjumps;
    return -1;
}

int main()
{
    int a[]={1, 3, 6, 3, 2, 3, 6, 8, 9, 5 };
    int n= sizeof(a)/sizeof(a[0]);
    cout<<minjumpsoptimized(a,n);
}
