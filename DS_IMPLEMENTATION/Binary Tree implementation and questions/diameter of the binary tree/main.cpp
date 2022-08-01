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

node* create_binary_tree(node* root)
{
    int data;
    cout<<"enter the data- "<<endl;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    root= new node(data);

    cout<<"enter data to left of "<<data<<endl;
    root->left=create_binary_tree(root->left);

    cout<<"enter data to right of "<<data<<endl;
    root->right=create_binary_tree(root->right);

    return root;
}

int height_binary_tree(node* root)
{
    int height;
    if(root==NULL)
    {
        return 0;
    }
    int left=height_binary_tree(root->left);
    int right=height_binary_tree(root->right);
    height= max(left,right)+1;
    return height;
}

//method 1- using simple recursion as there is usage of height function inside the diameter function hence O(n^2) time and O(n) space
int diameter_binary_tree(node *root)
{
    //stores the value of diameter
    int diameter;

    //base case
    if(root==NULL)
    {
        return 0;
    }

    //recursive calls

    //left diameter stores the diameter of left subtree i.e. it starts at leaf node of left subtree and ends in a leaf node of left subtree
    int left_diameter=diameter_binary_tree(root->left);

    //right diameter stores the diameter of right subtree i.e. it starts at leaf node of right subtree and ends in a leaf node of right subtree
    int right_diameter=diameter_binary_tree(root->right);

    //combo diameter stores the diameter that can be obtained from that starts at leaf node of left subtree and ends in leaf node of right subtree and vice versa
    int combo_diameter=height_binary_tree(root->left)+height_binary_tree(root->right)+1;

    //the maximum of the above three values gives the diameter of the whole binary tree
    diameter=max(combo_diameter,max(left_diameter,right_diameter));

    //return the diameter
    return diameter;
}

//method 2- without using the height function in O(n) time and O(n) space
pair<int,int> fast_diameter_binary_tree(node* root)
{
    //this stores the diameter and height at each node
    pair<int,int>diameter_height_pair;

    if(root==NULL)
    {
        diameter_height_pair.first=0;
        diameter_height_pair.second=0;
        return diameter_height_pair;
    }

    pair<int,int> left=fast_diameter_binary_tree(root->left);
    pair<int,int> right=fast_diameter_binary_tree(root->right);

    int left_height=left.second;
    int right_height=right.second;

    int left_diameter=left.first;
    int right_diameter=right.first;
    int combo_diameter=left_height+right_height+1;

    diameter_height_pair.first=max(combo_diameter,max(left_diameter,right_diameter));
    diameter_height_pair.second=max(left_height,right_height)+1;

    return diameter_height_pair;
}

int main()
{
    node* root;
    root= create_binary_tree(root);

    //diameter if the given binary tree
    cout<<"the diameter of the given binary tree is- "<<endl;
    //cout<<diameter_binary_tree(root);
    pair<int,int>d= fast_diameter_binary_tree(root);
    cout<<d.first;
}
