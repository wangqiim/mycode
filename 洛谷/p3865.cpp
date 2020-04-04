#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 100005;
int MAX[maxn][20];	//max[i][j]��ʾi�ұ�(����i)��2^j���������ֵ 
//max[5][2]��ʾ 5,6,7,8(2^2)�����е����ֵ 

int query(int l,int r){
	int res = 0;
	int k = log2(r-l+1);	
	//ֱ�ӵ�����O(1)log2���������Ҳ�ñ�����˼�������ҪO(logN) 
	return max(MAX[l][k],MAX[r-(1<<k)+1][k]);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&MAX[i][0]);
	for(int j=1;j<20;j++)
		for(int i=1; i+(1<<j)-1<=n; i++)
			MAX[i][j] = max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]);
	int l,r;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
