#include <bits/stdc++.h>

using namespace std;
//class for creating a single node
class node
{
    public:
        int data;
        node* left;
        node* right;

    //constructor
    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

//methods
node* buildtree(node* root)
{
   int data;
   cout<<"enter the data- "<<endl;
   cin>>data;
   root= new node(data);

   if(data==-1)
   {
       return NULL;
   }

   //building the left subtree of a particular node
   cout<<"enter data for inserting in left of "<<data<<endl;
   root->left=buildtree(root->left);

   //building the right subtree of a particular node
   cout<<"enter data for inserting in right of "<<data<<endl;
   root->right=buildtree(root->right);

   return root;
}

//function to print a given level
void printagivenlevel(node* root, int level)
{
    if(root==NULL)
    {
        return;
    }
    if(level==1)
    {
        cout<<root->data<<" ";
    }
    else if(level>1)
    {
        printagivenlevel(root->right,level-1);
        printagivenlevel(root->left,level-1);
    }
}

//function to calculate the height of the tree
int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        //return max(leftheight,rightheight)+1;
        if(leftheight>rightheight)
        {
            return leftheight+1;
        }
        else
        {
            return rightheight+1;
        }
    }
}

//level order traversal also called BFS(breadth first search) done using queues
void levelordertraversalsimple(node* root)
{
     queue<node*> q;
     q.push(root);

     cout<<"the level order traversal for the following tree is-"<<endl;
     while(!q.empty())
     {
         node* temp= q.front();
         cout<<temp->data<<" ";
         q.pop();
         if(temp->left)
         {
             q.push(temp->left);
         }
         if(temp->right)
         {
             q.push(temp->right);
         }
     }

     cout<<endl;
}

//level order traversal using separators
void levelordertraversalseparator(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    cout<<"the level order traversal for the following tree using separator is-"<<endl;

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            //temp==null implies that the previous level is already traversed
            cout<<endl;

            //we put a null at end of queue if the queue still has some child nodes so that the next level can be printed
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

//reverse level order traversal
//method 1- reverse level order traversal using space
void reverselevelordertraversalspace(node* root)
{
    queue<node*> q;
    q.push(root);
    vector<int> v;
    cout<<"the reverse level order traversal for the following tree using vectors is-"<<endl;

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        v.push_back(temp->data);
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }

    reverse(v.begin(),v.end());
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

//method 2- reverse level order traversal using stacks
void reverselevelordertraversalstacks(node* root)
{
    queue<node*> q;
    q.push(root);
    stack<int> s;
    cout<<"the reverse level order traversal for the following tree using stacks is-"<<endl;

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        s.push(temp->data);
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl;
}

//method 3- reverse level order traversal using recursion
void reverselevelordertraversalrecursion(node* root)
{
    int h=height(root);
    cout<<"the reverse level order traversal for the following tree using recursion is-"<<endl;
    for(int i=h;i>=1;i--)
    {
        printagivenlevel(root,i);
    }
    cout<<endl;
}

//inorder traversal of the given binary tree
void inoredertraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        //left node
        inoredertraversal(root->left);
        //root or node
        cout<<root->data<<" ";
        //right node
        inoredertraversal(root->right);
    }
}

//preorder traversal of the given binary tree
void preoredertraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        //root or node
        cout<<root->data<<" ";
        //left node
        preoredertraversal(root->left);
        //right node
        preoredertraversal(root->right);
    }
}

//postorder traversal of the given binary tree
void postoredertraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        //left node
        postoredertraversal(root->left);
        //right node
        postoredertraversal(root->right);
        //root or node
        cout<<root->data<<" ";
    }
}

int main()
{
    node* root= NULL;

    //creating a tree
    //for data 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 (-1 implies that pointer points to null)
    root= buildtree(root);

    //level order traversal simple
    levelordertraversalsimple(root);

    //level order traversal using separator
    levelordertraversalseparator(root);

    //reverse level order traversal using vectors
    reverselevelordertraversalspace(root);

    //reverse level order traversal using stacks
    reverselevelordertraversalspace(root);

    //reverse level order traversal using recursion
    reverselevelordertraversalrecursion(root);

    //inorder traversal
    cout<<"the inorder traversal for the following tree using recursion is-"<<endl;
    inoredertraversal(root);
    cout<<endl;

    //preorder traversal
    cout<<"the preorder traversal for the following tree using recursion is-"<<endl;
    preoredertraversal(root);
    cout<<endl;

    //postorder traversal
    cout<<"the postorder traversal for the following tree using recursion is-"<<endl;
    postoredertraversal(root);
    cout<<endl;
}
