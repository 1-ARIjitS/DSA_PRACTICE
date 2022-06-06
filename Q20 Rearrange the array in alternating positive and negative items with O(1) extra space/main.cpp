#include <bits/stdc++.h>

using namespace std;

//method 1- using extra space
void rearrangespace(int a[], int n)
{
    int i=0;
    int j=n-1;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    while(i<=j)
    {
        if(a[i]<0)
        {
            v1.push_back(a[i]);
            i++;
        }
        else if(a[j]>0)
        {
            v2.push_back(a[j]);
            j--;
        }
        else
        {
           swap(a[i],a[j]);
        }
    }
    /*for(auto it:v1)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:v2)
    {
        cout<<it<<" ";
    }
    cout<<endl;*/
    i=0;
    j=0;
    while(i<v1.size()&&j<v2.size())
    {
        v3.push_back(v1[i]);
        v3.push_back(v2[j]);
        i++;
        j++;
    }
    while(i<v1.size())
    {
        v3.push_back(v1[i]);
        i++;
    }
    while(j<v2.size())
    {
        v3.push_back(v2[j]);
        j++;
    }
    for(auto it:v3)
    {
        cout<<it<<" ";
    }
}
int main()
{
    int a[]={1, 2, 3, -4, -1, 4};
    int n= sizeof(a)/sizeof(a[0]);
    rearrangespace(a,n);
}
