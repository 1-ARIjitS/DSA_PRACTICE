#include <bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node *next;
};

long long factsmall(long long a)
{
    long long fact=1;
    for(long long i=2;i<=a;i++)
    {
        fact=fact*i;
    }
    return fact;
}

void factlarge(long long a)
{
    //vector<int> v;
    node *head= new node();
    head->data=1;
    head->next=nullptr;
    int fact=1;
    int i=2;
    /*while(fact!=0 && i<=2)
    {
        int rem= (fact*i)%10;
        fact=
    }*/
}

int main()
{
    long long a=5;
    cout<<factsmall(a);
}
