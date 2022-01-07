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
void inorder_traversal(Node* root)
{
	if(root==NULL)
		return;
	stack<Node*> st;
	Node* node=root;
	while(true)
	{
		if(node!=NULL)
				{
					st.push(node);
					node=node->left;
				}
		else{
			if(st.empty()==true) break;
			node=st.top();
			st.pop();
			cout<<node->data<<" ";
			node=node->right; 
		}
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
	inorder_traversal(root);
	return 0;
}