#include <bits/stdc++.h>

using namespace std;
void printelesorted(vector<vector<int>>a)
{
    int rows=a.size();
    int columns=a[0].size();
    vector<int>v;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            v.push_back(a[i][j]);
        }
    }
    sort(v.begin(),v.end());
    int counter=0;
    for(auto it:v)
    {
        cout<<it<<" ";
        counter++;
        if(counter==rows)
        {
            cout<<endl;
            counter=0;
        }
    }
}

int main()
{
    vector<vector<int>>a={{10,20,30,40},{15,25,35,45},
    {27,29,37,48},
    {32,33,39,50}};
    printelesorted(a);
}
