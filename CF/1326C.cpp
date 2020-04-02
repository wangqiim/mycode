#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long 

const int MOD = 998244353;
const int maxn = 200005;
pair<LL,LL> p[maxn]; //first Öµ,second Ë÷Òý 

bool cmp(pair<LL,LL> a,pair<LL,LL> b){
	return a.second>b.second;
}


int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&p[i].second);
		p[i].first = i;
	}
	sort(p,p+n,cmp);
	sort(p,p+k);
	LL res=0;
	LL cnt = 1;
	for(int i=0;i<k;i++){
		res+=p[i].second;	//Öµ
		if(i!=0)
			cnt = (cnt*(p[i].first-p[i-1].first))%MOD;
	}
	printf("%lld %lld\n",res,cnt);
	return 0;
}
