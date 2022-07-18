#include <bits/stdc++.h>

using namespace std;
//function to find all substrings of a given string
void allsubstr(string s)
{
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        //string s1="";
        //s1+=s[i];
        for(int j=i+1;j<n;j++)
        {
            //s1+=s[j];
            //cout<<s1<<endl;
            cout<<s.substr(i,(j-i)+1)<<endl;
        }
    }
}

//function to know if a string is palindrome or not in O(n) time
bool ispalindrome(string s)
{
    int n=s.length();
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

//method 1- using brute force approach i.e. finding all the substrings and then finding the largest palindromic substring in O(n^3) time and O(n) space
void longpalinsubstrbrute(string s)
{
    //size of the given string
    int n=s.length();
    string longpalin="";
    int maxlen=INT_MIN;
    for(int i=0;i<n;i++)
    {
        string newsubstr="";
        newsubstr+=s[i];
        for(int j=i+1;j<n;j++)
        {
            newsubstr+=s[j];
            int len=newsubstr.length();
            if(ispalindrome(newsubstr))
            {
                if(len>maxlen)
                {
                    maxlen=len;
                    longpalin="";
                    longpalin+=newsubstr;
                }
            }
        }
    }
    cout<<"longest palindromic string is- "<<longpalin<<" which has length- "<<maxlen<<endl;
}

//method 2- brute force approach without using space and using substrings in O(n^3) time and O(1) space
void longpalinsubstrbrutewospace(string s)
{
    //size of the given string
    int n=s.length();
    string longpalin="";
    int maxlen=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ispalindrome(s.substr(i,(j-i)+1)))
            {
                int len=(j-i)+1;
                if(len>maxlen)
                {
                    maxlen=len;
                    longpalin="";
                    longpalin+=s.substr(i,(j-i)+1);
                }
            }
        }
    }
    cout<<"longest palindromic string is- "<<longpalin<<" which has length- "<<maxlen<<endl;
}

//method 3- expand from center approach in O(n^2) time and O(1) space
void longpalinsubstrexpandcentre(string s)
{
    int n=s.length();
    int lo;
    int hi;
    int start=0;
    int end=1;
    for(int i=1;i<n;i++)
    {
        //for even substring
        lo=i-1;
        hi=i;
        while(lo>=0 && hi<n && s[lo]==s[hi])
        {
            if(hi-lo+1>end)
            {
                start=lo;
                end=hi-lo+1;
            }
            lo--;
            hi++;
        }
        //for odd substring
        lo=i-1;
        hi=i+1;
        while(lo>=0 && hi<n && s[lo]==s[hi])
        {
            if(hi-lo+1>end)
            {
                start=lo;
                end=hi-lo+1;
            }
            lo--;
            hi++;
        }
    }
    string ans="";
    for(int i=start;i<=start+end-1;i++)
    {
        ans+=s[i];
    }
    cout<<"the longest palindromic substring is- "<<ans<<" of length- "<<ans.length();
}

int main()
{
    string str= "aaaabbaa";
    //allsubstr(str);
    //longpalinsubstrbrute(str);
    //longpalinsubstrbrutewospace(str);
    longpalinsubstrexpandcentre(str);
}
