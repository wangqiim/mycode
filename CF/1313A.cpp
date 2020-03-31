#include<cstdio>
#include<algorithm>
using namespace std;

int a,b,c;
int solve(){
	int res = 0;
	if(a<b) swap(a,b);	//a必须是是最大的 
	if(a<c) swap(a,c);
	if(a>0) res++,a--;
	if(b>0) res++,b--;
	if(c>0) res++,c--;
	if(a>0&&b>0) res++,a--,b--;
	if(b>0&&c>0) res++,b--,c--;
	if(a>0&&c>0) res++,a--,c--;
	if(a>0&&b>0&&c>0) res++;
	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&a,&b,&c);
		
		printf("%d\n",solve());
	}
	return 0;
}
