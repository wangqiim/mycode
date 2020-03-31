#include<cstdio>
#include<algorithm>
using namespace std;

int n,x,y;
int maximum(){	//最大名次 
	int res;
	if(x-1<=n-y)
		res = 1+x-1+y-1;
	else
		res = n;
	return res;
}

int minimum(){	//最小名次
	int res;
	if(x-1<=n-y-1)
		res = 1;
	else{
		if(n==y||n==x)
			res = min(min(n-(n-x-1),n),(n-(n-y-1)));
		else
			res = n-(n-x-1+n-y-1+1);
	}
	return res;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&x,&y);
		printf("%d %d\n",minimum(),maximum());
	}
	return 0;
}
