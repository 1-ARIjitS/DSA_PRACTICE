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
    cout<<"enter the root node"<<endl;
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

void zig_zag_traversal(node* root)
{
    queue<node*>q;
    q.push(root);
    vector<int> zigzag;
    bool lefttoright=true;

    while(!q.empty())
    {
        int qsize=q.size();
        vector<int>eachlevel(qsize);
        for(int i=0;i<qsize;i++)
        {
            node* temp=q.front();
            q.pop();

            if(lefttoright==true)
            {
                eachlevel[i]=temp->data;
            }
            else if(lefttoright==false)
            {
                eachlevel[qsize-i-1]=temp->data;
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }

        lefttoright=!lefttoright;

        for(auto it:eachlevel)
        {
            zigzag.push_back(it);
        }
    }

    for(auto it:zigzag)
    {
        cout<<it<<" ";
    }
}

int main()
{
    node* root;
    root= create_tree_level(root);
    cout<<"zig zag traversal for the given tree is- "<<endl;
    zig_zag_traversal(root);
}
