#include <iostream>

using namespace std;

int ispalindrome(string s)
{
    int i=0;
    int j=s.size()-1;
    int flag=1;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            flag=0;
            break;
        }
        i++;
        j--;
    }
    return flag;
}

int main()
{
    string s="aaabbaaabbaaa";
    //string s="aaaaaaaaaaaabbbbbbbbbbb";
    cout<<ispalindrome(s);
}
