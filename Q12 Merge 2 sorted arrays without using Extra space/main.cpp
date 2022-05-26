#include <bits/stdc++.h>

using namespace std;

//method 1- using insertion sort merge operation in O(n*m)+O(n*lgn) time and  O(1) space
void mergeinsertion(int a1[], int a2[], int m, int n)
{
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(a1[i]<a2[j])
        {
            i++;
        }
        else if(a1[i]>a2[j])
        {
            swap(a1[i],a2[j]);
            //sort(a2,a2+n);
            for(int p=1; p<n; p++)
            {
                int q=p-1;
                int key=a2[p];
                while(q>=0 && a2[q]>key)
                {
                   a2[q+1]=a2[q];
                   q--;
                }
                a2[q+1]=key;
            }
            //i++;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<a1[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<a2[j]<<" ";
    }
}

//method 2- using gap method
void mergegap(int a1[], int a2[], int m, int n)
{
    int init_gap;
    if((m+n)%2==0)
        init_gap=(m+n)/2;
    else
        init_gap=((m+n)/2)+1;
    while(init_gap!=1)
    {
        int i=0;
        int j=init_gap;
        while(j<m+n)
        {
            if(i<m && j<m)
            {
                if(a1[i]>a1[j])
                    swap(a1[i],a1[j]);
            }
            else if(i<m && j>=m)
            {
               if(a1[i]>a2[j-m])
                swap(a1[i],a2[j-m]);
            }
            else if(i>=m && j>=m)
            {
                if(a2[i-m]>a2[j-m])
                    swap(a2[i-m],a2[j-m]);
            }
            i++;
            j++;
        }
        if(init_gap%2==0)
            init_gap=init_gap/2;
        else
            init_gap=(init_gap/2)+1;
    }
    for(int i=0;i<m;i++)
        cout<<a1[i]<<" ";
    cout<<endl;
    for(int j=0;j<n;j++)
        cout<<a2[j]<<" ";
}

int main()
{
    int a1[]={1,3,5,7};
    int a2[]={0,2,6,8,9};
    int m= sizeof(a1)/sizeof(a1[0]);
    int n= sizeof(a2)/sizeof(a2[0]);
    //mergeinsertion(a1,a2,m,n);
    mergegap(a1,a2,m,n);
}
