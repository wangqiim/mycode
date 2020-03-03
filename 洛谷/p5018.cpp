#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1000001;

int tree[maxn][2];	//tree[i][0].i����ڵ�ı��,���û����Ϊ-1 
int val[maxn];

bool ismirror(int root1,int root2,int &t){ //�ж�root1��root2�Ƿ�Ϊ������ 
	if(root1==-1&&root2==-1)	return true;	//���� 
	if(root1==-1^root2==-1)	return false;	//ֻ��һ���� 
	if(val[root1]==val[root2]){
		t++;//�����+1 
		return ismirror(tree[root1][0],tree[root2][1],t)&&ismirror(tree[root1][1],tree[root2][0],t);
	} 
	else
		return false;
}

int dfs(int root){	//�������,�������Գ������Ľ���� 
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
