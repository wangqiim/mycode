#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

const int maxn=501;
const int inf = 1000000000;
int n,m,c1,c2;
int place[maxn];	//各个点的权 
int G[maxn][maxn] = {0};
int d[maxn];	//存最近距离
int weight[maxn]={0};	//存路径上总人数 
int isvis[maxn] = {false};
int way[maxn] ={0};

void dijkstra(int start,int end){
	for(int i=0;i<maxn;i++)
		d[i] = inf;
	d[start] = 0;
	weight[start] = place[start];
	way[start] = 1;
	//weight[start] = place[start];
	for(int i=0;i<n;i++){
		int u = -1,min = inf;
		for(int j = 0;j<n;j++){
			if(isvis[j]==false&&d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1||u == end)
			return;
		isvis[u] = true;
		for(int v=0;v<n;v++){
			if(G[u][v]>0 && isvis[v] == false){
				if(G[u][v]+d[u]<d[v]){
					d[v] = G[u][v] + d[u];
					weight[v] = weight[u] + place[v];
					way[v] = way[u];				
				}else if(G[u][v]+d[u]==d[v]){
					way[v] += way[u];
					if(weight[u] + place[v]>weight[v]){
						weight[v] = weight[u] + place[v];
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
	for(int i = 0 ;i<n;i++){
		scanf("%d",&place[i]);
	}
	for(int i = 0 ;i<m;i++){
		int p1,p2,distance;
		scanf("%d %d %d",&p1,&p2,&distance);
		G[p1][p2] = G[p2][p1] = distance;
	}
	dijkstra(c1,c2);
	printf("%d %d",way[c2],weight[c2]);
    return 0;
}
