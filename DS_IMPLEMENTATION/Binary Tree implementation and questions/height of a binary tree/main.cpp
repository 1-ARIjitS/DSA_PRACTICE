#include <iostream>

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

node* create_tree(node* root)
{
    cout<<"enter the data- "<<endl;
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    root= new node(d);

    cout<<"enter data to left of "<<d<<endl;
    root->left=create_tree(root->left);

    cout<<"enter data to right of "<<d<<endl;
    root->right=create_tree(root->right);

    return root;
}

int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int left_subtree_height=height(root->left);
        int right_subtree_height=height(root->right);
        return max(left_subtree_height,right_subtree_height)+1;
    }
}

int main()
{
    node* root;
    //create a simple tree as 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    root= create_tree(root);
    //height of the tree using recursion
    cout<<"height of the given binary tree is- "<<endl;
    cout<<height(root);
}
