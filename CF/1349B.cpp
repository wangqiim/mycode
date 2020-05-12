#include<cstdio>

const int maxn = 100005;
int a[maxn];

int main(){
	int t, n, k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		bool flag = false;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] == k) flag = true;
			a[i] = (a[i]>=k? 1: 0);
		}
		if(n == 1 && flag == true){
			puts("yes");
			continue;
		}
		if(flag == false){
			puts("no");
			continue;
		}else{
			bool ans = false;
			for(int i = 0; i < n - 1; i++){
				if(a[i] == 1 && a[i + 1] == 1){
					ans = true;
					break;
				}
			}
			for(int i = 0; i < n - 2; i++){
				if(a[i] == 1 && a[i + 2] == 1){
					ans = true;
					break;
				}
			}
			if(ans)
				puts("yes");
			else
				puts("no");
		}
	}
	return 0;
}
