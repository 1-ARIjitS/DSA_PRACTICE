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
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }

    root=new node(data);

    cout<<"enter data to left of "<<root->data<<endl;
    create_tree(root->left);

    cout<<"enter data to right of "<<root->data<<endl;
    create_tree(root->right);

    return root;
}

node* create_tree_level(node* root)
{
    queue<node*>q;
    int rootdata;
    cout<<"enter data for root node"<<endl;
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

vector<int> vertical_traversal(node* root)
{
    vector<int>traversal;
    //map of horizontal distance mapped to a map of level and vector of elements in that level
    map<int,map<int,vector<int>>>nodes;
    //a queue is created for level order traversal
    //this queue is a pair of node*(pointer to node) and a pair storing the horizontal distance and level
    queue<pair<node*,pair<int,int>>>q;

    if(root==NULL)
    {
        return traversal;
    }

    //now we push the root node into the queue along with storing its horizontal distance and level
    //since initial horizontal distance and level of root node is 0 we push a pair of (0,0)
    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty())
    {
        auto temp=q.front();
        q.pop();
        //dequeue the head node of the queue
        node* frontnode=temp.first;
        //horizontal distance represented by hd
        int hd=temp.second.first;
        //level represented by level
        int level=temp.second.second;

        //now make the map
        nodes[hd][level].push_back(frontnode->data);

        //now push into the queue the left node and right node
        if(frontnode->left)
        {
           q.push(make_pair(frontnode->left,make_pair(hd-1,level+1)));
        }
        if(frontnode->right)
        {
            q.push(make_pair(frontnode->right,make_pair(hd+1,level+1)));
        }
    }

    for(auto i:nodes)
    {
        for(auto j:i.second)
        {
            for(auto k:j.second)
            {
                traversal.push_back(k);
            }
        }
    }

    return traversal;
}

int main()
{
   node* root;
   root= create_tree_level(root);
   vector<int>res;
   res= vertical_traversal(root);
   cout<<"the vertical traversal of the tree is as follows"<<endl;
   for(auto it:res)
   {
       cout<<it<<" ";
   }
}
