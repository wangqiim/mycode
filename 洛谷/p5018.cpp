#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1000001;

int tree[maxn][2];	//tree[i][0].i的左节点的编号,如果没有则为-1 
int val[maxn];

bool ismirror(int root1,int root2,int &t){ //判断root1与root2是否为镜像树 
	if(root1==-1&&root2==-1)	return true;	//都空 
	if(root1==-1^root2==-1)	return false;	//只有一个空 
	if(val[root1]==val[root2]){
		t++;//结点数+1 
		return ismirror(tree[root1][0],tree[root2][1],t)&&ismirror(tree[root1][1],tree[root2][0],t);
	} 
	else
		return false;
}

int dfs(int root){	//先序遍历,返回最大对称子树的结点数 
	int t=0;
	if(root==-1) return t;
	if(ismirror(root,root,t)) return t;
	else{
		return max(dfs(tree[root][0]),dfs(tree[root][1]));
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d %d",&tree[i][0],&tree[i][1]);
	}
	printf("%d",dfs(1));
	return 0;
}
