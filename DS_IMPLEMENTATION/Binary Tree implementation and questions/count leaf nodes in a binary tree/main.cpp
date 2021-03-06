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

node* create_tree(node* root)
{
    cout<<"enter the data- "<<endl;
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    root=new node(d);

    cout<<"enter data to be placed in the left of "<<root->data<<endl;
    root->left=create_tree(root->left);

    cout<<"enter data to be placed in the right of "<<root->data<<endl;
    root->right=create_tree(root->right);

    return root;
}

int count_leaf_nodes(node* root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    else
    {
        int count_leaf_left_subtree=count_leaf_nodes(root->left);
        int count_leaf_right_subtree=count_leaf_nodes(root->right);
        return count_leaf_left_subtree+count_leaf_right_subtree;
    }
}

void count_leaf_nodes_using_traversal(node* root, int &leaf_count)
{
    //using inorder traversal
    //similarly we can use any traversal we want preorder, postodrder to calculate number of leaf nodes in the tree
    if(root==NULL)
    {
        return;
    }
    count_leaf_nodes_using_traversal(root->left,leaf_count);
    if(root->left==NULL && root->right==NULL)
    {
        leaf_count++;
    }
    count_leaf_nodes_using_traversal(root->right,leaf_count);
}

int main()
{
    node* root;
    //root= create_tree(root);
    root= create_tree(root);

    cout<<"number of leaf nodes present in the tree using simple recursion"<<endl;
    cout<<count_leaf_nodes(root)<<endl;

    int counter=0;
    count_leaf_nodes_using_traversal(root,counter);
    cout<<"number of leaf nodes present in the tree using traversal is- "<<endl;
    cout<<counter;
}
