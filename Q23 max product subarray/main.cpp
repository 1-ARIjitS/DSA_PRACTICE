#include <iostream>

using namespace std;

int maxpdtsubarray(int a[], int n)
{
    int maxpdt=0;
    int maxpdt_th=1;
    int negcount=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            negcount++;
        }
    }
    for(int i=0;i<n;i++)
    {
    if(negcount%2==0)
    {
       //even no. of negative numbers so final positive result
       maxpdt_th=maxpdt_th*a[i];
       maxpdt=max(maxpdt, abs(maxpdt_th));
    }
    else
    {
       //odd no. of negative numbers so final negative result
       maxpdt_th=maxpdt_th*a[i];
       maxpdt=max(maxpdt, maxpdt_th);
    }
    }
    return maxpdt;
}

int main()
{
    //int a[]={6, -3, -10, 0, 2};
    //int a[]={2,3,4,5,-1,0};
    int a[]={2,3,-2,4};
    int n= sizeof(a)/sizeof(a[0]);
    cout<<maxpdtsubarray(a,n);
}
