#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val)
	{
		data=val;
		left=right=NULL;
	}
};
void postorder_traversal(Node* root)
{
	if(root==NULL)
		return;
	stack<Node*> st1,st2;
	st1.push(root);
	while(!st1.empty())
	{
		root=st1.top();
		st1.pop();
		st2.push(root);
		if(root->left!=NULL)
			st1.push(root->left);
		if(root->right!=NULL)
			st1.push(root->right);
	}
	while(!st2.empty()){
		Node* temp=st2.top();
		cout<<temp->data<<" ";
		st2.pop();
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	

	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	postorder_traversal(root);
	return 0;
}