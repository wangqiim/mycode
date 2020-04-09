#include<cstdio>

const int maxn = 100005;
int a[maxn];
int b[maxn];

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		int plus = 0;
		int sub = 0;
		bool flag = true;
		for(int i=1;i<=n;i++){
			if(a[i]<b[i]&&plus==0){
				flag = false;
				break;
			}else if(a[i]>b[i]&&sub==0){
				flag = false;
				break;
			}
			if(a[i]==1) plus = 1;
			if(a[i]==-1) sub = 1;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
} 
