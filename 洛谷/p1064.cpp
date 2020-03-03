#include<cstdio>
#include<algorithm>
using namespace std;
/*对于每组的枚举可以使用01恰好背包解决https://www.luogu.com.cn/problemnew/solution/P1064*/
/*用滚动数组能方便很多*/
const int maxn = 32001;	//最大钱数
const int maxm = 61;	//最大购买物品数量

int v[maxm],p[maxm],q[maxm];
//价格,		重要度,q=0主件,否则表示主件编号  
int group[maxm][3];	//第i组的主件和另外两个附件,从1开始 
int c[maxm][5];//c[i][j] 第i组第j种方案的价格 
int w[maxm][5];//w[i][j] 第i组第j种方案的价格与重要度乘积 
int hashmap[maxm];	//原来编号映射到group后的编号 

int dp[maxm][maxn];
//首先，把有依附关系的都分到一组，共有K组 
//dp[k][j] = 从前k组中选价值不超过j的所能得到的最大收益
//由于题目每组最多只有3件物件，因此有5中情况.1:都不选.2:选择主.3:选择主附1.4选择主附2.5全选
//转移方程 dp[k][j] = max(dp[k-1][j],dp[k-1][j-c[i]]+w[i](c[i],w[i]是k中一种方案对应的价格和价值重要度积)}

int main(){
	int n,m;	//n总钱数,m希望购买的物品数 
	scanf("%d %d",&n,&m);
	int n_group = 0; 
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&v[i],&p[i],&q[i]);
		if(q[i]==0){
			group[++n_group][0]=i;	//记录每组的主件,先不记录附件(其主件可能还未输入) 
			hashmap[i] = n_group;
		} 
	}
	for(int i=1;i<=m;i++)	//记录附件 
		if(q[i]!=0)
			for(int j=1;j<=2;j++)	//插入附件 
				if(group[hashmap[q[i]]][j]==0){
					group[hashmap[q[i]]][j]=i;
					break;
				}
	for(int i=1;i<=n_group;i++){	//计算每组的排列 
		int a1=group[i][0],a2=group[i][1],a3=group[i][2];	//该组中每个物品的编号 
		c[i][1] = v[a1]; 		
		w[i][1] = v[a1]*p[a1];					//只选主
		if(a2!=0){
			c[i][2] = v[a1]+v[a2];	
			w[i][2] = v[a1]*p[a1]+v[a2]*p[a2];		//主,附1
		}		
		if(a3!=0){
			c[i][3] = v[a1]+v[a3];	
			w[i][3] = v[a1]*p[a1]+v[a3]*p[a3];			//主,附2
			c[i][4]=v[a1]+v[a2]+v[a3];
			w[i][4]=v[a1]*p[a1]+v[a2]*p[a2]+v[a3]*p[a3];	//全选 
		}
	}
	for(int i=1;i<=n_group;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = dp[i-1][j];	//本组什么都不选 
			for(int k=1;k<=4&&c[i][k]!=0;k++){	//遍历每组的方案
				if(c[i][k]<=j)
					dp[i][j] = max(dp[i][j],dp[i-1][j-c[i][k]]+w[i][k]);
			}
		}
	}
	printf("%d",dp[n_group][n]);
	return 0;
}
