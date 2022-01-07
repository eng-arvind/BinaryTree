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
int Balance(Node* root)
{
    if(root==NULL)
        return 0;
    int lh=Balance(root->left);
    if(lh==-1) return -1;
    int rh=Balance(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
}
bool Is_tree_balanced(Node* root)
{
	return Balance(root)!=-1;
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
	root->left->left->left=new Node(6);
	if(Is_tree_balanced(root))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}