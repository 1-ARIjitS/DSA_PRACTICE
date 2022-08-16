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
    int rootdata;
    cout<<"enter data for the root node"<<endl;
    cin>>rootdata;
    root=new node(rootdata);
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
            temp->left=new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter data for right node of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
}

vector<int> diagonal_traversal(node* root)
{
    vector<int> diagtrav;
    if(root==NULL)
    {
        return diagtrav;
    }

    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        while(temp!=NULL)
        {
            diagtrav.push_back(temp->data);
            if(temp->left)
            {
                q.push(temp->left);
            }
            temp=temp->right;
        }
    }

    return diagtrav;
}

int main()
{
    node* root;
    root= create_tree_level(root);
    vector<int> v;
    cout<<"the diagonal traversal for the following tree is-"<<endl;
    v=diagonal_traversal(root);
    for(auto it:v)
    {
        cout<<it<<" ";
    }
}
