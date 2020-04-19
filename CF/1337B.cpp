#include<cstdio>

int main(){
	int t,x,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&x,&n,&m);
		while(n--&&x>20) x = x/2 + 10;
		if(x<=10*m) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

