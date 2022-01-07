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

vector<int> top_view(Node* root)
{
	    vector<int> ans;
    if(root==NULL)
        return ans;
    map<int,int> nodes;
	queue<pair<Node*,int>> todo;
	todo.push({root,0});
	while(!todo.empty())
	{
		auto p=todo.front();
		todo.pop();
		Node* node=p.first;
		int line=p.second;
		nodes[line]=node->data;   
		if(node->left!=NULL)
			todo.push({node->left,line-1});
		if(node->right!=NULL)
			todo.push({node->right,line+1});
	}
	for(auto x:nodes)
	{
		ans.push_back(x.second);
	}
	return ans;

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
	vector<int> res=top_view(root);
	for(int i=0;i<res.size();i++)
	{
			cout<<res[i]<<" ";
	}
	return 0;
}