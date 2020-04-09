#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 500005;
int b[maxn];	//b[i] = j表示i的最大约数是j 

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j = i+i;j<=n;j+=i)
			b[j] = i;	//更新j的最大约数
	sort(b+1,b+1+n); 
	for(int i=2;i<=n;i++){
		printf("%d ",b[i]);
	}	
	return 0;
}
