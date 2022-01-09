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
/* this one is for vector

 void path(Node* root,vector<vector<int>> &ans,vector<int> &temp)
 {
     if(root==NULL)
     return;
     temp.push_back(root->data);
     if(root->left==NULL && root->right==NULL)
     {
         ans.push_back(temp);
         temp.pop_back();
         return;
     }
     path(root->left,ans,temp);
     path(root->right,ans,temp);
     temp.pop_back();
     return;
 }

*/

 void path(Node* root,vector<string> &ans,string s)
{
    if(root==nullptr)
        return;
    s+=to_string(root->data);
    if(!root->left && !root->right)
    {
        ans.push_back(s);
        s="";
    }
    s+="->";
    path(root->left,ans,s);
    path(root->right,ans,s);
}

vector<string> All_path_from_root_t_leaf(Node* root)
{
   vector<string> ans;
	 if(root==NULL)
        return ans;
        string s="";
    path(root,ans,s);    
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
	vector<string> res=All_path_from_root_t_leaf(root);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
	return 0;
}