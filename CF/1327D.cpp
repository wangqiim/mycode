#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 200005;
int p[maxn];
int c[maxn];
int vis[maxn];	//�Ƿ��Ѿ����� 

int main(){
	int t,n,res;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&p[i]);
		for(int i=1;i<=n;i++) scanf("%d",&c[i]),vis[i]=0;
		int res = n;
		for(int i = 1;i<=n;i++)
			if(!vis[i]){
				int u = i;
				vector<int> cycle;	//�����ĵ����ɫ 
				while(!vis[u]){
					cycle.push_back(c[u]);
					vis[u] = 1;
					u = p[u];
				} 
				int	m = cycle.size();
				int flag = 0;
				for(int k=1;k<=m;k++){
					if(flag == 1) break;	//�Ѿ���������������k 
					if(m%k==0){	//k��m������,��ÿ���ߵĲ���
						for(int j=0;j<k;j++){
							bool suc = 1;
							for(int r=j;r<m;r+=k)
								suc&=(cycle[r]==cycle[j]);
							if(suc){
								res = min(res,k);
								flag = 1;
								break;
							}
						}
					}
				}
			}
		printf("%d\n",res);
	}
	return 0;
}
