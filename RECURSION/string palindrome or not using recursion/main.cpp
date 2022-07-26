#include <bits/stdc++.h>

using namespace std;
//Q2- Checking if palindrome or not using recursion
//using the code for reversing the string
bool ispalinrec(string s, int n)
{
    static string rev="";
    if(n==0)
    {
        return false;
    }
    else
    {
        rev+=s[n-1];
        ispalinrec(s,n-1);
        if(rev==s)
        {
            return true;
        }
    }
}

bool ispalincheck(string s, int i, int j)
{
    if(i>j)
    {
        return true;
    }
    if(s[i]!=s[j])
    {
        return false;
    }
    else
    {
        ispalincheck(s,i+1,j-1);
    }
}

int main()
{
    string str="abbcbba";
    //string str="abba";
    //string str="abs";
    //string str="a";
    int n=str.length();

    if(ispalinrec(str,n))
    {
        cout<<"given string is a palindrome"<<endl;
    }
    else
    {
        cout<<"given string is not a palindrome"<<endl;
    }

    int i=0;
    int j=n-1;
    if(ispalincheck(str,i,j))
    {
        cout<<"given string is a palindrome";
    }
    else
    {
        cout<<"given string is not a palindrome";
    }
}
