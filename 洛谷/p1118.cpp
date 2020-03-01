#include<cstdio>

const int maxn = 13;

int yhsj[12][12];
bool isused[maxn];	//递归时判断该数字有没有被使用
int nums[maxn];	//输出时使用 
int n;
int flag=false; //只输出一个最小的序列 

void dfs(int now,int sum){	//当前需要递归处理的是第now位数,sum为目标值减去之前所有的剩余的 
	if(now==n){
		if(sum==0){
			for(int i=0;i<n;i++)
				if(i==n-1) printf("%d\n",nums[i]);
				else printf("%d ",nums[i]);
			flag = true;
		}
		return;
	}
	for(int i=1;i<=n;i++){	//i能否使用 1~n
		if(flag) break;	//已经输出了最小答案,此处不剪枝也无法全部AC 
		if(isused[i]==false&&(sum-i*yhsj[n-1][now])>=0){
			isused[i] = true;
			nums[now] = i;
			dfs(now+1,sum-i*yhsj[n-1][now]);
			isused[i] = false;
		}
	}
	return;
}

int main(){
	int s;
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++){//构建杨辉三角 
		for(int j=0;j<=i;j++){
			if(j==0||i==j){
				yhsj[i][j]=1;
				continue;
			}else{
				yhsj[i][j]=yhsj[i-1][j-1]+yhsj[i-1][j];	//如果只构建最后一维的系数也可以利用滚动数组构建 
			}
		}
	}
	dfs(0,s);
	return 0;
}
