#include <bits/stdc++.h>

using namespace std;
//method 1- using sort in both arrays in O(n*lgn) time and O(1) space
int issubsetsort(int a1[], int a2[], int n1, int n2)
{
    sort(a1,a1+n1);
    sort(a2,a2+n2);
    //keeps track of first array
    int i=0;
    //keeps track of second array
    int j=0;
    //keeps count of common elements between both arrays
    int countsub=0;
    while(i<n1 && j<n2)
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
            countsub++;
            i++;
            j++;
        }
    }
    if(countsub==n2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

//method 2- using hash maps in O(n) time and O(n) space
int issubsetmap(int a1[], int a2[], int n1, int n2)
{
    map<int,int> m1;
    //keeps count of common elements between both arrays
    int countsub=0;
    for(int i=0;i<n1;i++)
    {
        m1[a1[i]]++;
    }
    for(int j=0;j<n2;j++)
    {
        if(m1[a2[j]]>=1)//a[j] found
        {
            countsub++;
        }
    }
    if(countsub==n2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int a1[] = {11, 1, 13, 21, 3, 7};
    int a2[] = {11, 3, 7, 1};
    int n1=sizeof(a1)/sizeof(a1[0]);
    int n2=sizeof(a2)/sizeof(a2[0]);
    //cout<<issubsetsort(a1,a2,n1,n2);
    cout<<issubsetmap(a1,a2,n1,n2);
}
