#include<cstdio>
#include<vector>
using namespace std;

const int maxn = 1001;
int n;
vector<int> nums;
vector<int> pre_nums;
vector<int> pre_nums_mirror;
vector<int> post_nums;
vector<int> post_nums_mirror;


struct node{
	int data;
	node *left;
	node *right;
};

void insert(node *&root,int x){
	if(root == NULL){
		root = new node;
		root->data = x;
		root->left = root->right = NULL;
	}else if(x<root->data)
		insert(root->left,x);
	else
		insert(root->right,x);
	return;	
}

void pre_order(node* root){
	if(root == NULL)
		return;
	else{
		pre_nums.push_back(root->data);
		pre_order(root->left);
		pre_order(root->right);
	}
}

void pre_order_mirror(node* root){
	if(root == NULL)
		return;
	else{
		pre_nums_mirror.push_back(root->data);
		pre_order_mirror(root->right);
		pre_order_mirror(root->left);
	}
}

void post_order(node* root){
	if(root == NULL)
		return;
	else{
		post_order(root->left);
		post_order(root->right);
		post_nums.push_back(root->data);
	}
}

void post_order_mirror(node* root){
	if(root == NULL)
		return;
	else{
		post_order_mirror(root->right);
		post_order_mirror(root->left);
		post_nums_mirror.push_back(root->data);
	}
}

int main(){
	scanf("%d",&n);
	int data;
	node *root = NULL;
	for(int i = 0;i<n;i++){
		scanf("%d",&data);
		nums.push_back(data);
		insert(root,data);
	}
	pre_order(root);
	pre_order_mirror(root);
	post_order(root);
	post_order_mirror(root);
	if(nums == pre_nums){
		printf("YES\n");
		for(int i= 0;i<n;i++){
			printf("%d",post_nums[i]);
			if(i!=n-1)
				printf(" ");
		}
	}
	else if(nums == pre_nums_mirror){
		printf("YES\n");
		for(int i = 0 ;i<n ;i++){
			printf("%d",post_nums_mirror[i]);
			if(i!=n-1)
				printf(" ");		
		}
	}else{
		printf("NO\n");
	}
	return 0;
}
