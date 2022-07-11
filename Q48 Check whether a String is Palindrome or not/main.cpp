#include <iostream>

using namespace std;
// using a single loop and 2 pointers(i and j) in O(n) time and O(1) space
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
