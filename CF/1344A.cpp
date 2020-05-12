#include<cstdio>
#include<cstring>

const int maxn = 200005;
int vis[maxn];

int main(){
	int t;
	long long n, a;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i = 0; i < n; i++)
			vis[i] = 0;
		bool ans = true;
		for(long long i = 0; i < n; i++){
			scanf("%lld", &a);
			a = (i + a) % n;
			if(a < 0)
				a = n + a;
			if(vis[a] == 1)
				ans = false;
			vis[a] = 1;
		}
		if(ans)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
