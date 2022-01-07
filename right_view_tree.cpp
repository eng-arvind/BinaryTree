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

void rightView(Node *root,int lev,vector<int> &ans)
{
    if(root==NULL) return;
    if(lev==ans.size())
        ans.push_back(root->data);
     if(root->right!=NULL)
        rightView(root->right,lev+1,ans);
     if(root->left!=NULL)
        rightView(root->left,lev+1,ans);
}

vector<int> right_view(Node* root)
{
	  vector<int> ans;
    if(root==NULL)
        return ans;
   rightView(root,0,ans);
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
	vector<int> res=right_view(root);
	for(int i=0;i<res.size();i++)
	{
			cout<<res[i]<<" ";
	}
	return 0;
}