#include <bits/stdc++.h>

using namespace std;
//class for implementation of stacks using linked lists
class stackll
{
public:
    int data;
    stackll* next;
    stackll* top;
    stackll* head;

    stackll()
    {
        head=NULL;
        top=head;
    }

    void push(int ele)
    {
        stackll* temp;
        temp= new stackll();
        temp->data= ele;
        temp->next= NULL;
        if(top==NULL)
        {
           head=temp;
           top=head;
        }
        else
        {
            top->next=temp;
            top=temp;
        }
    }

    int pop()
    {
        //the top of stack to be popped
        int poptop;
        //no element in stack
        if(top==NULL)
        {
            return -1;
        }
        //one element in stack
        else if(head->next==NULL)
        {
            poptop= head->data;
            head=NULL;
            top=NULL;
            return poptop;
        }
        //more than one element in stack
        else
        {
            stackll *temp;
            temp=top;
            poptop=temp->data;
            stackll *p;
            p=head;
            while(p->next!=top)
            {
                p=p->next;
            }
            p->next=NULL;
            top=p;
            free(temp);
            return poptop;
        }
    }

    int peek()
    {
        if(top==NULL)
        {
            return -1;
        }
        else
        {
            int poptop= top->data;
            return poptop;
        }
    }

    bool isEmpty()
    {
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void printstackll()
    {
        if(top==NULL)
        {
            cout<<"empty stack nothing to print"<<endl;
        }
        else{
        stackll *p=head;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
        }
    }
};

int main()
{
    stackll s;
    s.push(5);
    s.push(2);
    s.push(3);
    s.push(4);
    //s.push(5);
    s.printstackll();
    cout<<s.pop()<<endl;
    s.printstackll();
    cout<<s.pop()<<endl;
    s.printstackll();
    cout<<s.pop()<<endl;
    s.printstackll();
    cout<<s.pop()<<endl;
    s.printstackll();
    cout<<s.isEmpty();
}
