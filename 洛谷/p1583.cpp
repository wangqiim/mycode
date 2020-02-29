#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 20001;

int E[11];
struct people{
	int no;	//初始序号 
	int w;	//初始权值 
}W[maxn];

bool cmp(people a,people b){
	if(a.w!=b.w)
		return a.w>b.w;
	else	//如果权值相同，编号小的优先 
		return a.no<b.no;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=10;i++)
		scanf("%d",&E[i]);
	for(int i=1;i<=n;i++){
		W[i].no = i;
		scanf("%d",&W[i].w);
	}
	sort(W+1,W+1+n,cmp); //先按输入权值排序,下标为D[i]
	for(int i=1;i<=n;i++){	//将权值更新为加上E[i] 
		W[i].w += E[(i-1)%10+1]; 
	}
	sort(W+1,W+1+n,cmp);
	for(int i=1;i<=k;i++)
		printf("%d ",W[i].no);
	return 0;
}
