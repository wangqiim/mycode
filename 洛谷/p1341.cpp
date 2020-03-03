#include<iostream>
#include<string>
using namespace std;


const int maxn = 256;// ASCII 'z','Z'均小于256

int G[maxn][maxn];
int depth[maxn];	//点的度
int fa[maxn];	//并查集根结点 
int n,cnt=0,start=0;	//cnt度为奇数的点,start递归开始的结点 
char res[1000]={};
int left;
int t;

int find_fa(int x){
	if(fa[x] != x) fa[x]=find_fa(fa[x]);
	return fa[x];
}

void dfs(int now){
	for(int i=0;i<maxn;i++)
		if(G[now][i]==1){
			G[now][i]=G[i][now]=0;
			dfs(i);
		}
	res[n--]=(char)now;	//插 
	return;
}

int main(){
	for(int i=0;i<maxn;i++) fa[i]=i;	//并查集初始化 
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		G[s[0]][s[1]]=G[s[1]][s[0]] = 1;
		fa[find_fa(s[0])] = find_fa(s[1]);	//合并
		depth[s[0]]++;
		depth[s[1]]++; 
	}
	
	int root = find_fa(s[0]); //判断是否是一个连通图 
	for(int i=0;i<maxn;i++)
		if(find_fa(i)!=i&&find_fa(i)!=root){
			cout<<"No Solution";
			return 0;
		}
		
	for(int i=0;i<maxn;i++)	//计算奇数度结点的个数 
		if(depth[i]&1){
			cnt++;
			if(start==0)
				start = i;
		}

	if(cnt==0)	//有欧拉回路,找到一个最小的开始结点 
		for(int i=0;i<maxn;i++)
			if(depth[i]){
				start = i;
				break;
			}
			
	if(cnt!=0&&cnt!=2){//度为奇数的点不是0个或2个 
		cout<<"No Solution";
		return 0;
	}
	dfs(start);
	cout<<res;
	return 0;
}
