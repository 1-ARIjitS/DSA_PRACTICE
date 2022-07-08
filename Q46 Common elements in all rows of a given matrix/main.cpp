#include <bits/stdc++.h>

using namespace std;
//method 1-using brute force approach and extra space in O(n*2m) time and O(n*m) space
void commonelebrute(vector<vector<int>>a)
{
    int rows=a.size();
    int columns=a[0].size();
    vector<int>v;
    unordered_map<int,int>m;
    for(int i=0;i<rows;i++)
    {
        set<int>s;
        for(int j=0;j<columns;j++)
        {
            s.insert(a[i][j]);
        }
        for(auto it:s)
        {
            v.push_back(it);
        }
    }
    for(auto it:v)
    {
        m[it]++;
    }
    for(auto it:m)
    {
        if(it.second==rows)
        {
            cout<<it.first<<" ";
        }
    }
}

//method 2- using maps and avoiding duplicates in each row in O(n*m) time and O(1) space
void commonelemap(vector<vector<int>>a)
{
    int rows=a.size();
    int columns=a[0].size();
    unordered_map<int,int>m;
    for(int j=0;j<columns;j++)
    {
        m[a[0][j]]=1;
    }

    for(int i=1;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            //the variable i and m(x) stores the row number of the element
            //if current element is already present in the map then add 1 to the row number
            //if current element is already having elements= row no. then it is duplicated in the same row hence, do nothing
            if(m[a[i][j]]==i)
            {
               m[a[i][j]]=i+1;
            }
            //we can directly print here also without traversing the whole map again
            if(i==rows-1 && m[a[i][j]]==rows)
            {
                cout<<a[i][j]<<" ";
            }
        }
    }
    /*
    for(auto it:m)
    {
        if(it.second==rows)
        {
            cout<<it.first<<" ";
        }
    }
    */
}

int main()
{
    vector<vector<int>>a={{1, 2, 1, 4, 8},
    {3, 7, 8, 5, 1},
    {8, 7, 7, 3, 1},
    {8, 1, 2, 7, 9}};

    //commonelebrute(a);
    commonelemap(a);
}
