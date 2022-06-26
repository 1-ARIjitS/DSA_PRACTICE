#include <bits/stdc++.h>

using namespace std;
//method 1- using space and 2 pointers in O((n1+n2)lgn) time and O(n1+n2) space
int medianspace2pointer(int a1[], int a2[], int n1, int n2)
{
    int median=0;
    int i=0;//pointer for 1st array
    int j=0;//pointer for 2nd array
    vector<int>v;
    cout<<"the sorted array obtained is: [ ";
    while(i<n1 && j<n2)
    {
        if(a1[i]<=a2[j])
        {
            cout<<a1[i]<<" ";
            v.push_back(a1[i]);
            i++;
        }
        else if(a1[i]>a2[j])
        {
            cout<<a2[j]<<" ";
            v.push_back(a2[j]);
            j++;
        }
    }
    while(i<n1)
    {
        cout<<a1[i]<<" ";
        v.push_back(a1[i]);
        i++;
    }
    while(j<n2)
    {
        cout<<a2[j]<<" ";
        v.push_back(a2[j]);
        j++;
    }
    cout<<"]"<<endl;
    if((n1+n2)%2==0)//even no. of elements answer is average of middle elements
    {
        return (v[(n1+n2)/2]+v[(n1+n2)/2-1])/2;
    }
    else
    {
        return v[(n1+n2)/2];
    }
}

/*//method 2- without using space
int median(int a1[], int a2[], int n1, int n2)
{
    int median=0;
    int i=0;
    int j=0;
    int k=n1-1;
    while(i<=k && j<n2)
    {
        if(a1[i]<=a2[j])
        {
           i++;
        }
        else if(a1[i]>a2[j])
        {
            swap(a2[j],a1[k]);
            j++;
            k--;
        }
    }
    sort(a1,a1+n1);
    sort(a2,a2+n2);
    if((n1+n2)%2==0)
    {
        int a;
        int b;
        if((n1+n2)/2<n1)
        {
            a=a1[(n1+n2)/2];
        }
        else if((n1+n2)/2<n2)
        {

        }
    }
}*/

int main()
{
    //int a1[]={-5, 3, 6, 12, 15};
    //int a2[]={-12, -10, -6, -3, 4, 10};
    int a1[]={2, 3, 5, 8};
    int a2[]={10, 12, 14, 16, 18, 20};
    int n1= sizeof(a1)/sizeof(a1[0]);
    int n2= sizeof(a2)/sizeof(a2[0]);
    cout<<medianspace2pointer(a1,a2,n1,n2);
}
