//Time complexity – O(n)
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
    int data;
	Node *left;
    Node *right;
    Node(int val):data(val),left(nullptr),right(nullptr){};
    ~Node(){}
}; 

int height(Node* root, int& ans) 
{ 
	if (root == NULL) 
		return 0; 

	int left_height = height(root->left, ans); 

	int right_height = height(root->right, ans); 
	ans = max(ans, 1 + left_height + right_height); 

	return 1 + max(left_height, right_height); 
} 

int diameter(Node* root) 
{ 
	if (root == NULL) 
		return 0; 
	int ans = INT_MIN;
	int height_of_tree = height(root, ans); 
	return ans; 
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
    Node *root=n1;
    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n4->right=n7;
    n3->left=n5;
    n3->right=n6;
	printf("Diameter is %d\n", diameter(root)); 
	return 0; 
} 
