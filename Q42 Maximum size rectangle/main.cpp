#include <bits/stdc++.h>

using namespace std;
//using stacks in O() time and O()
int eachrowrectarea(int auxrect[], int n)
{
    int res=0;//result to be returned stores the area of max rect in each row
    int i=1;//iterator
    int h=0;//height
    int p=0;//position
    stack<int> startpos;
    stack<int> height;
    startpos.push(0);
    for(int i=0;i<n;i++)
    {
        if(height.empty()||auxrect[i]>height.top())
        {
            startpos.push(i);
            height.push(auxrect[i]);
        }
        else if(auxrect[i]<height.top())
        {
            while(height.empty()&&auxrect[i]<height.top())
            {
                h=height.top();
                height.pop();
                p=startpos.top();
                startpos.pop();
                res=max(res,h*(i-p));
            }
            startpos.push(p);
            height.push(auxrect[i]);
        }
    }
    while(!height.empty())
    {
       h=height.top();
       height.pop();
       p=startpos.top();
       startpos.pop();
       res=max(res,h*(i-p));
    }
    return res;
}

int maxarearectbrute(vector<vector<int>>a)
{
    int rows=a.size();
    int columns=a[0].size();
    int auxrect[columns]={0};
    int maxarea=0;
    for(int i=0;i<rows;i++)
    {
        int arearect=0;
        for(int j=0;j<columns;j++)
        {
            if(a[i][j]==1)
            {
                auxrect[j]+=a[i][j];
            }
            else if(a[i][j]==0)
            {
                auxrect[j]=0;
            }
        }
        arearect+=eachrowrectarea(auxrect,columns);
        maxarea=max(maxarea,arearect);
    }
    return maxarea;
}

int main()
{
    vector<vector<int>>a={{0,1,1,0},
         {1,1,1,1},
         {1,1,1,1},
         {1,1,0,0}};
    cout<<maxarearectbrute(a);
}
