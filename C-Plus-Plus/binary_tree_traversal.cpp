#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val):data(val),left(nullptr),right(nullptr){};
    ~Node(){}
};

void Inorder_stack(Node *root)
{
    stack<Node *> s;
    Node *curr=root;

    while(curr||!s.empty()){
        while(curr){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}

void inorder(Node *root)
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if(!root)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if(!root)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node *root)
{
    if(!root)
    return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node *ptr=q.front();
        cout<<ptr->data<<" ";
        q.pop();
        if(ptr->left) q.push(ptr->left);
        if(ptr->right) q.push(ptr->right);
    }
}

int main()
{
    Node *n1=new Node(1);
    Node *n2=new Node(2);
    Node *n3=new Node(3);
    Node *n4=new Node(4);
    Node *n5=new Node(5);    
    Node *n6=new Node(6);
    Node *n7=new Node(7); 

    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n4->right=n7;
    n3->left=n5;
    n3->right=n6;

    Node *root=n1;

    cout<<"Inorder traversal : ";
    inorder(root);
    cout<<endl;
    cout<<"Inorder traversal : ";
    Inorder_stack(root);
    cout<<endl;
    cout<<"Preorder traversal : ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal : ";
    postorder(root);
    cout<<endl;
    cout<<"Levelorder traversal : ";
    levelorder(root);
    cout<<endl;
    return 0;
}