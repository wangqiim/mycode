#include<cstdio>

const int maxn = 5003;
int hashmap[maxn];

int main(){
	int t,n,a;	//t×éÑùÀı
	int L,R;
	bool res;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		res = false;
		for(int j=0;j<maxn;j++) hashmap[j] = -1;
		for(int j=0;j<n;j++){
			scanf("%d",&a);
			if(hashmap[a]!=-1){
				if(hashmap[a]<j-1)
					res = true;
			}else
				hashmap[a] = j;
		}
		if(res)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
