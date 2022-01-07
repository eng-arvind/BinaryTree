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
vector<int> zig_zag_tra(Node* root)
{
	vector<int> ans;
    if(root==NULL) return ans;
    queue<Node*> q;
    q.push(root);
    bool flag=true;
    while(!q.empty()) {
        int sz=q.size();
        int anssize=ans.size();
        ans.resize(anssize+sz);
        for(int i=0;i<sz;i++) {
            Node * node=q.front();
            q.pop();
            if(flag)
            ans[anssize+i]=node->data;
            else
             ans[anssize+sz-1-i]=node->data; 
            if(node->left!=NULL)
                q.push(node->left);
             if(node->right!=NULL)
                q.push(node->right);
        }
            flag= !flag;
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
	vector<int> res=zig_zag_tra(root);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	return 0;
}