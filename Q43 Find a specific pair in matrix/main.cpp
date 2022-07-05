#include <bits/stdc++.h>

using namespace std;
//method 1-using brute force in O((n*m)^2) time and O(1) space
int pairdiff(vector<vector<int>>a, int x,int r, int c)
{
    int rows=a.size();
    int columns=a[0].size();
    int maxpairdiff=INT_MIN;
    for(int i=r;i<rows;i++)
    {
        for(int j=c;j<columns;j++)
        {
            int pairdiff=a[i][j]-x;
            maxpairdiff=max(maxpairdiff,pairdiff);
        }
    }
    return maxpairdiff;
}

int specificpairbrute(vector<vector<int>>a)
{
    int rows=a.size();
    int columns=a[0].size();
    int maxdiff=INT_MIN;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            int diff=pairdiff(a,a[i][j],i+1,j+1);
            maxdiff=max(maxdiff,diff);
        }
    }
    return maxdiff;
}

//method 2- using space to build maximum array in O(m*m) time and O(n*m) space
int specificpairspace(vector<vector<int>>a)
{
    int rows=a.size();
    int columns=a[0].size();
    int maxdiff=INT_MIN;

    //creating an auxiliary max array of same number of rows and columns as the original array
    vector<vector<int>>maxarr(rows,vector<int>(columns));

    //or just create an integer array as int maxarr[rows][columns];

    //fixing the last value of the max array as equal to the original array
    maxarr[rows-1][columns-1]=a[rows-1][columns-1];

    //initializing the max variable
    int maxv=a[rows-1][columns-1];

    //preprocessing the last row
    for(int j=columns-2;j>=0;j--)
    {
        if(a[rows-1][j]>maxv)
        {
            maxv=a[rows-1][j];
        }
        maxarr[rows-1][j]=maxv;
    }

    //initializing the max variable
    maxv=a[rows-1][columns-1];

    //preprocessing the last column
    for(int i=rows-2;i>=0;i--)
    {
        if(a[i][columns-1]>maxv)
        {
            maxv=a[i][columns-1];
        }
        maxarr[i][columns-1]=maxv;
    }

    //preprocessing the rest of the array starting from the bottom
    for(int i=rows-2;i>=0;i--)
    {
        for(int j=columns-2;j>=0;j--)
        {
            if(maxarr[i+1][j+1]-a[i][j]>maxdiff)
            {
                maxdiff= maxarr[i+1][j+1]-a[i][j];
            }
            maxarr[i][j]=max(a[i][j],max(maxarr[i][j+1],maxarr[i+1][j]));
        }
    }
    return maxdiff;
}

int main()
{
   vector<vector<int>>a={{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 },
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
   //cout<<specificpairbrute(a);
   cout<<specificpairspace(a);
}
