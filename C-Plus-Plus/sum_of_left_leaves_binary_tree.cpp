/*
question link-->>  https://leetcode.com/problems/sum-of-left-leaves/
Find the sum of all left leaves in a given binary tree.

           1
          / \
         2   3
        /   / \
       4   5   6
        \
         7

         sum of all left leaves=5
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val):data(val),left(nullptr),right(nullptr){};
    ~Node(){}
};

class Solution {
    int sum=0;
    void sumOfLeftLeaves(Node *root,bool isleft)
    {
        if(isleft&&!root->left&&!root->right){
            sum+=root->data;
        return;}
        
    if(root->left) sumOfLeftLeaves(root->left,true);
    if(root->right) sumOfLeftLeaves(root->right,false);
    }
        
public:
    int sumOfLeftLeaves(Node* root) {
        if(!root)
            return 0;
        sumOfLeftLeaves(root,false);
        return sum;
    }
};

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
    Solution s;
    cout<<s.sumOfLeftLeaves(root);
    return 0;
}