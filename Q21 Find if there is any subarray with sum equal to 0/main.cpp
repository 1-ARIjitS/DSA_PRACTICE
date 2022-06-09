#include <bits/stdc++.h>

using namespace std;

//method 1- brute force approach O(n^2) time and O(1) space
void subarrayaum0brute(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            if(sum==0)
            {
                cout<<"yes";
                break;
            }
        }
    }

}

//method 2- using unordered map O(n) time and O(n) space
void subarrayaum0map(int a[], int n)
{
    int sum=0;
    int flag=0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==0||a[i]==0||m[sum])
        {
            flag=1;
            break;
        }
        else
            m[sum]=1;
    }
    if(flag==1)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}

int main()
{
    int a[]={4,2,-3,1,6};
    int n= sizeof(a)/sizeof(a[0]);
    //subarrayaum0brute(a,n);
    subarrayaum0map(a,n);
}
