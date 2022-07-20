#include <bits/stdc++.h>

using namespace std;
//calculating a^b using recursion
int powerrec(int a, int b)
{
    //int power=a;
    if(b==0)
    {
        return 1;
    }
    else
    {
        //power= power*powerrec(a,b-1);
        return a*powerrec(a,b-1);
    }
    //return power;
}

//fast exponentiation
int powerrecfast(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    //optional if statement will work even if its not written
    if(b==1)
    {
        return a;
    }
    else
    {
        //if b is even
        if(b%2==0)
        {
            return powerrecfast(a,b/2)*powerrecfast(a,b/2);
        }

        //if b is odd
        else if(b%2!=0)
        {
            return a*powerrecfast(a,b/2)*powerrecfast(a,b/2);
        }
    }    
}

int main()
{
    int a;
    int b;
    cin>>a>>b;
    //cout<<powerrec(a,b);
    cout<<powerrecfast(a,b);
}
