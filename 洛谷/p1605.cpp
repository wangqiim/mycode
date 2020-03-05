#include<cstdio>

const int maxn = 6;

int G[maxn][maxn];
bool visit[maxn][maxn];
int n,m,t;
int sx,sy,ex,ey;
int dx[4] = {1,-1,0, 0};
int dy[4] = {0, 0,1,-1};
int res = 0;

void dfs(int x,int y){
	if(x==ex&&y==ey){
		res++;
		return;
	}
	for(int i=0;i<4;i++){
		int xx = x+dx[i],yy =y+dy[i];
		if(xx<=0||yy<=0||xx>n||yy>m) continue;
		if(visit[xx][yy]==false&&G[xx][yy]==0){
			visit[xx][yy] = true;
			dfs(xx,yy);
			visit[xx][yy] = false;
		}
	}
	return;
}

int main(){
	scanf("%d %d %d",&n,&m,&t);
	scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
	int x,y;
	for(int i=0;i<t;i++){
		scanf("%d %d",&x,&y);
		G[x][y] = 1;
	}
	visit[sx][sy] = true;
	dfs(sx,sy);
	printf("%d",res);
	return 0;
}
