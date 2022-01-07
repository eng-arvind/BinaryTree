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

vector<vector<int>> vertical_tra(Node* root)
{
	map<int,map<int,multiset<int>>> nodes;
	queue<pair<Node*,pair<int,int>>> todo;
	todo.push({root,{0,0}});
	while(!todo.empty())
	{
		auto p=todo.front();
		todo.pop();
		Node* node=p.first;
		int x=p.second.first,y=p.second.second;
		nodes[x][y].insert(node->data);
		if(node->left)
			todo.push({node->left,{x-1,y+1}});
		if(node->right)
			todo.push({node->right,{x+1,y+1}});
	}
	vector<vector<int> > ans;
	for(auto x:nodes){
		vector<int> col;
		for(auto y:x.second){
			col.insert(col.end(),y.second.begin(),y.second.end());
		}
		ans.push_back(col);
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
	vector<vector<int>> res=vertical_tra(root);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}