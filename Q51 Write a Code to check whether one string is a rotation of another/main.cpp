#include <bits/stdc++.h>

using namespace std;
//method 1- using string concatenation in O(n1+n2) time and O(n1+n2) space
void isrotconcat(string s1, string s2)
{
    int n1=s1.length();
    int n2=s2.length();
    if(n1!=n2)
    {
        cout<<"NO";
    }
    else
    {
        string temp= s1+s1;
        if(temp.find(s2)!=string::npos)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
    }
}

//method 2- using queues in O(n2) time and O(n1+n2) space
void isrotqueue(string s1, string s2)
{
    int n1=s1.size();
    int n2=s2.size();
    int flag=0;
    if(n1!=n2)
    {
        cout<<"No";
    }
    else
    {
        queue<char>q1;
        queue<char>q2;
        for(int i=0;i<n1;i++)
        {
            q1.push(s1[i]);
        }
        for(int i=0;i<n2;i++)
        {
            q2.push(s2[i]);
        }
        int k=n2;
        while(k!=0)
        {
            char ch=q2.front();
            q2.pop();
            q2.push(ch);
            if(q2==q1)
            {
                flag=1;
                break;
            }
            k--;
        }
        if(flag==0)
        {
            cout<<"No";
        }
        else
        {
            cout<<"Yes";
        }
    }
}

int main()
{
    string s1 = "AACD";
    string s2 = "ACDA";
    //string s2 = "AACDB";
    //string s2 = "AADC";
    //isrotconcat(s1,s2);
    isrotqueue(s1,s2);
}
