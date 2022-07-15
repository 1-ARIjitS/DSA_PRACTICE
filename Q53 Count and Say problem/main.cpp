#include <bits/stdc++.h>

using namespace std;
//method 1- using recursion in O(n^2) time and O(n) stack space due to recursion
string countnsay(int n)
{
    if(n==1)
    {
        return "1";
    }
    else
    {
        string say="";
        string str;
        str=countnsay(n-1);
        int n=str.length();
        int counter=0;
        for(int i=0;i<n;i++)
        {
            counter++;
            //do concatenate to the string if we are at end of string or adjacent characters are different in the string
            if(i==n-1 || str[i]!=str[i+1])
            {
                say=say+to_string(counter)+str[i];
                counter=0;
            }
        }
        return say;
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<countnsay(n);
}
