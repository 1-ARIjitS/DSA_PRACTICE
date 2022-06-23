#include <bits/stdc++.h>

using namespace std;

int ispalindrome(int a[], int n)
{
    int flag=1;
    for(int i=0;i<n;i++)
    {
        int ele=a[i];
        int num=0;
        int rem=0;
        while(ele>0)
        {
            rem=ele%10;
            num=num*10+rem;
            ele=ele/10;
        }
        if(num!=a[i])
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int a[]={111,222,333,444,555,666,777,888,999};
    int n= sizeof(a)/sizeof(a[0]);
    cout<<ispalindrome(a,n);
}

