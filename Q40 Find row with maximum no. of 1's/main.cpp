#include <bits/stdc++.h>

using namespace std;
//method 1- using brute force i.e. counting 1's in each 2d array row in O(n*m) time and O(1) space
int max1sbrute(vector<vector<int>>a)
{
    int rows=a.size();
    int columns=a[0].size();
    int max1count=-1;
    int idx=0;
    for(int i=0;i<rows;i++)
    {
        int count1=0;
        for(int j=0;j<columns;j++)
        {
            if(a[i][j]==1)
                count1++;
        }
        if(count1>max1count)
        {
            max1count=count1;
            idx=i;
        }
    }
    return idx;
}

//method 2-using binary search to find the number of zeroe in each row in O(n*lgm) time and O(1) space
int max1sbrutebinsearch(vector<vector<int>>a)
{
    int rows=a.size();
    int columns=a[0].size();
    int max1count=-1;
    int idx=0;
    for(int i=0;i<rows;i++)
    {
        int lo=0;
        int hi=columns-1;
        int count0s=0;//count of the number of 0s in a particular row
        int count1s=0;//count of the number of 1s in a particular row
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(a[i][mid]<=0)
            {
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        count0s+=lo;
        count1s+=(columns-count0s);
        if(count1s>max1count)
        {
            max1count=count1s;
            idx=i;
        }
    }
    return idx;
}

int main()
{
    vector<vector<int>>a={{0, 1, 1, 1},
    {0, 0, 1, 1},
    {1, 1, 1, 1},
    {0, 0, 0, 0}};
    //cout<<max1sbrute(a);
    cout<<max1sbrutebinsearch(a);
}
