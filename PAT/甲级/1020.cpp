#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

const int maxn = 30;
int n;
int postorder[maxn];	
int inorder[maxn];

node* creat(int post_l,int post_r,int in_l,int in_r);
void level_order(node *root);

node* creat(int post_l,int post_r,int in_l,int in_r){
	if(post_l>post_r){
		return NULL;
	}
	node* root = new node;
	int k;
	for(k = in_l;k<=in_r;k++){
		if(inorder[k]==postorder[post_r])
			break;
	}
	root->data = postorder[post_r];
	root->left = creat(post_l,post_l+k-in_l-1,in_l,k-1);
	root->right = creat(post_l+k-in_l,post_r-1,k+1,in_r);
	return root;
}

void level_order(node *root){
	queue <node*> q;
	if(root == NULL)
		return;
	q.push(root);
	while(!q.empty()){
		node *now = q.front();
		q.pop();
		if(now==root)
			printf("%d",now->data);
		else
			printf(" %d",now->data);
		if(now->left!=NULL) q.push(now->left);
		if(now->right!=NULL) q.push(now->right);
	}
	return;
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&postorder[i]);	//ºóÐò 
	}
	for(int i = 0;i<n;i++){
		scanf("%d",&inorder[i]);	//ÖÐÐò 
	}
	int post_left,post_right,in_left,in_right;
	node* root = creat(0,n-1,0,n-1);
	level_order(root);
	return 0;
} 


