#include <bits/stdc++.h>

using namespace std;
//method 1- 4 pointer approach
void printspiral4pointer(int a[][4], int rows, int columns)
{
    //bound for rows
    int top=0;
    int down=rows-1;

    //bound for columns
    int left=0;
    int right=columns-1;

    //direction pointer 0-left to right; 1-top to down; 2-right to left; 3-down to top
    int dir=0;//initialized to 0 i.e. left to right

    while(top<=down && left<=right)
    {
        //left to right
        if(dir==0)
        {
          for(int i=left;i<=right;i++)
          {
              cout<<a[left][i]<<" ";
          }
          top+=1;
        }
        //top to down
        else if(dir==1)
        {
            for(int i=top;i<=down;i++)
            {
                cout<<a[i][right]<<" ";
            }
            right-=1;
        }
        //right to left
        else if(dir==2)
        {
            for(int i=right;i>=left;i--)
            {
                cout<<a[down][i]<<" ";
            }
            down-=1;
        }
        //down to top
        else if(dir==3)
        {
            for(int i=down;i>=top;i--)
            {
                cout<<a[i][left]<<" ";
            }
            left+=1;
        }
        dir=(dir+1)%4;
    }
}

int main()
{
    int a[4][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15,16}};
    int rows=4;
    int columns=4;
    printspiral4pointer(a,rows,columns);
    //or
    //vector<vector<int> > a={ { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } };
}
