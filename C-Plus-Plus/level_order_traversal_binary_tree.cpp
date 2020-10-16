#include<bits/stdc++.h>
#include<queue>
using namespace std;

/*
            10
           /  \
          20   30
        /  \     \
       40   50    70

       60 is added to left of 30

*/

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
    ~Node(){}
};

void inorder(Node *root)
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void insert_level_order(Node *root,int val)
{
    Node *nn =new Node(val);
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node *n=q.front();
        q.pop();
        if(n->left==nullptr)
        {
            n->left=nn;
            return;
        }
        else if(n->right==nullptr)
        {
            n->right=nn;
            return;
        }
        else
        {
            q.push(n->left);
            q.push(n->right);
        }
        
    }
}

int main()
{
    Node *n10=new Node(10);
    Node *n20=new Node(20);
    Node *n30=new Node(30);
    Node *n40=new Node(40);
    Node *n50=new Node(50);
    Node *n70=new Node(70);
    n10->left=n20;
    n10->right=n30;
    n20->left=n40;
    n20->right=n50;
    n30->right=n70;
    inorder(n10);
    cout<<endl;
    insert_level_order(n10,60);
    inorder(n10);
    cout<<endl;
    return 0;
}