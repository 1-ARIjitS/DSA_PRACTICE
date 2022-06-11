#include <bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node *prev;
    node(int n)
    {
        this->data=n;
        prev=NULL;
    }
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

void multiply(node *tail, int i)
{
    node *temp= tail;
    node *prevnode= tail;
    int carry=0;
    while(temp!=NULL)
    {
        int data=temp->data*i+carry;
        temp->data=data%10;
        carry=data/10;
        prevnode=temp;
        temp=temp->prev;
    }
    while(carry!=0)
    {
        prevnode->prev= new node((int)carry%10);
        carry/=10;
        prevnode= prevnode->prev;
    }
}
void factlarge(int a)
{
    node tail(1);
    for(int i=2;i<a;i++)
    {
        multiply(&tail,i);
    }
}

int main()
{
    int a=5;
    //cout<<factsmall(a);
    factlarge(a);
}
