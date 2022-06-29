#include <bits/stdc++.h>

using namespace std;
#define maxarrlen 1e9
//method 1-brute force approach using space and sorting in O(n*m+(n*m)lg(n*m)) time and O(n*m) sapce
int medianbrute(int a[][3], int rows, int columns)
{
    vector<int>v;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            v.push_back(a[i][j]);
        }
    }
    sort(v.begin(),v.end());
    int matrixsize=v.size();
    if(matrixsize%2==0)//even no. of elements
    {
        return (v[matrixsize/2]+v[matrixsize/2-1])/2;
    }
    else
    {
        return v[matrixsize/2];
    }
}

//method 2-using binary search in
int countsmallerthanmid(vector<int>&row, int mid)
{
    int lo=0;
    int hi=row.size()-1;
    while(lo<=hi)
    {
        int m=(lo+hi)/2;
        if(row[m]<=mid)
        {
            lo=m+1;
        }
        else
        {
            hi=m-1;
        }
    }
    return lo;
}

int medianbinsearch(vector<vector<int>>&a)
{
   int rows=a.size();
   int columns=a[0].size();
   int n=(rows*columns);
   int lo=0;
   int hi=maxarrlen;
   while(lo<=hi)
   {
       int mid=(lo+hi)/2;//(lo+hi)/2
       //this counter stores the number of numbers less than equal to mid in all rows
       int counter=0;
       for(int i=0;i<rows;i++)
       {
           counter+=countsmallerthanmid(a[i],mid);
       }
       if(counter<=n/2)
       {
           lo=mid+1;
       }
       else
       {
           hi=mid-1;
       }
   }
   return lo;
}

int main()
{
    /*int a[][3]={{1, 3, 5},
    {2, 6, 9},
    {3, 6, 9}};
    int rows=3;
    int columns=3;*/
    //cout<<medianbrute(a,rows,columns);
    vector<vector<int>>a={{1, 3, 5},
    {2, 6, 9},
    {3, 6, 9}};
    cout<<medianbinsearch(a);
}
