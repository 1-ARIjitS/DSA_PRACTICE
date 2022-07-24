#include <bits/stdc++.h>

using namespace std;
//method 1- using recursion in O(2^n) time and O(n) stack space
void subseqrec(string subseqstr, string s, int index, int n)
{
    //the index has reached the last element of the string
    if(index==n)
    {
        cout<<subseqstr<<endl;
    }
    else
    {
        subseqrec(subseqstr,s,index+1,n);
        subseqstr+=s[index];
        subseqrec(subseqstr,s,index+1,n);
    }
}

int main()
{
    string str="abcd";
    //string str="a";
    //string str="aba";
    //string str="abababcdefgrtyhsdjvn";
    int n=str.length();
    string subseqstr="";
    subseqrec(subseqstr, str, 0, n);
}
