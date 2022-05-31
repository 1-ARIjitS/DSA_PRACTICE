#include <bits/stdc++.h>

using namespace std;
//method 1-
void next_permutation_brute(int a[], int n)
{

}

//method 2- single pass approach
void next_permutation_single_pass(int a[], int n)
{
    int idx=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>a[i-1])
        {
            idx=i;
            break;
        }
    }
    if(idx==-1)
    {
        reverse(a,a+n);
    }
    else
    {
        int prev=idx;
        for(int i=idx+1;i<n;i++)
        {
            if(a[i]>a[idx-1] and a[i]<a[prev])
            {
                prev=i;
            }
        }
        swap(a[idx-1],a[prev]);
        reverse(a+idx,a+n);
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
