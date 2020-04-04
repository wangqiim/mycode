#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 6003;
struct{
	int t;
	int next;
}edge[maxn];
int cnt = 1;
int head[maxn];
void addedge(int l,int k){	//k是父亲 
	edge[cnt].t = l;
	edge[cnt].next = head[k];
	head[k] = cnt++;
}
int dp[maxn][2];
//dp[i][0] 表示以i为根的子树，且x不会参加舞会的最大快乐值
//dp[i][1] 表示以i为根的子树，且x会参加舞会的最大快乐值
//dp[i][0] = ∑(max(dp[son[i][j]][0],dp[son[i][j]][1])
//dp[i][1] = r[i]+(∑dp[son[i][j]][0])

int r[maxn];
bool f[maxn];	//false表示是父亲结点，在输入的时候修改f 

void solve(int rt){	//first 不取，second 取 
	if(rt==0) return;
	dp[rt][0] = 0;
	dp[rt][1] = r[rt];
	for(int i=head[rt];i!=0;i=edge[i].next){
		int son = edge[i].t;
		solve(son);
		dp[rt][0] += max(dp[son][0],dp[son][1]);
		dp[rt][1] += dp[son][0];
	}
	return ;
}

int main(){
	int n,l,k;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
		scanf("%d",&r[i]);
	for(int i = 0;i<n-1;i++){
		scanf("%d %d",&l,&k);	//k是l的上司
		addedge(l,k);
		f[l] = true;
	}
	//先找到树根
	int rt;
	for(rt=1;rt<=n;rt++){
		if(f[rt]==false)
			break;
	}
	solve(rt);
	printf("%d\n",max(dp[rt][0],dp[rt][1]));
	return 0;
}

/*	//法二：直接DPS后根遍历扫一遍OVER，不用存DP也没问题的。 
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 6003;
struct{
	int t;
	int next;
}edge[maxn];
int cnt = 1;
int head[maxn];
void addedge(int l,int k){	//k是父亲 
	edge[cnt].t = l;
	edge[cnt].next = head[k];
	head[k] = cnt++;
}

int r[maxn];
bool f[maxn];	//false表示是父亲结点，在输入的时候修改f 

pair<int,int> solve(int rt){	//first 不取，second 取 
	if(rt==0) return make_pair(0,0);
	pair<int,int> res;
	res.first = 0;	//不取 
	res.second = r[rt];	//取 
	for(int i=head[rt];i!=0;i=edge[i].next){
		pair<int,int> tmp = solve(edge[i].t);
		res.first += max(tmp.first,tmp.second);
		res.second += tmp.first;
	}
	return res;
}

int main(){
	int n,l,k;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
		scanf("%d",&r[i]);
	for(int i = 0;i<n-1;i++){
		scanf("%d %d",&l,&k);	//k是l的上司
		addedge(l,k);
		f[l] = true;
	}
	//先找到树根
	int rt;
	for(rt=1;rt<=n;rt++){
		if(f[rt]==false)
			break;
	}
	pair<int,int> res = solve(rt);
	printf("%d\n",max(res.first,res.second));
	return 0;
}
*/
