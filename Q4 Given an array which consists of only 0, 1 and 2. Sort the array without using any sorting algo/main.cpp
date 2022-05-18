#include <bits/stdc++.h>

using namespace std;
//method 1- keeping count of 0,1,2
void sort012count(int a[],int n)
{
    int count0=0;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
            count0++;
        else if(a[i]==1)
            count1++;
        else if(a[i]==2)
            count2++;
    }

    //cout<<count0<<" "<<count1<<" "<<count2<<endl;
        int i=0;
        while(count0!=0)
        {
            a[i]=0;
            count0--;
            i++;
        }
        while(count1!=0)
        {
            a[i]=1;
            count1--;
            i++;
        }
        while(count2!=0)
        {
            a[i]=2;
            count2--;
            i++;
        }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
//method 2- 3 pointer approach variation of dutch national flag algorithm
void sort012threepointer(int a[], int n)
{
    int l=0;
    int m=0;
    int h=n-1;

    while(m<=h)
    {
        switch(a[m])
        {
            case 0:
                swap(a[m++],a[l++]);
                break;
            case 1:
                m++;
                break;
            case 2:
                swap(a[m],a[h--]);
                break;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
   int a[]={2,2,1,0,0,2,1,2,2,1,0,2,0,1,0,2,1,0,2,2,1,0,0,2,2,1,1};
   int n= sizeof(a)/sizeof(a[0]);
   //sort012count(a,n);
   sort012threepointer(a,n);
}
