#include <bits/stdc++.h>

using namespace std;
//method 1-using brute force in O(n^2) time and O(1) space
void findelebrute(int a[], int n, int k)
{
    set<int> s;
    int threshold=n/k;
    for(int i=0;i<n;i++)
    {
        int counter=0;
        for(int j=i;j<n;j++)
        {
            if(a[i]==a[j])
            {
                counter++;
            }
        }
        if(counter>threshold)
        {
            s.insert(a[i]);
        }
    }
    for(auto it:s)
    {
        cout<<it<<" ";
    }
}

//method 2-using sorting in O(n*lgn) time and O(1) space
void findelesort(int a[], int n, int k)
{
    unordered_set<int> s;
    sort(a,a+n);
    int threshold=n/k;
    int counter=1;
    for(int i=0;i<n;i++)
    {
        if(a[i+1]==a[i])
        {
            counter++;
            if(counter>threshold)
            {
                s.insert(a[i]);
            }
        }
        else
        {
            counter=1;
        }
    }
    for(auto it:s)
    {
        cout<<it<<" ";
    }
}

//method 3- using hash maps in O(n) time and O(n) space
void findelemap(int a[], int n, int k)
{
    vector<int> v;
    unordered_map<int,int>m;
    int threshold=n/k;
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }
    for(int i=0;i<m.size();i++)
    {
        if(m[i]>threshold)
        {
            v.push_back(i);
        }
    }
    for(auto it:v)
    {
        cout<<it<<" ";
    }
}

int main()
{
    int a[]={ 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
    //int a[]={3, 1, 2, 2, 1, 2, 3, 3};
    int n= sizeof(a)/sizeof(a[0]);
    int k=4;
    //findelebrute(a,n,k);
    findelesort(a,n,k);
    //findelemap(a,n,k);
}
