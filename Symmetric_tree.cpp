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
bool Symmetric(Node* left,Node* right)
{
    if(left==NULL || right==NULL)
        return left==right;
    if(left->data!=right->data)
        return false;
    return Symmetric(left->left,right->right) && Symmetric(left->right,right->left);
}

bool Symmetric_tree(Node* root)
{
	 if(root==NULL)
        return true;
    return Symmetric(root->left,root->right);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	

	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(2);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(5);
	root->right->right=new Node(4);
	if(Symmetric_tree(root))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}