#include <bits/stdc++.h>

using namespace std;
//method 1- using brute force approach and extra space in O(n*m) time and O(n*m) space
void matrot90brute(vector<vector<int>>a)
{
    int rows=a.size();
    int columns=a[0].size();
    vector<vector<int>>rotmat(rows,vector<int>(columns));
    for(int i=rows-1;i>=0;i--)
    {
        for(int j=0;j<columns;j++)
        {
            rotmat[j][(rows-1)-i]=a[i][j];
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout<<rotmat[i][j]<<" ";
        }
        cout<<endl;
    }
}

//method 2- using transpose of the matrix and reversing each row in O(n*m) time and O(1) space
void matrot90transpose(vector<vector<int>>a)
{
    int rows=a.size();
    int columns=a[0].size();
    //converting the original matrix into a transpose matrix
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(i<j)
            {
                swap(a[i][j],a[j][i]);
            }
        }
    }
    //converting the transpose matrix to matrix having rotation 90 degrees by reversing all the rows
    for(int i=0;i<rows;i++)
    {
        int left=0;
        int right=columns-1;
        while(left<right)
        {
            swap(a[i][left],a[i][right]);
            left++;
            right--;
        }
    }
    //printing the rotated matrix
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>>a={ { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    //matrot90brute(a);
    matrot90transpose(a);
}
