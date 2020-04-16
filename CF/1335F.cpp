#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

const int maxn = 1000006;
int n,m;
int ans1,ans2;	//ans1最大机器人数,ans2最大黑机器人数
int num[maxn],dir[maxn];	//num:0,1 dir:方向 
bool vis[maxn];

inline getpos(int x,int y){
	return x*m+y;
}
bool check(int x){	//判断位置是否合法 
	return x>=0 && x<m*n;
}
void solve(vector<int> v){
	int cur = v[0],loop;
	int size = v.size();
	for(int i=0;i<v.size();i++) cur += dir[cur];
	int fcur = cur;
	for(int i=1;;i++){
		fcur = fcur+dir[fcur];
		if(fcur==cur){
			ans1 += i;
			loop = i;	//循环的长度 
			break;
		}
	}
	//下面求ans2
	map<int,int> M;	//M[i]=1表示该点已经被计算过 
	set<int> S;
	queue<pair<int,int> >que;	//second到cur的距离 
	que.push(make_pair(cur,0));
	M[cur] = 1;
	if(!num[cur]) S.insert(0);	//黑色 
	while(!que.empty()){
		pair<int,int> c = que.front();que.pop();
		int x = c.first, y = c.second;
		if(!num[x]) S.insert(y%loop);
		if(check(x-1)&&!M[x-1]&&dir[x-1]==1){
			que.push(make_pair(x-1,y+1));
			M[x-1] = 1;
		}
		if(check(x+1)&&!M[x+1]&&dir[x+1]==-1){
			que.push(make_pair(x+1,y+1));
			M[x+1] = 1;
		}
		if(check(x-m)&&!M[x-m]&&dir[x-m]==m){
			que.push(make_pair(x-m,y+1));
			M[x-m] = 1;
		}
		if(check(x+m)&&!M[x+m]&&dir[x+m]==-m){
			que.push(make_pair(x+m,y+1));
			M[x+m] = 1;
		}
	}
	ans2 += S.size();
	return;
	
}

int main(){
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		memset(vis,0,m*n);
		ans1 = ans2 = 0;
		map<char,int> T;
		T['L'] = -1;T['R'] = 1;T['U'] = -m;T['D'] = m;
		for(int i=0;i<n;i++){
			string t;cin>>t;
			int len = t.size();
			for(int j=0;j<len;j++)
				num[getpos(i,j)] = t[j] - '0';
		}
		for(int i=0;i<n;i++){
			string t;cin>>t;
			int len = t.size();
			for(int j=0;j<len;j++)
				dir[getpos(i,j)] = T[t[j]];
		}
		for(int i=0;i<m*n;i++){
			if(vis[i]) continue;
			vector<int> v;	//从i点广搜能到达的点和能到达他的点（即子图） 
			queue<int> que;
			que.push(i);
			vis[i]=1;
			while(!que.empty()){
				int t = que.front();
				que.pop();
				v.push_back(t);
				if(!vis[t+dir[t]]){
					que.push(t+dir[t]);
					vis[t+dir[t]] = 1;
				}
				//下面4个if判断t的四个方向能否到达t(能到t的位置) 
				if(check(t-1)&&!vis[t-1]&&dir[t-1]==1){
					que.push(t-1);
					vis[t-1] = 1;
				}
				if(check(t+1)&&!vis[t+1]&&dir[t+1]==-1){
					que.push(t+1);
					vis[t+1] = 1;
				}
				if(check(t-m)&&!vis[t-m]&&dir[t-m]==m){
					que.push(t-m);
					vis[t-m] = 1;
				}
				if(check(t+m)&&!vis[t+m]&&dir[t+m]==-m){
					que.push(t+m);
					vis[t+m] = 1;
				}
			}
			solve(v);
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
