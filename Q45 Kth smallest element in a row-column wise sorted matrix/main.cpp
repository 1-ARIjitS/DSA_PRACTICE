#include <bits/stdc++.h>

using namespace std;
//method 1- using brute force approach by using space to store and sort in O(n*m) time and O(n*m) space
int ksmallbrute(vector<vector<int>>a, int k)
{
    int rows=a.size();
    int columns=a[0].size();
    int ksmallest=0;
    vector<int>v;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            v.push_back(a[i][j]);
        }
    }
    sort(v.begin(),v.end());
    int idxofksmall=k-1;
    ksmallest=v[idxofksmall];
    return ksmallest;
}

//method 2-using binary search in O(k*logn) time and O(1) space
int countlessthanmid(vector<int>&rows, int mid)
{
    int lo=0;
    int hi=rows.size()-1;
    while(lo<=hi)
    {
        //in case of indexes formula of m= lo+(hi-lo)/2
        int m=lo+(hi-lo)/2;
        //here mid is the key we are searching for in the binary search 
        //we are actually searching how many numbers are less than mid
        if(rows[m]<=mid)
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

int ksmallbinsearch(vector<vector<int>>a, int k)
{
    int rows=a.size();
    int columns= a[0].size();
    int ksmallest=0;
    int lo=a[0][0];
    int hi=a[rows-1][columns-1];
    while(lo<=hi)
    {
        //in case of ranges the formula of mid is (lo+hi)/2
        int mid=(lo+hi)/2;

        //this keeps the count of elements less than mid
        int counter=0;
        for(int i=0;i<rows;i++)
        {
            counter+=countlessthanmid(a[i],mid);
        }
        if(counter<k)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    ksmallest=lo;
    return ksmallest;
}

int main()
{
    vector<vector<int>>a={{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }};
    int k=3;
    //cout<<ksmallbrute(a,k);
    cout<<ksmallbinsearch(a,k);
}
