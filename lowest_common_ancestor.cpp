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

Node* lowest_common_ancs(Node* root,Node* p,Node* q)
{
	if(root==nullptr || root==p || root==q)
		return root;
	Node* left=lowest_common_ancs(root->left,p,q);
	Node* right=lowest_common_ancs(root->right,p,q);
	if(left==NULL)
		return right;
	else if(right==NULL)
		return left;
	else
		return root;

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
	Node* nd=lowest_common_ancs(root,root->left,root->right->right);
	cout<<nd->data;
	
	return 0;
}