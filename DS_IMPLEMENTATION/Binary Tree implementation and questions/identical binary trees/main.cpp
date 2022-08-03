#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* create_tree_level(node* root)
{
    queue<node*>q;
    int d;
    cout<<"enter data for root-"<<endl;
    cin>>d;
    root= new node(d);
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        cout<<"enter data for left node of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            temp->left= new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter data for right node of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            temp->right= new node(rightdata);
            q.push(temp->right);
        }
    }

    return root;
}

bool identical_trees(node* root1, node* root2)
{
    if(root1==NULL && root2== NULL)
    {
        return true;
    }
    if(root1!=NULL && root2== NULL)
    {
        return false;
    }
    if(root1==NULL && root2!= NULL)
    {
        return false;
    }
    bool left=identical_trees(root1->left,root2->left);
    bool right=identical_trees(root1->right,root2->right);
    bool value=root1->data==root2->data;
    if(left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node* root1;
    cout<<"enter details of the first binary tree- "<<endl;
    root1= create_tree_level(root1);

    node* root2;
    cout<<"enter details of the second binary tree- "<<endl;
    root2= create_tree_level(root2);

    cout<<"are the two given binary trees identical?"<<endl;
    if(identical_trees(root1,root2))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}
