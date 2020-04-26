#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int pre;
		int flag = 1;
		int a;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			if(i==0){
				pre = a;
				continue;
			}
			if(a>pre && a!=pre+1){
				flag = 0;
			}
			pre = a;
		}
		if(flag)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
