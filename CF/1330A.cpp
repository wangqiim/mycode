#include<cstdio>
#include<cstring>

const int maxn = 202;
int hashmap[maxn];

int main(){
	int t,n,x;
	int res;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x);
		memset(hashmap,0,sizeof(hashmap));
		int a;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			hashmap[a]++;
		}
		res = 0;
		for(int i=1;i<maxn;i++){
			if(hashmap[i]==0){
				if(x){
					x--;
				}else{
					res = i-1;
					break;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}

