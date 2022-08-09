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
    cout<<"enter data of root node"<<endl;
    cin>>rootdata;
    root=new node(rootdata);
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        cout<<"enter data for the left node of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            temp->left=new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter data for the right node of "<<temp->data<<endl;
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

void left_traversal(node* root, vector<int>&v)
{
    if((root==NULL) || (root->left==NULL && root->right==NULL))
    {
        return;
    }
    v.push_back(root->data);
    if(root->left)
    {
        left_traversal(root->left,v);
    }
    else
    {
        left_traversal(root->right,v);
    }
}

void leaf_traversal(node* root, vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        v.push_back(root->data);
    }
    leaf_traversal(root->left,v);
    leaf_traversal(root->right,v);
}

void right_traversal(node* root, vector<int>&v)
{
    if((root==NULL) || (root->left==NULL && root->right==NULL))
    {
        return;
    }
    if(root->right)
    {
        right_traversal(root->right,v);
    }
    else
    {
        right_traversal(root->left,v);
    }
    v.push_back(root->data);
}

vector<int> boundary_traversal(node* root)
{
    vector<int>v;
    if(root==NULL)
    {
        return v;
    }
    //pushing the root node of the binary tree onto thew vector
    v.push_back(root->data);
    //then we traverse the whole tree using the boundary traversal
    //traverse the left boundary or left nodes
    left_traversal(root->left,v);
    //traverse the left leaf nodes
    leaf_traversal(root->left,v);
    //traverse the right leaf nodes
    leaf_traversal(root->right,v);
    //traverse the right boundary or right nodes
    right_traversal(root->right,v);
    //return the vector containing the boundary traversal
    return v;
}

int main()
{
    node* root;
    root= create_tree_level(root);
    cout<<"the boundary traversal of the binary tree is"<<endl;
    vector<int>bound_trav= boundary_traversal(root);
    for(auto it:bound_trav)
    {
        cout<<it<<" ";
    }
}
