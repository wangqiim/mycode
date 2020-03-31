#include<cstdio>
#include<vector>
using namespace std;

const int maxn = 100005;
int nums[maxn];	//nums[i]表示i相邻的点 
int u[maxn];
int v[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int node = 0;
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&u[i],&v[i]);
		nums[u[i]]++;
		nums[v[i]]++;
		if(nums[u[i]]==3||nums[v[i]]==3)
			node = (nums[u[i]]==3?u[i]:v[i]);
	}
	if(node == 0)	//一条链 
		for(int i=0;i<n-1;i++)
			printf("%d\n",i);
	else{	//有1点连接了3个以上点,则分别置为0,1,2 
		int t = 0;
		int j = 3;
		for(int i=0;i<n-1;i++){
			if((u[i]!=node&&v[i]!=node)||(t>=3))
				printf("%d\n",j++);
			else
				printf("%d\n",t++);
		}
	}
	return 0;
}
