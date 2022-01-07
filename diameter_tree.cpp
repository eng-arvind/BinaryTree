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
int diameter_tree(Node* root,int &d)
{
	if(root==NULL)
		return 0;
	int lh=diameter_tree(root->left,d);
	int rh=diameter_tree(root->right,d);
	d=max(d,lh+rh);
	return 1+max(lh,rh);
}
int diameter(Node* root)
{
	int d=0;
	diameter_tree(root,d);
	return d;
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
	cout<<diameter(root);
	return 0;
}