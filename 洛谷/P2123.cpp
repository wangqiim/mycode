#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 20004;
struct node{
	int a;
	int b;
}nums[maxn];
int T,n;

bool cmp(node a,node b){	 
	int da = (a.a<=a.b?-1:1); 
	int db = (b.a<=b.b?-1:1);
	if(da!=db) return da<db;
	else if(da<=0)
		return a.a<b.a;
	else
		return a.b>b.b;
}

int main(){
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d %d",&nums[i].a,&nums[i].b);
		sort(nums,nums+n,cmp);
		long long acc=0;	//前i位左手和 
		long long res=0;	//上一位获得的奖金数目 
		for(int i=0;i<n;i++){
			acc += nums[i].a;
			res =  max(res,acc)+nums[i].b;
		}
		printf("%lld\n",res);
	}
	return 0;
}
