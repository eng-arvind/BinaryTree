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
bool path(Node* root,vector<int> &ans,int x)
{
    if(root==NULL)
    	return false;
    ans.push_back(root->data);
    if(x==root->data)
    	return true;
    if(path(root->left,ans,x) || path(root->right,ans,x))
    	return true;
    ans.pop_back();
    return false;

}

vector<int> path_from_root_t_node(Node* root,int x)
{
	vector<int> ans;
	 if(root==NULL)
        return ans;
    path(root,ans,x);
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
	vector<int> res=path_from_root_t_node(root,6);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	return 0;
}