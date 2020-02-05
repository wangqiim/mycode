#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;


const int maxn = 100;
int n;
int m;	//非叶子结点
int s;	//权重和 
int path[maxn];

struct node{
	int weight;
	vector<int> child;
}Node[maxn];

bool cmp(int a,int b){
	return Node[a].weight>Node[b].weight;	
}

void dfs(int index,int numNode,int sum){	//index:当前处理的结点。numNode:当前路径已包含的结点数 
	if(sum>s)
		return;
	if(sum == s){
		if(Node[index].child.size() != 0) return;
		for(int i=0;i<numNode;i++){
			printf("%d",Node[path[i]].weight);
			if(i<numNode-1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for(int i = 0;i<Node[index].child.size();i++){
		int child = Node[index].child[i];
		path[numNode] = child;
		dfs(child,numNode+1,sum+Node[child].weight);
	}
}

int main(){
	int id,k,child;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++)
		scanf("%d",&Node[i].weight);
	for(int i= 0 ;i<m;i++){
		scanf("%d %d",&id,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			Node[id].child.push_back(child);
		}
		sort(Node[id].child.begin(),Node[id].child.end(),cmp);	//把子结点按照权值降序排列 
	}
	path[0]=0;
	dfs(0,1,Node[0].weight);
	return 0;
}

