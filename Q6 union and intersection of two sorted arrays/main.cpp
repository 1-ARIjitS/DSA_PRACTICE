#include <bits/stdc++.h>

using namespace std;
//method 1- without considering duplicates
void unionsimple(int a1[],int a2[], int m, int n)
{
    int i=0;
    int j=0;
    while(i<m && j<n)
    {
        if(a1[i]<a2[j])
        {
            cout<<a1[i++]<<" ";
        }
        else if(a1[i]>a2[j])
        {
            cout<<a2[j++]<<" ";
        }
        else if(a1[i]==a2[j])
        {
            cout<<a1[i++]<<" ";
            j++;
        }
    }
        while(i<m)
        {
            cout<<a1[i++]<<" ";
        }

        while(j<n)
        {
            cout<<a2[j++]<<" ";
        }
}
//method 2- with considering duplicates
void uniondup(int a1[], int a2[], int m, int n)
{
    int i=0;
    int j=0;
    vector<int>v;
    while(i<m && j<n)
    {
        while(a1[i+1]==a1[i])
        {
            i++;
        }
        while(a2[j+1]==a2[j])
        {
            j++;
        }
        if(a1[i]>a2[j])
        {
            v.push_back(a2[j++]);
            //cout<<a2[j++]<<" ";
        }
        else if(a1[i]<a2[j])
        {
            v.push_back(a1[i++]);
            //cout<<a1[i++]<<" ";
        }
        else if(a1[i]==a2[j])
        {
            v.push_back(a1[i++]);
            //cout<<a1[i++]<<" ";
            j++;
        }

    }

        while(i<m)
        {
            v.push_back(a1[i++]);
            //cout<<a1[i++]<<" ";
        }

        while(j<n)
        {
            v.push_back(a2[j++]);
            //cout<<a2[j++]<<" ";
        }

        for(auto it=v.begin();it!=v.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
}

//method 1- using simple while and for loops
void intersectiondup(int a1[], int a2[], int n, int m)
{
    vector<int>v;
    int i=0;
    int j=0;
    while(i<m && j<n)
    {
        while(a1[i+1]==a1[i])
        {
            i++;
        }
        while(a2[j+1]==a2[j])
        {
            j++;
        }
        if(a1[i]<a2[j])
        {
            i++;
        }
        else if(a1[i]>a2[j])
        {
            j++;
        }
        else if(a1[i]==a2[j])
        {
            v.push_back(a1[i]);
            i++;
            j++;
        }
    }
    for(auto it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

//method 2- using sets to handle duplicates
void intersectiondupset(int a1[], int a2[], int n, int m)
{
    set<int>s;
    int i=0;
    int j=0;
    while(i<m && j<n)
    {
        if(a1[i]<a2[j])
        {
            i++;
        }
        else if(a1[i]>a2[j])
        {
            j++;
        }
        else if(a1[i]==a2[j])
        {
            s.insert(a1[i]);
            i++;
            j++;
        }
    }
    for(auto it:s)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    int a1[]={1,2,2,2,4,4,4,4,4,4,8,8,8,9};
    int a2[]={1,3,3,3,4,4,5,5,5,6,6,6,7,7,7,10,10,10};
    int m= sizeof(a1)/sizeof(a1[0]);
    int n= sizeof(a2)/sizeof(a2[0]);
    //union
    uniondup(a1,a2,m,n);
    //intersection
    intersectiondup(a1,a2,m,n);
    //intersection using set stl
    intersectiondupset(a1,a2,m,n);
}
