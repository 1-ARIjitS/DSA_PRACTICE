#include <bits/stdc++.h>

using namespace std;

//method 1- using recursion and swap function
void permstrrec(string s, vector<string>&perm, int index)
{
    int n=s.length();

    //base case
    if(index>=n)
    {
        perm.push_back(s);
        return;
    }

    else
    {
        for(int j=index;j<n;j++)
        {
            //solving the first case i.e. swapping the first char with all other char of the string
            swap(s[j],s[index]);

            //recursive call for handling all other cases
            permstrrec(s,perm,index+1);

            //backtrack to restore the swapped string to original string for further swapping and inconsistencies are avoided
            swap(s[j],s[index]);
        }
    }
}

int main()
{
    string str="abcd";
    //string str="abc";
    vector<string>perm;
    int index=0;
    permstrrec(str,perm,index);
    for(auto it:perm)
    {
       cout<<it<<endl;
    }
}
