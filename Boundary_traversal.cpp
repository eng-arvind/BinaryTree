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
   bool isLeaf(Node* root){
        return !root->left && !root->right;
    }
void leftside(Node* root,vector<int> &ans)
{
	Node* cr=root->left;
	while(cr)
	{
		if(!isLeaf(cr))
		ans.push_back(cr->data);
		if(cr->left) cr=cr->left;
		else cr=cr->right;
	}
}
void leafside(Node* root,vector<int> &ans)
{
	if(isLeaf(root))
	{
		ans.push_back(root->data);
		return;
	}
	if(root->left)
	leafside(root->left,ans);
	if(root->right)
	leafside(root->right,ans);
}
void rightside(Node* root,vector<int> &ans)
{
	Node* cr=root->right;
	vector<int> temp;
	while(cr)
	{
		if(!isLeaf(cr))
		temp.push_back(cr->data);
		if(cr->right) cr=cr->right;
		else cr=cr->left;
		
	}
	for(int i=temp.size()-1;i>=0;--i)
	{
		ans.push_back(temp[i]);
	}
}
vector<int> boundary_tra(Node* root)
{
	vector<int> ans;
    if(root==NULL) return ans;
   ans.push_back(root->data);
   leftside(root,ans);
   leafside(root,ans);
   rightside(root,ans);
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
	vector<int> res=boundary_tra(root);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	return 0;
}