#include<bits/stdc++.h>
#include<queue>
using namespace std;

/*
            1
           /  \
          2    3
         /    /
        4    5
         \
          6

         delete 3 
            1
           / \
          2   6
         /   /
        4   5
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

Node* delete_node(Node * root,int key)
{
    if(root==nullptr)
    return nullptr;
    if(!root->left&&!root->right)
    {
        if(root->data==key)
        {
            delete root;
            root=nullptr;
            return root;
        }
        return root;
    }
    queue<Node *> q;
    q.push(root);
    Node *key_node=nullptr;
    Node *curr_node=nullptr;
    Node *pl=nullptr;
    Node *pr=nullptr;

    while(!q.empty())
    {
        curr_node=q.front();
        q.pop();

        if(curr_node->data==key)
        key_node=curr_node;

        if(curr_node->left)
        {
            q.push(curr_node->left);
            pl=curr_node;
            pr=nullptr;
        }

        if(curr_node->right)
        {
            q.push(curr_node->right);
            pr=curr_node;
            pl=nullptr;
        }
    }

    if(key_node)
    {
        key_node->data=curr_node->data;
        //remove last node
        curr_node=nullptr;
        if(pl)
        {
            pl->left=nullptr;
        }
        if(pr)
        {
            pr->right=nullptr;
        }
    }
    return root;
}

int main()
{
    Node *n1=new Node(1);
    Node *n2=new Node(2);
    Node *n3=new Node(3);
    Node *n4=new Node(4);
    Node *n5=new Node(5);
    Node *n6=new Node(6);
    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n3->left=n5;
    n4->right=n6;
    Node *root=n1;
    inorder(root);
    cout<<endl;
    delete_node(root,2);
    inorder(root);
    cout<<endl;
    return 0;
}