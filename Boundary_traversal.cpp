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
void leftside(Node* root,vector<int> &ans)
{
	Node* cr=root;
	while(cr->left!=NULL && cr->right!=NULL)
	{
		ans.push_back(cr->data);
		if(cr->left!=NULL) cr=cr->left;
		else if(cr->right!=NULL) cr=cr->right;
	}
}
void leafside(Node* root,vector<int> &ans)
{
	if(root->left==NULL && root->right==NULL)
		ans.push_back(root->data);
	if(root->left)
	leafside(root->left,ans);
	if(root->right)
	leafside(root->right,ans);
}
void rightside(Node* root,vector<int> &ans)
{
	Node* cr=root->right;
	vector<int> temp;
	while(cr->left!=NULL && cr->right!=NULL)
	{
		temp.push_back(cr->data);
		if(cr->right!=NULL) cr=cr->right;
		else if(cr->left!=NULL) cr=cr->left;
		
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
   if(root->left==NULL && root->right==NULL)
   {
   		ans.push_back(root->data);
   		return ans;
   }
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