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

long long int findsum(Node *root,long long int &sm,long long int &ch)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL) ch++;
    long long int ls=findsum(root->left,sm,ch);
    long long int rs=findsum(root->right,sm,ch);
    sm=max(sm,root->data+ls+rs);
    return root->data+max(ls,rs);
}
long long int findMaxSumPath(Node *root)
{
    // Write your code here.
    long long int sm=0,ch=0;
    if(root==NULL)
        return -1;
    findsum(root,sm,ch);
    if(ch==0 || ch==1)
        return -1;
    return sm;
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
	cout<<findMaxSumPath(root)<<endl;

	return 0;
}