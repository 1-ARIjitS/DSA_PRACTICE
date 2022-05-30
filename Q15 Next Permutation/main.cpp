#include <bits/stdc++.h>

using namespace std;
//method 1-
void next_permutation_brute(int a[], int n)
{

}

//method 2- single pass approach
void next_permutation_single_pass(int a[], int n)
{
    int i=n-1;
    while(a[i]<a[i-1])
    {
        i--;
    }
    int idx=i;
    if(idx==0)
    {
        sort(a,a+n);
    }
    else
    {
    int min=a[idx-1];
    int min_great=a[idx];
    int idx_great=idx;
    for(int j=idx;j<n;j++)
    {
        if(a[j]<min_great && a[j]>min)
        {
            min_great=a[j];
            idx_great=j;
        }
    }
    swap(a[idx-1],a[idx_great]);
    sort(a+idx,a+n);
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int a[]={1,5,8,4,7,6,5,3,1};
    //int a[]={1,2,3};
    //int a[]={3,2,1};
    int n= sizeof(a)/sizeof(a[0]);
    //next_permutation_brute(a,n);
    next_permutation_single_pass(a,n);
    /*do {
        cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    } while (next_permutation(a, a + 3));*/
}
