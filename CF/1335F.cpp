#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

const int maxn = 1000006;
int n,m;
int ans1,ans2;	//ans1����������,ans2���ڻ�������
int num[maxn],dir[maxn];	//num:0,1 dir:���� 
bool vis[maxn];

inline getpos(int x,int y){
	return x*m+y;
}
bool check(int x){	//�ж�λ���Ƿ�Ϸ� 
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
			loop = i;	//ѭ���ĳ��� 
			break;
		}
	}
	//������ans2
	map<int,int> M;	//M[i]=1��ʾ�õ��Ѿ�������� 
	set<int> S;
	queue<pair<int,int> >que;	//second��cur�ľ��� 
	que.push(make_pair(cur,0));
	M[cur] = 1;
	if(!num[cur]) S.insert(0);	//��ɫ 
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
			vector<int> v;	//��i������ܵ���ĵ���ܵ������ĵ㣨����ͼ�� 
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
				//����4��if�ж�t���ĸ������ܷ񵽴�t(�ܵ�t��λ��) 
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
