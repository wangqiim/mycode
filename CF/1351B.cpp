#include<cstdio>

int main(){
	int t,a1,a2,b1,b2;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		bool ans = false;
		if(a1 == a2 && b1 + b2 == a1)
			ans = true;
		if(a1 == b2 && b1 + a2 == a1)
			ans = true;
		if(b1 == a2 && a1 + b2 == b1)
			ans = true;
		if(b1 == b2 && a1 + a2 == b1)
			ans = true;
		if(ans)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
