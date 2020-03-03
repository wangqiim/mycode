#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 200001;

bool isvis[maxn]={false};	//未经过的结点
int nums[maxn];
int n,res=0x7fffffff;
int dfsnums[maxn];	//记录每次查找中第一次出现的位置 

void dfs(int begin,int now){
	if(isvis[begin]==true) return;
	if(dfsnums[begin]!=0){	//本次搜索中,出现环了 
		res = min(res,now-dfsnums[begin]);
	}else{
		dfsnums[begin] = now;
		dfs(nums[begin],now+1);
		isvis[begin] = true;
	}
	return;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&nums[i]);
	}
	for(int i=1,j;i<=n;i++){
		dfs(i,1);
	}
	printf("%d",res);
	return 0;
}


/*	//直接暴力会超时 
#include<cstdio>

const int maxn = 200001;
int trans[maxn]; //trans[i]表示i每次会把信息传递给trans[i] 
int nums[maxn];	//nums[i]表示 i 的信息传到nums[i]了 

int main(){
	int n,res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&trans[i]);
		nums[i] = i;
	}
	bool flag=true;
	while(flag){
		res++;
		for(int i=1;i<=n;i++){
			nums[i] = trans[nums[i]];
			if(nums[i]==i){
				flag = false;
				break;	
			}
		}
	}
	printf("%d",res);
	return 0;
}
*/
