#include <iostream>

using namespace std;
//method 1- using brute force approach i.e. using 2 pointers (i and j) in O(n) time and O(1) space
void revstrbrute(string s)
{
    int n=s.size();
    int i=0;
    int j=n-1;
    while(i<j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
    cout<<s;
}

int main()
{
    string s="HELLO, WHO IS THERE ?";
    revstrbrute(s);
}
