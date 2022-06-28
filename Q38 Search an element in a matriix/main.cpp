#include <bits/stdc++.h>

using namespace std;
//method 1-using brute force in O(n*m) time and O(1) space
void searchbrute(int a[][4], int rows, int columns, int key)
{
    int flag=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(a[i][j]==key)
            {
                flag=1;
            }
        }
    }
    if(flag==1)
    {
        cout<<"TRUE";
    }
    else
    {
        cout<<"FALSE";
    }
}

//method 2-using each row sorted property and applying binary search in each row in O(n*lgm) time and O(1) space
void searchbineachrow(int a[][4], int rows, int columns, int key)
{
    int flag=0;
    for(int i=0;i<rows;i++)
    {
        int left=0;
        int right=columns-1;
        while(left<=right)
        {
            int mid=(left+right-1)/2;
            if(key<a[i][mid])
            {
                right=mid-1;
            }
            else if(key>a[i][mid])
            {
                left=mid+1;
            }
            else if(key==a[i][mid])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    if(flag==1)
    {
        cout<<"TRUE";
    }
    else
    {
        cout<<"FALSE";
    }
}

//method 3-using space and binary search in O(lg(n+m)) time and O(n+m) space
void searchbinspace(int a[][4], int rows, int columns, int key)
{
    vector<int>v;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            v.push_back(a[i][j]);
        }
    }
    int left=0;
    int right=v.size()-1;
    int flag=0;
    int mid=0;
    while(left<=right)
    {
        mid=(left+right-1)/2;
        if(key>v[mid])
        {
            left=mid+1;
        }
        else if(key<v[mid])
        {
            right=mid;
        }
        else if(key==v[mid])
        {
           flag=1;
           break;
        }
    }
    if(flag==1)
    {
         cout<<"TRUE";
    }
    else
    {
        cout<<"FALSE";
    }
}

//method 2-without using extra space in O(lgn) time and O(1) space
bool searchbinwospace(int a[][4], int rows, int columns, int key)
{
    int left=0;
    int right=(rows*columns)-1;
    while(left<=right)
    {
        int mid=(left+(right-left)/2);
        int midrow=mid/columns;
        int midcolumn=mid%columns;
        if(key==a[midrow][midcolumn])
        {
            return true;
        }
        else if(key<a[midrow][midcolumn])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return false;
}

int main()
{
   int a[][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
   int key = 3;
   int rows=3;
   int columns=4;
   //searchbrute(a,rows,columns,key);
   //searchbineachrow(a,rows,columns,key);
   //searchbinspace(a,rows,columns,key);
   cout<<searchbinwospace(a,rows,columns,key);
}
