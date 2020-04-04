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
void addedge(int l,int k){	//k�Ǹ��� 
	edge[cnt].t = l;
	edge[cnt].next = head[k];
	head[k] = cnt++;
}
int dp[maxn][2];
//dp[i][0] ��ʾ��iΪ������������x����μ�����������ֵ
//dp[i][1] ��ʾ��iΪ������������x��μ�����������ֵ
//dp[i][0] = ��(max(dp[son[i][j]][0],dp[son[i][j]][1])
//dp[i][1] = r[i]+(��dp[son[i][j]][0])

int r[maxn];
bool f[maxn];	//false��ʾ�Ǹ��׽�㣬�������ʱ���޸�f 

void solve(int rt){	//first ��ȡ��second ȡ 
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
		scanf("%d %d",&l,&k);	//k��l����˾
		addedge(l,k);
		f[l] = true;
	}
	//���ҵ�����
	int rt;
	for(rt=1;rt<=n;rt++){
		if(f[rt]==false)
			break;
	}
	solve(rt);
	printf("%d\n",max(dp[rt][0],dp[rt][1]));
	return 0;
}

/*	//������ֱ��DPS�������ɨһ��OVER�����ô�DPҲû����ġ� 
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
void addedge(int l,int k){	//k�Ǹ��� 
	edge[cnt].t = l;
	edge[cnt].next = head[k];
	head[k] = cnt++;
}

int r[maxn];
bool f[maxn];	//false��ʾ�Ǹ��׽�㣬�������ʱ���޸�f 

pair<int,int> solve(int rt){	//first ��ȡ��second ȡ 
	if(rt==0) return make_pair(0,0);
	pair<int,int> res;
	res.first = 0;	//��ȡ 
	res.second = r[rt];	//ȡ 
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
		scanf("%d %d",&l,&k);	//k��l����˾
		addedge(l,k);
		f[l] = true;
	}
	//���ҵ�����
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
