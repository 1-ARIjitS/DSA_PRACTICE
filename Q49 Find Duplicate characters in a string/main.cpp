#include <bits/stdc++.h>

using namespace std;
//method 1- using maps or unordered maps in O(n) time and O(n) space
void dupchstrmap(string s)
{
    //unordered_map<char,int>m;
    map<char,int>m;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        m[s[i]]++;
    }
    cout<<"duplicate characters in the given string are- "<<endl;
    for(auto it:m)
    {
        if(it.second>1)
        {
            cout<<it.first<<" "<<"has frequency= "<<it.second<<endl;
        }
    }
}

int main()
{
    string s="abacdefgahijjkklllllmmonbcdejghfrg";
    dupchstrmap(s);
}
