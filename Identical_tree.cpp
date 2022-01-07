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

bool Identical_tree(Node* root1,Node* root2)
{
	if(root1==NULL || root2==NULL)
		return root1==root2;
	return (root1->data==root2->data) && Identical_tree(root1->left,root2->left) && Identical_tree(root1->right,root2->right);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	

	Node* root1=new Node(1);
	root1->left=new Node(2);
	root1->right=new Node(3);
	root1->left->left=new Node(4);
	root1->left->right=new Node(5);
	root1->left->left->left=new Node(6);

	Node* root2=new Node(1);
	root2->left=new Node(2);
	root2->right=new Node(3);
	root2->left->left=new Node(4);
	root2->left->right=new Node(5);
	root2->left->left->left=new Node(6);
	if(Identical_tree(root1,root2))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}