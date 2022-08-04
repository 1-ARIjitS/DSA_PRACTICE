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
    cout<<"enter data for root node- "<<endl;
    cin>>d;
    root= new node(d);
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        cout<<"enter data for left of node "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            temp->left=new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter data for right of node "<<temp->data<<endl;
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

int sum(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=sum(root->left);
    int right=sum(root->right);
    int s=left+right+root->data;
    return s;
}

//sum tree implies data at all nodes is sum of data of left subtree and right subtree
bool is_sum_tree(node* root)
{
    if(root==NULL)
    {
        return true;
    }
    bool left=is_sum_tree(root->left);
    bool right=is_sum_tree(root->right);
    bool condn=(sum(root->left)+sum(root->right)==root->data);

    //both root right and root left are null implies that you have reached a leaf node
    if(root->left==NULL && root->right==NULL)
    {
        if(left && right)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //non leaf node
    else
    {
        if(left && right && condn)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

pair<bool,int> fast_is_sum_tree(node* root)
{
    pair<bool,int> issum_sum_pair;
    if(root==NULL)
    {
        issum_sum_pair.first=true;
        issum_sum_pair.second=0;
        return issum_sum_pair;
    }

    //leaf node condition
    if(root->left==NULL && root->right==NULL)
    {
        issum_sum_pair.first=true;
        issum_sum_pair.second=root->data;
        return issum_sum_pair;
    }

    pair<bool,int> left=fast_is_sum_tree(root->left);
    pair<bool,int> right=fast_is_sum_tree(root->right);

    int sum_left=left.second;
    int sum_right=right.second;

    bool left_issum=left.first;
    bool right_issum=right.first;
    bool condn=(sum_left+sum_right==root->data);

    issum_sum_pair.second=sum_left+sum_right+root->data;

    if(left_issum && right_issum && condn)
    {
        issum_sum_pair.first=true;
    }
    else
    {
        issum_sum_pair.first=false;
    }
    return issum_sum_pair;
}

int main()
{
    node* root;
    root= create_tree_level(root);
    cout<<"is the given binary tree a sum tree ?"<<endl;
    cout<<is_sum_tree(root)<<endl;
    cout<<"is the given binary tree a sum tree using the fast method?"<<endl;
    pair<bool,int>p=fast_is_sum_tree(root);
    cout<<p.first<<endl;
}
